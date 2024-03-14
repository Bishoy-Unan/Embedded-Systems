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

extern LED_strCFG_t LEDS[NumOfLeds];

/**
 *@brief  : Function to Configure the  LEDS Pins to be active high or active low .
 *@param  : Address to struct in which i configure port num and pin num and pin configration.
 *@return : Error State                                               
 */
LED_enumErrorState LED_enumdInit(void)
{
	LED_enumErrorState LOCAL_enumReturnStatus = LED_enumOK ;
	
	u8 LOCAL_u8Iterator = 0 ;
	
	PPRT_strCFG_t LOCAL_strCurrentLed[NumOfLeds];

	for( LOCAL_u8Iterator = 0 ; LOCAL_u8Iterator < NumOfLeds ; LOCAL_u8Iterator++)
	{
		LOCAL_strCurrentLed[LOCAL_u8Iterator].PORT_strPORT = LEDS[LOCAL_u8Iterator].LED_strPORT ;
		
		LOCAL_strCurrentLed[LOCAL_u8Iterator].PORT_strPIN = LEDS[LOCAL_u8Iterator].LED_strPIN ;
		
		switch(LEDS[LOCAL_u8Iterator].LED_strSTATE){
										case LED_enumActiveHigh_ON:
												LOCAL_strCurrentLed[LOCAL_u8Iterator].PORT_strCFGType = DIO_enumOUTPUTHIGH ;		
										break;
										case LED_enumActiveHigh_OFF:
												LOCAL_strCurrentLed[LOCAL_u8Iterator].PORT_strCFGType = DIO_enumOUTPUTLOW ;			
										break;
										case LED_enumActiveLow_ON:
												LOCAL_strCurrentLed[LOCAL_u8Iterator].PORT_strCFGType = DIO_enumOUTPUTLOW ;
										break;
										case LED_enumActiveLOw_OFF:
												LOCAL_strCurrentLed[LOCAL_u8Iterator].PORT_strCFGType = DIO_enumOUTPUTHIGH ;
										break;
										default:
										break;
									}//switch1
		
		
	/**
	*@ call DIO_enumSetCFG function to set configration in DIO Driver
	*@ and check return of DIO_enumSetCFG function ok or not ok
	*/		
		 DIO_enumSetCFG( & LOCAL_strCurrentLed [LOCAL_u8Iterator] );
			
		if( ! (DIO_enumSetCFG( & LOCAL_strCurrentLed [LOCAL_u8Iterator] ))){
			LOCAL_enumReturnStatus = LED_enumOK ;
		}/*if*/
		else {
			LOCAL_enumReturnStatus = LED_enumNOK ;
		}/*else*/
			
	}/*for*/
	

return LOCAL_enumReturnStatus ;
	
	
}/*led init function */


/**
 *@brief  : Function to set led state .
 *@param  : take led name and led state .
 *@return : Error State                                               
 */

LED_enumErrorState LED_enuSetLedState(u8 Copy_u8LedName , u8 Copy_u8State)
{
	/**
	*@ return variable
	*/
	LED_enumErrorState LOCAL_enumReturnStatus = LED_enumOK ;
	/*
	*@ local variable to be passed to DIO_enumSetCFG() function
	*/
	PPRT_strCFG_t LOCAL_strCurrentLed;
	/**
	*@ reconfigure led state which is element of array of leds
	*/
	LEDS[Copy_u8LedName].LED_strSTATE = Copy_u8State ;
	
	LOCAL_strCurrentLed.PORT_strPORT = LEDS[Copy_u8LedName].LED_strPORT ;
	
	LOCAL_strCurrentLed.PORT_strPIN = LEDS[Copy_u8LedName].LED_strPIN ;
	
	switch(LEDS[Copy_u8LedName].LED_strSTATE){
		
		case LED_enumActiveHigh_ON:
	    LOCAL_strCurrentLed.PORT_strCFGType = DIO_enumOUTPUTHIGH ;
		break;
		case LED_enumActiveHigh_OFF:
		LOCAL_strCurrentLed.PORT_strCFGType = DIO_enumOUTPUTLOW ;
		break;
		case LED_enumActiveLow_ON:
		LOCAL_strCurrentLed.PORT_strCFGType = DIO_enumOUTPUTLOW ;
		break;
		case LED_enumActiveLOw_OFF:
		LOCAL_strCurrentLed.PORT_strCFGType = DIO_enumOUTPUTHIGH ;
		break;
		default:
		break;
	}//switch1
	
	/**
	*@ call DIO_enumSetCFG function to set configration in DIO Driver
	*@ and check return of DIO_enumSetCFG function ok or not ok
	*/		
		 DIO_enumSetCFG( & LOCAL_strCurrentLed );
			
		if( ! (DIO_enumSetCFG( & LOCAL_strCurrentLed  )))
		{
			LOCAL_enumReturnStatus = LED_enumOK ;
		}/*if*/
		else {
			LOCAL_enumReturnStatus = LED_enumNOK ;
		}/*else*/
	
	
return LOCAL_enumReturnStatus ;	
	
}/*LED_enuSetLedState*/