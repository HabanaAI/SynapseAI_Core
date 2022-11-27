/***********************************
** This is an auto-generated file **
**       DO NOT EDIT BELOW        **
************************************/

#ifndef ASIC_REG_STRUCTS_DMA_CORE_CTX_H_
#define ASIC_REG_STRUCTS_DMA_CORE_CTX_H_

#include <stdint.h>
#include "gaudi2_types.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace gaudi2 {
namespace dma_core_ctx {
#else
#	ifndef static_assert
#		if defined( __STDC__ ) && defined( __STDC_VERSION__ ) && __STDC_VERSION__ >= 201112L
#			define static_assert(...) _Static_assert(__VA_ARGS__)
#		else
#			define static_assert(...)
#		endif
#	endif
#endif

/*
 RATE_LIM_TKN 
 b'Rate limiters Tokens'
*/
typedef struct reg_rate_lim_tkn {
	union {
		struct {
			uint32_t rd : 8,
				_reserved16 : 8,
				wr : 8,
				_reserved24 : 8;
		};
		uint32_t _raw;
	};
} reg_rate_lim_tkn;
static_assert((sizeof(struct reg_rate_lim_tkn) == 4), "reg_rate_lim_tkn size is not 32-bit");
/*
 PWRLP 
 b'power loop data and control'
*/
typedef struct reg_pwrlp {
	union {
		struct {
			uint32_t data : 8,
				en : 1,
				_reserved9 : 23;
		};
		uint32_t _raw;
	};
} reg_pwrlp;
static_assert((sizeof(struct reg_pwrlp) == 4), "reg_pwrlp size is not 32-bit");
/*
 TE_NUMROWS 
 b'Total rows num per descriptor. ignored if transpose not set'
*/
typedef struct reg_te_numrows {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_te_numrows;
static_assert((sizeof(struct reg_te_numrows) == 4), "reg_te_numrows size is not 32-bit");
/*
 IDX 
 b'context ID'
*/
typedef struct reg_idx {
	union {
		struct {
			uint32_t val : 16,
				_reserved16 : 16;
		};
		uint32_t _raw;
	};
} reg_idx;
static_assert((sizeof(struct reg_idx) == 4), "reg_idx size is not 32-bit");
/*
 IDX_INC 
 b'context index inc signed value'
*/
typedef struct reg_idx_inc {
	union {
		struct {
			uint32_t val : 8,
				_reserved8 : 24;
		};
		uint32_t _raw;
	};
} reg_idx_inc;
static_assert((sizeof(struct reg_idx_inc) == 4), "reg_idx_inc size is not 32-bit");
/*
 CTRL 
 b'Control bits. TE, compress etc.'
*/
typedef struct reg_ctrl {
	union {
		struct {
			uint32_t transpose : 1,
				_reserved4 : 3,
				dtype : 2,
				_reserved8 : 2,
				compress : 1,
				decompress : 1,
				_reserved12 : 2,
				rd_uncacheable : 1,
				_reserved13 : 19;
		};
		uint32_t _raw;
	};
} reg_ctrl;
static_assert((sizeof(struct reg_ctrl) == 4), "reg_ctrl size is not 32-bit");
/*
 SRC_TSIZE_0 
 b'Size in bytes of dim 0 transfer'
*/
typedef struct reg_src_tsize_0 {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_src_tsize_0;
static_assert((sizeof(struct reg_src_tsize_0) == 4), "reg_src_tsize_0 size is not 32-bit");
/*
 SRC_TSIZE_1 
 b'Size in elements of Dim1'
*/
typedef struct reg_src_tsize_1 {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_src_tsize_1;
static_assert((sizeof(struct reg_src_tsize_1) == 4), "reg_src_tsize_1 size is not 32-bit");
/*
 SRC_STRIDE_1 
 b'Src strides dim1'
*/
typedef struct reg_src_stride_1 {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_src_stride_1;
static_assert((sizeof(struct reg_src_stride_1) == 4), "reg_src_stride_1 size is not 32-bit");
/*
 SRC_TSIZE_2 
 b'Source size in elements of Dim2'
*/
typedef struct reg_src_tsize_2 {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_src_tsize_2;
static_assert((sizeof(struct reg_src_tsize_2) == 4), "reg_src_tsize_2 size is not 32-bit");
/*
 SRC_STRIDE_2 
 b'Source stride dim2'
*/
typedef struct reg_src_stride_2 {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_src_stride_2;
static_assert((sizeof(struct reg_src_stride_2) == 4), "reg_src_stride_2 size is not 32-bit");
/*
 SRC_TSIZE_3 
 b'Source size in elements of Dim3'
*/
typedef struct reg_src_tsize_3 {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_src_tsize_3;
static_assert((sizeof(struct reg_src_tsize_3) == 4), "reg_src_tsize_3 size is not 32-bit");
/*
 SRC_STRIDE_3 
 b'Source stride dim3'
*/
typedef struct reg_src_stride_3 {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_src_stride_3;
static_assert((sizeof(struct reg_src_stride_3) == 4), "reg_src_stride_3 size is not 32-bit");
/*
 SRC_TSIZE_4 
 b'Source size in elements of Dim4'
*/
typedef struct reg_src_tsize_4 {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_src_tsize_4;
static_assert((sizeof(struct reg_src_tsize_4) == 4), "reg_src_tsize_4 size is not 32-bit");
/*
 SRC_STRIDE_4 
 b'Source stride dim4'
*/
typedef struct reg_src_stride_4 {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_src_stride_4;
static_assert((sizeof(struct reg_src_stride_4) == 4), "reg_src_stride_4 size is not 32-bit");
/*
 DST_TSIZE_1 
 b'Dest size in elements Dim1'
*/
typedef struct reg_dst_tsize_1 {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_dst_tsize_1;
static_assert((sizeof(struct reg_dst_tsize_1) == 4), "reg_dst_tsize_1 size is not 32-bit");
/*
 DST_STRIDE_1 
 b'Dest stride dim1'
*/
typedef struct reg_dst_stride_1 {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_dst_stride_1;
static_assert((sizeof(struct reg_dst_stride_1) == 4), "reg_dst_stride_1 size is not 32-bit");
/*
 DST_TSIZE_2 
 b'Dest size in elements Dim2'
*/
typedef struct reg_dst_tsize_2 {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_dst_tsize_2;
static_assert((sizeof(struct reg_dst_tsize_2) == 4), "reg_dst_tsize_2 size is not 32-bit");
/*
 DST_STRIDE_2 
 b'Dest stride Dim2'
*/
typedef struct reg_dst_stride_2 {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_dst_stride_2;
static_assert((sizeof(struct reg_dst_stride_2) == 4), "reg_dst_stride_2 size is not 32-bit");
/*
 DST_TSIZE_3 
 b'Dest size in elements Dim3'
*/
typedef struct reg_dst_tsize_3 {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_dst_tsize_3;
static_assert((sizeof(struct reg_dst_tsize_3) == 4), "reg_dst_tsize_3 size is not 32-bit");
/*
 DST_STRIDE_3 
 b'Dest stride dim3'
*/
typedef struct reg_dst_stride_3 {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_dst_stride_3;
static_assert((sizeof(struct reg_dst_stride_3) == 4), "reg_dst_stride_3 size is not 32-bit");
/*
 DST_TSIZE_4 
 b'Dest size in elements Dim4'
*/
typedef struct reg_dst_tsize_4 {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_dst_tsize_4;
static_assert((sizeof(struct reg_dst_tsize_4) == 4), "reg_dst_tsize_4 size is not 32-bit");
/*
 DST_STRIDE_4 
 b'Dest stride dim4'
*/
typedef struct reg_dst_stride_4 {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_dst_stride_4;
static_assert((sizeof(struct reg_dst_stride_4) == 4), "reg_dst_stride_4 size is not 32-bit");
/*
 WR_COMP_ADDR_HI 
 b'Wr completion msg address byte 7-4'
*/
typedef struct reg_wr_comp_addr_hi {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_wr_comp_addr_hi;
static_assert((sizeof(struct reg_wr_comp_addr_hi) == 4), "reg_wr_comp_addr_hi size is not 32-bit");
/*
 WR_COMP_ADDR_LO 
 b'Wr completion msg address byte 3-0'
*/
typedef struct reg_wr_comp_addr_lo {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_wr_comp_addr_lo;
static_assert((sizeof(struct reg_wr_comp_addr_lo) == 4), "reg_wr_comp_addr_lo size is not 32-bit");
/*
 WR_COMP_WDATA 
 b'Wr completion msg wdata to send'
*/
typedef struct reg_wr_comp_wdata {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_wr_comp_wdata;
static_assert((sizeof(struct reg_wr_comp_wdata) == 4), "reg_wr_comp_wdata size is not 32-bit");
/*
 SRC_OFFSET_LO 
 b'Source base address offset byte 3-0'
*/
typedef struct reg_src_offset_lo {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_src_offset_lo;
static_assert((sizeof(struct reg_src_offset_lo) == 4), "reg_src_offset_lo size is not 32-bit");
/*
 SRC_OFFSET_HI 
 b'Source base address offset byte 7-4'
*/
typedef struct reg_src_offset_hi {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_src_offset_hi;
static_assert((sizeof(struct reg_src_offset_hi) == 4), "reg_src_offset_hi size is not 32-bit");
/*
 DST_OFFSET_LO 
 b'destination base address offset byte 3-0'
*/
typedef struct reg_dst_offset_lo {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_dst_offset_lo;
static_assert((sizeof(struct reg_dst_offset_lo) == 4), "reg_dst_offset_lo size is not 32-bit");
/*
 DST_OFFSET_HI 
 b'destination base address byte 7-4'
*/
typedef struct reg_dst_offset_hi {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_dst_offset_hi;
static_assert((sizeof(struct reg_dst_offset_hi) == 4), "reg_dst_offset_hi size is not 32-bit");
/*
 SRC_BASE_LO 
 b'Source base address byte 3-0'
*/
typedef struct reg_src_base_lo {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_src_base_lo;
static_assert((sizeof(struct reg_src_base_lo) == 4), "reg_src_base_lo size is not 32-bit");
/*
 SRC_BASE_HI 
 b'Source base address byte 7-4'
*/
typedef struct reg_src_base_hi {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_src_base_hi;
static_assert((sizeof(struct reg_src_base_hi) == 4), "reg_src_base_hi size is not 32-bit");
/*
 DST_BASE_LO 
 b'Destination base address byte 3-0'
*/
typedef struct reg_dst_base_lo {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_dst_base_lo;
static_assert((sizeof(struct reg_dst_base_lo) == 4), "reg_dst_base_lo size is not 32-bit");
/*
 DST_BASE_HI 
 b'Destination base address byte 7-4'
*/
typedef struct reg_dst_base_hi {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_dst_base_hi;
static_assert((sizeof(struct reg_dst_base_hi) == 4), "reg_dst_base_hi size is not 32-bit");
/*
 DST_TSIZE_0 
 b'Size in bytes of dim0. QMAN CP LDMA uses this as size'
*/
typedef struct reg_dst_tsize_0 {
	union {
		struct {
			uint32_t val : 32;
		};
		uint32_t _raw;
	};
} reg_dst_tsize_0;
static_assert((sizeof(struct reg_dst_tsize_0) == 4), "reg_dst_tsize_0 size is not 32-bit");
/*
 COMMIT 
 b'Controls. writing to this reg initiates transfer'
*/
typedef struct reg_commit {
	union {
		struct {
			uint32_t wr_comp_en : 1,
				endian_swap : 2,
				_reserved4 : 1,
				mem_set : 1,
				_reserved6 : 1,
				bf16 : 1,
				fp16 : 1,
				ctx_id_inc : 1,
				add_offset_0 : 1,
				src_size0_from_dst_size0 : 1,
				src_ofst_from_dst_ofst : 1,
				disable_dim1 : 1,
				disable_dim2 : 1,
				disable_dim3 : 1,
				disable_dim4 : 1,
				src_size1_from_dst_size1 : 1,
				src_size2_from_dst_size2 : 1,
				src_size3_from_dst_size3 : 1,
				src_size4_from_dst_size4 : 1,
				src_strd1_from_dst_strd1 : 1,
				src_strd2_from_dst_strd2 : 1,
				src_strd3_from_dst_strd3 : 1,
				src_strd4_from_dst_strd4 : 1,
				_reserved31 : 7,
				lin : 1;
		};
		uint32_t _raw;
	};
} reg_commit;
static_assert((sizeof(struct reg_commit) == 4), "reg_commit size is not 32-bit");

#ifdef __cplusplus
} /* dma_core_ctx namespace */
#endif

/*
 DMA_CORE_CTX block
*/

#ifdef __cplusplus

struct block_dma_core_ctx {
	struct dma_core_ctx::reg_rate_lim_tkn rate_lim_tkn;
	struct dma_core_ctx::reg_pwrlp pwrlp;
	struct dma_core_ctx::reg_te_numrows te_numrows;
	struct dma_core_ctx::reg_idx idx;
	struct dma_core_ctx::reg_idx_inc idx_inc;
	struct dma_core_ctx::reg_ctrl ctrl;
	struct dma_core_ctx::reg_src_tsize_0 src_tsize_0;
	struct dma_core_ctx::reg_src_tsize_1 src_tsize_1;
	struct dma_core_ctx::reg_src_stride_1 src_stride_1;
	struct dma_core_ctx::reg_src_tsize_2 src_tsize_2;
	struct dma_core_ctx::reg_src_stride_2 src_stride_2;
	struct dma_core_ctx::reg_src_tsize_3 src_tsize_3;
	struct dma_core_ctx::reg_src_stride_3 src_stride_3;
	struct dma_core_ctx::reg_src_tsize_4 src_tsize_4;
	struct dma_core_ctx::reg_src_stride_4 src_stride_4;
	struct dma_core_ctx::reg_dst_tsize_1 dst_tsize_1;
	struct dma_core_ctx::reg_dst_stride_1 dst_stride_1;
	struct dma_core_ctx::reg_dst_tsize_2 dst_tsize_2;
	struct dma_core_ctx::reg_dst_stride_2 dst_stride_2;
	struct dma_core_ctx::reg_dst_tsize_3 dst_tsize_3;
	struct dma_core_ctx::reg_dst_stride_3 dst_stride_3;
	struct dma_core_ctx::reg_dst_tsize_4 dst_tsize_4;
	struct dma_core_ctx::reg_dst_stride_4 dst_stride_4;
	struct dma_core_ctx::reg_wr_comp_addr_hi wr_comp_addr_hi;
	struct dma_core_ctx::reg_wr_comp_addr_lo wr_comp_addr_lo;
	struct dma_core_ctx::reg_wr_comp_wdata wr_comp_wdata;
	struct dma_core_ctx::reg_src_offset_lo src_offset_lo;
	struct dma_core_ctx::reg_src_offset_hi src_offset_hi;
	struct dma_core_ctx::reg_dst_offset_lo dst_offset_lo;
	struct dma_core_ctx::reg_dst_offset_hi dst_offset_hi;
	struct dma_core_ctx::reg_src_base_lo src_base_lo;
	struct dma_core_ctx::reg_src_base_hi src_base_hi;
	struct dma_core_ctx::reg_dst_base_lo dst_base_lo;
	struct dma_core_ctx::reg_dst_base_hi dst_base_hi;
	struct dma_core_ctx::reg_dst_tsize_0 dst_tsize_0;
	struct dma_core_ctx::reg_commit commit;
};
#else

typedef struct block_dma_core_ctx {
	reg_rate_lim_tkn rate_lim_tkn;
	reg_pwrlp pwrlp;
	reg_te_numrows te_numrows;
	reg_idx idx;
	reg_idx_inc idx_inc;
	reg_ctrl ctrl;
	reg_src_tsize_0 src_tsize_0;
	reg_src_tsize_1 src_tsize_1;
	reg_src_stride_1 src_stride_1;
	reg_src_tsize_2 src_tsize_2;
	reg_src_stride_2 src_stride_2;
	reg_src_tsize_3 src_tsize_3;
	reg_src_stride_3 src_stride_3;
	reg_src_tsize_4 src_tsize_4;
	reg_src_stride_4 src_stride_4;
	reg_dst_tsize_1 dst_tsize_1;
	reg_dst_stride_1 dst_stride_1;
	reg_dst_tsize_2 dst_tsize_2;
	reg_dst_stride_2 dst_stride_2;
	reg_dst_tsize_3 dst_tsize_3;
	reg_dst_stride_3 dst_stride_3;
	reg_dst_tsize_4 dst_tsize_4;
	reg_dst_stride_4 dst_stride_4;
	reg_wr_comp_addr_hi wr_comp_addr_hi;
	reg_wr_comp_addr_lo wr_comp_addr_lo;
	reg_wr_comp_wdata wr_comp_wdata;
	reg_src_offset_lo src_offset_lo;
	reg_src_offset_hi src_offset_hi;
	reg_dst_offset_lo dst_offset_lo;
	reg_dst_offset_hi dst_offset_hi;
	reg_src_base_lo src_base_lo;
	reg_src_base_hi src_base_hi;
	reg_dst_base_lo dst_base_lo;
	reg_dst_base_hi dst_base_hi;
	reg_dst_tsize_0 dst_tsize_0;
	reg_commit commit;
} block_dma_core_ctx;
#endif

const offsetVal block_dma_core_ctx_defaults[] =
{
	// offset	// value
	{ 0x0   , 0x40004             , 1 }, // rate_lim_tkn
};

#ifdef __cplusplus
} /* gaudi2 namespace */
#endif

#pragma pack(pop)
#endif /* ASIC_REG_STRUCTS_DMA_CORE_CTX_H_ */
