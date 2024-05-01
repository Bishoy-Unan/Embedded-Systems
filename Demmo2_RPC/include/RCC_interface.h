/*
 * RCC_interface.h
 *
 *  Created on: Feb 7, 2024
 *      Author: Aml Ashraf
 */

#ifndef RCC_INTERFACE_H_
#define RCC_INTERFACE_H_

#include "STD_types.h"

/*RCC system clock options*/
#define RCC_SYSCLK_HSI                  0
#define RCC_SYSCLK_HSE                  1
#define RCC_SYSCLK_PLL                  2

#define RCC_CLKSRC						RCC_SYSCLK_HSI

#define HSE_MECH						0
#define HSE_RC							1

#define RCC_HSE_SRC						HSE_MECH

typedef enum
{
	AHB1 = 0 ,
	AHB2     ,
	APB1     ,
	APB2
}BusName_t;



/*AHB1 peripheral clock enable*/
#define RCC_PERIPHERIAL_EN_GPIOA        0U
#define RCC_PERIPHERIAL_EN_GPIOB        1U
#define RCC_PERIPHERIAL_EN_GPIOC        2U
#define RCC_PERIPHERIAL_EN_GPIOD        3U
#define RCC_PERIPHERIAL_EN_GPIOE        4U
#define RCC_PERIPHERIAL_EN_GPIOH        7U
#define RCC_PERIPHERIAL_EN_CRC          12U
#define RCC_PERIPHERIAL_EN_DMA1         21U
#define RCC_PERIPHERIAL_EN_DMA2         22U


/*AHB2 peripheral clock enable*/
#define RCC_PERIPHERIAL_EN_OTGFS        7U

/*APB1 peripheral clock enable*/
#define RCC_PERIPHERIAL_EN_TIM2       	0U
#define RCC_PERIPHERIAL_EN_TIM3       	1U
#define RCC_PERIPHERIAL_EN_TIM4       	2U
#define RCC_PERIPHERIAL_EN_TIM5       	3U
#define RCC_PERIPHERIAL_EN_WWDG       	11U
#define RCC_PERIPHERIAL_EN_SPI2        14U
#define RCC_PERIPHERIAL_EN_SPI3        15U
#define RCC_PERIPHERIAL_EN_USART2       17U
#define RCC_PERIPHERIAL_EN_I2C1        21U
#define RCC_PERIPHERIAL_EN_I2C2        22U
#define RCC_PERIPHERIAL_EN_I2C3        23U
#define RCC_PERIPHERIAL_EN_PWR         28U

/*APB2 peripheral clock enable*/
#define RCC_PERIPHERIAL_EN_TIM1       	0U
#define RCC_PERIPHERIAL_EN_USART1       4U
#define RCC_PERIPHERIAL_EN_USART6       5U
#define RCC_PERIPHERIAL_EN_ADC1       	8U
#define RCC_PERIPHERIAL_EN_SDIO       	11U
#define RCC_PERIPHERIAL_EN_SPI1         12U
#define RCC_PERIPHERIAL_EN_SPI4         13U
#define RCC_PERIPHERIAL_EN_SYSCFG      14U
#define RCC_PERIPHERIAL_EN_TIM9      	16U
#define RCC_PERIPHERIAL_EN_TIM10        17U
#define RCC_PERIPHERIAL_EN_TIM11        18U

void RCC_voidInitSystemClock(void);

void RCC_voidEnablePeripheralClock(BusName_t Copy_uddtBusName, u8  Copy_u8PerNum);

void RCC_voidDisablePeripheralClock(BusName_t Copy_uddtBusName, u8  Copy_u8PerNum);

void RCC_voidResetPeripheral(BusName_t Copy_uddtBusName, u8  Copy_u8PerNum);

void RCC_voidEnableSecuritySystem(void);

void RCC_voidDisableSecuritySystem(void);


#endif /* RCC_INTERFACE_H_ */
