
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
extern const SWITCH_strCFG_t SWITCHS[_NUM_OF_SWITHs];
typedef enum 
{
    ClkDisplay_Mode    ,
    ClkEdit_Mode       ,
    DateDisplay_Mode   ,
    DateEdit_Mode      ,
    StopWatch_Mode     ,
    Modes              ,
    Nothing  

}CurrentMode_t;

static CurrentMode = Modes ;

;
volatile u8 UART_u8ReceivedData  = 0;


volatile  u16 Watch_counter = 0;
volatile  u16 StopWatch_Timer = 0 ;

volatile u8 Watch_seconds = 0;
volatile u8 Watch_minutes = 0;
volatile u8 Watch_hours   = 2;

volatile u8 StopWatch_M=0;
volatile u8 StopWatch_s=0;

volatile u8 stopWach_flag = 0;

volatile u8 switch_clock = 0;
volatile u8 switch_stopWatch = 0;
volatile u8 switch_edit = 0;

volatile u8 Modes_flaf = 0;

volatile u8 ButtonState[_NUM_OF_SWITHs] = {1};



volatile u8 date = 17 ;
volatile u16 year = 2024 ;
//volatile u8 * Month[12] = {"JAN","FEB","MAR","APR","MAY","JUN","JUL","AUG","SEPT","OCT","NOV","DEC"} ;  
u8 volatile Month = 4 ;

;
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

void SelectMode_Runnable(void)
{
    static u8 Modes_Counter = 0 ;

     // modes switch pressed
     if(CurrentMode == Modes )
     {
         if (Modes_Counter == 0)
          {
              Modes_Counter ++ ;
              //LCD_VidClearScreen();
          }
          else if (Modes_Counter == 1)
          {
               LCD_enuGotoDDRAM_XY(1,0);  
          }
          else if ( Modes_Counter == 2 )
          {
              LCD_enuWriteString("1-TD",4);
          }
          else if (Modes_Counter == 3)
          {
               LCD_enuGotoDDRAM_XY(1,5); 
          }
          else if (Modes_Counter == 4)
          {
               LCD_enuWriteString("2-TE",4);
          }
          else if (Modes_Counter == 5)
          {
               LCD_enuGotoDDRAM_XY(1,10); 
          }
          else if (Modes_Counter == 6)
          {
                LCD_enuWriteString("3-DD",4);
          }
          else if (Modes_Counter == 7)
          {
             LCD_enuGotoDDRAM_XY(2,0);
          }
          else if (Modes_Counter == 8)
          {
               LCD_enuWriteString("4-DE",4);
          }
          else if (Modes_Counter == 9)
          {
               LCD_enuGotoDDRAM_XY(2,5);
          }
          else if(Modes_Counter == 10)
          {
               LCD_enuWriteString("5-SW",4);
               Modes_Counter =0;
          }
         Modes_Counter ++ ;
     


     
               // check which mode is selected
               switch(UART_u8ReceivedData)
               {
                    // time display selected   
                case 48:
                       // set UART_u8ReceivedData to nothong as default value
                       UART_u8ReceivedData = 'N' ;
                       // clear LCD
                       LCD_VidClearScreen();
                       // switch current mode to be ClkDisplay_Mode
                       CurrentMode = Modes;      
                break ;  
                // time display selected   
                case 49:
                       // set UART_u8ReceivedData to nothong as default value
                       UART_u8ReceivedData = 'N' ;
                       // clear LCD
                       LCD_VidClearScreen();
                       // switch current mode to be ClkDisplay_Mode
                       CurrentMode = ClkDisplay_Mode;      
                break ;  
                //time edit selected
                case 50:
                       // set UART_u8ReceivedData to nothong as default value
                       UART_u8ReceivedData = 'N' ;
                       // clear LCD
                       LCD_VidClearScreen();
                       // switch current mode to be ClkEdit_Mode
                       CurrentMode = ClkEdit_Mode; 
                break ; 
                //date display selected
                case 51:
                       // set UART_u8ReceivedData to nothong as default value
                       UART_u8ReceivedData = 'N' ;
                       // clear LCD
                       LCD_VidClearScreen();
                       // switch current mode to be DateDisplay_Mode
                       CurrentMode = DateDisplay_Mode; 
                break ; 
                //date edit selected
                case 52:
                       // set UART_u8ReceivedData to nothong as default value
                       UART_u8ReceivedData = 'N' ;
                       // clear LCD
                       LCD_VidClearScreen();
                       // switch current mode to be DateEdit_Mode
                       CurrentMode = DateEdit_Mode; 
                break ;
                //stop watch selected 
                case 53:
                        // set UART_u8ReceivedData to nothong as default value
                       UART_u8ReceivedData = 'N' ;
                       // clear LCD
                       LCD_VidClearScreen();
                       // switch current mode to be StopWatch_Mode
                       CurrentMode = StopWatch_Mode; 
                break ;  
                default:
                       // do nothing
                break ;
               }//switch
     }
}

