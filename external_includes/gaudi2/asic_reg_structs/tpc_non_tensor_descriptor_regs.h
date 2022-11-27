/***********************************
** This is an auto-generated file **
**       DO NOT EDIT BELOW        **
************************************/

#ifndef ASIC_REG_STRUCTS_TPC_NON_TENSOR_DESCRIPTOR_H_
#define ASIC_REG_STRUCTS_TPC_NON_TENSOR_DESCRIPTOR_H_

#include <stdint.h>
#include "gaudi2_types.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace gaudi2 {
namespace tpc_non_tensor_descriptor {
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
 KERNEL_BASE_ADDRESS_LOW 
 b'lower 32 bits of the kernel base address'
*/
typedef struct reg_kernel_base_address_low {
	union {
		struct {
			uint32_t v : 32;
		};
		uint32_t _raw;
	};
} reg_kernel_base_address_low;
static_assert((sizeof(struct reg_kernel_base_address_low) == 4), "reg_kernel_base_address_low size is not 32-bit");
/*
 KERNEL_BASE_ADDRESS_HIGH 
 b'higher 32 bits of the kernel base address'
*/
typedef struct reg_kernel_base_address_high {
	union {
		struct {
			uint32_t v : 32;
		};
		uint32_t _raw;
	};
} reg_kernel_base_address_high;
static_assert((sizeof(struct reg_kernel_base_address_high) == 4), "reg_kernel_base_address_high size is not 32-bit");
/*
 TID_BASE_DIM_0 
 b'init value for IRF0[0]'
*/
typedef struct reg_tid_base_dim_0 {
	union {
		struct {
			uint32_t v : 32;
		};
		uint32_t _raw;
	};
} reg_tid_base_dim_0;
static_assert((sizeof(struct reg_tid_base_dim_0) == 4), "reg_tid_base_dim_0 size is not 32-bit");
/*
 TID_SIZE_DIM_0 
 b'init value for IRF1[0]'
*/
typedef struct reg_tid_size_dim_0 {
	union {
		struct {
			uint32_t v : 32;
		};
		uint32_t _raw;
	};
} reg_tid_size_dim_0;
static_assert((sizeof(struct reg_tid_size_dim_0) == 4), "reg_tid_size_dim_0 size is not 32-bit");
/*
 TID_BASE_DIM_1 
 b'init value for IRF0[1]'
*/
typedef struct reg_tid_base_dim_1 {
	union {
		struct {
			uint32_t v : 32;
		};
		uint32_t _raw;
	};
} reg_tid_base_dim_1;
static_assert((sizeof(struct reg_tid_base_dim_1) == 4), "reg_tid_base_dim_1 size is not 32-bit");
/*
 TID_SIZE_DIM_1 
 b'init value for IRF1[1]'
*/
typedef struct reg_tid_size_dim_1 {
	union {
		struct {
			uint32_t v : 32;
		};
		uint32_t _raw;
	};
} reg_tid_size_dim_1;
static_assert((sizeof(struct reg_tid_size_dim_1) == 4), "reg_tid_size_dim_1 size is not 32-bit");
/*
 TID_BASE_DIM_2 
 b'init value for IRF0[2]'
*/
typedef struct reg_tid_base_dim_2 {
	union {
		struct {
			uint32_t v : 32;
		};
		uint32_t _raw;
	};
} reg_tid_base_dim_2;
static_assert((sizeof(struct reg_tid_base_dim_2) == 4), "reg_tid_base_dim_2 size is not 32-bit");
/*
 TID_SIZE_DIM_2 
 b'init value for IRF1[2]'
*/
typedef struct reg_tid_size_dim_2 {
	union {
		struct {
			uint32_t v : 32;
		};
		uint32_t _raw;
	};
} reg_tid_size_dim_2;
static_assert((sizeof(struct reg_tid_size_dim_2) == 4), "reg_tid_size_dim_2 size is not 32-bit");
/*
 TID_BASE_DIM_3 
 b'init value for IRF0[3]'
*/
typedef struct reg_tid_base_dim_3 {
	union {
		struct {
			uint32_t v : 32;
		};
		uint32_t _raw;
	};
} reg_tid_base_dim_3;
static_assert((sizeof(struct reg_tid_base_dim_3) == 4), "reg_tid_base_dim_3 size is not 32-bit");
/*
 TID_SIZE_DIM_3 
 b'init value for IRF1[3]'
*/
typedef struct reg_tid_size_dim_3 {
	union {
		struct {
			uint32_t v : 32;
		};
		uint32_t _raw;
	};
} reg_tid_size_dim_3;
static_assert((sizeof(struct reg_tid_size_dim_3) == 4), "reg_tid_size_dim_3 size is not 32-bit");
/*
 TID_BASE_DIM_4 
 b'init value for IRF0[4]'
*/
typedef struct reg_tid_base_dim_4 {
	union {
		struct {
			uint32_t v : 32;
		};
		uint32_t _raw;
	};
} reg_tid_base_dim_4;
static_assert((sizeof(struct reg_tid_base_dim_4) == 4), "reg_tid_base_dim_4 size is not 32-bit");
/*
 TID_SIZE_DIM_4 
 b'init value for IRF1[4]'
*/
typedef struct reg_tid_size_dim_4 {
	union {
		struct {
			uint32_t v : 32;
		};
		uint32_t _raw;
	};
} reg_tid_size_dim_4;
static_assert((sizeof(struct reg_tid_size_dim_4) == 4), "reg_tid_size_dim_4 size is not 32-bit");
/*
 KERNEL_CONFIG 
 b'a few cfg (small VLM, num valid SRFs,IRF44,...)'
*/
typedef struct reg_kernel_config {
	union {
		struct {
			uint32_t small_vlm : 1,
				aso_evict_l0 : 1,
				num_valid_srfs : 6,
				rd_rate_limit_rst_token : 8,
				wr_rate_limit_rst_token : 8,
				irf_32bit_compatibility : 1,
				_reserved25 : 7;
		};
		uint32_t _raw;
	};
} reg_kernel_config;
static_assert((sizeof(struct reg_kernel_config) == 4), "reg_kernel_config size is not 32-bit");
/*
 KERNEL_ID 
 b'used by profiler'
*/
typedef struct reg_kernel_id {
	union {
		struct {
			uint32_t v : 16,
				_reserved16 : 16;
		};
		uint32_t _raw;
	};
} reg_kernel_id;
static_assert((sizeof(struct reg_kernel_id) == 4), "reg_kernel_id size is not 32-bit");
/*
 POWER_LOOP 
 b'en/dis messages to ARC at start/end descriptor'
*/
typedef struct reg_power_loop {
	union {
		struct {
			uint32_t start_en : 1,
				end_en : 1,
				_reserved4 : 2,
				payload : 8,
				_reserved12 : 20;
		};
		uint32_t _raw;
	};
} reg_power_loop;
static_assert((sizeof(struct reg_power_loop) == 4), "reg_power_loop size is not 32-bit");
/*
 SRF 
 b'the 32 register which should be preloaded into SRF'
*/
typedef struct reg_srf {
	union {
		struct {
			uint32_t v : 32;
		};
		uint32_t _raw;
	};
} reg_srf;
static_assert((sizeof(struct reg_srf) == 4), "reg_srf size is not 32-bit");
/*
 KERNEL_ID_INC 
 b'by how much to increment kernel_id (auto_inc)'
*/
typedef struct reg_kernel_id_inc {
	union {
		struct {
			uint32_t v : 8,
				_reserved8 : 24;
		};
		uint32_t _raw;
	};
} reg_kernel_id_inc;
static_assert((sizeof(struct reg_kernel_id_inc) == 4), "reg_kernel_id_inc size is not 32-bit");
/*
 TID_BASE_SIZE_HIGH_DIM_0 
 b'12 upper bits init value for IRF0[0]/IRF1[0]'
*/
typedef struct reg_tid_base_size_high_dim_0 {
	union {
		struct {
			uint32_t base_high : 12,
				_reserved16 : 4,
				size_high : 12,
				_reserved28 : 4;
		};
		uint32_t _raw;
	};
} reg_tid_base_size_high_dim_0;
static_assert((sizeof(struct reg_tid_base_size_high_dim_0) == 4), "reg_tid_base_size_high_dim_0 size is not 32-bit");
/*
 TID_BASE_SIZE_HIGH_DIM_1 
 b'12 upper bits init value for IRF0[1]/IRF1[1]'
*/
typedef struct reg_tid_base_size_high_dim_1 {
	union {
		struct {
			uint32_t base_high : 12,
				_reserved16 : 4,
				size_high : 12,
				_reserved28 : 4;
		};
		uint32_t _raw;
	};
} reg_tid_base_size_high_dim_1;
static_assert((sizeof(struct reg_tid_base_size_high_dim_1) == 4), "reg_tid_base_size_high_dim_1 size is not 32-bit");
/*
 TID_BASE_SIZE_HIGH_DIM_2 
 b'12 upper bits init value for IRF0[2]/IRF1[2]'
*/
typedef struct reg_tid_base_size_high_dim_2 {
	union {
		struct {
			uint32_t base_high : 12,
				_reserved16 : 4,
				size_high : 12,
				_reserved28 : 4;
		};
		uint32_t _raw;
	};
} reg_tid_base_size_high_dim_2;
static_assert((sizeof(struct reg_tid_base_size_high_dim_2) == 4), "reg_tid_base_size_high_dim_2 size is not 32-bit");
/*
 TID_BASE_SIZE_HIGH_DIM_3 
 b'12 upper bits init value for IRF0[3]/IRF1[3]'
*/
typedef struct reg_tid_base_size_high_dim_3 {
	union {
		struct {
			uint32_t base_high : 12,
				_reserved16 : 4,
				size_high : 12,
				_reserved28 : 4;
		};
		uint32_t _raw;
	};
} reg_tid_base_size_high_dim_3;
static_assert((sizeof(struct reg_tid_base_size_high_dim_3) == 4), "reg_tid_base_size_high_dim_3 size is not 32-bit");
/*
 TID_BASE_SIZE_HIGH_DIM_4 
 b'12 upper bits init value for IRF0[4]/IRF1[4]'
*/
typedef struct reg_tid_base_size_high_dim_4 {
	union {
		struct {
			uint32_t base_high : 12,
				_reserved16 : 4,
				size_high : 12,
				_reserved28 : 4;
		};
		uint32_t _raw;
	};
} reg_tid_base_size_high_dim_4;
static_assert((sizeof(struct reg_tid_base_size_high_dim_4) == 4), "reg_tid_base_size_high_dim_4 size is not 32-bit");

#ifdef __cplusplus
} /* tpc_non_tensor_descriptor namespace */
#endif

