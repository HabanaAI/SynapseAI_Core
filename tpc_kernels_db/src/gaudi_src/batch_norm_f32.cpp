/* SPDX-License-Identifier: MIT
 *
 * Copyright 2016-2021 HabanaLabs, Ltd.
 * All Rights Reserved.
 *
 */
#include "batch_norm_f32.hpp"

extern unsigned char _binary___batch_norm_fwd_f32_o_start;
extern unsigned char _binary___batch_norm_fwd_f32_o_end;

gcapi::GlueCodeReturn_t BatchNormF32::GetKernelName(
             char kernelName [gcapi::MAX_NODE_NAME])
{
    strcpy(kernelName, "my_batch_norm_fwd_f32");
    return gcapi::GLUE_SUCCESS;
}

gcapi::GlueCodeReturn_t  BatchNormF32::ValidateTensorsDataType(
           gcapi::Tensor_t* pTensors,
           int tensorCount,
           gcapi::TensorDataType_t expected)
{
    gcapi::GlueCodeReturn_t retVal = gcapi::GLUE_SUCCESS;
    for (int i = 0 ; i < tensorCount ; i++)
    {
        if (pTensors[i].dataType != expected)
        {
            retVal = gcapi::GLUE_INCOMPATIBLE_DATA_TYPE;
            pTensors[i].dataType = expected;
        }
    }
    return retVal;
}

