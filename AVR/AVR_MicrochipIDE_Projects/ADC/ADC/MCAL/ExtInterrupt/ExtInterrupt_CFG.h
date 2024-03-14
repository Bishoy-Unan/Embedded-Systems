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



#ifndef ExtInterrupt_CFG_H
#define ExtInterrupt_CFG_H

/**
*@ you need to enable or disable external interrupt 0. you have two options only
*@ 1-ENABLE  
*@ 2-DISABLE 
*@ otherwise it will be error
*@ you need to configure which type of trigring you want for ext int0 choose from 4 options
*@ 1- The_low_level
*@ 2- Any_logical_change
*@ 3- The_falling_edge
*@ 4- The_rising_edge
*@ otherwise it will be error
*/
#define EXT_INT0_ENABLING 					ENABLE
#define EXT_INT0_Triggring_Type				The_falling_edge
/**
*@ you need to enable or disable external interrupt 1 you have two options only
*@ 1-ENABLE  
*@ 2-DISABLE 
*@ otherwise it will be error
*@ you need to configure which type of trigring you want for ext int1 choose from 4 options
*@ 1- The_low_level
*@ 2- Any_logical_change
*@ 3- The_falling_edge
*@ 4- The_rising_edge
*@ otherwise it will be error
*/
#define EXT_INT1_ENABLING 					ENABLE
#define EXT_INT1_Triggring_Type				The_falling_edge
/**
*@ please note external interrupt2 is Asynchronous
*@ you need to enable or disable external interrupt 2 you have two options only
*@ 1-ENABLE  
*@ 2-DISABLE 
*@ otherwise it will be error
*@ you need to configure which type of trigring you want for ext int2 choose from 2 options
*@ 1- The_falling_edge
*@ 2- The_rising_edge
*@ otherwise it will be error
*/
#define EXT_INT2_ENABLING 					DISABLE
#define EXT_INT2_Triggring_Type				The_rising_edge








#endif
