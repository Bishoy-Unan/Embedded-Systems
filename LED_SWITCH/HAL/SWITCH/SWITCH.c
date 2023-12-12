/*########################################################*/
/* Author:	Bishoy Unan		*/
/* Date:	9/12/2023		*/
/* Version:	v1.0.0		*/
/* description: SWITCH Driver Using DIO V04*/
/* Specs:		*/
/* 01: SWITCH_enumErrorState SWITCH_enumdInit(void);*/
/*####################################################*/


#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "SWITCH.h"
#include "SWITCH_Config.h"
#include "../../MCAL/DIO_04/DIO.h"

extern SWITCH_strCFG_t SWITCHS[NumOfLSWITCHES];

/**
 *@brief  : Function to Configure the  SWITCHS Pins to be INPUT pull up or input external pull down resistor .
 *@param  : Address to struct in which i configure port num and pin num and pin configration.
 *@return : Error State                                               
 */
SWITCH_enumErrorState SWITCH_enumdInit(void)
{
	SWITCH_enumErrorState LOCAL_enumReturnStatus = SWITCH_enumOK ;
	
	u8 LOCAL_u8Iterator = 0 ;
	
	PPRT_strCFG_t LOCAL_strCurrentSWITCH[NumOfLSWITCHES];

	for( LOCAL_u8Iterator = 0 ; LOCAL_u8Iterator < NumOfLSWITCHES ; LOCAL_u8Iterator++)
	{
		LOCAL_strCurrentSWITCH[LOCAL_u8Iterator].PORT_strPORT = SWITCHS[LOCAL_u8Iterator].SWITCH_strPORT ;
		
		LOCAL_strCurrentSWITCH[LOCAL_u8Iterator].PORT_strPIN = SWITCHS[LOCAL_u8Iterator].SWITCH_strPIN ;
		
		switch(SWITCHS[LOCAL_u8Iterator].SWITCH_strSTATE){
										case SWITCH_enumINPUT_PULLUP:
												LOCAL_strCurrentSWITCH[LOCAL_u8Iterator].PORT_strCFGType = DIO_enumInputPullUp ;		
										break;
										case SWITCH_enumINPUT_EXTERNALPULLDOWN:
												LOCAL_strCurrentSWITCH[LOCAL_u8Iterator].PORT_strCFGType = DIO_enumInputExternalPullDown  ;			
										break;
										
										default:
										break;
									}//switch1
		
		
	/**
	*@ call DIO_enumSetCFG function to set configration in DIO Driver
	*@ and check return of DIO_enumSetCFG function ok or not ok
	*/		
		 DIO_enumSetCFG( & LOCAL_strCurrentSWITCH [LOCAL_u8Iterator] );
			
		if( ! (DIO_enumSetCFG( & LOCAL_strCurrentSWITCH [LOCAL_u8Iterator] )) ){
			LOCAL_enumReturnStatus = SWITCH_enumOK ;
		}/*if*/
		else {
			LOCAL_enumReturnStatus = SWITCH_enumNOK ;
		}/*else*/
			
	}/*for*/
	

return LOCAL_enumReturnStatus ;
	
	
}/*led init function */


