/* SPDX-License-Identifier: MIT
 *
 * Copyright 2017-2021 HabanaLabs, Ltd.
 * All Rights Reserved.
 *
 */

#ifndef GAUDI_PACKETS_H
#define GAUDI_PACKETS_H

#include <linux/types.h>

#define PACKET_HEADER_PACKET_ID_SHIFT		56
#define PACKET_HEADER_PACKET_ID_MASK		0x1F00000000000000ull

enum packet_id {
	PACKET_WREG_32 = 0x1,
	PACKET_WREG_BULK = 0x2,
	PACKET_MSG_LONG = 0x3,
	PACKET_MSG_SHORT = 0x4,
	PACKET_CP_DMA = 0x5,
	PACKET_REPEAT = 0x6,
	PACKET_MSG_PROT = 0x7,
	PACKET_FENCE = 0x8,
	PACKET_LIN_DMA = 0x9,
	PACKET_NOP = 0xA,
	PACKET_STOP = 0xB,
	PACKET_ARB_POINT = 0xC,
	PACKET_WAIT = 0xD,
	PACKET_LOAD_AND_EXE = 0xF,
	MAX_PACKET_ID = (PACKET_HEADER_PACKET_ID_MASK >>
				PACKET_HEADER_PACKET_ID_SHIFT) + 1
};

struct packet_nop {
	__u32 reserved;
	union {
		struct {
			__u32 :24;
			__u32 opcode :5;
			__u32 eng_barrier :1;
			__u32 reg_barrier :1;
			__u32 msg_barrier :1;
		};
		__u32 ctl;
	};
};

struct packet_stop {
	__u32 reserved;
	union {
		struct {
			__u32 :24;
			__u32 opcode :5;
			__u32 eng_barrier :1;
			__u32 reg_barrier :1; /* must be 0 */
			__u32 msg_barrier :1; /* must be 0 */
		};
		__u32 ctl;
	};
};

struct packet_wreg32 {
	__u32 value;
	union {
		struct {
			__u32 pred :5;
			__u32 :3;
			__u32 reg_offset :16;
			__u32 opcode :5;
			__u32 eng_barrier :1;
			__u32 reg_barrier :1; /* must be 1 */
			__u32 msg_barrier :1;
		};
		__u32 ctl;
	};
};

struct packet_wreg_bulk {
	__u32 size64 :16;
	__u32 :16;
	union {
		struct {
			__u32 pred :5;
			__u32 :3;
			__u32 reg_offset :16;
			__u32 opcode :5;
			__u32 eng_barrier :1;
			__u32 reg_barrier :1; /* must be 1 */
			__u32 msg_barrier :1;
		};
		__u32 ctl;
	};
	__u64 values[0]; /* data starts here */
};

struct packet_msg_long {
	__u32 value;
	union {
		struct {
			__u32 pred :5;
			__u32 :11;
			__u32 weakly_ordered :1;
			__u32 no_snoop :1;
			__u32 :2;
			__u32 op :2; /* 0: write <value>. 1: write timestamp. */
			__u32 :2;
			__u32 opcode :5;
			__u32 eng_barrier :1;
			__u32 reg_barrier :1;
			__u32 msg_barrier :1;
		};
		__u32 ctl;
	};
	__u64 addr;
};

struct packet_msg_short {
	union {
		struct {
			__u32 sync_group_id :8;
			__u32 mask :8;
			__u32 mode :1;
			__u32 sync_value :15;
		} mon_arm_register;
		struct {
			__u32 sync_value :15;
			__u32 :15;
			__u32 te :1;
			__u32 mode :1;
		} so_upd;
		__u32 value;
	};
	union {
		struct {
			__u32 msg_addr_offset :16;
			__u32 weakly_ordered :1;
			__u32 no_snoop :1;
			__u32 :2;
			__u32 op :2;
			__u32 base :2;
			__u32 opcode :5;
			__u32 eng_barrier :1;
			__u32 reg_barrier :1;
			__u32 msg_barrier :1;
		};
		__u32 ctl;
	};
};

