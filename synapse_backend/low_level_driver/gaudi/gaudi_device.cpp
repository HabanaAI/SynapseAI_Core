/* SPDX-License-Identifier: MIT
 *
 * Copyright 2016-2021 HabanaLabs, Ltd.
 * All Rights Reserved.
 *
 */

#include <stddef.h>
#include <misc/habanalabs.h>

#include "TensorDescriptor.h"
#include "gaudi_device.h"
#include "SpecialFuncCoefficients.h"
#include "gaudi/SpecialFuncCoefficients_defGen2.h"
#include "gaudi/asic_reg_structs/sync_mngr_regs.h"
#include "gaudi/asic_reg_structs/qman_regs.h"
#include "gaudi/asic_reg_structs/dma_core_regs.h"
#include "gaudi/asic_reg_structs/tpc_regs.h"
#include "gaudi_packet_gen.h"
#include "gaudi/asic_reg/gaudi_blocks.h"
#include "gaudi/gaudi_tpc_descriptor.h"
#include "synapse_common_types.h"

namespace gaudi
{
const unsigned GaudiDevice::c_tpcNr               = 8;
const unsigned GaudiDevice::c_syncObjNr           = 2048;
const unsigned GaudiDevice::c_monitorObjNr        = 512;
const unsigned GaudiDevice::c_syncObjectGroupSize = 8;
const uint64_t GaudiDevice::c_syncManagerBase     = mmSYNC_MNGR_GLBL_E_N_BASE;
const uint64_t GaudiDevice::c_syncObjectsBaseAddr =
    c_syncManagerBase + 0x2000ull; // from soc_online.
constexpr uint64_t GaudiDevice::GetSyncObjectAddress(int synObjIndex)
{
    return c_syncObjectsBaseAddr + (c_syncObjectSizeInBytes * synObjIndex);
}

unsigned GaudiDevice::GetTensorSizeFromDesc(TensorDescriptor& desc) const
{
    unsigned              size      = 1;
    unsigned dims = tpc_gaudi::get_TensorDescriptorLastDim(desc.configuration) + 1;
    for (unsigned i = 0; i < dims; i++)
    {
        size *= desc.dimDescriptors[i].size;
    }
    // multiply by element size to get result in bytes
    unsigned descElement = tpc_gaudi::get_TensorDescriptorElementSizeType(desc.configuration);
    unsigned elementSize =
        tpc_gaudi::get_ElementSizeInBytesFromDataType((TensorDataType)descElement);
    size *= elementSize;
    return size;
}

unsigned GaudiDevice::GetTensorSizeFromDesc(TensorDescriptor& desc0, TensorDescriptor& desc1) const
{
    unsigned              size      = 1;
    unsigned dims0 = tpc_gaudi::get_TensorDescriptorLastDim(desc0.configuration) + 1;
    unsigned dims1 = tpc_gaudi::get_TensorDescriptorLastDim(desc1.configuration) + 1;
    for (unsigned i = 0; i < dims0; i++)
    {
        size *= desc0.dimDescriptors[i].size;
    }

    for (unsigned i = 0; i < dims1; i++)
    {
        size *= desc1.dimDescriptors[i].size;
    }

    // multiply by element size to get result in bytes
    unsigned descElement = tpc_gaudi::get_TensorDescriptorElementSizeType(desc0.configuration);
    unsigned elementSize =
            tpc_gaudi::get_ElementSizeInBytesFromDataType((TensorDataType)descElement);
    size *= elementSize;

    return size;
}

unsigned GaudiDevice::GetSpecialFuncTabNr() const
{
    return SPECIAL_FUNC_NUM_OF_DIFFERENT_INTERVALS;
}

void GaudiDevice::GetSpecialFuncTabSizes(uint32_t* sizes, unsigned sizesLen) const
{
    assert(sizesLen >= 4);
    sizes[0] = SPECIAL_FUNC256_SIZE_BYTES;
    sizes[1] = SPECIAL_FUNC128_SIZE_BYTES;
    sizes[2] = SPECIAL_FUNC64_SIZE_BYTES;
    sizes[3] = SPECIAL_FUNC32_SIZE_BYTES;
}

void GaudiDevice::CopySpecialFuncTab(
    std::vector<std::vector<uint8_t>>& specialFunctionCoefficients) const
{
    specialFunctionCoefficients.resize(SPECIAL_FUNC_NUM_OF_DIFFERENT_INTERVALS);
    ::tpc_gaudi::buildSpecialFunctionCoefficients(specialFunctionCoefficients);
}

int GaudiDevice::GetDmaUpSyncObjectIndex() const
{
    return m_firstAvailSyncObj + c_syncObjectGroupSize;
}

uint64_t GaudiDevice::GetDmaUpSyncObjectAddr() const
{
    return GetSyncObjectAddress(m_firstAvailSyncObj + c_syncObjectGroupSize);
}

int GaudiDevice::GetDmaDownSyncObjectIndex() const { return m_firstAvailSyncObj; }

uint64_t GaudiDevice::GetDmaDownSyncObjectAddr() const
{
    return GetSyncObjectAddress(m_firstAvailSyncObj);
}

uint64_t GaudiDevice::GetSyncManagerBaseAddr() const { return c_syncManagerBase; }

int GaudiDevice::GetMonitorObjectBaseIndex() const { return m_firstAvailMonitor; }

unsigned GaudiDevice::GetTPCNr() const { return c_tpcNr; }

unsigned GaudiDevice::GetTPCQueueId(unsigned tpcId) const
{
    unsigned queueId;
    switch (tpcId)
    {
    case 0:
        queueId = GAUDI_QUEUE_ID_TPC_0_0;
        break;
    case 1:
        queueId = GAUDI_QUEUE_ID_TPC_1_0;
        break;
    case 2:
        queueId = GAUDI_QUEUE_ID_TPC_2_0;
        break;
    case 3:
        queueId = GAUDI_QUEUE_ID_TPC_3_0;
        break;
    case 4:
        queueId = GAUDI_QUEUE_ID_TPC_4_0;
        break;
    case 5:
        queueId = GAUDI_QUEUE_ID_TPC_5_0;
        break;
    case 6:
        queueId = GAUDI_QUEUE_ID_TPC_6_0;
        break;
    case 7:
        queueId = GAUDI_QUEUE_ID_TPC_7_0;
        break;
    default:
        assert(0);
        queueId = GAUDI_QUEUE_ID_TPC_0_0;
        break;
    }
    return queueId;
}

unsigned GaudiDevice::GetSyncObjectGroupSize() const { return c_syncObjectGroupSize; }

void GaudiDevice::Qid2Qman(unsigned qid, uint64_t& base, unsigned& pqIdx) const
{
    switch (qid)
    {
    case GAUDI_QUEUE_ID_DMA_0_0:
    case GAUDI_QUEUE_ID_DMA_0_1:
    case GAUDI_QUEUE_ID_DMA_0_2:
    case GAUDI_QUEUE_ID_DMA_0_3:
        base  = mmDMA0_QM_BASE;
        pqIdx = qid - GAUDI_QUEUE_ID_DMA_0_0;
        break;
    case GAUDI_QUEUE_ID_DMA_1_0:
    case GAUDI_QUEUE_ID_DMA_1_1:
    case GAUDI_QUEUE_ID_DMA_1_2:
    case GAUDI_QUEUE_ID_DMA_1_3:
        base  = mmDMA1_QM_BASE;
        pqIdx = qid - GAUDI_QUEUE_ID_DMA_1_0;
        break;
    case GAUDI_QUEUE_ID_CPU_PQ:
        assert(0);
        break;
    case GAUDI_QUEUE_ID_DMA_2_0:
    case GAUDI_QUEUE_ID_DMA_2_1:
    case GAUDI_QUEUE_ID_DMA_2_2:
    case GAUDI_QUEUE_ID_DMA_2_3:
        base  = mmDMA2_QM_BASE;
        pqIdx = qid - GAUDI_QUEUE_ID_DMA_2_0;
        break;
    case GAUDI_QUEUE_ID_DMA_3_0:
    case GAUDI_QUEUE_ID_DMA_3_1:
    case GAUDI_QUEUE_ID_DMA_3_2:
    case GAUDI_QUEUE_ID_DMA_3_3:
        base  = mmDMA3_QM_BASE;
        pqIdx = qid - GAUDI_QUEUE_ID_DMA_3_0;
        break;
    case GAUDI_QUEUE_ID_DMA_4_0:
    case GAUDI_QUEUE_ID_DMA_4_1:
    case GAUDI_QUEUE_ID_DMA_4_2:
    case GAUDI_QUEUE_ID_DMA_4_3:
        base  = mmDMA4_QM_BASE;
        pqIdx = qid - GAUDI_QUEUE_ID_DMA_4_0;
        break;
    case GAUDI_QUEUE_ID_DMA_5_0:
    case GAUDI_QUEUE_ID_DMA_5_1:
    case GAUDI_QUEUE_ID_DMA_5_2:
    case GAUDI_QUEUE_ID_DMA_5_3:
        base  = mmDMA5_QM_BASE;
        pqIdx = qid - GAUDI_QUEUE_ID_DMA_5_0;
        break;
    case GAUDI_QUEUE_ID_DMA_6_0:
    case GAUDI_QUEUE_ID_DMA_6_1:
    case GAUDI_QUEUE_ID_DMA_6_2:
    case GAUDI_QUEUE_ID_DMA_6_3:
        base  = mmDMA6_QM_BASE;
        pqIdx = qid - GAUDI_QUEUE_ID_DMA_6_0;
        break;
    case GAUDI_QUEUE_ID_DMA_7_0:
    case GAUDI_QUEUE_ID_DMA_7_1:
    case GAUDI_QUEUE_ID_DMA_7_2:
    case GAUDI_QUEUE_ID_DMA_7_3:
        base  = mmDMA7_QM_BASE;
        pqIdx = qid - GAUDI_QUEUE_ID_DMA_7_0;
        break;
    case GAUDI_QUEUE_ID_MME_0_0:
    case GAUDI_QUEUE_ID_MME_0_1:
    case GAUDI_QUEUE_ID_MME_0_2:
    case GAUDI_QUEUE_ID_MME_0_3:
        base  = mmMME2_QM_BASE;
        pqIdx = qid - GAUDI_QUEUE_ID_MME_0_0;
        break;
    case GAUDI_QUEUE_ID_MME_1_0:
    case GAUDI_QUEUE_ID_MME_1_1:
    case GAUDI_QUEUE_ID_MME_1_2:
    case GAUDI_QUEUE_ID_MME_1_3:
        base  = mmMME0_QM_BASE;
        pqIdx = qid - GAUDI_QUEUE_ID_MME_1_0;
        break;
    case GAUDI_QUEUE_ID_TPC_0_0:
    case GAUDI_QUEUE_ID_TPC_0_1:
    case GAUDI_QUEUE_ID_TPC_0_2:
    case GAUDI_QUEUE_ID_TPC_0_3:
        base  = mmTPC0_QM_BASE;
        pqIdx = qid - GAUDI_QUEUE_ID_TPC_0_0;
        break;
    case GAUDI_QUEUE_ID_TPC_1_0:
    case GAUDI_QUEUE_ID_TPC_1_1:
    case GAUDI_QUEUE_ID_TPC_1_2:
    case GAUDI_QUEUE_ID_TPC_1_3:
        base  = mmTPC1_QM_BASE;
        pqIdx = qid - GAUDI_QUEUE_ID_TPC_1_0;
        break;
    case GAUDI_QUEUE_ID_TPC_2_0:
    case GAUDI_QUEUE_ID_TPC_2_1:
    case GAUDI_QUEUE_ID_TPC_2_2:
    case GAUDI_QUEUE_ID_TPC_2_3:
        base  = mmTPC2_QM_BASE;
        pqIdx = qid - GAUDI_QUEUE_ID_TPC_2_0;
        break;
    case GAUDI_QUEUE_ID_TPC_3_0:
    case GAUDI_QUEUE_ID_TPC_3_1:
    case GAUDI_QUEUE_ID_TPC_3_2:
    case GAUDI_QUEUE_ID_TPC_3_3:
        base  = mmTPC3_QM_BASE;
        pqIdx = qid - GAUDI_QUEUE_ID_TPC_3_0;
        break;
    case GAUDI_QUEUE_ID_TPC_4_0:
    case GAUDI_QUEUE_ID_TPC_4_1:
    case GAUDI_QUEUE_ID_TPC_4_2:
    case GAUDI_QUEUE_ID_TPC_4_3:
        base  = mmTPC4_QM_BASE;
        pqIdx = qid - GAUDI_QUEUE_ID_TPC_4_0;
        break;
    case GAUDI_QUEUE_ID_TPC_5_0:
    case GAUDI_QUEUE_ID_TPC_5_1:
    case GAUDI_QUEUE_ID_TPC_5_2:
    case GAUDI_QUEUE_ID_TPC_5_3:
        base  = mmTPC5_QM_BASE;
        pqIdx = qid - GAUDI_QUEUE_ID_TPC_5_0;
        break;
    case GAUDI_QUEUE_ID_TPC_6_0:
    case GAUDI_QUEUE_ID_TPC_6_1:
    case GAUDI_QUEUE_ID_TPC_6_2:
    case GAUDI_QUEUE_ID_TPC_6_3:
        base  = mmTPC6_QM_BASE;
        pqIdx = qid - GAUDI_QUEUE_ID_TPC_6_0;
        break;
    case GAUDI_QUEUE_ID_TPC_7_0:
    case GAUDI_QUEUE_ID_TPC_7_1:
    case GAUDI_QUEUE_ID_TPC_7_2:
    case GAUDI_QUEUE_ID_TPC_7_3:
        base  = mmTPC7_QM_BASE;
        pqIdx = qid - GAUDI_QUEUE_ID_TPC_7_0;
        break;
    case GAUDI_QUEUE_ID_NIC_0_0:
    case GAUDI_QUEUE_ID_NIC_0_1:
    case GAUDI_QUEUE_ID_NIC_0_2:
    case GAUDI_QUEUE_ID_NIC_0_3:
        base  = mmNIC0_QM0_BASE;
        pqIdx = qid - GAUDI_QUEUE_ID_NIC_0_0;
        break;
    case GAUDI_QUEUE_ID_NIC_1_0:
    case GAUDI_QUEUE_ID_NIC_1_1:
    case GAUDI_QUEUE_ID_NIC_1_2:
    case GAUDI_QUEUE_ID_NIC_1_3:
        base  = mmNIC0_QM1_BASE;
        pqIdx = qid - GAUDI_QUEUE_ID_NIC_1_0;
        break;
    case GAUDI_QUEUE_ID_NIC_2_0:
    case GAUDI_QUEUE_ID_NIC_2_1:
    case GAUDI_QUEUE_ID_NIC_2_2:
    case GAUDI_QUEUE_ID_NIC_2_3:
        base  = mmNIC1_QM0_BASE;
        pqIdx = qid - GAUDI_QUEUE_ID_NIC_2_0;
        break;
    case GAUDI_QUEUE_ID_NIC_3_0:
    case GAUDI_QUEUE_ID_NIC_3_1:
    case GAUDI_QUEUE_ID_NIC_3_2:
    case GAUDI_QUEUE_ID_NIC_3_3:
        base  = mmNIC1_QM1_BASE;
        pqIdx = qid - GAUDI_QUEUE_ID_NIC_3_0;
        break;
    case GAUDI_QUEUE_ID_NIC_4_0:
    case GAUDI_QUEUE_ID_NIC_4_1:
    case GAUDI_QUEUE_ID_NIC_4_2:
    case GAUDI_QUEUE_ID_NIC_4_3:
        base  = mmNIC2_QM0_BASE;
        pqIdx = qid - GAUDI_QUEUE_ID_NIC_4_0;
        break;
    case GAUDI_QUEUE_ID_NIC_5_0:
    case GAUDI_QUEUE_ID_NIC_5_1:
    case GAUDI_QUEUE_ID_NIC_5_2:
    case GAUDI_QUEUE_ID_NIC_5_3:
        base  = mmNIC2_QM1_BASE;
        pqIdx = qid - GAUDI_QUEUE_ID_NIC_5_0;
        break;
    case GAUDI_QUEUE_ID_NIC_6_0:
    case GAUDI_QUEUE_ID_NIC_6_1:
    case GAUDI_QUEUE_ID_NIC_6_2:
    case GAUDI_QUEUE_ID_NIC_6_3:
        base  = mmNIC3_QM0_BASE;
        pqIdx = qid - GAUDI_QUEUE_ID_NIC_6_0;
        break;
    case GAUDI_QUEUE_ID_NIC_7_0:
    case GAUDI_QUEUE_ID_NIC_7_1:
    case GAUDI_QUEUE_ID_NIC_7_2:
    case GAUDI_QUEUE_ID_NIC_7_3:
        base  = mmNIC3_QM1_BASE;
        pqIdx = qid - GAUDI_QUEUE_ID_NIC_7_0;
        break;
    case GAUDI_QUEUE_ID_NIC_8_0:
    case GAUDI_QUEUE_ID_NIC_8_1:
    case GAUDI_QUEUE_ID_NIC_8_2:
    case GAUDI_QUEUE_ID_NIC_8_3:
        base  = mmNIC4_QM0_BASE;
        pqIdx = qid - GAUDI_QUEUE_ID_NIC_8_0;
        break;
    case GAUDI_QUEUE_ID_NIC_9_0:
    case GAUDI_QUEUE_ID_NIC_9_1:
    case GAUDI_QUEUE_ID_NIC_9_2:
    case GAUDI_QUEUE_ID_NIC_9_3:
        base  = mmNIC4_QM1_BASE;
        pqIdx = qid - GAUDI_QUEUE_ID_NIC_9_0;
        break;
    default:
        assert(0);
    }
}

unsigned GaudiDevice::GetQidSize() const { return GAUDI_QUEUE_ID_SIZE; }

unsigned GaudiDevice::GetDMAInQid() const { return GAUDI_QUEUE_ID_DMA_0_0; }

unsigned GaudiDevice::GetDMAOutQid() const { return GAUDI_QUEUE_ID_DMA_1_0; }

unsigned GaudiDevice::GetQmanFenceOffset(unsigned fenceIdx, unsigned streamId) const
{
    unsigned offset;
    switch (fenceIdx)
    {
    case 0:
        offset = (unsigned)offsetof(block_qman, cp_fence0_rdata[streamId]);
        break;
    case 1:
        offset = (unsigned)offsetof(block_qman, cp_fence1_rdata[streamId]);
        break;
    case 2:
        offset = (unsigned)offsetof(block_qman, cp_fence2_rdata[streamId]);
        break;
    case 3:
        offset = (unsigned)offsetof(block_qman, cp_fence3_rdata[streamId]);
        break;
    default:
        assert(0 && "invalid fence idx");
        offset = (unsigned)offsetof(block_qman, cp_fence0_rdata[streamId]);
        break;
    }
    return offset;
}

uint64_t GaudiDevice::GetSyncMngrVarAddr(std::string varName, unsigned idx) const
{
    unsigned offset = 0;
    if (varName != "sob_obj")
    {
        idx += GetMonitorObjectBaseIndex();
        assert(idx < c_monitorObjNr && "invalid monitor index");
    }
    if (varName == "mon_pay_addrl")
    {
        offset = (unsigned)offsetof(block_sync_mngr, sync_mngr_objs.mon_pay_addrl[idx]);
    }
    else if (varName == "mon_pay_addrh")
    {
        offset = (unsigned)offsetof(block_sync_mngr, sync_mngr_objs.mon_pay_addrh[idx]);
    }
    else if (varName == "mon_pay_data")
    {
        offset = (unsigned)offsetof(block_sync_mngr, sync_mngr_objs.mon_pay_data[idx]);
    }
    else if (varName == "mon_arm")
    {
        offset = (unsigned)offsetof(block_sync_mngr, sync_mngr_objs.mon_arm[idx]);
    }
    else if (varName == "sob_obj")
    {
        assert(idx < c_syncObjNr && "invalid sync object index");
        offset = (unsigned)offsetof(block_sync_mngr, sync_mngr_objs.sob_obj[idx]);
    }
    else
    {
        assert(0 && "invalid var name");
    }
    return c_syncManagerBase + offset;
}

unsigned GaudiDevice::GetDmaDownVarOffset(std::string varName) const
{
    unsigned offset = 0;
    if (varName == "wr_comp_addr_lo")
    {
        offset = (unsigned)offsetof(block_dma_core, wr_comp_addr_lo);
    }
    else if (varName == "wr_comp_addr_hi")
    {
        offset = (unsigned)offsetof(block_dma_core, wr_comp_addr_hi);
    }
    else if (varName == "wr_comp_wdata")
    {
        offset = (unsigned)offsetof(block_dma_core, wr_comp_wdata);
    }
    else
    {
        assert(0 && "invalid var name");
    }
    return offset;
}

void GaudiDevice::GetTpcTabOffset(int TabIdx, uint32_t* baseAddrLow, uint32_t* baseAddrHigh) const
{
    switch (TabIdx)
    {
    case 0: // 256b special functions
        *baseAddrLow  = (unsigned)offsetof(block_tpc, lut_func256_base_addr_lo);
        *baseAddrHigh = (unsigned)offsetof(block_tpc, lut_func256_base_addr_hi);
        break;
    case 1: // 128b special functions
        *baseAddrLow  = (unsigned)offsetof(block_tpc, lut_func128_base_addr_lo);
        *baseAddrHigh = (unsigned)offsetof(block_tpc, lut_func128_base_addr_hi);
        break;
    case 2: // 64b special functions
        *baseAddrLow  = (unsigned)offsetof(block_tpc, lut_func64_base_addr_lo);
        *baseAddrHigh = (unsigned)offsetof(block_tpc, lut_func64_base_addr_hi);
        break;
    case 3: // 32b special functions
        *baseAddrLow  = (unsigned)offsetof(block_tpc, lut_func32_base_addr_lo);
        *baseAddrHigh = (unsigned)offsetof(block_tpc, lut_func32_base_addr_hi);
        break;
    default:
        assert(0);
    }
    return;
}

unsigned GaudiDevice::GetTpcCfgVarOffset(std::string varName) const
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
    return offset;
}

