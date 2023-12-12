/*########################################################*/
/* Author:	Bishoy Unan		*/
/* Date:	9/12/2023		*/
/* Version:	v1.0.0		*/
/* description: LED Driver Using DIO V04*/
/* Specs:		*/
/* 01: LED_enumErrorState LED_enumdInit(void)						*/
/*####################################################*/


#ifndef LED_CFG_H
#define LED_CFG_H

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO_04/DIO.h"


#define NumOfLeds 	2

#define LED1		0
#define LED2		1


typedef enum
{
	LED_enumActiveHigh_ON    ,
	LED_enumActiveHigh_OFF   ,
	LED_enumActiveLow_ON	 ,
	LED_enumActiveLOw_OFF

}LED_enumSTATE_t;


/**
*@ struct by which we configure ports and pins numbers and pins configrations
*/

typedef struct{

	/**
	*@	DIO_enumPorts_t data type created in DIO.h to configure the port number
	*/
	DIO_enumPorts_t LED_strPORT;
	/**
	*@	DIO_enumPins_t data type created in DIO.h to configure the pins number
	*/
	DIO_enumPins_t LED_strPIN;
	/**
	*@ LED_enumSTATE_t data type created in LED_Config.h to configure the led state
	*/
	LED_enumSTATE_t LED_strSTATE ;
	
}LED_strCFG_t;









#endif