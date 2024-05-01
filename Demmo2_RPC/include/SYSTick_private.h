/*
 * SYSTick_private.h
 *
 *  Created on: Mar 22, 2024
 *      Author: Lenovo
 */

#ifndef SYSTICK_PRIVATE_H_
#define SYSTICK_PRIVATE_H_

#define MSTK_BASE_ADDRESS		(0xE000E010)


#define  STK_CTRL 				(*((volatile u32*)(MSTK_BASE_ADDRESS + 0x00)))
#define  STK_LOAD				(*((volatile u32*)(MSTK_BASE_ADDRESS + 0x04)))
#define  STK_VAL				(*((volatile u32*)(MSTK_BASE_ADDRESS + 0x08)))
#define  STK_CALIB				(*((volatile u32*)(MSTK_BASE_ADDRESS + 0x0C)))



#endif /* SYSTICK_PRIVATE_H_ */
