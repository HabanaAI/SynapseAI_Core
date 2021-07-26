/* SPDX-License-Identifier: MIT
 *
 * Copyright 2016-2021 HabanaLabs, Ltd.
 * All Rights Reserved.
 *
 */

#ifndef SYNAPSE_API_TYPES_H
#define SYNAPSE_API_TYPES_H

#include "synapse_common_types.h"

// clang-format off

static const uint32_t INVALID_MODULE_ID = 0xFFFFFFFF;

typedef enum
{
    DEVICE_ATTRIBUTE_SRAM_BASE_ADDRESS,
    DEVICE_ATTRIBUTE_DRAM_BASE_ADDRESS,
    DEVICE_ATTRIBUTE_SRAM_SIZE,
    DEVICE_ATTRIBUTE_DRAM_SIZE,
    DEVICE_ATTRIBUTE_DRAM_FREE_SIZE,
    DEVICE_ATTRIBUTE_TPC_ENABLED_MASK,
    DEVICE_ATTRIBUTE_DRAM_ENABLED,
    DEVICE_ATTRIBUTE_DEVICE_TYPE,
    DEVICE_ATTRIBUTE_CLK_RATE,
    DEVICE_ATTRIBUTE_MAX_RMW_SIZE,
    DEVICE_ATTRIBUTE_STREAMS_TOTAL_MEM_SIZE,
    DEVICE_ATTRIBUTE_MAX_DIMS
} synDeviceAttribute;

typedef enum
{
    STREAM_TYPE_COPY_DEVICE_TO_HOST,
    STREAM_TYPE_COPY_HOST_TO_DEVICE,
    STREAM_TYPE_COPY_DEVICE_TO_DEVICE,
    STREAM_TYPE_COMPUTE,
    STREAM_TYPE_NETWORK_COLLECTIVE,
    STREAM_TYPE_MAX_USER_TYPES,
    STREAM_TYPE_RESERVED_1 = STREAM_TYPE_MAX_USER_TYPES,
    STREAM_TYPE_MAX
} synStreamType;

typedef enum
{
    RECIPE_ATTRIBUTE_BATCH_SIZE,
    RECIPE_ATTRIBUTE_WORKSPACE_SIZE,
    RECIPE_ATTRIBUTE_NUM_PERSISTENT_TENSORS,
    RECIPE_ATTRIBUTE_HOST_MEM_SIZE,
    RECIPE_ATTRIBUTE_MAX
} synRecipeAttribute;

struct InternalRecipeHandle;
struct InternalSectionHandle;
struct InternalStreamHandle;
struct InternalGraphHandle;
struct EventInterface;

typedef struct EventInterface*          synEventHandle;
typedef struct InternalRecipeHandle*    synRecipeHandle;

typedef struct InternalSectionHandle*   synSectionHandle;
typedef struct InternalGraphHandle*     synGraphHandle;
typedef uint32_t                        synModuleId;
typedef uint32_t                        synDeviceId;
typedef struct InternalStreamHandle*    synStreamHandle;
typedef uint64_t                        synNodeId;


typedef struct
{
    const char*     tensorName;
    uint64_t        pTensorAddress;
    synTensorType   tensorType;
    uint32_t        tensorSize[SYN_MAX_TENSOR_DIM];
} synLaunchTensorInfo;

typedef struct
{
    const char*     tensorName;
    uint64_t        pTensorAddress;
    synTensorType   tensorType;
    uint32_t        tensorSize[SYN_MAX_TENSOR_DIM];
    uint64_t        tensorId;
} synLaunchTensorInfoExt;

typedef enum
{
    STREAM_HW_ID,
    STREAM_QUERY_ID_MAX
} StreamQuery_t;

typedef enum
{
    SYN_QUANT_DYNAMIC_RANGE,
    SYN_QUANT_METADATA,
    SYN_QUANT_FLAGS,
} synQuantizationProperty;

typedef struct
{
    uint32_t sizes[HABANA_DIM_MAX];
    uint32_t dims;
} synTensorGeometry;

typedef enum
{
    synGeometryMinSizes,
    synGeometryMaxSizes,
    synGeometrySizes = synGeometryMaxSizes
} synGeometryType;

typedef struct
{
    uint32_t    strides[HABANA_DIM_MAX-1];
    synDataType deviceDataType;
} synTensorDeviceLayout;

enum eventCreateFlags {EVENT_COLLECT_TIME = 1};

// clang-format on

#endif /*SYNAPSE_API_TYPES_H*/
