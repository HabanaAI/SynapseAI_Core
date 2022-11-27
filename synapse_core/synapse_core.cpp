/* SPDX-License-Identifier: MIT
 *
 * Copyright 2016-2021 HabanaLabs, Ltd.
 * All Rights Reserved.
 *
 */

#include <sstream>
#include "synapse_api.h"
#include "synapse_common_types.h"
#include "synapse_state.h"
#include "graph.h"
#include "tensor.h"
#include "node.h"
#include "recipe.h"
#include "version.h"

//Implementation of the Synapse API

SynapseState g_state;

synStatus SYN_API_CALL synStreamCreate( synStreamHandle*       pStreamHandle,
                                        const synDeviceId      deviceId,
                                        const synStreamType    streamType,
                                        const uint32_t         flags )
{
    if (deviceId != 0) return synInvalidArgument;
    synStreamHandle handle = g_state.CreateStream(deviceId, streamType, flags);
    if (handle == nullptr)
    {
        return synFail;
    }
    *pStreamHandle = handle;
    return synSuccess;
}

synStatus SYN_API_CALL synStreamDestroy( const synStreamHandle streamHandle )
{
    g_state.DestroyStream(streamHandle);
    return synSuccess;
}

synStatus SYN_API_CALL synStreamWaitEvent( const synStreamHandle       streamHandle,
                                           synEventHandle              eventHandle,
                                           const uint32_t              flags )
{
    //Our streams are synchronous
    return synSuccess;
}

synStatus SYN_API_CALL synStreamSynchronize( const synStreamHandle streamHandle )
{
    //Our streams are synchronous
    return synSuccess;
}

synStatus SYN_API_CALL synStreamQuery( const synStreamHandle streamHandle )
{
    //Our streams are synchronous
    return synSuccess;
}

synStatus SYN_API_CALL synEventCreate( synEventHandle*       pEventHandler,
                                       const synDeviceId     deviceId,
                                       const uint32_t        flags )
{
    if (deviceId != 0) return synInvalidArgument;
    if (flags != 0) return synInvalidArgument;
    if (pEventHandler == nullptr) return synInvalidArgument;

    //No event support in this version
    return synSuccess;
}

synStatus SYN_API_CALL synEventDestroy( synEventHandle eventHandle )
{
    //No event support in this version
    return synSuccess;
}

synStatus SYN_API_CALL synEventRecord( synEventHandle          eventHandle,
                                       const synStreamHandle   streamHandle )
{
    //No event support in this version
    return synSuccess;
}

synStatus SYN_API_CALL synEventQuery( const synEventHandle eventHandle )
{
    //Our streams are synchronous
    return synSuccess;
}

synStatus SYN_API_CALL synEventSynchronize( const synEventHandle eventHandle )
{
    //Our streams are synchronous
    return synSuccess;
}

synStatus SYN_API_CALL synEventElapsedTime( uint64_t*               pNanoSeconds,
                                            const synEventHandle    eventHandleStart,
                                            const synEventHandle    eventHandleEnd )
{
    //No event support in this version
    if (pNanoSeconds == nullptr) return synInvalidArgument;
    *pNanoSeconds = 0;
    return synSuccess;
}

synStatus SYN_API_CALL synRecipeDestroy (synRecipeHandle recipeHandle )
{
    Recipe* r = (Recipe*)recipeHandle;
    if (r == nullptr) return synInvalidArgument;
    delete r;
    return synSuccess;
}

synStatus SYN_API_CALL synRecipeSerialize( const synRecipeHandle  recipeHandle,
                                           const char*            recipeFileName )
{
    //Todo: let's not support
    return synUnsupported;
}

synStatus SYN_API_CALL synRecipeDeSerialize (synRecipeHandle*  pRecipeHandle,
                                             const char*       recipeFileName )
{
    //Todo: let's not support
    return synUnsupported;
}

synStatus SYN_API_CALL synRecipeGetAttribute( uint64_t*                 retVal,
                                              const synRecipeAttribute* recipeAttr,
                                              const unsigned            querySize,
                                              const synRecipeHandle     recipeHandle)
{
    if (retVal == nullptr) return synInvalidArgument;
    if (recipeAttr == nullptr) return synInvalidArgument;
    Recipe* r = (Recipe*)recipeHandle;
    if (r == nullptr) return synInvalidArgument;

    synStatus ret = synSuccess;

    for (unsigned i = 0; i < querySize; ++i)
    {
        switch (recipeAttr[i])
        {
            case RECIPE_ATTRIBUTE_BATCH_SIZE:
                retVal[i] = 0;
                ret = synUnsupported;
                break;

            case RECIPE_ATTRIBUTE_WORKSPACE_SIZE:
                retVal[i] = 0;
                break;

            case RECIPE_ATTRIBUTE_NUM_PERSISTENT_TENSORS:
                retVal[i] = r->GetNumTensors();
                break;

            case RECIPE_ATTRIBUTE_HOST_MEM_SIZE:
                retVal[i] = 0;
                ret = synUnsupported;
                break;

            default:
                ret = synInvalidArgument;
                break;
        }

    }
    return ret;
}

