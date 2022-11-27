/* SPDX-License-Identifier: MIT
 *
 * Copyright 2016-2021 HabanaLabs, Ltd.
 * All Rights Reserved.
 *
 */

#pragma once
#include <cstdlib>
#include <string.h>
#include <stdint.h>
#include <memory>
#include <list>

class Device;

namespace CPCommand
{
    class Command
    {
    public:
        Command(bool mb = true, bool eb = true)
            : m_mb(mb),  m_eb(eb) {}

        virtual ~Command() {}

        virtual unsigned GetSize() const = 0;
        virtual void Serialize(void **buff) const = 0;
        virtual Command *Clone() const = 0;

        bool m_mb;
        bool m_eb;
    };


    class Nop : public Command
    {
    public:
        Nop(bool mb = true, bool eb = true) : Command(mb, eb) {};

        virtual unsigned GetSize() const = 0;
        virtual void Serialize(void **buff) const = 0;
        virtual Command *Clone() const = 0;
    };

    class Stop : public Command
    {
    public:
        Stop() : Command() {};

        virtual unsigned GetSize() const = 0;
        virtual void Serialize(void **buff) const = 0;
        virtual Command *Clone() const = 0;
    };

    class WReg32 : public Command
    {
    public:
        uint16_t m_offset;
        uint32_t m_value;
        uint8_t m_pred;

        WReg32(uint16_t offset, uint32_t value, bool mb = true, bool eb = true) :
            Command(mb, eb), m_offset(offset), m_value(value), m_pred(0) {};
        WReg32() : WReg32(0, 0) {};

        virtual unsigned GetSize() const = 0;
        virtual void Serialize(void **buff) const = 0;
        virtual Command *Clone() const = 0;
    };

    class WRegBulk : public Command
    {
    public:
        uint16_t m_offset;
        uint64_t *m_values;
        uint8_t m_pred;
        unsigned m_numValues;

        WRegBulk() : Command(), m_offset(0), m_values(0), m_pred(0), m_numValues(0), m_freeValues(0) {};

        WRegBulk(uint16_t offset, uint64_t* values, unsigned numValues) :
            Command(), m_offset(offset), m_pred(0), m_numValues(numValues), m_freeValues(1)
        {
            m_values = (uint64_t*)malloc(m_numValues * sizeof(uint64_t));
            memcpy(m_values, values, m_numValues * sizeof(uint64_t));
        }

        WRegBulk(uint16_t offset, std::list<uint32_t>::const_iterator &begin, std::list<uint32_t>::const_iterator &end) :
            Command(), m_offset(offset), m_pred(0),m_numValues(0), m_freeValues(1)
        {
            for (auto &it = begin; it != end; it++) { m_numValues++; }
            m_numValues /= 2;
            m_values = (uint64_t*)malloc(m_numValues * sizeof(uint64_t));
            uint32_t *p = (uint32_t*)m_values;
            for (auto &it = begin; it != end; it++) { *(p++) = *it; }
        }

        WRegBulk(uint16_t offset, std::list<uint64_t> &list) :
            Command(), m_offset(offset),m_pred(0), m_numValues(list.size()),  m_freeValues(1)
        {
            m_values = (uint64_t*)malloc(m_numValues * sizeof(uint64_t));
            uint64_t *p = m_values;
            for (auto &it : list) { *(p++) = it; }
        }

        WRegBulk(uint16_t offset, std::list<uint32_t> &list) :
            Command(), m_offset(offset), m_pred(0), m_numValues(list.size() / 2), m_freeValues(1)
        {
            m_values = (uint64_t*)malloc(m_numValues * sizeof(uint64_t));
            uint32_t *p = (uint32_t*)m_values;
            for (auto &it : list) { *(p++) = it; }
        }

        WRegBulk(const WRegBulk &other) :
            Command(other.m_mb, other.m_eb), m_offset(other.m_offset),
            m_pred(other.m_pred),m_numValues(other.m_numValues),  m_freeValues(1)
        {
            m_values = (uint64_t*)malloc(m_numValues * sizeof(uint64_t));
            memcpy(m_values, other.m_values, m_numValues * sizeof(uint64_t));
        }

