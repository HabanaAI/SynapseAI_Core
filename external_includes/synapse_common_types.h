/* SPDX-License-Identifier: MIT
 *
 * Copyright 2016-2021 HabanaLabs, Ltd.
 * All Rights Reserved.
 *
 */

#ifndef SYNAPSE_COMMON_TYPES_H
#define SYNAPSE_COMMON_TYPES_H

#include <stdint.h>

typedef struct internalTensor*          synTensor;
typedef struct syn_cb_internal*         synCommandBuffer;
typedef struct internalWaitHandle*      synWaitHandle;
struct synTensorDescriptor;
typedef struct synTensorDescriptor      synTensorDescriptor;
struct synTensorNDimDescriptor;
typedef struct synTensorNDimDescriptor synTensorNDimDescriptor;
struct synDeviceInfo;
typedef struct synDeviceInfo            synDeviceInfo;

#ifndef __cplusplus
#define size_t uint64_t
#endif

// clang-format off

// The non-host device IDs are numbered 0-15, and the host-id will get the ID of 16
#define MAX_NUM_OF_DEVICES_PER_HOST       (16)

#define MAX_DIMENSIONS_NUM                5
#define MAX_CONV_DIMS                     3

#define TEF_MAX_FILE_NAME_STRING_SIZE 512
#define TEF_MAX_NAME_STRING_SIZE 256
#define TEF_MAX_DATA_STRING_SIZE 64

#define ENQUEUE_TENSOR_NAME_MAX_SIZE      (1024)
#define LSTM_MAX_DIRECTIONS               (2)
#define MAX_LAYOUT_SIZE                   20

static const uint32_t INVALID_BATCH_POS = 0xFFFFFFFF;
static const uint32_t INVALID_TENSOR_INDEX = 0xFFFFFFFF;
    
#define SYN_FLAGS_TENSOR_NAME 0x1

#define TENSOR_INVALID_ID  (0xFFFFFFFFFFFFFFFF)
#define TENSOR_SHAPE_BIT   (1UL << 63)
#define TENSOR_DYNAMIC_BIT (1UL << 62)

#define IS_TENSOR_INVALID(val)   ((val) == TENSOR_INVALID_ID)
#define IS_TENSOR_SHAPE(val)   ((val) & TENSOR_SHAPE_BIT)
#define IS_TENSOR_DYNAMIC(val) ((val) & TENSOR_DYNAMIC_BIT)

#define SYN_MAX_TENSOR_DIM 5
#define SYN_GAUDI_MAX_TENSOR_DIM 8
#define HABANA_DIM_MAX 5

typedef enum synStatus
{
    synSuccess                      = 0,
    synInvalidArgument              = 1,
    synCbFull                       = 2,
    synOutOfHostMemory              = 3,
    synOutOfDeviceMemory            = 4,
    synObjectAlreadyInitialized     = 5,
    synObjectNotInitialized         = 6,
    synCommandSubmissionFailure     = 7,
    synNoDeviceFound                = 8,
    synDeviceTypeMismatch           = 9,
    synFailedToInitializeCb         = 10,
    synFailedToFreeCb               = 11,
    synFailedToMapCb                = 12,
    synFailedToUnmapCb              = 13,
    synFailedToAllocateDeviceMemory = 14,
    synFailedToFreeDeviceMemory     = 15,
    synFailedNotEnoughDevicesFound  = 16,
    synDeviceReset                  = 17,
    synUnsupported                  = 18,
    synWrongParamsFile              = 19,
    synDeviceAlreadyAcquired        = 20,
    synNameIsAlreadyUsed            = 21,
    synBusy                         = 22,
    synAllResourcesTaken            = 23,
    synUnavailable                  = 24,
    synInvalidTensorDimensions      = 25,
    synFail
} synStatus;

typedef enum synDmaDir
{
    HOST_TO_DRAM,
    DRAM_TO_HOST,
    DRAM_TO_DRAM,
    DIRECTION_ENUM_MAX
} synDmaDir;

typedef enum synMemFlags
{
    synMemHost = 0x1,
    synMemDevice = 0x2
} synMemFlags;

typedef enum synDeviceType
{
    synDeviceGaudi,
    synDeviceGaudi2,
    synDeviceTypeInvalid,
    synDeviceTypeSize
} synDeviceType;