synStatus SYN_API_CALL synSectionCreate( synSectionHandle*        sectionHandle,
                                         uint64_t                 sectionDescriptor,
                                         const synGraphHandle     graph )
{
    *sectionHandle = nullptr;
    return synUnsupported;
}

synStatus SYN_API_CALL synSectionSetGroup( synSectionHandle         sectionHandle,
                                           uint64_t                 sectionGroup)
{
    return synUnsupported;
}

synStatus SYN_API_CALL synSectionGetGroup( synSectionHandle         sectionHandle,
                                           uint64_t*                sectionGroup)
{
    return synUnsupported;
}

synStatus SYN_API_CALL synSectionSetPersistent( synSectionHandle   sectionHandle,
                                                bool               sectionIsPersistent)
{
    return synUnsupported;
}

synStatus SYN_API_CALL synSectionGetPersistent( synSectionHandle     sectionHandle,
                                                bool*                sectionIsPersistent)
{
    return synUnsupported;
}

synStatus SYN_API_CALL synSectionSetRMW( synSectionHandle   sectionHandle,
                                         bool               sectionIsRMW)
{
    if (sectionIsRMW) return synUnsupported;
    return synSuccess;
}

synStatus SYN_API_CALL synSectionGetRMW( synSectionHandle     sectionHandle,
                                         bool*                sectionIsRMW)
{
    *sectionIsRMW = false;
    return synSuccess;
}

synStatus SYN_API_CALL synLaunch( const synStreamHandle             streamHandle,
                                  const synLaunchTensorInfo*        launchTensorsInfo,
                                  const uint32_t                    numberOfTensors,
                                  uint64_t                          pWorkspace,
                                  const synRecipeHandle             pRecipeHandle )
{
    Recipe* r = (Recipe*)(pRecipeHandle);
    Stream* s = (Stream*)(streamHandle);
    if (r == nullptr) return synInvalidArgument;
    if (s == nullptr) return synInvalidArgument;

    if (s->GetType() != STREAM_TYPE_COMPUTE) return synInvalidArgument;

    bool ret = g_state.Launch(s, r, launchTensorsInfo, numberOfTensors);
    if (!ret) return synFail;
    return synSuccess;
}

synStatus SYN_API_CALL synLaunchByTensorIds( const synStreamHandle          streamHandle,
                                             const synLaunchTensorInfoExt*  launchTensorsInfoExt,
                                             const uint32_t                 numberOfTensors,
                                             uint64_t                       pWorkspace,
                                             const synRecipeHandle          pRecipeHandle,
                                             uint32_t                       flags )
{
    return synUnsupported;
}

synStatus SYN_API_CALL synSectionDestroy( synSectionHandle sectionHandle )
{
    return synUnsupported;
}

synStatus SYN_API_CALL synWorkspaceGetSize( uint64_t*                pWorkspaceSize,
                                            const synRecipeHandle    recipeHandle )
{
    *pWorkspaceSize = 0;
    return synSuccess;
}

synStatus SYN_API_CALL synMemCopyAsyncMultiple(const synStreamHandle      streamHandle,
                                               const uint64_t*            src,
                                               const uint64_t*            size,
                                               const uint64_t*            dst,
                                               const synDmaDir            direction,
                                               const uint64_t             numCopies)
{
    if (src == nullptr)  return synInvalidArgument;
    if (size == nullptr) return synInvalidArgument;
    if (dst == nullptr)  return synInvalidArgument;

    synStatus ret = synSuccess;

    for (uint64_t i = 0; i < numCopies; ++i)
    {
        ret = synMemCopyAsync(streamHandle, src[i], size[i], dst[i], direction);
        if (ret != synSuccess) return ret;
    }
    return synSuccess;
}

synStatus SYN_API_CALL synMemCopyAsync(  const synStreamHandle     streamHandle,
                                         const uint64_t            src,
                                         const uint64_t            size,
                                         const uint64_t            dst,
                                         const synDmaDir           direction )
{
    if (size > (uint64_t)(std::numeric_limits<uint32_t>::max)) return synUnsupported;

    uint32_t size32 = (uint32_t)size;
    bool ret = g_state.Memcpy(streamHandle, src, size32, dst, direction);
    if (!ret) return synFail;
    return synSuccess;
}

