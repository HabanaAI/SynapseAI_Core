/* SPDX-License-Identifier: MIT
 *
 * Copyright 2016-2021 HabanaLabs, Ltd.
 * All Rights Reserved.
 *
 */

#include <cstring>
#include "node.h"

Node::~Node()
{
    if (m_paramSize > 0)
    {
        delete[] m_params;
        m_params = nullptr;
        m_paramSize = 0;
    }
}

bool Node::Init(std::vector<Tensor*> inputs, std::vector<Tensor*> outputs, const void* params, unsigned paramSize, const char* guid, const char* name)
{
    m_inputs  = inputs;
    m_outputs = outputs;
    if (guid == nullptr) return false;
    m_guid = guid;
    if (paramSize > 0)
    {
        if (params == nullptr)
        {
            return false;
        }
        m_params = new char[paramSize];
        memcpy(m_params, params, paramSize);
        m_paramSize = paramSize;
    }
    if (name != nullptr)
    {
        m_name = name;
    }
    return true;
}

const std::vector<Tensor*>& Node::GetInputs() const
{
    return m_inputs;
}

const std::vector<Tensor*>& Node::GetOutputs() const
{
    return m_outputs;
}
unsigned                    Node::GetParamSize() const
{
    return m_paramSize;
}
const void*                 Node::GetParams() const
{
    return m_params;
}
std::string                 Node::GetGUID() const
{
    return m_guid;
}

std::string                 Node::GetName() const
{
    return m_name;
}