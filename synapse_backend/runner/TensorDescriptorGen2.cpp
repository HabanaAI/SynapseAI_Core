/* SPDX-License-Identifier: MIT
 *
 * Copyright 2016-2021 HabanaLabs, Ltd.
 * All Rights Reserved.
 *
 */

#include "gaudi/TPC_IO_REG_SPACE_GEN2.h"
#include "TensorDescriptor.h"

uint32_t gen2_TensorDescriptorElementSizeType(uint32_t configuration) 
{ 
	return ((configuration & KERNEL_TENSOR_0_TENSOR_CONFIG_DATA_TYPE_MASK) >> KERNEL_TENSOR_0_TENSOR_CONFIG_DATA_TYPE_SHIFT);
}

uint32_t gen2_TensorDescriptorValidDimMask(uint32_t configuration) 
{
	return ((configuration & KERNEL_TENSOR_0_TENSOR_CONFIG_VALID_DIM_MASK_MASK) >> KERNEL_TENSOR_0_TENSOR_CONFIG_VALID_DIM_MASK_SHIFT);
} 

uint32_t gen2_TensorDescriptorLastDim(uint32_t configuration) 
{
	return ((configuration & KERNEL_TENSOR_0_TENSOR_CONFIG_LAST_DIM_MASK) >> KERNEL_TENSOR_0_TENSOR_CONFIG_LAST_DIM_SHIFT);
} 

uint32_t gen2_get_TensorDescriptorRMW_set(uint32_t configuration)
{
	return ((configuration & KERNEL_TENSOR_0_TENSOR_CONFIG_RMW_SET_MASK) >> KERNEL_TENSOR_0_TENSOR_CONFIG_RMW_SET_SHIFT);
}

uint32_t gen2_get_TensorDescriptorRMW_op(uint32_t configuration)
{
	return ((configuration & KERNEL_TENSOR_0_TENSOR_CONFIG_RMW_OP_MASK) >> KERNEL_TENSOR_0_TENSOR_CONFIG_RMW_OP_SHIFT);
}

namespace tpc_gaudi {
uint32_t TensorDescriptorConfiguration(uint32_t dataType, uint32_t validDimMask, uint32_t lastDim,  uint32_t rmwSel, uint32_t rmwOp)
{
	return (\
        ((dataType      << KERNEL_TENSOR_0_TENSOR_CONFIG_DATA_TYPE_SHIFT) & KERNEL_TENSOR_0_TENSOR_CONFIG_DATA_TYPE_MASK) |\
        ((validDimMask  << KERNEL_TENSOR_0_TENSOR_CONFIG_VALID_DIM_MASK_SHIFT  ) & KERNEL_TENSOR_0_TENSOR_CONFIG_VALID_DIM_MASK_MASK) |\
        ((lastDim       << KERNEL_TENSOR_0_TENSOR_CONFIG_LAST_DIM_SHIFT  ) & KERNEL_TENSOR_0_TENSOR_CONFIG_LAST_DIM_MASK) |\
        ((rmwSel        << KERNEL_TENSOR_0_TENSOR_CONFIG_RMW_SET_SHIFT  ) & KERNEL_TENSOR_0_TENSOR_CONFIG_RMW_SET_MASK) |\
        ((rmwOp         << KERNEL_TENSOR_0_TENSOR_CONFIG_RMW_OP_SHIFT  ) & KERNEL_TENSOR_0_TENSOR_CONFIG_RMW_OP_MASK) );
}

uint32_t get_ElementSizeInBytesFromDataType(TensorDataType DataType)
{
    switch (DataType)
    {
        case TensorDT_INT8:
        case TensorDT_UINT8:
            return 1;
        case TensorDT_INT16:
        case TensorDT_UINT16:
        case TensorDT_BF16:
            return 2;
        case TensorDT_INT32:
        case TensorDT_UINT32:
        case TensorDT_FP32:
            return 4;
        default:
            assert(0 && "This is not a valid DataType");
            break;
    }
    return 0;
}
} //namespace tpc_gaudi

