/* SPDX-License-Identifier: MIT
 *
 * Copyright 2016-2021 HabanaLabs, Ltd.
 * All Rights Reserved.
 *
 */

#ifndef WIN32
#    undef NDEBUG
#    include <assert.h>
#    include <limits.h>
#    include <algorithm>
#    include <stdint.h>
#    include <fcntl.h>
#    include <stdio.h>
#    include <cstring>
#    include <sys/ioctl.h>
#    include <sys/mman.h>
#    include <unistd.h>
#    include <errno.h>
#    include <dlfcn.h>
#    include "driver_device.h"

static const unsigned c_usecs_between_open_tries  = 1000;
static const unsigned c_open_device_max_tries_num = 100;

DriverDevice::DriverDevice(HWAbstractionLayer* pHal) : Device(pHal), m_fd(-1)
{
}

DriverDevice::~DriverDevice()
{
    assert(m_cbHandles.empty());
    assert(m_fd == -1);
}

bool DriverDevice::OpenDevice(const char* pciId)
{
    for (unsigned tries = 0; tries < c_open_device_max_tries_num; tries++)
    {
        if (!strcmp(pciId, ""))
        {
            m_fd = hlthunk_open(HLTHUNK_DEVICE_GAUDI, NULL);
        }
        else
        {
            m_fd = hlthunk_open(HLTHUNK_DEVICE_GAUDI, pciId);
        }

        if ((m_fd == -1) && ((errno == EBUSY) || (errno == EAGAIN)))
        {
            usleep(c_usecs_between_open_tries);
        }
        else
        {
            break;
        }
    }

    if (m_fd < 0)
    {
        assert(0 && "Check Driver availability. If using -pci, check pci address provided.");
        return false;
    }
    else
    {
        return true;
    }
}

void DriverDevice::CloseDevice()
{
    assert(m_cbHandles.empty());
    assert(m_fd != -1);
    hlthunk_close(m_fd);
    m_fd = -1;
}

bool DriverDevice::SubmitWklds(const std::list<QueueWkld>& setup,
                                   const std::list<QueueWkld>& wklds, bool forceSetup,
                                   Handle& handle)
{
    if (m_fd == -1)
    {
        assert(0);
        return false;
    }
    assert(!wklds.empty() || !setup.empty());

    hl_cs_chunk setupChunks[GAUDI_ENGINE_ID_SIZE];
    hl_cs_chunk exeChunks[GAUDI_ENGINE_ID_SIZE];
    memset(&exeChunks, 0, sizeof(exeChunks));
    memset(&setupChunks, 0, sizeof(setupChunks));
    assert(setup.size() <= (sizeof(setupChunks) / sizeof(setupChunks[0])));
    assert(wklds.size() <= (sizeof(exeChunks) / sizeof(exeChunks[0])));

    unsigned idx = 0;
    for (auto& su : setup)
    {
        setupChunks[idx].cb_handle      = su.buffer;
        setupChunks[idx].cb_size        = su.size;
        setupChunks[idx].queue_index    = su.qid;
        setupChunks[idx].cs_chunk_flags = su.flags;
        idx++;
    }

    idx = 0;
    for (auto& wkld : wklds)
    {
        exeChunks[idx].cb_handle      = wkld.buffer;
        exeChunks[idx].cb_size        = wkld.size;
        exeChunks[idx].queue_index    = wkld.qid;
        exeChunks[idx].cs_chunk_flags = wkld.flags;
        idx++;
    }

    hlthunk_cs_in  argsIn;
    hlthunk_cs_out argsOut;
    memset(&argsIn, 0, sizeof(hlthunk_cs_in));
    memset(&argsOut, 0, sizeof(hlthunk_cs_out));
    argsIn.chunks_restore     = setupChunks;
    argsIn.chunks_execute     = exeChunks;
    argsIn.num_chunks_restore = setup.size();
    argsIn.num_chunks_execute = wklds.size();
    argsIn.flags              = forceSetup ? HL_CS_FLAGS_FORCE_RESTORE : 0;

    int ret = hlthunk_command_submission(m_fd, &argsIn, &argsOut);
    if ((ret != 0) || (argsOut.status != HL_CS_STATUS_SUCCESS))
    {
        assert(0 && " Please check you're using the correct device ");
        return false;
    }
    else
    {
        handle = (Device::Handle)argsOut.seq;
        return true;
    }
}

bool DriverDevice::Wait(Handle handle)
{
    if (m_fd == -1)
    {
        assert(0);
        return false;
    }

    uint32_t status;
    int ret = hlthunk_wait_for_cs(m_fd, (__u64)handle, LONG_MAX, &status);

    if ((ret != 0) || (status != HL_WAIT_CS_STATUS_COMPLETED))
    {
        assert(0);
        return false;
    }
    else
    {
        return true;
    }
}

