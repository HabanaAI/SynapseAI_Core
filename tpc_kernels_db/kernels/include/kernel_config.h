/* SPDX-License-Identifier: MIT
 *
 * Copyright 2016-2021 HabanaLabs, Ltd.
 * All Rights Reserved.
 *
 */
#if defined(FLOAT32)
#define VECTOR                      float64
#define v_ld_tnsr_i(a,b)            v_f32_ld_tnsr_b(a, b)
#define v_sel_less_v_s_v_v(a,b,c,d) v_f32_sel_less_f32_b(a, b, c, d)
#define v_sel_geq_v_s_v_v(a,b,c,d)    v_f32_sel_geq_f32_b(a, b, c, d)
#define v_sel_grt_v_s_v_v(a,b,c,d)    v_f32_sel_grt_f32_b(a, b, c, d)
#define st_tnsr_i_v(a,b,c)          v_f32_st_tnsr(a, b, c)
#endif

#if defined(BFLOAT16)
#define VECTOR                      bfloat128
#define v_ld_tnsr_i(a,b)            v_bf16_ld_tnsr_b(a, b)
#define v_sel_less_v_s_v_v(a,b,c,d) v_bf16_sel_less_bf16_b(a, b, c, d)
#define v_sel_geq_v_s_v_v(a,b,c,d)    v_bf16_sel_geq_bf16_b(a, b, c, d)
#define v_sel_grt_v_s_v_v(a,b,c,d)    v_bf16_sel_grt_bf16_b(a, b, c, d)
#define st_tnsr_i_v(a,b,c)          v_bf16_st_tnsr(a, b, c)

#endif
