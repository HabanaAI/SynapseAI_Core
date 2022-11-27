/* SPDX-License-Identifier: MIT
 *
 * Copyright 2016-2021 HabanaLabs, Ltd.
 * All Rights Reserved.
 *
 */


/************************************
** This is an auto-generated file **
**       DO NOT EDIT BELOW        **
************************************/

#ifndef TPC_IO_REG_SPACE_GEN2_H_
#define TPC_IO_REG_SPACE_GEN2_H_

/*
*****************************************
*   TPC0_CFG (Prototype: TPC)
*****************************************
*/
#define ECC_SERR_INJ                                                                    0xF10
#define ECC_SERR_INJ_SHIFT                                                                0
#define ECC_SERR_INJ_MASK                                                                 0xFF

#define ECC_DERR_INJ                                                                    0xF14
#define ECC_DERR_INJ_SHIFT                                                                0
#define ECC_DERR_INJ_MASK                                                                 0xFF

#define ECC_MEM_SEL                                                                     0xF18
#define ECC_MEM_SEL_SHIFT                                                                 0
#define ECC_MEM_SEL_MASK                                                                  0xFF

#define ECC_ADDR                                                                        0xF1C
#define ECC_ADDR_SHIFT                                                                    0
#define ECC_ADDR_MASK                                                                     0xFFFF

#define ECC_SYND                                                                        0xF20
#define ECC_SYND_SHIFT                                                                    0
#define ECC_SYND_MASK                                                                     0xFFFF

#define ECC_TYPE                                                                        0xF24
#define ECC_TYPE_SHIFT                                                                    0
#define ECC_TYPE_MASK                                                                     0x1

#define ECC_SERR_0                                                                        0xF30
#define ECC_SERR_SHIFT_0                                                                    0
#define ECC_SERR_MASK_0                                                                     0xFFFFFFFF

#define ECC_SERR_1                                                                        0xF34
#define ECC_SERR_SHIFT_1                                                                    0
#define ECC_SERR_MASK_1                                                                     0xFFFFFFFF

#define ECC_SERR_2                                                                        0xF38
#define ECC_SERR_SHIFT_2                                                                    0
#define ECC_SERR_MASK_2                                                                     0x3FFFFFF

#define ECC_DERR_0                                                                        0xF40
#define ECC_DERR_SHIFT_0                                                                    0
#define ECC_DERR_MASK_0                                                                     0xFFFFFFFF

#define ECC_DERR_1                                                                        0xF44
#define ECC_DERR_SHIFT_1                                                                    0
#define ECC_DERR_MASK_1                                                                     0xFFFFFFFF

#define ECC_DERR_2                                                                        0xF48
#define ECC_DERR_SHIFT_2                                                                    0
#define ECC_DERR_MASK_2                                                                     0x3FFFFFF

#define KERNEL_TENSOR_0_BASE_ADDR_LOW                                                   0x400

#define KERNEL_TENSOR_0_BASE_ADDR_LOW_V_SHIFT                                             0
#define KERNEL_TENSOR_0_BASE_ADDR_LOW_V_MASK                                              0xFFFFFFFF

#define KERNEL_TENSOR_0_BASE_ADDR_HIGH                                                  0x404

#define KERNEL_TENSOR_0_BASE_ADDR_HIGH_V_SHIFT                                            0
#define KERNEL_TENSOR_0_BASE_ADDR_HIGH_V_MASK                                             0xFFFFFFFF

#define KERNEL_TENSOR_0_PADDING_VALUE                                                   0x408

#define KERNEL_TENSOR_0_PADDING_VALUE_V_SHIFT                                             0
#define KERNEL_TENSOR_0_PADDING_VALUE_V_MASK                                              0xFFFFFFFF

#define KERNEL_TENSOR_0_TENSOR_CONFIG                                                   0x40C

#define KERNEL_TENSOR_0_TENSOR_CONFIG_DATA_TYPE_SHIFT                                     0
#define KERNEL_TENSOR_0_TENSOR_CONFIG_DATA_TYPE_MASK                                      0x7
#define KERNEL_TENSOR_0_TENSOR_CONFIG_VALID_DIM_MASK_SHIFT                                8
#define KERNEL_TENSOR_0_TENSOR_CONFIG_VALID_DIM_MASK_MASK                                 0x1F00
#define KERNEL_TENSOR_0_TENSOR_CONFIG_LAST_DIM_SHIFT                                      16
#define KERNEL_TENSOR_0_TENSOR_CONFIG_LAST_DIM_MASK                                       0x70000
#define KERNEL_TENSOR_0_TENSOR_CONFIG_RMW_SET_SHIFT                                       19
#define KERNEL_TENSOR_0_TENSOR_CONFIG_RMW_SET_MASK                                        0x80000
#define KERNEL_TENSOR_0_TENSOR_CONFIG_RMW_RESERV_SHIFT                                    20
#define KERNEL_TENSOR_0_TENSOR_CONFIG_RMW_RESERV_MASK                                     0x100000
#define KERNEL_TENSOR_0_TENSOR_CONFIG_RMW_OP_SHIFT                                        21
#define KERNEL_TENSOR_0_TENSOR_CONFIG_RMW_OP_MASK                                         0x600000

#define KERNEL_TENSOR_0_DIM_0_SIZE                                                      0x410

#define KERNEL_TENSOR_0_DIM_0_SIZE_V_SHIFT                                                0
#define KERNEL_TENSOR_0_DIM_0_SIZE_V_MASK                                                 0xFFFFFFFF

#define KERNEL_TENSOR_0_DIM_0_STRIDE                                                    0x414

#define KERNEL_TENSOR_0_DIM_0_STRIDE_V_SHIFT                                              0
#define KERNEL_TENSOR_0_DIM_0_STRIDE_V_MASK                                               0xFFFFFFFF

#define KERNEL_TENSOR_0_DIM_1_SIZE                                                      0x418

#define KERNEL_TENSOR_0_DIM_1_SIZE_V_SHIFT                                                0
#define KERNEL_TENSOR_0_DIM_1_SIZE_V_MASK                                                 0xFFFFFFFF

#define KERNEL_TENSOR_0_DIM_1_STRIDE                                                    0x41C

#define KERNEL_TENSOR_0_DIM_1_STRIDE_V_SHIFT                                              0
#define KERNEL_TENSOR_0_DIM_1_STRIDE_V_MASK                                               0xFFFFFFFF

#define KERNEL_TENSOR_0_DIM_2_SIZE                                                      0x420

#define KERNEL_TENSOR_0_DIM_2_SIZE_V_SHIFT                                                0
#define KERNEL_TENSOR_0_DIM_2_SIZE_V_MASK                                                 0xFFFFFFFF

#define KERNEL_TENSOR_0_DIM_2_STRIDE                                                    0x424

#define KERNEL_TENSOR_0_DIM_2_STRIDE_V_SHIFT                                              0
#define KERNEL_TENSOR_0_DIM_2_STRIDE_V_MASK                                               0xFFFFFFFF

#define KERNEL_TENSOR_0_DIM_3_SIZE                                                      0x428

#define KERNEL_TENSOR_0_DIM_3_SIZE_V_SHIFT                                                0
#define KERNEL_TENSOR_0_DIM_3_SIZE_V_MASK                                                 0xFFFFFFFF

#define KERNEL_TENSOR_0_DIM_3_STRIDE                                                    0x42C

#define KERNEL_TENSOR_0_DIM_3_STRIDE_V_SHIFT                                              0
#define KERNEL_TENSOR_0_DIM_3_STRIDE_V_MASK                                               0xFFFFFFFF

#define KERNEL_TENSOR_0_DIM_4_SIZE                                                      0x430

#define KERNEL_TENSOR_0_DIM_4_SIZE_V_SHIFT                                                0
#define KERNEL_TENSOR_0_DIM_4_SIZE_V_MASK                                                 0xFFFFFFFF

#define KERNEL_TENSOR_0_DIM_4_STRIDE                                                    0x434

#define KERNEL_TENSOR_0_DIM_4_STRIDE_V_SHIFT                                              0
#define KERNEL_TENSOR_0_DIM_4_STRIDE_V_MASK                                               0xFFFFFFFF

#define KERNEL_TENSOR_1_BASE_ADDR_LOW                                                   0x438

#define KERNEL_TENSOR_1_BASE_ADDR_LOW_V_SHIFT                                             0
#define KERNEL_TENSOR_1_BASE_ADDR_LOW_V_MASK                                              0xFFFFFFFF

#define KERNEL_TENSOR_1_BASE_ADDR_HIGH                                                  0x43C

#define KERNEL_TENSOR_1_BASE_ADDR_HIGH_V_SHIFT                                            0
#define KERNEL_TENSOR_1_BASE_ADDR_HIGH_V_MASK                                             0xFFFFFFFF

#define KERNEL_TENSOR_1_PADDING_VALUE                                                   0x440

#define KERNEL_TENSOR_1_PADDING_VALUE_V_SHIFT                                             0
#define KERNEL_TENSOR_1_PADDING_VALUE_V_MASK                                              0xFFFFFFFF

#define KERNEL_TENSOR_1_TENSOR_CONFIG                                                   0x444

#define KERNEL_TENSOR_1_TENSOR_CONFIG_DATA_TYPE_SHIFT                                     0
#define KERNEL_TENSOR_1_TENSOR_CONFIG_DATA_TYPE_MASK                                      0x7
#define KERNEL_TENSOR_1_TENSOR_CONFIG_VALID_DIM_MASK_SHIFT                                8
#define KERNEL_TENSOR_1_TENSOR_CONFIG_VALID_DIM_MASK_MASK                                 0x1F00
#define KERNEL_TENSOR_1_TENSOR_CONFIG_LAST_DIM_SHIFT                                      16
#define KERNEL_TENSOR_1_TENSOR_CONFIG_LAST_DIM_MASK                                       0x70000
#define KERNEL_TENSOR_1_TENSOR_CONFIG_RMW_SET_SHIFT                                       19
#define KERNEL_TENSOR_1_TENSOR_CONFIG_RMW_SET_MASK                                        0x80000
#define KERNEL_TENSOR_1_TENSOR_CONFIG_RMW_RESERV_SHI	`FT                                    20
#define KERNEL_TENSOR_1_TENSOR_CONFIG_RMW_RESERV_MASK                                     0x100000
#define KERNEL_TENSOR_1_TENSOR_CONFIG_RMW_OP_SHIFT                                        21
#define KERNEL_TENSOR_1_TENSOR_CONFIG_RMW_OP_MASK                                         0x600000

#define KERNEL_TENSOR_1_DIM_0_SIZE                                                      0x448

#define KERNEL_TENSOR_1_DIM_0_SIZE_V_SHIFT                                                0
#define KERNEL_TENSOR_1_DIM_0_SIZE_V_MASK                                                 0xFFFFFFFF

#define KERNEL_TENSOR_1_DIM_0_STRIDE                                                    0x44C

#define KERNEL_TENSOR_1_DIM_0_STRIDE_V_SHIFT                                              0
#define KERNEL_TENSOR_1_DIM_0_STRIDE_V_MASK                                               0xFFFFFFFF

#define KERNEL_TENSOR_1_DIM_1_SIZE                                                      0x450

#define KERNEL_TENSOR_1_DIM_1_SIZE_V_SHIFT                                                0
#define KERNEL_TENSOR_1_DIM_1_SIZE_V_MASK                                                 0xFFFFFFFF

#define KERNEL_TENSOR_1_DIM_1_STRIDE                                                    0x454

#define KERNEL_TENSOR_1_DIM_1_STRIDE_V_SHIFT                                              0
#define KERNEL_TENSOR_1_DIM_1_STRIDE_V_MASK                                               0xFFFFFFFF

#define KERNEL_TENSOR_1_DIM_2_SIZE                                                      0x458

#define KERNEL_TENSOR_1_DIM_2_SIZE_V_SHIFT                                                0
#define KERNEL_TENSOR_1_DIM_2_SIZE_V_MASK                                                 0xFFFFFFFF

#define KERNEL_TENSOR_1_DIM_2_STRIDE                                                    0x45C

#define KERNEL_TENSOR_1_DIM_2_STRIDE_V_SHIFT                                              0
#define KERNEL_TENSOR_1_DIM_2_STRIDE_V_MASK                                               0xFFFFFFFF

#define KERNEL_TENSOR_1_DIM_3_SIZE                                                      0x460

#define KERNEL_TENSOR_1_DIM_3_SIZE_V_SHIFT                                                0
#define KERNEL_TENSOR_1_DIM_3_SIZE_V_MASK                                                 0xFFFFFFFF

#define KERNEL_TENSOR_1_DIM_3_STRIDE                                                    0x464

#define KERNEL_TENSOR_1_DIM_3_STRIDE_V_SHIFT                                              0
#define KERNEL_TENSOR_1_DIM_3_STRIDE_V_MASK                                               0xFFFFFFFF

#define KERNEL_TENSOR_1_DIM_4_SIZE                                                      0x468

#define KERNEL_TENSOR_1_DIM_4_SIZE_V_SHIFT                                                0
#define KERNEL_TENSOR_1_DIM_4_SIZE_V_MASK                                                 0xFFFFFFFF

#define KERNEL_TENSOR_1_DIM_4_STRIDE                                                    0x46C

#define KERNEL_TENSOR_1_DIM_4_STRIDE_V_SHIFT                                              0
#define KERNEL_TENSOR_1_DIM_4_STRIDE_V_MASK                                               0xFFFFFFFF

#define KERNEL_TENSOR_2_BASE_ADDR_LOW                                                   0x470

#define KERNEL_TENSOR_2_BASE_ADDR_LOW_V_SHIFT                                             0
#define KERNEL_TENSOR_2_BASE_ADDR_LOW_V_MASK                                              0xFFFFFFFF

#define KERNEL_TENSOR_2_BASE_ADDR_HIGH                                                  0x474

#define KERNEL_TENSOR_2_BASE_ADDR_HIGH_V_SHIFT                                            0
#define KERNEL_TENSOR_2_BASE_ADDR_HIGH_V_MASK                                             0xFFFFFFFF

#define KERNEL_TENSOR_2_PADDING_VALUE                                                   0x478

#define KERNEL_TENSOR_2_PADDING_VALUE_V_SHIFT                                             0
#define KERNEL_TENSOR_2_PADDING_VALUE_V_MASK                                              0xFFFFFFFF

#define KERNEL_TENSOR_2_TENSOR_CONFIG                                                   0x47C

#define KERNEL_TENSOR_2_TENSOR_CONFIG_DATA_TYPE_SHIFT                                     0
#define KERNEL_TENSOR_2_TENSOR_CONFIG_DATA_TYPE_MASK                                      0x7
#define KERNEL_TENSOR_2_TENSOR_CONFIG_VALID_DIM_MASK_SHIFT                                8
#define KERNEL_TENSOR_2_TENSOR_CONFIG_VALID_DIM_MASK_MASK                                 0x1F00
#define KERNEL_TENSOR_2_TENSOR_CONFIG_LAST_DIM_SHIFT                                      16
#define KERNEL_TENSOR_2_TENSOR_CONFIG_LAST_DIM_MASK                                       0x70000
#define KERNEL_TENSOR_2_TENSOR_CONFIG_RMW_SET_SHIFT                                       19
#define KERNEL_TENSOR_2_TENSOR_CONFIG_RMW_SET_MASK                                        0x80000
#define KERNEL_TENSOR_2_TENSOR_CONFIG_RMW_RESERV_SHIFT                                    20
#define KERNEL_TENSOR_2_TENSOR_CONFIG_RMW_RESERV_MASK                                     0x100000
#define KERNEL_TENSOR_2_TENSOR_CONFIG_RMW_OP_SHIFT                                        21
#define KERNEL_TENSOR_2_TENSOR_CONFIG_RMW_OP_MASK                                         0x600000

#define KERNEL_TENSOR_2_DIM_0_SIZE                                                      0x480

#define KERNEL_TENSOR_2_DIM_0_SIZE_V_SHIFT                                                0
#define KERNEL_TENSOR_2_DIM_0_SIZE_V_MASK                                                 0xFFFFFFFF

#define KERNEL_TENSOR_2_DIM_0_STRIDE                                                    0x484

#define KERNEL_TENSOR_2_DIM_0_STRIDE_V_SHIFT                                              0
#define KERNEL_TENSOR_2_DIM_0_STRIDE_V_MASK                                               0xFFFFFFFF

#define KERNEL_TENSOR_2_DIM_1_SIZE                                                      0x488

#define KERNEL_TENSOR_2_DIM_1_SIZE_V_SHIFT                                                0
#define KERNEL_TENSOR_2_DIM_1_SIZE_V_MASK                                                 0xFFFFFFFF

#define KERNEL_TENSOR_2_DIM_1_STRIDE                                                    0x48C

#define KERNEL_TENSOR_2_DIM_1_STRIDE_V_SHIFT                                              0
#define KERNEL_TENSOR_2_DIM_1_STRIDE_V_MASK                                               0xFFFFFFFF

#define KERNEL_TENSOR_2_DIM_2_SIZE                                                      0x490

#define KERNEL_TENSOR_2_DIM_2_SIZE_V_SHIFT                                                0
#define KERNEL_TENSOR_2_DIM_2_SIZE_V_MASK                                                 0xFFFFFFFF

#define KERNEL_TENSOR_2_DIM_2_STRIDE                                                    0x494

#define KERNEL_TENSOR_2_DIM_2_STRIDE_V_SHIFT                                              0
#define KERNEL_TENSOR_2_DIM_2_STRIDE_V_MASK                                               0xFFFFFFFF

#define KERNEL_TENSOR_2_DIM_3_SIZE                                                      0x498

#define KERNEL_TENSOR_2_DIM_3_SIZE_V_SHIFT                                                0
#define KERNEL_TENSOR_2_DIM_3_SIZE_V_MASK                                                 0xFFFFFFFF

#define KERNEL_TENSOR_2_DIM_3_STRIDE                                                    0x49C

#define KERNEL_TENSOR_2_DIM_3_STRIDE_V_SHIFT                                              0
#define KERNEL_TENSOR_2_DIM_3_STRIDE_V_MASK                                               0xFFFFFFFF

#define KERNEL_TENSOR_2_DIM_4_SIZE                                                      0x4A0

#define KERNEL_TENSOR_2_DIM_4_SIZE_V_SHIFT                                                0
#define KERNEL_TENSOR_2_DIM_4_SIZE_V_MASK                                                 0xFFFFFFFF

#define KERNEL_TENSOR_2_DIM_4_STRIDE                                                    0x4A4

#define KERNEL_TENSOR_2_DIM_4_STRIDE_V_SHIFT                                              0
#define KERNEL_TENSOR_2_DIM_4_STRIDE_V_MASK                                               0xFFFFFFFF

#define KERNEL_TENSOR_3_BASE_ADDR_LOW                                                   0x4A8

#define KERNEL_TENSOR_3_BASE_ADDR_LOW_V_SHIFT                                             0
#define KERNEL_TENSOR_3_BASE_ADDR_LOW_V_MASK                                              0xFFFFFFFF

#define KERNEL_TENSOR_3_BASE_ADDR_HIGH                                                  0x4AC

#define KERNEL_TENSOR_3_BASE_ADDR_HIGH_V_SHIFT                                            0
#define KERNEL_TENSOR_3_BASE_ADDR_HIGH_V_MASK                                             0xFFFFFFFF

#define KERNEL_TENSOR_3_PADDING_VALUE                                                   0x4B0

#define KERNEL_TENSOR_3_PADDING_VALUE_V_SHIFT                                             0
#define KERNEL_TENSOR_3_PADDING_VALUE_V_MASK                                              0xFFFFFFFF

#define KERNEL_TENSOR_3_TENSOR_CONFIG                                                   0x4B4

#define KERNEL_TENSOR_3_TENSOR_CONFIG_DATA_TYPE_SHIFT                                     0
#define KERNEL_TENSOR_3_TENSOR_CONFIG_DATA_TYPE_MASK                                      0x7
#define KERNEL_TENSOR_3_TENSOR_CONFIG_VALID_DIM_MASK_SHIFT                                8
#define KERNEL_TENSOR_3_TENSOR_CONFIG_VALID_DIM_MASK_MASK                                 0x1F00
#define KERNEL_TENSOR_3_TENSOR_CONFIG_LAST_DIM_SHIFT                                      16
#define KERNEL_TENSOR_3_TENSOR_CONFIG_LAST_DIM_MASK                                       0x70000
#define KERNEL_TENSOR_3_TENSOR_CONFIG_RMW_SET_SHIFT                                       19
#define KERNEL_TENSOR_3_TENSOR_CONFIG_RMW_SET_MASK                                        0x80000
#define KERNEL_TENSOR_3_TENSOR_CONFIG_RMW_RESERV_SHIFT                                    20
#define KERNEL_TENSOR_3_TENSOR_CONFIG_RMW_RESERV_MASK                                     0x100000
#define KERNEL_TENSOR_3_TENSOR_CONFIG_RMW_OP_SHIFT                                        21
#define KERNEL_TENSOR_3_TENSOR_CONFIG_RMW_OP_MASK                                         0x600000

#define KERNEL_TENSOR_3_DIM_0_SIZE                                                      0x4B8

#define KERNEL_TENSOR_3_DIM_0_SIZE_V_SHIFT                                                0
#define KERNEL_TENSOR_3_DIM_0_SIZE_V_MASK                                                 0xFFFFFFFF

#define KERNEL_TENSOR_3_DIM_0_STRIDE                                                    0x4BC

#define KERNEL_TENSOR_3_DIM_0_STRIDE_V_SHIFT                                              0
#define KERNEL_TENSOR_3_DIM_0_STRIDE_V_MASK                                               0xFFFFFFFF

#define KERNEL_TENSOR_3_DIM_1_SIZE                                                      0x4C0

#define KERNEL_TENSOR_3_DIM_1_SIZE_V_SHIFT                                                0
#define KERNEL_TENSOR_3_DIM_1_SIZE_V_MASK                                                 0xFFFFFFFF

#define KERNEL_TENSOR_3_DIM_1_STRIDE                                                    0x4C4

#define KERNEL_TENSOR_3_DIM_1_STRIDE_V_SHIFT                                              0
#define KERNEL_TENSOR_3_DIM_1_STRIDE_V_MASK                                               0xFFFFFFFF

#define KERNEL_TENSOR_3_DIM_2_SIZE                                                      0x4C8

#define KERNEL_TENSOR_3_DIM_2_SIZE_V_SHIFT                                                0
#define KERNEL_TENSOR_3_DIM_2_SIZE_V_MASK                                                 0xFFFFFFFF

#define KERNEL_TENSOR_3_DIM_2_STRIDE                                                    0x4CC

#define KERNEL_TENSOR_3_DIM_2_STRIDE_V_SHIFT                                              0
#define KERNEL_TENSOR_3_DIM_2_STRIDE_V_MASK                                               0xFFFFFFFF

#define KERNEL_TENSOR_3_DIM_3_SIZE                                                      0x4D0

#define KERNEL_TENSOR_3_DIM_3_SIZE_V_SHIFT                                                0
#define KERNEL_TENSOR_3_DIM_3_SIZE_V_MASK                                                 0xFFFFFFFF

#define KERNEL_TENSOR_3_DIM_3_STRIDE                                                    0x4D4

#define KERNEL_TENSOR_3_DIM_3_STRIDE_V_SHIFT                                              0
#define KERNEL_TENSOR_3_DIM_3_STRIDE_V_MASK                                               0xFFFFFFFF

#define KERNEL_TENSOR_3_DIM_4_SIZE                                                      0x4D8

#define KERNEL_TENSOR_3_DIM_4_SIZE_V_SHIFT                                                0
#define KERNEL_TENSOR_3_DIM_4_SIZE_V_MASK                                                 0xFFFFFFFF

#define KERNEL_TENSOR_3_DIM_4_STRIDE                                                    0x4DC

#define KERNEL_TENSOR_3_DIM_4_STRIDE_V_SHIFT                                              0
#define KERNEL_TENSOR_3_DIM_4_STRIDE_V_MASK                                               0xFFFFFFFF

#define KERNEL_TENSOR_4_BASE_ADDR_LOW                                                   0x4E0

#define KERNEL_TENSOR_4_BASE_ADDR_LOW_V_SHIFT                                             0
#define KERNEL_TENSOR_4_BASE_ADDR_LOW_V_MASK                                              0xFFFFFFFF

#define KERNEL_TENSOR_4_BASE_ADDR_HIGH                                                  0x4E4

#define KERNEL_TENSOR_4_BASE_ADDR_HIGH_V_SHIFT                                            0
#define KERNEL_TENSOR_4_BASE_ADDR_HIGH_V_MASK                                             0xFFFFFFFF

#define KERNEL_TENSOR_4_PADDING_VALUE                                                   0x4E8

#define KERNEL_TENSOR_4_PADDING_VALUE_V_SHIFT                                             0
#define KERNEL_TENSOR_4_PADDING_VALUE_V_MASK                                              0xFFFFFFFF

#define KERNEL_TENSOR_4_TENSOR_CONFIG                                                   0x4EC

#define KERNEL_TENSOR_4_TENSOR_CONFIG_DATA_TYPE_SHIFT                                     0
#define KERNEL_TENSOR_4_TENSOR_CONFIG_DATA_TYPE_MASK                                      0x7
#define KERNEL_TENSOR_4_TENSOR_CONFIG_VALID_DIM_MASK_SHIFT                                8
#define KERNEL_TENSOR_4_TENSOR_CONFIG_VALID_DIM_MASK_MASK                                 0x1F00
#define KERNEL_TENSOR_4_TENSOR_CONFIG_LAST_DIM_SHIFT                                      16
#define KERNEL_TENSOR_4_TENSOR_CONFIG_LAST_DIM_MASK                                       0x70000
#define KERNEL_TENSOR_4_TENSOR_CONFIG_RMW_SET_SHIFT                                       19
#define KERNEL_TENSOR_4_TENSOR_CONFIG_RMW_SET_MASK                                        0x80000
#define KERNEL_TENSOR_4_TENSOR_CONFIG_RMW_RESERV_SHIFT                                    20
#define KERNEL_TENSOR_4_TENSOR_CONFIG_RMW_RESERV_MASK                                     0x100000
#define KERNEL_TENSOR_4_TENSOR_CONFIG_RMW_OP_SHIFT                                        21
#define KERNEL_TENSOR_4_TENSOR_CONFIG_RMW_OP_MASK                                         0x600000

#define KERNEL_TENSOR_4_DIM_0_SIZE                                                      0x4F0

#define KERNEL_TENSOR_4_DIM_0_SIZE_V_SHIFT                                                0
#define KERNEL_TENSOR_4_DIM_0_SIZE_V_MASK                                                 0xFFFFFFFF

#define KERNEL_TENSOR_4_DIM_0_STRIDE                                                    0x4F4

#define KERNEL_TENSOR_4_DIM_0_STRIDE_V_SHIFT                                              0
#define KERNEL_TENSOR_4_DIM_0_STRIDE_V_MASK                                               0xFFFFFFFF

#define KERNEL_TENSOR_4_DIM_1_SIZE                                                      0x4F8

#define KERNEL_TENSOR_4_DIM_1_SIZE_V_SHIFT                                                0
#define KERNEL_TENSOR_4_DIM_1_SIZE_V_MASK                                                 0xFFFFFFFF

