/*==================================================
 * Author:	Bishoy Unan		
 * Date:	17/2/2024		
 * Version:	v1.0.0		
 * description: STM32F401CC LED Driver Using 
 * Specs:		
 * 01: LED_enumErrorState LED_enumdInit(void);						
 * 02: LED_enumErrorState LED_enuSetLedState(u8 Copy_u8LedName , u8 Copy_u8State); 
 *====================================================*/


#include "STD_TYPES.h"
#include "LED.h"
#include "LED_Config.h"
#include "GPIO_Interface.h"

extern const LED_strCFG_t LEDS[_NUM_OF_LEDs];

/**
 *@brief  : Function to Configure the  LEDS Pins to be active high or active low .
 *@param  : Address to struct in which i configure port num and pin num and pin configration.
 *@return : Error State                                               
 */
LED_enumErrorState LED_enumdInit(void)
{
	LED_enumErrorState LOCAL_enumReturnStatus = LED_enumOK ;
	
	u8 LOCAL_u8Iterator = 0 ;
	/*PARSING VARIABLR*/
	GPIO_strPinConfg_t LOCAL_strCurrentLed;

	for( LOCAL_u8Iterator = 0 ; LOCAL_u8Iterator < _NUM_OF_LEDs ; LOCAL_u8Iterator++)
	{
		LOCAL_strCurrentLed.GPIOPort = (GPIOx_t*)LEDS[LOCAL_u8Iterator].LED_PORT ;
		
		LOCAL_strCurrentLed.GPIOPin = LEDS[LOCAL_u8Iterator].LED_PIN ;
		
		LOCAL_strCurrentLed.GPIOMode = GPIO_MODE_OUTPUT_PP ;
		
		LOCAL_strCurrentLed.GPIOSpeed = GPIO_OUTPUT_SPEED_HIGH;
				
	/**
	*@ call DIO_enumSetCFG function to set configration in DIO Driver
	*@ and check return of DIO_enumSetCFG function ok or not ok
	*/		
		GPIO_enuInit( & LOCAL_strCurrentLed  );
			
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
	u8 Local_u8LedState ; 
	/**
	*@ return variable
	*/
	LED_enumErrorState LOCAL_enumReturnStatus = LED_enumOK ;
	/*
	*@ local variable to be passed to DIO_enumSetCFG() function
	*/
	GPIO_strPinConfg_t LOCAL_strCurrentLed;
	
	LOCAL_strCurrentLed.GPIOPort = (GPIOx_t*)LEDS[Copy_u8LedName].LED_PORT ;
	
	LOCAL_strCurrentLed.GPIOPin  = LEDS[Copy_u8LedName].LED_PIN ;
	/**
	*@ reconfigure led state which is element of array of leds
	*/
	Local_u8LedState = (LEDS[Copy_u8LedName].LED_STATE  ^ Copy_u8State) ;
	
	
	
	/**
	*@ call DIO_enumSetCFG function to set configration in DIO Driver
	*@ and check return of DIO_enumSetCFG function ok or not ok
	*/		
		 LOCAL_enumReturnStatus = GPIO_enuSetPinValue(LOCAL_strCurrentLed.GPIOPort , LOCAL_strCurrentLed.GPIOPin , Local_u8LedState );

	
return LOCAL_enumReturnStatus ;	
	
}/*LED_enuSetLedState*/
