
#include"STD_TYPES.h"
#include"MRCC_Interface.h"
#include"GPIO_Interface.h"


int
main(int argc, char* argv[])
{
	u8 var;
	/*variable to test GPIO*/
	GPIO_strPinConfg_t GPIOTest ={GPIOA,GPIO_PIN0,GPIO_MODE_ANALOG,GPIO_OUTPUT_SPEED_LOW};

	/*RCC Configuration*/
	RCC_enuControlClk(RCC_HSE,RCC_CLK_ON);
	RCC_enuSelectSystemClk(RCC_HSE);
	RCC_enuEnablePeripheralClock(RCC_AHB1,GPIOA_RCC);

	/*GPIO Test*/
	GPIO_enuInit( & GPIOTest );
	GPIO_enuSetPinValue( GPIOA, GPIO_PIN0 , GPIO_LOW);
	GPIO_enuGetPinValue(GPIOA,GPIO_PIN0,&var);

	//RCC_enuSelectSystemClk(RCC_HSE);


  while (1)
    {

    }
}