synStatus SYN_API_CALL synDeviceGetCount( uint32_t* pCount )
{
    if (pCount == nullptr) return synInvalidArgument;
    *pCount = 1;
    return synSuccess;
}

synStatus SYN_API_CALL synDeviceGetCountByDeviceType( uint32_t*              pCount,
                                                      const synDeviceType    deviceType )
{
    switch(deviceType)
    {
        case synDeviceGaudi:
        case synDeviceGaudi2:
            return synDeviceGetCount(pCount);
        default:
            return synInvalidArgument;
    }
}

synStatus SYN_API_CALL synDeviceAcquireByDeviceType( synDeviceId*            pDeviceId,
                                                     const synDeviceType     deviceType)
{
    bool ret = g_state.OpenDevice("", deviceType);
    if (!ret) return synFail;
    *pDeviceId = 0;
    return synSuccess;
}

synStatus SYN_API_CALL synDeviceAcquireByModuleId( synDeviceId*      pDeviceId,
                                                   const synModuleId moduleId )
{
    return synUnsupported;
}

synStatus SYN_API_CALL synDeviceAcquire( synDeviceId*   pDeviceId,
                                         const char*    pciBus )
{
    if (pDeviceId == nullptr) return synInvalidArgument;
    return synUnsupported;
}

synStatus SYN_API_CALL synDeviceSynchronize( const synDeviceId     deviceId )
{
    if (deviceId != 0) return synInvalidArgument;

    //Our streams are synchronous
    return synSuccess;
}

synStatus SYN_API_CALL synDriverGetVersion( char*        pDriverVersion,
                                            const int    len )
{
    if (pDriverVersion == nullptr) return synInvalidArgument;

    std::stringstream   versionStrm;

    versionStrm << HL_DRIVER_MAJOR << "." << HL_DRIVER_MINOR << "." << HL_DRIVER_PATCHLEVEL;

    static std::string version = versionStrm.str();

    if (len < version.size()) return synInvalidArgument;
    memcpy(pDriverVersion, version.c_str(), version.size());
    return synSuccess;
}

synStatus SYN_API_CALL synDeviceGetName( char*               pName,
                                         const int           len,
                                         const synDeviceId   deviceId )
{
    static const char s_gaudiDeviceName[] = "Gaudi";
    static const char s_gaudi2DeviceName[] = "Gaudi2";

    if (deviceId != 0) return synInvalidArgument;
    if (pName == nullptr) return synInvalidArgument;
    if (len < sizeof(s_gaudiDeviceName)) return synInvalidArgument;

    switch(g_state.getCurrentDeviceType())
    {
        case synDeviceGaudi:
            memcpy(pName, s_gaudiDeviceName, sizeof(s_gaudiDeviceName));
            break;
        case synDeviceGaudi2:
            memcpy(pName, s_gaudi2DeviceName, sizeof(s_gaudiDeviceName));
            break;
        default:
            return synInvalidArgument;
    }
    return synSuccess;
}

synStatus SYN_API_CALL synTensorCreate( synTensor*                        pTensor,
                                        const synTensorDescriptor*        descriptor,
                                        const synSectionHandle            pSectionHandle,
                                        const uint64_t                    sectionOffset)
{

    if (pSectionHandle != nullptr) return synUnsupported;
    if (descriptor->m_dataType != syn_type_float) return synUnsupported;
    if (descriptor->m_dims > Tensor::c_tensorMaxDim) return synUnsupported;
    if (descriptor->m_tensorType != DATA_TENSOR) return synUnsupported;

    unsigned sizes[Tensor::c_tensorMaxDim] = {1};

    for (unsigned i = 0; i < descriptor->m_dims; ++i)
    {
        if (descriptor->m_strides[i] != 0) return synUnsupported;
        if (descriptor->m_minSizes[i] != descriptor->m_sizes[i]) return synUnsupported;
        sizes[i] = descriptor->m_sizes[i];
    }

    Tensor* t = new Tensor(descriptor->m_name);
    t->Init(sizes);
    *pTensor = (synTensor)t;
    return synSuccess;
}

synStatus SYN_API_CALL synTensorDestroy( const synTensor tensor )
{
    Tensor* t = (Tensor*)tensor;
    delete t;
    return synSuccess;
}

synStatus SYN_API_CALL synConstTensorCreate (synTensor*                        pTensor,
                                             const synTensorDescriptor*        descriptor )
{
    return synUnsupported;
}

synStatus SYN_API_CALL synTensorRetrieveInfosByName(const synRecipeHandle   pRecipeHandle,
                                                    const uint32_t          numOfTensors,
                                                    TensorMetadataInfo*     tensorsMetadataInfo )
{
    return synUnsupported;
}

synStatus SYN_API_CALL synTensorRetrievePersistentAmount(const synRecipeHandle   pRecipeHandle,
                                                         uint32_t*               numOfTensors)