bool DriverDevice::GetCB(unsigned size, Handle& handle, void*& hostAddr, unsigned& flags)
{
    if (m_fd == -1)
    {
        assert(0);
        return false;
    }
    static const unsigned int c_page_size = getpagesize();
    assert(size);
    unsigned requestedSize = std::max(size, c_page_size);

    int ret;

    ret = hlthunk_request_command_buffer(m_fd, requestedSize, &handle);

    if (ret != 0)
    {
        assert(0);
        return false;
    }

    if (m_cbHandles.find(handle) != m_cbHandles.end())
    {
        assert(0);
        return false;
    }
    flags = 0; // CB is not allocated by the user
    // mapping handle to host address
    hostAddr = mmap(0, size, PROT_READ | PROT_WRITE, MAP_SHARED, m_fd, (off_t)handle);

    if (!hostAddr)
    {
        assert(0);
        return false;
    }

    VirtMem vm = {0};
    vm.addr    = hostAddr;
    vm.size    = size;
    vm.cbSize  = requestedSize;

    m_cbHandles[handle] = vm;

    return true;
}

bool DriverDevice::ReleaseCB(Handle handle)
{
    if (m_fd == -1)
    {
        assert(0);
        return false;
    }

    if (m_cbHandles.find(handle) == m_cbHandles.end())
    {
        assert(0);
        return false;
    }

    VirtMem vm = m_cbHandles[handle];

    int                 ret;
    hlthunk_device_name deviceName = GetDeviceName();
    if ((deviceName == HLTHUNK_DEVICE_GOYA) || (deviceName == HLTHUNK_DEVICE_GAUDI) ||
        (!IsMmuEnabled()))
    {
        ret = munmap(vm.addr, vm.size);
        if (ret != 0)
        {
            assert(0);
            return false;
        }

        ret = hlthunk_destroy_command_buffer(m_fd, (__u64)handle);
    }
    else
    {
        hlthunk_memory_unmap(m_fd, handle);
        free(m_cbHandles[handle].addr);
        ret = 0;
    }

    m_cbHandles.erase(handle);

    if (ret != 0)
    {
        assert(0);
        return false;
    }

    return true;
}

bool DriverDevice::MapHostMemory(Handle hostAddr, unsigned size, uint64_t& virtualAddr,
                                     uint64_t hintAddr)
{
    if (m_fd == -1)
    {
        assert(0);
        return false;
    }

    virtualAddr = hlthunk_host_memory_map(m_fd, (void*)hostAddr, hintAddr, size);

    if (virtualAddr == 0)
    {
        assert(0);
        return false;
    }

    return true;
}

bool DriverDevice::UnmapMemory(uint64_t addr)
{
    if (m_fd == -1)
    {
        assert(0);
        return false;
    }

    int ret = hlthunk_memory_unmap(m_fd, addr);

    if (ret != 0)
    {
        assert(0);
        return false;
    }

    return true;
}

bool DriverDevice::GetHwIpInfo(hlthunk_hw_ip_info& hwInfo)
{
    if (m_fd == -1)
    {
        assert(0);
        return false;
    }

    memset(&hwInfo, 0, sizeof(hwInfo));

    int ret = hlthunk_get_hw_ip_info(m_fd, &hwInfo);

    if (ret != 0)
    {
        assert(0);
        return false;
    }

    return true;
}

bool DriverDevice::GetSmInfo()
{
    if (m_fd == -1)
    {
        assert(0);
        return false;
    }

    hlthunk_sync_manager_info smInfo;
    memset(&smInfo, 0, sizeof(smInfo));

    int ret = hlthunk_get_sync_manager_info(m_fd, 0 /*DCORE number*/, &smInfo);

    if (ret != 0)
    {
        assert(0);
        return false;
    }

    DriverDevice::GetHal()->SetSmInfo(smInfo.first_available_sync_object,
                                          smInfo.first_available_monitor);
    return true;
}

hlthunk_device_name DriverDevice::GetDeviceName()
{
    hlthunk_device_name deviceName = hlthunk_get_device_name_from_fd(m_fd);
    return deviceName;
}

bool DriverDevice::IsDramEnabled()
{
    return true;
}

bool DriverDevice::IsMmuEnabled()
{
    return true;
}

bool DriverDevice::CopyHostDevice(bool toDevice, uint64_t hostPtr, uint64_t devicePtr, uint32_t size)
{
    std::shared_ptr<CPCommand::LinDma> pCommand;
    if (toDevice)
    {
        pCommand = GetHal()->GenLinDma(devicePtr, hostPtr, size, 0);
    }
    else
    {
        pCommand = GetHal()->GenLinDma(hostPtr, devicePtr, size, 0);
    }
    unsigned int cmdSize = pCommand->GetSize();
    Handle handle;
    void* cbAddr;
    unsigned flags = 0;
    bool ret = GetCB(cmdSize, handle, cbAddr, flags);
    if (!ret) return ret;

    pCommand->Serialize(&cbAddr);

    QueueWkld workload;
    std::list<QueueWkld> setup;
    std::list<QueueWkld> execute;

    workload.size   = cmdSize;
    workload.flags  = 0;
    workload.buffer = handle;
    workload.qid    = toDevice ? GAUDI_QUEUE_ID_DMA_0_0 : GAUDI_QUEUE_ID_DMA_1_0;

    execute.push_back(workload);

    Handle submissionHandle;
    ret = SubmitWklds(setup, execute, false, submissionHandle);
    if (!ret)
    {
        ReleaseCB(handle);
        return ret;
    }
    ret = Wait(submissionHandle);
    ReleaseCB(handle);
    return ret;
}

#endif
