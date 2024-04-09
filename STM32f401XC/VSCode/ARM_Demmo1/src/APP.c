
/**
 * @file APP.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-04-08
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "STD_TYPES.h"
#include "MRCC_Interface.h"
#include "SysTick_Interface.h"
#include "SCHED_Interface.h"
#include "GPIO_Interface.h"
#include "NVIC_Interface.h"
#include "UART_Interface.h"
#include "LCD.h"
#include "app.h"
#include "LED.h"
#include "LED_Config.h"
#include "SWITCH.h"
#include "SWITCH_Config.h"

;
volatile u8 UART_u8ReceivedData  = 0;


volatile  u16 Watch_counter = 0;
volatile u8 Watch_seconds = 0;
volatile u8 Watch_minutes = 00;
volatile u8 Watch_hours   = 10;
volatile u8 date = 8 ;
volatile u16 year = 2024 ;
volatile u8 * Month[12] = {"JAN","FEB","MAR","APR","MAY","JUN","JUL","AUG","SEPT","OCT","NOV","DEC"} ;  


;
void app(void)
{
	
	static u8 LOCAL_u8ToggleFlag = 0 ;
    //test lcd with scheduler
  
	
     static u32 time=0;
    time ++ ;
   
    if (time==1)
    {
        
     LCD_enuWriteString("Bishoy",6);
    //LCD_enuWriteNumber(55);
    }
    else if (time==2)
    {
     // LCD_Clear_ScreenAsync();
    }
    else if (time==3)
    {
      LCD_enuGotoDDRAM_XY(2,0);
    }
    else if (time==4)
    {
     
      LCD_enuWriteString("Unan ",5);
    }
    else if(time == 5)
    {
        LCD_enuGotoDDRAM_XY(2,6);
    }
    else if (time==6)
    {
     LCD_enuWriteNumber(14);
    }
	
    
	

	if(LOCAL_u8ToggleFlag == 0)
	{
		LED_enuSetLedState(LED_ORANGE,LED_STATE_ON);
		LOCAL_u8ToggleFlag = LOCAL_u8ToggleFlag ^ 1 ;
	}
	else
	{
		LED_enuSetLedState(LED_ORANGE,LED_STATE_OFF);
		LOCAL_u8ToggleFlag = LOCAL_u8ToggleFlag ^ 1 ;
	}

}

/**
 * @brief 
 * 
 */
void app1(void)
{
	static u8 LOCAL_u8ToggleFlag = 0 ;

	if(LOCAL_u8ToggleFlag == 0)
	{
		LED_enuSetLedState(LED_YELLOW,LED_STATE_ON);
		LOCAL_u8ToggleFlag = LOCAL_u8ToggleFlag ^ 1 ;
	}
	else
	{
		LED_enuSetLedState(LED_YELLOW,LED_STATE_OFF);
		LOCAL_u8ToggleFlag = LOCAL_u8ToggleFlag ^ 1 ;
	}
}

/**
 * @brief 
 * 
 */
void app2(void)
{
   static u8 LOCAL_u8ToggleFlag = 0 ;

	if(LOCAL_u8ToggleFlag == 0)
	{
		LED_enuSetLedState(LED_RED,LED_STATE_ON);
		LOCAL_u8ToggleFlag = LOCAL_u8ToggleFlag ^ 1 ;
	}
	else
	{
		LED_enuSetLedState(LED_RED,LED_STATE_OFF);
		LOCAL_u8ToggleFlag = LOCAL_u8ToggleFlag ^ 1 ;
	}
}

void app3(void)
{
   static u8 LOCAL_u8ToggleFlag = 0 ;

	if(LOCAL_u8ToggleFlag == 0)
	{
		LED_enuSetLedState(LED_BLUE,LED_STATE_ON);
		LOCAL_u8ToggleFlag = LOCAL_u8ToggleFlag ^ 1 ;
	}
	else
	{
		LED_enuSetLedState(LED_BLUE,LED_STATE_OFF);
		LOCAL_u8ToggleFlag = LOCAL_u8ToggleFlag ^ 1 ;
	}
}