unsigned GaudiDevice::GetMonArmRawVal(uint8_t mask, uint8_t sid, unsigned sod, unsigned sop) const
{
    sob_objs::reg_mon_arm monArm;
    memset(&monArm, 0, sizeof(sob_objs::reg_mon_arm));
    monArm.mask = mask;
    monArm.sid  = sid;
    monArm.sod  = sod;
    monArm.sop  = sop;

    return monArm._raw;
}

std::shared_ptr<::CPCommand::CpDma> GaudiDevice::GenCpDma(uint64_t src, uint32_t size) const
{
    std::shared_ptr<::CPCommand::CpDma> pCommand;
    pCommand = std::make_shared<CPCommand::CpDmaGen2>(src, size);
    return pCommand;
}

std::shared_ptr<::CPCommand::Fence> GaudiDevice::GenFence(unsigned id, uint8_t targetVal,
                                                        unsigned decVal) const
{
    std::shared_ptr<::CPCommand::Fence> pCommand;
    pCommand = std::make_shared<CPCommand::FenceGen2>(id, targetVal, decVal);
    return pCommand;
}

std::shared_ptr<::CPCommand::LinDma> GaudiDevice::GenLinDma(uint64_t dst, uint64_t src,
                                                          uint32_t tsize, unsigned dmaDir,
                                                          uint16_t ctxId, bool wrComp) const
{
    // dmaDir not required for Gaudi, only for Goya
    std::shared_ptr<::CPCommand::LinDma> pCommand;
    pCommand          = std::make_shared<CPCommand::LinDmaGen2>(dst, src, tsize, 0, wrComp);
    pCommand->m_ctxId = ctxId;
    return pCommand;
}

