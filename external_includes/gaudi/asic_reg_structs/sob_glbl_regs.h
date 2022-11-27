/***********************************
** This is an auto-generated file **
**       DO NOT EDIT BELOW        **
************************************/

#ifndef ASIC_REG_STRUCTS_SOB_GLBL_H_
#define ASIC_REG_STRUCTS_SOB_GLBL_H_

#include <stdint.h>

#pragma pack(push, 1)
namespace gaudi
{
namespace sob_glbl {
/*
 SM_SEI_MASK 
*/
struct reg_sm_sei_mask {
	union {
		struct {
			uint32_t so_overflow : 1,
				mst_unalign4b : 1,
				mst_rsp_err : 1,
				_reserved3 : 29;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_sm_sei_mask) == 4), "reg_sm_sei_mask size is not 32-bit");
/*
 SM_SEI_CAUSE 
*/
struct reg_sm_sei_cause {
	union {
		struct {
			uint32_t cause : 3,
				_reserved16 : 13,
				log : 16;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_sm_sei_cause) == 4), "reg_sm_sei_cause size is not 32-bit");
} /* sob_glbl namespace */

/*
 SOB_GLBL block
*/
struct block_sob_glbl {
	struct sob_glbl::reg_sm_sei_mask sm_sei_mask;
	struct sob_glbl::reg_sm_sei_cause sm_sei_cause;
};

} // namespace gaudi
#pragma pack(pop)
#endif /* ASIC_REG_STRUCTS_SOB_GLBL_H_ */
