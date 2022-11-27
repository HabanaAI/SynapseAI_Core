/* SPDX-License-Identifier: MIT
 *
 * Copyright 2016-2021 HabanaLabs, Ltd.
 * All Rights Reserved.
 *
 */
void main(
    tensor ifm_tr,
    tensor beta_tr,
    tensor gamma_tr,

    tensor ofm_tr,
    tensor mean_tr,
    tensor istd_tr,

    float N,
    float N_reciprocal,
    float momentum
)
{

    const int depth  = 0;
    const int width  = 1;
    const int height = 2;
    const int batch  = 3;

    const int5 index_space_start = get_index_space_offset();
    const int5 index_space_end = get_index_space_size() + index_space_start;

    // DEPTH
    const int depthStep = 64;
    const int depthStart = index_space_start[depth] * depthStep;
    const int depthEnd = index_space_end[depth] * depthStep;

    // WIDTH
    const int widthStep = 4;
    const int widthStart = 0;
    const int widthEnd = get_dim_size(ifm_tr, width);

    // HEIGHT
    const int heightStep = 1;
    const int heightStart = 0;
    const int heightEnd =get_dim_size(ifm_tr, height);

    // BATCH
    const int batchStep = 1;
    const int batchStart = 0;
    const int batchEnd = get_dim_size(ifm_tr, batch);

    float64 beta;
    float64 gamma;
    float64 y0, y1, y2, y3;
    float64 x0, x1, x2, x3;

    int5 ifmCoords = { 0, 0, 0, 0, 0 };
    int5 ofmCoords = { 0, 0, 0, 0, 0 };
    int5 depthCoords = { depthStart, 0, 0, 0, 0 };

    float64 vN = N_reciprocal;

    for (int d = depthStart; d < depthEnd; d += depthStep)
    {
        ifmCoords[depth] = d;   ofmCoords[depth] = d;

        // Initialize mean and variance to zero
        float64 mean_v_0 = 0, mean_v_1 = 0, mean_v_2 = 0, mean_v_3 = 0;
        float64 var_v_0 = 0, var_v_1 = 0, var_v_2 = 0, var_v_3 = 0;

        // Calculate mean across batch for each feature
        for (int b = batchStart; b < batchEnd; b += batchStep)
        {
            ifmCoords[batch] = b;   ofmCoords[batch] = b;
            for (int h = heightStart; h < heightEnd; h += heightStep)
            {
                ifmCoords[height] = h;   ofmCoords[height] = h;
                ifmCoords[width] = widthStart;   ofmCoords[width] = widthStart;

                for (int w = widthStart; w < widthEnd; w += widthStep)
                {
                    // Loading input values
                    x0 = v_f32_ld_tnsr_b(ifmCoords, ifm_tr); ifmCoords[width] += 1;
                    x1 = v_f32_ld_tnsr_b(ifmCoords, ifm_tr); ifmCoords[width] += 1;
                    x2 = v_f32_ld_tnsr_b(ifmCoords, ifm_tr); ifmCoords[width] += 1;
                    x3 = v_f32_ld_tnsr_b(ifmCoords, ifm_tr); ifmCoords[width] += 1;

                    mean_v_0 = mean_v_0 + x0;
                    mean_v_1 = mean_v_1 + x1;
                    mean_v_2 = mean_v_2 + x2;
                    mean_v_3 = mean_v_3 + x3;
                }
            }
        }

        float64 mean_v;
        mean_v_0 = mean_v_0 + mean_v_1;
        mean_v_2 = mean_v_2 + mean_v_3;
        mean_v   = mean_v_0 + mean_v_2;
        // mean = sum / (height + width + batch)
        mean_v = mean_v * vN;

        // Calculate variance across batch for each feature
        for (int b = batchStart; b < batchEnd; b += batchStep)
        {
            ifmCoords[batch] = b;   ofmCoords[batch] = b;
            for (int h = heightStart; h < heightEnd; h += heightStep)
            {
                ifmCoords[height] = h;   ofmCoords[height] = h;
                ifmCoords[width] = widthStart;   ofmCoords[width] = widthStart;

                for (int w = widthStart; w < widthEnd; w += widthStep)
                {

                    x0 = v_f32_ld_tnsr_b(ifmCoords, ifm_tr); ifmCoords[width] += 1;
                    x1 = v_f32_ld_tnsr_b(ifmCoords, ifm_tr); ifmCoords[width] += 1;
                    x2 = v_f32_ld_tnsr_b(ifmCoords, ifm_tr); ifmCoords[width] += 1;
                    x3 = v_f32_ld_tnsr_b(ifmCoords, ifm_tr); ifmCoords[width] += 1;

                    float64 tmp0, tmp1, tmp2, tmp3;
                    tmp0 = x0 - mean_v;
                    tmp1 = x1 - mean_v;
                    tmp2 = x2 - mean_v;
                    tmp3 = x3 - mean_v;

                    var_v_0 = v_f32_mac_b(tmp0, tmp0, var_v_0, e_no_negation << 1);
                    var_v_1 = v_f32_mac_b(tmp1, tmp1, var_v_1, e_no_negation << 1, w < widthEnd-1);
                    var_v_2 = v_f32_mac_b(tmp2, tmp2, var_v_2, e_no_negation << 1, w < widthEnd-2);
                    var_v_3 = v_f32_mac_b(tmp3, tmp3, var_v_3, e_no_negation << 1, w < widthEnd-3);
                }
            }
        }

        float64 var_v;
        var_v_0 = var_v_0 + var_v_1;
        var_v_2 = var_v_2 + var_v_3;
        var_v   = var_v_0 + var_v_2;

        // Variance = (x - mean)^2 / (height + width + batch)
        var_v = var_v * vN;

        // Loading gamma and beta
        beta  = v_f32_ld_tnsr_b(depthCoords, beta_tr);
        gamma = v_f32_ld_tnsr_b(depthCoords, gamma_tr);

        // Normalized Value = ((x-mean) * gamma / sqrt(variance + epsilon)) + beta
        // Normalized Value = x * (gamma / sqrt(variance + eps))
        //                    - mean * (gamma / sqrt(variance + eps)) + beta
        // Normalized Value = x * scale  + bias
        // where scale = (gamma / sqrt(variance + eps)) and bias = (-mean * scale + bias)

        // Calculate scale and bias
        float64 var_tmp = var_v + 1e-5;
        float64 istd = v_rsqrt_f32(var_tmp);
        float64 scale = gamma * istd;
        float64 bias = v_f32_mac_b(scale, mean_v, beta, e_with_negation << 1);

        v_f32_st_tnsr(depthCoords, istd_tr, istd);
        v_f32_st_tnsr(depthCoords, mean_tr, mean_v);

        depthCoords[depth] += depthStep;

        for (int b = batchStart; b < batchEnd; b += batchStep)
        {
            ifmCoords[batch] = b;   ofmCoords[batch] = b;
            for (int h = heightStart; h < heightEnd; h += heightStep)
            {
                ifmCoords[height] = h;   ofmCoords[height] = h;

                ifmCoords[width] = widthStart; ofmCoords[width] = widthStart;

                // Loading input values
                for (int w = widthStart; w < widthEnd; w += widthStep)
                {
                    // Loading input values
                    x0 = v_f32_ld_tnsr_b(ifmCoords, ifm_tr); ifmCoords[width] += 1;
                    x1 = v_f32_ld_tnsr_b(ifmCoords, ifm_tr); ifmCoords[width] += 1;
                    x2 = v_f32_ld_tnsr_b(ifmCoords, ifm_tr); ifmCoords[width] += 1;
                    x3 = v_f32_ld_tnsr_b(ifmCoords, ifm_tr); ifmCoords[width] += 1;

                    // y = x * scale + bias
                    y0 = v_f32_mac_b(x0, scale, bias, e_no_negation << 1);
                    y1 = v_f32_mac_b(x1, scale, bias, e_no_negation << 1);
                    y2 = v_f32_mac_b(x2, scale, bias, e_no_negation << 1);
                    y3 = v_f32_mac_b(x3, scale, bias, e_no_negation << 1);

                    v_f32_st_tnsr(ofmCoords, ofm_tr, y0); ofmCoords[width] += 1;
                    v_f32_st_tnsr(ofmCoords, ofm_tr, y1); ofmCoords[width] += 1;
                    v_f32_st_tnsr(ofmCoords, ofm_tr, y2); ofmCoords[width] += 1;
                    v_f32_st_tnsr(ofmCoords, ofm_tr, y3); ofmCoords[width] += 1;
                }
            }
        }
    }
}
