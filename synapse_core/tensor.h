/* SPDX-License-Identifier: MIT
 *
 * Copyright 2016-2021 HabanaLabs, Ltd.
 * All Rights Reserved.
 *
 */

#pragma once

#include <memory>

class Tensor
{
public:
    static const unsigned c_tensorMaxDim = 5;

    Tensor(const char* name = nullptr);
    ~Tensor() {}

    std::string GetName() const { return m_name; }
    unsigned    GetSize(unsigned int dim) const;
    void        Init(const unsigned sizes[c_tensorMaxDim]);
    Tensor*     Clone() const;
private:
    unsigned    m_sizes[c_tensorMaxDim];
    std::string m_name;
};
