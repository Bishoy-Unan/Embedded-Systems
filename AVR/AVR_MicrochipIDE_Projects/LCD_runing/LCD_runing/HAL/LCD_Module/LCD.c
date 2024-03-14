/*
 * LCD.c
 *
 *  Created on: Sep 16, 2019
 *      Author: BISHOY
 */

#include"../../std_types.h"  //contain data types to be more readable
#include"../../macros.h"    //contain some fundamental expression
#include"../../MCAL/DIO_Module/DIO.h" // contain all prototypes of the followed functions
#include"LCD_Config.h"       //for module configuration
#include "LCD.h"             //for function prototype
#define F_CPU	8000000UL    //clock of our system
#include <util/delay.h>      //delay functions
#include<string.h>
#include<stdlib.h>

static void LOC_VidSendInstruction(u8 Ins);  // function local prototype

/*instructions from data sheet for  LCD initialization   */
#define	FUNCTION_SET	        (0b00100000|(LCD_FONT<<2)|(LINE_NUM<<3)| (DATA_NUM<<4))
#define DISPLAY_ON_OFF_COTROL   (0b00001000|(DISPLAY<<2)|(CURSOR<<1)|(BLINK<<0))
#define DISPLAY_CLEAR   0x01
#define ENTRY_MODE_SET          (0b00000100|(CURSOR_MOVE<<1))
#define DISPLAY_SHIFT_LEFT      0x18
#define DISPLAY_SHIFT_RIGHT     0x1c
#define CURSOR_SHIFT_LEFT       0x10
#define CURSOR_SHIFT_RIGHT      0x14
#define SET_CGRAMADRESS 0x48
#define DDRAM_ADDRESS	0b10000000

extern void LCD_VidDisplay_OFF(void)
{
	/*cursor off , screen display off ,Blink off */
		LOC_VidSendInstruction(0b00001000);
}

extern void LCD_VidDisplay_ON(void)
{
	/*cursor off , screen display on ,Blink off */
		LOC_VidSendInstruction(0b00001100);
}

extern void LCD_VidInit(void)
{
	/* here we define data pins as o/p in PORTD and control pins */
	DIO_VidSetPortDir(LCD_DATAPORT,OUTPUT);
	DIO_VidSetPinDir(LCD_RWPORT,LCD_RWPIN,OUTPUT); //  Read 1 ,write 0
	DIO_VidSetPinDir(LCD_EPORT,LCD_EPIN,OUTPUT);
	DIO_VidSetPinDir(LCD_RSPORT,LCD_RSPIN,OUTPUT);

	_delay_ms(30);
	         /*2 lines 8 bit mode */
	LOC_VidSendInstruction(FUNCTION_SET);
	_delay_ms(2);
	/*cursor off , screen display on ,Blink off */
	LOC_VidSendInstruction(DISPLAY_ON_OFF_COTROL);
	_delay_ms(2);
	/*clear screen*/
	LOC_VidSendInstruction(DISPLAY_CLEAR);
	_delay_ms(2);
	/*NO shift and increment mode with 1 */
	LOC_VidSendInstruction(ENTRY_MODE_SET);
	_delay_ms(2);
}
                    /*MPU IN LCD WRITE TIMNING*/
static void LOC_VidSendInstruction(u8 Ins)
{
	/*set RW=0*/
	DIO_VidSetPinValue(LCD_RWPORT,LCD_RWPIN,LOW);
	/*set RS=0*/
	DIO_VidSetPinValue(LCD_RSPORT,LCD_RSPIN,LOW);
	_delay_us(1);
	/*Enable Rising edge*/
	DIO_VidSetPinValue(LCD_EPORT,LCD_EPIN,HIGH);
	_delay_us(1);
	/*set D0~D7*/
	DIO_VidSetPortValue(LCD_DATAPORT,Ins);
	_delay_us(1);
	/*Enable  Falling edge*/
	DIO_VidSetPinValue(LCD_EPORT,LCD_EPIN,LOW);
	_delay_us(1);
}

