/***********************************
** This is an auto-generated file **
**       DO NOT EDIT BELOW        **
************************************/

#ifndef ASIC_REG_STRUCTS_TPC_TENSOR_H_
#define ASIC_REG_STRUCTS_TPC_TENSOR_H_

#include <stdint.h>
#include "gaudi2_types.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace gaudi2 {
namespace tpc_tensor {
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
 BASE_ADDR_LOW 
 b'bits 31 to 0 of the base address'
*/
typedef struct reg_base_addr_low {
	union {
		struct {
			uint32_t v : 32;
		};
		uint32_t _raw;
	};
} reg_base_addr_low;
static_assert((sizeof(struct reg_base_addr_low) == 4), "reg_base_addr_low size is not 32-bit");
/*
 BASE_ADDR_HIGH 
 b'bits 63 to 32 of the base address'
*/
typedef struct reg_base_addr_high {
	union {
		struct {
			uint32_t v : 32;
		};
		uint32_t _raw;
	};
} reg_base_addr_high;
static_assert((sizeof(struct reg_base_addr_high) == 4), "reg_base_addr_high size is not 32-bit");
/*
 PADDING_VALUE 
 b'padding value when tensor access is out of bound'
*/
typedef struct reg_padding_value {
	union {
		struct {
			uint32_t v : 32;
		};
		uint32_t _raw;
	};
} reg_padding_value;
static_assert((sizeof(struct reg_padding_value) == 4), "reg_padding_value size is not 32-bit");
/*
 TENSOR_CONFIG 
 b'general tensor configuration'
*/
typedef struct reg_tensor_config {
	union {
		struct {
			uint32_t data_type : 4,
				_reserved8 : 4,
				valid_dim_mask : 5,
				last_dim64 : 1,
				_reserved16 : 2,
				last_dim : 3,
				rmw_set : 1,
				_reserved21 : 1,
				rmw_op : 3,
				dup_oob : 1,
				l0cd : 1,
				t_pref_dis : 1,
				_reserved27 : 5;
		};
		uint32_t _raw;
	};
} reg_tensor_config;
static_assert((sizeof(struct reg_tensor_config) == 4), "reg_tensor_config size is not 32-bit");
/*
 DIM_0_SIZE 
 b'number of elements in dimension 0'
*/
typedef struct reg_dim_0_size {
	union {
		struct {
			uint32_t v : 32;
		};
		uint32_t _raw;
	};
} reg_dim_0_size;
static_assert((sizeof(struct reg_dim_0_size) == 4), "reg_dim_0_size size is not 32-bit");
/*
 DIM_0_STRIDE 
 b'dimension 0 stride'
*/
typedef struct reg_dim_0_stride {
	union {
		struct {
			uint32_t v : 32;
		};
		uint32_t _raw;
	};
} reg_dim_0_stride;
static_assert((sizeof(struct reg_dim_0_stride) == 4), "reg_dim_0_stride size is not 32-bit");
/*
 DIM_1_SIZE 
 b'number of elements in dimension 1'
*/
typedef struct reg_dim_1_size {
	union {
		struct {
			uint32_t v : 32;
		};
		uint32_t _raw;
	};
} reg_dim_1_size;
static_assert((sizeof(struct reg_dim_1_size) == 4), "reg_dim_1_size size is not 32-bit");
/*
 DIM_1_STRIDE 
 b'dimension 1 stride'
*/
typedef struct reg_dim_1_stride {
	union {
		struct {
			uint32_t v : 32;
		};
		uint32_t _raw;
	};
} reg_dim_1_stride;
static_assert((sizeof(struct reg_dim_1_stride) == 4), "reg_dim_1_stride size is not 32-bit");
/*
 DIM_2_SIZE 
 b'number of elements in dimension 2'
*/
typedef struct reg_dim_2_size {
	union {
		struct {
			uint32_t v : 32;
		};
		uint32_t _raw;
	};
} reg_dim_2_size;
static_assert((sizeof(struct reg_dim_2_size) == 4), "reg_dim_2_size size is not 32-bit");
/*
 DIM_2_STRIDE 
 b'dimension 2 stride'
*/
typedef struct reg_dim_2_stride {
	union {
		struct {
			uint32_t v : 32;
		};
		uint32_t _raw;
	};
} reg_dim_2_stride;
static_assert((sizeof(struct reg_dim_2_stride) == 4), "reg_dim_2_stride size is not 32-bit");
/*
 DIM_3_SIZE 
 b'number of elements in dimension 3'
*/
typedef struct reg_dim_3_size {
	union {
		struct {
			uint32_t v : 32;
		};
		uint32_t _raw;
	};
} reg_dim_3_size;
static_assert((sizeof(struct reg_dim_3_size) == 4), "reg_dim_3_size size is not 32-bit");
/*
 DIM_3_STRIDE 
 b'dimension 3 stride'
*/
typedef struct reg_dim_3_stride {
	union {
		struct {
			uint32_t v : 32;
		};
		uint32_t _raw;
	};
} reg_dim_3_stride;
static_assert((sizeof(struct reg_dim_3_stride) == 4), "reg_dim_3_stride size is not 32-bit");
/*
 DIM_4_SIZE 
 b'number of elements in dimension4'
*/
typedef struct reg_dim_4_size {
	union {
		struct {
			uint32_t v : 32;
		};
		uint32_t _raw;
	};
} reg_dim_4_size;
static_assert((sizeof(struct reg_dim_4_size) == 4), "reg_dim_4_size size is not 32-bit");
/*
 DIM_4_STRIDE 
 b'dimension 4 stride'
*/
typedef struct reg_dim_4_stride {
	union {
		struct {
			uint32_t v : 32;
		};
		uint32_t _raw;
	};
} reg_dim_4_stride;
static_assert((sizeof(struct reg_dim_4_stride) == 4), "reg_dim_4_stride size is not 32-bit");
/*
 PREF_STRIDE 
 b'Prefetcher strides'
*/
typedef struct reg_pref_stride {
	union {
		struct {
			uint32_t val : 16,
				_reserved16 : 16;
		};
		uint32_t _raw;
	};
} reg_pref_stride;
static_assert((sizeof(struct reg_pref_stride) == 4), "reg_pref_stride size is not 32-bit");
/*
 DIM_0_SIZE_STRIDE_HIGH 
 b'Size and Stride high part dim 0'
*/
typedef struct reg_dim_0_size_stride_high {
	union {
		struct {
			uint32_t stride_high : 12,
				_reserved16 : 4,
				size_high : 12,
				_reserved28 : 4;
		};
		uint32_t _raw;
	};
} reg_dim_0_size_stride_high;
static_assert((sizeof(struct reg_dim_0_size_stride_high) == 4), "reg_dim_0_size_stride_high size is not 32-bit");
/*
 DIM_1_SIZE_STRIDE_HIGH 
 b'Size and Stride high part dim 1'
*/
typedef struct reg_dim_1_size_stride_high {
	union {
		struct {
			uint32_t stride_high : 12,
				_reserved16 : 4,
				size_high : 12,
				_reserved28 : 4;
		};
		uint32_t _raw;
	};
} reg_dim_1_size_stride_high;
static_assert((sizeof(struct reg_dim_1_size_stride_high) == 4), "reg_dim_1_size_stride_high size is not 32-bit");
/*
 DIM_2_SIZE_STRIDE_HIGH 
 b'Size and Stride high part dim 2'
*/
typedef struct reg_dim_2_size_stride_high {
	union {
		struct {
			uint32_t stride_high : 12,
				_reserved16 : 4,
				size_high : 12,
				_reserved28 : 4;
		};
		uint32_t _raw;
	};
} reg_dim_2_size_stride_high;
static_assert((sizeof(struct reg_dim_2_size_stride_high) == 4), "reg_dim_2_size_stride_high size is not 32-bit");
/*
 DIM_3_SIZE_STRIDE_HIGH 
 b'Size and Stride high part dim 3'
*/
typedef struct reg_dim_3_size_stride_high {
	union {
		struct {
			uint32_t stride_high : 12,
				_reserved16 : 4,
				size_high : 12,
				_reserved28 : 4;
		};
		uint32_t _raw;
	};
} reg_dim_3_size_stride_high;
static_assert((sizeof(struct reg_dim_3_size_stride_high) == 4), "reg_dim_3_size_stride_high size is not 32-bit");
/*
 DIM_4_SIZE_STRIDE_HIGH 
 b'Size and Stride high part dim 4'
*/
typedef struct reg_dim_4_size_stride_high {
	union {
		struct {
			uint32_t stride_high : 12,
				_reserved16 : 4,
				size_high : 12,
				_reserved28 : 4;
		};
		uint32_t _raw;
	};
} reg_dim_4_size_stride_high;
static_assert((sizeof(struct reg_dim_4_size_stride_high) == 4), "reg_dim_4_size_stride_high size is not 32-bit");

#ifdef __cplusplus
} /* tpc_tensor namespace */
#endif

