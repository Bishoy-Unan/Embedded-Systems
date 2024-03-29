/*
 * main.c
 *
 * Created: 12/10/2023 11:08:08 PM
 *  Author: Bishoy Unan
 */ 

#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../MCAL/DIO_04/DIO.h"
#include "../MCAL/DIO_04/DIO_Private.h"
#include "../HAL/LED/LED.h"
#include "../HAL/LED/LED_Config.h"
#include "../HAL/SWITCH/SWITCH.h"
#include "../HAL/SWITCH/SWITCH_Config.h"
#include<util/delay.h>


extern LED_strCFG_t LEDS[NumOfLeds];
extern SWITCH_strCFG_t SWITCHS[NumOfLSWITCHES];


int main(void)
{
	/**
	*@ LOCAL_u8Button1 variable to check switch1 one pressed or not , it initialized by 1 which mean switch unpressed
	*/
	u8 LOCAL_u8Button1 = 1 ;
	/**
	*@ LOCAL_u8Button2 variable to check switch2 one pressed or not , it initialized by 1 which mean switch unpressed
	*/
	u8 LOCAL_u8Button2 = 1 ;
	/**
	*@ FLAG used to toggle led
	*/
	u8 LOCAL_u8ToggleFlag = 0 ;
	
	
	LED_enumdInit();
	SWITCH_enumdInit();
    
	while(1)
    {
		/**
		*@ Check if switch1 pressed or not
		*/
		   SWITCH_enuGetSwitchState( SWITCH2 , & LOCAL_u8Button1 ) ;
		 
		/**
		*@ Check if switch1 pressed or not
		*/
		  SWITCH_enuGetSwitchState( SWITCH1 , & LOCAL_u8Button2 ) ;
		  
		/**
		*@ IF switch 1 pressed toggle led 1 and if switch 2 pressed toggle led 2
		*/  
		if ( LOCAL_u8Button1 == Pressed )
		{
			if(LOCAL_u8ToggleFlag == 0)
				{
					LED_enuSetLedState(LED1,LED_enumActiveHigh_ON);
					_delay_ms(1000);
					LOCAL_u8ToggleFlag ^= 1;		
				}
			else
				{	
					LED_enuSetLedState(LED1,LED_enumActiveHigh_OFF);
					_delay_ms(1000);
					LOCAL_u8ToggleFlag ^= 1;
				}	
		}
		
		else if (  LOCAL_u8Button2 == Pressed)
		{
			if(LOCAL_u8ToggleFlag == 0)
			{
				LED_enuSetLedState(LED2,LED_enumActiveHigh_ON);
				_delay_ms(1000);
				LOCAL_u8ToggleFlag ^= 1;
			}
			else
			{
				LED_enuSetLedState(LED2,LED_enumActiveHigh_OFF);
				_delay_ms(1000);
				LOCAL_u8ToggleFlag ^= 1;
			}
		}
		  
		
     
    }
}