typedef enum synDataType
{
    syn_type_na       = 0,               // invalid
    syn_type_fixed    = 1 << 0,          // 8-bit integer
    syn_type_int8     = syn_type_fixed,  // alias to syn_type_fixed
    syn_type_bf16     = 1 << 1,          // 16-bit float- 8 bits exponent, 7 bits mantisa, 1 bit sign
    syn_type_single   = 1 << 2,          // 32-bit floating point, IEEE compliant
    syn_type_float    = syn_type_single, // alias to syn_type_single, IEEE compliant
    syn_type_int16    = 1 << 3,          // 16-bit integer
    syn_type_int32    = 1 << 4,          // 32-bit integer
    syn_type_uint8    = 1 << 5,          // 8-bit unsigned integer
    syn_type_uint16   = 1 << 9,          // 16-bit unsigned integer
    syn_type_uint32   = 1 << 10,         // 32-bit unsigned integer
    // Must be last and this enum must be in ascending order!
    syn_type_max
} synDataType;

typedef enum
{
    DATA_TENSOR  = 0,
    SHAPE_TENSOR,
    OUTPUT_DESCRIBING_SHAPE_TENSOR = SHAPE_TENSOR,
    INPUT_DESCRIBING_SHAPE_TENSOR,
    DATA_TENSOR_DYNAMIC,
    DEVICE_SHAPE_TENSOR,
    TENSOR_TYPE_MAX
}  synTensorType;

typedef struct TensorMetadataInfo
{
    const char*     tensorName;

    uint32_t        elementType;
    double          zp;
    double          scale;
    uint32_t        dimensions;
    uint32_t        dimensionsSize[SYN_MAX_TENSOR_DIM];
    // Not related to this DB. Will be removed on a following commit,
    // so current commit will not break Python-Synapse pair
    uint32_t        roiSizeInBytes;
    uint16_t        batchSize;
    uint8_t         isInput; //TODO currently uint8_t because of python test issues
    char            layout[MAX_LAYOUT_SIZE]; // Only relevant for inference
    uint32_t        sectionId;
    uint64_t        offsetInSection;  // offsets in bytes
} TensorMetadataInfo;

typedef enum synTraceType
{
    synTraceAll = 0x1,
    synTraceHost,
    synTraceDevice,
    synTraceTypeSize
} synTraceType;

typedef enum synTraceFormat
{
    synTraceFormatTEF = 0x1,
    synTraceFormatSize
} synTraceFormat;

typedef struct synTraceEvent
{
    const char* name;
    const char* category;    /* @SerializedName("cat") */
    char        type;        /* @SerializedName("ph")  */
    long double timestamp;   /* @SerializedName("ts")  */
    long double duration;    /* @SerializedName("dur") */
    uint32_t    engineType;  /* @SerializedName("pid") */
    uint32_t    engineIndex; /* @SerializedName("tid") */
    uint32_t    contextId;   /* @SerializedName("id")  */

    union /* @SerializedName("args") */
    {
        struct /* event args */
        {
            const char* dataType;         /* @SerializedName("dtype") */
            const char* operation;        /* @SerializedName("op")    */
            const char* kernel_file_name; /* @serializeName("kernel_file_name")   */
        };

        struct /* counter args */
        {
            double minimum;   /* @SerializedName("Min")   */
            double maximum;   /* @SerializedName("Max")   */
            double average;   /* @SerializedName("Avg")   */
            uint16_t matches; /* @SerializedName("Match") */
        };

        struct /* metadata args */
        {
            const char* name;  /* @SerializedName("name") */
            const char* group; /* @SerializedName("level") */
        };

        /* spmu value */
        uint64_t value;
    } arguments;
} synTraceEvent;

struct synDeviceInfo
{
    uint64_t        sramBaseAddress;
    uint64_t        dramBaseAddress;
    uint32_t        sramSize;
    uint64_t        dramSize;
    uint16_t        tpcEnabledMask;
    uint8_t         dramEnabled;
    uint32_t        deviceId;
    uint32_t        fd;
    synDeviceType   deviceType;
};

// clang-format on

#ifdef __cplusplus
#include "synapse_common_types.hpp"
#endif
#endif /*SYNAPSE_COMMON_TYPES_H*/