/*
 TPC_TENSOR block
*/

#ifdef __cplusplus

struct block_tpc_tensor {
	struct tpc_tensor::reg_base_addr_low base_addr_low;
	struct tpc_tensor::reg_base_addr_high base_addr_high;
	struct tpc_tensor::reg_padding_value padding_value;
	struct tpc_tensor::reg_tensor_config tensor_config;
	struct tpc_tensor::reg_dim_0_size dim_0_size;
	struct tpc_tensor::reg_dim_0_stride dim_0_stride;
	struct tpc_tensor::reg_dim_1_size dim_1_size;
	struct tpc_tensor::reg_dim_1_stride dim_1_stride;
	struct tpc_tensor::reg_dim_2_size dim_2_size;
	struct tpc_tensor::reg_dim_2_stride dim_2_stride;
	struct tpc_tensor::reg_dim_3_size dim_3_size;
	struct tpc_tensor::reg_dim_3_stride dim_3_stride;
	struct tpc_tensor::reg_dim_4_size dim_4_size;
	struct tpc_tensor::reg_dim_4_stride dim_4_stride;
	struct tpc_tensor::reg_pref_stride pref_stride;
	struct tpc_tensor::reg_dim_0_size_stride_high dim_0_size_stride_high;
	struct tpc_tensor::reg_dim_1_size_stride_high dim_1_size_stride_high;
	struct tpc_tensor::reg_dim_2_size_stride_high dim_2_size_stride_high;
	struct tpc_tensor::reg_dim_3_size_stride_high dim_3_size_stride_high;
	struct tpc_tensor::reg_dim_4_size_stride_high dim_4_size_stride_high;
};
#else