extern void LCD_VidDisplayChar(u8 ch)     //character in single quote
{
	/*set RW=0*/
		DIO_VidSetPinValue(LCD_RWPORT,LCD_RWPIN,LOW);
		/*set RS=1*/
		DIO_VidSetPinValue(LCD_RSPORT,LCD_RSPIN,HIGH);
		_delay_us(1);
		/*Enable Falling edge*/
		DIO_VidSetPinValue(LCD_EPORT,LCD_EPIN,HIGH);
		_delay_us(1);
		/*set D0~D7*/
		DIO_VidSetPortValue(LCD_DATAPORT,ch);
		_delay_us(1);
		/*Enable Rising edge*/
		DIO_VidSetPinValue(LCD_EPORT,LCD_EPIN,LOW);
		_delay_us(1);
}


extern void LCD_VidSendCommand(u8 ch)
{
		/*set RW=0*/
		DIO_VidSetPinValue(LCD_RWPORT,LCD_RWPIN,LOW);
		/*set RS=0*/
		DIO_VidSetPinValue(LCD_RSPORT,LCD_RSPIN,LOW);
		_delay_us(1);
		/*Enable Falling edge*/
		DIO_VidSetPinValue(LCD_EPORT,LCD_EPIN,HIGH);
		_delay_us(1);
		/*set D0~D7*/
		DIO_VidSetPortValue(LCD_DATAPORT,ch);
		_delay_us(1);
		/*Enable Rising edge*/
		DIO_VidSetPinValue(LCD_EPORT,LCD_EPIN,LOW);
		_delay_us(1);

}

extern void LCD_VidClearScreen(void)
{
  LCD_VidSendCommand(DISPLAY_CLEAR);
  _delay_ms(2);
}
extern void LCD_VidDisplayString(const u8 *str)
{
 u8 i = 0;
 while(str[i]!='\0')
 {
	LCD_VidDisplayChar(str[i]);
	i++;
 }

}
extern void LCD_VidGoToRowCol(u8 row ,u8 col)
{
  u8 adress ;
  switch(row)
  {
  case 0 :
	  adress = col;
	  break ;
  case 1 :
  	  adress = col + 0x40;
  	  break ;

  case 2 :
  	  adress = col + 0x10;
  	  break ;
  case 3 :
  	  adress = col + 0x50;
  	  break ;

  default :
         {
        	 /*invalid numbers*/
         }
  }
LOC_VidSendInstruction(adress|0x80);
}

extern void LCD_VidShiftLeft(u8 shift_num)
{
	u8 i ;
 for(i=0 ; i<shift_num ;i++)
 {
  LCD_VidSendCommand(DISPLAY_SHIFT_LEFT);
  _delay_ms(500);
 }
}

extern void LCD_VidShiftRight(u8 shift_num)
{
	for(u8 i=0;i <shift_num;i++)
	{
      LCD_VidSendCommand(DISPLAY_SHIFT_RIGHT);
      _delay_ms(500);
	}
}

//Input:
	//     location: location where we want to store
	//               0,1,2,....7
	//     ptr: Pointer to pattern data
	//
	//Usage:
	//     pattern[8]={0x04,0x0E,0x0E,0x0E,0x1F,0x00,0x04,0x00};
	//     LCD_CustomAlphChar(1,pattern);
extern void LCD_CustomAlphChar(u8 location, u8 *ptr)
{
	      u8 i;
	      if(location<8)
	      {
	    	  LCD_VidSendCommand(0x40+(location*8));
	          for(i=0;i<8;i++)
	        	  LCD_VidDisplayChar(ptr[ i ]);
	      }
}


extern void LCD_VidClear(void)
{

	//LOC_vidSendInstruction(DISPLAY_CLEAR);
	u8 i;
	LCD_VidGoToRowCol(1,0);
	for(i=0;i<16;i++)
		LCD_VidDisplayChar(' ');
	LCD_VidGoToRowCol(2,0);
	for(i=0;i<16;i++)
		LCD_VidDisplayChar(' ');

	LCD_VidGoToRowCol(1,0);
}

extern void LCD_VidDisplayInt(s32 n)
{
	char str[20];
    s32 i, i_rev, j, temp, sign;

    /*int to ascii*/
    if ((sign = n) < 0)
    	{
    	  n = -1*n ;
    	}
    i = 0;
    do {
        str[i++] = n % 10 + '0';
    } while ((n /= 10) > 0);

    if (sign < 0) str[i++] = '-';
    str[i] = '\0';

    /*reverse string*/
    for (i_rev = 0, j = i-1; i_rev < j; i_rev++, j--) {
        temp = str[i_rev];
        str[i_rev] = str[j];
        str[j] = temp;
    }
	LCD_VidDisplayString(str);
}