// runnable to save clock
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

    // Stop Watch code
	if(stopWach_flag == 1)
	{
        StopWatch_Timer += 50 ;
        if(StopWatch_Timer == 1000)
        {
            StopWatch_s++;
            StopWatch_Timer = 0 ;
        }
		if(StopWatch_s == 60)
		{
			StopWatch_M++;
			StopWatch_s = 0;
		}

	}
}

void DisplayWatch_Runnable(void)
{
    static u8 DisplayWatch_Counter = 0 ;

    if(UART_u8ReceivedData == 48)
    {
        CurrentMode = Modes ;
        LCD_VidClearScreen();
    }
    else
    {   
            if(CurrentMode == ClkDisplay_Mode)
            {
                 if (DisplayWatch_Counter == 0)
                 {
                     DisplayWatch_Counter ++ ;
                     LCD_VidClearScreen();
                 }
                 else if (DisplayWatch_Counter == 1)
                 {
                      LCD_enuGotoDDRAM_XY(1,0);  
                 }
                 else if ( (Watch_hours < 10 ) && (DisplayWatch_Counter == 2) )
                 {
                     LCD_enuWriteNumber(0);
                 }
                 else if (DisplayWatch_Counter == 3)
                 {
                      LCD_enuWriteNumber(Watch_hours);  
                 }
                 else if (DisplayWatch_Counter == 4)
                 {
                      LCD_enuGotoDDRAM_XY(1,2);
                 }
                 else if (DisplayWatch_Counter == 5)
                 {
                      LCD_enuWriteString(":",1);
                 }
                 else if (DisplayWatch_Counter == 6)
                 {
                      LCD_enuGotoDDRAM_XY(1,3);
                 }
                 else if ( (Watch_minutes < 10 ) && (DisplayWatch_Counter == 7) )
                 {
                     LCD_enuWriteNumber(0);
                 }
                 else if (DisplayWatch_Counter == 8)
                 {
                      LCD_enuWriteNumber(Watch_minutes);
                 }
                 else if (DisplayWatch_Counter == 9)
                 {
                      LCD_enuGotoDDRAM_XY(1,5);
                 }
                 else if(DisplayWatch_Counter == 10)
                 {
                      LCD_enuWriteString(":",1);
                 }
                 else if ( (Watch_seconds < 10 ) && (DisplayWatch_Counter == 11) )
                 {
                     LCD_enuWriteNumber(0);
                 }
                 else if (DisplayWatch_Counter==12)
                 {
                      LCD_enuWriteNumber(Watch_seconds);
                      DisplayWatch_Counter = 0 ;
                 }
                 

                DisplayWatch_Counter ++ ;
            }
    }
}

