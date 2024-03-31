/****************************************************************************
 * Author:	Bishoy Unan		
 * Date:	22/3/2024		
 * Version:	v1.0.0		
 * description: LCD 16*2 Driver Driver using STMF401CC Black pill
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
 *@ two milli second for LCD task periodicity 
*/
#define LCD_TASK_PERIODICITY			2 


;
/**
*@ LCD Error status
*/
typedef enum
{
	LCD_enuOK	,
	LCD_enuNOK	
}LCD_enuErrorStatus_t;








/**
 *@ global APIs that could be used by user
*/
LCD_enuErrorStatus_t LCD_VidDisplay_OFF(void);

LCD_enuErrorStatus_t LCD_VidDisplay_ON(void);

LCD_enuErrorStatus_t LCD_VidClearScreen(void);

LCD_enuErrorStatus_t LCD_VidShiftLeft(u8 Copy_u8ShiftNum);

LCD_enuErrorStatus_t LCD_VidShiftRight(u8 Copy_u8ShiftNum);

LCD_enuErrorStatus_t LCD_enuGotoDDRAM_XY(u8 Copy_u8X, u8 Copy_u8Y);

LCD_enuErrorStatus_t LCD_enuWriteNumber(s32 Copy_u8Number);

LCD_enuErrorStatus_t LCD_enuWriteString(u8 * Copy_pchPattern);

LCD_enuErrorStatus_t LCD_enuDisplaySpecialPattern(u8* Copy_pu8Pattern, u8 Copy_u8CGRAMBlockNumber, u8 Copy_u8X, u8 Copy_u8Y);





/**
 *@ LCD Task that would be invoked in the scheduler 
*/
void LCD_vidTask(void);

#endif