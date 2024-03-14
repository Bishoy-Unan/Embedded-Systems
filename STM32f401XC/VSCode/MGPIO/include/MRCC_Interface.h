/**********************************************************************************************************************/
/* Author        : Bishoy Unan                                          
/* Version       : V0.0.0                                               
/* Date          : 5 Feb 2024                                           
/* Description   : MRCC_Interface.h --> Functions Prototypes            
/* Module Features  :                                                   
/*                 01- RCC_enuControlClk (RCC_enuSysClk_t Copy_enuClockSystem,RCC_enuClkStatus_t Copy_enuClkStatus)(); 
/*                 02- RCC_enuSelectSystemClk (RCC_enuSysClk_t Copy_enuSystemClock)();            					    
/*                 03- RCC_enuEnablePeripheralClock (RCC_Bus_t Copy_enuPeripheralBus, u8 Copy_u8PeripheralNumber)();    
/*                 04- RCC_enuDisablePeripheralClock (RCC_Bus_t Copy_enuPeripheralBus, u8 Copy_u8PeripheralNumber)();   
/*                 05- RCC_enuConfigPLL (RCC_structCLKPLL_t * Copy_structPLLCongif)();  							
/*                 06- RCC_enuControlBusesPrescaler  (RCC_Bus_t Copy_enuBus ,u8 Copy_u32APB2Prescaler)();  				
/************************************************************************************************************************/

#ifndef MRCC_INTERFACE_H_
#define MRCC_INTERFACE_H_

#include "STD_TYPES.h"
/*============================================================*/
/*================ PERIPHRALS ON BUSES =======================*/
/*============================================================*/

/*=========================== AHB1 ===========================*/
/**
*@ PERIPHRALS NUMBERS IN RCC_AHB1ENR REGISTERS ACCORDING TO IT'S POSITION IN THE REGISTER
*/
#define GPIOA_RCC                       0UL
#define GPIOB_RCC                       1UL
#define GPIOC_RCC                       2UL
#define GPIOD_RCC                       3UL
#define GPIOE_RCC                       4UL
#define GPIOH_RCC                       7UL
#define CRC_RCC                         12UL
#define DMA1_RCC                        21UL
#define DMA2_RCC                        22UL

/*=========================== AHB2 ===========================*/
#define OTGFS_RCC 7

/*=========================== APB1 ===========================*/
/**
*@ PERIPHRALS NUMBERS IN RCC_APB1ENR REGISTERS ACCORDING TO IT'S POSITION IN THE REGISTER
*/
#define TIM2_RCC                        0UL
#define TIM3_RCC                        1UL
#define TIM4_RCC                        2UL
#define TIM5_RCC                        3UL
#define WWDG_RCC                        11UL
#define SPI2_RCC                        14UL
#define SPI3_RCC                        15UL
#define USART2_RCC                      17UL
#define I2C1_RCC                        21UL
#define I2C2_RCC                        22UL
#define I2C3_RCC                        23UL
#define PWR_RCC                         28UL

/*=========================== APB2 ===========================*/
/**
*@ PERIPHRALS NUMBERS IN RCC_APB2ENR REGISTERS ACCORDING TO IT'S POSITION IN THE REGISTER
*/
#define TIM1_RCC                        0UL
#define USART1_RCC                      4UL
#define USART6_RCC                      5UL
#define ADC1_RCC                        8UL
#define SDIO_RCC                        11UL
#define SPI1_RCC                        12UL
#define SPI4_RCC                        13UL
#define SYSCFG_RCC                      14UL
#define TIM9_RCC                        16UL
#define TIM10_RCC                       17UL
#define TIM11_RCC                       18UL

/* ========================== AHB Prescalers ========================== */
#define MASK_AHB_PRESCALER                            0xFFFFFF0F
#define AHB_SYSTEM_CLOCK_NOT_DIVIDED                  0X00000000
#define AHB_SYSTEM_CLOCK_DIVIDED_BY_2                 0X00000080
#define AHB_SYSTEM_CLOCK_DIVIDED_BY_4                 0X00000090
#define AHB_SYSTEM_CLOCK_DIVIDED_BY_8                 0X000000A0
#define AHB_SYSTEM_CLOCK_DIVIDED_BY_16                0X000000B0
#define AHB_SYSTEM_CLOCK_DIVIDED_BY_64                0X000000C0
#define AHB_SYSTEM_CLOCK_DIVIDED_BY_128               0X000000D0
#define AHB_SYSTEM_CLOCK_DIVIDED_BY_256               0X000000E0
#define AHB_SYSTEM_CLOCK_DIVIDED_BY_512               0X000000F0

/* ========================== APB1 Prescalers ========================== */
#define MASK_APB1_PRESCALER                           0xFFFFE3FF
#define APB1_AHB_CLOCK_NOT_DIVIDED                    0X00000000
#define APB1_AHB__CLOCK_DIVIDED_BY_2                  0X00001000
#define APB1_AHB__CLOCK_DIVIDED_BY_4                  0X00001400
#define APB1_AHB__CLOCK_DIVIDED_BY_8                  0X00001800
#define APB1_AHB__CLOCK_DIVIDED_BY_16                 0X00001C00

