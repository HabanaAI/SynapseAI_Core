/* SPDX-License-Identifier: MIT
 *
 * Copyright 2016-2021 HabanaLabs, Ltd.
 * All Rights Reserved.
 *
 */

#ifndef SYNAPSE_API_H
#define SYNAPSE_API_H

#include <stdint.h>
#include <stdbool.h>
#include "synapse_api_types.h"

#ifdef __cplusplus
extern "C" {
#endif

#if defined(_WIN32)
#define SYN_API_CALL     __stdcall

#else
#define SYN_API_CALL
#include <linux/types.h>
#endif

// clang-format off

// Stream related functions

//!
/*!
 ***************************************************************************************************
 *   @brief Create a stream.
 *
 *   @param pStreamHandle     [out] Returned handle of newly created stream
 *   @param deviceId          [in]  Device ID connected to stream
 *   @param flags             [in]  Parameters for stream creation
 *
 *   @return                  The status of the operation
 ***************************************************************************************************
 */
synStatus SYN_API_CALL synStreamCreate( synStreamHandle*       pStreamHandle,
                                        const synDeviceId      deviceId,
                                        const synStreamType    streamType,
                                        const uint32_t         flags );

//!
/*!
 ***************************************************************************************************
 *   @brief Destroy a stream
 *
 *   Destroys the stream specified by streamHandle.
 *
 *   In case the device is still doing work in the stream streamHandle when synStreamDestroy() is called,
 *   the function will return immediately with error synBusy.
 *   This function is not thread safe (if one thread is destroying a stream while other thread is
 *   using the stream, the behavior is not defined.
 *
 *   @param streamHandle      [in]  Stream to be destroyed
 *
 *   @return                  The status of the operation
 ***************************************************************************************************
 */
synStatus SYN_API_CALL synStreamDestroy( const synStreamHandle streamHandle );

//!
/*!
 ***************************************************************************************************
 *   @brief Makes a stream wait on an event.
 *
 *   Makes all future work submitted to streamHandle wait for completion of eventHandle. eventHandle needs to be
 *   registered to other stream than streamHandle. It works on the same device only (not between devices)
 *
 *   @param streamHandle      [in]  Stream to wait
 *   @param eventHandle       [in]  Event to wait on
 *   @param flags             [in]  Parameters for the operation (must be 0)
 *
 *   @return                  The status of the operation
 ***************************************************************************************************
 */
synStatus SYN_API_CALL synStreamWaitEvent( const synStreamHandle       streamHandle,
                                           synEventHandle              eventHandle,
                                           const uint32_t              flags );

//!
/*!
 ***************************************************************************************************
 *   @brief Waits for all commands in stream to complete.
 *
 *   Blocking function; Waits until the device has completed all operations in the stream specified
 *   by streamHandle.
 *   This function is not thread-safe by design - other threads are not blocked on the stream unless
 *   they call this function as well.
 *
 *   @param streamHandle      [in]  Stream to wait for
 *
 *   @return                  The status of the operation
 ***************************************************************************************************
 */
synStatus SYN_API_CALL synStreamSynchronize( const synStreamHandle streamHandle );

//!
/*!
 ***************************************************************************************************
 *   @brief Determine status of a compute stream.
 *
 *   Returns synSuccess if stream idle or synBusy if there are pending operations in the stream
 *
 *   @param streamHandle      [in]  Stream to check
 *
 *   @return                  The status of the operation
 ***************************************************************************************************
 */
synStatus SYN_API_CALL synStreamQuery( const synStreamHandle streamHandle );

//!
/*!
 ***************************************************************************************************
 *   @brief Create an event
 *
 *   Creates an event *pEventHandle for the given device
 *
 *   @param pEventHandler     [out] Returned handle of newly created event
 *   @param deviceId          [in]  Device to associate newly created event with
 *   @param flags             [in]  Flags for the operation
 *
 *   @return                  The status of the operation
 ***************************************************************************************************
 */
synStatus SYN_API_CALL synEventCreate( synEventHandle*       pEventHandler,
                                       const synDeviceId     deviceId,
                                       const uint32_t        flags );

//!
/*!
 ***************************************************************************************************
 *   @brief Destroy an event
 *
 *   Destroys the event specified by eventHandle.
 *   An event may be destroyed before it is complete. In this case, the call does not block on
 *   completion of the event, and any associated resources will automatically be released
 *   asynchronously at completion.
 *
 *   @param eventHandle       [in]  Event to be destroyed
 *
 *   @return                  The status of the operation
 ***************************************************************************************************
 */
synStatus SYN_API_CALL synEventDestroy( synEventHandle eventHandle );

//!
/*!
 ***************************************************************************************************
 *   @brief Records an event.
 *
 *  Captures in eventHandle the contents of streamHandle at the time of this call. eventHandle and streamHandle must be
 *  from the same device. Calls such as synEventQuery() or synStreamWaitEvent() will then examine
 *  or wait for completion of the work that was captured. Uses of streamHandle after this call do not
 *  modify eventHandle.
 *  synEventRecord() can be called multiple times on the same event and will overwrite the
 *  previously captured state. Other APIs such as synStreamWaitEvent() use the most recently
 *  captured state at the time of the API call, and are not affected by later calls to
 *  synEventRecord(). Before the first call to synEventRecord(), an event represents an empty set of
 *  work, so for example synEventQuery() would return synSuccess.
 *  recording to the same handle from two different threads is not thread safe
 *
 *   @param eventHandle       [in]  Event to record
 *   @param streamHandle      [in]  Stream to record event for
 *
 *   @return                  The status of the operation
 ***************************************************************************************************
 */
synStatus SYN_API_CALL synEventRecord( synEventHandle          eventHandle,
                                       const synStreamHandle   streamHandle );

/*!
 ***************************************************************************************************
 *   @brief Queries an event's status.
 *
 *  Queries the status of work currently captured by eventHandle. Returns synSuccess if all captured work
 *  has been completed, or synBusy if any captured work is incomplete.
 *
 *   @param eventHandle       [in]  Event to check
 *
 *   @return                  The status of the operation
 ***************************************************************************************************
 */
synStatus SYN_API_CALL synEventQuery( const synEventHandle eventHandle );

//!
/*!
 ***************************************************************************************************
 *   @brief Waits for an event to complete.
 *
 *  Blocking function; Waits until the completion of all work currently captured in eventHandle
 *
 *   @param eventHandle       [in]  Event to wait for
 *
 *   @return                  The status of the operation
 ***************************************************************************************************
 */
synStatus SYN_API_CALL synEventSynchronize( const synEventHandle eventHandle );

//!
/*!
 ***************************************************************************************************
 *   @brief Computes the elapsed time between two events.
 *
 *  Computes the elapsed time between two events. If synEventRecord() has not been called on either
 *  event then synObjectNotInitialized is returned. If synEventRecord() has been called on both
 *  events but one or both of them has not yet been completed (that is, synEventQuery() would return
 *  synBusy on at least one of the events), synBusy is returned.
 *   @param pNanoSeconds              [out] number of elapsed nanoseconds
 *   @param eventHandleStart          [in]  Start event
 *   @param eventHandleEnd            [in]  Stop event
 *
 *   @return                  The status of the operation
 *                            synInvalidArgument: One or both events do not collect time
 *                            synUnavailable:     The time of one or both events is already gone (too old)
 ***************************************************************************************************
 */
synStatus SYN_API_CALL synEventElapsedTime( uint64_t*               pNanoSeconds,
                                            const synEventHandle    eventHandleStart,
                                            const synEventHandle    eventHandleEnd );

//!
/*!
 ***************************************************************************************************
 * @brief   Destroys the recipe handle stored in host memory
 *
 * @param   recipeHandle         [in] The Synapse recipe to destroy
 *
 * @return                  Status of the operation
 ***************************************************************************************************
 */
synStatus SYN_API_CALL synRecipeDestroy (synRecipeHandle recipeHandle );

//!
/*!
 ***************************************************************************************************
 * @brief   serialize a recipe to disk
 *
 * @param   recipeHandle             [in]  The Recipe to serialize
 * @param   recipeFileName           [in]  The filename to serialize to
 *
 * @return                  Status of the operation
 ***************************************************************************************************
 */
synStatus SYN_API_CALL synRecipeSerialize( const synRecipeHandle  recipeHandle,
                                           const char*            recipeFileName );

/*!
 ***************************************************************************************************
 * @brief   Deserialize a recipe from disk
 *
 * @param   pRecipeHandle            [out] A pointer to the Recipe to deserialize
 * @param   recipeFileName           [in]  The filename to read from
 *
 * @return                  Status of the operation
 ***************************************************************************************************
 */
synStatus SYN_API_CALL synRecipeDeSerialize (synRecipeHandle*  pRecipeHandle,
                                             const char*       recipeFileName );


//!
/*!
 ***************************************************************************************************
 * @brief   Extract information from recipe (via recipe handle, located in host memory)
 *
 * @param   retVal          [out] Returned array of value of requested attributes
 * @param   recipeAttr      [in]  Array of attributes to query of type synRecipeAttribute
 * @param   querySize       [in]  Size of array of attributes to query (and of the retVal array)
 * @param   recipeHandle    [in]  The handle of the inquired recipe.
 *
 * @return                  Status of the operation
 ***************************************************************************************************
 */

synStatus SYN_API_CALL synRecipeGetAttribute( uint64_t*                 retVal,
                                              const synRecipeAttribute* recipeAttr,
                                              const unsigned            querySize,
                                              const synRecipeHandle     recipeHandle);

//!
/*!
***************************************************************************************************
* @brief Create a memory section.
*
* @param sectionHandle         [out] Returned handle of newly created section
* @param sectionDescriptor     [in]  Deprecated - should not be used
* @param graph                 [in]  The Synapse graph in which a node is created
*
* @return                      The status of the operation
***************************************************************************************************
*/
synStatus SYN_API_CALL synSectionCreate( synSectionHandle*        sectionHandle,
                                         uint64_t                 sectionDescriptor,
                                         const synGraphHandle     graph );

//!
/*!
***************************************************************************************************
* @brief Sets the group of a memory section.
*
* @param sectionHandle         [in]  Handle of a created section
* @param sectionGroup          [in]  Group of the section (0-255)
*
* @return                      The status of the operation
***************************************************************************************************
*/
synStatus SYN_API_CALL synSectionSetGroup( synSectionHandle         sectionHandle,
                                           uint64_t                 sectionGroup);

//!
/*!
***************************************************************************************************
* @brief Get the group of a memory section.
*
* @param sectionHandle         [in]  Handle of a created section
* @param sectionGroup          [out] A pointer to the group
*
* @return                      The status of the operation
***************************************************************************************************
*/
synStatus SYN_API_CALL synSectionGetGroup( synSectionHandle         sectionHandle,
                                           uint64_t*                sectionGroup);

//!
/*!
***************************************************************************************************
* @brief Sets whether a memory section is managed by the application (persistent).
*
* @param sectionHandle         [in]  Handle of a created section
* @param sectionIsPersistent   [in]  Persistency value
*
* @return                      The status of the operation
***************************************************************************************************
*/
synStatus SYN_API_CALL synSectionSetPersistent( synSectionHandle   sectionHandle,
                                                bool               sectionIsPersistent);

//!
/*!
***************************************************************************************************
* @brief Gets whether a memory section is managed by the application (persistent).
*
* @param sectionHandle         [in]  Handle of a created section
* @param sectionIsPersistent   [out] A pointer to persistency value
*
* @return                      The status of the operation
***************************************************************************************************
*/
synStatus SYN_API_CALL synSectionGetPersistent( synSectionHandle     sectionHandle,
                                                bool*                sectionIsPersistent);

//!
/*!
***************************************************************************************************
* @brief Sets whether a memory section should have read-modify-write (RMW) capability.
*
* Note that the maximal capacity of such a section and all other such sections that are
* simultaneously used is limited. The limit can be read using synDeviceGetAttribute by
* reading the DEVICE_ATTRIBUTE_MAX_RMW_SIZE attribute.
*
* @param sectionHandle         [in]  Handle of a created section
* @param sectionIsRMW          [in]  RMW value
*
* @return                      The status of the operation
***************************************************************************************************
*/
synStatus SYN_API_CALL synSectionSetRMW( synSectionHandle   sectionHandle,
                                         bool               sectionIsRMW);

//!
/*!
***************************************************************************************************
* @brief Gets whether a memory section has read-modify-write (RMW) capability.
*
* @param sectionHandle         [in]  Handle of a created section
* @param sectionIsRMW          [out] A pointer to RMW value
*
* @return                      The status of the operation
***************************************************************************************************
*/
synStatus SYN_API_CALL synSectionGetRMW( synSectionHandle     sectionHandle,
                                         bool*                sectionIsRMW);

//!
/*!
 ***************************************************************************************************
 * @brief   Enqueue into the graph the inputs that the input_ptr points to, the device will
 *          execute on any input it can
 *
 * @param   streamHandle              [in]  Stream to enqueue operation to
 * @param   launchTensorsInfo         [in]  A pointer to a list of structs holding the tensor
 *                                          information
 * @param   numberOfTensors           [in]  The number of tensors in launchTensorsInfo
 * @param   pWorkspace                [in]  A pointer to workspace buffer
 * @param   pRecipeHandle             [in]  The RecipeHandle holding the recipe to execute
 *
 * @return                            Status of the operation
 ***************************************************************************************************
 */

synStatus SYN_API_CALL synLaunch( const synStreamHandle             streamHandle,
                                  const synLaunchTensorInfo*        launchTensorsInfo,
                                  const uint32_t                    numberOfTensors,
                                  uint64_t                          pWorkspace,
                                  const synRecipeHandle             pRecipeHandle );



//!
/*!
 ***************************************************************************************************
 * @brief   Immediately execute the given operation on the given stream
 *
 * @param   streamHandle              [in]  Stream to enqueue operation to
 * @param   launchTensorsInfo         [in]  A pointer to a list of structs holding the tensor
 *                                          information
 * @param   numberOfTensors           [in]  The number of tensors in launchTensorsInfo
 * @param   pWorkspace                [in]  A pointer to workspace buffer
 * @param   pRecipeHandle             [in]  The RecipeHandle holding the recipe to execute
 *
 * @return                            Status of the operation
 ***************************************************************************************************
 */

synStatus SYN_API_CALL synImperativeLaunch( const synStreamHandle   streamHandle,
                                            const synTensor*        pInputsTensorList,
                                            const synTensor*        pOutputsTensorList,
                                            const uint32_t          numberInputs,
                                            const uint32_t          numberOutputs,
                                            const void*             pUserParams,
                                            const unsigned          paramsSize,
                                            const char*             pGuid,
                                            const uint64_t*         pTensorDeviceAddresses);


//!
/*!
 ***************************************************************************************************
 * @brief   Enqueue into the graph the inputs that the input_ptr points to, the device will
 *          execute on any input it can
 *
 * @param   streamHandle           [in]  Stream to enqueue operation to
 * @param   pInputsTensorList      [in] An array of input tensors
 * @param   pOutputsTensorList     [in] An array of output tensors
 * @param   numberInputs           [in] The amount of inputs
 * @param   numberOutputs          [in] The amount of outputs
 * @param   pUserParams            [in] a pointer to a user-defined struct containing the scalar arguments
 *                                 to the kernel, that will be forwarded as-is to the glue code (see
 *                                 the appropriate spec). It can be null.
 * @param   pGuid                  [in] the identifier of the operator.
 * @param   pTensorDeviceAddresses [in] Addresses for all tensors, first to inputs in order, then outputs in order
 *
 *
 * @return                       Status of the operation
 ***************************************************************************************************
 */
synStatus SYN_API_CALL synLaunchByTensorIds( const synStreamHandle          streamHandle,
                                             const synLaunchTensorInfoExt*  launchTensorsInfoExt,
                                             const uint32_t                 numberOfTensors,
                                             uint64_t                       pWorkspace,
                                             const synRecipeHandle          pRecipeHandle,
                                             uint32_t                       flags );

//!
/*!
 ***************************************************************************************************
 *   @brief Destroy a memory section.
 *
 *   @param sectionHandle     [in] a handle to the section to destroy
 *
 *   @return                  The status of the operation
 ***************************************************************************************************
 */
synStatus SYN_API_CALL synSectionDestroy( synSectionHandle sectionHandle );

//!
/*!
 ***************************************************************************************************
 *   @brief Gets the size of the workspace which is required to execute a given recipe
 *
 *   @param pWorkspaceSize    [out] the size of the workspace in bytes
 *   @param recipeHandle      [in] a handle to the recipe that is queried
 *
 *   @return                  The status of the operation
 ***************************************************************************************************
 */
synStatus SYN_API_CALL synWorkspaceGetSize( uint64_t*                pWorkspaceSize,
                                            const synRecipeHandle    recipeHandle );

//!
/*!
 ***************************************************************************************************
 * @brief   Multi-entry memory copy between the device and host asynchronously
 *
 * @param   streamHandle   [in]  Stream to enqueue operation to
 * @param   src            [in]  Pointer to an array of source addresses to read from
 * @param   size           [in]  Pointer to an array of amounts in bytes to read
 * @param   dst            [in]  Pointer to an array of dst addresses to write to
 * @param   direction      [in]  The direction to memcpy
 * @param   numCopies      [in]  Amount of elements passed in the above [in] arrays
 *
 *
 * @return                 Status of the operation
 ***************************************************************************************************
 */
synStatus SYN_API_CALL synMemCopyAsyncMultiple(const synStreamHandle      streamHandle,
                                               const uint64_t*            src,
                                               const uint64_t*            size,
                                               const uint64_t*            dst,
                                               const synDmaDir            direction,
                                               const uint64_t             numCopies);

//!
/*!
 ***************************************************************************************************
 * @brief   Memory copy between the device and host asynchronously
 *
 * @param   streamHandle   [in]  Stream to enqueue operation to
 * @param   src            [in]  The source address to read from
 * @param   size           [in]  The amount in bytes to read
 * @param   dst            [in]  The dst address to write to
 * @param   direction      [in]  The direction to memcpy
 *
 * @return                 Status of the operation
 ***************************************************************************************************
 */
synStatus SYN_API_CALL synMemCopyAsync(  const synStreamHandle     streamHandle,
                                         const uint64_t            src,
                                         const uint64_t            size,
                                         const uint64_t            dst,
                                         const synDmaDir           direction );

//!
/*!
 ***************************************************************************************************
 *   @brief Return number of compute-capable devices.
 *
 *   @param pCount       [out] Returned number of devices
 *
 *   @return            The status of the operation
 ***************************************************************************************************
 */
synStatus SYN_API_CALL synDeviceGetCount( uint32_t* pCount );

//!
/*!
 ***************************************************************************************************
 *   @brief Return number of compute-capable devices ( by device type ).
 *
 *   @param pCount       [out] Returned number of devices
 *   @param deviceType   [in]  Device type to count
 *
 *   @return             The status of the operation
 ***************************************************************************************************
 */
synStatus SYN_API_CALL synDeviceGetCountByDeviceType( uint32_t*              pCount,
                                                      const synDeviceType    deviceType );

//!
/*!
 ***************************************************************************************************
 *   @brief Acquire a device (by device-type)
 *
 *   @param pDeviceId           [out] The acquired device-id.
 *   @param deviceType          [in]  The device-type requested to be acquired.
 *                                    In cfase of an invalid-type, finds the first device
 *                                    regardless of its type
 *
 *   @return                    The status of the operation
 ***************************************************************************************************
 */
synStatus SYN_API_CALL synDeviceAcquireByDeviceType( synDeviceId*            pDeviceId,
                                                     const synDeviceType     deviceType);

//!
/*!
 ***************************************************************************************************
 *   @brief Acquire a device (by Module-Id)
 *
 *   @param pDeviceId           [out] The acquired device-id.
 *   @param moduleId            [in]  The Module-Id the requested device is associated with.
 *
 *   @return                    The status of the operation
 ***************************************************************************************************
 */
synStatus SYN_API_CALL synDeviceAcquireByModuleId( synDeviceId*      pDeviceId,
                                                   const synModuleId moduleId );

//!
/*!
 ***************************************************************************************************
 *   @brief Acquire a device (by PCI-bus)
 *
 *   @param pDeviceId           [out] The acquired device-id.
 *   @param pciBus              [in]  The PCI-Bus the requested device resides on.
 *                                    In case of an empty string (or nullptr), finds the first
 *                                    device found
 *
 *   @return                    The status of the operation
 ***************************************************************************************************
 */
synStatus SYN_API_CALL synDeviceAcquire( synDeviceId*   pDeviceId,
                                         const char*    pciBus );

//!
/*!
 ***************************************************************************************************
 *   @brief Wait for compute device to finish
 *
 *   Blocks until the device has completed all preceding requested tasks
 *   Returns an error if one of the preceding tasks has failed
 *
 *   @param deviceId          [in]  Device requested to be synchronized
 *
 *   @return                  The status of the operation
 ***************************************************************************************************
 */
synStatus SYN_API_CALL synDeviceSynchronize( const synDeviceId     deviceId );

//!
/*!
 ***************************************************************************************************
 * @brief   Returns the approximate Synapse driver version.
 *
 * Returns an ASCII string identifying Synapse driver version in convention x.y.z.
 * Len specifies the maximum length of the string that may be returned.
 * @param   pDriverVersion   [out] driver version
 * @param   len              [in]  Maximum length of string to store in name
 *
 * @return                   Status of the operation
 ***************************************************************************************************
 */
synStatus SYN_API_CALL synDriverGetVersion( char*        pDriverVersion,
                                            const int    len );

//!
/*!
 ***************************************************************************************************
 * @brief   Returns an identifier string for the device.
 *
 * Returns an ASCII string identifying the device deviceId in the NULL-terminated string pointed to
 * by pName. len specifies the maximum length of the string that may be returned.
 *
 * @param   pName     [out] Returned identifier string for the device
 * @param   len       [in]  Maximum length of string to store in name
 * @param   deviceId  [in]  The (user's) ID of the device he request to use
 *
 * @return                  Status of the operation
 ***************************************************************************************************
 */
synStatus SYN_API_CALL synDeviceGetName( char*               pName,
                                         const int           len,
                                         const synDeviceId   deviceId );

//!
/*!
 ***************************************************************************************************
 * @brief   Creates a tensor object
 *
 * Created tensors actually are only tensor descriptors (name + shape&type definitions) for graph
 * compilation and don't contain any data nor references to any buffers
 *
 * @param   pTensor             [out]  The tensor that was created
 * @param   descriptor          [in]   A previously-created tensor descriptor
 * @param   sectionHandle       [in]   Section handle where tht tensor resides at
 * @param   sectionDescriptor   [in]   The offset in bytes from the given section base address
 *
 *
 * @return                  Status of the operation
 ***************************************************************************************************
 */
synStatus SYN_API_CALL synTensorCreate( synTensor*                        pTensor,
                                        const synTensorDescriptor*        descriptor,
                                        const synSectionHandle            pSectionHandle,
                                        const uint64_t                    sectionOffset);

//!
/*!
 ***************************************************************************************************
 * @brief   Creates a constant tensor object
 *
 * Created constant tensors are inputs for graph compilation and internally keep a pointer to user allocated data.
 * The user can free the data buffer after compilation.
 *
 * @param   pTensor         [out]  The constant tensor that was created.
 * @param   descriptor      [in]   A previously-created tensor descriptor.
 *
 *
 * @return                  Status of the operation
 ***************************************************************************************************
 */
synStatus SYN_API_CALL synConstTensorCreate (synTensor*                        pTensor,
                                             const synTensorDescriptor*        descriptor );

//!
/*!
 ***************************************************************************************************
 * @brief   Retrieves persistent tensors' information by name
 *
 * Allows the user to query specific persistent tensors in a given recipe.
 * Fills out a TensorMetaData struct containing information about the persistent tensor
 * for each queried tensor.
 *
 * @param   pRecipeHandle        [in]     The inquired recipe
 * @param   numOfTensors         [in]     Number of tensors to get their infos
 * @param   tensorsMetadataInfo  [in/out] A pointer to the TensorMetadataInfo array of size numOfTensors.
 *                                        Each given TensorMetadataInfo must contain the name of a
 *                                        tensor to be queried. the rest of the TensorMetadataInfo
 *                                        struct will be filled by API.
 *
 * @return                  Status of the operation
 ***************************************************************************************************
 */
synStatus SYN_API_CALL synTensorRetrieveInfosByName(const synRecipeHandle   pRecipeHandle,
                                                    const uint32_t          numOfTensors,
                                                    TensorMetadataInfo*     tensorsMetadataInfo );

//!
/*!
 ***************************************************************************************************
 * @brief   Retrieves Persistent Tensors' amount
 *
 * @param   pRecipeHandle        [in]     The inquired recipe
 * @param   numOfTensors         [out]    Number of tensors in recipe
  *
 * @return                  Status of the operation
 ***************************************************************************************************
 */

synStatus SYN_API_CALL synTensorRetrievePersistentAmount(const synRecipeHandle   pRecipeHandle,
                                                         uint32_t*               numOfTensors);

//!
/*!
 ***************************************************************************************************
 * @brief   Retrieves Persistent Tensors' names
 *
 * @param   pRecipeHandle        [in]    The inquired recipe
 * @param   tensorsName          [out]   An array of strings
 * @param   numOfTensors         [in]    Number of tensors' names to get
  *
 * @return                  Status of the operation
 ***************************************************************************************************
 */
synStatus SYN_API_CALL synTensorRetrieveNames(const synRecipeHandle   pRecipeHandle,
                                              char                    tensorsName[][ENQUEUE_TENSOR_NAME_MAX_SIZE],
                                              const uint32_t          numOfTensors);


//!
/*!
 ***************************************************************************************************
 * @brief   Retrieves Tensors id by name
 *
 * @param   pRecipeHandle       [in]  The inquired recipe
 * @param   tensorNames         [in]  A pointer to an array of tensor names
 * @param   tensorIds           [out] An array, allocated by caller, of tensor ids.
 *                                    filled by synapse.
 * @param   numOfTensors        [in]  Number of tensors
 *
 * @return                  Status of the operation
 ***************************************************************************************************
 */
synStatus SYN_API_CALL synTensorRetrieveIds(const synRecipeHandle    pRecipeHandle,
                                            const char**             tensorNames,
                                            uint64_t*                tensorIds,
                                            const uint32_t           numOfTensors);

//!
/*!
 ***************************************************************************************************
 * @brief   Destroy a tensor object
 *
 * Inside Synapse tensor objects are ref counted, so if this function is called after assigning
 * the tensor to some graph node, the tensor is valid (till synGraphDestroy).
 *
 * Upon calling synGraphDestroy, all tensors connected to the graph will also be destroyed, so
 * calling synTensorDestroy on these tensors afterwards is invalid.
 *
 * @param   tensor          [in]  The tensor to destroy
 *
 *
 * @return                  Status of the operation
 ***************************************************************************************************
 */
synStatus SYN_API_CALL synTensorDestroy( const synTensor tensor );

//!
/*!
 ***************************************************************************************************
 * @brief   Creates a node as part of the specified graph
 *
 *
 * @param   graphHandle          [in] The Synapse in which a node is created
 * @param   pInputsTensorList    [in] An array of input tensors
 * @param   pOutputsTensorList   [in] An array of output tensors
 * @param   numberInputs         [in] The amount of inputs
 * @param   numberOutputs        [in] The amount of outputs
 * @param   pUserParams          [in] a pointer to a user-defined struct containing the scalar arguments
 *                               to the kernel, that will be forwarded as-is to the glue code (see
 *                               the appropriate spec). It can be null.
 * @param   paramsSize           [in] The size in bytes of paramsSize
 * @param   pGuid                [in] the identifier of the operator. SynapseAI attempts to match it
 *                               against the list of pre-defined operators, and if no match is
 *                               found, it forwards it to the glue code library that reported
 *                               supporting this GUID in its GetKernelNames entry point. GUID
 *                               length is limited up to 30 characters.
 * @param   pName                [in] A user-defined name that will be later used in logging and graph
 *                               visualization. It’s recommended but not mandatory for this to be
 *                               unique.
 * @param   inputLayouts         [in] An array of strings which size pertains to the number of inputs.
 *                               Every entry in these arrays is the expected data layout for this
 *                               operand (e.g. “NHWC”) or null signifying the operator is
 *                               agnostic to the layout.
 * @param   outputLayouts        [in] As above, for the outputs.
 *
 * @return                  Status of the operation
 ***************************************************************************************************
 */
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
                                      const char**            outputLayouts );

