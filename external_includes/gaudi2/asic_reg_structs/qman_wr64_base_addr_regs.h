/***********************************
** This is an auto-generated file **
**       DO NOT EDIT BELOW        **
************************************/

#ifndef ASIC_REG_STRUCTS_QMAN_WR64_BASE_ADDR_H_
#define ASIC_REG_STRUCTS_QMAN_WR64_BASE_ADDR_H_

#include <stdint.h>
#include "gaudi2_types.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace gaudi2 {
namespace qman_wr64_base_addr {
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
 LSB 
 b'qman wrreg64 base address [31:0]'
*/
typedef struct reg_lsb {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_lsb;
static_assert((sizeof(struct reg_lsb) == 4), "reg_lsb size is not 32-bit");
/*
 MSB 
 b'qman wrreg64 base address [63:32]'
*/
typedef struct reg_msb {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_msb;
static_assert((sizeof(struct reg_msb) == 4), "reg_msb size is not 32-bit");

#ifdef __cplusplus
} /* qman_wr64_base_addr namespace */
#endif

/*
 QMAN_WR64_BASE_ADDR block
*/

#ifdef __cplusplus

struct block_qman_wr64_base_addr {
	struct qman_wr64_base_addr::reg_lsb lsb;
	struct qman_wr64_base_addr::reg_msb msb;
};
#else

typedef struct block_qman_wr64_base_addr {
	reg_lsb lsb;
	reg_msb msb;
} block_qman_wr64_base_addr;
#endif


#ifdef __cplusplus
} /* gaudi2 namespace */
#endif

#pragma pack(pop)
#endif /* ASIC_REG_STRUCTS_QMAN_WR64_BASE_ADDR_H_ */