        virtual ~WRegBulk()
        {
            if (m_freeValues) free(m_values);
        }

        virtual unsigned GetSize() const = 0;
        virtual void Serialize(void **buff) const = 0;
        virtual Command *Clone() const = 0;

    private:
        bool m_freeValues;
    };

    class MsgLong : public Command
    {
    public:
        uint64_t m_addr;
        uint32_t m_value;
        uint8_t m_pred;
        unsigned m_op;
        bool m_noSnoop;
        bool m_weaklyOrdered;


        MsgLong(uint64_t addr, uint32_t value, bool mb = true, bool eb = true) :
            Command(mb, eb), m_addr(addr), m_value(value), m_pred(0),
            m_op(0), m_noSnoop(0), m_weaklyOrdered(0) {}

        MsgLong() : MsgLong(0, 0) {}

        virtual unsigned GetSize() const = 0;
        virtual void Serialize(void **buff) const = 0;
        virtual Command *Clone() const = 0;
    };

    class MsgShort : public Command
    {
    public:
        uint16_t m_offset;
        uint32_t m_value;
        unsigned m_op;
        bool m_noSnoop;
        bool m_weaklyOrdered;
        unsigned m_base;


        MsgShort(unsigned base, uint16_t offset, uint32_t value) :
            Command(),m_offset(offset), m_value(value), m_op(0), m_noSnoop(0),
            m_weaklyOrdered(0), m_base(base)  {}

        MsgShort() : MsgShort(0, 0, 0) {}

        virtual unsigned GetSize() const = 0;
        virtual void Serialize(void **buff) const = 0;
        virtual Command *Clone() const = 0;
    };

    class MsgProt : public Command
    {
    public:
        uint64_t m_addr;
        uint32_t m_value;
        uint8_t m_pred;
        unsigned m_op;
        bool m_noSnoop;
        bool m_weaklyOrdered;

        MsgProt(uint64_t addr, uint32_t value, bool mb = true, bool eb = true) :
            Command(mb, eb), m_addr(addr), m_value(value), m_pred(0),
            m_op(0), m_noSnoop(0), m_weaklyOrdered(0) {}

        MsgProt() : MsgProt(0, 0) {}

        virtual unsigned GetSize() const = 0;
        virtual void Serialize(void **buff) const = 0;
        virtual Command *Clone() const = 0;
    };

    class Fence : public Command
    {
    public:
        unsigned m_decVal;
        uint8_t m_targetVal;
        unsigned m_id;
        uint8_t m_pred;

        Fence(unsigned id, uint8_t targetVal, unsigned decVal, bool mb = true, bool eb = true)
            : Command(mb, eb), m_decVal(decVal), m_targetVal(targetVal), m_id(id), m_pred(0) {}

        Fence() : Fence(0, 0, 0) {}

        virtual unsigned GetSize() const = 0;
        virtual void Serialize(void **buff) const = 0;
        virtual Command *Clone() const = 0;
    };

    class LinDma : public Command
    {
    public:
        uint32_t m_tsize;
        bool m_wrComp;
        bool m_transpose;
        bool m_dtype;
        bool m_linear;
        bool m_memset;
        bool m_compress;
        bool m_decompress;
        uint16_t m_ctxId;
        uint64_t m_src;
        uint64_t m_dst;
        unsigned m_dmaDir;


        LinDma(uint64_t dst, uint64_t src, uint32_t tsize, unsigned dmaDir, bool wrComp = 0) :
            Command(), m_tsize(tsize), m_wrComp(wrComp), m_transpose(0), m_dtype(0), m_linear(1),
            m_memset(0), m_compress(0), m_decompress(0), m_ctxId(0),
            m_src(src), m_dst(dst), m_dmaDir(dmaDir) {}

        LinDma(const LinDma& other)
        {
            m_tsize = other.m_tsize;
            m_wrComp = other.m_wrComp;
            m_transpose = other.m_transpose;
            m_dtype = other.m_dtype;
            m_linear = other.m_linear;
            m_memset = other.m_memset;
            m_compress = other.m_compress;
            m_decompress = other.m_decompress;
            m_ctxId = other.m_ctxId;
            m_src = other.m_src;
            m_dst = other.m_dst;
            m_dmaDir = other.m_dmaDir;
        }

