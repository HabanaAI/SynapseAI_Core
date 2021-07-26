/* SPDX-License-Identifier: MIT
 *
 * Copyright 2016-2021 HabanaLabs, Ltd.
 * All Rights Reserved.
 *
 */
#ifndef _RELU6_F32_HPP
#define _RELU6_F32_HPP

#include "gc_interface.h"

class Relu6All
{
public:
    typedef enum _Relu6_mode_t
    {
        fwd_f32,
        bwd_f32,
        fwd_bf16,
        bwd_bf16
    } Relu6_mode_t;

    Relu6All(Relu6_mode_t mode=fwd_f32) {m_mode = mode;}
    virtual ~Relu6All() {}

    virtual gcapi::GlueCodeReturn_t GetGcDefinitions(
            gcapi::HabanaKernelParams_t* params,
            gcapi::HabanaKernelInstantiation_t* kernel);

    virtual gcapi::GlueCodeReturn_t GetKernelName(
            char kernelName [gcapi::MAX_NODE_NAME], Relu6_mode_t mode);

private:
    Relu6_mode_t m_mode;
    Relu6All(const Relu6All& other) = delete;
    Relu6All& operator=(const Relu6All& other) = delete;
};


#endif //_RELU6_F32_HPP
