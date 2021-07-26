/***********************************
** This is an auto-generated file **
**       DO NOT EDIT BELOW        **
************************************/

#ifndef ASIC_REG_STRUCTS_SYNC_MNGR_H_
#define ASIC_REG_STRUCTS_SYNC_MNGR_H_

#include <stdint.h>

#pragma pack(push, 1)

namespace sync_mngr {
} /* sync_mngr namespace */

#include "sob_glbl_regs.h"
#include "sob_objs_regs.h"
/*
 SYNC_MNGR block
*/
struct block_sync_mngr {
	struct block_sob_glbl sync_mngr_glbl;
	uint32_t _pad8[1022];
	struct block_sob_objs sync_mngr_objs;
};

#pragma pack(pop)
#endif /* ASIC_REG_STRUCTS_SYNC_MNGR_H_ */
