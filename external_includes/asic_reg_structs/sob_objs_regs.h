/***********************************
** This is an auto-generated file **
**       DO NOT EDIT BELOW        **
************************************/

#ifndef ASIC_REG_STRUCTS_SOB_OBJS_H_
#define ASIC_REG_STRUCTS_SOB_OBJS_H_

#include <stdint.h>

#pragma pack(push, 1)

namespace sob_objs {
/*
 SM_SEC 
 security setting
*/
struct reg_sm_sec {
	union {
		struct {
			uint32_t sec_vec : 32;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_sm_sec) == 4), "reg_sm_sec size is not 32-bit");
/*
 SOB_OBJ 
 sync object
*/
struct reg_sob_obj {
	union {
		struct {
			uint32_t val : 15,
				_reserved30 : 15,
				trace_evict : 1,
				inc : 1;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_sob_obj) == 4), "reg_sob_obj size is not 32-bit");
/*
 MON_PAY_ADDRL 
 mon address payload
*/
struct reg_mon_pay_addrl {
	union {
		struct {
			uint32_t addrl : 32;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_mon_pay_addrl) == 4), "reg_mon_pay_addrl size is not 32-bit");
/*
 MON_PAY_ADDRH 
 mon address payload
*/
struct reg_mon_pay_addrh {
	union {
		struct {
			uint32_t addrh : 32;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_mon_pay_addrh) == 4), "reg_mon_pay_addrh size is not 32-bit");
/*
 MON_PAY_DATA 
 mon payload data
*/
struct reg_mon_pay_data {
	union {
		struct {
			uint32_t data : 32;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_mon_pay_data) == 4), "reg_mon_pay_data size is not 32-bit");
/*
 MON_ARM 
 MON ARM
*/
struct reg_mon_arm {
	union {
		struct {
			uint32_t sid : 8,
				mask : 8,
				sop : 1,
				sod : 15;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_mon_arm) == 4), "reg_mon_arm size is not 32-bit");
/*
 MON_STATUS 
 MON STATUS
*/
struct reg_mon_status {
	union {
		struct {
			uint32_t valid : 1,
				pending : 8,
				prot : 1,
				_reserved10 : 22;
		};
		uint32_t _raw;
	};
};
static_assert((sizeof(struct reg_mon_status) == 4), "reg_mon_status size is not 32-bit");
} /* sob_objs namespace */

/*
 SOB_OBJS block
*/
struct block_sob_objs {
	uint32_t _pad0[1024];
	struct sob_objs::reg_sob_obj sob_obj[2048];
	struct sob_objs::reg_mon_pay_addrl mon_pay_addrl[512];
	struct sob_objs::reg_mon_pay_addrh mon_pay_addrh[512];
	struct sob_objs::reg_mon_pay_data mon_pay_data[512];
	struct sob_objs::reg_mon_arm mon_arm[512];
	struct sob_objs::reg_mon_status mon_status[512];
	struct sob_objs::reg_sm_sec sm_sec[256];
};

#pragma pack(pop)
#endif /* ASIC_REG_STRUCTS_SOB_OBJS_H_ */
