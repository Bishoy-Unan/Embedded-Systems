#include"../LIB/STD_TYPES.h"
#include"../MCAL/ADC/ADC_Interface.h"



void fi(void)
{
	
}

int main(void)
{
	u8 length =3;
	u8  chan[] = {1,3,5};
	u8 Res[]={0};	
	ADC_strChannelChain_t chain = {length,chan,Res,fi};
	ADC_enuInit();
	ADC_enuStartConversionAsynch(& chain);
	
    while(1)
    {
       
    }
}