/***********************************
** This is an auto-generated file **
**       DO NOT EDIT BELOW        **
************************************/

#ifndef ASIC_REG_STRUCTS_QMAN_H_
#define ASIC_REG_STRUCTS_QMAN_H_

#include <stdint.h>

#pragma pack(push, 1)
namespace gaudi
{
namespace qman {
/*
 GLBL_CFG0 
 enable per pq cq cp
*/
struct reg_glbl_cfg0 {
	union {
		struct {
			uint32_t pqf_en : 4,
				cqf_en : 5,
				cp_en : 5,
				_reserved14 : 18;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_glbl_cfg0) == 4), "reg_glbl_cfg0 size is not 32-bit");
/*
 GLBL_CFG1 
 stop and flush
*/
struct reg_glbl_cfg1 {
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
};
static_assert((sizeof(struct reg_glbl_cfg1) == 4), "reg_glbl_cfg1 size is not 32-bit");
/*
 GLBL_PROT 
 Protection bit per PQ,CQ,CP. 1 means secure
*/
struct reg_glbl_prot {
	union {
		struct {
			uint32_t pqf : 4,
				cqf : 5,
				cp : 5,
				err : 1,
				arb : 1,
				_reserved16 : 16;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_glbl_prot) == 4), "reg_glbl_prot size is not 32-bit");
/*
 GLBL_ERR_CFG 
 error msg enable and stop on error
*/
struct reg_glbl_err_cfg {
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
};
static_assert((sizeof(struct reg_glbl_err_cfg) == 4), "reg_glbl_err_cfg size is not 32-bit");
/*
 GLBL_SECURE_PROPS 
 Secure properties for AXI USER
*/
struct reg_glbl_secure_props {
	union {
		struct {
			uint32_t asid : 10,
				mmbp : 1,
				_reserved11 : 21;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_glbl_secure_props) == 4), "reg_glbl_secure_props size is not 32-bit");
/*
 GLBL_NON_SECURE_PROPS 
 Non Secure properties for AXI USER
*/
struct reg_glbl_non_secure_props {
	union {
		struct {
			uint32_t asid : 10,
				mmbp : 1,
				_reserved11 : 21;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_glbl_non_secure_props) == 4), "reg_glbl_non_secure_props size is not 32-bit");
/*
 GLBL_STS0 
 Status of idle and is_stop
*/
struct reg_glbl_sts0 {
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
};
static_assert((sizeof(struct reg_glbl_sts0) == 4), "reg_glbl_sts0 size is not 32-bit");
/*
 GLBL_STS1 
 Events Error cause
*/
struct reg_glbl_sts1 {
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
				_reserved16 : 16;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_glbl_sts1) == 4), "reg_glbl_sts1 size is not 32-bit");
/*
 GLBL_STS1_4 
 Events Error cause
*/
struct reg_glbl_sts1_4 {
	union {
		struct {
			uint32_t _reserved1 : 1,
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
				_reserved16 : 16;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_glbl_sts1_4) == 4), "reg_glbl_sts1_4 size is not 32-bit");
/*
 GLBL_MSG_EN 
 MSG EN per indication
*/
struct reg_glbl_msg_en {
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
				_reserved16 : 16;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_glbl_msg_en) == 4), "reg_glbl_msg_en size is not 32-bit");
/*
 GLBL_MSG_EN_4 
 MSG EN per indication
*/
struct reg_glbl_msg_en_4 {
	union {
		struct {
			uint32_t _reserved1 : 1,
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
				_reserved16 : 16;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_glbl_msg_en_4) == 4), "reg_glbl_msg_en_4 size is not 32-bit");
/*
 PQ_BASE_LO 
 PQ base address bytes 3-0
*/
struct reg_pq_base_lo {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_pq_base_lo) == 4), "reg_pq_base_lo size is not 32-bit");
/*
 PQ_BASE_HI 
 PQ base address bytes 7-4
*/
struct reg_pq_base_hi {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_pq_base_hi) == 4), "reg_pq_base_hi size is not 32-bit");
/*
 PQ_SIZE 
 Log2(PQ allocated mem size) e.g. 8 for 256 PQ mem
*/
struct reg_pq_size {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_pq_size) == 4), "reg_pq_size size is not 32-bit");
/*
 PQ_PI 
 PQ wr pointer. SW managed.wraps at 2xPOW2(size)
*/
struct reg_pq_pi {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_pq_pi) == 4), "reg_pq_pi size is not 32-bit");
/*
 PQ_CI 
 PQ rd pointer. HW managed.wraps at 2xPOW2(size)
*/
struct reg_pq_ci {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_pq_ci) == 4), "reg_pq_ci size is not 32-bit");
/*
 PQ_CFG0 
 Reserved
*/
struct reg_pq_cfg0 {
	union {
		struct {
			uint32_t reserved : 1,
				_reserved1 : 31;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_pq_cfg0) == 4), "reg_pq_cfg0 size is not 32-bit");
/*
 PQ_CFG1 
 buffer and inflight limit
*/
struct reg_pq_cfg1 {
	union {
		struct {
			uint32_t credit_lim : 16,
				max_inflight : 16;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_pq_cfg1) == 4), "reg_pq_cfg1 size is not 32-bit");
/*
 PQ_ARUSER_31_11 
 AXI ARUser bits 31 to 11
*/
struct reg_pq_aruser_31_11 {
	union {
		struct {
			uint32_t val : 21,
				_reserved21 : 11;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_pq_aruser_31_11) == 4), "reg_pq_aruser_31_11 size is not 32-bit");
/*
 PQ_STS0 
 Status register 0
*/
struct reg_pq_sts0 {
	union {
		struct {
			uint32_t pq_credit_cnt : 16,
				pq_free_cnt : 16;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_pq_sts0) == 4), "reg_pq_sts0 size is not 32-bit");
/*
 PQ_STS1 
 Status register 1
*/
struct reg_pq_sts1 {
	union {
		struct {
			uint32_t pq_inflight_cnt : 16,
				_reserved30 : 14,
				pq_buf_empty : 1,
				pq_busy : 1;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_pq_sts1) == 4), "reg_pq_sts1 size is not 32-bit");
