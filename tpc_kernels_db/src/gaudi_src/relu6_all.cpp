/* SPDX-License-Identifier: MIT
 *
 * Copyright 2016-2021 HabanaLabs, Ltd.
 * All Rights Reserved.
 *
 */
#include <cstring>
#include "relu6_all.hpp"

extern unsigned char _kernels_gaudi_binary___relu6_fwd_f32_o_start;
extern unsigned char _kernels_gaudi_binary___relu6_fwd_f32_o_end;
extern unsigned char _kernels_gaudi_binary___relu6_bwd_f32_o_start;
extern unsigned char _kernels_gaudi_binary___relu6_bwd_f32_o_end;
extern unsigned char _kernels_gaudi_binary___relu6_fwd_bf16_o_start;
extern unsigned char _kernels_gaudi_binary___relu6_fwd_bf16_o_end;
extern unsigned char _kernels_gaudi_binary___relu6_bwd_bf16_o_start;
extern unsigned char _kernels_gaudi_binary___relu6_bwd_bf16_o_end;

gcapi::GlueCodeReturn_t Relu6All::GetKernelName(
        char kernelName [gcapi::MAX_NODE_NAME], Relu6_mode_t mode)
{
    if(mode == fwd_f32)
        strcpy(kernelName,"customrelu6_fwd_f32");
    else if(mode == bwd_f32)
        strcpy(kernelName,"customrelu6_bwd_f32");
    else if(mode == fwd_bf16)
        strcpy(kernelName,"customrelu6_fwd_bf16");
    else if(mode == bwd_bf16)
        strcpy(kernelName,"customrelu6_bwd_bf16");
    else
        return gcapi::GLUE_NODE_NOT_FOUND;
    return gcapi::GLUE_SUCCESS;
}