//application to test runnable switch
void app4(void)
{
    u8 button1 = 1;
    static u8 LOCAL_u8ToggleFlag = 0 ;
    SWITCH_enuGetSwitchState_task(SWITCH1,&button1);
     //check if switch 1 pressed or not
    if(button1 == 0)
    {
        if(LOCAL_u8ToggleFlag == 0)
        {
        	LED_enuSetLedState(LED_GREEN,LED_STATE_ON);
        	LOCAL_u8ToggleFlag = LOCAL_u8ToggleFlag ^ 1 ;
        }
        else
        {
        	LED_enuSetLedState(LED_GREEN,LED_STATE_OFF);
        	LOCAL_u8ToggleFlag = LOCAL_u8ToggleFlag ^ 1 ;
        }
    }
} 

// runnable to test LCD with UART
void app5(void)
{
    if (UART_u8ReceivedData==0)
    {
        // send the received data to putty to check uart 
    UART_SendByteAsynchronous(UART_1,'A');
    
    //LCD_enuWriteString("Bisho",5);
    
    }
    else if (UART_u8ReceivedData==49)
    {
       // send the received data to putty to check uart 
    UART_SendByteAsynchronous(UART_1,'B');
     UART_u8ReceivedData = 0 ;
    //LCD_enuWriteString("Bishoy",6);
    
    }
    else if (UART_u8ReceivedData==50)
    {
        // send the received data to putty to check uart 
    UART_SendByteAsynchronous(UART_1,'C');
     UART_u8ReceivedData = 0 ;
     // LCD_Clear_ScreenAsync();
    }
    else if (UART_u8ReceivedData==51)
    {
        // send the received data to putty to check uart 
    UART_SendByteAsynchronous(UART_1,'D');
     UART_u8ReceivedData = 0 ;
      //LCD_enuGotoDDRAM_XY(2 , 1);
    }
    else if (UART_u8ReceivedData==52)
    {
        // send the received data to putty to check uart 
    UART_SendByteAsynchronous(UART_1,'E');
     UART_u8ReceivedData = 0 ;
     // LCD_Write_StringAsync("Bishoy",6);
      //LCD_enuWriteString("Unan ",5);
    }
    else if (UART_u8ReceivedData==53)
    {
        // send the received data to putty to check uart 
    UART_SendByteAsynchronous(UART_1,'F');
     UART_u8ReceivedData = 0 ;
    //  LCD_enuGotoDDRAM_XY(2 , 6);
    }
    else if(UART_u8ReceivedData == 54)
    {
        UART_u8ReceivedData = 0 ;
         // send the received data to putty to check uart 
    UART_SendByteAsynchronous(UART_1,'G');
      //LCD_enuWriteNumber(14);
    }

}

void Watch_Runnable(void)
{
    // += 50 because this runnable runs every 100ms
    Watch_counter += 50 ;
    if(Watch_counter == 1000)
    {
        Watch_seconds ++;
        Watch_counter = 0;
    }
    if(Watch_seconds == 60)
    {
        Watch_minutes ++ ;
        Watch_seconds = 0;
    }
    if(Watch_minutes == 60)
     {
         Watch_hours ++ ;
         Watch_minutes = 0;
     }

}

