/*==================================================
 * Author:	Bishoy Unan		
 * Date:	17/2/2024		
 * Version:	v1.0.0		
 * description: STM32F401CC SWITCH Driver Using 
 * Specs:		
 * 01: SWITCH_enumErrorState SWITCH_enumdInit(void);
 * SWITCH_enumErrorState SWITCH_enuGetSwitchState(u8 Copy_strSwitchPort , u8 * Add_u8State) 
 *=======================================================*/

#include "STD_TYPES.h"
#include "SWITCH_Config.h"
#include "SWITCH.h"
#include "GPIO_Interface.h"






	/**
	*@ araay of LED_strCFG_t data type in which we configure ports of leds and configure pins of leds and leds status
	*/
const SWITCH_strCFG_t SWITCHS[_NUM_OF_SWITHs] =  { [SWITCH1] = {.SWITCH_strPORT  = GPIOC 					  , 
																.SWITCH_strPIN   = GPIO_PIN15 				  , 
																.SWITCH_strSTATE = SWITCH_enumINPUT_PULLUP }  ,
												   [SWITCH2] = {.SWITCH_strPORT  = GPIOA 					  , 
																.SWITCH_strPIN   = GPIO_PIN14				  , 
																.SWITCH_strSTATE = SWITCH_enumINPUT_PULLUP }			
									   			 }; /* LEDS ARRAY*/
