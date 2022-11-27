/***********************************
** This is an auto-generated file **
**       DO NOT EDIT BELOW        **
************************************/

#ifndef ASIC_REG_STRUCTS_TPC_NON_TENSOR_DESCRIPTOR_H_
#define ASIC_REG_STRUCTS_TPC_NON_TENSOR_DESCRIPTOR_H_

#include <stdint.h>

#pragma pack(push, 1)
namespace gaudi
{
namespace tpc_non_tensor_descriptor {
/*
 KERNEL_BASE_ADDRESS_LOW 
 lower 32 bits of the kernel base address
*/
struct reg_kernel_base_address_low {
	union {
		struct {
			uint32_t v : 32;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_kernel_base_address_low) == 4), "reg_kernel_base_address_low size is not 32-bit");
/*
 KERNEL_BASE_ADDRESS_HIGH 
 higher 32 bits of the kernel base address
*/
struct reg_kernel_base_address_high {
	union {
		struct {
			uint32_t v : 32;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_kernel_base_address_high) == 4), "reg_kernel_base_address_high size is not 32-bit");
/*
 TID_BASE_DIM_0 
*/
struct reg_tid_base_dim_0 {
	union {
		struct {
			uint32_t v : 32;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_tid_base_dim_0) == 4), "reg_tid_base_dim_0 size is not 32-bit");
/*
 TID_SIZE_DIM_0 
*/
struct reg_tid_size_dim_0 {
	union {
		struct {
			uint32_t v : 32;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_tid_size_dim_0) == 4), "reg_tid_size_dim_0 size is not 32-bit");
/*
 TID_BASE_DIM_1 
*/
struct reg_tid_base_dim_1 {
	union {
		struct {
			uint32_t v : 32;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_tid_base_dim_1) == 4), "reg_tid_base_dim_1 size is not 32-bit");
/*
 TID_SIZE_DIM_1 
*/
struct reg_tid_size_dim_1 {
	union {
		struct {
			uint32_t v : 32;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_tid_size_dim_1) == 4), "reg_tid_size_dim_1 size is not 32-bit");
/*
 TID_BASE_DIM_2 
*/
struct reg_tid_base_dim_2 {
	union {
		struct {
			uint32_t v : 32;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_tid_base_dim_2) == 4), "reg_tid_base_dim_2 size is not 32-bit");
/*
 TID_SIZE_DIM_2 
*/
struct reg_tid_size_dim_2 {
	union {
		struct {
			uint32_t v : 32;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_tid_size_dim_2) == 4), "reg_tid_size_dim_2 size is not 32-bit");
/*
 TID_BASE_DIM_3 
*/
struct reg_tid_base_dim_3 {
	union {
		struct {
			uint32_t v : 32;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_tid_base_dim_3) == 4), "reg_tid_base_dim_3 size is not 32-bit");
/*
 TID_SIZE_DIM_3 
*/
struct reg_tid_size_dim_3 {
	union {
		struct {
			uint32_t v : 32;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_tid_size_dim_3) == 4), "reg_tid_size_dim_3 size is not 32-bit");
/*
 TID_BASE_DIM_4 
*/
struct reg_tid_base_dim_4 {
	union {
		struct {
			uint32_t v : 32;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_tid_base_dim_4) == 4), "reg_tid_base_dim_4 size is not 32-bit");
/*
 TID_SIZE_DIM_4 
*/
struct reg_tid_size_dim_4 {
	union {
		struct {
			uint32_t v : 32;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_tid_size_dim_4) == 4), "reg_tid_size_dim_4 size is not 32-bit");
/*
 SRF 
 the 32 register which should be preloaded into SRF
*/
struct reg_srf {
	union {
		struct {
			uint32_t v : 32;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_srf) == 4), "reg_srf size is not 32-bit");
/*
 KERNEL_CONFIG 
*/
struct reg_kernel_config {
	union {
		struct {
			uint32_t small_vlm : 1,
				aso_evict_l0 : 1,
				num_valid_srfs : 6,
				rd_rate_limit_rst_token : 8,
				wr_rate_limit_rst_token : 8,
				_reserved24 : 8;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_kernel_config) == 4), "reg_kernel_config size is not 32-bit");
/*
 KERNEL_ID 
*/
struct reg_kernel_id {
	union {
		struct {
			uint32_t v : 16,
				_reserved16 : 16;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_kernel_id) == 4), "reg_kernel_id size is not 32-bit");
} /* tpc_non_tensor_descriptor namespace */

/*
 TPC_NON_TENSOR_DESCRIPTOR block
*/
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
	struct tpc_non_tensor_descriptor::reg_srf srf[32];
};
} // namespace gaudi
#include "gaudi_types.h"
namespace gaudi
{
const offsetVal block_tpc_non_tensor_descriptor_defaults[]
{
	// offset	// value
	{ 0x30  , 0x60882             , 1 }, // kernel_config
};

} //namespace gaudi
#pragma pack(pop)
#endif /* ASIC_REG_STRUCTS_TPC_NON_TENSOR_DESCRIPTOR_H_ */