typedef struct block_tpc_tensor {
	reg_base_addr_low base_addr_low;
	reg_base_addr_high base_addr_high;
	reg_padding_value padding_value;
	reg_tensor_config tensor_config;
	reg_dim_0_size dim_0_size;
	reg_dim_0_stride dim_0_stride;
	reg_dim_1_size dim_1_size;
	reg_dim_1_stride dim_1_stride;
	reg_dim_2_size dim_2_size;
	reg_dim_2_stride dim_2_stride;
	reg_dim_3_size dim_3_size;
	reg_dim_3_stride dim_3_stride;
	reg_dim_4_size dim_4_size;
	reg_dim_4_stride dim_4_stride;
	reg_pref_stride pref_stride;
	reg_dim_0_size_stride_high dim_0_size_stride_high;
	reg_dim_1_size_stride_high dim_1_size_stride_high;
	reg_dim_2_size_stride_high dim_2_size_stride_high;
	reg_dim_3_size_stride_high dim_3_size_stride_high;
	reg_dim_4_size_stride_high dim_4_size_stride_high;
} block_tpc_tensor;
#endif

const offsetVal block_tpc_tensor_defaults[] =
{
	// offset	// value
	{ 0xc   , 0x50000             , 1 }, // tensor_config
};

#ifdef __cplusplus
} /* gaudi2 namespace */
#endif

#pragma pack(pop)
#endif /* ASIC_REG_STRUCTS_TPC_TENSOR_H_ */