/*
 TPC_NON_TENSOR_DESCRIPTOR block
*/

#ifdef __cplusplus

struct block_tpc_non_tensor_descriptor {
	struct tpc_non_tensor_descriptor::reg_kernel_base_address_low kernel_base_address_low;
	struct tpc_non_tensor_descriptor::reg_kernel_base_address_high kernel_base_address_high;
	struct tpc_non_tensor_descriptor::reg_tid_base_dim_0 tid_base_dim_0;
	struct tpc_non_tensor_descriptor::reg_tid_size_dim_0 tid_size_dim_0;
	struct tpc_non_tensor_descriptor::reg_tid_base_dim_1 tid_base_dim_1;
	struct tpc_non_tensor_descriptor::reg_tid_size_dim_1 tid_size_dim_1;
	struct tpc_non_tensor_descriptor::reg_tid_base_dim_2 tid_base_dim_2;
	struct tpc_non_tensor_descriptor::reg_tid_size_dim_2 tid_size_dim_2;
	struct tpc_non_tensor_descriptor::reg_tid_base_dim_3 tid_base_dim_3;
	struct tpc_non_tensor_descriptor::reg_tid_size_dim_3 tid_size_dim_3;
	struct tpc_non_tensor_descriptor::reg_tid_base_dim_4 tid_base_dim_4;
	struct tpc_non_tensor_descriptor::reg_tid_size_dim_4 tid_size_dim_4;
	struct tpc_non_tensor_descriptor::reg_kernel_config kernel_config;
	struct tpc_non_tensor_descriptor::reg_kernel_id kernel_id;
	struct tpc_non_tensor_descriptor::reg_power_loop power_loop;
	struct tpc_non_tensor_descriptor::reg_srf srf[32];
	struct tpc_non_tensor_descriptor::reg_kernel_id_inc kernel_id_inc;
	struct tpc_non_tensor_descriptor::reg_tid_base_size_high_dim_0 tid_base_size_high_dim_0;
	struct tpc_non_tensor_descriptor::reg_tid_base_size_high_dim_1 tid_base_size_high_dim_1;
	struct tpc_non_tensor_descriptor::reg_tid_base_size_high_dim_2 tid_base_size_high_dim_2;
	struct tpc_non_tensor_descriptor::reg_tid_base_size_high_dim_3 tid_base_size_high_dim_3;
	struct tpc_non_tensor_descriptor::reg_tid_base_size_high_dim_4 tid_base_size_high_dim_4;
};
#else

