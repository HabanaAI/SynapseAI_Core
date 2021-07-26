/* SPDX-License-Identifier: MIT
 *
 * Copyright 2016-2021 HabanaLabs, Ltd.
 * All Rights Reserved.
 *
 */

#include <cassert>
#include <iterator>

#include "heap_allocator.h"

HeapAllocator::HeapAllocator(const std::string &name) : MemoryAllocatorBase(name)
{
}

void HeapAllocator::Init(uint64_t memorySize, uint64_t base)
{
    std::lock_guard<std::mutex> l(m_mutex);
    MemoryAllocatorBase::Init(memorySize, base);

    Range allRanges;
    allRanges.size        = m_memorySize;
    allRanges.base        = m_base;

    m_freeRanges.push_back(allRanges);
}

void HeapAllocator::Deinit()
{
    std::lock_guard<std::mutex> l(m_mutex);
    m_freeRanges.clear();
    m_occupiedRanges.clear();
    m_memorySize = 0;
    m_base       = 0;
}

uint64_t HeapAllocator::Allocate(uint64_t size, uint64_t alignment, uint64_t offset)
{
    std::lock_guard<std::mutex> l(m_mutex);
    uint64_t allocSize = size + offset + alignment - 1;

    Range newAlloc;

    //find a large enough allocation
    for (std::list<Range>::iterator it = m_freeRanges.begin(); it != m_freeRanges.end(); ++it)
    {
        if (it->size >= allocSize)
        {
            //allocate from here
            newAlloc.base = it->base;
            newAlloc.size = allocSize;
            it->size      -= allocSize;
            it->base      += allocSize;
            if (it->size == 0)
            {
                m_freeRanges.erase(it);
            }

            uint64_t retAddr = newAlloc.base;
            if ((retAddr % alignment) != 0)
            {
                retAddr += ((alignment) - (retAddr % alignment));
            }
            retAddr += offset;
            m_occupiedRanges[retAddr] = newAlloc;
            return retAddr;
        }
    }
    //failed to allocate
    return 0;
}

void HeapAllocator::Free(uint64_t ptr)
{
    std::lock_guard<std::mutex> l(m_mutex);
    const auto& r = m_occupiedRanges.find(ptr);
    if (r == m_occupiedRanges.end()) return;

    Range oldRange = r->second;
    m_occupiedRanges.erase(r);

    if (m_freeRanges.empty())
    {
        m_freeRanges.push_back(oldRange);
        return;
    }

    for (std::list<Range>::iterator it = m_freeRanges.begin(); it != m_freeRanges.end(); ++it)
    {
        if (it->base + it->size < oldRange.base) continue;

        if (it->base + it->size == oldRange.base)
        {
            //Need to coalesce with segment to the left
            it->size += oldRange.size;
            auto next_it = std::next(it);
            if (it->base + it->size == next_it->base)
            {
                //coalesce with right too
                it->size += next_it->size;
                m_freeRanges.erase(next_it);
                return;
            }
        }

        if (oldRange.base + oldRange.size == it->base)
        {
            //Need to coalesce with right
            it->base -= oldRange.size;
            it->size += oldRange.size;

            //No need to check for left coalescing since we checked above
            return;
        }

        //Otherwise this is just a boring insertion
        m_freeRanges.insert(it, oldRange);
    }

    //Can get here in case we alloc ABC with C being the size of the entire memory minus A+B, then free A then C
    m_freeRanges.insert(m_freeRanges.end(), oldRange);
}