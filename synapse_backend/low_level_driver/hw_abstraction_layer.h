/* SPDX-License-Identifier: MIT
 *
 * Copyright 2016-2021 HabanaLabs, Ltd.
 * All Rights Reserved.
 *
 */

#pragma once

#include <cstdint>
#include <vector>
#include <string>
#include <memory>
#include "TensorDescriptor.h"
#include "program.h"
#include "index_space.h"
#include "synapse_common_types.h"

class HWAbstractionLayer
{
public:
    HWAbstractionLayer() {}
    virtual ~HWAbstractionLayer() {}

    virtual synDeviceType getDeviceType() const = 0;
    virtual unsigned    GetTensorSizeFromDesc(TensorDescriptor& desc) const = 0;
    virtual unsigned    GetTensorSizeFromDesc(TensorDescriptor& desc0, TensorDescriptor& desc1) const = 0;
    virtual unsigned    GetSpecialFuncTabNr() const = 0;
    virtual void        GetSpecialFuncTabSizes(uint32_t* sizes, unsigned sizesLen) const = 0;
    virtual void        CopySpecialFuncTab(
            std::vector<std::vector<uint8_t>>& specialFunctionCoefficients) const = 0;

    virtual int         GetDmaUpSyncObjectIndex() const = 0;
    virtual int         GetDmaDownSyncObjectIndex() const = 0;
    virtual int         GetMonitorObjectBaseIndex() const = 0;
    virtual uint64_t    GetSyncManagerBaseAddr() const = 0;
    virtual uint64_t    GetDmaUpSyncObjectAddr() const = 0;
    virtual uint64_t    GetDmaDownSyncObjectAddr() const = 0;

    virtual unsigned    GetTPCNr() const = 0;
    virtual unsigned    GetTPCQueueId(unsigned tpcId) const = 0;
    virtual unsigned    GetSyncObjectGroupSize() const = 0;

    virtual void        Qid2Qman(unsigned qid, uint64_t& base, unsigned& pqIdx) const = 0;
    virtual unsigned    GetQidSize() const = 0;
    virtual unsigned    GetDMAInQid() const = 0;
    virtual unsigned    GetDMAOutQid() const = 0;
    virtual unsigned    GetQmanFenceOffset(unsigned fenceIdx, unsigned streamId) const = 0;
    virtual uint64_t    GetSyncMngrVarAddr(std::string varName, unsigned idx) const = 0;
    virtual unsigned    GetDmaDownVarOffset(std::string varName) const = 0;
    virtual unsigned    GetTpcCfgVarOffset(std::string varName) const = 0;
    virtual unsigned    GetMonArmRawVal(uint8_t mask, uint8_t sid, unsigned sod, unsigned sop) const = 0;
    virtual unsigned    GetMonCfgRawVal(unsigned msbSid) const {return 0;}
    virtual void        GetTpcTabOffset(int TabIdx, uint32_t* baseAddrLow, uint32_t* baseAddrHigh) const = 0;

    virtual std::shared_ptr<CPCommand::WReg32>              GenWReg32(uint16_t offset, uint32_t value, bool mb = false, bool rb = false, bool eb = false) const = 0;
    virtual std::shared_ptr<CPCommand::WRegBulk>            GenWRegBulk(uint16_t offset, uint32_t* values, unsigned numValues) const = 0;
    virtual std::shared_ptr<CPCommand::MsgLong>             GenMsgLong(uint64_t addr, uint32_t value, bool mb = false, bool rb = false, bool eb = false) const = 0;
    virtual std::shared_ptr<CPCommand::Fence>               GenFence(unsigned id, uint8_t targetVal, unsigned decVal) const = 0;
    virtual std::shared_ptr<CPCommand::LinDma>              GenLinDma(uint64_t dst, uint64_t src, uint32_t tsize, unsigned dmaDir, uint16_t ctxId = 0, bool wrComp = false) const = 0;
    virtual std::shared_ptr<CPCommand::CpDma>               GenCpDma(uint64_t src, uint32_t size) const = 0;

    typedef void* TpcDescHandle;

    virtual size_t      GetTpcDescSize() const = 0;
    virtual void        WriteSrf(TpcDescHandle tpcDesc, const uint32_t* params, unsigned paramsNr) const = 0;
    virtual void        WriteKernelCfg(TpcDescHandle tpcDesc, uint32_t smallVlm) const = 0;
    virtual void        WriteKernelAddr(TpcDescHandle tpcDesc, uint64_t kernelAddr) const = 0;
    virtual void        WriteTensorDesc(TpcDescHandle tpcDesc, TensorDescriptor& tensorDesc, unsigned tensorId) const = 0;
    virtual void        WriteTpcJobDesc(TpcDescHandle tpcDesc, const IndexSpace& partition, uint32_t soAddr, uint32_t soMsg, bool updatePrintfAddr, int printfTensorIdx) const = 0;
    virtual uint32_t    GenTpcCmd() const = 0;
    virtual uint32_t    GetTpcTensorConfig() const = 0;

    virtual bool isMmuEnabled() const = 0;
    virtual bool shouldConfigureMonCfg() const = 0;
    void SetSmInfo(int firstAvailSob, int firstAvailMon)
    {
        m_firstAvailMonitor = firstAvailMon;
        m_firstAvailSyncObj = firstAvailSob;
    }

    static const uint64_t c_syncObjectSizeInBytes = 4ull;

protected:
    int m_firstAvailSyncObj;
    int m_firstAvailMonitor;

private:
    HWAbstractionLayer(const HWAbstractionLayer& other) = delete;
    HWAbstractionLayer& operator=(const HWAbstractionLayer& other) = delete;
};
