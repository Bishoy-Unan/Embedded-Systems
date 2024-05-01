/*
 * SYSTick_program.c
 *
 *  Created on: Mar 22, 2024
 *      Author: Lenovo
 */
#include "BIT_MATH.h"
#include "STD_types.h"
#include "SYSTick_private.h"
#include "SYSTick_interface.h"



static void (*SYSTick_CallBack)(void);

// calling by Hardware if interrupt happens
void SysTick_Handler(void)
{
	// Execute CallBack Function
	SYSTick_CallBack();
}


void SYSTick_voidInit(void)
{
	//enable systick interrupt - clock = AHB/8 - stop systick
	SET_BIT(STK_CTRL,1);
	CLR_BIT(STK_CTRL,2);
	CLR_BIT(STK_CTRL,0);

}

void SYSTick_voidStart(u32 Copy_32preloadVal)
{

	// if F_CPU -> HSI = 16MHZ , AHB = 16 MHZ, F_Timer = AHB/8 = 2MHZ
	// 0.5 us for each count
	// 1- load value
	STK_LOAD = Copy_32preloadVal;
	// 2- Clear val reg

	STK_VAL = 0x00000000;
	// 3- Enable systick
	SET_BIT(STK_CTRL,0);
}

u8 SYSTick_u8ReadCountFlag(void)
{

	// read bit 16
	u8 countValue;
	countValue = GET_BIT(STK_CTRL,16);
	return countValue;
}

void SYSTick_voidSetIntStatus(INT_t Copy_uddtIntStatus)
{

	//clear bit of interrupt
	CLR_BIT(STK_CTRL,1);
	// set the bit of interrupt with the input
	STK_CTRL |= (1<<Copy_uddtIntStatus);
}

void SYSTick_voidDelayMs(u32 Copy_32Time)
{
	// step 1: init systick
	SYSTick_voidInit();
	// step 2: disable INT
	SYSTick_voidSetIntStatus(MSTK_INT_DISABLE);
	// step 3: start systick(Copy_32Time)
	SYSTick_voidStart(Copy_32Time * 2000);
	// step 4: wait flag polling
	while(SYSTick_u8ReadCountFlag()==0);

}

void SYSTick_voidDelayUs(u32 Copy_32Time)
{
	// step 1: init systick
	MSTK_voidInit();

	// step 2: disable INT
	MSTK_voidSetIntStatus(MSTK_INT_DISABLE);

	// step 3: start systick(Copy_32Time )
	MSTK_voidStart(Copy_32Time * 2);
	// step 4: wait flag polling
	while(MSTK_u8ReadCountFlag()==0);

}

void SYSTick_voidSetCallBack(void (*PFunc)(void))
{
	SYSTick_CallBack = PFunc;
}
