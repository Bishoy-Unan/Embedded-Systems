/*########################################################*/
/* Author:	Bishoy Unan		*/
/* Date:	9/12/2023		*/
/* Version:	v1.0.0		*/
/* description: LED Driver Using DIO V04*/
/* Specs:		*/
/* 01: LED_enumErrorState LED_enumdInit(void);		*/
/* 02: LED_enumErrorState LED_enuSetLedState(u8 Copy_u8LedName , u8 Copy_u8State); */
/*####################################################*/



#ifndef LED_H
#define LED_H


#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"


typedef enum
{
  LED_enumOK ,
  LED_enumNOK	
}LED_enumErrorState;


/**
 *@brief  : Function to Configure the  LEDS Pins to be active high or active low .
 *@param  : Address to struct in which i configure port num and pin num and pin configration.
 *@return : Error State                                               
 */	
LED_enumErrorState LED_enumdInit(void);

/**
 *@brief  : Function to set led state .
 *@param  : take led name and led state .
 *@return : Error State                                               
 */

LED_enumErrorState LED_enuSetLedState(u8 Copy_u8LedName , u8 Copy_u8State);





#endif