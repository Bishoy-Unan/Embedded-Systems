
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../MCAL/delay_function/delay_function.h"
#include "../HAL/LCD/LCD.h"
#include "../MCAL/DIO_04/DIO.h"
#define F_CPU 8000000UL

int main(void)
{
	
	//LCD_voidClearDisplay();
	LCD_init();
	u8 str1[]="Pola\0" ;
	u8 str2[]="shady\0" ;
	LCD_enuGotoDDRAM_XY(0,10);
	
	LCD_enuWriteString(str1);
    while(1)
    {
		//LCD_enuWriteNumber(55);
		
		/*
		LCD_enuGotoDDRAM_XY(1,5);
		
		LCD_enuWriteString(str2);
		
		LCD_enuGotoDDRAM_XY(0,10);
		
		LCD_enuWriteString(str1);
*/
		//LCD_voidCursorDisplayShift();
         
    }
}