#define KERNEL_TENSOR_4_DIM_1_STRIDE                                                    0x4FC

#define KERNEL_TENSOR_4_DIM_1_STRIDE_V_SHIFT                                              0
#define KERNEL_TENSOR_4_DIM_1_STRIDE_V_MASK                                               0xFFFFFFFF

#define KERNEL_TENSOR_4_DIM_2_SIZE                                                      0x500

#define KERNEL_TENSOR_4_DIM_2_SIZE_V_SHIFT                                                0
#define KERNEL_TENSOR_4_DIM_2_SIZE_V_MASK                                                 0xFFFFFFFF

#define KERNEL_TENSOR_4_DIM_2_STRIDE                                                    0x504

#define KERNEL_TENSOR_4_DIM_2_STRIDE_V_SHIFT                                              0
#define KERNEL_TENSOR_4_DIM_2_STRIDE_V_MASK                                               0xFFFFFFFF

#define KERNEL_TENSOR_4_DIM_3_SIZE                                                      0x508

#define KERNEL_TENSOR_4_DIM_3_SIZE_V_SHIFT                                                0
#define KERNEL_TENSOR_4_DIM_3_SIZE_V_MASK                                                 0xFFFFFFFF

#define KERNEL_TENSOR_4_DIM_3_STRIDE                                                    0x50C

#define KERNEL_TENSOR_4_DIM_3_STRIDE_V_SHIFT                                              0
#define KERNEL_TENSOR_4_DIM_3_STRIDE_V_MASK                                               0xFFFFFFFF

#define KERNEL_TENSOR_4_DIM_4_SIZE                                                      0x510

#define KERNEL_TENSOR_4_DIM_4_SIZE_V_SHIFT                                                0
#define KERNEL_TENSOR_4_DIM_4_SIZE_V_MASK                                                 0xFFFFFFFF

#define KERNEL_TENSOR_4_DIM_4_STRIDE                                                    0x514

#define KERNEL_TENSOR_4_DIM_4_STRIDE_V_SHIFT                                              0
#define KERNEL_TENSOR_4_DIM_4_STRIDE_V_MASK                                               0xFFFFFFFF

#define KERNEL_TENSOR_5_BASE_ADDR_LOW                                                   0x518

#define KERNEL_TENSOR_5_BASE_ADDR_LOW_V_SHIFT                                             0
#define KERNEL_TENSOR_5_BASE_ADDR_LOW_V_MASK                                              0xFFFFFFFF

#define KERNEL_TENSOR_5_BASE_ADDR_HIGH                                                  0x51C

#define KERNEL_TENSOR_5_BASE_ADDR_HIGH_V_SHIFT                                            0
#define KERNEL_TENSOR_5_BASE_ADDR_HIGH_V_MASK                                             0xFFFFFFFF

#define KERNEL_TENSOR_5_PADDING_VALUE                                                   0x520

#define KERNEL_TENSOR_5_PADDING_VALUE_V_SHIFT                                             0
#define KERNEL_TENSOR_5_PADDING_VALUE_V_MASK                                              0xFFFFFFFF

#define KERNEL_TENSOR_5_TENSOR_CONFIG                                                   0x524

#define KERNEL_TENSOR_5_TENSOR_CONFIG_DATA_TYPE_SHIFT                                     0
#define KERNEL_TENSOR_5_TENSOR_CONFIG_DATA_TYPE_MASK                                      0x7
#define KERNEL_TENSOR_5_TENSOR_CONFIG_VALID_DIM_MASK_SHIFT                                8
#define KERNEL_TENSOR_5_TENSOR_CONFIG_VALID_DIM_MASK_MASK                                 0x1F00
#define KERNEL_TENSOR_5_TENSOR_CONFIG_LAST_DIM_SHIFT                                      16
#define KERNEL_TENSOR_5_TENSOR_CONFIG_LAST_DIM_MASK                                       0x70000
#define KERNEL_TENSOR_5_TENSOR_CONFIG_RMW_SET_SHIFT                                       19
#define KERNEL_TENSOR_5_TENSOR_CONFIG_RMW_SET_MASK                                        0x80000
#define KERNEL_TENSOR_5_TENSOR_CONFIG_RMW_RESERV_SHIFT                                    20
#define KERNEL_TENSOR_5_TENSOR_CONFIG_RMW_RESERV_MASK                                     0x100000
#define KERNEL_TENSOR_5_TENSOR_CONFIG_RMW_OP_SHIFT                                        21
#define KERNEL_TENSOR_5_TENSOR_CONFIG_RMW_OP_MASK                                         0x600000

#define KERNEL_TENSOR_5_DIM_0_SIZE                                                      0x528

#define KERNEL_TENSOR_5_DIM_0_SIZE_V_SHIFT                                                0
#define KERNEL_TENSOR_5_DIM_0_SIZE_V_MASK                                                 0xFFFFFFFF

#define KERNEL_TENSOR_5_DIM_0_STRIDE                                                    0x52C

#define KERNEL_TENSOR_5_DIM_0_STRIDE_V_SHIFT                                              0
#define KERNEL_TENSOR_5_DIM_0_STRIDE_V_MASK                                               0xFFFFFFFF

#define KERNEL_TENSOR_5_DIM_1_SIZE                                                      0x530

#define KERNEL_TENSOR_5_DIM_1_SIZE_V_SHIFT                                                0
#define KERNEL_TENSOR_5_DIM_1_SIZE_V_MASK                                                 0xFFFFFFFF

#define KERNEL_TENSOR_5_DIM_1_STRIDE                                                    0x534

#define KERNEL_TENSOR_5_DIM_1_STRIDE_V_SHIFT                                              0
#define KERNEL_TENSOR_5_DIM_1_STRIDE_V_MASK                                               0xFFFFFFFF

#define KERNEL_TENSOR_5_DIM_2_SIZE                                                      0x538

#define KERNEL_TENSOR_5_DIM_2_SIZE_V_SHIFT                                                0
#define KERNEL_TENSOR_5_DIM_2_SIZE_V_MASK                                                 0xFFFFFFFF

#define KERNEL_TENSOR_5_DIM_2_STRIDE                                                    0x53C

#define KERNEL_TENSOR_5_DIM_2_STRIDE_V_SHIFT                                              0
#define KERNEL_TENSOR_5_DIM_2_STRIDE_V_MASK                                               0xFFFFFFFF

#define KERNEL_TENSOR_5_DIM_3_SIZE                                                      0x540

#define KERNEL_TENSOR_5_DIM_3_SIZE_V_SHIFT                                                0
#define KERNEL_TENSOR_5_DIM_3_SIZE_V_MASK                                                 0xFFFFFFFF

#define KERNEL_TENSOR_5_DIM_3_STRIDE                                                    0x544

#define KERNEL_TENSOR_5_DIM_3_STRIDE_V_SHIFT                                              0
#define KERNEL_TENSOR_5_DIM_3_STRIDE_V_MASK                                               0xFFFFFFFF

#define KERNEL_TENSOR_5_DIM_4_SIZE                                                      0x548

#define KERNEL_TENSOR_5_DIM_4_SIZE_V_SHIFT                                                0
#define KERNEL_TENSOR_5_DIM_4_SIZE_V_MASK                                                 0xFFFFFFFF

#define KERNEL_TENSOR_5_DIM_4_STRIDE                                                    0x54C

#define KERNEL_TENSOR_5_DIM_4_STRIDE_V_SHIFT                                              0
#define KERNEL_TENSOR_5_DIM_4_STRIDE_V_MASK                                               0xFFFFFFFF

#define KERNEL_TENSOR_6_BASE_ADDR_LOW                                                   0x550

#define KERNEL_TENSOR_6_BASE_ADDR_LOW_V_SHIFT                                             0
#define KERNEL_TENSOR_6_BASE_ADDR_LOW_V_MASK                                              0xFFFFFFFF

#define KERNEL_TENSOR_6_BASE_ADDR_HIGH                                                  0x554

#define KERNEL_TENSOR_6_BASE_ADDR_HIGH_V_SHIFT                                            0
#define KERNEL_TENSOR_6_BASE_ADDR_HIGH_V_MASK                                             0xFFFFFFFF

#define KERNEL_TENSOR_6_PADDING_VALUE                                                   0x558

#define KERNEL_TENSOR_6_PADDING_VALUE_V_SHIFT                                             0
#define KERNEL_TENSOR_6_PADDING_VALUE_V_MASK                                              0xFFFFFFFF

#define KERNEL_TENSOR_6_TENSOR_CONFIG                                                   0x55C

#define KERNEL_TENSOR_6_TENSOR_CONFIG_DATA_TYPE_SHIFT                                     0
#define KERNEL_TENSOR_6_TENSOR_CONFIG_DATA_TYPE_MASK                                      0x7
#define KERNEL_TENSOR_6_TENSOR_CONFIG_VALID_DIM_MASK_SHIFT                                8
#define KERNEL_TENSOR_6_TENSOR_CONFIG_VALID_DIM_MASK_MASK                                 0x1F00
#define KERNEL_TENSOR_6_TENSOR_CONFIG_LAST_DIM_SHIFT                                      16
#define KERNEL_TENSOR_6_TENSOR_CONFIG_LAST_DIM_MASK                                       0x70000
#define KERNEL_TENSOR_6_TENSOR_CONFIG_RMW_SET_SHIFT                                       19
#define KERNEL_TENSOR_6_TENSOR_CONFIG_RMW_SET_MASK                                        0x80000
#define KERNEL_TENSOR_6_TENSOR_CONFIG_RMW_RESERV_SHIFT                                    20
#define KERNEL_TENSOR_6_TENSOR_CONFIG_RMW_RESERV_MASK                                     0x100000
#define KERNEL_TENSOR_6_TENSOR_CONFIG_RMW_OP_SHIFT                                        21
#define KERNEL_TENSOR_6_TENSOR_CONFIG_RMW_OP_MASK                                         0x600000

#define KERNEL_TENSOR_6_DIM_0_SIZE                                                      0x560

#define KERNEL_TENSOR_6_DIM_0_SIZE_V_SHIFT                                                0
#define KERNEL_TENSOR_6_DIM_0_SIZE_V_MASK                                                 0xFFFFFFFF

#define KERNEL_TENSOR_6_DIM_0_STRIDE                                                    0x564

#define KERNEL_TENSOR_6_DIM_0_STRIDE_V_SHIFT                                              0
#define KERNEL_TENSOR_6_DIM_0_STRIDE_V_MASK                                               0xFFFFFFFF

#define KERNEL_TENSOR_6_DIM_1_SIZE                                                      0x568

#define KERNEL_TENSOR_6_DIM_1_SIZE_V_SHIFT                                                0
#define KERNEL_TENSOR_6_DIM_1_SIZE_V_MASK                                                 0xFFFFFFFF

#define KERNEL_TENSOR_6_DIM_1_STRIDE                                                    0x56C

#define KERNEL_TENSOR_6_DIM_1_STRIDE_V_SHIFT                                              0
#define KERNEL_TENSOR_6_DIM_1_STRIDE_V_MASK                                               0xFFFFFFFF

#define KERNEL_TENSOR_6_DIM_2_SIZE                                                      0x570

#define KERNEL_TENSOR_6_DIM_2_SIZE_V_SHIFT                                                0
#define KERNEL_TENSOR_6_DIM_2_SIZE_V_MASK                                                 0xFFFFFFFF

#define KERNEL_TENSOR_6_DIM_2_STRIDE                                                    0x574

#define KERNEL_TENSOR_6_DIM_2_STRIDE_V_SHIFT                                              0
#define KERNEL_TENSOR_6_DIM_2_STRIDE_V_MASK                                               0xFFFFFFFF

#define KERNEL_TENSOR_6_DIM_3_SIZE                                                      0x578

#define KERNEL_TENSOR_6_DIM_3_SIZE_V_SHIFT                                                0
#define KERNEL_TENSOR_6_DIM_3_SIZE_V_MASK                                                 0xFFFFFFFF

#define KERNEL_TENSOR_6_DIM_3_STRIDE                                                    0x57C

#define KERNEL_TENSOR_6_DIM_3_STRIDE_V_SHIFT                                              0
#define KERNEL_TENSOR_6_DIM_3_STRIDE_V_MASK                                               0xFFFFFFFF

#define KERNEL_TENSOR_6_DIM_4_SIZE                                                      0x580

#define KERNEL_TENSOR_6_DIM_4_SIZE_V_SHIFT                                                0
#define KERNEL_TENSOR_6_DIM_4_SIZE_V_MASK                                                 0xFFFFFFFF

#define KERNEL_TENSOR_6_DIM_4_STRIDE                                                    0x584

#define KERNEL_TENSOR_6_DIM_4_STRIDE_V_SHIFT                                              0
#define KERNEL_TENSOR_6_DIM_4_STRIDE_V_MASK                                               0xFFFFFFFF

#define KERNEL_TENSOR_7_BASE_ADDR_LOW                                                   0x588

#define KERNEL_TENSOR_7_BASE_ADDR_LOW_V_SHIFT                                             0
#define KERNEL_TENSOR_7_BASE_ADDR_LOW_V_MASK                                              0xFFFFFFFF

#define KERNEL_TENSOR_7_BASE_ADDR_HIGH                                                  0x58C

#define KERNEL_TENSOR_7_BASE_ADDR_HIGH_V_SHIFT                                            0
#define KERNEL_TENSOR_7_BASE_ADDR_HIGH_V_MASK                                             0xFFFFFFFF

#define KERNEL_TENSOR_7_PADDING_VALUE                                                   0x590

#define KERNEL_TENSOR_7_PADDING_VALUE_V_SHIFT                                             0
#define KERNEL_TENSOR_7_PADDING_VALUE_V_MASK                                              0xFFFFFFFF

#define KERNEL_TENSOR_7_TENSOR_CONFIG                                                   0x594

#define KERNEL_TENSOR_7_TENSOR_CONFIG_DATA_TYPE_SHIFT                                     0
#define KERNEL_TENSOR_7_TENSOR_CONFIG_DATA_TYPE_MASK                                      0x7
#define KERNEL_TENSOR_7_TENSOR_CONFIG_VALID_DIM_MASK_SHIFT                                8
#define KERNEL_TENSOR_7_TENSOR_CONFIG_VALID_DIM_MASK_MASK                                 0x1F00
#define KERNEL_TENSOR_7_TENSOR_CONFIG_LAST_DIM_SHIFT                                      16
#define KERNEL_TENSOR_7_TENSOR_CONFIG_LAST_DIM_MASK                                       0x70000
#define KERNEL_TENSOR_7_TENSOR_CONFIG_RMW_SET_SHIFT                                       19
#define KERNEL_TENSOR_7_TENSOR_CONFIG_RMW_SET_MASK                                        0x80000
#define KERNEL_TENSOR_7_TENSOR_CONFIG_RMW_RESERV_SHIFT                                    20
#define KERNEL_TENSOR_7_TENSOR_CONFIG_RMW_RESERV_MASK                                     0x100000
#define KERNEL_TENSOR_7_TENSOR_CONFIG_RMW_OP_SHIFT                                        21
#define KERNEL_TENSOR_7_TENSOR_CONFIG_RMW_OP_MASK                                         0x600000

#define KERNEL_TENSOR_7_DIM_0_SIZE                                                      0x598

#define KERNEL_TENSOR_7_DIM_0_SIZE_V_SHIFT                                                0
#define KERNEL_TENSOR_7_DIM_0_SIZE_V_MASK                                                 0xFFFFFFFF

#define KERNEL_TENSOR_7_DIM_0_STRIDE                                                    0x59C

#define KERNEL_TENSOR_7_DIM_0_STRIDE_V_SHIFT                                              0
#define KERNEL_TENSOR_7_DIM_0_STRIDE_V_MASK                                               0xFFFFFFFF

#define KERNEL_TENSOR_7_DIM_1_SIZE                                                      0x5A0

#define KERNEL_TENSOR_7_DIM_1_SIZE_V_SHIFT                                                0
#define KERNEL_TENSOR_7_DIM_1_SIZE_V_MASK                                                 0xFFFFFFFF

#define KERNEL_TENSOR_7_DIM_1_STRIDE                                                    0x5A4

#define KERNEL_TENSOR_7_DIM_1_STRIDE_V_SHIFT                                              0
#define KERNEL_TENSOR_7_DIM_1_STRIDE_V_MASK                                               0xFFFFFFFF

#define KERNEL_TENSOR_7_DIM_2_SIZE                                                      0x5A8

#define KERNEL_TENSOR_7_DIM_2_SIZE_V_SHIFT                                                0
#define KERNEL_TENSOR_7_DIM_2_SIZE_V_MASK                                                 0xFFFFFFFF

#define KERNEL_TENSOR_7_DIM_2_STRIDE                                                    0x5AC

#define KERNEL_TENSOR_7_DIM_2_STRIDE_V_SHIFT                                              0
#define KERNEL_TENSOR_7_DIM_2_STRIDE_V_MASK                                               0xFFFFFFFF

#define KERNEL_TENSOR_7_DIM_3_SIZE                                                      0x5B0

#define KERNEL_TENSOR_7_DIM_3_SIZE_V_SHIFT                                                0
#define KERNEL_TENSOR_7_DIM_3_SIZE_V_MASK                                                 0xFFFFFFFF

#define KERNEL_TENSOR_7_DIM_3_STRIDE                                                    0x5B4

#define KERNEL_TENSOR_7_DIM_3_STRIDE_V_SHIFT                                              0
#define KERNEL_TENSOR_7_DIM_3_STRIDE_V_MASK                                               0xFFFFFFFF

#define KERNEL_TENSOR_7_DIM_4_SIZE                                                      0x5B8

#define KERNEL_TENSOR_7_DIM_4_SIZE_V_SHIFT                                                0
#define KERNEL_TENSOR_7_DIM_4_SIZE_V_MASK                                                 0xFFFFFFFF

#define KERNEL_TENSOR_7_DIM_4_STRIDE                                                    0x5BC

#define KERNEL_TENSOR_7_DIM_4_STRIDE_V_SHIFT                                              0
#define KERNEL_TENSOR_7_DIM_4_STRIDE_V_MASK                                               0xFFFFFFFF

#define KERNEL_TENSOR_8_BASE_ADDR_LOW                                                   0x5C0

#define KERNEL_TENSOR_8_BASE_ADDR_LOW_V_SHIFT                                             0
#define KERNEL_TENSOR_8_BASE_ADDR_LOW_V_MASK                                              0xFFFFFFFF

#define KERNEL_TENSOR_8_BASE_ADDR_HIGH                                                  0x5C4

#define KERNEL_TENSOR_8_BASE_ADDR_HIGH_V_SHIFT                                            0
#define KERNEL_TENSOR_8_BASE_ADDR_HIGH_V_MASK                                             0xFFFFFFFF

#define KERNEL_TENSOR_8_PADDING_VALUE                                                   0x5C8

#define KERNEL_TENSOR_8_PADDING_VALUE_V_SHIFT                                             0
#define KERNEL_TENSOR_8_PADDING_VALUE_V_MASK                                              0xFFFFFFFF

#define KERNEL_TENSOR_8_TENSOR_CONFIG                                                   0x5CC

#define KERNEL_TENSOR_8_TENSOR_CONFIG_DATA_TYPE_SHIFT                                     0
#define KERNEL_TENSOR_8_TENSOR_CONFIG_DATA_TYPE_MASK                                      0x7
#define KERNEL_TENSOR_8_TENSOR_CONFIG_VALID_DIM_MASK_SHIFT                                8
#define KERNEL_TENSOR_8_TENSOR_CONFIG_VALID_DIM_MASK_MASK                                 0x1F00
#define KERNEL_TENSOR_8_TENSOR_CONFIG_LAST_DIM_SHIFT                                      16
#define KERNEL_TENSOR_8_TENSOR_CONFIG_LAST_DIM_MASK                                       0x70000
#define KERNEL_TENSOR_8_TENSOR_CONFIG_RMW_SET_SHIFT                                       19
#define KERNEL_TENSOR_8_TENSOR_CONFIG_RMW_SET_MASK                                        0x80000
#define KERNEL_TENSOR_8_TENSOR_CONFIG_RMW_RESERV_SHIFT                                    20
#define KERNEL_TENSOR_8_TENSOR_CONFIG_RMW_RESERV_MASK                                     0x100000
#define KERNEL_TENSOR_8_TENSOR_CONFIG_RMW_OP_SHIFT                                        21
#define KERNEL_TENSOR_8_TENSOR_CONFIG_RMW_OP_MASK                                         0x600000

#define KERNEL_TENSOR_8_DIM_0_SIZE                                                      0x5D0

#define KERNEL_TENSOR_8_DIM_0_SIZE_V_SHIFT                                                0
#define KERNEL_TENSOR_8_DIM_0_SIZE_V_MASK                                                 0xFFFFFFFF

#define KERNEL_TENSOR_8_DIM_0_STRIDE                                                    0x5D4

#define KERNEL_TENSOR_8_DIM_0_STRIDE_V_SHIFT                                              0
#define KERNEL_TENSOR_8_DIM_0_STRIDE_V_MASK                                               0xFFFFFFFF

#define KERNEL_TENSOR_8_DIM_1_SIZE                                                      0x5D8

#define KERNEL_TENSOR_8_DIM_1_SIZE_V_SHIFT                                                0
#define KERNEL_TENSOR_8_DIM_1_SIZE_V_MASK                                                 0xFFFFFFFF

#define KERNEL_TENSOR_8_DIM_1_STRIDE                                                    0x5DC

#define KERNEL_TENSOR_8_DIM_1_STRIDE_V_SHIFT                                              0
#define KERNEL_TENSOR_8_DIM_1_STRIDE_V_MASK                                               0xFFFFFFFF

#define KERNEL_TENSOR_8_DIM_2_SIZE                                                      0x5E0

#define KERNEL_TENSOR_8_DIM_2_SIZE_V_SHIFT                                                0
#define KERNEL_TENSOR_8_DIM_2_SIZE_V_MASK                                                 0xFFFFFFFF

#define KERNEL_TENSOR_8_DIM_2_STRIDE                                                    0x5E4

#define KERNEL_TENSOR_8_DIM_2_STRIDE_V_SHIFT                                              0
#define KERNEL_TENSOR_8_DIM_2_STRIDE_V_MASK                                               0xFFFFFFFF

#define KERNEL_TENSOR_8_DIM_3_SIZE                                                      0x5E8

#define KERNEL_TENSOR_8_DIM_3_SIZE_V_SHIFT                                                0
#define KERNEL_TENSOR_8_DIM_3_SIZE_V_MASK                                                 0xFFFFFFFF

#define KERNEL_TENSOR_8_DIM_3_STRIDE                                                    0x5EC

#define KERNEL_TENSOR_8_DIM_3_STRIDE_V_SHIFT                                              0
#define KERNEL_TENSOR_8_DIM_3_STRIDE_V_MASK                                               0xFFFFFFFF

#define KERNEL_TENSOR_8_DIM_4_SIZE                                                      0x5F0

#define KERNEL_TENSOR_8_DIM_4_SIZE_V_SHIFT                                                0
#define KERNEL_TENSOR_8_DIM_4_SIZE_V_MASK                                                 0xFFFFFFFF

#define KERNEL_TENSOR_8_DIM_4_STRIDE                                                    0x5F4

#define KERNEL_TENSOR_8_DIM_4_STRIDE_V_SHIFT                                              0
#define KERNEL_TENSOR_8_DIM_4_STRIDE_V_MASK                                               0xFFFFFFFF

#define KERNEL_TENSOR_9_BASE_ADDR_LOW                                                   0x5F8

#define KERNEL_TENSOR_9_BASE_ADDR_LOW_V_SHIFT                                             0
#define KERNEL_TENSOR_9_BASE_ADDR_LOW_V_MASK                                              0xFFFFFFFF

#define KERNEL_TENSOR_9_BASE_ADDR_HIGH                                                  0x5FC

#define KERNEL_TENSOR_9_BASE_ADDR_HIGH_V_SHIFT                                            0
#define KERNEL_TENSOR_9_BASE_ADDR_HIGH_V_MASK                                             0xFFFFFFFF

#define KERNEL_TENSOR_9_PADDING_VALUE                                                   0x600

#define KERNEL_TENSOR_9_PADDING_VALUE_V_SHIFT                                             0
#define KERNEL_TENSOR_9_PADDING_VALUE_V_MASK                                              0xFFFFFFFF

#define KERNEL_TENSOR_9_TENSOR_CONFIG                                                   0x604

#define KERNEL_TENSOR_9_TENSOR_CONFIG_DATA_TYPE_SHIFT                                     0
#define KERNEL_TENSOR_9_TENSOR_CONFIG_DATA_TYPE_MASK                                      0x7
#define KERNEL_TENSOR_9_TENSOR_CONFIG_VALID_DIM_MASK_SHIFT                                8
#define KERNEL_TENSOR_9_TENSOR_CONFIG_VALID_DIM_MASK_MASK                                 0x1F00
#define KERNEL_TENSOR_9_TENSOR_CONFIG_LAST_DIM_SHIFT                                      16
#define KERNEL_TENSOR_9_TENSOR_CONFIG_LAST_DIM_MASK                                       0x70000
#define KERNEL_TENSOR_9_TENSOR_CONFIG_RMW_SET_SHIFT                                       19
#define KERNEL_TENSOR_9_TENSOR_CONFIG_RMW_SET_MASK                                        0x80000
#define KERNEL_TENSOR_9_TENSOR_CONFIG_RMW_RESERV_SHIFT                                    20
#define KERNEL_TENSOR_9_TENSOR_CONFIG_RMW_RESERV_MASK                                     0x100000
#define KERNEL_TENSOR_9_TENSOR_CONFIG_RMW_OP_SHIFT                                        21
#define KERNEL_TENSOR_9_TENSOR_CONFIG_RMW_OP_MASK                                         0x600000

#define KERNEL_TENSOR_9_DIM_0_SIZE                                                      0x608

#define KERNEL_TENSOR_9_DIM_0_SIZE_V_SHIFT                                                0
#define KERNEL_TENSOR_9_DIM_0_SIZE_V_MASK                                                 0xFFFFFFFF

#define KERNEL_TENSOR_9_DIM_0_STRIDE                                                    0x60C

#define KERNEL_TENSOR_9_DIM_0_STRIDE_V_SHIFT                                              0
#define KERNEL_TENSOR_9_DIM_0_STRIDE_V_MASK                                               0xFFFFFFFF

#define KERNEL_TENSOR_9_DIM_1_SIZE                                                      0x610

#define KERNEL_TENSOR_9_DIM_1_SIZE_V_SHIFT                                                0
#define KERNEL_TENSOR_9_DIM_1_SIZE_V_MASK                                                 0xFFFFFFFF

#define KERNEL_TENSOR_9_DIM_1_STRIDE                                                    0x614

#define KERNEL_TENSOR_9_DIM_1_STRIDE_V_SHIFT                                              0
#define KERNEL_TENSOR_9_DIM_1_STRIDE_V_MASK                                               0xFFFFFFFF

#define KERNEL_TENSOR_9_DIM_2_SIZE                                                      0x618