/*
 CQ_CFG0 
 Reserved
*/
struct reg_cq_cfg0 {
	union {
		struct {
			uint32_t reserved : 1,
				_reserved1 : 31;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_cq_cfg0) == 4), "reg_cq_cfg0 size is not 32-bit");
/*
 CQ_CFG1 
 buffer and inflight limit
*/
struct reg_cq_cfg1 {
	union {
		struct {
			uint32_t credit_lim : 16,
				max_inflight : 16;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_cq_cfg1) == 4), "reg_cq_cfg1 size is not 32-bit");
/*
 CQ_ARUSER_31_11 
 AXI User bits 31 to 11
*/
struct reg_cq_aruser_31_11 {
	union {
		struct {
			uint32_t val : 21,
				_reserved21 : 11;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_cq_aruser_31_11) == 4), "reg_cq_aruser_31_11 size is not 32-bit");
/*
 CQ_STS0 
 Status register 0
*/
struct reg_cq_sts0 {
	union {
		struct {
			uint32_t cq_credit_cnt : 16,
				cq_free_cnt : 16;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_cq_sts0) == 4), "reg_cq_sts0 size is not 32-bit");
/*
 CQ_STS1 
 Status register 1
*/
struct reg_cq_sts1 {
	union {
		struct {
			uint32_t cq_inflight_cnt : 16,
				_reserved30 : 14,
				cq_buf_empty : 1,
				cq_busy : 1;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_cq_sts1) == 4), "reg_cq_sts1 size is not 32-bit");
/*
 CQ_PTR_LO_0 
 SW config port. Read base address bytes 3-0
*/
struct reg_cq_ptr_lo_0 {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_cq_ptr_lo_0) == 4), "reg_cq_ptr_lo_0 size is not 32-bit");
/*
 CQ_PTR_HI_0 
 SW config port. Read base address bytes 7-4
*/
struct reg_cq_ptr_hi_0 {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_cq_ptr_hi_0) == 4), "reg_cq_ptr_hi_0 size is not 32-bit");
/*
 CQ_TSIZE_0 
 SW config port. Read transaction size in bytes
*/
struct reg_cq_tsize_0 {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_cq_tsize_0) == 4), "reg_cq_tsize_0 size is not 32-bit");
/*
 CQ_CTL_0 
 SW config port.ctrl bits.write initiates CQ read
*/
struct reg_cq_ctl_0 {
	union {
		struct {
			uint32_t rpt : 16,
				ctl : 16;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_cq_ctl_0) == 4), "reg_cq_ctl_0 size is not 32-bit");
/*
 CQ_PTR_LO_1 
 SW config port. Read base address bytes 3-0
*/
struct reg_cq_ptr_lo_1 {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_cq_ptr_lo_1) == 4), "reg_cq_ptr_lo_1 size is not 32-bit");
/*
 CQ_PTR_HI_1 
 SW config port. Read base address bytes 7-4
*/
struct reg_cq_ptr_hi_1 {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_cq_ptr_hi_1) == 4), "reg_cq_ptr_hi_1 size is not 32-bit");
/*
 CQ_TSIZE_1 
 SW config port. Read transaction size in bytes
*/
struct reg_cq_tsize_1 {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_cq_tsize_1) == 4), "reg_cq_tsize_1 size is not 32-bit");
/*
 CQ_CTL_1 
 SW config port.ctrl bits.write initiates CQ read
*/
struct reg_cq_ctl_1 {
	union {
		struct {
			uint32_t rpt : 16,
				ctl : 16;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_cq_ctl_1) == 4), "reg_cq_ctl_1 size is not 32-bit");
/*
 CQ_PTR_LO_2 
 SW config port. Read base address bytes 3-0
*/
struct reg_cq_ptr_lo_2 {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_cq_ptr_lo_2) == 4), "reg_cq_ptr_lo_2 size is not 32-bit");
/*
 CQ_PTR_HI_2 
 SW config port. Read base address bytes 7-4
*/
struct reg_cq_ptr_hi_2 {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_cq_ptr_hi_2) == 4), "reg_cq_ptr_hi_2 size is not 32-bit");
/*
 CQ_TSIZE_2 
 SW config port. Read transaction size in bytes
*/
struct reg_cq_tsize_2 {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_cq_tsize_2) == 4), "reg_cq_tsize_2 size is not 32-bit");
/*
 CQ_CTL_2 
 SW config port.ctrl bits.write initiates CQ read
*/
struct reg_cq_ctl_2 {
	union {
		struct {
			uint32_t rpt : 16,
				ctl : 16;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_cq_ctl_2) == 4), "reg_cq_ctl_2 size is not 32-bit");
/*
 CQ_PTR_LO_3 
 SW config port. Read base address bytes 3-0
*/
struct reg_cq_ptr_lo_3 {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_cq_ptr_lo_3) == 4), "reg_cq_ptr_lo_3 size is not 32-bit");
/*
 CQ_PTR_HI_3 
 SW config port. Read base address bytes 7-4
*/
struct reg_cq_ptr_hi_3 {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_cq_ptr_hi_3) == 4), "reg_cq_ptr_hi_3 size is not 32-bit");
/*
 CQ_TSIZE_3 
 SW config port. Read transaction size in bytes
*/
struct reg_cq_tsize_3 {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_cq_tsize_3) == 4), "reg_cq_tsize_3 size is not 32-bit");
/*
 CQ_CTL_3 
 SW config port.ctrl bits.write initiates CQ read
*/
struct reg_cq_ctl_3 {
	union {
		struct {
			uint32_t rpt : 16,
				ctl : 16;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_cq_ctl_3) == 4), "reg_cq_ctl_3 size is not 32-bit");
