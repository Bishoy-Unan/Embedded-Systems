/*
 * RCC_program.c
 *
 *  Created on: Feb 7, 2024
 *      Author: Aml Ashraf
 */

#include "RCC_private.h"
#include "BIT_MATH.h"
#include "STD_types.h"
#include "RCC_interface.h"


void RCC_voidInitSystemClock(void)
{
	u32 local_SwitchSystemClockReg = RCC_CFGR;

#if RCC_CLKSRC == RCC_SYSCLK_HSI
	/*Step 1 : Enable HSI*/
	SET_BIT(RCC_CR,RCC_CR_HSION) ;
	/*Step 2: Wait Till HSI is ready */
	while(GET_BIT(RCC_CR,RCC_CR_HSIRDY) == 0) ;
	/*Step 3 : Switch to HSI*/
	//CLR_BIT(RCC_CFGR,0U) ;
	//CLR_BIT(RCC_CFGR,1U) ;
	local_SwitchSystemClockReg &= MASK_RCC_CFGR_SW;
	local_SwitchSystemClockReg |= MASK_HSI_SW;
	RCC_CFGR = local_SwitchSystemClockReg;

#elif RCC_CLKSRC == RCC_SYSCLK_HSE
	 /*Step 1 : Enable HSE*/
	 SET_BIT(RCC_CR,RCC_CR_HSEON) ;
	 /*Step 2 : Wait Till HSE is ready */
	 while(GET_BIT(RCC_CR,RCC_CR_HSERDY) == 0) ;
   #if   RCC_HSE_SRC == HSE_MECH
	 /*Step 3 : Disable BYPass*/
	 CLR_BIT(RCC_CR,RCC_CR_HSEBYP) ;
	 /*Step 4 : Switch to HSE*/
	 //SET_BIT(RCC_CFGR,0U) ;
	 //CLR_BIT(RCC_CFGR,1U) ;
	 local_SwitchSystemClockReg &= MASK_RCC_CFGR_SW;
	 local_SwitchSystemClockReg |= MASK_HSE_SW;
	 RCC_CFGR = local_SwitchSystemClockReg;

   #elif RCC_HSE_SRC == HSE_RC

		 /*Step 3 : Enable BYPass*/
	    SET_BIT(RCC_CR,RCC_CR_HSEBYP) ;
	     /*Step 3 : Switch to HSE*/
	    //SET_BIT(RCC_CFGR,0U) ;
	 	//CLR_BIT(RCC_CFGR,1U) ;
	    local_SwitchSystemClockReg &= MASK_RCC_CFGR_SW;
	    local_SwitchSystemClockReg |= MASK_HSE_SW;
	    RCC_CFGR = local_SwitchSystemClockReg;
   #else
	/*Error*/
   #endif

#elif RCC_CLKSRC == RCC_SYSCLK_PLL
   //TODO

	    //local_SwitchSystemClockReg &= MASK_RCC_CFGR_SW;
	    //local_SwitchSystemClockReg |= MASK_PLL_SW;
	    //RCC_CFGR = local_SwitchSystemClockReg;
#else
	/*Error*/
#endif

}

void RCC_voidEnablePeripheralClock(BusName_t Copy_uddtBusName, u8  Copy_u8PerNum)
{

	switch(Copy_uddtBusName)
	{
	case AHB1:
		RCC_AHB1ENR |= (1<<Copy_u8PerNum);
		//SET_BIT(RCC_AHB1ENR,Copy_u8PerNum);
		break;

	case AHB2:
		RCC_AHB2ENR |= (1<<Copy_u8PerNum);
		//SET_BIT(RCC_AHB2ENR,Copy_u8PerNum);
		break;

	case APB1:
		RCC_APB1ENR |= (1<<Copy_u8PerNum);
		//SET_BIT(RCC_APB1ENR,Copy_u8PerNum);
		break;

	case APB2:
		RCC_APB2ENR |= (1<<Copy_u8PerNum);
		//SET_BIT(RCC_APB2ENR,Copy_u8PerNum);
		break;

	default:
	//#error "error in RCC Bus Name"
		break;
	}

}

void RCC_voidDisablePeripheralClock(BusName_t Copy_uddtBusName, u8  Copy_u8PerNum)
{
	switch(Copy_uddtBusName)
		{
		case AHB1:
			RCC_AHB1ENR &= ~(1<<Copy_u8PerNum);
			//CLR_BIT(RCC_AHB1ENR,Copy_u8PerNum);
			break;

		case AHB2:
			RCC_AHB2ENR &= ~(1<<Copy_u8PerNum);
			//CLR_BIT(RCC_AHB2ENR,Copy_u8PerNum);
			break;

		case APB1:
			RCC_APB1ENR &= ~(1<<Copy_u8PerNum);
			//CLR_BIT(RCC_APB1ENR,Copy_u8PerNum);
			break;

		case APB2:
			RCC_APB1ENR &= ~(1<<Copy_u8PerNum);
			//CLR_BIT(RCC_APB2ENR,Copy_u8PerNum);
			break;

		default:
		//#error "error in RCC Bus Name"
			break;
		}

}

void RCC_voidResetPeripheral(BusName_t Copy_uddtBusName, u8  Copy_u8PerNum)
{

	switch(Copy_uddtBusName)
		{
		case AHB1:
			RCC_AHB1RSTR |= (1<<Copy_u8PerNum);
			//SET_BIT(RCC_AHB1ENR,Copy_u8PerNum);
			break;

		case AHB2:
			RCC_AHB2RSTR |= (1<<Copy_u8PerNum);
			//SET_BIT(RCC_AHB2ENR,Copy_u8PerNum);
			break;

		case APB1:
			RCC_APB1RSTR |= (1<<Copy_u8PerNum);
			//SET_BIT(RCC_APB1ENR,Copy_u8PerNum);
			break;

		case APB2:
			RCC_APB2RSTR |= (1<<Copy_u8PerNum);
			//SET_BIT(RCC_APB2ENR,Copy_u8PerNum);
			break;

		default:
		//#error "error in RCC Bus Name"
			break;
		}

}

void RCC_voidEnableSecuritySystem(void)
{
	SET_BIT(RCC_CR,RCC_CR_CSSON);
}


void RCC_voidDisableSecuritySystem(void)
{
	CLR_BIT(RCC_CR,RCC_CR_CSSON);
}

