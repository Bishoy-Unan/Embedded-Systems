

#ifndef UART_PRIVATE_H
#define UART_PRIVATE_H

#define  ENABLE       1
#define  DISABLE      0



/**
 *@ uart periphral registers 
*/
typedef struct
{
	u32 SR;
	u32 DR;
	u32 BRR;
	u32 CR1;
	u32 CR2;
	u32 CR3;
	u32 CR4;

}UART_strRegisters_t;


/**
 *@ Base addresses of UART periphrals 
*/
#define UART1	((UART_strRegisters_t*)0x40011000)
#define UART2	((UART_strRegisters_t*)0x40004400)
#define UART6	((UART_strRegisters_t*)0x40011400)








#endif