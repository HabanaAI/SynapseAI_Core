/* SPDX-License-Identifier: MIT
 *
 * Copyright 2017-2021 HabanaLabs, Ltd.
 * All Rights Reserved.
 *
 */

#ifndef TPC_KERNELS_TPCELFREADER_H
#define TPC_KERNELS_TPCELFREADER_H

#include "tpc_elf_api.hpp"
#include "elfio/elfio.hpp"

using namespace ELFIO;

TpcElfTools::TpcElfStatus ExtractTpcBinaryFromElfBySection( const void *pElf,
                                                            uint32_t elfSize,
                                                            void *&pTpcBinary,
                                                            uint32_t &tpcBinarySize,
                                                            std::string sectionName);

#endif //TPC_KERNELS_TPCELFREADER_H
