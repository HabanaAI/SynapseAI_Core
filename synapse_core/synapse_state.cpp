/* SPDX-License-Identifier: MIT
 *
 * Copyright 2016-2021 HabanaLabs, Ltd.
 * All Rights Reserved.
 *
 */

#include "synapse_state.h"
#include "asic_reg_structs/tpc_tensor_regs.h"

unsigned int
RunKernel(std::vector<TensorDescriptorGaudi>&       descriptors,
          const gcapi::HabanaKernelParams_t&        gc_input,
          const gcapi::HabanaKernelInstantiation_t& gc_output,
          bool                                      specialFunctionUsed,
          const std::vector<IndexSpace>&            partition,
          Runtime&                                  runner);


void SynapseState::Init()
{
    if (m_initialized)
    {
        return;
    }
    m_initMutex.lock();
    if (m_initialized)
    {
        m_initMutex.unlock();
        return;
    }

    Stream::g_streamId = 0;

    m_hal    = new GaudiDevice();
    m_runner = new Runtime(m_hal);

    m_kernelDB.init();

    m_initialized = true;
    m_initMutex.unlock();
}

void SynapseState::Destroy()
{
    if (!m_initialized)
    {
        return;
    }
    m_initMutex.lock();
    if (!m_initialized)
    {
        m_initMutex.unlock();
        return;
    }
    m_apiMutex.lock();
    m_initialized = false;
    m_h2dStream.Init(STREAM_TYPE_MAX);
    m_d2hStream.Init(STREAM_TYPE_MAX);
    m_computeStream.Init(STREAM_TYPE_MAX);

    for (const auto& it : m_mappedAddresses)
    {
        m_runner->m_device.UnmapMemory(it.second);
    }
    m_mappedAddresses.clear();
    m_deviceAllocSizes.clear();
    m_freeDram = 0;

    if (m_runner != nullptr)
    {
        if (m_hasDevice)
        {
            m_runner->m_device.CloseDevice();
        }
    }
    delete m_runner;
    m_runner = nullptr;
    delete m_hal;
    m_kernelDB.clear();
    m_hasDevice = false;
    m_apiMutex.unlock();
    m_initMutex.unlock();
}

synStreamHandle SynapseState::CreateStream(const synDeviceId      deviceId,
                                           const synStreamType    streamType,
                                           const uint32_t         flags)
{
    if (!m_initialized) return nullptr;
    std::lock_guard<std::recursive_mutex> l(m_apiMutex);

    if (flags != 0) return nullptr;
    Stream* pStream = nullptr;
    switch (streamType)
    {
        case STREAM_TYPE_COPY_DEVICE_TO_HOST:
            pStream = &m_d2hStream;
            break;
        case STREAM_TYPE_COPY_HOST_TO_DEVICE:
            pStream = &m_h2dStream;
            break;
        case STREAM_TYPE_COMPUTE:
            pStream = &m_computeStream;
            break;
        default:
            return nullptr;
    }
    if (pStream->GetType() != STREAM_TYPE_MAX)
    {
        //Only allow single stream per type
        return nullptr;
    }
    pStream->Init(streamType);
    return (synStreamHandle)pStream;
}

void SynapseState::DestroyStream(synStreamHandle handle)
{
    if (!m_initialized) return;
    std::lock_guard<std::recursive_mutex> l(m_apiMutex);

    if (handle == nullptr) return;
    Stream* pStream = (Stream*)handle;
    pStream->Init(STREAM_TYPE_MAX);
}

bool SynapseState::OpenDevice(const char *pciBusID)
{
    if (!m_initialized) return false;

    std::lock_guard<std::recursive_mutex> l(m_apiMutex);
    if (m_hasDevice) return false;

    m_hasDevice = m_runner->m_device.OpenDevice(pciBusID);
    if (m_hasDevice)
    {
        m_runner->m_device.GetHwIpInfo(m_cachedDeviceInfo);
        m_freeDram = m_cachedDeviceInfo.dram_size - s_stolenMemorySize;
        m_memoryAlloc.Init(m_cachedDeviceInfo.dram_size, m_cachedDeviceInfo.dram_base_address);
        m_sramAlloc.Init(m_cachedDeviceInfo.sram_size, m_cachedDeviceInfo.sram_base_address);
        m_runner->SetDramAlloc(&m_memoryAlloc);
        m_runner->SetSramAlloc(&m_sramAlloc);
    }
    return m_hasDevice;
}

void SynapseState::CloseDevice()
{
    if (!m_initialized) return;

    std::lock_guard<std::recursive_mutex> l(m_apiMutex);
    if (!m_hasDevice) return;

    m_runner->m_device.CloseDevice();
    m_hasDevice = false;
    m_memoryAlloc.Deinit();
}

