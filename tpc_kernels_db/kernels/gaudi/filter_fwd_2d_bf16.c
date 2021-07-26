/* SPDX-License-Identifier: MIT
 *
 * Copyright 2016-2021 HabanaLabs, Ltd.
 * All Rights Reserved.
 *
 */
void main(tensor ifm,
          tensor filter,
          tensor ofm,
            int padw,
            int padh,
            int kernel_w,
            int kernel_h,
            int stride_w,
            int stride_h,
            int dilation_w,
            int dilation_h)
{
    int5 index_space_start = get_index_space_offset();
    int5 index_space_end = get_index_space_size() + index_space_start;
    int5 output_coords = {0};
    for (int b = index_space_start[3] ; b <  index_space_end[3]; b += 1)
    {
        output_coords[3] = b;
        for (int h = index_space_start[2] ; h <  index_space_end[2]; h += 1)
        {
            output_coords[2] = h;
            for (int w = index_space_start[1] ; w <  index_space_end[1]; w += 1)
            {
                output_coords[1] = w;
                for (int d = index_space_start[0]*128 ; d <  index_space_end[0]*128; d += 128)
                {
                    int5 filterCoords = {0};
                    output_coords[0] = d;
                    filterCoords[0] = d;
                    float128 accum = {0};
                    for (int kh = 0 ; kh <  kernel_h; kh++)
                    {
                        filterCoords[2] = kh;
                        //int kw = 0;
                        for (int kw = 0 ; kw <  kernel_w; kw++)
                        {
                            filterCoords[1] = kw;
                            int5 ifmCoords = {d,
                                              (stride_w*w) - padw + (kw*dilation_w),
                                              (stride_h*h) - padh + (kh*dilation_h) ,
                                               b,
                                               0};
                            bfloat128 filterVector = v_bf16_ld_tnsr_b(filterCoords, filter);
                            bfloat128 ifmVector = v_bf16_ld_tnsr_b(ifmCoords, ifm);
                            accum = v_bf16_mac_acc32_b(filterVector, ifmVector, accum, (e_no_negation) << 1);
                        }
                    }
                    bfloat128 out = v_convert_f32_to_bf16_all_b (accum);
                    v_bf16_st_tnsr(output_coords, ofm, out);
                }
            }
        }
    }
}
