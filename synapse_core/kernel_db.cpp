/* SPDX-License-Identifier: MIT
 *
 * Copyright 2016-2021 HabanaLabs, Ltd.
 * All Rights Reserved.
 *
 */

#include <set>
#include <dlfcn.h>
#include <iostream>
#include "kernel_db.h"
#include "gc_interface.h"
#include "recipe.h"

using namespace gcapi;

const char* KernelDB::s_libName = "libcustom_tpc_perf_lib.so";

KernelDB::KernelDB() : m_libHandle(nullptr), m_libEntry(nullptr)
{
}

KernelDB::~KernelDB()
{
    if (m_libHandle != nullptr)
    {
        dlclose(m_libHandle);
    }
}

void KernelDB::clear()
{
    std::lock_guard<std::recursive_mutex> l(m_mutex);
    if (m_libHandle != nullptr)
    {
        dlclose(m_libHandle);
        m_libHandle = nullptr;
    }
    m_libEntry = nullptr;
    m_loadedKernels.clear();
    m_initalized = false;
}

void KernelDB::init(synDeviceType deviceType)
{
    std::lock_guard<std::recursive_mutex> l(m_mutex);
    if (m_libHandle != nullptr) return;

    m_libHandle = dlopen(s_libName, RTLD_LAZY);
    if (m_libHandle == nullptr) return;

    m_libEntry = (pfnHabanaKernel)dlsym(m_libHandle, KERNEL_QUERY_ENTRY_POINT_NAME);
    if (m_libEntry == nullptr)
    {
        clear();
        return;
    }

    //Cache GUIDs exported by this library

    pfnGetKernelNames nameFunc = (pfnGetKernelNames )dlsym(m_libHandle, KERNEL_NAMES_ENTRY_POINT_NAME);
    if (nameFunc == nullptr) return;

    gcapi::GlueCodeReturn_t ret;
    unsigned kernelCount = 0;
    ret = nameFunc(nullptr, &kernelCount, deviceIdfromDeviceType(deviceType));
    if (ret != gcapi::GLUE_SUCCESS)
    {
        return;
    }
    if (kernelCount == 0) return;

    char** kernelNames;
    kernelNames = new char*[kernelCount];
    for (unsigned kernel = 0; kernel < kernelCount; ++kernel)
    {
        kernelNames[kernel] = new char[gcapi::MAX_NODE_NAME];
    }

    ret = nameFunc(kernelNames, &kernelCount, deviceIdfromDeviceType(deviceType));
    if (ret != gcapi::GLUE_SUCCESS)
    {
        for (unsigned i = 0; i < kernelCount; i++)
        {
            delete[] kernelNames[i];
        }
        delete[] kernelNames;
        return;
    }

    for (unsigned i = 0; i < kernelCount; i++)
    {
        m_loadedKernels.insert(kernelNames[i]);
        delete[] kernelNames[i];
    }
    delete[] kernelNames;
    m_initalized = true;
}

bool KernelDB::isKernelExist(const std::string &guid) const
{
    std::lock_guard<std::recursive_mutex> l(m_mutex);
    return m_loadedKernels.find(guid) != m_loadedKernels.end();
}

GlueCodeReturn_t KernelDB::GetKernelInstantiation(HabanaKernelParams_t* params,
                                                  HabanaKernelInstantiation_t* instance)
{
    if ((params == nullptr) || (instance == nullptr)) return gcapi::GLUE_FAILED;

    std::lock_guard<std::recursive_mutex> l(m_mutex);
    if (m_libEntry == nullptr) return gcapi::GLUE_FAILED;

    std::string kernelName(params->nodeName);
    if (!isKernelExist(kernelName)) return gcapi::GLUE_FAILED;

    return m_libEntry(params, instance);
}
bool KernelDB::initialized() {
  std::lock_guard<std::recursive_mutex> l(m_mutex);
  return m_initalized;
}
