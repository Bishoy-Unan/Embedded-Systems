/*==================================================
 * Author:	Bishoy Unan		
 * Date:	17/2/2024		
 * Version:	v1.0.0		
 * description: STM32F401CC LED Driver Using 
 * Specs:		
 * 01: LED_enumErrorState LED_enumdInit(void);						
 * 02: LED_enumErrorState LED_enuSetLedState(u8 Copy_u8LedName , u8 Copy_u8State); 
 *====================================================*/


#ifndef LED_H
#define LED_H


#include "STD_TYPES.h"

#define LED_CONNECTION_FORWARD	0 
#define LED_CONNECTION_REVERSE	1
#define LED_STATE_ON			1
#define LED_STATE_OFF			0
 




typedef enum
{
  LED_enumOK ,
  LED_enumNOK	
}LED_enumErrorState;





/**
*@ struct by which we configure ports and pins numbers and pins configrations
*/

typedef struct{

	/**
	*@	DIO_enumPorts_t data type created in DIO.h to configure the port number
	*/
	void * LED_PORT;
	/**
	*@	DIO_enumPins_t data type created in DIO.h to configure the pins number
	*/
	u16 LED_PIN;
	
	u8 LED_Connection ;
	/**
	*@ LED_enumSTATE_t data type created in LED_Config.h to configure the led state
	*/
	u8 LED_STATE ;
	
	
	
}LED_strCFG_t;




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