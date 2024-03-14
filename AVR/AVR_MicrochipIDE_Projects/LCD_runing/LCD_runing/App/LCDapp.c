/*
 * LCDapp.c
 *
 *  Created on: Aug 24, 2019
 *      Author: BISHOY
 */
#include "../std_types.h"
#include "../macros.h"
#include "../MCAL/DIO_Module/DIO.h"
#include "../HAL/LCD_Module/LCD_Config.h"
#include "../HAL/LCD_Module/LCD.h"
#define F_CPU 8000000UL
#include "avr/delay.h"



u32 main(){
	u8 i,j;
	DIO_VidSetPortValue(PORTC,0x00);
	DIO_VidSetPortValue(PORTA,0x00);

	LCD_VidClearScreen();
	LCD_VidInit();

	while(1){
/*
		    LCD_VidGoToRowCol(0,0);
			LCD_VidDisplayString("pola\0");
			LCD_VidGoToRowCol(1,5);
			LCD_VidDisplayString("shady\0");
			LCD_VidGoToRowCol(0,10);
			LCD_VidDisplayString("pola\0");

				LCD_VidShiftRight(10);
				*/
				LCD_VidClearScreen();

				LCD_VidGoToRowCol(0,10);
		
				LCD_VidDisplayString(" Bishoy\0");
				//LCD_VidGoToRowCol(0,3);
			//	LCD_VidDisplayInt(5);
				for(i=0;i<10;i++){
	
				LCD_VidShiftRight(1);
		
				_delay_ms(100);
								}//for
			
			LCD_VidClearScreen();
				LCD_VidGoToRowCol(1,10);
			
				LCD_VidDisplayString(" Bishoy\0");
			
				for(j=0;j<10;j++){
					
								LCD_VidShiftRight(1);

			//	LCD_VidShiftLeft(1);
					
				_delay_ms(100);
				
				}//for
			}//while
	return 0;
}//main
	
