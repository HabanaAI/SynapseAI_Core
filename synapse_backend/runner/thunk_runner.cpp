/* SPDX-License-Identifier: MIT
 *
 * Copyright 2016-2021 HabanaLabs, Ltd.
 * All Rights Reserved.
 *
 */

#include "runtime.h"
#include "asic_reg_structs/tpc_regs.h"
#include "gaudi_device.h"
#include <gc_interface.h>
#include "index_space.h"
#include <iostream>

#define SPECIAL_FUNC_256_ENTRIES 0b00
#define SPECIAL_FUNC_128_ENTRIES 0b01
#define SPECIAL_FUNC_64_ENTRIES 0b10
#define SPECIAL_FUNC_32_ENTRIES 0b11

static uint64_t AlignAndIncrementAddress(uint64_t base, uint64_t size, uint64_t alignment = 0x100)
{
    base = (base + alignment - 1) & ~(alignment - 1);
    base += size;
    return base;
}

void AllocDramMemory(Runtime& runner, Buffer& dramBuf, unsigned specialFuncTabNr,
                     uint32_t* specialFuncTabSizes,
                     const gcapi::HabanaKernelParams_t&        gc_input,
                     const gcapi::HabanaKernelInstantiation_t& gc_output,
                     bool                                      specialFunctionUsed)
{
    uint32_t bufSize = 0;
    // ISA requires 13 bit alignment in order to apply ICACHE prefetch.
    uint64_t alignment = 0x2000;
    bufSize = AlignAndIncrementAddress(bufSize, gc_output.kernel.binarySize, alignment);

    if (specialFunctionUsed)
    {
        for (unsigned i = 0; i < specialFuncTabNr; i++)
        {
            bufSize = AlignAndIncrementAddress(bufSize, specialFuncTabSizes[i]);
        }
    }
    runner.AllocateMemory(bufSize, dramBuf, e_dram);
}

void LoadIsa(std::list<Buffer>& inputBuffers, DeviceMemory_t memSpace,
             Runtime& runner, const gcapi::HabanaKernelInstantiation_t& gc_output,
             HWAbstractionLayer::TpcDescHandle mainDesc)
{
    // ISA requires 13 bit alignment in order to apply ICACHE prefetch.
    uint64_t alignment = 0x2000;
    Buffer   isaBuffer;
    runner.AllocateMemory(gc_output.kernel.binarySize, isaBuffer, memSpace, alignment);
    isaBuffer.hostVirtAddr = reinterpret_cast<uint64_t>(gc_output.kernel.kernelBinary);
    isaBuffer.hostHandle   = reinterpret_cast<uint64_t>(gc_output.kernel.kernelBinary);
    runner.MapMemory(isaBuffer, e_dram);
    runner.MapMemory(isaBuffer, e_host);
    runner.m_device.GetHal()->WriteKernelAddr(mainDesc, isaBuffer.deviceVirtAddr);
    inputBuffers.push_back(isaBuffer);
}

void LoadSpecialFuncTab(std::list<Buffer>& inputBuffers, DeviceMemory_t memSpace,
                        Runtime& runner, unsigned specialFuncTabNr,
                        uint32_t* specialFuncTabSizes, uint64_t* specialFuncTabAddresses,
                        std::vector<std::vector<uint8_t>>& specialFunctionCoefficients)
{
    for (unsigned i = 0; i < specialFuncTabNr; i++)
    {
        Buffer tableBuffer;
        runner.AllocateMemory(specialFuncTabSizes[i], tableBuffer, memSpace);
        tableBuffer.hostVirtAddr = reinterpret_cast<uint64_t>(&(specialFunctionCoefficients[i][0]));
        tableBuffer.hostHandle   = reinterpret_cast<uint64_t>(&(specialFunctionCoefficients[i][0]));
        runner.MapMemory(tableBuffer, e_dram);
        runner.MapMemory(tableBuffer, e_host);
        specialFuncTabAddresses[i] = tableBuffer.deviceVirtAddr;
        inputBuffers.push_back(tableBuffer);
    }
}

