/*
 * SYSTick_interface.h
 *
 *  Created on: Mar 22, 2024
 *      Author: Lenovo
 */

#ifndef SYSTICK_INTERFACE_H_
#define SYSTICK_INTERFACE_H_

typedef enum
{
	MSTK_INT_DISABLE,
	MSTK_INT_ENABLE,

}INT_t;

void SYSTick_voidInit(void);

void SYSTick_voidStart(u32 Copy_32preloadVal);

u8 SYSTick_u8ReadCountFlag(void);

void SYSTick_voidSetIntStatus(INT_t Copy_uddtIntStatus);

void SYSTick_voidDelayMs(u32 Copy_32Time);

void SYSTick_voidDelayUs(u32 Copy_32Time);

void SYSTick_voidSetCallBack(void (*PFunc)(void));


#endif /* SYSTICK_INTERFACE_H_ */
