/*####################################################*/
/* Author:	Bishoy Unan		                          */
/* Date:	9/12/2023		                          */
/* Version:	v1.0.0									  */
/* description: SWITCH Driver Using DIO V04			  */
/* Specs:											  */
/* 01: SWITCH_enumErrorState SWITCH_enumdInit(void)	  */
/* SWITCH_enumErrorState SWITCH_enuGetSwitchState(u8 Copy_strSwitchPort , u8 * Add_u8State) */
/*####################################################*/


#ifndef SWITCH_CFG_H
#define SWITCH_CFG_H

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO_04/DIO.h"


#define NumOfLSWITCHES 	3

#define SWITCH1		0
#define SWITCH2		1
#define SWITCH3		2

#define Pressed   0
#define unPressed 1


typedef enum
{
	SWITCH_enumINPUT_PULLUP ,
	
	SWITCH_enumINPUT_EXTERNALPULLDOWN 
	
}SWITCH_enumSTATE_t;




/**
*@ struct by which we configure ports and pins numbers and pins configrations
*/

typedef struct{

	/**
	*@	DIO_enumPorts_t data type created in DIO.h to configure the port number
	*/
		DIO_enumPorts_t SWITCH_strPORT;
	/**
	*@	DIO_enumPins_t data type created in DIO.h to configure the pins number
	*/
		DIO_enumPins_t SWITCH_strPIN;
	/**
	*@ LED_enumSTATE_t data type created in SWITCH_Config.h to configure the led state
	*/	
		SWITCH_enumSTATE_t SWITCH_strSTATE ;
		
}SWITCH_strCFG_t;





#endif