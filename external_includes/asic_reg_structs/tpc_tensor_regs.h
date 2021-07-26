/***********************************
** This is an auto-generated file **
**       DO NOT EDIT BELOW        **
************************************/

#ifndef ASIC_REG_STRUCTS_TPC_TENSOR_H_
#define ASIC_REG_STRUCTS_TPC_TENSOR_H_

#include <stdint.h>

#pragma pack(push, 1)

namespace tpc_tensor {
/*
 BASE_ADDR_LOW 
 bits 31 to 0 of the base address
*/
struct reg_base_addr_low {
	union {
		struct {
			uint32_t v : 32;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_base_addr_low) == 4), "reg_base_addr_low size is not 32-bit");
/*
 BASE_ADDR_HIGH 
 bits 63 to 32 of the base address
*/
struct reg_base_addr_high {
	union {
		struct {
			uint32_t v : 32;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_base_addr_high) == 4), "reg_base_addr_high size is not 32-bit");
/*
 PADDING_VALUE 
 padding value when tensor access is out of bound
*/
struct reg_padding_value {
	union {
		struct {
			uint32_t v : 32;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_padding_value) == 4), "reg_padding_value size is not 32-bit");
/*
 DIM_0_SIZE 
 number of elements in dimension 0
*/
struct reg_dim_0_size {
	union {
		struct {
			uint32_t v : 32;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_dim_0_size) == 4), "reg_dim_0_size size is not 32-bit");
/*
 DIM_0_STRIDE 
 dimension 0 stride
*/
struct reg_dim_0_stride {
	union {
		struct {
			uint32_t v : 32;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_dim_0_stride) == 4), "reg_dim_0_stride size is not 32-bit");
/*
 DIM_1_SIZE 
 number of elements in dimension 1
*/
struct reg_dim_1_size {
	union {
		struct {
			uint32_t v : 32;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_dim_1_size) == 4), "reg_dim_1_size size is not 32-bit");
/*
 DIM_1_STRIDE 
 dimension 1 stride
*/
struct reg_dim_1_stride {
	union {
		struct {
			uint32_t v : 32;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_dim_1_stride) == 4), "reg_dim_1_stride size is not 32-bit");
/*
 DIM_2_SIZE 
 number of elements in dimension 2
*/
struct reg_dim_2_size {
	union {
		struct {
			uint32_t v : 32;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_dim_2_size) == 4), "reg_dim_2_size size is not 32-bit");
/*
 DIM_2_STRIDE 
 dimension 2 stride
*/
struct reg_dim_2_stride {
	union {
		struct {
			uint32_t v : 32;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_dim_2_stride) == 4), "reg_dim_2_stride size is not 32-bit");
/*
 DIM_3_SIZE 
 number of elements in dimension 3
*/
struct reg_dim_3_size {
	union {
		struct {
			uint32_t v : 32;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_dim_3_size) == 4), "reg_dim_3_size size is not 32-bit");
/*
 DIM_3_STRIDE 
 dimension 3 stride
*/
struct reg_dim_3_stride {
	union {
		struct {
			uint32_t v : 32;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_dim_3_stride) == 4), "reg_dim_3_stride size is not 32-bit");
/*
 DIM_4_SIZE 
 number of elements in dimension4
*/
struct reg_dim_4_size {
	union {
		struct {
			uint32_t v : 32;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_dim_4_size) == 4), "reg_dim_4_size size is not 32-bit");
/*
 DIM_4_STRIDE 
 dimension 4 stride
*/
struct reg_dim_4_stride {
	union {
		struct {
			uint32_t v : 32;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_dim_4_stride) == 4), "reg_dim_4_stride size is not 32-bit");
/*
 TENSOR_CONFIG 
 general tensor configuration
*/
struct reg_tensor_config {
	union {
		struct {
			uint32_t data_type : 3,
				_reserved8 : 5,
				valid_dim_mask : 5,
				_reserved16 : 3,
				last_dim : 3,
				rmw_set : 1,
				rmw_reserv : 1,
				rmw_op : 2,
				_reserved23 : 9;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_tensor_config) == 4), "reg_tensor_config size is not 32-bit");
} /* tpc_tensor namespace */

/*
 TPC_TENSOR block
*/
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
};
#include "gaudi_types.h"
const offsetVal block_tpc_tensor_defaults[]
{
	// offset	// value
	{ 0xc   , 0x50000             , 1 }, // tensor_config
};

#pragma pack(pop)
#endif /* ASIC_REG_STRUCTS_TPC_TENSOR_H_ */
