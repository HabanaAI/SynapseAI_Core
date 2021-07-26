/* SPDX-License-Identifier: MIT
 *
 * Copyright 2016-2021 HabanaLabs, Ltd.
 * All Rights Reserved.
 *
 */

#include "runtime.h"

bool Runtime::GetHwIpInfo(uint32_t& hwEnTpcMask)
{
    hlthunk_hw_ip_info hwInfo;
    bool               ret = m_device.GetHwIpInfo(hwInfo);
    if (ret)
    {
        // In case DRAM is disabled the driver creates a small "dram space" on the SRAM.
        // We don't plan to use it.
        if (!m_device.IsDramEnabled())
        {
            hwInfo.dram_size = 0;
        }
        hwEnTpcMask = hwInfo.tpc_enabled_mask;
    }
    return ret;
}

bool Runtime::AllocateHostMemory(uint64_t size, uint64_t alignment, void** buffer)
{
    *(buffer) = aligned_alloc(alignment, size);
    if (*(buffer) == NULL)
    {
        return false;
    }
    return true;
}

bool Runtime::FreeHostMemory(void* buffer)
{
    free(buffer);
    return true;
}


bool Runtime::AllocateMemory(uint64_t size, Buffer& buffer, DeviceMemory_t deviceMem, uint64_t alignment)
{
    bool                            retVal      = true;
    uint64_t                        pAddr       = 0;
    if (deviceMem == e_host)
    {
        retVal = AllocateHostMemory(size, alignment, (void**)&pAddr);
        if (!retVal)
        {
            return retVal;
        }
        else
        {
            buffer.hostVirtAddr = pAddr;
            buffer.hostHandle   = pAddr;
        }
    }
    else
    {
        SynMemoryAllocator* alloc = (deviceMem == e_dram) ? m_dramAlloc : m_sramAlloc;
        pAddr = alloc->Allocate(size, alignment);
        if (pAddr == 0)
        {
            return false;
        }
        buffer.deviceVirtAddr = reinterpret_cast<uint64_t>(pAddr);
        buffer.deviceHandle   = reinterpret_cast<uint64_t>(pAddr);
        buffer.memSpace       = deviceMem;
    }
    buffer.size = size;
    return retVal;
}

bool Runtime::FreeMemory(Buffer buffer, DeviceMemory_t memLocation)
{
    bool                retVal     = true;
    if (memLocation == e_host)
    {
        retVal = FreeHostMemory((void*)(buffer.hostHandle));
        if (!retVal)
        {
            return retVal;
        }
    }
    else
    {
        SynMemoryAllocator* alloc = (memLocation == e_dram) ? m_dramAlloc : m_sramAlloc;
        alloc->Free(buffer.deviceHandle);
        return true;
    }

    return false;
}

bool Runtime::MapMemory(Buffer& buffer, DeviceMemory_t memLocation, uint64_t hintAddr)
{
    bool     retVal      = true;
    uint64_t virtualAddr = 0;
    if (memLocation == e_host)
    {
        retVal = m_device.MapHostMemory(buffer.hostHandle, buffer.size, virtualAddr, hintAddr);
        if (!retVal)
        {
            return retVal;
        }
        else
        {
            buffer.hostVirtAddr = virtualAddr;
            return true;
        }
    }
    return false;
}

bool Runtime::UnmapMemory(Buffer buffer, DeviceMemory_t memLocation)
{
    bool retVal = true;
    if (memLocation == e_host)
    {
        retVal = m_device.UnmapMemory(buffer.hostVirtAddr);
        return retVal;
    }
    return false;
}
