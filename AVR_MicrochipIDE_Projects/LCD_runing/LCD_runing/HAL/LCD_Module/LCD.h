/*
 * LCD.h
 *
 *  Created on: Sep 16, 2019
 *      Author: BISHOY
 */

#ifndef HAL_LCD_MODULE_LCD_H_
#define HAL_LCD_MODULE_LCD_H_

#define FONT_5X10		0
#define FONT_5X8		1

#define ONE_LINE		0
#define TWO_LINES		1

#define _4BIT_DATA		0
#define _8BIT_DATA		1

#define MOVE_RIGHT		1
#define MOVE_LEFT		0

#define SHIFT_LEFT		0
#define SHIFT_RIGHT		1

#define ON_DISPLAY      1
#define OFF_DISPLAY     0

#define ON_CURSOR       1
#define OFF_CURSOR      0

#define ON_BLINK        1
#define OFF_BLINK       0

#define CURSOR_RIGHT    0
#define CURSOR_LEFT     1



extern void LCD_VidInit(void);
extern void LCD_VidDisplayChar(u8 ch);
extern void LCD_VidShiftLeft(u8 shift_num);
extern void LCD_VidShiftRight(u8 shift_num);
extern void LCD_VidSendCommand(u8 ch);
extern void LCD_VidClearScreen(void);
extern void LCD_VidDisplayString(const u8 *str);
extern void LCD_VidGoToRowCol(u8 row ,u8 col);
extern void LCD_CustomAlphChar(u8 location, u8 *ptr);
extern void LCD_VidClear(void);
extern void LCD_VidDisplayInt(s32 n);
extern void LCD_VidDisplay_OFF(void);
extern void LCD_VidDisplay_ON(void);





/*Notes
 * pass to LCD_vidCreatCustomPattern the pattern in array
 * for example: 	 u8 pattern1[]={0b00010101,
			 	 	 	 	 	 	 0b00010101,
			 	 	 	 	 	 	 0b00010101,
			 	 	 	 	 	 	 0b00010101,
			 	 	 	 	 	 	 0b00010101,
			 	 	 	 	 	 	 0b00010101,
			 	 	 	 	 	 	 0b00010101,
				 	 	 	 	 	 0b00010101};
 *draw your pattern in the least significant 5 bits
 * and pass the position of that pattern starting from 0 to 7
 *
 * to display your custom pattern use LCD_vidWriteChar(//ptrn number)
 * with your pattern number starting from 1 to 8
 *
 * */




#endif /* HAL_LCD_MODULE_LCD_H_ */