#define KERNEL_TENSOR_9_DIM_2_SIZE_V_SHIFT                                                0
#define KERNEL_TENSOR_9_DIM_2_SIZE_V_MASK                                                 0xFFFFFFFF

#define KERNEL_TENSOR_9_DIM_2_STRIDE                                                    0x61C

#define KERNEL_TENSOR_9_DIM_2_STRIDE_V_SHIFT                                              0
#define KERNEL_TENSOR_9_DIM_2_STRIDE_V_MASK                                               0xFFFFFFFF

#define KERNEL_TENSOR_9_DIM_3_SIZE                                                      0x620

#define KERNEL_TENSOR_9_DIM_3_SIZE_V_SHIFT                                                0
#define KERNEL_TENSOR_9_DIM_3_SIZE_V_MASK                                                 0xFFFFFFFF

#define KERNEL_TENSOR_9_DIM_3_STRIDE                                                    0x624

#define KERNEL_TENSOR_9_DIM_3_STRIDE_V_SHIFT                                              0
#define KERNEL_TENSOR_9_DIM_3_STRIDE_V_MASK                                               0xFFFFFFFF

#define KERNEL_TENSOR_9_DIM_4_SIZE                                                      0x628

#define KERNEL_TENSOR_9_DIM_4_SIZE_V_SHIFT                                                0
#define KERNEL_TENSOR_9_DIM_4_SIZE_V_MASK                                                 0xFFFFFFFF

#define KERNEL_TENSOR_9_DIM_4_STRIDE                                                    0x62C

#define KERNEL_TENSOR_9_DIM_4_STRIDE_V_SHIFT                                              0
#define KERNEL_TENSOR_9_DIM_4_STRIDE_V_MASK                                               0xFFFFFFFF

#define KERNEL_TENSOR_10_BASE_ADDR_LOW                                                  0x630

#define KERNEL_TENSOR_10_BASE_ADDR_LOW_V_SHIFT                                            0
#define KERNEL_TENSOR_10_BASE_ADDR_LOW_V_MASK                                             0xFFFFFFFF

#define KERNEL_TENSOR_10_BASE_ADDR_HIGH                                                 0x634

#define KERNEL_TENSOR_10_BASE_ADDR_HIGH_V_SHIFT                                           0
#define KERNEL_TENSOR_10_BASE_ADDR_HIGH_V_MASK                                            0xFFFFFFFF

#define KERNEL_TENSOR_10_PADDING_VALUE                                                  0x638

#define KERNEL_TENSOR_10_PADDING_VALUE_V_SHIFT                                            0
#define KERNEL_TENSOR_10_PADDING_VALUE_V_MASK                                             0xFFFFFFFF

#define KERNEL_TENSOR_10_TENSOR_CONFIG                                                  0x63C

#define KERNEL_TENSOR_10_TENSOR_CONFIG_DATA_TYPE_SHIFT                                    0
#define KERNEL_TENSOR_10_TENSOR_CONFIG_DATA_TYPE_MASK                                     0x7
#define KERNEL_TENSOR_10_TENSOR_CONFIG_VALID_DIM_MASK_SHIFT                               8
#define KERNEL_TENSOR_10_TENSOR_CONFIG_VALID_DIM_MASK_MASK                                0x1F00
#define KERNEL_TENSOR_10_TENSOR_CONFIG_LAST_DIM_SHIFT                                     16
#define KERNEL_TENSOR_10_TENSOR_CONFIG_LAST_DIM_MASK                                      0x70000
#define KERNEL_TENSOR_10_TENSOR_CONFIG_RMW_SET_SHIFT                                      19
#define KERNEL_TENSOR_10_TENSOR_CONFIG_RMW_SET_MASK                                       0x80000
#define KERNEL_TENSOR_10_TENSOR_CONFIG_RMW_RESERV_SHIFT                                   20
#define KERNEL_TENSOR_10_TENSOR_CONFIG_RMW_RESERV_MASK                                    0x100000
#define KERNEL_TENSOR_10_TENSOR_CONFIG_RMW_OP_SHIFT                                       21
#define KERNEL_TENSOR_10_TENSOR_CONFIG_RMW_OP_MASK                                        0x600000

#define KERNEL_TENSOR_10_DIM_0_SIZE                                                     0x640

#define KERNEL_TENSOR_10_DIM_0_SIZE_V_SHIFT                                               0
#define KERNEL_TENSOR_10_DIM_0_SIZE_V_MASK                                                0xFFFFFFFF

#define KERNEL_TENSOR_10_DIM_0_STRIDE                                                   0x644

#define KERNEL_TENSOR_10_DIM_0_STRIDE_V_SHIFT                                             0
#define KERNEL_TENSOR_10_DIM_0_STRIDE_V_MASK                                              0xFFFFFFFF

#define KERNEL_TENSOR_10_DIM_1_SIZE                                                     0x648

#define KERNEL_TENSOR_10_DIM_1_SIZE_V_SHIFT                                               0
#define KERNEL_TENSOR_10_DIM_1_SIZE_V_MASK                                                0xFFFFFFFF

#define KERNEL_TENSOR_10_DIM_1_STRIDE                                                   0x64C

#define KERNEL_TENSOR_10_DIM_1_STRIDE_V_SHIFT                                             0
#define KERNEL_TENSOR_10_DIM_1_STRIDE_V_MASK                                              0xFFFFFFFF

#define KERNEL_TENSOR_10_DIM_2_SIZE                                                     0x650

#define KERNEL_TENSOR_10_DIM_2_SIZE_V_SHIFT                                               0
#define KERNEL_TENSOR_10_DIM_2_SIZE_V_MASK                                                0xFFFFFFFF

#define KERNEL_TENSOR_10_DIM_2_STRIDE                                                   0x654

#define KERNEL_TENSOR_10_DIM_2_STRIDE_V_SHIFT                                             0
#define KERNEL_TENSOR_10_DIM_2_STRIDE_V_MASK                                              0xFFFFFFFF

#define KERNEL_TENSOR_10_DIM_3_SIZE                                                     0x658

#define KERNEL_TENSOR_10_DIM_3_SIZE_V_SHIFT                                               0
#define KERNEL_TENSOR_10_DIM_3_SIZE_V_MASK                                                0xFFFFFFFF

#define KERNEL_TENSOR_10_DIM_3_STRIDE                                                   0x65C

#define KERNEL_TENSOR_10_DIM_3_STRIDE_V_SHIFT                                             0
#define KERNEL_TENSOR_10_DIM_3_STRIDE_V_MASK                                              0xFFFFFFFF

#define KERNEL_TENSOR_10_DIM_4_SIZE                                                     0x660

#define KERNEL_TENSOR_10_DIM_4_SIZE_V_SHIFT                                               0
#define KERNEL_TENSOR_10_DIM_4_SIZE_V_MASK                                                0xFFFFFFFF

#define KERNEL_TENSOR_10_DIM_4_STRIDE                                                   0x664

#define KERNEL_TENSOR_10_DIM_4_STRIDE_V_SHIFT                                             0
#define KERNEL_TENSOR_10_DIM_4_STRIDE_V_MASK                                              0xFFFFFFFF

#define KERNEL_TENSOR_11_BASE_ADDR_LOW                                                  0x668

#define KERNEL_TENSOR_11_BASE_ADDR_LOW_V_SHIFT                                            0
#define KERNEL_TENSOR_11_BASE_ADDR_LOW_V_MASK                                             0xFFFFFFFF

#define KERNEL_TENSOR_11_BASE_ADDR_HIGH                                                 0x66C

#define KERNEL_TENSOR_11_BASE_ADDR_HIGH_V_SHIFT                                           0
#define KERNEL_TENSOR_11_BASE_ADDR_HIGH_V_MASK                                            0xFFFFFFFF

#define KERNEL_TENSOR_11_PADDING_VALUE                                                  0x670

#define KERNEL_TENSOR_11_PADDING_VALUE_V_SHIFT                                            0
#define KERNEL_TENSOR_11_PADDING_VALUE_V_MASK                                             0xFFFFFFFF

#define KERNEL_TENSOR_11_TENSOR_CONFIG                                                  0x674

#define KERNEL_TENSOR_11_TENSOR_CONFIG_DATA_TYPE_SHIFT                                    0
#define KERNEL_TENSOR_11_TENSOR_CONFIG_DATA_TYPE_MASK                                     0x7
#define KERNEL_TENSOR_11_TENSOR_CONFIG_VALID_DIM_MASK_SHIFT                               8
#define KERNEL_TENSOR_11_TENSOR_CONFIG_VALID_DIM_MASK_MASK                                0x1F00
#define KERNEL_TENSOR_11_TENSOR_CONFIG_LAST_DIM_SHIFT                                     16
#define KERNEL_TENSOR_11_TENSOR_CONFIG_LAST_DIM_MASK                                      0x70000
#define KERNEL_TENSOR_11_TENSOR_CONFIG_RMW_SET_SHIFT                                      19
#define KERNEL_TENSOR_11_TENSOR_CONFIG_RMW_SET_MASK                                       0x80000
#define KERNEL_TENSOR_11_TENSOR_CONFIG_RMW_RESERV_SHIFT                                   20
#define KERNEL_TENSOR_11_TENSOR_CONFIG_RMW_RESERV_MASK                                    0x100000
#define KERNEL_TENSOR_11_TENSOR_CONFIG_RMW_OP_SHIFT                                       21
#define KERNEL_TENSOR_11_TENSOR_CONFIG_RMW_OP_MASK                                        0x600000

#define KERNEL_TENSOR_11_DIM_0_SIZE                                                     0x678

#define KERNEL_TENSOR_11_DIM_0_SIZE_V_SHIFT                                               0
#define KERNEL_TENSOR_11_DIM_0_SIZE_V_MASK                                                0xFFFFFFFF

#define KERNEL_TENSOR_11_DIM_0_STRIDE                                                   0x67C

#define KERNEL_TENSOR_11_DIM_0_STRIDE_V_SHIFT                                             0
#define KERNEL_TENSOR_11_DIM_0_STRIDE_V_MASK                                              0xFFFFFFFF

#define KERNEL_TENSOR_11_DIM_1_SIZE                                                     0x680

#define KERNEL_TENSOR_11_DIM_1_SIZE_V_SHIFT                                               0
#define KERNEL_TENSOR_11_DIM_1_SIZE_V_MASK                                                0xFFFFFFFF

#define KERNEL_TENSOR_11_DIM_1_STRIDE                                                   0x684

#define KERNEL_TENSOR_11_DIM_1_STRIDE_V_SHIFT                                             0
#define KERNEL_TENSOR_11_DIM_1_STRIDE_V_MASK                                              0xFFFFFFFF

#define KERNEL_TENSOR_11_DIM_2_SIZE                                                     0x688

#define KERNEL_TENSOR_11_DIM_2_SIZE_V_SHIFT                                               0
#define KERNEL_TENSOR_11_DIM_2_SIZE_V_MASK                                                0xFFFFFFFF

#define KERNEL_TENSOR_11_DIM_2_STRIDE                                                   0x68C

#define KERNEL_TENSOR_11_DIM_2_STRIDE_V_SHIFT                                             0
#define KERNEL_TENSOR_11_DIM_2_STRIDE_V_MASK                                              0xFFFFFFFF

#define KERNEL_TENSOR_11_DIM_3_SIZE                                                     0x690

#define KERNEL_TENSOR_11_DIM_3_SIZE_V_SHIFT                                               0
#define KERNEL_TENSOR_11_DIM_3_SIZE_V_MASK                                                0xFFFFFFFF

#define KERNEL_TENSOR_11_DIM_3_STRIDE                                                   0x694

#define KERNEL_TENSOR_11_DIM_3_STRIDE_V_SHIFT                                             0
#define KERNEL_TENSOR_11_DIM_3_STRIDE_V_MASK                                              0xFFFFFFFF

#define KERNEL_TENSOR_11_DIM_4_SIZE                                                     0x698

#define KERNEL_TENSOR_11_DIM_4_SIZE_V_SHIFT                                               0
#define KERNEL_TENSOR_11_DIM_4_SIZE_V_MASK                                                0xFFFFFFFF

#define KERNEL_TENSOR_11_DIM_4_STRIDE                                                   0x69C

#define KERNEL_TENSOR_11_DIM_4_STRIDE_V_SHIFT                                             0
#define KERNEL_TENSOR_11_DIM_4_STRIDE_V_MASK                                              0xFFFFFFFF

#define KERNEL_TENSOR_12_BASE_ADDR_LOW                                                  0x6A0

#define KERNEL_TENSOR_12_BASE_ADDR_LOW_V_SHIFT                                            0
#define KERNEL_TENSOR_12_BASE_ADDR_LOW_V_MASK                                             0xFFFFFFFF

#define KERNEL_TENSOR_12_BASE_ADDR_HIGH                                                 0x6A4

#define KERNEL_TENSOR_12_BASE_ADDR_HIGH_V_SHIFT                                           0
#define KERNEL_TENSOR_12_BASE_ADDR_HIGH_V_MASK                                            0xFFFFFFFF

#define KERNEL_TENSOR_12_PADDING_VALUE                                                  0x6A8

#define KERNEL_TENSOR_12_PADDING_VALUE_V_SHIFT                                            0
#define KERNEL_TENSOR_12_PADDING_VALUE_V_MASK                                             0xFFFFFFFF

#define KERNEL_TENSOR_12_TENSOR_CONFIG                                                  0x6AC

#define KERNEL_TENSOR_12_TENSOR_CONFIG_DATA_TYPE_SHIFT                                    0
#define KERNEL_TENSOR_12_TENSOR_CONFIG_DATA_TYPE_MASK                                     0x7
#define KERNEL_TENSOR_12_TENSOR_CONFIG_VALID_DIM_MASK_SHIFT                               8
#define KERNEL_TENSOR_12_TENSOR_CONFIG_VALID_DIM_MASK_MASK                                0x1F00
#define KERNEL_TENSOR_12_TENSOR_CONFIG_LAST_DIM_SHIFT                                     16
#define KERNEL_TENSOR_12_TENSOR_CONFIG_LAST_DIM_MASK                                      0x70000
#define KERNEL_TENSOR_12_TENSOR_CONFIG_RMW_SET_SHIFT                                      19
#define KERNEL_TENSOR_12_TENSOR_CONFIG_RMW_SET_MASK                                       0x80000
#define KERNEL_TENSOR_12_TENSOR_CONFIG_RMW_RESERV_SHIFT                                   20
#define KERNEL_TENSOR_12_TENSOR_CONFIG_RMW_RESERV_MASK                                    0x100000
#define KERNEL_TENSOR_12_TENSOR_CONFIG_RMW_OP_SHIFT                                       21
#define KERNEL_TENSOR_12_TENSOR_CONFIG_RMW_OP_MASK                                        0x600000

#define KERNEL_TENSOR_12_DIM_0_SIZE                                                     0x6B0

#define KERNEL_TENSOR_12_DIM_0_SIZE_V_SHIFT                                               0
#define KERNEL_TENSOR_12_DIM_0_SIZE_V_MASK                                                0xFFFFFFFF

#define KERNEL_TENSOR_12_DIM_0_STRIDE                                                   0x6B4

#define KERNEL_TENSOR_12_DIM_0_STRIDE_V_SHIFT                                             0
#define KERNEL_TENSOR_12_DIM_0_STRIDE_V_MASK                                              0xFFFFFFFF

#define KERNEL_TENSOR_12_DIM_1_SIZE                                                     0x6B8

#define KERNEL_TENSOR_12_DIM_1_SIZE_V_SHIFT                                               0
#define KERNEL_TENSOR_12_DIM_1_SIZE_V_MASK                                                0xFFFFFFFF

#define KERNEL_TENSOR_12_DIM_1_STRIDE                                                   0x6BC

#define KERNEL_TENSOR_12_DIM_1_STRIDE_V_SHIFT                                             0
#define KERNEL_TENSOR_12_DIM_1_STRIDE_V_MASK                                              0xFFFFFFFF

#define KERNEL_TENSOR_12_DIM_2_SIZE                                                     0x6C0

#define KERNEL_TENSOR_12_DIM_2_SIZE_V_SHIFT                                               0
#define KERNEL_TENSOR_12_DIM_2_SIZE_V_MASK                                                0xFFFFFFFF

#define KERNEL_TENSOR_12_DIM_2_STRIDE                                                   0x6C4

#define KERNEL_TENSOR_12_DIM_2_STRIDE_V_SHIFT                                             0
#define KERNEL_TENSOR_12_DIM_2_STRIDE_V_MASK                                              0xFFFFFFFF

#define KERNEL_TENSOR_12_DIM_3_SIZE                                                     0x6C8

#define KERNEL_TENSOR_12_DIM_3_SIZE_V_SHIFT                                               0
#define KERNEL_TENSOR_12_DIM_3_SIZE_V_MASK                                                0xFFFFFFFF

#define KERNEL_TENSOR_12_DIM_3_STRIDE                                                   0x6CC

#define KERNEL_TENSOR_12_DIM_3_STRIDE_V_SHIFT                                             0
#define KERNEL_TENSOR_12_DIM_3_STRIDE_V_MASK                                              0xFFFFFFFF

#define KERNEL_TENSOR_12_DIM_4_SIZE                                                     0x6D0

#define KERNEL_TENSOR_12_DIM_4_SIZE_V_SHIFT                                               0
#define KERNEL_TENSOR_12_DIM_4_SIZE_V_MASK                                                0xFFFFFFFF

#define KERNEL_TENSOR_12_DIM_4_STRIDE                                                   0x6D4

#define KERNEL_TENSOR_12_DIM_4_STRIDE_V_SHIFT                                             0
#define KERNEL_TENSOR_12_DIM_4_STRIDE_V_MASK                                              0xFFFFFFFF

#define KERNEL_TENSOR_13_BASE_ADDR_LOW                                                  0x6D8

#define KERNEL_TENSOR_13_BASE_ADDR_LOW_V_SHIFT                                            0
#define KERNEL_TENSOR_13_BASE_ADDR_LOW_V_MASK                                             0xFFFFFFFF

#define KERNEL_TENSOR_13_BASE_ADDR_HIGH                                                 0x6DC

#define KERNEL_TENSOR_13_BASE_ADDR_HIGH_V_SHIFT                                           0
#define KERNEL_TENSOR_13_BASE_ADDR_HIGH_V_MASK                                            0xFFFFFFFF

#define KERNEL_TENSOR_13_PADDING_VALUE                                                  0x6E0

#define KERNEL_TENSOR_13_PADDING_VALUE_V_SHIFT                                            0
#define KERNEL_TENSOR_13_PADDING_VALUE_V_MASK                                             0xFFFFFFFF

#define KERNEL_TENSOR_13_TENSOR_CONFIG                                                  0x6E4

#define KERNEL_TENSOR_13_TENSOR_CONFIG_DATA_TYPE_SHIFT                                    0
#define KERNEL_TENSOR_13_TENSOR_CONFIG_DATA_TYPE_MASK                                     0x7
#define KERNEL_TENSOR_13_TENSOR_CONFIG_VALID_DIM_MASK_SHIFT                               8
#define KERNEL_TENSOR_13_TENSOR_CONFIG_VALID_DIM_MASK_MASK                                0x1F00
#define KERNEL_TENSOR_13_TENSOR_CONFIG_LAST_DIM_SHIFT                                     16
#define KERNEL_TENSOR_13_TENSOR_CONFIG_LAST_DIM_MASK                                      0x70000
#define KERNEL_TENSOR_13_TENSOR_CONFIG_RMW_SET_SHIFT                                      19
#define KERNEL_TENSOR_13_TENSOR_CONFIG_RMW_SET_MASK                                       0x80000
#define KERNEL_TENSOR_13_TENSOR_CONFIG_RMW_RESERV_SHIFT                                   20
#define KERNEL_TENSOR_13_TENSOR_CONFIG_RMW_RESERV_MASK                                    0x100000
#define KERNEL_TENSOR_13_TENSOR_CONFIG_RMW_OP_SHIFT                                       21
#define KERNEL_TENSOR_13_TENSOR_CONFIG_RMW_OP_MASK                                        0x600000

#define KERNEL_TENSOR_13_DIM_0_SIZE                                                     0x6E8

#define KERNEL_TENSOR_13_DIM_0_SIZE_V_SHIFT                                               0
#define KERNEL_TENSOR_13_DIM_0_SIZE_V_MASK                                                0xFFFFFFFF

#define KERNEL_TENSOR_13_DIM_0_STRIDE                                                   0x6EC

#define KERNEL_TENSOR_13_DIM_0_STRIDE_V_SHIFT                                             0
#define KERNEL_TENSOR_13_DIM_0_STRIDE_V_MASK                                              0xFFFFFFFF

#define KERNEL_TENSOR_13_DIM_1_SIZE                                                     0x6F0

#define KERNEL_TENSOR_13_DIM_1_SIZE_V_SHIFT                                               0
#define KERNEL_TENSOR_13_DIM_1_SIZE_V_MASK                                                0xFFFFFFFF

#define KERNEL_TENSOR_13_DIM_1_STRIDE                                                   0x6F4

#define KERNEL_TENSOR_13_DIM_1_STRIDE_V_SHIFT                                             0
#define KERNEL_TENSOR_13_DIM_1_STRIDE_V_MASK                                              0xFFFFFFFF

#define KERNEL_TENSOR_13_DIM_2_SIZE                                                     0x6F8

#define KERNEL_TENSOR_13_DIM_2_SIZE_V_SHIFT                                               0
#define KERNEL_TENSOR_13_DIM_2_SIZE_V_MASK                                                0xFFFFFFFF

#define KERNEL_TENSOR_13_DIM_2_STRIDE                                                   0x6FC

#define KERNEL_TENSOR_13_DIM_2_STRIDE_V_SHIFT                                             0
#define KERNEL_TENSOR_13_DIM_2_STRIDE_V_MASK                                              0xFFFFFFFF

#define KERNEL_TENSOR_13_DIM_3_SIZE                                                     0x700

#define KERNEL_TENSOR_13_DIM_3_SIZE_V_SHIFT                                               0
#define KERNEL_TENSOR_13_DIM_3_SIZE_V_MASK                                                0xFFFFFFFF

#define KERNEL_TENSOR_13_DIM_3_STRIDE                                                   0x704

#define KERNEL_TENSOR_13_DIM_3_STRIDE_V_SHIFT                                             0
#define KERNEL_TENSOR_13_DIM_3_STRIDE_V_MASK                                              0xFFFFFFFF

#define KERNEL_TENSOR_13_DIM_4_SIZE                                                     0x708

#define KERNEL_TENSOR_13_DIM_4_SIZE_V_SHIFT                                               0
#define KERNEL_TENSOR_13_DIM_4_SIZE_V_MASK                                                0xFFFFFFFF

#define KERNEL_TENSOR_13_DIM_4_STRIDE                                                   0x70C

#define KERNEL_TENSOR_13_DIM_4_STRIDE_V_SHIFT                                             0
#define KERNEL_TENSOR_13_DIM_4_STRIDE_V_MASK                                              0xFFFFFFFF

#define KERNEL_TENSOR_14_BASE_ADDR_LOW                                                  0x710

#define KERNEL_TENSOR_14_BASE_ADDR_LOW_V_SHIFT                                            0
#define KERNEL_TENSOR_14_BASE_ADDR_LOW_V_MASK                                             0xFFFFFFFF

#define KERNEL_TENSOR_14_BASE_ADDR_HIGH                                                 0x714

#define KERNEL_TENSOR_14_BASE_ADDR_HIGH_V_SHIFT                                           0
#define KERNEL_TENSOR_14_BASE_ADDR_HIGH_V_MASK                                            0xFFFFFFFF

#define KERNEL_TENSOR_14_PADDING_VALUE                                                  0x718

#define KERNEL_TENSOR_14_PADDING_VALUE_V_SHIFT                                            0
#define KERNEL_TENSOR_14_PADDING_VALUE_V_MASK                                             0xFFFFFFFF

#define KERNEL_TENSOR_14_TENSOR_CONFIG                                                  0x71C

#define KERNEL_TENSOR_14_TENSOR_CONFIG_DATA_TYPE_SHIFT                                    0
#define KERNEL_TENSOR_14_TENSOR_CONFIG_DATA_TYPE_MASK                                     0x7
#define KERNEL_TENSOR_14_TENSOR_CONFIG_VALID_DIM_MASK_SHIFT                               8
#define KERNEL_TENSOR_14_TENSOR_CONFIG_VALID_DIM_MASK_MASK                                0x1F00
#define KERNEL_TENSOR_14_TENSOR_CONFIG_LAST_DIM_SHIFT                                     16
#define KERNEL_TENSOR_14_TENSOR_CONFIG_LAST_DIM_MASK                                      0x70000
#define KERNEL_TENSOR_14_TENSOR_CONFIG_RMW_SET_SHIFT                                      19
#define KERNEL_TENSOR_14_TENSOR_CONFIG_RMW_SET_MASK                                       0x80000
#define KERNEL_TENSOR_14_TENSOR_CONFIG_RMW_RESERV_SHIFT                                   20
#define KERNEL_TENSOR_14_TENSOR_CONFIG_RMW_RESERV_MASK                                    0x100000
#define KERNEL_TENSOR_14_TENSOR_CONFIG_RMW_OP_SHIFT                                       21
#define KERNEL_TENSOR_14_TENSOR_CONFIG_RMW_OP_MASK                                        0x600000

#define KERNEL_TENSOR_14_DIM_0_SIZE                                                     0x720

#define KERNEL_TENSOR_14_DIM_0_SIZE_V_SHIFT                                               0
#define KERNEL_TENSOR_14_DIM_0_SIZE_V_MASK                                                0xFFFFFFFF

#define KERNEL_TENSOR_14_DIM_0_STRIDE                                                   0x724

#define KERNEL_TENSOR_14_DIM_0_STRIDE_V_SHIFT                                             0
#define KERNEL_TENSOR_14_DIM_0_STRIDE_V_MASK                                              0xFFFFFFFF

#define KERNEL_TENSOR_14_DIM_1_SIZE                                                     0x728

#define KERNEL_TENSOR_14_DIM_1_SIZE_V_SHIFT                                               0
#define KERNEL_TENSOR_14_DIM_1_SIZE_V_MASK                                                0xFFFFFFFF

#define KERNEL_TENSOR_14_DIM_1_STRIDE                                                   0x72C

#define KERNEL_TENSOR_14_DIM_1_STRIDE_V_SHIFT                                             0
#define KERNEL_TENSOR_14_DIM_1_STRIDE_V_MASK                                              0xFFFFFFFF

#define KERNEL_TENSOR_14_DIM_2_SIZE                                                     0x730

#define KERNEL_TENSOR_14_DIM_2_SIZE_V_SHIFT                                               0
#define KERNEL_TENSOR_14_DIM_2_SIZE_V_MASK                                                0xFFFFFFFF

#define KERNEL_TENSOR_14_DIM_2_STRIDE                                                   0x734

#define KERNEL_TENSOR_14_DIM_2_STRIDE_V_SHIFT                                             0
#define KERNEL_TENSOR_14_DIM_2_STRIDE_V_MASK                                              0xFFFFFFFF

#define KERNEL_TENSOR_14_DIM_3_SIZE                                                     0x738

#define KERNEL_TENSOR_14_DIM_3_SIZE_V_SHIFT                                               0
#define KERNEL_TENSOR_14_DIM_3_SIZE_V_MASK                                                0xFFFFFFFF

