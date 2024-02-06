/****************************************************************************
 * Author:	Bishoy Unan		
 * Date:	1/1/2024		
 * Version:	v1.0.0		
 * description: LCD 16*2 Driver Using DIO V04
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





#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "LCD_Private.h"
#include "LCD.h"
#include "../../MCAL/DIO_04/DIO.h"

/**
*@ array for LCD Pins to configure port and pin and state for each pin
*@ (REG_SEL = 0 && READ_WRITE = 0 : instruction write operation (MPU writes instruction code to IR)
*@ (REG_SEL = 0 && READ_WRITE = 1 : resd busy flag DATA_BIT7 and address counter DATA_BIT0 : DATA_BIT6)
*@ (REG_SEL = 1 && READ_WRITE = 0 : data write operation (MPU writes data code to DR)
*@ (REG_SEL = 1 && READ_WRITE = 1 : data read operation (MPU reads data code from DR)
*@ this default values for configrations
*/
PPRT_strCFG_t LCDPINS[LCD_PINS_NUM] = {     [DATA_BIT0] = { .PORT_strPORT = DIO_enumPORTB , 
															.PORT_strPIN = DIO_enumPIN0 , 
															.PORT_strCFGType =  DIO_enumOUTPUTLOW}  ,
											[DATA_BIT1] = { .PORT_strPORT = DIO_enumPORTB , 
															.PORT_strPIN = DIO_enumPIN1 , 
															.PORT_strCFGType =  DIO_enumOUTPUTLOW}  ,			
											[DATA_BIT2] = { .PORT_strPORT = DIO_enumPORTB , 
															.PORT_strPIN = DIO_enumPIN2 , 
															.PORT_strCFGType =  DIO_enumOUTPUTLOW}  ,
											[DATA_BIT3] = { .PORT_strPORT = DIO_enumPORTB , 
															.PORT_strPIN = DIO_enumPIN3 , 
															.PORT_strCFGType =  DIO_enumOUTPUTLOW}  ,	
											[DATA_BIT4] = { .PORT_strPORT = DIO_enumPORTB , 
															.PORT_strPIN = DIO_enumPIN4 , 
															.PORT_strCFGType =  DIO_enumOUTPUTLOW}  ,
											[DATA_BIT5] = { .PORT_strPORT = DIO_enumPORTB , 
															.PORT_strPIN = DIO_enumPIN5 , 
															.PORT_strCFGType =  DIO_enumOUTPUTLOW}  ,	
											[DATA_BIT6] = { .PORT_strPORT = DIO_enumPORTB , 
															.PORT_strPIN = DIO_enumPIN6 , 
															.PORT_strCFGType =  DIO_enumOUTPUTLOW}  ,
											[DATA_BIT7] = { .PORT_strPORT = DIO_enumPORTB , 
															.PORT_strPIN = DIO_enumPIN7 , 
															.PORT_strCFGType =  DIO_enumOUTPUTLOW}  ,
											[ENABLE] = 	 {  .PORT_strPORT = DIO_enumPORTC , 
													        .PORT_strPIN = DIO_enumPIN7 , 
													        .PORT_strCFGType =  DIO_enumOUTPUTLOW}  ,
											[REG_SEL] =    {.PORT_strPORT = DIO_enumPORTC , 
															.PORT_strPIN = DIO_enumPIN5 , 
															.PORT_strCFGType =  DIO_enumOUTPUTLOW}  ,
											[READ_WRITE] = {.PORT_strPORT = DIO_enumPORTC , 
															.PORT_strPIN = DIO_enumPIN6 , 
															.PORT_strCFGType =  DIO_enumOUTPUTLOW} 								
									   			 
								  }; /* LCDPINS ARRAY*/

