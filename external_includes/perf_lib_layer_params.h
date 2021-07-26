/* SPDX-License-Identifier: MIT
 *
 * Copyright 2016-2021 HabanaLabs, Ltd.
 * All Rights Reserved.
 *
 */

/*
 * NOTE: This file is parsed automatically. Please use the following structure:
 *
 *  Kernel name: kernel1, kernel2, kernel3, etc..
 *
 * IMPORTANT:Do not write anything after "Kernel name: " that is not a kernel guid.
 *
 * namespace ns_someNamespace
 * {
 *      struct Params
 *      {
 *          ...
 *      };
 * }
 *
 *  Only use 1 struct per namespace. Inheritance is ok, but not multiple inheritance.
 */

#ifndef PERF_LIB_LAYER_PARAMS_H
#define PERF_LIB_LAYER_PARAMS_H

typedef union
{
    float f;
    int i;
} fint_t;

enum EPoolingConvention
{
    POOLING_CONVENTION_VALID = 0,
    POOLING_CONVENTION_FULL
};
typedef enum _UpsampleType_t
{
    UPSAMPLE_TYPE_BILINEAR = 0,
    UPSAMPLE_TYPE_NEAREST_NEIGHBOR
} EUpsampleType_t;

typedef enum _SparseLengthsSumType_t
{
    EMBEDDED_SC_ZP = 0,
    SEPARATE_SC_ZP
} ESparseLengthsSumType_t;

typedef enum _GridGeneratorType_t
{
    GRID_GENERATOR_TYPE_AFFINE = 0,
    GRID_GENERATOR_TYPE_WARP
} EGridGeneratorType_t;

typedef enum _CrossEntropyMode_t
{
    CROSS_ENTROPY_MODE_SUM = 0,
    CROSS_ENTROPY_MODE_MEAN = 1,
    // CROSS_ENTROPY_MODE_NO_REDUCTION mode is only applicable in fwd non-sparse
    // (dense) version
    CROSS_ENTROPY_MODE_NO_REDUCTION = 2
} ECrossEntropyMode_t;

typedef enum _CastF32RoundMode_t
{
    CAST_ROUND_HALF_NE = 0,
    CAST_ROUND_DOWN = 1,
    CAST_ROUND_UP = 2,
    CAST_ROUND_SR = 3,
    CAST_ROUND_ZERO = 4,
    CAST_ROUND_DEFAULT = 5,
    CAST_ROUND_HALF_AZ = 6
} CastF32RoundMode_t;

typedef enum _ResizeInterpolationMode_t
{
    RESIZE_INTER_NEAREST = 0,
    RESIZE_INTER_LINEAR = 1,
    RESIZE_INTER_CUBIC = 2,
    RESIZE_INTER_AREA = 3,
    RESIZE_INTER_GAUSSIAN = 4
} ResizeInterpolationMode_t;

typedef enum _ResizeNearestMode_t
{
    // versions older than 11 did not have nearest_mode attr.
    // ROUND_DEFAULT is used to maintain backward compatibility
    ROUND_DEFAULT = 0,
    ROUND_PREFER_FLOOR = 1,
    ROUND_PREFER_CEIL = 2,
    FLOOR = 3,
    CEIL = 4
} ResizeNearestMode_t;

typedef enum _ResizeCoordinateTransformationMode_t
{
    HALF_PIXEL_MODE = 0,
    PYTORCH_HALF_PIXEL_MODE = 1,
    ALIGN_CORNERS_MODE = 2,
    ASYMMETRIC_MODE = 3,
    TF_HALF_PIXEL_FOR_NN_MODE = 4
} ResizeCoordinateTransformationMode_t;

typedef enum _RoiAlignMode_t
{
    ROI_ALIGN_AVG = 0,
    ROI_ALIGN_MAX = 1
} RoiAlignMode_t;

typedef enum _SortDirection_t
{
    SORT_ASCENDING = 0,
    SORT_DESCENDING = 1,
} SortDirection_t;

typedef enum _CropAndResizeMode_t
{
    CROP_AND_RESIZE_MODE_BILINEAR = 0,
    CROP_AND_RESIZE_MODE_NEAREST = 1
} CropAndResizeMode_t;

typedef enum
{
    EMBEDDING_BAG_MODE_SUM = 0,
    EMBEDDING_BAG_MODE_MEAN
} EmbeddingBagMode_t;

typedef enum
{
    LEFT = 0,
    RIGHT = 1
} ShiftDir_t;

typedef enum
{
    NLL_LOSS_MODE_MEAN = 0,
    NLL_LOSS_MODE_SUM,
    NLL_LOSS_MODE_NONE
} NLLLossMode_t;

typedef enum
{
    MSE_LOSS_REDUCTION_MODE_MEAN = 0,
    MSE_LOSS_REDUCTION_MODE_SUM,
    MSE_LOSS_REDUCTION_MODE_NONE
} MSELossMode_t;

typedef enum _RoundMode_t
{
    ROUND_HALF_AWAY_FROM_ZERO = 0,
    ROUND_HALF_NEAREST_EVEN = 1,
} RoundMode_t;

typedef enum _PadMode_t
{
    PAD_MODE_CONSTANT = 0,
    PAD_MODE_REFLECT,
    PAD_MODE_EDGE,
    PAD_MODE_SYMMETRIC
} PadMode_t;

typedef enum _ColorSpaceMode_t
{
    RGB_TO_YCBCR = 0,
    RGB_TO_BGR,
    YCBCR_TO_RGB,
    YCBCR_TO_BGR,
    BGR_TO_RGB,
    BGR_TO_YCBCR,
    GRAY_TO_RGB,
    GRAY_TO_BGR,
    GRAY_TO_YCBCR,
    RGB_TO_GRAY,
    YCBCR_TO_GRAY,
    BGR_TO_GRAY,
} ColorSpaceMode_t;

typedef enum _SpatialCorrelation_t
{
    SPATIAL_CORRELATION_TYPE_NEAREST_NEIGHBOR = 0,
    SPATIAL_CORRELATION_TYPE_BILINEAR,
} SpatialCorrelation_t;

typedef enum
{
    RIGHT_RIGHT = 0,
    RIGHT_LEFT = 1,
    LEFT_RIGHT = 2,
    LEFT_LEFT = 3,
} DiagAlign_t;
/////////////////////////////// GENERAL_KERNELS ///////////////////////////////

/*
 * Kernel name: long_loop
 */
namespace ns_LongLoop
{
    struct Params
    {
        unsigned int count;
    };
} // namespace ns_LongLoop

/*
 * Kernel name: l2norm_i8, l2norm_i16
 */
namespace ns_L2normKernel
{
    struct Params
    {
        float epsilon;
    };
} // namespace ns_L2normKernel

/*
 * Kernel name: printf_test
 */