/*
 CQ_PTR_LO_4 
 SW config port. Read base address bytes 3-0
*/
struct reg_cq_ptr_lo_4 {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_cq_ptr_lo_4) == 4), "reg_cq_ptr_lo_4 size is not 32-bit");
/*
 CQ_PTR_HI_4 
 SW config port. Read base address bytes 7-4
*/
struct reg_cq_ptr_hi_4 {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_cq_ptr_hi_4) == 4), "reg_cq_ptr_hi_4 size is not 32-bit");
/*
 CQ_TSIZE_4 
 SW config port. Read transaction size in bytes
*/
struct reg_cq_tsize_4 {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_cq_tsize_4) == 4), "reg_cq_tsize_4 size is not 32-bit");
/*
 CQ_CTL_4 
 SW config port.ctrl bits.write initiates CQ read
*/
struct reg_cq_ctl_4 {
	union {
		struct {
			uint32_t rpt : 16,
				ctl : 16;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_cq_ctl_4) == 4), "reg_cq_ctl_4 size is not 32-bit");
/*
 CQ_PTR_LO_STS 
 Current transfer base address byte 3-0
*/
struct reg_cq_ptr_lo_sts {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_cq_ptr_lo_sts) == 4), "reg_cq_ptr_lo_sts size is not 32-bit");
/*
 CQ_PTR_HI_STS 
 Current transfer base address byte 7-4
*/
struct reg_cq_ptr_hi_sts {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_cq_ptr_hi_sts) == 4), "reg_cq_ptr_hi_sts size is not 32-bit");
/*
 CQ_TSIZE_STS 
 Curent transfer size in bytes
*/
struct reg_cq_tsize_sts {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_cq_tsize_sts) == 4), "reg_cq_tsize_sts size is not 32-bit");
/*
 CQ_CTL_STS 
 Currenet transactions Control fields
*/
struct reg_cq_ctl_sts {
	union {
		struct {
			uint32_t rpt : 16,
				ctl : 16;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_cq_ctl_sts) == 4), "reg_cq_ctl_sts size is not 32-bit");
/*
 CQ_IFIFO_CNT 
 num of pq_cq_entries in cq_ififo
*/
struct reg_cq_ififo_cnt {
	union {
		struct {
			uint32_t val : 2,
				_reserved2 : 30;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_cq_ififo_cnt) == 4), "reg_cq_ififo_cnt size is not 32-bit");
/*
 CP_MSG_BASE0_ADDR_LO 
 Byte 3-0 of message base addr 0
*/
struct reg_cp_msg_base0_addr_lo {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_cp_msg_base0_addr_lo) == 4), "reg_cp_msg_base0_addr_lo size is not 32-bit");
/*
 CP_MSG_BASE0_ADDR_HI 
 Byte 7-4 of message base addr 0
*/
struct reg_cp_msg_base0_addr_hi {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_cp_msg_base0_addr_hi) == 4), "reg_cp_msg_base0_addr_hi size is not 32-bit");
/*
 CP_MSG_BASE1_ADDR_LO 
 Byte 3-0 of message base addr 1
*/
struct reg_cp_msg_base1_addr_lo {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_cp_msg_base1_addr_lo) == 4), "reg_cp_msg_base1_addr_lo size is not 32-bit");
/*
 CP_MSG_BASE1_ADDR_HI 
 Byte 7-4 of message base addr 1
*/
struct reg_cp_msg_base1_addr_hi {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_cp_msg_base1_addr_hi) == 4), "reg_cp_msg_base1_addr_hi size is not 32-bit");
/*
 CP_MSG_BASE2_ADDR_LO 
 Byte 3-0 of message base addr 2
*/
struct reg_cp_msg_base2_addr_lo {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_cp_msg_base2_addr_lo) == 4), "reg_cp_msg_base2_addr_lo size is not 32-bit");
/*
 CP_MSG_BASE2_ADDR_HI 
 Byte 7-4 of message base addr 2
*/
struct reg_cp_msg_base2_addr_hi {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_cp_msg_base2_addr_hi) == 4), "reg_cp_msg_base2_addr_hi size is not 32-bit");
/*
 CP_MSG_BASE3_ADDR_LO 
 Byte 3-0 of message base addr 3
*/
struct reg_cp_msg_base3_addr_lo {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_cp_msg_base3_addr_lo) == 4), "reg_cp_msg_base3_addr_lo size is not 32-bit");
/*
 CP_MSG_BASE3_ADDR_HI 
 Byte 7-4 of message base addr 3
*/
struct reg_cp_msg_base3_addr_hi {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_cp_msg_base3_addr_hi) == 4), "reg_cp_msg_base3_addr_hi size is not 32-bit");
/*
 CP_LDMA_TSIZE_OFFSET 
 Offset of DMA cmd to write TSIZE
*/
struct reg_cp_ldma_tsize_offset {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_cp_ldma_tsize_offset) == 4), "reg_cp_ldma_tsize_offset size is not 32-bit");
/*
 CP_LDMA_SRC_BASE_LO_OFFSET 
 Offset of DMA cmd to write SRC_ADDR bytes 3-0
*/
struct reg_cp_ldma_src_base_lo_offset {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_cp_ldma_src_base_lo_offset) == 4), "reg_cp_ldma_src_base_lo_offset size is not 32-bit");
/*
 CP_LDMA_DST_BASE_LO_OFFSET 
 Offset of DMA cmd to write DST_ADDR bytes 3-0
*/
struct reg_cp_ldma_dst_base_lo_offset {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_cp_ldma_dst_base_lo_offset) == 4), "reg_cp_ldma_dst_base_lo_offset size is not 32-bit");
/*
 CP_FENCE0_RDATA 
 Increment value for fence 0
*/
struct reg_cp_fence0_rdata {
	union {
		struct {
			uint32_t inc_val : 4,
				_reserved4 : 28;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_cp_fence0_rdata) == 4), "reg_cp_fence0_rdata size is not 32-bit");
/*
 CP_FENCE1_RDATA 
 Increment value for fence 1
*/
struct reg_cp_fence1_rdata {
	union {
		struct {
			uint32_t inc_val : 4,
				_reserved4 : 28;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_cp_fence1_rdata) == 4), "reg_cp_fence1_rdata size is not 32-bit");
