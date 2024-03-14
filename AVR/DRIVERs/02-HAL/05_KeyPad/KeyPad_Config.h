
/*****************************************************************
 * Author:	Bishoy Unan	 	   											  
 * Date:	8/1/2024						            							      
 * Version:	v1.0.0										 			    
 * description: KeyPad Driver Using ATMwga32 							    						
 * Specs:
 *		01-KeyPad_enumErrorState KEYPAD_enuInit(void);
 *		02-KeyPad_enumErrorState KEYPAD_enuGetPressedKey(u8 *Copy_pu8Addr); 									      							   
 ****************************************************************/



#ifndef KEY_PAD_CONFIG_H
#define KEY_PAD_CONFIG_H


#define 	NUM_OF_ROWS			4
#define 	NUM_OF_COLUMNS  	4

#define		ROW0_PIN				0
#define		ROW1_PIN				1
#define		ROW2_PIN				2
#define		ROW3_PIN				3

#define		COLUMN0_PIN				4
#define		COLUMN1_PIN				5
#define		COLUMN2_PIN				6
#define		COLUMN3_PIN				7

#include "../../LIB/STD_TYPES.h"



#endif