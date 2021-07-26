/* SPDX-License-Identifier: MIT
 *
 * Copyright 2016-2021 HabanaLabs, Ltd.
 * All Rights Reserved.
 *
 */
#ifndef _SPARSE_LENGTHS_SUM_BF16_HPP
#define _SPARSE_LENGTHS_SUM_BF16_HPP

#include <gc_interface.h>
#include <cstring>

class SparseLengthsSumBF16
{
public:
    SparseLengthsSumBF16() {}

    virtual ~SparseLengthsSumBF16() {}

    virtual gcapi::GlueCodeReturn_t GetGcDefinitions(
            gcapi::HabanaKernelParams_t *params,
            gcapi::HabanaKernelInstantiation_t *kernel);

    virtual gcapi::GlueCodeReturn_t GetKernelName(
            char kernelName[gcapi::MAX_NODE_NAME]);

private:
    SparseLengthsSumBF16(const SparseLengthsSumBF16 &other) = delete;
    SparseLengthsSumBF16 &operator=(const SparseLengthsSumBF16 &other) = delete;
};
#endif /* _SPARSE_LENGTHS_SUM_BF16_HPP */