/*
 CP_FENCE2_RDATA 
 Increment value for fence 2
*/
struct reg_cp_fence2_rdata {
	union {
		struct {
			uint32_t inc_val : 4,
				_reserved4 : 28;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_cp_fence2_rdata) == 4), "reg_cp_fence2_rdata size is not 32-bit");
/*
 CP_FENCE3_RDATA 
 Increment value for fence 3
*/
struct reg_cp_fence3_rdata {
	union {
		struct {
			uint32_t inc_val : 4,
				_reserved4 : 28;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_cp_fence3_rdata) == 4), "reg_cp_fence3_rdata size is not 32-bit");
/*
 CP_FENCE0_CNT 
 Current value of fence 0
*/
struct reg_cp_fence0_cnt {
	union {
		struct {
			uint32_t val : 14,
				_reserved14 : 18;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_cp_fence0_cnt) == 4), "reg_cp_fence0_cnt size is not 32-bit");
/*
 CP_FENCE1_CNT 
 Current value of fence 1
*/
struct reg_cp_fence1_cnt {
	union {
		struct {
			uint32_t val : 14,
				_reserved14 : 18;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_cp_fence1_cnt) == 4), "reg_cp_fence1_cnt size is not 32-bit");
/*
 CP_FENCE2_CNT 
 Current value of fence 2
*/
struct reg_cp_fence2_cnt {
	union {
		struct {
			uint32_t val : 14,
				_reserved14 : 18;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_cp_fence2_cnt) == 4), "reg_cp_fence2_cnt size is not 32-bit");
/*
 CP_FENCE3_CNT 
 Current value of fence 3
*/
struct reg_cp_fence3_cnt {
	union {
		struct {
			uint32_t val : 14,
				_reserved14 : 18;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_cp_fence3_cnt) == 4), "reg_cp_fence3_cnt size is not 32-bit");
/*
 CP_STS 
 Satus register
*/
struct reg_cp_sts {
	union {
		struct {
			uint32_t msg_inflight_cnt : 16,
				erdy : 1,
				rrdy : 1,
				mrdy : 1,
				sw_stop : 1,
				fence_id : 2,
				fence_in_progress : 1,
				_reserved23 : 9;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_cp_sts) == 4), "reg_cp_sts size is not 32-bit");
/*
 CP_CURRENT_INST_LO 
 Byte 3-0 of current CP instruction
*/
struct reg_cp_current_inst_lo {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_cp_current_inst_lo) == 4), "reg_cp_current_inst_lo size is not 32-bit");
/*
 CP_CURRENT_INST_HI 
 Byte 7-4 of current CP instruction
*/
struct reg_cp_current_inst_hi {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_cp_current_inst_hi) == 4), "reg_cp_current_inst_hi size is not 32-bit");
/*
 CP_BARRIER_CFG 
 Guard band to allow engine to deassert idle
*/
struct reg_cp_barrier_cfg {
	union {
		struct {
			uint32_t ebguard : 12,
				_reserved16 : 4,
				rbguard : 4,
				_reserved20 : 12;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_cp_barrier_cfg) == 4), "reg_cp_barrier_cfg size is not 32-bit");
/*
 CP_DBG_0 
 debug reg 0
*/
struct reg_cp_dbg_0 {
	union {
		struct {
			uint32_t cs : 4,
				eb_cnt_not_zero : 1,
				bulk_cnt_not_zero : 1,
				mreb_stall : 1,
				stall : 1,
				_reserved8 : 24;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_cp_dbg_0) == 4), "reg_cp_dbg_0 size is not 32-bit");
/*
 CP_ARUSER_31_11 
 CP AXI user bits
*/
struct reg_cp_aruser_31_11 {
	union {
		struct {
			uint32_t val : 21,
				_reserved21 : 11;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_cp_aruser_31_11) == 4), "reg_cp_aruser_31_11 size is not 32-bit");
/*
 CP_AWUSER_31_11 
 AXI AWUser bits 31 to 11
*/
struct reg_cp_awuser_31_11 {
	union {
		struct {
			uint32_t val : 21,
				_reserved21 : 11;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_cp_awuser_31_11) == 4), "reg_cp_awuser_31_11 size is not 32-bit");
/*
 ARB_CFG_0 
 config: enable, type, is_master
*/
struct reg_arb_cfg_0 {
	union {
		struct {
			uint32_t type : 1,
				_reserved4 : 3,
				is_master : 1,
				_reserved8 : 3,
				en : 1,
				_reserved12 : 3,
				mask : 4,
				mst_msg_nostall : 1,
				_reserved17 : 15;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_arb_cfg_0) == 4), "reg_arb_cfg_0 size is not 32-bit");
/*
 ARB_CHOISE_Q_PUSH 
 On slave - push choise Q from master
*/
struct reg_arb_choise_q_push {
	union {
		struct {
			uint32_t val : 2,
				_reserved2 : 30;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_arb_choise_q_push) == 4), "reg_arb_choise_q_push size is not 32-bit");
/*
 ARB_WRR_WEIGHT 
 WRR Weight
*/
struct reg_arb_wrr_weight {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_arb_wrr_weight) == 4), "reg_arb_wrr_weight size is not 32-bit");
/*
 ARB_CFG_1 
 CLR
*/
struct reg_arb_cfg_1 {
	union {
		struct {
			uint32_t clr : 1,
				_reserved1 : 31;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_arb_cfg_1) == 4), "reg_arb_cfg_1 size is not 32-bit");
/*
 ARB_STATE_STS 
 CURRENT ARB REQ GNT STATE
*/
struct reg_arb_state_sts {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_arb_state_sts) == 4), "reg_arb_state_sts size is not 32-bit");
/*
 ARB_ERR_CAUSE 
 ERR CAUSE
*/
struct reg_arb_err_cause {
	union {
		struct {
			uint32_t choise_ovf : 1,
				choise_wdt : 1,
				axi_lbw_err : 1,
				_reserved3 : 29;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_arb_err_cause) == 4), "reg_arb_err_cause size is not 32-bit");
