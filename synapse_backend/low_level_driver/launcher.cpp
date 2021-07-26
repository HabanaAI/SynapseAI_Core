/* SPDX-License-Identifier: MIT
 *
 * Copyright 2016-2021 HabanaLabs, Ltd.
 * All Rights Reserved.
 *
 */


#undef NDEBUG
#include <assert.h>
#include <list>
#include <set>
#include <iostream>
#include <iostream>
#include <stddef.h>
#include <limits.h>
#include <misc/habanalabs.h>
#include "driver_device.h"
#include "launcher.h"
#include "memory_allocator.h"

static const unsigned c_high_cp_prog_size = c_cl_size;
static short          g_contextId         = 0xabab;

static inline uint64_t RoundUp(uint64_t size, uint64_t round)
{
    return (size + round - 1) & ~(round - 1);
}

static inline unsigned CountBits(unsigned n)
{
    unsigned ret = 0;
    while (n)
    {
        ret += n & 1;
        n >>= 1;
    }

    return ret;
}

void TestLauncher::GetProgBuffSizeAndOffsets(Device*                             device,
                                             const std::list<Device::QueueWkld>* programs,
                                             std::list<unsigned>* offsets, unsigned* size)
{
    unsigned qidSize = device->GetHal()->GetQidSize();
    bool     prevQId[qidSize];
    memset(prevQId, 0, qidSize * sizeof(bool));

    std::list<Device::QueueWkld> emptyPrograms;
    if (!programs)
        programs = &emptyPrograms;

    *size = programs->size() * c_high_cp_prog_size;
    for (auto& prog : *programs)
    {
        assert(!prevQId[prog.qid]);
        prevQId[prog.qid] = true;
        offsets->push_back(*size);
        (*size) += RoundUp(prog.size, c_cl_size);
    }
}

void TestLauncher::PrepareProgBuff(Device* device, const unsigned stream,
                                   const uint64_t                          deviceAddr,
                                   const std::list<Device::QueueWkld>* programs,
                                   const std::list<unsigned>* offsets, const unsigned bufferSize,
                                   std::list<Device::QueueWkld>* devicePrograms, void* progBuff)
{
    std::list<Device::QueueWkld> emptyPrograms;
    std::list<unsigned>              emptyOffsets;
    if (!programs)
        programs = &emptyPrograms;
    if (!offsets)
        offsets = &emptyOffsets;

    assert(offsets->size() == programs->size());

    auto     offsetsIt = offsets->begin();
    unsigned progCtr   = 0;
    for (auto& prog : *programs)
    {
        uint8_t* cpHPtrBase = (uint8_t*)(progBuff) + (progCtr * c_high_cp_prog_size);
        uint8_t* cpHPtr     = cpHPtrBase;

        {
            std::shared_ptr<CPCommand::CpDma> pCpDma =
                device->GetHal()->GenCpDma(deviceAddr + (*offsetsIt), prog.size);
            pCpDma->Serialize((void**)&cpHPtr);
        }

        memcpy(((uint8_t*)progBuff) + (*offsetsIt), (void*)prog.buffer, prog.size);

        Device::QueueWkld devProg = {0};
        devProg.buffer                = cpHPtrBase - ((uint8_t*)progBuff) + deviceAddr;
        devProg.qid                   = prog.qid;
        devProg.flags                 = HL_CS_CHUNK_FLAGS_USER_ALLOC_CB;
        devProg.size                  = cpHPtr - cpHPtrBase;

        devicePrograms->push_back(devProg);

        progCtr++;
        offsetsIt++;
    }
}

