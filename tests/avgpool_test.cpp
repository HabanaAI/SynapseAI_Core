/* SPDX-License-Identifier: MIT
 *
 * Copyright 2016-2021 HabanaLabs, Ltd.
 * All Rights Reserved.
 *
 */

#include <iostream>
#include <synapse_api.h>
#include <perf_lib_layer_params.h>

void init_input_and_ref(float* input, float* ref)
{
    //Host-side data and reference
    const float inputData [1][4][4][2] = {{
                         {{0, 1}, {2, 3}, {4, 5}, {6, 7}},
                         {{0, 1}, {2, 3}, {4, 5}, {6, 7}},
                         {{7, 6}, {5, 4}, {3, 2}, {1, 0}},
                         {{7, 6}, {5, 4}, {3, 2}, {1, 0}}}};

    const float outputRef [1][3][3][2] = {{
                         {{1, 2}, {3, 4}, {5, 6}},
                         {{3.5, 3.5}, {3.5, 3.5}, {3.5, 3.5}},
                         {{6, 5}, {4, 3}, {2, 1}}}};

    memcpy(input, inputData, sizeof(inputData));
    memcpy(ref, outputRef, sizeof(outputRef));
}

void validate_output(float* output, float* ref)
{
    bool error = false;
    const float eps = 1e-6;
    float* pOutput = output;
    float* pRef = ref;
    for (unsigned b = 0; b < 1; ++b)
    {
        for (unsigned h = 0; h < 3; ++h)
        {
            for (unsigned w = 0; w < 3; ++w)
            {
                for (unsigned c = 0; c < 2; ++c)
                {
                    if (std::abs(*pOutput - *pRef) > eps)
                    {
                        std::cout << "Error at [" << c << "," << w << "," << h << "," << b << "]: Output:" << *pOutput
                                  << " Ref: " << *pRef << std::endl;
                        error = true;
                    }
                    ++pOutput;
                    ++pRef;
                }
            }
        }
    }
    if (!error)
    {
        std::cout << "Comparison passed successfully" << std::endl;
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

    //// Model definition

    synGraphHandle graph;
    status = synGraphCreate(&graph, synDeviceGaudi);
    if (status != synSuccess)
    {
        std::cout << "Failed to create graph" << std::endl;
        return -1;
    }

    //Average pool kernel scalar params. Found in perf_lib_layer_params.h
    ns_AveragePooling::Params kernel_params;
    kernel_params.pad_w_begin = 0;
    kernel_params.pad_h_end   = 0;
    kernel_params.pad_w_end   = 0;
    kernel_params.pad_h_begin = 0;
    kernel_params.kernel_w    = 2;
    kernel_params.kernel_h    = 2;
    kernel_params.stride_w    = 1;
    kernel_params.stride_h    = 1;
    kernel_params.dilation_w  = 1;
    kernel_params.dilation_h  = 1;
    kernel_params.includePadding = false;
    kernel_params.pooling_convention = POOLING_CONVENTION_FULL;

    //This test's tensor sizes
    const unsigned dims    = 4U;
    const unsigned inZ     = 2U;
    const unsigned inW     = 4U;
    const unsigned inH     = 4U;
    const unsigned batch   = 1U;
    unsigned outW = (inW + 2 * kernel_params.pad_w_begin - (kernel_params.kernel_w - 1) - 1) / kernel_params.stride_w + 1;
    unsigned outH = (inH + 2 * kernel_params.pad_h_begin - (kernel_params.kernel_h - 1) - 1) / kernel_params.stride_h + 1;
    unsigned inTensorSize[SYN_MAX_TENSOR_DIM]  = {inZ, inW, inH, batch};
    unsigned outTensorSize[SYN_MAX_TENSOR_DIM] = {inZ, outW, outH, batch};
    uint64_t inputSize  = inZ * inW  * inH  * batch * sizeof(float);
    uint64_t outputSize = inZ * outW * outH * batch * sizeof(float);

    //Tensors
    synTensor in_tensor, out_tensor;
    synTensorDescriptor desc;
    // input
    desc.m_dataType     = syn_type_float;
    desc.m_dims         = dims;
    desc.m_name         = "input";
    memset(desc.m_strides, 0, sizeof(desc.m_strides));

    for (unsigned i = 0; i < dims; ++i)
    {
        desc.m_sizes[i]   =  inTensorSize[i];
        desc.m_minSizes[i] = desc.m_sizes[i];
    }

    status = synTensorCreate(&in_tensor, &desc, nullptr, 0);
    if (status != synSuccess)
    {
        std::cout << "Failed to create input tensor" << std::endl;
        return -1;
    }

    desc.m_name = "output";
    for (unsigned i = 0; i < dims; ++i)
    {
        desc.m_sizes[i] = outTensorSize[i];
        desc.m_minSizes[i] = desc.m_sizes[i];
    }

    status = synTensorCreate(&out_tensor, &desc, nullptr, 0);
    if (status != synSuccess)
    {
        std::cout << "Failed to create output tensor" << std::endl;
        return -1;
    }

    //Create the average pooling kernel operating on the tensors
    status = synNodeCreate(graph, &in_tensor, &out_tensor, 1, 1, &kernel_params, sizeof(kernel_params), "avg_pool_2d_fwd_f32", "Pooling", nullptr, nullptr);
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
    status = synDeviceAcquireByDeviceType(&devId, synDeviceGaudi);
    if (status != synSuccess)
    {
        std::cout << "No available Gaudi devices!" << std::endl;
        return -1;
    }

    //Host buffers for input, output and ref
    float* input, * output, * ref;
    //ref has nothing to do with the device
    ref = new float[inZ * outW * outH * batch];
    //input and output need to be mapped to the device as they are copied from / to
    status = synHostMalloc(devId, inputSize, 0, (void**)&input);
    if (status != synSuccess)
    {
        std::cout << "Could not create allocate host memory for input" << std::endl;
        return -1;
    }
    status = synHostMalloc(devId, outputSize, 0, (void**)&output);
    if (status != synSuccess)
    {
        std::cout << "Could not create allocate host memory for output" << std::endl;
        return -1;
    }
    init_input_and_ref(input, ref);
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
    uint64_t pDeviceInput, pDeviceOutput;
    status = synDeviceMalloc(devId, inputSize, 0, 0, &pDeviceInput);
    if (status != synSuccess)
    {
        std::cout << "Failed to allocate input buffer in device memory" << std::endl;
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
    synLaunchTensorInfo persistentTensorInfo[2];
    persistentTensorInfo[0].pTensorAddress = pDeviceInput;
    persistentTensorInfo[0].tensorName     = "input"; //Must match the name supplied at tensor creation
    persistentTensorInfo[0].tensorType     = DATA_TENSOR;
    persistentTensorInfo[1].pTensorAddress = pDeviceOutput;
    persistentTensorInfo[1].tensorName     = "output"; //Must match the name supplied at tensor creation
    persistentTensorInfo[1].tensorType     = DATA_TENSOR;

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
    status = synMemCopyAsync(copyInStream, (uint64_t)input, inputSize, pDeviceInput, HOST_TO_DRAM);
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
    status = synLaunch(computeStream, persistentTensorInfo, 2, pWorkspace, recipe);
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
    validate_output(output, ref);

    synRecipeDestroy(recipe);
    synGraphDestroy(graph);

    delete[] ref;
    synHostFree(devId, (void*)input, 0);
    synHostFree(devId, (void*)output, 0);

    synTensorDestroy(in_tensor);
    synTensorDestroy(out_tensor);

    synEventDestroy(copyDone);
    synEventDestroy(computeDone);

    synStreamDestroy(copyInStream);
    synStreamDestroy(copyOutStream);
    synStreamDestroy(computeStream);

    synDeviceFree(devId, pDeviceInput, 0);
    synDeviceFree(devId, pDeviceOutput, 0);
    if (workspaceSize > 0)
    {
        synDeviceFree(devId, pWorkspace, 0);
    }

    synDestroy(); //Releases all other resources

    return 0;
}

