/*###############################################################################################################################################*/
/* Author:	Bishoy Unan	 	   												   */
/* Date:	9/12/2023						            						       */
/* Version:	v1.0.4									 							     */
/* description: ATMwga32 DIO Driver							    			   				   */
/* Specs: 									      							   */
/* 01: DIO_enumError_t DIO_enumError_t DIO_enumSetCFG( PPRT_strCFG_t * ADD_strPORT_CFG )		*/
/* 02: DIO_enumError_t DIO_enumSetPortConfig(DIO_enumPorts_t Copy_enumPortNum , DIO_enumConfig_t Copy_enumConfig)					   */
/* 03: DIO_enumError_t DIO_enumSetPin(DIO_enumPorts_t Copy_enumPortNum , DIO_enumPins_t Copy_enumPintNum , DIO_enumLogicState_t Copy_enumLogicState) */
/* 04: DIO_enumError_t DIO_enumGetPin(DIO_enumPorts_t Copy_enumPortNum, DIO_enumPins_t Copy_enumPintNum , u8 * Pu8PinVal);				*/
/* 05: DIO_enumError_t DIO_enumSetPortVal( DIO_enumPorts_t Copy_enumPortName , DIO_enumLogicState_t Copy_eumStatus);		 						*/
/*###############################################################################################################################################*/



#ifndef MDIO_PRIVATE_H
#define MDIO_PRIVATE_H

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

//PORT A
#define DDRA		*((volatile u8 *)0x3A)
#define PORTA		*((volatile u8 *)0x3B)
#define PINA		*((volatile u8 *)0x39)
//PORT B
#define DDRB		*((volatile u8 *)0x37)
#define PORTB		*((volatile u8 *)0x38)
#define PINB		*((volatile u8 *)0x36)
//PORT C
#define DDRC		*((volatile u8 *)0x34)
#define PORTC		*((volatile u8 *)0x35)
#define PINC		*((volatile u8 *)0x33)
//PORT D
#define DDRD		*((volatile u8 *)0x31)
#define PORTD		*((volatile u8 *)0x32)
#define PIND		*((volatile u8 *)0x30)

//#define SFIOR		*((volatile u8 *)0x50)
#define PUD_Bit		2

#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7




#endif