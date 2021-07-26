/* SPDX-License-Identifier: MIT
 *
 * Copyright 2016-2021 HabanaLabs, Ltd.
 * All Rights Reserved.
 *
 */

#pragma once

#include "program.h"

namespace CPCommand
{
    class NopGen2 : public Nop
    {
    public:
        using Nop::Nop;
        virtual unsigned GetSize() const;
        virtual void Serialize(void **buff) const;
        virtual Command *Clone() const;
    };

    class StopGen2 : public Stop
    {
    public:
        using Stop::Stop;
        virtual unsigned GetSize() const;
        virtual void Serialize(void **buff) const;
        virtual Command *Clone() const;
    };

    class WReg32Gen2 : public WReg32
    {
    public:
        using WReg32::WReg32;
        virtual unsigned GetSize() const;
        virtual void Serialize(void **buff) const;
        virtual Command *Clone() const;
    };

    class WRegBulkGen2 : public WRegBulk
    {
    public:
        using WRegBulk::WRegBulk;
        virtual ~WRegBulkGen2() {}

        virtual unsigned GetSize() const;
        virtual void Serialize(void **buff) const;
        virtual Command *Clone() const;
    };

    class MsgLongGen2 : public MsgLong
    {
    public:
        using MsgLong::MsgLong;
        virtual unsigned GetSize() const;
        virtual void Serialize(void **buff) const;
        virtual Command *Clone() const;
    };

    class MsgShortGen2 : public MsgShort
    {
    public:
        using MsgShort::MsgShort;
        virtual unsigned GetSize() const;
        virtual void Serialize(void **buff) const;
        virtual Command *Clone() const;
    };

    class MsgProtGen2 : public MsgProt
    {
    public:
        using MsgProt::MsgProt;
        virtual unsigned GetSize() const;
        virtual void Serialize(void **buff) const;
        virtual Command *Clone() const;
    };

    class FenceGen2 : public Fence
    {
    public:
        using Fence::Fence;
        virtual unsigned GetSize() const;
        virtual void Serialize(void **buff) const;
        virtual Command *Clone() const;
    };

    class LinDmaGen2 : public LinDma
    {
    public:
        using LinDma::LinDma;
        virtual unsigned GetSize() const;
        virtual void Serialize(void **buff) const;
        virtual Command *Clone() const;
    };

    class RepeatGen2 : public Repeat
    {
    public:
        using Repeat::Repeat;
        virtual unsigned GetSize() const;
        virtual void Serialize(void **buff) const;
        virtual Command *Clone() const;
    };

    class WaitGen2 : public Wait
    {
    public:
        using Wait::Wait;
        virtual unsigned GetSize() const;
        virtual void Serialize(void **buff) const;
        virtual Command *Clone() const;
    };

    class LoadAndExecGen2 : public LoadAndExec
    {
    public:
        using LoadAndExec::LoadAndExec;
        virtual unsigned GetSize() const;
        virtual void Serialize(void **buff) const;
        virtual Command *Clone() const;
    };

    class CpDmaGen2 : public CpDma
    {
    public:
        using CpDma::CpDma;
        virtual unsigned GetSize() const;
        virtual void Serialize(void **buff) const;
        virtual Command *Clone() const;
    };

    class ArbPointGen2 : public ArbPoint
    {
    public:
        using ArbPoint::ArbPoint;
        virtual unsigned GetSize() const;
        virtual void Serialize(void **buff) const;
        virtual Command *Clone() const;
    };
};
