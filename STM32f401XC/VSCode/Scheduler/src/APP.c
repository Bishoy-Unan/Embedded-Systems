
#include"STD_TYPES.h"
#include "app.h"
#include"LED.h"
#include"LED_Config.h"



void app1(void)
{

}


void app(void)
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
