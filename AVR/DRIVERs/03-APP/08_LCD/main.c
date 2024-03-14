
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../MCAL/delay_function/delay_function.h"
#include "../HAL/LCD/LCD.h"
#include "../MCAL/DIO_04/DIO.h"
#define F_CPU 8000000UL

int main(void)
{
	
	
		u8 i,j;
	u8  str1[]="Bishoy\0";
	LCD_VidClearScreen();
	
	LCD_init();

	while(1){
				LCD_VidClearScreen();

				LCD_enuGotoDDRAM_XY(0,10);
		
				LCD_enuWriteString(str1);
				/*
				LCD_enuGotoDDRAM_XY(0,8);
				
				LCD_enuWriteNumber(1);
				*//*
				for(i=0;i<10;i++){
	
							LCD_VidShiftRight(1);
		
							delay_ms(100);
							
								}//for
			
				LCD_VidClearScreen();
				
				LCD_enuGotoDDRAM_XY(1,10);
			
				LCD_enuWriteString(str1);
			
				for(j=0;j<10;j++){
					
								LCD_VidShiftRight(1);
								
								delay_ms(100);
				
								}//for  */
		}//while  
return 0;     
}