void TestLauncher::DownloadProgram2Device(Device* device, const unsigned stream,
                                          const Buffer*          progBuff)
{
    std::list<uint64_t>                            cfgAddr;
    std::list<uint32_t>                            cfgValue;
    Device::Handle                             dmaBuffHandle;
    void*                                          hostAddr;
    std::list<std::shared_ptr<CPCommand::MsgLong>> pMsgLong;

    unsigned dmaDir = (progBuff->memSpace == e_dram) ? DMA_HOST_TO_DRAM : DMA_HOST_TO_SRAM;
    std::shared_ptr<CPCommand::LinDma> pLinDma = device->GetHal()->GenLinDma(progBuff->deviceVirtAddr, progBuff->hostVirtAddr, progBuff->size, dmaDir, g_contextId);

    unsigned dmaBuffFlags;
    device->GetCB(pLinDma->GetSize(), dmaBuffHandle, hostAddr, dmaBuffFlags);

    pLinDma->Serialize(&hostAddr);

    Device::QueueWkld wkld;
    unsigned              dmaInQid = device->GetHal()->GetDMAInQid();
    switch (stream)
    {
    case 0:
        wkld.qid = dmaInQid;
        break;
    case 1:
        wkld.qid = dmaInQid + 1;
        break;
    case 2:
        wkld.qid = dmaInQid + 2;
        break;
    case 3:
        wkld.qid = dmaInQid + 3;
        break;
    default:
        assert(0);
    }
    wkld.buffer = dmaBuffHandle;
    wkld.size   = pLinDma->GetSize();
    wkld.flags  = dmaBuffFlags;

    std::list<Device::QueueWkld> wkldsList = {};
    wkldsList.push_back(wkld);

    Device::Handle               submitHandle;
    std::list<Device::QueueWkld> setupList;
    device->SubmitWklds(setupList, wkldsList, false, submitHandle);
    device->Wait(submitHandle);
    device->ReleaseCB(dmaBuffHandle);
}

