/* SPDX-License-Identifier: MIT
 *
 * Copyright 2016-2021 HabanaLabs, Ltd.
 * All Rights Reserved.
 *
 */

#pragma once

#include "hw_abstraction_layer.h"

class GaudiDevice : public HWAbstractionLayer
{
public:
    GaudiDevice() {}
    virtual ~GaudiDevice() {}

    virtual unsigned    GetTensorSizeFromDesc(TensorDescriptorGaudi& desc) const override;
    virtual unsigned    GetTensorSizeFromDesc(TensorDescriptorGaudi& desc0, TensorDescriptorGaudi& desc1) const override;

    virtual unsigned    GetSpecialFuncTabNr() const override;
    virtual void        GetSpecialFuncTabSizes(uint32_t* sizes, unsigned sizesLen) const override;
    virtual void        CopySpecialFuncTab(
            std::vector<std::vector<uint8_t>>& specialFunctionCoefficients) const override;

    virtual int         GetDmaUpSyncObjectIndex() const override;
    virtual int         GetDmaDownSyncObjectIndex() const override;
    virtual int         GetMonitorObjectBaseIndex() const override;
    virtual uint64_t    GetSyncManagerBaseAddr() const override;
    virtual uint64_t    GetDmaUpSyncObjectAddr() const override;
    virtual uint64_t    GetDmaDownSyncObjectAddr() const override;

    virtual unsigned    GetTPCNr() const override;
    virtual unsigned    GetTPCQueueId(unsigned tpcId) const override;
    virtual unsigned    GetSyncObjectGroupSize() const override;

    virtual void        Qid2Qman(unsigned qid, uint64_t& base, unsigned& pqIdx) const override;
    virtual unsigned    GetQidSize() const override;
    virtual unsigned    GetDMAInQid() const override;
    virtual unsigned    GetDMAOutQid() const override;
    virtual unsigned    GetQmanFenceOffset(unsigned fenceIdx, unsigned streamId) const override;
    virtual uint64_t    GetSyncMngrVarAddr(std::string varName, unsigned idx) const override;
    virtual unsigned    GetDmaDownVarOffset(std::string varName) const override;
    virtual unsigned    GetTpcCfgVarOffset(std::string varName) const override;
    virtual unsigned    GetMonArmRawVal(unsigned mask, unsigned sid, unsigned sod, unsigned sop) const override;
    virtual void        GetTpcTabOffset(int TabIdx, uint32_t* baseAddrLow, uint32_t* baseAddrHigh) const override;

    virtual std::shared_ptr<CPCommand::WReg32>              GenWReg32(uint16_t offset, uint32_t value, bool mb = false, bool rb = false, bool eb = false) const override;
    virtual std::shared_ptr<CPCommand::WRegBulk>            GenWRegBulk(uint16_t offset, uint32_t* values, unsigned numValues) const override;
    virtual std::shared_ptr<CPCommand::MsgLong>             GenMsgLong(uint64_t addr, uint32_t value, bool mb = false, bool rb = false, bool eb = false) const override;
    virtual std::shared_ptr<CPCommand::Fence>               GenFence(unsigned id, uint8_t targetVal, unsigned decVal) const override;
    virtual std::shared_ptr<CPCommand::LinDma>              GenLinDma(uint64_t dst, uint64_t src, uint32_t tsize, unsigned dmaDir, uint16_t ctxId = 0, bool wrComp = false) const override;
    virtual std::shared_ptr<CPCommand::CpDma>               GenCpDma(uint64_t src, uint32_t size) const override;

    virtual size_t      GetTpcDescSize() const override;
    virtual void        WriteSrf(TpcDescHandle tpcDesc, const uint32_t* params, unsigned paramsNr) const override;
    virtual void        WriteKernelCfg(TpcDescHandle tpcDesc, uint32_t smallVlm) const override;
    virtual void        WriteKernelAddr(TpcDescHandle tpcDesc, uint64_t kernelAddr) const override;
    virtual void        WriteTensorDesc(TpcDescHandle tpcDesc, TensorDescriptorGaudi& tensorDesc, unsigned tensorId) const override;
    virtual void        WriteTpcJobDesc(TpcDescHandle tpcDesc, const IndexSpace& partition, uint32_t contextId, uint32_t soAddr, uint32_t soMsg, uint32_t soIdx, bool updatePrintfAddr, int printfTensorIdx) const override;

private:
    GaudiDevice(const GaudiDevice& other) = delete;
    GaudiDevice& operator=(const GaudiDevice& other) = delete;

    static const unsigned   c_tpcNr;
    static const unsigned   c_syncObjNr;
    static const unsigned   c_monitorObjNr;
    static const unsigned   c_syncObjectGroupSize;
    static const int        c_dmaDownSyncObjectIndex;
    static const int        c_dmaUpSyncObjectIndex;
    static const int        c_monitorObjectBaseIndex;
    static const uint64_t   c_syncManagerBase;
    static const uint64_t   c_syncObjectsBaseAddr;
    static constexpr uint64_t GetSyncObjectAddress(int synObjIndex);
};