struct packet_msg_prot {
	__u32 value;
	union {
		struct {
			__u32 pred :5;
			__u32 :11;
			__u32 weakly_ordered :1;
			__u32 no_snoop :1;
			__u32 :2;
			__u32 op :2; /* 0: write <value>. 1: write timestamp. */
			__u32 :2;
			__u32 opcode :5;
			__u32 eng_barrier :1;
			__u32 reg_barrier :1;
			__u32 msg_barrier :1;
		};
		__u32 ctl;
	};
	__u64 addr;
};

struct packet_fence {
	union {
		struct {
			__u32 dec_val :4;
			__u32 :12;
			__u32 target_val :8;
			__u32 :6;
			__u32 id :2;
		};
		__u32 cfg;
	};
	union {
		struct {
			__u32 pred :5;
			__u32 :19;
			__u32 opcode :5;
			__u32 eng_barrier :1;
			__u32 reg_barrier :1;
			__u32 msg_barrier :1;
		};
		__u32 ctl;
	};
};

struct packet_lin_dma {
	__u32 tsize;
	union {
		struct {
			__u32 wr_comp_en :1;
			__u32 transpose:1;
			__u32 dtype :1;
			__u32 lin :1;		/* must be 1 for linear DMA */
			__u32 mem_set :1;
			__u32 compress :1;
			__u32 decompress :1;
			__u32 reserved: 9;
			__u32 context_id_low :8;
			__u32 opcode :5;
			__u32 eng_barrier :1;
			__u32 reg_barrier :1;	/* must be 1 */
			__u32 msg_barrier :1;
		};
		__u32 ctl;
	};
	__u64 src_addr;
	union {
		struct {
			__u64 dst_addr : 56 ;
			__u64 context_id_high :8;
		};
		__u64 dst_addr_ctx_id_raw;
	};
};

struct packet_arb_point {
	union {
		struct {
			__u32 priority :8;
			__u32:23;
			__u32 rls :1;
		};
		__u32 cfg;
	};
	union {
		struct {
			__u32 pred :5;
			__u32 :19;
			__u32 opcode :5;
			__u32 eng_barrier :1;
			__u32 reg_barrier :1;
			__u32 msg_barrier :1;
		};
		__u32 ctl;
	};
};

struct packet_repeat {
	__u32 sore :1;
	__u32 o :1;
	__u32 :14;
	__u32 jmp_ptr :16;
	union {
		struct {
			__u32 pred :5;
			__u32 :19;
			__u32 opcode :5;
			__u32 eng_barrier :1;
			__u32 reg_barrier :1; /* must be 1 */
			__u32 msg_barrier :1;
		};
		__u32 ctl;
	};
};

struct packet_wait {
	__u32 num_cycles_to_wait :24;
	__u32 inc_val :4;
	__u32 id :2;
	__u32 :2;
	union {
		struct {
			__u32 :24;
			__u32 opcode :5;
			__u32 eng_barrier :1;
			__u32 reg_barrier :1; /* must be 0 */
			__u32 msg_barrier :1;
		};
		__u32 ctl;
	};
};

struct packet_load_and_exe {
	union {
		struct {
			/* dst=1 means scalar mode which isn't allowed on
			 * external queues
			 */
			__u32 dst :1;
			__u32 :7;
			__u32 load :1;
			__u32 exe :1;
			__u32 etype :1;
			__u32 :21;
		};
		__u32 cfg;
	};
	union {
		struct {
			__u32 pred :5;
			__u32 :19;
			__u32 opcode :5;
			__u32 eng_barrier :1;
			__u32 reg_barrier :1; /* must be 1 */
			__u32 msg_barrier :1;
		};
		__u32 ctl;
	};
	__u64 src_addr;
};

struct packet_cp_dma {
	__u32 tsize;
	union {
		struct {
			__u32 pred :5;
			__u32 :19;
			__u32 opcode :5;
			__u32 eng_barrier :1;
			__u32 reg_barrier :1; /* must be 1 */
			__u32 msg_barrier :1;
		};
		__u32 ctl;
	};
	__u64 src_addr;
};

#endif /* GAUDI_PACKETS_H */