gcapi::GlueCodeReturn_t Relu6All::GetGcDefinitions(
        gcapi::HabanaKernelParams_t* in_defs,
        gcapi::HabanaKernelInstantiation_t* out_defs)
{
	const int c_unrollCount = 4;
    gcapi::GlueCodeReturn_t retVal;
    /*************************************************************************************
    *   Stage I - validate input
    **************************************************************************************/
    //validate correct amount of input tensors
    if(m_mode == fwd_f32 || m_mode == fwd_bf16)
    {
        if (in_defs->inputTensorNr != 1)
        {
            in_defs->inputTensorNr  = 1;
            return gcapi::GLUE_INCOMPATIBLE_INPUT_COUNT;
        }
    }
    else{
        if (in_defs->inputTensorNr != 2)
        {
            in_defs->inputTensorNr  = 2;
            return gcapi::GLUE_INCOMPATIBLE_INPUT_COUNT;
        }

    }
    //validate correct amount of output tensors
    if (in_defs->outputTensorNr != 1)
    {
        in_defs->outputTensorNr  = 1;
        return gcapi::GLUE_INCOMPATIBLE_OUTPUT_COUNT;
    }

    // validate input and output data type
    if(m_mode == fwd_f32 || m_mode == bwd_f32)
    {
        if (in_defs->inputTensors[0].dataType != gcapi::DATA_F32 ||
            in_defs->outputTensors[0].dataType != gcapi::DATA_F32)
        {
            in_defs->inputTensors[0].dataType = gcapi::DATA_F32;
            in_defs->outputTensors[0].dataType = gcapi::DATA_F32;
            return gcapi::GLUE_INCOMPATIBLE_DATA_TYPE;
        }
    }
    else{
        if (in_defs->inputTensors[0].dataType != gcapi::DATA_BF16 ||
            in_defs->outputTensors[0].dataType != gcapi::DATA_BF16)
        {
            in_defs->inputTensors[0].dataType = gcapi::DATA_BF16;
            in_defs->outputTensors[0].dataType = gcapi::DATA_BF16;
            return gcapi::GLUE_INCOMPATIBLE_DATA_TYPE;
        }
    }
    // Tensor 0 should be input feature map.
    // The semantics of the input tensors and their order is a convention
    // between TPC kernel writer and the write of the layer at the
    // framework level.
    unsigned int outputSizes[gcapi::MAX_TENSOR_DIM] = {0};

    memcpy(outputSizes, in_defs->inputTensors[0].geometry.sizes, sizeof(outputSizes));

    // verify that output feature map dimension are correct
    if (memcmp(in_defs->outputTensors[0].geometry.sizes, outputSizes,
               in_defs->outputTensors[0].geometry.dims * sizeof(unsigned) ) != 0)
    {
        memcpy(in_defs->outputTensors[0].geometry.sizes, in_defs->inputTensors[0].geometry.sizes, sizeof(outputSizes));
        return gcapi::GLUE_INCOMPATIBLE_OUTPUT_SIZE;
    }

    /*************************************************************************************
    *    Stage II -  Define index space geometry. In this example the index space matches
    *    the dimensions of the output tensor, up to dim 0.
    **************************************************************************************/
    int elementsInVec;
    if(m_mode == fwd_f32 || m_mode == bwd_f32)
        elementsInVec = 64;
    else
        elementsInVec = 128;

    //round up to elementsInVec and divide by elementsInVec.
    unsigned depthIndex = (outputSizes[0] + (elementsInVec - 1)) / elementsInVec;
    out_defs->indexSpaceGeometry.dims = 4;
    out_defs->indexSpaceGeometry.sizes[0] = depthIndex;
	//reduce index space due to unroll.
    out_defs->indexSpaceGeometry.sizes[1] = (outputSizes[1] +(c_unrollCount-1)) / c_unrollCount; 
    out_defs->indexSpaceGeometry.sizes[2] = outputSizes[2];
    out_defs->indexSpaceGeometry.sizes[3] = outputSizes[3];

    /*************************************************************************************
    *    Stage III -  Define index space mapping
    **************************************************************************************/
    // f_start f(i) = elementsInVec*i + 0;
    // f_end   f(i) = elementsInVec*i + (elementsInVec - 1);
    // Resource 0 (IFM) dim 0
    out_defs->inputTensorAccessPattern[0].allRequired = true;
    out_defs->inputTensorAccessPattern[0].dim[0].dim      = 0;
    out_defs->inputTensorAccessPattern[0].dim[0].start_a  = elementsInVec;
    out_defs->inputTensorAccessPattern[0].dim[0].end_a    = elementsInVec;
    out_defs->inputTensorAccessPattern[0].dim[0].start_b  = 0;
    out_defs->inputTensorAccessPattern[0].dim[0].end_b    = elementsInVec - 1;

	out_defs->inputTensorAccessPattern[0].dim[1].dim      = 1;
    out_defs->inputTensorAccessPattern[0].dim[1].start_a  = c_unrollCount;
    out_defs->inputTensorAccessPattern[0].dim[1].end_a    = c_unrollCount;
    out_defs->inputTensorAccessPattern[0].dim[1].start_b  = 0;
    out_defs->inputTensorAccessPattern[0].dim[1].end_b    = c_unrollCount - 1;
	
    // f_start f(i) = 1*i + 0;
    // f_end   f(i) = 1*i + 0;
    // Resource 0 (IFM) dim 1-4
    for (int dims = 2; dims < 4; dims++)
    {
        out_defs->inputTensorAccessPattern[0].dim[dims].dim      = dims;
        out_defs->inputTensorAccessPattern[0].dim[dims].start_a  = 1;
        out_defs->inputTensorAccessPattern[0].dim[dims].end_a    = 1;
        out_defs->inputTensorAccessPattern[0].dim[dims].start_b  = 0;
        out_defs->inputTensorAccessPattern[0].dim[dims].end_b    = 1 - 1;
    }

    //out_defs->inputTensorAccessPattern[1].allRequired = true;
    out_defs->inputTensorAccessPattern[1].dim[0].dim      = 0;
    out_defs->inputTensorAccessPattern[1].dim[0].start_a  = elementsInVec;
    out_defs->inputTensorAccessPattern[1].dim[0].end_a    = elementsInVec;
    out_defs->inputTensorAccessPattern[1].dim[0].start_b  = 0;
    out_defs->inputTensorAccessPattern[1].dim[0].end_b    = elementsInVec - 1;

	out_defs->inputTensorAccessPattern[1].dim[1].dim      = 1;
    out_defs->inputTensorAccessPattern[1].dim[1].start_a  = c_unrollCount;
    out_defs->inputTensorAccessPattern[1].dim[1].end_a    = c_unrollCount;
    out_defs->inputTensorAccessPattern[1].dim[1].start_b  = 0;
    out_defs->inputTensorAccessPattern[1].dim[1].end_b    = c_unrollCount - 1;
	
    // f_start f(i) = 1*i + 0;
    // f_end   f(i) = 1*i + 0;
    // Resource 0 (IFM) dim 1-4
    for (int dims = 2; dims < 4; dims++)
    {
        out_defs->inputTensorAccessPattern[1].dim[dims].dim      = dims;
        out_defs->inputTensorAccessPattern[1].dim[dims].start_a  = 1;
        out_defs->inputTensorAccessPattern[1].dim[dims].end_a    = 1;
        out_defs->inputTensorAccessPattern[1].dim[dims].start_b  = 0;
        out_defs->inputTensorAccessPattern[1].dim[dims].end_b    = 1 - 1;
    }

    // f_start f(i) = elementsInVec*i + 0;
    // f_end   f(i) = elementsInVec*i + (elementsInVec - 1);
    // Resource 0 (OFM) dim 0
    out_defs->outputTensorAccessPattern[0].dim[0].dim      = 0;
    out_defs->outputTensorAccessPattern[0].dim[0].start_a  = elementsInVec;
    out_defs->outputTensorAccessPattern[0].dim[0].end_a    = elementsInVec;
    out_defs->outputTensorAccessPattern[0].dim[0].start_b  = 0;
    out_defs->outputTensorAccessPattern[0].dim[0].end_b    = elementsInVec - 1;
	
	out_defs->outputTensorAccessPattern[0].dim[1].dim      = 1;
    out_defs->outputTensorAccessPattern[0].dim[1].start_a  = c_unrollCount;
    out_defs->outputTensorAccessPattern[0].dim[1].end_a    = c_unrollCount;
    out_defs->outputTensorAccessPattern[0].dim[1].start_b  = 0;
    out_defs->outputTensorAccessPattern[0].dim[1].end_b    = c_unrollCount - 1;

    // f_start f(i) = 1*i + 0;
    // f_end   f(i) = 1*i + 0;
    // Resource 0 (OFM) dim 1-4
    for (int dims = 2; dims < 4; dims++)
    {
        out_defs->outputTensorAccessPattern[0].dim[dims].dim      = dims;
        out_defs->outputTensorAccessPattern[0].dim[dims].start_a  = 1;
        out_defs->outputTensorAccessPattern[0].dim[dims].end_a    = 1;
        out_defs->outputTensorAccessPattern[0].dim[dims].start_b  = 0;
        out_defs->outputTensorAccessPattern[0].dim[dims].end_b    = 1 - 1;
    }


    /*************************************************************************************
    *    Stage IV -  define scalar parameters
    **************************************************************************************/
    out_defs->kernel.paramsNr =0;

    /*************************************************************************************
    *    Stage V -  Load ISA into the descriptor.
    **************************************************************************************/
    unsigned IsaSize = (&_kernels_gaudi_binary___relu6_fwd_f32_o_end - &_kernels_gaudi_binary___relu6_fwd_f32_o_start);
    unsigned char *binary_kernel;
    switch (m_mode)
    {
        case fwd_f32:
            IsaSize = (&_kernels_gaudi_binary___relu6_fwd_f32_o_end - &_kernels_gaudi_binary___relu6_fwd_f32_o_start);
            binary_kernel = &_kernels_gaudi_binary___relu6_fwd_f32_o_start;
            break;
        case bwd_f32:
            IsaSize = (&_kernels_gaudi_binary___relu6_bwd_f32_o_end - &_kernels_gaudi_binary___relu6_bwd_f32_o_start);
            binary_kernel = &_kernels_gaudi_binary___relu6_bwd_f32_o_start;
            break;
        case fwd_bf16:
            IsaSize = (&_kernels_gaudi_binary___relu6_fwd_bf16_o_end - &_kernels_gaudi_binary___relu6_fwd_bf16_o_start);
            binary_kernel = &_kernels_gaudi_binary___relu6_fwd_bf16_o_start;
            break;
        case bwd_bf16:
            IsaSize = (&_kernels_gaudi_binary___relu6_bwd_bf16_o_end - &_kernels_gaudi_binary___relu6_bwd_bf16_o_start);
            binary_kernel = &_kernels_gaudi_binary___relu6_bwd_bf16_o_start;
            break;
        default:
            break;
    
    }
        
    unsigned givenBinarySize = out_defs->elfSize;
    out_defs->elfSize = IsaSize;
    if (givenBinarySize >= IsaSize)
    {
        memcpy (out_defs->kernelElf, binary_kernel, IsaSize);
    }
    else
    {
        retVal = gcapi::GLUE_INSUFICIENT_ELF_BUFFER;
        return retVal;
    }

    return gcapi::GLUE_SUCCESS;
}


