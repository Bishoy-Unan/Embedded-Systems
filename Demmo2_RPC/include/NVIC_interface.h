/*
 * NVIC_interface.h
 *
 *  Created on: Mar 22, 2024
 *      Author: Lenovo
 */

#ifndef NVIC_INTERFACE_H_
#define NVIC_INTERFACE_H_


void MNVIC_voidEnableInterrupt(u8 Copy_u8IntNum);
void MNVIC_voidDisableInterrupt(u8 Copy_u8IntNum);
void MNVIC_voidEnableInterruptPending(u8 Copy_u8IntNum);
void MNVIC_voidDisableInterruptPending(u8 Copy_u8IntNum);
u8   MNVIC_u8InterruptActive(u8 Copy_u8IntNum);
//void MNVIC_voidInitInterruptGroup(NVIC_GroupMode_t Copy_uddtGroupMode);
//void MNVIC_voidSetInterruptPriority(u8 Copy_u8IntNum ,NVIC_GroupMode_t Copy_uddtGroupMode,u8 Copy_GroupPriority,u8 Copy_SubPriority);
//void MNVIC_voidSetInterruptPriority(NVIC_PriorityConfig_t* Copy_PuddtPriorityConfig) ;


#endif /* NVIC_INTERFACE_H_ */