void EditTime_Runnable(void)
{
     static u8 EditWatch_Counter = 0 ;

    if(CurrentMode == ClkEdit_Mode)
    {
            if(UART_u8ReceivedData == 48)
            {
                CurrentMode = Modes ;
                LCD_VidClearScreen();
            }
            // increment hours
	        else if(UART_u8ReceivedData == 49)
	        {
		        if(Watch_hours!=12)
		        {
			        Watch_hours++;
		        }
		        else if(Watch_hours==12)
		        {
			        Watch_hours = 1;
		        }
		        UART_u8ReceivedData = 'N';
	        }
	        // decrement hours
	        else if(UART_u8ReceivedData == 50)
	        {
		        if(Watch_hours!=1)
		        {
			        Watch_hours--;
		        }
		        else if(Watch_hours==1)
		        {
		        	Watch_hours = 12;
		        }

		        UART_u8ReceivedData = 'N';

	        }
	        // increment minutes
	        else if(UART_u8ReceivedData == 51)
	        {
		        if(Watch_minutes<59)
		        {
		        	Watch_minutes++;
		        }
		        else if(Watch_minutes==52)
		        {
		        	Watch_minutes = 0;
		        }

		        UART_u8ReceivedData = 'N';
        	     }

	        // decrement minutes
	        else if(UART_u8ReceivedData == 52)
	        {
	        	if(Watch_minutes!=0)
	        	{
	        		Watch_minutes--;
	        	}
	        	else if(Watch_minutes==0)
	        	{
	        		Watch_minutes = 59;
	        	}
	        	UART_u8ReceivedData = 'N';
        	   }
            else
            {   
                    
                    
                         if (EditWatch_Counter == 0)
                         {
                             EditWatch_Counter ++ ;
                             LCD_VidClearScreen();
                         }
                         else if (EditWatch_Counter == 1)
                         {
                              LCD_enuGotoDDRAM_XY(1,0);  
                         }
                         else if ( (Watch_hours < 10 ) && (EditWatch_Counter == 2) )
                         {
                             LCD_enuWriteNumber(0);
                         }
                         else if (EditWatch_Counter == 3)
                         {
                              LCD_enuWriteNumber(Watch_hours);  
                         }
                         else if (EditWatch_Counter == 4)
                         {
                              LCD_enuGotoDDRAM_XY(1,2);
                         }
                         else if (EditWatch_Counter == 5)
                         {
                              LCD_enuWriteString(":",1);
                         }
                         else if (EditWatch_Counter == 6)
                         {
                              LCD_enuGotoDDRAM_XY(1,3);
                         }
                         else if ( (Watch_minutes < 10 ) && (EditWatch_Counter == 7) )
                         {
                             LCD_enuWriteNumber(0);
                         }
                         else if (EditWatch_Counter == 8)
                         {
                              LCD_enuWriteNumber(Watch_minutes);
                         }
                         else if (EditWatch_Counter == 9)
                         {
                              LCD_enuGotoDDRAM_XY(1,5);
                         }
                         else if(EditWatch_Counter == 10)
                         {
                              LCD_enuWriteString(":",1);
                         }
                         else if ( (Watch_seconds < 10 ) && (EditWatch_Counter == 11) )
                         {
                             LCD_enuWriteNumber(0);
                         }
                         else if (EditWatch_Counter==12)
                         {
                              LCD_enuWriteNumber(Watch_seconds);
                              EditWatch_Counter = 0 ;
                         }

                        EditWatch_Counter ++ ;
                    
            }
    }    

}

