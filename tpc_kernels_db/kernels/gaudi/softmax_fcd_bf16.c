/* SPDX-License-Identifier: MIT
 *
 * Copyright 2016-2021 HabanaLabs, Ltd.
 * All Rights Reserved.
 *
 */
void main(
    tensor ifm,
    tensor ofm
)
{
    const int depth  = 0;
    const int width  = 1;
    const int height = 2;
    const int batch  = 3;

    const int5 index_space_start = get_index_space_offset();
    const int5 index_space_end = get_index_space_size() + index_space_start;

    // depth
    const int depthStep  = 128;
    const int depthStart = 0;
    // Returns the dim0 size of ifm
    const int depthEnd   = get_dim_size(ifm, 0);

    // width
    const int widthStep  = 1;
    const int widthStart = index_space_start[width] * widthStep;
    const int widthEnd   = index_space_end[width]   * widthStep;

    // height
    const int heightStep  = 1;
    const int heightStart = index_space_start[height] * heightStep;
    const int heightEnd   = index_space_end[height]   * heightStep;

    // batch
    const int batchStep  = 1;
    const int batchStart = index_space_start[batch] * batchStep;
    const int batchEnd   = index_space_end[batch]   * batchStep;

    int5 ifmCoords = { depthStart, widthStart, heightStart, batchStart, 0 };

    bfloat128 zero_bf16 = v_bf16_mov_s(0.f);

    bfloat128 x;
    bfloat128 y;
    bfloat128 sum;

    for (int b = batchStart; b < batchEnd; b += batchStep)
    {
        ifmCoords[batch] = b;

        for (int h = heightStart; h < heightEnd; h += heightStep)
        {
            ifmCoords[height] = h;

            for (int w = widthStart; w < widthEnd; w += widthStep)
            {
                ifmCoords[width] = w;

                sum = zero_bf16;

                for (int d = depthStart; d < depthEnd; d += depthStep)
                {
                    ifmCoords[depth] = d;

                    // load input tensors
                    x = v_bf16_ld_tnsr_b(ifmCoords, ifm);
                    float64_pair_t  xf32, yf32;
                    xf32 = v_convert_bf16_to_f32_all_b(x);
                    // exp_bf16(bfloat128 input)
                    yf32.v1 = v_exp_cephes_f32(xf32.v1);
                    yf32.v2 = v_exp_cephes_f32(xf32.v2);
                    y = v_convert_f32_to_bf16_all_b(yf32);

                    // Move zero for out of bound co-ordinates
                    bool256 pred = from_bool128(v_u16_cmp_geq_b(d + V_LANE_ID_16, (unsigned)depthEnd, 0, to_bool128((bool256){0})));
                    y = v_bf16_mov_vb(zero_bf16, 0, y, to_bool128(pred), 0);

                    // Sum up the values in a vector
                    sum = sum + y;
                }


                // Sum across the vector
                sum = v_bf16_reduce_add(sum);

                ifmCoords[width] = w;
                float64_pair_t sumf32;
                // calculate 1/sum by using float
                sumf32 = v_convert_bf16_to_f32_all_b(sum);
                sumf32.v1 = v_reciprocal_f32(sumf32.v1);
                sumf32.v2 = v_reciprocal_f32(sumf32.v2);
                sum = v_convert_f32_to_bf16_all_b(sumf32);


                for (int d = depthStart; d < depthEnd; d += depthStep)
                {
                    ifmCoords[depth] = d;

                    x = v_bf16_ld_tnsr_b(ifmCoords, ifm);
                    float64_pair_t xf32, yf32;
                    xf32 = v_convert_bf16_to_f32_all_b(x);
                    // exp_bf16(bfloat128 input)
                    yf32.v1 = v_exp_cephes_f32(xf32.v1);
                    yf32.v2 = v_exp_cephes_f32(xf32.v2);
                    y = v_convert_f32_to_bf16_all_b(yf32);

                    // Multiply exp(x) * 1/(sum_of_exponents)
                    x = y * sum;

                    v_bf16_st_tnsr(ifmCoords, ofm, x);
                }
            }
        }
    }
}
