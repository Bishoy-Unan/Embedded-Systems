/*
 * GPIO_program.c
 *
 *  Created on: Feb 17, 2024
 *      Author: Aml Ashraf
 */
#include "BIT_MATH.h"
#include "STD_types.h"
#include "GPIO_private.h"
#include "GPIO_interface.h"

void GPIO_voidSetPinMode(void* ptr_voidPortNum,u8 Copy_u8PinNum, u8 Copy_u8PinMode)
{
	/*first solution
	 * this solution to avoid redundancy which happened in switch case solution
	 *
	 * */
	((GPIO_t*)ptr_voidPortNum)->MODE &= (u32)(~(3U<<Copy_u8PinNum * 2U));
	((GPIO_t*)ptr_voidPortNum)->MODE |= (u32)(Copy_u8PinMode<<Copy_u8PinNum * 2U);


	/*the second solution using switch case */

	/*switch(Copy_u8PortNum)
	{
		case GPIO_PORTA:
			GPIOA->MODE &= (u32)(~(3U<<Copy_u8PinNum * 2U));
			GPIOA->MODE |= (u32)(Copy_u8PinMode<<Copy_u8PinNum * 2U);
			break;

		case GPIO_PORTB:
			GPIOB->MODE &= (u32)(~(3U<<Copy_u8PinNum * 2U));
			GPIOB->MODE |= (u32)(Copy_u8PinMode<<Copy_u8PinNum * 2U);
			break;

		case GPIO_PORTC:
			GPIOC->MODE &= (u32)(~(3U<<Copy_u8PinNum * 2U));
			GPIOC->MODE |= (u32)(Copy_u8PinMode<<Copy_u8PinNum * 2U);
			break;
		default:
			break;

	}*/

}


void GPIO_voidSetOutputType(void* ptr_voidPortNum,u8 Copy_u8PinNum, u8 Copy_u8PinOutType)
{

	/*first solution
	 * this solution to avoid redundancy which happened in switch case solution
	 *
	 * */

	((GPIO_t*)ptr_voidPortNum)->OTYPER &= (u32)(~(1<<Copy_u8PinNum));
	((GPIO_t*)ptr_voidPortNum)->OTYPER |= (u32)(Copy_u8PinOutType<<Copy_u8PinNum);


	/*the second solution using switch case */
	/*
	switch(Copy_u8PortNum)
		{
			case GPIO_PORTA:
				GPIOA->OTYPER &= (u32)(~(1<<Copy_u8PinNum));
				GPIOA->OTYPER |= (u32)(Copy_u8PinOutType<<Copy_u8PinNum);
				break;

			case GPIO_PORTB:
				GPIOB->OTYPER &= (u32)(~(1<<Copy_u8PinNum));
				GPIOB->OTYPER |= (u32)(Copy_u8PinOutType<<Copy_u8PinNum);
				break;

			case GPIO_PORTC:
				GPIOC->OTYPER &= (u32)(~(1<<Copy_u8PinNum));
				GPIOC->OTYPER |= (u32)(Copy_u8PinOutType<<Copy_u8PinNum);
				break;
			default:
				break;

		}*/

}

void GPIO_voidSetOutputPinSpeed(void* ptr_voidPortNum,u8 Copy_u8PinNum, u8 Copy_u8PinOutSpeed)
{

	/*first solution
	 * this solution to avoid redundancy which happened in switch case solution
	 *
	 * */
	((GPIO_t*)ptr_voidPortNum)->OSPEEDR &= (u32)(~(3U<<Copy_u8PinNum * 2U));
	((GPIO_t*)ptr_voidPortNum)->OSPEEDR |= (u32)(Copy_u8PinOutSpeed<<Copy_u8PinNum * 2U);

	/*the second solution using switch case */
	/*
	switch(Copy_u8PortNum)
		{
			case GPIO_PORTA:
				GPIOA->OSPEEDR &= (u32)(~(3U<<Copy_u8PinNum * 2U));
				GPIOA->OSPEEDR |= (u32)(Copy_u8PinOutSpeed<<Copy_u8PinNum * 2U);
				break;

			case GPIO_PORTB:
				GPIOB->OSPEEDR &= (u32)(~(3U<<Copy_u8PinNum * 2U));
				GPIOB->OSPEEDR |= (u32)(Copy_u8PinOutSpeed<<Copy_u8PinNum * 2U);
				break;

			case GPIO_PORTC:
				GPIOC->OSPEEDR &= (u32)(~(3U<<Copy_u8PinNum * 2U));
				GPIOC->OSPEEDR |= (u32)(Copy_u8PinOutSpeed<<Copy_u8PinNum * 2U);
				break;
			default:
				break;

		}*/

}

void GPIO_voidSetPinPullValue(void* ptr_voidPortNum,u8 Copy_u8PinNum, u8 Copy_u8PullMode)
{

	/*first solution
	 * this solution to avoid redundancy which happened in switch case solution
	 *
	 * */
	((GPIO_t*)ptr_voidPortNum)->PUPDR &= (u32)(~(3U<<Copy_u8PinNum * 2U));
	((GPIO_t*)ptr_voidPortNum)->PUPDR |= (u32)(Copy_u8PullMode<<Copy_u8PinNum * 2U);

	/*the second solution using switch case */
	/*
	switch(Copy_u8PortNum)
		{
			case GPIO_PORTA:
				GPIOA->PUPDR &= (u32)(~(3U<<Copy_u8PinNum * 2U));
				GPIOA->PUPDR |= (u32)(Copy_u8PullMode<<Copy_u8PinNum * 2U);
				break;

			case GPIO_PORTB:
				GPIOB->PUPDR &= (u32)(~(3U<<Copy_u8PinNum * 2U));
				GPIOB->PUPDR |= (u32)(Copy_u8PullMode<<Copy_u8PinNum * 2U);
				break;

			case GPIO_PORTC:
				GPIOC->PUPDR &= (u32)(~(3U<<Copy_u8PinNum * 2U));
				GPIOC->PUPDR |= (u32)(Copy_u8PullMode<<Copy_u8PinNum * 2U);
				break;
			default:
				break;

		}*/

}


