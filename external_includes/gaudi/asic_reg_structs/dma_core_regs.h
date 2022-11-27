/***********************************
** This is an auto-generated file **
**       DO NOT EDIT BELOW        **
************************************/

#ifndef ASIC_REG_STRUCTS_DMA_CORE_H_
#define ASIC_REG_STRUCTS_DMA_CORE_H_

#include <stdint.h>

#pragma pack(push, 1)
namespace gaudi
{
namespace dma_core {
/*
 CFG_0 
 dman_en
*/
struct reg_cfg_0 {
	union {
		struct {
			uint32_t en : 1,
				_reserved1 : 31;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_cfg_0) == 4), "reg_cfg_0 size is not 32-bit");
/*
 CFG_1 
 Halt(stop), flush,force-miss
*/
struct reg_cfg_1 {
	union {
		struct {
			uint32_t halt : 1,
				flush : 1,
				sb_force_miss : 1,
				_reserved3 : 29;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_cfg_1) == 4), "reg_cfg_1 size is not 32-bit");
/*
 ERRMSG_ADDR_LO 
 Error message address byte 3-0
*/
struct reg_errmsg_addr_lo {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_errmsg_addr_lo) == 4), "reg_errmsg_addr_lo size is not 32-bit");
/*
 ERRMSG_ADDR_HI 
 Error message address byte 7-4
*/
struct reg_errmsg_addr_hi {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_errmsg_addr_hi) == 4), "reg_errmsg_addr_hi size is not 32-bit");
/*
 ERRMSG_WDATA 
 Error message wdata to send
*/
struct reg_errmsg_wdata {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_errmsg_wdata) == 4), "reg_errmsg_wdata size is not 32-bit");
/*
 WR_COMP_ADDR_LO 
 Wr completion msg address byte 3-0
*/
struct reg_wr_comp_addr_lo {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_wr_comp_addr_lo) == 4), "reg_wr_comp_addr_lo size is not 32-bit");
/*
 WR_COMP_ADDR_HI 
 Wr completion msg address byte 7-4
*/
struct reg_wr_comp_addr_hi {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_wr_comp_addr_hi) == 4), "reg_wr_comp_addr_hi size is not 32-bit");
/*
 WR_COMP_WDATA 
 Wr completion msg wdata to send
*/
struct reg_wr_comp_wdata {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_wr_comp_wdata) == 4), "reg_wr_comp_wdata size is not 32-bit");
/*
 SRC_BASE_LO 
 Source base address byte 3-0
*/
struct reg_src_base_lo {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_src_base_lo) == 4), "reg_src_base_lo size is not 32-bit");
/*
 SRC_BASE_HI 
 Source base address byte 7-4
*/
struct reg_src_base_hi {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_src_base_hi) == 4), "reg_src_base_hi size is not 32-bit");
/*
 DST_BASE_LO 
 Destination base address byte 3-0
*/
struct reg_dst_base_lo {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_dst_base_lo) == 4), "reg_dst_base_lo size is not 32-bit");
/*
 DST_BASE_HI 
 Destination base address byte 6-4, CONTEXT_ID bits 15:8
*/
struct reg_dst_base_hi {
	union {
		struct {
			uint32_t val : 24,
				ctx_id_hi : 8;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_dst_base_hi) == 4), "reg_dst_base_hi size is not 32-bit");
/*
 SRC_TSIZE_0 
 Size in bytes of dim 0 transfer
*/
struct reg_src_tsize_0 {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_src_tsize_0) == 4), "reg_src_tsize_0 size is not 32-bit");
/*
 COMMIT 
 Controls+CONTEXT_ID bits 7:0. writing to this reg initiates transfer
*/
struct reg_commit {
	union {
		struct {
			uint32_t wr_comp_en : 1,
				transpose : 1,
				dtype : 1,
				lin : 1,
				mem_set : 1,
				compress : 1,
				decompress : 1,
				_reserved16 : 9,
				ctx_id : 8,
				_reserved24 : 8;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_commit) == 4), "reg_commit size is not 32-bit");
