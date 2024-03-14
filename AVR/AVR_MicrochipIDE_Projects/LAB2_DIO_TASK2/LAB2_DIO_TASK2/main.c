#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_Private.h"
#include "DIO.h"
#include "DIO_CFG.h"
#include "Port.h"
#include "PortCFG.h"
#include<util/delay.h>


int main(void)
{
	u8 Local_u8Button = 1 ;
	DIO_enumPins_t SwitchPin = DIO_enumPIN0;
	DIO_enumInit();
	
    while(1)
    {
		
        DIO_voidGetPinVal(DIO_PORTB,SwitchPin,&Local_u8Button);
        if(Local_u8Button==0)
        {
			
	        PORTA +=1;
	        _delay_ms(1000);
        }
        
    }
}