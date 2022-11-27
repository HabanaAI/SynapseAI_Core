/* SPDX-License-Identifier: MIT
 *
 * Copyright 2016-2021 HabanaLabs, Ltd.
 * All Rights Reserved.
 *
 */
void main(tensor input, tensor output, float alpha)
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
    const int widthStep     = 4;
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
                #pragma loop_unroll(4)
                for (int w = widthStart; w < widthEnd; w += 1)
                {
                    coords[width] = w;

                    float64 x = v_f32_ld_tnsr_b(coords, input);

                    bool256 cond = from_bool64(v_f32_cmp_grt_b(x, 0.0));

                    float64 y = v_f32_mul_vb(x, alpha, 0, x, to_bool64(cond), 1);

                    v_f32_st_tnsr(coords, output, y);
                }
            }
        }
    }
}