//!
/*!
 ***************************************************************************************************
 * @brief   Creates a node as part of the default graph with an option to get a unique ID
 *
 *
 * @param   graphHandle          [in] The Synapse in which a node is created
 * @param   pInputsTensorList    [in] An array of input tensors
 * @param   pOutputsTensorList   [in] An array of output tensors
 * @param   numberInputs         [in] The amount of inputs
 * @param   numberOutputs        [in] The amount of outputs
 * @param   pUserParams          [in] a pointer to a user-defined struct containing the scalar arguments
 *                               to the kernel, that will be forwarded as-is to the glue code (see
 *                               the appropriate spec). It can be null.
 * @param   pGuid                [in] the identifier of the operator. SynapseAI attempts to match it
 *                               against the list of pre-defined operators, and if no match is
 *                               found, it forwards it to the glue code library that reported
 *                               supporting this GUID in its GetKernelNames entry point. GUID
 *                               length is limited up to 30 characters.
 * @param   pName                [in] A user-defined name that will be later used in logging and graph
 *                               visualization. It’s recommended but not mandatory for this to be
 *                               unique.
 * @param   nodeUniqueId         [out] The API will return a unique ID for the new node,
 *                               that can be used for later references to this node by other API calls.
 * @param   inputLayouts         [in] An array of strings which size pertains to the number of inputs.
 *                               Every entry in these arrays is the expected data layout for this
 *                               operand (e.g. “NHWC”) or null signifying the operator is
 *                               agnostic to the layout.
 * @param   outputLayouts        [in] As above, for the outputs.
 *
 * @return                  Status of the operation
 ***************************************************************************************************
 */
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
                                            const char**         outputLayouts );

