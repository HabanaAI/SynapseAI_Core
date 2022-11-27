/***********************************
** This is an auto-generated file **
**       DO NOT EDIT BELOW        **
************************************/

#ifndef ASIC_REG_STRUCTS_QMAN_H_
#define ASIC_REG_STRUCTS_QMAN_H_

#include <stdint.h>
#include "gaudi2_types.h"
#include "axuser_regs.h"
#include "ic_lbw_dbg_cnt_regs.h"
#include "qman_cgm_regs.h"
#include "qman_wr64_base_addr_regs.h"
#include "special_regs_regs.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace gaudi2 {
namespace qman {
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
 GLBL_CFG0 
 b'Configuration: Enable PQ/CQF/ARC-CQF/CP'
*/
typedef struct reg_glbl_cfg0 {
	union {
		struct {
			uint32_t pqf_en : 4,
				cqf_en : 5,
				cp_en : 5,
				arc_cqf_en : 1,
				_reserved15 : 17;
		};
		uint32_t _raw;
	};
} reg_glbl_cfg0;
static_assert((sizeof(struct reg_glbl_cfg0) == 4), "reg_glbl_cfg0 size is not 32-bit");
/*
 GLBL_CFG1 
 b'Configuration: Stop/Flush PQ/CQF/CP'
*/
typedef struct reg_glbl_cfg1 {
	union {
		struct {
			uint32_t pqf_stop : 4,
				cqf_stop : 5,
				cp_stop : 5,
				_reserved16 : 2,
				pqf_flush : 4,
				cqf_flush : 5,
				cp_flush : 5,
				_reserved30 : 2;
		};
		uint32_t _raw;
	};
} reg_glbl_cfg1;
static_assert((sizeof(struct reg_glbl_cfg1) == 4), "reg_glbl_cfg1 size is not 32-bit");
/*
 GLBL_CFG2 
 b'Configuration: HBW/LBW override (AxUSER + AxPROT)'
*/
typedef struct reg_glbl_cfg2 {
	union {
		struct {
			uint32_t arc_cqf_stop : 1,
				arc_cqf_flush : 1,
				_reserved4 : 2,
				arc_hbw_awuser_ovrd : 1,
				arc_hbw_aruser_ovrd : 1,
				arc_lbw_awuser_ovrd : 1,
				arc_lbw_aruser_ovrd : 1,
				arc_hbw_awprot_ovrd : 1,
				arc_hbw_arprot_ovrd : 1,
				arc_lbw_awprot_ovrd : 1,
				arc_lbw_arprot_ovrd : 1,
				arc_hbw_awcache_ovrd : 1,
				arc_hbw_arcache_ovrd : 1,
				arc_lbw_awcache_ovrd : 1,
				arc_lbw_arcache_ovrd : 1,
				arc_lbw_buser_ovrd : 1,
				_reserved17 : 15;
		};
		uint32_t _raw;
	};
} reg_glbl_cfg2;
static_assert((sizeof(struct reg_glbl_cfg2) == 4), "reg_glbl_cfg2 size is not 32-bit");
/*
 GLBL_ERR_CFG 
 b'Err configuration: Stop on Error & Message enable'
*/
typedef struct reg_glbl_err_cfg {
	union {
		struct {
			uint32_t pqf_err_msg_en : 4,
				cqf_err_msg_en : 5,
				cp_err_msg_en : 5,
				_reserved16 : 2,
				pqf_stop_on_err : 4,
				cqf_stop_on_err : 5,
				cp_stop_on_err : 5,
				_reserved31 : 1,
				arb_stop_on_err : 1;
		};
		uint32_t _raw;
	};
} reg_glbl_err_cfg;
static_assert((sizeof(struct reg_glbl_err_cfg) == 4), "reg_glbl_err_cfg size is not 32-bit");
/*
 GLBL_ERR_CFG1 
 b'Err configuration: Stop on Error & Message enable'
*/
typedef struct reg_glbl_err_cfg1 {
	union {
		struct {
			uint32_t cqf_err_msg_en : 1,
				cqf_stop_on_err : 1,
				arc_stop_on_err : 1,
				_reserved3 : 29;
		};
		uint32_t _raw;
	};
} reg_glbl_err_cfg1;
static_assert((sizeof(struct reg_glbl_err_cfg1) == 4), "reg_glbl_err_cfg1 size is not 32-bit");
/*
 GLBL_ERR_ARC_HALT_EN 
 b'Err configuration: Halt ARC upon error'
*/
typedef struct reg_glbl_err_arc_halt_en {
	union {
		struct {
			uint32_t err_ind : 24,
				_reserved24 : 8;
		};
		uint32_t _raw;
	};
} reg_glbl_err_arc_halt_en;
static_assert((sizeof(struct reg_glbl_err_arc_halt_en) == 4), "reg_glbl_err_arc_halt_en size is not 32-bit");
/*
 GLBL_AXCACHE 
 b'Configuration: HBW & LBW ARCACHE/AWCACHE'
*/
typedef struct reg_glbl_axcache {
	union {
		struct {
			uint32_t hbw_ar : 4,
				_reserved16 : 12,
				hbw_aw : 4,
				lbw_aw : 4,
				lbw_ar : 4,
				_reserved28 : 4;
		};
		uint32_t _raw;
	};
} reg_glbl_axcache;
static_assert((sizeof(struct reg_glbl_axcache) == 4), "reg_glbl_axcache size is not 32-bit");
/*
 GLBL_STS0 
 b'Status: Idle & Stop'
*/
typedef struct reg_glbl_sts0 {
	union {
		struct {
			uint32_t pqf_idle : 4,
				cqf_idle : 5,
				cp_idle : 5,
				_reserved16 : 2,
				pqf_is_stop : 4,
				cqf_is_stop : 5,
				cp_is_stop : 5,
				_reserved31 : 1,
				arb_is_stop : 1;
		};
		uint32_t _raw;
	};
} reg_glbl_sts0;
static_assert((sizeof(struct reg_glbl_sts0) == 4), "reg_glbl_sts0 size is not 32-bit");
/*
 GLBL_STS1 
 b'Status: Idle & Stop (ARC-CQF)'
*/
typedef struct reg_glbl_sts1 {
	union {
		struct {
			uint32_t arc_cqf_idle : 1,
				arc_cqf_is_stop : 1,
				_reserved2 : 30;
		};
		uint32_t _raw;
	};
} reg_glbl_sts1;
static_assert((sizeof(struct reg_glbl_sts1) == 4), "reg_glbl_sts1 size is not 32-bit");
/*
 GLBL_ERR_STS 
 b'Error: Error cause'
*/
typedef struct reg_glbl_err_sts {
	union {
		struct {
			uint32_t pqf_rd_err : 1,
				cqf_rd_err : 1,
				cp_rd_err : 1,
				cp_undef_cmd_err : 1,
				cp_stop_op : 1,
				cp_msg_wr_err : 1,
				cp_wreg_err : 1,
				_reserved8 : 1,
				cp_fence0_ovf_err : 1,
				cp_fence1_ovf_err : 1,
				cp_fence2_ovf_err : 1,
				cp_fence3_ovf_err : 1,
				cp_fence0_udf_err : 1,
				cp_fence1_udf_err : 1,
				cp_fence2_udf_err : 1,
				cp_fence3_udf_err : 1,
				cpdma_up_ovf_err : 1,
				pqc_l2h_err : 1,
				rsvd_18_24 : 7,
				_reserved25 : 7;
		};
		uint32_t _raw;
	};
} reg_glbl_err_sts;
static_assert((sizeof(struct reg_glbl_err_sts) == 4), "reg_glbl_err_sts size is not 32-bit");
/*
 GLBL_ERR_STS_4 
 b'Error: Error cause (continue ..)'
*/
typedef struct reg_glbl_err_sts_4 {
	union {
		struct {
			uint32_t rsvd0 : 1,
				cqf_rd_err : 1,
				cp_rd_err : 1,
				cp_undef_cmd_err : 1,
				cp_stop_op : 1,
				cp_msg_wr_err : 1,
				cp_wreg_err : 1,
				_reserved8 : 1,
				cp_fence0_ovf_err : 1,
				cp_fence1_ovf_err : 1,
				cp_fence2_ovf_err : 1,
				cp_fence3_ovf_err : 1,
				cp_fence0_udf_err : 1,
				cp_fence1_udf_err : 1,
				cp_fence2_udf_err : 1,
				cp_fence3_udf_err : 1,
				cpdma_up_ovf_err : 1,
				rsvd17 : 1,
				cq_wr_ififo_ci_err : 1,
				cq_wr_ctl_ci_err : 1,
				arc_cqf_rd_err : 1,
				arc_cq_wr_ififo_ci_err : 1,
				arc_cq_wr_ctl_ci_err : 1,
				arc_axi_err : 1,
				cp_switch_wdt_err : 1,
				_reserved25 : 7;
		};
		uint32_t _raw;
	};
} reg_glbl_err_sts_4;
static_assert((sizeof(struct reg_glbl_err_sts_4) == 4), "reg_glbl_err_sts_4 size is not 32-bit");
/*
 GLBL_ERR_MSG_EN 
 b'Error-Msg: MSG EN per indication'
*/
typedef struct reg_glbl_err_msg_en {
	union {
		struct {
			uint32_t pqf_rd_err : 1,
				cqf_rd_err : 1,
				cp_rd_err : 1,
				cp_undef_cmd_err : 1,
				cp_stop_op : 1,
				cp_msg_wr_err : 1,
				cp_wreg_err : 1,
				_reserved8 : 1,
				cp_fence0_ovf_err : 1,
				cp_fence1_ovf_err : 1,
				cp_fence2_ovf_err : 1,
				cp_fence3_ovf_err : 1,
				cp_fence0_udf_err : 1,
				cp_fence1_udf_err : 1,
				cp_fence2_udf_err : 1,
				cp_fence3_udf_err : 1,
				cpdma_up_ovf_err : 1,
				pqc_l2h_err : 1,
				rsvd_18_24 : 7,
				_reserved25 : 7;
		};
		uint32_t _raw;
	};
} reg_glbl_err_msg_en;
static_assert((sizeof(struct reg_glbl_err_msg_en) == 4), "reg_glbl_err_msg_en size is not 32-bit");
/*
 GLBL_ERR_MSG_EN_4 
 b'Error-Msg: MSG EN per indication'
*/
typedef struct reg_glbl_err_msg_en_4 {
	union {
		struct {
			uint32_t rsvd0 : 1,
				cqf_rd_err : 1,
				cp_rd_err : 1,
				cp_undef_cmd_err : 1,
				cp_stop_op : 1,
				cp_msg_wr_err : 1,
				cp_wreg_err : 1,
				_reserved8 : 1,
				cp_fence0_ovf_err : 1,
				cp_fence1_ovf_err : 1,
				cp_fence2_ovf_err : 1,
				cp_fence3_ovf_err : 1,
				cp_fence0_udf_err : 1,
				cp_fence1_udf_err : 1,
				cp_fence2_udf_err : 1,
				cp_fence3_udf_err : 1,
				cpdma_up_ovf_err : 1,
				rsvd17 : 1,
				cq_wr_ififo_ci_err : 1,
				cq_wr_ctl_ci_err : 1,
				arc_cqf_rd_err : 1,
				arc_cq_wr_ififo_ci_err : 1,
				arc_cq_wr_ctl_ci_err : 1,
				arc_axi_err : 1,
				cp_switch_wdt_err : 1,
				_reserved25 : 7;
		};
		uint32_t _raw;
	};
} reg_glbl_err_msg_en_4;
static_assert((sizeof(struct reg_glbl_err_msg_en_4) == 4), "reg_glbl_err_msg_en_4 size is not 32-bit");
/*
 GLBL_PROT 
 b'Protection bit (1-Secured/0-User)'
*/
typedef struct reg_glbl_prot {
	union {
		struct {
			uint32_t pqf : 4,
				cqf : 5,
				cp : 5,
				err : 1,
				arb : 1,
				pqc : 1,
				cq_ififo_msg : 1,
				arc_cq_ififo_msg : 1,
				cq_ctl_msg : 1,
				arc_cq_ctl_msg : 1,
				cp_wr_arc : 1,
				arc_cqf : 1,
				arc_core : 1,
				_reserved24 : 8;
		};
		uint32_t _raw;
	};
} reg_glbl_prot;
static_assert((sizeof(struct reg_glbl_prot) == 4), "reg_glbl_prot size is not 32-bit");
/*
 PQ_BASE_LO 
 b'PQ: Base-Address (bytes 3-0)'
*/
typedef struct reg_pq_base_lo {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_pq_base_lo;
static_assert((sizeof(struct reg_pq_base_lo) == 4), "reg_pq_base_lo size is not 32-bit");
/*
 PQ_BASE_HI 
 b'PQ: Base address (bytes 7-4)'
*/
typedef struct reg_pq_base_hi {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_pq_base_hi;
static_assert((sizeof(struct reg_pq_base_hi) == 4), "reg_pq_base_hi size is not 32-bit");
/*
 PQ_SIZE 
 b'PQ: Size (LOG2) [EG:8 is 256)'
*/
typedef struct reg_pq_size {
	union {
		struct {
			uint32_t val : 5,
				_reserved5 : 27;
		};
		uint32_t _raw;
	};
} reg_pq_size;
static_assert((sizeof(struct reg_pq_size) == 4), "reg_pq_size size is not 32-bit");
/*
 PQ_PI 
 b'PQ: WR pointer. SW managed. raps at 2xPOW2(size)'
*/
typedef struct reg_pq_pi {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_pq_pi;
static_assert((sizeof(struct reg_pq_pi) == 4), "reg_pq_pi size is not 32-bit");
/*
 PQ_CI 
 b'PQ: RD pointer. HW managed. wraps at 2xPOW2(size)'
*/
typedef struct reg_pq_ci {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_pq_ci;
static_assert((sizeof(struct reg_pq_ci) == 4), "reg_pq_ci size is not 32-bit");
/*
 PQ_CFG0 
 b'PQ: Stall PQ buffer'
*/
typedef struct reg_pq_cfg0 {
	union {
		struct {
			uint32_t force_stall : 1,
				_reserved1 : 31;
		};
		uint32_t _raw;
	};
} reg_pq_cfg0;
static_assert((sizeof(struct reg_pq_cfg0) == 4), "reg_pq_cfg0 size is not 32-bit");
/*
 PQ_CFG1 
 b'PQ: Buffer limit & Inflight limit'
*/
typedef struct reg_pq_cfg1 {
	union {
		struct {
			uint32_t credit_lim : 8,
				_reserved16 : 8,
				max_inflight : 8,
				_reserved24 : 8;
		};
		uint32_t _raw;
	};
} reg_pq_cfg1;
static_assert((sizeof(struct reg_pq_cfg1) == 4), "reg_pq_cfg1 size is not 32-bit");
/*
 PQ_STS0 
 b'PQ-STS: Credit/Free/Inflight counters'
*/
typedef struct reg_pq_sts0 {
	union {
		struct {
			uint32_t credit_cnt : 8,
				free_cnt : 8,
				inflight_cnt : 8,
				_reserved24 : 8;
		};
		uint32_t _raw;
	};
} reg_pq_sts0;
static_assert((sizeof(struct reg_pq_sts0) == 4), "reg_pq_sts0 size is not 32-bit");
/*
 PQ_STS1 
 b'PQ-STS: Bus-empty/Busy'
*/
typedef struct reg_pq_sts1 {
	union {
		struct {
			uint32_t buf_empty : 1,
				busy : 1,
				_reserved2 : 30;
		};
		uint32_t _raw;
	};
} reg_pq_sts1;
static_assert((sizeof(struct reg_pq_sts1) == 4), "reg_pq_sts1 size is not 32-bit");
/*
 CQ_CFG0 
 b'CQF-CFG: B2B Enable / MSG-Enable'
*/
typedef struct reg_cq_cfg0 {
	union {
		struct {
			uint32_t if_b2b_en : 1,
				if_msg_en : 1,
				ctl_msg_en : 1,
				_reserved3 : 29;
		};
		uint32_t _raw;
	};
} reg_cq_cfg0;
static_assert((sizeof(struct reg_cq_cfg0) == 4), "reg_cq_cfg0 size is not 32-bit");
/*
 CQ_STS0 
 b'CQ-STS: Credit/Free/Inflight counters'
*/
typedef struct reg_cq_sts0 {
	union {
		struct {
			uint32_t credit_cnt : 8,
				free_cnt : 8,
				inflight_cnt : 8,
				_reserved24 : 8;
		};
		uint32_t _raw;
	};
} reg_cq_sts0;
static_assert((sizeof(struct reg_cq_sts0) == 4), "reg_cq_sts0 size is not 32-bit");
/*
 CQ_CFG1 
 b'CQ-CFG: Buffer and Inflight limit'
*/
typedef struct reg_cq_cfg1 {
	union {
		struct {
			uint32_t credit_lim : 8,
				_reserved16 : 8,
				max_inflight : 8,
				_reserved24 : 8;
		};
		uint32_t _raw;
	};
} reg_cq_cfg1;
static_assert((sizeof(struct reg_cq_cfg1) == 4), "reg_cq_cfg1 size is not 32-bit");
/*
 CQ_STS1 
 b'CQ-STS: Bus-empty/Busy'
*/
typedef struct reg_cq_sts1 {
	union {
		struct {
			uint32_t buf_empty : 1,
				busy : 1,
				_reserved2 : 30;
		};
		uint32_t _raw;
	};
} reg_cq_sts1;
static_assert((sizeof(struct reg_cq_sts1) == 4), "reg_cq_sts1 size is not 32-bit");
/*
 CQ_PTR_LO_0 
 b'CQF0(Upper): Pointer (LSB)'
*/
typedef struct reg_cq_ptr_lo_0 {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_cq_ptr_lo_0;
static_assert((sizeof(struct reg_cq_ptr_lo_0) == 4), "reg_cq_ptr_lo_0 size is not 32-bit");
/*
 CQ_PTR_HI_0 
 b'CQF0(Upper): Pointer (MSB)'
*/
typedef struct reg_cq_ptr_hi_0 {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_cq_ptr_hi_0;
static_assert((sizeof(struct reg_cq_ptr_hi_0) == 4), "reg_cq_ptr_hi_0 size is not 32-bit");
/*
 CQ_TSIZE_0 
 b'CQF0(Upper): Size in bytes'
*/
typedef struct reg_cq_tsize_0 {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_cq_tsize_0;
static_assert((sizeof(struct reg_cq_tsize_0) == 4), "reg_cq_tsize_0 size is not 32-bit");
/*
 CQ_CTL_0 
 b'CQF0(Upper): Control (WR initiate CQ read)'
*/
typedef struct reg_cq_ctl_0 {
	union {
		struct {
			uint32_t _reserved28 : 28,
up : 4;
		};
		uint32_t _raw;
	};
} reg_cq_ctl_0;
static_assert((sizeof(struct reg_cq_ctl_0) == 4), "reg_cq_ctl_0 size is not 32-bit");
/*
 CQ_PTR_LO_1 
 b'CQF1(Upper): Pointer (LSB)'
*/
typedef struct reg_cq_ptr_lo_1 {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_cq_ptr_lo_1;
static_assert((sizeof(struct reg_cq_ptr_lo_1) == 4), "reg_cq_ptr_lo_1 size is not 32-bit");
/*
 CQ_PTR_HI_1 
 b'CQF1(Upper): Pointer (MSB)'
*/
typedef struct reg_cq_ptr_hi_1 {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_cq_ptr_hi_1;
static_assert((sizeof(struct reg_cq_ptr_hi_1) == 4), "reg_cq_ptr_hi_1 size is not 32-bit");
/*
 CQ_TSIZE_1 
 b'CQF1(Upper): Size in bytes'
*/
typedef struct reg_cq_tsize_1 {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_cq_tsize_1;
static_assert((sizeof(struct reg_cq_tsize_1) == 4), "reg_cq_tsize_1 size is not 32-bit");
/*
 CQ_CTL_1 
 b'CQF1(Upper): Control (WR initiate CQ read)'
*/
typedef struct reg_cq_ctl_1 {
	union {
		struct {
			uint32_t _reserved28 : 28,
up : 4;
		};
		uint32_t _raw;
	};
} reg_cq_ctl_1;
static_assert((sizeof(struct reg_cq_ctl_1) == 4), "reg_cq_ctl_1 size is not 32-bit");
/*
 CQ_PTR_LO_2 
 b'CQF2(Upper): Pointer (LSB)'
*/
typedef struct reg_cq_ptr_lo_2 {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_cq_ptr_lo_2;
static_assert((sizeof(struct reg_cq_ptr_lo_2) == 4), "reg_cq_ptr_lo_2 size is not 32-bit");
/*
 CQ_PTR_HI_2 
 b'CQF2(Upper): Pointer (MSB)'
*/
typedef struct reg_cq_ptr_hi_2 {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_cq_ptr_hi_2;
static_assert((sizeof(struct reg_cq_ptr_hi_2) == 4), "reg_cq_ptr_hi_2 size is not 32-bit");
/*
 CQ_TSIZE_2 
 b'CQF2(Upper): Size in bytes'
*/
typedef struct reg_cq_tsize_2 {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_cq_tsize_2;
static_assert((sizeof(struct reg_cq_tsize_2) == 4), "reg_cq_tsize_2 size is not 32-bit");
/*
 CQ_CTL_2 
 b'CQF2(Upper): Control (WR initiate CQ read)'
*/
typedef struct reg_cq_ctl_2 {
	union {
		struct {
			uint32_t _reserved28 : 28,
up : 4;
		};
		uint32_t _raw;
	};
} reg_cq_ctl_2;
static_assert((sizeof(struct reg_cq_ctl_2) == 4), "reg_cq_ctl_2 size is not 32-bit");
/*
 CQ_PTR_LO_3 
 b'CQF3(Upper): Pointer (LSB)'
*/
typedef struct reg_cq_ptr_lo_3 {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_cq_ptr_lo_3;
static_assert((sizeof(struct reg_cq_ptr_lo_3) == 4), "reg_cq_ptr_lo_3 size is not 32-bit");
/*
 CQ_PTR_HI_3 
 b'CQF3(Upper): Pointer (MSB)'
*/
typedef struct reg_cq_ptr_hi_3 {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_cq_ptr_hi_3;
static_assert((sizeof(struct reg_cq_ptr_hi_3) == 4), "reg_cq_ptr_hi_3 size is not 32-bit");
/*
 CQ_TSIZE_3 
 b'CQF3(Upper): Size in bytes'
*/
typedef struct reg_cq_tsize_3 {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_cq_tsize_3;
static_assert((sizeof(struct reg_cq_tsize_3) == 4), "reg_cq_tsize_3 size is not 32-bit");
/*
 CQ_CTL_3 
 b'CQF4(Lower): Control (WR initiate CQ read)'
*/
typedef struct reg_cq_ctl_3 {
	union {
		struct {
			uint32_t _reserved28 : 28,
up : 4;
		};
		uint32_t _raw;
	};
} reg_cq_ctl_3;
static_assert((sizeof(struct reg_cq_ctl_3) == 4), "reg_cq_ctl_3 size is not 32-bit");
/*
 CQ_PTR_LO_4 
 b'CQF4(Lower: Pointer (LSB)'
*/
typedef struct reg_cq_ptr_lo_4 {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_cq_ptr_lo_4;
static_assert((sizeof(struct reg_cq_ptr_lo_4) == 4), "reg_cq_ptr_lo_4 size is not 32-bit");
/*
 CQ_PTR_HI_4 
 b'CQF4(Lower): Pointer (MSB)'
*/
typedef struct reg_cq_ptr_hi_4 {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_cq_ptr_hi_4;
static_assert((sizeof(struct reg_cq_ptr_hi_4) == 4), "reg_cq_ptr_hi_4 size is not 32-bit");
/*
 CQ_TSIZE_4 
 b'CQF4(Lower): Size in bytes'
*/
typedef struct reg_cq_tsize_4 {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_cq_tsize_4;
static_assert((sizeof(struct reg_cq_tsize_4) == 4), "reg_cq_tsize_4 size is not 32-bit");
/*
 CQ_CTL_4 
 b'CQF4(Lower): Control (WR initiate CQ read)'
*/
typedef struct reg_cq_ctl_4 {
	union {
		struct {
			uint32_t _reserved28 : 28,
up : 4;
		};
		uint32_t _raw;
	};
} reg_cq_ctl_4;
static_assert((sizeof(struct reg_cq_ctl_4) == 4), "reg_cq_ctl_4 size is not 32-bit");
/*
 CQ_TSIZE_STS 
 b'CQ-STS: Current transfer size in bytes'
*/
typedef struct reg_cq_tsize_sts {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_cq_tsize_sts;
static_assert((sizeof(struct reg_cq_tsize_sts) == 4), "reg_cq_tsize_sts size is not 32-bit");
/*
 CQ_PTR_LO_STS 
 b'CQ-STS: Current Transfer base address byte 3-0'
*/
typedef struct reg_cq_ptr_lo_sts {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_cq_ptr_lo_sts;
static_assert((sizeof(struct reg_cq_ptr_lo_sts) == 4), "reg_cq_ptr_lo_sts size is not 32-bit");
/*
 CQ_PTR_HI_STS 
 b'CQ-STS: Current transfer base address byte 7-4'
*/
typedef struct reg_cq_ptr_hi_sts {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_cq_ptr_hi_sts;
static_assert((sizeof(struct reg_cq_ptr_hi_sts) == 4), "reg_cq_ptr_hi_sts size is not 32-bit");
/*
 CQ_IFIFO_STS 
 b'CQ-STATUS: Input FIFO (Occupancy/Ready-Busy)'
*/
typedef struct reg_cq_ififo_sts {
	union {
		struct {
			uint32_t cnt : 3,
				_reserved4 : 1,
				rdy : 1,
				_reserved8 : 3,
				ctl_stall : 1,
				_reserved9 : 23;
		};
		uint32_t _raw;
	};
} reg_cq_ififo_sts;
static_assert((sizeof(struct reg_cq_ififo_sts) == 4), "reg_cq_ififo_sts size is not 32-bit");
/*
 CP_MSG_BASE0_ADDR_LO 
 b'CP: MESSAGE_BASE_ADDR_0 (LSB)'
*/
typedef struct reg_cp_msg_base0_addr_lo {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_cp_msg_base0_addr_lo;
static_assert((sizeof(struct reg_cp_msg_base0_addr_lo) == 4), "reg_cp_msg_base0_addr_lo size is not 32-bit");
/*
 CP_MSG_BASE0_ADDR_HI 
 b'CP: MESSAGE_BASE_ADDR_0 (MSB)'
*/
typedef struct reg_cp_msg_base0_addr_hi {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_cp_msg_base0_addr_hi;
static_assert((sizeof(struct reg_cp_msg_base0_addr_hi) == 4), "reg_cp_msg_base0_addr_hi size is not 32-bit");
/*
 CP_MSG_BASE1_ADDR_LO 
 b'CP: MESSAGE_BASE_ADDR_1 (LSB)'
*/
typedef struct reg_cp_msg_base1_addr_lo {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_cp_msg_base1_addr_lo;
static_assert((sizeof(struct reg_cp_msg_base1_addr_lo) == 4), "reg_cp_msg_base1_addr_lo size is not 32-bit");
/*
 CP_MSG_BASE1_ADDR_HI 
 b'CP: MESSAGE_BASE_ADDR_1 (MSB)'
*/
typedef struct reg_cp_msg_base1_addr_hi {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_cp_msg_base1_addr_hi;
static_assert((sizeof(struct reg_cp_msg_base1_addr_hi) == 4), "reg_cp_msg_base1_addr_hi size is not 32-bit");
/*
 CP_MSG_BASE2_ADDR_LO 
 b'CP: MESSAGE_BASE_ADDR_2 (LSB)'
*/
typedef struct reg_cp_msg_base2_addr_lo {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_cp_msg_base2_addr_lo;
static_assert((sizeof(struct reg_cp_msg_base2_addr_lo) == 4), "reg_cp_msg_base2_addr_lo size is not 32-bit");
/*
 CP_MSG_BASE2_ADDR_HI 
 b'CP: MESSAGE_BASE_ADDR_2 (MSB)'
*/
typedef struct reg_cp_msg_base2_addr_hi {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_cp_msg_base2_addr_hi;
static_assert((sizeof(struct reg_cp_msg_base2_addr_hi) == 4), "reg_cp_msg_base2_addr_hi size is not 32-bit");
/*
 CP_MSG_BASE3_ADDR_LO 
 b'CP: MESSAGE_BASE_ADDR_3 (LSB)'
*/
typedef struct reg_cp_msg_base3_addr_lo {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_cp_msg_base3_addr_lo;
static_assert((sizeof(struct reg_cp_msg_base3_addr_lo) == 4), "reg_cp_msg_base3_addr_lo size is not 32-bit");
/*
 CP_MSG_BASE3_ADDR_HI 
 b'CP: MESSAGE_BASE_ADDR_3 (MSB)'
*/
typedef struct reg_cp_msg_base3_addr_hi {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_cp_msg_base3_addr_hi;
static_assert((sizeof(struct reg_cp_msg_base3_addr_hi) == 4), "reg_cp_msg_base3_addr_hi size is not 32-bit");
/*
 CP_FENCE0_RDATA 
 b'CP-FENCE-0: Increment value for fence 0'
*/
typedef struct reg_cp_fence0_rdata {
	union {
		struct {
			uint32_t inc_val : 4,
				_reserved4 : 28;
		};
		uint32_t _raw;
	};
} reg_cp_fence0_rdata;
static_assert((sizeof(struct reg_cp_fence0_rdata) == 4), "reg_cp_fence0_rdata size is not 32-bit");
/*
 CP_FENCE1_RDATA 
 b'CP-FENCE-1: Increment value for fence 1'
*/
typedef struct reg_cp_fence1_rdata {
	union {
		struct {
			uint32_t inc_val : 4,
				_reserved4 : 28;
		};
		uint32_t _raw;
	};
} reg_cp_fence1_rdata;
static_assert((sizeof(struct reg_cp_fence1_rdata) == 4), "reg_cp_fence1_rdata size is not 32-bit");
/*
 CP_FENCE2_RDATA 
 b'CP-FENCE-2:Increment value for fence 2'
*/
typedef struct reg_cp_fence2_rdata {
	union {
		struct {
			uint32_t inc_val : 4,
				_reserved4 : 28;
		};
		uint32_t _raw;
	};
} reg_cp_fence2_rdata;
static_assert((sizeof(struct reg_cp_fence2_rdata) == 4), "reg_cp_fence2_rdata size is not 32-bit");
/*
 CP_FENCE3_RDATA 
 b'CP-FENCE-3:Increment value for fence 3'
*/
typedef struct reg_cp_fence3_rdata {
	union {
		struct {
			uint32_t inc_val : 4,
				_reserved4 : 28;
		};
		uint32_t _raw;
	};
} reg_cp_fence3_rdata;
static_assert((sizeof(struct reg_cp_fence3_rdata) == 4), "reg_cp_fence3_rdata size is not 32-bit");
/*
 CP_FENCE0_CNT 
 b'CP-FENCE-0: Fence 0 (Value)'
*/
typedef struct reg_cp_fence0_cnt {
	union {
		struct {
			uint32_t val : 14,
				_reserved14 : 18;
		};
		uint32_t _raw;
	};
} reg_cp_fence0_cnt;
static_assert((sizeof(struct reg_cp_fence0_cnt) == 4), "reg_cp_fence0_cnt size is not 32-bit");
/*
 CP_FENCE1_CNT 
 b'CP-FENCE-1: Fence 1 (Value)'
*/
typedef struct reg_cp_fence1_cnt {
	union {
		struct {
			uint32_t val : 14,
				_reserved14 : 18;
		};
		uint32_t _raw;
	};
} reg_cp_fence1_cnt;
static_assert((sizeof(struct reg_cp_fence1_cnt) == 4), "reg_cp_fence1_cnt size is not 32-bit");
/*
 CP_FENCE2_CNT 
 b'CP-FENCE-2: Fence 2 (Value)'
*/
typedef struct reg_cp_fence2_cnt {
	union {
		struct {
			uint32_t val : 14,
				_reserved14 : 18;
		};
		uint32_t _raw;
	};
} reg_cp_fence2_cnt;
static_assert((sizeof(struct reg_cp_fence2_cnt) == 4), "reg_cp_fence2_cnt size is not 32-bit");
/*
 CP_FENCE3_CNT 
 b'CP-FENCE-3: Fence 3 (Value)'
*/
typedef struct reg_cp_fence3_cnt {
	union {
		struct {
			uint32_t val : 14,
				_reserved14 : 18;
		};
		uint32_t _raw;
	};
} reg_cp_fence3_cnt;
static_assert((sizeof(struct reg_cp_fence3_cnt) == 4), "reg_cp_fence3_cnt size is not 32-bit");
/*
 CP_BARRIER_CFG 
 b'CP: Guard band (Allow engine to de-assert idle)'
*/
typedef struct reg_cp_barrier_cfg {
	union {
		struct {
			uint32_t ebguard : 12,
				_reserved16 : 4,
				rbguard : 4,
				_reserved20 : 12;
		};
		uint32_t _raw;
	};
} reg_cp_barrier_cfg;
static_assert((sizeof(struct reg_cp_barrier_cfg) == 4), "reg_cp_barrier_cfg size is not 32-bit");
/*
 CP_LDMA_SRC_BASE_LO_OFFSET 
 b'CP:LDMA: SRC_BASE_LO OFFSET (relative to DMA QMAN)'
*/
typedef struct reg_cp_ldma_src_base_lo_offset {
	union {
		struct {
			uint32_t val : 16,
				_reserved16 : 16;
		};
		uint32_t _raw;
	};
} reg_cp_ldma_src_base_lo_offset;
static_assert((sizeof(struct reg_cp_ldma_src_base_lo_offset) == 4), "reg_cp_ldma_src_base_lo_offset size is not 32-bit");
/*
 CP_LDMA_DST_BASE_LO_OFFSET 
 b'CP:LDMA: DST_BASE_LO OFFSET (relative to DMA QMAN)'
*/
typedef struct reg_cp_ldma_dst_base_lo_offset {
	union {
		struct {
			uint32_t val : 16,
				_reserved16 : 16;
		};
		uint32_t _raw;
	};
} reg_cp_ldma_dst_base_lo_offset;
static_assert((sizeof(struct reg_cp_ldma_dst_base_lo_offset) == 4), "reg_cp_ldma_dst_base_lo_offset size is not 32-bit");
/*
 CP_LDMA_TSIZE_OFFSET 
 b'CP:LDMA. DST_TSIZE_0 OFFSET (relative to DMA QMAN)'
*/
typedef struct reg_cp_ldma_tsize_offset {
	union {
		struct {
			uint32_t val : 16,
				_reserved16 : 16;
		};
		uint32_t _raw;
	};
} reg_cp_ldma_tsize_offset;
static_assert((sizeof(struct reg_cp_ldma_tsize_offset) == 4), "reg_cp_ldma_tsize_offset size is not 32-bit");
/*
 CP_CQ_PTR_LO_OFFSET_0 
 b'CP: CPDMA CQ_PTR_LO_0 OFFSET(relative to QMAN)'
*/
typedef struct reg_cp_cq_ptr_lo_offset_0 {
	union {
		struct {
			uint32_t val : 16,
				_reserved16 : 16;
		};
		uint32_t _raw;
	};
} reg_cp_cq_ptr_lo_offset_0;
static_assert((sizeof(struct reg_cp_cq_ptr_lo_offset_0) == 4), "reg_cp_cq_ptr_lo_offset_0 size is not 32-bit");
/*
 CP_CQ_PTR_LO_OFFSET_1 
 b'CP: CPDMA CQ_PTR_LO_1 OFFSET(relative to QMAN)'
*/
typedef struct reg_cp_cq_ptr_lo_offset_1 {
	union {
		struct {
			uint32_t val : 16,
				_reserved16 : 16;
		};
		uint32_t _raw;
	};
} reg_cp_cq_ptr_lo_offset_1;
static_assert((sizeof(struct reg_cp_cq_ptr_lo_offset_1) == 4), "reg_cp_cq_ptr_lo_offset_1 size is not 32-bit");
/*
 CP_CQ_PTR_LO_OFFSET_2 
 b'CP: CPDMA CQ_PTR_LO_2 OFFSET(relative to QMAN)'
*/
typedef struct reg_cp_cq_ptr_lo_offset_2 {
	union {
		struct {
			uint32_t val : 16,
				_reserved16 : 16;
		};
		uint32_t _raw;
	};
} reg_cp_cq_ptr_lo_offset_2;
static_assert((sizeof(struct reg_cp_cq_ptr_lo_offset_2) == 4), "reg_cp_cq_ptr_lo_offset_2 size is not 32-bit");
/*
 CP_CQ_PTR_LO_OFFSET_3 
 b'CP: CPDMA CQ_PTR_LO_3 OFFSET(relative to QMAN)'
*/
typedef struct reg_cp_cq_ptr_lo_offset_3 {
	union {
		struct {
			uint32_t val : 16,
				_reserved16 : 16;
		};
		uint32_t _raw;
	};
} reg_cp_cq_ptr_lo_offset_3;
static_assert((sizeof(struct reg_cp_cq_ptr_lo_offset_3) == 4), "reg_cp_cq_ptr_lo_offset_3 size is not 32-bit");
/*
 CP_CQ_PTR_LO_OFFSET_4 
 b'CP: CPDMA CQ_PTR_LO_4 OFFSET (relative to QMAN)'
*/
typedef struct reg_cp_cq_ptr_lo_offset_4 {
	union {
		struct {
			uint32_t val : 16,
				_reserved16 : 16;
		};
		uint32_t _raw;
	};
} reg_cp_cq_ptr_lo_offset_4;
static_assert((sizeof(struct reg_cp_cq_ptr_lo_offset_4) == 4), "reg_cp_cq_ptr_lo_offset_4 size is not 32-bit");
/*
 CP_STS 
 b'CP-STS: CP Status (Switch/Fence-ID/In-flights..)'
*/
typedef struct reg_cp_sts {
	union {
		struct {
			uint32_t msg_inflight_cnt : 8,
				erdy : 1,
				switch_en : 1,
				mrdy : 1,
				sw_stop : 1,
				fence_id : 2,
				fence_in_progress : 1,
				_reserved16 : 1,
				fence_target : 14,
				cur_cq : 1,
				_reserved31 : 1;
		};
		uint32_t _raw;
	};
} reg_cp_sts;
static_assert((sizeof(struct reg_cp_sts) == 4), "reg_cp_sts size is not 32-bit");
/*
 CP_CURRENT_INST_LO 
 b'CP: Current CP instruction (Byte 3-0)'
*/
typedef struct reg_cp_current_inst_lo {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_cp_current_inst_lo;
static_assert((sizeof(struct reg_cp_current_inst_lo) == 4), "reg_cp_current_inst_lo size is not 32-bit");
/*
 CP_CURRENT_INST_HI 
 b'CP: Current CP instruction (Byte 7-4)'
*/
typedef struct reg_cp_current_inst_hi {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_cp_current_inst_hi;
static_assert((sizeof(struct reg_cp_current_inst_hi) == 4), "reg_cp_current_inst_hi size is not 32-bit");
/*
 CP_PRED 
 b'CP: Predicates (Can also be updated by LOAD_N_EXE)'
*/
typedef struct reg_cp_pred {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_cp_pred;
static_assert((sizeof(struct reg_cp_pred) == 4), "reg_cp_pred size is not 32-bit");
/*
 CP_PRED_UPEN 
 b'CP:Bit per predicate to allow update by LOAD_N_EXE'
*/
typedef struct reg_cp_pred_upen {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_cp_pred_upen;
static_assert((sizeof(struct reg_cp_pred_upen) == 4), "reg_cp_pred_upen size is not 32-bit");
/*
 CP_DBG_0 
 b'CP: CP state (Debug)'
*/
typedef struct reg_cp_dbg_0 {
	union {
		struct {
			uint32_t cs : 5,
				eb_cnt_not_zero : 1,
				bulk_cnt_not_zero : 1,
				mreb_stall : 1,
				stall : 1,
				_reserved9 : 23;
		};
		uint32_t _raw;
	};
} reg_cp_dbg_0;
static_assert((sizeof(struct reg_cp_dbg_0) == 4), "reg_cp_dbg_0 size is not 32-bit");
/*
 CP_CPDMA_UP_CRED 
 b'CP-DMA: Status ,threshold, inflight CPDMA count'
*/
typedef struct reg_cp_cpdma_up_cred {
	union {
		struct {
			uint32_t th : 2,
				_reserved8 : 6,
				val : 2,
				_reserved10 : 22;
		};
		uint32_t _raw;
	};
} reg_cp_cpdma_up_cred;
static_assert((sizeof(struct reg_cp_cpdma_up_cred) == 4), "reg_cp_cpdma_up_cred size is not 32-bit");
/*
 CP_IN_DATA_LO 
 b'CP: Head of CQ2CP DATA Q (instructions Q) Byte 3-0'
*/
typedef struct reg_cp_in_data_lo {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_cp_in_data_lo;
static_assert((sizeof(struct reg_cp_in_data_lo) == 4), "reg_cp_in_data_lo size is not 32-bit");
/*
 CP_IN_DATA_HI 
 b'CP: Head of CQ2CP DATA Q (instructions Q) Byte 7-4'
*/
typedef struct reg_cp_in_data_hi {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_cp_in_data_hi;
static_assert((sizeof(struct reg_cp_in_data_hi) == 4), "reg_cp_in_data_hi size is not 32-bit");
/*
 PQC_HBW_BASE_LO 
 b'PQ-CQ: Completion Q base address bytes 3 to 0'
*/
typedef struct reg_pqc_hbw_base_lo {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_pqc_hbw_base_lo;
static_assert((sizeof(struct reg_pqc_hbw_base_lo) == 4), "reg_pqc_hbw_base_lo size is not 32-bit");
/*
 PQC_HBW_BASE_HI 
 b'PQ-CQ: Completion Q base address bytes 7 to 4'
*/
typedef struct reg_pqc_hbw_base_hi {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_pqc_hbw_base_hi;
static_assert((sizeof(struct reg_pqc_hbw_base_hi) == 4), "reg_pqc_hbw_base_hi size is not 32-bit");
/*
 PQC_SIZE 
 b'PQ-CQ: CQ size (Log2) per PQ.4B granularity'
*/
typedef struct reg_pqc_size {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_pqc_size;
static_assert((sizeof(struct reg_pqc_size) == 4), "reg_pqc_size size is not 32-bit");
/*
 PQC_PI 
 b'PQ-CQ: Val of HW MNG PQC PI. Host WR allowed'
*/
typedef struct reg_pqc_pi {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_pqc_pi;
static_assert((sizeof(struct reg_pqc_pi) == 4), "reg_pqc_pi size is not 32-bit");
/*
 PQC_LBW_WDATA 
 b'PQ-CQ: LBW completion data'
*/
typedef struct reg_pqc_lbw_wdata {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_pqc_lbw_wdata;
static_assert((sizeof(struct reg_pqc_lbw_wdata) == 4), "reg_pqc_lbw_wdata size is not 32-bit");
/*
 PQC_LBW_BASE_LO 
 b'PQ-CQ: Completion address (LSB) .PQE offset added'
*/
typedef struct reg_pqc_lbw_base_lo {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_pqc_lbw_base_lo;
static_assert((sizeof(struct reg_pqc_lbw_base_lo) == 4), "reg_pqc_lbw_base_lo size is not 32-bit");
/*
 PQC_LBW_BASE_HI 
 b'PQ-CQ: Completion address (MSB) .PQE offset added'
*/
typedef struct reg_pqc_lbw_base_hi {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_pqc_lbw_base_hi;
static_assert((sizeof(struct reg_pqc_lbw_base_hi) == 4), "reg_pqc_lbw_base_hi size is not 32-bit");
/*
 PQC_CFG 
 b'PQ-CQ: Completion flow enable and mode'
*/
typedef struct reg_pqc_cfg {
	union {
		struct {
			uint32_t en : 1,
				_reserved4 : 3,
				direct : 1,
				_reserved5 : 27;
		};
		uint32_t _raw;
	};
} reg_pqc_cfg;
static_assert((sizeof(struct reg_pqc_cfg) == 4), "reg_pqc_cfg size is not 32-bit");
/*
 PQC_SECURE_PUSH_IND 
 b'PQ-CQ: For completion indirect mode upper CPs push'
*/
typedef struct reg_pqc_secure_push_ind {
	union {
		struct {
			uint32_t cp_num : 2,
				_reserved2 : 30;
		};
		uint32_t _raw;
	};
} reg_pqc_secure_push_ind;
static_assert((sizeof(struct reg_pqc_secure_push_ind) == 4), "reg_pqc_secure_push_ind size is not 32-bit");
/*
 ARB_MASK 
 b'ARB: QMAN BASE_ADDR for CSMR access'
*/
typedef struct reg_arb_mask {
	union {
		struct {
			uint32_t val : 4,
				_reserved4 : 28;
		};
		uint32_t _raw;
	};
} reg_arb_mask;
static_assert((sizeof(struct reg_arb_mask) == 4), "reg_arb_mask size is not 32-bit");
/*
 ARB_CFG_0 
 b'ARB-CFG: Enable /Type (WRR/Priority) / Is-Master'
*/
typedef struct reg_arb_cfg_0 {
	union {
		struct {
			uint32_t prio_type : 1,
				_reserved4 : 3,
				is_master : 1,
				_reserved8 : 3,
				en : 1,
				mst_msg_nostall : 1,
				_reserved10 : 22;
		};
		uint32_t _raw;
	};
} reg_arb_cfg_0;
static_assert((sizeof(struct reg_arb_cfg_0) == 4), "reg_arb_cfg_0 size is not 32-bit");
/*
 ARB_CHOICE_Q_PUSH 
 b'ARB:SLV: Push choice Q from master'
*/
typedef struct reg_arb_choice_q_push {
	union {
		struct {
			uint32_t val : 2,
				_reserved2 : 30;
		};
		uint32_t _raw;
	};
} reg_arb_choice_q_push;
static_assert((sizeof(struct reg_arb_choice_q_push) == 4), "reg_arb_choice_q_push size is not 32-bit");
/*
 ARB_WRR_WEIGHT 
 b'ARB: WRR Weight'
*/
typedef struct reg_arb_wrr_weight {
	union {
		struct {
			uint32_t val : 8,
				_reserved8 : 24;
		};
		uint32_t _raw;
	};
} reg_arb_wrr_weight;
static_assert((sizeof(struct reg_arb_wrr_weight) == 4), "reg_arb_wrr_weight size is not 32-bit");
/*
 ARB_CFG_1 
 b'ARB-CFG: Reset choice-Q'
*/
typedef struct reg_arb_cfg_1 {
	union {
		struct {
			uint32_t clr : 1,
				_reserved1 : 31;
		};
		uint32_t _raw;
	};
} reg_arb_cfg_1;
static_assert((sizeof(struct reg_arb_cfg_1) == 4), "reg_arb_cfg_1 size is not 32-bit");
/*
 ARB_MST_AVAIL_CRED 
 b'ARB-MST: Limit queue credits (Master side)'
*/
typedef struct reg_arb_mst_avail_cred {
	union {
		struct {
			uint32_t val : 7,
				_reserved7 : 25;
		};
		uint32_t _raw;
	};
} reg_arb_mst_avail_cred;
static_assert((sizeof(struct reg_arb_mst_avail_cred) == 4), "reg_arb_mst_avail_cred size is not 32-bit");
/*
 ARB_MST_CRED_INC 
 b'ARB-MST: Credits increment (Slave->Master)'
*/
typedef struct reg_arb_mst_cred_inc {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_arb_mst_cred_inc;
static_assert((sizeof(struct reg_arb_mst_cred_inc) == 4), "reg_arb_mst_cred_inc size is not 32-bit");
/*
 ARB_MST_CHOICE_PUSH_OFST 
 b'ARB-MST: Choice Queue PUSH offsets'
*/
typedef struct reg_arb_mst_choice_push_ofst {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_arb_mst_choice_push_ofst;
static_assert((sizeof(struct reg_arb_mst_choice_push_ofst) == 4), "reg_arb_mst_choice_push_ofst size is not 32-bit");
/*
 ARB_SLV_MASTER_INC_CRED_OFST 
 b'ARB-SLV: Addr of slave choice-queue push'
*/
typedef struct reg_arb_slv_master_inc_cred_ofst {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_arb_slv_master_inc_cred_ofst;
static_assert((sizeof(struct reg_arb_slv_master_inc_cred_ofst) == 4), "reg_arb_slv_master_inc_cred_ofst size is not 32-bit");
/*
 ARB_MST_SLAVE_EN 
 b'ARB-SLV: Enable notify on CP priority grant (31:0'
*/
typedef struct reg_arb_mst_slave_en {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_arb_mst_slave_en;
static_assert((sizeof(struct reg_arb_mst_slave_en) == 4), "reg_arb_mst_slave_en size is not 32-bit");
/*
 ARB_MST_SLAVE_EN_1 
 b'ARB-SLV: Enable notify on CP priority grant (63:32'
*/
typedef struct reg_arb_mst_slave_en_1 {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_arb_mst_slave_en_1;
static_assert((sizeof(struct reg_arb_mst_slave_en_1) == 4), "reg_arb_mst_slave_en_1 size is not 32-bit");
/*
 ARB_SLV_CHOICE_WDT 
 b'ARB-SLV:Watch Dog For ChoiceQ not popped but ready'
*/
typedef struct reg_arb_slv_choice_wdt {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_arb_slv_choice_wdt;
static_assert((sizeof(struct reg_arb_slv_choice_wdt) == 4), "reg_arb_slv_choice_wdt size is not 32-bit");
/*
 ARB_SLV_ID 
 b'ARB-SLV: QMAN Slave ID (For credit management)'
*/
typedef struct reg_arb_slv_id {
	union {
		struct {
			uint32_t val : 7,
				_reserved7 : 25;
		};
		uint32_t _raw;
	};
} reg_arb_slv_id;
static_assert((sizeof(struct reg_arb_slv_id) == 4), "reg_arb_slv_id size is not 32-bit");
/*
 ARB_MST_QUIET_PER 
 b'ARB-SLV: Quiet period before new grant'
*/
typedef struct reg_arb_mst_quiet_per {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_arb_mst_quiet_per;
static_assert((sizeof(struct reg_arb_mst_quiet_per) == 4), "reg_arb_mst_quiet_per size is not 32-bit");
/*
 ARB_MSG_MAX_INFLIGHT 
 b'ARB-CFG: Limit maximum in-flights'
*/
typedef struct reg_arb_msg_max_inflight {
	union {
		struct {
			uint32_t val : 6,
				_reserved6 : 26;
		};
		uint32_t _raw;
	};
} reg_arb_msg_max_inflight;
static_assert((sizeof(struct reg_arb_msg_max_inflight) == 4), "reg_arb_msg_max_inflight size is not 32-bit");
/*
 ARB_BASE_LO 
 b'ARB-CFG: Base address for arb LBW access (LSB)'
*/
typedef struct reg_arb_base_lo {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_arb_base_lo;
static_assert((sizeof(struct reg_arb_base_lo) == 4), "reg_arb_base_lo size is not 32-bit");
/*
 ARB_BASE_HI 
 b'ARB-CFG: Base address for arb LBW access(MSB)'
*/
typedef struct reg_arb_base_hi {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_arb_base_hi;
static_assert((sizeof(struct reg_arb_base_hi) == 4), "reg_arb_base_hi size is not 32-bit");
/*
 ARB_STATE_STS 
 b'ARB-STS: Current granted CP'
*/
typedef struct reg_arb_state_sts {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_arb_state_sts;
static_assert((sizeof(struct reg_arb_state_sts) == 4), "reg_arb_state_sts size is not 32-bit");
/*
 ARB_CHOICE_FULLNESS_STS 
 b'ARB-STS: Choice-Q full level'
*/
typedef struct reg_arb_choice_fullness_sts {
	union {
		struct {
			uint32_t val : 7,
				_reserved7 : 25;
		};
		uint32_t _raw;
	};
} reg_arb_choice_fullness_sts;
static_assert((sizeof(struct reg_arb_choice_fullness_sts) == 4), "reg_arb_choice_fullness_sts size is not 32-bit");
/*
 ARB_MSG_STS 
 b'ARB-STS: Choice-Q full / No-Inflights'
*/
typedef struct reg_arb_msg_sts {
	union {
		struct {
			uint32_t full : 1,
				no_inflight : 1,
				_reserved2 : 30;
		};
		uint32_t _raw;
	};
} reg_arb_msg_sts;
static_assert((sizeof(struct reg_arb_msg_sts) == 4), "reg_arb_msg_sts size is not 32-bit");
/*
 ARB_SLV_CHOICE_Q_HEAD 
 b'ARB-STS: Head of choice Q next CP to be granted'
*/
typedef struct reg_arb_slv_choice_q_head {
	union {
		struct {
			uint32_t val : 2,
				_reserved2 : 30;
		};
		uint32_t _raw;
	};
} reg_arb_slv_choice_q_head;
static_assert((sizeof(struct reg_arb_slv_choice_q_head) == 4), "reg_arb_slv_choice_q_head size is not 32-bit");
/*
 ARB_ERR_CAUSE 
 b'ARB-ERR: Arbiter error cause (OVF/WD/LBW-ERR)'
*/
typedef struct reg_arb_err_cause {
	union {
		struct {
			uint32_t choice_ovf : 1,
				choice_wdt : 1,
				axi_lbw_err : 1,
				_reserved3 : 29;
		};
		uint32_t _raw;
	};
} reg_arb_err_cause;
static_assert((sizeof(struct reg_arb_err_cause) == 4), "reg_arb_err_cause size is not 32-bit");
/*
 ARB_ERR_MSG_EN 
 b'ARB-ERR: Message enable (Bit for each error)'
*/
typedef struct reg_arb_err_msg_en {
	union {
		struct {
			uint32_t choice_ovf : 1,
				choice_wdt : 1,
				axi_lbw_err : 1,
				_reserved3 : 29;
		};
		uint32_t _raw;
	};
} reg_arb_err_msg_en;
static_assert((sizeof(struct reg_arb_err_msg_en) == 4), "reg_arb_err_msg_en size is not 32-bit");
/*
 ARB_ERR_STS_DRP 
 b'ARB-ERR: CP number that got error'
*/
typedef struct reg_arb_err_sts_drp {
	union {
		struct {
			uint32_t val : 2,
				_reserved2 : 30;
		};
		uint32_t _raw;
	};
} reg_arb_err_sts_drp;
static_assert((sizeof(struct reg_arb_err_sts_drp) == 4), "reg_arb_err_sts_drp size is not 32-bit");
/*
 ARB_MST_CRED_STS 
 b'ARB-MST: Credits per slave [31:0]'
*/
typedef struct reg_arb_mst_cred_sts {
	union {
		struct {
			uint32_t val : 7,
				_reserved24 : 17,
				idx : 5,
				_reserved29 : 3;
		};
		uint32_t _raw;
	};
} reg_arb_mst_cred_sts;
static_assert((sizeof(struct reg_arb_mst_cred_sts) == 4), "reg_arb_mst_cred_sts size is not 32-bit");
/*
 ARB_MST_CRED_STS_1 
 b'ARB-MST: Credits per slave [63:32]'
*/
typedef struct reg_arb_mst_cred_sts_1 {
	union {
		struct {
			uint32_t val : 7,
				_reserved24 : 17,
				idx : 5,
				_reserved29 : 3;
		};
		uint32_t _raw;
	};
} reg_arb_mst_cred_sts_1;
static_assert((sizeof(struct reg_arb_mst_cred_sts_1) == 4), "reg_arb_mst_cred_sts_1 size is not 32-bit");
/*
 CSMR_STRICT_PRIO_CFG 
 b'ARB: Arbitration type (RR-0/Strict-1) ,Each CMD/8B'
*/
typedef struct reg_csmr_strict_prio_cfg {
	union {
		struct {
			uint32_t arb_type : 1,
				_reserved4 : 3,
				per_entry : 1,
				_reserved5 : 27;
		};
		uint32_t _raw;
	};
} reg_csmr_strict_prio_cfg;
static_assert((sizeof(struct reg_csmr_strict_prio_cfg) == 4), "reg_csmr_strict_prio_cfg size is not 32-bit");
/*
 ARC_CQ_CFG0 
 b'ARCCQF-CFG: B2B Enable / MSG-Enable'
*/
typedef struct reg_arc_cq_cfg0 {
	union {
		struct {
			uint32_t if_b2b_en : 1,
				if_msg_en : 1,
				ctl_msg_en : 1,
				_reserved3 : 29;
		};
		uint32_t _raw;
	};
} reg_arc_cq_cfg0;
static_assert((sizeof(struct reg_arc_cq_cfg0) == 4), "reg_arc_cq_cfg0 size is not 32-bit");
/*
 ARC_CQ_CFG1 
 b'ARCCQF-CFG: Buffer & Inflight limit'
*/
typedef struct reg_arc_cq_cfg1 {
	union {
		struct {
			uint32_t credit_lim : 8,
				_reserved16 : 8,
				max_inflight : 8,
				_reserved24 : 8;
		};
		uint32_t _raw;
	};
} reg_arc_cq_cfg1;
static_assert((sizeof(struct reg_arc_cq_cfg1) == 4), "reg_arc_cq_cfg1 size is not 32-bit");
/*
 ARC_CQ_PTR_LO 
 b'ARCCQF(Upper): Pointer (LSB)'
*/
typedef struct reg_arc_cq_ptr_lo {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_arc_cq_ptr_lo;
static_assert((sizeof(struct reg_arc_cq_ptr_lo) == 4), "reg_arc_cq_ptr_lo size is not 32-bit");
/*
 ARC_CQ_PTR_HI 
 b'ARCCQF(Upper): Pointer (MSB)'
*/
typedef struct reg_arc_cq_ptr_hi {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_arc_cq_ptr_hi;
static_assert((sizeof(struct reg_arc_cq_ptr_hi) == 4), "reg_arc_cq_ptr_hi size is not 32-bit");
/*
 ARC_CQ_TSIZE 
 b'ARC-CQF(Lower): Size in bytes'
*/
typedef struct reg_arc_cq_tsize {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_arc_cq_tsize;
static_assert((sizeof(struct reg_arc_cq_tsize) == 4), "reg_arc_cq_tsize size is not 32-bit");
/*
 ARC_CQ_CTL 
 b'ARC-CQF(Lower): Control (WR initiate CQ read)'
*/
typedef struct reg_arc_cq_ctl {
	union {
		struct {
			uint32_t _reserved28 : 28,
up : 4;
		};
		uint32_t _raw;
	};
} reg_arc_cq_ctl;
static_assert((sizeof(struct reg_arc_cq_ctl) == 4), "reg_arc_cq_ctl size is not 32-bit");
/*
 ARC_CQ_IFIFO_STS 
 b'ARC-CQ-STS: Input FIFO (Occupancy/Ready-Busy)'
*/
typedef struct reg_arc_cq_ififo_sts {
	union {
		struct {
			uint32_t cnt : 3,
				_reserved4 : 1,
				rdy : 1,
				_reserved8 : 3,
				ctl_stall : 1,
				_reserved9 : 23;
		};
		uint32_t _raw;
	};
} reg_arc_cq_ififo_sts;
static_assert((sizeof(struct reg_arc_cq_ififo_sts) == 4), "reg_arc_cq_ififo_sts size is not 32-bit");
/*
 ARC_CQ_STS0 
 b'ARC-CQ-STS: Credit/Free/Inflight co'
*/
typedef struct reg_arc_cq_sts0 {
	union {
		struct {
			uint32_t credit_cnt : 8,
				free_cnt : 8,
				inflight_cnt : 8,
				_reserved24 : 8;
		};
		uint32_t _raw;
	};
} reg_arc_cq_sts0;
static_assert((sizeof(struct reg_arc_cq_sts0) == 4), "reg_arc_cq_sts0 size is not 32-bit");
/*
 ARC_CQ_STS1 
 b'ARC-CQ-STS: Bus-empty/Busy'
*/
typedef struct reg_arc_cq_sts1 {
	union {
		struct {
			uint32_t buf_empty : 1,
				busy : 1,
				_reserved2 : 30;
		};
		uint32_t _raw;
	};
} reg_arc_cq_sts1;
static_assert((sizeof(struct reg_arc_cq_sts1) == 4), "reg_arc_cq_sts1 size is not 32-bit");
/*
 ARC_CQ_TSIZE_STS 
 b'ARC-CQ-STS: Current transfer size in bytes'
*/
typedef struct reg_arc_cq_tsize_sts {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_arc_cq_tsize_sts;
static_assert((sizeof(struct reg_arc_cq_tsize_sts) == 4), "reg_arc_cq_tsize_sts size is not 32-bit");
/*
 ARC_CQ_PTR_LO_STS 
 b'ARC-CQ-STS: Current Transfer base address byte 3-0'
*/
typedef struct reg_arc_cq_ptr_lo_sts {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_arc_cq_ptr_lo_sts;
static_assert((sizeof(struct reg_arc_cq_ptr_lo_sts) == 4), "reg_arc_cq_ptr_lo_sts size is not 32-bit");
/*
 ARC_CQ_PTR_HI_STS 
 b'ARC-CQ-STS: Current Transfer base address byte 4-7'
*/
typedef struct reg_arc_cq_ptr_hi_sts {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_arc_cq_ptr_hi_sts;
static_assert((sizeof(struct reg_arc_cq_ptr_hi_sts) == 4), "reg_arc_cq_ptr_hi_sts size is not 32-bit");
/*
 CP_WR_ARC_ADDR_HI 
 b'CP: WR_ARC_ADDRESS  (MSB)'
*/
typedef struct reg_cp_wr_arc_addr_hi {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_cp_wr_arc_addr_hi;
static_assert((sizeof(struct reg_cp_wr_arc_addr_hi) == 4), "reg_cp_wr_arc_addr_hi size is not 32-bit");
/*
 CP_WR_ARC_ADDR_LO 
 b'CP: WR_ARC_ADDRESS  (LSB)'
*/
typedef struct reg_cp_wr_arc_addr_lo {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_cp_wr_arc_addr_lo;
static_assert((sizeof(struct reg_cp_wr_arc_addr_lo) == 4), "reg_cp_wr_arc_addr_lo size is not 32-bit");
/*
 ARC_CQ_IFIFO_MSG_BASE_HI 
 b'ARC-CQ: ARC-CQ-IFIFO Shadow CI ADDR (Byte 7-4)'
*/
typedef struct reg_arc_cq_ififo_msg_base_hi {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_arc_cq_ififo_msg_base_hi;
static_assert((sizeof(struct reg_arc_cq_ififo_msg_base_hi) == 4), "reg_arc_cq_ififo_msg_base_hi size is not 32-bit");
/*
 ARC_CQ_IFIFO_MSG_BASE_LO 
 b'ARC-CQ: ARC-CQ-IFIFO Shadow CI ADDR (Byte 3-0)'
*/
typedef struct reg_arc_cq_ififo_msg_base_lo {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_arc_cq_ififo_msg_base_lo;
static_assert((sizeof(struct reg_arc_cq_ififo_msg_base_lo) == 4), "reg_arc_cq_ififo_msg_base_lo size is not 32-bit");
/*
 ARC_CQ_CTL_MSG_BASE_HI 
 b'ARC-CQ: CTL shadow CI address Byte 7-4'
*/
typedef struct reg_arc_cq_ctl_msg_base_hi {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_arc_cq_ctl_msg_base_hi;
static_assert((sizeof(struct reg_arc_cq_ctl_msg_base_hi) == 4), "reg_arc_cq_ctl_msg_base_hi size is not 32-bit");
/*
 ARC_CQ_CTL_MSG_BASE_LO 
 b'ARC CQ CTL shadow CI address Byte 3-0'
*/
typedef struct reg_arc_cq_ctl_msg_base_lo {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_arc_cq_ctl_msg_base_lo;
static_assert((sizeof(struct reg_arc_cq_ctl_msg_base_lo) == 4), "reg_arc_cq_ctl_msg_base_lo size is not 32-bit");
/*
 CQ_IFIFO_MSG_BASE_HI 
 b'CQ: CQ-IFIFO Shadow CI ADDR (Byte 7-4)'
*/
typedef struct reg_cq_ififo_msg_base_hi {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_cq_ififo_msg_base_hi;
static_assert((sizeof(struct reg_cq_ififo_msg_base_hi) == 4), "reg_cq_ififo_msg_base_hi size is not 32-bit");
/*
 CQ_IFIFO_MSG_BASE_LO 
 b'CQ: CQ-IFIFO Shadow CI ADDR (Byte 3-0)'
*/
typedef struct reg_cq_ififo_msg_base_lo {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_cq_ififo_msg_base_lo;
static_assert((sizeof(struct reg_cq_ififo_msg_base_lo) == 4), "reg_cq_ififo_msg_base_lo size is not 32-bit");
/*
 CQ_CTL_MSG_BASE_HI 
 b'CQ CTL shadow CI address Byte 7-4.'
*/
typedef struct reg_cq_ctl_msg_base_hi {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_cq_ctl_msg_base_hi;
static_assert((sizeof(struct reg_cq_ctl_msg_base_hi) == 4), "reg_cq_ctl_msg_base_hi size is not 32-bit");
/*
 CQ_CTL_MSG_BASE_LO 
 b'CQ CTL shadow CI address Byte 3-0'
*/
typedef struct reg_cq_ctl_msg_base_lo {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_cq_ctl_msg_base_lo;
static_assert((sizeof(struct reg_cq_ctl_msg_base_lo) == 4), "reg_cq_ctl_msg_base_lo size is not 32-bit");
/*
 ADDR_OVRD 
 b'QMAN-OVRIDE:ADDR[31:16] X-Y based / CFG-REG-OVRIDE'
*/
typedef struct reg_addr_ovrd {
	union {
		struct {
			uint32_t idx : 8,
				_reserved8 : 24;
		};
		uint32_t _raw;
	};
} reg_addr_ovrd;
static_assert((sizeof(struct reg_addr_ovrd) == 4), "reg_addr_ovrd size is not 32-bit");
/*
 CQ_IFIFO_CI 
 b'CQ: IFIFO CI per CQ [5xCopies] (Shadow)'
*/
typedef struct reg_cq_ififo_ci {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_cq_ififo_ci;
static_assert((sizeof(struct reg_cq_ififo_ci) == 4), "reg_cq_ififo_ci size is not 32-bit");
/*
 ARC_CQ_IFIFO_CI 
 b'ARC-CQ: IFIFO CI per ARC-CQ [5xCopies] (Shadow)'
*/
typedef struct reg_arc_cq_ififo_ci {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_arc_cq_ififo_ci;
static_assert((sizeof(struct reg_arc_cq_ififo_ci) == 4), "reg_arc_cq_ififo_ci size is not 32-bit");
/*
 CQ_CTL_CI 
 b'CQ: CQ CTL CI per CQ [5xcopies] (Shadow)'
*/
typedef struct reg_cq_ctl_ci {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_cq_ctl_ci;
static_assert((sizeof(struct reg_cq_ctl_ci) == 4), "reg_cq_ctl_ci size is not 32-bit");
/*
 ARC_CQ_CTL_CI 
 b'ARC-CQ: ARC-CQ CTL CI per CQ [5xcopies] (Shadow)'
*/
typedef struct reg_arc_cq_ctl_ci {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_arc_cq_ctl_ci;
static_assert((sizeof(struct reg_arc_cq_ctl_ci) == 4), "reg_arc_cq_ctl_ci size is not 32-bit");
/*
 CP_CFG 
 b'CP-SWITCH: Configuration (Enable Switch & its WD)'
*/
typedef struct reg_cp_cfg {
	union {
		struct {
			uint32_t switch_en : 1,
				switch_wd_en : 1,
				_reserved2 : 30;
		};
		uint32_t _raw;
	};
} reg_cp_cfg;
static_assert((sizeof(struct reg_cp_cfg) == 4), "reg_cp_cfg size is not 32-bit");
/*
 CP_EXT_SWITCH 
 b'CP-SWITCH-WD: Over-write switch (CQ/ARCCQ) state'
*/
typedef struct reg_cp_ext_switch {
	union {
		struct {
			uint32_t val : 1,
				_reserved1 : 31;
		};
		uint32_t _raw;
	};
} reg_cp_ext_switch;
static_assert((sizeof(struct reg_cp_ext_switch) == 4), "reg_cp_ext_switch size is not 32-bit");
/*
 CP_SWITCH_WD_SET 
 b'CP-SWITCH-WD: Set switch WD counter value'
*/
typedef struct reg_cp_switch_wd_set {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_cp_switch_wd_set;
static_assert((sizeof(struct reg_cp_switch_wd_set) == 4), "reg_cp_switch_wd_set size is not 32-bit");
/*
 CP_SWITCH_WD 
 b'CP-SWITCH-WD: Set switch WD target value'
*/
typedef struct reg_cp_switch_wd {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_cp_switch_wd;
static_assert((sizeof(struct reg_cp_switch_wd) == 4), "reg_cp_switch_wd size is not 32-bit");
/*
 ARC_LB_ADDR_BASE_LO 
 b'QMAN-ADDR: QMAN-LBW base address (LSB)'
*/
typedef struct reg_arc_lb_addr_base_lo {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_arc_lb_addr_base_lo;
static_assert((sizeof(struct reg_arc_lb_addr_base_lo) == 4), "reg_arc_lb_addr_base_lo size is not 32-bit");
/*
 ARC_LB_ADDR_BASE_HI 
 b'QMAN-ADDR: QMAN-LBW base address (MSB)'
*/
typedef struct reg_arc_lb_addr_base_hi {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_arc_lb_addr_base_hi;
static_assert((sizeof(struct reg_arc_lb_addr_base_hi) == 4), "reg_arc_lb_addr_base_hi size is not 32-bit");
/*
 ENGINE_BASE_ADDR_HI 
 b'QMAN-ADDR: QMAN-ENGINE BASE_ADDR (MSB)'
*/
typedef struct reg_engine_base_addr_hi {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_engine_base_addr_hi;
static_assert((sizeof(struct reg_engine_base_addr_hi) == 4), "reg_engine_base_addr_hi size is not 32-bit");
/*
 ENGINE_BASE_ADDR_LO 
 b'QMAN-ADDR: QMAN-ENGINE BASE_ADDR (MSB)'
*/
typedef struct reg_engine_base_addr_lo {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_engine_base_addr_lo;
static_assert((sizeof(struct reg_engine_base_addr_lo) == 4), "reg_engine_base_addr_lo size is not 32-bit");
/*
 ENGINE_ADDR_RANGE_SIZE 
 b'QMAN-ADDR: QMAN-ENGINE Address size'
*/
typedef struct reg_engine_addr_range_size {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_engine_addr_range_size;
static_assert((sizeof(struct reg_engine_addr_range_size) == 4), "reg_engine_addr_range_size size is not 32-bit");
/*
 QM_ARC_AUX_BASE_ADDR_HI 
 b'QMAN-ADDR: QMAN-ARC-AUX BASE_ADDR (MSB)'
*/
typedef struct reg_qm_arc_aux_base_addr_hi {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_qm_arc_aux_base_addr_hi;
static_assert((sizeof(struct reg_qm_arc_aux_base_addr_hi) == 4), "reg_qm_arc_aux_base_addr_hi size is not 32-bit");
/*
 QM_ARC_AUX_BASE_ADDR_LO 
 b'QMAN-ADDR: QMAN-ARC-AUX BASE_ADDR (LSB)'
*/
typedef struct reg_qm_arc_aux_base_addr_lo {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_qm_arc_aux_base_addr_lo;
static_assert((sizeof(struct reg_qm_arc_aux_base_addr_lo) == 4), "reg_qm_arc_aux_base_addr_lo size is not 32-bit");
/*
 QM_BASE_ADDR_HI 
 b'QMAN-ADDR: QMAN-CFG BASE_ADDR (MSB)'
*/
typedef struct reg_qm_base_addr_hi {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_qm_base_addr_hi;
static_assert((sizeof(struct reg_qm_base_addr_hi) == 4), "reg_qm_base_addr_hi size is not 32-bit");
/*
 QM_BASE_ADDR_LO 
 b'QMAN-ADDR: QMAN-CFG BASE_ADDR (LSB)'
*/
typedef struct reg_qm_base_addr_lo {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_qm_base_addr_lo;
static_assert((sizeof(struct reg_qm_base_addr_lo) == 4), "reg_qm_base_addr_lo size is not 32-bit");
/*
 ARC_PQC_SECURE_PUSH_IND 
 b'PQ-CQ:ARC/UCP indication to pass completion to LCQ'
*/
typedef struct reg_arc_pqc_secure_push_ind {
	union {
		struct {
			uint32_t cp_num : 2,
				_reserved2 : 30;
		};
		uint32_t _raw;
	};
} reg_arc_pqc_secure_push_ind;
static_assert((sizeof(struct reg_arc_pqc_secure_push_ind) == 4), "reg_arc_pqc_secure_push_ind size is not 32-bit");
/*
 PQC_STS_0 
 b'PQ-CQ: Completion Q status'
*/
typedef struct reg_pqc_sts_0 {
	union {
		struct {
			uint32_t comp_data : 16,
				comp_ofst : 16;
		};
		uint32_t _raw;
	};
} reg_pqc_sts_0;
static_assert((sizeof(struct reg_pqc_sts_0) == 4), "reg_pqc_sts_0 size is not 32-bit");
/*
 PQC_STS_1 
 b'PQ-CQ: Completion Q status (cont..)'
*/
typedef struct reg_pqc_sts_1 {
	union {
		struct {
			uint32_t comp_fifo_cntr : 4,
				comp_fifo_empty : 1,
				comp_fifo_full : 1,
				_reserved6 : 26;
		};
		uint32_t _raw;
	};
} reg_pqc_sts_1;
static_assert((sizeof(struct reg_pqc_sts_1) == 4), "reg_pqc_sts_1 size is not 32-bit");
/*
 SEI_STATUS 
 b'EXCEPTIONS: SEI cause (System Error Interrupts)'
*/
typedef struct reg_sei_status {
	union {
		struct {
			uint32_t qm_int : 1,
				arc_int : 1,
				_reserved2 : 30;
		};
		uint32_t _raw;
	};
} reg_sei_status;
static_assert((sizeof(struct reg_sei_status) == 4), "reg_sei_status size is not 32-bit");
/*
 SEI_MASK 
 b'EXCEPTIONS: SEI mask (System Error Interrupts)'
*/
typedef struct reg_sei_mask {
	union {
		struct {
			uint32_t qm_int : 1,
				arc_int : 1,
				_reserved2 : 30;
		};
		uint32_t _raw;
	};
} reg_sei_mask;
static_assert((sizeof(struct reg_sei_mask) == 4), "reg_sei_mask size is not 32-bit");
/*
 GLBL_ERR_ADDR_LO 
 b'GLOBAL-ERR: Global Error ADDRESS LSB (0..3)'
*/
typedef struct reg_glbl_err_addr_lo {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_glbl_err_addr_lo;
static_assert((sizeof(struct reg_glbl_err_addr_lo) == 4), "reg_glbl_err_addr_lo size is not 32-bit");
/*
 GLBL_ERR_ADDR_HI 
 b'GLOBAL-ERR: Global Error ADDRESS MSB (4..7)'
*/
typedef struct reg_glbl_err_addr_hi {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_glbl_err_addr_hi;
static_assert((sizeof(struct reg_glbl_err_addr_hi) == 4), "reg_glbl_err_addr_hi size is not 32-bit");
/*
 GLBL_ERR_WDATA 
 b'GLOBAL-ERR: Global Error DATA to send (LBW)'
*/
typedef struct reg_glbl_err_wdata {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_glbl_err_wdata;
static_assert((sizeof(struct reg_glbl_err_wdata) == 4), "reg_glbl_err_wdata size is not 32-bit");
/*
 L2H_MASK_LO 
 b'L2H:Addr mask (LSB) to select HBW over LBW'
*/
typedef struct reg_l2h_mask_lo {
	union {
		struct {
			uint32_t _reserved20 : 20,
val : 12;
		};
		uint32_t _raw;
	};
} reg_l2h_mask_lo;
static_assert((sizeof(struct reg_l2h_mask_lo) == 4), "reg_l2h_mask_lo size is not 32-bit");
/*
 L2H_MASK_HI 
 b'L2H:Addr mask (MSB) to select HBW over LBW'
*/
typedef struct reg_l2h_mask_hi {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_l2h_mask_hi;
static_assert((sizeof(struct reg_l2h_mask_hi) == 4), "reg_l2h_mask_hi size is not 32-bit");
/*
 L2H_CMPR_LO 
 b'L2H:Addr compare (LSB) to select HBW over LBW'
*/
typedef struct reg_l2h_cmpr_lo {
	union {
		struct {
			uint32_t _reserved20 : 20,
val : 12;
		};
		uint32_t _raw;
	};
} reg_l2h_cmpr_lo;
static_assert((sizeof(struct reg_l2h_cmpr_lo) == 4), "reg_l2h_cmpr_lo size is not 32-bit");
/*
 L2H_CMPR_HI 
 b'L2H:Addr compare (MSB) to select HBW over LBW'
*/
typedef struct reg_l2h_cmpr_hi {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_l2h_cmpr_hi;
static_assert((sizeof(struct reg_l2h_cmpr_hi) == 4), "reg_l2h_cmpr_hi size is not 32-bit");
/*
 LOCAL_RANGE_BASE 
 b'LCL:QMAN location relative to 64KB 0xA000 Int. use'
*/
typedef struct reg_local_range_base {
	union {
		struct {
			uint32_t val : 16,
				_reserved16 : 16;
		};
		uint32_t _raw;
	};
} reg_local_range_base;
static_assert((sizeof(struct reg_local_range_base) == 4), "reg_local_range_base size is not 32-bit");
/*
 LOCAL_RANGE_SIZE 
 b'LCL: Size of QMAN ADDR space 0x1000  (Int. use)'
*/
typedef struct reg_local_range_size {
	union {
		struct {
			uint32_t val : 16,
				_reserved16 : 16;
		};
		uint32_t _raw;
	};
} reg_local_range_size;
static_assert((sizeof(struct reg_local_range_size) == 4), "reg_local_range_size size is not 32-bit");
/*
 HBW_RD_RATE_LIM_CFG_1 
 b'RATE-LIMIT: QMAN rate limiter CFG0 (HBW port)'
*/
typedef struct reg_hbw_rd_rate_lim_cfg_1 {
	union {
		struct {
			uint32_t tout : 8,
				_reserved31 : 23,
				en : 1;
		};
		uint32_t _raw;
	};
} reg_hbw_rd_rate_lim_cfg_1;
static_assert((sizeof(struct reg_hbw_rd_rate_lim_cfg_1) == 4), "reg_hbw_rd_rate_lim_cfg_1 size is not 32-bit");
/*
 LBW_WR_RATE_LIM_CFG_0 
 b'RATE-LIMIT: QMAN rate limiter CFG0 (LBW port)'
*/
typedef struct reg_lbw_wr_rate_lim_cfg_0 {
	union {
		struct {
			uint32_t rst_token : 8,
				_reserved16 : 8,
				sat : 8,
				_reserved24 : 8;
		};
		uint32_t _raw;
	};
} reg_lbw_wr_rate_lim_cfg_0;
static_assert((sizeof(struct reg_lbw_wr_rate_lim_cfg_0) == 4), "reg_lbw_wr_rate_lim_cfg_0 size is not 32-bit");
/*
 LBW_WR_RATE_LIM_CFG_1 
 b'RATE-LIMIT: QMAN rate limiter CFG1 (LBW port)'
*/
typedef struct reg_lbw_wr_rate_lim_cfg_1 {
	union {
		struct {
			uint32_t tout : 8,
				_reserved31 : 23,
				en : 1;
		};
		uint32_t _raw;
	};
} reg_lbw_wr_rate_lim_cfg_1;
static_assert((sizeof(struct reg_lbw_wr_rate_lim_cfg_1) == 4), "reg_lbw_wr_rate_lim_cfg_1 size is not 32-bit");
/*
 HBW_RD_RATE_LIM_CFG_0 
 b'RATE-LIMIT: QMAN rate limiter CFG1 (HBW port)'
*/
typedef struct reg_hbw_rd_rate_lim_cfg_0 {
	union {
		struct {
			uint32_t rst_token : 8,
				_reserved16 : 8,
				sat : 8,
				_reserved24 : 8;
		};
		uint32_t _raw;
	};
} reg_hbw_rd_rate_lim_cfg_0;
static_assert((sizeof(struct reg_hbw_rd_rate_lim_cfg_0) == 4), "reg_hbw_rd_rate_lim_cfg_0 size is not 32-bit");
/*
 IND_GW_APB_CFG 
 b'QMAN-MEM-IND-ACC: Set ADDR for QMAN memory access'
*/
typedef struct reg_ind_gw_apb_cfg {
	union {
		struct {
			uint32_t addr : 31,
				cmd : 1;
		};
		uint32_t _raw;
	};
} reg_ind_gw_apb_cfg;
static_assert((sizeof(struct reg_ind_gw_apb_cfg) == 4), "reg_ind_gw_apb_cfg size is not 32-bit");
/*
 IND_GW_APB_WDATA 
 b'QMAN-MEM-IND-ACC: Data to write'
*/
typedef struct reg_ind_gw_apb_wdata {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_ind_gw_apb_wdata;
static_assert((sizeof(struct reg_ind_gw_apb_wdata) == 4), "reg_ind_gw_apb_wdata size is not 32-bit");
/*
 IND_GW_APB_RDATA 
 b'QMAN-MEM-IND-ACC: Data readf'
*/
typedef struct reg_ind_gw_apb_rdata {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_ind_gw_apb_rdata;
static_assert((sizeof(struct reg_ind_gw_apb_rdata) == 4), "reg_ind_gw_apb_rdata size is not 32-bit");
/*
 IND_GW_APB_STATUS 
 b'QMAN-MEM-IND-ACC: Status & Ready'
*/
typedef struct reg_ind_gw_apb_status {
	union {
		struct {
			uint32_t rdy : 1,
				err : 1,
				_reserved2 : 30;
		};
		uint32_t _raw;
	};
} reg_ind_gw_apb_status;
static_assert((sizeof(struct reg_ind_gw_apb_status) == 4), "reg_ind_gw_apb_status size is not 32-bit");
/*
 PERF_CNT_FREE_LO 
 b'PERF-CNT: Free-Run counter (LSB)'
*/
typedef struct reg_perf_cnt_free_lo {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_perf_cnt_free_lo;
static_assert((sizeof(struct reg_perf_cnt_free_lo) == 4), "reg_perf_cnt_free_lo size is not 32-bit");
/*
 PERF_CNT_FREE_HI 
 b'PERF-CNT: Free-Run counter (MSB)'
*/
typedef struct reg_perf_cnt_free_hi {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_perf_cnt_free_hi;
static_assert((sizeof(struct reg_perf_cnt_free_hi) == 4), "reg_perf_cnt_free_hi size is not 32-bit");
/*
 PERF_CNT_IDLE_LO 
 b'PERF-CNT: Idle cycles counter for monitoring (LSB)'
*/
typedef struct reg_perf_cnt_idle_lo {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_perf_cnt_idle_lo;
static_assert((sizeof(struct reg_perf_cnt_idle_lo) == 4), "reg_perf_cnt_idle_lo size is not 32-bit");
/*
 PERF_CNT_IDLE_HI 
 b'PERF-CNT: Idle cycles counter for monitoring (MSB)'
*/
typedef struct reg_perf_cnt_idle_hi {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_perf_cnt_idle_hi;
static_assert((sizeof(struct reg_perf_cnt_idle_hi) == 4), "reg_perf_cnt_idle_hi size is not 32-bit");
/*
 PERF_CNT_CFG 
 b'PERF-CNT: Enable / Set IDLE mask'
*/
typedef struct reg_perf_cnt_cfg {
	union {
		struct {
			uint32_t pq_mask : 4,
				_reserved8 : 4,
				cq_mask : 5,
				_reserved16 : 3,
				cp_mask : 5,
				_reserved24 : 3,
				agent_mask : 1,
				_reserved30 : 5,
				en_free : 1,
				en_idle : 1;
		};
		uint32_t _raw;
	};
} reg_perf_cnt_cfg;
static_assert((sizeof(struct reg_perf_cnt_cfg) == 4), "reg_perf_cnt_cfg size is not 32-bit");

#ifdef __cplusplus
} /* qman namespace */
#endif

/*
 QMAN block
*/

#ifdef __cplusplus

struct block_qman {
	struct qman::reg_glbl_cfg0 glbl_cfg0;
	struct qman::reg_glbl_cfg1 glbl_cfg1;
	struct qman::reg_glbl_cfg2 glbl_cfg2;
	struct qman::reg_glbl_err_cfg glbl_err_cfg;
	struct qman::reg_glbl_err_cfg1 glbl_err_cfg1;
	struct qman::reg_glbl_err_arc_halt_en glbl_err_arc_halt_en;
	struct qman::reg_glbl_axcache glbl_axcache;
	struct qman::reg_glbl_sts0 glbl_sts0;
	struct qman::reg_glbl_sts1 glbl_sts1;
	struct qman::reg_glbl_err_sts glbl_err_sts[4];
	struct qman::reg_glbl_err_sts_4 glbl_err_sts_4;
	struct qman::reg_glbl_err_msg_en glbl_err_msg_en[4];
	struct qman::reg_glbl_err_msg_en_4 glbl_err_msg_en_4;
	struct qman::reg_glbl_prot glbl_prot;
	struct qman::reg_pq_base_lo pq_base_lo[4];
	struct qman::reg_pq_base_hi pq_base_hi[4];
	struct qman::reg_pq_size pq_size[4];
	struct qman::reg_pq_pi pq_pi[4];
	struct qman::reg_pq_ci pq_ci[4];
	struct qman::reg_pq_cfg0 pq_cfg0[4];
	struct qman::reg_pq_cfg1 pq_cfg1[4];
	struct qman::reg_pq_sts0 pq_sts0[4];
	struct qman::reg_pq_sts1 pq_sts1[4];
	struct qman::reg_cq_cfg0 cq_cfg0[5];
	struct qman::reg_cq_sts0 cq_sts0[5];
	struct qman::reg_cq_cfg1 cq_cfg1[5];
	struct qman::reg_cq_sts1 cq_sts1[5];
	uint32_t _pad304[8];
	struct qman::reg_cq_ptr_lo_0 cq_ptr_lo_0;
	struct qman::reg_cq_ptr_hi_0 cq_ptr_hi_0;
	struct qman::reg_cq_tsize_0 cq_tsize_0;
	struct qman::reg_cq_ctl_0 cq_ctl_0;
	struct qman::reg_cq_ptr_lo_1 cq_ptr_lo_1;
	struct qman::reg_cq_ptr_hi_1 cq_ptr_hi_1;
	struct qman::reg_cq_tsize_1 cq_tsize_1;
	struct qman::reg_cq_ctl_1 cq_ctl_1;
	struct qman::reg_cq_ptr_lo_2 cq_ptr_lo_2;
	struct qman::reg_cq_ptr_hi_2 cq_ptr_hi_2;
	struct qman::reg_cq_tsize_2 cq_tsize_2;
	struct qman::reg_cq_ctl_2 cq_ctl_2;
	struct qman::reg_cq_ptr_lo_3 cq_ptr_lo_3;
	struct qman::reg_cq_ptr_hi_3 cq_ptr_hi_3;
	struct qman::reg_cq_tsize_3 cq_tsize_3;
	struct qman::reg_cq_ctl_3 cq_ctl_3;
	struct qman::reg_cq_ptr_lo_4 cq_ptr_lo_4;
	struct qman::reg_cq_ptr_hi_4 cq_ptr_hi_4;
	struct qman::reg_cq_tsize_4 cq_tsize_4;
	struct qman::reg_cq_ctl_4 cq_ctl_4;
	struct qman::reg_cq_tsize_sts cq_tsize_sts[5];
	struct qman::reg_cq_ptr_lo_sts cq_ptr_lo_sts[5];
	struct qman::reg_cq_ptr_hi_sts cq_ptr_hi_sts[5];
	struct qman::reg_cq_ififo_sts cq_ififo_sts[5];
	struct qman::reg_cp_msg_base0_addr_lo cp_msg_base0_addr_lo[5];
	struct qman::reg_cp_msg_base0_addr_hi cp_msg_base0_addr_hi[5];
	struct qman::reg_cp_msg_base1_addr_lo cp_msg_base1_addr_lo[5];
	struct qman::reg_cp_msg_base1_addr_hi cp_msg_base1_addr_hi[5];
	struct qman::reg_cp_msg_base2_addr_lo cp_msg_base2_addr_lo[5];
	struct qman::reg_cp_msg_base2_addr_hi cp_msg_base2_addr_hi[5];
	struct qman::reg_cp_msg_base3_addr_lo cp_msg_base3_addr_lo[5];
	struct qman::reg_cp_msg_base3_addr_hi cp_msg_base3_addr_hi[5];
	struct qman::reg_cp_fence0_rdata cp_fence0_rdata[5];
	struct qman::reg_cp_fence1_rdata cp_fence1_rdata[5];
	struct qman::reg_cp_fence2_rdata cp_fence2_rdata[5];
	struct qman::reg_cp_fence3_rdata cp_fence3_rdata[5];
	struct qman::reg_cp_fence0_cnt cp_fence0_cnt[5];
	struct qman::reg_cp_fence1_cnt cp_fence1_cnt[5];
	struct qman::reg_cp_fence2_cnt cp_fence2_cnt[5];
	struct qman::reg_cp_fence3_cnt cp_fence3_cnt[5];
	struct qman::reg_cp_barrier_cfg cp_barrier_cfg;
	struct qman::reg_cp_ldma_src_base_lo_offset cp_ldma_src_base_lo_offset;
	struct qman::reg_cp_ldma_dst_base_lo_offset cp_ldma_dst_base_lo_offset;
	struct qman::reg_cp_ldma_tsize_offset cp_ldma_tsize_offset;
	struct qman::reg_cp_cq_ptr_lo_offset_0 cp_cq_ptr_lo_offset_0;
	struct qman::reg_cp_cq_ptr_lo_offset_1 cp_cq_ptr_lo_offset_1;
	struct qman::reg_cp_cq_ptr_lo_offset_2 cp_cq_ptr_lo_offset_2;
	struct qman::reg_cp_cq_ptr_lo_offset_3 cp_cq_ptr_lo_offset_3;
	struct qman::reg_cp_cq_ptr_lo_offset_4 cp_cq_ptr_lo_offset_4;
	uint32_t _pad852[5];
	struct qman::reg_cp_sts cp_sts[5];
	struct qman::reg_cp_current_inst_lo cp_current_inst_lo[5];
	struct qman::reg_cp_current_inst_hi cp_current_inst_hi[5];
	struct qman::reg_cp_pred cp_pred[5];
	struct qman::reg_cp_pred_upen cp_pred_upen[5];
	struct qman::reg_cp_dbg_0 cp_dbg_0[5];
	struct qman::reg_cp_cpdma_up_cred cp_cpdma_up_cred[5];
	struct qman::reg_cp_in_data_lo cp_in_data_lo[5];
	struct qman::reg_cp_in_data_hi cp_in_data_hi[5];
	struct qman::reg_pqc_hbw_base_lo pqc_hbw_base_lo[4];
	struct qman::reg_pqc_hbw_base_hi pqc_hbw_base_hi[4];
	struct qman::reg_pqc_size pqc_size[4];
	struct qman::reg_pqc_pi pqc_pi[4];
	struct qman::reg_pqc_lbw_wdata pqc_lbw_wdata[4];
	struct qman::reg_pqc_lbw_base_lo pqc_lbw_base_lo[4];
	struct qman::reg_pqc_lbw_base_hi pqc_lbw_base_hi[4];
	struct qman::reg_pqc_cfg pqc_cfg;
	struct qman::reg_pqc_secure_push_ind pqc_secure_push_ind;
	uint32_t _pad1172[3];
	struct qman::reg_arb_mask arb_mask;
	struct qman::reg_arb_cfg_0 arb_cfg_0;
	struct qman::reg_arb_choice_q_push arb_choice_q_push;
	struct qman::reg_arb_wrr_weight arb_wrr_weight[4];
	struct qman::reg_arb_cfg_1 arb_cfg_1;
	struct qman::reg_arb_mst_avail_cred arb_mst_avail_cred[64];
	uint32_t _pad1472[8];
	struct qman::reg_arb_mst_cred_inc arb_mst_cred_inc;
	struct qman::reg_arb_mst_choice_push_ofst arb_mst_choice_push_ofst[64];
	uint32_t _pad1764[8];
	struct qman::reg_arb_slv_master_inc_cred_ofst arb_slv_master_inc_cred_ofst;
	struct qman::reg_arb_mst_slave_en arb_mst_slave_en;
	struct qman::reg_arb_mst_slave_en_1 arb_mst_slave_en_1;
	struct qman::reg_arb_slv_choice_wdt arb_slv_choice_wdt;
	struct qman::reg_arb_slv_id arb_slv_id;
	struct qman::reg_arb_mst_quiet_per arb_mst_quiet_per;
	uint32_t _pad1820[10];
	struct qman::reg_arb_msg_max_inflight arb_msg_max_inflight;
	uint32_t _pad1864[3];
	struct qman::reg_arb_base_lo arb_base_lo;
	struct qman::reg_arb_base_hi arb_base_hi;
	uint32_t _pad1884[9];
	struct qman::reg_arb_state_sts arb_state_sts;
	struct qman::reg_arb_choice_fullness_sts arb_choice_fullness_sts;
	struct qman::reg_arb_msg_sts arb_msg_sts;
	struct qman::reg_arb_slv_choice_q_head arb_slv_choice_q_head;
	uint32_t _pad1936[3];
	struct qman::reg_arb_err_cause arb_err_cause;
	struct qman::reg_arb_err_msg_en arb_err_msg_en;
	uint32_t _pad1956[1];
	struct qman::reg_arb_err_sts_drp arb_err_sts_drp;
	uint32_t _pad1964[1];
	struct qman::reg_arb_mst_cred_sts arb_mst_cred_sts;
	struct qman::reg_arb_mst_cred_sts_1 arb_mst_cred_sts_1;
	uint32_t _pad1976[17];
	struct qman::reg_csmr_strict_prio_cfg csmr_strict_prio_cfg;
	struct qman::reg_arc_cq_cfg0 arc_cq_cfg0;
	struct qman::reg_arc_cq_cfg1 arc_cq_cfg1;
	struct qman::reg_arc_cq_ptr_lo arc_cq_ptr_lo;
	struct qman::reg_arc_cq_ptr_hi arc_cq_ptr_hi;
	struct qman::reg_arc_cq_tsize arc_cq_tsize;
	struct qman::reg_arc_cq_ctl arc_cq_ctl;
	uint32_t _pad2072[1];
	struct qman::reg_arc_cq_ififo_sts arc_cq_ififo_sts;
	struct qman::reg_arc_cq_sts0 arc_cq_sts0;
	struct qman::reg_arc_cq_sts1 arc_cq_sts1;
	struct qman::reg_arc_cq_tsize_sts arc_cq_tsize_sts;
	struct qman::reg_arc_cq_ptr_lo_sts arc_cq_ptr_lo_sts;
	struct qman::reg_arc_cq_ptr_hi_sts arc_cq_ptr_hi_sts;
	struct qman::reg_cp_wr_arc_addr_hi cp_wr_arc_addr_hi;
	struct qman::reg_cp_wr_arc_addr_lo cp_wr_arc_addr_lo;
	struct qman::reg_arc_cq_ififo_msg_base_hi arc_cq_ififo_msg_base_hi;
	struct qman::reg_arc_cq_ififo_msg_base_lo arc_cq_ififo_msg_base_lo;
	struct qman::reg_arc_cq_ctl_msg_base_hi arc_cq_ctl_msg_base_hi;
	struct qman::reg_arc_cq_ctl_msg_base_lo arc_cq_ctl_msg_base_lo;
	struct qman::reg_cq_ififo_msg_base_hi cq_ififo_msg_base_hi;
	struct qman::reg_cq_ififo_msg_base_lo cq_ififo_msg_base_lo;
	struct qman::reg_cq_ctl_msg_base_hi cq_ctl_msg_base_hi;
	struct qman::reg_cq_ctl_msg_base_lo cq_ctl_msg_base_lo;
	struct qman::reg_addr_ovrd addr_ovrd;
	struct qman::reg_cq_ififo_ci cq_ififo_ci[5];
	struct qman::reg_arc_cq_ififo_ci arc_cq_ififo_ci;
	struct qman::reg_cq_ctl_ci cq_ctl_ci[5];
	struct qman::reg_arc_cq_ctl_ci arc_cq_ctl_ci;
	struct qman::reg_cp_cfg cp_cfg;
	struct qman::reg_cp_ext_switch cp_ext_switch;
	struct qman::reg_cp_switch_wd_set cp_switch_wd_set;
	struct qman::reg_cp_switch_wd cp_switch_wd;
	uint32_t _pad2208[1];
	struct qman::reg_arc_lb_addr_base_lo arc_lb_addr_base_lo;
	struct qman::reg_arc_lb_addr_base_hi arc_lb_addr_base_hi;
	struct qman::reg_engine_base_addr_hi engine_base_addr_hi;
	struct qman::reg_engine_base_addr_lo engine_base_addr_lo;
	struct qman::reg_engine_addr_range_size engine_addr_range_size;
	struct qman::reg_qm_arc_aux_base_addr_hi qm_arc_aux_base_addr_hi;
	struct qman::reg_qm_arc_aux_base_addr_lo qm_arc_aux_base_addr_lo;
	struct qman::reg_qm_base_addr_hi qm_base_addr_hi;
	struct qman::reg_qm_base_addr_lo qm_base_addr_lo;
	struct qman::reg_arc_pqc_secure_push_ind arc_pqc_secure_push_ind;
	uint32_t _pad2252[1];
	struct qman::reg_pqc_sts_0 pqc_sts_0[4];
	struct qman::reg_pqc_sts_1 pqc_sts_1[4];
	struct qman::reg_sei_status sei_status;
	struct qman::reg_sei_mask sei_mask;
	uint32_t _pad2296[2];
	struct block_qman_wr64_base_addr qman_wr64_base_addr0;
	struct block_qman_wr64_base_addr qman_wr64_base_addr1;
	struct block_qman_wr64_base_addr qman_wr64_base_addr2;
	struct block_qman_wr64_base_addr qman_wr64_base_addr3;
	struct block_qman_wr64_base_addr qman_wr64_base_addr4;
	struct block_qman_wr64_base_addr qman_wr64_base_addr5;
	struct block_qman_wr64_base_addr qman_wr64_base_addr6;
	struct block_qman_wr64_base_addr qman_wr64_base_addr7;
	struct block_qman_wr64_base_addr qman_wr64_base_addr8;
	struct block_qman_wr64_base_addr qman_wr64_base_addr9;
	struct block_qman_wr64_base_addr qman_wr64_base_addr10;
	struct block_qman_wr64_base_addr qman_wr64_base_addr11;
	struct block_qman_wr64_base_addr qman_wr64_base_addr12;
	struct block_qman_wr64_base_addr qman_wr64_base_addr13;
	struct block_qman_wr64_base_addr qman_wr64_base_addr14;
	struct block_qman_wr64_base_addr qman_wr64_base_addr15;
	uint32_t _pad2432[96];
	struct block_axuser axuser_secured;
	uint32_t _pad2896[12];
	struct block_axuser axuser_nonsecured;
	uint32_t _pad3024[12];
	struct block_ic_lbw_dbg_cnt dbg_hbw;
	uint32_t _pad3160[10];
	struct block_ic_lbw_dbg_cnt dbg_lbw;
	uint32_t _pad3288[10];
	struct qman::reg_glbl_err_addr_lo glbl_err_addr_lo;
	struct qman::reg_glbl_err_addr_hi glbl_err_addr_hi;
	struct qman::reg_glbl_err_wdata glbl_err_wdata;
	uint32_t _pad3340[2];
	struct qman::reg_l2h_mask_lo l2h_mask_lo;
	struct qman::reg_l2h_mask_hi l2h_mask_hi;
	struct qman::reg_l2h_cmpr_lo l2h_cmpr_lo;
	struct qman::reg_l2h_cmpr_hi l2h_cmpr_hi;
	struct qman::reg_local_range_base local_range_base;
	struct qman::reg_local_range_size local_range_size;
	uint32_t _pad3372[1];
	struct qman::reg_hbw_rd_rate_lim_cfg_1 hbw_rd_rate_lim_cfg_1;
	struct qman::reg_lbw_wr_rate_lim_cfg_0 lbw_wr_rate_lim_cfg_0;
	struct qman::reg_lbw_wr_rate_lim_cfg_1 lbw_wr_rate_lim_cfg_1;
	struct qman::reg_hbw_rd_rate_lim_cfg_0 hbw_rd_rate_lim_cfg_0;
	struct qman::reg_ind_gw_apb_cfg ind_gw_apb_cfg;
	struct qman::reg_ind_gw_apb_wdata ind_gw_apb_wdata;
	struct qman::reg_ind_gw_apb_rdata ind_gw_apb_rdata;
	struct qman::reg_ind_gw_apb_status ind_gw_apb_status;
	uint32_t _pad3408[4];
	struct qman::reg_perf_cnt_free_lo perf_cnt_free_lo;
	struct qman::reg_perf_cnt_free_hi perf_cnt_free_hi;
	struct qman::reg_perf_cnt_idle_lo perf_cnt_idle_lo;
	struct qman::reg_perf_cnt_idle_hi perf_cnt_idle_hi;
	struct qman::reg_perf_cnt_cfg perf_cnt_cfg;
	uint32_t _pad3444[3];
	struct block_qman_cgm cgm;
	uint32_t _pad3468[61];
	struct block_special_regs special;
};
#else

typedef struct block_qman {
	reg_glbl_cfg0 glbl_cfg0;
	reg_glbl_cfg1 glbl_cfg1;
	reg_glbl_cfg2 glbl_cfg2;
	reg_glbl_err_cfg glbl_err_cfg;
	reg_glbl_err_cfg1 glbl_err_cfg1;
	reg_glbl_err_arc_halt_en glbl_err_arc_halt_en;
	reg_glbl_axcache glbl_axcache;
	reg_glbl_sts0 glbl_sts0;
	reg_glbl_sts1 glbl_sts1;
	reg_glbl_err_sts glbl_err_sts[4];
	reg_glbl_err_sts_4 glbl_err_sts_4;
	reg_glbl_err_msg_en glbl_err_msg_en[4];
	reg_glbl_err_msg_en_4 glbl_err_msg_en_4;
	reg_glbl_prot glbl_prot;
	reg_pq_base_lo pq_base_lo[4];
	reg_pq_base_hi pq_base_hi[4];
	reg_pq_size pq_size[4];
	reg_pq_pi pq_pi[4];
	reg_pq_ci pq_ci[4];
	reg_pq_cfg0 pq_cfg0[4];
	reg_pq_cfg1 pq_cfg1[4];
	reg_pq_sts0 pq_sts0[4];
	reg_pq_sts1 pq_sts1[4];
	reg_cq_cfg0 cq_cfg0[5];
	reg_cq_sts0 cq_sts0[5];
	reg_cq_cfg1 cq_cfg1[5];
	reg_cq_sts1 cq_sts1[5];
	uint32_t _pad304[8];
	reg_cq_ptr_lo_0 cq_ptr_lo_0;
	reg_cq_ptr_hi_0 cq_ptr_hi_0;
	reg_cq_tsize_0 cq_tsize_0;
	reg_cq_ctl_0 cq_ctl_0;
	reg_cq_ptr_lo_1 cq_ptr_lo_1;
	reg_cq_ptr_hi_1 cq_ptr_hi_1;
	reg_cq_tsize_1 cq_tsize_1;
	reg_cq_ctl_1 cq_ctl_1;
	reg_cq_ptr_lo_2 cq_ptr_lo_2;
	reg_cq_ptr_hi_2 cq_ptr_hi_2;
	reg_cq_tsize_2 cq_tsize_2;
	reg_cq_ctl_2 cq_ctl_2;
	reg_cq_ptr_lo_3 cq_ptr_lo_3;
	reg_cq_ptr_hi_3 cq_ptr_hi_3;
	reg_cq_tsize_3 cq_tsize_3;
	reg_cq_ctl_3 cq_ctl_3;
	reg_cq_ptr_lo_4 cq_ptr_lo_4;
	reg_cq_ptr_hi_4 cq_ptr_hi_4;
	reg_cq_tsize_4 cq_tsize_4;
	reg_cq_ctl_4 cq_ctl_4;
	reg_cq_tsize_sts cq_tsize_sts[5];
	reg_cq_ptr_lo_sts cq_ptr_lo_sts[5];
	reg_cq_ptr_hi_sts cq_ptr_hi_sts[5];
	reg_cq_ififo_sts cq_ififo_sts[5];
	reg_cp_msg_base0_addr_lo cp_msg_base0_addr_lo[5];
	reg_cp_msg_base0_addr_hi cp_msg_base0_addr_hi[5];
	reg_cp_msg_base1_addr_lo cp_msg_base1_addr_lo[5];
	reg_cp_msg_base1_addr_hi cp_msg_base1_addr_hi[5];
	reg_cp_msg_base2_addr_lo cp_msg_base2_addr_lo[5];
	reg_cp_msg_base2_addr_hi cp_msg_base2_addr_hi[5];
	reg_cp_msg_base3_addr_lo cp_msg_base3_addr_lo[5];
	reg_cp_msg_base3_addr_hi cp_msg_base3_addr_hi[5];
	reg_cp_fence0_rdata cp_fence0_rdata[5];
	reg_cp_fence1_rdata cp_fence1_rdata[5];
	reg_cp_fence2_rdata cp_fence2_rdata[5];
	reg_cp_fence3_rdata cp_fence3_rdata[5];
	reg_cp_fence0_cnt cp_fence0_cnt[5];
	reg_cp_fence1_cnt cp_fence1_cnt[5];
	reg_cp_fence2_cnt cp_fence2_cnt[5];
	reg_cp_fence3_cnt cp_fence3_cnt[5];
	reg_cp_barrier_cfg cp_barrier_cfg;
	reg_cp_ldma_src_base_lo_offset cp_ldma_src_base_lo_offset;
	reg_cp_ldma_dst_base_lo_offset cp_ldma_dst_base_lo_offset;
	reg_cp_ldma_tsize_offset cp_ldma_tsize_offset;
	reg_cp_cq_ptr_lo_offset_0 cp_cq_ptr_lo_offset_0;
	reg_cp_cq_ptr_lo_offset_1 cp_cq_ptr_lo_offset_1;
	reg_cp_cq_ptr_lo_offset_2 cp_cq_ptr_lo_offset_2;
	reg_cp_cq_ptr_lo_offset_3 cp_cq_ptr_lo_offset_3;
	reg_cp_cq_ptr_lo_offset_4 cp_cq_ptr_lo_offset_4;
	uint32_t _pad852[5];
	reg_cp_sts cp_sts[5];
	reg_cp_current_inst_lo cp_current_inst_lo[5];
	reg_cp_current_inst_hi cp_current_inst_hi[5];
	reg_cp_pred cp_pred[5];
	reg_cp_pred_upen cp_pred_upen[5];
	reg_cp_dbg_0 cp_dbg_0[5];
	reg_cp_cpdma_up_cred cp_cpdma_up_cred[5];
	reg_cp_in_data_lo cp_in_data_lo[5];
	reg_cp_in_data_hi cp_in_data_hi[5];
	reg_pqc_hbw_base_lo pqc_hbw_base_lo[4];
	reg_pqc_hbw_base_hi pqc_hbw_base_hi[4];
	reg_pqc_size pqc_size[4];
	reg_pqc_pi pqc_pi[4];
	reg_pqc_lbw_wdata pqc_lbw_wdata[4];
	reg_pqc_lbw_base_lo pqc_lbw_base_lo[4];
	reg_pqc_lbw_base_hi pqc_lbw_base_hi[4];
	reg_pqc_cfg pqc_cfg;
	reg_pqc_secure_push_ind pqc_secure_push_ind;
	uint32_t _pad1172[3];
	reg_arb_mask arb_mask;
	reg_arb_cfg_0 arb_cfg_0;
	reg_arb_choice_q_push arb_choice_q_push;
	reg_arb_wrr_weight arb_wrr_weight[4];
	reg_arb_cfg_1 arb_cfg_1;
	reg_arb_mst_avail_cred arb_mst_avail_cred[64];
	uint32_t _pad1472[8];
	reg_arb_mst_cred_inc arb_mst_cred_inc;
	reg_arb_mst_choice_push_ofst arb_mst_choice_push_ofst[64];
	uint32_t _pad1764[8];
	reg_arb_slv_master_inc_cred_ofst arb_slv_master_inc_cred_ofst;
	reg_arb_mst_slave_en arb_mst_slave_en;
	reg_arb_mst_slave_en_1 arb_mst_slave_en_1;
	reg_arb_slv_choice_wdt arb_slv_choice_wdt;
	reg_arb_slv_id arb_slv_id;
	reg_arb_mst_quiet_per arb_mst_quiet_per;
	uint32_t _pad1820[10];
	reg_arb_msg_max_inflight arb_msg_max_inflight;
	uint32_t _pad1864[3];
	reg_arb_base_lo arb_base_lo;
	reg_arb_base_hi arb_base_hi;
	uint32_t _pad1884[9];
	reg_arb_state_sts arb_state_sts;
	reg_arb_choice_fullness_sts arb_choice_fullness_sts;
	reg_arb_msg_sts arb_msg_sts;
	reg_arb_slv_choice_q_head arb_slv_choice_q_head;
	uint32_t _pad1936[3];
	reg_arb_err_cause arb_err_cause;
	reg_arb_err_msg_en arb_err_msg_en;
	uint32_t _pad1956[1];
	reg_arb_err_sts_drp arb_err_sts_drp;
	uint32_t _pad1964[1];
	reg_arb_mst_cred_sts arb_mst_cred_sts;
	reg_arb_mst_cred_sts_1 arb_mst_cred_sts_1;
	uint32_t _pad1976[17];
	reg_csmr_strict_prio_cfg csmr_strict_prio_cfg;
	reg_arc_cq_cfg0 arc_cq_cfg0;
	reg_arc_cq_cfg1 arc_cq_cfg1;
	reg_arc_cq_ptr_lo arc_cq_ptr_lo;
	reg_arc_cq_ptr_hi arc_cq_ptr_hi;
	reg_arc_cq_tsize arc_cq_tsize;
	reg_arc_cq_ctl arc_cq_ctl;
	uint32_t _pad2072[1];
	reg_arc_cq_ififo_sts arc_cq_ififo_sts;
	reg_arc_cq_sts0 arc_cq_sts0;
	reg_arc_cq_sts1 arc_cq_sts1;
	reg_arc_cq_tsize_sts arc_cq_tsize_sts;
	reg_arc_cq_ptr_lo_sts arc_cq_ptr_lo_sts;
	reg_arc_cq_ptr_hi_sts arc_cq_ptr_hi_sts;
	reg_cp_wr_arc_addr_hi cp_wr_arc_addr_hi;
	reg_cp_wr_arc_addr_lo cp_wr_arc_addr_lo;
	reg_arc_cq_ififo_msg_base_hi arc_cq_ififo_msg_base_hi;
	reg_arc_cq_ififo_msg_base_lo arc_cq_ififo_msg_base_lo;
	reg_arc_cq_ctl_msg_base_hi arc_cq_ctl_msg_base_hi;
	reg_arc_cq_ctl_msg_base_lo arc_cq_ctl_msg_base_lo;
	reg_cq_ififo_msg_base_hi cq_ififo_msg_base_hi;
	reg_cq_ififo_msg_base_lo cq_ififo_msg_base_lo;
	reg_cq_ctl_msg_base_hi cq_ctl_msg_base_hi;
	reg_cq_ctl_msg_base_lo cq_ctl_msg_base_lo;
	reg_addr_ovrd addr_ovrd;
	reg_cq_ififo_ci cq_ififo_ci[5];
	reg_arc_cq_ififo_ci arc_cq_ififo_ci;
	reg_cq_ctl_ci cq_ctl_ci[5];
	reg_arc_cq_ctl_ci arc_cq_ctl_ci;
	reg_cp_cfg cp_cfg;
	reg_cp_ext_switch cp_ext_switch;
	reg_cp_switch_wd_set cp_switch_wd_set;
	reg_cp_switch_wd cp_switch_wd;
	uint32_t _pad2208[1];
	reg_arc_lb_addr_base_lo arc_lb_addr_base_lo;
	reg_arc_lb_addr_base_hi arc_lb_addr_base_hi;
	reg_engine_base_addr_hi engine_base_addr_hi;
	reg_engine_base_addr_lo engine_base_addr_lo;
	reg_engine_addr_range_size engine_addr_range_size;
	reg_qm_arc_aux_base_addr_hi qm_arc_aux_base_addr_hi;
	reg_qm_arc_aux_base_addr_lo qm_arc_aux_base_addr_lo;
	reg_qm_base_addr_hi qm_base_addr_hi;
	reg_qm_base_addr_lo qm_base_addr_lo;
	reg_arc_pqc_secure_push_ind arc_pqc_secure_push_ind;
	uint32_t _pad2252[1];
	reg_pqc_sts_0 pqc_sts_0[4];
	reg_pqc_sts_1 pqc_sts_1[4];
	reg_sei_status sei_status;
	reg_sei_mask sei_mask;
	uint32_t _pad2296[2];
	block_qman_wr64_base_addr qman_wr64_base_addr0;
	block_qman_wr64_base_addr qman_wr64_base_addr1;
	block_qman_wr64_base_addr qman_wr64_base_addr2;
	block_qman_wr64_base_addr qman_wr64_base_addr3;
	block_qman_wr64_base_addr qman_wr64_base_addr4;
	block_qman_wr64_base_addr qman_wr64_base_addr5;
	block_qman_wr64_base_addr qman_wr64_base_addr6;
	block_qman_wr64_base_addr qman_wr64_base_addr7;
	block_qman_wr64_base_addr qman_wr64_base_addr8;
	block_qman_wr64_base_addr qman_wr64_base_addr9;
	block_qman_wr64_base_addr qman_wr64_base_addr10;
	block_qman_wr64_base_addr qman_wr64_base_addr11;
	block_qman_wr64_base_addr qman_wr64_base_addr12;
	block_qman_wr64_base_addr qman_wr64_base_addr13;
	block_qman_wr64_base_addr qman_wr64_base_addr14;
	block_qman_wr64_base_addr qman_wr64_base_addr15;
	uint32_t _pad2432[96];
	block_axuser axuser_secured;
	uint32_t _pad2896[12];
	block_axuser axuser_nonsecured;
	uint32_t _pad3024[12];
	block_ic_lbw_dbg_cnt dbg_hbw;
	uint32_t _pad3160[10];
	block_ic_lbw_dbg_cnt dbg_lbw;
	uint32_t _pad3288[10];
	reg_glbl_err_addr_lo glbl_err_addr_lo;
	reg_glbl_err_addr_hi glbl_err_addr_hi;
	reg_glbl_err_wdata glbl_err_wdata;
	uint32_t _pad3340[2];
	reg_l2h_mask_lo l2h_mask_lo;
	reg_l2h_mask_hi l2h_mask_hi;
	reg_l2h_cmpr_lo l2h_cmpr_lo;
	reg_l2h_cmpr_hi l2h_cmpr_hi;
	reg_local_range_base local_range_base;
	reg_local_range_size local_range_size;
	uint32_t _pad3372[1];
	reg_hbw_rd_rate_lim_cfg_1 hbw_rd_rate_lim_cfg_1;
	reg_lbw_wr_rate_lim_cfg_0 lbw_wr_rate_lim_cfg_0;
	reg_lbw_wr_rate_lim_cfg_1 lbw_wr_rate_lim_cfg_1;
	reg_hbw_rd_rate_lim_cfg_0 hbw_rd_rate_lim_cfg_0;
	reg_ind_gw_apb_cfg ind_gw_apb_cfg;
	reg_ind_gw_apb_wdata ind_gw_apb_wdata;
	reg_ind_gw_apb_rdata ind_gw_apb_rdata;
	reg_ind_gw_apb_status ind_gw_apb_status;
	uint32_t _pad3408[4];
	reg_perf_cnt_free_lo perf_cnt_free_lo;
	reg_perf_cnt_free_hi perf_cnt_free_hi;
	reg_perf_cnt_idle_lo perf_cnt_idle_lo;
	reg_perf_cnt_idle_hi perf_cnt_idle_hi;
	reg_perf_cnt_cfg perf_cnt_cfg;
	uint32_t _pad3444[3];
	block_qman_cgm cgm;
	uint32_t _pad3468[61];
	block_special_regs special;
} block_qman;
#endif

const offsetVal block_qman_defaults[] =
{
	// offset	// value
	{ 0x1c  , 0x3fff              , 1 }, // glbl_sts0
	{ 0x20  , 0x1                 , 1 }, // glbl_sts1
	{ 0x38  , 0x3ff7f             , 4 }, // glbl_err_msg_en
	{ 0x48  , 0x1fdff7e           , 1 }, // glbl_err_msg_en_4
	{ 0x4c  , 0x10000             , 1 }, // glbl_prot
	{ 0xb0  , 0x10001             , 4 }, // pq_cfg1
	{ 0xd0  , 0x1                 , 4 }, // pq_sts1
	{ 0x108 , 0x140014            , 5 }, // cq_cfg1
	{ 0x11c , 0x1                 , 5 }, // cq_sts1
	{ 0x1dc , 0x10                , 5 }, // cq_ififo_sts
	{ 0x330 , 0x28                , 1 }, // cp_barrier_cfg
	{ 0x334 , 0xb8d8              , 1 }, // cp_ldma_src_base_lo_offset
	{ 0x338 , 0xb8e0              , 1 }, // cp_ldma_dst_base_lo_offset
	{ 0x33c , 0xb8e8              , 1 }, // cp_ldma_tsize_offset
	{ 0x340 , 0xa150              , 1 }, // cp_cq_ptr_lo_offset_0
	{ 0x344 , 0xa160              , 1 }, // cp_cq_ptr_lo_offset_1
	{ 0x348 , 0xa170              , 1 }, // cp_cq_ptr_lo_offset_2
	{ 0x34c , 0xa180              , 1 }, // cp_cq_ptr_lo_offset_3
	{ 0x350 , 0xa190              , 1 }, // cp_cq_ptr_lo_offset_4
	{ 0x3a4 , 0x1                 , 5 }, // cp_pred
	{ 0x3b8 , 0xfffffffe          , 5 }, // cp_pred_upen
	{ 0x3cc , 0x20                , 5 }, // cp_dbg_0
	{ 0x3e0 , 0x1                 , 5 }, // cp_cpdma_up_cred
	{ 0x47c , 0x1000007f          , 4 }, // pqc_lbw_base_hi
	{ 0x4c0 , 0x40                , 64 }, // arb_mst_avail_cred
	{ 0x710 , 0x4000              , 1 }, // arb_slv_choice_wdt
	{ 0x718 , 0x10                , 1 }, // arb_mst_quiet_per
	{ 0x744 , 0x20                , 1 }, // arb_msg_max_inflight
	{ 0x780 , 0xffffffff          , 1 }, // arb_state_sts
	{ 0x788 , 0x2                 , 1 }, // arb_msg_sts
	{ 0x7b0 , 0x40                , 1 }, // arb_mst_cred_sts
	{ 0x7b4 , 0x40                , 1 }, // arb_mst_cred_sts_1
	{ 0x804 , 0x140014            , 1 }, // arc_cq_cfg1
	{ 0x81c , 0x10                , 1 }, // arc_cq_ififo_sts
	{ 0x824 , 0x1                 , 1 }, // arc_cq_sts1
	{ 0x834 , 0x1000007f          , 1 }, // cp_wr_arc_addr_hi
	{ 0x838 , 0xfca08580          , 1 }, // cp_wr_arc_addr_lo
	{ 0x83c , 0x1000007f          , 1 }, // arc_cq_ififo_msg_base_hi
	{ 0x840 , 0xfca08654          , 1 }, // arc_cq_ififo_msg_base_lo
	{ 0x844 , 0x1000007f          , 1 }, // arc_cq_ctl_msg_base_hi
	{ 0x848 , 0xfca0865c          , 1 }, // arc_cq_ctl_msg_base_lo
	{ 0x84c , 0x1000007f          , 1 }, // cq_ififo_msg_base_hi
	{ 0x850 , 0xfca08650          , 1 }, // cq_ififo_msg_base_lo
	{ 0x854 , 0x1000007f          , 1 }, // cq_ctl_msg_base_hi
	{ 0x858 , 0xfca08658          , 1 }, // cq_ctl_msg_base_lo
	{ 0x89c , 0x4000              , 1 }, // cp_switch_wd
	{ 0x8a4 , 0xf8000000          , 1 }, // arc_lb_addr_base_lo
	{ 0x8a8 , 0x1000007f          , 1 }, // arc_lb_addr_base_hi
	{ 0x8ac , 0x1000007f          , 1 }, // engine_base_addr_hi
	{ 0x8b0 , 0xfca00000          , 1 }, // engine_base_addr_lo
	{ 0x8b4 , 0x40000             , 1 }, // engine_addr_range_size
	{ 0x8b8 , 0x1000007f          , 1 }, // qm_arc_aux_base_addr_hi
	{ 0x8bc , 0xfca08000          , 1 }, // qm_arc_aux_base_addr_lo
	{ 0x8c0 , 0x1000007f          , 1 }, // qm_base_addr_hi
	{ 0x8c4 , 0xfca0a000          , 1 }, // qm_base_addr_lo
	{ 0x8e0 , 0x10                , 4 }, // pqc_sts_1
	{ 0xb04 , 0x11                , 1 }, // hb_mmu_bp
	{ 0xb08 , 0x11                , 1 }, // hb_strong_order
	{ 0xb20 , 0x11                , 1 }, // hb_emem_cpage
	{ 0xb30 , 0xffffffff          , 1 }, // hb_wr_ovrd_lo
	{ 0xb34 , 0x3ff               , 1 }, // hb_wr_ovrd_hi
	{ 0xb38 , 0xffffffff          , 1 }, // hb_rd_ovrd_lo
	{ 0xb3c , 0x3ff               , 1 }, // hb_rd_ovrd_hi
	{ 0xb4c , 0xffffffff          , 1 }, // lb_ovrd
	{ 0xb84 , 0x11                , 1 }, // hb_mmu_bp
	{ 0xb88 , 0x11                , 1 }, // hb_strong_order
	{ 0xba0 , 0x11                , 1 }, // hb_emem_cpage
	{ 0xbb0 , 0xffffffff          , 1 }, // hb_wr_ovrd_lo
	{ 0xbb4 , 0x3ff               , 1 }, // hb_wr_ovrd_hi
	{ 0xbb8 , 0xffffffff          , 1 }, // hb_rd_ovrd_lo
	{ 0xbbc , 0x3ff               , 1 }, // hb_rd_ovrd_hi
	{ 0xbcc , 0xffffffff          , 1 }, // lb_ovrd
	{ 0xc40 , 0x100               , 1 }, // otf_over_th_wr_total_req_th
	{ 0xc44 , 0x100               , 1 }, // otf_over_th_rd_total_req_th
	{ 0xc48 , 0x100               , 1 }, // otf_over_th_wr_total_cyc_th
	{ 0xc4c , 0x100               , 1 }, // otf_over_th_rd_total_cyc_th
	{ 0xcc0 , 0x100               , 1 }, // otf_over_th_wr_total_req_th
	{ 0xcc4 , 0x100               , 1 }, // otf_over_th_rd_total_req_th
	{ 0xcc8 , 0x100               , 1 }, // otf_over_th_wr_total_cyc_th
	{ 0xccc , 0x100               , 1 }, // otf_over_th_rd_total_cyc_th
	{ 0xd14 , 0xf8000000          , 1 }, // l2h_mask_lo
	{ 0xd18 , 0xffffffff          , 1 }, // l2h_mask_hi
	{ 0xd1c , 0xf8000000          , 1 }, // l2h_cmpr_lo
	{ 0xd20 , 0x1000007f          , 1 }, // l2h_cmpr_hi
	{ 0xd24 , 0xa000              , 1 }, // local_range_base
	{ 0xd28 , 0x1000              , 1 }, // local_range_size
	{ 0xd70 , 0x1f1f0f            , 1 }, // perf_cnt_cfg
	{ 0xd80 , 0x100080            , 1 }, // cfg
	{ 0xd84 , 0xf00               , 1 }, // sts
	{ 0xd88 , 0x10                , 1 }, // cfg1
	{ 0xe80 , 0xffffffff          , 32 }, // glbl_priv
	{ 0xf24 , 0xffff              , 1 }, // mem_ecc_err_addr
	{ 0xf44 , 0xffffffff          , 1 }, // glbl_err_addr
	{ 0xf80 , 0xffffffff          , 32 }, // glbl_sec
};

#ifdef __cplusplus
} /* gaudi2 namespace */
#endif

#pragma pack(pop)
#endif /* ASIC_REG_STRUCTS_QMAN_H_ */
