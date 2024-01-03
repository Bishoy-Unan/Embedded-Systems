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
*@ header guard to prevend recursive inclusion
*/
#ifndef MDIO_PRIVATE_H
#define MDIO_PRIVATE_H



/**
*@PORT A
*/
#define DDRA		*((volatile u8 *)0x3A)
#define PORTA		*((volatile u8 *)0x3B)
#define PINA		*((volatile u8 *)0x39)
/**
*@PORT B
*/
#define DDRB		*((volatile u8 *)0x37)
#define PORTB		*((volatile u8 *)0x38)
#define PINB		*((volatile u8 *)0x36)
/**
*@PORT C
*/
#define DDRC		*((volatile u8 *)0x34)
#define PORTC		*((volatile u8 *)0x35)
#define PINC		*((volatile u8 *)0x33)
/**
*@PORT D
*/
#define DDRD		*((volatile u8 *)0x31)
#define PORTD		*((volatile u8 *)0x32)
#define PIND		*((volatile u8 *)0x30)

#define SFIOR		*((volatile u8 *)0x50)
#define PUD_Bit		2



#define PREBUILD_MODE		1
#define POSTBUILD_MODE		2


#define LOW   0
#define HIGH  1



#define INP_PU	  1
#define INP_HIm   2
#define OUT_HIGH  3
#define OUT_lOW	  4	


/**
*@ in case of prebuild
*/
#define DIO_PORTA	1
#define DIO_PORTB	2
#define DIO_PORTC	3
#define DIO_PORTD	4








#endif