/* SPDX-License-Identifier: MIT
 *
 * Copyright 2016-2021 HabanaLabs, Ltd.
 * All Rights Reserved.
 *
 */

#undef NDEBUG
#include <assert.h>
#include "program.h"
#include "device.h"

CPProgram::~CPProgram()
{
    for (CPCommand::Command* cmd : m_cmds)
    {
        delete cmd;
    }
}

CPProgram::CPProgram(const CPProgram& other) { *this = other; };

CPProgram& CPProgram::operator=(const CPProgram& other)
{
    m_qid = other.m_qid;
    m_cmds.clear();
    for (CPCommand::Command* otherCmd : other.m_cmds)
    {
        m_cmds.push_back(otherCmd->Clone());
    }
    return *this;
}
void CPProgram::AddCommandsFront(const CPCommand::Command& cmd) { m_cmds.push_front(cmd.Clone()); }

void CPProgram::AddCommandsFront(const CPCommand::Command* cmds, unsigned cmdsNr)
{
    assert(cmds || !cmdsNr);
    for (unsigned i = cmdsNr; i > 0; i--)
    {
        m_cmds.push_front(cmds[i - 1].Clone());
    }
}

void CPProgram::AddCommandsFront(const std::list<CPCommand::Command*>& cmds)
{
    for (auto it = cmds.rbegin(); it != cmds.rend(); it++)
    {
        m_cmds.push_front((*it)->Clone());
    }
}

void CPProgram::AddCommandsBack(const CPCommand::Command& cmd) { m_cmds.push_back(cmd.Clone()); }

void CPProgram::AddCommandsBack(const CPCommand::Command* cmds, unsigned cmdsNr)
{
    assert(cmds || !cmdsNr);
    for (unsigned i = 0; i < cmdsNr; i++)
    {
        m_cmds.push_back(cmds[i].Clone());
    }
}

void CPProgram::AddCommandsBack(const std::list<CPCommand::Command*>& cmds)
{
    for (auto it = cmds.begin(); it != cmds.end(); it++)
    {
        m_cmds.push_back((*it)->Clone());
    }
}

unsigned CPProgram::GetSize() const
{
    unsigned ret = 0;
    for (CPCommand::Command* cmd : m_cmds)
    {
        ret += cmd->GetSize();
    }
    return ret;
}

void CPProgram::Serialize(void** buff) const
{
    for (auto& cmd : m_cmds)
    {
        cmd->Serialize(buff);
    }
}

void CPProgram::Serialize(void* buff) const
{
    void** junk = &buff;
    Serialize(junk);
}

void CPProgram::AddTclSeq(Device* device, uint16_t offset, uint32_t* values, unsigned valuesNr,
                          bool front)
{
    unsigned i = 0;
    if ((offset % sizeof(uint64_t) != 0) || (valuesNr == 1))
    {
        std::shared_ptr<CPCommand::WReg32> wreg32 =
            device->GetHal()->GenWReg32(offset + (i * sizeof(uint32_t)), // Offset
                                        values[i]);

        if (front)
        {
            m_cmds.push_front(wreg32->Clone());
        }
        else
        {
            m_cmds.push_back(wreg32->Clone());
        }
        i++;
    }

    unsigned bulkNumRegs = (valuesNr - i) & ~1;
    if (bulkNumRegs)
    {
        std::shared_ptr<CPCommand::WRegBulk> bulk =
            device->GetHal()->GenWRegBulk(offset + (i * sizeof(uint32_t)), &values[i], bulkNumRegs);

        if (front)
        {
            m_cmds.push_front(bulk->Clone());
        }
        else
        {
            m_cmds.push_back(bulk->Clone());
        }

        i += bulkNumRegs;
    }

    if (i < valuesNr)
    {
        std::shared_ptr<CPCommand::WReg32> wreg32 =
            device->GetHal()->GenWReg32(offset + (i * sizeof(uint32_t)), // Offset
                                        values[i]);

        if (front)
        {
            m_cmds.push_front(wreg32->Clone());
        }
        else
        {
            m_cmds.push_back(wreg32->Clone());
        }
        i++;
    }

    assert(i == valuesNr);
}