#define KERNEL_TENSOR_14_DIM_3_STRIDE                                                   0x73C

#define KERNEL_TENSOR_14_DIM_3_STRIDE_V_SHIFT                                             0
#define KERNEL_TENSOR_14_DIM_3_STRIDE_V_MASK                                              0xFFFFFFFF

#define KERNEL_TENSOR_14_DIM_4_SIZE                                                     0x740

#define KERNEL_TENSOR_14_DIM_4_SIZE_V_SHIFT                                               0
#define KERNEL_TENSOR_14_DIM_4_SIZE_V_MASK                                                0xFFFFFFFF

#define KERNEL_TENSOR_14_DIM_4_STRIDE                                                   0x744

#define KERNEL_TENSOR_14_DIM_4_STRIDE_V_SHIFT                                             0
#define KERNEL_TENSOR_14_DIM_4_STRIDE_V_MASK                                              0xFFFFFFFF

#define KERNEL_TENSOR_15_BASE_ADDR_LOW                                                  0x748

#define KERNEL_TENSOR_15_BASE_ADDR_LOW_V_SHIFT                                            0
#define KERNEL_TENSOR_15_BASE_ADDR_LOW_V_MASK                                             0xFFFFFFFF

#define KERNEL_TENSOR_15_BASE_ADDR_HIGH                                                 0x74C

#define KERNEL_TENSOR_15_BASE_ADDR_HIGH_V_SHIFT                                           0
#define KERNEL_TENSOR_15_BASE_ADDR_HIGH_V_MASK                                            0xFFFFFFFF

#define KERNEL_TENSOR_15_PADDING_VALUE                                                  0x750

#define KERNEL_TENSOR_15_PADDING_VALUE_V_SHIFT                                            0
#define KERNEL_TENSOR_15_PADDING_VALUE_V_MASK                                             0xFFFFFFFF

#define KERNEL_TENSOR_15_TENSOR_CONFIG                                                  0x754

#define KERNEL_TENSOR_15_TENSOR_CONFIG_DATA_TYPE_SHIFT                                    0
#define KERNEL_TENSOR_15_TENSOR_CONFIG_DATA_TYPE_MASK                                     0x7
#define KERNEL_TENSOR_15_TENSOR_CONFIG_VALID_DIM_MASK_SHIFT                               8
#define KERNEL_TENSOR_15_TENSOR_CONFIG_VALID_DIM_MASK_MASK                                0x1F00
#define KERNEL_TENSOR_15_TENSOR_CONFIG_LAST_DIM_SHIFT                                     16
#define KERNEL_TENSOR_15_TENSOR_CONFIG_LAST_DIM_MASK                                      0x70000
#define KERNEL_TENSOR_15_TENSOR_CONFIG_RMW_SET_SHIFT                                      19
#define KERNEL_TENSOR_15_TENSOR_CONFIG_RMW_SET_MASK                                       0x80000
#define KERNEL_TENSOR_15_TENSOR_CONFIG_RMW_RESERV_SHIFT                                   20
#define KERNEL_TENSOR_15_TENSOR_CONFIG_RMW_RESERV_MASK                                    0x100000
#define KERNEL_TENSOR_15_TENSOR_CONFIG_RMW_OP_SHIFT                                       21
#define KERNEL_TENSOR_15_TENSOR_CONFIG_RMW_OP_MASK                                        0x600000

#define KERNEL_TENSOR_15_DIM_0_SIZE                                                     0x758

#define KERNEL_TENSOR_15_DIM_0_SIZE_V_SHIFT                                               0
#define KERNEL_TENSOR_15_DIM_0_SIZE_V_MASK                                                0xFFFFFFFF

#define KERNEL_TENSOR_15_DIM_0_STRIDE                                                   0x75C

#define KERNEL_TENSOR_15_DIM_0_STRIDE_V_SHIFT                                             0
#define KERNEL_TENSOR_15_DIM_0_STRIDE_V_MASK                                              0xFFFFFFFF

#define KERNEL_TENSOR_15_DIM_1_SIZE                                                     0x760

#define KERNEL_TENSOR_15_DIM_1_SIZE_V_SHIFT                                               0
#define KERNEL_TENSOR_15_DIM_1_SIZE_V_MASK                                                0xFFFFFFFF

#define KERNEL_TENSOR_15_DIM_1_STRIDE                                                   0x764

#define KERNEL_TENSOR_15_DIM_1_STRIDE_V_SHIFT                                             0
#define KERNEL_TENSOR_15_DIM_1_STRIDE_V_MASK                                              0xFFFFFFFF

#define KERNEL_TENSOR_15_DIM_2_SIZE                                                     0x768

#define KERNEL_TENSOR_15_DIM_2_SIZE_V_SHIFT                                               0
#define KERNEL_TENSOR_15_DIM_2_SIZE_V_MASK                                                0xFFFFFFFF

#define KERNEL_TENSOR_15_DIM_2_STRIDE                                                   0x76C

#define KERNEL_TENSOR_15_DIM_2_STRIDE_V_SHIFT                                             0
#define KERNEL_TENSOR_15_DIM_2_STRIDE_V_MASK                                              0xFFFFFFFF

#define KERNEL_TENSOR_15_DIM_3_SIZE                                                     0x770

#define KERNEL_TENSOR_15_DIM_3_SIZE_V_SHIFT                                               0
#define KERNEL_TENSOR_15_DIM_3_SIZE_V_MASK                                                0xFFFFFFFF

#define KERNEL_TENSOR_15_DIM_3_STRIDE                                                   0x774

#define KERNEL_TENSOR_15_DIM_3_STRIDE_V_SHIFT                                             0
#define KERNEL_TENSOR_15_DIM_3_STRIDE_V_MASK                                              0xFFFFFFFF

#define KERNEL_TENSOR_15_DIM_4_SIZE                                                     0x778

#define KERNEL_TENSOR_15_DIM_4_SIZE_V_SHIFT                                               0
#define KERNEL_TENSOR_15_DIM_4_SIZE_V_MASK                                                0xFFFFFFFF

#define KERNEL_TENSOR_15_DIM_4_STRIDE                                                   0x77C

#define KERNEL_TENSOR_15_DIM_4_STRIDE_V_SHIFT                                             0
#define KERNEL_TENSOR_15_DIM_4_STRIDE_V_MASK                                              0xFFFFFFFF

#define KERNEL_SYNC_OBJECT_MESSAGE                                                      0x780

#define KERNEL_SYNC_OBJECT_MESSAGE_SO_WRITE_VALUE_SHIFT                                   0
#define KERNEL_SYNC_OBJECT_MESSAGE_SO_WRITE_VALUE_MASK                                    0xFFFF
#define KERNEL_SYNC_OBJECT_MESSAGE_RSV_SHIFT                                              16
#define KERNEL_SYNC_OBJECT_MESSAGE_RSV_MASK                                               0x1FFF0000
#define KERNEL_SYNC_OBJECT_MESSAGE_SO_OPERATION_SHIFT                                     29
#define KERNEL_SYNC_OBJECT_MESSAGE_SO_OPERATION_MASK                                      0xE0000000

#define KERNEL_SYNC_OBJECT_ADDR                                                         0x784

#define KERNEL_SYNC_OBJECT_ADDR_V_SHIFT                                                   0
#define KERNEL_SYNC_OBJECT_ADDR_V_MASK                                                    0xFFFFFFFF

#define KERNEL_KERNEL_BASE_ADDRESS_LOW                                                  0x788

#define KERNEL_KERNEL_BASE_ADDRESS_LOW_V_SHIFT                                            0
#define KERNEL_KERNEL_BASE_ADDRESS_LOW_V_MASK                                             0xFFFFFFFF

#define KERNEL_KERNEL_BASE_ADDRESS_HIGH                                                 0x78C

#define KERNEL_KERNEL_BASE_ADDRESS_HIGH_V_SHIFT                                           0
#define KERNEL_KERNEL_BASE_ADDRESS_HIGH_V_MASK                                            0xFFFFFFFF

#define KERNEL_TID_BASE_DIM_0                                                           0x790

#define KERNEL_TID_BASE_DIM_0_V_SHIFT                                                     0
#define KERNEL_TID_BASE_DIM_0_V_MASK                                                      0xFFFFFFFF

#define KERNEL_TID_SIZE_DIM_0                                                           0x794

#define KERNEL_TID_SIZE_DIM_0_V_SHIFT                                                     0
#define KERNEL_TID_SIZE_DIM_0_V_MASK                                                      0xFFFFFFFF

#define KERNEL_TID_BASE_DIM_1                                                           0x798

#define KERNEL_TID_BASE_DIM_1_V_SHIFT                                                     0
#define KERNEL_TID_BASE_DIM_1_V_MASK                                                      0xFFFFFFFF

#define KERNEL_TID_SIZE_DIM_1                                                           0x79C

#define KERNEL_TID_SIZE_DIM_1_V_SHIFT                                                     0
#define KERNEL_TID_SIZE_DIM_1_V_MASK                                                      0xFFFFFFFF

#define KERNEL_TID_BASE_DIM_2                                                           0x7A0

#define KERNEL_TID_BASE_DIM_2_V_SHIFT                                                     0
#define KERNEL_TID_BASE_DIM_2_V_MASK                                                      0xFFFFFFFF

#define KERNEL_TID_SIZE_DIM_2                                                           0x7A4

#define KERNEL_TID_SIZE_DIM_2_V_SHIFT                                                     0
#define KERNEL_TID_SIZE_DIM_2_V_MASK                                                      0xFFFFFFFF

#define KERNEL_TID_BASE_DIM_3                                                           0x7A8

#define KERNEL_TID_BASE_DIM_3_V_SHIFT                                                     0
#define KERNEL_TID_BASE_DIM_3_V_MASK                                                      0xFFFFFFFF

#define KERNEL_TID_SIZE_DIM_3                                                           0x7AC

#define KERNEL_TID_SIZE_DIM_3_V_SHIFT                                                     0
#define KERNEL_TID_SIZE_DIM_3_V_MASK                                                      0xFFFFFFFF

#define KERNEL_TID_BASE_DIM_4                                                           0x7B0

#define KERNEL_TID_BASE_DIM_4_V_SHIFT                                                     0
#define KERNEL_TID_BASE_DIM_4_V_MASK                                                      0xFFFFFFFF

#define KERNEL_TID_SIZE_DIM_4                                                           0x7B4

#define KERNEL_TID_SIZE_DIM_4_V_SHIFT                                                     0
#define KERNEL_TID_SIZE_DIM_4_V_MASK                                                      0xFFFFFFFF

#define KERNEL_KERNEL_CONFIG                                                            0x7B8

#define KERNEL_KERNEL_CONFIG_SMALL_VLM_SHIFT                                              0
#define KERNEL_KERNEL_CONFIG_SMALL_VLM_MASK                                               0x1
#define KERNEL_KERNEL_CONFIG_ASO_EVICT_L0_SHIFT                                           1
#define KERNEL_KERNEL_CONFIG_ASO_EVICT_L0_MASK                                            0x2
#define KERNEL_KERNEL_CONFIG_NUM_VALID_SRFS_SHIFT                                         2
#define KERNEL_KERNEL_CONFIG_NUM_VALID_SRFS_MASK                                          0xFC
#define KERNEL_KERNEL_CONFIG_RD_RATE_LIMIT_RST_TOKEN_SHIFT                                8
#define KERNEL_KERNEL_CONFIG_RD_RATE_LIMIT_RST_TOKEN_MASK                                 0xFF00
#define KERNEL_KERNEL_CONFIG_WR_RATE_LIMIT_RST_TOKEN_SHIFT                                16
#define KERNEL_KERNEL_CONFIG_WR_RATE_LIMIT_RST_TOKEN_MASK                                 0xFF0000

#define KERNEL_KERNEL_ID                                                                0x7BC

#define KERNEL_KERNEL_ID_V_SHIFT                                                          0
#define KERNEL_KERNEL_ID_V_MASK                                                           0xFFFF

#define KERNEL_SRF_0                                                                    0x7C0

#define KERNEL_SRF_0_V_SHIFT                                                              0
#define KERNEL_SRF_0_V_MASK                                                               0xFFFFFFFF

#define KERNEL_SRF_1                                                                    0x7C4

#define KERNEL_SRF_1_V_SHIFT                                                              0
#define KERNEL_SRF_1_V_MASK                                                               0xFFFFFFFF

#define KERNEL_SRF_2                                                                    0x7C8

#define KERNEL_SRF_2_V_SHIFT                                                              0
#define KERNEL_SRF_2_V_MASK                                                               0xFFFFFFFF

#define KERNEL_SRF_3                                                                    0x7CC

#define KERNEL_SRF_3_V_SHIFT                                                              0
#define KERNEL_SRF_3_V_MASK                                                               0xFFFFFFFF

#define KERNEL_SRF_4                                                                    0x7D0

#define KERNEL_SRF_4_V_SHIFT                                                              0
#define KERNEL_SRF_4_V_MASK                                                               0xFFFFFFFF

#define KERNEL_SRF_5                                                                    0x7D4

#define KERNEL_SRF_5_V_SHIFT                                                              0
#define KERNEL_SRF_5_V_MASK                                                               0xFFFFFFFF

#define KERNEL_SRF_6                                                                    0x7D8

#define KERNEL_SRF_6_V_SHIFT                                                              0
#define KERNEL_SRF_6_V_MASK                                                               0xFFFFFFFF

#define KERNEL_SRF_7                                                                    0x7DC

#define KERNEL_SRF_7_V_SHIFT                                                              0
#define KERNEL_SRF_7_V_MASK                                                               0xFFFFFFFF

#define KERNEL_SRF_8                                                                    0x7E0

#define KERNEL_SRF_8_V_SHIFT                                                              0
#define KERNEL_SRF_8_V_MASK                                                               0xFFFFFFFF

#define KERNEL_SRF_9                                                                    0x7E4

#define KERNEL_SRF_9_V_SHIFT                                                              0
#define KERNEL_SRF_9_V_MASK                                                               0xFFFFFFFF

#define KERNEL_SRF_10                                                                   0x7E8

#define KERNEL_SRF_10_V_SHIFT                                                             0
#define KERNEL_SRF_10_V_MASK                                                              0xFFFFFFFF

#define KERNEL_SRF_11                                                                   0x7EC

#define KERNEL_SRF_11_V_SHIFT                                                             0
#define KERNEL_SRF_11_V_MASK                                                              0xFFFFFFFF

#define KERNEL_SRF_12                                                                   0x7F0

#define KERNEL_SRF_12_V_SHIFT                                                             0
#define KERNEL_SRF_12_V_MASK                                                              0xFFFFFFFF

#define KERNEL_SRF_13                                                                   0x7F4

#define KERNEL_SRF_13_V_SHIFT                                                             0
#define KERNEL_SRF_13_V_MASK                                                              0xFFFFFFFF

#define KERNEL_SRF_14                                                                   0x7F8

#define KERNEL_SRF_14_V_SHIFT                                                             0
#define KERNEL_SRF_14_V_MASK                                                              0xFFFFFFFF

#define KERNEL_SRF_15                                                                   0x7FC

#define KERNEL_SRF_15_V_SHIFT                                                             0
#define KERNEL_SRF_15_V_MASK                                                              0xFFFFFFFF

#define KERNEL_SRF_16                                                                   0x800

#define KERNEL_SRF_16_V_SHIFT                                                             0
#define KERNEL_SRF_16_V_MASK                                                              0xFFFFFFFF

#define KERNEL_SRF_17                                                                   0x804

#define KERNEL_SRF_17_V_SHIFT                                                             0
#define KERNEL_SRF_17_V_MASK                                                              0xFFFFFFFF

#define KERNEL_SRF_18                                                                   0x808

#define KERNEL_SRF_18_V_SHIFT                                                             0
#define KERNEL_SRF_18_V_MASK                                                              0xFFFFFFFF

#define KERNEL_SRF_19                                                                   0x80C

#define KERNEL_SRF_19_V_SHIFT                                                             0
#define KERNEL_SRF_19_V_MASK                                                              0xFFFFFFFF

#define KERNEL_SRF_20                                                                   0x810

#define KERNEL_SRF_20_V_SHIFT                                                             0
#define KERNEL_SRF_20_V_MASK                                                              0xFFFFFFFF

#define KERNEL_SRF_21                                                                   0x814

#define KERNEL_SRF_21_V_SHIFT                                                             0
#define KERNEL_SRF_21_V_MASK                                                              0xFFFFFFFF

#define KERNEL_SRF_22                                                                   0x818

#define KERNEL_SRF_22_V_SHIFT                                                             0
#define KERNEL_SRF_22_V_MASK                                                              0xFFFFFFFF

#define KERNEL_SRF_23                                                                   0x81C

#define KERNEL_SRF_23_V_SHIFT                                                             0
#define KERNEL_SRF_23_V_MASK                                                              0xFFFFFFFF

#define KERNEL_SRF_24                                                                   0x820

#define KERNEL_SRF_24_V_SHIFT                                                             0
#define KERNEL_SRF_24_V_MASK                                                              0xFFFFFFFF

#define KERNEL_SRF_25                                                                   0x824

#define KERNEL_SRF_25_V_SHIFT                                                             0
#define KERNEL_SRF_25_V_MASK                                                              0xFFFFFFFF

#define KERNEL_SRF_26                                                                   0x828

#define KERNEL_SRF_26_V_SHIFT                                                             0
#define KERNEL_SRF_26_V_MASK                                                              0xFFFFFFFF

#define KERNEL_SRF_27                                                                   0x82C

#define KERNEL_SRF_27_V_SHIFT                                                             0
#define KERNEL_SRF_27_V_MASK                                                              0xFFFFFFFF

#define KERNEL_SRF_28                                                                   0x830

#define KERNEL_SRF_28_V_SHIFT                                                             0
#define KERNEL_SRF_28_V_MASK                                                              0xFFFFFFFF

#define KERNEL_SRF_29                                                                   0x834

#define KERNEL_SRF_29_V_SHIFT                                                             0
#define KERNEL_SRF_29_V_MASK                                                              0xFFFFFFFF

#define KERNEL_SRF_30                                                                   0x838

#define KERNEL_SRF_30_V_SHIFT                                                             0
#define KERNEL_SRF_30_V_MASK                                                              0xFFFFFFFF

#define KERNEL_SRF_31                                                                   0x83C

#define KERNEL_SRF_31_V_SHIFT                                                             0
#define KERNEL_SRF_31_V_MASK                                                              0xFFFFFFFF

#define ROUND_CSR                                                                       0x8FC

#define ROUND_CSR_MODE_SHIFT                                                              0
#define ROUND_CSR_MODE_MASK                                                               0x7

#define PROT                                                                            0x900

#define PROT_AWPROT_SHIFT                                                                 0
#define PROT_AWPROT_MASK                                                                  0x7
#define PROT_ARPROT_SHIFT                                                                 3
#define PROT_ARPROT_MASK                                                                  0x38

#define SEMAPHORE                                                                       0x908

#define SEMAPHORE_V_SHIFT                                                                 0
#define SEMAPHORE_V_MASK                                                                  0xFFFFFFFF

#define VFLAGS                                                                          0x90C

#define VFLAGS_V_SHIFT                                                                    0
#define VFLAGS_V_MASK                                                                     0xF

#define SFLAGS                                                                          0x910

#define SFLAGS_V_SHIFT                                                                    0
#define SFLAGS_V_MASK                                                                     0xF

#define LFSR_POLYNOM                                                                    0x918

#define LFSR_POLYNOM_V_SHIFT                                                              0
#define LFSR_POLYNOM_V_MASK                                                               0xFFFFFFFF

#define STATUS                                                                          0x91C

#define STATUS_SCALAR_PIPE_EMPTY_SHIFT                                                    1
#define STATUS_SCALAR_PIPE_EMPTY_MASK                                                     0x2
#define STATUS_VECTOR_PIPE_EMPTY_SHIFT                                                    2
#define STATUS_VECTOR_PIPE_EMPTY_MASK                                                     0x4
#define STATUS_IQ_EMPTY_SHIFT                                                             3
#define STATUS_IQ_EMPTY_MASK                                                              0x8
#define STATUS_SB_EMPTY_SHIFT                                                             5
#define STATUS_SB_EMPTY_MASK                                                              0x20

#define CFG_BASE_ADDRESS_HIGH                                                           0x920

#define CFG_BASE_ADDRESS_HIGH_V_SHIFT                                                     0
#define CFG_BASE_ADDRESS_HIGH_V_MASK                                                      0xFFFFFFFF

#define CFG_SUBTRACT_VALUE                                                              0x924

#define CFG_SUBTRACT_VALUE_V_SHIFT                                                        0
#define CFG_SUBTRACT_VALUE_V_MASK                                                         0xFFFFFFFF

#define SM_BASE_ADDRESS_HIGH                                                            0x92C

#define SM_BASE_ADDRESS_HIGH_V_SHIFT                                                      0
#define SM_BASE_ADDRESS_HIGH_V_MASK                                                       0xFFFFFFFF

#define TPC_CMD                                                                         0x930

#define TPC_CMD_ICACHE_INVALIDATE_SHIFT                                                   0
#define TPC_CMD_ICACHE_INVALIDATE_MASK                                                    0x1
#define TPC_CMD_DCACHE_INVALIDATE_SHIFT                                                   1
#define TPC_CMD_DCACHE_INVALIDATE_MASK                                                    0x2
#define TPC_CMD_LCACHE_INVALIDATE_SHIFT                                                   2
#define TPC_CMD_LCACHE_INVALIDATE_MASK                                                    0x4
#define TPC_CMD_TCACHE_INVALIDATE_SHIFT                                                   3
#define TPC_CMD_TCACHE_INVALIDATE_MASK                                                    0x8
#define TPC_CMD_ICACHE_PREFETCH_64KB_SHIFT                                                4
#define TPC_CMD_ICACHE_PREFETCH_64KB_MASK                                                 0x10
#define TPC_CMD_ICACHE_PREFETCH_32KB_SHIFT                                                5
#define TPC_CMD_ICACHE_PREFETCH_32KB_MASK                                                 0x20
#define TPC_CMD_QMAN_STOP_SHIFT                                                           6
#define TPC_CMD_QMAN_STOP_MASK                                                            0x40

#define TPC_EXECUTE                                                                     0x938

#define TPC_EXECUTE_V_SHIFT                                                               0
#define TPC_EXECUTE_V_MASK                                                                0x1

#define TPC_STALL                                                                       0x93C

#define TPC_STALL_V_SHIFT                                                                 0
#define TPC_STALL_V_MASK                                                                  0x1

#define ICACHE_BASE_ADDERESS_LOW                                                        0x940

#define ICACHE_BASE_ADDERESS_LOW_V_SHIFT                                                  0
#define ICACHE_BASE_ADDERESS_LOW_V_MASK                                                   0xFFFFFFFF

#define ICACHE_BASE_ADDERESS_HIGH                                                       0x944

#define ICACHE_BASE_ADDERESS_HIGH_V_SHIFT                                                 0
#define ICACHE_BASE_ADDERESS_HIGH_V_MASK                                                  0xFFFFFFFF

#define RD_RATE_LIMIT                                                                   0x948

#define RD_RATE_LIMIT_ENABLE_SHIFT                                                        0
#define RD_RATE_LIMIT_ENABLE_MASK                                                         0x1
#define RD_RATE_LIMIT_SATURATION_SHIFT                                                    1
#define RD_RATE_LIMIT_SATURATION_MASK                                                     0x1FE
#define RD_RATE_LIMIT_TIMEOUT_SHIFT                                                       9
#define RD_RATE_LIMIT_TIMEOUT_MASK                                                        0x1FE00

#define WR_RATE_LIMIT                                                                   0x950

#define WR_RATE_LIMIT_ENABLE_SHIFT                                                        0
#define WR_RATE_LIMIT_ENABLE_MASK                                                         0x1
#define WR_RATE_LIMIT_SATURATION_SHIFT                                                    1
#define WR_RATE_LIMIT_SATURATION_MASK                                                     0x1FE
#define WR_RATE_LIMIT_TIMEOUT_SHIFT                                                       9
#define WR_RATE_LIMIT_TIMEOUT_MASK                                                        0x1FE00

#define MSS_CONFIG                                                                      0x954

#define MSS_CONFIG_AWCACHE_SHIFT                                                          0
#define MSS_CONFIG_AWCACHE_MASK                                                           0xF
#define MSS_CONFIG_ARCACHE_SHIFT                                                          4
#define MSS_CONFIG_ARCACHE_MASK                                                           0xF0
#define MSS_CONFIG_ICACHE_FETCH_LINE_NUM_SHIFT                                            8
#define MSS_CONFIG_ICACHE_FETCH_LINE_NUM_MASK                                             0x300
#define MSS_CONFIG_EXPOSED_PIPE_DIS_SHIFT                                                 10
#define MSS_CONFIG_EXPOSED_PIPE_DIS_MASK                                                  0x400
#define MSS_CONFIG_DCACHE_PREFETCH_DIS_SHIFT                                              11
#define MSS_CONFIG_DCACHE_PREFETCH_DIS_MASK                                               0x800

#define TPC_INTR_CAUSE                                                                  0x958

#define TPC_INTR_CAUSE_CAUSE_SHIFT                                                        0
#define TPC_INTR_CAUSE_CAUSE_MASK                                                         0xFFFFF

#define TPC_INTR_MASK                                                                   0x95C

#define TPC_INTR_MASK_MASK_SHIFT                                                          0
#define TPC_INTR_MASK_MASK_MASK                                                           0xFFFFF

#define WQ_CREDITS                                                                      0x960

#define WQ_CREDITS_ST_G_SHIFT                                                             0
#define WQ_CREDITS_ST_G_MASK                                                              0xF
#define WQ_CREDITS_KERNEL_FIFO_SHIFT                                                      4
#define WQ_CREDITS_KERNEL_FIFO_MASK                                                       0x70

#define ARUSER_LO                                                                       0x964

#define ARUSER_LO_V_SHIFT                                                                 0
#define ARUSER_LO_V_MASK                                                                  0x7FF

#define ARUSER_HI                                                                       0x968

#define ARUSER_HI_V_SHIFT                                                                 11
#define ARUSER_HI_V_MASK                                                                  0x1800
#define ARUSER_HI_RSRV_SHIFT                                                              13
#define ARUSER_HI_RSRV_MASK                                                               0xFFFFE000

#define AWUSER_LO                                                                       0x96C

#define AWUSER_LO_V_SHIFT                                                                 0
#define AWUSER_LO_V_MASK                                                                  0x7FF

#define AWUSER_HI                                                                       0x970

#define AWUSER_HI_V_SHIFT                                                                 11
#define AWUSER_HI_V_MASK                                                                  0x1800
#define AWUSER_HI_RSRV_SHIFT                                                              13
#define AWUSER_HI_RSRV_MASK                                                               0xFFFFE000

#define OPCODE_EXEC                                                                     0x974