namespace ns_PrintfTestKernel
{
    struct Params
    {
        int int_val;
        unsigned int uint_val;
        float float_val;
        short short_val __attribute__((aligned(4)));
        unsigned short ushort_val __attribute__((aligned(4)));
        char char_val __attribute__((aligned(4)));
        unsigned char uchar_val __attribute__((aligned(4)));
    };
} // namespace ns_PrintfTestKernel

/*
 * Kernel name:  printf_vpu_demo_i8, printf_vpu_demo_u8, printf_vpu_demo_i16,
 *               printf_vpu_demo_i32, printf_vpu_demo_f32, printf_vpu_demo_bf16
 */
namespace ns_PrintfVpuDemoKernel
{
    struct Params
    {
        fint_t val_0;
        int pos_0;
        fint_t val_1;
        int pos_1;
        fint_t val_2;
        int pos_2;
    };
} // namespace ns_PrintfVpuDemoKernel

///////////////////////////// ELEMENTWISE_KERNELS /////////////////////////////

/*
 * Kernel name: rsqrt_fwd_f32
 */
namespace ns_RsqrtKernel
{
    struct Params
    {
        bool useNonLut; // there is NonLut based flavor for rsqrt_fwd_f32
                        // pros: VLM will be free
                        // cons: accuaracy and performance degraded
                        //default is false
    };
} // namespace ns_RsqrtKernel

/*
 * Kernel name: div_mod_fwd_i16, div_mod_fwd_i8, div_mod_fwd_i32,
 *              div_mod_i8, div_mod_i16, div_mod_i32
 */
namespace ns_DivModKernel
{
    struct Params
    {
        bool isPyCompatible; // python div_mod requires remainder with the same sign of
                             // divisor except of zero remainder, unlike C++
                             // for backward compatibility, default is false
    };
} // namespace ns_DivModKernel

/*
 * Kernel name: clamp_i8, clamp_i16, clamp_f32
 */
namespace ns_ClampKernel
{
    struct Params
    {
        fint_t upperBound;
        fint_t lowerBound;
    };
} // namespace ns_ClampKernel

/*
 * Kernel name: hard_sigmoid_f32
 */
namespace ns_HardSigmoidKernel
{
    struct Params
    {
        float alpha;
        float beta;
    };
} // namespace ns_HardSigmoidKernel

/*
 * Kernel name: relu_i8, relu_u8, relu_i16, relu_f32
 */
namespace ns_ReluKernel
{
    struct Params
    {
        fint_t threshold;
    };
} // namespace ns_ReluKernel

/*
 * Kernel name: selu_f32, selu_i16
 */
namespace ns_SeluKernel
{
    struct Params
    {
        float gamma;
        float alpha;
    };
    struct ParamsV2 : public Params
    {
        bool isInputFeaturemap;
    };
} // namespace ns_SeluKernel

/*
 * Kernel name: elu_i8, elu_i16, elu_f32
 */
namespace ns_EluKernel
{
    struct Params
    {
        float alpha;
    };
    struct ParamsV2 : public Params
    {
        bool isInputFeaturemap;
    };
} // namespace ns_EluKernel

/*
 * Kernel name: leakyrelu_i8, leakyrelu_i16, leakyrelu_f32
 */
namespace ns_LeakyReluKernel
{
    struct Params
    {
        double alpha;
    };
} // namespace ns_LeakyReluKernel

/*
 * Kernel name: batch_norm_i8,  batch_norm_relu_i8,
 *              batch_norm_i16, batch_norm_relu_i16,
 *              batch_norm_f32, batch_norm_relu_f32,
 */
namespace ns_BatchNormKernel
{
    struct Params
    {
        fint_t threshold; // threshold.i to use with .._i8 and .._i16 kernels
                          // threshold.f to use with .._f32 kernel
        float momentum;
        float epsilon;
    };
    struct ParamsV2 : public Params
    {
        bool isTraining;
    };
} // namespace ns_BatchNormKernel

/*
 * Kernel name: batch_norm_variance_f32,  batch_norm_variance_bf16
 */
namespace ns_BatchNormVarienceKernel
{
    struct Params
    {
        fint_t threshold; // threshold.i to use with .._i8 and .._i16 kernels
                          // threshold.f to use with .._f32 kernel
        float momentum;
        float epsilon;
        float N;
    };
} // namespace ns_BatchNormVarienceKernel

/*
 * Kernel name: batch_norm_stage1_bwd_bf16
 */
namespace ns_BatchNormStage1Kernel
{
    struct Params
    {
        int disable_beta_gamma_update;
        int N;
    };
    struct ParamsV2 : public Params
    {
        bool isTraining;
    };
} // namespace ns_BatchNormStage1Kernel

/*
 * Kernel name: batch_norm_stage2_relu_bwd_bf16,        batch_norm_stage2_relu_bwd_f32
 *              batch_norm_stage2_relu_fwd_bf16,        batch_norm_stage2_relu_fwd_f32
 *              batch_norm_stage2_add_relu_bwd_bf16,    batch_norm_stage2_add_relu_bwd_f32
 *              batch_norm_stage2_add_relu_fwd_bf16,    batch_norm_stage2_add_relu_fwd_f32
 */
namespace ns_BatchNormStage2Kernel
{
    struct Params
    {
        float momentum;
        int disable_runnings_update;
        int N;
        float epsilon;
    };
    struct ParamsV2 : public Params
    {
        bool isTraining;
    };
} // namespace ns_BatchNormStage2Kernel

/*
 * Kernel name: instance_norm_f32, instance_norm_relu_f32,
 */
namespace ns_InstanceNormKernel
{
    struct Params
    {
        fint_t threshold; // threshold.f to use with .._f32 kernel
    };
} // namespace ns_InstanceNormKernel

/*
 * Kernel name: instance_norm_fwd_f32
 */
namespace ns_InstanceNormTrainingKernel
{
    struct Params
    {
        float momentum;
        float eps;
    };
} // namespace ns_InstanceNormTrainingKernel

/*
 * Kernel name: layer_norm_relu_f32,
 */
namespace ns_LayerNormKernelRelu
{
    struct Params
    {
        fint_t threshold; // threshold.f to use with .._f32 kernel
        bool epsValid;
        fint_t eps; // threshold.f to use with .._f32 kernel
    };
    struct ParamsNorm : Params
    {
        int NormAxisBmp;  // A bit-map for CWHN. Set res bit for the dim to be normalized
        int ParamAxisBmp; // A bit-map for CWHN. Set res bit for the dim to be normalized
    };
} // namespace ns_LayerNormKernelRelu

/*
 * Kernel name: layer_norm_f32,
 *              layer_norm_fwd_f32, layer_norm_fwd_bf16
 */
