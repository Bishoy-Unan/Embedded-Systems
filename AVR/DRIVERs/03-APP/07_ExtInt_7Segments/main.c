/*
 * main.c
 *
 * Created: 12/18/2023 1:12:26 PM
 *  Author: BISHOY UNAN
 */ 


//#include<util/delay.h>
#define F_CPU 8000000UL
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../MCAL/DIO_04/DIO.h"
#include "../MCAL/DIO_04/DIO_Private.h"
#include "../MCAL/ExtInterrupt/ExtInterrupt.h"
#include "../HAL/LED/LED.h"
#include "../HAL/LED/LED_Config.h"
#include "../HAL/SWITCH/SWITCH.h"
#include "../HAL/SWITCH/SWITCH_Config.h"
#include "../HAL/7_SEGMENTS/SevenSegments.h"
#include "../HAL/7_SEGMENTS/SevenSegments_Config.h"

/**
*@ Please note we are using two 7 segments on A & B ports 
*@  and 3 switches on port c pin 0 & 1 & 2
*@ and one led on port c pin 3 
*/
/**
*@ #define SEVEN_SEG1_PORT		DIO_enumPORTA
*@ #define SEVEN_SEG1_POR2		DIO_enumPORTB
*@ #define SWITCHES_PORT		DIO_enumPORTC
*@ #define SWITCH1_PIN			DIO_enumPIN0
*@ #define SWITCH2_PIN			DIO_enumPIN1
*@ #define SWITCH3_PIN			DIO_enumPIN2
*@ #define LED_PORT			DIO_enumPORTC
*@ #define LED_PIN				DIO_enumPIN3
*/

extern LED_strCFG_t LEDS[NumOfLeds];
extern SWITCH_strCFG_t SWITCHS[NumOfLSWITCHES];

/**
	*@ flag used to check if user want to start or reset alarm 
	*/
	u8 LOCAL_u8StartStopFlag = 0 ;
	/**
	*@ two variables represent the value to be shown on two seven segments
	*/
	u8 LOCAL_u8SevenSegment1_Val = 0 ;
	u8 LOCAL_u8SevenSegment2_Val = 0 ;
	/**
	*@ flag used to toggle led when counter reaches to zero
	*/
	u8 LOCAL_u8ToggleFlag = 0;


	void _delay_ms( int volatile milliseconds)
{
	/*
	assembly code auto generated by utility
	from bret mulvey 
	delay 8 000 cycles
	1ms at 8.0 MZ
	*/
	while(milliseconds--)
	{
	asm volatile(
	"     ldi   r18, 11   \n"
	"     ldi   r19, 99   \n"
	"1:   dec   r19   \n "
	"     brne  1b    \n"
	"     dec   r18   \n"
	"     brne  1b    \n"  
	);
	
	}
	

}



void Increment(void)
{
					/**
				*@ check if seven segment 1 exceeds number 9 reset it to zero and increment segment two by one
				*@ and if the two segments exceeds nine number reset both of them to zero
				*/
				if((LOCAL_u8SevenSegment1_Val < 9) && (LOCAL_u8SevenSegment2_Val < 9))
				{
					LOCAL_u8SevenSegment1_Val++;
					_delay_ms(300);
					SevenSegments_enumSetVal(SevenSegments_1,LOCAL_u8SevenSegment1_Val);
				}
				else if( (LOCAL_u8SevenSegment1_Val == 9) && (LOCAL_u8SevenSegment2_Val < 9) )
				{
					LOCAL_u8SevenSegment1_Val = 0;
					LOCAL_u8SevenSegment2_Val++;
					_delay_ms(300);	
					SevenSegments_enumSetVal(SevenSegments_1,LOCAL_u8SevenSegment1_Val);
					SevenSegments_enumSetVal(SevenSegments_2,LOCAL_u8SevenSegment2_Val);
				}/*if2*/
				else if( (LOCAL_u8SevenSegment1_Val == 9) && (LOCAL_u8SevenSegment2_Val == 9) )
				{
					LOCAL_u8SevenSegment1_Val = 0;
					LOCAL_u8SevenSegment2_Val = 0;
					_delay_ms(300);
					SevenSegments_enumSetVal(SevenSegments_1,LOCAL_u8SevenSegment1_Val);
					SevenSegments_enumSetVal(SevenSegments_2,LOCAL_u8SevenSegment2_Val);
					
				}/*else if*/
				else
				{
					LOCAL_u8SevenSegment1_Val++;
					LOCAL_u8SevenSegment2_Val = 9;
					_delay_ms(300);
					SevenSegments_enumSetVal(SevenSegments_1,LOCAL_u8SevenSegment1_Val);
					SevenSegments_enumSetVal(SevenSegments_2,LOCAL_u8SevenSegment2_Val);
					
					
				}
	
}/*Increment function*/

