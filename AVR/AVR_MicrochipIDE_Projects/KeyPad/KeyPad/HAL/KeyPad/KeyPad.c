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
#include "../../LIB/BIT_MATH.h"
#include "KeyPad.h"
#include "KeyPad_Config.h"
#include "../../MCAL/DIO_04/DIO.h"
#include "../../MCAL/Delay_Function/delay_function.h"

/**
*@ array of pins intialization
*/
extern PPRT_strCFG_t KeyPad_PINS[NUM_OF_ROWS + NUM_OF_COLUMNS];
/**
*@ array of each button configration
*/
extern u8 SWITCH_Configration[NUM_OF_ROWS] [NUM_OF_COLUMNS];

/**
*@breif KEYPAD_enuInit() function to set the Rows and Columns configrations
*@param Nothing
*@return Error status
*/
KeyPad_enumErrorState KEYPAD_enuInit(void)
{
	/**
	*@ Error status for return variable
	*/
	KeyPad_enumErrorState LOCAL_enumReturnStatus = KeyPad_enumOK ;
	
	u8 Local_u8PinNo = 0 ;

	for(Local_u8PinNo = 0 ; Local_u8PinNo < (NUM_OF_ROWS + NUM_OF_COLUMNS) ; Local_u8PinNo++)
	{
		/**
		*@ Set the row and columns pins as configred in KeyPad_PINS array in KeyPad_Config.c file
		*@ using DIO_enumSetCFG() API from DIO_04 driver
		*/
		LOCAL_enumReturnStatus = DIO_enumSetCFG( & KeyPad_PINS [Local_u8PinNo] );
		/**
		*@ validate if DIO_enumSetCFG function return not ok then break
		*/
		if(LOCAL_enumReturnStatus)
		{ break;}
		
	}
	
	
  return LOCAL_enumReturnStatus ;	
}/* KEYPAD_enuInit function*/


/**
*@breif KEYPAD_enuGetPressedKey() function to get the pressed button value
*@param pointer in which return the value of the pressed button
*@return Error status
*/
KeyPad_enumErrorState KEYPAD_enuGetPressedKey(u8 *Copy_pu8Addr)
{
	
	/**
	*@ Error status for return variable
	*/
	KeyPad_enumErrorState LOCAL_enumReturnStatus = KeyPad_enumOK ;
	
	u8 Local_u8ColNo=0 , Local_u8RowNo=0 , Local_u8RetVal = 1 ;
	
	/**
	*@ validate the pointer
	*/
	if( Copy_pu8Addr == NULL)
	{
		LOCAL_enumReturnStatus = KeyPad_enumNOK ;
	
	}/*if*/
	else{
			
			*Copy_pu8Addr =	0 ;	
			/**
			*@ looping on the columns, start from 4 to 8
			*@ becouse of the columns starts from 4 index in SWITCH_Configration array
			*/
			for (Local_u8ColNo = COLUMN0_PIN ; Local_u8ColNo < (NUM_OF_ROWS + NUM_OF_COLUMNS) ; Local_u8ColNo++)
			{
				/*
				*@ Activate column
				*/
				KeyPad_PINS[Local_u8ColNo].PORT_strCFGType = DIO_enumOUTPUTLOW ;
				/**
				*@ DIO_enumSetCFG() API to set the configration
				*/
				LOCAL_enumReturnStatus = DIO_enumSetCFG( & KeyPad_PINS [Local_u8ColNo] );
				/**
				*@ loop to read the rows, which one is Low, start from zero to NUM_OF_ROWS
				*@ becouse of the rows starts from zero index in SWITCH_Configration array
				*/
				for(Local_u8RowNo = ROW0_PIN ; Local_u8RowNo < NUM_OF_ROWS ; Local_u8RowNo++)
				{
					/**
					*@ read the pin status and return the value in the Local_u8RetVal variable
					*/
					DIO_enumGetPinVal( KeyPad_PINS[Local_u8RowNo].PORT_strPORT , KeyPad_PINS[Local_u8RowNo].PORT_strPIN , &Local_u8RetVal);
					/**
					*@ wait to release the button
					*/
				
					/**
					*@ ckeck the pressed button at this row or not
					*/
					if ( Local_u8RetVal == 0)
						{
							
							/**
							*@ return the pressed button value according to the array SWITCH_Configration configuration
							*/
							 * Copy_pu8Addr = SWITCH_Configration[Local_u8RowNo][(Local_u8ColNo-NUM_OF_COLUMNS)];
							
							/*
							*@ wait to release the button
							*/
						while(Local_u8RetVal == 0)
							{
								DIO_enumGetPinVal( KeyPad_PINS[Local_u8RowNo].PORT_strPORT , KeyPad_PINS[Local_u8RowNo].PORT_strPIN , &Local_u8RetVal);			
							}
							break;/*break for of rows*/
						}/*if 1*/
					
				}/*for 2*/
				
				/*
				*@Deactivate column
				*/
				KeyPad_PINS[Local_u8ColNo].PORT_strCFGType = DIO_enumOUTPUTHIGH ;
				/**
				*@ DIO_enumSetCFG() API to set the configration
				*/
				LOCAL_enumReturnStatus = DIO_enumSetCFG( & KeyPad_PINS [Local_u8ColNo] );
				/**
				*@ check the pointer value to break columns loop in case any key is pressed
				*/
				if(*Copy_pu8Addr!=0)
				{
					break;
				}
				
			}/*for 1*/
	}/*else*/
	
	/**
	*@ return the error status value
	*/
	 return LOCAL_enumReturnStatus ;
	 
}/*KEYPAD_enuGetPressedKey function*/