std::shared_ptr<::CPCommand::MsgLong> GaudiDevice::GenMsgLong(uint64_t addr, uint32_t value, bool mb,
                                                            bool rb, bool eb) const
{
    std::shared_ptr<::CPCommand::MsgLong> pCommand;
    pCommand = std::make_shared<CPCommand::MsgLongGen2>(addr, value, mb, rb, eb);
    return pCommand;
}

std::shared_ptr<::CPCommand::WReg32> GaudiDevice::GenWReg32(uint16_t offset, uint32_t value, bool mb,
                                                          bool rb, bool eb) const
{
    std::shared_ptr<::CPCommand::WReg32> pCommand;
    pCommand = std::make_shared<CPCommand::WReg32Gen2>(offset, value, mb, rb, eb);
    return pCommand;
}

std::shared_ptr<::CPCommand::WRegBulk> GaudiDevice::GenWRegBulk(uint16_t offset, uint32_t* values,
                                                              unsigned numValues) const
{
    std::shared_ptr<::CPCommand::WRegBulk> pCommand;
    pCommand = std::make_shared<CPCommand::WRegBulkGen2>(offset, values, numValues);
    return pCommand;
}

size_t GaudiDevice::GetTpcDescSize() const { return sizeof(GaudiTpcDesc); }

