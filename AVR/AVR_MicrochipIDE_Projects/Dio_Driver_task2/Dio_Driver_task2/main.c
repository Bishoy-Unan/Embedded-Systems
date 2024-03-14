/*
 * main.c
 *
 * Created: 11/27/2023 1:24:21 PM
 *  Author: NoteBook
 */ 

#include<util/delay.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_Private.h"
#include "DIO.h"





int main(void)
{
	u8 Local_u8Button = 1 ;
	
	/*p0&p1&p2&p3 for led and p4 for switch*/
	/*configure p0,p1,p2,p3 as out and p4 as input*/
	DIO_enumPorts_t LedPort = DIO_enumPORTA ;
	DIO_enumPorts_t SwitchPort = DIO_enumPORTB ;
	
	DIO_enumPins_t LED1Pin = DIO_enumPIN0 ;
	DIO_enumPins_t LED2Pin = DIO_enumPIN1 ;
	DIO_enumPins_t LED3Pin = DIO_enumPIN2 ;
	DIO_enumPins_t LED4Pin = DIO_enumPIN3 ;
	DIO_enumPins_t SwitchPin = DIO_enumPIN0;
	
	DIO_enumConfig_t LED1Config = DIO_enumOUTPUT;
	DIO_enumConfig_t LED2Config = DIO_enumOUTPUT;
	DIO_enumConfig_t LED3Config = DIO_enumOUTPUT;
	DIO_enumConfig_t LED4Config = DIO_enumOUTPUT;
	DIO_enumConfig_t SwitchConfig = DIO_enumInputPullUp;
	
	
	
	DIO_enumSetPinConfig(LedPort,LED1Pin,LED1Config);
	DIO_enumSetPinConfig(LedPort,LED2Pin,LED2Config);
	DIO_enumSetPinConfig(LedPort,LED3Pin,LED3Config);
	DIO_enumSetPinConfig(LedPort,LED4Pin,LED4Config);
	DIO_enumSetPinConfig(SwitchPort,SwitchPin,SwitchConfig);
	//DDRA = 0b00001111;
	/*enable pull up resistor at pin 4 port A*/
	//PORTA = 0b00010000;
	while(1)
	{
		/*because of avr by default is pull up resistor so when the switch pressed we read zero on p4*/
		 DIO_enumGetPinVal(SwitchPort,SwitchPin,&Local_u8Button);
		if(Local_u8Button==0)
		{
			PORTA +=1;
			_delay_ms(1000);
		}
		
		
	}
}