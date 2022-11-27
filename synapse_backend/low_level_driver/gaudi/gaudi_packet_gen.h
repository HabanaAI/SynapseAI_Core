/* SPDX-License-Identifier: MIT
 *
 * Copyright 2016-2021 HabanaLabs, Ltd.
 * All Rights Reserved.
 *
 */

#pragma once

#include "program.h"
namespace gaudi
{
namespace CPCommand
{
    class NopGen2 : public ::CPCommand::Nop
    {
    public:
        NopGen2(bool mb = true, bool rb = true, bool eb = true) : Nop(mb, eb), m_rb(rb) {};
        virtual unsigned GetSize() const;
        virtual void Serialize(void **buff) const;
        virtual Command *Clone() const;
    private:
        bool m_rb = true;

    };

    class StopGen2 : public ::CPCommand::Stop
    {
    public:
        StopGen2() : Stop() {};
        virtual unsigned GetSize() const;
        virtual void Serialize(void **buff) const;
        virtual Command *Clone() const;
    private:
        bool m_rb = true;
    };

    class WReg32Gen2 : public ::CPCommand::WReg32
    {
    public:
        WReg32Gen2(uint16_t offset, uint32_t value, bool mb = true, bool rb = true, bool eb = true) :
            WReg32(offset, value, mb, eb), m_rb(rb) {};
        virtual unsigned GetSize() const;
        virtual void Serialize(void **buff) const;
        virtual Command *Clone() const;
    private:
        bool m_rb = true;
    };

    class WRegBulkGen2 : public ::CPCommand::WRegBulk
    {
    public:
        WRegBulkGen2() : WRegBulk() {};

        WRegBulkGen2(uint16_t offset, uint64_t* values, unsigned numValues) :
            WRegBulk(offset, values, numValues) {}

        // wregbulk writes in 64-bit words , need to divide num of iteartion by 2.
        WRegBulkGen2(uint16_t offset, uint32_t* values, unsigned numValues) :
            WRegBulk(offset, (uint64_t*)values, numValues/2) {}


        WRegBulkGen2(uint16_t offset, std::list<uint32_t>::const_iterator &begin, std::list<uint32_t>::const_iterator &end) :
            WRegBulk(offset, begin, end) {}

        WRegBulkGen2(uint16_t offset, std::list<uint64_t> &list) :
            WRegBulk(offset, list) {}

        WRegBulkGen2(uint16_t offset, std::list<uint32_t> &list) :
            WRegBulk(offset, list) {}

        WRegBulkGen2(const WRegBulkGen2 &other) :
            WRegBulk(other), m_rb(other.m_rb) {}

        virtual ~WRegBulkGen2() {}

        virtual unsigned GetSize() const;
        virtual void Serialize(void **buff) const;
        virtual Command *Clone() const;
    private:
        bool m_rb = true;
    };

    class MsgLongGen2 : public ::CPCommand::MsgLong
    {
    public:
        MsgLongGen2(uint64_t addr, uint32_t value, bool mb = true, bool rb = true, bool eb = true) :
            MsgLong(addr, value, mb, eb), m_rb(rb) {}

        MsgLongGen2() : MsgLong() {}
        virtual unsigned GetSize() const;
        virtual void Serialize(void **buff) const;
        virtual Command *Clone() const;
    private:
        bool m_rb = true;
    };

    class MsgShortGen2 : public ::CPCommand::MsgShort
    {
    public:
        MsgShortGen2(unsigned base, uint16_t offset, uint32_t value) :
            MsgShort(base, offset, value) {}

        MsgShortGen2() : MsgShort() {}
        virtual unsigned GetSize() const;
        virtual void Serialize(void **buff) const;
        virtual Command *Clone() const;
    private:
        bool m_rb = true;
    };

    class MsgProtGen2 : public ::CPCommand::MsgProt
    {
    public:
        MsgProtGen2(uint64_t addr, uint32_t value, bool mb = true, bool rb = true, bool eb = true) :
            MsgProt(addr, value, mb, eb), m_rb(rb) {}

        MsgProtGen2() : MsgProt() {}

        virtual unsigned GetSize() const;
        virtual void Serialize(void **buff) const;
        virtual Command *Clone() const;
    private:
        bool m_rb = true;
    };

    class FenceGen2 : public ::CPCommand::Fence
    {
    public:
        FenceGen2(unsigned id, uint8_t targetVal, unsigned decVal, bool mb = true, bool rb = true, bool eb = true)
            : Fence(id, targetVal, decVal, mb, eb), m_rb(rb) {}

        FenceGen2() : Fence() {}
        virtual unsigned GetSize() const;
        virtual void Serialize(void **buff) const;
        virtual Command *Clone() const;
    private:
        bool m_rb = true;
    };

    class LinDmaGen2 : public ::CPCommand::LinDma
    {
    public:
        LinDmaGen2(uint64_t dst, uint64_t src, uint32_t tsize, unsigned dmaDir, bool wrComp = 0) :
            LinDma(dst, src, tsize, dmaDir, wrComp) {}

        LinDmaGen2(const LinDmaGen2& other) : LinDma(other), m_rb(other.m_rb) {}

        LinDmaGen2() : LinDma() {};
        virtual unsigned GetSize() const;
        virtual void Serialize(void **buff) const;
        virtual Command *Clone() const;
    private:
        bool m_rb = true;
    };

    class RepeatGen2 : public ::CPCommand::Repeat
    {
    public:
        RepeatGen2(uint16_t jumpPtr = 0) : Repeat(jumpPtr) {}
        virtual unsigned GetSize() const;
        virtual void Serialize(void **buff) const;
        virtual Command *Clone() const;
    private:
        bool m_rb = true;
    };

    class WaitGen2 : public ::CPCommand::Wait
    {
    public:
         WaitGen2(uint32_t cycles, unsigned incVal, unsigned id) :
            Wait(cycles, incVal, id) {}

        WaitGen2() : Wait() {};
        virtual unsigned GetSize() const;
        virtual void Serialize(void **buff) const;
        virtual Command *Clone() const;
    private:
        bool m_rb = true;
    };

    class LoadAndExecGen2 : public ::CPCommand::LoadAndExec
    {
    public:
        LoadAndExecGen2() :
            LoadAndExec() {}
        virtual unsigned GetSize() const;
        virtual void Serialize(void **buff) const;
        virtual Command *Clone() const;
    private:
        bool m_rb = true;
    };

    class CpDmaGen2 : public ::CPCommand::CpDma
    {
    public:
        CpDmaGen2(uint64_t src, uint32_t size) :
            CpDma(src, size) {}

        CpDmaGen2() : CpDma() {}
        virtual unsigned GetSize() const;
        virtual void Serialize(void **buff) const;
        virtual Command *Clone() const;
    private:
        bool m_rb = true;
    };

    class ArbPointGen2 : public ::CPCommand::ArbPoint
    {
    public:
        ArbPointGen2(uint8_t prio) :
            ArbPoint(prio) {}

        ArbPointGen2() : ArbPoint() {}
        virtual unsigned GetSize() const;
        virtual void Serialize(void **buff) const;
        virtual Command *Clone() const;
    private:
        bool m_rb = true;
    };
};

} // namespace gaudi