namespace ns_LayerNormKernel
{
    struct Params
    {
        bool epsValid;
        float eps;
    };
    struct ParamsNorm : Params
    {
        int NormAxisBmp;  // A bit-map for CWHN. Set res bit for the dim to be normalized
        int ParamAxisBmp; // A bit-map for CWHN. Set res bit for the dim to be normalized
    };
} // namespace ns_LayerNormKernel

/*
 * Kernel name: layer_norm_bwd_stage1_f32,
 *              layer_norm_bwd_stage1_bf16
 */
namespace ns_LayerNormStage1Kernel
{
    struct Params
    {
        int chunkSize; // size of chunk to be accumulated for dBeta and dGamma along width
    };
} // namespace ns_LayerNormStage1Kernel

/*
 * Kernel name: lrn_f32
 */
namespace ns_LrnKernel
{
    struct Params
    {
        float alpha;
        float beta;
        float knorm;
        int nsize;
    };
} // namespace ns_LrnKernel

/*
 * Kernel name: lpnorm_f32
 */
namespace ns_LpNormKernel
{
    struct Params
    {
        float p;
        float eps;
        int dim;
    };
    struct ParamsNorm : Params
    {
        bool epsMax;  // Performs 'max(denominator,eps)' instead of 'denominator += eps'
    };
} // namespace ns_LpNormKernel

/*
 * Kernel name: lpnorm_frobenius_stage1_f32,
 *              lpnorm_frobenius_stage1_bf16
 */
namespace ns_LpNormFroStage1Kernel
{
    struct Params
    {
        int chunkSize; // size of chunk to be accumulated for norm along width
    };
}

/*
 * Kernel name: softmax_f32, logsoftmax_f32,
 *              softmax_i16, logsoftmax_i16
 */
namespace ns_Softmax
{
    struct Params
    {
        int dim;
    };
    struct ParamsV2 : public Params
    {
        bool isRaggedSoftMax;
    };
} // namespace ns_Softmax

/*
* Kernel name: constant_i8, constant_i16, constant_f32
*/
namespace ns_ConstantKernel
{
    struct Params
    {
        fint_t constant;
    };
} // namespace ns_ConstantKernel

/*
 * Kernel name: random_uniform_f32
 */
namespace ns_RandomUniform
{
    struct Params
    {
        float low;
        float high;
        unsigned int seed;
    };
} // namespace ns_RandomUniform

/*
 * Kernel name: random_normal_f32
 */
namespace ns_RandomNormal
{
    struct Params
    {
        float mean;
        float stddev;
        unsigned int seed;
    };
} // namespace ns_RandomNormal

/*
 * Kernel name: random_seed
 */
namespace ns_RandomSeed
{
    struct Params
    {
        unsigned int seed;
    };
} // namespace ns_RandomSeed

/*
 * Kernel name: random_multinomial_f32,
 *              random_multinomial_log_f32
 */
namespace ns_RandomMultinomial
{
    struct Params
    {
        int outcomes;
        int shape;
        int get_prob;
        unsigned int seed;
    };
} // namespace ns_RandomMultinomial

/*
 * Kernel name: random_exponential_f32
 */
namespace ns_RandomExponential
{
    struct Params
    {
        float beta;
        unsigned int seed;
    };
} // namespace ns_RandomExponential

/*
* Kernel name : random_gamma_f32
*/
namespace ns_RandomGamma
{
    struct Params
    {
        float alpha;
        float beta;
        unsigned int seed;
    };
} // namespace ns_RandomGamma

/*
* Kernel name: random_negative_binomial_f32
*/
namespace ns_RandomNegativeBinomial
{
    struct Params
    {
        float k;
        float p;
        unsigned int seed;
    };
} // namespace ns_RandomNegativeBinomial

/*
* Kernel name: random_bernoulli_fwd_f32, random_bernoulli_fwd_bf16
*/
namespace ns_RandomBernoulli
{
    struct Params
    {
        unsigned int seed;
    };
} // namespace ns_RandomBernoulli

/*
 * Kernel name: random_uniform_fwd_f32, random_uniform_fwd_bf16
 */
namespace ns_XavierFill
{
    struct Params
    {
        unsigned int seed;
    };
} // namespace ns_XavierFill

/*
* Kernel name : pick_f32
*/
namespace ns_Pick
{
    struct Params
    {
        int axis;
    };
} // namespace ns_Pick

/*
 * Kernel name : random_poisson_f32
 */
namespace ns_RandomPoisson
{
    struct Params
    {
        float lambda;
        unsigned int seed;
    };
} // namespace ns_RandomPoisson

/*
 * Kernel name: bitonic_sort_f32
 */
namespace ns_BitonicSort
{
    struct Params
    {
        int chunkSize;        // Size of each chunk to be sorted (Same for input/output)
        int axis;             // axis to be sorted
        SortDirection_t dir;  // ascending/descending
        bool isInputSqueezed; // Is the input squeezed
    };
    struct ParamsV2 : public Params
    {
        bool isStable; // stable sort = 1 / unstable sort = 0
    };
} // namespace ns_BitonicSort

/*
 * Kernel name: sort_step_f32
 */

/*
 * Multiple kernel invocations lead to sorted output
 *
 * ( i) totalIterations - number of times the kernel has to be invoked
 *
 *                 - (n * ( n + 1 ) ) / 2
 *
 *             where n = log2 of size of dimension to be sorted
 *
 *       Example : Input : 4D Tensor of size {4,16,5,5}
 *                         axis = 1
 *                         is_ascend = 1
 *
 *           Size of dimension 1 = 16
 *           log2(16) = 4
 *
 *           totalIterations = ( 4 * ( 4 + 1 ) ) / 2 = 10
 *
 *           totalIterations = 10
 *
 *           for(int i = 0; i < totalIterations; i++)
 *           {
 *               iterationNumber = i;
 *
 *               // Kernel Invocations
 *
 *           }
 */
namespace ns_SortStep
{
    struct Params
    {
        // python layer params
        int totalIterations;
        int iterationNumber; // current iteration number

        // user params
        int axis;       // axis to be sorted
        bool is_ascend; // ascending/descending
    };
} // namespace ns_SortStep

/*
 * Kernel name : filter_and_squeeze_f32
 */
namespace ns_FilterAndSqueeze
{
    struct Params
    {
        fint_t threshold;
    };
} // namespace ns_FilterAndSqueeze

/*
 * Kernel name: scalar_merge_f32
 */

namespace ns_ScalarMerge
{
    struct Params
    {
        int inputChunkSize;
        int topK; // 0 < topK <= IFM dim[axis] size anything beyond that is an error.
        SortDirection_t sortDirection;
        int axis;
        bool isInputSqueezed;
    };
} // namespace ns_ScalarMerge

/*
 * Kernel name: sort_bwd_f32
 */