//!
/*!
 ***************************************************************************************************
 * @brief   Set node type precision
 *
 *
 * @param   graphHandle         [in] The Synapse in which the node is created.
 * @param   guid                [in] A string identifier for the node type.
 * @param   precision           [in] The precision to set for all nodes for the given guid.
 *                                   If the given precision is syn_type_na, then it will be treated as
 *                                   "don't care", meaning it will take its type from its surrounding nodes.
 *
 * @return                      Status of the operation
 ***************************************************************************************************
 */
synStatus SYN_API_CALL synNodeTypeSetPrecision( const synGraphHandle graphHandle,
                                                const char*          guid,
                                                synDataType          precision );

//!
/*!
 ***************************************************************************************************
 * @brief   Creates a control dependency between two group of nodes
 *
 *
 * @param   graphHandle          [in] The Synapse in which the dependency is created
 * @param   pBlockingNodesIdList [in] An array of blocking node unique IDs
 * @param   pBlockedNodesIdList  [in] An array of blocked node unique IDs
 * @param   numberInputs         [in] The amount of blocking nodes
 * @param   numberOutputs        [in] The amount of blocked nodes
 *
 * @return                  Status of the operation
 ***************************************************************************************************
 */
synStatus SYN_API_CALL synNodeDependencySet( const synGraphHandle   graphHandle,
                                             const synNodeId*       pBlockingNodesIdList,
                                             const synNodeId*       pBlockedNodesIdList,
                                             const uint32_t         numberblocking,
                                             const uint32_t         numberblocked );

