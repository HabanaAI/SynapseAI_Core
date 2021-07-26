/* SPDX-License-Identifier: MIT
 *
 * Copyright 2016-2021 HabanaLabs, Ltd.
 * All Rights Reserved.
 *
 */

#pragma once
#include <stdint.h>
#include <list>
#include "hlthunk.h"
#include "hw_abstraction_layer.h"

class Device
{
public:

    static const unsigned c_streams_num = 4;

    Device(HWAbstractionLayer* pHal) : m_pHal(pHal) {}
    virtual ~Device() {}

    struct QueueWkld
    {
        unsigned qid;
        uint64_t buffer;
        unsigned size;
        unsigned flags;
    };

    typedef uint64_t Handle;

    virtual bool OpenDevice(const char *pciId) = 0;
    virtual void CloseDevice() = 0;
    virtual bool SubmitWklds(
        const std::list<QueueWkld> &setup,
        const std::list<QueueWkld> &wklds,
        bool forceSetup,
        Handle &handle) = 0;
    virtual bool Wait(Handle) = 0;
    virtual bool GetCB(unsigned size, Handle &handle, void *&hostAddr, unsigned &flags) = 0;
    virtual bool ReleaseCB(Handle handle) = 0;

    virtual bool CopyHostDevice(bool toDevice, uint64_t hostPtr, uint64_t devicePtr, uint32_t size) = 0;

    HWAbstractionLayer* GetHal() { return  m_pHal; }

private:
    HWAbstractionLayer* m_pHal;
};