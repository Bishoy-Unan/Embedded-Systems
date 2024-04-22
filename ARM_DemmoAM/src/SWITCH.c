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
#include "SWITCH_Config.h"
#include "GPIO_Interface.h"


extern const SWITCH_strCFG_t SWITCHS[_NUM_OF_SWITHs];
/**button released */
static u8 ButtonStatus[_NUM_OF_SWITHs] = {1};

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
		 GPIO_enuInit( & LOCAL_strCurrentSWITCH );
			
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

/**
 *@brief  : Function to get switch state .
 *@param  : switch number and variable in which return switch state.
 *@return : Error State                                               
 */	
SWITCH_enumErrorState SWITCH_enuGetSwitchState_task(u8 Copy_strSwitNUM , u8 * Add_u8State)
{
SWITCH_enumErrorState LOCAL_enumReturnStatus = SWITCH_enumOK ;
if(Add_u8State == NULL)
{
	 LOCAL_enumReturnStatus = SWITCH_enumNOK ;
}
else if (Copy_strSwitNUM >_NUM_OF_SWITHs)
{
		 LOCAL_enumReturnStatus = SWITCH_enumNOK ;
}	
else
{
	
	/**
	 *@ get the state from the array which be updated by the debouncing task
	*/
	*Add_u8State = ButtonStatus[Copy_strSwitNUM] ; 
	
}	
	
return LOCAL_enumReturnStatus ;	
	
}/* SWITCH_enuGetSwitchState function*/

/**
 *@ debouncing task that runs every 5 ms to update the status array
*/
 void SWITCH_vidDebounceTask(void){

	/* STATIC : COUNT NUMBER OF SIMILAR STATUS */
	static u8 SWITCH_u8Counter[_NUM_OF_SWITHs];

	/* STATIC : SAVE THE PREVIOUS STATUS */
	static u8 SWITCH_enuPrevValue[_NUM_OF_SWITHs];

	/* LOCAL : TO GET THE CURRENT STATUS */
	u8 Loc_enuCurrentValue[_NUM_OF_SWITHs];

	u16 Loc_u16SwitchIndex = 0;

	/* ITERATE THROUGH ALL THE SWITCHES */
	for( Loc_u16SwitchIndex=0 ; Loc_u16SwitchIndex < _NUM_OF_SWITHs ; Loc_u16SwitchIndex++ ){

		 /* GET THE VALUE OF THE SWITCH */
		 GPIO_enuGetPinValue( (GPIOx_t*)SWITCHS[Loc_u16SwitchIndex].SWITCH_strPORT , SWITCHS[Loc_u16SwitchIndex].SWITCH_strPIN  , &Loc_enuCurrentValue[Loc_u16SwitchIndex]);
		 /* 1: CURRENT VALUE IS EQUAL THE PREVIOUS ONE */
		 if(Loc_enuCurrentValue[Loc_u16SwitchIndex] == SWITCH_enuPrevValue[Loc_u16SwitchIndex]){

			 /* INCREAMENT THE COUNTER */
			 SWITCH_u8Counter[Loc_u16SwitchIndex]++;
		 }

		 /* 2:  CURRENT VALUE NOT EQUAL THE PREVIOUS ONE */
		 else{

			 /* SET THE COUNTER BY ZERO */
			 SWITCH_u8Counter[Loc_u16SwitchIndex] = 0;
		 }

		 /* at least the counter equal 5 stamps to ensure that it not debouncing */
		 if(SWITCH_u8Counter[Loc_u16SwitchIndex] == 5){

			 /* SET THE STATUS OF THE SWITCH AS A CURRENT VALUE (return value) */
			 ButtonStatus[Loc_u16SwitchIndex] = Loc_enuCurrentValue[Loc_u16SwitchIndex];

			 /* SET THE COUNTER BY ZERO */
			 SWITCH_u8Counter[Loc_u16SwitchIndex] = 0;
		 }

		 /* SET THE PREVIOUS VALUE AS A CURRENT TO GET A NEW ONE */
		 SWITCH_enuPrevValue[Loc_u16SwitchIndex] = Loc_enuCurrentValue[Loc_u16SwitchIndex];
	}

}