//!
/*!
 ***************************************************************************************************
 * @brief   Compile the graph specified
 *
 * @param   pRecipeHandle       [out] Handle to a HabanaRecipe
 * @param   graphHandle         [in] The Synapse graph to compile
 * @param   pRecipeName         [in] The name of the recipe that will be generated
 * @param   pBuildLog           [in] A compilation output log file name. Can be Null
 *
 * @return                  Status of the operation
 ***************************************************************************************************
 */
synStatus SYN_API_CALL synGraphCompile( synRecipeHandle*                pRecipeHandle,
                                        const synGraphHandle            graphHandle,
                                        const char*                     pRecipeName,
                                        const char*                     pBuildLog );
//!
/*!
 ***************************************************************************************************
 * @brief   Replaces the currently active graph instances (if exists) with a new, empty instance.
 *
 * @param   pGraphHandle        [out] The Synapse graph to create
 * @param   deviceType          [in]  The deviceType the graph is created for
 *
 *
 * @return                  Status of the operation
 ***************************************************************************************************
 */
synStatus SYN_API_CALL synGraphCreate( synGraphHandle*        pGraphHandle,
                                       const synDeviceType    deviceType );

//!
/*!
 ***************************************************************************************************
 * @brief   Destroys the current graph instance
 * @param   graphHandle    [in] The Synapse graph to destroy
 *
 * @return                  Status of the operation
 ***************************************************************************************************
 */
