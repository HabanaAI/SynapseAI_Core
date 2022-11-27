/***********************************
** This is an auto-generated file **
**       DO NOT EDIT BELOW        **
************************************/

#ifndef ASIC_REG_STRUCTS_SPECIAL_REGS_H_
#define ASIC_REG_STRUCTS_SPECIAL_REGS_H_

#include <stdint.h>
#include "gaudi2_types.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace gaudi2 {
namespace special_regs {
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
 GLBL_PRIV 
 b'Privilege configuration'
*/
typedef struct reg_glbl_priv {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_glbl_priv;
static_assert((sizeof(struct reg_glbl_priv) == 4), "reg_glbl_priv size is not 32-bit");
/*
 MEM_GW_DATA 
 b'Memory gateway read/write data'
*/
typedef struct reg_mem_gw_data {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_mem_gw_data;
static_assert((sizeof(struct reg_mem_gw_data) == 4), "reg_mem_gw_data size is not 32-bit");
/*
 MEM_GW_REQ 
 b'Memory gateway configuration and address'
*/
typedef struct reg_mem_gw_req {
	union {
		struct {
			uint32_t addr : 22,
				mid : 8,
				wnr : 1,
				vld : 1;
		};
		uint32_t _raw;
	};
} reg_mem_gw_req;
static_assert((sizeof(struct reg_mem_gw_req) == 4), "reg_mem_gw_req size is not 32-bit");
/*
 MEM_NUMOF 
 b'Number of memories of the block'
*/
typedef struct reg_mem_numof {
	union {
		struct {
			uint32_t val : 8,
				_reserved8 : 24;
		};
		uint32_t _raw;
	};
} reg_mem_numof;
static_assert((sizeof(struct reg_mem_numof) == 4), "reg_mem_numof size is not 32-bit");
/*
 MEM_ECC_SEL 
 b'Select memory to access regarding init or ecc'
*/
typedef struct reg_mem_ecc_sel {
	union {
		struct {
			uint32_t val : 8,
				_reserved8 : 24;
		};
		uint32_t _raw;
	};
} reg_mem_ecc_sel;
static_assert((sizeof(struct reg_mem_ecc_sel) == 4), "reg_mem_ecc_sel size is not 32-bit");
/*
 MEM_ECC_CTL 
 b'Memory control ECC_INJ ECC_CLR'
*/
typedef struct reg_mem_ecc_ctl {
	union {
		struct {
			uint32_t serr_inj : 1,
				derr_inj : 1,
				serr_clr : 1,
				derr_clr : 1,
				_reserved4 : 28;
		};
		uint32_t _raw;
	};
} reg_mem_ecc_ctl;
static_assert((sizeof(struct reg_mem_ecc_ctl) == 4), "reg_mem_ecc_ctl size is not 32-bit");
/*
 MEM_ECC_ERR_MASK 
 b'SERR DERR mask per memory'
*/
typedef struct reg_mem_ecc_err_mask {
	union {
		struct {
			uint32_t serr : 1,
				derr : 1,
				_reserved2 : 30;
		};
		uint32_t _raw;
	};
} reg_mem_ecc_err_mask;
static_assert((sizeof(struct reg_mem_ecc_err_mask) == 4), "reg_mem_ecc_err_mask size is not 32-bit");
/*
 MEM_ECC_GLBL_ERR_MASK 
 b'Global SERR and DERR mask'
*/
typedef struct reg_mem_ecc_glbl_err_mask {
	union {
		struct {
			uint32_t serr : 1,
				derr : 1,
				_reserved2 : 30;
		};
		uint32_t _raw;
	};
} reg_mem_ecc_glbl_err_mask;
static_assert((sizeof(struct reg_mem_ecc_glbl_err_mask) == 4), "reg_mem_ecc_glbl_err_mask size is not 32-bit");
/*
 MEM_ECC_ERR_STS 
 b'Captured syndrom on ECC error selected by MEM_SEL'
*/
typedef struct reg_mem_ecc_err_sts {
	union {
		struct {
			uint32_t synd : 16,
				serr : 1,
				derr : 1,
				_reserved18 : 14;
		};
		uint32_t _raw;
	};
} reg_mem_ecc_err_sts;
static_assert((sizeof(struct reg_mem_ecc_err_sts) == 4), "reg_mem_ecc_err_sts size is not 32-bit");
/*
 MEM_ECC_ERR_ADDR 
 b'Captured address on ECC error selected by MEM_SEL'
*/
typedef struct reg_mem_ecc_err_addr {
	union {
		struct {
			uint32_t val : 16,
				_reserved16 : 16;
		};
		uint32_t _raw;
	};
} reg_mem_ecc_err_addr;
static_assert((sizeof(struct reg_mem_ecc_err_addr) == 4), "reg_mem_ecc_err_addr size is not 32-bit");
/*
 MEM_RM 
 b'Control memory read margin'
*/
typedef struct reg_mem_rm {
	union {
		struct {
			uint32_t val : 30,
				_reserved30 : 2;
		};
		uint32_t _raw;
	};
} reg_mem_rm;
static_assert((sizeof(struct reg_mem_rm) == 4), "reg_mem_rm size is not 32-bit");
/*
 GLBL_ERR_MASK 
 b'Mask APB from returning bus error'
*/
typedef struct reg_glbl_err_mask {
	union {
		struct {
			uint32_t apb_priv_rd : 1,
				apb_sec_rd : 1,
				apb_unmapped_rd : 1,
				apb_priv_wr : 1,
				apb_sec_wr : 1,
				apb_unmapped_wr : 1,
				_reserved16 : 10,
				ext_sec_wr : 1,
				ext_unmapped_wr : 1,
				_reserved18 : 14;
		};
		uint32_t _raw;
	};
} reg_glbl_err_mask;
static_assert((sizeof(struct reg_glbl_err_mask) == 4), "reg_glbl_err_mask size is not 32-bit");
/*
 GLBL_ERR_ADDR 
 b'Captured address on security or unmapped violation'
*/
typedef struct reg_glbl_err_addr {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_glbl_err_addr;
static_assert((sizeof(struct reg_glbl_err_addr) == 4), "reg_glbl_err_addr size is not 32-bit");
/*
 GLBL_ERR_CAUSE 
 b'Error cause register'
*/
typedef struct reg_glbl_err_cause {
	union {
		struct {
			uint32_t apb_priv_rd : 1,
				apb_sec_rd : 1,
				apb_unmapped_rd : 1,
				apb_priv_wr : 1,
				apb_sec_wr : 1,
				apb_unmapped_wr : 1,
				_reserved16 : 10,
				ext_sec_wr : 1,
				ext_unmapped_wr : 1,
				_reserved18 : 14;
		};
		uint32_t _raw;
	};
} reg_glbl_err_cause;
static_assert((sizeof(struct reg_glbl_err_cause) == 4), "reg_glbl_err_cause size is not 32-bit");
/*
 GLBL_SPARE 
 b'Spare registers'
*/
typedef struct reg_glbl_spare {
	union {
		struct {
			uint32_t r : 32;
		};
		uint32_t _raw;
	};
} reg_glbl_spare;
static_assert((sizeof(struct reg_glbl_spare) == 4), "reg_glbl_spare size is not 32-bit");
/*
 GLBL_SEC 
 b'Security configuration'
*/
typedef struct reg_glbl_sec {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_glbl_sec;
static_assert((sizeof(struct reg_glbl_sec) == 4), "reg_glbl_sec size is not 32-bit");

#ifdef __cplusplus
} /* special_regs namespace */
#endif

/*
 SPECIAL_REGS block
*/

#ifdef __cplusplus

struct block_special_regs {
	struct special_regs::reg_glbl_priv glbl_priv[32];
	struct special_regs::reg_mem_gw_data mem_gw_data;
	struct special_regs::reg_mem_gw_req mem_gw_req;
	uint32_t _pad136[1];
	struct special_regs::reg_mem_numof mem_numof;
	struct special_regs::reg_mem_ecc_sel mem_ecc_sel;
	struct special_regs::reg_mem_ecc_ctl mem_ecc_ctl;
	struct special_regs::reg_mem_ecc_err_mask mem_ecc_err_mask;
	struct special_regs::reg_mem_ecc_glbl_err_mask mem_ecc_glbl_err_mask;
	struct special_regs::reg_mem_ecc_err_sts mem_ecc_err_sts;
	struct special_regs::reg_mem_ecc_err_addr mem_ecc_err_addr;
	struct special_regs::reg_mem_rm mem_rm;
	uint32_t _pad172[5];
	struct special_regs::reg_glbl_err_mask glbl_err_mask;
	struct special_regs::reg_glbl_err_addr glbl_err_addr;
	struct special_regs::reg_glbl_err_cause glbl_err_cause;
	uint32_t _pad204[5];
	struct special_regs::reg_glbl_spare glbl_spare[4];
	uint32_t _pad240[4];
	struct special_regs::reg_glbl_sec glbl_sec[32];
};
#else

typedef struct block_special_regs {
	reg_glbl_priv glbl_priv[32];
	reg_mem_gw_data mem_gw_data;
	reg_mem_gw_req mem_gw_req;
	uint32_t _pad136[1];
	reg_mem_numof mem_numof;
	reg_mem_ecc_sel mem_ecc_sel;
	reg_mem_ecc_ctl mem_ecc_ctl;
	reg_mem_ecc_err_mask mem_ecc_err_mask;
	reg_mem_ecc_glbl_err_mask mem_ecc_glbl_err_mask;
	reg_mem_ecc_err_sts mem_ecc_err_sts;
	reg_mem_ecc_err_addr mem_ecc_err_addr;
	reg_mem_rm mem_rm;
	uint32_t _pad172[5];
	reg_glbl_err_mask glbl_err_mask;
	reg_glbl_err_addr glbl_err_addr;
	reg_glbl_err_cause glbl_err_cause;
	uint32_t _pad204[5];
	reg_glbl_spare glbl_spare[4];
	uint32_t _pad240[4];
	reg_glbl_sec glbl_sec[32];
} block_special_regs;
#endif

const offsetVal block_special_regs_defaults[] =
{
	// offset	// value
	{ 0x0   , 0xffffffff          , 32 }, // glbl_priv
	{ 0xa4  , 0xffff              , 1 }, // mem_ecc_err_addr
	{ 0xc4  , 0xffffffff          , 1 }, // glbl_err_addr
	{ 0x100 , 0xffffffff          , 32 }, // glbl_sec
};

#ifdef __cplusplus
} /* gaudi2 namespace */
#endif

#pragma pack(pop)
#endif /* ASIC_REG_STRUCTS_SPECIAL_REGS_H_ */
