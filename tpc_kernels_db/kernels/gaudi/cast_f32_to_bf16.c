/* SPDX-License-Identifier: MIT
 *
 * Copyright 2016-2021 HabanaLabs, Ltd.
 * All Rights Reserved.
 *
 */
void main(tensor ifm,
          tensor ofm,
          float scaleToBF16)
{
    const int depth = 0;
    const int width = 1;
    const int height = 2;
    const int batch = 3;

    const int5 index_space_start = get_index_space_offset();
    const int5 index_space_end = get_index_space_size() + index_space_start;

    // DEPTH
    const int depthStep = 128;
    const int depthStart = index_space_start[depth] * depthStep;
    const int depthEnd = index_space_end[depth] * depthStep;

    // WIDTH
    const int widthStep = 1;
    const int widthStart = index_space_start[width] * widthStep;
    const int widthEnd = index_space_end[width] * widthStep;

    // HEIGHT
    const int heightStep = 1;
    const int heightStart = index_space_start[height] * heightStep;
    const int heightEnd = index_space_end[height] * heightStep;

    // BATCH
    const int batchStep = 1;
    const int batchStart = index_space_start[batch] * batchStep;
    const int batchtEnd = index_space_end[batch] * batchStep;

    int5 ifmCoords0, ifmCoords1, ofmCoords;

    float64_pair_t x;

    for (int d = depthStart; d < depthEnd; d += depthStep)
    {
        ifmCoords0[0] = ifmCoords1[0] = d;
        ofmCoords[0] = d;

        for (int b = batchStart; b < batchtEnd; b += batchStep)
        {
            ifmCoords0[3] =  ifmCoords1[3] = b;
            ofmCoords[3] = b;

            for (int h = heightStart; h < heightEnd; h += heightStep)
            {
                ifmCoords0[2] = ifmCoords1[2] = h;
                ofmCoords[2] = h;

                ifmCoords1[0] = ifmCoords0[0] + 64;

                for (int w = widthStart; w < widthEnd; w += widthStep)
                {

                    ifmCoords0[1] = ifmCoords1[1] = w;
                    ofmCoords[1] = w;

                    // Load input elements
                    x.v1 = v_f32_ld_tnsr_b(ifmCoords0, ifm);
                    x.v2 = v_f32_ld_tnsr_b(ifmCoords1, ifm);

                    bfloat128 y = 0;
                    y = v_convert_f32_to_bf16_all_b(x, SW_RHNE, y);
                    // Store and pack output data directly
                    v_bf16_st_tnsr(ofmCoords, ofm, y, SW_PACK);
                }
            }
        }
    }
}

