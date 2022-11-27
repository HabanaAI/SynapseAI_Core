/***********************************
** This is an auto-generated file **
**       DO NOT EDIT BELOW        **
************************************/

#ifndef ASIC_REG_STRUCTS_TPC_H_
#define ASIC_REG_STRUCTS_TPC_H_

#include <stdint.h>

#pragma pack(push, 1)
namespace gaudi
{
namespace tpc {
/*
 CFG_BASE_ADDRESS_HIGH 
 higher 32 bits of the CFG base address
*/
struct reg_cfg_base_address_high {
	union {
		struct {
			uint32_t v : 32;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_cfg_base_address_high) == 4), "reg_cfg_base_address_high size is not 32-bit");
/*
 SEMAPHORE 
*/
struct reg_semaphore {
	union {
		struct {
			uint32_t v : 32;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_semaphore) == 4), "reg_semaphore size is not 32-bit");
/*
 VFLAGS 
 Vector Flags
*/
struct reg_vflags {
	union {
		struct {
			uint32_t v : 4,
				_reserved4 : 28;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_vflags) == 4), "reg_vflags size is not 32-bit");
/*
 SFLAGS 
 Scalar Flags
*/
struct reg_sflags {
	union {
		struct {
			uint32_t v : 4,
				_reserved4 : 28;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_sflags) == 4), "reg_sflags size is not 32-bit");
/*
 LFSR_POLYNOM 
 LFSR polynom
*/
struct reg_lfsr_polynom {
	union {
		struct {
			uint32_t v : 32;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_lfsr_polynom) == 4), "reg_lfsr_polynom size is not 32-bit");
/*
 STATUS 
 Used to qeury  the status of the TPC
*/
struct reg_status {
	union {
		struct {
			uint32_t _reserved1 : 1,
scalar_pipe_empty : 1,
				vector_pipe_empty : 1,
				iq_empty : 1,
				_reserved5 : 1,
				sb_empty : 1,
				qm_idle : 1,
				qm_rdy : 1,
				_reserved8 : 24;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_status) == 4), "reg_status size is not 32-bit");
/*
 CFG_SUBTRACT_VALUE 
*/
struct reg_cfg_subtract_value {
	union {
		struct {
			uint32_t v : 32;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_cfg_subtract_value) == 4), "reg_cfg_subtract_value size is not 32-bit");
/*
 SM_BASE_ADDRESS_HIGH 
 32 MSBs of SM Base address
*/
struct reg_sm_base_address_high {
	union {
		struct {
			uint32_t v : 32;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_sm_base_address_high) == 4), "reg_sm_base_address_high size is not 32-bit");
/*
 TPC_CMD 
*/
struct reg_tpc_cmd {
	union {
		struct {
			uint32_t icache_invalidate : 1,
				dcache_invalidate : 1,
				lcache_invalidate : 1,
				tcache_invalidate : 1,
				icache_prefetch_64kb : 1,
				icache_prefetch_32kb : 1,
				qman_stop : 1,
				_reserved7 : 25;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_tpc_cmd) == 4), "reg_tpc_cmd size is not 32-bit");
/*
 TPC_STALL 
 stalls TPC core
*/
struct reg_tpc_stall {
	union {
		struct {
			uint32_t v : 1,
				_reserved1 : 31;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_tpc_stall) == 4), "reg_tpc_stall size is not 32-bit");
/*
 ROUND_CSR 
*/
struct reg_round_csr {
	union {
		struct {
			uint32_t mode : 3,
				_reserved3 : 29;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_round_csr) == 4), "reg_round_csr size is not 32-bit");
/*
 ICACHE_BASE_ADDERESS_LOW 
 32 LSBs of the base address to prefetch in a 64KB
*/
struct reg_icache_base_adderess_low {
	union {
		struct {
			uint32_t v : 32;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_icache_base_adderess_low) == 4), "reg_icache_base_adderess_low size is not 32-bit");
/*
 ICACHE_BASE_ADDERESS_HIGH 
 32 MSBs of the base address to prefetch in a 64KB
*/
struct reg_icache_base_adderess_high {
	union {
		struct {
			uint32_t v : 32;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_icache_base_adderess_high) == 4), "reg_icache_base_adderess_high size is not 32-bit");
/*
 MSS_CONFIG 
*/
struct reg_mss_config {
	union {
		struct {
			uint32_t awcache : 4,
				arcache : 4,
				icache_fetch_line_num : 2,
				exposed_pipe_dis : 1,
				dcache_prefetch_dis : 1,
				_reserved12 : 20;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_mss_config) == 4), "reg_mss_config size is not 32-bit");
/*
 ARUSER_LO 
*/
struct reg_aruser_lo {
	union {
		struct {
			uint32_t v : 11,
				_reserved11 : 21;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_aruser_lo) == 4), "reg_aruser_lo size is not 32-bit");
/*
 AWUSER_LO 
*/
struct reg_awuser_lo {
	union {
		struct {
			uint32_t v : 11,
				_reserved11 : 21;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_awuser_lo) == 4), "reg_awuser_lo size is not 32-bit");
/*
 TPC_EXECUTE 
*/
struct reg_tpc_execute {
	union {
		struct {
			uint32_t v : 1,
				_reserved1 : 31;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_tpc_execute) == 4), "reg_tpc_execute size is not 32-bit");
/*
 TPC_INTR_CAUSE 
 TPC interrupts cause
*/
struct reg_tpc_intr_cause {
	union {
		struct {
			uint32_t cause : 20,
				_reserved20 : 12;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_tpc_intr_cause) == 4), "reg_tpc_intr_cause size is not 32-bit");
/*
 TPC_INTR_MASK 
 Set 1 to mask the corresponding interrupt
*/
struct reg_tpc_intr_mask {
	union {
		struct {
			uint32_t mask : 20,
				_reserved20 : 12;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_tpc_intr_mask) == 4), "reg_tpc_intr_mask size is not 32-bit");
/*
 FUNC_MBIST_CNTRL 
 Initiate and get status of func MBIST
*/
struct reg_func_mbist_cntrl {
	union {
		struct {
			uint32_t mbist_start : 1,
				mbist_done : 1,
				mbist_active : 1,
				_reserved16 : 13,
				mbist_failed : 10,
				_reserved26 : 6;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_func_mbist_cntrl) == 4), "reg_func_mbist_cntrl size is not 32-bit");
/*
 FUNC_MBIST_PAT 
 Set func MBIST patterns
*/
struct reg_func_mbist_pat {
	union {
		struct {
			uint32_t mbist_pattern0_even : 2,
				mbist_pattern0_odd : 2,
				mbist_pattern1_even : 2,
				mbist_pattern1_odd : 2,
				mbist_pattern2_even : 2,
				mbist_pattern2_odd : 2,
				_reserved12 : 20;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_func_mbist_pat) == 4), "reg_func_mbist_pat size is not 32-bit");
/*
 FUNC_MBIST_MEM 
 Unique config and status per memory for func MBIST
*/
struct reg_func_mbist_mem {
	union {
		struct {
			uint32_t max_addr : 11,
				_reserved12 : 1,
				pattern_en : 3,
				_reserved16 : 1,
				last_failed_addr : 11,
				_reserved28 : 1,
				last_failed_pattern : 3,
				_reserved31 : 1;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_func_mbist_mem) == 4), "reg_func_mbist_mem size is not 32-bit");
/*
 WQ_CREDITS 
 WQ_CREDITS
*/
struct reg_wq_credits {
	union {
		struct {
			uint32_t st_g : 4,
				kernel_fifo : 3,
				_reserved7 : 25;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_wq_credits) == 4), "reg_wq_credits size is not 32-bit");
/*
 OPCODE_EXEC 
 Opcodes Executed for Counters
*/
struct reg_opcode_exec {
	union {
		struct {
			uint32_t spu_op : 7,
				spu_en : 1,
				vpu_op : 7,
				vpu_en : 1,
				ld_op : 7,
				ld_en : 1,
				st_op : 7,
				st_en : 1;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_opcode_exec) == 4), "reg_opcode_exec size is not 32-bit");
/*
 LUT_FUNC32_BASE_ADDR_LO 
 LOOKUP TABLE 32 lines Base Address 32 LSB
*/
struct reg_lut_func32_base_addr_lo {
	union {
		struct {
			uint32_t v : 32;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_lut_func32_base_addr_lo) == 4), "reg_lut_func32_base_addr_lo size is not 32-bit");
/*
 LUT_FUNC32_BASE_ADDR_HI 
 LOOKUP TABLE 32 lines Base Address 32 MSB
*/
struct reg_lut_func32_base_addr_hi {
	union {
		struct {
			uint32_t v : 32;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_lut_func32_base_addr_hi) == 4), "reg_lut_func32_base_addr_hi size is not 32-bit");
/*
 LUT_FUNC64_BASE_ADDR_LO 
 LOOKUP TABLE 64 lines Base Address 32 LSB
*/
struct reg_lut_func64_base_addr_lo {
	union {
		struct {
			uint32_t v : 32;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_lut_func64_base_addr_lo) == 4), "reg_lut_func64_base_addr_lo size is not 32-bit");
/*
 LUT_FUNC64_BASE_ADDR_HI 
 LOOKUP TABLE 64 lines Base Address 32 MSB
*/
struct reg_lut_func64_base_addr_hi {
	union {
		struct {
			uint32_t v : 32;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_lut_func64_base_addr_hi) == 4), "reg_lut_func64_base_addr_hi size is not 32-bit");
/*
 LUT_FUNC128_BASE_ADDR_LO 
 LOOKUP TABLE 128 lines Base Address 32 LSB
*/
struct reg_lut_func128_base_addr_lo {
	union {
		struct {
			uint32_t v : 32;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_lut_func128_base_addr_lo) == 4), "reg_lut_func128_base_addr_lo size is not 32-bit");
/*
 LUT_FUNC128_BASE_ADDR_HI 
 LOOKUP TABLE 128 lines Base Address 32 MSB
*/
struct reg_lut_func128_base_addr_hi {
	union {
		struct {
			uint32_t v : 32;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_lut_func128_base_addr_hi) == 4), "reg_lut_func128_base_addr_hi size is not 32-bit");
/*
 LUT_FUNC256_BASE_ADDR_LO 
 LOOKUP TABLE 256 lines Base Address 32 LSB
*/
struct reg_lut_func256_base_addr_lo {
	union {
		struct {
			uint32_t v : 32;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_lut_func256_base_addr_lo) == 4), "reg_lut_func256_base_addr_lo size is not 32-bit");
/*
 LUT_FUNC256_BASE_ADDR_HI 
 LOOKUP TABLE 256 lines Base Address 32 MSB
*/
struct reg_lut_func256_base_addr_hi {
	union {
		struct {
			uint32_t v : 32;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_lut_func256_base_addr_hi) == 4), "reg_lut_func256_base_addr_hi size is not 32-bit");
/*
 TSB_CFG_MAX_SIZE 
 TSB Configuration
*/
struct reg_tsb_cfg_max_size {
	union {
		struct {
			uint32_t data : 16,
				md : 16;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_tsb_cfg_max_size) == 4), "reg_tsb_cfg_max_size size is not 32-bit");
/*
 TSB_CFG 
 more TSB configuration
*/
struct reg_tsb_cfg {
	union {
		struct {
			uint32_t force_miss : 1,
				max_os : 16,
				_reserved17 : 15;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_tsb_cfg) == 4), "reg_tsb_cfg size is not 32-bit");
/*
 WR_RATE_LIMIT 
 AXI Write Port RATE LIMIT Static Config
*/
struct reg_wr_rate_limit {
	union {
		struct {
			uint32_t enable : 1,
				saturation : 8,
				timeout : 8,
				_reserved17 : 15;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_wr_rate_limit) == 4), "reg_wr_rate_limit size is not 32-bit");
/*
 RD_RATE_LIMIT 
 AXI Read Port RATE LIMIT Static Config
*/
struct reg_rd_rate_limit {
	union {
		struct {
			uint32_t enable : 1,
				saturation : 8,
				timeout : 8,
				_reserved17 : 15;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_rd_rate_limit) == 4), "reg_rd_rate_limit size is not 32-bit");
/*
 AWUSER_HI 
*/
struct reg_awuser_hi {
	union {
		struct {
			uint32_t _reserved11 : 11,
v : 2,
				rsrv : 19;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_awuser_hi) == 4), "reg_awuser_hi size is not 32-bit");
/*
 ARUSER_HI 
*/
struct reg_aruser_hi {
	union {
		struct {
			uint32_t _reserved11 : 11,
v : 2,
				rsrv : 19;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_aruser_hi) == 4), "reg_aruser_hi size is not 32-bit");
/*
 DBGMEM_ADD 
*/
struct reg_dbgmem_add {
	union {
		struct {
			uint32_t v : 32;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_dbgmem_add) == 4), "reg_dbgmem_add size is not 32-bit");
/*
 DBGMEM_DATA_WR 
*/
struct reg_dbgmem_data_wr {
	union {
		struct {
			uint32_t v : 32;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_dbgmem_data_wr) == 4), "reg_dbgmem_data_wr size is not 32-bit");
/*
 DBGMEM_DATA_RD 
*/
struct reg_dbgmem_data_rd {
	union {
		struct {
			uint32_t v : 32;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_dbgmem_data_rd) == 4), "reg_dbgmem_data_rd size is not 32-bit");
/*
 DBGMEM_CTRL 
*/
struct reg_dbgmem_ctrl {
	union {
		struct {
			uint32_t wr_nrd : 1,
				_reserved1 : 31;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_dbgmem_ctrl) == 4), "reg_dbgmem_ctrl size is not 32-bit");
/*
 DBGMEM_RC 
*/
struct reg_dbgmem_rc {
	union {
		struct {
			uint32_t valid : 1,
				_reserved1 : 31;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_dbgmem_rc) == 4), "reg_dbgmem_rc size is not 32-bit");
/*
 TSB_INFLIGHT_CNTR 
*/
struct reg_tsb_inflight_cntr {
	union {
		struct {
			uint32_t v : 32;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_tsb_inflight_cntr) == 4), "reg_tsb_inflight_cntr size is not 32-bit");
/*
 PROT 
*/
struct reg_prot {
	union {
		struct {
			uint32_t awprot : 3,
				arprot : 3,
				_reserved6 : 26;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_prot) == 4), "reg_prot size is not 32-bit");
/*
 WQ_INFLIGHT_CNTR 
*/
struct reg_wq_inflight_cntr {
	union {
		struct {
			uint32_t hbw : 16,
				lbw : 4,
				_reserved20 : 12;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_wq_inflight_cntr) == 4), "reg_wq_inflight_cntr size is not 32-bit");
/*
 WQ_LBW_TOTAL_CNTR 
 writing reset counter
*/
struct reg_wq_lbw_total_cntr {
	union {
		struct {
			uint32_t v : 32;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_wq_lbw_total_cntr) == 4), "reg_wq_lbw_total_cntr size is not 32-bit");
/*
 WQ_HBW_TOTAL_CNTR 
 writing reset counter
*/
struct reg_wq_hbw_total_cntr {
	union {
		struct {
			uint32_t v : 32;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_wq_hbw_total_cntr) == 4), "reg_wq_hbw_total_cntr size is not 32-bit");
/*
 IRQ_OCCOUPY_CNTR 
*/
struct reg_irq_occoupy_cntr {
	union {
		struct {
			uint32_t v : 32;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_irq_occoupy_cntr) == 4), "reg_irq_occoupy_cntr size is not 32-bit");
} /* tpc namespace */
} //namespace gaudi
#include "sync_object_regs.h"
#include "tpc_non_tensor_descriptor_regs.h"
#include "tpc_tensor_regs.h"
/*
 TPC block
*/
namespace gaudi
{
struct block_tpc {
	uint32_t _pad0[256];
	struct block_tpc_tensor kernel_tensor_0;
	struct block_tpc_tensor kernel_tensor_1;
	struct block_tpc_tensor kernel_tensor_2;
	struct block_tpc_tensor kernel_tensor_3;
	struct block_tpc_tensor kernel_tensor_4;
	struct block_tpc_tensor kernel_tensor_5;
	struct block_tpc_tensor kernel_tensor_6;
	struct block_tpc_tensor kernel_tensor_7;
	struct block_tpc_tensor kernel_tensor_8;
	struct block_tpc_tensor kernel_tensor_9;
	struct block_tpc_tensor kernel_tensor_10;
	struct block_tpc_tensor kernel_tensor_11;
	struct block_tpc_tensor kernel_tensor_12;
	struct block_tpc_tensor kernel_tensor_13;
	struct block_tpc_tensor kernel_tensor_14;
	struct block_tpc_tensor kernel_tensor_15;
	struct block_sync_object kernel_sync_object;
	struct block_tpc_non_tensor_descriptor kernel;
	uint32_t _pad2112[47];
	struct tpc::reg_round_csr round_csr;
	struct tpc::reg_prot prot;
	uint32_t _pad2308[1];
	struct tpc::reg_semaphore semaphore;
	struct tpc::reg_vflags vflags;
	struct tpc::reg_sflags sflags;
	uint32_t _pad2324[1];
	struct tpc::reg_lfsr_polynom lfsr_polynom;
	struct tpc::reg_status status;
	struct tpc::reg_cfg_base_address_high cfg_base_address_high;
	struct tpc::reg_cfg_subtract_value cfg_subtract_value;
	uint32_t _pad2344[1];
	struct tpc::reg_sm_base_address_high sm_base_address_high;
	struct tpc::reg_tpc_cmd tpc_cmd;
	uint32_t _pad2356[1];
	struct tpc::reg_tpc_execute tpc_execute;
	struct tpc::reg_tpc_stall tpc_stall;
	struct tpc::reg_icache_base_adderess_low icache_base_adderess_low;
	struct tpc::reg_icache_base_adderess_high icache_base_adderess_high;
	struct tpc::reg_rd_rate_limit rd_rate_limit;
	uint32_t _pad2380[1];
	struct tpc::reg_wr_rate_limit wr_rate_limit;
	struct tpc::reg_mss_config mss_config;
	struct tpc::reg_tpc_intr_cause tpc_intr_cause;
	struct tpc::reg_tpc_intr_mask tpc_intr_mask;
	struct tpc::reg_wq_credits wq_credits;
	struct tpc::reg_aruser_lo aruser_lo;
	struct tpc::reg_aruser_hi aruser_hi;
	struct tpc::reg_awuser_lo awuser_lo;
	struct tpc::reg_awuser_hi awuser_hi;
	struct tpc::reg_opcode_exec opcode_exec;
	struct tpc::reg_lut_func32_base_addr_lo lut_func32_base_addr_lo;
	struct tpc::reg_lut_func32_base_addr_hi lut_func32_base_addr_hi;
	struct tpc::reg_lut_func64_base_addr_lo lut_func64_base_addr_lo;
	struct tpc::reg_lut_func64_base_addr_hi lut_func64_base_addr_hi;
	struct tpc::reg_lut_func128_base_addr_lo lut_func128_base_addr_lo;
	struct tpc::reg_lut_func128_base_addr_hi lut_func128_base_addr_hi;
	struct tpc::reg_lut_func256_base_addr_lo lut_func256_base_addr_lo;
	struct tpc::reg_lut_func256_base_addr_hi lut_func256_base_addr_hi;
	struct tpc::reg_tsb_cfg_max_size tsb_cfg_max_size;
	struct tpc::reg_tsb_cfg tsb_cfg;
	struct tpc::reg_dbgmem_add dbgmem_add;
	struct tpc::reg_dbgmem_data_wr dbgmem_data_wr;
	struct tpc::reg_dbgmem_data_rd dbgmem_data_rd;
	struct tpc::reg_dbgmem_ctrl dbgmem_ctrl;
	struct tpc::reg_dbgmem_rc dbgmem_rc;
	struct tpc::reg_tsb_inflight_cntr tsb_inflight_cntr;
	struct tpc::reg_wq_inflight_cntr wq_inflight_cntr;
	struct tpc::reg_wq_lbw_total_cntr wq_lbw_total_cntr;
	struct tpc::reg_wq_hbw_total_cntr wq_hbw_total_cntr;
	struct tpc::reg_irq_occoupy_cntr irq_occoupy_cntr;
	uint32_t _pad2504[2];
	struct tpc::reg_func_mbist_cntrl func_mbist_cntrl;
	struct tpc::reg_func_mbist_pat func_mbist_pat;
	struct tpc::reg_func_mbist_mem func_mbist_mem[10];
	struct block_tpc_tensor qm_tensor_0;
	struct block_tpc_tensor qm_tensor_1;
	struct block_tpc_tensor qm_tensor_2;
	struct block_tpc_tensor qm_tensor_3;
	struct block_tpc_tensor qm_tensor_4;
	struct block_tpc_tensor qm_tensor_5;
	struct block_tpc_tensor qm_tensor_6;
	struct block_tpc_tensor qm_tensor_7;
	struct block_tpc_tensor qm_tensor_8;
	struct block_tpc_tensor qm_tensor_9;
	struct block_tpc_tensor qm_tensor_10;
	struct block_tpc_tensor qm_tensor_11;
	struct block_tpc_tensor qm_tensor_12;
	struct block_tpc_tensor qm_tensor_13;
	struct block_tpc_tensor qm_tensor_14;
	struct block_tpc_tensor qm_tensor_15;
	struct block_sync_object qm_sync_object;
	struct block_tpc_non_tensor_descriptor qm;
};
} // namespace gaudi
#include "gaudi_types.h"
namespace gaudi
{
const offsetVal block_tpc_defaults[]
{
	// offset	// value
	{ 0x40c , 0x50000             , 1 }, // tensor_config
	{ 0x444 , 0x50000             , 1 }, // tensor_config
	{ 0x47c , 0x50000             , 1 }, // tensor_config
	{ 0x4b4 , 0x50000             , 1 }, // tensor_config
	{ 0x4ec , 0x50000             , 1 }, // tensor_config
	{ 0x524 , 0x50000             , 1 }, // tensor_config
	{ 0x55c , 0x50000             , 1 }, // tensor_config
	{ 0x594 , 0x50000             , 1 }, // tensor_config
	{ 0x5cc , 0x50000             , 1 }, // tensor_config
	{ 0x604 , 0x50000             , 1 }, // tensor_config
	{ 0x63c , 0x50000             , 1 }, // tensor_config
	{ 0x674 , 0x50000             , 1 }, // tensor_config
	{ 0x6ac , 0x50000             , 1 }, // tensor_config
	{ 0x6e4 , 0x50000             , 1 }, // tensor_config
	{ 0x71c , 0x50000             , 1 }, // tensor_config
	{ 0x754 , 0x50000             , 1 }, // tensor_config
	{ 0x7b8 , 0x60882             , 1 }, // kernel_config
	{ 0x900 , 0x12                , 1 }, // prot
	{ 0x918 , 0x800002cc          , 1 }, // lfsr_polynom
	{ 0x91c , 0xee                , 1 }, // status
	{ 0x920 , 0x7f                , 1 }, // cfg_base_address_high
	{ 0x948 , 0x1e09              , 1 }, // rd_rate_limit
	{ 0x950 , 0x1c06              , 1 }, // wr_rate_limit
	{ 0x960 , 0x48                , 1 }, // wq_credits
	{ 0x964 , 0x400               , 1 }, // aruser_lo
	{ 0x968 , 0x800               , 1 }, // aruser_hi
	{ 0x96c , 0x400               , 1 }, // awuser_lo
	{ 0x970 , 0x800               , 1 }, // awuser_hi
	{ 0x974 , 0xffffffff          , 1 }, // opcode_exec
	{ 0x978 , 0x17000             , 1 }, // lut_func32_base_addr_lo
	{ 0x980 , 0x13800             , 1 }, // lut_func64_base_addr_lo
	{ 0x988 , 0xd000              , 1 }, // lut_func128_base_addr_lo
	{ 0x9d4 , 0xf69               , 1 }, // func_mbist_pat
	{ 0x9d8 , 0x73ff              , 10 }, // func_mbist_mem
	{ 0xa0c , 0x50000             , 1 }, // tensor_config
	{ 0xa44 , 0x50000             , 1 }, // tensor_config
	{ 0xa7c , 0x50000             , 1 }, // tensor_config
	{ 0xab4 , 0x50000             , 1 }, // tensor_config
	{ 0xaec , 0x50000             , 1 }, // tensor_config
	{ 0xb24 , 0x50000             , 1 }, // tensor_config
	{ 0xb5c , 0x50000             , 1 }, // tensor_config
	{ 0xb94 , 0x50000             , 1 }, // tensor_config
	{ 0xbcc , 0x50000             , 1 }, // tensor_config
	{ 0xc04 , 0x50000             , 1 }, // tensor_config
	{ 0xc3c , 0x50000             , 1 }, // tensor_config
	{ 0xc74 , 0x50000             , 1 }, // tensor_config
	{ 0xcac , 0x50000             , 1 }, // tensor_config
	{ 0xce4 , 0x50000             , 1 }, // tensor_config
	{ 0xd1c , 0x50000             , 1 }, // tensor_config
	{ 0xd54 , 0x50000             , 1 }, // tensor_config
	{ 0xdb8 , 0x60882             , 1 }, // kernel_config
};
} // namespace gaudi
#pragma pack(pop)
#endif /* ASIC_REG_STRUCTS_TPC_H_ */
