/* SPDX-License-Identifier: MIT
 *
 * Copyright 2016-2021 HabanaLabs, Ltd.
 * All Rights Reserved.
 *
 */

#pragma once

#include "synapse_common_types.h"
#include <stdint.h>
#include <cassert>

#define DEF_NUM_DIMS_IN_IRF    5
#define DEF_PACK( __Declaration__ ) __Declaration__ __attribute__((__packed__))

DEF_PACK(
	struct _TensorDimDescriptorGaudi
{
	uint32_t size;
	uint32_t stride;
}
);

typedef struct _TensorDimDescriptorGaudi TensorDimDescriptorGaudi;

DEF_PACK(
    struct _TensorDescriptorBase
{
    union _baseAddrUnion
    {
        struct lowHigh
        {
            uint32_t baseAddrLow;
            uint32_t baseAddrHigh;
        } baseAddrStruct;
        uint64_t baseAddr;
    } baseAddrUnion;
    uint32_t paddingValue;
    uint32_t configuration;
}
);

typedef struct _TensorDescriptorBase  TensorDescriptorBase;

struct TensorDescriptor : public TensorDescriptorBase
{
	/* for Gaudi:
	TENSOR_0_BASE_ADDR_LOW		+0x00	32	0		Read/Write	bits 31 to 0 of the base address		no	no	no
	TENSOR_0_BASE_ADDR_HIGH		+0x04	32	0		Read/Write	bits 63 to 32 of the base address		no	no	no
	TENSOR_0_PADDING_VALUE		+0x08	32	0		Read/Write	padding value when tensor access is out of bound		no	no	no
	TENSOR_0_TENSOR_CONFIG		+0x0C	32	50000	Read/Write	general tensor configuration		no	no	no
	TENSOR_0_DIM_0_SIZE			+0x10	32	0		Read/Write	number of elements in dimension 0		no	no	no
	TENSOR_0_DIM_0_STRIDE		+0x14	32	0		Read/Write	dimension 0 stride		no	no	no
	TENSOR_0_DIM_1_SIZE			+0x18	32	0		Read/Write	number of elements in dimension 1		no	no	no
	TENSOR_0_DIM_1_STRIDE		+0x1C	32	0		Read/Write	dimension 1 stride		no	no	no
	TENSOR_0_DIM_2_SIZE			+0x20	32	0		Read/Write	number of elements in dimension 2		no	no	no
	TENSOR_0_DIM_2_STRIDE		+0x24	32	0		Read/Write	dimension 2 stride		no	no	no
	TENSOR_0_DIM_3_SIZE			+0x28	32	0		Read/Write	number of elements in dimension 3		no	no	no
	TENSOR_0_DIM_3_STRIDE		+0x2C	32	0		Read/Write	dimension 3 stride		no	no	no
	TENSOR_0_DIM_4_SIZE			+0x30	32	0		Read/Write	number of elements in dimension4		no	no	no
	TENSOR_0_DIM_4_STRIDE		+0x34	32	0		Read/Write	dimension 4 stride		no	no	no
	*/
	TensorDimDescriptorGaudi dimDescriptors[DEF_NUM_DIMS_IN_IRF];
};

typedef struct _AddressDescriptor AddressDescriptor;

//static_assert(sizeof(TensorDescriptor) == TPC_IO_REG_TENSOR_DESC_SIZE, "TensorDescriptor size is not aligned with HW expectations");
//static_assert(sizeof(AddressDescriptor) == ADRF_ENTRY_SIZE_IN_BYTES, "AddressDescriptor size is not aligned with HW expectations");

typedef enum TensorDataType_
{
    TensorDT_INT8   = 0,
    TensorDT_INT16  = 1,
    TensorDT_INT32  = 2,
    TensorDT_UINT8  = 3,
    TensorDT_UINT16 = 4,
    TensorDT_UINT32 = 5,
    TensorDT_BF16   = 6,
    TensorDT_FP32   = 7,
	TensorDT_FP16   = 8,
} TensorDataType;

uint32_t gen2_TensorDescriptorElementSizeType(uint32_t configuration);
uint32_t gen2_TensorDescriptorValidDimMask(uint32_t configuration);
uint32_t gen2_TensorDescriptorLastDim(uint32_t configuration);
uint32_t gen6_TensorDescriptorElementSizeType(uint32_t configuration);
uint32_t gen6_TensorDescriptorValidDimMask(uint32_t configuration);
uint32_t gen6_TensorDescriptorLastDim(uint32_t configuration);

namespace tpc_gaudi {
    inline uint32_t get_TensorDescriptorLastDim(uint32_t configuration)
    {
        return gen2_TensorDescriptorLastDim(configuration);
    }
    inline uint32_t get_TensorDescriptorElementSizeType(uint32_t configuration)
    {
        return gen2_TensorDescriptorElementSizeType(configuration);
    }
    inline uint32_t get_TensorDescriptorValidDimMask(uint32_t configuration)
    {
        return gen2_TensorDescriptorValidDimMask(configuration);
    }
	uint32_t TensorDescriptorConfiguration(uint32_t dataType, uint32_t validDimMask, uint32_t lastDim,  uint32_t rmwSel, uint32_t rmwOp);
    uint32_t get_ElementSizeInBytesFromDataType(TensorDataType DataType);
}

namespace tpc_gaudi2 {
    inline uint32_t get_TensorDescriptorLastDim(uint32_t configuration)
    {
        return gen6_TensorDescriptorLastDim(configuration);
    }
    inline uint32_t get_TensorDescriptorElementSizeType(uint32_t configuration)
    {
        return gen6_TensorDescriptorElementSizeType(configuration);
    }
    inline uint32_t get_TensorDescriptorValidDimMask(uint32_t configuration)
    {
        return gen6_TensorDescriptorValidDimMask(configuration);
    }
	uint32_t TensorDescriptorConfiguration(uint32_t dataType, uint32_t validDimMask, uint32_t lastDim,  uint32_t rmwSel, uint32_t rmwOp);
    uint32_t get_ElementSizeInBytesFromDataType(TensorDataType DataType);
}