namespace ns_SortBwd
{
    struct Params
    {
        int topK;
        int axis;
    };
} // namespace ns_SortBwd

/*
 * Kernel name: sort_pre_process_f32, sort_pre_process_i32
 */
namespace ns_SortPreProcess
{
    struct Params
    {
        int staticChunkSize;     // Size of each chunk to be sorted according to the graph.
        int axis;                // axis to be sorted
        SortDirection_t sortDir; // ascending/descending
    };
} // namespace ns_SortPreProcess

/*
 * Kernel name: generate_bitonic_chunks_f32, generate_bitonic_chunks_i32
 */
namespace ns_GenerateBitonicChunks
{
    struct Params
    {
        int staticChunkSize;     // Size of each chunk to be sorted according to the graph.
        int axis;                // axis to be sorted
        SortDirection_t sortDir; // ascending/descending
    };

    struct ParamsV2 : public Params
    {
        bool isTopK;   // Flag to indicate whether TopK or not
        bool isStable; // stable sort = 1 / unstable sort = 0
    };
} // namespace ns_GenerateBitonicChunks
/*
* Kernel name: large_bitonic_merge_f32, large_bitonic_merge_i32
*/
namespace ns_LargeBitonicMerge
{
    struct Params
    {
        int staticChunkSize;     // Chunk size at the GBC stage
        int axis;                // axis to be sorted
        SortDirection_t sortDir; // ascending/descending
        int blockId;
        int stageId;
    };

    struct ParamsV2 : public Params
    {
        bool isStable; // stable sort = 1 / unstable sort = 0
    };
} // namespace ns_LargeBitonicMerge

/*
 * Kernel name: small_bitonic_merge_f32, small_bitonic_merge_i32
 */
namespace ns_SmallBitonicMerge
{
    struct Params
    {
        int staticChunkSize;     // Chunk size at the GBC stage
        int blockId;             // Block number corresponding to required SBM stage
        int axis;                // axis to be sorted
        SortDirection_t sortDir; // ascending/descending
    };

    struct ParamsV2 : public Params
    {
        bool isStable; // stable sort = 1 / unstable sort = 0
    };
} // namespace ns_SmallBitonicMerge

//////////////////////////////// GNMT_KERNELS /////////////////////////////////

/*
 * Kernel name: top_k_st1_i8,   top_k_st2_i8,
 *              top_k_st1_i16,  top_k_st2_i16,
 *              top_k_st1_f32,  top_k_st2_f32,
 */
namespace ns_TopK
{
    struct Params
    {
        unsigned int kSize;
        unsigned int axis;
        unsigned int chunkSize;
    };
} // namespace ns_TopK

/*
 * Kernel name: gru_st1_i8, gru_st2_i8,
 */
namespace ns_GruKernel
{
    struct Params
    {
        int expX;
        int expCt;
    };
} // namespace ns_GruKernel
/*
 * Kernel name: lstm_i16, lstm_f32
 */
namespace ns_LstmKernel
{
    struct Params
    {
        int timeStamp;            // begins with 0, must be LT B vector length
        int expGatesIntermediate; // must be GE to expGatesIn extracted from Tensors
    };
} // namespace ns_LstmKernel

/*
 * Kernel name: bs_st0_f32,
 *              bs_st1_i16,
 *              bs_st2_i16,
 *              bs_st3_i16,
 *              bs_st4_i16,
 *              bs_st5_i16,
 *              bs_st6_i16,
 *              bs_st7_i16,
 *              bs_st8_i16,
 *              bs_st8_i8,
 *              bs_st9_i16
 */
namespace ns_BsKernel
{
    struct Params
    {
        unsigned int k;       //  bsw;
        unsigned int b;       //  bdec;
        unsigned int vocSize; // vocabularySize;
        unsigned int maxOutputLen;
        unsigned int decoderOutputSize;
        float scaleFix;
        float scaleGem;
        int zp;
    };
} // namespace ns_BsKernel

////////////////////////////// REDUCTION_KERNELS //////////////////////////////

/*
 * Kernel name: reduce_sum_f32,
 *              reduce_sum_i8,
 *              reduce_sum_i16,
 *              reduce_prod_f32,
 *              reduce_L1_f32,
 *              reduce_L2_f32,
 *              reduce_log_sum_f32,
 *              reduce_log_sum_exp_f32,
 *              reduce_sum_square_f32,
 *              reduce_max_f32,
 *              reduce_min_f32,
 *              reduce_mean_f32,
 *              argmin_i8,
 *              argmin_i16,
 *              argmin_f32,
 *              argmax_i8,
 *              argmax_i16,
 *              argmax_f32,
 *              hardmax_f32
 */
namespace ns_Reduction
{
    struct Params
    {
        unsigned int reductionDimension;
    };
} // namespace ns_Reduction

/*
 * Kernel name: reduce_Lp_f32
 */
namespace ns_ReduceLp
{
    struct Params : public ns_Reduction::Params
    {
        unsigned int p;
    };
} // namespace ns_ReduceLp

/////////////////////////// SPATIAL_POOLING_KERNELS ///////////////////////////

/*
 * Kernel name: filter_2d_f32,
 *              filter_2d_i8,       filter_2d_i16,
 *              filter_2d_relu_i8,  filter_2d_relu_i16,
 *              maxpool_2d_i8,      maxpool_2d_i16
 */
namespace ns_SpatialReduction
{
    struct Params
    {
        int pad_w_begin;
        int pad_w_end;
        int pad_h_begin;
        int pad_h_end;
        int kernel_w;
        int kernel_h;
        int stride_w;
        int stride_h;
        int dilation_w;
        int dilation_h;
        EPoolingConvention pooling_convention;
    };
} // namespace ns_SpatialReduction

/*
 * Kernel name: filter_3d_f32,
 *              maxpool_3d_f32
 */
namespace ns_SpatialReduction3D
{
    struct Params : public ns_SpatialReduction::Params
    {
        int pad_d_begin;
        int pad_d_end;
        int kernel_d;
        int stride_d;
        int dilation_d;
    };
} // namespace ns_SpatialReduction3D

/*
 * Kernel name: avg_pool_2d_i8,         avg_pool_2d_i16,
 *              avg_pool_2d_relu_i8,    avg_pool_2d_relu_i16
 */
namespace ns_AveragePooling
{
    struct Params : public ns_SpatialReduction::Params
    {
        int includePadding;
    };
    struct ParamsIsValidCount : public Params
    {
        bool isValidCount;
        int dummy; // to avoid Params size ambiguity
    };
} // namespace ns_AveragePooling

/* Kernel name: avg_pool_2d_f32
                avg_pool_2d_bf16 */
