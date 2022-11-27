/***********************************
** This is an auto-generated file **
**       DO NOT EDIT BELOW        **
************************************/

#ifndef ASIC_REG_STRUCTS_SYNC_OBJECT_H_
#define ASIC_REG_STRUCTS_SYNC_OBJECT_H_

#include <stdint.h>
#include "gaudi2_types.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace gaudi2 {
namespace sync_object {
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
 MESSAGE 
 b'Sync Object message configurations'
*/
typedef struct reg_message {
	union {
		struct {
			uint32_t so_write_value : 16,
				rsv : 13,
				so_operation : 3;
		};
		uint32_t _raw;
	};
} reg_message;
static_assert((sizeof(struct reg_message) == 4), "reg_message size is not 32-bit");
/*
 ADDR 
 b'Sync Object address configuration'
*/
typedef struct reg_addr {
	union {
		struct {
			uint32_t v : 32;
		};
		uint32_t _raw;
	};
} reg_addr;
static_assert((sizeof(struct reg_addr) == 4), "reg_addr size is not 32-bit");

#ifdef __cplusplus
} /* sync_object namespace */
#endif

/*
 SYNC_OBJECT block
*/

#ifdef __cplusplus

struct block_sync_object {
	struct sync_object::reg_message message;
	struct sync_object::reg_addr addr;
};
#else

typedef struct block_sync_object {
	reg_message message;
	reg_addr addr;
} block_sync_object;
#endif


#ifdef __cplusplus
} /* gaudi2 namespace */
#endif

#pragma pack(pop)
#endif /* ASIC_REG_STRUCTS_SYNC_OBJECT_H_ */
