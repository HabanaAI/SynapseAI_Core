/* SPDX-License-Identifier: MIT
 *
 * Copyright 2016-2021 HabanaLabs, Ltd.
 * All Rights Reserved.
 *
 */

#include "gaudi_packet_gen.h"
#include "gaudi_packets.h"

unsigned CPCommand::NopGen2::GetSize() const { return sizeof(packet_nop); }
unsigned CPCommand::StopGen2::GetSize() const { return sizeof(packet_stop); }
unsigned CPCommand::WReg32Gen2::GetSize() const { return sizeof(packet_wreg32); }
unsigned CPCommand::WRegBulkGen2::GetSize() const
{
    return sizeof(packet_wreg_bulk) + (m_numValues * sizeof(uint64_t));
}
unsigned CPCommand::MsgLongGen2::GetSize() const { return sizeof(packet_msg_long); }
unsigned CPCommand::MsgShortGen2::GetSize() const { return sizeof(packet_msg_short); }
unsigned CPCommand::MsgProtGen2::GetSize() const { return sizeof(packet_msg_prot); }
unsigned CPCommand::FenceGen2::GetSize() const { return sizeof(packet_fence); }
unsigned CPCommand::LinDmaGen2::GetSize() const { return sizeof(packet_lin_dma); }
unsigned CPCommand::RepeatGen2::GetSize() const { return sizeof(packet_repeat); }
unsigned CPCommand::WaitGen2::GetSize() const { return sizeof(packet_wait); }
unsigned CPCommand::LoadAndExecGen2::GetSize() const { return sizeof(packet_load_and_exe); }
unsigned CPCommand::CpDmaGen2::GetSize() const { return sizeof(packet_cp_dma); }
unsigned CPCommand::ArbPointGen2::GetSize() const { return sizeof(packet_arb_point); }

CPCommand::Command* CPCommand::NopGen2::Clone() const { return new NopGen2(*this); }
CPCommand::Command* CPCommand::StopGen2::Clone() const { return new StopGen2(*this); }
CPCommand::Command* CPCommand::WReg32Gen2::Clone() const { return new WReg32Gen2(*this); }
CPCommand::Command* CPCommand::WRegBulkGen2::Clone() const { return new WRegBulkGen2(*this); }
CPCommand::Command* CPCommand::MsgLongGen2::Clone() const { return new MsgLongGen2(*this); }
CPCommand::Command* CPCommand::MsgShortGen2::Clone() const { return new MsgShortGen2(*this); }
CPCommand::Command* CPCommand::MsgProtGen2::Clone() const { return new MsgProtGen2(*this); }
CPCommand::Command* CPCommand::FenceGen2::Clone() const { return new FenceGen2(*this); }
CPCommand::Command* CPCommand::LinDmaGen2::Clone() const { return new LinDmaGen2(*this); }
CPCommand::Command* CPCommand::RepeatGen2::Clone() const { return new RepeatGen2(*this); }
CPCommand::Command* CPCommand::WaitGen2::Clone() const { return new WaitGen2(*this); }
CPCommand::Command* CPCommand::LoadAndExecGen2::Clone() const { return new LoadAndExecGen2(*this); }
CPCommand::Command* CPCommand::CpDmaGen2::Clone() const { return new CpDmaGen2(*this); }
CPCommand::Command* CPCommand::ArbPointGen2::Clone() const { return new ArbPointGen2(*this); }

void CPCommand::NopGen2::Serialize(void** buff) const
{
    memset(*buff, 0, sizeof(packet_nop));
    ((packet_nop*)(*buff))->opcode      = PACKET_NOP;
    ((packet_nop*)(*buff))->eng_barrier = m_eb;
    ((packet_nop*)(*buff))->reg_barrier = m_rb;
    ((packet_nop*)(*buff))->msg_barrier = m_mb;
    (*(uint8_t**)buff) += GetSize();
}

void CPCommand::StopGen2::Serialize(void** buff) const
{
    memset(*buff, 0, sizeof(packet_stop));
    ((packet_stop*)(*buff))->opcode      = PACKET_STOP;
    ((packet_stop*)(*buff))->eng_barrier = m_eb;
    ((packet_stop*)(*buff))->reg_barrier = m_rb;
    ((packet_stop*)(*buff))->msg_barrier = m_mb;
    (*(uint8_t**)buff) += GetSize();
}

void CPCommand::WReg32Gen2::Serialize(void** buff) const
{
    memset(*buff, 0, sizeof(packet_wreg32));
    ((packet_wreg32*)(*buff))->opcode      = PACKET_WREG_32;
    ((packet_wreg32*)(*buff))->eng_barrier = m_eb;
    ((packet_wreg32*)(*buff))->reg_barrier = 1;
    ((packet_wreg32*)(*buff))->msg_barrier = m_mb;
    ((packet_wreg32*)(*buff))->pred        = m_pred;
    ((packet_wreg32*)(*buff))->reg_offset  = m_offset;
    ((packet_wreg32*)(*buff))->value       = m_value;
    (*(uint8_t**)buff) += GetSize();
}