void GaudiDevice::WriteSrf(HWAbstractionLayer::TpcDescHandle tpcDesc, const uint32_t* params,
                           unsigned paramsNr) const
{
    memcpy(&(((GaudiTpcDesc*)(tpcDesc))->m_desc.srf[0]), params, paramsNr * sizeof(uint32_t));
}

void GaudiDevice::WriteKernelCfg(HWAbstractionLayer::TpcDescHandle tpcDesc, uint32_t smallVlm) const
{
    ((GaudiTpcDesc*)(tpcDesc))->m_desc.kernel_config.small_vlm = smallVlm;
    // TODO: load actual count.
    ((GaudiTpcDesc*)(tpcDesc))->m_desc.kernel_config.num_valid_srfs = 32;

    // Don't change rate limiter, setting default values.
    ((GaudiTpcDesc*)(tpcDesc))->m_desc.kernel_config.rd_rate_limit_rst_token = 0x8;
    ((GaudiTpcDesc*)(tpcDesc))->m_desc.kernel_config.wr_rate_limit_rst_token = 0x6;
}

void GaudiDevice::WriteKernelAddr(HWAbstractionLayer::TpcDescHandle tpcDesc,
                                  uint64_t                          kernelAddr) const
{
    ((GaudiTpcDesc*)(tpcDesc))->m_desc.kernel_base_address_low._raw =
        (uint32_t)(kernelAddr & 0xffffffff);
    ((GaudiTpcDesc*)(tpcDesc))->m_desc.kernel_base_address_high._raw = (uint32_t)(kernelAddr >> 32);
}

