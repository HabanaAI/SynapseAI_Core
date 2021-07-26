#ifndef _GAUDI_TPC_DESC_H_
#define _GAUDI_TPC_DESC_H_

/* SPDX-License-Identifier: MIT
 *
 * Copyright 2016-2021 HabanaLabs, Ltd.
 * All Rights Reserved.
 *
 */

#include <stdint.h>

#include "asic_reg/gaudi_blocks.h"
#include "asic_reg_structs/tpc_regs.h"

#pragma pack(push, 4)

struct GaudiTpcDesc
{
    static const int c_max_tensor_dims = 5;
    static const int c_max_tensors_nr = 16;

    block_tpc_tensor                m_tensors[c_max_tensors_nr];
    block_sync_object               m_so;
    block_tpc_non_tensor_descriptor m_desc;
};

#pragma pack(pop)
#endif // _GAUDI_TPC_DESC_H_
