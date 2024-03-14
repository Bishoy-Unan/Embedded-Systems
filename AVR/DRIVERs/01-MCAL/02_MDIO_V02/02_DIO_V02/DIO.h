/*######################################################################################################################*/
/* Author:	Bishoy Unan	 	   					   					*/
/* Date:	2/12/2023									       			*/
/* Version:	v2.0.0				 			     					         */
/* description: ATMwga32 DIO Driver with pre and post build configration defined by user			          */
/* Specs: 								     						*/
/* 01: DIO_enumError_t DIO_enumInit(void);		      								  */
/* 02: DIO_enumError_t DIO_enumGetPin(DIO_enumPorts_t Copy_enumPortNum, DIO_enumPins_t Copy_enumPintNum , u8 * Pu8PinVal);*/
/* 03: DIO_enumError_t DIO_enumSetPortVal( DIO_enumPorts_t Copy_enumPortName , DIO_enumLogicState_t Copy_eumStatus);	  */
/*#######################################################################################################################*/



/**
*@ header guard to prevent recursive inclusion
*/
#ifndef MDIO_H
#define MDIO_H


/**
*@ new standard data types to avoid conflict of compilers defination of data types compiler 
*/

#include "STD_TYPES.h"
#include "BIT_MATH.h"


typedef enum {
	/*every thing run correctly */
	DIO_enumOK ,
	/*there is mistake*/
	DIO_enumNOK,
	/*thr port which user sent not A,B,C or D*/
	DIO_enumINVALID_PORT,
	/*the pin user sent out of rangr 0:7*/
	DIO_enumINVALID_PIN,
	/*the mode which user sent neither output nor input */
	DIO_enumINVALID_MODE,
	/*the mode which user sent neither high nor low */
	DIO_enumINVALID_VALUE,
	DIO_enumOUT_OF_RANGE



}DIO_enumError_t;




/**
 *@ The ports Type of the AVR Atmega32                            
 */

typedef enum {
	
	DIO_enumPORTA,
	DIO_enumPORTB,
	DIO_enumPORTC,
	DIO_enumPORTD

	}DIO_enumPorts_t;


/**
 *@ The Configuration Type of Pins to be Input or Output !        
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
	/*the port or pin is set to be output*/
	DIO_enumOUTPUT,
	/*the pin is set to be input and activating internal pull up resistor*/
	DIO_enumInputPullUp,
	/*the pin is set to be input and disable internal pull up resistor to conect external pull down resistor*/
	DIO_enumInputExternalPullDown
	
}DIO_enumConfig_t;

typedef enum{
	
	/*the pin set to be input with 0v*/
	DIO_eumLOW,
	/*the pin is set to be high 5v*/
	DIO_enumHIGH
	
	
}DIO_enumLogicState_t;





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