/* SPDX-License-Identifier: MIT
 *
 * Copyright 2016-2021 HabanaLabs, Ltd.
 * All Rights Reserved.
 *
 */
#ifndef _LEAKYRELU_F32_GAUDI_HPP
#define _LEAKYRELU_F32_GAUDI_HPP

#include "gc_interface.h"

class LeakyReluF32Gaudi
{
public:
    LeakyReluF32Gaudi() {}
    virtual ~LeakyReluF32Gaudi() {}

    virtual gcapi::GlueCodeReturn_t GetGcDefinitions(
            gcapi::HabanaKernelParams_t* params,
            gcapi::HabanaKernelInstantiation_t* kernel);

    virtual gcapi::GlueCodeReturn_t GetKernelName(
            char kernelName [gcapi::MAX_NODE_NAME]);

    // This struct is common between the TPC kernel writer and the framework
    // layer writer. The programmer who adds a new layer to the framework-backend
    // is responsible to fill the structure with valid data.
    struct LeakyReluParam
    {
        float alpha;
    };

private:
    LeakyReluF32Gaudi(const LeakyReluF32Gaudi& other) = delete;
    LeakyReluF32Gaudi& operator=(const LeakyReluF32Gaudi& other) = delete;
};


#endif //_LEAKYRELU_F32_GAUDI_HPP
