/* SPDX-License-Identifier: MIT
 *
 * Copyright 2016-2021 HabanaLabs, Ltd.
 * All Rights Reserved.
 *
 */
#ifndef _FILTER_FWD_2D_BF16_HPP
#define _FILTER_FWD_2D_BF16_HPP

#include <vector>
#include <cstring>
#include "spatial_reduction_kernels.hpp"



class FilterFwd2dBF16 : public SpatialReductionKernels
{
public:
    FilterFwd2dBF16() {}
    virtual ~FilterFwd2dBF16() {}

    virtual gcapi::GlueCodeReturn_t GetGcDefinitions(
                                  gcapi::HabanaKernelParams_t* in_defs,
                                  gcapi::HabanaKernelInstantiation_t* out_defs);

     virtual gcapi::GlueCodeReturn_t GetKernelName(
             char kernelName [gcapi::MAX_NODE_NAME]);
private:
    FilterFwd2dBF16(const FilterFwd2dBF16& other) = delete;
    FilterFwd2dBF16& operator=(const FilterFwd2dBF16& other) = delete;
};

#endif

