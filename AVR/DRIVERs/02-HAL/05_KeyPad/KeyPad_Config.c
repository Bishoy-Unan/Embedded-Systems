
/*****************************************************************
 * Author:	Bishoy Unan	 	   											  
 * Date:	8/1/2024						            							      
 * Version:	v1.0.0										 			    
 * description: KeyPad Driver Using ATMwga32 							    						
 * Specs:
 *		01-KeyPad_enumErrorState KEYPAD_enuInit(void);
 *		02-KeyPad_enumErrorState KEYPAD_enuGetPressedKey(u8 *Copy_pu8Addr); 									      							   
 ****************************************************************/






#include "../../LIB/STD_TYPES.h"
#include "KeyPad_Config.h"

#include "../../MCAL/DIO_04/DIO.h"

/**
*@ array to configure the row ports and pins and ports and pins for the columns
*@ and configure which is the inputs and which is the output
*/
PPRT_strCFG_t KeyPad_PINS[NUM_OF_ROWS + NUM_OF_COLUMNS] =  {   [ROW0_PIN]    = {.PORT_strPORT = DIO_enumPORTC , 
																				.PORT_strPIN = DIO_enumPIN0 , 
																				.PORT_strCFGType = DIO_enumInputPullUp }    ,
															   [ROW1_PIN]    = {.PORT_strPORT = DIO_enumPORTC , 
																				.PORT_strPIN = DIO_enumPIN1 , 
																				.PORT_strCFGType = DIO_enumInputPullUp }	,		
															   [ROW2_PIN]    = {.PORT_strPORT = DIO_enumPORTC , 
																				.PORT_strPIN = DIO_enumPIN2 , 
																				.PORT_strCFGType = DIO_enumInputPullUp }    ,
															   [ROW3_PIN]    = {.PORT_strPORT = DIO_enumPORTC , 
																				.PORT_strPIN = DIO_enumPIN3 , 
																				.PORT_strCFGType = DIO_enumInputPullUp }	,		
															   [COLUMN0_PIN] = {.PORT_strPORT = DIO_enumPORTC , 
																				.PORT_strPIN = DIO_enumPIN4 , 
																				.PORT_strCFGType = DIO_enumOUTPUTHIGH } 	,
															   [COLUMN1_PIN] = {.PORT_strPORT = DIO_enumPORTC , 	
																				.PORT_strPIN = DIO_enumPIN5 , 	
																				.PORT_strCFGType = DIO_enumOUTPUTHIGH }		,		
															   [COLUMN2_PIN] = {.PORT_strPORT = DIO_enumPORTC , 	
																				.PORT_strPIN = DIO_enumPIN6 , 	
																				.PORT_strCFGType = DIO_enumOUTPUTHIGH } 	,
															   [COLUMN3_PIN] = {.PORT_strPORT = DIO_enumPORTC , 
																				.PORT_strPIN = DIO_enumPIN7 , 
																				.PORT_strCFGType = DIO_enumOUTPUTHIGH }			
															 }; /* KeyPad_PINS ARRAY*/
															 
/**
*@ array in which you can configure each button invidually by any configration from the assci table
*@ according to the number of rows and nmber of rows
*/															 
u8 SWITCH_Configration[NUM_OF_ROWS] [NUM_OF_COLUMNS] = {
														/**
														*@ this configuration in case of 4x4 keypad
														*@ you can configure any dimensions you want 
														*/	
						
														{'7' , '8' , '9' , '/'} ,	
																			
														{'4' , '5' , '6' , '*'} ,
														
														{'1' , '2' , '3' , '-'} ,
													  
													    {'c' , '0' , '=' , '+'}

													    }; /*SWITCH_Configration*/