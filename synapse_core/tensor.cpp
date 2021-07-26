/* SPDX-License-Identifier: MIT
 *
 * Copyright 2016-2021 HabanaLabs, Ltd.
 * All Rights Reserved.
 *
 */

#include <cstring>
#include "tensor.h"

Tensor::Tensor(const char* name)
{
    for (unsigned i = 0; i < Tensor::c_tensorMaxDim; ++i)
    {
        m_sizes[i] = 0;
    }
    if (name != nullptr)
    {
        m_name = name;
    }
}

void Tensor::Init(const unsigned sizes[c_tensorMaxDim])
{
    memcpy(m_sizes, sizes, sizeof(m_sizes));
}

unsigned Tensor::GetSize(unsigned int dim) const
{
    if (dim >= c_tensorMaxDim)
    {
        return 1;
    }
    return m_sizes[dim];
}

Tensor* Tensor::Clone() const
{
    Tensor* t = new Tensor(m_name.c_str());
    t->Init(m_sizes);
    return t;
}