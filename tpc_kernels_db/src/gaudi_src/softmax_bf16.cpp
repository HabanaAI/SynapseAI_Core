/* SPDX-License-Identifier: MIT
 *
 * Copyright 2016-2021 HabanaLabs, Ltd.
 * All Rights Reserved.
 *
 */
#include "softmax_bf16.hpp"

extern unsigned char _kernels_gaudi_binary___softmax_fcd_bf16_o_start;
extern unsigned char _kernels_gaudi_binary___softmax_fcd_bf16_o_end;
extern unsigned char _kernels_gaudi_binary___softmax_non_fcd_bf16_o_start;
extern unsigned char _kernels_gaudi_binary___softmax_non_fcd_bf16_o_end;

 gcapi::GlueCodeReturn_t SoftMaxBF16::GetKernelNameFcd(
             char kernelName [gcapi::MAX_NODE_NAME])
 {
     strcpy(kernelName,"softmax_fcd_bf16");
     return gcapi::GLUE_SUCCESS;
 }

 gcapi::GlueCodeReturn_t SoftMaxBF16::GetKernelNameNonFcd(
             char kernelName [gcapi::MAX_NODE_NAME])
 {
     strcpy(kernelName,"softmax_non_fcd_bf16");
     return gcapi::GLUE_SUCCESS;
 }

