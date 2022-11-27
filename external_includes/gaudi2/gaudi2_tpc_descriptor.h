#ifndef _GAUDI2_TPC_DESC_H_
#define _GAUDI2_TPC_DESC_H_

#include <stdint.h>

#include "asic_reg/gaudi2_blocks.h"
#include "asic_reg_structs/tpc_regs.h"

#pragma pack(push, 4)
namespace gaudi2 
{
struct Gaudi2TpcDesc
{
    static const int c_max_tensor_dims = 5;
    static const int c_max_tensors_nr = 16;

    gaudi2::block_tpc_tensor                m_tensors[c_max_tensors_nr];
    gaudi2::block_sync_object               m_so;
    gaudi2::block_tpc_non_tensor_descriptor m_desc;
};
} // namespace gaudi2
#pragma pack(pop)
#endif // _GAUDI2_TPC_DESC_H_
