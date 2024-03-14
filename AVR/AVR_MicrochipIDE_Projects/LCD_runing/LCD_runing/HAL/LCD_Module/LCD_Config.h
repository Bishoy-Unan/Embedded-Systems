/*
 * LCD_Config.h
 *
 *  Created on: Sep 16, 2019
 *      Author: BISHOY
 */

#ifndef HAL_LCD_MODULE_LCD_CONFIG_H_
#define HAL_LCD_MODULE_LCD_CONFIG_H_

#include"LCD.h"

      // change in LCD.c
#define LCD_DATAPORT   PORTA    /*for LCD data*/
#define LCD_RSPORT     PORTC   //for register selection on specific port
#define LCD_RSPIN      PIN2    //for register selection in specific pin_no on specific port
#define LCD_RWPORT     PORTC   //for read and write pin in specific port
#define LCD_RWPIN      PIN1    //for read and write on pin_no in specific port
#define LCD_EPORT      PORTC   //for enable LCD on specific port
#define LCD_EPIN       PIN0    //for enable pin_no LCD on specific port

/*USE FONT_5X10 OR FONT_5X8*/
#define LCD_FONT		FONT_5X8
/*USE ONE_LINE OR TWO_LINES*/
#define LINE_NUM		 TWO_LINES
/*USE _4BIT_DATA OR _8BIT_DATA*/
#define DATA_NUM		_8BIT_DATA
/*USE MOVE_RIGHT OR MOVE_LEFT*/
#define CURSOR_MOVE	     MOVE_RIGHT
/*USE ON_DISPLAY OR OFF_DISPLAY*/
#define DISPLAY         ON_DISPLAY
/*USE ON_CURSOR OR OFF_CURSOR*/    //for next cell
#define CURSOR          OFF_CURSOR
/*USE ON_BLINK OR OFF_BLINK*/   //for the place that you will write in it
#define BLINK           OFF_BLINK
/*USE CURSER_LEFT OR CURSER_RIGHT*/
#define CURSOR_SHIFT    CURSOR_RIGHT


#if ( LCD_FONT == FONT_5x10 && LINE_NUM == TWO_LINES )
		#pragma GCC error "You cannot Have Two Lines LCD with 5 * 10"
#endif




#endif /* HAL_LCD_MODULE_LCD_CONFIG_H_ */