#define OPCODE_EXEC_SPU_OP_SHIFT                                                          0
#define OPCODE_EXEC_SPU_OP_MASK                                                           0x7F
#define OPCODE_EXEC_SPU_EN_SHIFT                                                          7
#define OPCODE_EXEC_SPU_EN_MASK                                                           0x80
#define OPCODE_EXEC_VPU_OP_SHIFT                                                          8
#define OPCODE_EXEC_VPU_OP_MASK                                                           0x7F00
#define OPCODE_EXEC_VPU_EN_SHIFT                                                          15
#define OPCODE_EXEC_VPU_EN_MASK                                                           0x8000
#define OPCODE_EXEC_LD_OP_SHIFT                                                           16
#define OPCODE_EXEC_LD_OP_MASK                                                            0x7F0000
#define OPCODE_EXEC_LD_EN_SHIFT                                                           23
#define OPCODE_EXEC_LD_EN_MASK                                                            0x800000
#define OPCODE_EXEC_ST_OP_SHIFT                                                           24
#define OPCODE_EXEC_ST_OP_MASK                                                            0x7F000000
#define OPCODE_EXEC_ST_EN_SHIFT                                                           31
#define OPCODE_EXEC_ST_EN_MASK                                                            0x80000000

#define LUT_FUNC32_BASE_ADDR_LO                                                         0x978

#define LUT_FUNC32_BASE_ADDR_LO_V_SHIFT                                                   0
#define LUT_FUNC32_BASE_ADDR_LO_V_MASK                                                    0xFFFFFFFF

#define LUT_FUNC32_BASE_ADDR_HI                                                         0x97C

#define LUT_FUNC32_BASE_ADDR_HI_V_SHIFT                                                   0
#define LUT_FUNC32_BASE_ADDR_HI_V_MASK                                                    0xFFFFFFFF

#define LUT_FUNC64_BASE_ADDR_LO                                                         0x980

#define LUT_FUNC64_BASE_ADDR_LO_V_SHIFT                                                   0
#define LUT_FUNC64_BASE_ADDR_LO_V_MASK                                                    0xFFFFFFFF

#define LUT_FUNC64_BASE_ADDR_HI                                                         0x984

#define LUT_FUNC64_BASE_ADDR_HI_V_SHIFT                                                   0
#define LUT_FUNC64_BASE_ADDR_HI_V_MASK                                                    0xFFFFFFFF

#define LUT_FUNC128_BASE_ADDR_LO                                                        0x988

#define LUT_FUNC128_BASE_ADDR_LO_V_SHIFT                                                  0
#define LUT_FUNC128_BASE_ADDR_LO_V_MASK                                                   0xFFFFFFFF

#define LUT_FUNC128_BASE_ADDR_HI                                                        0x98C

#define LUT_FUNC128_BASE_ADDR_HI_V_SHIFT                                                  0
#define LUT_FUNC128_BASE_ADDR_HI_V_MASK                                                   0xFFFFFFFF

#define LUT_FUNC256_BASE_ADDR_LO                                                        0x990

#define LUT_FUNC256_BASE_ADDR_LO_V_SHIFT                                                  0
#define LUT_FUNC256_BASE_ADDR_LO_V_MASK                                                   0xFFFFFFFF

#define LUT_FUNC256_BASE_ADDR_HI                                                        0x994

#define LUT_FUNC256_BASE_ADDR_HI_V_SHIFT                                                  0
#define LUT_FUNC256_BASE_ADDR_HI_V_MASK                                                   0xFFFFFFFF

#define TSB_CFG_MAX_SIZE                                                                0x998

#define TSB_CFG_MAX_SIZE_DATA_SHIFT                                                       0
#define TSB_CFG_MAX_SIZE_DATA_MASK                                                        0xFFFF
#define TSB_CFG_MAX_SIZE_MD_SHIFT                                                         16
#define TSB_CFG_MAX_SIZE_MD_MASK                                                          0xFFFF0000

#define TSB_CFG                                                                         0x99C

#define TSB_CFG_FORCE_MISS_SHIFT                                                          0
#define TSB_CFG_FORCE_MISS_MASK                                                           0x1
#define TSB_CFG_MAX_OS_SHIFT                                                              1
#define TSB_CFG_MAX_OS_MASK                                                               0x1FFFE

#define DBGMEM_ADD                                                                      0x9A0

#define DBGMEM_ADD_V_SHIFT                                                                0
#define DBGMEM_ADD_V_MASK                                                                 0xFFFFFFFF

#define DBGMEM_DATA_WR                                                                  0x9A4

#define DBGMEM_DATA_WR_V_SHIFT                                                            0
#define DBGMEM_DATA_WR_V_MASK                                                             0xFFFFFFFF

#define DBGMEM_DATA_RD                                                                  0x9A8

#define DBGMEM_DATA_RD_V_SHIFT                                                            0
#define DBGMEM_DATA_RD_V_MASK                                                             0xFFFFFFFF

#define DBGMEM_CTRL                                                                     0x9AC

#define DBGMEM_CTRL_WR_NRD_SHIFT                                                          0
#define DBGMEM_CTRL_WR_NRD_MASK                                                           0x1

#define DBGMEM_RC                                                                       0x9B0

#define DBGMEM_RC_VALID_SHIFT                                                             0
#define DBGMEM_RC_VALID_MASK                                                              0x1

#define TSB_INFLIGHT_CNTR                                                               0x9B4

#define TSB_INFLIGHT_CNTR_V_SHIFT                                                         0
#define TSB_INFLIGHT_CNTR_V_MASK                                                          0xFFFFFFFF

#define WQ_INFLIGHT_CNTR                                                                0x9B8

#define WQ_INFLIGHT_CNTR_HBW_SHIFT                                                        0
#define WQ_INFLIGHT_CNTR_HBW_MASK                                                         0xFFFF
#define WQ_INFLIGHT_CNTR_LBW_SHIFT                                                        16
#define WQ_INFLIGHT_CNTR_LBW_MASK                                                         0xF0000

#define WQ_LBW_TOTAL_CNTR                                                               0x9BC

#define WQ_LBW_TOTAL_CNTR_V_SHIFT                                                         0
#define WQ_LBW_TOTAL_CNTR_V_MASK                                                          0xFFFFFFFF

#define WQ_HBW_TOTAL_CNTR                                                               0x9C0

#define WQ_HBW_TOTAL_CNTR_V_SHIFT                                                         0
#define WQ_HBW_TOTAL_CNTR_V_MASK                                                          0xFFFFFFFF

#define IRQ_OCCOUPY_CNTR                                                                0x9C4

#define IRQ_OCCOUPY_CNTR_V_SHIFT                                                          0
#define IRQ_OCCOUPY_CNTR_V_MASK                                                           0xFFFFFFFF

#define FUNC_MBIST_CNTRL                                                                0x9D0

#define FUNC_MBIST_CNTRL_MBIST_START_SHIFT                                                0
#define FUNC_MBIST_CNTRL_MBIST_START_MASK                                                 0x1
#define FUNC_MBIST_CNTRL_MBIST_DONE_SHIFT                                                 1
#define FUNC_MBIST_CNTRL_MBIST_DONE_MASK                                                  0x2
#define FUNC_MBIST_CNTRL_MBIST_ACTIVE_SHIFT                                               2
#define FUNC_MBIST_CNTRL_MBIST_ACTIVE_MASK                                                0x4
#define FUNC_MBIST_CNTRL_MBIST_FAILED_SHIFT                                               16
#define FUNC_MBIST_CNTRL_MBIST_FAILED_MASK                                                0x3FF0000

#define FUNC_MBIST_PAT                                                                  0x9D4

#define FUNC_MBIST_PAT_MBIST_PATTERN0_EVEN_SHIFT                                          0
#define FUNC_MBIST_PAT_MBIST_PATTERN0_EVEN_MASK                                           0x3
#define FUNC_MBIST_PAT_MBIST_PATTERN0_ODD_SHIFT                                           2
#define FUNC_MBIST_PAT_MBIST_PATTERN0_ODD_MASK                                            0xC
#define FUNC_MBIST_PAT_MBIST_PATTERN1_EVEN_SHIFT                                          4
#define FUNC_MBIST_PAT_MBIST_PATTERN1_EVEN_MASK                                           0x30
#define FUNC_MBIST_PAT_MBIST_PATTERN1_ODD_SHIFT                                           6
#define FUNC_MBIST_PAT_MBIST_PATTERN1_ODD_MASK                                            0xC0
#define FUNC_MBIST_PAT_MBIST_PATTERN2_EVEN_SHIFT                                          8
#define FUNC_MBIST_PAT_MBIST_PATTERN2_EVEN_MASK                                           0x300
#define FUNC_MBIST_PAT_MBIST_PATTERN2_ODD_SHIFT                                           10
#define FUNC_MBIST_PAT_MBIST_PATTERN2_ODD_MASK                                            0xC00

#define FUNC_MBIST_MEM_0                                                                0x9D8

#define FUNC_MBIST_MEM_0_MAX_ADDR_SHIFT                                                   0
#define FUNC_MBIST_MEM_0_MAX_ADDR_MASK                                                    0x7FF
#define FUNC_MBIST_MEM_0_PATTERN_EN_SHIFT                                                 12
#define FUNC_MBIST_MEM_0_PATTERN_EN_MASK                                                  0x7000
#define FUNC_MBIST_MEM_0_LAST_FAILED_ADDR_SHIFT                                           16
#define FUNC_MBIST_MEM_0_LAST_FAILED_ADDR_MASK                                            0x7FF0000
#define FUNC_MBIST_MEM_0_LAST_FAILED_PATTERN_SHIFT                                        28
#define FUNC_MBIST_MEM_0_LAST_FAILED_PATTERN_MASK                                         0x70000000

#define FUNC_MBIST_MEM_1                                                                0x9DC

#define FUNC_MBIST_MEM_1_MAX_ADDR_SHIFT                                                   0
#define FUNC_MBIST_MEM_1_MAX_ADDR_MASK                                                    0x7FF
#define FUNC_MBIST_MEM_1_PATTERN_EN_SHIFT                                                 12
#define FUNC_MBIST_MEM_1_PATTERN_EN_MASK                                                  0x7000
#define FUNC_MBIST_MEM_1_LAST_FAILED_ADDR_SHIFT                                           16
#define FUNC_MBIST_MEM_1_LAST_FAILED_ADDR_MASK                                            0x7FF0000
#define FUNC_MBIST_MEM_1_LAST_FAILED_PATTERN_SHIFT                                        28
#define FUNC_MBIST_MEM_1_LAST_FAILED_PATTERN_MASK                                         0x70000000

#define FUNC_MBIST_MEM_2                                                                0x9E0

#define FUNC_MBIST_MEM_2_MAX_ADDR_SHIFT                                                   0
#define FUNC_MBIST_MEM_2_MAX_ADDR_MASK                                                    0x7FF
#define FUNC_MBIST_MEM_2_PATTERN_EN_SHIFT                                                 12
#define FUNC_MBIST_MEM_2_PATTERN_EN_MASK                                                  0x7000
#define FUNC_MBIST_MEM_2_LAST_FAILED_ADDR_SHIFT                                           16
#define FUNC_MBIST_MEM_2_LAST_FAILED_ADDR_MASK                                            0x7FF0000
#define FUNC_MBIST_MEM_2_LAST_FAILED_PATTERN_SHIFT                                        28
#define FUNC_MBIST_MEM_2_LAST_FAILED_PATTERN_MASK                                         0x70000000

#define FUNC_MBIST_MEM_3                                                                0x9E4

#define FUNC_MBIST_MEM_3_MAX_ADDR_SHIFT                                                   0
#define FUNC_MBIST_MEM_3_MAX_ADDR_MASK                                                    0x7FF
#define FUNC_MBIST_MEM_3_PATTERN_EN_SHIFT                                                 12
#define FUNC_MBIST_MEM_3_PATTERN_EN_MASK                                                  0x7000
#define FUNC_MBIST_MEM_3_LAST_FAILED_ADDR_SHIFT                                           16
#define FUNC_MBIST_MEM_3_LAST_FAILED_ADDR_MASK                                            0x7FF0000
#define FUNC_MBIST_MEM_3_LAST_FAILED_PATTERN_SHIFT                                        28
#define FUNC_MBIST_MEM_3_LAST_FAILED_PATTERN_MASK                                         0x70000000

#define FUNC_MBIST_MEM_4                                                                0x9E8

#define FUNC_MBIST_MEM_4_MAX_ADDR_SHIFT                                                   0
#define FUNC_MBIST_MEM_4_MAX_ADDR_MASK                                                    0x7FF
#define FUNC_MBIST_MEM_4_PATTERN_EN_SHIFT                                                 12
#define FUNC_MBIST_MEM_4_PATTERN_EN_MASK                                                  0x7000
#define FUNC_MBIST_MEM_4_LAST_FAILED_ADDR_SHIFT                                           16
#define FUNC_MBIST_MEM_4_LAST_FAILED_ADDR_MASK                                            0x7FF0000
#define FUNC_MBIST_MEM_4_LAST_FAILED_PATTERN_SHIFT                                        28
#define FUNC_MBIST_MEM_4_LAST_FAILED_PATTERN_MASK                                         0x70000000

#define FUNC_MBIST_MEM_5                                                                0x9EC

#define FUNC_MBIST_MEM_5_MAX_ADDR_SHIFT                                                   0
#define FUNC_MBIST_MEM_5_MAX_ADDR_MASK                                                    0x7FF
#define FUNC_MBIST_MEM_5_PATTERN_EN_SHIFT                                                 12
#define FUNC_MBIST_MEM_5_PATTERN_EN_MASK                                                  0x7000
#define FUNC_MBIST_MEM_5_LAST_FAILED_ADDR_SHIFT                                           16
#define FUNC_MBIST_MEM_5_LAST_FAILED_ADDR_MASK                                            0x7FF0000
#define FUNC_MBIST_MEM_5_LAST_FAILED_PATTERN_SHIFT                                        28
#define FUNC_MBIST_MEM_5_LAST_FAILED_PATTERN_MASK                                         0x70000000

#define FUNC_MBIST_MEM_6                                                                0x9F0

#define FUNC_MBIST_MEM_6_MAX_ADDR_SHIFT                                                   0
#define FUNC_MBIST_MEM_6_MAX_ADDR_MASK                                                    0x7FF
#define FUNC_MBIST_MEM_6_PATTERN_EN_SHIFT                                                 12
#define FUNC_MBIST_MEM_6_PATTERN_EN_MASK                                                  0x7000
#define FUNC_MBIST_MEM_6_LAST_FAILED_ADDR_SHIFT                                           16
#define FUNC_MBIST_MEM_6_LAST_FAILED_ADDR_MASK                                            0x7FF0000
#define FUNC_MBIST_MEM_6_LAST_FAILED_PATTERN_SHIFT                                        28
#define FUNC_MBIST_MEM_6_LAST_FAILED_PATTERN_MASK                                         0x70000000

#define FUNC_MBIST_MEM_7                                                                0x9F4

#define FUNC_MBIST_MEM_7_MAX_ADDR_SHIFT                                                   0
#define FUNC_MBIST_MEM_7_MAX_ADDR_MASK                                                    0x7FF
#define FUNC_MBIST_MEM_7_PATTERN_EN_SHIFT                                                 12
#define FUNC_MBIST_MEM_7_PATTERN_EN_MASK                                                  0x7000
#define FUNC_MBIST_MEM_7_LAST_FAILED_ADDR_SHIFT                                           16
#define FUNC_MBIST_MEM_7_LAST_FAILED_ADDR_MASK                                            0x7FF0000
#define FUNC_MBIST_MEM_7_LAST_FAILED_PATTERN_SHIFT                                        28
#define FUNC_MBIST_MEM_7_LAST_FAILED_PATTERN_MASK                                         0x70000000

#define FUNC_MBIST_MEM_8                                                                0x9F8

#define FUNC_MBIST_MEM_8_MAX_ADDR_SHIFT                                                   0
#define FUNC_MBIST_MEM_8_MAX_ADDR_MASK                                                    0x7FF
#define FUNC_MBIST_MEM_8_PATTERN_EN_SHIFT                                                 12
#define FUNC_MBIST_MEM_8_PATTERN_EN_MASK                                                  0x7000
#define FUNC_MBIST_MEM_8_LAST_FAILED_ADDR_SHIFT                                           16
#define FUNC_MBIST_MEM_8_LAST_FAILED_ADDR_MASK                                            0x7FF0000
#define FUNC_MBIST_MEM_8_LAST_FAILED_PATTERN_SHIFT                                        28
#define FUNC_MBIST_MEM_8_LAST_FAILED_PATTERN_MASK                                         0x70000000

#define FUNC_MBIST_MEM_9                                                                0x9FC

#define FUNC_MBIST_MEM_9_MAX_ADDR_SHIFT                                                   0
#define FUNC_MBIST_MEM_9_MAX_ADDR_MASK                                                    0x7FF
#define FUNC_MBIST_MEM_9_PATTERN_EN_SHIFT                                                 12
#define FUNC_MBIST_MEM_9_PATTERN_EN_MASK                                                  0x7000
#define FUNC_MBIST_MEM_9_LAST_FAILED_ADDR_SHIFT                                           16
#define FUNC_MBIST_MEM_9_LAST_FAILED_ADDR_MASK                                            0x7FF0000
#define FUNC_MBIST_MEM_9_LAST_FAILED_PATTERN_SHIFT                                        28
#define FUNC_MBIST_MEM_9_LAST_FAILED_PATTERN_MASK                                         0x70000000

#define QM_TENSOR_0_BASE_ADDR_LOW                                                       0xA00

#define QM_TENSOR_0_BASE_ADDR_LOW_V_SHIFT                                                 0
#define QM_TENSOR_0_BASE_ADDR_LOW_V_MASK                                                  0xFFFFFFFF

#define QM_TENSOR_0_BASE_ADDR_HIGH                                                      0xA04

#define QM_TENSOR_0_BASE_ADDR_HIGH_V_SHIFT                                                0
#define QM_TENSOR_0_BASE_ADDR_HIGH_V_MASK                                                 0xFFFFFFFF

#define QM_TENSOR_0_PADDING_VALUE                                                       0xA08

#define QM_TENSOR_0_PADDING_VALUE_V_SHIFT                                                 0
#define QM_TENSOR_0_PADDING_VALUE_V_MASK                                                  0xFFFFFFFF

#define QM_TENSOR_0_TENSOR_CONFIG                                                       0xA0C

#define QM_TENSOR_0_TENSOR_CONFIG_DATA_TYPE_SHIFT                                         0
#define QM_TENSOR_0_TENSOR_CONFIG_DATA_TYPE_MASK                                          0x7
#define QM_TENSOR_0_TENSOR_CONFIG_VALID_DIM_MASK_SHIFT                                    8
#define QM_TENSOR_0_TENSOR_CONFIG_VALID_DIM_MASK_MASK                                     0x1F00
#define QM_TENSOR_0_TENSOR_CONFIG_LAST_DIM_SHIFT                                          16
#define QM_TENSOR_0_TENSOR_CONFIG_LAST_DIM_MASK                                           0x70000
#define QM_TENSOR_0_TENSOR_CONFIG_RMW_SET_SHIFT                                           19
#define QM_TENSOR_0_TENSOR_CONFIG_RMW_SET_MASK                                            0x80000
#define QM_TENSOR_0_TENSOR_CONFIG_RMW_RESERV_SHIFT                                        20
#define QM_TENSOR_0_TENSOR_CONFIG_RMW_RESERV_MASK                                         0x100000
#define QM_TENSOR_0_TENSOR_CONFIG_RMW_OP_SHIFT                                            21
#define QM_TENSOR_0_TENSOR_CONFIG_RMW_OP_MASK                                             0x600000

#define QM_TENSOR_0_DIM_0_SIZE                                                          0xA10

#define QM_TENSOR_0_DIM_0_SIZE_V_SHIFT                                                    0
#define QM_TENSOR_0_DIM_0_SIZE_V_MASK                                                     0xFFFFFFFF

#define QM_TENSOR_0_DIM_0_STRIDE                                                        0xA14

#define QM_TENSOR_0_DIM_0_STRIDE_V_SHIFT                                                  0
#define QM_TENSOR_0_DIM_0_STRIDE_V_MASK                                                   0xFFFFFFFF

#define QM_TENSOR_0_DIM_1_SIZE                                                          0xA18

#define QM_TENSOR_0_DIM_1_SIZE_V_SHIFT                                                    0
#define QM_TENSOR_0_DIM_1_SIZE_V_MASK                                                     0xFFFFFFFF

#define QM_TENSOR_0_DIM_1_STRIDE                                                        0xA1C

#define QM_TENSOR_0_DIM_1_STRIDE_V_SHIFT                                                  0
#define QM_TENSOR_0_DIM_1_STRIDE_V_MASK                                                   0xFFFFFFFF

#define QM_TENSOR_0_DIM_2_SIZE                                                          0xA20

#define QM_TENSOR_0_DIM_2_SIZE_V_SHIFT                                                    0
#define QM_TENSOR_0_DIM_2_SIZE_V_MASK                                                     0xFFFFFFFF

#define QM_TENSOR_0_DIM_2_STRIDE                                                        0xA24

#define QM_TENSOR_0_DIM_2_STRIDE_V_SHIFT                                                  0
#define QM_TENSOR_0_DIM_2_STRIDE_V_MASK                                                   0xFFFFFFFF

#define QM_TENSOR_0_DIM_3_SIZE                                                          0xA28

#define QM_TENSOR_0_DIM_3_SIZE_V_SHIFT                                                    0
#define QM_TENSOR_0_DIM_3_SIZE_V_MASK                                                     0xFFFFFFFF

#define QM_TENSOR_0_DIM_3_STRIDE                                                        0xA2C

#define QM_TENSOR_0_DIM_3_STRIDE_V_SHIFT                                                  0
#define QM_TENSOR_0_DIM_3_STRIDE_V_MASK                                                   0xFFFFFFFF

#define QM_TENSOR_0_DIM_4_SIZE                                                          0xA30

#define QM_TENSOR_0_DIM_4_SIZE_V_SHIFT                                                    0
#define QM_TENSOR_0_DIM_4_SIZE_V_MASK                                                     0xFFFFFFFF

#define QM_TENSOR_0_DIM_4_STRIDE                                                        0xA34

#define QM_TENSOR_0_DIM_4_STRIDE_V_SHIFT                                                  0
#define QM_TENSOR_0_DIM_4_STRIDE_V_MASK                                                   0xFFFFFFFF

#define QM_TENSOR_1_BASE_ADDR_LOW                                                       0xA38

#define QM_TENSOR_1_BASE_ADDR_LOW_V_SHIFT                                                 0
#define QM_TENSOR_1_BASE_ADDR_LOW_V_MASK                                                  0xFFFFFFFF

#define QM_TENSOR_1_BASE_ADDR_HIGH                                                      0xA3C

#define QM_TENSOR_1_BASE_ADDR_HIGH_V_SHIFT                                                0
#define QM_TENSOR_1_BASE_ADDR_HIGH_V_MASK                                                 0xFFFFFFFF

#define QM_TENSOR_1_PADDING_VALUE                                                       0xA40

#define QM_TENSOR_1_PADDING_VALUE_V_SHIFT                                                 0
#define QM_TENSOR_1_PADDING_VALUE_V_MASK                                                  0xFFFFFFFF

#define QM_TENSOR_1_TENSOR_CONFIG                                                       0xA44

#define QM_TENSOR_1_TENSOR_CONFIG_DATA_TYPE_SHIFT                                         0
#define QM_TENSOR_1_TENSOR_CONFIG_DATA_TYPE_MASK                                          0x7
#define QM_TENSOR_1_TENSOR_CONFIG_VALID_DIM_MASK_SHIFT                                    8
#define QM_TENSOR_1_TENSOR_CONFIG_VALID_DIM_MASK_MASK                                     0x1F00
#define QM_TENSOR_1_TENSOR_CONFIG_LAST_DIM_SHIFT                                          16
#define QM_TENSOR_1_TENSOR_CONFIG_LAST_DIM_MASK                                           0x70000
#define QM_TENSOR_1_TENSOR_CONFIG_RMW_SET_SHIFT                                           19
#define QM_TENSOR_1_TENSOR_CONFIG_RMW_SET_MASK                                            0x80000
#define QM_TENSOR_1_TENSOR_CONFIG_RMW_RESERV_SHIFT                                        20
#define QM_TENSOR_1_TENSOR_CONFIG_RMW_RESERV_MASK                                         0x100000
#define QM_TENSOR_1_TENSOR_CONFIG_RMW_OP_SHIFT                                            21
#define QM_TENSOR_1_TENSOR_CONFIG_RMW_OP_MASK                                             0x600000

#define QM_TENSOR_1_DIM_0_SIZE                                                          0xA48

#define QM_TENSOR_1_DIM_0_SIZE_V_SHIFT                                                    0
#define QM_TENSOR_1_DIM_0_SIZE_V_MASK                                                     0xFFFFFFFF

#define QM_TENSOR_1_DIM_0_STRIDE                                                        0xA4C

#define QM_TENSOR_1_DIM_0_STRIDE_V_SHIFT                                                  0
#define QM_TENSOR_1_DIM_0_STRIDE_V_MASK                                                   0xFFFFFFFF

#define QM_TENSOR_1_DIM_1_SIZE                                                          0xA50

#define QM_TENSOR_1_DIM_1_SIZE_V_SHIFT                                                    0
#define QM_TENSOR_1_DIM_1_SIZE_V_MASK                                                     0xFFFFFFFF

#define QM_TENSOR_1_DIM_1_STRIDE                                                        0xA54

#define QM_TENSOR_1_DIM_1_STRIDE_V_SHIFT                                                  0
#define QM_TENSOR_1_DIM_1_STRIDE_V_MASK                                                   0xFFFFFFFF

#define QM_TENSOR_1_DIM_2_SIZE                                                          0xA58

#define QM_TENSOR_1_DIM_2_SIZE_V_SHIFT                                                    0
#define QM_TENSOR_1_DIM_2_SIZE_V_MASK                                                     0xFFFFFFFF

#define QM_TENSOR_1_DIM_2_STRIDE                                                        0xA5C

#define QM_TENSOR_1_DIM_2_STRIDE_V_SHIFT                                                  0
#define QM_TENSOR_1_DIM_2_STRIDE_V_MASK                                                   0xFFFFFFFF

#define QM_TENSOR_1_DIM_3_SIZE                                                          0xA60

#define QM_TENSOR_1_DIM_3_SIZE_V_SHIFT                                                    0
#define QM_TENSOR_1_DIM_3_SIZE_V_MASK                                                     0xFFFFFFFF

#define QM_TENSOR_1_DIM_3_STRIDE                                                        0xA64

#define QM_TENSOR_1_DIM_3_STRIDE_V_SHIFT                                                  0
#define QM_TENSOR_1_DIM_3_STRIDE_V_MASK                                                   0xFFFFFFFF

#define QM_TENSOR_1_DIM_4_SIZE                                                          0xA68

#define QM_TENSOR_1_DIM_4_SIZE_V_SHIFT                                                    0
#define QM_TENSOR_1_DIM_4_SIZE_V_MASK                                                     0xFFFFFFFF

#define QM_TENSOR_1_DIM_4_STRIDE                                                        0xA6C

#define QM_TENSOR_1_DIM_4_STRIDE_V_SHIFT                                                  0
#define QM_TENSOR_1_DIM_4_STRIDE_V_MASK                                                   0xFFFFFFFF

