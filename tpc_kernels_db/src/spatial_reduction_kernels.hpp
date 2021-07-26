/* SPDX-License-Identifier: MIT
 *
 * Copyright 2016-2021 HabanaLabs, Ltd.
 * All Rights Reserved.
 *
 */
#ifndef _SPATIAL_REDUCTION_KERNELS_HPP
#define _SPATIAL_REDUCTION_KERNELS_HPP

#include <gc_interface.h>

class SpatialReductionKernels
{
public:

    SpatialReductionKernels() {}
    virtual ~SpatialReductionKernels() {}

    // This struct is common between the TPC kernel writer and the framework
    // layer writer. The programmer who adds a new layer to the framework-backend
    // is responsible to fill the structure with valid data.
    // TPC kernel writer accepts this struct as input.
    struct SpatialReduction2DDef
    {
        int pad_w;
        int pad_h;
        int kernel_w;
        int kernel_h;
        int stride_w;
        int stride_h;
        int dilation_w;
        int dilation_h;
    };

    // function common to all host glue code
    static bool GetOfmSize(unsigned int IfmSize [gcapi::MAX_TENSOR_DIM],
                                   const SpatialReduction2DDef * def,
                                   unsigned int OfmSize [gcapi::MAX_TENSOR_DIM]);

    static void GetAccessPatterns(gcapi::HabanaKernelInstantiation_t* out_defs,
                           const SpatialReduction2DDef * def,
                           unsigned int elementsInVector);

    void OverrideAccessPatternForMultipleElements(gcapi::HabanaKernelInstantiation_t* out_defs,
                                                  const SpatialReduction2DDef* def,
                                                  unsigned int dim,
                                                  unsigned int elementsNr);

    unsigned int ElementsInVector() const;

    gcapi::GlueCodeReturn_t  ValidateTensorsDataType(
                                gcapi::Tensor_t* pTensors,
                                int tensorCount,
                                gcapi::TensorDataType_t expected);


protected:
     const unsigned int c_f32ElementsInVector = 64;
     const unsigned int c_bf16ElementsInVector = 128;
     const unsigned int c_i8ElementsInVector  = 256;

private:
    SpatialReductionKernels(const SpatialReductionKernels& other) = delete;
    SpatialReductionKernels& operator=(const SpatialReductionKernels& other) = delete;
};

#endif  // _SPATIAL_REDUCTION_KERNELS_HPP
