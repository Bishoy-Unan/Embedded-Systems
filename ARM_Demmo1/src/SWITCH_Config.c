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
																.SWITCH_strPIN   = GPIO_PIN1 				  , 
																.SWITCH_strSTATE = SWITCH_enumINPUT_PULLUP }  ,
												   [SWITCH2] = {.SWITCH_strPORT  = GPIOA 					  , 
																.SWITCH_strPIN   = GPIO_PIN2				  , 
																.SWITCH_strSTATE = SWITCH_enumINPUT_PULLUP }  ,		
												   [SWITCH3] = {.SWITCH_strPORT  = GPIOA 					  , 
																.SWITCH_strPIN   = GPIO_PIN3				  , 
																.SWITCH_strSTATE = SWITCH_enumINPUT_PULLUP }  ,		
												   [SWITCH4] = {.SWITCH_strPORT  = GPIOA 					  , 
																.SWITCH_strPIN   = GPIO_PIN4				  , 
																.SWITCH_strSTATE = SWITCH_enumINPUT_PULLUP }  ,		
												   [SWITCH5] = {.SWITCH_strPORT  = GPIOA 					  , 
																.SWITCH_strPIN   = GPIO_PIN5				  , 
																.SWITCH_strSTATE = SWITCH_enumINPUT_PULLUP }  ,		
												   [SWITCH6] = {.SWITCH_strPORT  = GPIOA 					  , 
																.SWITCH_strPIN   = GPIO_PIN6				  , 
																.SWITCH_strSTATE = SWITCH_enumINPUT_PULLUP }  ,		
												   [SWITCH7] = {.SWITCH_strPORT  = GPIOA 					  , 
																.SWITCH_strPIN   = GPIO_PIN7				  , 
																.SWITCH_strSTATE = SWITCH_enumINPUT_PULLUP }  ,		
												   [SWITCH8] = {.SWITCH_strPORT  = GPIOA 					  , 
																.SWITCH_strPIN   = GPIO_PIN8				  , 
																.SWITCH_strSTATE = SWITCH_enumINPUT_PULLUP }  ,		
												   [SWITCH9] = {.SWITCH_strPORT  = GPIOA 					  , 
																.SWITCH_strPIN   = GPIO_PIN9				  , 
																.SWITCH_strSTATE = SWITCH_enumINPUT_PULLUP }  ,		
												   [SWITCH10] = {.SWITCH_strPORT  = GPIOB 					  , 
																.SWITCH_strPIN   = GPIO_PIN10				  , 
																.SWITCH_strSTATE = SWITCH_enumINPUT_PULLUP }  	
									   			 }; /* LEDS ARRAY*/
