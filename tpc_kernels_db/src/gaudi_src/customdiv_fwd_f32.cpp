/* SPDX-License-Identifier: MIT
 *
 * Copyright 2016-2021 HabanaLabs, Ltd.
 * All Rights Reserved.
 *
 */
#include <cstring>
#include "customdiv_fwd_f32.hpp"

#define CUSTOM_DIV_START _kernels_gaudi_binary___customdiv_fwd_f32_o_start
#define CUSTOM_DIV_END _kernels_gaudi_binary___customdiv_fwd_f32_o_end

extern unsigned char CUSTOM_DIV_START;
extern unsigned char CUSTOM_DIV_END;

extern unsigned char _kernels_gaudi2_binary___customdiv_fwd_f32_o_start;
extern unsigned char _kernels_gaudi2_binary___customdiv_fwd_f32_o_end;



gcapi::GlueCodeReturn_t CustomdivFwdF32::GetKernelName(
        char kernelName [gcapi::MAX_NODE_NAME])
{
    strcpy(kernelName,"customdiv_fwd_f32");
    return gcapi::GLUE_SUCCESS;
}

gcapi::GlueCodeReturn_t CustomdivFwdF32::GetGcDefinitions(
        gcapi::HabanaKernelParams_t* params,
        gcapi::HabanaKernelInstantiation_t* kernel)
{
    gcapi::GlueCodeReturn_t retVal;
    /*************************************************************************************
    *   Stage I - validate input
    **************************************************************************************/
    //validate correct amount of input tensors
    if (params->inputTensorNr != 2)
    {
        params->inputTensorNr  = 2;
        return gcapi::GLUE_INCOMPATIBLE_INPUT_COUNT;
    }
    //validate correct amount of output tensors
    if (params->outputTensorNr != 1)
    {
        params->outputTensorNr  = 1;
        return gcapi::GLUE_INCOMPATIBLE_OUTPUT_COUNT;
    }

    // validate input and output data type
    if (params->inputTensors[0].dataType != gcapi::DATA_F32 ||
        params->inputTensors[1].dataType != gcapi::DATA_F32 ||
        params->outputTensors[0].dataType != gcapi::DATA_F32)
    {
        params->inputTensors[0].dataType = gcapi::DATA_F32;
        params->inputTensors[1].dataType = gcapi::DATA_F32;
        params->outputTensors[0].dataType = gcapi::DATA_F32;
        return gcapi::GLUE_INCOMPATIBLE_DATA_TYPE;
    }

    // Tensor 0 should be input feature map.
    // The semantics of the input tensors and their order is a convention
    // between TPC kernel writer and the write of the layer at the
    // framework level.
    unsigned int outputSizes[gcapi::MAX_TENSOR_DIM] = {0};

    memcpy(outputSizes, params->inputTensors[0].geometry.sizes, sizeof(outputSizes));

    // verify that output feature map dimension are correct
    if (memcmp(params->outputTensors[0].geometry.sizes, outputSizes,
               params->outputTensors[0].geometry.dims * sizeof(unsigned) ) != 0)
    {
        memcpy(params->outputTensors[0].geometry.sizes, params->inputTensors[0].geometry.sizes, sizeof(outputSizes));
        return gcapi::GLUE_INCOMPATIBLE_OUTPUT_SIZE;
    }

    /*************************************************************************************
    *    Stage II -  Define index space geometry. In this example the index space matches
    *    the dimensions of the output tensor, up to dim 0.
    **************************************************************************************/
    int elementsInVec = 64;

    //round up to elementsInVec and divide by elementsInVec.
    unsigned depthIndex = (outputSizes[0] + (elementsInVec - 1)) / elementsInVec;
    kernel->indexSpaceGeometry.dims = 4;
    kernel->indexSpaceGeometry.sizes[0] = depthIndex;
	//reduce index space due to unroll.
    kernel->indexSpaceGeometry.sizes[1] = outputSizes[1]; 
    kernel->indexSpaceGeometry.sizes[2] = outputSizes[2];
    kernel->indexSpaceGeometry.sizes[3] = outputSizes[3];

    /*************************************************************************************
    *    Stage III -  Define index space mapping
    **************************************************************************************/
    // f_start f(i) = elementsInVec*i + 0;
    // f_end   f(i) = elementsInVec*i + (elementsInVec - 1);
    // Resource 0 (IFM) dim 0
    for (unsigned i = 0; i < params->inputTensorNr; i++)
    {
        kernel->inputTensorAccessPattern[i].dim[0].dim      = 0;
        kernel->inputTensorAccessPattern[i].dim[0].start_a  = elementsInVec;
        kernel->inputTensorAccessPattern[i].dim[0].end_a    = elementsInVec;
        kernel->inputTensorAccessPattern[i].dim[0].start_b  = 0;
        kernel->inputTensorAccessPattern[i].dim[0].end_b    = elementsInVec - 1;

        // f_start f(i) = 1*i + 0;
        // f_end   f(i) = 1*i + 0;
        // Resource 0 (IFM) dim 1-4
        for (int dims = 1; dims < 4; dims++)
        {
            kernel->inputTensorAccessPattern[i].dim[dims].dim      = dims;
            kernel->inputTensorAccessPattern[i].dim[dims].start_a  = 1;
            kernel->inputTensorAccessPattern[i].dim[dims].end_a    = 1;
            kernel->inputTensorAccessPattern[i].dim[dims].start_b  = 0;
            kernel->inputTensorAccessPattern[i].dim[dims].end_b    = 1 - 1;
        }        
    }    

    // f_start f(i) = elementsInVec*i + 0;
    // f_end   f(i) = elementsInVec*i + (elementsInVec - 1);
    // Resource 0 (OFM) dim 0
    kernel->outputTensorAccessPattern[0].dim[0].dim      = 0;
    kernel->outputTensorAccessPattern[0].dim[0].start_a  = elementsInVec;
    kernel->outputTensorAccessPattern[0].dim[0].end_a    = elementsInVec;
    kernel->outputTensorAccessPattern[0].dim[0].start_b  = 0;
    kernel->outputTensorAccessPattern[0].dim[0].end_b    = elementsInVec - 1;
	
    // f_start f(i) = 1*i + 0;
    // f_end   f(i) = 1*i + 0;
    // Resource 0 (OFM) dim 1-4
    for (int dims = 1; dims < 4; dims++)
    {
        kernel->outputTensorAccessPattern[0].dim[dims].dim      = dims;
        kernel->outputTensorAccessPattern[0].dim[dims].start_a  = 1;
        kernel->outputTensorAccessPattern[0].dim[dims].end_a    = 1;
        kernel->outputTensorAccessPattern[0].dim[dims].start_b  = 0;
        kernel->outputTensorAccessPattern[0].dim[dims].end_b    = 1 - 1;
    }


    /*************************************************************************************
    *    Stage IV -  define scalar parameters
    **************************************************************************************/
    kernel->kernel.paramsNr = 0;

    /*************************************************************************************
    *    Stage V -  Load ISA into the descriptor.
    **************************************************************************************/

    unsigned char* pStart = nullptr;
    unsigned char* pEnd = nullptr;

    switch(params->deviceId)
    {
        case gcapi::DEVICE_ID_GAUDI:
        {
            pStart = &CUSTOM_DIV_START;
            pEnd = &CUSTOM_DIV_END;
            break;
        }
        case gcapi::DEVICE_ID_GAUDI2:
        {
            pStart = &_kernels_gaudi2_binary___customdiv_fwd_f32_o_start;
            pEnd = &_kernels_gaudi2_binary___customdiv_fwd_f32_o_end;
            break;            
        }
        default:
            return gcapi::GLUE_FAILED;
    }

    unsigned IsaSize = (pEnd - pStart);
    unsigned givenBinarySize = kernel->elfSize;
    kernel->elfSize = IsaSize;

    if (givenBinarySize >= IsaSize)
    {
        memcpy (kernel->kernelElf, pStart, IsaSize);
    }
    else
    {
        retVal = gcapi::GLUE_INSUFICIENT_ELF_BUFFER;
        return retVal;
    }

    return gcapi::GLUE_SUCCESS;
}


