/* SPDX-License-Identifier: MIT
 *
 * Copyright 2016-2021 HabanaLabs, Ltd.
 * All Rights Reserved.
 *
 */

#include "memory_allocator.h"

MemoryAllocatorBase::MemoryAllocatorBase(const std::string& name)
  : m_base(0),
    m_memorySize(0),
    m_name(name)
{
}

void MemoryAllocatorBase::Init(DriverDevice* device, bool mmuEnabled, uint64_t memorySize, uint64_t base)
{
    m_memorySize = memorySize;
    m_base       = base;
    m_device = device;
    m_mmuEnabled = mmuEnabled;
}
