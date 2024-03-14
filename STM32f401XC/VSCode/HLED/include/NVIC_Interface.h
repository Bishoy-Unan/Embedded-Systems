/***************************************************************
 * Author            : Bishoy Unan                              
 * Version           : V0.0.0                                   
 * Data              : 5 Mar 2024                              
 * Description       : NVIC_Interface.h --> prototypes                                            
 * Module  Features  :                                                                                 
 *      01- NVIC_enuEnableInterrupt(u8 Copy_u8InterruptID);                                                                                  
 *      02- NVIC_enuDisableInterrupt(u8 Copy_u8InterruptID);                                                                                    
 *      03- NVIC_enuSetPending(u8 Copy_u8InterruptID);                                                                                          
 *      04- NVIC_enuClearPending(u8 Copy_u8InterruptID);                                                                                           
 *      05- NVIC_enuGetActiveStatus(u8 Copy_u8InterruptID);                                                                                   
 *      06- NVIC_enuSetPriority(u8 Copy_u8InterruptID,u32 Copy_u32GroupingMode,u8 Copy_u8GroupPriority, u8 Copy_u8SubGroupPriority);                                                                                                                                                
 **************************************************************/


#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H



/*=====================================================================================================*
 *                STM32F401CC INTERRUPTS POSITIONS (ID) IN VECTOR TABLE                                *
 *=====================================================================================================*/


#define NVIC_WINDOW_WATCHDOG_TIMER					0
#define	NIVC_EXTERNAL_LINE16						1
#define	NIVC_EXTERNAL_LINE21						2
#define	NIVC_EXTERNAL_LINE22						3
#define	NIVC_FLASH_INTERRUPT						4
#define	NVIC_RCC_INTERRUPT							5
#define NVIC_EXT0_INTERRRUPT						6
#define NVIC_EXT1_INTERRRUPT						7
#define NVIC_EXT2_INTERRRUPT						8
#define NVIC_EXT3_INTERRRUPT						9
#define NVIC_EXT4_INTERRRUPT						10
#define NVIC_DMA1_STREAM0							11
#define NVIC_DMA1_STREAM1							12
#define NVIC_DMA1_STREAM2							13
#define NVIC_DMA1_STREAM3							14
#define NVIC_DMA1_STREAM4							15
#define NVIC_DMA1_STREAM5							16
#define NVIC_DMA1_STREAM6          					17
#define NVIC_ADC_INTERRUPT         					18
#define NVIC_EXT9_INTERRUPT        					23
#define NVIC_TIM1_BRK_INTERRUPT    					24
#define NVIC_TIM1_UP_INTERRUPT     					25
#define NVIC_TIMI1_TRG_INTERRUPT   					26
#define NVIC_TIMI1_CC_INTERRUPT    					27
#define NVIC_TIMI2_INTERRUPT       					28
#define NVIC_TIMI3_INTERRUPT       					29
#define NVIC_TIMI4_INTERRUPT       					30
#define NVIC_I2C1_EV_INTERRUPT     					31
#define NVIC_I2C1_ER_INTERRUPT     					32
#define NVIC_I2C2_EV_INTERRUPT     					33
#define NVIC_I2C2_ER_INTERRUPT     					34
#define NVIC_SPI1_INTERRUPT        					35
#define NVIC_SPI2_INTERRUPT        					36
#define NVIC_USART1_INTERRUPT      					37
#define NVIC_USART2_INTERRUPT      					38
#define NVIC_EXTI15_INTERRUPT      					40
#define NVIC_EXTI17_INTERRUPT      					41
#define NVIC_EXTI18_INTERRUPT      					42
#define NVIC_DMA1_INTERRUPT        					47
#define NVIC_SDIO_INTERRUPT        					49
#define NVIC_TIM5_INTERRUPT        					50
#define NVIC_SPI3_INTERRUPT        					51
#define NVIC_DMA2_STREAM0_INTERRUPT					56
#define NVIC_DMA2_STREAM1_INTERRUPT					57
#define NVIC_DMA2_STREAM2_INTERRUPT					58
#define NVIC_DMA2_STREAM3_INTERRUPT					59
#define NVIC_DMA2_STREAM4_INTERRUPT					60
#define NVIC_OTG_FS_INTERRUPT      					67
#define NVIC_DMA2_STREAM5_INTERRUPT					68
#define NVIC_DMA2_STREAM6_INTERRUPT					69
#define NVIC_DMA2_STREAM7_INTERRUPT					70
#define NVIC_USART6_INTERRUPT      					71
#define NVIC_I2C3_EV_INTERRUPT     					72
#define NVIC_I2C3_ER_INTERRUPT     					73
#define NVIC_FPU_INTERRUPT         					81
#define NVIC_SPI4_INTERRUPT        					84



