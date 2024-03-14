/*==================================================
 * Author:	Bishoy Unan		
 * Date:	17/2/2024		
 * Version:	v1.0.0		
 * description: STM32F401CC SWITCH Driver Using 
 * Specs:		
 * 01: SWITCH_enumErrorState SWITCH_enumdInit(void);
 * SWITCH_enumErrorState SWITCH_enuGetSwitchState(u8 Copy_strSwitchPort , u8 * Add_u8State) 
 *===================================================*/



#ifndef SWITCH_H
#define SWITCH_H


#define PRESSED   	 0
#define UNPRESSED	 1

;
typedef enum
{
  SWITCH_enumOK ,
  SWITCH_enumNOK	
  
}SWITCH_enumErrorState;



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
		void * SWITCH_strPORT;
	/**
	*@	DIO_enumPins_t data type created in DIO.h to configure the pins number
	*/
		u16 SWITCH_strPIN;
	/**
	*@ LED_enumSTATE_t data type created in SWITCH_Config.h to configure the led state
	*/	
		SWITCH_enumSTATE_t SWITCH_strSTATE ;
		
}SWITCH_strCFG_t;



/**
 *@brief  : Function to Configure the  SWITCHS Pins to be INPUT Pull up or input external pull down resistor .
 *@param  : Address to struct in which i configure port num and pin num and pin configration.
 *@return : Error State                                               
 */	
SWITCH_enumErrorState SWITCH_enumdInit(void);


/**
 *@brief  : Function to get switch state , this task used in case of using scheduler.
 *@param  : switch number and variable in which return switch state.
 *@return : Error State                                               
 */	
SWITCH_enumErrorState SWITCH_enuGetSwitchState_task(u8 Copy_strSwitchPort , u8 * Add_u8State);
/**
 *@brief  : Function to get switch state .
 *@param  : switch number and variable in which return switch state.
 *@return : Error State                                               
 */	
SWITCH_enumErrorState SWITCH_enuGetSwitchState(u8 Copy_strSwitchPort , u8 * Add_u8State);

/**
 *@ task to handle the debouncing problem 
*/
 void SWITCH_vidDebounceTask(void);




#endif
