/* SPDX-License-Identifier: MIT
 *
 * Copyright 2016-2021 HabanaLabs, Ltd.
 * All Rights Reserved.
 *
 */

#include <cstdlib>
#include <iostream>
#include "synapse_api.h"

void random_init_buffer(float* buf, unsigned nElems)
{
    srand(2021);
    for (unsigned i = 0; i < nElems; ++i)
    {
        buf[i] = (float)std::rand();
    }
}

int main(int argc, char* argv[])
{
    synStatus status;

    //Initialization
    status = synInitialize();

    if (status != synSuccess)
    {
        std::cout << "Failed to initialize Synapse!" << std::endl;
        return -1;
    }

    const unsigned bufferSizeElements = 1024;
    const unsigned bufferSizeBytes    = bufferSizeElements * sizeof(float);

    synDeviceId devId;
    status = synDeviceAcquireByDeviceType(&devId, synDeviceGaudi);
    if (status != synSuccess)
    {
        std::cout << "No available Gaudi devices!" << std::endl;
        return -1;
    }

    float* input, * output;

    status = synHostMalloc(devId, bufferSizeBytes, 0, (void**)&input);
    if (status != synSuccess)
    {
        std::cout << "Could not create allocate host memory for input" << std::endl;
        return -1;
    }
    status = synHostMalloc(devId, bufferSizeBytes, 0, (void**)&output);
    if (status != synSuccess)
    {
        std::cout << "Could not create allocate host memory for output" << std::endl;
        return -1;
    }

    random_init_buffer(input, bufferSizeElements);
    //Set output to 0 so valgrind doesn't complain
    memset(output, 0, bufferSizeBytes);

    synStreamHandle copyInStream, copyOutStream;
    status = synStreamCreate(&copyInStream, devId, STREAM_TYPE_COPY_HOST_TO_DEVICE, 0);
    if (status != synSuccess)
    {
        std::cout << "Could not create stream to copy data to the device" << std::endl;
        return -1;
    }
    status = synStreamCreate(&copyOutStream, devId, STREAM_TYPE_COPY_DEVICE_TO_HOST, 0);
    if (status != synSuccess)
    {
        std::cout << "Could not create stream to copy data from the device" << std::endl;
        return -1;
    }


    //Device-side buffer
    uint64_t pDevice;
    status = synDeviceMalloc(devId, bufferSizeBytes, 0, 0, &pDevice);
    if (status != synSuccess)
    {
        std::cout << "Failed to allocate buffer in device memory" << std::endl;
        return -1;
    }

    //Copy data from host to device
    status = synMemCopyAsync(copyInStream, (uint64_t)input, bufferSizeBytes, pDevice, HOST_TO_DRAM);
    if (status != synSuccess)
    {
        std::cout << "Failed to copy inputs to device memory" << std::endl;
        return -1;
    }

    //Copy data from device to host
    status = synMemCopyAsync(copyOutStream, pDevice, bufferSizeBytes, (uint64_t)output, DRAM_TO_HOST);
    if (status != synSuccess)
    {
        std::cout << "Failed to copy outputs from device memory" << std::endl;
        return -1;
    }

    //Wait for everything to finish by blocking on the copy from device to hose
    status = synStreamSynchronize(copyOutStream);
    if (status != synSuccess)
    {
        std::cout << "Failed to wait for copy out stream" << std::endl;
        return -1;
    }

    //Check results
    if (memcmp(input, output, bufferSizeBytes) != 0)
    {
        std::cout << "Buffers don't match" << std::endl;
        return -1;
    }
    else
    {
        std::cout << "Comparison passed successfully" << std::endl;
    }


    synHostFree(devId, (void*)input, 0);
    synHostFree(devId, (void*)output, 0);

    synStreamDestroy(copyInStream);
    synStreamDestroy(copyOutStream);

    synDeviceFree(devId, pDevice, 0);

    synDestroy(); //Releases all other resources

    return 0;
}