{
    if (numOfTensors == nullptr) return synInvalidArgument;
    Recipe* r = (Recipe*)pRecipeHandle;
    if (r == nullptr) return synInvalidArgument;
    *numOfTensors = r->GetNumTensors();
    return synSuccess;
}

synStatus SYN_API_CALL synTensorRetrieveNames(const synRecipeHandle   pRecipeHandle,
                                              char                    tensorsName[][ENQUEUE_TENSOR_NAME_MAX_SIZE],
                                              const uint32_t          numOfTensors)
{
    Recipe* r = (Recipe*)pRecipeHandle;
    if (r == nullptr) return synInvalidArgument;

    for (unsigned i = 0; i < numOfTensors; ++i)
    {
        const Tensor* t = r->GetTensor(i);
        if (t == nullptr) return synInvalidArgument;
        memcpy(tensorsName[i], t->GetName().c_str(), t->GetName().size());
    }
    return synSuccess;

}

synStatus SYN_API_CALL synTensorRetrieveIds(const synRecipeHandle    pRecipeHandle,
                                            const char**             tensorNames,
                                            uint64_t*                tensorIds,
                                            const uint32_t           numOfTensors)
{
    return synUnsupported;
}

synStatus SYN_API_CALL synNodeCreate( const synGraphHandle    graphHandle,
                                      const synTensor*        pInputsTensorList,
                                      const synTensor*        pOutputsTensorList,
                                      const uint32_t          numberInputs,
                                      const uint32_t          numberOutputs,
                                      const void*             pUserParams,
                                      const unsigned          paramsSize,
                                      const char*             pGuid,
                                      const char*             pName,
                                      const char**            inputLayouts,
                                      const char**            outputLayouts )
{
    if (inputLayouts != nullptr) return synUnsupported;
    if (outputLayouts != nullptr) return synUnsupported;

    Graph* g = (Graph*)graphHandle;
    if (g == nullptr) return synInvalidArgument;

    Node* n = new Node();
    std::vector<Tensor*> in, out;
    for (unsigned i = 0; i < numberInputs; ++i)
    {
        in.push_back(((Tensor*)(pInputsTensorList[i])));
    }
    for (unsigned i = 0; i < numberOutputs; ++i)
    {
        out.push_back(((Tensor*)(pOutputsTensorList[i])));
    }
    bool ret = n->Init(in, out, pUserParams, paramsSize, pGuid, pName);
    if (!ret)
    {
        delete n;
        return synFail;
    }
    g->addNode(n);
    return synSuccess;
}

synStatus SYN_API_CALL synNodeCreateWithId( const synGraphHandle graphHandle,
                                            const synTensor*     pInputsTensorList,
                                            const synTensor*     pOutputsTensorList,
                                            const uint32_t       numberInputs,
                                            const uint32_t       numberOutputs,
                                            const void*          pUserParams,
                                            const unsigned       paramsSize,
                                            const char*          pGuid,
                                            const char*          pName,
                                            synNodeId*           nodeUniqueId,
                                            const char**         inputLayouts,
                                            const char**         outputLayouts )
{
    return synUnsupported;
}

synStatus SYN_API_CALL synNodeTypeSetPrecision( const synGraphHandle graphHandle,
                                                const char*          guid,
                                                synDataType          precision )
{
    return synUnsupported;
}

synStatus SYN_API_CALL synNodeDependencySet( const synGraphHandle   graphHandle,
                                             const synNodeId*       pBlockingNodesIdList,
                                             const synNodeId*       pBlockedNodesIdList,
                                             const uint32_t         numberblocking,
                                             const uint32_t         numberblocked )
{
    return synUnsupported;
}

synStatus SYN_API_CALL synGraphCompile( synRecipeHandle*                pRecipeHandle,
                                        const synGraphHandle            graphHandle,
                                        const char*                     pRecipeName,
                                        const char*                     pBuildLog )
{
    if (pRecipeHandle == nullptr) return synInvalidArgument;
    Graph* g = (Graph*)graphHandle;
    if (g == nullptr) return synInvalidArgument;

    Recipe* r = new Recipe(g->getDeviceType());
    r->Compile(g, g_state.GetKernelDB(g->getDeviceType()));
    *pRecipeHandle = (synRecipeHandle)r;
    return synSuccess;
}

synStatus SYN_API_CALL synGraphCreate( synGraphHandle*        pGraphHandle,
                                       const synDeviceType    deviceType )
{
    if (pGraphHandle == nullptr) return synInvalidArgument;

    Graph* g;

    switch (deviceType)
    {
        case synDeviceGaudi:
        case synDeviceGaudi2:
            g = new Graph(deviceType);
            *pGraphHandle = (synGraphHandle)g;
            return synSuccess;

        default:
            return synInvalidArgument;
    }
    return synFail;
}

