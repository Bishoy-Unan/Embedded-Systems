#include "STD_types.h"
#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "SWITCH_interface.h"
#include "NVIC_interface.h"
#include "UART_interface.h"
#include "Sched.h"

u8 dataReceived;

u8 array[2]={0};

u8 counter=0;

void uart6_ReceiveDone();
//void uart6_TransmitDone();

void Systick_App(void);

void SWITCHApp_runnuble(void);
extern void SWITCH_Runnuble(void);

void service1_sendPinStatus(void);
void service(void);

int main(void)
{

	runnable_t runnables[3] =
		{
				{.name="runnable1",.priority=0,.periodicityMs=5,.delayMS=0,.cb= SWITCH_Runnuble},
				{.name="runnable2",.priority=1,.periodicityMs=300,.delayMS=0,.cb= SWITCHApp_runnuble},
				{.name="runnable3",.priority=2,.periodicityMs=100,.delayMS=0,.cb= service}
		};

	RCC_voidInitSystemClock();
	RCC_voidEnablePeripheralClock(AHB1,RCC_PERIPHERIAL_EN_GPIOB);
	RCC_voidEnablePeripheralClock(AHB1,RCC_PERIPHERIAL_EN_GPIOA);
	GPIO_voidSetPinMode(GPIOB,GPIO_PIN1,GPIO_PIN_OUTPUT);
	GPIO_voidSetPinValue(GPIOB,GPIO_PIN1,GPIO_PIN_LOW);


	SWITCH_init();
	//enable clock for UART6
	RCC_voidEnablePeripheralClock(APB2,5);
	// enable UART6 pins
	GPIO_voidSetPinMode(GPIOA,GPIO_PIN11,GPIO_PIN_ALTF);
	GPIO_voidSetPinMode(GPIOA,GPIO_PIN12,GPIO_PIN_ALTF);
	GPIO_voidSetAlternateFunction(GPIOA,8,11);
	GPIO_voidSetAlternateFunction(GPIOA,8,12);
	// set Receive call back function
	USART6Receive_voidSetCallBack(uart6_ReceiveDone);
	//enable interrupt for UART6
	MNVIC_voidEnableInterrupt(71);

    UART6_Init();

	sched_init();
	sched_register_runnable(&runnables[0]);
	sched_register_runnable(&runnables[1]);
	sched_register_runnable(&runnables[2]);
	sched_start();
	while (1)
	{
		   // Add your code here.
	}
}

void service(void)
{
	if(counter == 2)
	{
		switch(array[0])
			{
			case 0:
				service1_sendPinStatus();
				break;

			case 1:
					break;

			default:
			break;

			}

	}


}

void service1_sendPinStatus(void)
{
	// xx 00 0000
	//
	u8 pin;
	u8 port;
	u8 pinValue=5;
	if(counter == 2)
	{
		pin = (array[1] & 0x0F);
		port = ((array[1]>>4) & 0x03);
		switch(port)
		{
		case 0:
			GPIO_voidSetGetPinValue(GPIOA,pin,&pinValue);
			break;

		case 1:
			GPIO_voidSetGetPinValue(GPIOB,pin,&pinValue);
			break;

		case 2:

			GPIO_voidSetGetPinValue(GPIOC,pin,&pinValue);
			break;

		default:
		break;

		}
		if(pinValue == 0)
		{
			USARTSendByte(USART6,'0');

		}
		else if(pinValue == 1)
		{
			USARTSendByte(USART6,'1');

		}

		counter = 0;
		array[0]=0;
		array[1]=0;

	}



}

void SWITCHApp_runnuble(void)
{
	if(SWITCH_getState(SWITCH_1) == SWITCH_PULLUP_PRESSED)
	{
		GPIO_voidSetPinValue(GPIOB,GPIO_PIN1,GPIO_PIN_HIGH);
		//USARTSendByte(USART6,'0');

	}
	else
	{
		GPIO_voidSetPinValue(GPIOB,GPIO_PIN1,GPIO_PIN_LOW);
	}
	/*else if(SWITCH_getState(SWITCH_2) == SWITCH_PULLUP_PRESSED)
	{
		GPIO_voidSetPinValue(GPIOB,GPIO_PIN1,GPIO_PIN_LOW);
		//USARTSendByte(USART6,'1');
	}*/

}



void uart6_ReceiveDone()
{
	if(counter != 2)
	{
		array[counter] = USARTRecieveByteAsynchDone(USART6);
		counter++;
	}

	/*if(dataReceived == 'A')
	{
		GPIO_voidSetPinValue(GPIOB,GPIO_PIN7,GPIO_PIN_HIGH);

	}
	else if(dataReceived == 'B')
	{
		GPIO_voidSetPinValue(GPIOB,GPIO_PIN7,GPIO_PIN_LOW);

	}*/
}
