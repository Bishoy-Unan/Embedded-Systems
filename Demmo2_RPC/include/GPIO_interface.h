/*
 * GPIO_interface.h
 *
 *  Created on: Feb 17, 2024
 *      Author: Aml Ashraf
 */

#ifndef GPIO_INTERFACE_H_
#define GPIO_INTERFACE_H_

#include "STD_types.h"

#define GPIOA_BASE_ADDRESS		0x40020000
#define GPIOB_BASE_ADDRESS		0x40020400
#define GPIOC_BASE_ADDRESS		0x40020800

#define GPIOA	((void*)(GPIOA_BASE_ADDRESS))
#define GPIOB	((void*)(GPIOB_BASE_ADDRESS))
#define GPIOC	((void*)(GPIOC_BASE_ADDRESS))

/******************************/
#define	GPIO_PIN0			0
#define	GPIO_PIN1			1
#define	GPIO_PIN2			2
#define	GPIO_PIN3			3
#define	GPIO_PIN4			4
#define	GPIO_PIN5			5
#define	GPIO_PIN6			6
#define	GPIO_PIN7			7
#define	GPIO_PIN8			8
#define	GPIO_PIN9			9
#define	GPIO_PIN10			10
#define	GPIO_PIN11			11
#define	GPIO_PIN12			12
#define	GPIO_PIN13			13
#define	GPIO_PIN14			14
#define	GPIO_PIN15			15

/**********************************/
#define GPIO_PIN_INPUT		0
#define GPIO_PIN_OUTPUT		1
#define GPIO_PIN_ALTF		2
#define GPIO_PIN_ANALOG		3


/***********************************/
#define GPIO_OUTPUT_PUSH_PULL		0
#define GPIO_OUTPUT_OPEN_DRAIN		1


/***********************************/

#define GPIO_OUTPUT_SPEED_LOW		0
#define GPIO_OUTPUT_SPEED_MID		1
#define	GPIO_OUTPUT_SPEED_HIGH		2
#define GPIO_OUTPUT_SPEED_VHIGH		3

/***********************************/
#define GPIO_PIN_FLOAT				0
#define GPIO_PIN_PULL_UP			1
#define GPIO_PIN__PULL_DOWN			2

/************************************/
#define GPIO_PIN_LOW				0
#define GPIO_PIN_HIGH				1

void GPIO_voidSetPinMode(void* ptr_voidPortNum,u8 Copy_u8PinNum, u8 Copy_u8PinMode);

void GPIO_voidSetOutputType(void* ptr_voidPortNum,u8 Copy_u8PinNum, u8 Copy_u8PinOutType);

void GPIO_voidSetOutputPinSpeed(void* ptr_voidPortNum,u8 Copy_u8PinNum, u8 Copy_u8PinOutSpeed);

void GPIO_voidSetPinPullValue(void* ptr_voidPortNum,u8 Copy_u8PinNum, u8 Copy_u8PullMode);

void GPIO_voidSetPinValue(void* Copy_u8PortNum,u8 Copy_u8PinNum, u8 Copy_u8Pinvalue);

void GPIO_voidSetPortValue(void* ptr_voidPortNum,u16 Copy_u16Portvalue );

void GPIO_voidSetGetPinValue(void* ptr_voidPortNum,u8 Copy_u8PinNum, u8 * Copy_pu8Pinvalue);

void GPIO_voidSetAlternateFunction(void* ptr_voidPortNum,u8 Copy_u8AlternateFunNum,u8 Copy_u8PinNum);

void MGPIO_voidSetSubPortValue(void*  ptr_voidPortNum ,u8 Copy_u16SubPortvalue, u8 Copy_u8SubPort);

#endif /* GPIO_INTERFACE_H_ */
