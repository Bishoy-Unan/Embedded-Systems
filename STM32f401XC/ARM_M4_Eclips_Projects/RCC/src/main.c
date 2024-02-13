


#include "STD_TYPES.h"
#include "MRCC_Interface.h"





int main()
{
	RCC_structCLKPLL_t PLLCFG = {PLL_HSE_SRC,25,336,4,2};
	RCC_enuControlClk(RCC_HSE,RCC_CLK_ON);
	RCC_enuSelectSystemClk(RCC_HSE);

	RCC_enuConfigPLL(&PLLCFG);
	RCC_enuEnablePeripheralClock(RCC_AHB1,GPIOA_RCC);
	RCC_enuDisablePeripheralClock(RCC_AHB1,GPIOA_RCC);
	RCC_enuControlBusesPrescaler(RCC_AHB1,AHB_SYSTEM_CLOCK_DIVIDED_BY_2);

  while (1)
    {

    }
  return 0;
}



// ----------------------------------------------------------------------------