synStatus SYN_API_CALL synGraphDestroy( const synGraphHandle    graphHandle )
{
    Graph* g = (Graph*)graphHandle;
    delete g;
    return synSuccess;
}

synStatus SYN_API_CALL synMemsetD32Async( uint64_t                 pDeviceMem,
                                          const uint32_t           value,
                                          const size_t             numOfElements,
                                          const synStreamHandle    streamHandle )
{
    synStatus ret;
    uint32_t* hostBuf;
    synDeviceId id = 0;
    ret = synHostMalloc(id, numOfElements * sizeof(uint32_t), 0, (void**)&hostBuf);
    if (ret != synSuccess) return ret;
    for (size_t i = 0; i < numOfElements; ++i)
    {
        hostBuf[i] = value;
    }
    ret = synMemCopyAsync(streamHandle, (uint64_t)hostBuf, numOfElements * sizeof(uint32_t), pDeviceMem, HOST_TO_DRAM);
    synHostFree(id, hostBuf, 0);
    return ret;
}

synStatus SYN_API_CALL synMemsetD8Async( uint64_t                 pDeviceMem,
                                         const unsigned char      value,
                                         const size_t             numOfElements,
                                         const synStreamHandle    streamHandle )
{
    synStatus ret;
    unsigned char* hostBuf;
    synDeviceId id = 0;
    ret = synHostMalloc(id, numOfElements * sizeof(unsigned char), 0, (void**)&hostBuf);
    if (ret != synSuccess) return ret;
    for (size_t i = 0; i < numOfElements; ++i)
    {
        hostBuf[i] = value;
    }
    ret = synMemCopyAsync(streamHandle, (uint64_t)hostBuf, numOfElements * sizeof(unsigned char), pDeviceMem, HOST_TO_DRAM);
    synHostFree(id, hostBuf, 0);
    return ret;
}

synStatus SYN_API_CALL synMemsetD16Async( uint64_t                 pDeviceMem,
                                          const uint16_t           value,
                                          const size_t             numOfElements,
                                          const synStreamHandle    streamHandle )
{
    synStatus ret;
    uint16_t* hostBuf;
    synDeviceId id = 0;
    ret = synHostMalloc(id, numOfElements * sizeof(uint16_t), 0, (void**)&hostBuf);
    if (ret != synSuccess) return ret;
    for (size_t i = 0; i < numOfElements; ++i)
    {
        hostBuf[i] = value;
    }
    ret = synMemCopyAsync(streamHandle, (uint64_t)hostBuf, numOfElements * sizeof(uint16_t), pDeviceMem, HOST_TO_DRAM);
    synHostFree(id, hostBuf, 0);
    return ret;
}

synStatus SYN_API_CALL synHostMalloc( const synDeviceId      deviceId,
                                      const uint64_t         size,
                                      const uint32_t         flags,
                                      void**                 buffer )
{
    if (deviceId != 0)     return synInvalidArgument;
    if (flags != 0)        return synInvalidArgument;
    if (buffer == nullptr) return synInvalidArgument;

    void* ret = g_state.HostAlloc(size);
    if (ret == nullptr) return synFail;
    *buffer = ret;
    return synSuccess;
}

synStatus SYN_API_CALL synHostFree( const synDeviceId    deviceId,
                                    const void*          buffer,
                                    const uint32_t       flags )
{
    if (deviceId != 0) return synInvalidArgument;
    if (flags !=0)     return synInvalidArgument;

    g_state.HostFree(const_cast<void*>(buffer));
    return synSuccess;
}

synStatus SYN_API_CALL synHostMap( const synDeviceId          deviceId,
                                   const uint64_t             size,
                                   const void*                buffer )
{
    if (deviceId != 0) return synInvalidArgument;

    bool ret = g_state.HostMap(buffer, size);
    if (!ret) return synFail;
    return synSuccess;
}

synStatus SYN_API_CALL synHostUnmap( const synDeviceId    deviceId,
                                     const void*          buffer )
{
    if (deviceId != 0) return synInvalidArgument;

    bool ret = g_state.HostUnmap(buffer);
    if (!ret) return synFail;
    return synSuccess;
}

synStatus SYN_API_CALL synDeviceMalloc( const synDeviceId    deviceId,
                                        const uint64_t       size,
                                        uint64_t             reqAddr,
                                        const uint32_t       flags,
                                        uint64_t*            buffer )
{
    if (deviceId != 0)     return synInvalidArgument;
    if (flags !=0)         return synInvalidArgument;
    if (reqAddr != 0)      return synInvalidArgument;
    if (buffer == nullptr) return synInvalidArgument;

    uint64_t ret = g_state.DeviceAlloc(size);
    *buffer = ret;
    if (ret == SynapseState::s_invalidDeviceAddr) return synFail;
    return synSuccess;
}

