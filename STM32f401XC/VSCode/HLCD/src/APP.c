
#include"STD_TYPES.h"
#include "app.h"
#include "LED.h"
#include"LED_Config.h"
//#include "diag/Trace.h"



void app(void)
{
	
	static u8 LOCAL_u8ToggleFlag = 0 ;

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
		LED_enuSetLedState(LED_GREEN,LED_STATE_ON);
		LOCAL_u8ToggleFlag = LOCAL_u8ToggleFlag ^ 1 ;
	}
	else
	{
		LED_enuSetLedState(LED_GREEN,LED_STATE_OFF);
		LOCAL_u8ToggleFlag = LOCAL_u8ToggleFlag ^ 1 ;
	}
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