#define QM_TENSOR_2_BASE_ADDR_LOW                                                       0xA70

#define QM_TENSOR_2_BASE_ADDR_LOW_V_SHIFT                                                 0
#define QM_TENSOR_2_BASE_ADDR_LOW_V_MASK                                                  0xFFFFFFFF

#define QM_TENSOR_2_BASE_ADDR_HIGH                                                      0xA74

#define QM_TENSOR_2_BASE_ADDR_HIGH_V_SHIFT                                                0
#define QM_TENSOR_2_BASE_ADDR_HIGH_V_MASK                                                 0xFFFFFFFF

#define QM_TENSOR_2_PADDING_VALUE                                                       0xA78

#define QM_TENSOR_2_PADDING_VALUE_V_SHIFT                                                 0
#define QM_TENSOR_2_PADDING_VALUE_V_MASK                                                  0xFFFFFFFF

#define QM_TENSOR_2_TENSOR_CONFIG                                                       0xA7C

#define QM_TENSOR_2_TENSOR_CONFIG_DATA_TYPE_SHIFT                                         0
#define QM_TENSOR_2_TENSOR_CONFIG_DATA_TYPE_MASK                                          0x7
#define QM_TENSOR_2_TENSOR_CONFIG_VALID_DIM_MASK_SHIFT                                    8
#define QM_TENSOR_2_TENSOR_CONFIG_VALID_DIM_MASK_MASK                                     0x1F00
#define QM_TENSOR_2_TENSOR_CONFIG_LAST_DIM_SHIFT                                          16
#define QM_TENSOR_2_TENSOR_CONFIG_LAST_DIM_MASK                                           0x70000
#define QM_TENSOR_2_TENSOR_CONFIG_RMW_SET_SHIFT                                           19
#define QM_TENSOR_2_TENSOR_CONFIG_RMW_SET_MASK                                            0x80000
#define QM_TENSOR_2_TENSOR_CONFIG_RMW_RESERV_SHIFT                                        20
#define QM_TENSOR_2_TENSOR_CONFIG_RMW_RESERV_MASK                                         0x100000
#define QM_TENSOR_2_TENSOR_CONFIG_RMW_OP_SHIFT                                            21
#define QM_TENSOR_2_TENSOR_CONFIG_RMW_OP_MASK                                             0x600000

#define QM_TENSOR_2_DIM_0_SIZE                                                          0xA80

#define QM_TENSOR_2_DIM_0_SIZE_V_SHIFT                                                    0
#define QM_TENSOR_2_DIM_0_SIZE_V_MASK                                                     0xFFFFFFFF

#define QM_TENSOR_2_DIM_0_STRIDE                                                        0xA84

#define QM_TENSOR_2_DIM_0_STRIDE_V_SHIFT                                                  0
#define QM_TENSOR_2_DIM_0_STRIDE_V_MASK                                                   0xFFFFFFFF

#define QM_TENSOR_2_DIM_1_SIZE                                                          0xA88

#define QM_TENSOR_2_DIM_1_SIZE_V_SHIFT                                                    0
#define QM_TENSOR_2_DIM_1_SIZE_V_MASK                                                     0xFFFFFFFF

#define QM_TENSOR_2_DIM_1_STRIDE                                                        0xA8C

#define QM_TENSOR_2_DIM_1_STRIDE_V_SHIFT                                                  0
#define QM_TENSOR_2_DIM_1_STRIDE_V_MASK                                                   0xFFFFFFFF

#define QM_TENSOR_2_DIM_2_SIZE                                                          0xA90

#define QM_TENSOR_2_DIM_2_SIZE_V_SHIFT                                                    0
#define QM_TENSOR_2_DIM_2_SIZE_V_MASK                                                     0xFFFFFFFF

#define QM_TENSOR_2_DIM_2_STRIDE                                                        0xA94

#define QM_TENSOR_2_DIM_2_STRIDE_V_SHIFT                                                  0
#define QM_TENSOR_2_DIM_2_STRIDE_V_MASK                                                   0xFFFFFFFF

#define QM_TENSOR_2_DIM_3_SIZE                                                          0xA98

#define QM_TENSOR_2_DIM_3_SIZE_V_SHIFT                                                    0
#define QM_TENSOR_2_DIM_3_SIZE_V_MASK                                                     0xFFFFFFFF

#define QM_TENSOR_2_DIM_3_STRIDE                                                        0xA9C

#define QM_TENSOR_2_DIM_3_STRIDE_V_SHIFT                                                  0
#define QM_TENSOR_2_DIM_3_STRIDE_V_MASK                                                   0xFFFFFFFF

#define QM_TENSOR_2_DIM_4_SIZE                                                          0xAA0

#define QM_TENSOR_2_DIM_4_SIZE_V_SHIFT                                                    0
#define QM_TENSOR_2_DIM_4_SIZE_V_MASK                                                     0xFFFFFFFF

#define QM_TENSOR_2_DIM_4_STRIDE                                                        0xAA4

#define QM_TENSOR_2_DIM_4_STRIDE_V_SHIFT                                                  0
#define QM_TENSOR_2_DIM_4_STRIDE_V_MASK                                                   0xFFFFFFFF

#define QM_TENSOR_3_BASE_ADDR_LOW                                                       0xAA8

#define QM_TENSOR_3_BASE_ADDR_LOW_V_SHIFT                                                 0
#define QM_TENSOR_3_BASE_ADDR_LOW_V_MASK                                                  0xFFFFFFFF

#define QM_TENSOR_3_BASE_ADDR_HIGH                                                      0xAAC

#define QM_TENSOR_3_BASE_ADDR_HIGH_V_SHIFT                                                0
#define QM_TENSOR_3_BASE_ADDR_HIGH_V_MASK                                                 0xFFFFFFFF

#define QM_TENSOR_3_PADDING_VALUE                                                       0xAB0

#define QM_TENSOR_3_PADDING_VALUE_V_SHIFT                                                 0
#define QM_TENSOR_3_PADDING_VALUE_V_MASK                                                  0xFFFFFFFF

#define QM_TENSOR_3_TENSOR_CONFIG                                                       0xAB4

#define QM_TENSOR_3_TENSOR_CONFIG_DATA_TYPE_SHIFT                                         0
#define QM_TENSOR_3_TENSOR_CONFIG_DATA_TYPE_MASK                                          0x7
#define QM_TENSOR_3_TENSOR_CONFIG_VALID_DIM_MASK_SHIFT                                    8
#define QM_TENSOR_3_TENSOR_CONFIG_VALID_DIM_MASK_MASK                                     0x1F00
#define QM_TENSOR_3_TENSOR_CONFIG_LAST_DIM_SHIFT                                          16
#define QM_TENSOR_3_TENSOR_CONFIG_LAST_DIM_MASK                                           0x70000
#define QM_TENSOR_3_TENSOR_CONFIG_RMW_SET_SHIFT                                           19
#define QM_TENSOR_3_TENSOR_CONFIG_RMW_SET_MASK                                            0x80000
#define QM_TENSOR_3_TENSOR_CONFIG_RMW_RESERV_SHIFT                                        20
#define QM_TENSOR_3_TENSOR_CONFIG_RMW_RESERV_MASK                                         0x100000
#define QM_TENSOR_3_TENSOR_CONFIG_RMW_OP_SHIFT                                            21
#define QM_TENSOR_3_TENSOR_CONFIG_RMW_OP_MASK                                             0x600000

#define QM_TENSOR_3_DIM_0_SIZE                                                          0xAB8

#define QM_TENSOR_3_DIM_0_SIZE_V_SHIFT                                                    0
#define QM_TENSOR_3_DIM_0_SIZE_V_MASK                                                     0xFFFFFFFF

#define QM_TENSOR_3_DIM_0_STRIDE                                                        0xABC

#define QM_TENSOR_3_DIM_0_STRIDE_V_SHIFT                                                  0
#define QM_TENSOR_3_DIM_0_STRIDE_V_MASK                                                   0xFFFFFFFF

#define QM_TENSOR_3_DIM_1_SIZE                                                          0xAC0

#define QM_TENSOR_3_DIM_1_SIZE_V_SHIFT                                                    0
#define QM_TENSOR_3_DIM_1_SIZE_V_MASK                                                     0xFFFFFFFF

#define QM_TENSOR_3_DIM_1_STRIDE                                                        0xAC4

#define QM_TENSOR_3_DIM_1_STRIDE_V_SHIFT                                                  0
#define QM_TENSOR_3_DIM_1_STRIDE_V_MASK                                                   0xFFFFFFFF

#define QM_TENSOR_3_DIM_2_SIZE                                                          0xAC8

#define QM_TENSOR_3_DIM_2_SIZE_V_SHIFT                                                    0
#define QM_TENSOR_3_DIM_2_SIZE_V_MASK                                                     0xFFFFFFFF

#define QM_TENSOR_3_DIM_2_STRIDE                                                        0xACC

#define QM_TENSOR_3_DIM_2_STRIDE_V_SHIFT                                                  0
#define QM_TENSOR_3_DIM_2_STRIDE_V_MASK                                                   0xFFFFFFFF

#define QM_TENSOR_3_DIM_3_SIZE                                                          0xAD0

#define QM_TENSOR_3_DIM_3_SIZE_V_SHIFT                                                    0
#define QM_TENSOR_3_DIM_3_SIZE_V_MASK                                                     0xFFFFFFFF

#define QM_TENSOR_3_DIM_3_STRIDE                                                        0xAD4

#define QM_TENSOR_3_DIM_3_STRIDE_V_SHIFT                                                  0
#define QM_TENSOR_3_DIM_3_STRIDE_V_MASK                                                   0xFFFFFFFF

#define QM_TENSOR_3_DIM_4_SIZE                                                          0xAD8

#define QM_TENSOR_3_DIM_4_SIZE_V_SHIFT                                                    0
#define QM_TENSOR_3_DIM_4_SIZE_V_MASK                                                     0xFFFFFFFF

#define QM_TENSOR_3_DIM_4_STRIDE                                                        0xADC

#define QM_TENSOR_3_DIM_4_STRIDE_V_SHIFT                                                  0
#define QM_TENSOR_3_DIM_4_STRIDE_V_MASK                                                   0xFFFFFFFF

#define QM_TENSOR_4_BASE_ADDR_LOW                                                       0xAE0

#define QM_TENSOR_4_BASE_ADDR_LOW_V_SHIFT                                                 0
#define QM_TENSOR_4_BASE_ADDR_LOW_V_MASK                                                  0xFFFFFFFF

#define QM_TENSOR_4_BASE_ADDR_HIGH                                                      0xAE4

#define QM_TENSOR_4_BASE_ADDR_HIGH_V_SHIFT                                                0
#define QM_TENSOR_4_BASE_ADDR_HIGH_V_MASK                                                 0xFFFFFFFF

#define QM_TENSOR_4_PADDING_VALUE                                                       0xAE8

#define QM_TENSOR_4_PADDING_VALUE_V_SHIFT                                                 0
#define QM_TENSOR_4_PADDING_VALUE_V_MASK                                                  0xFFFFFFFF

#define QM_TENSOR_4_TENSOR_CONFIG                                                       0xAEC

#define QM_TENSOR_4_TENSOR_CONFIG_DATA_TYPE_SHIFT                                         0
#define QM_TENSOR_4_TENSOR_CONFIG_DATA_TYPE_MASK                                          0x7
#define QM_TENSOR_4_TENSOR_CONFIG_VALID_DIM_MASK_SHIFT                                    8
#define QM_TENSOR_4_TENSOR_CONFIG_VALID_DIM_MASK_MASK                                     0x1F00
#define QM_TENSOR_4_TENSOR_CONFIG_LAST_DIM_SHIFT                                          16
#define QM_TENSOR_4_TENSOR_CONFIG_LAST_DIM_MASK                                           0x70000
#define QM_TENSOR_4_TENSOR_CONFIG_RMW_SET_SHIFT                                           19
#define QM_TENSOR_4_TENSOR_CONFIG_RMW_SET_MASK                                            0x80000
#define QM_TENSOR_4_TENSOR_CONFIG_RMW_RESERV_SHIFT                                        20
#define QM_TENSOR_4_TENSOR_CONFIG_RMW_RESERV_MASK                                         0x100000
#define QM_TENSOR_4_TENSOR_CONFIG_RMW_OP_SHIFT                                            21
#define QM_TENSOR_4_TENSOR_CONFIG_RMW_OP_MASK                                             0x600000

#define QM_TENSOR_4_DIM_0_SIZE                                                          0xAF0

#define QM_TENSOR_4_DIM_0_SIZE_V_SHIFT                                                    0
#define QM_TENSOR_4_DIM_0_SIZE_V_MASK                                                     0xFFFFFFFF

#define QM_TENSOR_4_DIM_0_STRIDE                                                        0xAF4

#define QM_TENSOR_4_DIM_0_STRIDE_V_SHIFT                                                  0
#define QM_TENSOR_4_DIM_0_STRIDE_V_MASK                                                   0xFFFFFFFF

#define QM_TENSOR_4_DIM_1_SIZE                                                          0xAF8

#define QM_TENSOR_4_DIM_1_SIZE_V_SHIFT                                                    0
#define QM_TENSOR_4_DIM_1_SIZE_V_MASK                                                     0xFFFFFFFF

#define QM_TENSOR_4_DIM_1_STRIDE                                                        0xAFC

#define QM_TENSOR_4_DIM_1_STRIDE_V_SHIFT                                                  0
#define QM_TENSOR_4_DIM_1_STRIDE_V_MASK                                                   0xFFFFFFFF

#define QM_TENSOR_4_DIM_2_SIZE                                                          0xB00

#define QM_TENSOR_4_DIM_2_SIZE_V_SHIFT                                                    0
#define QM_TENSOR_4_DIM_2_SIZE_V_MASK                                                     0xFFFFFFFF

#define QM_TENSOR_4_DIM_2_STRIDE                                                        0xB04

#define QM_TENSOR_4_DIM_2_STRIDE_V_SHIFT                                                  0
#define QM_TENSOR_4_DIM_2_STRIDE_V_MASK                                                   0xFFFFFFFF

#define QM_TENSOR_4_DIM_3_SIZE                                                          0xB08

#define QM_TENSOR_4_DIM_3_SIZE_V_SHIFT                                                    0
#define QM_TENSOR_4_DIM_3_SIZE_V_MASK                                                     0xFFFFFFFF

#define QM_TENSOR_4_DIM_3_STRIDE                                                        0xB0C

#define QM_TENSOR_4_DIM_3_STRIDE_V_SHIFT                                                  0
#define QM_TENSOR_4_DIM_3_STRIDE_V_MASK                                                   0xFFFFFFFF

#define QM_TENSOR_4_DIM_4_SIZE                                                          0xB10

#define QM_TENSOR_4_DIM_4_SIZE_V_SHIFT                                                    0
#define QM_TENSOR_4_DIM_4_SIZE_V_MASK                                                     0xFFFFFFFF

#define QM_TENSOR_4_DIM_4_STRIDE                                                        0xB14

#define QM_TENSOR_4_DIM_4_STRIDE_V_SHIFT                                                  0
#define QM_TENSOR_4_DIM_4_STRIDE_V_MASK                                                   0xFFFFFFFF

#define QM_TENSOR_5_BASE_ADDR_LOW                                                       0xB18

#define QM_TENSOR_5_BASE_ADDR_LOW_V_SHIFT                                                 0
#define QM_TENSOR_5_BASE_ADDR_LOW_V_MASK                                                  0xFFFFFFFF

#define QM_TENSOR_5_BASE_ADDR_HIGH                                                      0xB1C

#define QM_TENSOR_5_BASE_ADDR_HIGH_V_SHIFT                                                0
#define QM_TENSOR_5_BASE_ADDR_HIGH_V_MASK                                                 0xFFFFFFFF

#define QM_TENSOR_5_PADDING_VALUE                                                       0xB20

#define QM_TENSOR_5_PADDING_VALUE_V_SHIFT                                                 0
#define QM_TENSOR_5_PADDING_VALUE_V_MASK                                                  0xFFFFFFFF

#define QM_TENSOR_5_TENSOR_CONFIG                                                       0xB24

#define QM_TENSOR_5_TENSOR_CONFIG_DATA_TYPE_SHIFT                                         0
#define QM_TENSOR_5_TENSOR_CONFIG_DATA_TYPE_MASK                                          0x7
#define QM_TENSOR_5_TENSOR_CONFIG_VALID_DIM_MASK_SHIFT                                    8
#define QM_TENSOR_5_TENSOR_CONFIG_VALID_DIM_MASK_MASK                                     0x1F00
#define QM_TENSOR_5_TENSOR_CONFIG_LAST_DIM_SHIFT                                          16
#define QM_TENSOR_5_TENSOR_CONFIG_LAST_DIM_MASK                                           0x70000
#define QM_TENSOR_5_TENSOR_CONFIG_RMW_SET_SHIFT                                           19
#define QM_TENSOR_5_TENSOR_CONFIG_RMW_SET_MASK                                            0x80000
#define QM_TENSOR_5_TENSOR_CONFIG_RMW_RESERV_SHIFT                                        20
#define QM_TENSOR_5_TENSOR_CONFIG_RMW_RESERV_MASK                                         0x100000
#define QM_TENSOR_5_TENSOR_CONFIG_RMW_OP_SHIFT                                            21
#define QM_TENSOR_5_TENSOR_CONFIG_RMW_OP_MASK                                             0x600000

#define QM_TENSOR_5_DIM_0_SIZE                                                          0xB28

#define QM_TENSOR_5_DIM_0_SIZE_V_SHIFT                                                    0
#define QM_TENSOR_5_DIM_0_SIZE_V_MASK                                                     0xFFFFFFFF

#define QM_TENSOR_5_DIM_0_STRIDE                                                        0xB2C

#define QM_TENSOR_5_DIM_0_STRIDE_V_SHIFT                                                  0
#define QM_TENSOR_5_DIM_0_STRIDE_V_MASK                                                   0xFFFFFFFF

#define QM_TENSOR_5_DIM_1_SIZE                                                          0xB30

#define QM_TENSOR_5_DIM_1_SIZE_V_SHIFT                                                    0
#define QM_TENSOR_5_DIM_1_SIZE_V_MASK                                                     0xFFFFFFFF

#define QM_TENSOR_5_DIM_1_STRIDE                                                        0xB34

#define QM_TENSOR_5_DIM_1_STRIDE_V_SHIFT                                                  0
#define QM_TENSOR_5_DIM_1_STRIDE_V_MASK                                                   0xFFFFFFFF

#define QM_TENSOR_5_DIM_2_SIZE                                                          0xB38

#define QM_TENSOR_5_DIM_2_SIZE_V_SHIFT                                                    0
#define QM_TENSOR_5_DIM_2_SIZE_V_MASK                                                     0xFFFFFFFF

#define QM_TENSOR_5_DIM_2_STRIDE                                                        0xB3C

#define QM_TENSOR_5_DIM_2_STRIDE_V_SHIFT                                                  0
#define QM_TENSOR_5_DIM_2_STRIDE_V_MASK                                                   0xFFFFFFFF

#define QM_TENSOR_5_DIM_3_SIZE                                                          0xB40

#define QM_TENSOR_5_DIM_3_SIZE_V_SHIFT                                                    0
#define QM_TENSOR_5_DIM_3_SIZE_V_MASK                                                     0xFFFFFFFF

#define QM_TENSOR_5_DIM_3_STRIDE                                                        0xB44

#define QM_TENSOR_5_DIM_3_STRIDE_V_SHIFT                                                  0
#define QM_TENSOR_5_DIM_3_STRIDE_V_MASK                                                   0xFFFFFFFF

#define QM_TENSOR_5_DIM_4_SIZE                                                          0xB48

#define QM_TENSOR_5_DIM_4_SIZE_V_SHIFT                                                    0
#define QM_TENSOR_5_DIM_4_SIZE_V_MASK                                                     0xFFFFFFFF

#define QM_TENSOR_5_DIM_4_STRIDE                                                        0xB4C

#define QM_TENSOR_5_DIM_4_STRIDE_V_SHIFT                                                  0
#define QM_TENSOR_5_DIM_4_STRIDE_V_MASK                                                   0xFFFFFFFF

#define QM_TENSOR_6_BASE_ADDR_LOW                                                       0xB50

#define QM_TENSOR_6_BASE_ADDR_LOW_V_SHIFT                                                 0
#define QM_TENSOR_6_BASE_ADDR_LOW_V_MASK                                                  0xFFFFFFFF

#define QM_TENSOR_6_BASE_ADDR_HIGH                                                      0xB54

#define QM_TENSOR_6_BASE_ADDR_HIGH_V_SHIFT                                                0
#define QM_TENSOR_6_BASE_ADDR_HIGH_V_MASK                                                 0xFFFFFFFF

#define QM_TENSOR_6_PADDING_VALUE                                                       0xB58

#define QM_TENSOR_6_PADDING_VALUE_V_SHIFT                                                 0
#define QM_TENSOR_6_PADDING_VALUE_V_MASK                                                  0xFFFFFFFF

#define QM_TENSOR_6_TENSOR_CONFIG                                                       0xB5C

#define QM_TENSOR_6_TENSOR_CONFIG_DATA_TYPE_SHIFT                                         0
#define QM_TENSOR_6_TENSOR_CONFIG_DATA_TYPE_MASK                                          0x7
#define QM_TENSOR_6_TENSOR_CONFIG_VALID_DIM_MASK_SHIFT                                    8
#define QM_TENSOR_6_TENSOR_CONFIG_VALID_DIM_MASK_MASK                                     0x1F00
#define QM_TENSOR_6_TENSOR_CONFIG_LAST_DIM_SHIFT                                          16
#define QM_TENSOR_6_TENSOR_CONFIG_LAST_DIM_MASK                                           0x70000
#define QM_TENSOR_6_TENSOR_CONFIG_RMW_SET_SHIFT                                           19
#define QM_TENSOR_6_TENSOR_CONFIG_RMW_SET_MASK                                            0x80000
#define QM_TENSOR_6_TENSOR_CONFIG_RMW_RESERV_SHIFT                                        20
#define QM_TENSOR_6_TENSOR_CONFIG_RMW_RESERV_MASK                                         0x100000
#define QM_TENSOR_6_TENSOR_CONFIG_RMW_OP_SHIFT                                            21
#define QM_TENSOR_6_TENSOR_CONFIG_RMW_OP_MASK                                             0x600000

#define QM_TENSOR_6_DIM_0_SIZE                                                          0xB60

#define QM_TENSOR_6_DIM_0_SIZE_V_SHIFT                                                    0
#define QM_TENSOR_6_DIM_0_SIZE_V_MASK                                                     0xFFFFFFFF

#define QM_TENSOR_6_DIM_0_STRIDE                                                        0xB64

#define QM_TENSOR_6_DIM_0_STRIDE_V_SHIFT                                                  0
#define QM_TENSOR_6_DIM_0_STRIDE_V_MASK                                                   0xFFFFFFFF

#define QM_TENSOR_6_DIM_1_SIZE                                                          0xB68

#define QM_TENSOR_6_DIM_1_SIZE_V_SHIFT                                                    0
#define QM_TENSOR_6_DIM_1_SIZE_V_MASK                                                     0xFFFFFFFF

#define QM_TENSOR_6_DIM_1_STRIDE                                                        0xB6C

#define QM_TENSOR_6_DIM_1_STRIDE_V_SHIFT                                                  0
#define QM_TENSOR_6_DIM_1_STRIDE_V_MASK                                                   0xFFFFFFFF

#define QM_TENSOR_6_DIM_2_SIZE                                                          0xB70

#define QM_TENSOR_6_DIM_2_SIZE_V_SHIFT                                                    0
#define QM_TENSOR_6_DIM_2_SIZE_V_MASK                                                     0xFFFFFFFF

#define QM_TENSOR_6_DIM_2_STRIDE                                                        0xB74

#define QM_TENSOR_6_DIM_2_STRIDE_V_SHIFT                                                  0
#define QM_TENSOR_6_DIM_2_STRIDE_V_MASK                                                   0xFFFFFFFF

#define QM_TENSOR_6_DIM_3_SIZE                                                          0xB78

#define QM_TENSOR_6_DIM_3_SIZE_V_SHIFT                                                    0
#define QM_TENSOR_6_DIM_3_SIZE_V_MASK                                                     0xFFFFFFFF

#define QM_TENSOR_6_DIM_3_STRIDE                                                        0xB7C

#define QM_TENSOR_6_DIM_3_STRIDE_V_SHIFT                                                  0
#define QM_TENSOR_6_DIM_3_STRIDE_V_MASK                                                   0xFFFFFFFF

#define QM_TENSOR_6_DIM_4_SIZE                                                          0xB80

#define QM_TENSOR_6_DIM_4_SIZE_V_SHIFT                                                    0
#define QM_TENSOR_6_DIM_4_SIZE_V_MASK                                                     0xFFFFFFFF

#define QM_TENSOR_6_DIM_4_STRIDE                                                        0xB84

#define QM_TENSOR_6_DIM_4_STRIDE_V_SHIFT                                                  0
#define QM_TENSOR_6_DIM_4_STRIDE_V_MASK                                                   0xFFFFFFFF

#define QM_TENSOR_7_BASE_ADDR_LOW                                                       0xB88

#define QM_TENSOR_7_BASE_ADDR_LOW_V_SHIFT                                                 0
#define QM_TENSOR_7_BASE_ADDR_LOW_V_MASK                                                  0xFFFFFFFF

#define QM_TENSOR_7_BASE_ADDR_HIGH                                                      0xB8C

#define QM_TENSOR_7_BASE_ADDR_HIGH_V_SHIFT                                                0
#define QM_TENSOR_7_BASE_ADDR_HIGH_V_MASK                                                 0xFFFFFFFF

#define QM_TENSOR_7_PADDING_VALUE                                                       0xB90

#define QM_TENSOR_7_PADDING_VALUE_V_SHIFT                                                 0
#define QM_TENSOR_7_PADDING_VALUE_V_MASK                                                  0xFFFFFFFF

#define QM_TENSOR_7_TENSOR_CONFIG                                                       0xB94

#define QM_TENSOR_7_TENSOR_CONFIG_DATA_TYPE_SHIFT                                         0
#define QM_TENSOR_7_TENSOR_CONFIG_DATA_TYPE_MASK                                          0x7
#define QM_TENSOR_7_TENSOR_CONFIG_VALID_DIM_MASK_SHIFT                                    8
#define QM_TENSOR_7_TENSOR_CONFIG_VALID_DIM_MASK_MASK                                     0x1F00
#define QM_TENSOR_7_TENSOR_CONFIG_LAST_DIM_SHIFT                                          16
#define QM_TENSOR_7_TENSOR_CONFIG_LAST_DIM_MASK                                           0x70000
#define QM_TENSOR_7_TENSOR_CONFIG_RMW_SET_SHIFT                                           19
#define QM_TENSOR_7_TENSOR_CONFIG_RMW_SET_MASK                                            0x80000
#define QM_TENSOR_7_TENSOR_CONFIG_RMW_RESERV_SHIFT                                        20
#define QM_TENSOR_7_TENSOR_CONFIG_RMW_RESERV_MASK                                         0x100000
#define QM_TENSOR_7_TENSOR_CONFIG_RMW_OP_SHIFT                                            21
#define QM_TENSOR_7_TENSOR_CONFIG_RMW_OP_MASK                                             0x600000

