/*########################################################*/
/* Author:	Bishoy Unan		*/
/* Date:	9/12/2023		*/
/* Version:	v1.0.0		*/
/* description: LED Driver Using DIO V04*/
/* Specs:		*/
/* 01: LED_enumErrorState LED_enumdInit(void);		*/
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








#endif