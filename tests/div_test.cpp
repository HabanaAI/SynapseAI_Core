/* SPDX-License-Identifier: MIT
 *
 * Copyright 2016-2021 HabanaLabs, Ltd.
 * All Rights Reserved.
 *
 */

#include <iostream>
#include "test_infra.h"

void init_input_and_ref(float* a, float* b, float* ref, unsigned size) {
  srand(2021);
  for (unsigned i = 0; i < size; ++i) {
    a[i] = HabanaTest::get_rand_between(-5.f, 5.f);
    b[i] = HabanaTest::get_rand_between(-5.f, 5.f);
    ref[i] = a[i] / b[i];
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

    HabanaTest::TestArguments args = HabanaTest::parseArguments(argc, argv);

    const synDeviceType deviceType = args.deviceType;

    //// Model definition

    synGraphHandle graph;
    status = synGraphCreate(&graph, deviceType);
    if (status != synSuccess)
    {
        std::cout << "Failed to create graph" << std::endl;
        return -1;
    }

    //This test's tensor sizes
    const unsigned dims    = 4U;
    const unsigned inZ     = 1024U;
    const unsigned inW     = 1U;
    const unsigned inH     = 1U;
    const unsigned batch   = 1U;
    unsigned outW          = inW;
    unsigned outH          = inH;
    unsigned inTensorSize[SYN_MAX_TENSOR_DIM]  = {inZ, inW, inH, batch};
    unsigned outTensorSize[SYN_MAX_TENSOR_DIM] = {inZ, outW, outH, batch};
    uint64_t inputSize  = inZ * inW  * inH  * batch * sizeof(float);
    uint64_t outputSize = inZ * outW * outH * batch * sizeof(float);

    //Tensors
    synTensor in_a_tensor, in_b_tensor, out_tensor;
    synTensorDescriptor desc;
    // input
    desc.m_dataType     = syn_type_float;
    desc.m_dims         = dims;
    desc.m_name         = "inputA";
    memset(desc.m_strides, 0, sizeof(desc.m_strides));

    for (unsigned i = 0; i < dims; ++i)
    {
        desc.m_sizes[i]    =  inTensorSize[i];
        desc.m_minSizes[i] = desc.m_sizes[i];
    }

    status = synTensorCreate(&in_a_tensor, &desc, nullptr, 0);
    if (status != synSuccess)
    {
        std::cout << "Failed to create input A tensor" << std::endl;
        return -1;
    }

    desc.m_name         = "inputB";
    status = synTensorCreate(&in_b_tensor, &desc, nullptr, 0);
    if (status != synSuccess)
    {
        std::cout << "Failed to create input B tensor" << std::endl;
        return -1;
    }

    desc.m_name = "output";
    for (unsigned i = 0; i < dims; ++i)
    {
        desc.m_sizes[i]    = outTensorSize[i];
        desc.m_minSizes[i] = desc.m_sizes[i];
    }

    status = synTensorCreate(&out_tensor, &desc, nullptr, 0);
    if (status != synSuccess)
    {
        std::cout << "Failed to create output tensor" << std::endl;
        return -1;
    }

    synTensor inputs[] = {in_a_tensor, in_b_tensor};
    //Create the div kernel operating on the tensors
    status = synNodeCreate(graph, inputs, &out_tensor, 2, 1, nullptr, 0, "customdiv_fwd_f32", "Division", nullptr, nullptr);
    if (status != synSuccess)
    {
        std::cout << "Failed to create node" << std::endl;
        return -1;
    }

    //Compile the graph to get an executable recipe
    synRecipeHandle recipe;
    status = synGraphCompile(&recipe, graph, "my_graph", nullptr);
    if (status != synSuccess)
    {
        std::cout << "Failed to compile graph" << std::endl;
        return -1;
    }

    //// Execution

    synDeviceId devId;
    status = synDeviceAcquireByDeviceType(&devId, deviceType);
    if (status != synSuccess)
    {
        std::cout << "No available Gaudi devices!" << std::endl;
        return -1;
    }

    //Host buffers for input, output and ref
    float* inputa, * inputb, * output, * ref;
    //ref has nothing to do with the device
    ref = new float[inZ * outW * outH * batch];
    //input and output need to be mapped to the device as they are copied from / to
    status = synHostMalloc(devId, inputSize, 0, (void**)&inputa);
    if (status != synSuccess)
    {
        std::cout << "Could not create allocate host memory for input A" << std::endl;
        return -1;
    }
    status = synHostMalloc(devId, inputSize, 0, (void**)&inputb);
    if (status != synSuccess)
    {
        std::cout << "Could not create allocate host memory for input B" << std::endl;
        return -1;
    }
    status = synHostMalloc(devId, outputSize, 0, (void**)&output);
    if (status != synSuccess)
    {
        std::cout << "Could not create allocate host memory for output" << std::endl;
        return -1;
    }
    init_input_and_ref(inputa, inputb, ref, inZ);
    //Set output to 0 so valgrind doesn't complain
    memset(output, 0, outputSize);

    synStreamHandle copyInStream, copyOutStream, computeStream;
    status = synStreamCreate(&copyInStream, devId, STREAM_TYPE_COPY_HOST_TO_DEVICE, 0);
    if (status != synSuccess)
    {
        std::cout << "Could not create stream to copy data to the device" << std::endl;
        return -1;
    }
    status = synStreamCreate(&computeStream, devId, STREAM_TYPE_COMPUTE, 0);
    if (status != synSuccess)
    {
        std::cout << "Could not create compute stream" << std::endl;
        return -1;
    }
    status = synStreamCreate(&copyOutStream, devId, STREAM_TYPE_COPY_DEVICE_TO_HOST, 0);
    if (status != synSuccess)
    {
        std::cout << "Could not create stream to copy data from the device" << std::endl;
        return -1;
    }


    //Device-side buffers for input and output
    uint64_t pDeviceInputA, pDeviceInputB, pDeviceOutput;
    status = synDeviceMalloc(devId, inputSize, 0, 0, &pDeviceInputA);
    if (status != synSuccess)
    {
        std::cout << "Failed to allocate input buffer A in device memory" << std::endl;
        return -1;
    }
    status = synDeviceMalloc(devId, inputSize, 0, 0, &pDeviceInputB);
    if (status != synSuccess)
    {
        std::cout << "Failed to allocate input buffer B in device memory" << std::endl;
        return -1;
    }
    status = synDeviceMalloc(devId, outputSize, 0, 0, &pDeviceOutput);
    if (status != synSuccess)
    {
        std::cout << "Failed to allocate input buffer in device memory" << std::endl;
        return -1;
    }

    //Workspace for all the non-user-managed memory
    uint64_t workspaceSize;
    status = synWorkspaceGetSize(&workspaceSize, recipe);
    if (status != synSuccess)
    {
        std::cout << "Failed to query required workspace size" << std::endl;
        return -1;
    }

    uint64_t pWorkspace = 0;
    if (workspaceSize > 0)
    {
        status = synDeviceMalloc(devId, workspaceSize, 0, 0, &pWorkspace);
        if (status != synSuccess)
        {
            std::cout << "Failed to allocate workspace in device memory" << std::endl;
            return -1;
        }
    }

    //Associate the tensors with the device memory so compute knows where to read from / write to
    synLaunchTensorInfo persistentTensorInfo[3];
    persistentTensorInfo[0].pTensorAddress = pDeviceInputA;
    persistentTensorInfo[0].tensorName     = "inputA"; //Must match the name supplied at tensor creation
    persistentTensorInfo[0].tensorType     = DATA_TENSOR;
    persistentTensorInfo[1].pTensorAddress = pDeviceInputB;
    persistentTensorInfo[1].tensorName     = "inputB"; //Must match the name supplied at tensor creation
    persistentTensorInfo[1].tensorType     = DATA_TENSOR;
    persistentTensorInfo[2].pTensorAddress = pDeviceOutput;
    persistentTensorInfo[2].tensorName     = "output"; //Must match the name supplied at tensor creation
    persistentTensorInfo[2].tensorType     = DATA_TENSOR;

    synEventHandle copyDone, computeDone;
    status = synEventCreate(&copyDone, devId, 0);
    if (status != synSuccess)
    {
        std::cout << "Failed to create event" << std::endl;
        return -1;
    }

    status = synEventCreate(&computeDone, devId, 0);
    if (status != synSuccess)
    {
        std::cout << "Failed to create event" << std::endl;
        return -1;
    }

    //Copy data from host to device
    status = synMemCopyAsync(copyInStream, (uint64_t)inputa, inputSize, pDeviceInputA, HOST_TO_DRAM);
    if (status != synSuccess)
    {
        std::cout << "Failed to copy inputs to device memory" << std::endl;
        return -1;
    }
    status = synMemCopyAsync(copyInStream, (uint64_t)inputb, inputSize, pDeviceInputB, HOST_TO_DRAM);
    if (status != synSuccess)
    {
        std::cout << "Failed to copy inputs to device memory" << std::endl;
        return -1;
    }
    //Associate an event with its completion
    status = synEventRecord(copyDone, copyInStream);
    if (status != synSuccess)
    {
        std::cout << "Failed to record event" << std::endl;
        return -1;
    }

    //Compute waits for the copy to finish
    status = synStreamWaitEvent(computeStream, copyDone, 0);
    if (status != synSuccess)
    {
        std::cout << "Failed to stream wait event" << std::endl;
        return -1;
    }
    //Schedule compute
    status = synLaunch(computeStream, persistentTensorInfo, 3, pWorkspace, recipe);
    if (status != synSuccess)
    {
        std::cout << "Failed to launch graph" << std::endl;
        return -1;
    }
    //Associate an event with its completion
    status = synEventRecord(computeDone, computeStream);
    if (status != synSuccess)
    {
        std::cout << "Failed to record event" << std::endl;
        return -1;
    }

    //Copy waits for compute to finish
    status = synStreamWaitEvent(copyOutStream, computeDone, 0);
    if (status != synSuccess)
    {
        std::cout << "Failed to stream wait event" << std::endl;
        return -1;
    }
    //Copy data from device to host
    status = synMemCopyAsync(copyOutStream, pDeviceOutput, outputSize, (uint64_t)output, DRAM_TO_HOST);
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
    HabanaTest::validate_output(output, ref);

    synRecipeDestroy(recipe);
    synGraphDestroy(graph);

    delete[] ref;
    synHostFree(devId, (void*)inputa, 0);
    synHostFree(devId, (void*)inputb, 0);
    synHostFree(devId, (void*)output, 0);

    synTensorDestroy(in_a_tensor);
    synTensorDestroy(in_b_tensor);
    synTensorDestroy(out_tensor);

    synEventDestroy(copyDone);
    synEventDestroy(computeDone);

    synStreamDestroy(copyInStream);
    synStreamDestroy(copyOutStream);
    synStreamDestroy(computeStream);

    synDeviceFree(devId, pDeviceInputA, 0);
    synDeviceFree(devId, pDeviceInputB, 0);
    synDeviceFree(devId, pDeviceOutput, 0);
    if (workspaceSize > 0)
    {
        synDeviceFree(devId, pWorkspace, 0);
    }

    synDestroy(); //Releases all other resources

    return 0;
}

