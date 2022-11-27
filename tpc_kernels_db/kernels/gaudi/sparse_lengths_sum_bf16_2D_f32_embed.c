/* SPDX-License-Identifier: MIT
 *
 * Copyright 2016-2021 HabanaLabs, Ltd.
 * All Rights Reserved.
 *
 */
#pragma tpc_printf (enable)
// Cast bfloat128 into float128
bfloat128_pair_t cast_bf16_to_32bits_lin_order(bfloat128 x)
{
    bfloat128_pair_t y;
    bfloat128 tmp;

    // 0..15, 32..47, 64..79, 96..111
    y.v1 = v_bf16_unpack_b(x, e_group_0 << 8 | e_every_second_element << 9 | e_lower_half_group << 10, y.v1);
    // 16..31, 48..63, 80..95, 112..127
    y.v2 = v_bf16_unpack_b(x, e_group_1 << 8 | e_every_second_element << 9 | e_lower_half_group << 10, y.v2);

    tmp = y.v1;
    // Rearranges the vector in correct order
    // Move dualgroup0 of y.v2 to dualgroup1 of y.v1, 0..15, 16..31
    y.v1 = v_bf16_mov_dual_group_b(y.v2, 0xFFFFFFFF, 0, 1, MkWr(1, 1), y.v1);
    // Move dualgroup1 of y.v1 to dualgroup2 of y.v1, 0..15, 16..31, 32..47
    y.v1 = v_bf16_mov_dual_group_b(tmp, 0xFFFFFFFF, 1, 2, MkWr(1, 1), y.v1);
    // Move dualgroup1 of y.v2 to dualgroup3 of y.v1, 0..15, 16..31, 32..47, 48..63
    y.v1 = v_bf16_mov_dual_group_b(y.v2, 0xFFFFFFFF, 1, 3, MkWr(1, 1), y.v1);

    // Move dualgroup1 of y.v1 to dualgroup0 of y.v2, 64..79 48..63, 80..95, 112..127
    y.v2 = v_bf16_mov_dual_group_b(tmp, 0xFFFFFFFF, 2, 0, MkWr(1, 1), y.v2);
    // Move dualgroup2 of y.v2 to dualgroup1 of y.v2, 64..79 80..95, 80..95, 112..127
    y.v2 = v_bf16_mov_dual_group_b(y.v2, 0xFFFFFFFF, 2, 1, MkWr(1, 1), y.v2);
    // Move dualgroup3 of y.v1 to dualgroup2 of y.v2, 64..79 80..95, 96..111, 112..127
    y.v2 = v_bf16_mov_dual_group_b(tmp, 0xFFFFFFFF, 3, 2, MkWr(1, 1), y.v2);

    return y;
}

