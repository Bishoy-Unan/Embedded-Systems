/****************************************************************************
 * Author:	Bishoy Unan		
 * Date:	1/1/2024		
 * Version:	v1.0.0		
 * description: LCD 16*2 Driver Using DIO V04
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



#ifndef LCD_H
#define LCD_H

/**
*@ LCD Error status
*/
typedef enum
{
	LCD_enuOK	,
	LCD_enuNOK	
}LCD_enuErrorStatus_t;


LCD_enuErrorStatus_t LCD_init(void);

LCD_enuErrorStatus_t LCD_enuWriteCharacter(u8 Copy_u8Data);

LCD_enuErrorStatus_t LCD_enuWriteCommand(u8 Copy_u8Command);

LCD_enuErrorStatus_t LCD_enuGotoDDRAM_XY(u8 Copy_u8X, u8 Copy_u8Y);

LCD_enuErrorStatus_t LCD_enuWriteNumber(s32 Copy_u8Number);

LCD_enuErrorStatus_t LCD_enuWriteString(u8 * Copy_pchPattern);

LCD_enuErrorStatus_t LCD_enuDisplaySpecialPattern(u8* Copy_pu8Pattern, u8 Copy_u8CGRAMBlockNumber, u8 Copy_u8X, u8 Copy_u8Y);

LCD_enuErrorStatus_t LCD_voidFunctionSet(void);

LCD_enuErrorStatus_t LCD_VidDisplay_OFF(void);

LCD_enuErrorStatus_t LCD_VidDisplay_ON(void);

LCD_enuErrorStatus_t LCD_VidClearScreen(void);

LCD_enuErrorStatus_t LCD_VidShiftLeft(u8 Copy_u8ShiftNum);

LCD_enuErrorStatus_t LCD_VidShiftRight(u8 Copy_u8ShiftNum);


#endif