/*
 ARB_ERR_MSG_EN 
 ERR MSG EN
*/
struct reg_arb_err_msg_en {
	union {
		struct {
			uint32_t choise_ovf : 1,
				choise_wdt : 1,
				axi_lbw_err : 1,
				_reserved3 : 29;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_arb_err_msg_en) == 4), "reg_arb_err_msg_en size is not 32-bit");
/*
 ARB_MST_AVAIL_CRED 
 LIMIT CHOISE Q CREDITS MASTER SIDE
*/
struct reg_arb_mst_avail_cred {
	union {
		struct {
			uint32_t val : 7,
				_reserved7 : 25;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_arb_mst_avail_cred) == 4), "reg_arb_mst_avail_cred size is not 32-bit");
/*
 ARB_MST_CRED_INC 
 CREDIT INC NOTIFY FROM SLAVE
*/
struct reg_arb_mst_cred_inc {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_arb_mst_cred_inc) == 4), "reg_arb_mst_cred_inc size is not 32-bit");
/*
 ARB_MST_CHOISE_PUSH_OFST 
 CHOISE Qs Offsets
*/
struct reg_arb_mst_choise_push_ofst {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_arb_mst_choise_push_ofst) == 4), "reg_arb_mst_choise_push_ofst size is not 32-bit");
/*
 ARB_MST_SLAVE_EN 
 per slave EN notify on CP prio grant
*/
struct reg_arb_mst_slave_en {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_arb_mst_slave_en) == 4), "reg_arb_mst_slave_en size is not 32-bit");
/*
 ARB_SLV_MASTER_INC_CRED_OFST 
 ADDRESS OF Slave CHOISE Q PUSH
*/
struct reg_arb_slv_master_inc_cred_ofst {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_arb_slv_master_inc_cred_ofst) == 4), "reg_arb_slv_master_inc_cred_ofst size is not 32-bit");
/*
 ARB_CHOISE_FULLNESS_STS 
 CHOISE Q FULLNESS LEVEL
*/
struct reg_arb_choise_fullness_sts {
	union {
		struct {
			uint32_t val : 7,
				_reserved7 : 25;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_arb_choise_fullness_sts) == 4), "reg_arb_choise_fullness_sts size is not 32-bit");
/*
 ARB_MST_QUIET_PER 
 Quiet period Between Grants Before New Grant
*/
struct reg_arb_mst_quiet_per {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_arb_mst_quiet_per) == 4), "reg_arb_mst_quiet_per size is not 32-bit");
/*
 ARB_SLV_CHOISE_WDT 
 Watch Dog For Choise Q not popped but ready
*/
struct reg_arb_slv_choise_wdt {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_arb_slv_choise_wdt) == 4), "reg_arb_slv_choise_wdt size is not 32-bit");
/*
 ARB_SLV_ID 
 QMAN SLAVE ID SYSTEM WISE FOR CREDIT MNG
*/
struct reg_arb_slv_id {
	union {
		struct {
			uint32_t val : 5,
				_reserved5 : 27;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_arb_slv_id) == 4), "reg_arb_slv_id size is not 32-bit");
/*
 ARB_ERR_STS_DRP 
 NUMBER OF CP THAT WAS DROPPED
*/
struct reg_arb_err_sts_drp {
	union {
		struct {
			uint32_t val : 2,
				_reserved2 : 30;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_arb_err_sts_drp) == 4), "reg_arb_err_sts_drp size is not 32-bit");
/*
 ARB_MSG_MAX_INFLIGHT 
 LIMIT MAX INFLIGHT MESSAGES
*/
struct reg_arb_msg_max_inflight {
	union {
		struct {
			uint32_t val : 6,
				_reserved6 : 26;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_arb_msg_max_inflight) == 4), "reg_arb_msg_max_inflight size is not 32-bit");
/*
 ARB_MSG_AWUSER_31_11 
 USER BITS 31_11
*/
struct reg_arb_msg_awuser_31_11 {
	union {
		struct {
			uint32_t val : 21,
				_reserved21 : 11;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_arb_msg_awuser_31_11) == 4), "reg_arb_msg_awuser_31_11 size is not 32-bit");
/*
 ARB_MSG_AWUSER_SEC_PROP 
 SECURE USER BITS 10_0 MMBP and ASID
*/
struct reg_arb_msg_awuser_sec_prop {
	union {
		struct {
			uint32_t asid : 10,
				mmbp : 1,
				_reserved11 : 21;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_arb_msg_awuser_sec_prop) == 4), "reg_arb_msg_awuser_sec_prop size is not 32-bit");
/*
 ARB_MSG_AWUSER_NON_SEC_PROP 
 NON SECURE USER BITS 10_0 MMBP and ASID
*/
struct reg_arb_msg_awuser_non_sec_prop {
	union {
		struct {
			uint32_t asid : 10,
				mmbp : 1,
				_reserved11 : 21;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_arb_msg_awuser_non_sec_prop) == 4), "reg_arb_msg_awuser_non_sec_prop size is not 32-bit");
/*
 ARB_MSG_STS 
 Status of ARB LBW MSG agent
*/
struct reg_arb_msg_sts {
	union {
		struct {
			uint32_t full : 1,
				no_inflight : 1,
				_reserved2 : 30;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_arb_msg_sts) == 4), "reg_arb_msg_sts size is not 32-bit");
/*
 ARB_SLV_CHOISE_Q_HEAD 
 Head of choise Q next CP to be granted
*/
struct reg_arb_slv_choise_q_head {
	union {
		struct {
			uint32_t val : 2,
				_reserved2 : 30;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_arb_slv_choise_q_head) == 4), "reg_arb_slv_choise_q_head size is not 32-bit");
/*
 LOCAL_RANGE_BASE 
 QMAN location relative to 64KB default 0x8000
*/
struct reg_local_range_base {
	union {
		struct {
			uint32_t val : 16,
				_reserved16 : 16;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_local_range_base) == 4), "reg_local_range_base size is not 32-bit");
/*
 LOCAL_RANGE_SIZE 
 Size of QMAN Address space deafult 0x2000
*/
struct reg_local_range_size {
	union {
		struct {
			uint32_t val : 16,
				_reserved16 : 16;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_local_range_size) == 4), "reg_local_range_size size is not 32-bit");
