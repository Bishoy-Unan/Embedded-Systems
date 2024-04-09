/****************************************************************************
 * Author:	Bishoy Unan		
 * Date:	22/3/2024		
 * Version:	v1.0.0		
 * description: LCD 16*2 Driver using STMF401CC Black pill
 * Specs:		
 * 01: LCD_enuErrorStatus_t LCD_init(void);
 * 02: LCD_enuErrorStatus_t LCD_enuWriteData(u8 Copy_u8Data);
 * 03: LCD_enuErrorStatus_t LCD_enuWriteCommand(u8 Copy_u8Command);
 * 04: LCD_enuErrorStatus_t LCD_enuGotoDDRAM_XY(u8 Copy_u8X, u8 Copy_u8Y);
 * 05: LCD_enuErrorStatus_t LCD_enuWriteNumber(s32 Copy_u8Number);
 * 06: LCD_enuErrorStatus_t LCD_enuWriteString(char* Copy_pchPattern, u8 Copy_u8Length);
 * 07: LCD_enuErrorStatus_t LCD_enuDisplaySpecialPattern(u8* Copy_pu8Pattern, u8 Copy_u8CGRAMBlockNumber, u8 Copy_u8X, u8 Copy_u8Y);
 *
 ********************************************************************************/




#ifndef LCD_CONFIG_H
#define LCD_CONFIG_H

#include "STD_TYPES.h"


/**
*@ here you need to configre DATA_LENGTH you have two options
*@ 1- EIGHT_BITS_MODE
*@ 2- FOUR_BITS_MODE
*/
#define DATA_LENGTH		EIGHT_BITS_MODE



/**
*@ here you need to configre INCREMENT_DECREMENT_MODE you have two options
*@ 1- INCREMENT
*@ 2- DECREMENT
*/
#define INCREMENT_DECREMENT_MODE	INCREMENT
/**
*@ here you need to configure SHIFTING_MODE you have two options
*@ 1- DISPLAY_SHIFTING_ON
*@ 2- DISPLAY_SHIFTING_OFF
*/
#define SHIFTING_MODE				DISPLAY_SHIFTING_ON
/**
*@ here you need to configure ENTIRE_DISPLAY_MODE you have two options
*@ 1- DISPLAY_ON
*@ 2- DISPLAY_OFF
*/
#define ENTIRE_DISPLAY_MODE			DISPLAY_ON
/**
*@ here you need to configure CURSOR_MODE you have two options
*@ 1- CURSOR_ON
*@ 2- CURSOR_OFF
*/
#define CURSOR_MODE					CURSOR_OFF	
/**
*@ here you need to configure CURSOR_BLNKING_MODE you have two options
*@ 1- BLINKING_ON
*@ 2- BLINKING_OFF
*/
#define CURSOR_BLNKING_MODE			BLINKING_OFF
/**
*@ Moves cursor and shifts display without changing DDRAM contents
*@ CURSOR_SHIFT_OFF & ENTIRE_DISPLAY_SHIFT_OFF : 
*@                       Shifts cursor position to the left (AC is decreased by 1)
*@ CURSOR_SHIFT_OFF & ENTIRE_DISPLAY_SHIFT_ON : 
*@						 Shifts cursor position to the right (AC is increased by 1)
*@ CURSOR_SHIFT_ON & ENTIRE_DISPLAY_SHIFT_OFF : 
*@						 Shifts the entire display to the left, cursor follows the display shift
*@ CURSOR_SHIFT_ON & ENTIRE_DISPLAY_SHIFT_ON : 
*@						 Shifts the entire display to the right, cursor follows the display shift
*/ 		
#define CURSOR_SHIFT_MODE				CURSOR_SHIFT_OFF
#define ENTIRE_DISPLAY_SHIFT_MODE		ENTIRE_DISPLAY_SHIFT_OFF

/**
*@ here you need to configure DISPLAY_LINES_NUM you have two options
*@ 1- TWO_LINES
*@ 2- ONE_LINE
*/
#define DISPLAY_LINES_NUM	TWO_LINES
/**
*@ here you need to configure DISPLAY_FONT_TYPE you have two options
*@ 1- FONT_5X8
*@ 2- FONT_5X10
*/
#define DISPLAY_FONT_TYPE	FONT_5X8





#endif