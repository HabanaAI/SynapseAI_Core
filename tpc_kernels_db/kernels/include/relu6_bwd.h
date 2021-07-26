/* SPDX-License-Identifier: MIT
 *
 * Copyright 2016-2021 HabanaLabs, Ltd.
 * All Rights Reserved.
 *
 */
#include "kernel_config.h"

void main(tensor grad, tensor input, tensor output)
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

                    VECTOR x = v_ld_tnsr_i(coords, input);
                    VECTOR g = v_ld_tnsr_i(coords, grad);

                    VECTOR y = v_sel_less_v_s_v_v(x, 0.0, 0.0, x);
                    
                    x = v_sel_geq_v_s_v_v(y, 6.0, 0.0, y);

                    y = v_sel_grt_v_s_v_v(x, 0.0, g, 0.0);

                    st_tnsr_i_v(coords, output, y);
                }
            }
        }
    }
}
