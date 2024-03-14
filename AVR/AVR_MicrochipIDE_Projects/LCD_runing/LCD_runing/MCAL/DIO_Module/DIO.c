/*
 * DIO.c
 *
 *  Created on: Sep 16, 2019
 *      Author: BISHOY
 */

/*here we will include all header files that we make it */
#include "../../STD_Types.h" //contain data types to be more readable
#include "../../macros.h"    //contain some fundamental expression
#include "DIO.h"     // contain all prototypes of the followed functions

                         /*Local defines*/
/*PORTA Registers*/

#define DDRA_REGISTER  *((volatile u8*) 0x3A)
#define PORTA_REGISTER *((volatile u8*) 0x3B)
#define PINA_REGISTER  *((volatile u8*) 0x39)

/*PORTB Registers*/
#define DDRB_REGISTER  *((volatile u8*) 0x37)
#define PORTB_REGISTER *((volatile u8*) 0x38)
#define PINB_REGISTER  *((volatile u8*) 0x36)

/*PORTC Registers*/
#define DDRC_REGISTER  *((volatile u8*) 0x34)
#define PORTC_REGISTER *((volatile u8*) 0x35)
#define PINC_REGISTER  *((volatile u8*) 0x33)

/*PORTD Registers*/
#define DDRD_REGISTER  *((volatile u8*) 0x31)
#define PORTD_REGISTER *((volatile u8*) 0x32)
#define PIND_REGISTER  *((volatile u8*) 0x30)

void DIO_VidSetPortDir(u8 PortName, u8 PortDir)
{
	switch (PortName)
	{
		case PORTA :
		{
			if(PortDir == INPUT)
			{
				DDRA_REGISTER = 0x00 ;
			}
			else /*Direction is output*/
			{
				DDRA_REGISTER = 0xFF ;
			}
		}break;

		case PORTB :
		{
			if(PortDir == INPUT)
			{
				DDRB_REGISTER = 0x00 ;
			}
			else /*Direction is output*/
			{
				DDRB_REGISTER = 0xFF ;
			}
		}break;

		case PORTC :
		{
			if(PortDir == INPUT)
			{
				DDRC_REGISTER = 0x00 ;
			}
			else /*Direction is output*/
			{
				DDRC_REGISTER = 0xFF ;
			}
		}break;

		case PORTD :
		{
			if(PortDir == INPUT)
			{
				DDRD_REGISTER = 0x00 ;
			}
			else /*Direction is output*/
			{
				DDRD_REGISTER = 0xFF ;
			}
		}break;
	}
}

void DIO_VidSetPinDir(u8 PortName, u8 PinNo , u8 PinDir){
	switch (PortName)
	{
		case PORTA :
		{
			if (PinDir == INPUT)
			{
				clr_bit(DDRA_REGISTER ,PinNo);
			}
			else if (PinDir == OUTPUT)
			{
				set_bit(DDRA_REGISTER , PinNo );
			}
			else
			{
				/*Invalid Input*/
			}

		}break;

		case PORTB :
		{
			if (PinDir == INPUT)
			{
				clr_bit(DDRB_REGISTER ,PinNo);
			}
			else if (PinDir == OUTPUT)
			{
				set_bit(DDRB_REGISTER , PinNo );
			}
			else
			{
				/*Invalid Input*/
			}
		}break;

		case PORTC :
		{
			if (PinDir == INPUT)
			{
				clr_bit(DDRC_REGISTER ,PinNo);
			}
			else if (PinDir == OUTPUT)
			{
				set_bit(DDRC_REGISTER , PinNo );
			}
			else
			{
				/*Invalid Input*/
			}

		}break;
		case PORTD :
		{
			if (PinDir == INPUT)
			{
				clr_bit(DDRD_REGISTER ,PinNo);
			}
			else if (PinDir == OUTPUT)
			{
				set_bit(DDRD_REGISTER , PinNo );
			}
			else
			{
				/*Invalid Input*/
			}
		}break;
	}
}

void DIO_VidSetPortValue (u8 PortName , u8 PortValue)
{
	switch (PortName)
	{
		case PORTA :
		{
			PORTA_REGISTER = PortValue;
		}break;

		case PORTB :
		{
			PORTB_REGISTER = PortValue;
		}break ;

		case PORTC :
		{
			PORTC_REGISTER = PortValue;
		}break ;

		case PORTD :
		{
			PORTD_REGISTER = PortValue;
		}break ;
	}
}



void DIO_VidSetPinValue (u8 PortName , u8 PinNo , u8 PinValue)
{
	switch (PortName)
	{
		case PORTA :
		{
			assign_bit(PORTA_REGISTER,PinNo,PinValue) ;
		}break;

		case PORTB :
		{
			assign_bit(PORTB_REGISTER,PinNo,PinValue) ;
		}break ;

		case PORTC :
		{
			assign_bit(PORTC_REGISTER,PinNo,PinValue) ;
		}break ;

		case PORTD :
		{
			assign_bit(PORTD_REGISTER,PinNo,PinValue) ;
		}break;
	}
}

u8 DIO_U8GetPortValue(u8 PortName)
{
	u8 retVal ;
	switch(PortName)
	{
		case PORTA:
		{
			retVal = PINA_REGISTER;
		}break ;

		case PORTB:
		{
			retVal = PINB_REGISTER;
		}break ;

		case PORTC:
		{
			retVal = PINC_REGISTER;
		}break ;

		case PORTD:
		{
			retVal = PIND_REGISTER;
		}break ;
	}

	return retVal;
}



u8 DIO_U8GetPinaValue (u8 PortName , u8 PinNo )
{
	u8 Value ;
	switch (PortName)
	{
		case PORTA :
		{
			Value =  get_bit(PINA_REGISTER, PinNo);
		}break ;
		case PORTB :
		{
			Value =  get_bit(PINB_REGISTER, PinNo);
		}break ;
		case PORTC :
		{
			Value =  get_bit(PINC_REGISTER, PinNo);
		}break ;

		case PORTD :
		{
			Value =  get_bit(PIND_REGISTER, PinNo);
		}break ;
	}

	return Value ;
}













