/*
 * UART_private.h
 *
 *  Created on: Mar 26, 2024
 *      Author: Lenovo
 */

#ifndef UART_PRIVATE_H_
#define UART_PRIVATE_H_



typedef struct
{
	u32 volatile SR;
	u32 volatile DR;
	u32 volatile BPR;
	u32 volatile CR1;
	u32 volatile CR2;
	u32 volatile CR3;
	u32 volatile GTPR;

}USART_t;


#endif /* UART_PRIVATE_H_ */
