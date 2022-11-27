/***********************************
** This is an auto-generated file **
**       DO NOT EDIT BELOW        **
************************************/

#ifndef ASIC_REG_STRUCTS_DMA_CORE_H_
#define ASIC_REG_STRUCTS_DMA_CORE_H_

#include <stdint.h>
#include "gaudi2_types.h"
#include "axuser_regs.h"
#include "dma_core_ctx_regs.h"
#include "qman_cgm_regs.h"
#include "special_regs_regs.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace gaudi2 {
namespace dma_core {
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
 CFG_0 
 b'DMA enable'
*/
typedef struct reg_cfg_0 {
	union {
		struct {
			uint32_t en : 1,
				_reserved1 : 31;
		};
		uint32_t _raw;
	};
} reg_cfg_0;
static_assert((sizeof(struct reg_cfg_0) == 4), "reg_cfg_0 size is not 32-bit");
/*
 CFG_1 
 b'Halt(stop), flush,force-miss'
*/
typedef struct reg_cfg_1 {
	union {
		struct {
			uint32_t halt : 1,
				flush : 1,
				_reserved2 : 30;
		};
		uint32_t _raw;
	};
} reg_cfg_1;
static_assert((sizeof(struct reg_cfg_1) == 4), "reg_cfg_1 size is not 32-bit");
/*
 PROT 
 b'Secure or non Secure master'
*/
typedef struct reg_prot {
	union {
		struct {
			uint32_t val : 1,
				err_val : 1,
				_reserved2 : 30;
		};
		uint32_t _raw;
	};
} reg_prot;
static_assert((sizeof(struct reg_prot) == 4), "reg_prot size is not 32-bit");
/*
 CKG 
 b'clock gating config'
*/
typedef struct reg_ckg {
	union {
		struct {
			uint32_t hbw_rbuf : 1,
				lbw_rbuf_kdma : 1,
				te : 1,
				_reserved3 : 29;
		};
		uint32_t _raw;
	};
} reg_ckg;
static_assert((sizeof(struct reg_ckg) == 4), "reg_ckg size is not 32-bit");
/*
 RD_GLBL 
 b'global RD config'
*/
typedef struct reg_rd_glbl {
	union {
		struct {
			uint32_t lbw_via_hbw : 1,
				_reserved4 : 3,
				hbw_force_miss : 1,
				lbw_force_miss : 1,
				_reserved6 : 26;
		};
		uint32_t _raw;
	};
} reg_rd_glbl;
static_assert((sizeof(struct reg_rd_glbl) == 4), "reg_rd_glbl size is not 32-bit");
/*
 RD_HBW_MAX_OUTSTAND 
 b'Max Read open AXI transactions.0 means max possible'
*/
typedef struct reg_rd_hbw_max_outstand {
	union {
		struct {
			uint32_t val : 12,
				_reserved12 : 20;
		};
		uint32_t _raw;
	};
} reg_rd_hbw_max_outstand;
static_assert((sizeof(struct reg_rd_hbw_max_outstand) == 4), "reg_rd_hbw_max_outstand size is not 32-bit");
/*
 RD_HBW_MAX_SIZE 
 b'Max buffers size to use. 0 means max possible'
*/
typedef struct reg_rd_hbw_max_size {
	union {
		struct {
			uint32_t data : 12,
				_reserved16 : 4,
				md : 12,
				_reserved28 : 4;
		};
		uint32_t _raw;
	};
} reg_rd_hbw_max_size;
static_assert((sizeof(struct reg_rd_hbw_max_size) == 4), "reg_rd_hbw_max_size size is not 32-bit");
/*
 RD_HBW_ARCACHE 
 b'AXI ARCACHE'
*/
typedef struct reg_rd_hbw_arcache {
	union {
		struct {
			uint32_t val : 4,
				_reserved4 : 28;
		};
		uint32_t _raw;
	};
} reg_rd_hbw_arcache;
static_assert((sizeof(struct reg_rd_hbw_arcache) == 4), "reg_rd_hbw_arcache size is not 32-bit");
/*
 RD_HBW_INFLIGHTS 
 b'Read buffer open requests counter'
*/
typedef struct reg_rd_hbw_inflights {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_rd_hbw_inflights;
static_assert((sizeof(struct reg_rd_hbw_inflights) == 4), "reg_rd_hbw_inflights size is not 32-bit");
/*
 RD_HBW_RATE_LIM_CFG 
 b'Read rate limiter timeout,saturation,enable'
*/
typedef struct reg_rd_hbw_rate_lim_cfg {
	union {
		struct {
			uint32_t tout : 8,
				_reserved16 : 8,
				sat : 8,
				_reserved31 : 7,
				en : 1;
		};
		uint32_t _raw;
	};
} reg_rd_hbw_rate_lim_cfg;
static_assert((sizeof(struct reg_rd_hbw_rate_lim_cfg) == 4), "reg_rd_hbw_rate_lim_cfg size is not 32-bit");
/*
 RD_LBW_MAX_OUTSTAND 
 b'Max Read open AXI transactions.0 means max possible'
*/
typedef struct reg_rd_lbw_max_outstand {
	union {
		struct {
			uint32_t val : 12,
				_reserved12 : 20;
		};
		uint32_t _raw;
	};
} reg_rd_lbw_max_outstand;
static_assert((sizeof(struct reg_rd_lbw_max_outstand) == 4), "reg_rd_lbw_max_outstand size is not 32-bit");
/*
 RD_LBW_MAX_SIZE 
 b'Max buffers size to use. 0 means max possible'
*/
typedef struct reg_rd_lbw_max_size {
	union {
		struct {
			uint32_t data : 12,
				_reserved16 : 4,
				md : 12,
				_reserved28 : 4;
		};
		uint32_t _raw;
	};
} reg_rd_lbw_max_size;
static_assert((sizeof(struct reg_rd_lbw_max_size) == 4), "reg_rd_lbw_max_size size is not 32-bit");
/*
 RD_LBW_ARCACHE 
 b'AXI ARCACHE'
*/
typedef struct reg_rd_lbw_arcache {
	union {
		struct {
			uint32_t val : 4,
				_reserved4 : 28;
		};
		uint32_t _raw;
	};
} reg_rd_lbw_arcache;
static_assert((sizeof(struct reg_rd_lbw_arcache) == 4), "reg_rd_lbw_arcache size is not 32-bit");
/*
 RD_LBW_INFLIGHTS 
 b'Read buffer open requests counter'
*/
typedef struct reg_rd_lbw_inflights {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_rd_lbw_inflights;
static_assert((sizeof(struct reg_rd_lbw_inflights) == 4), "reg_rd_lbw_inflights size is not 32-bit");
/*
 RD_LBW_RATE_LIM_CFG 
 b'Read rate limiter timeout,saturation,enable'
*/
typedef struct reg_rd_lbw_rate_lim_cfg {
	union {
		struct {
			uint32_t tout : 8,
				_reserved16 : 8,
				sat : 8,
				_reserved31 : 7,
				en : 1;
		};
		uint32_t _raw;
	};
} reg_rd_lbw_rate_lim_cfg;
static_assert((sizeof(struct reg_rd_lbw_rate_lim_cfg) == 4), "reg_rd_lbw_rate_lim_cfg size is not 32-bit");
/*
 WR_HBW_MAX_OUTSTAND 
 b'Max open AXI-WR transactions. val of 0 means max possible'
*/
typedef struct reg_wr_hbw_max_outstand {
	union {
		struct {
			uint32_t val : 16,
				_reserved16 : 16;
		};
		uint32_t _raw;
	};
} reg_wr_hbw_max_outstand;
static_assert((sizeof(struct reg_wr_hbw_max_outstand) == 4), "reg_wr_hbw_max_outstand size is not 32-bit");
/*
 WR_HBW_MAX_AWID 
 b'MAX ID value for Wr buffer for debug'
*/
typedef struct reg_wr_hbw_max_awid {
	union {
		struct {
			uint32_t val : 14,
				_reserved14 : 18;
		};
		uint32_t _raw;
	};
} reg_wr_hbw_max_awid;
static_assert((sizeof(struct reg_wr_hbw_max_awid) == 4), "reg_wr_hbw_max_awid size is not 32-bit");
/*
 WR_HBW_AWCACHE 
 b'AXI AWCACHE'
*/
typedef struct reg_wr_hbw_awcache {
	union {
		struct {
			uint32_t val : 4,
				_reserved4 : 28;
		};
		uint32_t _raw;
	};
} reg_wr_hbw_awcache;
static_assert((sizeof(struct reg_wr_hbw_awcache) == 4), "reg_wr_hbw_awcache size is not 32-bit");
/*
 WR_HBW_INFLIGHTS 
 b'AXI INFLIGHT Writes COUNTER'
*/
typedef struct reg_wr_hbw_inflights {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_wr_hbw_inflights;
static_assert((sizeof(struct reg_wr_hbw_inflights) == 4), "reg_wr_hbw_inflights size is not 32-bit");
/*
 WR_HBW_RATE_LIM_CFG 
 b'Write rate limiter timeout,saturation,enable'
*/
typedef struct reg_wr_hbw_rate_lim_cfg {
	union {
		struct {
			uint32_t tout : 8,
				_reserved16 : 8,
				sat : 8,
				_reserved31 : 7,
				en : 1;
		};
		uint32_t _raw;
	};
} reg_wr_hbw_rate_lim_cfg;
static_assert((sizeof(struct reg_wr_hbw_rate_lim_cfg) == 4), "reg_wr_hbw_rate_lim_cfg size is not 32-bit");
/*
 WR_LBW_MAX_OUTSTAND 
 b'Max open AXI-WR transactions. val of 0 means max possible'
*/
typedef struct reg_wr_lbw_max_outstand {
	union {
		struct {
			uint32_t val : 16,
				_reserved16 : 16;
		};
		uint32_t _raw;
	};
} reg_wr_lbw_max_outstand;
static_assert((sizeof(struct reg_wr_lbw_max_outstand) == 4), "reg_wr_lbw_max_outstand size is not 32-bit");
/*
 WR_LBW_MAX_AWID 
 b'MAX ID value for Wr buffer for debug'
*/
typedef struct reg_wr_lbw_max_awid {
	union {
		struct {
			uint32_t val : 7,
				_reserved7 : 25;
		};
		uint32_t _raw;
	};
} reg_wr_lbw_max_awid;
static_assert((sizeof(struct reg_wr_lbw_max_awid) == 4), "reg_wr_lbw_max_awid size is not 32-bit");
/*
 WR_LBW_AWCACHE 
 b'AXI AWCACHE'
*/
typedef struct reg_wr_lbw_awcache {
	union {
		struct {
			uint32_t val : 4,
				_reserved4 : 28;
		};
		uint32_t _raw;
	};
} reg_wr_lbw_awcache;
static_assert((sizeof(struct reg_wr_lbw_awcache) == 4), "reg_wr_lbw_awcache size is not 32-bit");
/*
 WR_LBW_INFLIGHTS 
 b'AXI INFLIGHT Writes COUNTER'
*/
typedef struct reg_wr_lbw_inflights {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_wr_lbw_inflights;
static_assert((sizeof(struct reg_wr_lbw_inflights) == 4), "reg_wr_lbw_inflights size is not 32-bit");
/*
 WR_LBW_RATE_LIM_CFG 
 b'Write rate limiter timeout,saturation,enable'
*/
typedef struct reg_wr_lbw_rate_lim_cfg {
	union {
		struct {
			uint32_t tout : 8,
				_reserved16 : 8,
				sat : 8,
				_reserved31 : 7,
				en : 1;
		};
		uint32_t _raw;
	};
} reg_wr_lbw_rate_lim_cfg;
static_assert((sizeof(struct reg_wr_lbw_rate_lim_cfg) == 4), "reg_wr_lbw_rate_lim_cfg size is not 32-bit");
/*
 WR_COMP_MAX_OUTSTAND 
 b'MAX LBW AXI transactions'
*/
typedef struct reg_wr_comp_max_outstand {
	union {
		struct {
			uint32_t val : 5,
				_reserved5 : 27;
		};
		uint32_t _raw;
	};
} reg_wr_comp_max_outstand;
static_assert((sizeof(struct reg_wr_comp_max_outstand) == 4), "reg_wr_comp_max_outstand size is not 32-bit");
/*
 WR_COMP_AWUSER 
 b'AWUSER bits for completion message'
*/
typedef struct reg_wr_comp_awuser {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_wr_comp_awuser;
static_assert((sizeof(struct reg_wr_comp_awuser) == 4), "reg_wr_comp_awuser size is not 32-bit");
/*
 ERR_CFG 
 b'Err msg en, stop on error'
*/
typedef struct reg_err_cfg {
	union {
		struct {
			uint32_t err_msg_en : 1,
				stop_on_err : 1,
				_reserved2 : 30;
		};
		uint32_t _raw;
	};
} reg_err_cfg;
static_assert((sizeof(struct reg_err_cfg) == 4), "reg_err_cfg size is not 32-bit");
/*
 ERR_CAUSE 
 b'Error cause'
*/
typedef struct reg_err_cause {
	union {
		struct {
			uint32_t hbw_rd_err : 1,
				hbw_wr_err : 1,
				lbw_msg_wr_err : 1,
				desc_ovf : 1,
				lbw_rd_err : 1,
				lbw_wr_err : 1,
				te_desc_fifo_ovfl : 1,
				lin_dma_commit_cfg_err : 1,
				_reserved8 : 24;
		};
		uint32_t _raw;
	};
} reg_err_cause;
static_assert((sizeof(struct reg_err_cause) == 4), "reg_err_cause size is not 32-bit");
/*
 ERRMSG_ADDR_LO 
 b'Error message address byte 3-0'
*/
typedef struct reg_errmsg_addr_lo {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_errmsg_addr_lo;
static_assert((sizeof(struct reg_errmsg_addr_lo) == 4), "reg_errmsg_addr_lo size is not 32-bit");
/*
 ERRMSG_ADDR_HI 
 b'Error message address byte 7-4'
*/
typedef struct reg_errmsg_addr_hi {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_errmsg_addr_hi;
static_assert((sizeof(struct reg_errmsg_addr_hi) == 4), "reg_errmsg_addr_hi size is not 32-bit");
/*
 ERRMSG_WDATA 
 b'Error message wdata to send'
*/
typedef struct reg_errmsg_wdata {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_errmsg_wdata;
static_assert((sizeof(struct reg_errmsg_wdata) == 4), "reg_errmsg_wdata size is not 32-bit");
/*
 STS0 
 b'BUSY and counters'
*/
typedef struct reg_sts0 {
	union {
		struct {
			uint32_t rd_req_cnt : 15,
				_reserved16 : 1,
				wr_req_cnt : 15,
				busy : 1;
		};
		uint32_t _raw;
	};
} reg_sts0;
static_assert((sizeof(struct reg_sts0) == 4), "reg_sts0 size is not 32-bit");
/*
 STS1 
 b'IS_STOP'
*/
typedef struct reg_sts1 {
	union {
		struct {
			uint32_t is_halt : 1,
				_reserved1 : 31;
		};
		uint32_t _raw;
	};
} reg_sts1;
static_assert((sizeof(struct reg_sts1) == 4), "reg_sts1 size is not 32-bit");
/*
 STS_RD_CTX_SEL 
 b'Current descriptor in process. select dim size sts'
*/
typedef struct reg_sts_rd_ctx_sel {
	union {
		struct {
			uint32_t val : 3,
				_reserved8 : 5,
				stride : 1,
				_reserved9 : 23;
		};
		uint32_t _raw;
	};
} reg_sts_rd_ctx_sel;
static_assert((sizeof(struct reg_sts_rd_ctx_sel) == 4), "reg_sts_rd_ctx_sel size is not 32-bit");
/*
 STS_RD_CTX_SIZE 
 b'Current desc. in process. dim size selected by sel'
*/
typedef struct reg_sts_rd_ctx_size {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_sts_rd_ctx_size;
static_assert((sizeof(struct reg_sts_rd_ctx_size) == 4), "reg_sts_rd_ctx_size size is not 32-bit");
/*
 STS_RD_CTX_BASE_LO 
 b'Current descriptor in process. base address 31:0'
*/
typedef struct reg_sts_rd_ctx_base_lo {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_sts_rd_ctx_base_lo;
static_assert((sizeof(struct reg_sts_rd_ctx_base_lo) == 4), "reg_sts_rd_ctx_base_lo size is not 32-bit");
/*
 STS_RD_CTX_BASE_HI 
 b'Current descriptor in process. base address 63:0'
*/
typedef struct reg_sts_rd_ctx_base_hi {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_sts_rd_ctx_base_hi;
static_assert((sizeof(struct reg_sts_rd_ctx_base_hi) == 4), "reg_sts_rd_ctx_base_hi size is not 32-bit");
/*
 STS_RD_CTX_ID 
 b'Current descriptor in process. Context ID'
*/
typedef struct reg_sts_rd_ctx_id {
	union {
		struct {
			uint32_t val : 16,
				_reserved16 : 16;
		};
		uint32_t _raw;
	};
} reg_sts_rd_ctx_id;
static_assert((sizeof(struct reg_sts_rd_ctx_id) == 4), "reg_sts_rd_ctx_id size is not 32-bit");
/*
 STS_RD_HB_AXI_ADDR_LO 
 b'Current AXI address 31:0'
*/
typedef struct reg_sts_rd_hb_axi_addr_lo {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_sts_rd_hb_axi_addr_lo;
static_assert((sizeof(struct reg_sts_rd_hb_axi_addr_lo) == 4), "reg_sts_rd_hb_axi_addr_lo size is not 32-bit");
/*
 STS_RD_HB_AXI_ADDR_HI 
 b'Current AXI address 49:32, valid,ready'
*/
typedef struct reg_sts_rd_hb_axi_addr_hi {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_sts_rd_hb_axi_addr_hi;
static_assert((sizeof(struct reg_sts_rd_hb_axi_addr_hi) == 4), "reg_sts_rd_hb_axi_addr_hi size is not 32-bit");
/*
 STS_RD_LB_AXI_ADDR 
 b'Current AXI address 25:0, valid,ready'
*/
typedef struct reg_sts_rd_lb_axi_addr {
	union {
		struct {
			uint32_t val : 26,
				_reserved30 : 4,
				rdy : 1,
				vld : 1;
		};
		uint32_t _raw;
	};
} reg_sts_rd_lb_axi_addr;
static_assert((sizeof(struct reg_sts_rd_lb_axi_addr) == 4), "reg_sts_rd_lb_axi_addr size is not 32-bit");
/*
 STS_WR_CTX_SEL 
 b'Current descriptor in process. select dim size sts'
*/
typedef struct reg_sts_wr_ctx_sel {
	union {
		struct {
			uint32_t val : 3,
				_reserved8 : 5,
				stride : 1,
				_reserved9 : 23;
		};
		uint32_t _raw;
	};
} reg_sts_wr_ctx_sel;
static_assert((sizeof(struct reg_sts_wr_ctx_sel) == 4), "reg_sts_wr_ctx_sel size is not 32-bit");
/*
 STS_WR_CTX_SIZE 
 b'Current desc. in process. dim size selected by sel'
*/
typedef struct reg_sts_wr_ctx_size {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_sts_wr_ctx_size;
static_assert((sizeof(struct reg_sts_wr_ctx_size) == 4), "reg_sts_wr_ctx_size size is not 32-bit");
/*
 STS_WR_CTX_BASE_LO 
 b'Current descriptor in process. base address 31:0'
*/
typedef struct reg_sts_wr_ctx_base_lo {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_sts_wr_ctx_base_lo;
static_assert((sizeof(struct reg_sts_wr_ctx_base_lo) == 4), "reg_sts_wr_ctx_base_lo size is not 32-bit");
/*
 STS_WR_CTX_BASE_HI 
 b'Current descriptor in process. base address 63:0'
*/
typedef struct reg_sts_wr_ctx_base_hi {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_sts_wr_ctx_base_hi;
static_assert((sizeof(struct reg_sts_wr_ctx_base_hi) == 4), "reg_sts_wr_ctx_base_hi size is not 32-bit");
/*
 STS_WR_CTX_ID 
 b'Current descriptor in process. Context ID'
*/
typedef struct reg_sts_wr_ctx_id {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_sts_wr_ctx_id;
static_assert((sizeof(struct reg_sts_wr_ctx_id) == 4), "reg_sts_wr_ctx_id size is not 32-bit");
/*
 STS_WR_HB_AXI_ADDR_LO 
 b'Current AXI address 31:0'
*/
typedef struct reg_sts_wr_hb_axi_addr_lo {
	union {
		struct {
			uint32_t val : 18,
				_reserved30 : 12,
				rdy : 1,
				vld : 1;
		};
		uint32_t _raw;
	};
} reg_sts_wr_hb_axi_addr_lo;
static_assert((sizeof(struct reg_sts_wr_hb_axi_addr_lo) == 4), "reg_sts_wr_hb_axi_addr_lo size is not 32-bit");
/*
 STS_WR_HB_AXI_ADDR_HI 
 b'Current AXI address 49:32, valid,ready'
*/
typedef struct reg_sts_wr_hb_axi_addr_hi {
	union {
		struct {
			uint32_t val : 18,
				_reserved30 : 12,
				rdy : 1,
				vld : 1;
		};
		uint32_t _raw;
	};
} reg_sts_wr_hb_axi_addr_hi;
static_assert((sizeof(struct reg_sts_wr_hb_axi_addr_hi) == 4), "reg_sts_wr_hb_axi_addr_hi size is not 32-bit");
/*
 STS_WR_LB_AXI_ADDR 
 b'Current AXI address 25:0, valid,ready'
*/
typedef struct reg_sts_wr_lb_axi_addr {
	union {
		struct {
			uint32_t val : 26,
				_reserved30 : 4,
				rdy : 1,
				vld : 1;
		};
		uint32_t _raw;
	};
} reg_sts_wr_lb_axi_addr;
static_assert((sizeof(struct reg_sts_wr_lb_axi_addr) == 4), "reg_sts_wr_lb_axi_addr size is not 32-bit");
/*
 PWRLP_CFG 
 b'power loop static config'
*/
typedef struct reg_pwrlp_cfg {
	union {
		struct {
			uint32_t glbl_en : 1,
				_reserved4 : 3,
				clr : 1,
				_reserved5 : 27;
		};
		uint32_t _raw;
	};
} reg_pwrlp_cfg;
static_assert((sizeof(struct reg_pwrlp_cfg) == 4), "reg_pwrlp_cfg size is not 32-bit");
/*
 PWRLP_STS 
 b'power loop status - fifos, counters'
*/
typedef struct reg_pwrlp_sts {
	union {
		struct {
			uint32_t rlvl : 7,
				_reserved8 : 1,
				wlvl : 7,
				_reserved16 : 1,
				rcnt : 7,
				wcnt : 7,
				rfull : 1,
				wfull : 1;
		};
		uint32_t _raw;
	};
} reg_pwrlp_sts;
static_assert((sizeof(struct reg_pwrlp_sts) == 4), "reg_pwrlp_sts size is not 32-bit");
/*
 DBG_DESC_CNT 
 b'Global cyclic read descriptor count for debug'
*/
typedef struct reg_dbg_desc_cnt {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_dbg_desc_cnt;
static_assert((sizeof(struct reg_dbg_desc_cnt) == 4), "reg_dbg_desc_cnt size is not 32-bit");
/*
 DBG_STS 
 b'FIFOs status etc'
*/
typedef struct reg_dbg_sts {
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
				rd_agu_cs : 1,
				wr_agu_cs : 1,
				_reserved12 : 20;
		};
		uint32_t _raw;
	};
} reg_dbg_sts;
static_assert((sizeof(struct reg_dbg_sts) == 4), "reg_dbg_sts size is not 32-bit");
/*
 DBG_BUF_STS 
 b'Buffer fullness'
*/
typedef struct reg_dbg_buf_sts {
	union {
		struct {
			uint32_t hbw_fullness : 12,
				_reserved16 : 4,
				lbw_fullness : 12,
				_reserved28 : 4;
		};
		uint32_t _raw;
	};
} reg_dbg_buf_sts;
static_assert((sizeof(struct reg_dbg_buf_sts) == 4), "reg_dbg_buf_sts size is not 32-bit");
/*
 DBG_RD_DESC_ID 
 b'Current RD descriptor ID'
*/
typedef struct reg_dbg_rd_desc_id {
	union {
		struct {
			uint32_t val : 16,
				_reserved16 : 16;
		};
		uint32_t _raw;
	};
} reg_dbg_rd_desc_id;
static_assert((sizeof(struct reg_dbg_rd_desc_id) == 4), "reg_dbg_rd_desc_id size is not 32-bit");
/*
 DBG_WR_DESC_ID 
 b'Current WR descriptor ID'
*/
typedef struct reg_dbg_wr_desc_id {
	union {
		struct {
			uint32_t val : 16,
				_reserved16 : 16;
		};
		uint32_t _raw;
	};
} reg_dbg_wr_desc_id;
static_assert((sizeof(struct reg_dbg_wr_desc_id) == 4), "reg_dbg_wr_desc_id size is not 32-bit");
/*
 APB_DMA_LBW_BASE 
 b'dma cfg base address used for apb forking'
*/
typedef struct reg_apb_dma_lbw_base {
	union {
		struct {
			uint32_t val : 16,
				_reserved16 : 16;
		};
		uint32_t _raw;
	};
} reg_apb_dma_lbw_base;
static_assert((sizeof(struct reg_apb_dma_lbw_base) == 4), "reg_apb_dma_lbw_base size is not 32-bit");
/*
 APB_MSTR_IF_LBW_BASE 
 b'mstr if cfg base address used for apb forking'
*/
typedef struct reg_apb_mstr_if_lbw_base {
	union {
		struct {
			uint32_t val : 16,
				_reserved16 : 16;
		};
		uint32_t _raw;
	};
} reg_apb_mstr_if_lbw_base;
static_assert((sizeof(struct reg_apb_mstr_if_lbw_base) == 4), "reg_apb_mstr_if_lbw_base size is not 32-bit");
/*
 E2E_CRED_ASYNC_CFG 
 b'e2e cred top async_cfg ports'
*/
typedef struct reg_e2e_cred_async_cfg {
	union {
		struct {
			uint32_t y_x_force : 9,
				force_en : 1,
				_reserved10 : 22;
		};
		uint32_t _raw;
	};
} reg_e2e_cred_async_cfg;
static_assert((sizeof(struct reg_e2e_cred_async_cfg) == 4), "reg_e2e_cred_async_cfg size is not 32-bit");
/*
 DBG_APB_ENABLER 
 b'Force DBG APB auto clock opener to always on'
*/
typedef struct reg_dbg_apb_enabler {
	union {
		struct {
			uint32_t dis : 1,
				_reserved1 : 31;
		};
		uint32_t _raw;
	};
} reg_dbg_apb_enabler;
static_assert((sizeof(struct reg_dbg_apb_enabler) == 4), "reg_dbg_apb_enabler size is not 32-bit");
/*
 L2H_CMPR_LO 
 b'L2H Addr mask bit 31 to 0 to selecet HBW over LBW'
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
 b'L2H Addr mask bit 63 to 32 to selecet HBW over LBW'
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
 L2H_MASK_LO 
 b'L2H Addr compare bit 31 to 0 to selecet HBW over L'
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
 b'L2H Addr compare bit 63 to 32 to selecet HBW over'
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
 IDLE_IND_MASK 
 b'option to mask idle indications'
*/
typedef struct reg_idle_ind_mask {
	union {
		struct {
			uint32_t desc : 1,
				comp : 1,
				instage : 1,
				core : 1,
				_reserved8 : 4,
				desc_cnt_sts : 5,
				_reserved16 : 3,
				comp_cnt_sts : 5,
				_reserved24 : 3,
				instage_empty : 1,
				core_idle_sts : 1,
				_reserved26 : 6;
		};
		uint32_t _raw;
	};
} reg_idle_ind_mask;
static_assert((sizeof(struct reg_idle_ind_mask) == 4), "reg_idle_ind_mask size is not 32-bit");
/*
 APB_ENABLER 
 b'Force APB auto clock opener to always on'
*/
typedef struct reg_apb_enabler {
	union {
		struct {
			uint32_t dis : 1,
				_reserved1 : 31;
		};
		uint32_t _raw;
	};
} reg_apb_enabler;
static_assert((sizeof(struct reg_apb_enabler) == 4), "reg_apb_enabler size is not 32-bit");

#ifdef __cplusplus
} /* dma_core namespace */
#endif

/*
 DMA_CORE block
*/

#ifdef __cplusplus

struct block_dma_core {
	struct dma_core::reg_cfg_0 cfg_0;
	struct dma_core::reg_cfg_1 cfg_1;
	struct dma_core::reg_prot prot;
	struct dma_core::reg_ckg ckg;
	uint32_t _pad16[27];
	struct dma_core::reg_rd_glbl rd_glbl;
	struct dma_core::reg_rd_hbw_max_outstand rd_hbw_max_outstand;
	struct dma_core::reg_rd_hbw_max_size rd_hbw_max_size;
	struct dma_core::reg_rd_hbw_arcache rd_hbw_arcache;
	uint32_t _pad140[1];
	struct dma_core::reg_rd_hbw_inflights rd_hbw_inflights;
	struct dma_core::reg_rd_hbw_rate_lim_cfg rd_hbw_rate_lim_cfg;
	uint32_t _pad152[10];
	struct dma_core::reg_rd_lbw_max_outstand rd_lbw_max_outstand;
	struct dma_core::reg_rd_lbw_max_size rd_lbw_max_size;
	struct dma_core::reg_rd_lbw_arcache rd_lbw_arcache;
	uint32_t _pad204[1];
	struct dma_core::reg_rd_lbw_inflights rd_lbw_inflights;
	struct dma_core::reg_rd_lbw_rate_lim_cfg rd_lbw_rate_lim_cfg;
	uint32_t _pad216[10];
	struct dma_core::reg_wr_hbw_max_outstand wr_hbw_max_outstand;
	struct dma_core::reg_wr_hbw_max_awid wr_hbw_max_awid;
	struct dma_core::reg_wr_hbw_awcache wr_hbw_awcache;
	struct dma_core::reg_wr_hbw_inflights wr_hbw_inflights;
	struct dma_core::reg_wr_hbw_rate_lim_cfg wr_hbw_rate_lim_cfg;
	uint32_t _pad276[11];
	struct dma_core::reg_wr_lbw_max_outstand wr_lbw_max_outstand;
	struct dma_core::reg_wr_lbw_max_awid wr_lbw_max_awid;
	struct dma_core::reg_wr_lbw_awcache wr_lbw_awcache;
	struct dma_core::reg_wr_lbw_inflights wr_lbw_inflights;
	struct dma_core::reg_wr_lbw_rate_lim_cfg wr_lbw_rate_lim_cfg;
	uint32_t _pad340[11];
	struct dma_core::reg_wr_comp_max_outstand wr_comp_max_outstand;
	struct dma_core::reg_wr_comp_awuser wr_comp_awuser;
	uint32_t _pad392[94];
	struct dma_core::reg_err_cfg err_cfg;
	struct dma_core::reg_err_cause err_cause;
	struct dma_core::reg_errmsg_addr_lo errmsg_addr_lo;
	struct dma_core::reg_errmsg_addr_hi errmsg_addr_hi;
	struct dma_core::reg_errmsg_wdata errmsg_wdata;
	uint32_t _pad788[27];
	struct dma_core::reg_sts0 sts0;
	struct dma_core::reg_sts1 sts1;
	uint32_t _pad904[30];
	struct dma_core::reg_sts_rd_ctx_sel sts_rd_ctx_sel;
	struct dma_core::reg_sts_rd_ctx_size sts_rd_ctx_size;
	struct dma_core::reg_sts_rd_ctx_base_lo sts_rd_ctx_base_lo;
	struct dma_core::reg_sts_rd_ctx_base_hi sts_rd_ctx_base_hi;
	struct dma_core::reg_sts_rd_ctx_id sts_rd_ctx_id;
	struct dma_core::reg_sts_rd_hb_axi_addr_lo sts_rd_hb_axi_addr_lo;
	struct dma_core::reg_sts_rd_hb_axi_addr_hi sts_rd_hb_axi_addr_hi;
	struct dma_core::reg_sts_rd_lb_axi_addr sts_rd_lb_axi_addr;
	struct dma_core::reg_sts_wr_ctx_sel sts_wr_ctx_sel;
	struct dma_core::reg_sts_wr_ctx_size sts_wr_ctx_size;
	struct dma_core::reg_sts_wr_ctx_base_lo sts_wr_ctx_base_lo;
	struct dma_core::reg_sts_wr_ctx_base_hi sts_wr_ctx_base_hi;
	struct dma_core::reg_sts_wr_ctx_id sts_wr_ctx_id;
	struct dma_core::reg_sts_wr_hb_axi_addr_lo sts_wr_hb_axi_addr_lo;
	struct dma_core::reg_sts_wr_hb_axi_addr_hi sts_wr_hb_axi_addr_hi;
	struct dma_core::reg_sts_wr_lb_axi_addr sts_wr_lb_axi_addr;
	uint32_t _pad1088[176];
	struct dma_core::reg_pwrlp_cfg pwrlp_cfg;
	struct dma_core::reg_pwrlp_sts pwrlp_sts;
	uint32_t _pad1800[2];
	struct dma_core::reg_dbg_desc_cnt dbg_desc_cnt;
	struct dma_core::reg_dbg_sts dbg_sts;
	struct dma_core::reg_dbg_buf_sts dbg_buf_sts;
	uint32_t _pad1820[1];
	struct dma_core::reg_dbg_rd_desc_id dbg_rd_desc_id;
	struct dma_core::reg_dbg_wr_desc_id dbg_wr_desc_id;
	struct dma_core::reg_apb_dma_lbw_base apb_dma_lbw_base;
	struct dma_core::reg_apb_mstr_if_lbw_base apb_mstr_if_lbw_base;
	struct dma_core::reg_e2e_cred_async_cfg e2e_cred_async_cfg;
	uint32_t _pad1844[51];
	struct block_axuser ctx_axuser;
	uint32_t _pad2128[4];
	struct block_dma_core_ctx ctx;
	uint32_t _pad2288[324];
	struct block_qman_cgm kdma_cgm;
	uint32_t _pad3596[4];
	struct dma_core::reg_dbg_apb_enabler dbg_apb_enabler;
	struct dma_core::reg_l2h_cmpr_lo l2h_cmpr_lo;
	struct dma_core::reg_l2h_cmpr_hi l2h_cmpr_hi;
	struct dma_core::reg_l2h_mask_lo l2h_mask_lo;
	struct dma_core::reg_l2h_mask_hi l2h_mask_hi;
	struct dma_core::reg_idle_ind_mask idle_ind_mask;
	struct dma_core::reg_apb_enabler apb_enabler;
	uint32_t _pad3640[18];
	struct block_special_regs special;
};
#else

typedef struct block_dma_core {
	reg_cfg_0 cfg_0;
	reg_cfg_1 cfg_1;
	reg_prot prot;
	reg_ckg ckg;
	uint32_t _pad16[27];
	reg_rd_glbl rd_glbl;
	reg_rd_hbw_max_outstand rd_hbw_max_outstand;
	reg_rd_hbw_max_size rd_hbw_max_size;
	reg_rd_hbw_arcache rd_hbw_arcache;
	uint32_t _pad140[1];
	reg_rd_hbw_inflights rd_hbw_inflights;
	reg_rd_hbw_rate_lim_cfg rd_hbw_rate_lim_cfg;
	uint32_t _pad152[10];
	reg_rd_lbw_max_outstand rd_lbw_max_outstand;
	reg_rd_lbw_max_size rd_lbw_max_size;
	reg_rd_lbw_arcache rd_lbw_arcache;
	uint32_t _pad204[1];
	reg_rd_lbw_inflights rd_lbw_inflights;
	reg_rd_lbw_rate_lim_cfg rd_lbw_rate_lim_cfg;
	uint32_t _pad216[10];
	reg_wr_hbw_max_outstand wr_hbw_max_outstand;
	reg_wr_hbw_max_awid wr_hbw_max_awid;
	reg_wr_hbw_awcache wr_hbw_awcache;
	reg_wr_hbw_inflights wr_hbw_inflights;
	reg_wr_hbw_rate_lim_cfg wr_hbw_rate_lim_cfg;
	uint32_t _pad276[11];
	reg_wr_lbw_max_outstand wr_lbw_max_outstand;
	reg_wr_lbw_max_awid wr_lbw_max_awid;
	reg_wr_lbw_awcache wr_lbw_awcache;
	reg_wr_lbw_inflights wr_lbw_inflights;
	reg_wr_lbw_rate_lim_cfg wr_lbw_rate_lim_cfg;
	uint32_t _pad340[11];
	reg_wr_comp_max_outstand wr_comp_max_outstand;
	reg_wr_comp_awuser wr_comp_awuser;
	uint32_t _pad392[94];
	reg_err_cfg err_cfg;
	reg_err_cause err_cause;
	reg_errmsg_addr_lo errmsg_addr_lo;
	reg_errmsg_addr_hi errmsg_addr_hi;
	reg_errmsg_wdata errmsg_wdata;
	uint32_t _pad788[27];
	reg_sts0 sts0;
	reg_sts1 sts1;
	uint32_t _pad904[30];
	reg_sts_rd_ctx_sel sts_rd_ctx_sel;
	reg_sts_rd_ctx_size sts_rd_ctx_size;
	reg_sts_rd_ctx_base_lo sts_rd_ctx_base_lo;
	reg_sts_rd_ctx_base_hi sts_rd_ctx_base_hi;
	reg_sts_rd_ctx_id sts_rd_ctx_id;
	reg_sts_rd_hb_axi_addr_lo sts_rd_hb_axi_addr_lo;
	reg_sts_rd_hb_axi_addr_hi sts_rd_hb_axi_addr_hi;
	reg_sts_rd_lb_axi_addr sts_rd_lb_axi_addr;
	reg_sts_wr_ctx_sel sts_wr_ctx_sel;
	reg_sts_wr_ctx_size sts_wr_ctx_size;
	reg_sts_wr_ctx_base_lo sts_wr_ctx_base_lo;
	reg_sts_wr_ctx_base_hi sts_wr_ctx_base_hi;
	reg_sts_wr_ctx_id sts_wr_ctx_id;
	reg_sts_wr_hb_axi_addr_lo sts_wr_hb_axi_addr_lo;
	reg_sts_wr_hb_axi_addr_hi sts_wr_hb_axi_addr_hi;
	reg_sts_wr_lb_axi_addr sts_wr_lb_axi_addr;
	uint32_t _pad1088[176];
	reg_pwrlp_cfg pwrlp_cfg;
	reg_pwrlp_sts pwrlp_sts;
	uint32_t _pad1800[2];
	reg_dbg_desc_cnt dbg_desc_cnt;
	reg_dbg_sts dbg_sts;
	reg_dbg_buf_sts dbg_buf_sts;
	uint32_t _pad1820[1];
	reg_dbg_rd_desc_id dbg_rd_desc_id;
	reg_dbg_wr_desc_id dbg_wr_desc_id;
	reg_apb_dma_lbw_base apb_dma_lbw_base;
	reg_apb_mstr_if_lbw_base apb_mstr_if_lbw_base;
	reg_e2e_cred_async_cfg e2e_cred_async_cfg;
	uint32_t _pad1844[51];
	block_axuser ctx_axuser;
	uint32_t _pad2128[4];
	block_dma_core_ctx ctx;
	uint32_t _pad2288[324];
	block_qman_cgm kdma_cgm;
	uint32_t _pad3596[4];
	reg_dbg_apb_enabler dbg_apb_enabler;
	reg_l2h_cmpr_lo l2h_cmpr_lo;
	reg_l2h_cmpr_hi l2h_cmpr_hi;
	reg_l2h_mask_lo l2h_mask_lo;
	reg_l2h_mask_hi l2h_mask_hi;
	reg_idle_ind_mask idle_ind_mask;
	reg_apb_enabler apb_enabler;
	uint32_t _pad3640[18];
	block_special_regs special;
} block_dma_core;
#endif

const offsetVal block_dma_core_defaults[] =
{
	// offset	// value
	{ 0x104 , 0x3fff              , 1 }, // wr_hbw_max_awid
	{ 0x110 , 0x80040003          , 1 }, // wr_hbw_rate_lim_cfg
	{ 0x144 , 0x7f                , 1 }, // wr_lbw_max_awid
	{ 0x180 , 0x14                , 1 }, // wr_comp_max_outstand
	{ 0x41c , 0x40000000          , 1 }, // sts_rd_lb_axi_addr
	{ 0x434 , 0x40000000          , 1 }, // sts_wr_hb_axi_addr_lo
	{ 0x438 , 0x40000000          , 1 }, // sts_wr_hb_axi_addr_hi
	{ 0x43c , 0x40000000          , 1 }, // sts_wr_lb_axi_addr
	{ 0x714 , 0x178               , 1 }, // dbg_sts
	{ 0x728 , 0xb000              , 1 }, // apb_dma_lbw_base
	{ 0x72c , 0xc000              , 1 }, // apb_mstr_if_lbw_base
	{ 0x804 , 0x11                , 1 }, // hb_mmu_bp
	{ 0x808 , 0x11                , 1 }, // hb_strong_order
	{ 0x820 , 0x11                , 1 }, // hb_emem_cpage
	{ 0x830 , 0xffffffff          , 1 }, // hb_wr_ovrd_lo
	{ 0x834 , 0x3ff               , 1 }, // hb_wr_ovrd_hi
	{ 0x838 , 0xffffffff          , 1 }, // hb_rd_ovrd_lo
	{ 0x83c , 0x3ff               , 1 }, // hb_rd_ovrd_hi
	{ 0x84c , 0xffffffff          , 1 }, // lb_ovrd
	{ 0x860 , 0x40004             , 1 }, // rate_lim_tkn
	{ 0xe00 , 0x100080            , 1 }, // cfg
	{ 0xe04 , 0xf00               , 1 }, // sts
	{ 0xe08 , 0x10                , 1 }, // cfg1
	{ 0xe20 , 0xfc000000          , 1 }, // l2h_cmpr_lo
	{ 0xe24 , 0x1000007f          , 1 }, // l2h_cmpr_hi
	{ 0xe28 , 0xfc000000          , 1 }, // l2h_mask_lo
	{ 0xe2c , 0xffffffff          , 1 }, // l2h_mask_hi
	{ 0xe30 , 0x3000000           , 1 }, // idle_ind_mask
	{ 0xe80 , 0xffffffff          , 32 }, // glbl_priv
	{ 0xf24 , 0xffff              , 1 }, // mem_ecc_err_addr
	{ 0xf44 , 0xffffffff          , 1 }, // glbl_err_addr
	{ 0xf80 , 0xffffffff          , 32 }, // glbl_sec
};

#ifdef __cplusplus
} /* gaudi2 namespace */
#endif

#pragma pack(pop)
#endif /* ASIC_REG_STRUCTS_DMA_CORE_H_ */
