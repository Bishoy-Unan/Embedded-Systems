/*############################################################################*/
/* Author:	Bishoy Unan	 	   							*/
/* Date:	24/12/2023						       						*/
/* Version:	v0.0.0									 						 			     							*/
/* description: ATMwga32 External Interrupt Driver for Int0 and Int1 and Int2 */
/* Specs: 									      										   								*/
/* 01: void ExtInterrupt_voidInit(void);	*/
/* 02: void ExtINT_voidSetExtINT0(void(*ptr)(void));*/
/* 03: void ExtINT_voidSetExtINT1(void(*ptr)(void));  */
/* 04: void ExtINT_voidSetExtINT2(void(*ptr)(void)); */
/*########################################################*/


#ifndef ExtInterrupt_H
#define ExtInterrupt_H



/**
*@ External Interrupt Init function in which we enable and disable ExtInt0 , ExtInt1, ExtInt2
*@ and configure the trigring type
*/
void ExtInterrupt_voidInit(void);

/**
*@ function take pointer to function as input from application 
*@ and assign this variable ExtInt0_AddCallBack which used in ExtInt0 ISR 
*/
void ExtINT_voidSetExtINT0(void(*ptr)(void));

/**
*@ function take pointer to function as input from application 
*@ and assign this variable ExtInt0_AddCallBack which used in ExtInt1 ISR 
*/
void ExtINT_voidSetExtINT1(void(*ptr)(void));

/**
*@ function take pointer to function as input from application 
*@ and assign this variable ExtInt0_AddCallBack which used in ExtInt2 ISR 
*/
void ExtINT_voidSetExtINT2(void(*ptr)(void));



#endif