/*
 DBG_STS 
 FIFOs status etc
*/
struct reg_dbg_sts {
	union {
		struct {
			uint32_t rd_ctx_full : 1,
				wr_ctx_full : 1,
				wr_comp_full : 1,
				rd_ctx_empty : 1,
				wr_ctx_empty : 1,
				wr_comp_empty : 1,
				te_empty : 1,
				te_busy : 1,
				gskt_empty : 1,
				gskt_full : 1,
				_reserved20 : 10,
				rdbuf_fullness : 11,
				_reserved31 : 1;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_dbg_sts) == 4), "reg_dbg_sts size is not 32-bit");
/*
 DBG_DESC_CNT 
 Global cyclic read descriptor count for debug
*/
struct reg_dbg_desc_cnt {
	union {
		struct {
			uint32_t rd_sts_ctx_cnt : 32;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_dbg_desc_cnt) == 4), "reg_dbg_desc_cnt size is not 32-bit");
/*
 SRC_TSIZE_1 
*/
struct reg_src_tsize_1 {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_src_tsize_1) == 4), "reg_src_tsize_1 size is not 32-bit");
/*
 SRC_STRIDE_1 
*/
struct reg_src_stride_1 {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_src_stride_1) == 4), "reg_src_stride_1 size is not 32-bit");
/*
 SRC_TSIZE_2 
*/
struct reg_src_tsize_2 {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_src_tsize_2) == 4), "reg_src_tsize_2 size is not 32-bit");
/*
 SRC_STRIDE_2 
*/
struct reg_src_stride_2 {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_src_stride_2) == 4), "reg_src_stride_2 size is not 32-bit");
/*
 SRC_TSIZE_3 
*/
struct reg_src_tsize_3 {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_src_tsize_3) == 4), "reg_src_tsize_3 size is not 32-bit");
/*
 SRC_STRIDE_3 
*/
struct reg_src_stride_3 {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_src_stride_3) == 4), "reg_src_stride_3 size is not 32-bit");
/*
 SRC_TSIZE_4 
*/
struct reg_src_tsize_4 {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_src_tsize_4) == 4), "reg_src_tsize_4 size is not 32-bit");
/*
 SRC_STRIDE_4 
*/
struct reg_src_stride_4 {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_src_stride_4) == 4), "reg_src_stride_4 size is not 32-bit");
/*
 DST_STRIDE_1 
*/
struct reg_dst_stride_1 {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_dst_stride_1) == 4), "reg_dst_stride_1 size is not 32-bit");
/*
 DST_STRIDE_2 
*/
struct reg_dst_stride_2 {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_dst_stride_2) == 4), "reg_dst_stride_2 size is not 32-bit");
/*
 DST_STRIDE_3 
*/
struct reg_dst_stride_3 {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_dst_stride_3) == 4), "reg_dst_stride_3 size is not 32-bit");
/*
 DST_STRIDE_4 
*/
struct reg_dst_stride_4 {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_dst_stride_4) == 4), "reg_dst_stride_4 size is not 32-bit");
/*
 RD_RATE_LIM_CFG_1 
 Read rate limiter timeout
*/
struct reg_rd_rate_lim_cfg_1 {
	union {
		struct {
			uint32_t tout : 8,
				_reserved31 : 23,
				en : 1;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_rd_rate_lim_cfg_1) == 4), "reg_rd_rate_lim_cfg_1 size is not 32-bit");
