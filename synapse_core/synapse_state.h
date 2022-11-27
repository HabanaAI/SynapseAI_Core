/* SPDX-License-Identifier: MIT
 *
 * Copyright 2016-2021 HabanaLabs, Ltd.
 * All Rights Reserved.
 *
 */

#pragma once
#include <mutex>
#include <map>
#include "synapse_api.h"
#include "stream.h"
#include "node.h"
#include "synapse_api_types.h"
#include "synapse_common_types.h"
#include "tensor.h"
#include "heap_allocator.h"
#include "kernel_db.h"
#include "recipe.h"

#include "runtime.h"
#include "hw_abstraction_layer.h"

class SynapseState
{
public:
    SynapseState() : m_initialized(false), m_hasDevice(false), m_freeDram(0), m_memoryAlloc("Device Alloc"), m_sramAlloc("SRAM Alloc") {}
    ~SynapseState() {}

    void Init();
    void Destroy();
    synStreamHandle CreateStream(const synDeviceId      deviceId,
                                 const synStreamType    streamType,
                                 const uint32_t         flags);

    void DestroyStream(synStreamHandle handle);

    bool OpenDevice(const char* pciBusID, const synDeviceType deviceType);
    void CloseDevice();

    void* HostAlloc(uint64_t size);
    void  HostFree(void* ptr);
    uint64_t DeviceAlloc(uint64_t size);
    void DeviceFree(uint64_t ptr);
    bool HostMap(const void* ptr, uint64_t size);
    bool HostUnmap(const void* ptr);

    bool GetDeviceInfo(hlthunk_hw_ip_info* info);
    uint64_t GetFreeDram();

    bool Memcpy(synStreamHandle streamHandle, uint64_t src, uint32_t size, uint64_t dst, synDmaDir direction);

    bool Launch(Stream* stream, Recipe* recipe, const synLaunchTensorInfo* launchTensorsInfo, unsigned numTensors);

    KernelDB* GetKernelDB(synDeviceType deviceType);
    synDeviceType getCurrentDeviceType() const;
    static const uint64_t s_stolenMemorySize  = 512ULL*1024ULL*1024ULL; //0.5GB
    static const uint64_t s_invalidDeviceAddr = std::numeric_limits<uint64_t>::max();

private:
    bool                 m_initialized;
    bool                 m_hasDevice;
    std::mutex           m_initMutex;
    std::recursive_mutex m_apiMutex;
    Stream               m_h2dStream;
    Stream               m_d2hStream;
    Stream               m_computeStream;

    HWAbstractionLayer*  m_hal;
    Runtime*             m_runner;
    hlthunk_hw_ip_info   m_cachedDeviceInfo;

    uint64_t             m_freeDram;

    std::map<const void*, uint64_t> m_mappedAddresses;
    std::map<uint64_t, uint64_t>    m_deviceAllocSizes;

    HeapAllocator                   m_memoryAlloc;
    HeapAllocator                   m_sramAlloc;
    KernelDB                        m_kernelDB;
};
