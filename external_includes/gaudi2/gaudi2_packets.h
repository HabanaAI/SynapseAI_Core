/* SPDX-License-Identifier: MIT
 *
 * Copyright 2020 HabanaLabs, Ltd.
 * All Rights Reserved.
 *
 */

#ifndef GAUDI2_PACKETS_H
#define GAUDI2_PACKETS_H

#include <linux/types.h>

#define PACKET_HEADER_PACKET_ID_SHIFT		56
#define PACKET_HEADER_PACKET_ID_MASK		0x1F00000000000000ull
namespace gaudi2
{
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
	PACKET_CB_LIST = 0xE,
	PACKET_LOAD_AND_EXE = 0xF,
	PACKET_WRITE_ARC_STREAM = 0x10,
	PACKET_WREG_64_SHORT = 0x12,
	PACKET_WREG_64_LONG = 0x13,
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
			__u32 swtc :1;
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
			__u32 swtc :1;
			__u32 msg_barrier :1;
		};
		__u32 ctl;
	};
};

struct packet_wreg32 {
	union {
		struct {
			__u32 reg_id :2;
			__u32 :30;
		};
		__u32 value;
	};
	union {
		struct {
			__u32 pred :5;
			__u32 reg :1;
			__u32 :2;
			__u32 reg_offset :16;
			__u32 opcode :5;
			__u32 eng_barrier :1;
			__u32 swtc :1;
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
			__u32 swtc :1;
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
			__u32 swtc :1;
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
			__u32 long_sob :1;
			__u32:3;
			__u32 cq_en :1;
			__u32 wr_num :2;
			__u32:1;
			__u32 lbw_en :1;
			__u32:7;
			__u32 msb_sid :4;
			__u32:11;
			__u32 long_high_group :1;
		} mon_config_register;
		struct {
			__u32 sync_value :15;
			__u32:9;
			__u32 long_mode :1;
			__u32:5;
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
			__u32 dw :1;
			__u32 :1;
			__u32 op :2;
			__u32 base :2;
			__u32 opcode :5;
			__u32 eng_barrier :1;
			__u32 swtc :1;
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
			__u32 swtc :1;
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
			__u32 swtc :1;
			__u32 msg_barrier :1;
		};
		__u32 ctl;
	};
};

struct packet_lin_dma {
	__u32 tsize;
	union {
		struct {
			__u32 wrcomp :1;
			__u32 endian :2;
			__u32 :1;
			__u32 memset :1;
			__u32 :1;
			__u32 bf16 :1;
			__u32 fp16 :1;
			__u32 context_id_inc :1;
			__u32 add_offset_0 :1;
			__u32 :14;
			__u32 opcode :5;
			__u32 eng_barrier :1;
			__u32 swtc :1;
			__u32 msg_barrier :1;
		};
		__u32 ctl;
	};
	__u64 src_addr;
	__u64 dst_addr;
};

struct packet_arb_point {
	union {
		struct {
			__u32 priority :24;
			__u32:7;
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
			__u32 :1;
			__u32 msg_barrier :1;
		};
		__u32 ctl;
	};
};

struct packet_repeat {
	__u32 sore :1;
	__u32 outer :1;
	__u32 :14;
	__u32 jmp_ptr :16;
	union {
		struct {
			__u32 pred :5;
			__u32 :19;
			__u32 opcode :5;
			__u32 eng_barrier :1;
			__u32 :1;
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
			__u32 :1;
			__u32 msg_barrier :1;
		};
		__u32 ctl;
	};
};

struct packet_cb_list {
	__u32 reserved;
	union {
		struct {
			__u32 pred :5;
			__u32 size_desc :1;
			__u32 :18;
			__u32 opcode :5;
			__u32 eng_barrier :1;
			__u32 :1;
			__u32 msg_barrier :1;
		};
		__u32 ctl;
	};
	__u64 index_addr;
	__u64 table_addr;
};

struct packet_load_and_exe {
	union {
		struct {
			__u32 dst :1;
			__u32 pmap :1;
			__u32 :6;
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
			__u32 swtc :1;
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
			__u32 upper_cp :1;
			__u32 :18;
			__u32 opcode :5;
			__u32 eng_barrier :1;
			__u32 :1;
			__u32 msg_barrier :1;
		};
		__u32 ctl;
	};
	__u64 src_addr;
};

struct packet_write_arc_stream {
	__u32 size64 :16;
	__u32 :16;
	union {
		struct {
			__u32 :24;
			__u32 opcode :5;
			__u32 eng_barrier :1;
			__u32 swtc :1;
			__u32 msg_barrier :1;
		};
		__u32 ctl;
	};
	__u64 values[0]; /* data starts here */
};

struct packet_wreg64_short {
	union {
		struct {
			__u32 reg_id :2;
			__u32 :30;
		};
		__u32 offset;
	};
	union {
		struct {
			__u32 pred :5;
			__u32 base :4;
			__u32 reg :1;
			__u32 dreg_offset :14;
			__u32 opcode :5;
			__u32 eng_barrier :1;
			__u32 swtc :1;
			__u32 msg_barrier :1;
		};
		__u32 ctl;
	};
};

struct packet_wreg64_long {
	__u32 dw_enable :2;
	__u32 :30;
	union {
		struct {
			__u32 pred :5;
			__u32 base :4;
			__u32 rel :1;
			__u32 dreg_offset :14;
			__u32 opcode :5;
			__u32 eng_barrier :1;
			__u32 swtc :1;
			__u32 msg_barrier :1;
		};
		__u32 ctl;
	};
	__u64 offset;
};

} //namespace gaudi2

#endif /* GAUDI2_PACKETS_ */
