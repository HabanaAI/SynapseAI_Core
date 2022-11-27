/***********************************
** This is an auto-generated file **
**       DO NOT EDIT BELOW        **
************************************/

#ifndef ASIC_REG_STRUCTS_SOB_OBJS_H_
#define ASIC_REG_STRUCTS_SOB_OBJS_H_

#include <stdint.h>
#include "gaudi2_types.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace gaudi2 {
namespace sob_objs {
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
 SOB_OBJ 
 b'Sync object counters'
*/
typedef struct reg_sob_obj {
	union {
		struct {
			uint32_t val : 15,
				_reserved24 : 9,
				long_sob : 1,
				_reserved30 : 5,
				trace_evict : 1,
				inc : 1;
		};
		uint32_t _raw;
	};
} reg_sob_obj;
static_assert((sizeof(struct reg_sob_obj) == 4), "reg_sob_obj size is not 32-bit");
/*
 MON_PAY_ADDRL 
 b'Monitor Address (LSB)'
*/
typedef struct reg_mon_pay_addrl {
	union {
		struct {
			uint32_t addrl : 32;
		};
		uint32_t _raw;
	};
} reg_mon_pay_addrl;
static_assert((sizeof(struct reg_mon_pay_addrl) == 4), "reg_mon_pay_addrl size is not 32-bit");
/*
 MON_PAY_ADDRH 
 b'Monitor Address (MSB)'
*/
typedef struct reg_mon_pay_addrh {
	union {
		struct {
			uint32_t addrh : 32;
		};
		uint32_t _raw;
	};
} reg_mon_pay_addrh;
static_assert((sizeof(struct reg_mon_pay_addrh) == 4), "reg_mon_pay_addrh size is not 32-bit");
/*
 MON_PAY_DATA 
 b'Monitor Data (Payload)'
*/
typedef struct reg_mon_pay_data {
	union {
		struct {
			uint32_t data : 32;
		};
		uint32_t _raw;
	};
} reg_mon_pay_data;
static_assert((sizeof(struct reg_mon_pay_data) == 4), "reg_mon_pay_data size is not 32-bit");
/*
 MON_ARM 
 b'Monitor ARM configuration'
*/
typedef struct reg_mon_arm {
	union {
		struct {
			uint32_t sid : 8,
				mask : 8,
				sop : 1,
				sod : 15;
		};
		uint32_t _raw;
	};
} reg_mon_arm;
static_assert((sizeof(struct reg_mon_arm) == 4), "reg_mon_arm size is not 32-bit");
/*
 MON_CONFIG 
 b'Monitor ARM configuration (Additional..)'
*/
typedef struct reg_mon_config {
	union {
		struct {
			uint32_t long_sob : 1,
				_reserved4 : 3,
				cq_en : 1,
				wr_num : 2,
				_reserved8 : 1,
				lbw_en : 1,
				_reserved16 : 7,
				msb_sid : 4,
				_reserved31 : 11,
				long_high_group : 1;
		};
		uint32_t _raw;
	};
} reg_mon_config;
static_assert((sizeof(struct reg_mon_config) == 4), "reg_mon_config size is not 32-bit");
/*
 MON_STATUS 
 b'Monitor status'
*/
typedef struct reg_mon_status {
	union {
		struct {
			uint32_t valid : 1,
				pending : 8,
				prot : 1,
				priv : 1,
				_reserved11 : 21;
		};
		uint32_t _raw;
	};
} reg_mon_status;
static_assert((sizeof(struct reg_mon_status) == 4), "reg_mon_status size is not 32-bit");
/*
 SM_SEC 
 b'SM security setting (Secured)'
*/
typedef struct reg_sm_sec {
	union {
		struct {
			uint32_t sec_vec : 32;
		};
		uint32_t _raw;
	};
} reg_sm_sec;
static_assert((sizeof(struct reg_sm_sec) == 4), "reg_sm_sec size is not 32-bit");
/*
 SM_PRIV 
 b'SM security setting (Privileged)'
*/
typedef struct reg_sm_priv {
	union {
		struct {
			uint32_t priv : 32;
		};
		uint32_t _raw;
	};
} reg_sm_priv;
static_assert((sizeof(struct reg_sm_priv) == 4), "reg_sm_priv size is not 32-bit");

#ifdef __cplusplus
} /* sob_objs namespace */
#endif

/*
 SOB_OBJS block
*/

#ifdef __cplusplus

struct block_sob_objs {
	struct sob_objs::reg_sob_obj sob_obj[8192];
	struct sob_objs::reg_mon_pay_addrl mon_pay_addrl[2048];
	struct sob_objs::reg_mon_pay_addrh mon_pay_addrh[2048];
	struct sob_objs::reg_mon_pay_data mon_pay_data[2048];
	struct sob_objs::reg_mon_arm mon_arm[2048];
	struct sob_objs::reg_mon_config mon_config[2048];
	struct sob_objs::reg_mon_status mon_status[2048];
	struct sob_objs::reg_sm_sec sm_sec[640];
	uint32_t _pad84480[384];
	struct sob_objs::reg_sm_priv sm_priv[640];
};
#else

typedef struct block_sob_objs {
	reg_sob_obj sob_obj[8192];
	reg_mon_pay_addrl mon_pay_addrl[2048];
	reg_mon_pay_addrh mon_pay_addrh[2048];
	reg_mon_pay_data mon_pay_data[2048];
	reg_mon_arm mon_arm[2048];
	reg_mon_config mon_config[2048];
	reg_mon_status mon_status[2048];
	reg_sm_sec sm_sec[640];
	uint32_t _pad84480[384];
	reg_sm_priv sm_priv[640];
} block_sob_objs;
#endif

const offsetVal block_sob_objs_defaults[] =
{
	// offset	// value
	{ 0x12000, 0x200               , 2048 }, // mon_status
	{ 0x14000, 0xffffffff          , 640 }, // sm_sec
	{ 0x15000, 0xffffffff          , 640 }, // sm_priv
};

#ifdef __cplusplus
} /* gaudi2 namespace */
#endif

#pragma pack(pop)
#endif /* ASIC_REG_STRUCTS_SOB_OBJS_H_ */
