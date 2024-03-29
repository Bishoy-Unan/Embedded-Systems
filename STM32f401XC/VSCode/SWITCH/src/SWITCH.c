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
#include "SWITCH.h"
#include"SWITCH_Config.h"
#include "GPIO_Interface.h"

extern const SWITCH_strCFG_t SWITCHS[_NUM_OF_SWITHs];

/**
 *@brief  : Function to Configure the  SWITCHS Pins to be INPUT pull up or input external pull down resistor .
 *@param  : Address to struct in which i configure port num and pin num and pin configration.
 *@return : Error State                                               
 */
SWITCH_enumErrorState SWITCH_enumdInit(void)
{
	SWITCH_enumErrorState LOCAL_enumReturnStatus = SWITCH_enumOK ;
	
	u8 LOCAL_u8Iterator = 0 ;
	
	GPIO_strPinConfg_t LOCAL_strCurrentSWITCH;

	for( LOCAL_u8Iterator = 0 ; LOCAL_u8Iterator < _NUM_OF_SWITHs ; LOCAL_u8Iterator++)
	{
		LOCAL_strCurrentSWITCH.GPIOPort = (GPIOx_t*)SWITCHS[LOCAL_u8Iterator].SWITCH_strPORT ;
		
		LOCAL_strCurrentSWITCH.GPIOPin  = SWITCHS[LOCAL_u8Iterator].SWITCH_strPIN ;
		
		/*to pass validation in GPIO module only, this configration has n meaning*/
		LOCAL_strCurrentSWITCH.GPIOSpeed =0;

		switch(SWITCHS[LOCAL_u8Iterator].SWITCH_strSTATE){
										case SWITCH_enumINPUT_PULLUP:
												LOCAL_strCurrentSWITCH.GPIOMode = GPIO_MODE_INPUT_PU ;		
										break;
										case SWITCH_enumINPUT_EXTERNALPULLDOWN:
												LOCAL_strCurrentSWITCH.GPIOMode = GPIO_MODE_INPUT_PD  ;			
										break;
										
										default:
										break;
									}//switch1
		
		
	/**
	*@ call DIO_enumSetCFG function to set configration in DIO Driver
	*@ and check return of DIO_enumSetCFG function ok or not ok
	*/		
		 GPIO_enuInit( & LOCAL_strCurrentSWITCH  );
			
	}/*for*/
	
return LOCAL_enumReturnStatus ;
}/*led init function */



/**
 *@brief  : Function to get switch state .
 *@param  : switch number and variable in which return switch state.
 *@return : Error State                                               
 */	
SWITCH_enumErrorState SWITCH_enuGetSwitchState(u8 Copy_strSwitNUM , u8 * Add_u8State)
{
SWITCH_enumErrorState LOCAL_enumReturnStatus = SWITCH_enumOK ;
if(Add_u8State == NULL)
{
	 LOCAL_enumReturnStatus = SWITCH_enumNOK ;
}
else if( ! (GPIO_enuGetPinValue( (GPIOx_t*)SWITCHS[Copy_strSwitNUM].SWITCH_strPORT , SWITCHS[Copy_strSwitNUM].SWITCH_strPIN  , Add_u8State)) )
	{
		 LOCAL_enumReturnStatus = SWITCH_enumOK ;
	}
else
	{
		 LOCAL_enumReturnStatus = SWITCH_enumNOK ;
	}	
	
	
return LOCAL_enumReturnStatus ;	
	
}/* SWITCH_enuGetSwitchState function*/
