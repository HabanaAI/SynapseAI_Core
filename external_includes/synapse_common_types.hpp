/* SPDX-License-Identifier: MIT
 *
 * Copyright 2016-2021 HabanaLabs, Ltd.
 * All Rights Reserved.
 *
 */

#pragma once

#include <stdint.h>
#include <string.h>
#include <assert.h>
#include <vector>
#include <map>

static const size_t TENSOR_DEFAULT_MIN_SIZE = 0;

struct synTensorDescriptor
{
public:
    synTensorDescriptor() : m_dataType(syn_type_na), m_dims(0), m_ptr(nullptr),m_name(nullptr), m_tensorType(DATA_TENSOR)
    {
        memset(m_sizes, 0, SYN_MAX_TENSOR_DIM * sizeof(unsigned));
        memset(m_strides, 0, SYN_MAX_TENSOR_DIM * sizeof(unsigned));
        memset(m_minSizes, TENSOR_DEFAULT_MIN_SIZE, SYN_MAX_TENSOR_DIM * sizeof(unsigned));
    }

    synTensorDescriptor(synDataType                     dataType,
                        unsigned                        dims,
                        unsigned                        sizes[SYN_MAX_TENSOR_DIM],
                        void*                           ptr,
                        const char*                     name                    = nullptr) :
            m_dataType(dataType), m_dims(dims), m_ptr(ptr), m_name(name), m_tensorType(DATA_TENSOR)
    {
        memcpy(m_sizes, sizes, dims * sizeof(unsigned));
        memset(m_strides, 0, SYN_MAX_TENSOR_DIM * sizeof(unsigned));
        memset(m_minSizes, TENSOR_DEFAULT_MIN_SIZE, SYN_MAX_TENSOR_DIM * sizeof(unsigned));
    }

    synDataType                         m_dataType;
    unsigned                            m_dims;
    unsigned                            m_sizes[SYN_MAX_TENSOR_DIM];  // In dynamic tensors this is the maxSize
    void*                               m_ptr;
    const char*                         m_name;
    unsigned                            m_strides[SYN_MAX_TENSOR_DIM];
    unsigned                            m_minSizes[SYN_MAX_TENSOR_DIM];
    synTensorType                       m_tensorType;
};
