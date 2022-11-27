/***********************************
** This is an auto-generated file **
**       DO NOT EDIT BELOW        **
************************************/

#ifndef ASIC_REG_STRUCTS_TPC_H_
#define ASIC_REG_STRUCTS_TPC_H_

#include <stdint.h>
#include "gaudi2_types.h"
#include "axuser_regs.h"
#include "special_regs_regs.h"
#include "sync_object_regs.h"
#include "tpc_non_tensor_descriptor_regs.h"
#include "tpc_tensor_regs.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace gaudi2 {
namespace tpc {
#else
#	ifndef static_assert
#		if defined( __STDC__ ) && defined( __STDC_VERSION__ ) && __STDC_VERSION__ >= 201112L
#			define static_assert(...) _Static_assert(__VA_ARGS__)
#		else
#			define static_assert(...)
#		endif
#	endif
#endif

/*
 TPC_COUNT 
 b"number of TPC's"
*/
typedef struct reg_tpc_count {
	union {
		struct {
			uint32_t v : 32;
		};
		uint32_t _raw;
	};
} reg_tpc_count;
static_assert((sizeof(struct reg_tpc_count) == 4), "reg_tpc_count size is not 32-bit");
/*
 TPC_ID 
 b'TPC unique ID'
*/
typedef struct reg_tpc_id {
	union {
		struct {
			uint32_t v : 32;
		};
		uint32_t _raw;
	};
} reg_tpc_id;
static_assert((sizeof(struct reg_tpc_id) == 4), "reg_tpc_id size is not 32-bit");
/*
 STALL_ON_ERR 
 b'stall TPC when interrupt occurs'
*/
typedef struct reg_stall_on_err {
	union {
		struct {
			uint32_t v : 1,
				_reserved1 : 31;
		};
		uint32_t _raw;
	};
} reg_stall_on_err;
static_assert((sizeof(struct reg_stall_on_err) == 4), "reg_stall_on_err size is not 32-bit");
/*
 CLK_EN 
 b'chicken bits: disable waking up HBW upon LBW/DBG'
*/
typedef struct reg_clk_en {
	union {
		struct {
			uint32_t lbw_cfg_dis : 1,
				_reserved4 : 3,
				dbg_cfg_dis : 1,
				_reserved5 : 27;
		};
		uint32_t _raw;
	};
} reg_clk_en;
static_assert((sizeof(struct reg_clk_en) == 4), "reg_clk_en size is not 32-bit");
/*
 IQ_RL_EN 
 b'Tpc IQ rate limiter enable'
*/
typedef struct reg_iq_rl_en {
	union {
		struct {
			uint32_t v : 1,
				_reserved1 : 31;
		};
		uint32_t _raw;
	};
} reg_iq_rl_en;
static_assert((sizeof(struct reg_iq_rl_en) == 4), "reg_iq_rl_en size is not 32-bit");
/*
 IQ_RL_SAT 
 b'Tpc IQ rate limiter saturation value'
*/
typedef struct reg_iq_rl_sat {
	union {
		struct {
			uint32_t v : 8,
				_reserved8 : 24;
		};
		uint32_t _raw;
	};
} reg_iq_rl_sat;
static_assert((sizeof(struct reg_iq_rl_sat) == 4), "reg_iq_rl_sat size is not 32-bit");
/*
 IQ_RL_RST_TOKEN 
 b'Tpc IQ rate limiter reset token'
*/
typedef struct reg_iq_rl_rst_token {
	union {
		struct {
			uint32_t v : 8,
				_reserved8 : 24;
		};
		uint32_t _raw;
	};
} reg_iq_rl_rst_token;
static_assert((sizeof(struct reg_iq_rl_rst_token) == 4), "reg_iq_rl_rst_token size is not 32-bit");
/*
 IQ_RL_TIMEOUT 
 b'Tpc IQ rate limiter timeout'
*/
typedef struct reg_iq_rl_timeout {
	union {
		struct {
			uint32_t v : 8,
				_reserved8 : 24;
		};
		uint32_t _raw;
	};
} reg_iq_rl_timeout;
static_assert((sizeof(struct reg_iq_rl_timeout) == 4), "reg_iq_rl_timeout size is not 32-bit");
/*
 TSB_CFG_MTRR_2 
 b'TSB MTRR cfg2'
*/
typedef struct reg_tsb_cfg_mtrr_2 {
	union {
		struct {
			uint32_t phy_base_add_lo : 24,
				_reserved24 : 8;
		};
		uint32_t _raw;
	};
} reg_tsb_cfg_mtrr_2;
static_assert((sizeof(struct reg_tsb_cfg_mtrr_2) == 4), "reg_tsb_cfg_mtrr_2 size is not 32-bit");
/*
 IQ_LBW_CLK_EN 
 b'use lbw_clk bypass for iq'
*/
typedef struct reg_iq_lbw_clk_en {
	union {
		struct {
			uint32_t v : 1,
				_reserved1 : 31;
		};
		uint32_t _raw;
	};
} reg_iq_lbw_clk_en;
static_assert((sizeof(struct reg_iq_lbw_clk_en) == 4), "reg_iq_lbw_clk_en size is not 32-bit");
/*
 TPC_LOCK_VALUE 
 b'TPC lock value'
*/
typedef struct reg_tpc_lock_value {
	union {
		struct {
			uint32_t value : 32;
		};
		uint32_t _raw;
	};
} reg_tpc_lock_value;
static_assert((sizeof(struct reg_tpc_lock_value) == 4), "reg_tpc_lock_value size is not 32-bit");
/*
 TPC_LOCK 
 b'TPC lock'
*/
typedef struct reg_tpc_lock {
	union {
		struct {
			uint32_t lock : 1,
				_reserved1 : 31;
		};
		uint32_t _raw;
	};
} reg_tpc_lock;
static_assert((sizeof(struct reg_tpc_lock) == 4), "reg_tpc_lock size is not 32-bit");
/*
 CGU_SB 
 b'CGU SB Configuration Disable'
*/
typedef struct reg_cgu_sb {
	union {
		struct {
			uint32_t tsb_disable : 1,
				_reserved1 : 31;
		};
		uint32_t _raw;
	};
} reg_cgu_sb;
static_assert((sizeof(struct reg_cgu_sb) == 4), "reg_cgu_sb size is not 32-bit");
/*
 CGU_CNT 
 b'CGU CNT Configuration Disable'
*/
typedef struct reg_cgu_cnt {
	union {
		struct {
			uint32_t dcache_disable : 1,
				wq_disable : 1,
				spu_agu_addsub_0_disable : 1,
				spu_agu_addsub_1_disable : 1,
				spu_agu_addsub_2_disable : 1,
				spu_agu_addsub_3_disable : 1,
				spu_agu_addsub_4_disable : 1,
				spu_agu_cmp_0_disable : 1,
				spu_agu_cmp_1_disable : 1,
				spu_agu_cmp_2_disable : 1,
				spu_agu_cmp_3_disable : 1,
				spu_agu_cmp_4_disable : 1,
				msac_disable : 1,
				conv_disable : 1,
				nearbyint_disable : 1,
				cmp_disable : 1,
				fp_mac_disable : 1,
				sops_src_a_d2_disable : 1,
				sops_src_b_d2_disable : 1,
				sops_src_e_d2_disable : 1,
				sops_fma_src_c_e1_disable : 1,
				ld_sops_src_a_d2_disable : 1,
				st_sops_src_a_d2_disable : 1,
				fp_addsub_disable : 1,
				_reserved24 : 8;
		};
		uint32_t _raw;
	};
} reg_cgu_cnt;
static_assert((sizeof(struct reg_cgu_cnt) == 4), "reg_cgu_cnt size is not 32-bit");
/*
 CGU_CPE 
 b'CGU CPE  Configuration Disable'
*/
typedef struct reg_cgu_cpe {
	union {
		struct {
			uint32_t nearbyint_disable : 1,
				sops_src_a_disable : 1,
				sops_src_b_disable : 1,
				sops_src_e_disable : 1,
				sops_src_d_disable : 1,
				sops_src_c_disable : 1,
				ld_sops_src_a_disable : 1,
				msac_disable : 1,
				addsub_disable : 1,
				shift_disable : 1,
				gle_disable : 1,
				cmp_disable : 1,
				conv_disable : 1,
				sb_disable : 1,
				tbuf_disable : 1,
				st_g_disable : 1,
				fp_mac_0_disable : 1,
				fp_mac_1_disable : 1,
				fp_addsub_disable : 1,
				st_sops_src_c_disable : 1,
				_reserved20 : 12;
		};
		uint32_t _raw;
	};
} reg_cgu_cpe;
static_assert((sizeof(struct reg_cgu_cpe) == 4), "reg_cgu_cpe size is not 32-bit");
/*
 FP16_FTZ_IN 
 b'Flush FP16 denormals to 0 at FMA input\xc3\xa2\xc2\x80\xc2\x8b'
*/
typedef struct reg_fp16_ftz_in {
	union {
		struct {
			uint32_t mode : 1,
				_reserved1 : 31;
		};
		uint32_t _raw;
	};
} reg_fp16_ftz_in;
static_assert((sizeof(struct reg_fp16_ftz_in) == 4), "reg_fp16_ftz_in size is not 32-bit");
/*
 DCACHE_CFG 
 b'Dcache Config'
*/
typedef struct reg_dcache_cfg {
	union {
		struct {
			uint32_t g_pref_dis : 1,
				g_pref_vld_clr : 1,
				halt_flush : 1,
				dealign_dis : 1,
				_reserved4 : 28;
		};
		uint32_t _raw;
	};
} reg_dcache_cfg;
static_assert((sizeof(struct reg_dcache_cfg) == 4), "reg_dcache_cfg size is not 32-bit");
/*
 E2E_CRDT_TOP 
 b'e2e crdt top force en and force val'
*/
typedef struct reg_e2e_crdt_top {
	union {
		struct {
			uint32_t force_en : 1,
				_reserved4 : 3,
				y_x_force : 9,
				_reserved13 : 19;
		};
		uint32_t _raw;
	};
} reg_e2e_crdt_top;
static_assert((sizeof(struct reg_e2e_crdt_top) == 4), "reg_e2e_crdt_top size is not 32-bit");
/*
 TPC_DCACHE_L0CD 
 b'L0 DCACHE Cache Disable'
*/
typedef struct reg_tpc_dcache_l0cd {
	union {
		struct {
			uint32_t val : 1,
				_reserved1 : 31;
		};
		uint32_t _raw;
	};
} reg_tpc_dcache_l0cd;
static_assert((sizeof(struct reg_tpc_dcache_l0cd) == 4), "reg_tpc_dcache_l0cd size is not 32-bit");
/*
 TPC_SB_L0CD 
 b'L0 SB Cache Disable'
*/
typedef struct reg_tpc_sb_l0cd {
	union {
		struct {
			uint32_t val : 1,
				_reserved1 : 31;
		};
		uint32_t _raw;
	};
} reg_tpc_sb_l0cd;
static_assert((sizeof(struct reg_tpc_sb_l0cd) == 4), "reg_tpc_sb_l0cd size is not 32-bit");
/*
 CONV_ROUND_CSR 
 b'Converter Round CSR'
*/
typedef struct reg_conv_round_csr {
	union {
		struct {
			uint32_t mode : 3,
				_reserved3 : 29;
		};
		uint32_t _raw;
	};
} reg_conv_round_csr;
static_assert((sizeof(struct reg_conv_round_csr) == 4), "reg_conv_round_csr size is not 32-bit");
/*
 TSB_OCCUPANCY 
 b'current number of CLs in SB'
*/
typedef struct reg_tsb_occupancy {
	union {
		struct {
			uint32_t v : 32;
		};
		uint32_t _raw;
	};
} reg_tsb_occupancy;
static_assert((sizeof(struct reg_tsb_occupancy) == 4), "reg_tsb_occupancy size is not 32-bit");
/*
 ARB_QNT_HBW_WEIGHT 
 b'QNT hbw arbitration weight'
*/
typedef struct reg_arb_qnt_hbw_weight {
	union {
		struct {
			uint32_t ar : 12,
				aw : 8,
				_reserved20 : 12;
		};
		uint32_t _raw;
	};
} reg_arb_qnt_hbw_weight;
static_assert((sizeof(struct reg_arb_qnt_hbw_weight) == 4), "reg_arb_qnt_hbw_weight size is not 32-bit");
/*
 ARB_QNT_LBW_WEIGHT 
 b'QNT lbw arbitration weight'
*/
typedef struct reg_arb_qnt_lbw_weight {
	union {
		struct {
			uint32_t aw : 8,
				ar : 8,
				_reserved16 : 16;
		};
		uint32_t _raw;
	};
} reg_arb_qnt_lbw_weight;
static_assert((sizeof(struct reg_arb_qnt_lbw_weight) == 4), "reg_arb_qnt_lbw_weight size is not 32-bit");
/*
 ARB_CNT_HBW_WEIGHT 
 b'CNT hbw arbitration weight'
*/
typedef struct reg_arb_cnt_hbw_weight {
	union {
		struct {
			uint32_t ar : 12,
				aw : 12,
				_reserved24 : 8;
		};
		uint32_t _raw;
	};
} reg_arb_cnt_hbw_weight;
static_assert((sizeof(struct reg_arb_cnt_hbw_weight) == 4), "reg_arb_cnt_hbw_weight size is not 32-bit");
/*
 ARB_CNT_LBW_WEIGHT 
 b'CNT lbw arbitration weight'
*/
typedef struct reg_arb_cnt_lbw_weight {
	union {
		struct {
			uint32_t ar : 8,
				aw : 12,
				_reserved20 : 12;
		};
		uint32_t _raw;
	};
} reg_arb_cnt_lbw_weight;
static_assert((sizeof(struct reg_arb_cnt_lbw_weight) == 4), "reg_arb_cnt_lbw_weight size is not 32-bit");
/*
 LUT_FUNC32_BASE2_ADDR_LO 
 b'LOOKUP TABLE 32 lines Base2 Address 32 LSB'
*/
typedef struct reg_lut_func32_base2_addr_lo {
	union {
		struct {
			uint32_t v : 32;
		};
		uint32_t _raw;
	};
} reg_lut_func32_base2_addr_lo;
static_assert((sizeof(struct reg_lut_func32_base2_addr_lo) == 4), "reg_lut_func32_base2_addr_lo size is not 32-bit");
/*
 LUT_FUNC32_BASE2_ADDR_HI 
 b'LOOKUP TABLE 32 lines Base2 Address 32 MSB'
*/
typedef struct reg_lut_func32_base2_addr_hi {
	union {
		struct {
			uint32_t v : 32;
		};
		uint32_t _raw;
	};
} reg_lut_func32_base2_addr_hi;
static_assert((sizeof(struct reg_lut_func32_base2_addr_hi) == 4), "reg_lut_func32_base2_addr_hi size is not 32-bit");
/*
 LUT_FUNC64_BASE2_ADDR_LO 
 b'LOOKUP TABLE 64 lines Base2 Address 32 LSB'
*/
typedef struct reg_lut_func64_base2_addr_lo {
	union {
		struct {
			uint32_t v : 32;
		};
		uint32_t _raw;
	};
} reg_lut_func64_base2_addr_lo;
static_assert((sizeof(struct reg_lut_func64_base2_addr_lo) == 4), "reg_lut_func64_base2_addr_lo size is not 32-bit");
/*
 LUT_FUNC64_BASE2_ADDR_HI 
 b'LOOKUP TABLE 64 lines Base2 Address 32 MSB'
*/
typedef struct reg_lut_func64_base2_addr_hi {
	union {
		struct {
			uint32_t v : 32;
		};
		uint32_t _raw;
	};
} reg_lut_func64_base2_addr_hi;
static_assert((sizeof(struct reg_lut_func64_base2_addr_hi) == 4), "reg_lut_func64_base2_addr_hi size is not 32-bit");
/*
 LUT_FUNC128_BASE2_ADDR_LO 
 b'LOOKUP TABLE 128 lines Base2 Address 32 LSB'
*/
typedef struct reg_lut_func128_base2_addr_lo {
	union {
		struct {
			uint32_t v : 32;
		};
		uint32_t _raw;
	};
} reg_lut_func128_base2_addr_lo;
static_assert((sizeof(struct reg_lut_func128_base2_addr_lo) == 4), "reg_lut_func128_base2_addr_lo size is not 32-bit");
/*
 LUT_FUNC128_BASE2_ADDR_HI 
 b'LOOKUP TABLE 128 lines Base2 Address 32 MSB'
*/
typedef struct reg_lut_func128_base2_addr_hi {
	union {
		struct {
			uint32_t v : 32;
		};
		uint32_t _raw;
	};
} reg_lut_func128_base2_addr_hi;
static_assert((sizeof(struct reg_lut_func128_base2_addr_hi) == 4), "reg_lut_func128_base2_addr_hi size is not 32-bit");
/*
 LUT_FUNC256_BASE2_ADDR_LO 
 b'LOOKUP TABLE 256 lines Base2 Address 32 LSB'
*/
typedef struct reg_lut_func256_base2_addr_lo {
	union {
		struct {
			uint32_t v : 32;
		};
		uint32_t _raw;
	};
} reg_lut_func256_base2_addr_lo;
static_assert((sizeof(struct reg_lut_func256_base2_addr_lo) == 4), "reg_lut_func256_base2_addr_lo size is not 32-bit");
/*
 LUT_FUNC256_BASE2_ADDR_HI 
 b'LOOKUP TABLE 256 lines Base2 Address 32 MSB'
*/
typedef struct reg_lut_func256_base2_addr_hi {
	union {
		struct {
			uint32_t v : 32;
		};
		uint32_t _raw;
	};
} reg_lut_func256_base2_addr_hi;
static_assert((sizeof(struct reg_lut_func256_base2_addr_hi) == 4), "reg_lut_func256_base2_addr_hi size is not 32-bit");
/*
 SPE_LFSR_POLYNOM 
 b'LFSR polynom'
*/
typedef struct reg_spe_lfsr_polynom {
	union {
		struct {
			uint32_t v : 32;
		};
		uint32_t _raw;
	};
} reg_spe_lfsr_polynom;
static_assert((sizeof(struct reg_spe_lfsr_polynom) == 4), "reg_spe_lfsr_polynom size is not 32-bit");
/*
 TSB_CFG_MTRR_GLBL 
 b'TSB MTRR Global cfg'
*/
typedef struct reg_tsb_cfg_mtrr_glbl {
	union {
		struct {
			uint32_t en : 1,
				_reserved4 : 3,
				default_memory_type : 1,
				_reserved5 : 27;
		};
		uint32_t _raw;
	};
} reg_tsb_cfg_mtrr_glbl;
static_assert((sizeof(struct reg_tsb_cfg_mtrr_glbl) == 4), "reg_tsb_cfg_mtrr_glbl size is not 32-bit");
/*
 TSB_CFG_MTRR 
 b'TSB MTRR cfg'
*/
typedef struct reg_tsb_cfg_mtrr {
	union {
		struct {
			uint32_t valid : 1,
				_reserved4 : 3,
				memory_type : 1,
				_reserved8 : 3,
				phy_base_add : 16,
				_reserved24 : 8;
		};
		uint32_t _raw;
	};
} reg_tsb_cfg_mtrr;
static_assert((sizeof(struct reg_tsb_cfg_mtrr) == 4), "reg_tsb_cfg_mtrr size is not 32-bit");
/*
 TSB_CFG_MTRR_MASK_LO 
 b'TSB MTRR mask cfg lo'
*/
typedef struct reg_tsb_cfg_mtrr_mask_lo {
	union {
		struct {
			uint32_t v : 32;
		};
		uint32_t _raw;
	};
} reg_tsb_cfg_mtrr_mask_lo;
static_assert((sizeof(struct reg_tsb_cfg_mtrr_mask_lo) == 4), "reg_tsb_cfg_mtrr_mask_lo size is not 32-bit");
/*
 TSB_CFG_MTRR_MASK_HI 
 b'TSB MTRR mask cfg hi'
*/
typedef struct reg_tsb_cfg_mtrr_mask_hi {
	union {
		struct {
			uint32_t v : 8,
				_reserved8 : 24;
		};
		uint32_t _raw;
	};
} reg_tsb_cfg_mtrr_mask_hi;
static_assert((sizeof(struct reg_tsb_cfg_mtrr_mask_hi) == 4), "reg_tsb_cfg_mtrr_mask_hi size is not 32-bit");
/*
 FP8_143_BIAS 
 b'FP8 143 Bias value'
*/
typedef struct reg_fp8_143_bias {
	union {
		struct {
			uint32_t bias_143 : 4,
				_reserved4 : 28;
		};
		uint32_t _raw;
	};
} reg_fp8_143_bias;
static_assert((sizeof(struct reg_fp8_143_bias) == 4), "reg_fp8_143_bias size is not 32-bit");
/*
 ROUND_CSR 
 b'round mode for FMA operations'
*/
typedef struct reg_round_csr {
	union {
		struct {
			uint32_t mode : 3,
				_reserved3 : 29;
		};
		uint32_t _raw;
	};
} reg_round_csr;
static_assert((sizeof(struct reg_round_csr) == 4), "reg_round_csr size is not 32-bit");
/*
 HB_PROT 
 b'AXI HBW AxPROT bits'
*/
typedef struct reg_hb_prot {
	union {
		struct {
			uint32_t awprot : 3,
				arprot : 3,
				_reserved6 : 26;
		};
		uint32_t _raw;
	};
} reg_hb_prot;
static_assert((sizeof(struct reg_hb_prot) == 4), "reg_hb_prot size is not 32-bit");
/*
 LB_PROT 
 b'AXI LBW AxPROT bits'
*/
typedef struct reg_lb_prot {
	union {
		struct {
			uint32_t awprot : 3,
				arprot : 3,
				_reserved6 : 26;
		};
		uint32_t _raw;
	};
} reg_lb_prot;
static_assert((sizeof(struct reg_lb_prot) == 4), "reg_lb_prot size is not 32-bit");
/*
 SEMAPHORE 
 b'atomic semaphore (used for spu/vpu sync)'
*/
typedef struct reg_semaphore {
	union {
		struct {
			uint32_t v : 32;
		};
		uint32_t _raw;
	};
} reg_semaphore;
static_assert((sizeof(struct reg_semaphore) == 4), "reg_semaphore size is not 32-bit");
/*
 VFLAGS 
 b'Vector Flags'
*/
typedef struct reg_vflags {
	union {
		struct {
			uint32_t v : 7,
				_reserved7 : 25;
		};
		uint32_t _raw;
	};
} reg_vflags;
static_assert((sizeof(struct reg_vflags) == 4), "reg_vflags size is not 32-bit");
/*
 SFLAGS 
 b'Scalar Flags'
*/
typedef struct reg_sflags {
	union {
		struct {
			uint32_t v : 7,
				_reserved7 : 25;
		};
		uint32_t _raw;
	};
} reg_sflags;
static_assert((sizeof(struct reg_sflags) == 4), "reg_sflags size is not 32-bit");
/*
 LFSR_POLYNOM 
 b'VPU LFSR polynom'
*/
typedef struct reg_lfsr_polynom {
	union {
		struct {
			uint32_t v : 32;
		};
		uint32_t _raw;
	};
} reg_lfsr_polynom;
static_assert((sizeof(struct reg_lfsr_polynom) == 4), "reg_lfsr_polynom size is not 32-bit");
/*
 STATUS 
 b'Used to qeury  the status of the TPC'
*/
typedef struct reg_status {
	union {
		struct {
			uint32_t _reserved1 : 1,
scalar_pipe_empty : 1,
				vector_pipe_empty : 1,
				iq_empty : 1,
				_reserved5 : 1,
				sb_empty : 1,
				qm_idle : 1,
				qm_rdy : 1,
				_reserved8 : 24;
		};
		uint32_t _raw;
	};
} reg_status;
static_assert((sizeof(struct reg_status) == 4), "reg_status size is not 32-bit");
/*
 CFG_BASE_ADDRESS_HIGH 
 b'higher 32 bits of the CFG base address'
*/
typedef struct reg_cfg_base_address_high {
	union {
		struct {
			uint32_t v : 32;
		};
		uint32_t _raw;
	};
} reg_cfg_base_address_high;
static_assert((sizeof(struct reg_cfg_base_address_high) == 4), "reg_cfg_base_address_high size is not 32-bit");
/*
 CFG_SUBTRACT_VALUE 
 b'MMIO address offset for outbound LBW'
*/
typedef struct reg_cfg_subtract_value {
	union {
		struct {
			uint32_t v : 32;
		};
		uint32_t _raw;
	};
} reg_cfg_subtract_value;
static_assert((sizeof(struct reg_cfg_subtract_value) == 4), "reg_cfg_subtract_value size is not 32-bit");
/*
 SM_BASE_ADDRESS_HIGH 
 b'32 MSBs of SM Base address'
*/
typedef struct reg_sm_base_address_high {
	union {
		struct {
			uint32_t v : 32;
		};
		uint32_t _raw;
	};
} reg_sm_base_address_high;
static_assert((sizeof(struct reg_sm_base_address_high) == 4), "reg_sm_base_address_high size is not 32-bit");
/*
 TPC_CMD 
 b'enable sequencer operations before next descriptor'
*/
typedef struct reg_tpc_cmd {
	union {
		struct {
			uint32_t icache_invalidate : 1,
				dcache_invalidate : 1,
				lcache_invalidate : 1,
				tcache_invalidate : 1,
				icache_prefetch_64kb : 1,
				icache_prefetch_32kb : 1,
				qman_stop : 1,
				_reserved7 : 25;
		};
		uint32_t _raw;
	};
} reg_tpc_cmd;
static_assert((sizeof(struct reg_tpc_cmd) == 4), "reg_tpc_cmd size is not 32-bit");
/*
 TPC_EXECUTE 
 b'push descriptor to TPC'
*/
typedef struct reg_tpc_execute {
	union {
		struct {
			uint32_t v : 1,
				_reserved1 : 31;
		};
		uint32_t _raw;
	};
} reg_tpc_execute;
static_assert((sizeof(struct reg_tpc_execute) == 4), "reg_tpc_execute size is not 32-bit");
/*
 TPC_STALL 
 b'stalls TPC core'
*/
typedef struct reg_tpc_stall {
	union {
		struct {
			uint32_t v : 1,
				_reserved1 : 31;
		};
		uint32_t _raw;
	};
} reg_tpc_stall;
static_assert((sizeof(struct reg_tpc_stall) == 4), "reg_tpc_stall size is not 32-bit");
/*
 ICACHE_BASE_ADDERESS_LOW 
 b'32 LSBs of the base address to prefetch in a 64KB'
*/
typedef struct reg_icache_base_adderess_low {
	union {
		struct {
			uint32_t v : 32;
		};
		uint32_t _raw;
	};
} reg_icache_base_adderess_low;
static_assert((sizeof(struct reg_icache_base_adderess_low) == 4), "reg_icache_base_adderess_low size is not 32-bit");
/*
 ICACHE_BASE_ADDERESS_HIGH 
 b'32 MSBs of the base address to prefetch in a 64KB'
*/
typedef struct reg_icache_base_adderess_high {
	union {
		struct {
			uint32_t v : 32;
		};
		uint32_t _raw;
	};
} reg_icache_base_adderess_high;
static_assert((sizeof(struct reg_icache_base_adderess_high) == 4), "reg_icache_base_adderess_high size is not 32-bit");
/*
 RD_RATE_LIMIT 
 b'AXI Read Port RATE LIMIT Static Config'
*/
typedef struct reg_rd_rate_limit {
	union {
		struct {
			uint32_t enable : 1,
				saturation : 8,
				timeout : 8,
				_reserved17 : 15;
		};
		uint32_t _raw;
	};
} reg_rd_rate_limit;
static_assert((sizeof(struct reg_rd_rate_limit) == 4), "reg_rd_rate_limit size is not 32-bit");
/*
 WR_RATE_LIMIT 
 b'AXI Write Port RATE LIMIT Static Config'
*/
typedef struct reg_wr_rate_limit {
	union {
		struct {
			uint32_t enable : 1,
				saturation : 8,
				timeout : 8,
				_reserved17 : 15;
		};
		uint32_t _raw;
	};
} reg_wr_rate_limit;
static_assert((sizeof(struct reg_wr_rate_limit) == 4), "reg_wr_rate_limit size is not 32-bit");
/*
 MSS_CONFIG 
 b'configurations related to caches'
*/
typedef struct reg_mss_config {
	union {
		struct {
			uint32_t awcache : 4,
				arcache : 4,
				icache_fetch_line_num : 2,
				exposed_pipe_dis : 1,
				dcache_prefetch_dis : 1,
				_reserved12 : 20;
		};
		uint32_t _raw;
	};
} reg_mss_config;
static_assert((sizeof(struct reg_mss_config) == 4), "reg_mss_config size is not 32-bit");
/*
 TPC_INTR_CAUSE 
 b'TPC interrupts cause'
*/
typedef struct reg_tpc_intr_cause {
	union {
		struct {
			uint32_t cause : 32;
		};
		uint32_t _raw;
	};
} reg_tpc_intr_cause;
static_assert((sizeof(struct reg_tpc_intr_cause) == 4), "reg_tpc_intr_cause size is not 32-bit");
/*
 TPC_INTR_MASK 
 b'Set 1 to mask the corresponding interrupt'
*/
typedef struct reg_tpc_intr_mask {
	union {
		struct {
			uint32_t mask : 32;
		};
		uint32_t _raw;
	};
} reg_tpc_intr_mask;
static_assert((sizeof(struct reg_tpc_intr_mask) == 4), "reg_tpc_intr_mask size is not 32-bit");
/*
 WQ_CREDITS 
 b'WQ_CREDITS'
*/
typedef struct reg_wq_credits {
	union {
		struct {
			uint32_t st_g : 4,
				kernel_fifo : 3,
				_reserved7 : 25;
		};
		uint32_t _raw;
	};
} reg_wq_credits;
static_assert((sizeof(struct reg_wq_credits) == 4), "reg_wq_credits size is not 32-bit");
/*
 OPCODE_EXEC 
 b'Opcodes Executed for Counters'
*/
typedef struct reg_opcode_exec {
	union {
		struct {
			uint32_t spu_op : 7,
				spu_en : 1,
				vpu_op : 7,
				vpu_en : 1,
				ld_op : 7,
				ld_en : 1,
				st_op : 7,
				st_en : 1;
		};
		uint32_t _raw;
	};
} reg_opcode_exec;
static_assert((sizeof(struct reg_opcode_exec) == 4), "reg_opcode_exec size is not 32-bit");
/*
 LUT_FUNC32_BASE_ADDR_LO 
 b'LOOKUP TABLE 32 lines Base Address 32 LSB'
*/
typedef struct reg_lut_func32_base_addr_lo {
	union {
		struct {
			uint32_t v : 32;
		};
		uint32_t _raw;
	};
} reg_lut_func32_base_addr_lo;
static_assert((sizeof(struct reg_lut_func32_base_addr_lo) == 4), "reg_lut_func32_base_addr_lo size is not 32-bit");
/*
 LUT_FUNC32_BASE_ADDR_HI 
 b'LOOKUP TABLE 32 lines Base Address 32 MSB'
*/
typedef struct reg_lut_func32_base_addr_hi {
	union {
		struct {
			uint32_t v : 32;
		};
		uint32_t _raw;
	};
} reg_lut_func32_base_addr_hi;
static_assert((sizeof(struct reg_lut_func32_base_addr_hi) == 4), "reg_lut_func32_base_addr_hi size is not 32-bit");
/*
 LUT_FUNC64_BASE_ADDR_LO 
 b'LOOKUP TABLE 64 lines Base Address 32 LSB'
*/
typedef struct reg_lut_func64_base_addr_lo {
	union {
		struct {
			uint32_t v : 32;
		};
		uint32_t _raw;
	};
} reg_lut_func64_base_addr_lo;
static_assert((sizeof(struct reg_lut_func64_base_addr_lo) == 4), "reg_lut_func64_base_addr_lo size is not 32-bit");
/*
 LUT_FUNC64_BASE_ADDR_HI 
 b'LOOKUP TABLE 64 lines Base Address 32 MSB'
*/
typedef struct reg_lut_func64_base_addr_hi {
	union {
		struct {
			uint32_t v : 32;
		};
		uint32_t _raw;
	};
} reg_lut_func64_base_addr_hi;
static_assert((sizeof(struct reg_lut_func64_base_addr_hi) == 4), "reg_lut_func64_base_addr_hi size is not 32-bit");
/*
 LUT_FUNC128_BASE_ADDR_LO 
 b'LOOKUP TABLE 128 lines Base Address 32 LSB'
*/
typedef struct reg_lut_func128_base_addr_lo {
	union {
		struct {
			uint32_t v : 32;
		};
		uint32_t _raw;
	};
} reg_lut_func128_base_addr_lo;
static_assert((sizeof(struct reg_lut_func128_base_addr_lo) == 4), "reg_lut_func128_base_addr_lo size is not 32-bit");
/*
 LUT_FUNC128_BASE_ADDR_HI 
 b'LOOKUP TABLE 128 lines Base Address 32 MSB'
*/
typedef struct reg_lut_func128_base_addr_hi {
	union {
		struct {
			uint32_t v : 32;
		};
		uint32_t _raw;
	};
} reg_lut_func128_base_addr_hi;
static_assert((sizeof(struct reg_lut_func128_base_addr_hi) == 4), "reg_lut_func128_base_addr_hi size is not 32-bit");
/*
 LUT_FUNC256_BASE_ADDR_LO 
 b'LOOKUP TABLE 256 lines Base Address 32 LSB'
*/
typedef struct reg_lut_func256_base_addr_lo {
	union {
		struct {
			uint32_t v : 32;
		};
		uint32_t _raw;
	};
} reg_lut_func256_base_addr_lo;
static_assert((sizeof(struct reg_lut_func256_base_addr_lo) == 4), "reg_lut_func256_base_addr_lo size is not 32-bit");
/*
 LUT_FUNC256_BASE_ADDR_HI 
 b'LOOKUP TABLE 256 lines Base Address 32 MSB'
*/
typedef struct reg_lut_func256_base_addr_hi {
	union {
		struct {
			uint32_t v : 32;
		};
		uint32_t _raw;
	};
} reg_lut_func256_base_addr_hi;
static_assert((sizeof(struct reg_lut_func256_base_addr_hi) == 4), "reg_lut_func256_base_addr_hi size is not 32-bit");
/*
 TSB_CFG_MAX_SIZE 
 b'TSB Configuration'
*/
typedef struct reg_tsb_cfg_max_size {
	union {
		struct {
			uint32_t data : 16,
				md : 16;
		};
		uint32_t _raw;
	};
} reg_tsb_cfg_max_size;
static_assert((sizeof(struct reg_tsb_cfg_max_size) == 4), "reg_tsb_cfg_max_size size is not 32-bit");
/*
 TSB_CFG 
 b'more TSB configuration'
*/
typedef struct reg_tsb_cfg {
	union {
		struct {
			uint32_t cache_disable : 1,
				max_os : 16,
				enable_cgate : 1,
				_reserved18 : 14;
		};
		uint32_t _raw;
	};
} reg_tsb_cfg;
static_assert((sizeof(struct reg_tsb_cfg) == 4), "reg_tsb_cfg size is not 32-bit");
/*
 TSB_INFLIGHT_CNTR 
 b'number of inflight req. of SB'
*/
typedef struct reg_tsb_inflight_cntr {
	union {
		struct {
			uint32_t v : 32;
		};
		uint32_t _raw;
	};
} reg_tsb_inflight_cntr;
static_assert((sizeof(struct reg_tsb_inflight_cntr) == 4), "reg_tsb_inflight_cntr size is not 32-bit");
/*
 WQ_INFLIGHT_CNTR 
 b'number of inflight req. of WQ'
*/
typedef struct reg_wq_inflight_cntr {
	union {
		struct {
			uint32_t hbw : 16,
				lbw : 9,
				_reserved25 : 7;
		};
		uint32_t _raw;
	};
} reg_wq_inflight_cntr;
static_assert((sizeof(struct reg_wq_inflight_cntr) == 4), "reg_wq_inflight_cntr size is not 32-bit");
/*
 WQ_LBW_TOTAL_CNTR 
 b'writing reset counter'
*/
typedef struct reg_wq_lbw_total_cntr {
	union {
		struct {
			uint32_t v : 32;
		};
		uint32_t _raw;
	};
} reg_wq_lbw_total_cntr;
static_assert((sizeof(struct reg_wq_lbw_total_cntr) == 4), "reg_wq_lbw_total_cntr size is not 32-bit");
/*
 WQ_HBW_TOTAL_CNTR 
 b'writing reset counter'
*/
typedef struct reg_wq_hbw_total_cntr {
	union {
		struct {
			uint32_t v : 32;
		};
		uint32_t _raw;
	};
} reg_wq_hbw_total_cntr;
static_assert((sizeof(struct reg_wq_hbw_total_cntr) == 4), "reg_wq_hbw_total_cntr size is not 32-bit");
/*
 IRQ_OCCOUPY_CNTR 
 b'number of instructions in IQ'
*/
typedef struct reg_irq_occoupy_cntr {
	union {
		struct {
			uint32_t v : 32;
		};
		uint32_t _raw;
	};
} reg_irq_occoupy_cntr;
static_assert((sizeof(struct reg_irq_occoupy_cntr) == 4), "reg_irq_occoupy_cntr size is not 32-bit");

#ifdef __cplusplus
} /* tpc namespace */
#endif

