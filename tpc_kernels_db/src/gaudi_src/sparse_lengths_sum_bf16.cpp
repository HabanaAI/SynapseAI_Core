/* SPDX-License-Identifier: MIT
 *
 * Copyright 2016-2021 HabanaLabs, Ltd.
 * All Rights Reserved.
 *
 */
#include "sparse_lengths_sum_bf16.hpp"

extern unsigned char _kernels_gaudi_binary___sparse_lengths_sum_bf16_2D_f32_embed_o_start;
extern unsigned char _kernels_gaudi_binary___sparse_lengths_sum_bf16_2D_f32_embed_o_end;

gcapi::GlueCodeReturn_t SparseLengthsSumBF16::GetKernelName(
        char kernelName [gcapi::MAX_NODE_NAME])
{
    strcpy(kernelName,"sparse_lengths_sum_bf16_2D_embed_f32");
    return gcapi::GLUE_SUCCESS;
}

gcapi::GlueCodeReturn_t SparseLengthsSumBF16::GetGcDefinitions(
            gcapi::HabanaKernelParams_t* params,
            gcapi::HabanaKernelInstantiation_t* kernel)
{
    gcapi::GlueCodeReturn_t retVal;
    /*************************************************************************************
    *   Stage I - validate input
    **************************************************************************************/
    // validate correct amount of input tensors
    if (params->inputTensorNr != 3)
    {
        params->inputTensorNr  = 3;
        return gcapi::GLUE_INCOMPATIBLE_INPUT_COUNT;
    }

    // validate correct amount of output tensors
    if (params->outputTensorNr != 1)
    {
        params->outputTensorNr  = 1;
        return gcapi::GLUE_INCOMPATIBLE_OUTPUT_COUNT;
    }

    // validate tensor dimensions
    if (params->inputTensors[0].geometry.dims  != 2 ||
        params->outputTensors[0].geometry.dims != 2)
    {
        params->inputTensors[0].geometry.dims   = 2;
        params->outputTensors[0].geometry.dims  = 2;
        return gcapi::GLUE_INCOMPATIBLE_INPUT_SIZE;
    }

    // length tensor and index tensor are 1D
    if (params->inputTensors[1].geometry.dims != 1 ||
        params->inputTensors[2].geometry.dims != 1)
    {
        params->inputTensors[1].geometry.dims  = 1;
        params->inputTensors[2].geometry.dims  = 1;
        return gcapi::GLUE_INCOMPATIBLE_INPUT_SIZE;
    }

    // output's dimension 0 size is equal to input's 0 dimension size,
    // minus the embed scale and zero-point size.
    if (params->outputTensors[0].geometry.sizes[0] !=
        (params->inputTensors[0].geometry.sizes[0] -
        (2 * sizeof(float) / sizeof(int8_t))))
    {
        params->outputTensors[0].geometry.sizes[0] =
                (params->inputTensors[0].geometry.sizes[0]
                - (2 * sizeof(float) / sizeof(int8_t)));
        return gcapi::GLUE_INCOMPATIBLE_OUTPUT_SIZE;
    }

    //  output's dimension 1 size is equal to length tensor size
    if (params->outputTensors[0].geometry.sizes[1] !=
        params->inputTensors[2].geometry.sizes[0])
    {
        params->outputTensors[0].geometry.sizes[1] =
                params->inputTensors[2].geometry.sizes[0];
        return gcapi::GLUE_INCOMPATIBLE_OUTPUT_SIZE;
    }

    // validate input data type
    if (params->inputTensors[0].dataType != gcapi::DATA_BF16 ||
        params->inputTensors[1].dataType != gcapi::DATA_I32 ||
        params->inputTensors[2].dataType != gcapi::DATA_I32 ||
        params->outputTensors[0].dataType != gcapi::DATA_F32)
    {
        params->inputTensors[0].dataType = gcapi::DATA_BF16;
        params->inputTensors[1].dataType = gcapi::DATA_I32;
        params->inputTensors[2].dataType = gcapi::DATA_I32;
        params->outputTensors[0].dataType = gcapi::DATA_F32;
        return gcapi::GLUE_INCOMPATIBLE_DATA_TYPE;
    }

    /*************************************************************************************
    *    Stage II -  Define index space geometry. In this example the index space matches
    *    the dimensions of the output tensor
    **************************************************************************************/
    kernel->indexSpaceGeometry.dims = 2;

    unsigned eig = 128;
    unsigned unrollCount = 2;

    // round up to 256 and divide by 256 (int8 vec size).
    unsigned depthIndex = (params->outputTensors[0].geometry.sizes[0] + eig - 1) / eig;
    kernel->indexSpaceGeometry.sizes[0] = depthIndex;
    // round up to 2 and divide by 2 (2 is the unroll count on dim 1).
    unsigned widthIndex =
            (params->outputTensors[0].geometry.sizes[1] + unrollCount - 1) / unrollCount;
    kernel->indexSpaceGeometry.sizes[1] = widthIndex;

    /*************************************************************************************
    *    Stage III -  Define index space mapping
    **************************************************************************************/
    //Stating Access Patterns

    //InputTensor
    kernel->inputTensorAccessPattern[0].allRequired = true;
    //Index tensor
    kernel->inputTensorAccessPattern[1].allRequired = true;
    //length tensor
    kernel->inputTensorAccessPattern[2].dim[0].dim        = 1;
    kernel->inputTensorAccessPattern[2].dim[0].start_a    = 0;
    kernel->inputTensorAccessPattern[2].dim[0].end_a      = unrollCount;
    kernel->inputTensorAccessPattern[2].dim[0].start_b    = 0;
    kernel->inputTensorAccessPattern[2].dim[0].end_b      = unrollCount - 1;
    //we need all elements from length tensor including and before the current lengths being used

    //OutputTensor
    kernel->outputTensorAccessPattern[0].dim[0].dim       = 0;
    kernel->outputTensorAccessPattern[0].dim[0].start_a   = eig;
    kernel->outputTensorAccessPattern[0].dim[0].end_a     = eig;
    kernel->outputTensorAccessPattern[0].dim[0].start_b   = 0;
    kernel->outputTensorAccessPattern[0].dim[0].end_b     = eig - 1;

    kernel->outputTensorAccessPattern[0].dim[1].dim       = 1;
    kernel->outputTensorAccessPattern[0].dim[1].start_a   = unrollCount;
    kernel->outputTensorAccessPattern[0].dim[1].end_a     = unrollCount;
    kernel->outputTensorAccessPattern[0].dim[1].start_b   = 0;
    kernel->outputTensorAccessPattern[0].dim[1].end_b     = unrollCount - 1;

    /*************************************************************************************
    *    Stage IV -  define scalar parameters
    **************************************************************************************/
    kernel->kernel.paramsNr = 0;

    /*************************************************************************************
    *    Stage V -  Load ISA into the descriptor.
    **************************************************************************************/
    unsigned IsaSize = (&_kernels_gaudi_binary___sparse_lengths_sum_bf16_2D_f32_embed_o_end - &_kernels_gaudi_binary___sparse_lengths_sum_bf16_2D_f32_embed_o_start);
    unsigned givenBinarySize = kernel->elfSize;
    kernel->elfSize = IsaSize;

    if (givenBinarySize >= IsaSize)
    {
        // copy binary out
        memcpy (kernel->kernelElf ,
                &_kernels_gaudi_binary___sparse_lengths_sum_bf16_2D_f32_embed_o_start,
                IsaSize);
    }
    else
    {
        retVal = gcapi::GLUE_INSUFICIENT_ELF_BUFFER;
        return retVal;
    }
    return gcapi::GLUE_SUCCESS;
}