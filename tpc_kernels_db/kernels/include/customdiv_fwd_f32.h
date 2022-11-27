/* SPDX-License-Identifier: MIT
 *
 * Copyright 2016-2021 HabanaLabs, Ltd.
 * All Rights Reserved.
 *
 */
float64 reciprocal_cephes_fast_f32(float64 input)
{
    float64 result, temp0, temp1, temp2;
    const float a = 2.58586f;
    const float b = -5.81818f;
    const float c = 4.24242f;

    int64 significand = 0;
    significand = v_i32_and_b(*((int64*)&input), 0x007fffff);
    significand = v_i32_or_b(significand, 0x3f000000);
    result = *((float64*)&significand);

    int64 exponent = 0;
    exponent =  v_i32_shr_b(*((int64*)&input), 23);
    exponent = v_i32_and_b(exponent, 0x000000ff);
    exponent -= 0x7e;

    temp0 = v_f32_mac_b(result, a, b);
    temp1 = v_f32_mac_b(result, temp0, c);
    temp2 = v_f32_mac_b(-result, temp1, 2);
    temp2 *= temp1;
    temp0 = v_f32_mac_b(-result, temp2, 2);
    temp0 *= temp2;

    int64 exp =  v_i32_shr_b(*((int64*)&temp0), 23);
    exp = v_i32_and_b(exp, 0x000000ff);
    exp = v_i32_add_b(exp, -exponent);
    exp = v_i32_and_b(exp, 0xff);
    result = v_f32_form_fp_num_ie_b((char256)exp, input, temp0, SW_EXP_IS_NUM);

    return result;
}


float64 reciprocal_cephes_f32(float64 input)
{
    float64 result = reciprocal_cephes_fast_f32(input);


// ====================================
//  Processing special values: denorm, +-0. +-inf, nan
    float64 abs_x = v_f32_abs_b(input);

    const uint64 flt_max = 0x7f7fffff;
    const float64 flt_max_fp32 = *((float64*)&flt_max);

    float64 fclass = v_f32_fclass_b(input);
    result = v_f32_calc_fp_special_b(fclass, fclass, e_fp_recip, result);
    result = v_f32_sel_geq_f32_b(abs_x, flt_max_fp32, 0.0f, result);
// ====================================

    return result;
}

void main(tensor input0, tensor input1, tensor output)
{
    const int depth     = 0;
    const int width     = 1;
    const int height    = 2;
    const int batch     = 3;

    const int5 index_space_start = get_index_space_offset();
    const int5 index_space_end = get_index_space_size() + index_space_start;

    int5 coords = { 0, 0, 0, 0, 0 };

    // DEPTH
    const int depthStep     = 64;
    const int depthStart    = index_space_start[depth] * depthStep;
    const int depthEnd      = index_space_end[depth] * depthStep;

    // WIDTH
    const int widthStep     = 1;
    const int widthStart    = index_space_start[width] * widthStep;
    const int widthEnd      = index_space_end[width] * widthStep;

    // HEIGHT
    const int heightStep    = 1;
    const int heightStart   = index_space_start[height];
    const int heightEnd     = index_space_end[height];

    // BATCH
    const int batchStep     = 1;
    const int batchStart    = index_space_start[batch];
    const int batchtEnd     = index_space_end[batch];

    for (int b = batchStart; b < batchtEnd; b += batchStep)
    {
        coords[batch] = b;

        for (int h = heightStart; h < heightEnd; h += heightStep)
        {
            coords[height] = h;
            for (int d = depthStart; d < depthEnd; d += depthStep)
            {
                coords[depth] = d;
                for (int w = widthStart; w < widthEnd; w += widthStep)
                {
                    coords[width] = w;

                    float64 x = v_f32_ld_tnsr_b(coords, input0);
                    float64 y = v_f32_ld_tnsr_b(coords, input1);

                    float64 div_x_y = x * reciprocal_cephes_fast_f32(y);

                    v_f32_st_tnsr(coords, output, div_x_y);
                }
            }
        }
    }
}