/*
 HBW_RD_RATE_LIM_CFG_0 
 rate limiter qman HBW port
*/
struct reg_hbw_rd_rate_lim_cfg_0 {
	union {
		struct {
			uint32_t rst_token : 8,
				_reserved16 : 8,
				sat : 8,
				_reserved24 : 8;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_hbw_rd_rate_lim_cfg_0) == 4), "reg_hbw_rd_rate_lim_cfg_0 size is not 32-bit");
/*
 CSMR_STRICT_PRIO_CFG 
 Strict or RR select for top CPs
*/
struct reg_csmr_strict_prio_cfg {
	union {
		struct {
			uint32_t type : 1,
				_reserved1 : 31;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_csmr_strict_prio_cfg) == 4), "reg_csmr_strict_prio_cfg size is not 32-bit");
/*
 HBW_RD_RATE_LIM_CFG_1 
 rate limiter qman HBW port
*/
struct reg_hbw_rd_rate_lim_cfg_1 {
	union {
		struct {
			uint32_t tout : 8,
				_reserved31 : 23,
				en : 1;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_hbw_rd_rate_lim_cfg_1) == 4), "reg_hbw_rd_rate_lim_cfg_1 size is not 32-bit");
/*
 LBW_WR_RATE_LIM_CFG_0 
 rate limiter qman LBW port
*/
struct reg_lbw_wr_rate_lim_cfg_0 {
	union {
		struct {
			uint32_t rst_token : 8,
				_reserved16 : 8,
				sat : 8,
				_reserved24 : 8;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_lbw_wr_rate_lim_cfg_0) == 4), "reg_lbw_wr_rate_lim_cfg_0 size is not 32-bit");
/*
 LBW_WR_RATE_LIM_CFG_1 
 rate limiter qman LBW port
*/
struct reg_lbw_wr_rate_lim_cfg_1 {
	union {
		struct {
			uint32_t tout : 8,
				_reserved31 : 23,
				en : 1;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_lbw_wr_rate_lim_cfg_1) == 4), "reg_lbw_wr_rate_lim_cfg_1 size is not 32-bit");
/*
 GLBL_AXCACHE 
 global HBW AXI ARCACHE LBW AWCACHE
*/
struct reg_glbl_axcache {
	union {
		struct {
			uint32_t ar : 4,
				_reserved16 : 12,
				aw : 4,
				_reserved20 : 12;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_glbl_axcache) == 4), "reg_glbl_axcache size is not 32-bit");
/*
 IND_GW_APB_CFG 
 Addre and Cmd Indirect access to memories gateway
*/
struct reg_ind_gw_apb_cfg {
	union {
		struct {
			uint32_t addr : 31,
				cmd : 1;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_ind_gw_apb_cfg) == 4), "reg_ind_gw_apb_cfg size is not 32-bit");
/*
 IND_GW_APB_RDATA 
 Read data Indirect access to memories gateway
*/
struct reg_ind_gw_apb_rdata {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_ind_gw_apb_rdata) == 4), "reg_ind_gw_apb_rdata size is not 32-bit");
/*
 IND_GW_APB_STATUS 
 Status Indirect access to memories gateway
*/
struct reg_ind_gw_apb_status {
	union {
		struct {
			uint32_t rdy : 1,
				err : 1,
				_reserved2 : 30;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_ind_gw_apb_status) == 4), "reg_ind_gw_apb_status size is not 32-bit");
/*
 GLBL_ERR_ADDR_LO 
 global Error LB address byte 3 to 0
*/
struct reg_glbl_err_addr_lo {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_glbl_err_addr_lo) == 4), "reg_glbl_err_addr_lo size is not 32-bit");
/*
 GLBL_ERR_ADDR_HI 
 global Error LB address byte 7 to 4
*/
struct reg_glbl_err_addr_hi {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_glbl_err_addr_hi) == 4), "reg_glbl_err_addr_hi size is not 32-bit");
/*
 GLBL_ERR_WDATA 
 global Error LB wdata to send
*/
struct reg_glbl_err_wdata {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_glbl_err_wdata) == 4), "reg_glbl_err_wdata size is not 32-bit");
/*
 CGM_CFG 
 Clock gate Manager config
*/
struct reg_cgm_cfg {
	union {
		struct {
			uint32_t idle_th : 12,
				_reserved16 : 4,
				g2f_th : 8,
				cp_idle_mask : 5,
				_reserved31 : 2,
				en : 1;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_cgm_cfg) == 4), "reg_cgm_cfg size is not 32-bit");
/*
 CGM_STS 
 Clock Manager Status
*/
struct reg_cgm_sts {
	union {
		struct {
			uint32_t st : 2,
				_reserved4 : 2,
				cg : 1,
				_reserved8 : 3,
				agent_idle : 1,
				axi_idle : 1,
				cp_idle : 1,
				_reserved11 : 21;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_cgm_sts) == 4), "reg_cgm_sts size is not 32-bit");
/*
 ARB_MST_CRED_STS 
 Current status of credits per slave
*/
struct reg_arb_mst_cred_sts {
	union {
		struct {
			uint32_t val : 7,
				_reserved7 : 25;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_arb_mst_cred_sts) == 4), "reg_arb_mst_cred_sts size is not 32-bit");
/*
 GLBL_MEM_INIT_BUSY 
 Memory init status 1 means busy
*/
struct reg_glbl_mem_init_busy {
	union {
		struct {
			uint32_t rbuf : 4,
				_reserved4 : 28;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_glbl_mem_init_busy) == 4), "reg_glbl_mem_init_busy size is not 32-bit");
