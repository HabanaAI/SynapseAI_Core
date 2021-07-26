/* SPDX-License-Identifier: MIT
 *
 * Copyright 2016-2021 HabanaLabs, Ltd.
 * All Rights Reserved.
 *
 */
#ifndef _CUSTOMDIV_FWD_F32_HPP
#define _CUSTOMDIV_FWD_F32_HPP

#include "gc_interface.h"

class CustomdivFwdF32
{
public:
    CustomdivFwdF32() {}
    virtual ~CustomdivFwdF32() {}

    virtual gcapi::GlueCodeReturn_t GetGcDefinitions(
            gcapi::HabanaKernelParams_t* params,
            gcapi::HabanaKernelInstantiation_t* kernel);

    virtual gcapi::GlueCodeReturn_t GetKernelName(
            char kernelName [gcapi::MAX_NODE_NAME]);

private:
    CustomdivFwdF32(const CustomdivFwdF32& other) = delete;
    CustomdivFwdF32& operator=(const CustomdivFwdF32& other) = delete;
};


#endif //_CUSTOMDIV_FWD_F32_HPP
