/* SPDX-License-Identifier: MIT
 *
 * Copyright 2016-2021 HabanaLabs, Ltd.
 * All Rights Reserved.
 *
 */

#pragma once
#include <vector>
#include "device.h"
#include "program.h"
#include "memory_allocator.h"

static const unsigned c_cl_size = 256;

enum DeviceType
{
    e_null = 0,
    e_sim,
    e_chip
};
class Device;

enum DmaDirection
{
    DMA_HOST_TO_DRAM,
    DMA_HOST_TO_SRAM,
    DMA_DRAM_TO_SRAM,
    DMA_SRAM_TO_DRAM,
    DMA_SRAM_TO_HOST,
    DMA_DRAM_TO_HOST,
    DMA_DRAM_TO_DRAM,
    DMA_SRAM_TO_SRAM,
    DMA_ENUM_MAX
};

typedef enum
{
    e_sram          = 0,
    e_dram          = 1,
    e_host          = 2,
} DeviceMemory_t;

struct Buffer
{
    uint64_t hostVirtAddr;
    uint64_t deviceVirtAddr;
    uint32_t size;
    // Handle can be either a handle (address id) we received from hl_thunk,
    // or the physical host/device address.
    Device::Handle hostHandle;
    Device::Handle deviceHandle;
    DeviceMemory_t memSpace;
};

struct ArbitrationInfo
{
    bool enable;
    unsigned prio;
};

struct SyncInfo
{
    unsigned outputSOIdx;
    unsigned outputSOSel;
    unsigned outputSOTarget;
};


class TestLauncher
{
public:
    static void DownloadProgram2Device(
        Device *device,
        const unsigned stream,
        const Buffer* progBuff);
    static void ExecuteProgram(
        Device *device,
        const unsigned stream,
        const std::list<Device::QueueWkld> *devicePrograms,
        const SyncInfo *syncInfo,
        const std::list<Buffer> *inputBuffers,
        const std::list<Buffer> *outputBuffers);
    static void AddInputFenceSequence(
        Device *device,
        CPProgram &prog,
        uint32_t syncObjectGroup);
    static void CreateAndExecuteProgram(
        SynMemoryAllocator *memAlloc,
        Device *device,
        const unsigned stream,
        const std::list<CPProgram> *progs,
        const SyncInfo *syncInfo,
        const std::list<Buffer> *inputBuffers,
        const std::list<Buffer> *outputBuffers,
        DeviceMemory_t memSpace);

private:
  static void ResetSoObjsInDevice(Device *device, const SyncInfo* syncInfo,
                                  unsigned stream);
  static void
  GetProgBuffSizeAndOffsets(Device *device,
                            const std::list<Device::QueueWkld> *programs,
                            std::list<unsigned> *offsets, unsigned *size);
  static void PrepareProgBuff(Device *device, const unsigned stream,
                              const uint64_t deviceAddr,
                              const std::list<Device::QueueWkld> *programs,
                              const std::list<unsigned> *offsets,
                              const unsigned bufferSize,
                              std::list<Device::QueueWkld> *devicePrograms,
                              void *progBuff);
  static void addMonitorForNode(Device* device,
                                unsigned stream,
                                const SyncInfo* syncInfo,
                                uint32_t outMonitorIdx,
                                uint64_t fenceAddr,
                                uint8_t** CBPtr,
                                CPProgram* prog,
                                bool addFence);


};
