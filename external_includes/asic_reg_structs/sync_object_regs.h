/***********************************
** This is an auto-generated file **
**       DO NOT EDIT BELOW        **
************************************/

#ifndef ASIC_REG_STRUCTS_SYNC_OBJECT_H_
#define ASIC_REG_STRUCTS_SYNC_OBJECT_H_

#include <stdint.h>

#pragma pack(push, 1)

namespace sync_object {
/*
 MESSAGE 
*/
struct reg_message {
	union {
		struct {
			uint32_t so_write_value : 16,
				rsv : 13,
				so_operation : 3;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_message) == 4), "reg_message size is not 32-bit");
/*
 ADDR 
*/
struct reg_addr {
	union {
		struct {
			uint32_t v : 32;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_addr) == 4), "reg_addr size is not 32-bit");
} /* sync_object namespace */

/*
 SYNC_OBJECT block
*/
struct block_sync_object {
	struct sync_object::reg_message message;
	struct sync_object::reg_addr addr;
};

#pragma pack(pop)
#endif /* ASIC_REG_STRUCTS_SYNC_OBJECT_H_ */