void GaudiDevice::WriteTensorDesc(HWAbstractionLayer::TpcDescHandle tpcDesc,
                                  TensorDescriptor& tensorDesc, unsigned tensorId) const
{
    memcpy(&(((GaudiTpcDesc*)(tpcDesc))->m_tensors[tensorId]), &tensorDesc,
           sizeof(TensorDescriptor));
}

void GaudiDevice::WriteTpcJobDesc(HWAbstractionLayer::TpcDescHandle tpcDesc,
                                  const IndexSpace& partition, uint32_t soAddr,
                                  uint32_t soMsg, bool updatePrintfAddr,
                                  int printfTensorIdx) const
{
    // load IRF0/1
    ((GaudiTpcDesc*)(tpcDesc))->m_desc.tid_size_dim_0.v = partition.size[0];
    ((GaudiTpcDesc*)(tpcDesc))->m_desc.tid_size_dim_1.v = partition.size[1];
    ((GaudiTpcDesc*)(tpcDesc))->m_desc.tid_size_dim_2.v = partition.size[2];
    ((GaudiTpcDesc*)(tpcDesc))->m_desc.tid_size_dim_3.v = partition.size[3];
    ((GaudiTpcDesc*)(tpcDesc))->m_desc.tid_size_dim_4.v = partition.size[4];

    ((GaudiTpcDesc*)(tpcDesc))->m_desc.tid_base_dim_0.v = partition.offset[0];
    ((GaudiTpcDesc*)(tpcDesc))->m_desc.tid_base_dim_1.v = partition.offset[1];
    ((GaudiTpcDesc*)(tpcDesc))->m_desc.tid_base_dim_2.v = partition.offset[2];
    ((GaudiTpcDesc*)(tpcDesc))->m_desc.tid_base_dim_3.v = partition.offset[3];
    ((GaudiTpcDesc*)(tpcDesc))->m_desc.tid_base_dim_4.v = partition.offset[4];

    ((GaudiTpcDesc*)(tpcDesc))->m_so.addr.v       = soAddr;
    ((GaudiTpcDesc*)(tpcDesc))->m_so.message._raw = soMsg;

}

uint32_t GaudiDevice::GenTpcCmd() const
{
    gaudi::tpc::reg_tpc_cmd command;
    memset(&command, 0, sizeof(command));
    command.icache_invalidate    = 1;
    command.dcache_invalidate    = 1;
    command.lcache_invalidate    = 1;
    command.tcache_invalidate    = 1;
    command.icache_prefetch_64kb = 0;
    return command._raw;
}

uint32_t GaudiDevice::GetTpcTensorConfig() const
{
  struct gaudi::tpc_tensor::reg_tensor_config config;
  config._raw = 0;
  config.last_dim = 3;
  config.valid_dim_mask = 0xF;
  config.data_type = TensorDataType::TensorDT_FP32;
  return config._raw;

}

} // namespace gaudi