void CPCommand::WRegBulkGen2::Serialize(void** buff) const
{
    memset(*buff, 0, sizeof(packet_wreg_bulk));
    ((packet_wreg_bulk*)(*buff))->opcode      = PACKET_WREG_BULK;
    ((packet_wreg_bulk*)(*buff))->eng_barrier = m_eb;
    ((packet_wreg_bulk*)(*buff))->reg_barrier = 1;
    ((packet_wreg_bulk*)(*buff))->msg_barrier = m_mb;
    ((packet_wreg_bulk*)(*buff))->size64      = m_numValues;
    ((packet_wreg_bulk*)(*buff))->pred        = m_pred;
    ((packet_wreg_bulk*)(*buff))->reg_offset  = m_offset;
    memcpy(((packet_wreg_bulk*)(*buff))->values, m_values, m_numValues * sizeof(uint64_t));
    (*(uint8_t**)buff) += GetSize();
}

void CPCommand::MsgLongGen2::Serialize(void** buff) const
{
    memset(*buff, 0, sizeof(packet_msg_long));
    ((packet_msg_long*)(*buff))->opcode         = PACKET_MSG_LONG;
    ((packet_msg_long*)(*buff))->eng_barrier    = m_eb;
    ((packet_msg_long*)(*buff))->reg_barrier    = m_rb;
    ((packet_msg_long*)(*buff))->msg_barrier    = m_mb;
    ((packet_msg_long*)(*buff))->pred           = m_pred;
    ((packet_msg_long*)(*buff))->weakly_ordered = m_weaklyOrdered;
    ((packet_msg_long*)(*buff))->no_snoop       = m_noSnoop;
    ((packet_msg_long*)(*buff))->op             = m_op;
    ((packet_msg_long*)(*buff))->value          = m_value;
    ((packet_msg_long*)(*buff))->addr           = m_addr;
    (*(uint8_t**)buff) += GetSize();
}

void CPCommand::MsgShortGen2::Serialize(void** buff) const
{
    memset(*buff, 0, sizeof(packet_msg_short));
    ((packet_msg_short*)(*buff))->opcode          = PACKET_MSG_SHORT;
    ((packet_msg_short*)(*buff))->eng_barrier     = m_eb;
    ((packet_msg_short*)(*buff))->reg_barrier     = m_rb;
    ((packet_msg_short*)(*buff))->msg_barrier     = m_mb;
    ((packet_msg_short*)(*buff))->msg_addr_offset = m_offset;
    ((packet_msg_short*)(*buff))->weakly_ordered  = m_weaklyOrdered;
    ((packet_msg_short*)(*buff))->no_snoop        = m_noSnoop;
    ((packet_msg_short*)(*buff))->op              = m_op;
    ((packet_msg_short*)(*buff))->value           = m_value;
    (*(uint8_t**)buff) += GetSize();
}

void CPCommand::MsgProtGen2::Serialize(void** buff) const
{
    memset(*buff, 0, sizeof(packet_msg_prot));
    ((packet_msg_prot*)(*buff))->opcode         = PACKET_MSG_PROT;
    ((packet_msg_prot*)(*buff))->eng_barrier    = m_eb;
    ((packet_msg_prot*)(*buff))->reg_barrier    = m_rb;
    ((packet_msg_prot*)(*buff))->msg_barrier    = m_mb;
    ((packet_msg_prot*)(*buff))->pred           = m_pred;
    ((packet_msg_prot*)(*buff))->weakly_ordered = m_weaklyOrdered;
    ((packet_msg_prot*)(*buff))->no_snoop       = m_noSnoop;
    ((packet_msg_prot*)(*buff))->op             = m_op;
    ((packet_msg_prot*)(*buff))->value          = m_value;
    ((packet_msg_prot*)(*buff))->addr           = m_addr;
    (*(uint8_t**)buff) += GetSize();
}

void CPCommand::FenceGen2::Serialize(void** buff) const
{
    memset(*buff, 0, sizeof(packet_fence));
    ((packet_fence*)(*buff))->opcode      = PACKET_FENCE;
    ((packet_fence*)(*buff))->eng_barrier = m_eb;
    ((packet_fence*)(*buff))->reg_barrier = m_rb;
    ((packet_fence*)(*buff))->msg_barrier = m_mb;
    ((packet_fence*)(*buff))->pred        = m_pred;
    ((packet_fence*)(*buff))->dec_val     = m_decVal;
    ((packet_fence*)(*buff))->target_val  = m_targetVal;
    ((packet_fence*)(*buff))->id          = m_id;
    (*(uint8_t**)buff) += GetSize();
}

