/* SPDX-License-Identifier: MIT
 *
 * Copyright 2016-2021 HabanaLabs, Ltd.
 * All Rights Reserved.
 *
 */
void main(tensor ifm,
          tensor ofm,
          float scaleToF32)
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

    int5 ifmCoords, ofmCoords0, ofmCoords1;

    bfloat128 in;
    bfloat128_pair_t y;
    bfloat128 tmp;
    float128 out0, out1;

    for (int d = depthStart; d < depthEnd; d += depthStep)
    {
        ifmCoords[0] = d;
        ofmCoords0[0] = d;

        for (int b = batchStart; b < batchtEnd; b += batchStep)
        {
            ifmCoords[3] = b;
            ofmCoords0[3] =ofmCoords1[3] = b;

            for (int h = heightStart; h < heightEnd; h += heightStep)
            {
                ifmCoords[2] = h;
                ofmCoords0[2] = ofmCoords1[2] = h;

                ofmCoords1[0] = ofmCoords0[0] + 64;

                for (int w = widthStart; w < widthEnd; w += widthStep)
                {

                    ifmCoords[1] = w;
                    ofmCoords0[1] =ofmCoords1[1] = w;
                    in = v_bf16_ld_tnsr_b(ifmCoords, ifm);

                    // Cast bfloat128 into float128
                    // Note: bfloat128 vector contains 4 dual groups and each dual group has 32 elements
                    // Unpacks lower half of first group of all 4 dual gorups
                    // 0..15, 32..47, 64..79, 96..111
                    y.v1 = v_bf16_unpack_b(in, e_group_0 << 8 | e_every_second_element << 9 | e_lower_half_group << 10, y.v1);
                    // Unpacks lower half of second group of all 4 dual gorups
                    // 16..31, 48..63, 80..95, 112..127
                    y.v2 = v_bf16_unpack_b(in, e_group_1 << 8 | e_every_second_element << 9 | e_lower_half_group << 10, y.v2);

                    tmp = y.v1;
                    // Rearranges the vector in correct order
                    // Move dualgroup0 of y.v2 to dualgroup1 of y.v1
                    // 0..15, 16..31
                    y.v1 = v_bf16_mov_dual_group_b(y.v2, 0xFFFFFFFF, 0, 1, MkWr(1, 1), y.v1);
                    // Move dualgroup1 of y.v1 to dualgroup2 of y.v1
                    // 0..15, 16..31, 32..47
                    y.v1 = v_bf16_mov_dual_group_b(tmp, 0xFFFFFFFF, 1, 2, MkWr(1, 1), y.v1);
                    // Move dualgroup1 of y.v2 to dualgroup3 of y.v1
                    // 0..15, 16..31, 32..47, 48..63
                    y.v1 = v_bf16_mov_dual_group_b(y.v2, 0xFFFFFFFF, 1, 3, MkWr(1, 1), y.v1);


                    // Move dualgroup1 of y.v1 to dualgroup0 of y.v2
                    // 64..79 48..63, 80..95, 112..127
                    y.v2 = v_bf16_mov_dual_group_b(tmp, 0xFFFFFFFF, 2, 0, MkWr(1, 1), y.v2);
                    // Move dualgroup2 of y.v2 to dualgroup1 of y.v2
                    // 64..79 80..95, 80..95, 112..127
                    y.v2 = v_bf16_mov_dual_group_b(y.v2, 0xFFFFFFFF, 2, 1, MkWr(1, 1), y.v2);
                    // Move dualgroup3 of y.v1 to dualgroup2 of y.v2
                    // 64..79 80..95, 96..111, 112..127
                    y.v2 = v_bf16_mov_dual_group_b(tmp, 0xFFFFFFFF, 3, 2, MkWr(1, 1), y.v2);

                    // only save the v1 part, v2 are 0
                    out0 = v_convert_bf16_to_f32_all_b(y.v1);
                    v_f32_st_tnsr(ofmCoords0, ofm, out0.v1);
                    // only save the v1 part, v2 are 0
                    out1 = v_convert_bf16_to_f32_all_b(y.v2);
                    v_f32_st_tnsr(ofmCoords1, ofm, out1.v1);

                }
            }
        }
    }
}

