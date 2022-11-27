/* SPDX-License-Identifier: MIT
 *
 * Copyright 2016-2021 HabanaLabs, Ltd.
 * All Rights Reserved.
 *
 */
#include <vector>
#include <cstring>
#include <iostream>
#include "filter_fwd_2d_bf16.hpp"


extern unsigned char _kernels_gaudi_binary___filter_fwd_2d_bf16_o_start;
extern unsigned char _kernels_gaudi_binary___filter_fwd_2d_bf16_o_end;

 gcapi::GlueCodeReturn_t FilterFwd2dBF16::GetKernelName(
             char kernelName [gcapi::MAX_NODE_NAME])
 {
     strcpy(kernelName,"filter_fwd_2d_bf16");
     return gcapi::GLUE_SUCCESS;
 }


gcapi::GlueCodeReturn_t FilterFwd2dBF16::GetGcDefinitions(
            gcapi::HabanaKernelParams_t* in_defs,
            gcapi::HabanaKernelInstantiation_t* out_defs)
{
    gcapi::GlueCodeReturn_t retVal;
    SpatialReduction2DDef* def = static_cast<SpatialReduction2DDef*>(in_defs->NodeParams);
    /*************************************************************************************
    *   Stage I - validate input
    **************************************************************************************/
    //validate correct amount of input tensors
    if (in_defs->inputTensorNr != 2)
    {
        in_defs->inputTensorNr  = 2;
        return gcapi::GLUE_INCOMPATIBLE_INPUT_COUNT;
    }
    //validate correct amount of output tensors
    if (in_defs->outputTensorNr !=1)
    {
        in_defs->outputTensorNr  = 1;
        return gcapi::GLUE_INCOMPATIBLE_OUTPUT_COUNT;
    }
    //check that filter depth match IFM
    if (in_defs->inputTensors[1].geometry.sizes[0] !=
        in_defs->inputTensors[0].geometry.sizes[0])
    {
        in_defs->inputTensors[1].geometry.sizes[0] =
                in_defs->inputTensors[0].geometry.sizes[0];
        return gcapi::GLUE_INCOMPATIBLE_INPUT_SIZE;
    }

    retVal = ValidateTensorsDataType(in_defs->inputTensors,
                                        in_defs->inputTensorNr,
                                        gcapi::DATA_BF16);
    if (retVal != gcapi::GLUE_SUCCESS)
    {
        return retVal;
    }

    retVal = ValidateTensorsDataType(in_defs->outputTensors,
                                        in_defs->outputTensorNr,
                                        gcapi::DATA_BF16);
    if (retVal != gcapi::GLUE_SUCCESS)
    {
        return retVal;
    }

    // Tensor 0 should be input feature map.
    // The semantics of the input tensors and their order is a convention
    // between TPC kernel writer and the write of the layer at the
    // framework level.
    unsigned int outputSizes[gcapi::MAX_TENSOR_DIM];

    if (!GetOfmSize(in_defs->inputTensors[0].geometry.sizes,def,outputSizes))
    {
        return gcapi::GLUE_UNSUPPORTED_LAYER_CONFIGURATION;
    }

    // verify that output feature map dimension are correct
    if (memcmp(in_defs->outputTensors[0].geometry.sizes,outputSizes,
               in_defs->outputTensors[0].geometry.dims * sizeof(unsigned) ) != 0)
    {
        memcpy(in_defs->outputTensors[0].geometry.sizes,outputSizes,sizeof(outputSizes));
        return gcapi::GLUE_INCOMPATIBLE_OUTPUT_SIZE;
    }
    /*************************************************************************************
    *    Stage II -  Define index space geometry. In this example the index space matches
    *    the dimensions of the output tensor, up to dim 0.
    **************************************************************************************/
    out_defs->indexSpaceGeometry.dims = 4;
    //round up to 128 and divide by 128.
    unsigned depthIndex = (outputSizes[0] + 127) / 128;
    out_defs->indexSpaceGeometry.sizes[0] = depthIndex;
    out_defs->indexSpaceGeometry.sizes[1] = outputSizes[1];
    out_defs->indexSpaceGeometry.sizes[2] = outputSizes[2];
    out_defs->indexSpaceGeometry.sizes[3] = outputSizes[3];

    /*************************************************************************************
    *    Stage III -  Define index space mapping
    **************************************************************************************/
    GetAccessPatterns(out_defs,def,c_bf16ElementsInVector);

    /*************************************************************************************
    *    Stage IV -  define scalar parameters
    **************************************************************************************/
    out_defs->kernel.paramsNr = sizeof(*def)/ sizeof(int);
    memcpy(&( out_defs->kernel.scalarParams[0]),def, sizeof(*def));

    /*************************************************************************************
    *    Stage V -  Load ISA into the descriptor.
    **************************************************************************************/
    unsigned IsaSize = (&_kernels_gaudi_binary___filter_fwd_2d_bf16_o_end - &_kernels_gaudi_binary___filter_fwd_2d_bf16_o_start);
    unsigned givenBinarySize = out_defs->elfSize;
    out_defs->elfSize = IsaSize;

    if (givenBinarySize >= IsaSize)
    {
        // copy binary out
        memcpy (out_defs->kernelElf,
                &_kernels_gaudi_binary___filter_fwd_2d_bf16_o_start,
                IsaSize);
    }
    else
    {
       retVal = gcapi::GLUE_INSUFICIENT_ELF_BUFFER;
       return retVal;
    }

    return gcapi::GLUE_SUCCESS;
}