void TestLauncher::ExecuteProgram(Device* device, const unsigned stream,
                                  const std::list<Device::QueueWkld>* devicePrograms,
                                  const SyncInfo* syncInfo,
                                  const std::list<Buffer>* inputBuffers,
                                  const std::list<Buffer>* outputBuffers)
{
    // step 1 - check input
    std::list<Device::QueueWkld> emptyPrograms;
    std::list<Buffer>                emptyIOBuffers;

    if (!devicePrograms)
        devicePrograms = &emptyPrograms;
    if (!inputBuffers)
        inputBuffers = &emptyIOBuffers;
    if (!outputBuffers)
        outputBuffers = &emptyIOBuffers;

    assert(syncInfo);

    // step 2 - allocate dma buffers
    std::shared_ptr<CPCommand::LinDma>  pLinDma  = device->GetHal()->GenLinDma(0, 0, 0, 0);
    std::shared_ptr<CPCommand::MsgLong> pMsgLong = device->GetHal()->GenMsgLong(0, 0);
    std::shared_ptr<CPCommand::WReg32>  pWReg32  = device->GetHal()->GenWReg32(0, 0);
    unsigned                            dmaInBuffSize;
    dmaInBuffSize = inputBuffers->size() * pLinDma->GetSize() + 3 * pWReg32->GetSize();

    unsigned dmaOutBuffSize = outputBuffers->size() * pLinDma->GetSize();

    dmaInBuffSize += pMsgLong->GetSize(); // reset input sync object
    dmaInBuffSize +=
        CountBits(syncInfo->outputSOSel) * pMsgLong->GetSize(); // reset output sync object

    std::shared_ptr<CPCommand::Fence> pFence = device->GetHal()->GenFence(0, 0, 0);
    dmaOutBuffSize += 4 * pMsgLong->GetSize(); // arm the monitor
    dmaOutBuffSize += pFence->GetSize();       // fence
    dmaOutBuffSize += pMsgLong->GetSize();     // reset input sync object
    dmaOutBuffSize +=
        CountBits(syncInfo->outputSOSel) * pMsgLong->GetSize(); // reset output sync object

    Device::Handle dmaInHandle   = {};
    Device::Handle dmaOutHandle  = {};
    void*              dmaInHostPtr  = nullptr;
    void*              dmaOutHostPtr = nullptr;

    unsigned dmaInFlags;
    unsigned dmaOutFlags;

    if (dmaInBuffSize)
    {
        device->GetCB(dmaInBuffSize, dmaInHandle, dmaInHostPtr, dmaInFlags);
    }

    if (dmaOutBuffSize)
    {
        device->GetCB(dmaOutBuffSize, dmaOutHandle, dmaOutHostPtr, dmaOutFlags);
    }

    std::list<Device::QueueWkld> wkldsList;

    // step 3 - prepare input buffer
    assert(dmaInHostPtr != nullptr && "dmaInHostPtr is null!");
    uint8_t* dmaInPtr = ((uint8_t*)dmaInHostPtr);

    // reset input so
    {
        uint64_t                            addr     = device->GetHal()->GetDmaDownSyncObjectAddr();
        std::shared_ptr<CPCommand::MsgLong> pMsgLong = device->GetHal()->GenMsgLong(addr, 0);
        pMsgLong->Serialize((void**)&dmaInPtr);
    }

    // reset output so
    static const unsigned c_so_group_size = device->GetHal()->GetSyncObjectGroupSize();
    for (unsigned k = 0; k < c_so_group_size; k++)
    {
        if (syncInfo->outputSOSel & (1 << k))
        {
            unsigned soIdx = device->GetHal()->GetDmaUpSyncObjectIndex() + k;
            uint64_t addr  = device->GetHal()->GetSyncMngrVarAddr("sob_obj", soIdx);
            std::shared_ptr<CPCommand::MsgLong> pMsgLong = device->GetHal()->GenMsgLong(addr, 0);
            pMsgLong->Serialize((void**)&dmaInPtr);
        }
    }

    // INFO: temporarily removing ARB_POINT packet from DMA down/up
    /*
    // arb request
    if (arbitration && arbitration->enable)
    {
        packet_arb_point * ptr = (packet_arb_point*)dmaInPtr;
        ptr->eng_barrier = 0;
        ptr->msg_barrier = 0;
        ptr->reg_barrier = 0;
        ptr->opcode = PACKET_ARB_POINT;
        ptr->pred = 0;
        ptr->priority = arbitration->prio;
        ptr->rls = 0;
        dmaInPtr += sizeof(packet_arb_point);
    }
    */

    // dma in
    {
        uint64_t syncObj = device->GetHal()->GetSyncMngrVarAddr(
            "sob_obj", device->GetHal()->GetDmaDownSyncObjectIndex());

        // TODO : add support for multiple streams
        std::shared_ptr<CPCommand::WReg32> pMsg1 = device->GetHal()->GenWReg32(
            device->GetHal()->GetDmaDownVarOffset("wr_comp_addr_lo"), (uint32_t)syncObj);
        pMsg1->Serialize((void**)&dmaInPtr);

        std::shared_ptr<CPCommand::WReg32> pMsg2 = device->GetHal()->GenWReg32(
            device->GetHal()->GetDmaDownVarOffset("wr_comp_addr_hi"),
            (uint32_t)(syncObj >> 32));
        pMsg2->Serialize((void**)&dmaInPtr);

        std::shared_ptr<CPCommand::WReg32> pMsg3 = device->GetHal()->GenWReg32(
            device->GetHal()->GetDmaDownVarOffset("wr_comp_wdata"), 1, true, true, true);
        pMsg3->Serialize((void**)&dmaInPtr);

        unsigned bufferCtr = 0;
        unsigned dmaDir;
        for (auto buff : *inputBuffers)
        {
            bufferCtr++;
            dmaDir = (buff.memSpace == e_dram) ? DMA_HOST_TO_DRAM : DMA_HOST_TO_SRAM;
            std::shared_ptr<CPCommand::LinDma> pLinDmaIn = device->GetHal()->GenLinDma(
                buff.deviceVirtAddr, buff.hostVirtAddr, buff.size, dmaDir, g_contextId,
                (bufferCtr == inputBuffers->size()));
            pLinDmaIn->Serialize((void**)&dmaInPtr);
        }
    }

    assert(((uint64_t)dmaInPtr - (uint64_t)dmaInHostPtr) == dmaInBuffSize);
    Device::QueueWkld inputWkld;
    inputWkld.buffer = dmaInHandle;
    inputWkld.size   = dmaInBuffSize;
    inputWkld.flags  = dmaInFlags;

    unsigned dmaInQid = device->GetHal()->GetDMAInQid();
    switch (stream)
    {
    case 0:
        inputWkld.qid = dmaInQid;
        break;
    case 1:
        inputWkld.qid = dmaInQid + 1;
        break;
    case 2:
        inputWkld.qid = dmaInQid + 2;
        break;
    case 3:
        inputWkld.qid = dmaInQid + 3;
        break;
    default:
        assert(0);
    }

    wkldsList.push_back(inputWkld);

    // step 4 - prepare output buffer
    unsigned outQId    = 0;
    unsigned dmaOutQid = device->GetHal()->GetDMAOutQid();
    switch (stream)
    {
    case 0:
        outQId = dmaOutQid;
        break;
    case 1:
        outQId = dmaOutQid + 1;
        break;
    case 2:
        outQId = dmaOutQid + 2;
        break;
    case 3:
        outQId = dmaOutQid + 3;
        break;
    default:
        assert(0);
    }

    unsigned junk;
    uint64_t qmBase;
    device->GetHal()->Qid2Qman(outQId, qmBase, junk);

    assert(dmaOutHostPtr != nullptr && "dmaOutHostPtr is null!");
    uint8_t* dmaOutPtr = ((uint8_t*)dmaOutHostPtr);

    // mon arm - addr low
    {
        uint64_t fenceAddr  = qmBase + device->GetHal()->GetQmanFenceOffset(0, stream);
        uint64_t monArmAddr = device->GetHal()->GetSyncMngrVarAddr("mon_pay_addrl", outQId);
        std::shared_ptr<CPCommand::MsgLong> pMsgLong =
            device->GetHal()->GenMsgLong(monArmAddr, (uint32_t)fenceAddr);
        pMsgLong->Serialize((void**)&dmaOutPtr);
    }

    // mon arm - addr high
    {
        uint64_t fenceAddr  = qmBase + device->GetHal()->GetQmanFenceOffset(0, stream);
        uint64_t monArmAddr = device->GetHal()->GetSyncMngrVarAddr("mon_pay_addrh", outQId);
        std::shared_ptr<CPCommand::MsgLong> pMsgLong =
            device->GetHal()->GenMsgLong(monArmAddr, (uint32_t)(fenceAddr >> 32));
        pMsgLong->Serialize((void**)&dmaOutPtr);
    }

    // mon arm - value
    {
        uint64_t monArmAddr = device->GetHal()->GetSyncMngrVarAddr("mon_pay_data", outQId);
        std::shared_ptr<CPCommand::MsgLong> pMsgLong = device->GetHal()->GenMsgLong(monArmAddr, 1);
        pMsgLong->Serialize((void**)&dmaOutPtr);
    }

    // mon arm - arm
    {
        uint64_t monArmAddr = device->GetHal()->GetSyncMngrVarAddr("mon_arm", outQId);
        uint32_t monArmVal  = device->GetHal()->GetMonArmRawVal(~(syncInfo->outputSOSel), // mask
                                                               syncInfo->outputSOIdx,    // sid
                                                               syncInfo->outputSOTarget, // sod
                                                               0);                       // sop
        std::shared_ptr<CPCommand::MsgLong> pMsgLong =
            device->GetHal()->GenMsgLong(monArmAddr, monArmVal);
        pMsgLong->Serialize((void**)&dmaOutPtr);
    }

    // fence
    {
        std::shared_ptr<CPCommand::Fence> pFence = device->GetHal()->GenFence(0, 1, 1);
        pFence->Serialize((void**)&dmaOutPtr);
    }

    // dma
    unsigned dmaDir;
    for (auto buff : *outputBuffers)
    {
        dmaDir = (buff.memSpace == e_dram) ? DMA_DRAM_TO_HOST : DMA_SRAM_TO_HOST;
        std::shared_ptr<CPCommand::LinDma> pLinDmaOut = device->GetHal()->GenLinDma(
            buff.hostVirtAddr, buff.deviceVirtAddr, buff.size, dmaDir, g_contextId);
        pLinDmaOut->Serialize((void**)&dmaOutPtr);
    }

    // reset input so (+wait for DMA comp)
    {
        uint64_t                            addr = device->GetHal()->GetDmaDownSyncObjectAddr();
        std::shared_ptr<CPCommand::MsgLong> pMsgLong =
            device->GetHal()->GenMsgLong(addr, 0, false, false, true);
        pMsgLong->Serialize((void**)&dmaOutPtr);
    }

    // reset output so
    for (unsigned k = 0; k < c_so_group_size; k++)
    {
        if (syncInfo->outputSOSel & (1 << k))
        {
            unsigned soIdx = device->GetHal()->GetDmaUpSyncObjectIndex() + k;
            uint64_t addr  = device->GetHal()->GetSyncMngrVarAddr("sob_obj", soIdx);
            std::shared_ptr<CPCommand::MsgLong> pMsgLong = device->GetHal()->GenMsgLong(addr, 0);
            pMsgLong->Serialize((void**)&dmaOutPtr);
        }
    }

    assert(((uint64_t)dmaOutPtr - (uint64_t)dmaOutHostPtr) == dmaOutBuffSize);
    Device::QueueWkld outputWkld;
    outputWkld.buffer = dmaOutHandle;
    outputWkld.size   = dmaOutBuffSize;
    outputWkld.qid    = outQId;
    outputWkld.flags  = dmaOutFlags;

    wkldsList.push_back(outputWkld);

    // step 5 - validate the internal queue programs and add them to the list of programs
    for (auto& prog : *devicePrograms)
    {
        uint64_t junk;
        unsigned streamID;
        device->GetHal()->Qid2Qman(prog.qid, junk, streamID);
    }

    wkldsList.insert(wkldsList.end(), devicePrograms->begin(), devicePrograms->end());

    // step 6 - sumbit wklds, wait for comp and release handles.
    Device::Handle               submitHandle;
    std::list<Device::QueueWkld> setupList;
    device->SubmitWklds(setupList, wkldsList, false, submitHandle);
    device->Wait(submitHandle);
    device->ReleaseCB(dmaInHandle);
    device->ReleaseCB(dmaOutHandle);
}