synStatus SYN_API_CALL synGraphDestroy( const synGraphHandle    graphHandle );

//!
/*!
 ***************************************************************************************************
 * @brief   Sets device memory
 *
 * @param   pDeviceMem      [in] Pointer to device memory
 * @param   value           [in] Value to set
 * @param   numOfElements   [in] Number of elements
 * @param   streamHandle    [in] Stream to enqueue operation to
 * @return                  Status of the operation
 ***************************************************************************************************
 */
synStatus SYN_API_CALL synMemsetD32Async( uint64_t                 pDeviceMem,
                                          const uint32_t           value,
                                          const size_t             numOfElements,
                                          const synStreamHandle    streamHandle );

//!
/*!
 ***************************************************************************************************
 * @brief   Sets device memory
 *
 * @param   pDeviceMem      [in] Pointer to device memory
 * @param   value           [in] Value to set
 * @param   numOfElements   [in] Number of elements
 * @param   streamHandle    [in] Stream identifier
 *
 * @return                  Status of the operation
 ***************************************************************************************************
 */
synStatus SYN_API_CALL synMemsetD8Async( uint64_t                 pDeviceMem,
                                         const unsigned char      value,
                                         const size_t             numOfElements,
                                         const synStreamHandle    streamHandle );

//!
/*!
 ***************************************************************************************************
 * @brief   Sets device memory4
 *
 * @param   pDeviceMem      [in] Pointer to device memory
 * @param   value           [in] Value to set
 * @param   numOfElements               [in] Number of elements
 * @param   streamHandle    [in] Stream identifier
 *
 * @return                  Status of the operation
 ***************************************************************************************************
 */
synStatus SYN_API_CALL synMemsetD16Async( uint64_t                 pDeviceMem,
                                          const uint16_t           value,
                                          const size_t             numOfElements,
                                          const synStreamHandle    streamHandle );

//!
/*!
 ***************************************************************************************************
 *   @brief Creates a memory allocation on the host and maps it in the device's MMU
 *
 *   @param deviceId        [in]  The device id for resource creation.
 *   @param size            [in]  Size of the created buffer in bytes.
 *   @param flags           [in]  flags for the operation. should be zero
 *   @param buffer          [out] A pointer to the newly created buffer.
 *
 *   @return                The status of the operation
 ***************************************************************************************************
 */
synStatus SYN_API_CALL synHostMalloc( const synDeviceId      deviceId,
                                      const uint64_t         size,
                                      const uint32_t         flags,
                                      void**                 buffer );

/*!
 ***************************************************************************************************
 *   @brief Deletes a memory allocation on the host
 *
 *   @param deviceId        [in]  The device id for resource manipulation.
 *   @param buffer          [in]  A pointer to the buffer to be deleted
 *   @param flags           [in]  flags for the operation. should be zero
 *
 *   @return                The status of the operation
 ***************************************************************************************************
 */
synStatus SYN_API_CALL synHostFree( const synDeviceId    deviceId,
                                    const void*          buffer,
                                    const uint32_t       flags );