        LinDma() : LinDma(0, 0, 0, 0) {};

        virtual unsigned GetSize() const = 0;
        virtual void Serialize(void **buff) const = 0;
        virtual Command *Clone() const = 0;
    };

    class Repeat : public Command
    {
    public:
        bool m_sore;
        bool m_o;
        uint16_t m_jumpPtr;
        uint8_t m_pred;

        Repeat(uint16_t jumpPtr = 0) : Command(), m_sore(0), m_o(0), m_jumpPtr(jumpPtr), m_pred(0) {};
        virtual unsigned GetSize() const = 0;
        virtual void Serialize(void **buff) const = 0;
        virtual Command *Clone() const = 0;
    };

    class Wait : public Command
    {
    public:
        uint32_t m_cycles;
        unsigned m_incVal;
        unsigned m_id;

        Wait(uint32_t cycles, unsigned incVal, unsigned id) :
            Command(), m_cycles(cycles), m_incVal(incVal), m_id(id) {};

        Wait() : Wait(0, 0, 0) {};

        virtual unsigned GetSize() const = 0;
        virtual void Serialize(void **buff) const = 0;
        virtual Command *Clone() const = 0;
    };

    class LoadAndExec : public Command
    {
    public:
        uint32_t m_dest;
        bool m_load;
        bool m_exec;
        bool m_eType;
        uint8_t m_pred;
        bool m_pmap;


        LoadAndExec() :
            Command(), m_dest(0), m_load(0), m_exec(0), m_eType(0), m_pred(0), m_pmap(0) {}

        virtual unsigned GetSize() const = 0;
        virtual void Serialize(void **buff) const = 0;
        virtual Command *Clone() const = 0;
    };

    class CpDma : public Command
    {
    public:
        uint32_t m_tSize;
        uint64_t m_src;
        uint8_t m_pred;

        CpDma(uint64_t src, uint32_t size) :
            Command(), m_tSize(size), m_src(src), m_pred(0) {}

        CpDma() : CpDma(0, 0) {}

        virtual unsigned GetSize() const = 0;
        virtual void Serialize(void **buff) const = 0;
        virtual Command *Clone() const = 0;
    };

    class ArbPoint : public Command
    {
    public:
        uint8_t m_prio;
        bool m_release;
        uint8_t m_pred;

        ArbPoint(uint8_t prio) :
            Command(), m_prio(prio), m_release(0), m_pred(0) {}

        ArbPoint() :
            Command(), m_prio(0), m_release(1), m_pred(0) {}

        virtual unsigned GetSize() const = 0;
        virtual void Serialize(void **buff) const = 0;
        virtual Command *Clone() const = 0;
    };

};


class CPProgram
{
public:

    CPProgram(unsigned qid = 0) :  m_qid(qid) {};
    CPProgram(const CPProgram & other) ;

    ~CPProgram();
    CPProgram& operator= (const CPProgram & other);

    unsigned GetQId() const { return m_qid; }
    void SetQId(unsigned qid) { m_qid = qid; }
    const std::list<CPCommand::Command *> * GetCmds() const { return &m_cmds; }

    void AddCommandsFront(const CPCommand::Command &cmd);
    void AddCommandsFront(const CPCommand::Command *cmds, unsigned cmdsNr=1);
    void AddCommandsFront(const std::list<CPCommand::Command *> &cmds);

    void AddCommandsBack(const CPCommand::Command &cmd);
    void AddCommandsBack(const CPCommand::Command *cmds, unsigned cmdsNr = 1);
    void AddCommandsBack(const std::list<CPCommand::Command *> &cmds);

    unsigned GetSize() const;
    void Serialize(void **buff) const;
    void Serialize(void *buff) const;

    void AddTclSeq(Device* device, uint16_t offset, uint32_t* values, unsigned valuesNr, bool front=false);


private:
    std::list<CPCommand::Command *> m_cmds;
    unsigned m_qid;

};
