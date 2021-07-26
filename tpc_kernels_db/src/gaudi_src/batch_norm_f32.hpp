/* SPDX-License-Identifier: MIT
 *
 * Copyright 2016-2021 HabanaLabs, Ltd.
 * All Rights Reserved.
 *
 */
#ifndef _BATCH_NORM_F32_HPP
#define _BATCH_NORM_F32_HPP

#include <vector>
#include <cstring>
#include <cmath>
#include "gc_interface.h"

class BatchNormF32
{
public:
    BatchNormF32() {};
    virtual ~BatchNormF32() {};

    virtual gcapi::GlueCodeReturn_t GetGcDefinitions(
                                 gcapi::HabanaKernelParams_t* in_defs,
                                 gcapi::HabanaKernelInstantiation_t* out_defs);

    virtual gcapi::GlueCodeReturn_t GetKernelName(
            char kernelName [gcapi::MAX_NODE_NAME]);

    gcapi::GlueCodeReturn_t  ValidateTensorsDataType(
                                gcapi::Tensor_t* pTensors,
                                int tensorCount,
                                gcapi::TensorDataType_t expected);

    // This struct is common between the TPC kernel writer and the framework
    // layer writer. The programmer who adds a new layer to the framework-backend
    // is responsible to fill the momentum
    // N and N_reciprocal are calculated in glue code
    struct BatchNormParams
    {
        float N;
        float N_reciprocal;
        float momentum;
    };


private:

    BatchNormF32(const BatchNormF32& other) = delete;
    BatchNormF32& operator=(const BatchNormF32& other) = delete;
};

#endif //_BATCH_NORM_F32_HPP
