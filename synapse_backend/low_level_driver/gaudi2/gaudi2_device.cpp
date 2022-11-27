/* SPDX-License-Identifier: MIT
 *
 * Copyright 2016-2021 HabanaLabs, Ltd.
 * All Rights Reserved.
 *
 */

#include <stddef.h>
#include <misc/habanalabs.h>

#include "TensorDescriptor.h"
#include "gaudi2/asic_reg_structs/sob_objs_regs.h"
#include "gaudi2_device.h"
#include "SpecialFuncCoefficients.h"
#include "gaudi2/SpecialFuncCoefficients_defGen6.h"
#include "gaudi2/asic_reg_structs/qman_regs.h"
#include "gaudi2/asic_reg_structs/dma_core_regs.h"
#include "gaudi2/asic_reg_structs/tpc_regs.h"
#include "gaudi2_packet_gen.h"
#include "gaudi2/asic_reg/gaudi2_blocks.h"
#include "gaudi2/gaudi2_tpc_descriptor.h"

namespace gaudi2
{

const unsigned Gaudi2Device::c_tpcNr               = 24;
const unsigned Gaudi2Device::c_syncObjNr           = 8192;
const unsigned Gaudi2Device::c_monitorObjNr        = 2048;
const unsigned Gaudi2Device::c_syncObjectGroupSize = 8;
const uint64_t Gaudi2Device::c_syncManagerBase     = mmDCORE0_SYNC_MNGR_GLBL_BASE;
const uint64_t Gaudi2Device::c_syncObjectsBaseAddr = mmDCORE0_SYNC_MNGR_OBJS_BASE;
const unsigned Gaudi2Device::c_dmaCoreBlockOffset = mmPDMA0_CORE_BASE - mmPDMA0_QM_ARC_DCCM_BASE;
const unsigned Gaudi2Device::c_tpcCfgBlockOffset = mmDCORE0_TPC0_CFG_BASE - mmDCORE0_TPC0_QM_DCCM_BASE;
inline static uint64_t div_round_up(uint64_t a, uint64_t b)
{
    return (a + b - 1) / b;
}
inline static uint64_t round_to_multiple(uint64_t a, uint64_t mul)
{
    return mul * div_round_up(a, mul);
}

constexpr uint64_t Gaudi2Device::GetSyncObjectAddress(int synObjIndex)
{
    return c_syncObjectsBaseAddr + (c_syncObjectSizeInBytes * synObjIndex);
}

unsigned Gaudi2Device::GetTensorSizeFromDesc(TensorDescriptor& desc) const
{
    unsigned              size      = 1;
    unsigned dims = tpc_gaudi2::get_TensorDescriptorLastDim(desc.configuration) + 1;
    for (unsigned i = 0; i < dims; i++)
    {
        size *= desc.dimDescriptors[i].size;
    }
    // multiply by element size to get result in bytes
    unsigned descElement = tpc_gaudi2::get_TensorDescriptorElementSizeType(desc.configuration);
    unsigned elementSize =
        tpc_gaudi2::get_ElementSizeInBytesFromDataType((TensorDataType)descElement);
    size *= elementSize;
    return size;
}

unsigned Gaudi2Device::GetTensorSizeFromDesc(TensorDescriptor& desc0, TensorDescriptor& desc1) const
{
    unsigned              size      = 1;
    unsigned dims0 = tpc_gaudi2::get_TensorDescriptorLastDim(desc0.configuration) + 1;
    unsigned dims1 = tpc_gaudi2::get_TensorDescriptorLastDim(desc1.configuration) + 1;
    for (unsigned i = 0; i < dims0; i++)
    {
        size *= desc0.dimDescriptors[i].size;
    }

    for (unsigned i = 0; i < dims1; i++)
    {
        size *= desc1.dimDescriptors[i].size;
    }

    // multiply by element size to get result in bytes
    unsigned descElement = tpc_gaudi2::get_TensorDescriptorElementSizeType(desc0.configuration);
    unsigned elementSize =
            tpc_gaudi2::get_ElementSizeInBytesFromDataType((TensorDataType)descElement);
    size *= elementSize;

    return size;
}

unsigned Gaudi2Device::GetSpecialFuncTabNr() const
{
    return SPECIAL_FUNC_NUM_OF_DIFFERENT_INTERVALS;
}

void Gaudi2Device::GetSpecialFuncTabSizes(uint32_t* sizes, unsigned sizesLen) const
{
    assert(sizesLen >= 4);
    sizes[0] = SPECIAL_FUNC256_SIZE_BYTES;
    sizes[1] = SPECIAL_FUNC128_SIZE_BYTES;
    sizes[2] = SPECIAL_FUNC64_SIZE_BYTES;
    sizes[3] = SPECIAL_FUNC32_SIZE_BYTES;
}

void Gaudi2Device::CopySpecialFuncTab(
    std::vector<std::vector<uint8_t>>& specialFunctionCoefficients) const
{
    specialFunctionCoefficients.resize(SPECIAL_FUNC_NUM_OF_DIFFERENT_INTERVALS);
    tpc_gaudi2::buildSpecialFunctionCoefficients(specialFunctionCoefficients);
}

int Gaudi2Device::getAlignedFirstAvailableSOB() const
{
    return round_to_multiple(m_firstAvailSyncObj, c_syncObjectGroupSize);
}

int Gaudi2Device::GetDmaUpSyncObjectIndex() const
{
    auto sobObjIdx = getAlignedFirstAvailableSOB() + c_syncObjectGroupSize;
    return sobObjIdx;
}

uint64_t Gaudi2Device::GetDmaUpSyncObjectAddr() const
{
    return GetSyncObjectAddress(GetDmaUpSyncObjectIndex());
}

int Gaudi2Device::GetDmaDownSyncObjectIndex() const 
{
     auto sobIdx = getAlignedFirstAvailableSOB();
     return sobIdx;
}

uint64_t Gaudi2Device::GetDmaDownSyncObjectAddr() const
{
    return GetSyncObjectAddress(GetDmaDownSyncObjectIndex());
}

uint64_t Gaudi2Device::GetSyncManagerBaseAddr() const { return c_syncManagerBase; }

int Gaudi2Device::GetMonitorObjectBaseIndex() const { return m_firstAvailMonitor; }

unsigned Gaudi2Device::GetTPCNr() const { return c_tpcNr; }

unsigned Gaudi2Device::GetTPCQueueId(unsigned tpcId) const
{
    unsigned queueId = GAUDI2_QUEUE_ID_DCORE0_TPC_0_0;
    switch (tpcId)
    {
    case 0:
        queueId = GAUDI2_QUEUE_ID_DCORE0_TPC_0_0;
        break;
    case 1:
        queueId = GAUDI2_QUEUE_ID_DCORE0_TPC_1_0;
        break;
    case 2:
        queueId = GAUDI2_QUEUE_ID_DCORE0_TPC_2_0;
        break;
    case 3:
        queueId = GAUDI2_QUEUE_ID_DCORE0_TPC_3_0;
        break;
    case 4:
        queueId = GAUDI2_QUEUE_ID_DCORE0_TPC_4_0;
        break;
    case 5:
        queueId = GAUDI2_QUEUE_ID_DCORE0_TPC_5_0;
        break;
    case 6:
        queueId = GAUDI2_QUEUE_ID_DCORE1_TPC_0_0;
        break;
    case 7:
        queueId = GAUDI2_QUEUE_ID_DCORE1_TPC_1_0;
        break;
    case 8:
        queueId = GAUDI2_QUEUE_ID_DCORE1_TPC_2_0;
        break;
    case 9:
        queueId = GAUDI2_QUEUE_ID_DCORE1_TPC_3_0;
        break;
    case 10:
        queueId = GAUDI2_QUEUE_ID_DCORE1_TPC_4_0;
        break;
    case 11:
        queueId = GAUDI2_QUEUE_ID_DCORE1_TPC_5_0;
        break;
    case 12:
        queueId = GAUDI2_QUEUE_ID_DCORE2_TPC_0_0;
        break;
    case 13:
        queueId = GAUDI2_QUEUE_ID_DCORE2_TPC_1_0;
        break;
    case 14:
        queueId = GAUDI2_QUEUE_ID_DCORE2_TPC_2_0;
        break;
    case 15:
        queueId = GAUDI2_QUEUE_ID_DCORE2_TPC_3_0;
        break;
    case 16:
        queueId = GAUDI2_QUEUE_ID_DCORE2_TPC_4_0;
        break;
    case 17:
        queueId = GAUDI2_QUEUE_ID_DCORE2_TPC_5_0;
        break;
    case 18:
        queueId = GAUDI2_QUEUE_ID_DCORE3_TPC_0_0;
        break;
    case 19:
        queueId = GAUDI2_QUEUE_ID_DCORE3_TPC_1_0;
        break;
    case 20:
        queueId = GAUDI2_QUEUE_ID_DCORE3_TPC_2_0;
        break;
    case 21:
        queueId = GAUDI2_QUEUE_ID_DCORE3_TPC_3_0;
        break;
    case 22:
        queueId = GAUDI2_QUEUE_ID_DCORE3_TPC_4_0;
        break;
    case 23:
        queueId = GAUDI2_QUEUE_ID_DCORE3_TPC_5_0;
        break;
    default:
        assert(0);
    }
    return queueId;
}

unsigned Gaudi2Device::GetSyncObjectGroupSize() const { return c_syncObjectGroupSize; }

void Gaudi2Device::Qid2Qman(unsigned qid, uint64_t& base, unsigned& pqIdx) const
{
    switch (qid) {
        case GAUDI2_QUEUE_ID_PDMA_0_0:
        case GAUDI2_QUEUE_ID_PDMA_0_1:
        case GAUDI2_QUEUE_ID_PDMA_0_2:
        case GAUDI2_QUEUE_ID_PDMA_0_3:
            base  = mmPDMA0_QM_BASE;
            pqIdx = qid - GAUDI2_QUEUE_ID_PDMA_0_0;
            break;
        case GAUDI2_QUEUE_ID_PDMA_1_0:
        case GAUDI2_QUEUE_ID_PDMA_1_1:
        case GAUDI2_QUEUE_ID_PDMA_1_2:
        case GAUDI2_QUEUE_ID_PDMA_1_3:
            base  = mmPDMA1_QM_BASE;
            pqIdx = qid - GAUDI2_QUEUE_ID_PDMA_1_0;
            break;
        case GAUDI2_QUEUE_ID_DCORE0_EDMA_0_0:
        case GAUDI2_QUEUE_ID_DCORE0_EDMA_0_1:
        case GAUDI2_QUEUE_ID_DCORE0_EDMA_0_2:
        case GAUDI2_QUEUE_ID_DCORE0_EDMA_0_3:
            base  = mmDCORE0_EDMA0_QM_BASE;
            pqIdx = qid - GAUDI2_QUEUE_ID_DCORE0_EDMA_0_0;
            break;
        case GAUDI2_QUEUE_ID_DCORE0_EDMA_1_0:
        case GAUDI2_QUEUE_ID_DCORE0_EDMA_1_1:
        case GAUDI2_QUEUE_ID_DCORE0_EDMA_1_2:
        case GAUDI2_QUEUE_ID_DCORE0_EDMA_1_3:
            base  = mmDCORE0_EDMA1_QM_BASE;
            pqIdx = qid - GAUDI2_QUEUE_ID_DCORE0_EDMA_1_0;
            break;
        case GAUDI2_QUEUE_ID_DCORE0_TPC_0_0:
        case GAUDI2_QUEUE_ID_DCORE0_TPC_0_1:
        case GAUDI2_QUEUE_ID_DCORE0_TPC_0_2:
        case GAUDI2_QUEUE_ID_DCORE0_TPC_0_3:
            base  = mmDCORE0_TPC0_QM_BASE;
            pqIdx = qid - GAUDI2_QUEUE_ID_DCORE0_TPC_0_0;
            break;
        case GAUDI2_QUEUE_ID_DCORE0_TPC_1_0:
        case GAUDI2_QUEUE_ID_DCORE0_TPC_1_1:
        case GAUDI2_QUEUE_ID_DCORE0_TPC_1_2:
        case GAUDI2_QUEUE_ID_DCORE0_TPC_1_3:
            base  = mmDCORE0_TPC1_QM_BASE;
            pqIdx = qid - GAUDI2_QUEUE_ID_DCORE0_TPC_1_0;
            break;
        case GAUDI2_QUEUE_ID_DCORE0_TPC_2_0:
        case GAUDI2_QUEUE_ID_DCORE0_TPC_2_1:
        case GAUDI2_QUEUE_ID_DCORE0_TPC_2_2:
        case GAUDI2_QUEUE_ID_DCORE0_TPC_2_3:
            base  = mmDCORE0_TPC2_QM_BASE;
            pqIdx = qid - GAUDI2_QUEUE_ID_DCORE0_TPC_2_0;
            break;
        case GAUDI2_QUEUE_ID_DCORE0_TPC_3_0:
        case GAUDI2_QUEUE_ID_DCORE0_TPC_3_1:
        case GAUDI2_QUEUE_ID_DCORE0_TPC_3_2:
        case GAUDI2_QUEUE_ID_DCORE0_TPC_3_3:
            base  = mmDCORE0_TPC3_QM_BASE;
            pqIdx = qid - GAUDI2_QUEUE_ID_DCORE0_TPC_3_0;
            break;
        case GAUDI2_QUEUE_ID_DCORE0_TPC_4_0:
        case GAUDI2_QUEUE_ID_DCORE0_TPC_4_1:
        case GAUDI2_QUEUE_ID_DCORE0_TPC_4_2:
        case GAUDI2_QUEUE_ID_DCORE0_TPC_4_3:
            base  = mmDCORE0_TPC4_QM_BASE;
            pqIdx = qid - GAUDI2_QUEUE_ID_DCORE0_TPC_4_0;
            break;
        case GAUDI2_QUEUE_ID_DCORE0_TPC_5_0:
        case GAUDI2_QUEUE_ID_DCORE0_TPC_5_1:
        case GAUDI2_QUEUE_ID_DCORE0_TPC_5_2:
        case GAUDI2_QUEUE_ID_DCORE0_TPC_5_3:
            base  = mmDCORE0_TPC5_QM_BASE;
            pqIdx = qid - GAUDI2_QUEUE_ID_DCORE0_TPC_5_0;
            break;
        case GAUDI2_QUEUE_ID_DCORE0_TPC_6_0:
        case GAUDI2_QUEUE_ID_DCORE0_TPC_6_1:
        case GAUDI2_QUEUE_ID_DCORE0_TPC_6_2:
        case GAUDI2_QUEUE_ID_DCORE0_TPC_6_3:
            base  = mmDCORE0_TPC6_QM_BASE;
            pqIdx = qid - GAUDI2_QUEUE_ID_DCORE0_TPC_5_0;
            break;
        case GAUDI2_QUEUE_ID_DCORE1_EDMA_0_0:
        case GAUDI2_QUEUE_ID_DCORE1_EDMA_0_1:
        case GAUDI2_QUEUE_ID_DCORE1_EDMA_0_2:
        case GAUDI2_QUEUE_ID_DCORE1_EDMA_0_3:
            base  = mmDCORE1_EDMA0_QM_BASE;
            pqIdx = qid - GAUDI2_QUEUE_ID_DCORE1_EDMA_0_0;
            break;
        case GAUDI2_QUEUE_ID_DCORE1_EDMA_1_0:
        case GAUDI2_QUEUE_ID_DCORE1_EDMA_1_1:
        case GAUDI2_QUEUE_ID_DCORE1_EDMA_1_2:
        case GAUDI2_QUEUE_ID_DCORE1_EDMA_1_3:
            base  = mmDCORE1_EDMA1_QM_BASE;
            pqIdx = qid - GAUDI2_QUEUE_ID_DCORE1_EDMA_1_0;
            break;
        case GAUDI2_QUEUE_ID_DCORE1_TPC_0_0:
        case GAUDI2_QUEUE_ID_DCORE1_TPC_0_1:
        case GAUDI2_QUEUE_ID_DCORE1_TPC_0_2:
        case GAUDI2_QUEUE_ID_DCORE1_TPC_0_3:
            base  = mmDCORE1_TPC0_QM_BASE;
            pqIdx = qid - GAUDI2_QUEUE_ID_DCORE1_TPC_0_0;
            break;
        case GAUDI2_QUEUE_ID_DCORE1_TPC_1_0:
        case GAUDI2_QUEUE_ID_DCORE1_TPC_1_1:
        case GAUDI2_QUEUE_ID_DCORE1_TPC_1_2:
        case GAUDI2_QUEUE_ID_DCORE1_TPC_1_3:
            base  = mmDCORE1_TPC1_QM_BASE;
            pqIdx = qid - GAUDI2_QUEUE_ID_DCORE1_TPC_1_0;
            break;
        case GAUDI2_QUEUE_ID_DCORE1_TPC_2_0:
        case GAUDI2_QUEUE_ID_DCORE1_TPC_2_1:
        case GAUDI2_QUEUE_ID_DCORE1_TPC_2_2:
        case GAUDI2_QUEUE_ID_DCORE1_TPC_2_3:
            base  = mmDCORE1_TPC2_QM_BASE;
            pqIdx = qid - GAUDI2_QUEUE_ID_DCORE1_TPC_2_0;
            break;
        case GAUDI2_QUEUE_ID_DCORE1_TPC_3_0:
        case GAUDI2_QUEUE_ID_DCORE1_TPC_3_1:
        case GAUDI2_QUEUE_ID_DCORE1_TPC_3_2:
        case GAUDI2_QUEUE_ID_DCORE1_TPC_3_3:
            base  = mmDCORE1_TPC3_QM_BASE;
            pqIdx = qid - GAUDI2_QUEUE_ID_DCORE1_TPC_3_0;
            break;
        case GAUDI2_QUEUE_ID_DCORE1_TPC_4_0:
        case GAUDI2_QUEUE_ID_DCORE1_TPC_4_1:
        case GAUDI2_QUEUE_ID_DCORE1_TPC_4_2:
        case GAUDI2_QUEUE_ID_DCORE1_TPC_4_3:
            base  = mmDCORE1_TPC4_QM_BASE;
            pqIdx = qid - GAUDI2_QUEUE_ID_DCORE1_TPC_4_0;
            break;
        case GAUDI2_QUEUE_ID_DCORE1_TPC_5_0:
        case GAUDI2_QUEUE_ID_DCORE1_TPC_5_1:
        case GAUDI2_QUEUE_ID_DCORE1_TPC_5_2:
        case GAUDI2_QUEUE_ID_DCORE1_TPC_5_3:
            base  = mmDCORE1_TPC5_QM_BASE;
            pqIdx = qid - GAUDI2_QUEUE_ID_DCORE1_TPC_5_0;
            break;
        case GAUDI2_QUEUE_ID_DCORE2_EDMA_0_0:
        case GAUDI2_QUEUE_ID_DCORE2_EDMA_0_1:
        case GAUDI2_QUEUE_ID_DCORE2_EDMA_0_2:
        case GAUDI2_QUEUE_ID_DCORE2_EDMA_0_3:
            base  = mmDCORE2_EDMA0_QM_BASE;
            pqIdx = qid - GAUDI2_QUEUE_ID_DCORE2_EDMA_0_0;
            break;
        case GAUDI2_QUEUE_ID_DCORE2_EDMA_1_0:
        case GAUDI2_QUEUE_ID_DCORE2_EDMA_1_1:
        case GAUDI2_QUEUE_ID_DCORE2_EDMA_1_2:
        case GAUDI2_QUEUE_ID_DCORE2_EDMA_1_3:
            base  = mmDCORE2_EDMA1_QM_BASE;
            pqIdx = qid - GAUDI2_QUEUE_ID_DCORE2_EDMA_1_0;
            break;
        case GAUDI2_QUEUE_ID_DCORE2_TPC_0_0:
        case GAUDI2_QUEUE_ID_DCORE2_TPC_0_1:
        case GAUDI2_QUEUE_ID_DCORE2_TPC_0_2:
        case GAUDI2_QUEUE_ID_DCORE2_TPC_0_3:
            base  = mmDCORE2_TPC0_QM_BASE;
            pqIdx = qid - GAUDI2_QUEUE_ID_DCORE2_TPC_0_0;
            break;
        case GAUDI2_QUEUE_ID_DCORE2_TPC_1_0:
        case GAUDI2_QUEUE_ID_DCORE2_TPC_1_1:
        case GAUDI2_QUEUE_ID_DCORE2_TPC_1_2:
        case GAUDI2_QUEUE_ID_DCORE2_TPC_1_3:
            base  = mmDCORE2_TPC1_QM_BASE;
            pqIdx = qid - GAUDI2_QUEUE_ID_DCORE2_TPC_1_0;
            break;
        case GAUDI2_QUEUE_ID_DCORE2_TPC_2_0:
        case GAUDI2_QUEUE_ID_DCORE2_TPC_2_1:
        case GAUDI2_QUEUE_ID_DCORE2_TPC_2_2:
        case GAUDI2_QUEUE_ID_DCORE2_TPC_2_3:
            base  = mmDCORE2_TPC2_QM_BASE;
            pqIdx = qid - GAUDI2_QUEUE_ID_DCORE2_TPC_2_0;
            break;
        case GAUDI2_QUEUE_ID_DCORE2_TPC_3_0:
        case GAUDI2_QUEUE_ID_DCORE2_TPC_3_1:
        case GAUDI2_QUEUE_ID_DCORE2_TPC_3_2:
        case GAUDI2_QUEUE_ID_DCORE2_TPC_3_3:
            base  = mmDCORE2_TPC3_QM_BASE;
            pqIdx = qid - GAUDI2_QUEUE_ID_DCORE2_TPC_3_0;
            break;
        case GAUDI2_QUEUE_ID_DCORE2_TPC_4_0:
        case GAUDI2_QUEUE_ID_DCORE2_TPC_4_1:
        case GAUDI2_QUEUE_ID_DCORE2_TPC_4_2:
        case GAUDI2_QUEUE_ID_DCORE2_TPC_4_3:
            base  = mmDCORE2_TPC4_QM_BASE;
            pqIdx = qid - GAUDI2_QUEUE_ID_DCORE2_TPC_4_0;
            break;
        case GAUDI2_QUEUE_ID_DCORE2_TPC_5_0:
        case GAUDI2_QUEUE_ID_DCORE2_TPC_5_1:
        case GAUDI2_QUEUE_ID_DCORE2_TPC_5_2:
        case GAUDI2_QUEUE_ID_DCORE2_TPC_5_3:
            base  = mmDCORE2_TPC5_QM_BASE;
            pqIdx = qid - GAUDI2_QUEUE_ID_DCORE2_TPC_5_0;
            break;
        case GAUDI2_QUEUE_ID_DCORE3_EDMA_0_0:
        case GAUDI2_QUEUE_ID_DCORE3_EDMA_0_1:
        case GAUDI2_QUEUE_ID_DCORE3_EDMA_0_2:
        case GAUDI2_QUEUE_ID_DCORE3_EDMA_0_3:
            base  = mmDCORE3_EDMA0_QM_BASE;
            pqIdx = qid - GAUDI2_QUEUE_ID_DCORE3_EDMA_0_0;
            break;
        case GAUDI2_QUEUE_ID_DCORE3_EDMA_1_0:
        case GAUDI2_QUEUE_ID_DCORE3_EDMA_1_1:
        case GAUDI2_QUEUE_ID_DCORE3_EDMA_1_2:
        case GAUDI2_QUEUE_ID_DCORE3_EDMA_1_3:
            base  = mmDCORE3_EDMA1_QM_BASE;
            pqIdx = qid - GAUDI2_QUEUE_ID_DCORE3_EDMA_1_0;
            break;
        case GAUDI2_QUEUE_ID_DCORE3_TPC_0_0:
        case GAUDI2_QUEUE_ID_DCORE3_TPC_0_1:
        case GAUDI2_QUEUE_ID_DCORE3_TPC_0_2:
        case GAUDI2_QUEUE_ID_DCORE3_TPC_0_3:
            base  = mmDCORE3_TPC0_QM_BASE;
            pqIdx = qid - GAUDI2_QUEUE_ID_DCORE3_TPC_0_0;
            break;
        case GAUDI2_QUEUE_ID_DCORE3_TPC_1_0:
        case GAUDI2_QUEUE_ID_DCORE3_TPC_1_1:
        case GAUDI2_QUEUE_ID_DCORE3_TPC_1_2:
        case GAUDI2_QUEUE_ID_DCORE3_TPC_1_3:
            base  = mmDCORE3_TPC1_QM_BASE;
            pqIdx = qid - GAUDI2_QUEUE_ID_DCORE3_TPC_1_0;
            break;
        case GAUDI2_QUEUE_ID_DCORE3_TPC_2_0:
        case GAUDI2_QUEUE_ID_DCORE3_TPC_2_1:
        case GAUDI2_QUEUE_ID_DCORE3_TPC_2_2:
        case GAUDI2_QUEUE_ID_DCORE3_TPC_2_3:
            base  = mmDCORE3_TPC2_QM_BASE;
            pqIdx = qid - GAUDI2_QUEUE_ID_DCORE3_TPC_2_0;
            break;
        case GAUDI2_QUEUE_ID_DCORE3_TPC_3_0:
        case GAUDI2_QUEUE_ID_DCORE3_TPC_3_1:
        case GAUDI2_QUEUE_ID_DCORE3_TPC_3_2:
        case GAUDI2_QUEUE_ID_DCORE3_TPC_3_3:
            base  = mmDCORE3_TPC3_QM_BASE;
            pqIdx = qid - GAUDI2_QUEUE_ID_DCORE3_TPC_3_0;
            break;
        case GAUDI2_QUEUE_ID_DCORE3_TPC_4_0:
        case GAUDI2_QUEUE_ID_DCORE3_TPC_4_1:
        case GAUDI2_QUEUE_ID_DCORE3_TPC_4_2:
        case GAUDI2_QUEUE_ID_DCORE3_TPC_4_3:
            base  = mmDCORE3_TPC4_QM_BASE;
            pqIdx = qid - GAUDI2_QUEUE_ID_DCORE3_TPC_4_0;
            break;
        case GAUDI2_QUEUE_ID_DCORE3_TPC_5_0:
        case GAUDI2_QUEUE_ID_DCORE3_TPC_5_1:
        case GAUDI2_QUEUE_ID_DCORE3_TPC_5_2:
        case GAUDI2_QUEUE_ID_DCORE3_TPC_5_3:
            base  = mmDCORE3_TPC5_QM_BASE;
            pqIdx = qid - GAUDI2_QUEUE_ID_DCORE3_TPC_5_0;
            break;
        case GAUDI2_QUEUE_ID_CPU_PQ: assert(0 && "QID GAUDI2_QUEUE_ID_CPU_PQ mustn't be used"); break;
        default: assert(0 && "Unknown QID");
    }
}

unsigned Gaudi2Device::GetQidSize() const { return GAUDI2_QUEUE_ID_SIZE; }

unsigned Gaudi2Device::GetDMAInQid() const { return GAUDI2_QUEUE_ID_PDMA_0_0; }

unsigned Gaudi2Device::GetDMAOutQid() const { return GAUDI2_QUEUE_ID_PDMA_1_0; }

unsigned Gaudi2Device::GetQmanFenceOffset(unsigned fenceIdx, unsigned streamId) const
{
    unsigned offset;
    switch (fenceIdx)
    {
    case 0:
        offset = (unsigned)offsetof(gaudi2::block_qman, cp_fence0_rdata[streamId]);
        break;
    case 1:
        offset = (unsigned)offsetof(gaudi2::block_qman, cp_fence1_rdata[streamId]);
        break;
    case 2:
        offset = (unsigned)offsetof(gaudi2::block_qman, cp_fence2_rdata[streamId]);
        break;
    case 3:
        offset = (unsigned)offsetof(gaudi2::block_qman, cp_fence3_rdata[streamId]);
        break;
    default:
        assert(0 && "invalid fence idx");
        offset = (unsigned)offsetof(gaudi2::block_qman, cp_fence0_rdata[streamId]);
        break;
    }
    return offset;
}

uint64_t Gaudi2Device::GetSyncMngrVarAddr(std::string varName, unsigned idx) const
{
    unsigned offset = 0;
    uint64_t addr = 0;
    if (varName != "sob_obj")
    {
        idx += GetMonitorObjectBaseIndex();
        assert(idx < c_monitorObjNr && "invalid monitor index");
    }
    if (varName == "mon_pay_addrl")
    {
        offset = (unsigned)offsetof(gaudi2::block_sob_objs, mon_pay_addrl[idx]);
        addr = c_syncObjectsBaseAddr + offset;
        assert(addr > 0x1000007FFC108000 && addr < 0x1000007FFC10A000);
    }
    else if (varName == "mon_pay_addrh")
    {
        offset = (unsigned)offsetof(gaudi2::block_sob_objs, mon_pay_addrh[idx]);
        addr = c_syncObjectsBaseAddr + offset;
        assert(addr > 0x1000007FFC10A000 && addr < 0x1000007FFC10C000);
    }
    else if (varName == "mon_pay_data")
    {
        offset = (unsigned)offsetof(gaudi2::block_sob_objs, mon_pay_data[idx]);
        addr = c_syncObjectsBaseAddr + offset;
        assert(addr > 0x1000007FFC10C000 && addr < 0x1000007FFC10E000);
    }
    else if (varName == "mon_cfg")
    {
        offset = (unsigned)offsetof(gaudi2::block_sob_objs, mon_config[idx]);
        addr = c_syncObjectsBaseAddr + offset;
    }

    else if (varName == "mon_arm")
    {
        offset = (unsigned)offsetof(gaudi2::block_sob_objs, mon_arm[idx]);
        addr = c_syncObjectsBaseAddr + offset;
        assert(addr > 0x1000007FFC10E000 && addr < 0x1000007FFC110000);
    }
    else if (varName == "sob_obj")
    {
        assert(idx < c_syncObjNr && "invalid sync object index");
        offset = (unsigned)offsetof(gaudi2::block_sob_objs, sob_obj[idx]);
        addr = c_syncObjectsBaseAddr + offset;
        assert(addr > 0x1000007FFC100000 && addr < 0x1000007FFC108000);
    }
    else
    {
        assert(0 && "invalid var name");
    }
    return addr;
}

unsigned Gaudi2Device::GetDmaDownVarOffset(std::string varName) const
{
    unsigned offset = 0;
    if (varName == "wr_comp_addr_lo")
    {
        offset = (unsigned)offsetof(gaudi2::block_dma_core, ctx.wr_comp_addr_lo);
    }
    else if (varName == "wr_comp_addr_hi")
    {
        offset = (unsigned)offsetof(block_dma_core, ctx.wr_comp_addr_hi);
    }
    else if (varName == "wr_comp_wdata")
    {
        offset = (unsigned)offsetof(block_dma_core, ctx.wr_comp_wdata);
    }
    else
    {
        assert(0 && "invalid var name");
    }
    offset += mmPDMA0_CORE_BASE & 0xffff;
    return offset;
}

void Gaudi2Device::GetTpcTabOffset(int TabIdx, uint32_t* baseAddrLow, uint32_t* baseAddrHigh) const
{
    switch (TabIdx)
    {
    case 0: // 256b special functions
        *baseAddrLow =
            c_tpcCfgBlockOffset + (unsigned)offsetof(block_tpc, lut_func256_base_addr_lo);
        *baseAddrHigh =
            c_tpcCfgBlockOffset + (unsigned)offsetof(block_tpc, lut_func256_base_addr_hi);
        break;
    case 1: // 128b special functions
        *baseAddrLow =
            c_tpcCfgBlockOffset + (unsigned)offsetof(block_tpc, lut_func128_base_addr_lo);
        *baseAddrHigh =
            c_tpcCfgBlockOffset + (unsigned)offsetof(block_tpc, lut_func128_base_addr_hi);
        break;
    case 2: // 64b special functions
        *baseAddrLow = c_tpcCfgBlockOffset + (unsigned)offsetof(block_tpc, lut_func64_base_addr_lo);
        *baseAddrHigh =
            c_tpcCfgBlockOffset + (unsigned)offsetof(block_tpc, lut_func64_base_addr_hi);
        break;
    case 3: // 32b special functions
        *baseAddrLow = c_tpcCfgBlockOffset + (unsigned)offsetof(block_tpc, lut_func32_base_addr_lo);
        *baseAddrHigh =
            c_tpcCfgBlockOffset + (unsigned)offsetof(block_tpc, lut_func32_base_addr_hi);
        break;
    default:
        assert(0);
    }
    return;
}

unsigned Gaudi2Device::GetTpcCfgVarOffset(std::string varName) const
{
    unsigned offset = 0;
    if (varName == "qm_tensor_0")
    {
        offset = (unsigned)offsetof(block_tpc, qm_tensor_0);
    }
    else if (varName == "sm_base_address_high")
    {
        offset = (unsigned)offsetof(block_tpc, sm_base_address_high);
    }
    else if (varName == "tpc_cmd")
    {
        offset = (unsigned)offsetof(block_tpc, tpc_cmd);
    }
    else if (varName == "tpc_execute")
    {
        offset = (unsigned)offsetof(block_tpc, tpc_execute);
    }
    else if (varName == "icache_base_adderess_low")
    {
        offset = (unsigned)offsetof(block_tpc, icache_base_adderess_low);
    }
    else if (varName == "icache_base_adderess_high")
    {
        offset = (unsigned)offsetof(block_tpc, icache_base_adderess_high);
    }
    else
    {
        assert(0 && "invalid var name");
    }
    return c_tpcCfgBlockOffset + offset;
}

unsigned Gaudi2Device::GetMonArmRawVal(uint8_t mask, uint8_t sid, unsigned sod, unsigned sop) const
{
    sob_objs::reg_mon_arm monArm;
    memset(&monArm, 0, sizeof(sob_objs::reg_mon_arm));
    monArm.mask = mask;
    monArm.sid  = sid;
    monArm.sod  = sod;
    monArm.sop  = sop;

    return monArm._raw;
}

unsigned Gaudi2Device::GetMonCfgRawVal(unsigned msbSid) const
{
    sob_objs::reg_mon_config monCfg;
    memset(&monCfg, 0, sizeof(sob_objs::reg_mon_config));
    monCfg.msb_sid = msbSid;

    return monCfg._raw;
}
std::shared_ptr<::CPCommand::CpDma> Gaudi2Device::GenCpDma(uint64_t src, uint32_t size) const
{
    std::shared_ptr<::CPCommand::CpDma> pCommand;
    pCommand = std::make_shared<CPCommand::CpDmaGen6>(src, size);
    return pCommand;
}

std::shared_ptr<::CPCommand::Fence> Gaudi2Device::GenFence(unsigned id, uint8_t targetVal,
                                                        unsigned decVal) const
{
    std::shared_ptr<::CPCommand::Fence> pCommand;
    pCommand = std::make_shared<CPCommand::FenceGen6>(id, targetVal, decVal);
    return pCommand;
}

std::shared_ptr<::CPCommand::LinDma> Gaudi2Device::GenLinDma(uint64_t dst, uint64_t src,
                                                          uint32_t tsize, unsigned dmaDir,
                                                          uint16_t ctxId, bool wrComp) const
{
    // dmaDir not required for Gaudi, only for Goya
    std::shared_ptr<::CPCommand::LinDma> pCommand;
    pCommand          = std::make_shared<CPCommand::LinDmaGen6>(dst, src, tsize, 0, wrComp);
    pCommand->m_ctxId = ctxId;
    return pCommand;
}

std::shared_ptr<::CPCommand::MsgLong> Gaudi2Device::GenMsgLong(uint64_t addr, uint32_t value, bool mb,
                                                            bool rb, bool eb) const
{
    std::shared_ptr<::CPCommand::MsgLong> pCommand;
    pCommand = std::make_shared<CPCommand::MsgLongGen6>(addr, value, mb, eb);
    return pCommand;
}

std::shared_ptr<::CPCommand::WReg32> Gaudi2Device::GenWReg32(uint16_t offset, uint32_t value, bool mb,
                                                             bool rb, bool eb) const
{
    std::shared_ptr<::CPCommand::WReg32> pCommand;
    pCommand = std::make_shared<CPCommand::WReg32Gen6>(offset, value, mb, eb);
    return pCommand;
}

std::shared_ptr<::CPCommand::WRegBulk> Gaudi2Device::GenWRegBulk(uint16_t offset, uint32_t* values,
                                                              unsigned numValues) const
{
    std::shared_ptr<::CPCommand::WRegBulk> pCommand;
    pCommand = std::make_shared<CPCommand::WRegBulkGen6>(offset, values, numValues);
    return pCommand;
}

size_t Gaudi2Device::GetTpcDescSize() const { return sizeof(Gaudi2TpcDesc); }

void Gaudi2Device::WriteSrf(HWAbstractionLayer::TpcDescHandle tpcDesc, const uint32_t* params,
                           unsigned paramsNr) const
{
    memcpy(&(((Gaudi2TpcDesc*)(tpcDesc))->m_desc.srf[0]), params, paramsNr * sizeof(uint32_t));
}

void Gaudi2Device::WriteKernelCfg(HWAbstractionLayer::TpcDescHandle tpcDesc, uint32_t smallVlm) const
{
    ((Gaudi2TpcDesc*)(tpcDesc))->m_desc.kernel_config.small_vlm = smallVlm;
    ((Gaudi2TpcDesc*)(tpcDesc))->m_desc.kernel_config.aso_evict_l0 = 1;
    // TODO: load actual count.
    ((Gaudi2TpcDesc*)(tpcDesc))->m_desc.kernel_config.num_valid_srfs = 32;

    // Don't change rate limiter, setting default values.
    ((Gaudi2TpcDesc*)(tpcDesc))->m_desc.kernel_config.rd_rate_limit_rst_token = 0x8;
    ((Gaudi2TpcDesc*)(tpcDesc))->m_desc.kernel_config.wr_rate_limit_rst_token = 0x6;
    ((Gaudi2TpcDesc*)(tpcDesc))->m_desc.kernel_config.irf_32bit_compatibility = 0x1;
}

void Gaudi2Device::WriteKernelAddr(HWAbstractionLayer::TpcDescHandle tpcDesc,
                                  uint64_t                          kernelAddr) const
{
    ((Gaudi2TpcDesc*)(tpcDesc))->m_desc.kernel_base_address_low._raw =
        (uint32_t)(kernelAddr & 0xffffffff);
    ((Gaudi2TpcDesc*)(tpcDesc))->m_desc.kernel_base_address_high._raw = (uint32_t)(kernelAddr >> 32);
}

void Gaudi2Device::WriteTensorDesc(HWAbstractionLayer::TpcDescHandle tpcDesc,
                                  TensorDescriptor& tensorDesc, unsigned tensorId) const
{
    memcpy(&(((Gaudi2TpcDesc*)(tpcDesc))->m_tensors[tensorId]), &tensorDesc,
           sizeof(TensorDescriptor));
}

void Gaudi2Device::WriteTpcJobDesc(HWAbstractionLayer::TpcDescHandle tpcDesc,
                                  const IndexSpace& partition, uint32_t soAddr,
                                  uint32_t soMsg, bool updatePrintfAddr,
                                  int printfTensorIdx) const
{
    // load IRF0/1
    ((Gaudi2TpcDesc*)(tpcDesc))->m_desc.tid_size_dim_0.v = partition.size[0];
    ((Gaudi2TpcDesc*)(tpcDesc))->m_desc.tid_size_dim_1.v = partition.size[1];
    ((Gaudi2TpcDesc*)(tpcDesc))->m_desc.tid_size_dim_2.v = partition.size[2];
    ((Gaudi2TpcDesc*)(tpcDesc))->m_desc.tid_size_dim_3.v = partition.size[3];
    ((Gaudi2TpcDesc*)(tpcDesc))->m_desc.tid_size_dim_4.v = partition.size[4];

    ((Gaudi2TpcDesc*)(tpcDesc))->m_desc.tid_base_dim_0.v = partition.offset[0];
    ((Gaudi2TpcDesc*)(tpcDesc))->m_desc.tid_base_dim_1.v = partition.offset[1];
    ((Gaudi2TpcDesc*)(tpcDesc))->m_desc.tid_base_dim_2.v = partition.offset[2];
    ((Gaudi2TpcDesc*)(tpcDesc))->m_desc.tid_base_dim_3.v = partition.offset[3];
    ((Gaudi2TpcDesc*)(tpcDesc))->m_desc.tid_base_dim_4.v = partition.offset[4];

    ((Gaudi2TpcDesc*)(tpcDesc))->m_so.addr.v       = soAddr;
    ((Gaudi2TpcDesc*)(tpcDesc))->m_so.message._raw = soMsg;

}

uint32_t Gaudi2Device::GenTpcCmd() const
{
    gaudi2::tpc::reg_tpc_cmd command;
    memset(&command, 0, sizeof(command));
    command.icache_invalidate    = 1;
    command.dcache_invalidate    = 1;
    command.lcache_invalidate    = 1;
    command.tcache_invalidate    = 1;
    command.icache_prefetch_64kb = 0;
    return command._raw;
}

uint32_t Gaudi2Device::GetTpcTensorConfig() const {
  struct gaudi2::tpc_tensor::reg_tensor_config config;
  config._raw = 0;
  config.data_type = TensorDataType::TensorDT_FP32;
  config.valid_dim_mask = 0xF;
  config.last_dim = 3;
  return config._raw;
}
} // namespace gaudi2