/* ========================== APB2 Prescaler ========================== */
#define MASK_APB2_PRESCALER                           0xFFFF1FFF
#define APB2_AHB_CLOCK_NOT_DIVIDED                    0X00000000
#define APB2_AHB__CLOCK_DIVIDED_BY_2                  0X00008000
#define APB2_AHB__CLOCK_DIVIDED_BY_4                  0X0000A000
#define APB2_AHB__CLOCK_DIVIDED_BY_8                  0X0000C000
#define APB2_AHB__CLOCK_DIVIDED_BY_16                 0X0000E000


/**
*@ RRC PERIPHRAL ERROR STATUS
*/
typedef enum {
  RCC_enuOK,
  RCC_enuNOK
}RCC_enuErrorStatus_t;

typedef enum
{
	RCC_AHB1 = 0 ,
	RCC_AHB2	 ,
	RCC_APB1     ,
	RCC_APB2	
}RCC_enuBus_t;

typedef enum
{
	RCC_HSI = 0 ,
	RCC_HSE	    ,
	RCC_PLL	
}RCC_enuSysClk_t;

typedef enum 
{
	RCC_CLK_ON ,
	RCC_CLK_OFF
}RCC_enuClkStatus_t;

typedef enum 
{
	PLL_HSI_SRC ,
	PLL_HSE_SRC
}RCC_enuPLLSRC_t;

typedef struct{
  RCC_enuPLLSRC_t   RCC_strPLLSCR;
  u32             RCC_strPLL_M;
  u32             RCC_strPLL_N;
  u32             RCC_strPLL_P;
  u32             RCC_strPLL_Q;
}RCC_structCLKPLL_t;





/*******************************************************************************************************/
/*                                      01- RCC_enuControlClk                                          */
/*-----------------------------------------------------------------------------------------------------*/
/* @description  -> Control the clocks on the periphrals (ON & OFF)                                    */
/* @param        -> the desired clock , it's status (ON or OFF)                                        */
/* @return       -> Error Status                                                                       */
/*******************************************************************************************************/
RCC_enuErrorStatus_t RCC_enuControlClk (RCC_enuSysClk_t Copy_enuClockSystem,RCC_enuClkStatus_t Copy_enuClkStatus);


/*******************************************************************************************************/
/*                                      02- RCC_enuSelectSystemClk                                     */
/*-----------------------------------------------------------------------------------------------------*/
/* @description  -> Select the System Clock                                                            */
/* @param        -> the desired system clock                                                           */
/* @return       -> Error Status                                                                       */
/*******************************************************************************************************/
RCC_enuErrorStatus_t RCC_enuSelectSystemClk (RCC_enuSysClk_t Copy_enuSystemClock);


/*******************************************************************************************************/
/*                                      03- RCC_enuEnablePeripheralClock                               */
/*-----------------------------------------------------------------------------------------------------*/
/* @description  -> Enamble periphral clock from Rcc periphral                                         */
/* @param        -> Peripheral Bus , Peripheral Number                                                 */
/* @return       -> Error Status                                                                       */
/*******************************************************************************************************/
RCC_enuErrorStatus_t RCC_enuEnablePeripheralClock (RCC_enuBus_t Copy_enuPeripheralBus, u8 Copy_u8PeripheralNumber);


/*******************************************************************************************************/
/*                                      04- RCC_enuDisablePeripheralClock                              */
/*-----------------------------------------------------------------------------------------------------*/
/* @description  -> Enamble periphral clock from Rcc periphral                                         */
/* @param        -> Peripheral Bus , Peripheral Number                                                 */
/* @return       -> Error Status                                                                       */
/*******************************************************************************************************/
RCC_enuErrorStatus_t RCC_enuDisablePeripheralClock (RCC_enuBus_t Copy_enuPeripheralBus, u8 Copy_u8PeripheralNumber);


/*******************************************************************************************************/
/*                                      05- RCC_enuConfigPLL                                           */
/*-----------------------------------------------------------------------------------------------------*/
/* @description  -> PLL configration							                                       */
/* @param        -> struct contain the PLL Configrations                                               */
/* @return       -> Error Status                                                                       */
/*******************************************************************************************************/
RCC_enuErrorStatus_t  RCC_enuConfigPLL (RCC_structCLKPLL_t * Copy_structPLLCongif);


/*******************************************************************************************************/
/*                                      06- RCC_enuControlBusesPrescaler                                           */
/*-----------------------------------------------------------------------------------------------------*/
/* @description  -> control the prescaler of each bus (AHB1 , APB1 , APB2)                             */
/* @param        -> struct contain the PLL Configrations                                               */
/* @return       -> Error Status                                                                       */
/*******************************************************************************************************/
RCC_enuErrorStatus_t  RCC_enuControlBusesPrescaler  (RCC_enuBus_t Copy_enuBus ,u8 Copy_u32APB2Prescaler);

#endif