//!
/*!
 ***************************************************************************************************
 *   @brief Maps a given buffer (allocated by the user on the host) to a memory-allocation of a
 *   specific device
 *
 *   @param deviceId        [in]  The device id for resource mapping.
 *   @param size            [in]  Size in bytes, of the buffer to be mapped.
 *   @param buffer          [in] A pointer to the buffer requested to be mapped.
 *
 *   @return                The status of the operation
 ***************************************************************************************************
 */
synStatus SYN_API_CALL synHostMap( const synDeviceId          deviceId,
                                   const uint64_t             size,
                                   const void*                buffer );

//!
/*!
 ***************************************************************************************************
 *   @brief Un-map a host memory allocation
 *
 *   @param deviceId        [in]  The device id for resource creation.
 *   @param buffer          [in]  A pointer to the buffer to be unmapped
 *
 *   @return                The status of the operation.
 ***************************************************************************************************
 */
synStatus SYN_API_CALL synHostUnmap( const synDeviceId    deviceId,
                                     const void*          buffer );

//!
/*!
 ***************************************************************************************************
 *   @brief Creates a memory allocation on a specific device
 *
 *   @param deviceId        [in]  The device id for resource creation.
 *   @param size            [in]  Size of the created buffer in bytes.
 *   @param reqAddr         [in]  The requested address of the buffer that is allocated. This request
 *                                  serves as a hint. Synapse is not required to provide the given
 *                                  address as the malloc result. User is required to check what is
 *                                  the actual address that synapse provided by inspecting the content
 *                                  of 'buffer' argument.
 *                                  Malloc will succeed regardless if Synapse can or can't provide the requested address.
 *                                  Setting reqAddr = 0 implies that the user is indifferent to the address
 *                                  provided.
 *                                  Its the user responsibility to ask for an 128 bytes aligned address.
 *   @param flags           [in]  flags for the operation. should be zero
 *   @param buffer          [out] A pointer to the newly created buffer.
 *
 *   @return                The status of the operation
 ***************************************************************************************************
 */
synStatus SYN_API_CALL synDeviceMalloc( const synDeviceId    deviceId,
                                        const uint64_t       size,
                                        uint64_t             reqAddr,
                                        const uint32_t       flags,
                                        uint64_t*            buffer );

//!
/*!
 ***************************************************************************************************
 *   @brief Deletes a memory allocation on the device
 *
 *   @param deviceId        [in]  The device id for resource manipulation.
 *   @param buffer          [in]  A pointer to the buffer to be deleted
 *   @param flags           [in]  flags for the operation. should be zero
 *
 *   @return                The status of the operation
 ***************************************************************************************************
 */
synStatus SYN_API_CALL synDeviceFree( const synDeviceId     deviceId,
                                      const uint64_t        buffer,
                                      const uint32_t        flags );

//!
/*!
 ***************************************************************************************************
 * @brief Initiate synapse instance
 *
 *   @return                        The status of the operation
 ***************************************************************************************************
 */
synStatus SYN_API_CALL synInitialize();

//!
/*!
 ***************************************************************************************************
 *   @brief Destroy the synapse instance
 *
 *   @return                    The status of the operation
 ***************************************************************************************************
 */
synStatus SYN_API_CALL synDestroy();

//!
/*!
 ***************************************************************************************************
 *   @brief Release a device (and destroy and data allocated for it)
 *
 *   @param deviceId            [in] The device-id requested to be released.
 *
 *   @return                    The status of the operation
 ***************************************************************************************************
 */
synStatus SYN_API_CALL synDeviceRelease( const synDeviceId deviceId );

//!
/*!
 ***************************************************************************************************
 *   @brief Return the free and total memory on a specific device
 *
 *   @param deviceId    [in]  The device id the memory info is asked for
 *   @param free        [out] Free memory available
 *   @param total       [out] Total memory on device
 *
 *   @return                  The status of the operation
 ***************************************************************************************************
 */
synStatus SYN_API_CALL synDeviceGetMemoryInfo( const synDeviceId    deviceId,
                                               uint64_t*            free,
                                               uint64_t*            total );

//!
/*!
 ***************************************************************************************************
 * @brief   Get the Synapse's Device-Info
 *
 * @param   deviceId        [in]  The inquired (user's) ID of the device
 * @param   pDeviceInfo     [out] The requested Device-Info
 *
 * @return                  Status of the operation
 ***************************************************************************************************
 */
synStatus SYN_API_CALL synDeviceGetInfo( const synDeviceId      deviceId,
                                         synDeviceInfo*         pDeviceInfo );

//!
/*!
 ***************************************************************************************************
 * @brief   Query the given device attributes
 *
 * @param   retVal          [out] Returned array of value of requested attributes
 * @param   deviceAttr      [in]  Array of attributes to query of type synDeviceAttribute
 * @param   querySize       [in]  Size of array of attributes to query (and of the retVal array)
 * @param   deviceId        [in]  The inquired (user's) ID of the device
 *
 * @return                  Status of the operation
 ***************************************************************************************************
 */
synStatus SYN_API_CALL synDeviceGetAttribute( uint64_t*                 retVal,
                                              const synDeviceAttribute* deviceAttr,
                                              const unsigned            querySize,
                                              const synDeviceId         deviceId);

/*!
 ***************************************************************************************************
 * @brief Get the Synapse's Device Attribute according to Device Type
 *
 * @param retVal     [out] Returned array of value of requested attributes
 * @param deviceAttr [in] Array of attributes to query of type synDeviceAttribute
 * @param querySize  [in] Size of array of attributes to query (and of the retVal array)
 * @param deviceType [in] The inquired device type
 *
 * @return Status of the operation
 ***************************************************************************************************
 */
synStatus SYN_API_CALL synDeviceTypeGetAttribute( uint64_t*                 retVal,
                                                  const synDeviceAttribute* deviceAttr,
                                                  const unsigned            querySize,
                                                  const synDeviceType       deviceType);

//!
/*!
 ***************************************************************************************************
 * @brief   Set a Synapse configuration parameter
 *
 * @param   configurationName        [in]  The config parameter name
 * @param   configurationValue       [in]  The requested value to be set
 *
 * @return                  Status of the operation
 ***************************************************************************************************
 */
synStatus SYN_API_CALL synConfigurationSet(const char*          configurationName,
                                           const char*          configurationValue);

//!
/*!
 ***************************************************************************************************
 * @brief   Get the value of a Synapse configuration parameter
 *
 * @param   configurationName        [in]  The config parameter name
 * @param   configurationValue      [Out]  The requested value to be set
 * @param   size                     [in]  configurationValue buffer size
 *
 * @return                  Status of the operation
 ***************************************************************************************************
 */
synStatus SYN_API_CALL synConfigurationGet(const char*          configurationName,
                                           char*                configurationValue,
                                           uint64_t             size);


//!
/*!
 ***************************************************************************************************
 * @brief   Begins profiling session using on-device instrumentation
 *
 * @param   type              [in]  The requested type of trace
 * @param   deviceId          [in]  The inquired (user's) ID of the device (set to 0 for host trace)
 *
 * @return                  Status of the operation
 ***************************************************************************************************
 */
synStatus SYN_API_CALL synProfilerStart( const synTraceType        type,
                                         const synDeviceId         deviceId );