/*=====================================================================================================*
 *                                      Function Prototypes                                            *
 *=====================================================================================================*/


typedef enum{
     NVIC_enuOK,
	 NVIC_enuNOK,
	 NVIC_enuErrorNullPointer
}NVIC_enuErrorStatus_t;

/******************** NVIC_enuEnableInterrupt ***************************
 * @brief: This function Enable an interrupt. 
 * @param :  Copy_u8InterruptID (u8)  : 0 -> 239 
 * @return: NVIC_enuErrorStatus
 ************************************************************************/
NVIC_enuErrorStatus_t NVIC_enuEnableInterrupt(u8 Copy_u8InterruptID);
/******************** NVIC_enuDisableInterrupt **************************
 * @brief: This function Enable an interrupt. 
 * @param :  Copy_u8InterruptID (u8)  : 0 -> 239 
 * @return: NVIC_enuErrorStatus
 ************************************************************************/
NVIC_enuErrorStatus_t NVIC_enuDisableInterrupt(u8 Copy_u8InterruptID);
/*********************** NVIC_enuSetPending *****************************
 * @brief: This function set pending flag. 
 * @param :  Copy_u8InterruptID (u8)  : 0 -> 239 
 * @return: NVIC_enuErrorStatus
 ************************************************************************/
NVIC_enuErrorStatus_t NVIC_enuSetPending(u8 Copy_u8InterruptID);
/*********************** NVIC_enuClearPending ***************************
 * @brief: This function clear pending flag. 
 * @param :  Copy_u8InterruptID (u8)  : 0 -> 239 
 * @return: NVIC_enuErrorStatus
 ************************************************************************/
NVIC_enuErrorStatus_t NVIC_enuClearPending(u8 Copy_u8InterruptID);
/********************** NVIC_enuGetActiveStatus *************************
 * @bief: This function get active status  
 * @param:  Copy_u8InterruptID (u8) : 0 -> 239 
 *           Add_pu8ActiveValue(pu8) : to return the value 
 * @return: NVIC_enuErrorStatus 
 ************************************************************************/
NVIC_enuErrorStatus_t NVIC_enuGetActiveStatus(u8 Copy_u8InterruptID, u8* Add_pu8ActiveValue);
/********************** NVIC_enuSetPriority *****************************************************
 * @bief: This function set grouping mode and group priority and sub group priority ( only for external interrupt --240 int--)  
 * @param:  Copy_u8InterruptID (u8) : 0 -> 239 
 *          Copy_u32GroupingMode : 
 *                                   1- NVIC_GROUPMODE_G16S0
 *                                   2- NVIC_GROUPMODE_G8S2 
 *                                   3- NVIC_GROUPMODE_G4S4 
 *                                   4- NVIC_GROUPMODE_G2S8 
 *                                   5- NVIC_GROUPMODE_G0S16
 *         Copy_u8GroupPriority:
 *         Copy_u8SubGroupPriority: any number based on grouping mode
 * @return: NVIC_enuErrorStatus 
 ****************************************************************************************************/

NVIC_enuErrorStatus_t NVIC_enuSetPriority(u8 Copy_u8InterruptID,u32 Copy_u32GroupingMode,u8 Copy_u8GroupPriority, u8 Copy_u8SubGroupPriority);




#endif //NVIC_INTERFACE_H
