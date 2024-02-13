/*###############################################################################################################################################*/
/* Author:	Bishoy Unan	 	   											   */
/* Date:	9/12/2023						            							       */
/* Version:	v1.0.4										 			     */
/* description: ATMwga32 DIO Driver							    						   */
/* Specs: 									      							   */
/* 01: DIO_enumError_t DIO_enumError_t DIO_enumSetCFG( PPRT_strCFG_t * ADD_strPORT_CFG )		*/
/* 02: DIO_enumError_t DIO_enumSetPortConfig(DIO_enumPorts_t Copy_enumPortNum , DIO_enumConfig_t Copy_enumConfig)		  */
/* 03: DIO_enumError_t DIO_enumSetPin(DIO_enumPorts_t Copy_enumPortNum , DIO_enumPins_t Copy_enumPintNum , DIO_enumLogicState_t Copy_enumLogicState) */
/* 04: DIO_enumError_t DIO_enumGetPin(DIO_enumPorts_t Copy_enumPortNum, DIO_enumPins_t Copy_enumPintNum , u8 * Pu8PinVal);				*/
/* 05: DIO_enumError_t DIO_enumSetPortVal( DIO_enumPorts_t Copy_enumPortName , DIO_enumLogicState_t Copy_eumStatus);		 						*/
/*###############################################################################################################################################*/



#ifndef MDIO_H
#define MDIO_H



/**
*@Include here Your Standard Types File that contains  typedef, SET,CLEAR,Toggle...etc 
*/

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"


/**
*@brief : The Error List Type                                           
*/

typedef enum {
/**
*@every thing run correctly 
*/
	DIO_enumOK ,
/**
*@there is mistake
*/
	DIO_enumNOK,
/**
*@thr port which user sent not A,B,C or D
*/
	DIO_enumINVALID_PORT,
/**
*@the pin user sent out of rangr 0:7
*/
	DIO_enumINVALID_PIN,
/**
*@the mode which user sent neither output nor input 
*/
	DIO_enumINVALID_MODE,
/**
*@the mode which user sent neither high nor low 
*/
	DIO_enumINVALID_VALUE,
	DIO_enumOUT_OF_RANGE

}DIO_enumError_t;


/**
*@brief : The ports Type of the AVR Atmega32                            
*/

typedef enum {
	
	DIO_enumPORTA,
	DIO_enumPORTB,
	DIO_enumPORTC,
	DIO_enumPORTD

	}DIO_enumPorts_t;


/**
*@brief : The Configuration Type of Pins to be Input or Output !        
*/


typedef enum {
	DIO_enumPIN0,
	DIO_enumPIN1,
	DIO_enumPIN2,
	DIO_enumPIN3,
	DIO_enumPIN4,
	DIO_enumPIN5,
	DIO_enumPIN6,
	DIO_enumPIN7
	
}DIO_enumPins_t;
	
	
typedef enum {
/**
/@the port or pin is set to be output high
*/
	
	DIO_enumOUTPUTHIGH,

/**
/@the port or pin is set to be output low
*/	DIO_enumOUTPUTLOW,
	
/**
*@the pin is set to be input and activating internal pull up resistor
*/
	DIO_enumInputPullUp,
/**
*@the pin is set to be input and disable internal pull up resistor to conect external pull down resistor
*/
	DIO_enumInputExternalPullDown ,


	
}DIO_enumConfig_t;






typedef enum{
	
/**
*@the pin set to be input with 0v
*/
	DIO_eumLOW,
/**
*@the pin is set to be high 5v
*/
	DIO_enumHIGH
	
	
}DIO_enumLogicState_t;

/**
*@i create this data type to be used in leds and switchs driver 
*/
typedef struct{
	
	DIO_enumPorts_t PORT_strPORT;
	
	DIO_enumPins_t  PORT_strPIN;
	
	DIO_enumConfig_t PORT_strCFGType;
	
	
}PPRT_strCFG_t;


/**
 *@brief  : Function to Configure the Pins to be INPUT pin or OUTPUT pin.
 *@param  : Port Number,Pin Number,Configuration type(Input/Output).
 *@return : Error State                                               
 */	
DIO_enumError_t DIO_enumSetCFG( PPRT_strCFG_t * ADD_strPORT_CFG );
/**
 *@brief  : Function to Configure the whole Port(8 pins) at one time to be INPUT or OUTPUT port.
 *@param  : Port Number,Configuration type(Input/Output).
 *@return : Error State                                                                      
 */
DIO_enumError_t DIO_enumSetPortConfig(DIO_enumPorts_t Copy_enumPortNum , DIO_enumConfig_t Copy_enumConfig);
/**
 *@brief  : Function to Set the Pins to be Logic HIGH  or Logic LOW.
 *@param  : Port Number,Pin Number,Logic State(HIGH/LOW).
 *@return : Error State                                                                      
 */
DIO_enumError_t DIO_enumSetPinVal(DIO_enumPorts_t Copy_enumPortNum , DIO_enumPins_t Copy_enumPinNum , DIO_enumLogicState_t Copy_enumLogicState);

/**
 *@brief  : Function to Read the Logic State of the Pin (Is it HIGH or LOW).
 *@param  : Port Number,Pin Number, Pointer points to unsigned char passed by address (to return the value of pin state).
 *@return : Error State                                                                     
 */
DIO_enumError_t DIO_enumGetPinVal(DIO_enumPorts_t Copy_enumPortNum, DIO_enumPins_t Copy_enumPinNum , u8 * Pu8PinVal);
/**
 *@brief : Function to Set the whole Port(8 pins) at one time to be Logic HIGH  or Logic LOW.
 *@param : Port Number,Logic State(HIGH/LOW).
 *@return: Error State.                                                                      
 */
DIO_enumError_t DIO_enumSetPortVal( DIO_enumPorts_t Copy_enumPortNum , DIO_enumLogicState_t Copy_eumStatus);








#endif