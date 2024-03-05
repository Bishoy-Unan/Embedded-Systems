
#include"STD_TYPES.h"
#include"SWITCH.h"
#include"SWITCH_Config.h"
#include"MRCC_Interface.h"



int
main(int argc, char* argv[])
{
	u8 Button;

	/*RCC Configuration*/
	RCC_enuControlClk(RCC_HSE,RCC_CLK_ON);
	RCC_enuSelectSystemClk(RCC_HSE);
	RCC_enuEnablePeripheralClock(RCC_AHB1,GPIOA_RCC);

	SWITCH_enumdInit();
	SWITCH_enuGetSwitchState(SWITCH1,&Button);
  while (1)
    {

    }
}