#define QM_TENSOR_7_DIM_0_SIZE                                                          0xB98

#define QM_TENSOR_7_DIM_0_SIZE_V_SHIFT                                                    0
#define QM_TENSOR_7_DIM_0_SIZE_V_MASK                                                     0xFFFFFFFF

#define QM_TENSOR_7_DIM_0_STRIDE                                                        0xB9C

#define QM_TENSOR_7_DIM_0_STRIDE_V_SHIFT                                                  0
#define QM_TENSOR_7_DIM_0_STRIDE_V_MASK                                                   0xFFFFFFFF

#define QM_TENSOR_7_DIM_1_SIZE                                                          0xBA0

#define QM_TENSOR_7_DIM_1_SIZE_V_SHIFT                                                    0
#define QM_TENSOR_7_DIM_1_SIZE_V_MASK                                                     0xFFFFFFFF

#define QM_TENSOR_7_DIM_1_STRIDE                                                        0xBA4

#define QM_TENSOR_7_DIM_1_STRIDE_V_SHIFT                                                  0
#define QM_TENSOR_7_DIM_1_STRIDE_V_MASK                                                   0xFFFFFFFF

#define QM_TENSOR_7_DIM_2_SIZE                                                          0xBA8

#define QM_TENSOR_7_DIM_2_SIZE_V_SHIFT                                                    0
#define QM_TENSOR_7_DIM_2_SIZE_V_MASK                                                     0xFFFFFFFF

#define QM_TENSOR_7_DIM_2_STRIDE                                                        0xBAC

#define QM_TENSOR_7_DIM_2_STRIDE_V_SHIFT                                                  0
#define QM_TENSOR_7_DIM_2_STRIDE_V_MASK                                                   0xFFFFFFFF

#define QM_TENSOR_7_DIM_3_SIZE                                                          0xBB0

#define QM_TENSOR_7_DIM_3_SIZE_V_SHIFT                                                    0
#define QM_TENSOR_7_DIM_3_SIZE_V_MASK                                                     0xFFFFFFFF

#define QM_TENSOR_7_DIM_3_STRIDE                                                        0xBB4

#define QM_TENSOR_7_DIM_3_STRIDE_V_SHIFT                                                  0
#define QM_TENSOR_7_DIM_3_STRIDE_V_MASK                                                   0xFFFFFFFF

#define QM_TENSOR_7_DIM_4_SIZE                                                          0xBB8

#define QM_TENSOR_7_DIM_4_SIZE_V_SHIFT                                                    0
#define QM_TENSOR_7_DIM_4_SIZE_V_MASK                                                     0xFFFFFFFF

#define QM_TENSOR_7_DIM_4_STRIDE                                                        0xBBC

#define QM_TENSOR_7_DIM_4_STRIDE_V_SHIFT                                                  0
#define QM_TENSOR_7_DIM_4_STRIDE_V_MASK                                                   0xFFFFFFFF

#define QM_TENSOR_8_BASE_ADDR_LOW                                                       0xBC0

#define QM_TENSOR_8_BASE_ADDR_LOW_V_SHIFT                                                 0
#define QM_TENSOR_8_BASE_ADDR_LOW_V_MASK                                                  0xFFFFFFFF

#define QM_TENSOR_8_BASE_ADDR_HIGH                                                      0xBC4

#define QM_TENSOR_8_BASE_ADDR_HIGH_V_SHIFT                                                0
#define QM_TENSOR_8_BASE_ADDR_HIGH_V_MASK                                                 0xFFFFFFFF

#define QM_TENSOR_8_PADDING_VALUE                                                       0xBC8

#define QM_TENSOR_8_PADDING_VALUE_V_SHIFT                                                 0
#define QM_TENSOR_8_PADDING_VALUE_V_MASK                                                  0xFFFFFFFF

#define QM_TENSOR_8_TENSOR_CONFIG                                                       0xBCC

#define QM_TENSOR_8_TENSOR_CONFIG_DATA_TYPE_SHIFT                                         0
#define QM_TENSOR_8_TENSOR_CONFIG_DATA_TYPE_MASK                                          0x7
#define QM_TENSOR_8_TENSOR_CONFIG_VALID_DIM_MASK_SHIFT                                    8
#define QM_TENSOR_8_TENSOR_CONFIG_VALID_DIM_MASK_MASK                                     0x1F00
#define QM_TENSOR_8_TENSOR_CONFIG_LAST_DIM_SHIFT                                          16
#define QM_TENSOR_8_TENSOR_CONFIG_LAST_DIM_MASK                                           0x70000
#define QM_TENSOR_8_TENSOR_CONFIG_RMW_SET_SHIFT                                           19
#define QM_TENSOR_8_TENSOR_CONFIG_RMW_SET_MASK                                            0x80000
#define QM_TENSOR_8_TENSOR_CONFIG_RMW_RESERV_SHIFT                                        20
#define QM_TENSOR_8_TENSOR_CONFIG_RMW_RESERV_MASK                                         0x100000
#define QM_TENSOR_8_TENSOR_CONFIG_RMW_OP_SHIFT                                            21
#define QM_TENSOR_8_TENSOR_CONFIG_RMW_OP_MASK                                             0x600000

#define QM_TENSOR_8_DIM_0_SIZE                                                          0xBD0

#define QM_TENSOR_8_DIM_0_SIZE_V_SHIFT                                                    0
#define QM_TENSOR_8_DIM_0_SIZE_V_MASK                                                     0xFFFFFFFF

#define QM_TENSOR_8_DIM_0_STRIDE                                                        0xBD4

#define QM_TENSOR_8_DIM_0_STRIDE_V_SHIFT                                                  0
#define QM_TENSOR_8_DIM_0_STRIDE_V_MASK                                                   0xFFFFFFFF

#define QM_TENSOR_8_DIM_1_SIZE                                                          0xBD8

#define QM_TENSOR_8_DIM_1_SIZE_V_SHIFT                                                    0
#define QM_TENSOR_8_DIM_1_SIZE_V_MASK                                                     0xFFFFFFFF

#define QM_TENSOR_8_DIM_1_STRIDE                                                        0xBDC

#define QM_TENSOR_8_DIM_1_STRIDE_V_SHIFT                                                  0
#define QM_TENSOR_8_DIM_1_STRIDE_V_MASK                                                   0xFFFFFFFF

#define QM_TENSOR_8_DIM_2_SIZE                                                          0xBE0

#define QM_TENSOR_8_DIM_2_SIZE_V_SHIFT                                                    0
#define QM_TENSOR_8_DIM_2_SIZE_V_MASK                                                     0xFFFFFFFF

#define QM_TENSOR_8_DIM_2_STRIDE                                                        0xBE4

#define QM_TENSOR_8_DIM_2_STRIDE_V_SHIFT                                                  0
#define QM_TENSOR_8_DIM_2_STRIDE_V_MASK                                                   0xFFFFFFFF

#define QM_TENSOR_8_DIM_3_SIZE                                                          0xBE8

#define QM_TENSOR_8_DIM_3_SIZE_V_SHIFT                                                    0
#define QM_TENSOR_8_DIM_3_SIZE_V_MASK                                                     0xFFFFFFFF

#define QM_TENSOR_8_DIM_3_STRIDE                                                        0xBEC

#define QM_TENSOR_8_DIM_3_STRIDE_V_SHIFT                                                  0
#define QM_TENSOR_8_DIM_3_STRIDE_V_MASK                                                   0xFFFFFFFF

#define QM_TENSOR_8_DIM_4_SIZE                                                          0xBF0

#define QM_TENSOR_8_DIM_4_SIZE_V_SHIFT                                                    0
#define QM_TENSOR_8_DIM_4_SIZE_V_MASK                                                     0xFFFFFFFF

#define QM_TENSOR_8_DIM_4_STRIDE                                                        0xBF4

#define QM_TENSOR_8_DIM_4_STRIDE_V_SHIFT                                                  0
#define QM_TENSOR_8_DIM_4_STRIDE_V_MASK                                                   0xFFFFFFFF

#define QM_TENSOR_9_BASE_ADDR_LOW                                                       0xBF8

#define QM_TENSOR_9_BASE_ADDR_LOW_V_SHIFT                                                 0
#define QM_TENSOR_9_BASE_ADDR_LOW_V_MASK                                                  0xFFFFFFFF

#define QM_TENSOR_9_BASE_ADDR_HIGH                                                      0xBFC

#define QM_TENSOR_9_BASE_ADDR_HIGH_V_SHIFT                                                0
#define QM_TENSOR_9_BASE_ADDR_HIGH_V_MASK                                                 0xFFFFFFFF

#define QM_TENSOR_9_PADDING_VALUE                                                       0xC00

#define QM_TENSOR_9_PADDING_VALUE_V_SHIFT                                                 0
#define QM_TENSOR_9_PADDING_VALUE_V_MASK                                                  0xFFFFFFFF

#define QM_TENSOR_9_TENSOR_CONFIG                                                       0xC04

#define QM_TENSOR_9_TENSOR_CONFIG_DATA_TYPE_SHIFT                                         0
#define QM_TENSOR_9_TENSOR_CONFIG_DATA_TYPE_MASK                                          0x7
#define QM_TENSOR_9_TENSOR_CONFIG_VALID_DIM_MASK_SHIFT                                    8
#define QM_TENSOR_9_TENSOR_CONFIG_VALID_DIM_MASK_MASK                                     0x1F00
#define QM_TENSOR_9_TENSOR_CONFIG_LAST_DIM_SHIFT                                          16
#define QM_TENSOR_9_TENSOR_CONFIG_LAST_DIM_MASK                                           0x70000
#define QM_TENSOR_9_TENSOR_CONFIG_RMW_SET_SHIFT                                           19
#define QM_TENSOR_9_TENSOR_CONFIG_RMW_SET_MASK                                            0x80000
#define QM_TENSOR_9_TENSOR_CONFIG_RMW_RESERV_SHIFT                                        20
#define QM_TENSOR_9_TENSOR_CONFIG_RMW_RESERV_MASK                                         0x100000
#define QM_TENSOR_9_TENSOR_CONFIG_RMW_OP_SHIFT                                            21
#define QM_TENSOR_9_TENSOR_CONFIG_RMW_OP_MASK                                             0x600000

#define QM_TENSOR_9_DIM_0_SIZE                                                          0xC08

#define QM_TENSOR_9_DIM_0_SIZE_V_SHIFT                                                    0
#define QM_TENSOR_9_DIM_0_SIZE_V_MASK                                                     0xFFFFFFFF

#define QM_TENSOR_9_DIM_0_STRIDE                                                        0xC0C

#define QM_TENSOR_9_DIM_0_STRIDE_V_SHIFT                                                  0
#define QM_TENSOR_9_DIM_0_STRIDE_V_MASK                                                   0xFFFFFFFF

#define QM_TENSOR_9_DIM_1_SIZE                                                          0xC10

#define QM_TENSOR_9_DIM_1_SIZE_V_SHIFT                                                    0
#define QM_TENSOR_9_DIM_1_SIZE_V_MASK                                                     0xFFFFFFFF

#define QM_TENSOR_9_DIM_1_STRIDE                                                        0xC14

#define QM_TENSOR_9_DIM_1_STRIDE_V_SHIFT                                                  0
#define QM_TENSOR_9_DIM_1_STRIDE_V_MASK                                                   0xFFFFFFFF

#define QM_TENSOR_9_DIM_2_SIZE                                                          0xC18

#define QM_TENSOR_9_DIM_2_SIZE_V_SHIFT                                                    0
#define QM_TENSOR_9_DIM_2_SIZE_V_MASK                                                     0xFFFFFFFF

#define QM_TENSOR_9_DIM_2_STRIDE                                                        0xC1C

#define QM_TENSOR_9_DIM_2_STRIDE_V_SHIFT                                                  0
#define QM_TENSOR_9_DIM_2_STRIDE_V_MASK                                                   0xFFFFFFFF

#define QM_TENSOR_9_DIM_3_SIZE                                                          0xC20

#define QM_TENSOR_9_DIM_3_SIZE_V_SHIFT                                                    0
#define QM_TENSOR_9_DIM_3_SIZE_V_MASK                                                     0xFFFFFFFF

#define QM_TENSOR_9_DIM_3_STRIDE                                                        0xC24

#define QM_TENSOR_9_DIM_3_STRIDE_V_SHIFT                                                  0
#define QM_TENSOR_9_DIM_3_STRIDE_V_MASK                                                   0xFFFFFFFF

#define QM_TENSOR_9_DIM_4_SIZE                                                          0xC28

#define QM_TENSOR_9_DIM_4_SIZE_V_SHIFT                                                    0
#define QM_TENSOR_9_DIM_4_SIZE_V_MASK                                                     0xFFFFFFFF

#define QM_TENSOR_9_DIM_4_STRIDE                                                        0xC2C

#define QM_TENSOR_9_DIM_4_STRIDE_V_SHIFT                                                  0
#define QM_TENSOR_9_DIM_4_STRIDE_V_MASK                                                   0xFFFFFFFF

#define QM_TENSOR_10_BASE_ADDR_LOW                                                      0xC30

#define QM_TENSOR_10_BASE_ADDR_LOW_V_SHIFT                                                0
#define QM_TENSOR_10_BASE_ADDR_LOW_V_MASK                                                 0xFFFFFFFF

#define QM_TENSOR_10_BASE_ADDR_HIGH                                                     0xC34

#define QM_TENSOR_10_BASE_ADDR_HIGH_V_SHIFT                                               0
#define QM_TENSOR_10_BASE_ADDR_HIGH_V_MASK                                                0xFFFFFFFF

#define QM_TENSOR_10_PADDING_VALUE                                                      0xC38

#define QM_TENSOR_10_PADDING_VALUE_V_SHIFT                                                0
#define QM_TENSOR_10_PADDING_VALUE_V_MASK                                                 0xFFFFFFFF

#define QM_TENSOR_10_TENSOR_CONFIG                                                      0xC3C

#define QM_TENSOR_10_TENSOR_CONFIG_DATA_TYPE_SHIFT                                        0
#define QM_TENSOR_10_TENSOR_CONFIG_DATA_TYPE_MASK                                         0x7
#define QM_TENSOR_10_TENSOR_CONFIG_VALID_DIM_MASK_SHIFT                                   8
#define QM_TENSOR_10_TENSOR_CONFIG_VALID_DIM_MASK_MASK                                    0x1F00
#define QM_TENSOR_10_TENSOR_CONFIG_LAST_DIM_SHIFT                                         16
#define QM_TENSOR_10_TENSOR_CONFIG_LAST_DIM_MASK                                          0x70000
#define QM_TENSOR_10_TENSOR_CONFIG_RMW_SET_SHIFT                                          19
#define QM_TENSOR_10_TENSOR_CONFIG_RMW_SET_MASK                                           0x80000
#define QM_TENSOR_10_TENSOR_CONFIG_RMW_RESERV_SHIFT                                       20
#define QM_TENSOR_10_TENSOR_CONFIG_RMW_RESERV_MASK                                        0x100000
#define QM_TENSOR_10_TENSOR_CONFIG_RMW_OP_SHIFT                                           21
#define QM_TENSOR_10_TENSOR_CONFIG_RMW_OP_MASK                                            0x600000

#define QM_TENSOR_10_DIM_0_SIZE                                                         0xC40

#define QM_TENSOR_10_DIM_0_SIZE_V_SHIFT                                                   0
#define QM_TENSOR_10_DIM_0_SIZE_V_MASK                                                    0xFFFFFFFF

#define QM_TENSOR_10_DIM_0_STRIDE                                                       0xC44

#define QM_TENSOR_10_DIM_0_STRIDE_V_SHIFT                                                 0
#define QM_TENSOR_10_DIM_0_STRIDE_V_MASK                                                  0xFFFFFFFF

#define QM_TENSOR_10_DIM_1_SIZE                                                         0xC48

#define QM_TENSOR_10_DIM_1_SIZE_V_SHIFT                                                   0
#define QM_TENSOR_10_DIM_1_SIZE_V_MASK                                                    0xFFFFFFFF

#define QM_TENSOR_10_DIM_1_STRIDE                                                       0xC4C

#define QM_TENSOR_10_DIM_1_STRIDE_V_SHIFT                                                 0
#define QM_TENSOR_10_DIM_1_STRIDE_V_MASK                                                  0xFFFFFFFF

#define QM_TENSOR_10_DIM_2_SIZE                                                         0xC50

#define QM_TENSOR_10_DIM_2_SIZE_V_SHIFT                                                   0
#define QM_TENSOR_10_DIM_2_SIZE_V_MASK                                                    0xFFFFFFFF

#define QM_TENSOR_10_DIM_2_STRIDE                                                       0xC54

#define QM_TENSOR_10_DIM_2_STRIDE_V_SHIFT                                                 0
#define QM_TENSOR_10_DIM_2_STRIDE_V_MASK                                                  0xFFFFFFFF

#define QM_TENSOR_10_DIM_3_SIZE                                                         0xC58

#define QM_TENSOR_10_DIM_3_SIZE_V_SHIFT                                                   0
#define QM_TENSOR_10_DIM_3_SIZE_V_MASK                                                    0xFFFFFFFF

#define QM_TENSOR_10_DIM_3_STRIDE                                                       0xC5C

#define QM_TENSOR_10_DIM_3_STRIDE_V_SHIFT                                                 0
#define QM_TENSOR_10_DIM_3_STRIDE_V_MASK                                                  0xFFFFFFFF

#define QM_TENSOR_10_DIM_4_SIZE                                                         0xC60

#define QM_TENSOR_10_DIM_4_SIZE_V_SHIFT                                                   0
#define QM_TENSOR_10_DIM_4_SIZE_V_MASK                                                    0xFFFFFFFF

#define QM_TENSOR_10_DIM_4_STRIDE                                                       0xC64

#define QM_TENSOR_10_DIM_4_STRIDE_V_SHIFT                                                 0
#define QM_TENSOR_10_DIM_4_STRIDE_V_MASK                                                  0xFFFFFFFF

#define QM_TENSOR_11_BASE_ADDR_LOW                                                      0xC68

#define QM_TENSOR_11_BASE_ADDR_LOW_V_SHIFT                                                0
#define QM_TENSOR_11_BASE_ADDR_LOW_V_MASK                                                 0xFFFFFFFF

#define QM_TENSOR_11_BASE_ADDR_HIGH                                                     0xC6C

#define QM_TENSOR_11_BASE_ADDR_HIGH_V_SHIFT                                               0
#define QM_TENSOR_11_BASE_ADDR_HIGH_V_MASK                                                0xFFFFFFFF

#define QM_TENSOR_11_PADDING_VALUE                                                      0xC70

#define QM_TENSOR_11_PADDING_VALUE_V_SHIFT                                                0
#define QM_TENSOR_11_PADDING_VALUE_V_MASK                                                 0xFFFFFFFF

#define QM_TENSOR_11_TENSOR_CONFIG                                                      0xC74

#define QM_TENSOR_11_TENSOR_CONFIG_DATA_TYPE_SHIFT                                        0
#define QM_TENSOR_11_TENSOR_CONFIG_DATA_TYPE_MASK                                         0x7
#define QM_TENSOR_11_TENSOR_CONFIG_VALID_DIM_MASK_SHIFT                                   8
#define QM_TENSOR_11_TENSOR_CONFIG_VALID_DIM_MASK_MASK                                    0x1F00
#define QM_TENSOR_11_TENSOR_CONFIG_LAST_DIM_SHIFT                                         16
#define QM_TENSOR_11_TENSOR_CONFIG_LAST_DIM_MASK                                          0x70000
#define QM_TENSOR_11_TENSOR_CONFIG_RMW_SET_SHIFT                                          19
#define QM_TENSOR_11_TENSOR_CONFIG_RMW_SET_MASK                                           0x80000
#define QM_TENSOR_11_TENSOR_CONFIG_RMW_RESERV_SHIFT                                       20
#define QM_TENSOR_11_TENSOR_CONFIG_RMW_RESERV_MASK                                        0x100000
#define QM_TENSOR_11_TENSOR_CONFIG_RMW_OP_SHIFT                                           21
#define QM_TENSOR_11_TENSOR_CONFIG_RMW_OP_MASK                                            0x600000

#define QM_TENSOR_11_DIM_0_SIZE                                                         0xC78

#define QM_TENSOR_11_DIM_0_SIZE_V_SHIFT                                                   0
#define QM_TENSOR_11_DIM_0_SIZE_V_MASK                                                    0xFFFFFFFF

#define QM_TENSOR_11_DIM_0_STRIDE                                                       0xC7C

#define QM_TENSOR_11_DIM_0_STRIDE_V_SHIFT                                                 0
#define QM_TENSOR_11_DIM_0_STRIDE_V_MASK                                                  0xFFFFFFFF

#define QM_TENSOR_11_DIM_1_SIZE                                                         0xC80

#define QM_TENSOR_11_DIM_1_SIZE_V_SHIFT                                                   0
#define QM_TENSOR_11_DIM_1_SIZE_V_MASK                                                    0xFFFFFFFF

#define QM_TENSOR_11_DIM_1_STRIDE                                                       0xC84

#define QM_TENSOR_11_DIM_1_STRIDE_V_SHIFT                                                 0
#define QM_TENSOR_11_DIM_1_STRIDE_V_MASK                                                  0xFFFFFFFF

#define QM_TENSOR_11_DIM_2_SIZE                                                         0xC88

#define QM_TENSOR_11_DIM_2_SIZE_V_SHIFT                                                   0
#define QM_TENSOR_11_DIM_2_SIZE_V_MASK                                                    0xFFFFFFFF

#define QM_TENSOR_11_DIM_2_STRIDE                                                       0xC8C

#define QM_TENSOR_11_DIM_2_STRIDE_V_SHIFT                                                 0
#define QM_TENSOR_11_DIM_2_STRIDE_V_MASK                                                  0xFFFFFFFF

#define QM_TENSOR_11_DIM_3_SIZE                                                         0xC90

#define QM_TENSOR_11_DIM_3_SIZE_V_SHIFT                                                   0
#define QM_TENSOR_11_DIM_3_SIZE_V_MASK                                                    0xFFFFFFFF

#define QM_TENSOR_11_DIM_3_STRIDE                                                       0xC94

#define QM_TENSOR_11_DIM_3_STRIDE_V_SHIFT                                                 0
#define QM_TENSOR_11_DIM_3_STRIDE_V_MASK                                                  0xFFFFFFFF

#define QM_TENSOR_11_DIM_4_SIZE                                                         0xC98

#define QM_TENSOR_11_DIM_4_SIZE_V_SHIFT                                                   0
#define QM_TENSOR_11_DIM_4_SIZE_V_MASK                                                    0xFFFFFFFF

#define QM_TENSOR_11_DIM_4_STRIDE                                                       0xC9C

#define QM_TENSOR_11_DIM_4_STRIDE_V_SHIFT                                                 0
#define QM_TENSOR_11_DIM_4_STRIDE_V_MASK                                                  0xFFFFFFFF

#define QM_TENSOR_12_BASE_ADDR_LOW                                                      0xCA0

#define QM_TENSOR_12_BASE_ADDR_LOW_V_SHIFT                                                0
#define QM_TENSOR_12_BASE_ADDR_LOW_V_MASK                                                 0xFFFFFFFF

#define QM_TENSOR_12_BASE_ADDR_HIGH                                                     0xCA4

#define QM_TENSOR_12_BASE_ADDR_HIGH_V_SHIFT                                               0
#define QM_TENSOR_12_BASE_ADDR_HIGH_V_MASK                                                0xFFFFFFFF

#define QM_TENSOR_12_PADDING_VALUE                                                      0xCA8

#define QM_TENSOR_12_PADDING_VALUE_V_SHIFT                                                0
#define QM_TENSOR_12_PADDING_VALUE_V_MASK                                                 0xFFFFFFFF

#define QM_TENSOR_12_TENSOR_CONFIG                                                      0xCAC

#define QM_TENSOR_12_TENSOR_CONFIG_DATA_TYPE_SHIFT                                        0
#define QM_TENSOR_12_TENSOR_CONFIG_DATA_TYPE_MASK                                         0x7
#define QM_TENSOR_12_TENSOR_CONFIG_VALID_DIM_MASK_SHIFT                                   8
#define QM_TENSOR_12_TENSOR_CONFIG_VALID_DIM_MASK_MASK                                    0x1F00
#define QM_TENSOR_12_TENSOR_CONFIG_LAST_DIM_SHIFT                                         16
#define QM_TENSOR_12_TENSOR_CONFIG_LAST_DIM_MASK                                          0x70000
#define QM_TENSOR_12_TENSOR_CONFIG_RMW_SET_SHIFT                                          19
#define QM_TENSOR_12_TENSOR_CONFIG_RMW_SET_MASK                                           0x80000
#define QM_TENSOR_12_TENSOR_CONFIG_RMW_RESERV_SHIFT                                       20
#define QM_TENSOR_12_TENSOR_CONFIG_RMW_RESERV_MASK                                        0x100000
#define QM_TENSOR_12_TENSOR_CONFIG_RMW_OP_SHIFT                                           21
#define QM_TENSOR_12_TENSOR_CONFIG_RMW_OP_MASK                                            0x600000

#define QM_TENSOR_12_DIM_0_SIZE                                                         0xCB0

#define QM_TENSOR_12_DIM_0_SIZE_V_SHIFT                                                   0
#define QM_TENSOR_12_DIM_0_SIZE_V_MASK                                                    0xFFFFFFFF

#define QM_TENSOR_12_DIM_0_STRIDE                                                       0xCB4

#define QM_TENSOR_12_DIM_0_STRIDE_V_SHIFT                                                 0
#define QM_TENSOR_12_DIM_0_STRIDE_V_MASK                                                  0xFFFFFFFF

#define QM_TENSOR_12_DIM_1_SIZE                                                         0xCB8

#define QM_TENSOR_12_DIM_1_SIZE_V_SHIFT                                                   0
#define QM_TENSOR_12_DIM_1_SIZE_V_MASK                                                    0xFFFFFFFF

#define QM_TENSOR_12_DIM_1_STRIDE                                                       0xCBC

#define QM_TENSOR_12_DIM_1_STRIDE_V_SHIFT                                                 0
#define QM_TENSOR_12_DIM_1_STRIDE_V_MASK                                                  0xFFFFFFFF

#define QM_TENSOR_12_DIM_2_SIZE                                                         0xCC0

#define QM_TENSOR_12_DIM_2_SIZE_V_SHIFT                                                   0
#define QM_TENSOR_12_DIM_2_SIZE_V_MASK                                                    0xFFFFFFFF

#define QM_TENSOR_12_DIM_2_STRIDE                                                       0xCC4

#define QM_TENSOR_12_DIM_2_STRIDE_V_SHIFT                                                 0
#define QM_TENSOR_12_DIM_2_STRIDE_V_MASK                                                  0xFFFFFFFF

#define QM_TENSOR_12_DIM_3_SIZE                                                         0xCC8

#define QM_TENSOR_12_DIM_3_SIZE_V_SHIFT                                                   0
#define QM_TENSOR_12_DIM_3_SIZE_V_MASK                                                    0xFFFFFFFF

