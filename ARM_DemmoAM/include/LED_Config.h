/*==================================================
 * Author:	Bishoy Unan		
 * Date:	17/2/2024		
 * Version:	v1.0.0		
 * description: STM32F401CC LED Driver Using 
 * Specs:		
 * 01: LED_enumErrorState LED_enumdInit(void);						
 * 02: LED_enumErrorState LED_enuSetLedState(u8 Copy_u8LedName , u8 Copy_u8State); 
 *====================================================*/


#ifndef LED_CFG_H
#define LED_CFG_H

#include "STD_TYPES.h"


/**
*@ Leds names defined by user
*/
typedef enum
{
	LED_GREEN      ,
	LED_YELLOW     ,
	LED_RED        ,
	LED_BLUE	   ,
	LED_ORANGE     ,
	
	
	
	_NUM_OF_LEDs
	
}LEDs_t;






#endif