namespace ns_AveragePoolingWithDivisorOverride
{
    struct Params : public ns_AveragePooling::Params
    {
        int divisorOverride;
    };
    struct ParamsIsValidCount : public Params
    {
        bool isValidCount;
        int dummy; // to avoid Params size ambiguity
    };
} // namespace ns_AveragePoolingWithDivisorOverride

/*
 * Kernel name : avg_pool_3d_f32
 */
namespace ns_AveragePooling3D
{
    struct Params : public ns_SpatialReduction3D::Params
    {
        int includePadding;
    };
} // namespace ns_AveragePooling3D

/*
 * Kernel name: maxpool_roi_i8, maxpool_roi_i16
 */
namespace ns_MaxPoolRoiKernel
{
    struct Params
    {
        unsigned int num_channels;
        unsigned int pooled_shapeX;
        unsigned int pooled_shapeY;
        unsigned int num_roi;
    };
} // namespace ns_MaxPoolRoiKernel

/*
 * The struct is deprecated, ns_PadKernelEx should be used instead
 */
namespace ns_PadKernel
{
    struct Params
    {
        fint_t value;
        unsigned int pads[10];
    };
} // namespace ns_PadKernel

/*
 * Kernel name: pad_i8, pad_i16, pad_f32, pad_i32
 */
namespace ns_PadKernelEx
{
    struct Params : public ns_PadKernel::Params
    {
        PadMode_t mode;
    };
} // namespace ns_PadKernelEx

/*
 * Kernel name : lpPooling_3d_f32, lpPooling_2d_f32
 */
namespace ns_LpPooling3D
{
    struct Params : public ns_SpatialReduction3D::Params
    {
        int p;
    };
} // namespace ns_LpPooling3D

/*
 * Kernel name: sequence_reverse_i32,
 *              sequence_reverse_i16,
 *              sequence_reverse_i8,
 *              sequence_reverse_f32
 */
namespace ns_SequenceLength
{
    struct Params
    {
        int use_sequence_length; // To use variable-length sequences, set use_sequence_length to
                                 // True, otherwise each example in the batch is assumed
                                 //  to have the max sequence length.
        int batch_axis;
        int time_axis;
    };
} // namespace ns_SequenceLength

/*
 * Kernel name : tile_f32
 */
namespace ns_TileKernel
{
    struct Params
    {
        int repeat[4];
    };
    struct ParamsV2
    {
        int repeat[5];
    };
} // namespace ns_TileKernel

/*
 * Kernel name :sequence_mask_var_len_f32,
 *              sequence_mask_var_len_i8,
 *              sequence_mask_var_len_i16
 */
namespace ns_SequenceMask
{
    struct Params
    {
        bool use_sequence_length;
        float mask_value;
    };
} // namespace ns_SequenceMask

/*
 * Kernel name : dropout_fwd_f32, dropout_bwd_f32
 */
namespace ns_DropoutKernel
{
    struct Params
    {
        float ratio;
        unsigned int seed;
    };
    struct ParamsOptionalMaskOut : public Params
    {
        bool disableMaskOut;
    };
} // namespace ns_DropoutKernel

/*
 * Kernel name : repeat_f32
 */
namespace ns_RepeatKernel
{
    struct Params
    {
        int repeats;
        int axis;
    };
} // namespace ns_RepeatKernel

/*
 * Kernel name : repeat_fwd_f32, repeat_bwd_f32
 */
namespace ns_RepeatKernelGaudiTF
{
    struct Params
    {
        int axis;
    };
} // namespace ns_RepeatKernelGaudiTF

/*
 * Kernel name : take_f32
 */
namespace ns_TakeKernel
{
    struct Params
    {
        int axis;
        int mode;
    };
} // namespace ns_TakeKernel

/*
 * Kernel name : gather_f32
 */
namespace ns_GatherKernel
{
    struct Params
    {
        int axis;
    };

    struct ParamsV2 : public Params
    {
        int batchDims;
    };
} // namespace ns_GatherKernel

/*
 * Kernel name : flip_f32
 */
namespace ns_FlipKernel
{
    struct Params
    {
        int axis;
    };
} // namespace ns_FlipKernel

/*
 * Kernel name : compress_f32
 */
namespace ns_CompressKernel
{
    struct Params
    {
        int axis;
    };
} // namespace ns_CompressKernel

/*
 * Kernel name : ravel_multi_index_i32
 */
namespace ns_RavelKernel
{
    struct Params
    {
        int shape[5];
    };
} // namespace ns_RavelKernel

/*
 * Kernel name : one_hot_f32
 */
namespace ns_OneHotKernel
{
    struct Params
    {
        int axis;
        int depth;
        float on_value;
        float off_value;
    };
} // namespace ns_OneHotKernel

/*
 * Kernel name : correlation_f32
 */
namespace ns_CorrelationKernel
{
    struct Params
    {
        int kernel_size;
        int max_displacement;
        int stride1;
        int stride2;
        int pad_size;
        int is_multiply;
    };
} // namespace ns_CorrelationKernel

/*
 * Kernel name : spatial_correlation_f32
 */
namespace ns_SpatialCorrelationKernel
{
    struct Params
    {
        SpatialCorrelation_t interpolation;
    };
} // namespace ns_SpatialCorrelationKernel

/*
 * Kernel name : upsample_f32, upsample_i8, upsample_u8
 */
namespace ns_UpsampleKernel
{
    struct Params
    {
        EUpsampleType_t mode;
        int scale;
    };
} // namespace ns_UpsampleKernel

/*
 * Kernel name : sparse_lengths_sum_i8, sparse_lengths_sum_i16
 */
namespace ns_SparseLengthsSum
{
    struct Params
    {
        ESparseLengthsSumType_t mode;
    };
} // namespace ns_SparseLengthsSum

/*
 * Kernel name : deformation_transformation_f32, deformation_transformation_i16
 */
namespace ns_DeformationTransformation
{
    struct Params
    {
        int groupCount;
        int kernelWidth;
        int kernelHeight;
        int strideW;
        int strideH;
        int dilationW;
        int dilationH;
        int padW;
        int padH;
    };
} // namespace ns_DeformationTransformation

/*
 * Kernel name : fully_connected_f32
 */
namespace ns_FullyConnected
{
    struct Params
    {
        int is_relu;
    };
} // namespace ns_FullyConnected

/*
 * Kernel name : grid_generator
 */
namespace ns_GridGeneratorKernel
{
    struct Params
    {
        EGridGeneratorType_t mode;
    };
} // namespace ns_GridGeneratorKernel

/*
 * Kernel name : smooth_l1_f32
 */
namespace ns_SmoothL1Kernel
{
    struct Params
    {
        float sigma;
    };
} // namespace ns_SmoothL1Kernel

/*
 * Kernel name : shrink_f32
 */
namespace ns_ShrinkKernel
{
    struct Params
    {
        float lambda;
        float bias;
    };
} // namespace ns_ShrinkKernel

