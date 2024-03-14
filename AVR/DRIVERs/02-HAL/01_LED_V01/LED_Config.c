/*########################################################*/
/* Author:	Bishoy Unan		*/
/* Date:	9/12/2023		*/
/* Version:	v1.0.0		*/
/* description: LED Driver Using DIO V04*/
/* Specs:		*/
/* 01: LED_enumErrorState LED_enumdInit(void)						*/
/* 02: LED_enumErrorState LED_enuSetLedState(u8 Copy_u8LedName , u8 Copy_u8State); */
/*####################################################*/

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "LED.h"
#include "LED_Config.h"
#include "../../MCAL/DIO_04/DIO.h"



/**
*@ araay of LED_strCFG_t data type in which we configure ports of leds and configure pins of leds and leds status
*/
LED_strCFG_t LEDS[NumOfLeds] =  { [LED1] = {.LED_strPORT = DIO_enumPORTA , 
											.LED_strPIN = DIO_enumPIN0 , 
											.LED_strSTATE = LED_enumActiveHigh_ON }  ,
								  [LED2] = {.LED_strPORT = DIO_enumPORTA , 
											.LED_strPIN = DIO_enumPIN1 , 
											.LED_strSTATE = LED_enumActiveHigh_ON }			
							    }; /* LEDS ARRAY*/