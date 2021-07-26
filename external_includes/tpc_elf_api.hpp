/* SPDX-License-Identifier: MIT
 *
 * Copyright 2016-2021 HabanaLabs, Ltd.
 * All Rights Reserved.
 *
 */

#ifndef TPC_ELF_API_HPP
#define TPC_ELF_API_HPP

#include <gc_interface.h>

extern "C"{
namespace TpcElfTools
{

enum TpcElfStatus
{
    TPC_ELF_SUCCESS                            = 0,
    TPC_ELF_INVALID_ELF_BUFFER                 = 1,
    TPC_ELF_SECTION_NOT_FOUND                  = 2,
    TPC_ELF_UNSUPPORTED                        = 3,
    TPC_ELF_INDEXSPACE_ERROR                   = 4,
    TPC_ELF_INVALID_BUFFER                     = 5
} ;

enum TPCArch {
  Unknown,
  Goya   = 1,
  Gaudi  = 2,
};

enum SCEVStatusMassage{
    SCEVSuccess =      0,
    GC_CUSTOM_MODE = 1,                    // SCEV is in GC_CUSTOM mode.
    SCEVEmpty =        6,                  // SCEV is empty
    IdGreaterThenNumTensor = 7,            // The indexSpace tensor ID is gather then available tensor in target
    DimSmallerThenZero  = 8,               // At lest one of the indexes is negative number
    //AllZero = 9,                         // One of the dimension is set to all to zero
    TrySetAuxTensor = 10,                  // Setting an auxiliary tensor
    NumberOfDimIsGreaterThen5=11           // Glue code error: params tensor.geometry.dims is higher then 5

};

struct TPCProgramHeader
{
    uint32_t    version;                // version of header
    bool        specialFunctionUsed;
    bool        printfUsed;
    bool        lockUnlock;
    bool        mmioUse;
    TPCArch     march;
    bool        reserved_temp[14];
    uint16_t    scalarLoad;
    uint16_t    rmwStore;              // RMW store is a bitmask indicates if the tensor has RMW store operation or not
                                       // The most significant bit indicate tensor ID 15.
                                       // For example 0b0100 --> tensor id 2 has RMW indication.
    uint32_t    reserved[58];
} ;
/*!
 ***************************************************************************************************
 *   @brief Returns pointer and size of TPC binary from elf buffer
 *
 *   @param pElf            [in]    pointer to elf buffer
 *   @param size            [in]    size of elf buffer
 *   @param pTpcBinary      [out]   Returned pointer to TPC binary on elf buffer
 *   @param tpcBinarySize   [out]   Returned size to TPC binary
 *
 *   @return                  The status of the operation
 ***************************************************************************************************
 */
TpcElfStatus ExtractTpcBinaryFromElf(   const void*  pElf,
                                        uint32_t     elfSize,
                                        void*&       pTpcBinary,
                                        uint32_t&    tpcBinarySize);



/*!
 ***************************************************************************************************
 *   @brief Returns TPC program header from elf buffer
 *
 *   @param pElf            [in]    Pointer to elf buffer
 *   @param size            [in]    Size of elf buffer
 *   @param programHeader   [out]   program header structure.
 *
 *   @return                  The status of the operation
 ***************************************************************************************************
 */
TpcElfStatus ExtractTpcProgramHeaderFromElf(    const void*     pElf,
                                                uint32_t        elfSize,
                                                TPCProgramHeader&  programHeader);


/*!
 ***************************************************************************************************
 *   @brief retrieve kernel name
 *
 *   @param params        [in]    kernel instantiation struct which holds the elf buffer.
 *   @param kernelISA     [out]   kernel name
 *
 *   @return                  The status of the operation
 ***************************************************************************************************
 */
TpcElfStatus GetTpcKernelISAName(  gcapi::HabanaKernelInstantiation_t *instance,
                                   _OUT_   char*    kernelISA,  unsigned* nameSize);


} // end of TpcElfTools
}
#endif /* TPC_ELF_API_HPP */