/*
 * Kernel name : optimizer_sgd_bwd_bf16, optimizer_sgd_bwd_f32
 */
namespace ns_OptimizerSGD
{
    struct Params
    {
        float wd;
        float mom;
        float damp;
        bool nesterov;
    };
} // namespace ns_OptimizerSGD

/*
 * Kernel name : optimizer_sparse_sgd_bf16
 */
namespace ns_OptimizerSparseSGD
{
    struct Params
    {
        float mom;
        bool nesterov;
    };
} // namespace ns_OptimizerSparseSGD

/*
 * Kernel name : optimizer_adagrad_bwd_bf16, optimizer_adagrad_bwd_f32,
 *               optimizer_adagrad_bf16, optimizer_adagrad_f32
 */
namespace ns_OptimizerAdagrad
{
    struct Params
    {
        float wd;
        float lrd;
        float eps;
    };
} // namespace ns_OptimizerAdagrad

/*
 * Kernel name : optimizer_sparse_adagrad_bf16,
 *               optimizer_sparse_adagrad_with_valid_count_2d_f32,
 *               optimizer_sparse_adagrad_with_valid_count_2d_bf16
 */
namespace ns_OptimizerSparseAdagrad
{
    struct Params
    {
        float decay;
        float eps;
    };
} // namespace ns_OptimizerSparseAdagrad

/*
 * Kernel name : optimizer_sparse_rowwise_adagrad_with_valid_count_2d_bf16,
 *               optimizer_sparse_rowwise_adagrad_with_valid_count_2d_f32
 */
namespace ns_OptimizerRowWiseAdagrad
{
    struct Params
    {
        float eps;
    };
    struct ParamsV2 : public Params
    {
        float decay;
    };
} // namespace ns_OptimizerRowWiseAdagrad

/*
 * Kernel name : range_f32,
 *               range_i16,
 *               range_i8
 */
namespace ns_RangeKernel
{
    struct Params
    {
        fint_t start;
        fint_t limit;
        fint_t delta;
    };
} // namespace ns_RangeKernel

/*
 * Kernel name : nms_f32
 */
namespace ns_Nms
{
    struct Params
    {
        float nms_threshold;
    };
} // namespace ns_Nms

/*
 * Kernel name : post_nms_f32
 */
namespace ns_PostNms
{
    struct Params
    {
        int max_output_size;
    };
    struct ParamsV2 : public Params
    {
        int max_size_per_batch;
    };
} // namespace ns_PostNms

/*
 * Kernel name : complex_nms_f32
 */
namespace ns_ComplexNMS
{
    struct Params
    {
        ns_FilterAndSqueeze::Params filterAndSqueeze;
        ns_BitonicSort::Params bitonicSort;
        ns_ScalarMerge::Params mergeSort;
        ns_GatherKernel::Params gather;
        ns_Nms::Params nms;
        ns_PostNms::Params postNms;
    };
} // namespace ns_ComplexNMS

/*
 * Kernel name : softmax_cross_entropy_f32, softmax_cross_entropy_bwd_bf16,
 *               softmax_cross_entropy_bwd_f32, softmax_cross_entropy_fwd_bf16,
 *               softmax_cross_entropy_fwd_f32
 */
namespace ns_SoftmaxCrossEntropy
{
    struct Params
    {
        ECrossEntropyMode_t mode;
        int batchSize;
    };

    struct ParamsV2 : public Params
    {
        int axis;
    };

    struct ParamsV3 : public Params
    {
        bool isTfMode; //To imitate TF at BWD
    };
} // namespace ns_SoftmaxCrossEntropy

/*
 * Kernel name : binary_cross_entropy_fwd_f32, binary_cross_entropy_bwd_f32
 */
namespace ns_BinaryCrossEntropy
{
    struct Params
    {
        bool isWeightsUsed;
        ECrossEntropyMode_t mode;
    };

    struct ParamsOptionalSigmoid : public Params
    {
        bool binaryCrossEntropyWithoutSigmoid;
    };
} // namespace ns_BinaryCrossEntropy

/*
 * Kernel name : eye_like_f32
 */
namespace ns_EyeLikeKernel
{
    struct Params
    {
        int k;
    };
} // namespace ns_EyeLikeKernel

/*
 * Kernel name: max_unpool_2d_f32
 */
namespace ns_MaxUnpoolKernel
{
    struct Params
    {
        int pad_w_begin;
        int pad_w_end;
        int pad_h_begin;
        int pad_h_end;
        int kernel_w;
        int kernel_h;
        int stride_w;
        int stride_h;
        int out_width;
        int out_height;
    };
} // namespace ns_MaxUnpoolKernel

/*
 * Kernel name : logit_f32
 */
namespace ns_LogitKernel
{
    struct Params
    {
        float epsilon;
    };
} // namespace ns_LogitKernel

/*
 * Kernel name : cast_f32_to_i16,
 *               cast_f32_to_i32,
 *               cast_f32_to_i8,
 *               cast_f32_to_u8,
 *               cast_i16_to_f32,
 *               cast_i32_to_f32,
 *               cast_i8_to_f32,
 *               cast_u8_to_f32
 */
namespace ns_CastKernel
{
    struct Params
    {
        CastF32RoundMode_t round_mode;
    };
} // namespace ns_CastKernel

/*
 * Kernel name : scatter_f32
 */
namespace ns_ScatterKernel
{
    struct Params
    {
        int axis;
    };
} // namespace ns_ScatterKernel

/*
 * Kernel name : scatter_nd_fwd_f32, scatter_nd_fwd_bf16
 */
namespace ns_ScatterNDKernel
{
    struct Params
    {
        int origIndicesDims;
        int origIndicesShape[5];
    };
} // namespace ns_ScatterNDKernel

/*
 * Kernel name : gather_elements_f32, gather_elements_i32
 */
namespace ns_GatherElementsKernel
{
    struct Params
    {
        int axis;
    };
    struct ParamsV2 : public Params
    {
        bool isSort; // sort = 1
    };
} // namespace ns_GatherElementsKernel

/*
 * Kernel name : resize_u8, resize_i8, resize_f32
 */
namespace ns_ResizeKernel
{
    struct Params
    {
        ResizeInterpolationMode_t mode;
        float scaleDim1;
        float scaleDim2;
        float scaleDim3;
        ResizeCoordinateTransformationMode_t coordTransMode;
        ResizeNearestMode_t nearestMode;
        bool excludeOutside;
        bool useScales; // bool value to select between scales and output sizes
        float cubicCoeffA;
        int size1;
        int size2;
        int size3;
    };

    struct ParamsGauss : Params
    {
        int filterWidth;
        float sigma;
    };
} // namespace ns_ResizeKernel

/*
 * Kernel name : radix_sort_stg1_i32, radix_sort_stg2_i32
 */
