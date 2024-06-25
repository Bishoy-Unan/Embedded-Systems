/*******************************************************************************/
/*******************************************************************************/
/***********************   GRADUATION PROJECT : (FOTA)   ***********************/
/***********************   Layer :Application   ***********************/
/*******************************************************************************/
/*******************************************************************************/

#include "../../6-Library/STD_TYPES.h"
#include "../../1-MCAL/01-GPIO/GPIO_interface.h"
#include "../../3-SERVICE/02-SYS/SYS_interface.h"
#include "../../1-MCAL/08-FPEC/FPEC_interface.h"
#include "../../1-MCAL/05-USART/USART_interface.h"
#include "../../1-MCAL/02-RCC/RCC_register.h"

#include "../../2-HAL/01-LED/LED_interface.h"

/******************** function to initlize the sp *****************/
static inline void __set_MSP(u32 topOfMainStack) {
    __asm volatile ("MSR msp, %0" : : "r" (topOfMainStack) : );
}


/*************** to do a soft reset ****************/

#define SCB_AIRCR *((volatile unsigned int *)0xE000ED0C)
#define VECTKEY    0x5FA
#define SYSRESETREQ_BIT 2

void PerformSoftwareReset(void)
{
    // Write the key and set the SYSRESETREQ bit to trigger a software reset
	RCC->CSR |= (1 << 24);
    SCB_AIRCR = (VECTKEY << 16) | (1 << SYSRESETREQ_BIT);
}


/* Declare a variable at a specific address in Flash */
u16 BOOT_u8REQUESTFLAG __attribute__((section(".my_section")))  ;// Initial value
;

#define SCB_VTOR   							(*((volatile u32*)0xE000ED08))

u16 update =1;


void APP1(void) ;
void APP2(void) ;

typedef void (*Application)(void) ;

Application AddrAPP1 ;
Application AddrAPP2 ;



u8 ok[]={"o"};

#define BOOT_u8REQUESTFLAG					0x08003C00

LED_t LED1 = {LED_PORTA,LED_PIN4,LED_ACTIVE_HIGH};
LED_t LED2 = {LED_PORTA,LED_PIN7,LED_ACTIVE_HIGH};
int main(void)
{
	//Initialization
	SYS_voidAppInit();
	volatile u8 Flashing_check=0;

	LED_voidLedOn(&LED1);
	LED_voidLedOn(&LED2);
	while(1){
		Flashing_check=USART_u8ReceiveChar(USART1);
		USART_voidTransmitSync(USART1,ok);
		FPEC_voidFlashPageErase(15);
		FPEC_voidFlashWrite(BOOT_u8REQUESTFLAG, &update, 1);

        // Set vector table base address to bootloader start address
        //SCB_VTOR = 0x08000000;
		PerformSoftwareReset();
	}

}


void APP1(void)
{

	   SCB_VTOR = 0x08000000;
	   AddrAPP1 = *(Application *)(0x08000004);
	   AddrAPP1();

}

