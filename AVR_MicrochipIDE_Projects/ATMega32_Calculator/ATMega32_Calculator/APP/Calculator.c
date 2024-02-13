

#include "../LIB/STD_TYPES.h"
#include "Calculator.h"
#include "../HAL/LCD/LCD.h"



s32 Convert_To_Int(s8 str[])
{
	s32 num = 0, sign = 1, i = -1;

	if(str[0] == '-')    //check if the string is -ve
	{
		sign = -1;
		i = 0;           //skip the -ve sign to the number
	}

	while(str[++i] != 0)
	{
		num = (num * 10) + (str[i] - '0');
	}

	num *= sign;
	return num;
}

void Convert_To_String(s8 str[], s32 num)
{
	s32 len=0, temp1, temp2, i, rem;

	temp2 = num;
	
	if(temp2 <=0)
	{
		len++;
		num *= -1;
	}
	
	temp1 = num;
	
	while(temp1 != 0)                 //finding length of the number
	{
		len++;
		temp1 /= 10;
	}

	for(i=0; i<len; i++)             //converting numbers to equivalent char
	{
		rem = num % 10;
		num = num / 10;
		str[len - (i+1)] = rem + '0';
	}
	
	if(temp2 < 0)
	{
		str[0] = '-';
	}
	
	str[len] = '\0';
}


void Calculate(s8 num1[], s8 num2[], s8 operator)
{
	s32  operand1, operand2, result = 0;
	s8 buffer[10];
	
	operand1 = Convert_To_Int(num1);
	operand2 = Convert_To_Int(num2);
	
	switch(operator)
	{
		case '+':
		result = operand1 + operand2;
		break;
		case '-':
		result = operand1 - operand2;
		break;
		case '/':
		result = operand1 / operand2;
		break;
		case '*':
		result = operand1 * operand2;
		break;
	}
	
	Convert_To_String(buffer,result);
	
	LCD_enuGotoDDRAM_XY(1,2);
	
	LCD_enuWriteString((u8)buffer);

}