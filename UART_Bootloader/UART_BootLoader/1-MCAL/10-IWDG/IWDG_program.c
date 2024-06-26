/*******************************************************************************/
/*******************************************************************************/
/***********************   GRADUATION PROJECT : (FOTA)   ***********************/
/***********************   Layer : MCAL                  ***********************/
/***********************   SWC (DRIVER):IWDG			 ***********************/
/*******************************************************************************/
/*******************************************************************************/

#include "../../6-Library/STD_TYPES.h"
#include "../../6-Library/BIT_MATH.h"

#include "IWDG_interface.h"
#include "IWDG_config.h"
#include "IWDG_private.h"
#include "IWDG_register.h"

//Reset Function
void IWDG_voidReset(u16 Copy_u16TimeoutValue)
{
	//Enabling write operations to Prescalar and Reload Registers
	IWDG->KR = IWDG_PROTECTION_KEY;
	
	//Updating Prescalar
	while (GET_BIT(IWDG->SR,IWDG_SR_PVU));	//Bit is set by hardware to indicate write operation is ongoing
	
	IWDG->PR &= IWDG_PRESCALAR_MASK;
	IWDG->PR |= IWDG_PRESCALAR_VALUE;
	
	//Reload Counter
	while (GET_BIT(IWDG->SR,IWDG_SR_RVU));	//Bit is set by hardware to indicate write operation is ongoing

	if(Copy_u16TimeoutValue<=IWDG_MAX_RELOAD_VALUE)
		IWDG->RLR = Copy_u16TimeoutValue;
	else
		IWDG->RLR = IWDG_MAX_RELOAD_VALUE;
	
	IWDG->KR = IWDG_RELOAD_KEY;
	
	//Staring Counter
	IWDG->KR = IWDG_COUNTER_KEY;
}
