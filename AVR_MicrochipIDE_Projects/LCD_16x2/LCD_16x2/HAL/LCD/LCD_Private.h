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




#ifndef LCD_PRIVATE_H
#define LCD_PRIVATE_H


/**
*@ number of LCD Pins to be configred by user at LCD_Config.c file
*/
#define LCD_PINS_NUM	11
/**
*@ index of LCD Data pins at the array which would 
*@ be configred by user at LCD_Config.c file
*/
#define DATA_BIT0		3
#define DATA_BIT1		4
#define DATA_BIT2		5
#define DATA_BIT3		6
#define DATA_BIT4		7
#define DATA_BIT5		8
#define DATA_BIT6		9
#define DATA_BIT7		10
/**
*@ index of LCD E pin at the array which would 
*@ be configred by user at LCD_Config.c file
*/
#define ENABLE			0

/**
*@ index of LCD R/W (Read Write) pin at the array which would 
*@ be configred by user at LCD_Config.c file
*/
#define READ_WRITE				1
/**
*@ index of LCD R/S (register select) pin at the array which would 
*@ be configred by user at LCD_Config.c file
*@ choose between instruction register or data register
*/
#define REG_SEL				2

/**
*@ the operation mode it may be one of two modes (Data Length)
*@ 4_BITS_MODE
*@ 8_BITS_MODE
*/
#define  FOUR_BITS_MODE	0
#define  EIGHT_BITS_MODE	1
/**
*@ one or two lines display
*/
#define ONE_LINE		0
#define TWO_LINES		1
/*
*@ font size : it equal 5*8 in case of 16*2 LCD
*/
#define FONT_5X10		1
#define FONT_5X8		0
/**
*@ display mode on or off
*/
#define DISPLAY_ON      1
#define DISPLAY_OFF     0
/**
*@ cursor mode on or off
*/
#define CURSOR_ON       1
#define CURSOR_OFF      0
/**
*@ cursor blinking mode on or off
*/
#define BLINKING_ON        1
#define BLINKING_OFF       0
/**
*@ Increment Decrement Mode
*/
#define	INCREMENT		1
#define DECREMENT		0
/**
*@ Display shifting Operation
*/
#define DISPLAY_SHIFTING_ON		1
#define DISPLAY_SHIFTING_OFF	0


/**
*@ to configure read or write operation
*/
#define WRITE			0
#define READ			1
/**
*@ to select instruction register or data register (write data or instruction)
*/
#define INSTRUCTION_REGISTER	0
#define DATA_REGISTER			1
/**
*@ To check the busy flag
*/
#define BUSY		1
#define NOT_BUSY	0

#define FIRST_LINE	   0
#define SECOND_LINE    1



#define CURSOR_SHIFT_ON			1
#define CURSOR_SHIFT_OFF		0

#define ENTIRE_DISPLAY_SHIFT_ON		1
#define ENTIRE_DISPLAY_SHIFT_OFF	0







#define CURSOR_RIGHT    0
#define CURSOR_LEFT     1








#endif