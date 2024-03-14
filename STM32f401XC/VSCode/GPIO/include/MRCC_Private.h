/**********************************************************************************************************************/
/* Author        : Bishoy Unan                                          
/* Version       : V0.0.0                                               
/* Date          : 5 Feb 2024                                           
/* Description   :             
/* Module Features  :                                                   
/*                 01- RCC_enuControlClk (RCC_enuSysClk_t Copy_enuClockSystem,RCC_enuClkStatus_t Copy_enuClkStatus)(); 
/*                 02- RCC_enuSelectSystemClk (RCC_enuSysClk_t Copy_enuSystemClock)();            					    
/*                 03- RCC_enuEnablePeripheralClock (RCC_Bus_t Copy_enuPeripheralBus, u8 Copy_u8PeripheralNumber)();    
/*                 04- RCC_enuDisablePeripheralClock (RCC_Bus_t Copy_enuPeripheralBus, u8 Copy_u8PeripheralNumber)();   
/*                 05- RCC_enuConfigPLL (RCC_structCLKPLL_t * Copy_structPLLCongif)();  							
/*                 06- RCC_enuControlBusesPrescaler  (RCC_Bus_t Copy_enuBus ,u8 Copy_u32APB2Prescaler)();  				
/************************************************************************************************************************/


#ifndef MRCC_PRIVATE_H_
#define MRCC_PRIVATE_H_
/*============================================================*/
/*==================== RCC BASE ADDRESS ======================*/
/*============================================================*/
#define RCC_BASE_ADDRESS	0x40023800

/*============================================================*/
/*================== CC REGISTERS ADDRESS ====================*/
/*============================================================*/
#define RCC_CR			    	*((volatile u32 *)(RCC_BASE_ADDRESS + 0x00))
#define RCC_PLLCFGR			    *((volatile u32 *)(RCC_BASE_ADDRESS + 0x04))
#define RCC_CFGR			    *((volatile u32 *)(RCC_BASE_ADDRESS + 0x08))
#define RCC_CIR			        *((volatile u32 *)(RCC_BASE_ADDRESS + 0x0C))
#define RCC_AHB1RSTR			*((volatile u32 *)(RCC_BASE_ADDRESS + 0x10))
#define RCC_AHB2RSTR			*((volatile u32 *)(RCC_BASE_ADDRESS + 0x14))
#define RCC_APB1RSTR			*((volatile u32 *)(RCC_BASE_ADDRESS + 0x20))
#define RCC_APB2RSTR			*((volatile u32 *)(RCC_BASE_ADDRESS + 0x24))
#define RCC_AHB1ENR			    *((volatile u32 *)(RCC_BASE_ADDRESS + 0x30))
#define RCC_AHB2ENR			    *((volatile u32 *)(RCC_BASE_ADDRESS + 0x34))
#define RCC_APB1ENR			    *((volatile u32 *)(RCC_BASE_ADDRESS + 0x40))
#define RCC_APB2ENR			    *((volatile u32 *)(RCC_BASE_ADDRESS + 0x44))
#define RCC_AHB1LPENR           *((volatile u32 *)(RCC_BASE_ADDRESS + 0X50))
#define RCC_AHB2LPENR           *((volatile u32 *)(RCC_BASE_ADDRESS + 0X54))
#define RCC_APB1LPENR           *((volatile u32 *)(RCC_BASE_ADDRESS + 0X60))
#define RCC_APB2LPENR           *((volatile u32 *)(RCC_BASE_ADDRESS + 0X64))
#define RCC_BDCR                *((volatile u32 *)(RCC_BASE_ADDRESS + 0X70))
#define RCC_CSR                 *((volatile u32 *)(RCC_BASE_ADDRESS + 0X74))
#define RCC_SSCGR               *((volatile u32 *)(RCC_BASE_ADDRESS + 0X80))
#define RCC_PLLI2SCFGR          *((volatile u32 *)(RCC_BASE_ADDRESS + 0X84))
#define RCC_DCKCFGR             *((volatile u32 *)(RCC_BASE_ADDRESS + 0X8C))


/*============================================================*/
/*======================= RCC CLOCK TYPES ====================*/
/*============================================================*/
#define RCC_HSI                 0x00000000
#define RCC_HSE                 0x00000001
#define RCC_PLL                 0x00000002

/*============================================================*/
/*================ RCC EXTERNAL CLOCK TYPES ==================*/
/*============================================================*/
#define RCC_HSE_SRC_RC		         0UL
#define RCC_HSE_SRC_CRYSTAL	         1UL

/*============================================================*/
/*=============== RCC PLL INPUT CLOCK TYPES ==================*/
/*============================================================*/
#define RCC_PLL_SRC_HSI	             0UL
#define RCC_PLL_SRC_HSE	             1UL



/*=======================  BUSES  ===========================*/
#define AHB1_BUS                        0UL
#define AHB2_BUS                        1UL
#define APB1_BUS                        2UL
#define APB2_BUS                        3UL



/*==================== MCO2 SOURCES  ========================*/

/*=======================  MASKS  ===========================*/


#define MASK_GET_SYSCLK          0x0000000C

#define  MASK_HSI_ON             0x00000001
#define  MASK_HSI_RDY            0x00000002
#define  MASK_HSE_ON             0x00010000
#define  MASK_HSE_RDY            0x00020000
#define  MASK_PLL_ON             0x01000000
#define  MASK_PLL_RDY            0x02000000

#define  MASK_SW                 0x00000003
#define  MASK_GET_SWS            0x0000000C
#define  MASK_SWS_HSI 			 0x00000000
#define  MASK_SWS_HSE 			 0x00000004
#define  MASK_SWS_PLL 			 0x00000008

#define MASK_GET_ON_PLL          0x01000000

#define  ON         1UL
#define  OFF        0UL   

#define MASK_SET_PPL_M           0x0000003F
#define MASK_SET_PPL_N           0x00007FC0
#define MASK_SET_PPL_P           0x00030000
#define MASK_SET_PPL_Q           0x0F000000
#define MASK_SET_PPL_SRC         0x00400000

#define SHIFT_PLL_M              0
#define SHIFT_PLL_N              6
#define SHIFT_PLL_P              16
#define SHIFT_PLL_Q              24
#define SHIFT_PLL_SRC            22

#endif