void TestLauncher::CreateAndExecuteProgram(SynMemoryAllocator* memAlloc, Device* device,
                                           const unsigned stream, const std::list<CPProgram>* progs,
                                           const SyncInfo*                 syncInfo,
                                           const std::list<Buffer>*        inputBuffers,
                                           const std::list<Buffer>*        outputBuffers,
                                           DeviceMemory_t memSpace)
{
    std::list<Device::QueueWkld> programs;
    for (std::list<CPProgram>::const_iterator it = progs->begin(); it != progs->end(); it++)
    {
        Device::QueueWkld wkld = {0};
        wkld.qid                   = it->GetQId();
        wkld.size                  = it->GetSize();
        wkld.buffer                = (uint64_t)malloc(wkld.size);
        wkld.flags = HL_CS_CHUNK_FLAGS_USER_ALLOC_CB;
        it->Serialize((void*)wkld.buffer);
        programs.push_back(wkld);
    }

    unsigned            progBuffSize;
    std::list<unsigned> offsets;

    GetProgBuffSizeAndOffsets(device, &programs, &offsets, &progBuffSize);

    void* progBuff = malloc(progBuffSize);
#if 0
    memset(progBuff, 0, progBuffSize);
#endif

    uint64_t            pAddr        = 0;
    DriverDevice*   driverDevice = dynamic_cast<DriverDevice*>(device);

    pAddr = memAlloc->Allocate(progBuffSize, 0x100);
    assert(pAddr > 0 && "Failed to allocate device memory");
    uint64_t programDeviceAddr = pAddr;
    uint64_t programHostAddr   = reinterpret_cast<uint64_t>(progBuff);

    Buffer programBuffer;
    programBuffer.deviceVirtAddr = programDeviceAddr;
    programBuffer.deviceHandle   = programDeviceAddr;
    programBuffer.hostVirtAddr   = programHostAddr;
    programBuffer.hostHandle     = programHostAddr;
    programBuffer.size           = progBuffSize;
    programBuffer.memSpace       = memSpace;

    std::list<Device::QueueWkld> devicePrograms;
    PrepareProgBuff(device, stream, programBuffer.deviceVirtAddr, &programs, &offsets,
                    programBuffer.size, &devicePrograms,
                    (void*)programBuffer.hostVirtAddr);

    uint64_t addressOut;
    bool ret = driverDevice->MapHostMemory(programBuffer.hostHandle, programBuffer.size, addressOut);
    assert(ret && "Failed to map host memory");
    programBuffer.hostVirtAddr = addressOut;

    DownloadProgram2Device(device, stream, &programBuffer);

    ExecuteProgram(device, stream, &devicePrograms, syncInfo, inputBuffers,
                   outputBuffers);

    ret = driverDevice->UnmapMemory(programBuffer.hostVirtAddr);
    assert(ret && "Failed to unmap host memory");

    free(progBuff);
    for (auto& wkld : programs)
    {
        free((void*)wkld.buffer);
    }
}

