/*
 * UART_program.c
 *
 *  Created on: Mar 26, 2024
 *      Author: Lenovo
 */
#include "BIT_MATH.h"
#include "STD_types.h"
#include "UART_private.h"
#include "UART_interface.h"

#include "GPIO_interface.h"


static void (*USART1Transmit_CallBack)(void)=NULL;

static void (*USART2Transmit_CallBack)(void)=NULL;

static void (*USART6Transmit_CallBack)(void)=NULL;

static void (*USART1Receive_CallBack)(void)=NULL;

static void (*USART2Receive_CallBack)(void)=NULL;

static void (*USART6Receive_CallBack)(void) = NULL;

void USART1Transmit_voidSetCallBack(void (*USART1_PFunc)(void))
{
	USART1Transmit_CallBack = USART1_PFunc;
}

void USART2Transmit_voidSetCallBack(void (*USART2_PFunc)(void))
{
	USART2Transmit_CallBack = USART2_PFunc;
}

void USART6Transmit_voidSetCallBack(void (*USART6_PFunc)(void))
{
	USART6Transmit_CallBack = USART6_PFunc;
}


void USART1Receive_voidSetCallBack(void (*USART1_PFunc)(void))
{
	USART1Receive_CallBack = USART1_PFunc;
}

void USART2Receive_voidSetCallBack(void (*USART2_PFunc)(void))
{
	USART2Receive_CallBack = USART2_PFunc;
}

void USART6Receive_voidSetCallBack(void (*USART6_PFunc)(void))
{
	USART6Receive_CallBack = USART6_PFunc;
}


void UART1_Init(void)
{
	//baud rate 9600
	((USART_t *)USART1)->BPR = 0x683;

	// enable transmitter
	SET_BIT(((USART_t *)USART1)->CR1,3);
	// enable receiver
	SET_BIT(((USART_t *)USART1)->CR1,2);

	// enable receive interrupt
	SET_BIT(((USART_t *)USART1)->CR1,5);

	// Transmission complete interrupt enable
	SET_BIT(((USART_t *)USART1)->CR1,6);

	//clear the status register
	((USART_t *)USART1)->SR = 0x0;

	//enable uart1
	SET_BIT(((USART_t *)USART1)->CR1,13);
}

void UART2_Init(void)
{

	//baud rate 9600
	((USART_t *)USART2)->BPR = 0x683;


	SET_BIT(((USART_t *)USART2)->CR1,3);
	SET_BIT(((USART_t *)USART2)->CR1,2);

	// enable receive interrupt
	SET_BIT(((USART_t *)USART2)->CR1,5);

	// Transmission complete interrupt enable
	SET_BIT(((USART_t *)USART2)->CR1,6);

	((USART_t *)USART2)->SR = 0x0;

	SET_BIT(((USART_t *)USART2)->CR1,13);

}


void UART6_Init(void)
{

	//baud rate 9600
	((USART_t *)USART6)->BPR = 0x683;


	SET_BIT(((USART_t *)USART6)->CR1,3);
	SET_BIT(((USART_t *)USART6)->CR1,2);

	// enable receive interrupt
	SET_BIT(((USART_t *)USART6)->CR1,5);

	// Transmission complete interrupt enable
	//SET_BIT(((USART_t *)USART6)->CR1,6);

	((USART_t *)USART6)->SR = 0x0;

	SET_BIT(((USART_t *)USART6)->CR1,13);
}

void USARTSendByte(void* ptr_voidUSARTNum,u8 byteData)
{
	//wait
	(((USART_t *) ptr_voidUSARTNum)->DR) = byteData;
	while(GET_BIT(((USART_t *) ptr_voidUSARTNum)->SR,6) == 0);

}

void USARTSendByteAsynch(void* ptr_voidUSARTNum,u8 byteData)
{

	// send data
	(((USART_t *) ptr_voidUSARTNum)->DR) = byteData;

}

u8 USARTRecieveByte(void* ptr_voidUSARTNum)
{

	while(GET_BIT(((USART_t *) ptr_voidUSARTNum)->SR,5) == 0);
	return (u8)(((USART_t *) ptr_voidUSARTNum)->DR);

}


u8 USARTRecieveByteAsynchDone(void* ptr_voidUSARTNum)
{
	return (u8)(((USART_t *) ptr_voidUSARTNum)->DR);
}



void USART1_IRQHandler(void)
{
	// transmit done
	if(GET_BIT(((USART_t *) USART1)->SR,6) == 1 )
	{
		if(USART1Transmit_CallBack != NULL)
		{
			USART1Transmit_CallBack();
		}

	}

	// receive done
	if(GET_BIT(((USART_t *) USART1)->SR,5) == 1)
	{
		if(USART1Receive_CallBack != NULL)
		{
			USART1Receive_CallBack();
		}

	}

}

void USART2_IRQHandler(void)
{
	// transmit done
			if(GET_BIT(((USART_t *) USART2)->SR,6) == 1 )
			{

				if(USART2Transmit_CallBack != NULL)
				{
					USART2Transmit_CallBack();

				}

			}

			// receive done
			if(GET_BIT(((USART_t *) USART2)->SR,5) == 1)
			{

				if(USART2Receive_CallBack != NULL)
				{

					USART2Receive_CallBack();
				}

			}
			//((USART_t *)USART6)->SR = 0x0;


}

void USART6_IRQHandler(void)
{

	// transmit done
		if(GET_BIT(((USART_t *) USART6)->SR,6) == 1 )
		{

			if(USART6Transmit_CallBack != NULL)
			{
				USART6Transmit_CallBack();

			}

		}

		// receive done
		if(GET_BIT(((USART_t *) USART6)->SR,5) == 1)
		{

			if(USART6Receive_CallBack != NULL)
			{

				USART6Receive_CallBack();
			}

		}
		//((USART_t *)USART6)->SR = 0x0;

}
