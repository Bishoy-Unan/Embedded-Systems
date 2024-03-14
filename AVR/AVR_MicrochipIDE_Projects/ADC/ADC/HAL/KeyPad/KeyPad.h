/*****************************************************************
 * Author:	Bishoy Unan	 	   											  
 * Date:	8/1/2024						            							      
 * Version:	v1.0.0										 			    
 * description: KeyPad Driver Using ATMwga32 							    						
 * Specs:
 *		01-KeyPad_enumErrorState KEYPAD_enuInit(void);
 *		02-KeyPad_enumErrorState KEYPAD_enuGetPressedKey(u8 *Copy_pu8Addr); 									      							   
 ****************************************************************/




#ifndef KEY_PAD_H
#define KEY_PAD_H


/**
*@ KeyPsd Error status check
*/
typedef enum{
	
	KeyPad_enumOK   , 
	
	KeyPad_enumNOK
	
}KeyPad_enumErrorState;
/**
*@breif KEYPAD_enuInit() function to set the Rows and Columns configrations
*@param Nothing
*@return Error status
*/
KeyPad_enumErrorState KEYPAD_enuInit(void);
/**
*@breif KEYPAD_enuGetPressedKey() function to get the pressed button value
*@param pointer in which return the value of the pressed button
*@return Error status
*/
KeyPad_enumErrorState KEYPAD_enuGetPressedKey(u8 *Copy_pu8Addr);


#endif