/*
 TPC block
*/

#ifdef __cplusplus

struct block_tpc {
	struct block_tpc_tensor kernel_tensor_0;
	struct block_tpc_tensor kernel_tensor_1;
	struct block_tpc_tensor kernel_tensor_2;
	struct block_tpc_tensor kernel_tensor_3;
	struct block_tpc_tensor kernel_tensor_4;
	struct block_tpc_tensor kernel_tensor_5;
	struct block_tpc_tensor kernel_tensor_6;
	struct block_tpc_tensor kernel_tensor_7;
	struct block_tpc_tensor kernel_tensor_8;
	struct block_tpc_tensor kernel_tensor_9;
	struct block_tpc_tensor kernel_tensor_10;
	struct block_tpc_tensor kernel_tensor_11;
	struct block_tpc_tensor kernel_tensor_12;
	struct block_tpc_tensor kernel_tensor_13;
	struct block_tpc_tensor kernel_tensor_14;
	struct block_tpc_tensor kernel_tensor_15;
	struct block_sync_object kernel_sync_object;
	struct block_tpc_non_tensor_descriptor kernel;
	struct block_tpc_tensor qm_tensor_0;
	struct block_tpc_tensor qm_tensor_1;
	struct block_tpc_tensor qm_tensor_2;
	struct block_tpc_tensor qm_tensor_3;
	struct block_tpc_tensor qm_tensor_4;
	struct block_tpc_tensor qm_tensor_5;
	struct block_tpc_tensor qm_tensor_6;
	struct block_tpc_tensor qm_tensor_7;
	struct block_tpc_tensor qm_tensor_8;
	struct block_tpc_tensor qm_tensor_9;
	struct block_tpc_tensor qm_tensor_10;
	struct block_tpc_tensor qm_tensor_11;
	struct block_tpc_tensor qm_tensor_12;
	struct block_tpc_tensor qm_tensor_13;
	struct block_tpc_tensor qm_tensor_14;
	struct block_tpc_tensor qm_tensor_15;
	struct block_sync_object qm_sync_object;
	struct block_tpc_non_tensor_descriptor qm;
	uint32_t _pad3000[24];
	struct tpc::reg_tpc_count tpc_count;
	struct tpc::reg_tpc_id tpc_id;
	struct tpc::reg_stall_on_err stall_on_err;
	struct tpc::reg_clk_en clk_en;
	struct tpc::reg_iq_rl_en iq_rl_en;
	struct tpc::reg_iq_rl_sat iq_rl_sat;
	struct tpc::reg_iq_rl_rst_token iq_rl_rst_token;
	struct tpc::reg_iq_rl_timeout iq_rl_timeout;
	struct tpc::reg_tsb_cfg_mtrr_2 tsb_cfg_mtrr_2[4];
	struct tpc::reg_iq_lbw_clk_en iq_lbw_clk_en;
	struct tpc::reg_tpc_lock_value tpc_lock_value[4];
	struct tpc::reg_tpc_lock tpc_lock[4];
	struct tpc::reg_cgu_sb cgu_sb;
	struct tpc::reg_cgu_cnt cgu_cnt;
	struct tpc::reg_cgu_cpe cgu_cpe[8];
	struct tpc::reg_fp16_ftz_in fp16_ftz_in;
	struct tpc::reg_dcache_cfg dcache_cfg;
	struct tpc::reg_e2e_crdt_top e2e_crdt_top;
	struct tpc::reg_tpc_dcache_l0cd tpc_dcache_l0cd;
	struct tpc::reg_tpc_sb_l0cd tpc_sb_l0cd;
	struct tpc::reg_conv_round_csr conv_round_csr;
	struct tpc::reg_tsb_occupancy tsb_occupancy;
	struct tpc::reg_arb_qnt_hbw_weight arb_qnt_hbw_weight;
	struct tpc::reg_arb_qnt_lbw_weight arb_qnt_lbw_weight;
	struct tpc::reg_arb_cnt_hbw_weight arb_cnt_hbw_weight;
	struct tpc::reg_arb_cnt_lbw_weight arb_cnt_lbw_weight;
	struct tpc::reg_lut_func32_base2_addr_lo lut_func32_base2_addr_lo;
	struct tpc::reg_lut_func32_base2_addr_hi lut_func32_base2_addr_hi;
	struct tpc::reg_lut_func64_base2_addr_lo lut_func64_base2_addr_lo;
	struct tpc::reg_lut_func64_base2_addr_hi lut_func64_base2_addr_hi;
	struct tpc::reg_lut_func128_base2_addr_lo lut_func128_base2_addr_lo;
	struct tpc::reg_lut_func128_base2_addr_hi lut_func128_base2_addr_hi;
	struct tpc::reg_lut_func256_base2_addr_lo lut_func256_base2_addr_lo;
	struct tpc::reg_lut_func256_base2_addr_hi lut_func256_base2_addr_hi;
	struct tpc::reg_spe_lfsr_polynom spe_lfsr_polynom;
	struct tpc::reg_tsb_cfg_mtrr_glbl tsb_cfg_mtrr_glbl;
	struct tpc::reg_tsb_cfg_mtrr tsb_cfg_mtrr[4];
	struct tpc::reg_tsb_cfg_mtrr_mask_lo tsb_cfg_mtrr_mask_lo[4];
	struct tpc::reg_tsb_cfg_mtrr_mask_hi tsb_cfg_mtrr_mask_hi[4];
	uint32_t _pad3352[19];
	struct tpc::reg_fp8_143_bias fp8_143_bias;
	struct tpc::reg_round_csr round_csr;
	struct tpc::reg_hb_prot hb_prot;
	struct tpc::reg_lb_prot lb_prot;
	struct tpc::reg_semaphore semaphore;
	struct tpc::reg_vflags vflags;
	struct tpc::reg_sflags sflags;
	struct tpc::reg_lfsr_polynom lfsr_polynom;
	struct tpc::reg_status status;
	struct tpc::reg_cfg_base_address_high cfg_base_address_high;
	struct tpc::reg_cfg_subtract_value cfg_subtract_value;
	struct tpc::reg_sm_base_address_high sm_base_address_high;
	struct tpc::reg_tpc_cmd tpc_cmd;
	struct tpc::reg_tpc_execute tpc_execute;
	struct tpc::reg_tpc_stall tpc_stall;
	struct tpc::reg_icache_base_adderess_low icache_base_adderess_low;
	struct tpc::reg_icache_base_adderess_high icache_base_adderess_high;
	struct tpc::reg_rd_rate_limit rd_rate_limit;
	struct tpc::reg_wr_rate_limit wr_rate_limit;
	struct tpc::reg_mss_config mss_config;
	struct tpc::reg_tpc_intr_cause tpc_intr_cause;
	struct tpc::reg_tpc_intr_mask tpc_intr_mask;
	struct tpc::reg_wq_credits wq_credits;
	struct tpc::reg_opcode_exec opcode_exec;
	struct tpc::reg_lut_func32_base_addr_lo lut_func32_base_addr_lo;
	struct tpc::reg_lut_func32_base_addr_hi lut_func32_base_addr_hi;
	struct tpc::reg_lut_func64_base_addr_lo lut_func64_base_addr_lo;
	struct tpc::reg_lut_func64_base_addr_hi lut_func64_base_addr_hi;
	struct tpc::reg_lut_func128_base_addr_lo lut_func128_base_addr_lo;
	struct tpc::reg_lut_func128_base_addr_hi lut_func128_base_addr_hi;
	struct tpc::reg_lut_func256_base_addr_lo lut_func256_base_addr_lo;
	struct tpc::reg_lut_func256_base_addr_hi lut_func256_base_addr_hi;
	struct tpc::reg_tsb_cfg_max_size tsb_cfg_max_size;
	struct tpc::reg_tsb_cfg tsb_cfg;
	struct tpc::reg_tsb_inflight_cntr tsb_inflight_cntr;
	struct tpc::reg_wq_inflight_cntr wq_inflight_cntr;
	struct tpc::reg_wq_lbw_total_cntr wq_lbw_total_cntr;
	struct tpc::reg_wq_hbw_total_cntr wq_hbw_total_cntr;
	struct tpc::reg_irq_occoupy_cntr irq_occoupy_cntr;
	struct block_axuser axuser;
	uint32_t _pad3664[12];
	struct block_special_regs special;
};
#else