void TestLauncher::AddInputFenceSequence(Device* device, CPProgram& prog,
                                         uint32_t syncObjectGroup)
{
    uint64_t qmanBase;
    unsigned stream;
    unsigned qid = prog.GetQId();
    device->GetHal()->Qid2Qman(qid, qmanBase, stream);
    uint64_t fenceAddr;
    switch (stream)
    {
    case 0:
        fenceAddr = qmanBase + device->GetHal()->GetQmanFenceOffset(0, Device::c_streams_num);
        break;
    case 1:
        fenceAddr = qmanBase + device->GetHal()->GetQmanFenceOffset(1, Device::c_streams_num);
        break;
    case 2:
        fenceAddr = qmanBase + device->GetHal()->GetQmanFenceOffset(2, Device::c_streams_num);
        break;
    case 3:
        fenceAddr = qmanBase + device->GetHal()->GetQmanFenceOffset(3, Device::c_streams_num);
        break;
    default:
        assert(0);
    }

    std::shared_ptr<CPCommand::MsgLong> pMsgLong1 = device->GetHal()->GenMsgLong(
        device->GetHal()->GetSyncMngrVarAddr("mon_pay_addrl", qid), // addr
        (uint32_t)fenceAddr);                                       // value
    prog.AddCommandsBack(*pMsgLong1);

    std::shared_ptr<CPCommand::MsgLong> pMsgLong2 = device->GetHal()->GenMsgLong(
        device->GetHal()->GetSyncMngrVarAddr("mon_pay_addrh", qid), // addr
        (uint32_t)(fenceAddr >> 32));                               // value
    prog.AddCommandsBack(*pMsgLong2);

    std::shared_ptr<CPCommand::MsgLong> pMsgLong3 = device->GetHal()->GenMsgLong(
        device->GetHal()->GetSyncMngrVarAddr("mon_pay_data", qid), // addr
        1);                                                        // value
    prog.AddCommandsBack(*pMsgLong3);

    std::shared_ptr<CPCommand::MsgLong> pMsgLong4 =
        device->GetHal()->GenMsgLong(device->GetHal()->GetSyncMngrVarAddr("mon_arm", qid), // addr
                                     device->GetHal()->GetMonArmRawVal(                    // value
                                         254,             // mask // ~(1) in 8 bit
                                         syncObjectGroup, // sid
                                         1,               // sod
                                         0));             // sop
    prog.AddCommandsBack(*pMsgLong4);

    std::shared_ptr<CPCommand::Fence> pFence = device->GetHal()->GenFence(stream, 1, 1);
    prog.AddCommandsBack(*pFence);
}