void* SynapseState::HostAlloc(uint64_t size)
{
    if (!m_initialized) return nullptr;
    std::lock_guard<std::recursive_mutex> l(m_apiMutex);

    if (!m_hasDevice) return nullptr; //no device in which MMU to map the host memory

    void* hostPtr = malloc(size);
    if (hostPtr == nullptr) return hostPtr;
    bool ret = HostMap(hostPtr, size);
    if (!ret)
    {
        free(hostPtr);
        hostPtr = nullptr;
    }
    return hostPtr;
}

void SynapseState::HostFree(void *ptr)
{
    if (!m_initialized) return;
    std::lock_guard<std::recursive_mutex> l(m_apiMutex);

    HostUnmap(ptr);
    free(ptr);
}

bool SynapseState::HostMap(const void *ptr, uint64_t size)
{
    if (!m_initialized) return false;
    std::lock_guard<std::recursive_mutex> l(m_apiMutex);

    if (!m_hasDevice) return false; //no device in which MMU to map the host memory

    if (m_mappedAddresses.find(ptr) != m_mappedAddresses.end()) return true; //already mapped

    uint64_t mappedAddress = 0;
    bool ret = m_runner->m_device.MapHostMemory((Device::Handle)ptr, size, mappedAddress);
    if (ret)
    {
        m_mappedAddresses[ptr] = mappedAddress;
    }
    return ret;
}

bool SynapseState::HostUnmap(const void *ptr)
{
    if (!m_initialized) return false;
    std::lock_guard<std::recursive_mutex> l(m_apiMutex);

    if (!m_hasDevice) return false; //no device in which MMU to unmap the host memory

    const auto& it = m_mappedAddresses.find(ptr);
    if (it == m_mappedAddresses.end()) return false; //Not mapped

    uint64_t mappedAddress = it->second;
    m_mappedAddresses.erase(it);

    return m_runner->m_device.UnmapMemory(mappedAddress);
}

uint64_t SynapseState::DeviceAlloc(uint64_t size)
{
    if (!m_initialized) return false;
    std::lock_guard<std::recursive_mutex> l(m_apiMutex);

    if (!m_hasDevice) return false;

    uint64_t addr = m_memoryAlloc.Allocate(size, 128);
    if (addr == 0)
    {
        addr = s_invalidDeviceAddr;
    }
    else
    {
        m_deviceAllocSizes[addr] = size;
        m_freeDram -= size;
    }
    return addr;
}

void SynapseState::DeviceFree(uint64_t ptr)
{
    if (!m_initialized) return;
    std::lock_guard<std::recursive_mutex> l(m_apiMutex);

    if (!m_hasDevice) return;

    m_memoryAlloc.Free(ptr);
    const auto& it = m_deviceAllocSizes.find(ptr);
    if (it != m_deviceAllocSizes.end())
    {
        m_freeDram += it->second;
        m_deviceAllocSizes.erase(it);
    }
}

bool SynapseState::GetDeviceInfo(hlthunk_hw_ip_info *info)
{
    if (!m_initialized) return false;
    std::lock_guard<std::recursive_mutex> l(m_apiMutex);

    if (!m_hasDevice) return false;
    if (info == nullptr) return false;

    memcpy(info, &m_cachedDeviceInfo, sizeof(m_cachedDeviceInfo));
    return true;
}

uint64_t SynapseState::GetFreeDram()
{
    if (!m_initialized) return 0;
    std::lock_guard<std::recursive_mutex> l(m_apiMutex);

    if (!m_hasDevice) return 0;
    return m_freeDram;
}

bool SynapseState::Memcpy(synStreamHandle streamHandle, uint64_t src, uint32_t size, uint64_t dst, synDmaDir direction)
{
    if (!m_initialized) return false;
    std::lock_guard<std::recursive_mutex> l(m_apiMutex);

    if (!m_hasDevice) return false;

    Stream* stream = (Stream*)streamHandle;
    if (stream == nullptr) return false;
    if (size == 0)         return true;

    bool toDevice = false;
    switch (direction)
    {
        case HOST_TO_DRAM:
            toDevice = true;
            break;

        case DRAM_TO_HOST:
            break;

        default:
            return false;
    }
    if (toDevice)
    {
        if (stream->GetType() != STREAM_TYPE_COPY_HOST_TO_DEVICE) return false;
    }
    else
    {
        if (stream->GetType() != STREAM_TYPE_COPY_DEVICE_TO_HOST) return false;
    }

    uint64_t devicePtr = toDevice ? dst : src;
    void* hostPtr      = toDevice ? (void*)src : (void*)dst;
    const auto& it     = m_mappedAddresses.find(hostPtr);
    if (it == m_mappedAddresses.end()) return false;

    return m_runner->m_device.CopyHostDevice(toDevice, it->second, devicePtr, size);
}