namespace ns_RadixSort
{
    struct Params
    {
        int stg;
        int maxBktLen;
        bool sSignBit;
        bool sortDescending;
    };
} // namespace ns_RadixSort

/*
 * Kernel name : roialign_f32
 */
namespace ns_RoiAlignKernel
{
    struct Params
    {
        RoiAlignMode_t mode;
        int sampling_ratio;
        float spatial_scale;
    };
} // namespace ns_RoiAlignKernel

/*
 * Kernel name : isinf_f32
 */
namespace ns_IsInfKernel
{
    struct Params
    {
        int detect_negative;
        int detect_positive;
    };
} // namespace ns_IsInfKernel

/*
 * Kernel name : quad_tree_fwd_f32,
 *               quad_tree_fwd_bf16
 */
namespace ns_QuadTree
{
    struct Params
    {
        int segments; // should be pow(4, x)
    };
    struct ParamsIsValidCount : public Params
    {
        bool isValidCount;
    };
    struct ParamsAbsoluteCoords: ParamsIsValidCount
    {
        bool enableAbsoluteCoords;
        float levelScalarFactor;
    };
} // namespace ns_QuadTree

/*
 * Kernel name : crop_and_resize_f32, crop_and_resize_fwd_f32,
 *               crop_and_resize_fwd_bf16
 */
namespace ns_CropAndResizeKernel
{
    struct Params
    {
        CropAndResizeMode_t mode;
        float extrapolationValue;
    };
    struct ParamsIsValidCount : public Params
    {
        bool isValidCount;
    };
    struct ParamsIsOptionalCropsSize : public ParamsIsValidCount
    {
        int isOptionalCropsSize;
        int dummy;
    };
    struct ParamsBorderReplicate : public ParamsIsOptionalCropsSize
    {
        bool borderReplicate;
    };
    struct ParamsAbsoluteCoords : ParamsBorderReplicate
    {
        bool enableAbsoluteCoords;
        float levelScalarFactor;
    };
} // namespace ns_CropAndResizeKernel

/*
 * Kernel name : crop_and_resize_bwd_f32, crop_and_resize_bwd_bf16
 */
namespace ns_CropAndResizeBwdKernel
{
    struct Params
    {
        CropAndResizeMode_t mode;
    };
    struct ParamsIsValidCount : public Params
    {
        bool isValidCount;
    };
    struct ParamsIsOptionalCropsSize : public ParamsIsValidCount
    {
        int isOptionalCropsSize;
        int dummy;
    };
    // relevant for Reducible version only. For quad-tree based offsets value will be ignored
    struct ParamsSplitedOutput : public ParamsIsOptionalCropsSize
    {
        int outputWidthOffset;
        int outputHeightOffset;
        int outputBatchOffset;
        int outputChannelOffset;
    };
    struct ParamsBorderReplicate : public ParamsSplitedOutput
    {
        bool borderReplicate;
    };
    struct ParamsAbsoluteCoords : ParamsBorderReplicate
    {
        bool enableAbsoluteCoords;
        float levelScalarFactor;
    };
} // namespace ns_CropAndResizeBwdKernel

/*
 * Kernel name : complex_pyramid_roi_align_fwd_f32
 */
namespace ns_PyramidRoiAlignKernel
{
    struct Params
    {
        int num_levels;
        int down_scale_factor;
        ns_CropAndResizeKernel::ParamsIsValidCount cropAndResize_params;
        ns_AveragePoolingWithDivisorOverride::ParamsIsValidCount avgPool_params;
    };
} // namespace ns_PyramidRoiAlignKernel

/*
 * Kernel name : complex_pyramid_roi_align_bwd_f32
 */
namespace ns_PyramidRoiAlignBwdKernel
{
    struct Params
    {
        int num_levels;
        int down_scale_factor;
        ns_QuadTree::ParamsIsValidCount quadTree_params;
        ns_CropAndResizeBwdKernel::ParamsIsValidCount cropAndResize_params;
        ns_AveragePoolingWithDivisorOverride::ParamsIsValidCount avgPool_params;
    };
} // namespace ns_PyramidRoiAlignBwdKernel

/*
 * Kernel name : embedding_sgd_fwd_f32, embedding_sgd_bwd_f32
 */
namespace ns_EmbeddingWithSgdKernel
{
    struct Params
    {
        EmbeddingBagMode_t mode;
        ns_OptimizerSGD::Params sgd;
    };
} // namespace ns_EmbeddingWithSgdKernel

namespace ns_EmbeddingWithAdagradKernel
{
    struct Params
    {
        EmbeddingBagMode_t mode;
        ns_OptimizerAdagrad::Params adagrad;
    };
} // namespace ns_EmbeddingWithAdagradKernel

// TODO: remove structures with 'bag' after renaming
namespace ns_EmbeddingBagWithSgdKernel
{
    struct Params
    {
        EmbeddingBagMode_t mode;
        ns_OptimizerSGD::Params sgd;
    };
} // namespace ns_EmbeddingBagWithSgdKernel

namespace ns_EmbeddingBagWithAdagradKernel
{
    struct Params
    {
        EmbeddingBagMode_t mode;
        ns_OptimizerAdagrad::Params adagrad;
    };
} // namespace ns_EmbeddingBagWithAdagradKernel

/*
 * Kernel name : cumsum_f32
 */
namespace ns_CumSumKernel
{
    struct Params
    {
        int axis;
        int exclusive;
        int reverse;
    };
} // namespace ns_CumSumKernel

/*
 * Kernel name : cumprod_f32
 */
namespace ns_CumProdKernel
{
    struct Params
    {
        int axis;
        int exclusive;
        int reverse;
    };
} // namespace ns_CumProdKernel

/*
 * Kernel name : bitshift_f32
 */
namespace ns_BitShiftKernel
{
    struct Params
    {
        ShiftDir_t direction;
    };
} // namespace ns_BitShiftKernel

/*
 * Kernel name : matrix_band_part_fwd_f32, matrix_band_part_fwd_bf16,
 *               matrix_band_part_bwd_f32, matrix_band_part_bwd_bf16
 */
namespace ns_MatrixBandPartKernel
{
    struct Params
    {
        int numLower;
        int numUpper;
    };
} // namespace ns_MatrixBandPartKernel

/*
 * Kernel name : transpose_f32
 */
namespace ns_TransposeKernel
{
    struct Params
    {
        int axes[4];
    };
} // namespace ns_TransposeKernel

/*
 * Kernel name : bn_get_moments_stage2_f32/bf16
 */
namespace ns_BatchnormGetMomentsKernel
{
    struct Params
    {
        float N;
    };
} // namespace ns_BatchnormGetMomentsKernel

/*
 * Kernel name : unique_fwd_f32
 */

