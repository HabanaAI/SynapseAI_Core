/* SPDX-License-Identifier: MIT
 *
 * Copyright 2016-2021 HabanaLabs, Ltd.
 * All Rights Reserved.
 *
 */
#ifndef _CAST_GAUDI_HPP
#define _CAST_GAUDI_HPP

#include <vector>
#include <cstring>
#include "gc_interface.h"

class CastGaudi
{
public:
    // List of supported casting types
    typedef enum _CastBF16DataType_t
    {
        bf16_to_f32,
        f32_to_bf16
    } CastDataType_t;

    char castDataType[2][15] = {"bf16_to_f32", "f32_to_bf16"};
    CastGaudi(CastDataType_t mode = bf16_to_f32)
    {
        m_mode = mode;
    }

    virtual ~CastGaudi() {}

    virtual gcapi::GlueCodeReturn_t GetGcDefinitions(
                                 gcapi::HabanaKernelParams_t* in_defs,
                                 gcapi::HabanaKernelInstantiation_t* out_defs);

    virtual gcapi::GlueCodeReturn_t GetKernelName(
            char kernelName [gcapi::MAX_NODE_NAME],
            CastDataType_t mode);

    // This struct is common between the TPC kernel writer and the framework
    // layer writer. The programmer who adds a new layer to the framework-backend
    // is responsible to fill the structure with valid dat
    struct CastParams
    {
        float scale;
    };

private:

    CastDataType_t m_mode;
    CastGaudi(const CastGaudi& other) = delete;
    CastGaudi& operator=(const CastGaudi& other) = delete;
};

#endif


