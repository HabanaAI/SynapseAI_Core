/***********************************
** This is an auto-generated file **
**       DO NOT EDIT BELOW        **
************************************/

#ifndef ASIC_REG_STRUCTS_IC_LBW_DBG_CNT_H_
#define ASIC_REG_STRUCTS_IC_LBW_DBG_CNT_H_

#include <stdint.h>
#include "gaudi2_types.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace gaudi2 {
namespace ic_lbw_dbg_cnt {
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
 BP_AW_CNT 
 b'WR req address phase (AW) backpressure counter'
*/
typedef struct reg_bp_aw_cnt {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_bp_aw_cnt;
static_assert((sizeof(struct reg_bp_aw_cnt) == 4), "reg_bp_aw_cnt size is not 32-bit");
/*
 BP_W_CNT 
 b'WR req data phase (W) backpressure counter'
*/
typedef struct reg_bp_w_cnt {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_bp_w_cnt;
static_assert((sizeof(struct reg_bp_w_cnt) == 4), "reg_bp_w_cnt size is not 32-bit");
/*
 BP_AR_CNT 
 b'RD req address phase (AR) backpressure counter'
*/
typedef struct reg_bp_ar_cnt {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_bp_ar_cnt;
static_assert((sizeof(struct reg_bp_ar_cnt) == 4), "reg_bp_ar_cnt size is not 32-bit");
/*
 BP_B_CNT 
 b'WR rsp (B) backpressure counter'
*/
typedef struct reg_bp_b_cnt {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_bp_b_cnt;
static_assert((sizeof(struct reg_bp_b_cnt) == 4), "reg_bp_b_cnt size is not 32-bit");
/*
 BP_R_CNT 
 b'RD rsp (B) backpressure counter'
*/
typedef struct reg_bp_r_cnt {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_bp_r_cnt;
static_assert((sizeof(struct reg_bp_r_cnt) == 4), "reg_bp_r_cnt size is not 32-bit");
/*
 TRAN_AW_CNT 
 b'Count outgoing AXI write transactions'
*/
typedef struct reg_tran_aw_cnt {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_tran_aw_cnt;
static_assert((sizeof(struct reg_tran_aw_cnt) == 4), "reg_tran_aw_cnt size is not 32-bit");
/*
 TRAN_W_CNT 
 b'Count outgoing AXI write transactions (only LAST)'
*/
typedef struct reg_tran_w_cnt {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_tran_w_cnt;
static_assert((sizeof(struct reg_tran_w_cnt) == 4), "reg_tran_w_cnt size is not 32-bit");
/*
 TRAN_AR_CNT 
 b'Count outgoing AXI read transactions'
*/
typedef struct reg_tran_ar_cnt {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_tran_ar_cnt;
static_assert((sizeof(struct reg_tran_ar_cnt) == 4), "reg_tran_ar_cnt size is not 32-bit");
/*
 TRAN_B_CNT 
 b'Count incoming AXI write completions'
*/
typedef struct reg_tran_b_cnt {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_tran_b_cnt;
static_assert((sizeof(struct reg_tran_b_cnt) == 4), "reg_tran_b_cnt size is not 32-bit");
/*
 TRAN_R_CNT 
 b'Count incoming AXI read completions'
*/
typedef struct reg_tran_r_cnt {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_tran_r_cnt;
static_assert((sizeof(struct reg_tran_r_cnt) == 4), "reg_tran_r_cnt size is not 32-bit");
/*
 OTF_WR_TOTAL_CNT 
 b'Outstanding write request counter'
*/
typedef struct reg_otf_wr_total_cnt {
	union {
		struct {
			uint32_t val : 16,
				_reserved16 : 16;
		};
		uint32_t _raw;
	};
} reg_otf_wr_total_cnt;
static_assert((sizeof(struct reg_otf_wr_total_cnt) == 4), "reg_otf_wr_total_cnt size is not 32-bit");
/*
 OTF_RD_TOTAL_CNT 
 b'Outstanding read request counter'
*/
typedef struct reg_otf_rd_total_cnt {
	union {
		struct {
			uint32_t val : 16,
				_reserved16 : 16;
		};
		uint32_t _raw;
	};
} reg_otf_rd_total_cnt;
static_assert((sizeof(struct reg_otf_rd_total_cnt) == 4), "reg_otf_rd_total_cnt size is not 32-bit");
/*
 OTF_OVER_TH_WR_TOTAL_REQ_CNT 
 b'Count WR req when OTF is higher than threshold'
*/
typedef struct reg_otf_over_th_wr_total_req_cnt {
	union {
		struct {
			uint32_t val : 16,
				_reserved16 : 16;
		};
		uint32_t _raw;
	};
} reg_otf_over_th_wr_total_req_cnt;
static_assert((sizeof(struct reg_otf_over_th_wr_total_req_cnt) == 4), "reg_otf_over_th_wr_total_req_cnt size is not 32-bit");
/*
 OTF_OVER_TH_RD_TOTAL_REQ_CNT 
 b'Count RD req when OTF is higher than threshold'
*/
typedef struct reg_otf_over_th_rd_total_req_cnt {
	union {
		struct {
			uint32_t val : 16,
				_reserved16 : 16;
		};
		uint32_t _raw;
	};
} reg_otf_over_th_rd_total_req_cnt;
static_assert((sizeof(struct reg_otf_over_th_rd_total_req_cnt) == 4), "reg_otf_over_th_rd_total_req_cnt size is not 32-bit");
/*
 OTF_OVER_TH_WR_TOTAL_CYC_CNT 
 b'Count cycles when OTF is higher than threshold'
*/
typedef struct reg_otf_over_th_wr_total_cyc_cnt {
	union {
		struct {
			uint32_t val : 16,
				_reserved16 : 16;
		};
		uint32_t _raw;
	};
} reg_otf_over_th_wr_total_cyc_cnt;
static_assert((sizeof(struct reg_otf_over_th_wr_total_cyc_cnt) == 4), "reg_otf_over_th_wr_total_cyc_cnt size is not 32-bit");
/*
 OTF_OVER_TH_RD_TOTAL_CYC_CNT 
 b'Count cycles when OTF is higher than threshold'
*/
typedef struct reg_otf_over_th_rd_total_cyc_cnt {
	union {
		struct {
			uint32_t val : 16,
				_reserved16 : 16;
		};
		uint32_t _raw;
	};
} reg_otf_over_th_rd_total_cyc_cnt;
static_assert((sizeof(struct reg_otf_over_th_rd_total_cyc_cnt) == 4), "reg_otf_over_th_rd_total_cyc_cnt size is not 32-bit");
/*
 OTF_OVER_TH_WR_TOTAL_REQ_TH 
 b'Threshold for outstanding requests counter'
*/
typedef struct reg_otf_over_th_wr_total_req_th {
	union {
		struct {
			uint32_t val : 16,
				_reserved16 : 16;
		};
		uint32_t _raw;
	};
} reg_otf_over_th_wr_total_req_th;
static_assert((sizeof(struct reg_otf_over_th_wr_total_req_th) == 4), "reg_otf_over_th_wr_total_req_th size is not 32-bit");
/*
 OTF_OVER_TH_RD_TOTAL_REQ_TH 
 b'Threshold for outstanding requests counter'
*/
typedef struct reg_otf_over_th_rd_total_req_th {
	union {
		struct {
			uint32_t val : 16,
				_reserved16 : 16;
		};
		uint32_t _raw;
	};
} reg_otf_over_th_rd_total_req_th;
static_assert((sizeof(struct reg_otf_over_th_rd_total_req_th) == 4), "reg_otf_over_th_rd_total_req_th size is not 32-bit");
/*
 OTF_OVER_TH_WR_TOTAL_CYC_TH 
 b'Threshold for outstanding cycles counter'
*/
typedef struct reg_otf_over_th_wr_total_cyc_th {
	union {
		struct {
			uint32_t val : 16,
				_reserved16 : 16;
		};
		uint32_t _raw;
	};
} reg_otf_over_th_wr_total_cyc_th;
static_assert((sizeof(struct reg_otf_over_th_wr_total_cyc_th) == 4), "reg_otf_over_th_wr_total_cyc_th size is not 32-bit");
/*
 OTF_OVER_TH_RD_TOTAL_CYC_TH 
 b'Threshold for outstanding cycles counter'
*/
typedef struct reg_otf_over_th_rd_total_cyc_th {
	union {
		struct {
			uint32_t val : 16,
				_reserved16 : 16;
		};
		uint32_t _raw;
	};
} reg_otf_over_th_rd_total_cyc_th;
static_assert((sizeof(struct reg_otf_over_th_rd_total_cyc_th) == 4), "reg_otf_over_th_rd_total_cyc_th size is not 32-bit");
/*
 OTF_CNT_DEST_SEL 
 b'Select which destination to present on OTF counter'
*/
typedef struct reg_otf_cnt_dest_sel {
	union {
		struct {
			uint32_t val : 3,
				_reserved3 : 29;
		};
		uint32_t _raw;
	};
} reg_otf_cnt_dest_sel;
static_assert((sizeof(struct reg_otf_cnt_dest_sel) == 4), "reg_otf_cnt_dest_sel size is not 32-bit");
/*
 DBG_EN 
 b'Enable debug counters'
*/
typedef struct reg_dbg_en {
	union {
		struct {
			uint32_t val : 1,
				_reserved1 : 31;
		};
		uint32_t _raw;
	};
} reg_dbg_en;
static_assert((sizeof(struct reg_dbg_en) == 4), "reg_dbg_en size is not 32-bit");

#ifdef __cplusplus
} /* ic_lbw_dbg_cnt namespace */
#endif

/*
 IC_LBW_DBG_CNT block
*/

#ifdef __cplusplus

struct block_ic_lbw_dbg_cnt {
	struct ic_lbw_dbg_cnt::reg_bp_aw_cnt bp_aw_cnt;
	struct ic_lbw_dbg_cnt::reg_bp_w_cnt bp_w_cnt;
	struct ic_lbw_dbg_cnt::reg_bp_ar_cnt bp_ar_cnt;
	struct ic_lbw_dbg_cnt::reg_bp_b_cnt bp_b_cnt;
	struct ic_lbw_dbg_cnt::reg_bp_r_cnt bp_r_cnt;
	struct ic_lbw_dbg_cnt::reg_tran_aw_cnt tran_aw_cnt;
	struct ic_lbw_dbg_cnt::reg_tran_w_cnt tran_w_cnt;
	struct ic_lbw_dbg_cnt::reg_tran_ar_cnt tran_ar_cnt;
	struct ic_lbw_dbg_cnt::reg_tran_b_cnt tran_b_cnt;
	struct ic_lbw_dbg_cnt::reg_tran_r_cnt tran_r_cnt;
	struct ic_lbw_dbg_cnt::reg_otf_wr_total_cnt otf_wr_total_cnt;
	struct ic_lbw_dbg_cnt::reg_otf_rd_total_cnt otf_rd_total_cnt;
	struct ic_lbw_dbg_cnt::reg_otf_over_th_wr_total_req_cnt otf_over_th_wr_total_req_cnt;
	struct ic_lbw_dbg_cnt::reg_otf_over_th_rd_total_req_cnt otf_over_th_rd_total_req_cnt;
	struct ic_lbw_dbg_cnt::reg_otf_over_th_wr_total_cyc_cnt otf_over_th_wr_total_cyc_cnt;
	struct ic_lbw_dbg_cnt::reg_otf_over_th_rd_total_cyc_cnt otf_over_th_rd_total_cyc_cnt;
	struct ic_lbw_dbg_cnt::reg_otf_over_th_wr_total_req_th otf_over_th_wr_total_req_th;
	struct ic_lbw_dbg_cnt::reg_otf_over_th_rd_total_req_th otf_over_th_rd_total_req_th;
	struct ic_lbw_dbg_cnt::reg_otf_over_th_wr_total_cyc_th otf_over_th_wr_total_cyc_th;
	struct ic_lbw_dbg_cnt::reg_otf_over_th_rd_total_cyc_th otf_over_th_rd_total_cyc_th;
	struct ic_lbw_dbg_cnt::reg_otf_cnt_dest_sel otf_cnt_dest_sel;
	struct ic_lbw_dbg_cnt::reg_dbg_en dbg_en;
};
#else

typedef struct block_ic_lbw_dbg_cnt {
	reg_bp_aw_cnt bp_aw_cnt;
	reg_bp_w_cnt bp_w_cnt;
	reg_bp_ar_cnt bp_ar_cnt;
	reg_bp_b_cnt bp_b_cnt;
	reg_bp_r_cnt bp_r_cnt;
	reg_tran_aw_cnt tran_aw_cnt;
	reg_tran_w_cnt tran_w_cnt;
	reg_tran_ar_cnt tran_ar_cnt;
	reg_tran_b_cnt tran_b_cnt;
	reg_tran_r_cnt tran_r_cnt;
	reg_otf_wr_total_cnt otf_wr_total_cnt;
	reg_otf_rd_total_cnt otf_rd_total_cnt;
	reg_otf_over_th_wr_total_req_cnt otf_over_th_wr_total_req_cnt;
	reg_otf_over_th_rd_total_req_cnt otf_over_th_rd_total_req_cnt;
	reg_otf_over_th_wr_total_cyc_cnt otf_over_th_wr_total_cyc_cnt;
	reg_otf_over_th_rd_total_cyc_cnt otf_over_th_rd_total_cyc_cnt;
	reg_otf_over_th_wr_total_req_th otf_over_th_wr_total_req_th;
	reg_otf_over_th_rd_total_req_th otf_over_th_rd_total_req_th;
	reg_otf_over_th_wr_total_cyc_th otf_over_th_wr_total_cyc_th;
	reg_otf_over_th_rd_total_cyc_th otf_over_th_rd_total_cyc_th;
	reg_otf_cnt_dest_sel otf_cnt_dest_sel;
	reg_dbg_en dbg_en;
} block_ic_lbw_dbg_cnt;
#endif

const offsetVal block_ic_lbw_dbg_cnt_defaults[] =
{
	// offset	// value
	{ 0x40  , 0x100               , 1 }, // otf_over_th_wr_total_req_th
	{ 0x44  , 0x100               , 1 }, // otf_over_th_rd_total_req_th
	{ 0x48  , 0x100               , 1 }, // otf_over_th_wr_total_cyc_th
	{ 0x4c  , 0x100               , 1 }, // otf_over_th_rd_total_cyc_th
};

#ifdef __cplusplus
} /* gaudi2 namespace */
#endif

#pragma pack(pop)
#endif /* ASIC_REG_STRUCTS_IC_LBW_DBG_CNT_H_ */
