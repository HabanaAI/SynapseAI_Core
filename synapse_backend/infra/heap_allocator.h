/* SPDX-License-Identifier: MIT
 *
 * Copyright 2016-2021 HabanaLabs, Ltd.
 * All Rights Reserved.
 *
 */

#pragma once
#include <list>
#include <map>
#include <mutex>
#include "memory_allocator.h"

class HeapAllocator : public MemoryAllocatorBase
{
public:
    struct Range
    {
        uint64_t base;
        uint64_t size;
    };

    HeapAllocator(const std::string& name);
    virtual ~HeapAllocator() {}

    virtual void     Init(uint64_t memorySize, uint64_t base = 0) override;
    void             Deinit();
    virtual uint64_t Allocate(uint64_t size, uint64_t alignment, uint64_t offset = 0) override;
    virtual void     Free(uint64_t ptr) override;

private:

    //A Sorted (by start address) list of free ranges
    std::list<Range>          m_freeRanges;
    //A container for existing allocations
    std::map<uint64_t, Range> m_occupiedRanges;

    std::mutex                m_mutex;
};