typedef struct block_tpc {
	block_tpc_tensor kernel_tensor_0;
	block_tpc_tensor kernel_tensor_1;
	block_tpc_tensor kernel_tensor_2;
	block_tpc_tensor kernel_tensor_3;
	block_tpc_tensor kernel_tensor_4;
	block_tpc_tensor kernel_tensor_5;
	block_tpc_tensor kernel_tensor_6;
	block_tpc_tensor kernel_tensor_7;
	block_tpc_tensor kernel_tensor_8;
	block_tpc_tensor kernel_tensor_9;
	block_tpc_tensor kernel_tensor_10;
	block_tpc_tensor kernel_tensor_11;
	block_tpc_tensor kernel_tensor_12;
	block_tpc_tensor kernel_tensor_13;
	block_tpc_tensor kernel_tensor_14;
	block_tpc_tensor kernel_tensor_15;
	block_sync_object kernel_sync_object;
	block_tpc_non_tensor_descriptor kernel;
	block_tpc_tensor qm_tensor_0;
	block_tpc_tensor qm_tensor_1;
	block_tpc_tensor qm_tensor_2;
	block_tpc_tensor qm_tensor_3;
	block_tpc_tensor qm_tensor_4;
	block_tpc_tensor qm_tensor_5;
	block_tpc_tensor qm_tensor_6;
	block_tpc_tensor qm_tensor_7;
	block_tpc_tensor qm_tensor_8;
	block_tpc_tensor qm_tensor_9;
	block_tpc_tensor qm_tensor_10;
	block_tpc_tensor qm_tensor_11;
	block_tpc_tensor qm_tensor_12;
	block_tpc_tensor qm_tensor_13;
	block_tpc_tensor qm_tensor_14;
	block_tpc_tensor qm_tensor_15;
	block_sync_object qm_sync_object;
	block_tpc_non_tensor_descriptor qm;
	uint32_t _pad3000[24];
	reg_tpc_count tpc_count;
	reg_tpc_id tpc_id;
	reg_stall_on_err stall_on_err;
	reg_clk_en clk_en;
	reg_iq_rl_en iq_rl_en;
	reg_iq_rl_sat iq_rl_sat;
	reg_iq_rl_rst_token iq_rl_rst_token;
	reg_iq_rl_timeout iq_rl_timeout;
	reg_tsb_cfg_mtrr_2 tsb_cfg_mtrr_2[4];
	reg_iq_lbw_clk_en iq_lbw_clk_en;
	reg_tpc_lock_value tpc_lock_value[4];
	reg_tpc_lock tpc_lock[4];
	reg_cgu_sb cgu_sb;
	reg_cgu_cnt cgu_cnt;
	reg_cgu_cpe cgu_cpe[8];
	reg_fp16_ftz_in fp16_ftz_in;
	reg_dcache_cfg dcache_cfg;
	reg_e2e_crdt_top e2e_crdt_top;
	reg_tpc_dcache_l0cd tpc_dcache_l0cd;
	reg_tpc_sb_l0cd tpc_sb_l0cd;
	reg_conv_round_csr conv_round_csr;
	reg_tsb_occupancy tsb_occupancy;
	reg_arb_qnt_hbw_weight arb_qnt_hbw_weight;
	reg_arb_qnt_lbw_weight arb_qnt_lbw_weight;
	reg_arb_cnt_hbw_weight arb_cnt_hbw_weight;
	reg_arb_cnt_lbw_weight arb_cnt_lbw_weight;
	reg_lut_func32_base2_addr_lo lut_func32_base2_addr_lo;
	reg_lut_func32_base2_addr_hi lut_func32_base2_addr_hi;
	reg_lut_func64_base2_addr_lo lut_func64_base2_addr_lo;
	reg_lut_func64_base2_addr_hi lut_func64_base2_addr_hi;
	reg_lut_func128_base2_addr_lo lut_func128_base2_addr_lo;
	reg_lut_func128_base2_addr_hi lut_func128_base2_addr_hi;
	reg_lut_func256_base2_addr_lo lut_func256_base2_addr_lo;
	reg_lut_func256_base2_addr_hi lut_func256_base2_addr_hi;
	reg_spe_lfsr_polynom spe_lfsr_polynom;
	reg_tsb_cfg_mtrr_glbl tsb_cfg_mtrr_glbl;
	reg_tsb_cfg_mtrr tsb_cfg_mtrr[4];
	reg_tsb_cfg_mtrr_mask_lo tsb_cfg_mtrr_mask_lo[4];
	reg_tsb_cfg_mtrr_mask_hi tsb_cfg_mtrr_mask_hi[4];
	uint32_t _pad3352[19];
	reg_fp8_143_bias fp8_143_bias;
	reg_round_csr round_csr;
	reg_hb_prot hb_prot;
	reg_lb_prot lb_prot;
	reg_semaphore semaphore;
	reg_vflags vflags;
	reg_sflags sflags;
	reg_lfsr_polynom lfsr_polynom;
	reg_status status;
	reg_cfg_base_address_high cfg_base_address_high;
	reg_cfg_subtract_value cfg_subtract_value;
	reg_sm_base_address_high sm_base_address_high;
	reg_tpc_cmd tpc_cmd;
	reg_tpc_execute tpc_execute;
	reg_tpc_stall tpc_stall;
	reg_icache_base_adderess_low icache_base_adderess_low;
	reg_icache_base_adderess_high icache_base_adderess_high;
	reg_rd_rate_limit rd_rate_limit;
	reg_wr_rate_limit wr_rate_limit;
	reg_mss_config mss_config;
	reg_tpc_intr_cause tpc_intr_cause;
	reg_tpc_intr_mask tpc_intr_mask;
	reg_wq_credits wq_credits;
	reg_opcode_exec opcode_exec;
	reg_lut_func32_base_addr_lo lut_func32_base_addr_lo;
	reg_lut_func32_base_addr_hi lut_func32_base_addr_hi;
	reg_lut_func64_base_addr_lo lut_func64_base_addr_lo;
	reg_lut_func64_base_addr_hi lut_func64_base_addr_hi;
	reg_lut_func128_base_addr_lo lut_func128_base_addr_lo;
	reg_lut_func128_base_addr_hi lut_func128_base_addr_hi;
	reg_lut_func256_base_addr_lo lut_func256_base_addr_lo;
	reg_lut_func256_base_addr_hi lut_func256_base_addr_hi;
	reg_tsb_cfg_max_size tsb_cfg_max_size;
	reg_tsb_cfg tsb_cfg;
	reg_tsb_inflight_cntr tsb_inflight_cntr;
	reg_wq_inflight_cntr wq_inflight_cntr;
	reg_wq_lbw_total_cntr wq_lbw_total_cntr;
	reg_wq_hbw_total_cntr wq_hbw_total_cntr;
	reg_irq_occoupy_cntr irq_occoupy_cntr;
	block_axuser axuser;
	uint32_t _pad3664[12];
	block_special_regs special;
} block_tpc;
#endif

