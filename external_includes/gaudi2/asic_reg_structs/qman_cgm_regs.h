/***********************************
** This is an auto-generated file **
**       DO NOT EDIT BELOW        **
************************************/

#ifndef ASIC_REG_STRUCTS_QMAN_CGM_H_
#define ASIC_REG_STRUCTS_QMAN_CGM_H_

#include <stdint.h>
#include "gaudi2_types.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace gaudi2 {
namespace qman_cgm {
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
 CFG 
 b'Clock gate Manager config'
*/
typedef struct reg_cfg {
	union {
		struct {
			uint32_t idle_th : 12,
				_reserved16 : 4,
				g2f_th : 8,
				cp_idle_mask : 5,
				hbw_wr_idle_mask : 1,
				_reserved31 : 1,
				en : 1;
		};
		uint32_t _raw;
	};
} reg_cfg;
static_assert((sizeof(struct reg_cfg) == 4), "reg_cfg size is not 32-bit");
/*
 STS 
 b'Clock Manager Status'
*/
typedef struct reg_sts {
	union {
		struct {
			uint32_t st : 2,
				_reserved4 : 2,
				cg : 1,
				_reserved8 : 3,
				agent_idle : 1,
				axi_idle : 1,
				cp_idle : 1,
				axi_wr_idle : 1,
				_reserved12 : 20;
		};
		uint32_t _raw;
	};
} reg_sts;
static_assert((sizeof(struct reg_sts) == 4), "reg_sts size is not 32-bit");
/*
 CFG1 
 b'CGM config reg 1 HBW mask Thresh'
*/
typedef struct reg_cfg1 {
	union {
		struct {
			uint32_t mask_th : 8,
				_reserved8 : 24;
		};
		uint32_t _raw;
	};
} reg_cfg1;
static_assert((sizeof(struct reg_cfg1) == 4), "reg_cfg1 size is not 32-bit");

#ifdef __cplusplus
} /* qman_cgm namespace */
#endif

/*
 QMAN_CGM block
*/

#ifdef __cplusplus

struct block_qman_cgm {
	struct qman_cgm::reg_cfg cfg;
	struct qman_cgm::reg_sts sts;
	struct qman_cgm::reg_cfg1 cfg1;
};
#else

typedef struct block_qman_cgm {
	reg_cfg cfg;
	reg_sts sts;
	reg_cfg1 cfg1;
} block_qman_cgm;
#endif

const offsetVal block_qman_cgm_defaults[] =
{
	// offset	// value
	{ 0x0   , 0x100080            , 1 }, // cfg
	{ 0x4   , 0xf00               , 1 }, // sts
	{ 0x8   , 0x10                , 1 }, // cfg1
};

#ifdef __cplusplus
} /* gaudi2 namespace */
#endif

#pragma pack(pop)
#endif /* ASIC_REG_STRUCTS_QMAN_CGM_H_ */
