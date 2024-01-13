#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../MCAL/DIO_04/DIO.h"
#include "../MCAL/DIO_04/DIO_Private.h"
#include "../MCAL/Delay_Function/delay_function.h"
#include "../HAL/KeyPad/KeyPad.h"
#include "../HAL/KeyPad/KeyPad_Config.h"
#include "../HAL/LED/LED.h"
#include "../HAL/LED/LED_Config.h"

int main(void)
{
	
	/**
	*@ LOCAL_u8Button1 variable to check that any switch  pressed or not
	*/
	u8 LOCAL_u8Button1 ; 
	
	KEYPAD_enuInit();
	LED_enumdInit();
	
    while(1)
    {
		KEYPAD_enuGetPressedKey( & LOCAL_u8Button1 );
		switch(LOCAL_u8Button1)
		{
			case '+':
				
					LED_enuSetLedState(LED1,LED_enumActiveHigh_ON);
					
				
			break;
			case '/':
					LED_enuSetLedState(LED1,LED_enumActiveHigh_OFF);
					
			break;
			default:
			break;
			
			
		}/*switch*/
        
    }/*while 1*/

}/*main function*/