/*
 * main.c
 *
 * Created: 11/27/2023 12:41:08 AM
 *  Author: NoteBook
 */ 

#include<util/delay.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_Private.h"
#include "DIO.h"


int main(void)
{
	//DIO_enumError_t;
	DIO_enumPorts_t LEDPort = DIO_enumPORTA ;
	
	DIO_enumPins_t LED1Pin = DIO_enumPIN0 ;

	
	DIO_enumConfig_t LED1Config = DIO_enumOUTPUT ;
	
	
	DIO_enumLogicState_t LED1ON = DIO_enumHIGH;   
	
	
	DIO_enumLogicState_t LED1OFF = DIO_eumLOW ;
	
	
	/*cnfigure pin0 and pin1 at port A as output */
	DIO_enumSetPinConfig(LEDPort , LED1Pin , LED1Config);
	
	
    while(1)
    {
        /*LED1 ON FOR ONE SECOND AND LED 2 OFF FOR ONE SECOND*/
		
		DIO_enumSetPinVal(LEDPort , LED1Pin , LED1ON);
        _delay_ms(1000);
        /*LED1 ON FOR ONE SECOND AND LED TWO 2 FOR ONE SECOND*/
		DIO_enumSetPinVal(LEDPort , LED1Pin , LED1OFF);
        
	   
        _delay_ms(1000);
    }
}