void main(tensor input_tensor,
          tensor indices_tensor,
          tensor lengths_tensor,
          tensor output_tensor)
{
    const int5 index_space_start = get_index_space_offset();
    const int5 index_space_end = get_index_space_size() + index_space_start;

    // DEPTH
    const int depth_step  = 128;
    const int depth_start = index_space_start[0] * depth_step;
    const int depth_end   = index_space_end[0] * depth_step;

    // WIDTH
    const int width_step  = 2;
    const int width_start = index_space_start[1] * width_step;
    const int width_end   = index_space_end[1] * width_step;

    int5 in_coord_1 = {0};
    int5 in_coord_2 = {0};
    int5 idx_coord_1 = {0};
    int5 idx_coord_2 = {0};
    int5 lengths_coord_1 = {0};
    int5 lengths_coord_2 = {0};
    int5 out_coord_1 = {0};
    int5 out_coord_2 = {0};
    int5 scale_bias_coord_1 = {0};
    int5 scale_bias_coord_2 = {0};

    const int input_dim0_len = get_dim_size(input_tensor, 0);
    //the column number for scale and bias (the two float values take up 4 int8 pockets each)
    const int scale_column = input_dim0_len - 8;

    //assigning scale column
    scale_bias_coord_1[0] = scale_bias_coord_2[0] = scale_column;

    // LUT1 for shuffling first element to all 64 elements of the first dual group
    const uchar256 lut1 = 0x80;
    // LUT2 for shuffling third element to all 64 elements of the first dual group
    const uchar256 lut2 = 0x82;

    int index_offset = 0;

    //finding the sum of length tensor upto the current element
    for(int segment_no = 0; segment_no < width_start; segment_no++)
    {
        lengths_coord_1[0] = segment_no;
        __global__ int* len_coord_ptr = gen_addr(lengths_coord_1, lengths_tensor);
        index_offset += s_i32_ld_g(len_coord_ptr);
    }
    //this is the index tensor offset
    const int index_offset_orig = index_offset;

    for (int depth = depth_start; depth < depth_end; depth += depth_step)
    {
        in_coord_1[0] = out_coord_1[0] = depth;
        in_coord_2[0] = out_coord_2[0] = depth;
        //after each iteration in depth, offset_1 is reset to the original length tensor offset
        int index_offset_1 = index_offset_orig;
        int index_offset_2;

        //iterating along the length tensor (i.e. the width of the output)
        for (int segment_no = width_start; segment_no < width_end; segment_no += width_step)
        {
            //processing two length elements at a time
            out_coord_1[1] = lengths_coord_1[0] = segment_no + 0;
            out_coord_2[1] = lengths_coord_2[0] = segment_no + 1;

            //address generation
            __global__ int* len_coord_ptr_1 = gen_addr(lengths_coord_1, lengths_tensor);
            __global__ int* len_coord_ptr_2 = gen_addr(lengths_coord_2, lengths_tensor);
            //obtaining the two segment lengths
            const int segment_length_1 = s_i32_ld_g(len_coord_ptr_1);
            const int segment_length_2 = s_i32_ld_g(len_coord_ptr_2);
            //offset_2 = offset_1 + segment_length_1
            index_offset_2 = index_offset_1 + segment_length_1;
            //finding the larger of the two lengths to iterate until
            int max_length = s_i32_max(segment_length_2, segment_length_1);
            //augmented float vector to hold the result
            float128 out_value_1 = {0};
            float128 out_value_2 = {0};
            //intermediate int augmented vectors for the conversion from char256 to float256
            bfloat128_pair_t in_value_1_bf16_av;
            bfloat128_pair_t in_value_2_bf16_av;

            idx_coord_1[0] = index_offset_1;
            idx_coord_2[0] = index_offset_2;
            //prologue
            __global__ int* idx_coord_ptr_1 = gen_addr(idx_coord_1, indices_tensor);
            __global__ int* idx_coord_ptr_2 = gen_addr(idx_coord_2, indices_tensor);

            scale_bias_coord_1[1] = in_coord_1[1] = s_i32_ld_g(idx_coord_ptr_1);
            scale_bias_coord_2[1] = in_coord_2[1] = s_i32_ld_g(idx_coord_ptr_2);
            //loading value from input
            bfloat128 in_value_1 = v_bf16_ld_tnsr_b(in_coord_1, input_tensor);
            bfloat128 in_value_2 = v_bf16_ld_tnsr_b(in_coord_2, input_tensor);

            //loading the vector containing the bias and the zp
            float64 scale_zp_1 = v_f32_ld_tnsr_low_b(scale_bias_coord_1, input_tensor);
            float64 scale_zp_2 = v_f32_ld_tnsr_low_b(scale_bias_coord_2, input_tensor);

            //extracting scale and zp into separate vectors
            /* Extract scale and broadcast to the whole vector */
            // Shuffle first element of vector to dual group 0
            float64 scale_1_v = v_f32_shuffle_b(scale_zp_1, lut1, 0, scale_zp_1);
            float64 scale_2_v = v_f32_shuffle_b(scale_zp_2, lut1, 0, scale_zp_2);
            printf("value 0 in vector scale_1_v is %f\n", scale_1_v[0]);

            // Move dual group 0 to dual group 1
            scale_1_v = v_f32_mov_dual_group_b(scale_1_v, 0xFFFFFFFF, 0, 1, MkWr(1, 1), scale_1_v);
            scale_2_v = v_f32_mov_dual_group_b(scale_2_v, 0xFFFFFFFF, 0, 1, MkWr(1, 1), scale_2_v);
            // Move dual group 0 to dual group 2
            scale_1_v = v_f32_mov_dual_group_b(scale_1_v, 0xFFFFFFFF, 0, 2, MkWr(1, 1), scale_1_v);
            scale_2_v = v_f32_mov_dual_group_b(scale_2_v, 0xFFFFFFFF, 0, 2, MkWr(1, 1), scale_2_v);
            // Move dual group 0 to dual group 3
            scale_1_v = v_f32_mov_dual_group_b(scale_1_v, 0xFFFFFFFF, 0, 3, MkWr(1, 1), scale_1_v);
            scale_2_v = v_f32_mov_dual_group_b(scale_2_v, 0xFFFFFFFF, 0, 3, MkWr(1, 1), scale_2_v);

            //assuming that the second column of the scale-bias tensor is filled with -sc*zp values
            float64 neg_scale_x_bias_1_v = v_f32_shuffle_b(scale_zp_1, lut2, 0, scale_zp_1);
            float64 neg_scale_x_bias_2_v = v_f32_shuffle_b(scale_zp_2, lut2, 0, scale_zp_2);

            // Move dual group 0 to dual group 1
            neg_scale_x_bias_1_v = v_f32_mov_dual_group_b(neg_scale_x_bias_1_v, 0xFFFFFFFF, 0, 1, MkWr(1, 1), \
                 neg_scale_x_bias_1_v);
            neg_scale_x_bias_2_v = v_f32_mov_dual_group_b(neg_scale_x_bias_2_v, 0xFFFFFFFF, 0, 1, MkWr(1, 1), \
                 neg_scale_x_bias_2_v);
            // Move dual group 0 to dual group 2
            neg_scale_x_bias_1_v = v_f32_mov_dual_group_b(neg_scale_x_bias_1_v, 0xFFFFFFFF, 0, 2, MkWr(1, 1), \
                 neg_scale_x_bias_1_v);
            neg_scale_x_bias_2_v = v_f32_mov_dual_group_b(neg_scale_x_bias_2_v, 0xFFFFFFFF, 0, 2, MkWr(1, 1), \
                 neg_scale_x_bias_2_v);
            // Move dual group 0 to dual group 3
            neg_scale_x_bias_1_v = v_f32_mov_dual_group_b(neg_scale_x_bias_1_v, 0xFFFFFFFF, 0, 3, MkWr(1, 1), \
                 neg_scale_x_bias_1_v);
            neg_scale_x_bias_2_v = v_f32_mov_dual_group_b(neg_scale_x_bias_2_v, 0xFFFFFFFF, 0, 3, MkWr(1, 1), \
                 neg_scale_x_bias_2_v);

            //char256 to int256
            in_value_1_bf16_av = cast_bf16_to_32bits_lin_order(in_value_1);
            in_value_2_bf16_av = cast_bf16_to_32bits_lin_order(in_value_2);

            float128 in_value_1_float_0, in_value_1_float_1;
            float128 in_value_2_float_0, in_value_2_float_1;

            //iterating through the elements to be accumulated
            for (int element_no = 1; element_no < max_length; element_no++)
            {
                //this predicate lets us stop accumulating past the the segment length selectively
                char pred_1 = s_i32_cmp_leq(element_no, segment_length_1);
                char pred_2 = s_i32_cmp_leq(element_no, segment_length_2);

                //conversion to f32
                in_value_1_float_0 = v_convert_bf16_to_f32_all_b(in_value_1_bf16_av.v1);
                in_value_1_float_1 = v_convert_bf16_to_f32_all_b(in_value_1_bf16_av.v2);
                //application of scale and bias
                in_value_1_float_0.v1 = v_f32_mac_b(in_value_1_float_0.v1, scale_1_v, neg_scale_x_bias_1_v, e_no_negation << 1);
                in_value_1_float_1.v1 = v_f32_mac_b(in_value_1_float_1.v1, scale_1_v, neg_scale_x_bias_1_v, e_no_negation << 1);
                //conversion to f32
                in_value_2_float_0 = v_convert_bf16_to_f32_all_b(in_value_2_bf16_av.v1);
                in_value_2_float_1 = v_convert_bf16_to_f32_all_b(in_value_2_bf16_av.v2);
                //application of scale and bias
                in_value_2_float_0.v1 = v_f32_mac_b(in_value_2_float_0.v1, scale_2_v, neg_scale_x_bias_2_v, e_no_negation << 1);
                in_value_2_float_1.v1 = v_f32_mac_b(in_value_2_float_1.v1, scale_2_v, neg_scale_x_bias_2_v, e_no_negation << 1);

                //next index coordinate
                idx_coord_1[0]++;
                idx_coord_2[0]++;

                idx_coord_ptr_1 = gen_addr(idx_coord_1, indices_tensor);
                idx_coord_ptr_2 = gen_addr(idx_coord_2, indices_tensor);

                scale_bias_coord_1[1] = in_coord_1[1] = s_i32_ld_g(idx_coord_ptr_1);
                scale_bias_coord_2[1] = in_coord_2[1] = s_i32_ld_g(idx_coord_ptr_2);
                //loading value from input
                in_value_1 = v_bf16_ld_tnsr_b(in_coord_1, input_tensor);
                in_value_2 = v_bf16_ld_tnsr_b(in_coord_2, input_tensor);

                //char256 to float256
                in_value_1_bf16_av = cast_bf16_to_32bits_lin_order(in_value_1);
                in_value_2_bf16_av = cast_bf16_to_32bits_lin_order(in_value_2);
                //accumulating
                out_value_1.v1 = v_f32_add_b(out_value_1.v1, in_value_1_float_0.v1, 0, out_value_1.v1, pred_1);
                out_value_1.v2 = v_f32_add_b(out_value_1.v2, in_value_1_float_1.v1, 0, out_value_1.v2, pred_1);
                out_value_2.v1 = v_f32_add_b(out_value_2.v1, in_value_2_float_0.v1, 0, out_value_2.v1, pred_2);
                out_value_2.v2 = v_f32_add_b(out_value_2.v2, in_value_2_float_1.v1, 0, out_value_2.v2, pred_2);

                //scale is loaded from input tensor in the embedded version
                //loading the vector containing the scale and the zp
                float64 scale_zp_1 = v_f32_ld_tnsr_low_b(scale_bias_coord_1, input_tensor);
                float64 scale_zp_2 = v_f32_ld_tnsr_low_b(scale_bias_coord_2, input_tensor);

                //extracting scale and zp into separate vectors
                /* Extract scale and broadcast to the whole vector */
                // Shuffle first element of vector to dual group 0
                scale_1_v = v_f32_shuffle_b(scale_zp_1, lut1, 0, scale_zp_1);
                scale_2_v = v_f32_shuffle_b(scale_zp_2, lut1, 0, scale_zp_2);
                // Move dual group 0 to dual group 1
                scale_1_v = v_f32_mov_dual_group_b(scale_1_v, 0xFFFFFFFF, 0, 1, MkWr(1, 1), scale_1_v);
                scale_2_v = v_f32_mov_dual_group_b(scale_2_v, 0xFFFFFFFF, 0, 1, MkWr(1, 1), scale_2_v);
                // Move dual group 0 to dual group 2
                scale_1_v = v_f32_mov_dual_group_b(scale_1_v, 0xFFFFFFFF, 0, 2, MkWr(1, 1), scale_1_v);
                scale_2_v = v_f32_mov_dual_group_b(scale_2_v, 0xFFFFFFFF, 0, 2, MkWr(1, 1), scale_2_v);
                // Move dual group 0 to dual group 3
                scale_1_v = v_f32_mov_dual_group_b(scale_1_v, 0xFFFFFFFF, 0, 3, MkWr(1, 1), scale_1_v);
                scale_2_v = v_f32_mov_dual_group_b(scale_2_v, 0xFFFFFFFF, 0, 3, MkWr(1, 1), scale_2_v);

                //assuming that the second column of the scale-bias tensor is filled with -sc*zp values
                neg_scale_x_bias_1_v = v_f32_shuffle_b(scale_zp_1, lut2, 0, scale_zp_1);
                neg_scale_x_bias_2_v = v_f32_shuffle_b(scale_zp_2, lut2, 0, scale_zp_2);

                // Move dual group 0 to dual group 1
                neg_scale_x_bias_1_v = v_f32_mov_dual_group_b(neg_scale_x_bias_1_v, 0xFFFFFFFF, 0, 1, MkWr(1, 1), \
                     neg_scale_x_bias_1_v);
                neg_scale_x_bias_2_v = v_f32_mov_dual_group_b(neg_scale_x_bias_2_v, 0xFFFFFFFF, 0, 1, MkWr(1, 1), \
                     neg_scale_x_bias_2_v);
                // Move dual group 0 to dual group 2
                neg_scale_x_bias_1_v = v_f32_mov_dual_group_b(neg_scale_x_bias_1_v, 0xFFFFFFFF, 0, 2, MkWr(1, 1), \
                     neg_scale_x_bias_1_v);
                neg_scale_x_bias_2_v = v_f32_mov_dual_group_b(neg_scale_x_bias_2_v, 0xFFFFFFFF, 0, 2, MkWr(1, 1), \
                     neg_scale_x_bias_2_v);
                // Move dual group 0 to dual group 3
                neg_scale_x_bias_1_v = v_f32_mov_dual_group_b(neg_scale_x_bias_1_v, 0xFFFFFFFF, 0, 3, MkWr(1, 1), \
                     neg_scale_x_bias_1_v);
                neg_scale_x_bias_2_v = v_f32_mov_dual_group_b(neg_scale_x_bias_2_v, 0xFFFFFFFF, 0, 3, MkWr(1, 1), \
                     neg_scale_x_bias_2_v);

            }
            //epilogue

            char pred_1 = s_i32_cmp_leq(max_length, segment_length_1);
            char pred_2 = s_i32_cmp_leq(max_length, segment_length_2);

            in_value_1_float_0 = v_convert_bf16_to_f32_all_b(in_value_1_bf16_av.v1);
            in_value_1_float_1 = v_convert_bf16_to_f32_all_b(in_value_1_bf16_av.v2);
            in_value_1_float_0.v1 = v_f32_mac_b(in_value_1_float_0.v1, scale_1_v, neg_scale_x_bias_1_v, e_no_negation << 1);
            in_value_1_float_1.v1 = v_f32_mac_b(in_value_1_float_1.v1, scale_1_v, neg_scale_x_bias_1_v, e_no_negation << 1);

            in_value_2_float_0 = v_convert_bf16_to_f32_all_b(in_value_2_bf16_av.v1);
            in_value_2_float_1 = v_convert_bf16_to_f32_all_b(in_value_2_bf16_av.v2);
            in_value_2_float_0.v1 = v_f32_mac_b(in_value_2_float_0.v1, scale_2_v, neg_scale_x_bias_2_v, e_no_negation << 1);
            in_value_2_float_1.v1 = v_f32_mac_b(in_value_2_float_1.v1, scale_2_v, neg_scale_x_bias_2_v, e_no_negation << 1);

            out_value_1.v1 = v_f32_add_b(out_value_1.v1, in_value_1_float_0.v1, 0, out_value_1.v1, pred_1);
            out_value_1.v2 = v_f32_add_b(out_value_1.v2, in_value_1_float_1.v1, 0, out_value_1.v2, pred_1);
            out_value_2.v1 = v_f32_add_b(out_value_2.v1, in_value_2_float_0.v1, 0, out_value_2.v1, pred_2);
            out_value_2.v2 = v_f32_add_b(out_value_2.v2, in_value_2_float_1.v1, 0, out_value_2.v2, pred_2);
            //epilogue ends here

            //for next iteration, offset is calculated from the last segment of the current iteration
            index_offset_1 = index_offset_2 + segment_length_2;

            //store the output vectors
            v_f32_st_tnsr(out_coord_1, output_tensor, out_value_1.v1); out_coord_1[0] += 64;
            v_f32_st_tnsr(out_coord_1, output_tensor, out_value_1.v2); out_coord_1[0] -= 64;
            v_f32_st_tnsr(out_coord_2, output_tensor, out_value_2.v1); out_coord_2[0] += 64;
            v_f32_st_tnsr(out_coord_2, output_tensor, out_value_2.v2); out_coord_2[0] -= 64;
        }
    }
}