void GPIO_voidSetPinValue(void* ptr_voidPortNum,u8 Copy_u8PinNum, u8 Copy_u8Pinvalue)
{
	u32 var;

	/*first solution
	 * this solution to avoid redundancy which happened in switch case solution
	 *
	 * */
	var = ((GPIO_t*)ptr_voidPortNum)->ODR;
	var &= (u32)(~(1<<Copy_u8PinNum));
	var |= (Copy_u8Pinvalue<<Copy_u8PinNum);
	((GPIO_t*)ptr_voidPortNum)->ODR = var;

	/*the second solution using switch case */
	/*
	switch(Copy_u8PortNum)
		{
			case GPIO_PORTA:
				var = GPIOA->ODR;
				var &= (u32)(~(1<<Copy_u8PinNum));
				var |= (Copy_u8Pinvalue<<Copy_u8PinNum);
				GPIOA->ODR = var;
				break;

			case GPIO_PORTB:
				var = GPIOB->ODR;
				var &= (u32)(~(1<<Copy_u8PinNum));
				var |= (Copy_u8Pinvalue<<Copy_u8PinNum);
				GPIOB->ODR = var;
				break;

			case GPIO_PORTC:
				var = GPIOC->ODR;
				var &= (u32)(~(1<<Copy_u8PinNum));
				var |= (Copy_u8Pinvalue<<Copy_u8PinNum);
				GPIOC->ODR = var;
				break;
			default:
				break;

		}*/

}


void GPIO_voidSetPortValue(void* ptr_voidPortNum ,u16 Copy_u16Portvalue )
{

	/*first solution
	 * this solution to avoid redundancy which happened in switch case solution
	 *
	 * */

	((GPIO_t*)ptr_voidPortNum)->ODR = Copy_u16Portvalue;

	/*the second solution using switch case */
	/*
	switch(Copy_u8PortNum)
		{
			case GPIO_PORTA:
				GPIOA->ODR = Copy_u16Portvalue;
				break;

			case GPIO_PORTB:
				GPIOB->ODR = Copy_u16Portvalue;
				break;

			case GPIO_PORTC:
				GPIOC->ODR = Copy_u16Portvalue;
				break;
			default:
				break;

		}*/

}

void GPIO_voidSetGetPinValue(void* ptr_voidPortNum,u8 Copy_u8PinNum, u8 * Copy_pu8Pinvalue)
{
	/*first solution
	 * this solution to avoid redundancy which happened in switch case solution
	 *
	 * */

	*Copy_pu8Pinvalue = ((((GPIO_t*)ptr_voidPortNum)->IDR>>Copy_u8PinNum) & 0x1);

	/*the second solution using switch case */
	/*
	switch(Copy_u8PortNum)
		{
			case GPIO_PORTA:
				*Copy_pu8Pinvalue = ((GPIOA->IDR>>Copy_u8PinNum) & 0x1);
				break;

			case GPIO_PORTB:
				*Copy_pu8Pinvalue = ((GPIOB->IDR>>Copy_u8PinNum) & 0x1);
				break;

			case GPIO_PORTC:
				*Copy_pu8Pinvalue = ((GPIOC->IDR>>Copy_u8PinNum) & 0x1);
				break;
			default:
				break;

		}*/

}

void GPIO_voidSetAlternateFunction(void* ptr_voidPortNum,u8 Copy_u8AlternateFunNum,u8 Copy_u8PinNum)
{
	if(Copy_u8AlternateFunNum >= 0 && Copy_u8AlternateFunNum < 8)
	{
		((GPIO_t*)ptr_voidPortNum)->AFRL &= (u32)(~(15U<<Copy_u8AlternateFunNum * 4U));
		//((GPIO_t*)ptr_voidPortNum)->AFRL |= (u32)(Copy_u8AlternateFunNum<<Copy_u8AlternateFunNum * 4U);
		((GPIO_t*)ptr_voidPortNum)->AFRL |= (u32)(Copy_u8AlternateFunNum<<Copy_u8PinNum * 4U);
	}

	else if(Copy_u8AlternateFunNum > 7 && Copy_u8AlternateFunNum < 16)
	{
		((GPIO_t*)ptr_voidPortNum)->AFRH &= (u32)(~(15U<<Copy_u8AlternateFunNum * 4U));
		//((GPIO_t*)ptr_voidPortNum)->AFRH |= (u32)(Copy_u8AlternateFunNum<<Copy_u8AlternateFunNum * 4U);

		((GPIO_t*)ptr_voidPortNum)->AFRH |= (u32)(Copy_u8AlternateFunNum<<(Copy_u8PinNum % 8) * 4U);
	}
}

void MGPIO_voidSetSubPortValue(void*  ptr_voidPortNum ,u8 Copy_u16SubPortvalue, u8 Copy_u8SubPort)
{

	Clr_BITS( ((GPIO_t*)ptr_voidPortNum)->ODR ,(255U<<Copy_u8SubPort * 8U) ) ;
	((GPIO_t*)ptr_voidPortNum)->ODR |= (u32)(Copy_u16SubPortvalue << Copy_u8SubPort * 8U);

}
