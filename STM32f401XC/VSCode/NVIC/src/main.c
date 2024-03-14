#include"STD_TYPES.h"
#include"LED.h"
#include"LED_Config.h"
#include "SWITCH.h"
#include"SWITCH_Config.h"
#include"MRCC_Interface.h"

int
main(int argc, char* argv[])
{
	u8 LOCAL_u8Button1 = 1 ;
	u8 LOCAL_u8Button2 = 1 ;
	


	/*RCC Configuration*/
	RCC_enuControlClk(RCC_HSE,RCC_CLK_ON);
	RCC_enuSelectSystemClk(RCC_HSE);
	RCC_enuEnablePeripheralClock(RCC_AHB1,GPIOA_RCC);

	LED_enumdInit();
	SWITCH_enumdInit();
	LED_enuSetLedState(LED_GREEN,LED_STATE_ON);
	

  while (1)
    {
		SWITCH_enuGetSwitchState( SWITCH2 , & LOCAL_u8Button1 ) ;
		SWITCH_enuGetSwitchState( SWITCH1 , & LOCAL_u8Button2 ) ;
		if(LOCAL_u8Button1 == PRESSED)
		{
			LED_enuSetLedState(LED_GREEN,LED_STATE_ON);
		}
		if(LOCAL_u8Button2 == PRESSED)
		{
			LED_enuSetLedState(LED_GREEN,LED_STATE_OFF);
		}

    }
}

