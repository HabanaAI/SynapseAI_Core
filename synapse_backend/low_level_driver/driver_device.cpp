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

bool DriverDevice::OpenDevice(const char* pciId, const hlthunk_device_name deviceName)
{
    for (unsigned tries = 0; tries < c_open_device_max_tries_num; tries++)
    {
        if (!strcmp(pciId, ""))
        {
            m_fd = hlthunk_open(deviceName, NULL);
        }
        else
        {
            m_fd = hlthunk_open(deviceName, pciId);
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
        assert(0 && "Check Driver availability.");
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

    std::vector<hl_cs_chunk> setupChunks(GetHal()->GetQidSize(), hl_cs_chunk{});
    std::vector<hl_cs_chunk> exeChunks(GetHal()->GetQidSize(), hl_cs_chunk{});

    assert(setup.size() <= setupChunks.size());
    assert(wklds.size() <= exeChunks.size());

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
    argsIn.chunks_restore     = setupChunks.data();
    argsIn.chunks_execute     = exeChunks.data();
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
    uint64_t hostVA        = 0;
    int ret;
    bool     isUserCb;
    if (IsMmuEnabled())
    {
        hostAddr = (void*)(new uint8_t[requestedSize]);

        ret = MapHostMemory((uint64_t)hostAddr, requestedSize, hostVA);
        assert(hostVA);
        handle   = hostVA;
        isUserCb = true;
        flags = HL_CS_CHUNK_FLAGS_USER_ALLOC_CB; // CB is allocated by the user
    }
    else
    {
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
        isUserCb = false;
    }
    VirtMem vm = {0};
    vm.addrVirt = hostVA;
    vm.addr    = hostAddr;
    vm.size    = size;
    vm.cbSize  = requestedSize;
    vm.isUserCb = isUserCb;

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
    if (vm.isUserCb)
    {
        ret = UnmapMemory(vm.addrVirt);
        delete[](uint8_t*) vm.addr;
        if (!ret)
        {
            assert(0);
            return false;
        }
    }
    else
    {
        ret = munmap(vm.addr, vm.cbSize);
        if (ret != 0)
        {
            assert(0);
            return false;
        }
        ret = hlthunk_destroy_command_buffer(m_fd, (__u64)handle);
        if (ret != 0)
        {
            assert(0);
            return false;
        }
    }

    m_cbHandles.erase(handle);

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

uint64_t DriverDevice::dramMemoryAllocAndMap()
{
    uint64_t size = c_dram_phys_size;

    m_dramHandle   = hlthunk_device_memory_alloc(m_fd, size, 0, false, false); // contiguous = 0
    m_dramVirtAddr = 0;
    assert(m_dramHandle);
    m_dramVirtAddr = hlthunk_device_memory_map(m_fd, m_dramHandle, 0);
    if (!m_dramVirtAddr)
    {
        dramMemoryFree();
        assert(0);
        return 0;
    }

    return m_dramVirtAddr;
}

bool DriverDevice::dramMemoryFree()
{
    if (m_dramHandle) {
        int ret = hlthunk_device_memory_free(m_fd, m_dramHandle);
        if (ret) {
            return false;
        } else {
        }
        m_dramHandle = 0;
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
    c_dram_phys_size = hwInfo.dram_size;
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
    return GetHal()->isMmuEnabled();
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
    workload.flags  = flags;
    workload.buffer = handle;
    workload.qid    = toDevice ? GetHal()->GetDMAInQid() : GetHal()->GetDMAOutQid();

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