/*
 RD_RATE_LIM_CFG_0 
 Read rate config 0. Tokens and Saturation
*/
struct reg_rd_rate_lim_cfg_0 {
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
static_assert((sizeof(struct reg_rd_rate_lim_cfg_0) == 4), "reg_rd_rate_lim_cfg_0 size is not 32-bit");
/*
 WR_RATE_LIM_CFG_0 
 Write rate config 0. Tokens and Saturation
*/
struct reg_wr_rate_lim_cfg_0 {
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
static_assert((sizeof(struct reg_wr_rate_lim_cfg_0) == 4), "reg_wr_rate_lim_cfg_0 size is not 32-bit");
/*
 WR_RATE_LIM_CFG_1 
 Write rate limiter timeout
*/
struct reg_wr_rate_lim_cfg_1 {
	union {
		struct {
			uint32_t tout : 8,
				_reserved31 : 23,
				en : 1;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_wr_rate_lim_cfg_1) == 4), "reg_wr_rate_lim_cfg_1 size is not 32-bit");
/*
 RD_ARUSER_31_11 
 AXI ARUSER BITS 31to11
*/
struct reg_rd_aruser_31_11 {
	union {
		struct {
			uint32_t val : 21,
				_reserved21 : 11;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_rd_aruser_31_11) == 4), "reg_rd_aruser_31_11 size is not 32-bit");
/*
 WR_AWUSER_31_11 
 AWUSER 31to11 bit 11 is weakOrder 12 is noSnoop
*/
struct reg_wr_awuser_31_11 {
	union {
		struct {
			uint32_t val : 21,
				_reserved21 : 11;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_wr_awuser_31_11) == 4), "reg_wr_awuser_31_11 size is not 32-bit");
/*
 ERR_CAUSE 
 Error cause
*/
struct reg_err_cause {
	union {
		struct {
			uint32_t hbw_rd_err : 1,
				hbw_wr_err : 1,
				lbw_wr_err : 1,
				desc_ovf : 1,
				_reserved4 : 28;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_err_cause) == 4), "reg_err_cause size is not 32-bit");
/*
 DST_TSIZE_0 
 Size in bytes of dim0. QMAN CP LDMA uses this as size
*/
struct reg_dst_tsize_0 {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_dst_tsize_0) == 4), "reg_dst_tsize_0 size is not 32-bit");
/*
 DST_TSIZE_1 
 Size in bytes of last dim 0 transfer
*/
struct reg_dst_tsize_1 {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_dst_tsize_1) == 4), "reg_dst_tsize_1 size is not 32-bit");
/*
 DST_TSIZE_2 
 Size in bytes of last dim 0 transfer
*/
struct reg_dst_tsize_2 {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_dst_tsize_2) == 4), "reg_dst_tsize_2 size is not 32-bit");
/*
 DST_TSIZE_3 
 Size in bytes of last dim 0 transfer
*/
struct reg_dst_tsize_3 {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_dst_tsize_3) == 4), "reg_dst_tsize_3 size is not 32-bit");
/*
 DST_TSIZE_4 
 Size in bytes of last dim 0 transfer
*/
struct reg_dst_tsize_4 {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_dst_tsize_4) == 4), "reg_dst_tsize_4 size is not 32-bit");
/*
 RD_MAX_SIZE 
 Max buffer size to use. value of 0 is max
*/
struct reg_rd_max_size {
	union {
		struct {
			uint32_t data : 11,
				_reserved16 : 5,
				md : 11,
				_reserved27 : 5;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_rd_max_size) == 4), "reg_rd_max_size size is not 32-bit");
/*
 WR_MAX_AWID 
 MAX ID value for Wr buffer for debug
*/
struct reg_wr_max_awid {
	union {
		struct {
			uint32_t val : 16,
				_reserved16 : 16;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_wr_max_awid) == 4), "reg_wr_max_awid size is not 32-bit");
/*
 PROT 
 Security settings for normal operation and error
*/
struct reg_prot {
	union {
		struct {
			uint32_t val : 1,
				err_val : 1,
				_reserved2 : 30;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_prot) == 4), "reg_prot size is not 32-bit");
/*
 ERR_CFG 
 Err msg en, stop on error
*/
struct reg_err_cfg {
	union {
		struct {
			uint32_t err_msg_en : 1,
				stop_on_err : 1,
				_reserved2 : 30;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_err_cfg) == 4), "reg_err_cfg size is not 32-bit");
/*
 SECURE_PROPS 
 Secure Properties MMU_BP ASID
*/
struct reg_secure_props {
	union {
		struct {
			uint32_t asid : 10,
				mmbp : 1,
				_reserved11 : 21;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_secure_props) == 4), "reg_secure_props size is not 32-bit");
/*
 NON_SECURE_PROPS 
 Non Secure Properties MMU_BP ASID
*/
struct reg_non_secure_props {
	union {
		struct {
			uint32_t asid : 10,
				mmbp : 1,
				_reserved11 : 21;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_non_secure_props) == 4), "reg_non_secure_props size is not 32-bit");
