/****************************************************************************
 * Author:	Bishoy Unan		
 * Date:	2/3/2024		
 * Version:	v1.0.0		
 * description: LCD 16*2 Driver using STMF401CC Black pill
 * Specs:		
 * 01: LCD_enuErrorStatus_t LCD_init(void);
 * 02: LCD_enuErrorStatus_t LCD_enuWriteData(u8 Copy_u8Data);
 * 03: LCD_enuErrorStatus_t LCD_enuWriteCommand(u8 Copy_u8Command);
 * 04: LCD_enuErrorStatus_t LCD_enuGotoDDRAM_XY(u8 Copy_u8X, u8 Copy_u8Y);
 * 05: LCD_enuErrorStatus_t LCD_enuWriteNumber(s32 Copy_u8Number);
 * 06: LCD_enuErrorStatus_t LCD_enuWriteString(char* Copy_pchPattern, u8 Copy_u8Length);
 * 07: LCD_enuErrorStatus_t LCD_enuDisplaySpecialPattern(u8* Copy_pu8Pattern, u8 Copy_u8CGRAMBlockNumber, u8 Copy_u8X, u8 Copy_u8Y);
 *
 ********************************************************************************/





#include "STD_TYPES.h"
#include "LCD_Private.h"
#include "LCD.h"
#include "GPIO_Interface.h"

/**
*@ array for LCD Pins to configure port and pin and state for each pin
*@ (REG_SEL = 0 && READ_WRITE = 0 : instruction write operation (MPU writes instruction code to IR)
*@ (REG_SEL = 0 && READ_WRITE = 1 : resd busy flag DATA_BIT7 and address counter DATA_BIT0 : DATA_BIT6)
*@ (REG_SEL = 1 && READ_WRITE = 0 : data write operation (MPU writes data code to DR)
*@ (REG_SEL = 1 && READ_WRITE = 1 : data read operation (MPU reads data code from DR)
*@ this default values for configrations
*/
 GPIO_strPinConfg_t LCDPINS[LCD_PINS_NUM] = {[DATA_BIT0] = { .GPIOPort = GPIOA , 
																 .GPIOPin = GPIO_PIN0 }		, 
												 [DATA_BIT1] = { .GPIOPort = GPIOA , 
												 			 	 .GPIOPin = GPIO_PIN1 }		, 			
												 [DATA_BIT2] = { .GPIOPort = GPIOA , 
												 				 .GPIOPin = GPIO_PIN2 }		, 
												 [DATA_BIT3] = { .GPIOPort = GPIOA , 
												 				 .GPIOPin = GPIO_PIN3 }		, 
												 [DATA_BIT4] = { .GPIOPort = GPIOA , 
												 				 .GPIOPin = GPIO_PIN4 }		, 
												 [DATA_BIT5] = { .GPIOPort = GPIOA , 
												 				 .GPIOPin = GPIO_PIN5 }		, 	
												 [DATA_BIT6] = { .GPIOPort = GPIOA , 
												 				 .GPIOPin = GPIO_PIN6 }		, 
												 [DATA_BIT7] = { .GPIOPort = GPIOA , 
												 				 .GPIOPin = GPIO_PIN7 }		, 
												 [ENABLE]    = { .GPIOPort = GPIOB , 
												 		         .GPIOPin = GPIO_PIN0 }		, 
												 [REG_SEL]   = { .GPIOPort = GPIOB , 
												 				 .GPIOPin = GPIO_PIN1 }		, 
												 [READ_WRITE]= { .GPIOPort = GPIOB , 
												 				 .GPIOPin = GPIO_PIN2 }								   			 
								  }; /* LCDPINS ARRAY*/