void DisplayWatch_Runnable(void)
{
    static u8 DisplayWatch_Counter = 0 ;
    if (DisplayWatch_Counter == 0)
    {
         DisplayWatch_Counter ++ ;
         LCD_enuGotoDDRAM_XY(1,0);
       
    }
    else if (DisplayWatch_Counter == 1)
    {
         DisplayWatch_Counter ++ ;
         LCD_enuWriteNumber(Watch_hours);
    }
    else if (DisplayWatch_Counter == 2)
    {
         DisplayWatch_Counter ++ ;
         LCD_enuGotoDDRAM_XY(1,2);
       
    }
    else if (DisplayWatch_Counter == 3)
    {
        DisplayWatch_Counter ++ ;
         LCD_enuWriteString(":",1);
    }
    else if (DisplayWatch_Counter == 4)
    {
        DisplayWatch_Counter ++ ;
         LCD_enuGotoDDRAM_XY(1,3);
    }
    else if (DisplayWatch_Counter == 5)
    {
       DisplayWatch_Counter ++ ;
         LCD_enuWriteNumber(Watch_minutes);
    }
    else if (DisplayWatch_Counter == 6)
    {
        DisplayWatch_Counter ++ ;
         LCD_enuGotoDDRAM_XY(1,5);
    }
    else if(DisplayWatch_Counter == 7)
    {
        DisplayWatch_Counter ++ ;
         LCD_enuWriteString(":",1);
    }
    else if (DisplayWatch_Counter==8)
    {
        DisplayWatch_Counter ++ ;
         LCD_enuGotoDDRAM_XY(1,6);
    }
    else if (DisplayWatch_Counter==9)
    {
        DisplayWatch_Counter  ++  ;
         LCD_enuWriteNumber(Watch_seconds);
    }
     else if (DisplayWatch_Counter==10)
    {
        DisplayWatch_Counter ++ ;
         LCD_enuGotoDDRAM_XY(2,0);
    }
    else if (DisplayWatch_Counter==11)
    {
        DisplayWatch_Counter  ++  ;
         LCD_enuWriteNumber(date);
    }
     else if (DisplayWatch_Counter==12)
    {
        DisplayWatch_Counter ++ ;
         LCD_enuGotoDDRAM_XY(2,2);
    }
    else if (DisplayWatch_Counter==13)
    {
        DisplayWatch_Counter  ++  ;
         LCD_enuWriteString(Month[3],3);
    }
      else if (DisplayWatch_Counter==14)
    {
        DisplayWatch_Counter ++ ;
         LCD_enuGotoDDRAM_XY(2,6);
    }
    else if (DisplayWatch_Counter==15)
    {
        DisplayWatch_Counter  = 0 ;
         LCD_enuWriteNumber(year);
    }
}

void DisplayDate(void)
{

}

void UART_vidRunnable(void)
{
    UART_ReceiveByteAsync(UART_1 , & UART_u8ReceivedData);
}

void TrafficLight(void)
{
    static u32 Loc_u32Seconds = 0;
    

    Traffic_Lights_t Loc_enuState = Red ;

    Traffic_Lights_t Loc_enuPreviouse = Yellow ;


   
    switch (Loc_enuState)
    {
    case Green :
                 LED_enuSetLedState( LED_GREEN , LED_STATE_ON);
                 LED_enuSetLedState( LED_YELLOW , LED_STATE_OFF);
                 LED_enuSetLedState( LED_RED , LED_STATE_OFF);

                if(Loc_u32Seconds == 6)
                {
                    Loc_u32Seconds = 0;
                    Loc_enuState = Yellow ;
                    Loc_enuPreviouse = Green ;
                }
        break;
    case Yellow :
                 LED_enuSetLedState( LED_GREEN , LED_STATE_OFF);
                 LED_enuSetLedState( LED_YELLOW , LED_STATE_ON);
                 LED_enuSetLedState( LED_RED , LED_STATE_OFF);

                if(Loc_u32Seconds == 2)
                {
                    Loc_u32Seconds = 0;
                    Loc_enuState = Red ;
                    Loc_enuPreviouse = Yellow ;
                }
        break;
    case Red :
                 LED_enuSetLedState( LED_GREEN , LED_STATE_OFF);
                 LED_enuSetLedState( LED_YELLOW , LED_STATE_OFF);
                 LED_enuSetLedState( LED_RED , LED_STATE_ON);

                if(Loc_u32Seconds == 20)
                {
                    Loc_u32Seconds = 0;
                    Loc_enuState = Yellow ;
                    Loc_enuPreviouse = Red ;
                }
        break;
    
    default:

        break;
    }
     Loc_u32Seconds += PERIODICITY_SECONDS ;

}