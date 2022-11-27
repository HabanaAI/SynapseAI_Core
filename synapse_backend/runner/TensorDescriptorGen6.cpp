/*****************************************************************************
 * Copyright (C) 2020 HabanaLabs, Ltd.
 * All Rights Reserved.
 *
 * Unauthorized copying of this file, via any medium is strictly prohibited.
 * Proprietary and confidential.
 ******************************************************************************
 */

#include "TensorDescriptor.h"
#include "gaudi2/TPC_IO_REG_SPACE_GEN6.h"

uint32_t gen6_TensorDescriptorElementSizeType(uint32_t configuration)
{
    return ((configuration & KERNEL_TENSOR_0_TENSOR_CONFIG_DATA_TYPE_MASK) >>
            KERNEL_TENSOR_0_TENSOR_CONFIG_DATA_TYPE_SHIFT);
}

uint32_t gen6_TensorDescriptorValidDimMask(uint32_t configuration)
{
    return ((configuration & KERNEL_TENSOR_0_TENSOR_CONFIG_VALID_DIM_MASK_MASK) >>
            KERNEL_TENSOR_0_TENSOR_CONFIG_VALID_DIM_MASK_SHIFT);
}

uint32_t gen6_TensorDescriptorLastDim(uint32_t configuration)
{
    return ((configuration & KERNEL_TENSOR_0_TENSOR_CONFIG_LAST_DIM_MASK) >>
            KERNEL_TENSOR_0_TENSOR_CONFIG_LAST_DIM_SHIFT);
}

uint32_t gen6_TensorDescriptorLastDim64(uint32_t configuration)
{
    return ((configuration & KERNEL_TENSOR_0_TENSOR_CONFIG_LAST_DIM64_MASK) >>
            KERNEL_TENSOR_0_TENSOR_CONFIG_LAST_DIM64_SHIFT);
}

uint32_t gen6_TensorDescriptorL0CD(uint32_t configuration)
{
    return ((configuration & KERNEL_TENSOR_0_TENSOR_CONFIG_L0CD_MASK) >> KERNEL_TENSOR_0_TENSOR_CONFIG_L0CD_SHIFT);
}

uint32_t gen6_get_TensorDescriptorRMW_set(uint32_t configuration)
{
    return ((configuration & KERNEL_TENSOR_0_TENSOR_CONFIG_RMW_SET_MASK) >>
            KERNEL_TENSOR_0_TENSOR_CONFIG_RMW_SET_SHIFT);
}

uint32_t gen6_get_TensorDescriptorRMW_op(uint32_t configuration)
{
    return ((configuration & KERNEL_TENSOR_0_TENSOR_CONFIG_RMW_OP_MASK) >> KERNEL_TENSOR_0_TENSOR_CONFIG_RMW_OP_SHIFT);
}

namespace tpc_gaudi2
{
uint32_t TensorDescriptorConfiguration(uint32_t dataType,
                                       uint32_t validDimMask,
                                       uint32_t lastDim,
                                       uint32_t rmwSel,
                                       uint32_t rmwOp,
                                       uint32_t dup_oob,
                                       uint32_t l0cd,
                                       uint32_t lastDim64,
                                       uint32_t hw_pref_dis)
{
    return (
        ((dataType << KERNEL_TENSOR_0_TENSOR_CONFIG_DATA_TYPE_SHIFT) & KERNEL_TENSOR_0_TENSOR_CONFIG_DATA_TYPE_MASK) |
        ((validDimMask << KERNEL_TENSOR_0_TENSOR_CONFIG_VALID_DIM_MASK_SHIFT) &
         KERNEL_TENSOR_0_TENSOR_CONFIG_VALID_DIM_MASK_MASK) |
        ((lastDim << KERNEL_TENSOR_0_TENSOR_CONFIG_LAST_DIM_SHIFT) & KERNEL_TENSOR_0_TENSOR_CONFIG_LAST_DIM_MASK) |
        ((lastDim64 << KERNEL_TENSOR_0_TENSOR_CONFIG_LAST_DIM64_SHIFT) &
         KERNEL_TENSOR_0_TENSOR_CONFIG_LAST_DIM64_MASK) |
        ((l0cd << KERNEL_TENSOR_0_TENSOR_CONFIG_L0CD_SHIFT) & KERNEL_TENSOR_0_TENSOR_CONFIG_L0CD_MASK) |
        ((hw_pref_dis << KERNEL_TENSOR_0_TENSOR_CONFIG_T_PREF_DIS_SHIFT) &
         KERNEL_TENSOR_0_TENSOR_CONFIG_T_PREF_DIS_MASK) |
        ((dup_oob << KERNEL_TENSOR_0_TENSOR_CONFIG_DUP_OOB_SHIFT) & KERNEL_TENSOR_0_TENSOR_CONFIG_DUP_OOB_MASK) |
        ((rmwSel << KERNEL_TENSOR_0_TENSOR_CONFIG_RMW_SET_SHIFT) & KERNEL_TENSOR_0_TENSOR_CONFIG_RMW_SET_MASK) |
        ((rmwOp << KERNEL_TENSOR_0_TENSOR_CONFIG_RMW_OP_SHIFT) & KERNEL_TENSOR_0_TENSOR_CONFIG_RMW_OP_MASK));
}

uint32_t get_ElementSizeInBytesFromDataType(TensorDataType DataType)
{
    switch (DataType) {
        case TensorDT_INT8:
        case TensorDT_UINT8:
        case TensorDT_INT16:
        case TensorDT_UINT16:
        case TensorDT_BF16:
        case TensorDT_FP16: return 2;
        case TensorDT_INT32:
        case TensorDT_UINT32:
        case TensorDT_FP32: return 4;
        default: assert(0 && "This is not a valid DataType"); break;
    }
    return 0;
}
} // namespace tpc_gaudi2