/*
 RD_DBGMEM_ADD 
 Read buf address access for debug
*/
struct reg_rd_dbgmem_add {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_rd_dbgmem_add) == 4), "reg_rd_dbgmem_add size is not 32-bit");
/*
 RD_DBGMEM_DATA_WR 
 Read buf write data access for debug
*/
struct reg_rd_dbgmem_data_wr {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_rd_dbgmem_data_wr) == 4), "reg_rd_dbgmem_data_wr size is not 32-bit");
/*
 RD_DBGMEM_DATA_RD 
 Read buf read data access for debug
*/
struct reg_rd_dbgmem_data_rd {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_rd_dbgmem_data_rd) == 4), "reg_rd_dbgmem_data_rd size is not 32-bit");
/*
 RD_DBGMEM_CTRL 
 Read buf access type for debug also inits command
*/
struct reg_rd_dbgmem_ctrl {
	union {
		struct {
			uint32_t wr_nrd : 1,
				_reserved1 : 31;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_rd_dbgmem_ctrl) == 4), "reg_rd_dbgmem_ctrl size is not 32-bit");
/*
 RD_DBGMEM_RC 
 Read buf read clear data access for debug
*/
struct reg_rd_dbgmem_rc {
	union {
		struct {
			uint32_t valid : 1,
				_reserved1 : 31;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_rd_dbgmem_rc) == 4), "reg_rd_dbgmem_rc size is not 32-bit");
/*
 RD_ARCACHE 
 AXI ARCACHE
*/
struct reg_rd_arcache {
	union {
		struct {
			uint32_t val : 4,
				_reserved4 : 28;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_rd_arcache) == 4), "reg_rd_arcache size is not 32-bit");
/*
 RD_INFLIGHTS 
 Read buffer open requests counter
*/
struct reg_rd_inflights {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_rd_inflights) == 4), "reg_rd_inflights size is not 32-bit");
/*
 WR_AWCACHE 
 AXI AWCACHE
*/
struct reg_wr_awcache {
	union {
		struct {
			uint32_t val : 4,
				_reserved4 : 28;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_wr_awcache) == 4), "reg_wr_awcache size is not 32-bit");
/*
 WR_INFLIGHTS 
 AXI INFLIGHT Writes COUNTER
*/
struct reg_wr_inflights {
	union {
		struct {
			uint32_t val : 16,
				_reserved16 : 16;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_wr_inflights) == 4), "reg_wr_inflights size is not 32-bit");
/*
 TE_NUMROWS 
 Total number of rows per descriptor
*/
struct reg_te_numrows {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_te_numrows) == 4), "reg_te_numrows size is not 32-bit");
/*
 RD_MAX_OUTSTAND 
 Max Read open AXI transactions
*/
struct reg_rd_max_outstand {
	union {
		struct {
			uint32_t val : 12,
				_reserved12 : 20;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_rd_max_outstand) == 4), "reg_rd_max_outstand size is not 32-bit");
/*
 WR_MAX_OUTSTAND 
 Max Writeopen AXI transactions
*/
struct reg_wr_max_outstand {
	union {
		struct {
			uint32_t val : 12,
				_reserved12 : 20;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_wr_max_outstand) == 4), "reg_wr_max_outstand size is not 32-bit");
/*
 WR_COMP_AWUSER_31_11 
 AWUSER 31to11 bit 11 is weakOrder 12 is noSnoop
*/
struct reg_wr_comp_awuser_31_11 {
	union {
		struct {
			uint32_t val : 21,
				_reserved21 : 11;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_wr_comp_awuser_31_11) == 4), "reg_wr_comp_awuser_31_11 size is not 32-bit");
/*
 DBG_HBW_AXI_AR_CNT 
 Global cyclic axi read req count for debug
*/
struct reg_dbg_hbw_axi_ar_cnt {
	union {
		struct {
			uint32_t _reserved0 : 32;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_dbg_hbw_axi_ar_cnt) == 4), "reg_dbg_hbw_axi_ar_cnt size is not 32-bit");
/*
 DBG_HBW_AXI_AW_CNT 
 Global cyclic axi write req count for debug
*/
struct reg_dbg_hbw_axi_aw_cnt {
	union {
		struct {
			uint32_t _reserved0 : 32;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_dbg_hbw_axi_aw_cnt) == 4), "reg_dbg_hbw_axi_aw_cnt size is not 32-bit");
