/* SPDX-License-Identifier: MIT
 *
 * Copyright 2016-2021 HabanaLabs, Ltd.
 * All Rights Reserved.
 *
 */

#pragma once

#include <memory>
#include <vector>
#include "tensor.h"

class Node
{
public:
    Node() : m_params(nullptr), m_paramSize(0) {}
    ~Node();

    bool Init(std::vector<Tensor*> inputs, std::vector<Tensor*> outputs, const void* params, unsigned paramSize, const char* guid, const char* name = nullptr);

    const std::vector<Tensor*>& GetInputs() const;
    const std::vector<Tensor*>& GetOutputs() const;
    unsigned                    GetParamSize() const;
    const void*                 GetParams() const;
    std::string                 GetGUID() const;
    std::string                 GetName() const;
private:
    std::vector<Tensor*> m_inputs;
    std::vector<Tensor*> m_outputs;
    char*                m_params;
    unsigned             m_paramSize;
    std::string          m_guid;
    std::string          m_name;
};
