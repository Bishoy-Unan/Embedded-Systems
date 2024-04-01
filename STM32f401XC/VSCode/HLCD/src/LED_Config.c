/*==================================================
 * Author:	Bishoy Unan		
 * Date:	17/2/2024		
 * Version:	v1.0.0		
 * description: STM32F401CC LED Driver Using 
 * Specs:		
 * 01: LED_enumErrorState LED_enumdInit(void);						
 * 02: LED_enumErrorState LED_enuSetLedState(u8 Copy_u8LedName , u8 Copy_u8State); 
 *====================================================*/

#include "STD_TYPES.h"

#include"LED_Config.h"
#include"LED.h"
#include "GPIO_Interface.h"





/**
*@ araay of LED_strCFG_t data type in which we configure ports of leds and configure pins of leds and leds status
*/
const LED_strCFG_t LEDS[_NUM_OF_LEDs] =  { [LED_GREEN]  = {.LED_PORT          = GPIOC , 
														 .LED_PIN           = GPIO_PIN13 , 
														 .LED_Connection    = LED_CONNECTION_FORWARD , 
														 .LED_STATE 		= LED_STATE_OFF }  ,
										   [LED_YELLOW]= {.LED_PORT  		= GPIOC , 
														 .LED_PIN   		= GPIO_PIN12 , 
														 .LED_Connection   	= LED_CONNECTION_FORWARD , 
														 .LED_STATE 		= LED_STATE_OFF }	,
										   [LED_RED] = {.LED_PORT  			= GPIOC , 
														 .LED_PIN   		= GPIO_PIN11 ,   
														 .LED_Connection   	= LED_CONNECTION_FORWARD ,   
														 .LED_STATE 		= LED_STATE_OFF 	}	,
										   [LED_ORANGE] = {.LED_PORT  		= GPIOC , 
														 .LED_PIN   		= GPIO_PIN10 ,   
														 .LED_Connection   	= LED_CONNECTION_FORWARD ,   
														 .LED_STATE 		= LED_STATE_OFF 	}	,
										   [LED_BLUE] = {.LED_PORT  		= GPIOC , 
														 .LED_PIN   		= GPIO_PIN10 ,   
														 .LED_Connection   	= LED_CONNECTION_FORWARD ,   
														 .LED_STATE 		= LED_STATE_OFF 	}			 			 			
							    }; /* LEDS ARRAY*/
