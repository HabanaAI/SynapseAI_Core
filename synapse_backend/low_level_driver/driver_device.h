/* SPDX-License-Identifier: MIT
 *
 * Copyright 2016-2021 HabanaLabs, Ltd.
 * All Rights Reserved.
 *
 */

#pragma once
#include "device.h"
#include <map>

#ifndef WIN32
class DriverDevice : public Device
{
  public:
    DriverDevice(HWAbstractionLayer* pHal);
    virtual ~DriverDevice();

    bool OpenDevice(const char* pciId, const hlthunk_device_name deviceName);
    void CloseDevice();
    bool SubmitWklds(const std::list<QueueWkld>& setup, const std::list<QueueWkld>& wklds,
                     bool forceSetup, Handle& handle);
    bool Wait(Handle handle);
    bool GetCB(unsigned size, Handle& handle, void*& hostAddr, unsigned& flags);
    bool ReleaseCB(Handle handle);
    bool MapHostMemory(Handle hostAddr, unsigned size, uint64_t& virtualAddr, uint64_t hintAddr = 0);
    bool UnmapMemory(uint64_t addr);
    uint64_t dramMemoryAllocAndMap();
    bool dramMemoryFree();
    virtual bool CopyHostDevice(bool toDevice, uint64_t hostPtr, uint64_t devicePtr, uint32_t size);

    bool GetHwIpInfo(hlthunk_hw_ip_info& hwInfo);
    bool GetSmInfo();
    bool IsDramEnabled();
    bool IsMmuEnabled();

    hlthunk_device_name GetDeviceName();

  private:
    struct VirtMem
    {
        uint64_t addrVirt;
        void*    addr;
        unsigned size;
        unsigned cbSize;
        bool     isUserCb;
    };

    std::map<Handle, VirtMem> m_cbHandles;
    int                       m_fd;
    uint64_t m_dramVirtAddr;
    uint64_t m_dramHandle;
    uint64_t c_dram_phys_size = 0;

    DriverDevice(const DriverDevice& other) = delete;
    DriverDevice& operator=(const DriverDevice& other) = delete;
};
#endif