synStatus SYN_API_CALL synDeviceFree( const synDeviceId     deviceId,
                                      const uint64_t        buffer,
                                      const uint32_t        flags )
{
    if (deviceId != 0) return synInvalidArgument;
    if (flags !=0)     return synInvalidArgument;

    g_state.DeviceFree(buffer);
    return synSuccess;
}

synStatus SYN_API_CALL synInitialize()
{
    g_state.Init();
    return synSuccess;
}

synStatus SYN_API_CALL synDestroy()
{
    g_state.Destroy();
    return synSuccess;
}

synStatus SYN_API_CALL synDeviceRelease( const synDeviceId deviceId )
{
    if (deviceId != 0) return synInvalidArgument;
    g_state.CloseDevice();
    return synSuccess;
}

synStatus SYN_API_CALL synDeviceGetMemoryInfo( const synDeviceId    deviceId,
                                               uint64_t*            free,
                                               uint64_t*            total )
{
    if (deviceId != 0)    return synInvalidArgument;
    if (free == nullptr)  return synInvalidArgument;
    if (total == nullptr) return synInvalidArgument;

    synStatus ret;
    synDeviceAttribute att;
    att = DEVICE_ATTRIBUTE_DRAM_FREE_SIZE;
    ret = synDeviceGetAttribute(free, &att, sizeof(uint64_t), deviceId);
    if (ret != synSuccess) return ret;
    att = DEVICE_ATTRIBUTE_DRAM_SIZE;
    ret = synDeviceGetAttribute(total, &att, sizeof(uint64_t), deviceId);
    return ret;
}

synStatus SYN_API_CALL synDeviceGetInfo( const synDeviceId      deviceId,
                                         synDeviceInfo*         pDeviceInfo )
{
    return synUnsupported;
}

synStatus SYN_API_CALL synDeviceGetAttribute( uint64_t*                 retVal,
                                              const synDeviceAttribute* deviceAttr,
                                              const unsigned            querySize,
                                              const synDeviceId         deviceId)
{
    if (deviceId != 0) return synInvalidArgument;
    if (deviceAttr == nullptr) return synInvalidArgument;
    if (querySize < sizeof(uint64_t)) return synInvalidArgument;

    hlthunk_hw_ip_info info;
    if (!g_state.GetDeviceInfo(&info)) return synFail;

    switch (*deviceAttr)
    {
        case DEVICE_ATTRIBUTE_DRAM_SIZE:
            *retVal = info.dram_size;
            break;

        case DEVICE_ATTRIBUTE_TPC_ENABLED_MASK:
            *retVal = info.tpc_enabled_mask;
            break;

        case DEVICE_ATTRIBUTE_STREAMS_TOTAL_MEM_SIZE:
            *retVal = 0;
            break;

        case DEVICE_ATTRIBUTE_DRAM_FREE_SIZE:
            *retVal = g_state.GetFreeDram();
            if (*retVal == 0) return synFail;
            break;

        default:
            return synDeviceTypeGetAttribute(retVal, deviceAttr, querySize, g_state.getCurrentDeviceType());
    }
    return synSuccess;
}

synStatus SYN_API_CALL synDeviceTypeGetAttribute( uint64_t*                 retVal,
                                                  const synDeviceAttribute* deviceAttr,
                                                  const unsigned            querySize,
                                                  const synDeviceType       deviceType)
{
    if (deviceAttr == nullptr) return synInvalidArgument;
    if (deviceType != g_state.getCurrentDeviceType()) return synInvalidArgument;
    if (querySize < sizeof(uint64_t)) return synInvalidArgument;

    hlthunk_hw_ip_info info;

    switch (*deviceAttr)
    {
        case DEVICE_ATTRIBUTE_DRAM_BASE_ADDRESS:
            if (!g_state.GetDeviceInfo(&info)) return synFail;
            *retVal = info.dram_base_address;
            break;

        case DEVICE_ATTRIBUTE_SRAM_SIZE:
        case DEVICE_ATTRIBUTE_MAX_RMW_SIZE:
            *retVal = 0;
            break;

        case DEVICE_ATTRIBUTE_DRAM_ENABLED:
            *retVal = 1;
            break;

        case DEVICE_ATTRIBUTE_DEVICE_TYPE:
            *retVal = deviceType;
            break;

        case DEVICE_ATTRIBUTE_CLK_RATE:
            *retVal = 1600;
            break;

        case DEVICE_ATTRIBUTE_SRAM_BASE_ADDRESS:
            *retVal = SynapseState::s_invalidDeviceAddr;
            break;

        case DEVICE_ATTRIBUTE_DRAM_SIZE:
        case DEVICE_ATTRIBUTE_TPC_ENABLED_MASK:
        case DEVICE_ATTRIBUTE_DRAM_FREE_SIZE:
        case DEVICE_ATTRIBUTE_STREAMS_TOTAL_MEM_SIZE:
        default:
            return synInvalidArgument;
    }
    return synSuccess;
}

