/* SPDX-License-Identifier: MIT
 *
 * Copyright 2016-2021 HabanaLabs, Ltd.
 * All Rights Reserved.
 *
 */

#ifndef _MEMORY_ALLOCATOR_H_
#define _MEMORY_ALLOCATOR_H_

#include <cstdint>
#include <memory>

class SynMemoryAllocator
{
public:
    SynMemoryAllocator() {}
    virtual ~SynMemoryAllocator() {}
    virtual void Init(uint64_t memorySize, uint64_t base = 0) = 0;
    virtual uint64_t Allocate(uint64_t size, uint64_t alignment, uint64_t offset = 0) = 0;
    virtual void Free(uint64_t ptr) = 0;
    virtual uint64_t GetMemorySize() const = 0;
    virtual uint64_t GetMemoryBase() const = 0;

protected:
};

class MemoryAllocatorBase : public SynMemoryAllocator
{
public:
    MemoryAllocatorBase(const std::string& name);
    virtual ~MemoryAllocatorBase() {}
    virtual void Init(uint64_t memorySize, uint64_t base = 0) override;
    virtual uint64_t Allocate(uint64_t size, uint64_t alignment, uint64_t offset = 0) = 0;
    virtual void Free(uint64_t ptr) override = 0;

    virtual uint64_t GetMemorySize() const override {return m_memorySize;}
    virtual uint64_t GetMemoryBase() const override {return m_base;}

protected:
    uint64_t            m_base;
    uint64_t            m_memorySize;

    const std::string   m_name;
};

#endif