const offsetVal block_tpc_defaults[] =
{
	// offset	// value
	{ 0xc   , 0x50000             , 1 }, // tensor_config
	{ 0x5c  , 0x50000             , 1 }, // tensor_config
	{ 0xac  , 0x50000             , 1 }, // tensor_config
	{ 0xfc  , 0x50000             , 1 }, // tensor_config
	{ 0x14c , 0x50000             , 1 }, // tensor_config
	{ 0x19c , 0x50000             , 1 }, // tensor_config
	{ 0x1ec , 0x50000             , 1 }, // tensor_config
	{ 0x23c , 0x50000             , 1 }, // tensor_config
	{ 0x28c , 0x50000             , 1 }, // tensor_config
	{ 0x2dc , 0x50000             , 1 }, // tensor_config
	{ 0x32c , 0x50000             , 1 }, // tensor_config
	{ 0x37c , 0x50000             , 1 }, // tensor_config
	{ 0x3cc , 0x50000             , 1 }, // tensor_config
	{ 0x41c , 0x50000             , 1 }, // tensor_config
	{ 0x46c , 0x50000             , 1 }, // tensor_config
	{ 0x4bc , 0x50000             , 1 }, // tensor_config
	{ 0x538 , 0x1040482           , 1 }, // kernel_config
	{ 0x5e8 , 0x50000             , 1 }, // tensor_config
	{ 0x638 , 0x50000             , 1 }, // tensor_config
	{ 0x688 , 0x50000             , 1 }, // tensor_config
	{ 0x6d8 , 0x50000             , 1 }, // tensor_config
	{ 0x728 , 0x50000             , 1 }, // tensor_config
	{ 0x778 , 0x50000             , 1 }, // tensor_config
	{ 0x7c8 , 0x50000             , 1 }, // tensor_config
	{ 0x818 , 0x50000             , 1 }, // tensor_config
	{ 0x868 , 0x50000             , 1 }, // tensor_config
	{ 0x8b8 , 0x50000             , 1 }, // tensor_config
	{ 0x908 , 0x50000             , 1 }, // tensor_config
	{ 0x958 , 0x50000             , 1 }, // tensor_config
	{ 0x9a8 , 0x50000             , 1 }, // tensor_config
	{ 0x9f8 , 0x50000             , 1 }, // tensor_config
	{ 0xa48 , 0x50000             , 1 }, // tensor_config
	{ 0xa98 , 0x50000             , 1 }, // tensor_config
	{ 0xb14 , 0x1040482           , 1 }, // kernel_config
	{ 0xc18 , 0x18                , 1 }, // tpc_count
	{ 0xc2c , 0x4                 , 1 }, // iq_rl_sat
	{ 0xc30 , 0x8                 , 1 }, // iq_rl_rst_token
	{ 0xc34 , 0xf                 , 1 }, // iq_rl_timeout
	{ 0xc6c , 0x1                 , 1 }, // cgu_sb
	{ 0xc70 , 0xffffff            , 1 }, // cgu_cnt
	{ 0xc74 , 0xfffff             , 8 }, // cgu_cpe
	{ 0xc98 , 0x4                 , 1 }, // dcache_cfg
	{ 0xcb0 , 0x1414f             , 1 }, // arb_qnt_hbw_weight
	{ 0xcb4 , 0xff14              , 1 }, // arb_qnt_lbw_weight
	{ 0xcb8 , 0x14f14f            , 1 }, // arb_cnt_hbw_weight
	{ 0xcbc , 0x14f14             , 1 }, // arb_cnt_lbw_weight
	{ 0xcc0 , 0x17000             , 1 }, // lut_func32_base2_addr_lo
	{ 0xcc8 , 0x13800             , 1 }, // lut_func64_base2_addr_lo
	{ 0xcd0 , 0xd000              , 1 }, // lut_func128_base2_addr_lo
	{ 0xce0 , 0x800002cc          , 1 }, // spe_lfsr_polynom
	{ 0xd64 , 0x7                 , 1 }, // fp8_143_bias
	{ 0xd6c , 0x12                , 1 }, // hb_prot
	{ 0xd70 , 0x12                , 1 }, // lb_prot
	{ 0xd80 , 0x800002cc          , 1 }, // lfsr_polynom
	{ 0xd84 , 0xee                , 1 }, // status
	{ 0xd88 , 0x7f                , 1 }, // cfg_base_address_high
	{ 0xda8 , 0xe0b               , 1 }, // rd_rate_limit
	{ 0xdac , 0xe0b               , 1 }, // wr_rate_limit
	{ 0xdbc , 0x4a                , 1 }, // wq_credits
	{ 0xdc0 , 0xffffffff          , 1 }, // opcode_exec
	{ 0xdc4 , 0x17000             , 1 }, // lut_func32_base_addr_lo
	{ 0xdcc , 0x13800             , 1 }, // lut_func64_base_addr_lo
	{ 0xdd4 , 0xd000              , 1 }, // lut_func128_base_addr_lo
	{ 0xde8 , 0x20000             , 1 }, // tsb_cfg
	{ 0xe04 , 0x11                , 1 }, // hb_mmu_bp
	{ 0xe08 , 0x11                , 1 }, // hb_strong_order
	{ 0xe20 , 0x11                , 1 }, // hb_emem_cpage
	{ 0xe30 , 0xffffffff          , 1 }, // hb_wr_ovrd_lo
	{ 0xe34 , 0x3ff               , 1 }, // hb_wr_ovrd_hi
	{ 0xe38 , 0xffffffff          , 1 }, // hb_rd_ovrd_lo
	{ 0xe3c , 0x3ff               , 1 }, // hb_rd_ovrd_hi
	{ 0xe4c , 0xffffffff          , 1 }, // lb_ovrd
	{ 0xe80 , 0xffffffff          , 32 }, // glbl_priv
	{ 0xf24 , 0xffff              , 1 }, // mem_ecc_err_addr
	{ 0xf44 , 0xffffffff          , 1 }, // glbl_err_addr
	{ 0xf80 , 0xffffffff          , 32 }, // glbl_sec
};

#ifdef __cplusplus
} /* gaudi2 namespace */
#endif

#pragma pack(pop)
#endif /* ASIC_REG_STRUCTS_TPC_H_ */