synStatus SYN_API_CALL synConfigurationSet(const char*          configurationName,
                                           const char*          configurationValue)
{
    return synUnsupported;
}

synStatus SYN_API_CALL synConfigurationGet(const char*          configurationName,
                                           char*                configurationValue,
                                           uint64_t             size)
{
    return synUnsupported;
}

synStatus SYN_API_CALL synProfilerStart( const synTraceType        type,
                                         const synDeviceId         deviceId )
{
    return synUnsupported;
}

synStatus SYN_API_CALL synProfilerStop( const synTraceType      type,
                                        const synDeviceId       deviceId )
{
    return synUnsupported;
}

synStatus SYN_API_CALL synProfilerGetTrace( const synTraceType      type,
                                            const synDeviceId       deviceId,
                                            const synTraceFormat    format,
                                            void*                   buffer,
                                            size_t*                 size,
                                            size_t*                 numEntries)
{
    return synUnsupported;
}

synStatus SYN_API_CALL synTensorHandleCreate(synTensor*               tensor,
                                             synGraphHandle           graph,
                                             synTensorType            type,
                                             const char*              tensorName)
{
    if (graph == nullptr)  return synInvalidArgument;
    if (tensor == nullptr) return synInvalidArgument;

    if (type != DATA_TENSOR) return synUnsupported;

    Tensor* t = new Tensor(tensorName);
    *tensor = (synTensor)t;
    return synSuccess;
}

synStatus SYN_API_CALL synTensorAssignToSection(synTensor           tensor,
                                                synSectionHandle    section,
                                                uint64_t            byteOffset)
{
    if ((section != nullptr) || (byteOffset != 0)) return synUnsupported;

    return synSuccess;
}

synStatus SYN_API_CALL synTensorSetHostPtr(synTensor            tensor,
                                           void*                hostPtr,
                                           uint64_t             size,
                                           synDataType          dataType,
                                           bool                 copyBuffer)
{
    return synUnsupported;
}

synStatus SYN_API_CALL synTensorSetQuantizationData(synTensor               tensor,
                                                    synQuantizationProperty prop,
                                                    void*                   propVal,
                                                    uint64_t                propSize)
{
    return synUnsupported;
}

synStatus SYN_API_CALL synTensorSetGeometry(synTensor                   tensor,
                                            const synTensorGeometry*    geometry,
                                            synGeometryType             geometryType)
{
    if (geometryType != synGeometrySizes)
    {
        return synUnsupported;
    }
    if (geometry == nullptr) return synInvalidArgument;

    Tensor* t = (Tensor*)tensor;
    if (t == nullptr) return synInvalidArgument;

    unsigned sizes[Tensor::c_tensorMaxDim] = {1};



    for (unsigned i = 0; i < geometry->dims; ++i)
    {
        sizes[i] = geometry->sizes[i];
    }

    t->Init(sizes);
    return synSuccess;
}

synStatus SYN_API_CALL synTensorSetDeviceLayout(synTensor                    tensor,
                                                const synTensorDeviceLayout* layout)
{
    return synUnsupported;
}

synStatus SYN_API_CALL synTensorGetSection(synTensor           tensor,
                                           synSectionHandle*   section,
                                           uint64_t*           byteOffset)
{
    if ((section == nullptr) || (byteOffset == nullptr)) return synInvalidArgument;

    *section = nullptr;
    *byteOffset = 0;
    return synSuccess;
}

synStatus SYN_API_CALL synTensorGetHostPtr(synTensor            tensor,
                                           void**               hostPtr,
                                           uint64_t*            size,
                                           synDataType*         dataType)
{
    if ((hostPtr == nullptr) || (size == nullptr) || (dataType == nullptr)) return synInvalidArgument;

    *dataType = syn_type_float;
    *size     = 0;
    *hostPtr  = nullptr;
    return synSuccess;
}

synStatus SYN_API_CALL synTensorGetQuantizationData(synTensor               tensor,
                                                    synQuantizationProperty prop,
                                                    void*                   propVal,
                                                    uint64_t                propSize)
{
    return synUnsupported;
}

