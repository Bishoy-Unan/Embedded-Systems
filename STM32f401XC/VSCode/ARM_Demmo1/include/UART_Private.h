

#ifndef UART_PRIVATE_H
#define UART_PRIVATE_H

#define  ENABLE       1
#define  DISABLE      0

#define UART_RX_NOT_EMPTY_FLAG 0X00000020

/**
 *@ uart periphral registers 
*/
typedef struct
{
	volatile u32 SR;
	volatile u32 DR;
	volatile u32 BRR;
	volatile u32 CR1;
	volatile u32 CR2;
	volatile u32 CR3;
	volatile u32 CR4;

}UART_strRegisters_t;


/**
 *@ Base addresses of UART periphrals 
*/
#define UART1	((UART_strRegisters_t*)0x40011000)
#define UART2	((UART_strRegisters_t*)0x40004400)
#define UART6	((UART_strRegisters_t*)0x40011400)








#endif