//!
/*!
 ***************************************************************************************************
 * @brief   Ends profiling session and saves output to file(s)
 *
 * @param   type              [in]  The requested type of trace
 * @param   deviceId          [in]  The inquired (user's) ID of the device (set to 0 for host trace)
 *
 * @return                  Status of the operation
 ***************************************************************************************************
 */
synStatus SYN_API_CALL synProfilerStop( const synTraceType      type,
                                        const synDeviceId       deviceId );

//!
/*!
 ***************************************************************************************************
 * @brief   Retrieve the trace buffer from memory
 *
 * @param   type        [in] The requested type of trace to retrieve (device or host)
 * @param   deviceId    [in] The inquired (user's) ID of the device (ignored for host trace)
 * @param   format      [in] The requested format of the trace data
 * @param   buffer      [in/out] Pointer to user allocated memory to contain the requested buffer.
 *                            If null, only size and numEntries will be returned.
 *                            The ruturned buffer is built in the following format:
 *                            [synTraceEvent enries][chars][size_t num][size_t version]
 *                            num: Amount of synTraceEvent entries
 *                            version: Synprof parser version
 * @param   size        [in/out] Input is the size of the allocated buffer in bytes, output is
 *                              the actual amount of trace data copied to buffer. If buffer is null,
 *                              the size of the entire trace buffer (including the chars array) is
 *                              returned. If null, the trace buffer will be written to the file
 *                              system in the requested format.
 * @param   numEntries  [out] Actual amount of synTraceEvent entries copied to buffer, or the total
 *                            amount of synTraceEvent entries in the trace buffer if buffer is null.
 *
 * @return              The status of the operation
 ***************************************************************************************************
 */
synStatus SYN_API_CALL synProfilerGetTrace( const synTraceType      type,
                                            const synDeviceId       deviceId,
                                            const synTraceFormat    format,
                                            void*                   buffer,
                                            size_t*                 size,
                                            size_t*                 numEntries);

//!
/*!
 ***************************************************************************************************
 *   @brief Create an empty tensor handle.
 *
 *   The tensor is coupled with a graph.
 *   The tensor name may be omitted, in which case a default naming of Tensor_XXX will be generated.
 *   The tensor name must not be duplicated in other tensors within the graph.
 *
 *   After creating the empty tensor handle please use other tensor APIs to set properties
 *   for this tensor, according to your requirements:
 *   -  synTensorAssignToSection
 *   -  synTensorSetHostPtr
 *   -  synTensorSetGeometry
 *   -  synTensorSetDeviceLayout
 *   -  synTensorSetQuantizationData
 *
 *   @param tensor            [out] A pointer to the created tensor handle.
 *   @param graph             [in]  A previously-created graph handle in which to create the tensor.
 *   @param type              [in]  The tensor classification in the graph.
 *   @param tensorName        [in]  The tensor's name - may be omitted (null or empty string).
 *
 *   @return                  The status of the operation
 ***************************************************************************************************
 */
synStatus SYN_API_CALL synTensorHandleCreate(synTensor*               tensor,
                                             synGraphHandle           graph,
                                             synTensorType            type,
                                             const char*              tensorName);

//!
/*!
 ***************************************************************************************************
 *   @brief Assign a tensor to memory section and offset.
 *
 *   This API assigns a tensor to a previously-created section.
 *   Tensors for which no section was assigned reside in the workspace.
 *   section was returned from a previous successful call to synSectionCreate.
 *
 *   This API cannot be used with synTensorSetHostPtr on the same tensor - the tensor
 *   can either have a host pointer or assigned a section.
 *
 *   @param tensor            [in] A previously-created tensor handle.
 *   @param section           [in] A previously-created section handle.
 *   @param byteOffset        [in] An offset in which the tensor resides within the section.
 *
 *   @return                  The status of the operation
 ***************************************************************************************************
 */
synStatus SYN_API_CALL synTensorAssignToSection(synTensor           tensor,
                                                synSectionHandle    section,
                                                uint64_t            byteOffset);

//!
/*!
 ***************************************************************************************************
 *   @brief Sets a host buffer to the tensor.
 *
 *   This API sets the tensor as const (containing static data, such as weights or an embedding
 *   table).
 *   Unless copyBuffer is true, the data pointed to by hostPtr must not be released until the
 *   tensor is destroyed.
 *   The dataType must be equal to the device data type set in synTensorSetDeviceLayout.
 *
 *   In inference graphs, the dataType may be different from the device data type if it is FP32.
 *   In addition, for inference graphs, the contents of the host-side data will be interpreted
 *   according to the quantization information for this data type supplied by synTensorSetQuantizationData.
 *
 *   This API cannot be used with synTensorAssignToSection on the same tensor - the tensor
 *   can either have a host pointer or assigned a section.
 *
 *   @param tensor            [in] A previously-created tensor handle.
 *   @param hostPtr           [in] A pointer to the host buffer.
 *   @param size              [in] The buffer size in bytes.
 *   @param dataType          [in] The buffer data type.
 *   @param copyBuffer        [in] Whether to copy buffer content to the tensor (if false - use the host pointer).
 *
 *   @return                  The status of the operation
 ***************************************************************************************************
 */
synStatus SYN_API_CALL synTensorSetHostPtr(synTensor            tensor,
                                           void*                hostPtr,
                                           uint64_t             size,
                                           synDataType          dataType,
                                           bool                 copyBuffer);

//!
/*!
 ***************************************************************************************************
 *   @brief Sets quantization parameters to tensor.
 *
 *   This API sets the quantization metadata specified by prop based on the data in propVal.
 *   No more than propSize bytes will be read from propVal.
 *   Legal values to prop: SYN_QUANT_DYNAMIC_RANGE, SYN_QUANT_METADATA, SYN_QUANT_FLAGS
 *
 *   For SYN_QUANT_DYNAMIC_RANGE, propVal should point to a synQuantDynamicRange struct to define
 *   the dynamic range of the tensor data. From the dynamic range, the quantization information of
 *   the tensor will be automatically calculated by the graph compiler.
 *
 *   For SYN_QUANT_METADATA, propVal should point to a synQuantMetadata struct to define the
 *   quantization information of the tensor for a specific data type - instead of relying on the
 *   automatic calculation done in the GC from the dynamic range. This prop can be called multiple
 *   times - once for each data type that quantization info should be set for.
 *   synQuantMetadata contains a pointer to an array of synQuantZPScale (zero point and scale).
 *   The size of this array is noted in numZPScales: if numZPScales is set to 1, the values are used
 *   for all channels in the specified tensor for that data type. Otherwise, it must equal the number
 *   of the channels in the tensor and indicates per-channel quantization for tensors that support it.
 *
 *   For SYN_QUANT_FLAGS, propVal should point to a synQuantFlags struct to define some quantization
 *   attributes of the tensor, to affect GC's automatic calculation of the quantization, mainly for
 *   MME weight tensors:
 *   - enablePerChannelQuant - calculate the zp and scale per channel, in tensors that support it.
 *   - isSparsifiedWeights -   mark the weights as sparse, and force the zp to be 0.
 *
 *   @param tensor            [in] A previously-created tensor handle.
 *   @param prop              [in] The quantization property indicator
 *   @param propVal           [in] A pointer to user-allocated struct that matches prop
 *   @param propSize          [in] Size in bytes of propVal struct..
 *
 *   @return                  The status of the operation
 ***************************************************************************************************
 */
