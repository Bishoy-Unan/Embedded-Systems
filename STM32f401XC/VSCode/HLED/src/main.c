#include"STD_TYPES.h"
#include"LED.h"
#include"LED_Config.h"
#include"MRCC_Interface.h"

int
main(int argc, char* argv[])
{
	/*RCC Configuration*/
	RCC_enuControlClk(RCC_HSE,RCC_CLK_ON);
	RCC_enuSelectSystemClk(RCC_HSE);
	RCC_enuEnablePeripheralClock(RCC_AHB1,GPIOA_RCC);

	LED_enumdInit();
	LED_enuSetLedState(LED_GREEN,LED_STATE_ON);
	LED_enuSetLedState(LED_RED,LED_STATE_ON);
	LED_enuSetLedState(LED_BLUE,LED_STATE_ON);

  while (1)
    {
		
    }
}