synStatus SYN_API_CALL synTensorGetGeometry(const synTensor         tensor,
                                            synTensorGeometry*      geometry,
                                            synGeometryType         geometryType)
{
    if (geometryType != synGeometrySizes)
    {
        return synUnsupported;
    }
    if (geometry == nullptr) return synInvalidArgument;

    Tensor* t = (Tensor*)tensor;
    if (t == nullptr) return synInvalidArgument;

    for (unsigned i = 0; i < Tensor::c_tensorMaxDim; ++i)
    {
        geometry->sizes[i] = t->GetSize(i);
    }
    return synSuccess;
}

synStatus SYN_API_CALL synTensorGetDeviceLayout(const synTensor         tensor,
                                                synTensorDeviceLayout*  layout)
{
    if (layout == nullptr) return synInvalidArgument;

    layout->deviceDataType = syn_type_float;
    for (unsigned i = 0; i < HABANA_DIM_MAX - 1; ++i)
    {
        layout->strides[i] = 0;
    }
    return synSuccess;
}

synStatus SYN_API_CALL synTensorGetName(const synTensor   tensor,
                                        const uint64_t    size,
                                        char*             name)
{
    Tensor* t = (Tensor*)tensor;
    if ((tensor == nullptr) || (name == nullptr) || size == 0) return synInvalidArgument;
    if (t->GetName().size() >= size) return synInvalidArgument;

    strcpy(name, t->GetName().c_str());
    return synSuccess;
}

synStatus SYN_API_CALL synImperativeLaunch( const synStreamHandle   streamHandle,
                                            const synTensor*        pInputsTensorList,
                                            const synTensor*        pOutputsTensorList,
                                            const uint32_t          numberInputs,
                                            const uint32_t          numberOutputs,
                                            const void*             pUserParams,
                                            const unsigned          paramsSize,
                                            const char*             pGuid,
                                            const uint64_t*         pTensorDeviceAddresses)
{
    //Nothing fancy here, just hide some boilerplate code
    uint32_t numTensors = numberInputs + numberOutputs;
    if (numTensors == 0) return synInvalidArgument;
    if (pTensorDeviceAddresses == nullptr) return synInvalidArgument;

    synStatus ret;

    synGraphHandle graphHandle;
    ret = synGraphCreate(&graphHandle, synDeviceGaudi);
    if (ret != synSuccess) return ret;

    ret = synNodeCreate(graphHandle, pInputsTensorList, pOutputsTensorList, numberInputs, numberOutputs, pUserParams, paramsSize, pGuid, "", nullptr,nullptr);
    if (ret != synSuccess)
    {
        synGraphDestroy(graphHandle);
        return ret;
    }

    synRecipeHandle recipe;
    ret = synGraphCompile(&recipe, graphHandle, nullptr, nullptr);
    if (ret != synSuccess)
    {
        synGraphDestroy(graphHandle);
        return ret;
    }

    synLaunchTensorInfo* tensorInfo = new synLaunchTensorInfo[numberInputs + numberOutputs];

    for (unsigned i = 0; i < numTensors; ++i)
    {
        tensorInfo[i].tensorType = DATA_TENSOR;
        tensorInfo[i].pTensorAddress = pTensorDeviceAddresses[i];

        synTensor t = (i < numberInputs) ? pInputsTensorList[i] : pOutputsTensorList[i - numberInputs];

        synTensorGeometry geo;
        ret = synTensorGetGeometry(t, &geo, synGeometrySizes);
        if (ret != synSuccess)
        {
            for (unsigned j = 0; j < i; ++j)
            {
                delete[] tensorInfo[j].tensorName;
            }
            delete[] tensorInfo;
            synGraphDestroy(graphHandle);
            synRecipeDestroy(recipe);
            return ret;
        }
        memcpy(tensorInfo[i].tensorSize, geo.sizes, sizeof(tensorInfo[i].tensorSize));

        char* pTensorName = new char[ENQUEUE_TENSOR_NAME_MAX_SIZE];
        ret = synTensorGetName(t, ENQUEUE_TENSOR_NAME_MAX_SIZE, pTensorName);
        if (ret != synSuccess)
        {
            for (unsigned j = 0; j < i; ++j)
            {
                delete[] tensorInfo[j].tensorName;
            }
            delete[] tensorInfo;
            synGraphDestroy(graphHandle);
            synRecipeDestroy(recipe);
            return ret;
        }

        tensorInfo[i].tensorName = pTensorName;
    }

    ret = synLaunch(streamHandle, tensorInfo, numTensors, 0, recipe);
    if (ret == synSuccess)
    {
        ret = synStreamSynchronize(streamHandle);
    }

    for (unsigned i = 0; i < numTensors; ++i)
    {
        delete[] tensorInfo[i].tensorName;
    }
    delete[] tensorInfo;
    synGraphDestroy(graphHandle);
    synRecipeDestroy(recipe);
    return ret;
}