/*
 IND_GW_APB_WDATA 
 GW wdata
*/
struct reg_ind_gw_apb_wdata {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_ind_gw_apb_wdata) == 4), "reg_ind_gw_apb_wdata size is not 32-bit");
/*
 ARB_BASE_LO 
 Base address bits 31to0 for arb lbw access
*/
struct reg_arb_base_lo {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_arb_base_lo) == 4), "reg_arb_base_lo size is not 32-bit");
/*
 ARB_BASE_HI 
 Base address bits 63to32 for arb lbw access
*/
struct reg_arb_base_hi {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_arb_base_hi) == 4), "reg_arb_base_hi size is not 32-bit");
/*
 CGM_CFG1 
 CGM config reg 1 HBW mask Thresh
*/
struct reg_cgm_cfg1 {
	union {
		struct {
			uint32_t mask_th : 8,
				_reserved8 : 24;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_cgm_cfg1) == 4), "reg_cgm_cfg1 size is not 32-bit");
} /* qman namespace */

/*
 QMAN block
*/
struct block_qman {
	struct qman::reg_glbl_cfg0 glbl_cfg0;
	struct qman::reg_glbl_cfg1 glbl_cfg1;
	struct qman::reg_glbl_prot glbl_prot;
	struct qman::reg_glbl_err_cfg glbl_err_cfg;
	struct qman::reg_glbl_secure_props glbl_secure_props[5];
	struct qman::reg_glbl_non_secure_props glbl_non_secure_props[5];
	struct qman::reg_glbl_sts0 glbl_sts0;
	uint32_t _pad60[1];
	struct qman::reg_glbl_sts1 glbl_sts1[4];
	struct qman::reg_glbl_sts1_4 glbl_sts1_4;
	struct qman::reg_glbl_msg_en glbl_msg_en[4];
	uint32_t _pad100[1];
	struct qman::reg_glbl_msg_en_4 glbl_msg_en_4;
	uint32_t _pad108[1];
	struct qman::reg_pq_base_lo pq_base_lo[4];
	struct qman::reg_pq_base_hi pq_base_hi[4];
	struct qman::reg_pq_size pq_size[4];
	struct qman::reg_pq_pi pq_pi[4];
	struct qman::reg_pq_ci pq_ci[4];
	struct qman::reg_pq_cfg0 pq_cfg0[4];
	struct qman::reg_pq_cfg1 pq_cfg1[4];
	struct qman::reg_pq_aruser_31_11 pq_aruser_31_11[4];
	struct qman::reg_pq_sts0 pq_sts0[4];
	struct qman::reg_pq_sts1 pq_sts1[4];
	struct qman::reg_cq_cfg0 cq_cfg0[5];
	struct qman::reg_cq_cfg1 cq_cfg1[5];
	struct qman::reg_cq_aruser_31_11 cq_aruser_31_11[5];
	struct qman::reg_cq_sts0 cq_sts0[5];
	struct qman::reg_cq_sts1 cq_sts1[5];
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
	struct qman::reg_cq_ptr_lo_sts cq_ptr_lo_sts[5];
	struct qman::reg_cq_ptr_hi_sts cq_ptr_hi_sts[5];
	struct qman::reg_cq_tsize_sts cq_tsize_sts[5];
	struct qman::reg_cq_ctl_sts cq_ctl_sts[5];
	struct qman::reg_cq_ififo_cnt cq_ififo_cnt[5];
	struct qman::reg_cp_msg_base0_addr_lo cp_msg_base0_addr_lo[5];
	struct qman::reg_cp_msg_base0_addr_hi cp_msg_base0_addr_hi[5];
	struct qman::reg_cp_msg_base1_addr_lo cp_msg_base1_addr_lo[5];
	struct qman::reg_cp_msg_base1_addr_hi cp_msg_base1_addr_hi[5];
	struct qman::reg_cp_msg_base2_addr_lo cp_msg_base2_addr_lo[5];
	struct qman::reg_cp_msg_base2_addr_hi cp_msg_base2_addr_hi[5];
	struct qman::reg_cp_msg_base3_addr_lo cp_msg_base3_addr_lo[5];
	struct qman::reg_cp_msg_base3_addr_hi cp_msg_base3_addr_hi[5];
	struct qman::reg_cp_ldma_tsize_offset cp_ldma_tsize_offset[5];
	uint32_t _pad732[1];
	struct qman::reg_cp_ldma_src_base_lo_offset cp_ldma_src_base_lo_offset[5];
	struct qman::reg_cp_ldma_dst_base_lo_offset cp_ldma_dst_base_lo_offset[5];
	struct qman::reg_cp_fence0_rdata cp_fence0_rdata[5];
	struct qman::reg_cp_fence1_rdata cp_fence1_rdata[5];
	struct qman::reg_cp_fence2_rdata cp_fence2_rdata[5];
	struct qman::reg_cp_fence3_rdata cp_fence3_rdata[5];
	struct qman::reg_cp_fence0_cnt cp_fence0_cnt[5];
	struct qman::reg_cp_fence1_cnt cp_fence1_cnt[5];
	struct qman::reg_cp_fence2_cnt cp_fence2_cnt[5];
	struct qman::reg_cp_fence3_cnt cp_fence3_cnt[5];
	struct qman::reg_cp_sts cp_sts[5];
	struct qman::reg_cp_current_inst_lo cp_current_inst_lo[5];
	struct qman::reg_cp_current_inst_hi cp_current_inst_hi[5];
	uint32_t _pad996[4];
	struct qman::reg_cp_barrier_cfg cp_barrier_cfg[5];
	struct qman::reg_cp_dbg_0 cp_dbg_0[5];
	struct qman::reg_cp_aruser_31_11 cp_aruser_31_11[5];
	struct qman::reg_cp_awuser_31_11 cp_awuser_31_11[5];
	uint32_t _pad1092[367];
	struct qman::reg_arb_cfg_0 arb_cfg_0;
	struct qman::reg_arb_choise_q_push arb_choise_q_push;
	struct qman::reg_arb_wrr_weight arb_wrr_weight[4];
	struct qman::reg_arb_cfg_1 arb_cfg_1;
	uint32_t _pad2588[1];
	struct qman::reg_arb_mst_avail_cred arb_mst_avail_cred[32];
	struct qman::reg_arb_mst_cred_inc arb_mst_cred_inc;
	struct qman::reg_arb_mst_choise_push_ofst arb_mst_choise_push_ofst[32];
	uint32_t _pad2852[1];
	struct qman::reg_arb_slv_master_inc_cred_ofst arb_slv_master_inc_cred_ofst;
	struct qman::reg_arb_mst_slave_en arb_mst_slave_en;
	uint32_t _pad2864[1];
	struct qman::reg_arb_mst_quiet_per arb_mst_quiet_per;
	struct qman::reg_arb_slv_choise_wdt arb_slv_choise_wdt;
	struct qman::reg_arb_slv_id arb_slv_id;
	uint32_t _pad2880[1];
	struct qman::reg_arb_msg_max_inflight arb_msg_max_inflight;
	struct qman::reg_arb_msg_awuser_31_11 arb_msg_awuser_31_11;
	struct qman::reg_arb_msg_awuser_sec_prop arb_msg_awuser_sec_prop;
	struct qman::reg_arb_msg_awuser_non_sec_prop arb_msg_awuser_non_sec_prop;
	struct qman::reg_arb_base_lo arb_base_lo;
	struct qman::reg_arb_base_hi arb_base_hi;
	uint32_t _pad2908[9];
	struct qman::reg_arb_state_sts arb_state_sts;
	struct qman::reg_arb_choise_fullness_sts arb_choise_fullness_sts;
	struct qman::reg_arb_msg_sts arb_msg_sts;
	struct qman::reg_arb_slv_choise_q_head arb_slv_choise_q_head;
	uint32_t _pad2960[3];
	struct qman::reg_arb_err_cause arb_err_cause;
	struct qman::reg_arb_err_msg_en arb_err_msg_en;
	uint32_t _pad2980[1];
	struct qman::reg_arb_err_sts_drp arb_err_sts_drp;
	uint32_t _pad2988[1];
	struct qman::reg_arb_mst_cred_sts arb_mst_cred_sts[32];
	uint32_t _pad3120[16];
	struct qman::reg_cgm_cfg cgm_cfg;
	struct qman::reg_cgm_sts cgm_sts;
	struct qman::reg_cgm_cfg1 cgm_cfg1;
	uint32_t _pad3196[1];
	struct qman::reg_local_range_base local_range_base;
	struct qman::reg_local_range_size local_range_size;
	uint32_t _pad3208[2];
	struct qman::reg_csmr_strict_prio_cfg csmr_strict_prio_cfg;
	struct qman::reg_hbw_rd_rate_lim_cfg_1 hbw_rd_rate_lim_cfg_1;
	struct qman::reg_lbw_wr_rate_lim_cfg_0 lbw_wr_rate_lim_cfg_0;
	struct qman::reg_lbw_wr_rate_lim_cfg_1 lbw_wr_rate_lim_cfg_1;
	struct qman::reg_hbw_rd_rate_lim_cfg_0 hbw_rd_rate_lim_cfg_0;
	struct qman::reg_glbl_axcache glbl_axcache;
	uint32_t _pad3240[2];
	struct qman::reg_ind_gw_apb_cfg ind_gw_apb_cfg;
	struct qman::reg_ind_gw_apb_wdata ind_gw_apb_wdata;
	struct qman::reg_ind_gw_apb_rdata ind_gw_apb_rdata;
	struct qman::reg_ind_gw_apb_status ind_gw_apb_status;
	uint32_t _pad3264[4];
	struct qman::reg_glbl_err_addr_lo glbl_err_addr_lo;
	struct qman::reg_glbl_err_addr_hi glbl_err_addr_hi;
	struct qman::reg_glbl_err_wdata glbl_err_wdata;
	uint32_t _pad3292[9];
	struct qman::reg_glbl_mem_init_busy glbl_mem_init_busy;
};
} // namespace gaudi
#include "gaudi_types.h"
namespace gaudi
{
const offsetVal block_qman_defaults[]
{
	// offset	// value
	{ 0x10  , 0x400               , 5 }, // glbl_secure_props
	{ 0x24  , 0x400               , 5 }, // glbl_non_secure_props
	{ 0x38  , 0x3fff              , 1 }, // glbl_sts0
	{ 0x54  , 0xff7f              , 4 }, // glbl_msg_en
	{ 0x68  , 0xff7e              , 1 }, // glbl_msg_en_4
	{ 0xd0  , 0x10001             , 4 }, // pq_cfg1
	{ 0x100 , 0x40000000          , 4 }, // pq_sts1
	{ 0x124 , 0x140014            , 5 }, // cq_cfg1
	{ 0x160 , 0x40000000          , 5 }, // cq_sts1
	{ 0x2c8 , 0x103c              , 5 }, // cp_ldma_tsize_offset
	{ 0x2e0 , 0x102c              , 5 }, // cp_ldma_src_base_lo_offset
	{ 0x2f4 , 0x1034              , 5 }, // cp_ldma_dst_base_lo_offset
	{ 0x3f4 , 0x28                , 5 }, // cp_barrier_cfg
	{ 0x408 , 0x10                , 5 }, // cp_dbg_0
	{ 0xa20 , 0x40                , 32 }, // arb_mst_avail_cred
	{ 0xb34 , 0x10                , 1 }, // arb_mst_quiet_per
	{ 0xb38 , 0x4000              , 1 }, // arb_slv_choise_wdt
	{ 0xb44 , 0x20                , 1 }, // arb_msg_max_inflight
	{ 0xb80 , 0xffffffff          , 1 }, // arb_state_sts
	{ 0xb88 , 0x2                 , 1 }, // arb_msg_sts
	{ 0xbb0 , 0x40                , 32 }, // arb_mst_cred_sts
	{ 0xc70 , 0xf100400           , 1 }, // cgm_cfg
	{ 0xc74 , 0x700               , 1 }, // cgm_sts
	{ 0xc78 , 0x10                , 1 }, // cgm_cfg1
	{ 0xc80 , 0x8000              , 1 }, // local_range_base
	{ 0xc84 , 0x2000              , 1 }, // local_range_size
};

} //namespace gaudi
#pragma pack(pop)
#endif /* ASIC_REG_STRUCTS_QMAN_H_ */