/*
 STS0 
 BUSY and counters
*/
struct reg_sts0 {
	union {
		struct {
			uint32_t rd_req_cnt : 15,
				_reserved16 : 1,
				wr_req_cnt : 15,
				busy : 1;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_sts0) == 4), "reg_sts0 size is not 32-bit");
/*
 DBG_LBW_AXI_AW_CNT 
 Global cyclic axi write req count for debug
*/
struct reg_dbg_lbw_axi_aw_cnt {
	union {
		struct {
			uint32_t _reserved0 : 32;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_dbg_lbw_axi_aw_cnt) == 4), "reg_dbg_lbw_axi_aw_cnt size is not 32-bit");
/*
 STS1 
 IS_STOP
*/
struct reg_sts1 {
	union {
		struct {
			uint32_t is_halt : 1,
				_reserved1 : 31;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_sts1) == 4), "reg_sts1 size is not 32-bit");
/*
 LBW_MAX_OUTSTAND 
 MAX LBW AXI transactions
*/
struct reg_lbw_max_outstand {
	union {
		struct {
			uint32_t val : 5,
				_reserved5 : 27;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_lbw_max_outstand) == 4), "reg_lbw_max_outstand size is not 32-bit");
/*
 DBG_RD_DESC_ID 
 Current RD descriptor ID
*/
struct reg_dbg_rd_desc_id {
	union {
		struct {
			uint32_t _reserved0 : 32;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_dbg_rd_desc_id) == 4), "reg_dbg_rd_desc_id size is not 32-bit");
/*
 DBG_WR_DESC_ID 
 Current WR descriptor ID
*/
struct reg_dbg_wr_desc_id {
	union {
		struct {
			uint32_t _reserved0 : 32;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_dbg_wr_desc_id) == 4), "reg_dbg_wr_desc_id size is not 32-bit");
} /* dma_core namespace */