gcapi::GlueCodeReturn_t BatchNormF32::GetGcDefinitions(
            gcapi::HabanaKernelParams_t* in_defs,
            gcapi::HabanaKernelInstantiation_t* out_defs)
{
    gcapi::GlueCodeReturn_t retVal;
    BatchNormParams* def = static_cast<BatchNormParams*>(in_defs->NodeParams);
    /*************************************************************************************
    *   Stage I - validate input
    **************************************************************************************/
    //validate correct amount of input tensors
    if (in_defs->inputTensorNr != 3)
    {
        in_defs->inputTensorNr  = 3;
        return gcapi::GLUE_INCOMPATIBLE_INPUT_COUNT;
    }
    //validate correct amount of output tensors
    if (in_defs->outputTensorNr != 3)
    {
        in_defs->outputTensorNr  = 3;
        return gcapi::GLUE_INCOMPATIBLE_OUTPUT_COUNT;
    }

    // validate input and output data type
    retVal = ValidateTensorsDataType(in_defs->inputTensors,
                                        in_defs->inputTensorNr,
                                        gcapi::DATA_F32);
    if (retVal != gcapi::GLUE_SUCCESS)
    {
        return retVal;
    }

    retVal = ValidateTensorsDataType(in_defs->outputTensors,
                                        in_defs->outputTensorNr,
                                        gcapi::DATA_F32);
    if (retVal != gcapi::GLUE_SUCCESS)
    {
        return retVal;
    }

   // Validate input and output tensor sizes are same
   unsigned int * inputTensorSizes = in_defs->inputTensors[0].geometry.sizes;
   bool SizesAreEqual = true;

   for(unsigned int dim = 0; dim < 4; dim++)
   {
      SizesAreEqual &= (in_defs->outputTensors[0].geometry.sizes[dim]
              == inputTensorSizes[dim]);
   }

   if(!SizesAreEqual)
   {
      return gcapi::GLUE_INCOMPATIBLE_OUTPUT_SIZE;
   }

   // Validate dim0 of all input tensors are equal
   for(unsigned int tns = 1; tns < in_defs->inputTensorNr; tns++)
   {
      SizesAreEqual &= (in_defs->inputTensors[tns].geometry.sizes[0] == inputTensorSizes[0]);
   }

   if(!SizesAreEqual)
   {
      return gcapi::GLUE_INCOMPATIBLE_INPUT_SIZE;
   }

    // Beta and Gamma tensors are expected to be 1D
    if ((in_defs->inputTensors[1].geometry.dims != 1 || in_defs->inputTensors[2].geometry.dims != 1))
    {
           return gcapi::GLUE_INCOMPATIBLE_INPUT_SIZE;
    }

    if ((in_defs->outputTensors[1].geometry.dims != 1 ||
        in_defs->outputTensors[2].geometry.dims != 1))

    {
        return gcapi::GLUE_INCOMPATIBLE_OUTPUT_SIZE;
    }


    /*************************************************************************************
    *    Stage II -  Define index space geometry.
    **************************************************************************************/
    out_defs->indexSpaceGeometry.dims = 4;

    int elementsInVec =  64;
    unsigned depthIndex = (inputTensorSizes[0] + (elementsInVec - 1)) / elementsInVec;
    out_defs->indexSpaceGeometry.sizes[0] = depthIndex;
    out_defs->indexSpaceGeometry.sizes[1] = 1;
    out_defs->indexSpaceGeometry.sizes[2] = 1;
    out_defs->indexSpaceGeometry.sizes[3] = 1;

    /*************************************************************************************
    *    Stage III -  Define index space mapping
    **************************************************************************************/
    // f_start(i) = elementsInVec*i + 0;
    // f_end f(i) = elementsInVec*i + (elementsInVec - 1);
    // Resource 0-4 (IFM) dim 0
    for (unsigned i = 0; i < in_defs->inputTensorNr; i++)
    {
        out_defs->inputTensorAccessPattern[i].dim[0].dim      = 0;
        out_defs->inputTensorAccessPattern[i].dim[0].start_a  = elementsInVec;
        out_defs->inputTensorAccessPattern[i].dim[0].end_a    = elementsInVec;
        out_defs->inputTensorAccessPattern[i].dim[0].start_b  = 0;
        out_defs->inputTensorAccessPattern[i].dim[0].end_b    = elementsInVec - 1;
    }

    float unroll = 4.0; // float is used to promote float divison
    // f_start(i) = 0;
    // f_end f(i) = size[1] - 1;
    // Resource 0 (IFM) dim 1
    // Access is given to all the elements(factor of unroll) since single indexspace is used
    out_defs->inputTensorAccessPattern[0].dim[1].dim = 1;
    out_defs->inputTensorAccessPattern[0].dim[1].start_a =
                ceilf(in_defs->inputTensors[0].geometry.sizes[1] / unroll) * unroll;
    out_defs->inputTensorAccessPattern[0].dim[1].end_a =
                ceilf(in_defs->inputTensors[0].geometry.sizes[1] / unroll) * unroll;
    out_defs->inputTensorAccessPattern[0].dim[1].start_b = 0;
    out_defs->inputTensorAccessPattern[0].dim[1].end_b =
                ceilf(in_defs->inputTensors[0].geometry.sizes[1] / unroll) * unroll - 1;

    // f_start(i) = 0;
    // f_end f(i) = size[2] - 1;
    // Resource 0 (IFM) dim 2
    // Access is given to all the elements(factor of unroll) since single indexspace is used
    out_defs->inputTensorAccessPattern[0].dim[2].dim = 2;
    out_defs->inputTensorAccessPattern[0].dim[2].start_a = in_defs->inputTensors[0].geometry.sizes[2];
    out_defs->inputTensorAccessPattern[0].dim[2].end_a = in_defs->inputTensors[0].geometry.sizes[2];
    out_defs->inputTensorAccessPattern[0].dim[2].start_b = 0;
    out_defs->inputTensorAccessPattern[0].dim[2].end_b = in_defs->inputTensors[0].geometry.sizes[2] - 1;

    // f_start(i) = 0;
    // f_end f(i) = size[3] - 1;
    // Resource 0 (IFM) dim 3
    // Access is given to all the elements(factor of unroll) since single indexspace is used
    out_defs->inputTensorAccessPattern[0].dim[3].dim = 3;
    out_defs->inputTensorAccessPattern[0].dim[3].start_a = in_defs->inputTensors[0].geometry.sizes[3];
    out_defs->inputTensorAccessPattern[0].dim[3].end_a = in_defs->inputTensors[0].geometry.sizes[3];
    out_defs->inputTensorAccessPattern[0].dim[3].start_b = 0;
    out_defs->inputTensorAccessPattern[0].dim[3].end_b = in_defs->inputTensors[0].geometry.sizes[3] - 1;

    // f_start(i) = elementsInVec*i + 0;
    // f_end f(i) = elementsInVec*i + (elementsInVec - 1);
    // Resource 0-4 (OFM) dim 0
    for (unsigned i = 0; i < in_defs->outputTensorNr; i++)
    {
        out_defs->outputTensorAccessPattern[i].dim[0].dim      = 0;
        out_defs->outputTensorAccessPattern[i].dim[0].start_a  = elementsInVec;
        out_defs->outputTensorAccessPattern[i].dim[0].end_a    = elementsInVec;
        out_defs->outputTensorAccessPattern[i].dim[0].start_b  = 0;
        out_defs->outputTensorAccessPattern[i].dim[0].end_b    = elementsInVec - 1;
    }

    // f_start(i) = 0;
    // f_end f(i) = size[1] - 1;
    // Resource 0 (OFM) dim 1
    // Access is given to all the elements(factor of unroll) since single indexspace is used
    out_defs->outputTensorAccessPattern[0].dim[1].dim = 1;
    out_defs->outputTensorAccessPattern[0].dim[1].start_a =
                ceilf(in_defs->inputTensors[0].geometry.sizes[1] / unroll) * unroll;
    out_defs->outputTensorAccessPattern[0].dim[1].end_a =
                ceilf(in_defs->inputTensors[0].geometry.sizes[1] / unroll) * unroll;
    out_defs->outputTensorAccessPattern[0].dim[1].start_b = 0;
    out_defs->outputTensorAccessPattern[0].dim[1].end_b =
                ceilf(in_defs->inputTensors[0].geometry.sizes[1] / unroll) * unroll - 1;

    // f_start(i) = 0;
    // f_end f(i) = size[2] - 1;
    // Resource 0 (OFM) dim 2
    // Access is given to all the elements(factor of unroll) since single indexspace is used
    out_defs->outputTensorAccessPattern[0].dim[2].dim = 2;
    out_defs->outputTensorAccessPattern[0].dim[2].start_a = in_defs->inputTensors[0].geometry.sizes[2];
    out_defs->outputTensorAccessPattern[0].dim[2].end_a = in_defs->inputTensors[0].geometry.sizes[2];
    out_defs->outputTensorAccessPattern[0].dim[2].start_b = 0;
    out_defs->outputTensorAccessPattern[0].dim[2].end_b = in_defs->inputTensors[0].geometry.sizes[2] - 1;

    // f_start(i) = 0;
    // f_end f(i) = size[3] - 1;
    // Resource 0 (OFM) dim 3
    // Access is given to all the elements(factor of unroll) since single indexspace is used
    out_defs->outputTensorAccessPattern[0].dim[3].dim = 3;
    out_defs->outputTensorAccessPattern[0].dim[3].start_a = in_defs->inputTensors[0].geometry.sizes[3];
    out_defs->outputTensorAccessPattern[0].dim[3].end_a = in_defs->inputTensors[0].geometry.sizes[3];
    out_defs->outputTensorAccessPattern[0].dim[3].start_b = 0;
    out_defs->outputTensorAccessPattern[0].dim[3].end_b = in_defs->inputTensors[0].geometry.sizes[3] - 1;
    /*************************************************************************************
    *    Stage IV -  define scalar parameters
    **************************************************************************************/
    float N = in_defs->inputTensors[0].geometry.sizes[1] *
              in_defs->inputTensors[0].geometry.sizes[2] *
              in_defs->inputTensors[0].geometry.sizes[3];
    def->N = N;
    def->N_reciprocal = 1.0 / N;
    out_defs->kernel.paramsNr = sizeof(*def)/ sizeof(int);
    memcpy(&( out_defs->kernel.scalarParams[0]),def, sizeof(*def));

    /*************************************************************************************
    *    Stage V -  Load ISA into the descriptor.
    **************************************************************************************/
    unsigned IsaSize = (&_binary___batch_norm_fwd_f32_o_end - &_binary___batch_norm_fwd_f32_o_start);
    unsigned givenBinarySize = out_defs->elfSize;
    out_defs->elfSize = IsaSize;

    if (givenBinarySize >= IsaSize)
    {
        // copy binary out
        memcpy (out_defs->kernelElf ,
                &_binary___batch_norm_fwd_f32_o_start,
                IsaSize);
    }
    else
    {
       retVal = gcapi::GLUE_INSUFICIENT_ELF_BUFFER;
       return retVal;
    }

    return gcapi::GLUE_SUCCESS;
}