typedef struct block_tpc_non_tensor_descriptor {
	reg_kernel_base_address_low kernel_base_address_low;
	reg_kernel_base_address_high kernel_base_address_high;
	reg_tid_base_dim_0 tid_base_dim_0;
	reg_tid_size_dim_0 tid_size_dim_0;
	reg_tid_base_dim_1 tid_base_dim_1;
	reg_tid_size_dim_1 tid_size_dim_1;
	reg_tid_base_dim_2 tid_base_dim_2;
	reg_tid_size_dim_2 tid_size_dim_2;
	reg_tid_base_dim_3 tid_base_dim_3;
	reg_tid_size_dim_3 tid_size_dim_3;
	reg_tid_base_dim_4 tid_base_dim_4;
	reg_tid_size_dim_4 tid_size_dim_4;
	reg_kernel_config kernel_config;
	reg_kernel_id kernel_id;
	reg_power_loop power_loop;
	reg_srf srf[32];
	reg_kernel_id_inc kernel_id_inc;
	reg_tid_base_size_high_dim_0 tid_base_size_high_dim_0;
	reg_tid_base_size_high_dim_1 tid_base_size_high_dim_1;
	reg_tid_base_size_high_dim_2 tid_base_size_high_dim_2;
	reg_tid_base_size_high_dim_3 tid_base_size_high_dim_3;
	reg_tid_base_size_high_dim_4 tid_base_size_high_dim_4;
} block_tpc_non_tensor_descriptor;
#endif

const offsetVal block_tpc_non_tensor_descriptor_defaults[] =
{
	// offset	// value
	{ 0x30  , 0x1040482           , 1 }, // kernel_config
};

#ifdef __cplusplus
} /* gaudi2 namespace */
#endif

#pragma pack(pop)
#endif /* ASIC_REG_STRUCTS_TPC_NON_TENSOR_DESCRIPTOR_H_ */