synStatus SYN_API_CALL synTensorSetQuantizationData(synTensor               tensor,
                                                    synQuantizationProperty prop,
                                                    void*                   propVal,
                                                    uint64_t                propSize);

//!
/*!
 ***************************************************************************************************
 *   @brief Sets shape and dimension to tensor.
 *
 *   Set geometry according to geometryType.
 *   Legal values to geometryType: synGeometryMinSizes, synGeometryMaxSizes, synGeometrySizes.
 *   If only one of synGeometryMinSizes or synGeometryMaxSizes is specified, the other is assumed
 *   to be identical (the same as using synGeometrySizes).
 *
 *   @param tensor            [in] A previously-created tensor handle.
 *   @param geometry          [in] A pointer to the synTensorGeometry struct.
 *   @param geometryType      [in] Specify if Minimum or Maximum sizes.
 *
 *   @return                  The status of the operation
 ***************************************************************************************************
 */
synStatus SYN_API_CALL synTensorSetGeometry(synTensor                   tensor,
                                            const synTensorGeometry*    geometry,
                                            synGeometryType             geometryType);


//!
/*!
 ***************************************************************************************************
 *   @brief Sets device data type and strides.
 *
 *   Set the desired data type of the tensor in the device.
 *
 *   In inference graphs, a buffer provided by synTensorSetHostPtr will be quantized to the device
 *   data type, if is different from the buffer data type given in that API.
 *
 *   In the future this API can also be used to set the strides of a tensors, but currently only
 *   default strides are allowed.
 *   If the given strides are empty (zeros) then they will be calculated inside the tensor according
 *   to its geometry.
 *
 *   @param tensor            [in] A previously-created tensor handle.
 *   @param layout            [in] A pointer to the synTensorDeviceLayout struct.
 *
 *   @return                  The status of the operation
 ***************************************************************************************************
 */
synStatus SYN_API_CALL synTensorSetDeviceLayout(synTensor                    tensor,
                                                const synTensorDeviceLayout* layout);


//!
/*!
 ***************************************************************************************************
 *   @brief Query a tensor's memory section.
 *
 *   This API returns the tensor's section handle and offset.
 *   For tensors without a section, null and 0 will be returned in section and byteOffset, respectively.
 *
 *   @param tensor            [in]   A previously-created tensor handle
 *   @param section           [out]  The section handle allocated by the user
 *   @param byteOffset        [out]  The offset within the section
 *
 *   @return                  The status of the operation
 ***************************************************************************************************
 */
synStatus SYN_API_CALL synTensorGetSection(synTensor           tensor,
                                           synSectionHandle*   section,
                                           uint64_t*           byteOffset);

//!
/*!
 ***************************************************************************************************
 *   @brief Query a tensor's host buffer.
 *
 *   This API returns the tensor's host buffer's pointer, size and data type.
 *   The tensor host buffer contains the tensor's static data.
 *   The data pointed to by hostPtr must not be released until the tensor is destroyed.
 *   Modifying the data pointed by hostPtr will modify the actual tensor data,
 *   and shouldn't be done after compiling the graph.
 *
 *   @param tensor            [in]   A previously-created tensor handle
 *   @param hostPtr           [out]  The host buffer pointer
 *   @param size              [out]  The buffer size in bytes
 *   @param dataType          [out]  The buffer data type
 *
 *   @return                  The status of the operation
 ***************************************************************************************************
 */
synStatus SYN_API_CALL synTensorGetHostPtr(synTensor            tensor,
                                           void**               hostPtr,
                                           uint64_t*            size,
                                           synDataType*         dataType);

//!
/*!
 ***************************************************************************************************
 *   @brief Query a tensor's quantization parameters.
 *
 *   This API returns the tensor's quantization properties.
 *   The quantization property type is determined by the prop argument.
 *   Legal values to prop: SYN_QUANT_DYNAMIC_RANGE, SYN_QUANT_METADATA, SYN_QUANT_FLAGS
 *   The tensor's quantization property will be stored in a user-allocated struct pointed by propVal argument.
 *
 *   For SYN_QUANT_DYNAMIC_RANGE, propVal should point to a synQuantDynamicRange struct,
 *   which will be filled by the API.
 *
 *   For SYN_QUANT_METADATA, propVal should point to a synQuantMetadata struct with a specific data type.
 *   The struct contains an array of synQuantZPScale structs which should be allocated by the user.
 *   In case the array is null, the returned struct will contain the channels number.
 *   In case the array isn't null, it's assumed allocated, and the returned struct will contain also the synQuantZPScale array.
 *   The required allocation size is calculated as follows : number of tensor channels * sizeof(synQuantZPScale)
 *
 *   For SYN_QUANT_FLAGS, propVal should point to a synQuantFlags struct which will be filled by the API.
 *
 *   The size of the property struct should be passed for validation. For SYN_QUANT_METADATA,
 *   in case the synQuantZPScale array is null, the size of synQuantMetadata should be passed.
 *   In case the array is allocated, the size of the allocated array plus the size of synQuantMetadata should be passed.
 *
 *   @param tensor            [in]   A previously-created tensor handle
 *   @param prop              [in]   The quantization property indicator
 *   @param propVal           [out]  A pointer to user-allocated struct that matches prop
 *   @param propSize          [in]   Size in bytes of propVal struct
 *
 *   @return                  The status of the operation
 ***************************************************************************************************
 */
synStatus SYN_API_CALL synTensorGetQuantizationData(synTensor               tensor,
                                                    synQuantizationProperty prop,
                                                    void*                   propVal,
                                                    uint64_t                propSize);

//!
/*!
 ***************************************************************************************************
 *   @brief Query tensor shape and dimension.
 *
 *   Geometry property will be returned in user-allocated buffer.
 *
 *   @param tensor            [in]   A previously-created tensor handle
 *   @param geometry          [out]  A pointer to the synTensorGeometry struct
 *   @param geometryType      [in]   Type of the geometry to be queried
 *
 *   @return                  The status of the operation
 ***************************************************************************************************
 */
synStatus SYN_API_CALL synTensorGetGeometry(const synTensor         tensor,
                                            synTensorGeometry*      geometry,
                                            synGeometryType         geometryType);

//!
/*!
 ***************************************************************************************************
 *   @brief Query tensor device data type and strides.
 *
 *   Device layout property will be returned in user-allocated buffer.
 *
 *   @param tensor            [in]   A previously-created tensor handle
 *   @param layout            [out]  A pointer to the synTensorDeviceLayout struct.
 *
 *   @return                  The status of the operation
 ***************************************************************************************************
 */
synStatus SYN_API_CALL synTensorGetDeviceLayout(const synTensor         tensor,
                                                synTensorDeviceLayout*  layout);


//!
/*!
 ***************************************************************************************************
 *   @brief Query tensor name.
 *
 *   Name will be returned in user-allocated buffer.
 *
 *   @param tensor            [in]   A previously-created tensor handle
 *   @param size              [in]   Size in bytes of user allocated buffer
 *   @param name              [out]  Pointer to user-allocated buffer
 *
 *   @return                  The status of the operation
 ***************************************************************************************************
 */
synStatus SYN_API_CALL synTensorGetName(const synTensor   tensor,
                                        const uint64_t    size,
                                        char*             name);

// clang-format on

#ifdef __cplusplus
}

#endif

#endif //SYNAPSE_API_H