void EditDate_Runnable(void)
{
      static u8 EditDate_Counter = 0 ;

    if(CurrentMode == DateEdit_Mode)
    {
            if(UART_u8ReceivedData == 48)
            {
                CurrentMode = Modes ;
                LCD_VidClearScreen();
            }
            // increment date
	        else if(UART_u8ReceivedData == 49)
	        {
		        if(date!=30)
		        {
			        date++;
		        }
		        else if(date==30)
		        {
			        date = 1;
		        }
		        UART_u8ReceivedData = 'N';
	        }
	        // decrement date
	        else if(UART_u8ReceivedData == 50)
	        {
		        if(date!=1)
		        {
			        date--;
		        }
		        else if(date==1)
		        {
		        	date = 30;
		        }

		        UART_u8ReceivedData = 'N';

	        }
	        // increment Months
	        else if(UART_u8ReceivedData == 51)
	        {
		        if(Month < 12)
		        {
		        	Month++;
		        }
		        else if(Month == 12)
		        {
		        	Month = 1;
		        }

		        UART_u8ReceivedData = 'N';
        	   }
	        // decrement Month
	        else if(UART_u8ReceivedData == 52)
	        {
	        	if(Month != 1)
	        	{
	        		Month--;
	        	}
	        	else if(Month == 1)
	        	{
	        		Month = 12;
	        	}
	        	UART_u8ReceivedData = 'N';
            }
            // increment years
            else if(UART_u8ReceivedData == 53)
	        {
	        	year ++;
	        	UART_u8ReceivedData = 'N';
            }
             // decrement years
            else if(UART_u8ReceivedData == 54)
	        {
	        	year --;
	        	UART_u8ReceivedData = 'N';
             }
            else
            {   
                    if (EditDate_Counter == 0)
                    {
                         EditDate_Counter ++ ;
                         //LCD_VidClearScreen();
                    }
                    else if (EditDate_Counter==1)
                    {
                         LCD_enuGotoDDRAM_XY(1,0);
                    }
                    else if (EditDate_Counter==2)
                    {
                         LCD_enuWriteString("Edit",4);
                    }
                    else if (EditDate_Counter==3)
                    {
                         LCD_enuWriteString(":",1);
                    }
                    else if (EditDate_Counter==4)
                    {
                         LCD_enuGotoDDRAM_XY(1,6);
                    }
                    else if ( (date < 10 ) && (EditDate_Counter==5))
                    {
                         LCD_enuWriteNumber(0);
                    }
                     else if ((EditDate_Counter==6))
                    {
                         LCD_enuWriteNumber(date);
                    }
                     else if (EditDate_Counter==7)
                    {
                         LCD_enuGotoDDRAM_XY(1,8);
                    }
                     else if (EditDate_Counter==8)
                    {
                         LCD_enuWriteString("/",1);
                    }
                    else if (EditDate_Counter==9)
                    {
                         LCD_enuGotoDDRAM_XY(1,9);
                    }
                    else if ( (Month < 10 ) && (EditDate_Counter==10))
                    {
                         LCD_enuWriteNumber(0);
                    }
                    else if (EditDate_Counter==11)
                    {
                         LCD_enuWriteNumber(Month);
                    }
                    else if (EditDate_Counter==12)
                    {   
                         LCD_enuGotoDDRAM_XY(1,11);
                    }
                    else if (EditDate_Counter==13)
                    {
                         LCD_enuWriteString("/",1);
                    }
                     else if (EditDate_Counter==14)
                    {   
                         LCD_enuGotoDDRAM_XY(1,12);
                    }
                    else if (EditDate_Counter==15)
                    {
                         LCD_enuWriteNumber(year);
                         EditDate_Counter = 0;
                    }
               EditDate_Counter ++ ;
            }
    }    

}

void StopWatch_Runnable(void)
{
      static u8 StopWatch_Counter = 0 ;

    if(CurrentMode == StopWatch_Mode)
    {
            if(UART_u8ReceivedData == 48)
            {
                CurrentMode = Modes ;
                LCD_VidClearScreen();
            }
            // start the stop watch count
	        else if(UART_u8ReceivedData == 54)
	        {
		        stopWach_flag = 1;
		        UART_u8ReceivedData = 'N';
	        }
	        // pause the stop watch count
	        else if(UART_u8ReceivedData == 55)
	        {
		        stopWach_flag = 0;
		        UART_u8ReceivedData = 'N';

	        }
	        // reset the stop watch count
	        else if(UART_u8ReceivedData == 56)
	        {
		        LCD_VidClearScreen();
		        StopWatch_s = 0;
		        StopWatch_M = 0;
		        stopWach_flag = 0;
		        UART_u8ReceivedData = 'N';
        	}
            else
            {   
                         if (StopWatch_Counter == 0)
                         {
                             StopWatch_Counter ++ ;
                             LCD_VidClearScreen();
                         }
                         else if (StopWatch_Counter == 1)
                         {
                              LCD_enuGotoDDRAM_XY(1,0);  
                         }
                         else if ( (StopWatch_M < 10 ) && (StopWatch_Counter == 2) )
                         {
                             LCD_enuWriteNumber(0);
                         }
                         else if (StopWatch_Counter == 3)
                         {
                              LCD_enuWriteNumber(StopWatch_M);  
                         }
                         else if (StopWatch_Counter == 4)
                         {
                              LCD_enuGotoDDRAM_XY(1,2);
                         }
                         else if (StopWatch_Counter == 5)
                         {
                              LCD_enuWriteString(":",1);
                         }
                         else if (StopWatch_Counter == 6)
                         {
                              LCD_enuGotoDDRAM_XY(1,3);
                         }
                         else if ( (StopWatch_s < 10 ) && (StopWatch_Counter == 7) )
                         {
                             LCD_enuWriteNumber(0);
                         }
                         else if (StopWatch_Counter == 8)
                         {
                              LCD_enuWriteNumber(StopWatch_s);
                              StopWatch_Counter = 0 ;
                         }
                         /*
                         else if (StopWatch_Counter == 9)
                         {
                              LCD_enuGotoDDRAM_XY(1,5);
                         }
                         else if(StopWatch_Counter == 10)
                         {
                              LCD_enuWriteString(":",1);
                         }
                         else if (StopWatch_Counter==11)
                         {
                              LCD_enuWriteNumber(StopWatch_Timer);
                              StopWatch_Counter = 0 ;
                         }
                        */
                        StopWatch_Counter ++ ;
                    
            }
    }    
}

