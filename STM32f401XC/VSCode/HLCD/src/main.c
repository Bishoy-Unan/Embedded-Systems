

#include"STD_TYPES.h"
#include"MRCC_Interface.h"
#include"SysTick_Interface.h"
#include"SCHED_Interface.h"
#include "app.h"
#include"LED.h"
#include"LED_Config.h"
#include "SWITCH.h"
#include"SWITCH_Config.h"




;
int
main(int argc, char* argv[])
{
	//u8 LOCAL_u8Button1 = 1 ;
	//u8 LOCAL_u8Button2 = 1 ;
	


	/*RCC Configuration*/
	RCC_enuControlClk(RCC_HSE,RCC_CLK_ON);
	RCC_enuSelectSystemClk(RCC_HSE);
	RCC_enuEnablePeripheralClock(RCC_AHB1,GPIOA_RCC);
	RCC_enuEnablePeripheralClock(RCC_AHB1,GPIOB_RCC);

	LED_enumdInit();
	SWITCH_enumdInit();
	
	SCHED_vidInit();
    SCHED_vidStart();
	

  //while (1)
    //{
		/*
		SWITCH_enuGetSwitchState( SWITCH2 , & LOCAL_u8Button1 ) ;
		SWITCH_enuGetSwitchState( SWITCH1 , & LOCAL_u8Button2 ) ;

		if(LOCAL_u8Button1 == PRESSED)
		{
		
			LED_enuSetLedState(LED_RED,LED_STATE_ON);
			LED_enuSetLedState(LED_BLUE,LED_STATE_OFF);

		}
		if(LOCAL_u8Button2 == PRESSED)
		{
		
			LED_enuSetLedState(LED_BLUE,LED_STATE_ON);
			LED_enuSetLedState(LED_RED,LED_STATE_OFF);
		}
		*/
    //}



    return 0;
}



