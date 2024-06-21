/*******************************************************************************/
/*******************************************************************************/
/***********************   GRADUATION PROJECT : (FOTA)   ***********************/
/***********************   Layer :App ECU Application   ***********************/
/***********************   DATE : 10/5/2022 			 ***********************/
/*******************************************************************************/
/*******************************************************************************/

#include "../../6-Library/STD_TYPES.h"
#include "../../1-MCAL/01-GPIO/GPIO_interface.h"
#include "../../3-SERVICE/02-SYS/SYS_interface.h"
#include "../../1-MCAL/08-FPEC/FPEC_interface.h"

#include "../../2-HAL/01-LED/LED_interface.h"


#define BOOT_u8REQUESTFLAG					0x080028C0

LED_t LED1 = {LED_PORTA,LED_PIN2,LED_ACTIVE_HIGH};
//LED_t LED2 = {LED_PORTB,LED_PIN1,LED_ACTIVE_HIGH};
int main(void)
{
	//Initialization
	SYS_voidAppInit();

	u16 Update = 0;

	LED_voidLedOn(&LED1);
	//LED_voidLedOn(&LED2);
	//FPEC_voidFlashPageErase(10);
	//FPEC_voidFlashWrite(BOOT_u8REQUESTFLAG, &Update, 1);
	while(1);

}