void CPCommand::LinDmaGen2::Serialize(void** buff) const
{
    memset(*buff, 0, sizeof(packet_lin_dma));
    ((packet_lin_dma*)(*buff))->opcode         = PACKET_LIN_DMA;
    ((packet_lin_dma*)(*buff))->eng_barrier    = m_eb;
    ((packet_lin_dma*)(*buff))->reg_barrier    = 1;
    ((packet_lin_dma*)(*buff))->msg_barrier    = m_mb;
    ((packet_lin_dma*)(*buff))->tsize          = m_tsize;
    ((packet_lin_dma*)(*buff))->wr_comp_en     = m_wrComp;
    ((packet_lin_dma*)(*buff))->transpose      = m_transpose;
    ((packet_lin_dma*)(*buff))->dtype          = m_dtype;
    ((packet_lin_dma*)(*buff))->lin            = m_linear;
    ((packet_lin_dma*)(*buff))->mem_set        = m_memset;
    ((packet_lin_dma*)(*buff))->compress       = m_compress;
    ((packet_lin_dma*)(*buff))->decompress     = m_decompress;
    ((packet_lin_dma*)(*buff))->context_id_low = m_ctxId & 0xff;
    ((packet_lin_dma*)(*buff))->src_addr       = m_src;
    ((packet_lin_dma*)(*buff))->dst_addr       = m_dst;
    (*(uint8_t**)buff) += GetSize();
}

void CPCommand::RepeatGen2::Serialize(void** buff) const
{
    memset(*buff, 0, sizeof(packet_repeat));
    ((packet_repeat*)(*buff))->opcode      = PACKET_REPEAT;
    ((packet_repeat*)(*buff))->eng_barrier = m_eb;
    ((packet_repeat*)(*buff))->reg_barrier = 1;
    ((packet_repeat*)(*buff))->msg_barrier = m_mb;
    ((packet_repeat*)(*buff))->sore        = m_sore;
    ((packet_repeat*)(*buff))->o           = m_o;
    ((packet_repeat*)(*buff))->pred        = m_pred;
    ((packet_repeat*)(*buff))->jmp_ptr     = m_jumpPtr;
    (*(uint8_t**)buff) += GetSize();
}

void CPCommand::WaitGen2::Serialize(void** buff) const
{
    memset(*buff, 0, sizeof(packet_wait));
    ((packet_wait*)(*buff))->opcode             = PACKET_WAIT;
    ((packet_wait*)(*buff))->eng_barrier        = m_eb;
    ((packet_wait*)(*buff))->reg_barrier        = 1;
    ((packet_wait*)(*buff))->msg_barrier        = m_mb;
    ((packet_wait*)(*buff))->num_cycles_to_wait = m_cycles;
    ((packet_wait*)(*buff))->inc_val            = m_incVal;
    ((packet_wait*)(*buff))->id                 = m_id;
    (*(uint8_t**)buff) += GetSize();
}

void CPCommand::LoadAndExecGen2::Serialize(void** buff) const
{
    memset(*buff, 0, sizeof(packet_load_and_exe));
    ((packet_load_and_exe*)(*buff))->opcode      = PACKET_LOAD_AND_EXE;
    ((packet_load_and_exe*)(*buff))->eng_barrier = m_eb;
    ((packet_load_and_exe*)(*buff))->reg_barrier = 1;
    ((packet_load_and_exe*)(*buff))->msg_barrier = m_mb;
    ((packet_load_and_exe*)(*buff))->dst         = m_dest;
    ((packet_load_and_exe*)(*buff))->load        = m_load;
    ((packet_load_and_exe*)(*buff))->exe         = m_exec;
    ((packet_load_and_exe*)(*buff))->etype       = m_eType;
    ((packet_load_and_exe*)(*buff))->pred        = m_pred;
    (*(uint8_t**)buff) += GetSize();
}

void CPCommand::CpDmaGen2::Serialize(void** buff) const
{
    memset(*buff, 0, sizeof(packet_cp_dma));
    ((packet_cp_dma*)(*buff))->opcode      = PACKET_CP_DMA;
    ((packet_cp_dma*)(*buff))->eng_barrier = m_eb;
    ((packet_cp_dma*)(*buff))->reg_barrier = 1;
    ((packet_cp_dma*)(*buff))->msg_barrier = m_mb;
    ((packet_cp_dma*)(*buff))->tsize       = m_tSize;
    ((packet_cp_dma*)(*buff))->src_addr    = m_src;
    ((packet_cp_dma*)(*buff))->pred        = m_pred;
    (*(uint8_t**)buff) += GetSize();
}

void CPCommand::ArbPointGen2::Serialize(void** buff) const
{
    memset(*buff, 0, sizeof(packet_arb_point));
    ((packet_arb_point*)(*buff))->opcode      = PACKET_ARB_POINT;
    ((packet_arb_point*)(*buff))->eng_barrier = 0;
    ((packet_arb_point*)(*buff))->reg_barrier = 0;
    ((packet_arb_point*)(*buff))->msg_barrier = 0;
    ((packet_arb_point*)(*buff))->priority    = m_prio;
    ((packet_arb_point*)(*buff))->rls         = m_release;
    ((packet_arb_point*)(*buff))->pred        = m_pred;
    (*(uint8_t**)buff) += GetSize();
}
