/*
 * UART_interface.h
 *
 *  Created on: Mar 26, 2024
 *      Author: Lenovo
 */

#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_



#define USART1_BASE_ADDRESS		0x40011000
#define USART2_BASE_ADDRESS		0x40004400
#define USART6_BASE_ADDRESS		0x40011400

#define USART1	((void*)(USART1_BASE_ADDRESS))
#define USART2	((void*)(USART2_BASE_ADDRESS))
#define USART6	((void*)(USART6_BASE_ADDRESS))

void UART1_Init(void);

void UART2_Init(void);

void UART6_Init(void);

void USARTSendByte(void* ptr_voidUSARTNum,u8 byteData);
void USARTSendByteAsynch(void* ptr_voidUSARTNum,u8 byteData);

u8 USARTRecieveByte(void* ptr_voidUSARTNum);

void USART1Transmit_voidSetCallBack(void (*USART1_PFunc)(void));

void USART2Transmit_voidSetCallBack(void (*USART2_PFunc)(void));

void USART6Transmit_voidSetCallBack(void (*USART6_PFunc)(void));

void USART1Receive_voidSetCallBack(void (*USART1_PFunc)(void));

void USART2Receive_voidSetCallBack(void (*USART2_PFunc)(void));

void USART6Receive_voidSetCallBack(void (*USART6_PFunc)(void));

u8 USARTRecieveByteAsynchDone(void* ptr_voidUSARTNum);

#endif /* UART_INTERFACE_H_ */