gcapi::GlueCodeReturn_t SoftMaxBF16::GetGcDefinitions(
            gcapi::HabanaKernelParams_t* params,
            gcapi::HabanaKernelInstantiation_t* kernel)
{
    gcapi::GlueCodeReturn_t retVal;
    SoftMaxParam* def = static_cast<SoftMaxParam*>(params->NodeParams);

    /*************************************************************************************
    *   Stage I - validate input
    **************************************************************************************/
    //validate correct amount of input tensors
    if (params->inputTensorNr != 1)
    {
        params->inputTensorNr  = 1;
        return gcapi::GLUE_INCOMPATIBLE_INPUT_COUNT;
    }
    //validate correct amount of output tensors
    if (params->outputTensorNr != 1)
    {
        params->outputTensorNr  = 1;
        return gcapi::GLUE_INCOMPATIBLE_OUTPUT_COUNT;
    }
    // Validate number of dimensions for input and output tensors
    if (params->inputTensors[0].geometry.dims != 2 ||
        params->outputTensors[0].geometry.dims != 2)
    {
        return gcapi::GLUE_INCOMPATIBLE_INPUT_SIZE;
    }

    // validate input data type
    if (params->inputTensors[0].dataType != gcapi::DATA_BF16 ||
        params->outputTensors[0].dataType != gcapi::DATA_BF16)
    {
        params->inputTensors[0].dataType = gcapi::DATA_BF16;
        params->outputTensors[0].dataType = gcapi::DATA_BF16;
        return gcapi::GLUE_INCOMPATIBLE_DATA_TYPE;
    }

    // Tensor 0 should be input feature map.
    // The semantics of the input tensors and their order is a convention
    // between TPC kernel writer and the write of the layer at the
    // framework level.
    unsigned int outputSizes[gcapi::MAX_TENSOR_DIM] = {0};

    std::copy(params->inputTensors[0].geometry.sizes,
              params->inputTensors[0].geometry.sizes + gcapi::MAX_TENSOR_DIM,
            outputSizes);

    unsigned * inputSizes = params->inputTensors[0].geometry.sizes;

    // verify that output feature map dimension are correct
    if (memcmp(params->outputTensors[0].geometry.sizes,inputSizes,
               params->outputTensors[0].geometry.dims * sizeof(unsigned) ) != 0)
    {
        memcpy(params->outputTensors[0].geometry.sizes,inputSizes,sizeof(outputSizes));
        return gcapi::GLUE_INCOMPATIBLE_OUTPUT_SIZE;
    }
    /*************************************************************************************
    *    Stage II -  Define index space geometry. In this example the index space matches
    *    the dimensions of the output tensor, up to dim 0.
    **************************************************************************************/
    kernel->indexSpaceGeometry.dims = 4;
    //round up to 128 and divide by 128.
    unsigned depthIndex = (outputSizes[0] + 127) / 128 * 128;
    kernel->indexSpaceGeometry.sizes[0] = outputSizes[0];
    kernel->indexSpaceGeometry.sizes[1] = outputSizes[1];
    kernel->indexSpaceGeometry.sizes[2] = 1;
    kernel->indexSpaceGeometry.sizes[3] = 1;

    // Single index space along axis of softmax calculation
    // Single index space is used when there is data dependency among index spaces
    kernel->indexSpaceGeometry.sizes[def->axis] = 1;

    /*************************************************************************************
    *    Stage III -  Define index space mapping
    **************************************************************************************/

    // Index space mapping is calculated using f(i) = Ai + B
    // 'i' is the index space member and A/B constants to be defined.
    if (def->axis == 0)
    {

        // f_start(i) = 0;
        // f_end f(i) = size[0] - 1;
        // Resource 0 (IFM) dim 0 (depth)
        // Access is given to all the elements since single indexspace is used
        kernel->inputTensorAccessPattern[0].dim[0].dim        = 0;
        kernel->inputTensorAccessPattern[0].dim[0].start_a    = 0;
        kernel->inputTensorAccessPattern[0].dim[0].end_a      = 0;
        kernel->inputTensorAccessPattern[0].dim[0].start_b    = 0;
        kernel->inputTensorAccessPattern[0].dim[0].end_b      = depthIndex - 1;

        // f_start(i) = 1*i + 0;
        // f_end f(i) = 1*i + 0;
        // Resource 0 (IFM) dim 1 (width)
        kernel->inputTensorAccessPattern[0].dim[1].dim        = 1;
        kernel->inputTensorAccessPattern[0].dim[1].start_a    = 1;
        kernel->inputTensorAccessPattern[0].dim[1].end_a      = 1;
        kernel->inputTensorAccessPattern[0].dim[1].start_b    = 0;
        kernel->inputTensorAccessPattern[0].dim[1].end_b      = 1 - 1;

        // f_start(i) = 0;
        // f_end f(i) = size[0] - 1;
        // Resource 0 (OFM) dim 0 (depth)
        // Access is given to all the elements since single indexspace is used
        kernel->outputTensorAccessPattern[0].dim[0].dim        = 0;
        kernel->outputTensorAccessPattern[0].dim[0].start_a    = 0;
        kernel->outputTensorAccessPattern[0].dim[0].end_a      = 0;
        kernel->outputTensorAccessPattern[0].dim[0].start_b    = 0;
        kernel->outputTensorAccessPattern[0].dim[0].end_b      = depthIndex - 1;

        // f_start(i) = 1*i + 0;
        // f_end f(i) = 1*i + 0;
        // Resource 0 (OFM) dim 1 (width)
        kernel->outputTensorAccessPattern[0].dim[1].dim        = 1;
        kernel->outputTensorAccessPattern[0].dim[1].start_a    = 1;
        kernel->outputTensorAccessPattern[0].dim[1].end_a      = 1;
        kernel->outputTensorAccessPattern[0].dim[1].start_b    = 0;
        kernel->outputTensorAccessPattern[0].dim[1].end_b      = 1 - 1;
    }
    else
    {
        // f_start(i) = 128*i + 0;
        // f_end f(i) = 128*i + 127;
        // Resource 0 (IFM) dim 0 (depth)
        kernel->inputTensorAccessPattern[0].dim[0].dim        = 0;
        kernel->inputTensorAccessPattern[0].dim[0].start_a    = 128;
        kernel->inputTensorAccessPattern[0].dim[0].end_a      = 128;
        kernel->inputTensorAccessPattern[0].dim[0].start_b    = 0;
        kernel->inputTensorAccessPattern[0].dim[0].end_b      = 127;

        // f_start(i) = 0;
        // f_end f(i) = size[1] - 1;
        // Resource 0 (IFM) dim 1 (width)
        // Access is given to all the elements since single indexspace is used
        kernel->inputTensorAccessPattern[0].dim[1].dim        = 1;
        kernel->inputTensorAccessPattern[0].dim[1].start_a    = 0;
        kernel->inputTensorAccessPattern[0].dim[1].end_a      = 0;
        kernel->inputTensorAccessPattern[0].dim[1].start_b    = 0;
        kernel->inputTensorAccessPattern[0].dim[1].end_b      = outputSizes[1] - 1;

        // f_start(i) = 128*i + 0;
        // f_end f(i) = 128*i + 127;
        // Resource 0 (OFM) dim 0 (depth)
        kernel->outputTensorAccessPattern[0].dim[0].dim        = 0;
        kernel->outputTensorAccessPattern[0].dim[0].start_a    = 128;
        kernel->outputTensorAccessPattern[0].dim[0].end_a      = 128;
        kernel->outputTensorAccessPattern[0].dim[0].start_b    = 0;
        kernel->outputTensorAccessPattern[0].dim[0].end_b      = 127;

        // f_start(i) = 0;
        // f_end f(i) = size[1] - 1;
        // Resource 0 (OFM) dim 1 (width)
        kernel->outputTensorAccessPattern[0].dim[1].dim        = 1;
        kernel->outputTensorAccessPattern[0].dim[1].start_a    = 0;
        kernel->outputTensorAccessPattern[0].dim[1].end_a      = 0;
        kernel->outputTensorAccessPattern[0].dim[1].start_b    = 0;
        kernel->outputTensorAccessPattern[0].dim[1].end_b      = outputSizes[1] - 1;
    }

    /*************************************************************************************
    *    Stage IV -  Set Auxiliary Tensor
    **************************************************************************************/
 
    /*************************************************************************************
    *    Stage V -  Load ISA into the descriptor.
    **************************************************************************************/
    unsigned IsaSize1 = (&_kernels_gaudi_binary___softmax_fcd_bf16_o_end - &_kernels_gaudi_binary___softmax_fcd_bf16_o_start);
    unsigned IsaSize2 = (&_kernels_gaudi_binary___softmax_non_fcd_bf16_o_end - &_kernels_gaudi_binary___softmax_non_fcd_bf16_o_start);
    unsigned givenBinarySize = kernel->elfSize;
    unsigned IsaSize = def->axis==0? IsaSize1:IsaSize2;

    kernel->elfSize = IsaSize;

    if (givenBinarySize >= IsaSize)
    {
        if(def->axis == 0)
        {
            // copy binary out
            memcpy (kernel->kernelElf ,
                    &_kernels_gaudi_binary___softmax_fcd_bf16_o_start,
                    IsaSize);
        }
        else
        {
            // copy binary out
            memcpy (kernel->kernelElf ,
                    &_kernels_gaudi_binary___softmax_non_fcd_bf16_o_start,
                    IsaSize);
        }
    }
    else
    {
       retVal = gcapi::GLUE_INSUFICIENT_ELF_BUFFER;
       return retVal;
    }

    return gcapi::GLUE_SUCCESS;
}


