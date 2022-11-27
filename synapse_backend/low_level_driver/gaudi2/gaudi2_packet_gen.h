/* SPDX-License-Identifier: MIT
 *
 * Copyright 2016-2021 HabanaLabs, Ltd.
 * All Rights Reserved.
 *
 */

#pragma once

#include "../program.h"

namespace gaudi2
{
namespace CPCommand
{
    class NopGen6 : public ::CPCommand::Nop
    {
    public:
        NopGen6(bool mb = true, bool eb = true) : Nop(mb, eb) {};
        virtual unsigned GetSize() const;
        virtual void Serialize(void **buff) const;
        virtual Command *Clone() const;
    private:
        bool m_swtc = false;
    };

    class StopGen6 : public ::CPCommand::Stop
    {
    public:
        StopGen6() : Stop() {};
        virtual unsigned GetSize() const;
        virtual void Serialize(void **buff) const;
        virtual Command *Clone() const;
    private:
        bool m_swtc = false;
    };

    class WReg32Gen6 : public ::CPCommand::WReg32
    {
    public:
        WReg32Gen6(uint16_t offset, uint32_t value, bool mb = true, bool eb = true) :
            WReg32(offset, value, mb, eb) {}
        WReg32Gen6() : WReg32() {};
        virtual unsigned GetSize() const;
        virtual void Serialize(void **buff) const;
        virtual Command *Clone() const;
    private:
        bool m_swtc = false;
    };

    class WRegBulkGen6 : public ::CPCommand::WRegBulk
    {
    public:
        WRegBulkGen6() : WRegBulk() {};

         WRegBulkGen6(uint16_t offset, uint64_t* values, unsigned numValues) :
            WRegBulk(offset, values, numValues) {}

        // wregbulk writes in 64-bit words , need to divide num of iteartion by 2.
        WRegBulkGen6(uint16_t offset, uint32_t* values, unsigned numValues) :
            WRegBulk(offset, (uint64_t*)values, numValues/2) {}


        WRegBulkGen6(uint16_t offset, std::list<uint32_t>::const_iterator &begin, std::list<uint32_t>::const_iterator &end) :
            WRegBulk(offset, begin, end) {}

        WRegBulkGen6(uint16_t offset, std::list<uint64_t> &list) :
            WRegBulk(offset, list) {}

        WRegBulkGen6(uint16_t offset, std::list<uint32_t> &list) :
            WRegBulk(offset, list) {} 

        WRegBulkGen6(const WRegBulkGen6 &other) :
            WRegBulk(other), m_swtc(other.m_swtc) {}

        virtual ~WRegBulkGen6() {}

        virtual unsigned GetSize() const;
        virtual void Serialize(void **buff) const;
        virtual Command *Clone() const;
    private:
        bool m_swtc = false;
    };

    class MsgLongGen6 : public ::CPCommand::MsgLong
    {
    public:
        MsgLongGen6(uint64_t addr, uint32_t value, bool mb = true, bool eb = true) :
            MsgLong(addr, value, mb, eb) {}

        MsgLongGen6() : MsgLong() {}
        virtual unsigned GetSize() const;
        virtual void Serialize(void **buff) const;
        virtual Command *Clone() const;
    private:
        bool m_swtc = false;
    };

    class MsgShortGen6 : public ::CPCommand::MsgShort
    {
    public:
        MsgShortGen6(unsigned base, uint16_t offset, uint32_t value) :
            MsgShort(base, offset, value) {}
        MsgShortGen6() : MsgShort(0, 0, 0) {}
        virtual unsigned GetSize() const;
        virtual void Serialize(void **buff) const;
        virtual Command *Clone() const;
    private:
        bool m_swtc = false;
    };

    class MsgProtGen6 : public ::CPCommand::MsgProt
    {
    public:
        MsgProtGen6(uint64_t addr, uint32_t value, bool mb = true, bool eb = true) :
            MsgProt(addr, value, mb, eb) {} 

        MsgProtGen6() : MsgProt(0, 0) {}
        virtual unsigned GetSize() const;
        virtual void Serialize(void **buff) const;
        virtual Command *Clone() const;
    private:
        bool m_swtc = false;
    };

    class FenceGen6 : public ::CPCommand::Fence
    {
    public:
        FenceGen6(unsigned id, uint8_t targetVal, unsigned decVal, bool mb = true, bool eb = true)
            : Fence(id, targetVal, decVal, mb, eb) {}

        FenceGen6() : Fence() {}
        virtual unsigned GetSize() const;
        virtual void Serialize(void **buff) const;
        virtual Command *Clone() const;
    private:
        bool m_swtc = false;
    };

    class LinDmaGen6 : public ::CPCommand::LinDma
    {
    public:
        LinDmaGen6(uint64_t dst, uint64_t src, uint32_t tsize, unsigned dmaDir, bool wrComp = 0) :
            LinDma(dst, src, tsize, dmaDir, wrComp) {}

        LinDmaGen6(const LinDmaGen6& other) : LinDma(other), m_swtc(other.m_swtc) {}

        LinDmaGen6() : LinDma() {};
        virtual unsigned GetSize() const;
        virtual void Serialize(void **buff) const;
        virtual Command *Clone() const;
    private:
        bool m_swtc = false;
    };

    class RepeatGen6 : public ::CPCommand::Repeat
    {
    public:
        RepeatGen6(uint16_t jumpPtr = 0) : Repeat(jumpPtr) {}
        virtual unsigned GetSize() const;
        virtual void Serialize(void **buff) const;
        virtual Command *Clone() const;
    private:
        bool m_swtc = false;
    };

    class WaitGen6 : public ::CPCommand::Wait
    {
    public:
        WaitGen6(uint32_t cycles, unsigned incVal, unsigned id) :
            Wait(cycles, incVal, id) {}

        WaitGen6() : Wait(0, 0, 0) {};
        virtual unsigned GetSize() const;
        virtual void Serialize(void **buff) const;
        virtual Command *Clone() const;
    private:
        bool m_swtc = false;
    };

    class LoadAndExecGen6 : public ::CPCommand::LoadAndExec
    {
    public:
        LoadAndExecGen6() : LoadAndExec() {}

        virtual unsigned GetSize() const;
        virtual void Serialize(void **buff) const;
        virtual Command *Clone() const;
    private:
        bool m_swtc = false;
    };

    class CpDmaGen6 : public ::CPCommand::CpDma
    {
    public:
        CpDmaGen6(uint64_t src, uint32_t size) : CpDma(src, size) {}

        CpDmaGen6() : CpDma() {}
        virtual unsigned GetSize() const;
        virtual void Serialize(void **buff) const;
        virtual Command *Clone() const;
    private:
        bool m_swtc = false;
    };

    class ArbPointGen6 : public ::CPCommand::ArbPoint
    {
    public:
        ArbPointGen6(uint8_t prio) :
            ArbPoint(prio) {} 

        ArbPointGen6() : ArbPoint() {}
        virtual unsigned GetSize() const;
        virtual void Serialize(void **buff) const;
        virtual Command *Clone() const;
    private:
        bool m_swtc = false;
    };
};

} // namespace gaudi2