void Decrement(void)
{
	/**
				*@ check if seven segment 1 reach to zero reset it to nine and decrement seven segment two 
				*@ and if both segments reach to zero reset them to nine 
				*/
				 if( (LOCAL_u8SevenSegment1_Val > 0) && (LOCAL_u8SevenSegment2_Val > 0) )
				{
					LOCAL_u8SevenSegment1_Val--;
					_delay_ms(300);
					SevenSegments_enumSetVal(SevenSegments_1,LOCAL_u8SevenSegment1_Val);
					SevenSegments_enumSetVal(SevenSegments_2,LOCAL_u8SevenSegment2_Val);
					}/*if2*/
				else if( (LOCAL_u8SevenSegment1_Val == 0) && (LOCAL_u8SevenSegment2_Val > 0) )
				{
					LOCAL_u8SevenSegment1_Val = 9;
					LOCAL_u8SevenSegment2_Val--;
					_delay_ms(300);
					SevenSegments_enumSetVal(SevenSegments_1,LOCAL_u8SevenSegment1_Val);
					SevenSegments_enumSetVal(SevenSegments_2,LOCAL_u8SevenSegment2_Val);	
				}/*if2*/
				else if( (LOCAL_u8SevenSegment1_Val == 0) && (LOCAL_u8SevenSegment2_Val == 0) )
				{
					LOCAL_u8SevenSegment1_Val = 9;
					LOCAL_u8SevenSegment2_Val = 9;
					_delay_ms(300);
					SevenSegments_enumSetVal(SevenSegments_1,LOCAL_u8SevenSegment1_Val);
					SevenSegments_enumSetVal(SevenSegments_2,LOCAL_u8SevenSegment2_Val);
					
				}/*else if*/
				else
				{
					LOCAL_u8SevenSegment1_Val--;
					LOCAL_u8SevenSegment2_Val = 0;
					_delay_ms(300);
					SevenSegments_enumSetVal(SevenSegments_1,LOCAL_u8SevenSegment1_Val);
					SevenSegments_enumSetVal(SevenSegments_2,LOCAL_u8SevenSegment2_Val);
					
					
				}
	
}/*Decrement function*/

void Start(void)
{
			LOCAL_u8StartStopFlag = 0 ;
	
			while(LOCAL_u8StartStopFlag == 0){
				 if( (LOCAL_u8SevenSegment1_Val > 0) && (LOCAL_u8SevenSegment2_Val > 0) )
				 {
					 LOCAL_u8SevenSegment1_Val--;
					 _delay_ms(1000);
					 SevenSegments_enumSetVal(SevenSegments_1,LOCAL_u8SevenSegment1_Val);
					 SevenSegments_enumSetVal(SevenSegments_2,LOCAL_u8SevenSegment2_Val);
				 }/*if2*/
				else if( (LOCAL_u8SevenSegment1_Val == 0) && (LOCAL_u8SevenSegment2_Val > 0) )
				{
					LOCAL_u8SevenSegment1_Val = 9;
					LOCAL_u8SevenSegment2_Val--;
					_delay_ms(1000);
					SevenSegments_enumSetVal(SevenSegments_1,LOCAL_u8SevenSegment1_Val);
					SevenSegments_enumSetVal(SevenSegments_2,LOCAL_u8SevenSegment2_Val);
				}/*if2*/
				else if( (LOCAL_u8SevenSegment1_Val > 0) && (LOCAL_u8SevenSegment2_Val == 0) )
				{
					LOCAL_u8SevenSegment1_Val--;
				
					_delay_ms(1000);
					SevenSegments_enumSetVal(SevenSegments_1,LOCAL_u8SevenSegment1_Val);
					SevenSegments_enumSetVal(SevenSegments_2,LOCAL_u8SevenSegment2_Val);
				}/*if2*/	 
					 else
					 {
						 /**
							*@ toggle led and break loop
							*/
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
					 LOCAL_u8StartStopFlag =1 ;
					 }/*else */
					 
					 
					 
				 }/*while LOCAL_u8StartStopFlag*/
	
}/*Start function */



int main(void)
{
	
	/**
	*@ set call back function for external interrupt 0
	*/
	ExtINT_voidSetExtINT0(Increment);
	/**
	*@ set call back function for external interrupt 1
	*/
	ExtINT_voidSetExtINT1(Decrement);
	
	/**
	*@ external interrupt init function
	*/
	ExtInterrupt_voidInit();
	/**
	*@ LED init function
	*/
	LED_enumdInit();
	/**
	*@ switch init function
	*/
	SWITCH_enumdInit();
	/**
	*@ seven segments init function
	*/
	SevenSegments_enumInit();
	
	SevenSegments_enumSetVal(SevenSegments_1,zero);
	SevenSegments_enumSetVal(SevenSegments_2,zero);
	
	
    while(1)
    {
		
		
        
    } /*while 1*/

	
	
	
	
	
return 0;	
} /*main function*/