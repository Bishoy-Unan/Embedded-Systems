/*
 * NVIC_private.h
 *
 *  Created on: Mar 22, 2024
 *      Author: Lenovo
 */

#ifndef NVIC_PRIVATE_H_
#define NVIC_PRIVATE_H_

#define		NVIC_ISER_BASE_ADDRESS              (0xE000E100)

typedef struct
{

	u32 ISER[8];
	u32 RESERVED1[24];
	u32 ICER[8];
	u32 RESERVED2[24];
	u32 ISPR[8];
	u32 RESERVED3[24];
	u32 ICPR[8];
	u32 RESERVED4[24];
	u32 IABR[8];
	u32 RESERVED5[56];
	u8 IPR[240];
	u32 RESERVED6[580];
	u32 STIR;

}NVIC_t;

#define		NVIC_REG		((volatile NVIC_t*)(NVIC_ISER_BASE_ADDRESS))

#endif /* NVIC_PRIVATE_H_ */