namespace ns_UniqueKernel
{
    struct Params
    {
        int returnInverse;
        int returnCounts;
        int dim;
    };
} // namespace ns_UniqueKernel

/*
 * Kernel name : nll_loss_f32/bf16
 */
namespace ns_NLLLossKernel
{
    struct Params
    {
        NLLLossMode_t mode;
    };
    struct ParamsOptionalIgnoreIndex : public Params
    {
        int ignoreIndexValue;
    };
} // namespace ns_NLLLossKernel

/*
 * Kernel name : matrix_diag_f32/bf16
 */
namespace ns_MatrixDiag
{
    struct Params
    {
        int kMin;
        int kMax;
        int rows;
        int cols;
        float pad;
        DiagAlign_t align;
    };
} // namespace ns_MatrixDiag

/*
 * Kernel name : matrix_set_diag_f32/bf16
 */
namespace ns_MatrixSetDiag
{
    struct Params
    {
        int kMin;
        int kMax;
        DiagAlign_t align;
    };
} // namespace ns_MatrixSetDiag

/*
 * Kernel name : mse_loss_f32, mse_loss_bf16
 */
namespace ns_MSELossKernel
{
    struct Params
    {
        MSELossMode_t mode;
    };
} // namespace ns_MSELossKernel

/*
 * Kernel name : round_f32
 */

namespace ns_RoundKernel
{
    struct Params
    {
        RoundMode_t roundMode;
    };
} // namespace ns_RoundKernel

/*
 * Kernel name : adaptive_avg_pool_2d_fwd_f32,
 *               adaptive_avg_pool_2d_fwd_bf16
 */
namespace ns_AdaptiveAvgPool
{
    struct Params
    {
        int outputWidth;
        int outputHeight;
    };
} // namespace ns_AdaptiveAvgPool

/*
 * Kernel name : brightness_u8,
 *               brightness_u16
 */
namespace ns_Brightness
{
    struct Params
    {
        float brightness_scale;
    };
} // namespace ns_Brightness

/*
 * Kernel name : affine_transform_u8
 */
namespace ns_AffineTransform
{
    struct Params
    {
        int resample;
        int fill;
    };
    struct ShearParams : Params
    {
        float shearX;
        float shearY;
        int isAngle;
        float centerX;
        float centerY;
    };
    struct TranslateParams : Params
    {
        float offsetX;
        float offsetY;
    };
} // namespace ns_AffineTransform

/*
 * Kernel name : hue_u8,
 *               hue_u16
 */
namespace ns_Hue
{
    struct Params
    {
        float degree;
    };
} // namespace ns_Hue

/*
 * Kernel name : crop_u8,
 *               crop_u16
 */
namespace ns_Crop
{
    struct Params
    {
        int crop_w;
        int crop_h;
        int crop_d;
        float crop_pos_x;
        float crop_pos_y;
        float crop_pos_z;
        int pad_val;
    };
} // namespace ns_Crop

/*
 * Kernel name : crop_mirror_i8,
 *               crop_mirror_u8,
 *               crop_mirror_u16
 */
namespace ns_CropMirror
{
    struct Params : public ns_Crop::Params
    {
        int mirror;
    };
} // namespace ns_CropMirror

/*
 * Kernel name : crop_mirror_norm_u8,
 *               crop_mirror_norm_u16
 */
namespace ns_CropMirrorNorm
{
    struct Params : public ns_Crop::Params
    {
        int mirror;
    };
} // namespace ns_CropMirrorNorm

/*
 * Kernel name : saturation_u8,
 *               saturation_u16
 */
namespace ns_Saturation
{
    struct Params
    {
        float saturation_level;
    };
} // namespace ns_Saturation

/*
 * Kernel name : contrast_u8,
 *               contrast_u16
 */
namespace ns_Contrast
{
    struct Params
    {
        float contrast_scale;
    };
} // namespace ns_Contrast

/*
 * Kernel name : color_space_conversion_u8,
 *               color_space_conversion_u16
 */
namespace ns_ColorSpaceConversion
{
    struct Params
    {
        ColorSpaceMode_t colorSpaceMode;
    };
} // namespace ns_ColorSpaceConversion

/*
 * Kernel name : bbflip_f32
 */
namespace ns_BbFlip
{
    struct Params
    {
        int horizontal;
        int vertical;
        bool ltrb;
        bool isHorizontalTensor;
        bool isVerticalTensor;
    };
} // namespace ns_BbFlip

/*
 * Kernel name : flip_3d_u8,
 *               flip_3d_u16
 */
namespace ns_Flip3D
{
    struct Params
    {
        int horizontal;
        int vertical;
        int depthwise;
    };
} // namespace ns_Flip3D

/*
 * Kernel name: where_stage1_i8,  where_stage2_i32
 */
namespace ns_TfWhere
{
    struct Params
    {
        unsigned int tpcCount;
    };
} // namespace ns_TfWhere

/*
 * Kernel name : normalize_u8,
 *               normalize_u16
 */
namespace ns_Normalize
{
    struct Params
    {
        float scale;
        float shift;
        int axis;
        bool batch;
    };
} // namespace ns_Normalize

/*
 * Kernel name : gconv_fwd_bf16, gconv_fwd_f32
 */
namespace ns_GConv
{
    struct Params
    {
        int k;
    };
} // namespace ns_GConv

/*
 * Kernel name : conv_weight_packing_fwd_f32, conv_weight_packing_fwd_bf16
 */
namespace ns_WtPack
{
    struct Params
    {
        int packDegree;
        int stride;
    };
} // namespace ns_WtPack

/*
 * Kernel name : unsorted_f32,
 *               unsorted_bf16
 */
namespace ns_UnsortedSegmentSum
{
    struct Params
    {
        int numSegments;
    };
} // namespace ns_UnsortedSegmentSum

/*
 * Kernel name : color_fwd_u8,
 */
namespace ns_Color
{
    struct Params
    {
        float colorFactor;
    };
}

/*
 * Kernel name : solarize_fwd_u8,
 */
namespace ns_Solarize
{
    struct Params
    {
        float threshold;
    };
}

/*
 * Kernel name: reverse_f32
 */
namespace ns_ReverseKernel
{
    struct Params
    {
        int axis;
    };
} // namespace ns_PadKernelEx

/*
 * Kernel name : sharpness_fwd_u8,
 */
namespace ns_Sharpness
{
    struct Params
    {
        float factor;
    };
}

/*
 * Kernel name : ctc_loss_fwd_f32, ctc_loss_bwd_f32
 */
namespace ns_CTCLoss
{
    struct Params
    {
        bool preprocessCollapseRepeated;
        bool ctcMergeRepeated;
        bool ignoreLongerOutputsThanInputs;
    };
}

#endif /* PERF_LIB_LAYER_PARAMS_H */
