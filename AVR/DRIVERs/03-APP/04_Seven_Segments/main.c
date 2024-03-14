/*
 * main.c
 *
 * Created: 12/17/2023 3:11:07 PM
 *  Author: Bishoy Unan
 */ 

#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../HAL/7_SEGMENTS/SevenSegments.h"
#include "../HAL/7_SEGMENTS/SevenSegments_Config.h"
#include "../MCAL/DIO_04/DIO.h"


int main(void)
{
	SevenSegments_enumInit();
	/*
	SevenSegments_enumSetVal(1,seven);
	
	SevenSegments_enumSetVal(2,five);
	*/
	SevenSegments_enumVal(73);
    while(1)
    {
        
    }
}