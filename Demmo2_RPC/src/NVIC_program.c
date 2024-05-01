/*
 * NVIC_program.c
 *
 *  Created on: Mar 22, 2024
 *      Author: Lenovo
 */


#include "BIT_MATH.h"
#include "STD_types.h"
#include "NVIC_private.h"
#include "NVIC_interface.h"

void MNVIC_voidEnableInterrupt(u8 Copy_u8IntNum)
{
	u8 index = (u8)(Copy_u8IntNum / 32);
	u8 interrupt_num = (u8)(Copy_u8IntNum - (index * 32));
	SET_BIT(NVIC_REG->ISER[index],interrupt_num);


}
void MNVIC_voidDisableInterrupt(u8 Copy_u8IntNum)
{
	u8 index = (u8)(Copy_u8IntNum / 32);
	u8 interrupt_num = (u8)(Copy_u8IntNum - (index * 32));
	SET_BIT(NVIC_REG->ICER[index],interrupt_num);
}

void MNVIC_voidEnableInterruptPending(u8 Copy_u8IntNum)
{
	u8 index = (u8)(Copy_u8IntNum / 32);
	u8 interrupt_num = (u8)(Copy_u8IntNum - (index * 32));
	SET_BIT(NVIC_REG->ISPR[index],interrupt_num);

}

void MNVIC_voidDisableInterruptPending(u8 Copy_u8IntNum)
{
	u8 index = (u8)(Copy_u8IntNum / 32);
	u8 interrupt_num = (u8)(Copy_u8IntNum - (index * 32));
	SET_BIT(NVIC_REG->ICPR[index],interrupt_num);
}

u8   MNVIC_u8InterruptActive(u8 Copy_u8IntNum)
{
	u8 index = (u8)(Copy_u8IntNum / 32);
	u8 interrupt_num = (u8)(Copy_u8IntNum - (index * 32));
	return (GET_BIT(NVIC_REG->IABR[index],interrupt_num));
}

/*
void MNVIC_voidInitInterruptGroup(NVIC_GroupMode_t Copy_uddtGroupMode)
{

}

void MNVIC_voidSetInterruptPriority(u8 Copy_u8IntNum ,NVIC_GroupMode_t Copy_uddtGroupMode,u8 Copy_GroupPriority,u8 Copy_SubPriority)
{

}

//void MNVIC_voidSetInterruptPriority(NVIC_PriorityConfig_t* Copy_PuddtPriorityConfig) ;

*/
