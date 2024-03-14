

#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../MCAL/DIO_04/DIO_Private.h"
#include "../MCAL/Delay_Function/delay_function.h"
#include "../HAL/KeyPad/KeyPad.h"
#include "../HAL/KeyPad/KeyPad_Config.h"
#include "../HAL/LED/LED.h"
#include "../HAL/LED/LED_Config.h"
#include "../HAL/LCD/LCD.h"
#include "Calculator.h"


int main(void)
{
	u8  str1[]="Bishoy\0";
	u8 CLE; 
	
	KEYPAD_enuInit();
	LCD_init();
	
	LCD_VidClearScreen();

	LCD_enuGotoDDRAM_XY(0,1);
	
	LCD_enuWriteString(str1);
	while(1)
	{
		/*
		u8 num1[9], num2[9], operator=0;
		u8 i = 0 ;

		LCD_enuGotoDDRAM_XY(1,1);
	
		KEYPAD_enuGetPressedKey(&num1[i]);
		
		LCD_enuWriteCharacter(num1[i]);
		
		i++;
		
		while(1){
			
			
			
			
			LCD_enuWriteCharacter(num1[i]);
			
			if(num1[i] == '+')
			{
				operator = '+';
				num1[i] = '\0';
				break;
			}
			else if(num1[i] == '-')
			{
				operator = '-';
				num1[i] = '\0';
				break;
			}
			else if(num1[i] == '/')
			{
				operator = '/';
				num1[i] = '\0';
				break;
			}
			else if(num1[i] == '*')
			{
				operator = '*';
				num1[i] = '\0';
				break;
			}
			i++;
		}
		
		i = 0;
		
		
		KEYPAD_enuGetPressedKey(&num2[i]);
		
		LCD_enuWriteCharacter(num2[i]);
		
		i++;
		
		while(1){
			
			KEYPAD_enuGetPressedKey(&num2[i]);
			LCD_enuWriteCharacter(num2[i]);
			if(num2[i] == '='){
				num2[i] = '\0';
				break;
			}
			
			i++;
		}
		
		Calculate(num1,num2,operator);
		
		
		
		if(KEYPAD_enuGetPressedKey(&CLE))
		{
			LCD_VidClearScreen();
		}
		*/
	}
}

