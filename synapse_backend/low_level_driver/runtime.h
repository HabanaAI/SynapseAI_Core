/* SPDX-License-Identifier: MIT
 *
 * Copyright 2016-2021 HabanaLabs, Ltd.
 * All Rights Reserved.
 *
 */

#pragma once

#include "launcher.h"
#include "driver_device.h"
#include "memory_allocator.h"
#include <unordered_map>

#define PAGE_SIZE_4K            0x00001000

class Runtime
{
public:
    Runtime(HWAbstractionLayer* pHal) : m_device(pHal) {}
    virtual ~Runtime() {}
    bool GetHwIpInfo(uint32_t& hwEnTpcMask);
    void SetSramAlloc(SynMemoryAllocator* alloc) { m_sramAlloc = alloc; }
    void SetDramAlloc(SynMemoryAllocator* alloc) { m_dramAlloc = alloc; }
    bool AllocateMemory(
                uint64_t size,
                Buffer& buffer,
                DeviceMemory_t deviceMem = e_dram,
                uint64_t alignment = 0x100);
    bool FreeMemory(
                Buffer buffer,
                DeviceMemory_t memLocation);
    bool MapMemory(
                Buffer& buffer,
                DeviceMemory_t memLocation,
                uint64_t hintAddr = 0);
    bool UnmapMemory(
                Buffer buffer,
                DeviceMemory_t memLocation);

    SynMemoryAllocator*     m_sramAlloc;
    SynMemoryAllocator*     m_dramAlloc;
    DriverDevice        m_device;

protected:
    bool AllocateHostMemory(uint64_t size, uint64_t alignment, void** buffer);
    bool FreeHostMemory(void* buffer);

private:
    Runtime(const Runtime& other) = delete;
    Runtime& operator=(const Runtime& other) = delete;
};
