/* SPDX-License-Identifier: MIT
 *
 * Copyright 2016-2021 HabanaLabs, Ltd.
 * All Rights Reserved.
 *
 */
#ifndef _SOFTMAX_BF16_HPP
#define _SOFTMAX_BF16_HPP

#include <vector>
#include <cstring>
#include "gc_interface.h"



class SoftMaxBF16
{
public:
    SoftMaxBF16() {}
    virtual ~SoftMaxBF16() {}

    virtual gcapi::GlueCodeReturn_t GetGcDefinitions(
                                  gcapi::HabanaKernelParams_t* in_defs,
                                  gcapi::HabanaKernelInstantiation_t* out_defs);

     virtual gcapi::GlueCodeReturn_t GetKernelNameFcd(
             char kernelName [gcapi::MAX_NODE_NAME]);

     virtual gcapi::GlueCodeReturn_t GetKernelNameNonFcd(
             char kernelName [gcapi::MAX_NODE_NAME]);


    // This struct is common between the TPC kernel writer and the framework
    // layer writer. The programmer who adds a new layer to the framework-backend
    // is responsible to fill the structure with valid data.
    struct SoftMaxParam
    {
        int32_t axis;
    };


private:
    SoftMaxBF16(const SoftMaxBF16& other) = delete;
    SoftMaxBF16& operator=(const SoftMaxBF16& other) = delete;
};


#endif