#define QM_TENSOR_12_DIM_3_STRIDE                                                       0xCCC

#define QM_TENSOR_12_DIM_3_STRIDE_V_SHIFT                                                 0
#define QM_TENSOR_12_DIM_3_STRIDE_V_MASK                                                  0xFFFFFFFF

#define QM_TENSOR_12_DIM_4_SIZE                                                         0xCD0

#define QM_TENSOR_12_DIM_4_SIZE_V_SHIFT                                                   0
#define QM_TENSOR_12_DIM_4_SIZE_V_MASK                                                    0xFFFFFFFF

#define QM_TENSOR_12_DIM_4_STRIDE                                                       0xCD4

#define QM_TENSOR_12_DIM_4_STRIDE_V_SHIFT                                                 0
#define QM_TENSOR_12_DIM_4_STRIDE_V_MASK                                                  0xFFFFFFFF

#define QM_TENSOR_13_BASE_ADDR_LOW                                                      0xCD8

#define QM_TENSOR_13_BASE_ADDR_LOW_V_SHIFT                                                0
#define QM_TENSOR_13_BASE_ADDR_LOW_V_MASK                                                 0xFFFFFFFF

#define QM_TENSOR_13_BASE_ADDR_HIGH                                                     0xCDC

#define QM_TENSOR_13_BASE_ADDR_HIGH_V_SHIFT                                               0
#define QM_TENSOR_13_BASE_ADDR_HIGH_V_MASK                                                0xFFFFFFFF

#define QM_TENSOR_13_PADDING_VALUE                                                      0xCE0

#define QM_TENSOR_13_PADDING_VALUE_V_SHIFT                                                0
#define QM_TENSOR_13_PADDING_VALUE_V_MASK                                                 0xFFFFFFFF

#define QM_TENSOR_13_TENSOR_CONFIG                                                      0xCE4

#define QM_TENSOR_13_TENSOR_CONFIG_DATA_TYPE_SHIFT                                        0
#define QM_TENSOR_13_TENSOR_CONFIG_DATA_TYPE_MASK                                         0x7
#define QM_TENSOR_13_TENSOR_CONFIG_VALID_DIM_MASK_SHIFT                                   8
#define QM_TENSOR_13_TENSOR_CONFIG_VALID_DIM_MASK_MASK                                    0x1F00
#define QM_TENSOR_13_TENSOR_CONFIG_LAST_DIM_SHIFT                                         16
#define QM_TENSOR_13_TENSOR_CONFIG_LAST_DIM_MASK                                          0x70000
#define QM_TENSOR_13_TENSOR_CONFIG_RMW_SET_SHIFT                                          19
#define QM_TENSOR_13_TENSOR_CONFIG_RMW_SET_MASK                                           0x80000
#define QM_TENSOR_13_TENSOR_CONFIG_RMW_RESERV_SHIFT                                       20
#define QM_TENSOR_13_TENSOR_CONFIG_RMW_RESERV_MASK                                        0x100000
#define QM_TENSOR_13_TENSOR_CONFIG_RMW_OP_SHIFT                                           21
#define QM_TENSOR_13_TENSOR_CONFIG_RMW_OP_MASK                                            0x600000

#define QM_TENSOR_13_DIM_0_SIZE                                                         0xCE8

#define QM_TENSOR_13_DIM_0_SIZE_V_SHIFT                                                   0
#define QM_TENSOR_13_DIM_0_SIZE_V_MASK                                                    0xFFFFFFFF

#define QM_TENSOR_13_DIM_0_STRIDE                                                       0xCEC

#define QM_TENSOR_13_DIM_0_STRIDE_V_SHIFT                                                 0
#define QM_TENSOR_13_DIM_0_STRIDE_V_MASK                                                  0xFFFFFFFF

#define QM_TENSOR_13_DIM_1_SIZE                                                         0xCF0

#define QM_TENSOR_13_DIM_1_SIZE_V_SHIFT                                                   0
#define QM_TENSOR_13_DIM_1_SIZE_V_MASK                                                    0xFFFFFFFF

#define QM_TENSOR_13_DIM_1_STRIDE                                                       0xCF4

#define QM_TENSOR_13_DIM_1_STRIDE_V_SHIFT                                                 0
#define QM_TENSOR_13_DIM_1_STRIDE_V_MASK                                                  0xFFFFFFFF

#define QM_TENSOR_13_DIM_2_SIZE                                                         0xCF8

#define QM_TENSOR_13_DIM_2_SIZE_V_SHIFT                                                   0
#define QM_TENSOR_13_DIM_2_SIZE_V_MASK                                                    0xFFFFFFFF

#define QM_TENSOR_13_DIM_2_STRIDE                                                       0xCFC

#define QM_TENSOR_13_DIM_2_STRIDE_V_SHIFT                                                 0
#define QM_TENSOR_13_DIM_2_STRIDE_V_MASK                                                  0xFFFFFFFF

#define QM_TENSOR_13_DIM_3_SIZE                                                         0xD00

#define QM_TENSOR_13_DIM_3_SIZE_V_SHIFT                                                   0
#define QM_TENSOR_13_DIM_3_SIZE_V_MASK                                                    0xFFFFFFFF

#define QM_TENSOR_13_DIM_3_STRIDE                                                       0xD04

#define QM_TENSOR_13_DIM_3_STRIDE_V_SHIFT                                                 0
#define QM_TENSOR_13_DIM_3_STRIDE_V_MASK                                                  0xFFFFFFFF

#define QM_TENSOR_13_DIM_4_SIZE                                                         0xD08

#define QM_TENSOR_13_DIM_4_SIZE_V_SHIFT                                                   0
#define QM_TENSOR_13_DIM_4_SIZE_V_MASK                                                    0xFFFFFFFF

#define QM_TENSOR_13_DIM_4_STRIDE                                                       0xD0C

#define QM_TENSOR_13_DIM_4_STRIDE_V_SHIFT                                                 0
#define QM_TENSOR_13_DIM_4_STRIDE_V_MASK                                                  0xFFFFFFFF

#define QM_TENSOR_14_BASE_ADDR_LOW                                                      0xD10

#define QM_TENSOR_14_BASE_ADDR_LOW_V_SHIFT                                                0
#define QM_TENSOR_14_BASE_ADDR_LOW_V_MASK                                                 0xFFFFFFFF

#define QM_TENSOR_14_BASE_ADDR_HIGH                                                     0xD14

#define QM_TENSOR_14_BASE_ADDR_HIGH_V_SHIFT                                               0
#define QM_TENSOR_14_BASE_ADDR_HIGH_V_MASK                                                0xFFFFFFFF

#define QM_TENSOR_14_PADDING_VALUE                                                      0xD18

#define QM_TENSOR_14_PADDING_VALUE_V_SHIFT                                                0
#define QM_TENSOR_14_PADDING_VALUE_V_MASK                                                 0xFFFFFFFF

#define QM_TENSOR_14_TENSOR_CONFIG                                                      0xD1C

#define QM_TENSOR_14_TENSOR_CONFIG_DATA_TYPE_SHIFT                                        0
#define QM_TENSOR_14_TENSOR_CONFIG_DATA_TYPE_MASK                                         0x7
#define QM_TENSOR_14_TENSOR_CONFIG_VALID_DIM_MASK_SHIFT                                   8
#define QM_TENSOR_14_TENSOR_CONFIG_VALID_DIM_MASK_MASK                                    0x1F00
#define QM_TENSOR_14_TENSOR_CONFIG_LAST_DIM_SHIFT                                         16
#define QM_TENSOR_14_TENSOR_CONFIG_LAST_DIM_MASK                                          0x70000
#define QM_TENSOR_14_TENSOR_CONFIG_RMW_SET_SHIFT                                          19
#define QM_TENSOR_14_TENSOR_CONFIG_RMW_SET_MASK                                           0x80000
#define QM_TENSOR_14_TENSOR_CONFIG_RMW_RESERV_SHIFT                                       20
#define QM_TENSOR_14_TENSOR_CONFIG_RMW_RESERV_MASK                                        0x100000
#define QM_TENSOR_14_TENSOR_CONFIG_RMW_OP_SHIFT                                           21
#define QM_TENSOR_14_TENSOR_CONFIG_RMW_OP_MASK                                            0x600000

#define QM_TENSOR_14_DIM_0_SIZE                                                         0xD20

#define QM_TENSOR_14_DIM_0_SIZE_V_SHIFT                                                   0
#define QM_TENSOR_14_DIM_0_SIZE_V_MASK                                                    0xFFFFFFFF

#define QM_TENSOR_14_DIM_0_STRIDE                                                       0xD24

#define QM_TENSOR_14_DIM_0_STRIDE_V_SHIFT                                                 0
#define QM_TENSOR_14_DIM_0_STRIDE_V_MASK                                                  0xFFFFFFFF

#define QM_TENSOR_14_DIM_1_SIZE                                                         0xD28

#define QM_TENSOR_14_DIM_1_SIZE_V_SHIFT                                                   0
#define QM_TENSOR_14_DIM_1_SIZE_V_MASK                                                    0xFFFFFFFF

#define QM_TENSOR_14_DIM_1_STRIDE                                                       0xD2C

#define QM_TENSOR_14_DIM_1_STRIDE_V_SHIFT                                                 0
#define QM_TENSOR_14_DIM_1_STRIDE_V_MASK                                                  0xFFFFFFFF

#define QM_TENSOR_14_DIM_2_SIZE                                                         0xD30

#define QM_TENSOR_14_DIM_2_SIZE_V_SHIFT                                                   0
#define QM_TENSOR_14_DIM_2_SIZE_V_MASK                                                    0xFFFFFFFF

#define QM_TENSOR_14_DIM_2_STRIDE                                                       0xD34

#define QM_TENSOR_14_DIM_2_STRIDE_V_SHIFT                                                 0
#define QM_TENSOR_14_DIM_2_STRIDE_V_MASK                                                  0xFFFFFFFF

#define QM_TENSOR_14_DIM_3_SIZE                                                         0xD38

#define QM_TENSOR_14_DIM_3_SIZE_V_SHIFT                                                   0
#define QM_TENSOR_14_DIM_3_SIZE_V_MASK                                                    0xFFFFFFFF

#define QM_TENSOR_14_DIM_3_STRIDE                                                       0xD3C

#define QM_TENSOR_14_DIM_3_STRIDE_V_SHIFT                                                 0
#define QM_TENSOR_14_DIM_3_STRIDE_V_MASK                                                  0xFFFFFFFF

#define QM_TENSOR_14_DIM_4_SIZE                                                         0xD40

#define QM_TENSOR_14_DIM_4_SIZE_V_SHIFT                                                   0
#define QM_TENSOR_14_DIM_4_SIZE_V_MASK                                                    0xFFFFFFFF

#define QM_TENSOR_14_DIM_4_STRIDE                                                       0xD44

#define QM_TENSOR_14_DIM_4_STRIDE_V_SHIFT                                                 0
#define QM_TENSOR_14_DIM_4_STRIDE_V_MASK                                                  0xFFFFFFFF

#define QM_TENSOR_15_BASE_ADDR_LOW                                                      0xD48

#define QM_TENSOR_15_BASE_ADDR_LOW_V_SHIFT                                                0
#define QM_TENSOR_15_BASE_ADDR_LOW_V_MASK                                                 0xFFFFFFFF

#define QM_TENSOR_15_BASE_ADDR_HIGH                                                     0xD4C

#define QM_TENSOR_15_BASE_ADDR_HIGH_V_SHIFT                                               0
#define QM_TENSOR_15_BASE_ADDR_HIGH_V_MASK                                                0xFFFFFFFF

#define QM_TENSOR_15_PADDING_VALUE                                                      0xD50

#define QM_TENSOR_15_PADDING_VALUE_V_SHIFT                                                0
#define QM_TENSOR_15_PADDING_VALUE_V_MASK                                                 0xFFFFFFFF

#define QM_TENSOR_15_TENSOR_CONFIG                                                      0xD54

#define QM_TENSOR_15_TENSOR_CONFIG_DATA_TYPE_SHIFT                                        0
#define QM_TENSOR_15_TENSOR_CONFIG_DATA_TYPE_MASK                                         0x7
#define QM_TENSOR_15_TENSOR_CONFIG_VALID_DIM_MASK_SHIFT                                   8
#define QM_TENSOR_15_TENSOR_CONFIG_VALID_DIM_MASK_MASK                                    0x1F00
#define QM_TENSOR_15_TENSOR_CONFIG_LAST_DIM_SHIFT                                         16
#define QM_TENSOR_15_TENSOR_CONFIG_LAST_DIM_MASK                                          0x70000
#define QM_TENSOR_15_TENSOR_CONFIG_RMW_SET_SHIFT                                          19
#define QM_TENSOR_15_TENSOR_CONFIG_RMW_SET_MASK                                           0x80000
#define QM_TENSOR_15_TENSOR_CONFIG_RMW_RESERV_SHIFT                                       20
#define QM_TENSOR_15_TENSOR_CONFIG_RMW_RESERV_MASK                                        0x100000
#define QM_TENSOR_15_TENSOR_CONFIG_RMW_OP_SHIFT                                           21
#define QM_TENSOR_15_TENSOR_CONFIG_RMW_OP_MASK                                            0x600000

#define QM_TENSOR_15_DIM_0_SIZE                                                         0xD58

#define QM_TENSOR_15_DIM_0_SIZE_V_SHIFT                                                   0
#define QM_TENSOR_15_DIM_0_SIZE_V_MASK                                                    0xFFFFFFFF

#define QM_TENSOR_15_DIM_0_STRIDE                                                       0xD5C

#define QM_TENSOR_15_DIM_0_STRIDE_V_SHIFT                                                 0
#define QM_TENSOR_15_DIM_0_STRIDE_V_MASK                                                  0xFFFFFFFF

#define QM_TENSOR_15_DIM_1_SIZE                                                         0xD60

#define QM_TENSOR_15_DIM_1_SIZE_V_SHIFT                                                   0
#define QM_TENSOR_15_DIM_1_SIZE_V_MASK                                                    0xFFFFFFFF

#define QM_TENSOR_15_DIM_1_STRIDE                                                       0xD64

#define QM_TENSOR_15_DIM_1_STRIDE_V_SHIFT                                                 0
#define QM_TENSOR_15_DIM_1_STRIDE_V_MASK                                                  0xFFFFFFFF

#define QM_TENSOR_15_DIM_2_SIZE                                                         0xD68

#define QM_TENSOR_15_DIM_2_SIZE_V_SHIFT                                                   0
#define QM_TENSOR_15_DIM_2_SIZE_V_MASK                                                    0xFFFFFFFF

#define QM_TENSOR_15_DIM_2_STRIDE                                                       0xD6C

#define QM_TENSOR_15_DIM_2_STRIDE_V_SHIFT                                                 0
#define QM_TENSOR_15_DIM_2_STRIDE_V_MASK                                                  0xFFFFFFFF

#define QM_TENSOR_15_DIM_3_SIZE                                                         0xD70

#define QM_TENSOR_15_DIM_3_SIZE_V_SHIFT                                                   0
#define QM_TENSOR_15_DIM_3_SIZE_V_MASK                                                    0xFFFFFFFF

#define QM_TENSOR_15_DIM_3_STRIDE                                                       0xD74

#define QM_TENSOR_15_DIM_3_STRIDE_V_SHIFT                                                 0
#define QM_TENSOR_15_DIM_3_STRIDE_V_MASK                                                  0xFFFFFFFF

#define QM_TENSOR_15_DIM_4_SIZE                                                         0xD78

#define QM_TENSOR_15_DIM_4_SIZE_V_SHIFT                                                   0
#define QM_TENSOR_15_DIM_4_SIZE_V_MASK                                                    0xFFFFFFFF

#define QM_TENSOR_15_DIM_4_STRIDE                                                       0xD7C

#define QM_TENSOR_15_DIM_4_STRIDE_V_SHIFT                                                 0
#define QM_TENSOR_15_DIM_4_STRIDE_V_MASK                                                  0xFFFFFFFF

#define QM_SYNC_OBJECT_MESSAGE                                                          0xD80

#define QM_SYNC_OBJECT_MESSAGE_SO_WRITE_VALUE_SHIFT                                       0
#define QM_SYNC_OBJECT_MESSAGE_SO_WRITE_VALUE_MASK                                        0xFFFF
#define QM_SYNC_OBJECT_MESSAGE_RSV_SHIFT                                                  16
#define QM_SYNC_OBJECT_MESSAGE_RSV_MASK                                                   0x1FFF0000
#define QM_SYNC_OBJECT_MESSAGE_SO_OPERATION_SHIFT                                         29
#define QM_SYNC_OBJECT_MESSAGE_SO_OPERATION_MASK                                          0xE0000000

#define QM_SYNC_OBJECT_ADDR                                                             0xD84

#define QM_SYNC_OBJECT_ADDR_V_SHIFT                                                       0
#define QM_SYNC_OBJECT_ADDR_V_MASK                                                        0xFFFFFFFF

#define QM_KERNEL_BASE_ADDRESS_LOW                                                      0xD88

#define QM_KERNEL_BASE_ADDRESS_LOW_V_SHIFT                                                0
#define QM_KERNEL_BASE_ADDRESS_LOW_V_MASK                                                 0xFFFFFFFF

#define QM_KERNEL_BASE_ADDRESS_HIGH                                                     0xD8C

#define QM_KERNEL_BASE_ADDRESS_HIGH_V_SHIFT                                               0
#define QM_KERNEL_BASE_ADDRESS_HIGH_V_MASK                                                0xFFFFFFFF

#define QM_TID_BASE_DIM_0                                                               0xD90

#define QM_TID_BASE_DIM_0_V_SHIFT                                                         0
#define QM_TID_BASE_DIM_0_V_MASK                                                          0xFFFFFFFF

#define QM_TID_SIZE_DIM_0                                                               0xD94

#define QM_TID_SIZE_DIM_0_V_SHIFT                                                         0
#define QM_TID_SIZE_DIM_0_V_MASK                                                          0xFFFFFFFF

#define QM_TID_BASE_DIM_1                                                               0xD98

#define QM_TID_BASE_DIM_1_V_SHIFT                                                         0
#define QM_TID_BASE_DIM_1_V_MASK                                                          0xFFFFFFFF

#define QM_TID_SIZE_DIM_1                                                               0xD9C

#define QM_TID_SIZE_DIM_1_V_SHIFT                                                         0
#define QM_TID_SIZE_DIM_1_V_MASK                                                          0xFFFFFFFF

#define QM_TID_BASE_DIM_2                                                               0xDA0

#define QM_TID_BASE_DIM_2_V_SHIFT                                                         0
#define QM_TID_BASE_DIM_2_V_MASK                                                          0xFFFFFFFF

#define QM_TID_SIZE_DIM_2                                                               0xDA4

#define QM_TID_SIZE_DIM_2_V_SHIFT                                                         0
#define QM_TID_SIZE_DIM_2_V_MASK                                                          0xFFFFFFFF

#define QM_TID_BASE_DIM_3                                                               0xDA8

#define QM_TID_BASE_DIM_3_V_SHIFT                                                         0
#define QM_TID_BASE_DIM_3_V_MASK                                                          0xFFFFFFFF

#define QM_TID_SIZE_DIM_3                                                               0xDAC

#define QM_TID_SIZE_DIM_3_V_SHIFT                                                         0
#define QM_TID_SIZE_DIM_3_V_MASK                                                          0xFFFFFFFF

#define QM_TID_BASE_DIM_4                                                               0xDB0

#define QM_TID_BASE_DIM_4_V_SHIFT                                                         0
#define QM_TID_BASE_DIM_4_V_MASK                                                          0xFFFFFFFF

#define QM_TID_SIZE_DIM_4                                                               0xDB4

#define QM_TID_SIZE_DIM_4_V_SHIFT                                                         0
#define QM_TID_SIZE_DIM_4_V_MASK                                                          0xFFFFFFFF

#define QM_KERNEL_CONFIG                                                                0xDB8

#define QM_KERNEL_CONFIG_SMALL_VLM_SHIFT                                                  0
#define QM_KERNEL_CONFIG_SMALL_VLM_MASK                                                   0x1
#define QM_KERNEL_CONFIG_ASO_EVICT_L0_SHIFT                                               1
#define QM_KERNEL_CONFIG_ASO_EVICT_L0_MASK                                                0x2
#define QM_KERNEL_CONFIG_NUM_VALID_SRFS_SHIFT                                             2
#define QM_KERNEL_CONFIG_NUM_VALID_SRFS_MASK                                              0xFC
#define QM_KERNEL_CONFIG_RD_RATE_LIMIT_RST_TOKEN_SHIFT                                    8
#define QM_KERNEL_CONFIG_RD_RATE_LIMIT_RST_TOKEN_MASK                                     0xFF00
#define QM_KERNEL_CONFIG_WR_RATE_LIMIT_RST_TOKEN_SHIFT                                    16
#define QM_KERNEL_CONFIG_WR_RATE_LIMIT_RST_TOKEN_MASK                                     0xFF0000

#define QM_KERNEL_ID                                                                    0xDBC

#define QM_KERNEL_ID_V_SHIFT                                                              0
#define QM_KERNEL_ID_V_MASK                                                               0xFFFF

#define QM_SRF_0                                                                        0xDC0

#define QM_SRF_0_V_SHIFT                                                                  0
#define QM_SRF_0_V_MASK                                                                   0xFFFFFFFF

#define QM_SRF_1                                                                        0xDC4

#define QM_SRF_1_V_SHIFT                                                                  0
#define QM_SRF_1_V_MASK                                                                   0xFFFFFFFF

#define QM_SRF_2                                                                        0xDC8

#define QM_SRF_2_V_SHIFT                                                                  0
#define QM_SRF_2_V_MASK                                                                   0xFFFFFFFF

#define QM_SRF_3                                                                        0xDCC

#define QM_SRF_3_V_SHIFT                                                                  0
#define QM_SRF_3_V_MASK                                                                   0xFFFFFFFF

#define QM_SRF_4                                                                        0xDD0

#define QM_SRF_4_V_SHIFT                                                                  0
#define QM_SRF_4_V_MASK                                                                   0xFFFFFFFF

#define QM_SRF_5                                                                        0xDD4

#define QM_SRF_5_V_SHIFT                                                                  0
#define QM_SRF_5_V_MASK                                                                   0xFFFFFFFF

#define QM_SRF_6                                                                        0xDD8

#define QM_SRF_6_V_SHIFT                                                                  0
#define QM_SRF_6_V_MASK                                                                   0xFFFFFFFF

#define QM_SRF_7                                                                        0xDDC

#define QM_SRF_7_V_SHIFT                                                                  0
#define QM_SRF_7_V_MASK                                                                   0xFFFFFFFF

#define QM_SRF_8                                                                        0xDE0

#define QM_SRF_8_V_SHIFT                                                                  0
#define QM_SRF_8_V_MASK                                                                   0xFFFFFFFF

#define QM_SRF_9                                                                        0xDE4

#define QM_SRF_9_V_SHIFT                                                                  0
#define QM_SRF_9_V_MASK                                                                   0xFFFFFFFF

#define QM_SRF_10                                                                       0xDE8

#define QM_SRF_10_V_SHIFT                                                                 0
#define QM_SRF_10_V_MASK                                                                  0xFFFFFFFF

#define QM_SRF_11                                                                       0xDEC

#define QM_SRF_11_V_SHIFT                                                                 0
#define QM_SRF_11_V_MASK                                                                  0xFFFFFFFF

#define QM_SRF_12                                                                       0xDF0

#define QM_SRF_12_V_SHIFT                                                                 0
#define QM_SRF_12_V_MASK                                                                  0xFFFFFFFF

#define QM_SRF_13                                                                       0xDF4

#define QM_SRF_13_V_SHIFT                                                                 0
#define QM_SRF_13_V_MASK                                                                  0xFFFFFFFF

#define QM_SRF_14                                                                       0xDF8

#define QM_SRF_14_V_SHIFT                                                                 0
#define QM_SRF_14_V_MASK                                                                  0xFFFFFFFF

#define QM_SRF_15                                                                       0xDFC

#define QM_SRF_15_V_SHIFT                                                                 0
#define QM_SRF_15_V_MASK                                                                  0xFFFFFFFF

#define QM_SRF_16                                                                       0xE00

#define QM_SRF_16_V_SHIFT                                                                 0
#define QM_SRF_16_V_MASK                                                                  0xFFFFFFFF

#define QM_SRF_17                                                                       0xE04

#define QM_SRF_17_V_SHIFT                                                                 0
#define QM_SRF_17_V_MASK                                                                  0xFFFFFFFF

#define QM_SRF_18                                                                       0xE08

#define QM_SRF_18_V_SHIFT                                                                 0
#define QM_SRF_18_V_MASK                                                                  0xFFFFFFFF

#define QM_SRF_19                                                                       0xE0C

#define QM_SRF_19_V_SHIFT                                                                 0
#define QM_SRF_19_V_MASK                                                                  0xFFFFFFFF

#define QM_SRF_20                                                                       0xE10

#define QM_SRF_20_V_SHIFT                                                                 0
#define QM_SRF_20_V_MASK                                                                  0xFFFFFFFF

#define QM_SRF_21                                                                       0xE14

#define QM_SRF_21_V_SHIFT                                                                 0
#define QM_SRF_21_V_MASK                                                                  0xFFFFFFFF

#define QM_SRF_22                                                                       0xE18

#define QM_SRF_22_V_SHIFT                                                                 0
#define QM_SRF_22_V_MASK                                                                  0xFFFFFFFF

#define QM_SRF_23                                                                       0xE1C

#define QM_SRF_23_V_SHIFT                                                                 0
#define QM_SRF_23_V_MASK                                                                  0xFFFFFFFF

#define QM_SRF_24                                                                       0xE20

#define QM_SRF_24_V_SHIFT                                                                 0
#define QM_SRF_24_V_MASK                                                                  0xFFFFFFFF

#define QM_SRF_25                                                                       0xE24

#define QM_SRF_25_V_SHIFT                                                                 0
#define QM_SRF_25_V_MASK                                                                  0xFFFFFFFF

#define QM_SRF_26                                                                       0xE28

#define QM_SRF_26_V_SHIFT                                                                 0
#define QM_SRF_26_V_MASK                                                                  0xFFFFFFFF

#define QM_SRF_27                                                                       0xE2C

#define QM_SRF_27_V_SHIFT                                                                 0
#define QM_SRF_27_V_MASK                                                                  0xFFFFFFFF

#define QM_SRF_28                                                                       0xE30

#define QM_SRF_28_V_SHIFT                                                                 0
#define QM_SRF_28_V_MASK                                                                  0xFFFFFFFF

#define QM_SRF_29                                                                       0xE34

#define QM_SRF_29_V_SHIFT                                                                 0
#define QM_SRF_29_V_MASK                                                                  0xFFFFFFFF

#define QM_SRF_30                                                                       0xE38

#define QM_SRF_30_V_SHIFT                                                                 0
#define QM_SRF_30_V_MASK                                                                  0xFFFFFFFF

#define QM_SRF_31                                                                       0xE3C

#define QM_SRF_31_V_SHIFT                                                                 0
#define QM_SRF_31_V_MASK                                                                  0xFFFFFFFF
#endif /* TPC_IO_REG_SPACE_GEN2_H_ */
