/* SPDX-License-Identifier: MIT
 *
 * Copyright 2016-2021 HabanaLabs, Ltd.
 * All Rights Reserved.
 *
 */

#pragma once
#include <string>
#include <mutex>
#include <unordered_set>
#include "gc_interface.h"

class KernelDB
{
public:
    typedef void* libHandle;

    static const char* s_libName;

    KernelDB();
    ~KernelDB();

    void init();
    void clear();

    gcapi::GlueCodeReturn_t GetKernelInstantiation(gcapi::HabanaKernelParams_t* params, gcapi::HabanaKernelInstantiation_t* instance);

    bool isKernelExist(const std::string& guid) const;

private:
    mutable std::recursive_mutex    m_mutex;
    std::unordered_set<std::string> m_loadedKernels;
    libHandle                       m_libHandle;
    gcapi::pfnHabanaKernel          m_libEntry;
};

