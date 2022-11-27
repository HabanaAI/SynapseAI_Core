/***********************************
** This is an auto-generated file **
**       DO NOT EDIT BELOW        **
************************************/

#ifndef ASIC_REG_STRUCTS_AXUSER_H_
#define ASIC_REG_STRUCTS_AXUSER_H_

#include <stdint.h>
#include "gaudi2_types.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace gaudi2 {
namespace axuser {
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
 HB_ASID 
 b'HBW ASID'
*/
typedef struct reg_hb_asid {
	union {
		struct {
			uint32_t wr : 10,
				_reserved16 : 6,
				rd : 10,
				_reserved26 : 6;
		};
		uint32_t _raw;
	};
} reg_hb_asid;
static_assert((sizeof(struct reg_hb_asid) == 4), "reg_hb_asid size is not 32-bit");
/*
 HB_MMU_BP 
 b'HBW MMU bypass'
*/
typedef struct reg_hb_mmu_bp {
	union {
		struct {
			uint32_t wr : 1,
				_reserved4 : 3,
				rd : 1,
				_reserved5 : 27;
		};
		uint32_t _raw;
	};
} reg_hb_mmu_bp;
static_assert((sizeof(struct reg_hb_mmu_bp) == 4), "reg_hb_mmu_bp size is not 32-bit");
/*
 HB_STRONG_ORDER 
 b'HBW Strong Order'
*/
typedef struct reg_hb_strong_order {
	union {
		struct {
			uint32_t wr : 1,
				_reserved4 : 3,
				rd : 1,
				_reserved5 : 27;
		};
		uint32_t _raw;
	};
} reg_hb_strong_order;
static_assert((sizeof(struct reg_hb_strong_order) == 4), "reg_hb_strong_order size is not 32-bit");
/*
 HB_NO_SNOOP 
 b'HBW NO_SNOOP'
*/
typedef struct reg_hb_no_snoop {
	union {
		struct {
			uint32_t wr : 1,
				_reserved4 : 3,
				rd : 1,
				_reserved5 : 27;
		};
		uint32_t _raw;
	};
} reg_hb_no_snoop;
static_assert((sizeof(struct reg_hb_no_snoop) == 4), "reg_hb_no_snoop size is not 32-bit");
/*
 HB_WR_REDUCTION 
 b'HBW Reduction operators'
*/
typedef struct reg_hb_wr_reduction {
	union {
		struct {
			uint32_t ind : 1,
				_reserved4 : 3,
				dtype : 4,
				op : 2,
				_reserved12 : 2,
				round : 2,
				_reserved16 : 2,
				max : 1,
				_reserved17 : 15;
		};
		uint32_t _raw;
	};
} reg_hb_wr_reduction;
static_assert((sizeof(struct reg_hb_wr_reduction) == 4), "reg_hb_wr_reduction size is not 32-bit");
/*
 HB_RD_ATOMIC 
 b'HBW Read atomic'
*/
typedef struct reg_hb_rd_atomic {
	union {
		struct {
			uint32_t ind : 2,
				_reserved4 : 2,
				addition_size : 8,
				msb_mask : 5,
				_reserved17 : 15;
		};
		uint32_t _raw;
	};
} reg_hb_rd_atomic;
static_assert((sizeof(struct reg_hb_rd_atomic) == 4), "reg_hb_rd_atomic size is not 32-bit");
/*
 HB_QOS 
 b'HBW Quality of service for HBM'
*/
typedef struct reg_hb_qos {
	union {
		struct {
			uint32_t wr : 4,
				rd : 3,
				_reserved7 : 25;
		};
		uint32_t _raw;
	};
} reg_hb_qos;
static_assert((sizeof(struct reg_hb_qos) == 4), "reg_hb_qos size is not 32-bit");
/*
 HB_RSVD 
 b'HBW reserved fields of user bus'
*/
typedef struct reg_hb_rsvd {
	union {
		struct {
			uint32_t wr_bit_27 : 1,
				wr_bit_28 : 1,
				wr_bit_30 : 1,
				wr_bit_31 : 1,
				_reserved4 : 28;
		};
		uint32_t _raw;
	};
} reg_hb_rsvd;
static_assert((sizeof(struct reg_hb_rsvd) == 4), "reg_hb_rsvd size is not 32-bit");
/*
 HB_EMEM_CPAGE 
 b'HBW HBM Mode close page'
*/
typedef struct reg_hb_emem_cpage {
	union {
		struct {
			uint32_t wr : 1,
				_reserved4 : 3,
				rd : 1,
				_reserved5 : 27;
		};
		uint32_t _raw;
	};
} reg_hb_emem_cpage;
static_assert((sizeof(struct reg_hb_emem_cpage) == 4), "reg_hb_emem_cpage size is not 32-bit");
/*
 HB_CORE 
 b'HBW Coreherency load lock (or store unlock)'
*/
typedef struct reg_hb_core {
	union {
		struct {
			uint32_t wr : 1,
				_reserved4 : 3,
				rd : 1,
				_reserved5 : 27;
		};
		uint32_t _raw;
	};
} reg_hb_core;
static_assert((sizeof(struct reg_hb_core) == 4), "reg_hb_core size is not 32-bit");
/*
 E2E_COORD 
 b'HBW and LBW E2E coordinates'
*/
typedef struct reg_e2e_coord {
	union {
		struct {
			uint32_t x : 5,
				_reserved8 : 3,
				y : 4,
				_reserved12 : 20;
		};
		uint32_t _raw;
	};
} reg_e2e_coord;
static_assert((sizeof(struct reg_e2e_coord) == 4), "reg_e2e_coord size is not 32-bit");
/*
 HB_WR_OVRD_LO 
 b'HBM AWUSER override config[31:0]'
*/
typedef struct reg_hb_wr_ovrd_lo {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_hb_wr_ovrd_lo;
static_assert((sizeof(struct reg_hb_wr_ovrd_lo) == 4), "reg_hb_wr_ovrd_lo size is not 32-bit");
/*
 HB_WR_OVRD_HI 
 b'HBM AWUSER override config[41:32]'
*/
typedef struct reg_hb_wr_ovrd_hi {
	union {
		struct {
			uint32_t val : 10,
				_reserved10 : 22;
		};
		uint32_t _raw;
	};
} reg_hb_wr_ovrd_hi;
static_assert((sizeof(struct reg_hb_wr_ovrd_hi) == 4), "reg_hb_wr_ovrd_hi size is not 32-bit");
/*
 HB_RD_OVRD_LO 
 b'HBM ARUSER override config[31:0]'
*/
typedef struct reg_hb_rd_ovrd_lo {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_hb_rd_ovrd_lo;
static_assert((sizeof(struct reg_hb_rd_ovrd_lo) == 4), "reg_hb_rd_ovrd_lo size is not 32-bit");
/*
 HB_RD_OVRD_HI 
 b'HBM ARUSER override config[41:32]'
*/
typedef struct reg_hb_rd_ovrd_hi {
	union {
		struct {
			uint32_t val : 10,
				_reserved10 : 22;
		};
		uint32_t _raw;
	};
} reg_hb_rd_ovrd_hi;
static_assert((sizeof(struct reg_hb_rd_ovrd_hi) == 4), "reg_hb_rd_ovrd_hi size is not 32-bit");
/*
 LB_COORD 
 b'LBW RAZWI coordinates'
*/
typedef struct reg_lb_coord {
	union {
		struct {
			uint32_t val : 10,
				_reserved10 : 22;
		};
		uint32_t _raw;
	};
} reg_lb_coord;
static_assert((sizeof(struct reg_lb_coord) == 4), "reg_lb_coord size is not 32-bit");
/*
 LB_LOCK 
 b'LBW TPC Lock indication'
*/
typedef struct reg_lb_lock {
	union {
		struct {
			uint32_t val : 1,
				_reserved1 : 31;
		};
		uint32_t _raw;
	};
} reg_lb_lock;
static_assert((sizeof(struct reg_lb_lock) == 4), "reg_lb_lock size is not 32-bit");
/*
 LB_RSVD 
 b'LBW Reserved'
*/
typedef struct reg_lb_rsvd {
	union {
		struct {
			uint32_t bit_21_11 : 11,
				_reserved12 : 1,
				bit_22 : 1,
				_reserved13 : 19;
		};
		uint32_t _raw;
	};
} reg_lb_rsvd;
static_assert((sizeof(struct reg_lb_rsvd) == 4), "reg_lb_rsvd size is not 32-bit");
/*
 LB_OVRD 
 b'LBW AxUSER override config'
*/
typedef struct reg_lb_ovrd {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_lb_ovrd;
static_assert((sizeof(struct reg_lb_ovrd) == 4), "reg_lb_ovrd size is not 32-bit");

#ifdef __cplusplus
} /* axuser namespace */
#endif

/*
 AXUSER block
*/

#ifdef __cplusplus

struct block_axuser {
	struct axuser::reg_hb_asid hb_asid;
	struct axuser::reg_hb_mmu_bp hb_mmu_bp;
	struct axuser::reg_hb_strong_order hb_strong_order;
	struct axuser::reg_hb_no_snoop hb_no_snoop;
	struct axuser::reg_hb_wr_reduction hb_wr_reduction;
	struct axuser::reg_hb_rd_atomic hb_rd_atomic;
	struct axuser::reg_hb_qos hb_qos;
	struct axuser::reg_hb_rsvd hb_rsvd;
	struct axuser::reg_hb_emem_cpage hb_emem_cpage;
	struct axuser::reg_hb_core hb_core;
	struct axuser::reg_e2e_coord e2e_coord;
	uint32_t _pad44[1];
	struct axuser::reg_hb_wr_ovrd_lo hb_wr_ovrd_lo;
	struct axuser::reg_hb_wr_ovrd_hi hb_wr_ovrd_hi;
	struct axuser::reg_hb_rd_ovrd_lo hb_rd_ovrd_lo;
	struct axuser::reg_hb_rd_ovrd_hi hb_rd_ovrd_hi;
	struct axuser::reg_lb_coord lb_coord;
	struct axuser::reg_lb_lock lb_lock;
	struct axuser::reg_lb_rsvd lb_rsvd;
	struct axuser::reg_lb_ovrd lb_ovrd;
};
#else

typedef struct block_axuser {
	reg_hb_asid hb_asid;
	reg_hb_mmu_bp hb_mmu_bp;
	reg_hb_strong_order hb_strong_order;
	reg_hb_no_snoop hb_no_snoop;
	reg_hb_wr_reduction hb_wr_reduction;
	reg_hb_rd_atomic hb_rd_atomic;
	reg_hb_qos hb_qos;
	reg_hb_rsvd hb_rsvd;
	reg_hb_emem_cpage hb_emem_cpage;
	reg_hb_core hb_core;
	reg_e2e_coord e2e_coord;
	uint32_t _pad44[1];
	reg_hb_wr_ovrd_lo hb_wr_ovrd_lo;
	reg_hb_wr_ovrd_hi hb_wr_ovrd_hi;
	reg_hb_rd_ovrd_lo hb_rd_ovrd_lo;
	reg_hb_rd_ovrd_hi hb_rd_ovrd_hi;
	reg_lb_coord lb_coord;
	reg_lb_lock lb_lock;
	reg_lb_rsvd lb_rsvd;
	reg_lb_ovrd lb_ovrd;
} block_axuser;
#endif

const offsetVal block_axuser_defaults[] =
{
	// offset	// value
	{ 0x4   , 0x11                , 1 }, // hb_mmu_bp
	{ 0x8   , 0x11                , 1 }, // hb_strong_order
	{ 0x20  , 0x11                , 1 }, // hb_emem_cpage
	{ 0x30  , 0xffffffff          , 1 }, // hb_wr_ovrd_lo
	{ 0x34  , 0x3ff               , 1 }, // hb_wr_ovrd_hi
	{ 0x38  , 0xffffffff          , 1 }, // hb_rd_ovrd_lo
	{ 0x3c  , 0x3ff               , 1 }, // hb_rd_ovrd_hi
	{ 0x4c  , 0xffffffff          , 1 }, // lb_ovrd
};

#ifdef __cplusplus
} /* gaudi2 namespace */
#endif

#pragma pack(pop)
#endif /* ASIC_REG_STRUCTS_AXUSER_H_ */
