/**************************************************************************//**
 * @file     mem_VK_RZ_A1H.h
 * @brief    Memory base and size definitions (used in scatter file)
 * @version  V1.00
 * @date     10 Mar 2017
 *
 * @note
 *
 ******************************************************************************/
/*
 * Copyright (c) 2009-2017 ARM Limited. All rights reserved.
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef __MEM_VK_RZ_A1H_H
#define __MEM_VK_RZ_A1H_H

/*----------------------------------------------------------------------------
  User Stack & Heap size definition
 *----------------------------------------------------------------------------*/
/*
//-------- <<< Use Configuration Wizard in Context Menu >>> ------------------
*/

/*--------------------- ROM Configuration ------------------------------------
//
// <h> ROM Configuration
//   <o0> ROM Base Address <0x0-0xFFFFFFFF:8>
//   <o1> ROM Size (in Bytes) <0x0-0xFFFFFFFF:8>
// </h>
 *----------------------------------------------------------------------------*/
#ifdef RUN_FROM_SDRAM
 #define __ROM_BASE       0x08000000
 #define __ROM_SIZE       0x02000000
 #define __VECTOR_BASE    0x08000000
 #define __DATA_BASE	  +0 ALIGN 0x100000
#elif defined (RUN_FROM_SRAM)
 #define __ROM_BASE       0x200A0000
 #define __ROM_SIZE       0x00960000
 #define __VECTOR_BASE    0x200A0000
 #define __DATA_BASE	  +0 ALIGN 0x100000 NOCOMPRESS
#else
 #define __ROM_BASE       0x18020000
 #define __ROM_SIZE       0x01FE0000
 #define __VECTOR_BASE    0x18020000
 #define __DATA_BASE	  0x20020000
#endif

/*--------------------- RAM Configuration -----------------------------------
 *----------------------------------------------------------------------------*/
#ifdef RUN_FROM_SDRAM
#define __RAM_BASE       0x08000000
#define __RAM_SIZE       0x02000000
#define __NC_RAM_SIZE    0x00200000
#else
#define __RAM_BASE       0x20000000
#define __RAM_SIZE       0x00A00000
#define __NC_RAM_SIZE    0x00100000
#endif
#define __NM_RAM_SIZE    (__RAM_SIZE - __NC_RAM_SIZE)
#define __DATA_NC_BASE   (__RAM_BASE + __NM_RAM_SIZE + 0x40000000)

#define __UND_STACK_SIZE 0x00000100
#define __SVC_STACK_SIZE 0x00008000
#define __ABT_STACK_SIZE 0x00000100
#define __FIQ_STACK_SIZE 0x00000100
#define __IRQ_STACK_SIZE 0x0000F000
#define __STACK_SIZE     (__UND_STACK_SIZE + __SVC_STACK_SIZE + __ABT_STACK_SIZE + __FIQ_STACK_SIZE + __IRQ_STACK_SIZE)

/*----------------------------------------------------------------------------*/

/*--------------------- TTB Configuration ------------------------------------
//
// <h> TTB Configuration
//   <o0> TTB Base Address <0x0-0xFFFFFFFF:8>
//   <o1> TTB Size (in Bytes) <0x0-0xFFFFFFFF:8>
// </h>
 *----------------------------------------------------------------------------*/
#define __TTB_BASE       0x20000000
#define __TTB_SIZE       0x00004000

#endif /* __MEM_VK_RZ_A1H_H */