unsigned int
RunKernel(std::vector<TensorDescriptorGaudi>&       descriptors,
          const gcapi::HabanaKernelParams_t&        gc_input,
          const gcapi::HabanaKernelInstantiation_t& gc_output,
          bool                                      specialFunctionUsed,
          const std::vector<IndexSpace>&            partition,
          Runtime&                                  runner)
{
    uint32_t hwEnTpcMask;
    runner.GetHwIpInfo(hwEnTpcMask);
    // get first available sob and monitor for the device from hlthunk
    runner.m_device.GetSmInfo();

    std::list<Buffer> inputBuffers;
    std::list<Buffer> outputBuffers;

    // copy special function coefficients
    unsigned tabNr = runner.m_device.GetHal()->GetSpecialFuncTabNr();
    uint32_t specialFuncTabSizes[tabNr];
    uint64_t specialFuncTabAddresses[tabNr];
    memset(specialFuncTabSizes, 0, tabNr * sizeof(uint32_t));
    memset(specialFuncTabAddresses, 0, tabNr * sizeof(uint64_t));
    std::vector<std::vector<uint8_t>> specialFunctionCoefficients;
    if (specialFunctionUsed)
    {
        runner.m_device.GetHal()->GetSpecialFuncTabSizes(specialFuncTabSizes, tabNr);
        runner.m_device.GetHal()->CopySpecialFuncTab(specialFunctionCoefficients);
    }

    const int      c_syncObjectIndex = runner.m_device.GetHal()->GetDmaUpSyncObjectIndex();
    const uint64_t c_syncObjectAddr  = runner.m_device.GetHal()->GetDmaUpSyncObjectAddr();
    const int      c_maxTpcId        = runner.m_device.GetHal()->GetTPCNr();

    size_t                            mainDescSize = runner.m_device.GetHal()->GetTpcDescSize();
    HWAbstractionLayer::TpcDescHandle mainDesc;
    mainDesc = malloc(mainDescSize);
    memset(mainDesc, 0, mainDescSize);

    // Set global memory space SRAM / DRAM / HOST
    DeviceMemory_t memSpace;
    memSpace = e_dram;

    // Allocate DRAM memory - pre-process allocate a huge buffer for all data buffers
    // (ISA, LUT, tensors) including alignment considerations.
    Buffer dramBuf;
    if (runner.m_device.IsDramEnabled())
    {
        AllocDramMemory(runner, dramBuf, tabNr, specialFuncTabSizes, gc_input, gc_output, specialFunctionUsed);
    }

    // ISA buffer comes first
    LoadIsa(inputBuffers, memSpace, runner, gc_output, mainDesc);

    // allocate SRAM / DRAM addresses to the lookup tables
    if (specialFunctionUsed)
    {
        LoadSpecialFuncTab(inputBuffers, memSpace, runner, tabNr, specialFuncTabSizes,
                           specialFuncTabAddresses, specialFunctionCoefficients);
    }

    // load SRF
    runner.m_device.GetHal()->WriteSrf(mainDesc, &(gc_output.kernel.scalarParams[0]),
                                          gc_output.kernel.paramsNr);

    runner.m_device.GetHal()->WriteKernelCfg(mainDesc, specialFunctionUsed ? 1 : 0);

    //Tensor descriptors
    for (unsigned i = 0; i < descriptors.size(); ++i)
    {
        runner.m_device.GetHal()->WriteTensorDesc(mainDesc, descriptors[i], i);
    }


    std::vector<int>       tpcIds;
    std::vector<CPProgram> tpcProgram;

    for (int i = 0; i < c_maxTpcId; i++)
    {
        tpcIds.push_back(i);
    }

    std::list<CPProgram> progList;

    unsigned queueNr = 1;

    unsigned activeTpcCount = std::min(partition.size(), tpcIds.size());

    for (unsigned qidx = 0; qidx < queueNr; qidx++)
    {
        for (unsigned i = 0; i < activeTpcCount; i++)
        {
            tpcProgram.push_back(
                    CPProgram(runner.m_device.GetHal()->GetTPCQueueId(tpcIds[i]) + qidx));
            // divide by sync object group size,
            // to convert between sync object ID and sync object group
            TestLauncher::AddInputFenceSequence(
                    &runner.m_device, tpcProgram[activeTpcCount * qidx + i],
                    runner.m_device.GetHal()->GetDmaDownSyncObjectIndex() /
                    runner.m_device.GetHal()->GetSyncObjectGroupSize());
        }

        for (unsigned i = 0; i < partition.size(); i++)
        {
            unsigned j = i % tpcIds.size();

            // generates a unique context ID for each TPC for trace use.
            uint32_t contextId = (uint32_t)0xab + tpcIds[j];

            uint32_t soAddr = (uint32_t)c_syncObjectAddr;
            // if this tpc id receives more then one descriptor - we write 0 to the sync object.
            uint32_t soMsg = 0x80000000;
            // on the last descriptor - we write 1 to the sync object.
            if ((int)i >= ((int)partition.size() - (int)tpcIds.size()))
            {
                soMsg = 0x80000001;
            }

            uint32_t soIdx = (uint32_t)c_syncObjectIndex;

            // Explanation for (i == 0 ? 0 : s_printfIsUsed) :
            // in the first invocation there is no need to update the base address of the printf
            // tensor
            runner.m_device.GetHal()->WriteTpcJobDesc(
                    mainDesc, partition[i], contextId, soAddr, soMsg, soIdx,
                    0, 15);

            // write TPC descriptor to queue manager.
            uint32_t qmOffset = runner.m_device.GetHal()->GetTpcCfgVarOffset("qm_tensor_0");
            tpcProgram[activeTpcCount * qidx + j].AddTclSeq(
                    &runner.m_device, qmOffset, (uint32_t*)mainDesc,
                    mainDescSize / sizeof(uint32_t), false);

            // set lut base address
            uint32_t baseAddrLow, baseAddrHigh;
            int      tabIdx;
            if (specialFunctionUsed)
            {
                for (tabIdx = 0; tabIdx < tabNr; tabIdx++)
                {
                    // read tpc descriptor's table base addr (high and low) offset in descriptor
                    runner.m_device.GetHal()->GetTpcTabOffset(tabIdx, &baseAddrLow,
                                                                 &baseAddrHigh);
                    tpcProgram[activeTpcCount * qidx + j].AddCommandsBack(
                            *runner.m_device.GetHal()->GenWReg32(
                                    baseAddrLow, specialFuncTabAddresses[tabIdx] & 0xFFFFFFFF));
                    tpcProgram[activeTpcCount * qidx + j].AddCommandsBack(
                            *runner.m_device.GetHal()->GenWReg32(
                                    baseAddrHigh, specialFuncTabAddresses[tabIdx] >> 32));
                }
            }
            // set SM_BASE_ADDRESS_HIGH
            tpcProgram[activeTpcCount * qidx + j].AddCommandsBack(
                    *runner.m_device.GetHal()->GenWReg32(
                            runner.m_device.GetHal()->GetTpcCfgVarOffset("sm_base_address_high"),
                            (runner.m_device.GetHal()->GetSyncManagerBaseAddr() >> 32)));

            // Invalidate ICache/DCache/LCache/TCache
            tpc::reg_tpc_cmd command;
            memset(&command, 0, sizeof(command));
            command.icache_invalidate    = 1;
            command.dcache_invalidate    = 1;
            command.lcache_invalidate    = 1;
            command.tcache_invalidate    = 1;
            command.icache_prefetch_64kb = 0;
            bool msgBarrier              = 0;
            bool regBarrier              = 0;
            bool engBarrier              = 1;
            // TPC cmd
            tpcProgram[activeTpcCount * qidx + j].AddCommandsBack(
                    *runner.m_device.GetHal()->GenWReg32(
                            runner.m_device.GetHal()->GetTpcCfgVarOffset("tpc_cmd"), command._raw,
                            msgBarrier, regBarrier, engBarrier));
            // TPC execute
            tpcProgram[activeTpcCount * qidx + j].AddCommandsBack(
                    *runner.m_device.GetHal()->GenWReg32(
                            runner.m_device.GetHal()->GetTpcCfgVarOffset("tpc_execute"), 1));
        }
    }

    for (unsigned i = 0; i < tpcProgram.size(); i++)
    {
        progList.push_back(tpcProgram[i]);
    }

    SyncInfo si = {0};

    // Each monitor objects monitors a group of sync objects.
    // When defining a group of SOs to be tracked by a monitor,
    // we need to divide the SO ID by sync object group size.
    si.outputSOIdx = c_syncObjectIndex / runner.m_device.GetHal()->GetSyncObjectGroupSize();
    // mask of active SO to monitor - only the first SO in SO group is active.
    si.outputSOSel = 1;
    // SO target value = active TPC number
    si.outputSOTarget = activeTpcCount * queueNr;

    TestLauncher::CreateAndExecuteProgram(runner.m_dramAlloc, &runner.m_device,
                                          0, // stream
                                          &progList, &si, &inputBuffers, &outputBuffers,
                                          memSpace);
    free(mainDesc);

    return 0;
}