void DisplayDate_Runnable(void)
{
    static u8 DisplayDate_Counter = 0 ;

    if(CurrentMode == DateDisplay_Mode)
    {
         if(UART_u8ReceivedData == 48)
            {
                CurrentMode = Modes ;
                LCD_VidClearScreen();
            } 
        else if (DisplayDate_Counter == 0)
        {
             DisplayDate_Counter ++ ;
             //LCD_VidClearScreen();
        }
        else if (DisplayDate_Counter==1)
        {
             LCD_enuGotoDDRAM_XY(1,0);
        }
        else if (DisplayDate_Counter==2)
        {
             LCD_enuWriteString("date",4);
        }
        else if (DisplayDate_Counter==3)
        {
             LCD_enuWriteString(":",1);
        }
        else if (DisplayDate_Counter==4)
        {
             LCD_enuGotoDDRAM_XY(1,6);
        }
        else if ( (date < 10 ) && (DisplayDate_Counter==5))
        {
             LCD_enuWriteNumber(0);
        }
         else if ((DisplayDate_Counter==6))
        {
             LCD_enuWriteNumber(date);
        }
         else if (DisplayDate_Counter==7)
        {
             LCD_enuGotoDDRAM_XY(1,8);
        }
         else if (DisplayDate_Counter==8)
        {
             LCD_enuWriteString("/",1);
        }
        else if (DisplayDate_Counter==9)
        {
             LCD_enuGotoDDRAM_XY(1,9);
        }
        else if ( (Month < 10 ) && (DisplayDate_Counter==10))
        {
             LCD_enuWriteNumber(0);
        }
        else if (DisplayDate_Counter==11)
        {
             LCD_enuWriteNumber(Month);
        }
        else if (DisplayDate_Counter==12)
        {   
             LCD_enuGotoDDRAM_XY(1,11);
        }
        else if (DisplayDate_Counter==13)
        {
             LCD_enuWriteString("/",1);
        }
         else if (DisplayDate_Counter==14)
        {   
             LCD_enuGotoDDRAM_XY(1,12);
        }
        else if (DisplayDate_Counter==15)
        {
             LCD_enuWriteNumber(year);
             DisplayDate_Counter = 0 ;
        }
        DisplayDate_Counter ++ ;
    }
}

void SwitchsState_Runnable(void)
{
    u8 Loc_u8Iterator = 0  ;

     //check if there is switchs pressed 
    for(Loc_u8Iterator = 0 ; Loc_u8Iterator < _NUM_OF_SWITHs ; Loc_u8Iterator++)
    {
	    	SWITCH_enuGetSwitchState_task(Loc_u8Iterator ,  ButtonState[Loc_u8Iterator]);
    }

}

void UART_vidRunnable(void)
{
    u8 Loc_u8Iterator = 0  ;

    //check if there is data received
    UART_ReceiveByteAsync(UART_1 , & UART_u8ReceivedData);

    //check if there is switchs pressed to be sent
    for(Loc_u8Iterator = 0 ; Loc_u8Iterator < _NUM_OF_SWITHs ; Loc_u8Iterator++)
    {
         if(ButtonState[Loc_u8Iterator] == PRESSED)
	     {
	    	UART_SendByteAsynchronous(UART_1,Loc_u8Iterator);
            ButtonState[Loc_u8Iterator] = UNPRESSED ;
	     }
    }
}