KernelDB* SynapseState::GetKernelDB()
{
    if (!m_initialized) return nullptr;
    std::lock_guard<std::recursive_mutex> l(m_apiMutex);

    return &m_kernelDB;
}

bool SynapseState::Launch(Stream *stream, Recipe *recipe, const synLaunchTensorInfo *launchTensorsInfo, unsigned int numTensors)
{
    if (!m_initialized) return false;
    std::lock_guard<std::recursive_mutex> l(m_apiMutex);
    if (!m_hasDevice) return false;

    if (stream->GetType() != STREAM_TYPE_COMPUTE) return false;
    if (numTensors != (recipe->GetNumTensors() - recipe->GetNumAux())) return false;

    std::map<std::string, uint64_t> tensorBaseAddresses;

    synStreamHandle copyHandle = nullptr;
    bool releaseStream = false;
    if (recipe->GetNumAux() > 0)
    {
        if (m_h2dStream.GetType() == STREAM_TYPE_MAX)
        {
            synStatus ret = synStreamCreate(&copyHandle, 0, STREAM_TYPE_COPY_HOST_TO_DEVICE, 0);
            if (ret != synSuccess) return ret;
            releaseStream = true;
        }
        else
        {
            copyHandle = (synStreamHandle)&m_h2dStream;
        }
    }

    for (unsigned i = 0; i < numTensors; ++i)
    {
        const synLaunchTensorInfo& info = launchTensorsInfo[i];
        if (info.tensorType != DATA_TENSOR) return false;
        std::string name(info.tensorName);
        if (tensorBaseAddresses.find(name) != tensorBaseAddresses.end()) return false;
        tensorBaseAddresses[name] = info.pTensorAddress;
    }

    std::vector<TensorDescriptorGaudi> tensorDescs;
    for (unsigned i = 0; i < numTensors + recipe->GetNumAux(); ++i)
    {
        TensorDescriptorGaudi t;
        const Tensor* tensor = recipe->GetTensor(i);
        std::string name = tensor->GetName();
        uint64_t baseAddress = 0;
        if (!recipe->IsTensorAux(i))
        {
            if (tensorBaseAddresses.find(name) == tensorBaseAddresses.end()) return false;
            baseAddress = tensorBaseAddresses[name];
        }
        else
        {
            //Need to allocate mapped memory and device memory, copy data over to device and point to it
            void* mappedPtr;
            void* hostPtr = recipe->GetAuxHostPtr(i);
            unsigned size = recipe->GetAuxSize(i);
            synStatus ret = synHostMalloc(0, size, 0, &mappedPtr);
            if (ret != synSuccess) return ret;
            ret = synDeviceMalloc(0, size, 0, 0, &baseAddress);
            if (ret != synSuccess)
            {
                synHostFree(0, mappedPtr, 0);
                return ret;
            }
            memcpy(mappedPtr, hostPtr, size);
            ret = synMemCopyAsync(copyHandle, (uint64_t)mappedPtr, size, baseAddress, HOST_TO_DRAM);
            if (ret == synSuccess) ret = synStreamSynchronize(copyHandle);
            synHostFree(0, mappedPtr, 0);
            if (ret != synSuccess) return ret;
        }

        struct tpc_tensor::reg_tensor_config config;
        config._raw           = 0;
        config.last_dim       = 3;
        config.valid_dim_mask = 0xF;
        config.data_type      = 0x7; //FP32

        t.baseAddrUnion.baseAddr = baseAddress;
        t.configuration          = config._raw;
        t.paddingValue           = recipe->GetPaddingValue(i);
        unsigned stride = 1;
        for (unsigned dim = 0; dim < 5; ++dim)
        {
            unsigned size                = tensor->GetSize(dim);
            t.dimDescriptors[dim].size   = size > 0 ? size : 1;
            t.dimDescriptors[dim].stride = stride;
            stride                      *= t.dimDescriptors[dim].size;
        }
        tensorDescs.push_back(t);
    }
    if (releaseStream)
    {
        synStreamDestroy(copyHandle);
    }
    unsigned int ret =
    RunKernel(tensorDescs,
              *recipe->GetParams(),
              *recipe->GetInstance(),
              recipe->GetInstance()->flags.specialFunctionsUsed,
              recipe->GetIndexSpacePartition(),
              *m_runner);

    return (ret == 0);
}