/*
 DMA_CORE block
*/
struct block_dma_core {
	struct dma_core::reg_cfg_0 cfg_0;
	struct dma_core::reg_cfg_1 cfg_1;
	struct dma_core::reg_lbw_max_outstand lbw_max_outstand;
	uint32_t _pad12[2];
	struct dma_core::reg_src_base_lo src_base_lo;
	struct dma_core::reg_src_base_hi src_base_hi;
	struct dma_core::reg_dst_base_lo dst_base_lo;
	struct dma_core::reg_dst_base_hi dst_base_hi;
	uint32_t _pad36[2];
	struct dma_core::reg_src_tsize_1 src_tsize_1;
	struct dma_core::reg_src_stride_1 src_stride_1;
	struct dma_core::reg_src_tsize_2 src_tsize_2;
	struct dma_core::reg_src_stride_2 src_stride_2;
	struct dma_core::reg_src_tsize_3 src_tsize_3;
	struct dma_core::reg_src_stride_3 src_stride_3;
	struct dma_core::reg_src_tsize_4 src_tsize_4;
	struct dma_core::reg_src_stride_4 src_stride_4;
	struct dma_core::reg_src_tsize_0 src_tsize_0;
	uint32_t _pad80[1];
	struct dma_core::reg_dst_tsize_1 dst_tsize_1;
	struct dma_core::reg_dst_stride_1 dst_stride_1;
	struct dma_core::reg_dst_tsize_2 dst_tsize_2;
	struct dma_core::reg_dst_stride_2 dst_stride_2;
	struct dma_core::reg_dst_tsize_3 dst_tsize_3;
	struct dma_core::reg_dst_stride_3 dst_stride_3;
	struct dma_core::reg_dst_tsize_4 dst_tsize_4;
	struct dma_core::reg_dst_stride_4 dst_stride_4;
	struct dma_core::reg_dst_tsize_0 dst_tsize_0;
	struct dma_core::reg_commit commit;
	struct dma_core::reg_wr_comp_wdata wr_comp_wdata;
	struct dma_core::reg_wr_comp_addr_lo wr_comp_addr_lo;
	struct dma_core::reg_wr_comp_addr_hi wr_comp_addr_hi;
	struct dma_core::reg_wr_comp_awuser_31_11 wr_comp_awuser_31_11;
	uint32_t _pad140[2];
	struct dma_core::reg_te_numrows te_numrows;
	uint32_t _pad152[8];
	struct dma_core::reg_prot prot;
	uint32_t _pad188[13];
	struct dma_core::reg_secure_props secure_props;
	struct dma_core::reg_non_secure_props non_secure_props;
	uint32_t _pad248[2];
	struct dma_core::reg_rd_max_outstand rd_max_outstand;
	struct dma_core::reg_rd_max_size rd_max_size;
	struct dma_core::reg_rd_arcache rd_arcache;
	uint32_t _pad268[1];
	struct dma_core::reg_rd_aruser_31_11 rd_aruser_31_11;
	struct dma_core::reg_rd_inflights rd_inflights;
	uint32_t _pad280[2];
	struct dma_core::reg_wr_max_outstand wr_max_outstand;
	struct dma_core::reg_wr_max_awid wr_max_awid;
	struct dma_core::reg_wr_awcache wr_awcache;
	uint32_t _pad300[1];
	struct dma_core::reg_wr_awuser_31_11 wr_awuser_31_11;
	struct dma_core::reg_wr_inflights wr_inflights;
	uint32_t _pad312[6];
	struct dma_core::reg_rd_rate_lim_cfg_0 rd_rate_lim_cfg_0;
	struct dma_core::reg_rd_rate_lim_cfg_1 rd_rate_lim_cfg_1;
	struct dma_core::reg_wr_rate_lim_cfg_0 wr_rate_lim_cfg_0;
	struct dma_core::reg_wr_rate_lim_cfg_1 wr_rate_lim_cfg_1;
	struct dma_core::reg_err_cfg err_cfg;
	struct dma_core::reg_err_cause err_cause;
	uint32_t _pad360[2];
	struct dma_core::reg_errmsg_addr_lo errmsg_addr_lo;
	struct dma_core::reg_errmsg_addr_hi errmsg_addr_hi;
	struct dma_core::reg_errmsg_wdata errmsg_wdata;
	uint32_t _pad380[5];
	struct dma_core::reg_sts0 sts0;
	struct dma_core::reg_sts1 sts1;
	uint32_t _pad408[26];
	struct dma_core::reg_rd_dbgmem_add rd_dbgmem_add;
	struct dma_core::reg_rd_dbgmem_data_wr rd_dbgmem_data_wr;
	struct dma_core::reg_rd_dbgmem_data_rd rd_dbgmem_data_rd;
	struct dma_core::reg_rd_dbgmem_ctrl rd_dbgmem_ctrl;
	struct dma_core::reg_rd_dbgmem_rc rd_dbgmem_rc;
	uint32_t _pad532[3];
	struct dma_core::reg_dbg_hbw_axi_ar_cnt dbg_hbw_axi_ar_cnt;
	struct dma_core::reg_dbg_hbw_axi_aw_cnt dbg_hbw_axi_aw_cnt;
	struct dma_core::reg_dbg_lbw_axi_aw_cnt dbg_lbw_axi_aw_cnt;
	struct dma_core::reg_dbg_desc_cnt dbg_desc_cnt;
	struct dma_core::reg_dbg_sts dbg_sts;
	struct dma_core::reg_dbg_rd_desc_id dbg_rd_desc_id;
	struct dma_core::reg_dbg_wr_desc_id dbg_wr_desc_id;
};
#include "gaudi_types.h"
const offsetVal block_dma_core_defaults[]
{
	// offset	// value
	{ 0x8   , 0x14                , 1 }, // lbw_max_outstand
	{ 0x100 , 0x690               , 1 }, // rd_max_outstand
	{ 0x104 , 0x6900690           , 1 }, // rd_max_size
	{ 0x110 , 0x1                 , 1 }, // rd_aruser_31_11
	{ 0x120 , 0x3ff               , 1 }, // wr_max_outstand
	{ 0x124 , 0x3ff               , 1 }, // wr_max_awid
	{ 0x130 , 0x1                 , 1 }, // wr_awuser_31_11
	{ 0x230 , 0x178               , 1 }, // dbg_sts
};
} // namespace gaudi
#pragma pack(pop)
#endif /* ASIC_REG_STRUCTS_DMA_CORE_H_ */
