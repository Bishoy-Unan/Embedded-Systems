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
#include "../../MCAL/delay_function/delay_function.h"
#include "LCD_Private.h"
#include "LCD.h"
#include "LCD_Config.h"
#include "../../MCAL/DIO_04/DIO.h"

/*instructions from data sheet for  LCD initialization   */
#define	FUNCTION_SET	        (0b00100000|(DISPLAY_FONT_TYPE<<2)|(DISPLAY_LINES_NUM<<3)| (DATA_LENGTH<<4))
#define DISPLAY_ON_OFF_COTROL   (0b00001000|(ENTIRE_DISPLAY_MODE<<2)|(CURSOR_MODE<<1)|(CURSOR_BLNKING_MODE<<0))
#define DISPLAY_CLEAR   0x01
#define ENTRY_MODE_SET          (0b00000100|(INCREMENT_DECREMENT_MODE<<1))
#define DISPLAY_SHIFT_LEFT      0x18
#define DISPLAY_SHIFT_RIGHT     0x1c
#define CURSOR_SHIFT_LEFT       0x10
#define CURSOR_SHIFT_RIGHT      0x14
#define SET_CGRAMADRESS 0x48
#define DDRAM_ADDRESS	0b10000000

/**
*@ Array of LCD pins which declared in LCD_Config.c
*/
extern PPRT_strCFG_t LCDPINS[LCD_PINS_NUM];

/**
*@ private functions prototype
*/


void LCD_voidEntryModeSet(void);

void LCD_voidDisplay_ON_OFF_Control(void);

void LCD_voidFunctionSet(void);

void LCD_voidSetCGRAMAddress(u8 Copy_u8Address);

void LCD_voidSetDDRAMAddress(u8 Copy_u8Address);

void LCD_voidWriteCharacter_CG_DDRAM(u8 Copy_u8Data);







/**
*@ Clears entire display and sets DDRAM address to 00H.
*/
void LCD_voidClearDisplay(void)
{
		/**
		*@ iterator used in for loop to configure every single pin using DIO driver
		*/
		u8 LOCAL_u8Iterator = 0 ;
		
		/**
		*@ check the operational mode 4 pins or 8 pins
		*/
		#if	(DATA_LENGTH == EIGHT_BITS_MODE)
			/**
			*@ iterator used in for loop to configure every single pin using DIO driver
			*/
			
				/**
				*@ Enable Rising edge
				*/
				LCDPINS[ENABLE].PORT_strCFGType =  DIO_enumOUTPUTHIGH  ;
				/**
				*@ set pins configrations according to data sheet sequence
				*/
				LCDPINS[REG_SEL]    .PORT_strCFGType =  DIO_enumOUTPUTLOW   ;
				LCDPINS[READ_WRITE] .PORT_strCFGType =  DIO_enumOUTPUTLOW   ;
			    LCDPINS[DATA_BIT0]  .PORT_strCFGType =  DIO_enumOUTPUTHIGH ;
				LCDPINS[DATA_BIT1]  .PORT_strCFGType =  DIO_enumOUTPUTLOW  ;			
				LCDPINS[DATA_BIT2]  .PORT_strCFGType =  DIO_enumOUTPUTLOW  ;
				LCDPINS[DATA_BIT3]  .PORT_strCFGType =  DIO_enumOUTPUTLOW  ;	
				LCDPINS[DATA_BIT4]  .PORT_strCFGType =  DIO_enumOUTPUTLOW  ;
				LCDPINS[DATA_BIT5]  .PORT_strCFGType =  DIO_enumOUTPUTLOW  ;	
				LCDPINS[DATA_BIT6]  .PORT_strCFGType =  DIO_enumOUTPUTLOW  ;
				LCDPINS[DATA_BIT7]  .PORT_strCFGType =  DIO_enumOUTPUTLOW  ;	
				
			
			for( LOCAL_u8Iterator = 0 ; LOCAL_u8Iterator < LCD_PINS_NUM ; LOCAL_u8Iterator++)
			{
					/**
					*@ call DIO_enumSetCFG function to set configration in DIO Driver
					*@ and check return of DIO_enumSetCFG function ok or not ok
					*/		
						DIO_enumSetCFG( & LCDPINS [LOCAL_u8Iterator] );
	
			}/*for loop*/
			delay_ms(2);
			/**
			*@ Enable falling edge
			*/
			LCDPINS[ENABLE].PORT_strCFGType =  DIO_enumOUTPUTLOW  ;
			/**
			*@ send enable signal to LCD
			*/
			DIO_enumSetCFG( & LCDPINS [ENABLE] );
			
		#elif (DATA_LENGTH == FOUR_BITS_MODE)
			
		
				/**
				*@ Enable Rising edge
				*/
				LCDPINS[ENABLE].PORT_strCFGType =  DIO_enumOUTPUTHIGH  ;
				/**
				*@ set pins configrations according to data sheet sequence
				*/
				LCDPINS[READ_WRITE].PORT_strCFGType =  DIO_enumOUTPUTLOW   ;
				LCDPINS[REG_SEL] = .PORT_strCFGType =  DIO_enumOUTPUTLOW   ;
			    LCDPINS[DATA_BIT4] .PORT_strCFGType =  DIO_enumOUTPUTLOW   ;
				LCDPINS[DATA_BIT5] .PORT_strCFGType =  DIO_enumOUTPUTLOW   ;			
				LCDPINS[DATA_BIT6] .PORT_strCFGType =  DIO_enumOUTPUTLOW   ;
				LCDPINS[DATA_BIT7] .PORT_strCFGType =  DIO_enumOUTPUTLOW   ;	
		
			for( LOCAL_u8Iterator = 0 ; LOCAL_u8Iterator < LCD_PINS_NUM ; LOCAL_u8Iterator++)
			{
					/**
					*@ call DIO_enumSetCFG function to set configration in DIO Driver
					*@ and check return of DIO_enumSetCFG function ok or not ok
					*/		
						DIO_enumSetCFG( & LCDPINS [LOCAL_u8Iterator] );
	
			}/*for loop*/
			delay_ms(2);
			/**
			*@ Enable falling edge
			*/
			LCDPINS[ENABLE].PORT_strCFGType =  DIO_enumOUTPUTLOW  ;
			/**
			*@ send enable signal to LCD
			*/
			DIO_enumSetCFG( & LCDPINS [ENABLE] );
			
			
				/**
				*@ Enable Rising edge
				*/
				LCDPINS[ENABLE].PORT_strCFGType =  DIO_enumOUTPUTHIGH  ;
				/**
				*@ the remaining four bits 
				*/
				LCDPINS[READ_WRITE].PORT_strCFGType =  DIO_enumOUTPUTLOW   ;
				LCDPINS[REG_SEL]   .PORT_strCFGType =  DIO_enumOUTPUTLOW   ;
				LCDPINS[DATA_BIT4] .PORT_strCFGType =  DIO_enumOUTPUTHIGH  ;
				LCDPINS[DATA_BIT5] .PORT_strCFGType =  DIO_enumOUTPUTLOW   ;	
				LCDPINS[DATA_BIT6] .PORT_strCFGType =  DIO_enumOUTPUTLOW   ;
				LCDPINS[DATA_BIT7] .PORT_strCFGType =  DIO_enumOUTPUTLOW   ;	
		
			for( LOCAL_u8Iterator = 0 ; LOCAL_u8Iterator < LCD_PINS_NUM ; LOCAL_u8Iterator++)
			{
					/**
					*@ call DIO_enumSetCFG function to set configration in DIO Driver
					*@ and check return of DIO_enumSetCFG function ok or not ok
					*/		
						DIO_enumSetCFG( & LCDPINS [LOCAL_u8Iterator] );
	
			}/*for loop*/
			delay_ms(2);
			/**
			*@ Enable falling edge
			*/
			LCDPINS[ENABLE].PORT_strCFGType =  DIO_enumOUTPUTLOW  ;
			/**
			*@ send enable signal to LCD
			*/
			DIO_enumSetCFG( & LCDPINS [ENABLE] );

			
		#else
			
		#endif	
	
}/*LCD_voidClearDisplay function*/






/**
*@ Sets DDRAM address to 00H in
*@ AC and returns shifted display to
*@ its original position. The contents
*@ of DDRAM remain unchanged..
*/
void LCD_voidReturnHome(void)
{
		/**
		*@ iterator used in for loop to configure every single pin using DIO driver
		*/
		u8 LOCAL_u8Iterator = 0 ;
		
				
				/**
				*@ Enable Rising edge
				*/
				LCDPINS[ENABLE].PORT_strCFGType =  DIO_enumOUTPUTHIGH  ;
				/**
				*@ set pins configrations according to data sheet sequence
				*/
			    LCDPINS[DATA_BIT0] .PORT_strCFGType =  DIO_enumOUTPUTLOW   ;
				LCDPINS[DATA_BIT1] .PORT_strCFGType =  DIO_enumOUTPUTHIGH  ;			
				LCDPINS[DATA_BIT2] .PORT_strCFGType =  DIO_enumOUTPUTLOW   ;
				LCDPINS[DATA_BIT3] .PORT_strCFGType =  DIO_enumOUTPUTLOW   ;	
				LCDPINS[DATA_BIT4] .PORT_strCFGType =  DIO_enumOUTPUTLOW   ;
				LCDPINS[DATA_BIT5] .PORT_strCFGType =  DIO_enumOUTPUTLOW   ;	
				LCDPINS[DATA_BIT6] .PORT_strCFGType =  DIO_enumOUTPUTLOW   ;
				LCDPINS[DATA_BIT7] .PORT_strCFGType =  DIO_enumOUTPUTLOW   ;	
				LCDPINS[REG_SEL]   .PORT_strCFGType =  DIO_enumOUTPUTLOW   ;
				LCDPINS[READ_WRITE].PORT_strCFGType =  DIO_enumOUTPUTLOW   ;
	
		for( LOCAL_u8Iterator = 0 ; LOCAL_u8Iterator < LCD_PINS_NUM ; LOCAL_u8Iterator++)
		{
				/**
				*@ call DIO_enumSetCFG function to set configration in DIO Driver
				*@ and check return of DIO_enumSetCFG function ok or not ok
				*/		
					DIO_enumSetCFG( & LCDPINS [LOCAL_u8Iterator] );
	
		}/*for loop*/
		delay_ms(1);
		/**
		*@ Enable falling edge
		*/
		LCDPINS[ENABLE].PORT_strCFGType =  DIO_enumOUTPUTLOW  ;
		/**
		*@ send enable signal to LCD
		*/
		DIO_enumSetCFG( & LCDPINS [ENABLE] );


	
}/*LCD_voidReturnHome function*/





/**
*@ Sets cursor move direction and
*@ enable the shift of entire display.
*@ These operations are performed
*@ during data write and read.
*/
void LCD_voidEntryModeSet(void)
{
		/**
		*@ iterator used in for loop to configure every single pin using DIO driver
		*/
		u8 LOCAL_u8Iterator = 0 ;

	
		/**
		*@ check the operational mode 4 pins or 8 pins
		*/
		#if	(DATA_LENGTH == EIGHT_BITS_MODE)
			
		
				/**
				*@ Enable Rising edge
				*/
				LCDPINS[ENABLE].PORT_strCFGType =  DIO_enumOUTPUTHIGH  ;
				/**
				*@ set pins configrations according to data sheet sequence
				*/
				LCDPINS[REG_SEL]   .PORT_strCFGType =  DIO_enumOUTPUTLOW  		 ;
				LCDPINS[READ_WRITE].PORT_strCFGType =  DIO_enumOUTPUTLOW  		 ;
			    LCDPINS[DATA_BIT0] .PORT_strCFGType =  SHIFTING_MODE               ;
				LCDPINS[DATA_BIT1] .PORT_strCFGType =  INCREMENT_DECREMENT_MODE    ;			
				LCDPINS[DATA_BIT2] .PORT_strCFGType =  DIO_enumOUTPUTLOW  		 ;
				LCDPINS[DATA_BIT3] .PORT_strCFGType =  DIO_enumOUTPUTLOW  		 ;	
				LCDPINS[DATA_BIT4] .PORT_strCFGType =  DIO_enumOUTPUTLOW  		 ;
				LCDPINS[DATA_BIT5] .PORT_strCFGType =  DIO_enumOUTPUTLOW  		 ;	
				LCDPINS[DATA_BIT6] .PORT_strCFGType =  DIO_enumOUTPUTLOW  		 ;
				LCDPINS[DATA_BIT7] .PORT_strCFGType =  DIO_enumOUTPUTLOW  		 ;	
						
			for( LOCAL_u8Iterator = 0 ; LOCAL_u8Iterator < LCD_PINS_NUM ; LOCAL_u8Iterator++)
			{
					/**
					*@ call DIO_enumSetCFG function to set configration in DIO Driver
					*@ and check return of DIO_enumSetCFG function ok or not ok
					*/		
						DIO_enumSetCFG( & LCDPINS [LOCAL_u8Iterator] );
		
			}/*for loop*/
			delay_ms(1);
			/**
			*@ Enable falling edge
			*/
			LCDPINS[ENABLE].PORT_strCFGType =  DIO_enumOUTPUTLOW  ;
			/**
			*@ send enable signal to LCD
			*/
			DIO_enumSetCFG( & LCDPINS [ENABLE] );
				
				
		#elif (DATA_LENGTH == FOUR_BITS_MODE)
			
		
				
				/**
				*@ Enable Rising edge
				*/
				LCDPINS[ENABLE].PORT_strCFGType =  DIO_enumOUTPUTHIGH  ;
				/**
				*@ set pins configrations according to data sheet sequence
				*/
				LCDPINS[READ_WRITE].PORT_strCFGType =  DIO_enumOUTPUTLOW   ;
				LCDPINS[REG_SEL]   .PORT_strCFGType =  DIO_enumOUTPUTLOW   ;
			    LCDPINS[DATA_BIT4] .PORT_strCFGType =  DIO_enumOUTPUTLOW   ;
				LCDPINS[DATA_BIT5] .PORT_strCFGType =  DIO_enumOUTPUTLOW   ;			
				LCDPINS[DATA_BIT6] .PORT_strCFGType =  DIO_enumOUTPUTLOW   ;
				LCDPINS[DATA_BIT7] .PORT_strCFGType =  DIO_enumOUTPUTLOW   ;	
			
			for( LOCAL_u8Iterator = 0 ; LOCAL_u8Iterator < LCD_PINS_NUM ; LOCAL_u8Iterator++)
			{
					/**
					*@ call DIO_enumSetCFG function to set configration in DIO Driver
					*@ and check return of DIO_enumSetCFG function ok or not ok
					*/		
						DIO_enumSetCFG( & LCDPINS [LOCAL_u8Iterator] );
		
			}/*for loop*/
			delay_ms(1);
			/**
			*@ Enable falling edge
			*/
			LCDPINS[ENABLE].PORT_strCFGType =  DIO_enumOUTPUTLOW  ;
			/**
			*@ send enable signal to LCD
			*/
			DIO_enumSetCFG( & LCDPINS [ENABLE] );
			
			
			
				/**
				*@ Enable Rising edge
				*/
				LCDPINS[ENABLE].PORT_strCFGType =  DIO_enumOUTPUTHIGH  ;
				
				LCDPINS[READ_WRITE].PORT_strCFGType =  DIO_enumOUTPUTLOW   	  ;
				LCDPINS[REG_SEL]   .PORT_strCFGType =  DIO_enumOUTPUTLOW  	  ;				
				LCDPINS[DATA_BIT4] .PORT_strCFGType =  SHIFTING_MODE  		  ;
				LCDPINS[DATA_BIT5] .PORT_strCFGType =  INCREMENT_DECREMENT_MODE ;	
				LCDPINS[DATA_BIT6] .PORT_strCFGType =  DIO_enumOUTPUTHIGH   	  ;
				LCDPINS[DATA_BIT7] .PORT_strCFGType =  DIO_enumOUTPUTLOW   	  ;	
				
			for( LOCAL_u8Iterator = 0 ; LOCAL_u8Iterator < LCD_PINS_NUM ; LOCAL_u8Iterator++)
			{
					/**
					*@ call DIO_enumSetCFG function to set configration in DIO Driver
					*@ and check return of DIO_enumSetCFG function ok or not ok
					*/		
						DIO_enumSetCFG( & LCDPINS [LOCAL_u8Iterator] );
			
			}/*for loop*/
			delay_ms(1);
			/**
			*@ Enable falling edge
			*/
			LCDPINS[ENABLE].PORT_strCFGType =  DIO_enumOUTPUTLOW  ;
			/**
			*@ send enable signal to LCD
			*/
			DIO_enumSetCFG( & LCDPINS [ENABLE] );
				

		#else
			
		#endif	

	
}/*LCD_voidEntryModeSet function*/





/**
*@ Set ON/OFF of entire display (D),
*@ cursor ON/OFF(C), and blinking
*@ of cursor position character(B.
*/
void LCD_voidDisplay_ON_OFF_Control(void)
{
		/**
		*@ iterator used in for loop to configure every single pin using DIO driver
		*/
		u8 LOCAL_u8Iterator = 0 ;

	
		/**
		*@ check the operational mode 4 pins or 8 pins
		*/
		#if	(DATA_LENGTH == EIGHT_BITS_MODE)
			
		
				/**
				*@ Enable Rising edge
				*/
				LCDPINS[ENABLE].PORT_strCFGType =  DIO_enumOUTPUTHIGH  ;
				/**
				*@ set pins configrations according to data sheet sequence
				*/
				LCDPINS[REG_SEL]   .PORT_strCFGType =  DIO_enumOUTPUTLOW   ;
				LCDPINS[READ_WRITE].PORT_strCFGType =  DIO_enumOUTPUTLOW   ;
			    LCDPINS[DATA_BIT0] .PORT_strCFGType =  CURSOR_BLNKING_MODE ;
				LCDPINS[DATA_BIT1] .PORT_strCFGType =  CURSOR_MODE	     ;			
				LCDPINS[DATA_BIT2] .PORT_strCFGType =  ENTIRE_DISPLAY_MODE ;
				LCDPINS[DATA_BIT3] .PORT_strCFGType =  DIO_enumOUTPUTLOW   ;	
				LCDPINS[DATA_BIT4] .PORT_strCFGType =  DIO_enumOUTPUTLOW   ;
				LCDPINS[DATA_BIT5] .PORT_strCFGType =  DIO_enumOUTPUTLOW   ;	
				LCDPINS[DATA_BIT6] .PORT_strCFGType =  DIO_enumOUTPUTLOW   ;
				LCDPINS[DATA_BIT7] .PORT_strCFGType =  DIO_enumOUTPUTLOW   ;	
						
			for( LOCAL_u8Iterator = 0 ; LOCAL_u8Iterator < LCD_PINS_NUM ; LOCAL_u8Iterator++)
			{
					/**
					*@ call DIO_enumSetCFG function to set configration in DIO Driver
					*@ and check return of DIO_enumSetCFG function ok or not ok
					*/		
						DIO_enumSetCFG( & LCDPINS [LOCAL_u8Iterator] );
			
			}/*for loop*/
			delay_ms(1);
			/**
			*@ Enable falling edge
			*/
			LCDPINS[ENABLE].PORT_strCFGType =  DIO_enumOUTPUTLOW  ;
			/**
			*@ send enable signal to LCD
			*/
			DIO_enumSetCFG( & LCDPINS [ENABLE] );




		#elif (DATA_LENGTH == FOUR_BITS_MODE)
			
		
		
				/**
				*@ Enable Rising edge
				*/
				LCDPINS[ENABLE].PORT_strCFGType =  DIO_enumOUTPUTHIGH  ;	
				/**
				*@ set pins configrations according to data sheet sequence
				*/
				LCDPINS[READ_WRITE].PORT_strCFGType =  DIO_enumOUTPUTLOW   ;
				LCDPINS[REG_SEL]   .PORT_strCFGType =  DIO_enumOUTPUTLOW   ;
			    LCDPINS[DATA_BIT4] .PORT_strCFGType =  DIO_enumOUTPUTLOW   ;
				LCDPINS[DATA_BIT5] .PORT_strCFGType =  DIO_enumOUTPUTLOW   ;			
				LCDPINS[DATA_BIT6] .PORT_strCFGType =  DIO_enumOUTPUTLOW   ;
				LCDPINS[DATA_BIT7] .PORT_strCFGType =  DIO_enumOUTPUTLOW   ;	
				
			for( LOCAL_u8Iterator = 0 ; LOCAL_u8Iterator < LCD_PINS_NUM ; LOCAL_u8Iterator++)
			{
					/**
					*@ call DIO_enumSetCFG function to set configration in DIO Driver
					*@ and check return of DIO_enumSetCFG function ok or not ok
					*/		
						DIO_enumSetCFG( & LCDPINS [LOCAL_u8Iterator] );
			
			}/*for loop*/
			delay_ms(1);
			/**
			*@ Enable falling edge
			*/
			LCDPINS[ENABLE].PORT_strCFGType =  DIO_enumOUTPUTLOW  ;
			/**
			*@ send enable signal to LCD
			*/
			DIO_enumSetCFG( & LCDPINS [ENABLE] );
			
			
			
				/**
				*@ Enable Rising edge
				*/
				LCDPINS[ENABLE].PORT_strCFGType =  DIO_enumOUTPUTHIGH  ;
					
				LCDPINS[READ_WRITE].PORT_strCFGType =  DIO_enumOUTPUTLOW     ;
				LCDPINS[REG_SEL]   .PORT_strCFGType =  DIO_enumOUTPUTLOW     ;
				LCDPINS[DATA_BIT4] .PORT_strCFGType =  CURSOR_BLNKING_MODE   ;
				LCDPINS[DATA_BIT5] .PORT_strCFGType =  CURSOR_MODE           ;	
				LCDPINS[DATA_BIT6] .PORT_strCFGType =  ENTIRE_DISPLAY_MODE   ;
				LCDPINS[DATA_BIT7] .PORT_strCFGType =  DIO_enumOUTPUTHIGH    ;	
		
			for( LOCAL_u8Iterator = 0 ; LOCAL_u8Iterator < LCD_PINS_NUM ; LOCAL_u8Iterator++)
			{
					/**
					*@ call DIO_enumSetCFG function to set configration in DIO Driver
					*@ and check return of DIO_enumSetCFG function ok or not ok
					*/		
						DIO_enumSetCFG( & LCDPINS [LOCAL_u8Iterator] );
			
			}/*for loop*/
			delay_ms(1);
			/**
			*@ Enable falling edge
			*/
			LCDPINS[ENABLE].PORT_strCFGType =  DIO_enumOUTPUTLOW  ;
			/**
			*@ send enable signal to LCD
			*/
			DIO_enumSetCFG( & LCDPINS [ENABLE] );

				
		#else
			
		#endif	

	
}/*LCD_voidDisplay_ON_OFF_Control function*/





/**
*@ Moves cursor and shifts display
*@ without changing DDRAM contents.
*/
void LCD_voidCursorDisplayShift(void)
{
	
		/**
		*@ iterator used in for loop to configure every single pin using DIO driver
		*/
		u8 LOCAL_u8Iterator = 0 ;

				/**
				*@ Enable Rising edge
				*/
				LCDPINS[ENABLE].PORT_strCFGType =  DIO_enumOUTPUTHIGH  ;
				/**
				*@ set pins configrations according to data sheet sequence
				*/
				LCDPINS[REG_SEL]   .PORT_strCFGType =  DIO_enumOUTPUTLOW  		   ;
				LCDPINS[READ_WRITE].PORT_strCFGType =  DIO_enumOUTPUTLOW  		   ;
			    LCDPINS[DATA_BIT0] .PORT_strCFGType =  DIO_enumOUTPUTLOW  		   ;
				LCDPINS[DATA_BIT1] .PORT_strCFGType =  DIO_enumOUTPUTLOW  		   ;			
				LCDPINS[DATA_BIT2] .PORT_strCFGType =  ENTIRE_DISPLAY_SHIFT_MODE     ;
				LCDPINS[DATA_BIT3] .PORT_strCFGType =  CURSOR_SHIFT_MODE			   ;	
				LCDPINS[DATA_BIT4] .PORT_strCFGType =  DIO_enumOUTPUTLOW			   ;
				LCDPINS[DATA_BIT5] .PORT_strCFGType =  DIO_enumOUTPUTLOW			   ;	
				LCDPINS[DATA_BIT6] .PORT_strCFGType =  DIO_enumOUTPUTLOW			   ;
				LCDPINS[DATA_BIT7] .PORT_strCFGType =  DIO_enumOUTPUTLOW			   ;	

			
			for( LOCAL_u8Iterator = 0 ; LOCAL_u8Iterator < LCD_PINS_NUM ; LOCAL_u8Iterator++)
			{
					/**
					*@ call DIO_enumSetCFG function to set configration in DIO Driver
					*@ and check return of DIO_enumSetCFG function ok or not ok
					*/		
						DIO_enumSetCFG( & LCDPINS [LOCAL_u8Iterator] );
			
			}/*for loop*/
			delay_ms(1);
			/**
			*@ Enable falling edge
			*/
			LCDPINS[ENABLE].PORT_strCFGType =  DIO_enumOUTPUTLOW  ;
			/**
			*@ send enable signal to LCD
			*/
			DIO_enumSetCFG( & LCDPINS [ENABLE] );	

	
}/*LCD_voidCursorDisplayShift function*/





/**
*@ Sets interface data length (DL:
*@ 8-bit/4-bit), numbers of display
*@ line (N: 2-line/1-line), and display
*@ font type (F: 5x11dots/5x8dots).
*/
void LCD_voidFunctionSet(void)
{
	
		/**
		*@ iterator used in for loop to configure every single pin using DIO driver
		*/
		u8 LOCAL_u8Iterator = 0 ;

	
		/**
		*@ check the operational mode 4 pins or 8 pins
		*/
		#if	(DATA_LENGTH == EIGHT_BITS_MODE)
				
				/**
				*@ Enable Rising edge
				*/
				LCDPINS[ENABLE].PORT_strCFGType =  DIO_enumOUTPUTHIGH  ;
				/**
				*@ set pins configrations according to data sheet sequence
				*/
				LCDPINS[REG_SEL]   .PORT_strCFGType =  DIO_enumOUTPUTLOW   ;
				LCDPINS[READ_WRITE].PORT_strCFGType =  DIO_enumOUTPUTLOW   ;
			    LCDPINS[DATA_BIT0] .PORT_strCFGType =  DIO_enumOUTPUTLOW   ;
				LCDPINS[DATA_BIT1] .PORT_strCFGType =  DIO_enumOUTPUTLOW   ;			
				LCDPINS[DATA_BIT2] .PORT_strCFGType =  DISPLAY_FONT_TYPE   ;
				LCDPINS[DATA_BIT3] .PORT_strCFGType =  DISPLAY_LINES_NUM   ;	
				LCDPINS[DATA_BIT4] .PORT_strCFGType =  DIO_enumOUTPUTHIGH  ;
				LCDPINS[DATA_BIT5] .PORT_strCFGType =  DIO_enumOUTPUTHIGH  ;	
				LCDPINS[DATA_BIT6] .PORT_strCFGType =  DIO_enumOUTPUTLOW   ;
				LCDPINS[DATA_BIT7] .PORT_strCFGType =  DIO_enumOUTPUTLOW   ;	
		
			for( LOCAL_u8Iterator = 0 ; LOCAL_u8Iterator < LCD_PINS_NUM ; LOCAL_u8Iterator++)
			{
					/**
					*@ call DIO_enumSetCFG function to set configration in DIO Driver
					*@ and check return of DIO_enumSetCFG function ok or not ok
					*/		
						DIO_enumSetCFG( & LCDPINS [LOCAL_u8Iterator] );
			
			}/*for loop*/		
			delay_ms(1);
			
			/**
			*@ Enable Falling edge
			*/
			LCDPINS[ENABLE].PORT_strCFGType =  DIO_enumOUTPUTLOW;
			/**
			*@ enable signal to LCD to write configrations
			*/
			DIO_enumSetCFG( & LCDPINS [ENABLE] );
			delay_ms(1);
			
		#elif (DATA_LENGTH == FOUR_BITS_MODE)
		
	
				/**
				*@ Enable Rising edge
				*/
				LCDPINS[ENABLE].PORT_strCFGType =  DIO_enumOUTPUTHIGH  ;
				/**
				*@ set pins configrations according to data sheet sequence
				*/
				LCDPINS[READ_WRITE].PORT_strCFGType =  DIO_enumOUTPUTLOW   ;
				LCDPINS[REG_SEL]   .PORT_strCFGType =  DIO_enumOUTPUTLOW   ;
			    LCDPINS[DATA_BIT4] .PORT_strCFGType =  DIO_enumOUTPUTLOW   ;
				LCDPINS[DATA_BIT5] .PORT_strCFGType =  DIO_enumOUTPUTHIGH  ;			
				LCDPINS[DATA_BIT6] .PORT_strCFGType =  DIO_enumOUTPUTLOW   ;
				LCDPINS[DATA_BIT7] .PORT_strCFGType =  DIO_enumOUTPUTLOW   ;	
			for( LOCAL_u8Iterator = 0 ; LOCAL_u8Iterator < LCD_PINS_NUM ; LOCAL_u8Iterator++)
			{
					/**
					*@ call DIO_enumSetCFG function to set configration in DIO Driver
					*@ and check return of DIO_enumSetCFG function ok or not ok
					*/		
						DIO_enumSetCFG( & LCDPINS [LOCAL_u8Iterator] );
			
			}/*for loop*/	
			delay_ms(1);
			/**
			*@ Enable Falling edge
			*/
			LCDPINS[ENABLE].PORT_strCFGType =  DIO_enumOUTPUTLOW;
			/**
			*@ enable signal to LCD to write configrations
			*/
			DIO_enumSetCFG( & LCDPINS [ENABLE] );
			delay_ms(1);
			
			
			
			
				/**
				*@ Enable Rising edge
				*/
				LCDPINS[ENABLE].PORT_strCFGType =  DIO_enumOUTPUTHIGH  ;
				/**
				*@ the remainig four bits
				*/
				LCDPINS[READ_WRITE].PORT_strCFGType =  DIO_enumOUTPUTLOW   ;
				LCDPINS[REG_SEL]   .PORT_strCFGType =  DIO_enumOUTPUTLOW   ;
				LCDPINS[DATA_BIT4] .PORT_strCFGType =  DIO_enumOUTPUTLOW   ;
				LCDPINS[DATA_BIT5] .PORT_strCFGType =  DIO_enumOUTPUTHIGH  ;	
				LCDPINS[DATA_BIT6] .PORT_strCFGType =  DIO_enumOUTPUTLOW   ;
				LCDPINS[DATA_BIT7] .PORT_strCFGType =  DIO_enumOUTPUTLOW   ;	
				
			for( LOCAL_u8Iterator = 0 ; LOCAL_u8Iterator < LCD_PINS_NUM ; LOCAL_u8Iterator++)
			{
					/**
					*@ call DIO_enumSetCFG function to set configration in DIO Driver
					*@ and check return of DIO_enumSetCFG function ok or not ok
					*/		
						DIO_enumSetCFG( & LCDPINS [LOCAL_u8Iterator] );
			
			}/*for loop*/	
			delay_ms(1);
			/**
			*@ Enable Falling edge
			*/
			LCDPINS[ENABLE].PORT_strCFGType =  DIO_enumOUTPUTLOW;
			/**
			*@ enable signal to LCD to write configrations
			*/
			DIO_enumSetCFG( & LCDPINS [ENABLE] );
			delay_ms(1);
			
			
				/**
				*@ Enable Rising edge
				*/
				LCDPINS[ENABLE].PORT_strCFGType =  DIO_enumOUTPUTHIGH  ;
				/**
				*@ the remaining two bits
				*/
				LCDPINS[READ_WRITE].PORT_strCFGType =  DIO_enumOUTPUTLOW   ;
				LCDPINS[REG_SEL]   .PORT_strCFGType =  DIO_enumOUTPUTLOW   ;
				LCDPINS[DATA_BIT6] .PORT_strCFGType =  DISPLAY_FONT_TYPE   ;
				LCDPINS[DATA_BIT7] .PORT_strCFGType =  DISPLAY_LINES_NUM   ;	
				
			for( LOCAL_u8Iterator = 0 ; LOCAL_u8Iterator < LCD_PINS_NUM ; LOCAL_u8Iterator++)
			{
					/**
					*@ call DIO_enumSetCFG function to set configration in DIO Driver
					*@ and check return of DIO_enumSetCFG function ok or not ok
					*/		
						DIO_enumSetCFG( & LCDPINS [LOCAL_u8Iterator] );
			
			}/*for loop*/	
			delay_ms(1);
			/**
			*@ Enable Falling edge
			*/
			LCDPINS[ENABLE].PORT_strCFGType =  DIO_enumOUTPUTLOW;
			/**
			*@ enable signal to LCD to write configrations
			*/
			DIO_enumSetCFG( & LCDPINS [ENABLE] );
			delay_ms(1);
		#else
			
		#endif			   			
			 

	
}/*LCD_voidFunctionSet function*/






/**
*@ set cgram address function
*/
void LCD_voidSetCGRAMAddress(u8 Copy_u8Address)
{
	
		/**
		*@ iterator used in for loop to configure every single pin using DIO driver
		*/
		u8 LOCAL_u8Iterator = 0 ;

		/**
		*@ check the operational mode 4 pins or 8 pins
		*/
		#if	(DATA_LENGTH == EIGHT_BITS_MODE)
				
				/**
				*@ Enable Rising edge
				*/
				LCDPINS[ENABLE].PORT_strCFGType =  DIO_enumOUTPUTHIGH  ;
				/**
				*@ set pins configrations according to data sheet sequence
				*/
				LCDPINS[REG_SEL]   .PORT_strCFGType =  DIO_enumOUTPUTLOW				      ;
				LCDPINS[READ_WRITE].PORT_strCFGType =  DIO_enumOUTPUTLOW				      ;
			    LCDPINS[DATA_BIT0] .PORT_strCFGType =  GET_BIT(Copy_u8Address,DATA_BIT0)    ;
				LCDPINS[DATA_BIT1] .PORT_strCFGType =  GET_BIT(Copy_u8Address,DATA_BIT1)    ;			
				LCDPINS[DATA_BIT2] .PORT_strCFGType =  GET_BIT(Copy_u8Address,DATA_BIT2)    ;
				LCDPINS[DATA_BIT3] .PORT_strCFGType =  GET_BIT(Copy_u8Address,DATA_BIT3)    ;	
				LCDPINS[DATA_BIT4] .PORT_strCFGType =  GET_BIT(Copy_u8Address,DATA_BIT4)    ;
				LCDPINS[DATA_BIT5] .PORT_strCFGType =  GET_BIT(Copy_u8Address,DATA_BIT5)    ;	
				LCDPINS[DATA_BIT6] .PORT_strCFGType =  DIO_enumOUTPUTHIGH				      ;
				LCDPINS[DATA_BIT7] .PORT_strCFGType =  DIO_enumOUTPUTLOW				      ;	

				
			for( LOCAL_u8Iterator = 0 ; LOCAL_u8Iterator < LCD_PINS_NUM ; LOCAL_u8Iterator++)
			{
					/**
					*@ call DIO_enumSetCFG function to set configration in DIO Driver
					*@ and check return of DIO_enumSetCFG function ok or not ok
					*/		
						DIO_enumSetCFG( & LCDPINS [LOCAL_u8Iterator] );
			
			}/*for loop*/	
			delay_ms(1);
			/**
			*@ Enable falling edge
			*/
			LCDPINS[ENABLE].PORT_strCFGType =  DIO_enumOUTPUTLOW  ;
			/**
			*@ send enable signal to LCD
			*/
			DIO_enumSetCFG( & LCDPINS [ENABLE] );
			
		#elif (DATA_LENGTH == FOUR_BITS_MODE)
			
		
				/**
				*@ Enable Rising edge
				*/
				LCDPINS[ENABLE].PORT_strCFGType =  DIO_enumOUTPUTHIGH  ;
				/**
				*@ set pins configrations according to data sheet sequence
				*/
				LCDPINS[REG_SEL]   .PORT_strCFGType =  DIO_enumOUTPUTLOW					  ;
				LCDPINS[READ_WRITE].PORT_strCFGType =  DIO_enumOUTPUTLOW				      ;
				LCDPINS[DATA_BIT4] .PORT_strCFGType =  GET_BIT(Copy_u8Address,DATA_BIT4)    ;
				LCDPINS[DATA_BIT5] .PORT_strCFGType =  GET_BIT(Copy_u8Address,DATA_BIT5)    ;	
				LCDPINS[DATA_BIT6] .PORT_strCFGType =  DIO_enumOUTPUTHIGH				      ;
				LCDPINS[DATA_BIT7] .PORT_strCFGType =  DIO_enumOUTPUTLOW				      ;	

				
			for( LOCAL_u8Iterator = 0 ; LOCAL_u8Iterator < LCD_PINS_NUM ; LOCAL_u8Iterator++)
			{
					/**
					*@ call DIO_enumSetCFG function to set configration in DIO Driver
					*@ and check return of DIO_enumSetCFG function ok or not ok
					*/		
						DIO_enumSetCFG( & LCDPINS [LOCAL_u8Iterator] );
			
			}/*for loop*/
			delay_ms(1);
			/**
			*@ Enable falling edge
			*/
			LCDPINS[ENABLE].PORT_strCFGType =  DIO_enumOUTPUTLOW  ;
			/**
			*@ send enable signal to LCD
			*/
			DIO_enumSetCFG( & LCDPINS [ENABLE] );
			
			
				/**
				*@ Enable Rising edge
				*/
				LCDPINS[ENABLE].PORT_strCFGType =  DIO_enumOUTPUTHIGH  ;
				
				LCDPINS[REG_SEL]   .PORT_strCFGType =  DIO_enumOUTPUTLOW				     ;
				LCDPINS[READ_WRITE].PORT_strCFGType =  DIO_enumOUTPUTLOW 				     ;
			    LCDPINS[DATA_BIT4] .PORT_strCFGType =  GET_BIT(Copy_u8Address,DATA_BIT0)   ;
				LCDPINS[DATA_BIT5] .PORT_strCFGType =  GET_BIT(Copy_u8Address,DATA_BIT1)   ;			
				LCDPINS[DATA_BIT6] .PORT_strCFGType =  GET_BIT(Copy_u8Address,DATA_BIT2)   ;
				LCDPINS[DATA_BIT7] .PORT_strCFGType =  GET_BIT(Copy_u8Address,DATA_BIT3)   ;	

				
			for( LOCAL_u8Iterator = 0 ; LOCAL_u8Iterator < LCD_PINS_NUM ; LOCAL_u8Iterator++)
			{
					/**
					*@ call DIO_enumSetCFG function to set configration in DIO Driver
					*@ and check return of DIO_enumSetCFG function ok or not ok
					*/		
						DIO_enumSetCFG( & LCDPINS [LOCAL_u8Iterator] );
			
			}/*for loop*/	
			delay_ms(1);
			/**
			*@ Enable falling edge
			*/
			LCDPINS[ENABLE].PORT_strCFGType =  DIO_enumOUTPUTLOW  ;
			/**
			*@ send enable signal to LCD
			*/
			DIO_enumSetCFG( & LCDPINS [ENABLE] );
		#else
			
		#endif			   			
			 

	
	
	
	
	
}/*LCD_voidSetCGRAMAddress function*/





/**
*@ set ddram address function
*/
void LCD_voidSetDDRAMAddress(u8 Copy_u8Address)
{
	
		/**
		*@ iterator used in for loop to configure every single pin using DIO driver
		*/
		u8 LOCAL_u8Iterator = 0 ;

		/**
		*@ check the operational mode 4 pins or 8 pins
		*/
		#if	(DATA_LENGTH == EIGHT_BITS_MODE)
			
		
				/**
				*@ Enable falling edge
				*/
				LCDPINS[ENABLE].PORT_strCFGType =  DIO_enumOUTPUTHIGH  ;
				/**
				*@ set pins configrations according to data sheet sequence
				*/
				LCDPINS[REG_SEL]   .PORT_strCFGType =  DIO_enumOUTPUTLOW				     ;
				LCDPINS[READ_WRITE].PORT_strCFGType =  DIO_enumOUTPUTLOW				     ;
			    LCDPINS[DATA_BIT0] .PORT_strCFGType =  GET_BIT(Copy_u8Address,DATA_BIT0)   ;
				LCDPINS[DATA_BIT1] .PORT_strCFGType =  GET_BIT(Copy_u8Address,DATA_BIT1)   ;			
				LCDPINS[DATA_BIT2] .PORT_strCFGType =  GET_BIT(Copy_u8Address,DATA_BIT2)   ;
				LCDPINS[DATA_BIT3] .PORT_strCFGType =  GET_BIT(Copy_u8Address,DATA_BIT3)   ;	
				LCDPINS[DATA_BIT4] .PORT_strCFGType =  GET_BIT(Copy_u8Address,DATA_BIT4)   ;
				LCDPINS[DATA_BIT5] .PORT_strCFGType =  GET_BIT(Copy_u8Address,DATA_BIT5)   ;	
				LCDPINS[DATA_BIT6] .PORT_strCFGType =  GET_BIT(Copy_u8Address,DATA_BIT6)   ;
				LCDPINS[DATA_BIT7] .PORT_strCFGType =  DIO_enumOUTPUTHIGH				     ;	
			
			for( LOCAL_u8Iterator = 0 ; LOCAL_u8Iterator < LCD_PINS_NUM ; LOCAL_u8Iterator++)
			{
					/**
					*@ call DIO_enumSetCFG function to set configration in DIO Driver
					*@ and check return of DIO_enumSetCFG function ok or not ok
					*/		
						DIO_enumSetCFG( & LCDPINS [LOCAL_u8Iterator] );
			
			}/*for loop*/	
			delay_ms(1);
			/**
			*@ Enable falling edge
			*/
			LCDPINS[ENABLE].PORT_strCFGType =  DIO_enumOUTPUTLOW  ;
			/**
			*@ send enable signal to LCD
			*/
			DIO_enumSetCFG( & LCDPINS [ENABLE] );
	
		#elif (DATA_LENGTH == FOUR_BITS_MODE)
			
				/**
				*@ Enable falling edge
				*/
				LCDPINS[ENABLE].PORT_strCFGType =  DIO_enumOUTPUTHIGH  ;
				/**
				*@ set pins configrations according to data sheet sequence
				*/
				LCDPINS[REG_SEL]   .PORT_strCFGType =  DIO_enumOUTPUTLOW   				 ;
				LCDPINS[READ_WRITE].PORT_strCFGType =  DIO_enumOUTPUTLOW   				 ;
				LCDPINS[DATA_BIT4] .PORT_strCFGType =  GET_BIT(Copy_u8Address,DATA_BIT4)   ;
				LCDPINS[DATA_BIT5] .PORT_strCFGType =  GET_BIT(Copy_u8Address,DATA_BIT5)   ;	
				LCDPINS[DATA_BIT6] .PORT_strCFGType =  GET_BIT(Copy_u8Address,DATA_BIT6)   ;
				LCDPINS[DATA_BIT7] .PORT_strCFGType =  DIO_enumOUTPUTHIGH				     ;	
				
			for( LOCAL_u8Iterator = 0 ; LOCAL_u8Iterator < LCD_PINS_NUM ; LOCAL_u8Iterator++)
			{
					/**
					*@ call DIO_enumSetCFG function to set configration in DIO Driver
					*@ and check return of DIO_enumSetCFG function ok or not ok
					*/		
						DIO_enumSetCFG( & LCDPINS [LOCAL_u8Iterator] );
			
			}/*for loop*/		
			delay_ms(1);
			/**
			*@ Enable falling edge
			*/
			LCDPINS[ENABLE].PORT_strCFGType =  DIO_enumOUTPUTLOW  ;
			/**
			*@ send enable signal to LCD
			*/
			DIO_enumSetCFG( & LCDPINS [ENABLE] );
			
			
				/**
				*@ Enable falling edge
				*/
				LCDPINS[ENABLE].PORT_strCFGType =  DIO_enumOUTPUTHIGH  ;
			
				LCDPINS[REG_SEL]   .PORT_strCFGType =  DIO_enumOUTPUTLOW				     ;
				LCDPINS[READ_WRITE].PORT_strCFGType =  DIO_enumOUTPUTLOW				     ;
			    LCDPINS[DATA_BIT4] .PORT_strCFGType =  GET_BIT(Copy_u8Address,DATA_BIT0)   ;
				LCDPINS[DATA_BIT5] .PORT_strCFGType =  GET_BIT(Copy_u8Address,DATA_BIT1)   ;			
				LCDPINS[DATA_BIT6] .PORT_strCFGType =  GET_BIT(Copy_u8Address,DATA_BIT2)   ;
				LCDPINS[DATA_BIT7] .PORT_strCFGType =  GET_BIT(Copy_u8Address,DATA_BIT3)   ;	

			for( LOCAL_u8Iterator = 0 ; LOCAL_u8Iterator < LCD_PINS_NUM ; LOCAL_u8Iterator++)
			{
					/**
					*@ call DIO_enumSetCFG function to set configration in DIO Driver
					*@ and check return of DIO_enumSetCFG function ok or not ok
					*/		
						DIO_enumSetCFG( & LCDPINS [LOCAL_u8Iterator] );
			
			}/*for loop*/		
			delay_ms(1);	
			/**
			*@ Enable falling edge
			*/
			LCDPINS[ENABLE].PORT_strCFGType =  DIO_enumOUTPUTLOW  ;
			/**
			*@ send enable signal to LCD
			*/
			DIO_enumSetCFG( & LCDPINS [ENABLE] );
		#else
			
		#endif			   			
			 

		
}/*LCD_voidSetCGRAMAddress function*/




/**
*@  Write Data to CG or DD RAM
*/
void LCD_voidWriteCharacter_CG_DDRAM(u8 Copy_u8Data)
{
	
		/**
		*@ iterator used in for loop to configure every single pin using DIO driver
		*/
		u8 LOCAL_u8Iterator = 0 ;

		/**
		*@ check the operational mode 4 pins or 8 pins
		*/
		#if	(DATA_LENGTH == EIGHT_BITS_MODE)
			
				/**
				*@ Enable Rising edge
				*/
				LCDPINS[ENABLE].PORT_strCFGType =  DIO_enumOUTPUTHIGH  ;
				/**
				*@ set pins configrations according to data sheet sequence
				*/
				LCDPINS[ENABLE]    .PORT_strCFGType =  DIO_enumOUTPUTHIGH			      ;
				LCDPINS[REG_SEL]   .PORT_strCFGType =  DIO_enumOUTPUTHIGH 			  ;
				LCDPINS[READ_WRITE].PORT_strCFGType =  DIO_enumOUTPUTLOW  			  ;
			    LCDPINS[DATA_BIT0] .PORT_strCFGType =  GET_BIT(Copy_u8Data,DATA_BIT0)   ;
				LCDPINS[DATA_BIT1] .PORT_strCFGType =  GET_BIT(Copy_u8Data,DATA_BIT1)   ;			
				LCDPINS[DATA_BIT2] .PORT_strCFGType =  GET_BIT(Copy_u8Data,DATA_BIT2)   ;
				LCDPINS[DATA_BIT3] .PORT_strCFGType =  GET_BIT(Copy_u8Data,DATA_BIT3)   ;	
				LCDPINS[DATA_BIT4] .PORT_strCFGType =  GET_BIT(Copy_u8Data,DATA_BIT4)   ;
				LCDPINS[DATA_BIT5] .PORT_strCFGType =  GET_BIT(Copy_u8Data,DATA_BIT5)   ;	
				LCDPINS[DATA_BIT6] .PORT_strCFGType =  GET_BIT(Copy_u8Data,DATA_BIT6)   ;
				LCDPINS[DATA_BIT7] .PORT_strCFGType =  GET_BIT(Copy_u8Data,DATA_BIT7)   ;	
				LCDPINS[ENABLE]    .PORT_strCFGType =  DIO_enumOUTPUTLOW			      ;
			
			for( LOCAL_u8Iterator = 0 ; LOCAL_u8Iterator < LCD_PINS_NUM ; LOCAL_u8Iterator++)
			{
					/**
					*@ call DIO_enumSetCFG function to set configration in DIO Driver
					*@ and check return of DIO_enumSetCFG function ok or not ok
					*/		
						DIO_enumSetCFG( & LCDPINS [LOCAL_u8Iterator] );
			
			}/*for loop*/	
			delay_ms(1);
			/**
			*@ Enable falling edge
			*/
			LCDPINS[ENABLE].PORT_strCFGType =  DIO_enumOUTPUTLOW  ;
			/**
			*@ send enable signal to LCD
			*/
			DIO_enumSetCFG( & LCDPINS [ENABLE] );
	
		#elif (DATA_LENGTH == FOUR_BITS_MODE)
			
		
				/**
				*@ Enable Rising edge
				*/
				LCDPINS[ENABLE].PORT_strCFGType =  DIO_enumOUTPUTHIGH  ;
				/**
				*@ set pins configrations according to data sheet sequence
				*/
				LCDPINS[ENABLE]    .PORT_strCFGType =  DIO_enumOUTPUTHIGH				   ;
				LCDPINS[REG_SEL]   .PORT_strCFGType =  DIO_enumOUTPUTHIGH				   ;
				LCDPINS[READ_WRITE].PORT_strCFGType =  DIO_enumOUTPUTLOW 				   ;
				LCDPINS[DATA_BIT4] .PORT_strCFGType =  GET_BIT(Copy_u8Data,DATA_BIT4)    ;
				LCDPINS[DATA_BIT5] .PORT_strCFGType =  GET_BIT(Copy_u8Data,DATA_BIT5)    ;	
				LCDPINS[DATA_BIT6] .PORT_strCFGType =  GET_BIT(Copy_u8Data,DATA_BIT6)    ;
				LCDPINS[DATA_BIT7] .PORT_strCFGType =  GET_BIT(Copy_u8Data,DATA_BIT7)    ;	
				LCDPINS[ENABLE]    .PORT_strCFGType =  DIO_enumOUTPUTLOW				   ;
				
			for( LOCAL_u8Iterator = 0 ; LOCAL_u8Iterator < LCD_PINS_NUM ; LOCAL_u8Iterator++)
			{
					/**
					*@ call DIO_enumSetCFG function to set configration in DIO Driver
					*@ and check return of DIO_enumSetCFG function ok or not ok
					*/		
						DIO_enumSetCFG( & LCDPINS [LOCAL_u8Iterator] );
			
			}/*for loop*/		
			delay_ms(1);
			/**
			*@ Enable falling edge
			*/
			LCDPINS[ENABLE].PORT_strCFGType =  DIO_enumOUTPUTLOW  ;
			/**
			*@ send enable signal to LCD
			*/
			DIO_enumSetCFG( & LCDPINS [ENABLE] );
			
				/**
				*@ Enable Rising edge
				*/
				LCDPINS[ENABLE].PORT_strCFGType =  DIO_enumOUTPUTHIGH  ;
				
				LCDPINS[ENABLE]    .PORT_strCFGType =  DIO_enumOUTPUTHIGH 				  ;
				LCDPINS[REG_SEL]   .PORT_strCFGType =  DIO_enumOUTPUTHIGH 				  ;
				LCDPINS[READ_WRITE].PORT_strCFGType =  DIO_enumOUTPUTLOW  				  ;
			    LCDPINS[DATA_BIT4] .PORT_strCFGType =  GET_BIT(Copy_u8Address,DATA_BIT0)    ;
				LCDPINS[DATA_BIT5] .PORT_strCFGType =  GET_BIT(Copy_u8Address,DATA_BIT1)    ;			
				LCDPINS[DATA_BIT6] .PORT_strCFGType =  GET_BIT(Copy_u8Address,DATA_BIT2)    ;
				LCDPINS[DATA_BIT7] .PORT_strCFGType =  GET_BIT(Copy_u8Address,DATA_BIT3)    ;	
				LCDPINS[ENABLE]    .PORT_strCFGType =  DIO_enumOUTPUTLOW				      ;
				
			for( LOCAL_u8Iterator = 0 ; LOCAL_u8Iterator < LCD_PINS_NUM ; LOCAL_u8Iterator++)
			{
					/**
					*@ call DIO_enumSetCFG function to set configration in DIO Driver
					*@ and check return of DIO_enumSetCFG function ok or not ok
					*/		
						DIO_enumSetCFG( & LCDPINS [LOCAL_u8Iterator] );
			
			}/*for loop*/		
			delay_ms(1);	
			/**
			*@ Enable falling edge
			*/
			LCDPINS[ENABLE].PORT_strCFGType =  DIO_enumOUTPUTLOW  ;
			/**
			*@ send enable signal to LCD
			*/
			DIO_enumSetCFG( & LCDPINS [ENABLE] );
		#else
			
		#endif			   			
			 

		
}/*LCD_voidSetCGRAMAddress function*/



/**
*@ function to send commands to LCD controller
*/
LCD_enuErrorStatus_t LCD_enuWriteCommand(u8 Copy_u8Command)
{
	
		/**
		*@ iterator used in for loop to configure every single pin using DIO driver
		*/
		u8 LOCAL_u8Iterator = 0 ;

	
		/**
		*@ Error status return variable
		*/
		LCD_enuErrorStatus_t LCD_RETURN_ERRORSTATUS = LCD_enuOK;
	
		/**
		*@ check the operational mode 4 pins or 8 pins
		*/
		#if	(DATA_LENGTH == EIGHT_BITS_MODE)

		
			/**
			*@ intialization sequence according to datasheet
			*@ set RW=0  & Set RS=0 & Activate Enable Bit
			*/
			LCDPINS[READ_WRITE].PORT_strCFGType =  DIO_enumOUTPUTLOW   ;
			LCDPINS[REG_SEL]   .PORT_strCFGType =  DIO_enumOUTPUTLOW   ;
			
			/**
			*@ Enable Falling edge
			*/
			LCDPINS[ENABLE].PORT_strCFGType =  DIO_enumOUTPUTHIGH  ;
			
			
				/**
				*@ set pins configrations according to the input command
				*/
			    LCDPINS[DATA_BIT0] .PORT_strCFGType =  GET_BIT(Copy_u8Command,DATA_BIT0)   ;
				LCDPINS[DATA_BIT1] .PORT_strCFGType =  GET_BIT(Copy_u8Command,DATA_BIT1)   ;			
				LCDPINS[DATA_BIT2] .PORT_strCFGType =  GET_BIT(Copy_u8Command,DATA_BIT2)   ;
				LCDPINS[DATA_BIT3] .PORT_strCFGType =  GET_BIT(Copy_u8Command,DATA_BIT3)   ;	
				LCDPINS[DATA_BIT4] .PORT_strCFGType =  GET_BIT(Copy_u8Command,DATA_BIT4)   ;
				LCDPINS[DATA_BIT5] .PORT_strCFGType =  GET_BIT(Copy_u8Command,DATA_BIT5)   ;	
				LCDPINS[DATA_BIT6] .PORT_strCFGType =  GET_BIT(Copy_u8Command,DATA_BIT6)   ;
				LCDPINS[DATA_BIT7] .PORT_strCFGType =  GET_BIT(Copy_u8Command,DATA_BIT7)   ;	
			delay_ms(1);
			
			
			for( LOCAL_u8Iterator = 0 ; LOCAL_u8Iterator < LCD_PINS_NUM ; LOCAL_u8Iterator++)
			{
					/**
					*@ call DIO_enumSetCFG function to set configration in DIO Driver
					*@ and check return of DIO_enumSetCFG function ok or not ok
					*/		
						DIO_enumSetCFG( & LCDPINS [LOCAL_u8Iterator] );
			
			}/*for loop*/		
			delay_ms(1);
			/**
			*@ Enable Falling edge
			*/
			LCDPINS[ENABLE].PORT_strCFGType =  DIO_enumOUTPUTLOW;
			/**
			*@ enable signal to LCD to write configrations
			*/
			DIO_enumSetCFG( & LCDPINS [ENABLE] );
			
			delay_ms(1);
			
		#elif (DATA_LENGTH == FOUR_BITS_MODE)
			/**
			*@ intialization sequence according to datasheet
			*@ set RW=0  & Set RS=0 & Activate Enable Bit
			*/
			LCDPINS[READ_WRITE].PORT_strCFGType =  DIO_enumOUTPUTLOW   ;
			LCDPINS[REG_SEL]   .PORT_strCFGType =  DIO_enumOUTPUTLOW   ;
			
			/**
			*@ Enable Rising edge
			*/
			LCDPINS[ENABLE] .PORT_strCFGType =  DIO_enumOUTPUTHIGH;
			
			
				/**
				*@ set pins configrations according to the input command
				*/
				LCDPINS[DATA_BIT4].PORT_strCFGType =  GET_BIT(Copy_u8Command,DATA_BIT4)   ;
				LCDPINS[DATA_BIT5].PORT_strCFGType =  GET_BIT(Copy_u8Command,DATA_BIT5)   ;	
				LCDPINS[DATA_BIT6].PORT_strCFGType =  GET_BIT(Copy_u8Command,DATA_BIT6)   ;
				LCDPINS[DATA_BIT7].PORT_strCFGType =  GET_BIT(Copy_u8Command,DATA_BIT7)   ;
			/**
			*@ send the configration to LCD
			*/
			for( LOCAL_u8Iterator = 0 ; LOCAL_u8Iterator < LCD_PINS_NUM ; LOCAL_u8Iterator++)
			{
					/**
					*@ call DIO_enumSetCFG function to set configration in DIO Driver
					*@ and check return of DIO_enumSetCFG function ok or not ok
					*/		
						DIO_enumSetCFG( & LCDPINS [LOCAL_u8Iterator] );
			
			}/*for loop*/	
			delay_ms(1);
			/**
			*@ Enable  Falling edge
			*/
			LCDPINS[ENABLE].PORT_strCFGType =  DIO_enumOUTPUTLOW;
			/**
			*@ send the configration to lcd
			*/
			DIO_enumSetCFG( & LCDPINS [ENABLE] );
			
				/**
				*@ write the other four bits
				*/
			    LCDPINS[DATA_BIT4].PORT_strCFGType =  GET_BIT(Copy_u8Command,DATA_BIT0)   ;
				LCDPINS[DATA_BIT5].PORT_strCFGType =  GET_BIT(Copy_u8Command,DATA_BIT1)   ;			
				LCDPINS[DATA_BIT6].PORT_strCFGType =  GET_BIT(Copy_u8Command,DATA_BIT2)   ;
				LCDPINS[DATA_BIT7].PORT_strCFGType =  GET_BIT(Copy_u8Command,DATA_BIT3)   ;	
				/**
				*@ intialization sequence according to datasheet
				*@ set RW=0  & Set RS=0 & Activate Enable Bit
				*/
				LCDPINS[READ_WRITE].PORT_strCFGType =  DIO_enumOUTPUTLOW   ;
				LCDPINS[REG_SEL]   .PORT_strCFGType =  DIO_enumOUTPUTLOW   ;
				
				/**
				*@ Enable Rising edge
				*/
				LCDPINS[ENABLE] .PORT_strCFGType =  DIO_enumOUTPUTHIGH;
			/**	
			*@ send the configration to LCD
			*/
			for( LOCAL_u8Iterator = 0 ; LOCAL_u8Iterator < LCD_PINS_NUM ; LOCAL_u8Iterator++)
			{
					/**
					*@ call DIO_enumSetCFG function to set configration in DIO Driver
					*@ and check return of DIO_enumSetCFG function ok or not ok
					*/		
						DIO_enumSetCFG( & LCDPINS [LOCAL_u8Iterator] );
			
			}/*for loop*/	
			delay_ms(1);
			
			/**
			*@ Enable  Falling edge : enable LCD to the new Configrations
			*/
			LCDPINS[ENABLE].PORT_strCFGType =  DIO_enumOUTPUTLOW;
			/**
			*@ send to LCD
			*/
			DIO_enumSetCFG( & LCDPINS [LOCAL_u8Iterator] );
			delay_ms(1);
	
		#else
				 LCD_RETURN_ERRORSTATUS = LCD_enuNOK;
		#endif			   			
		


	return LCD_RETURN_ERRORSTATUS;		
}/*LCD_enuWriteCommand function*/




/**
*@ LCD_enuErrorStatus_t LCD_init(void);
*/
LCD_enuErrorStatus_t LCD_init(void)
{
	
	u8 LOCAL_u8Iterator;
	/**
	*@ Error status return variable
	*/
	LCD_enuErrorStatus_t LCD_RETURN_ERRORSTATUS = LCD_enuOK;
	
			/**
			*@ Enable falling edge
			*/
			LCDPINS[ENABLE].PORT_strCFGType =  DIO_enumOUTPUTLOW  ;
				DIO_enumSetCFG( & LCDPINS [LOCAL_u8Iterator] );
				/**
				*@ send the pins configrations to LCD
				*/
			for( LOCAL_u8Iterator = 0 ; LOCAL_u8Iterator < LCD_PINS_NUM ; LOCAL_u8Iterator++)
			{
					/**
					*@ call DIO_enumSetCFG function to set configration in DIO Driver
					*@ and check return of DIO_enumSetCFG function ok or not ok
					*/		
						DIO_enumSetCFG( & LCDPINS [LOCAL_u8Iterator] );
			
			}/*for loop*/
			delay_ms(1);
			/**
			*@ Enable falling edge
			*/
			LCDPINS[ENABLE].PORT_strCFGType =  DIO_enumOUTPUTLOW  ;
			/**
			*@ send enable signal to LCD
			*/
			DIO_enumSetCFG( & LCDPINS [ENABLE] );

				/**
				*@ intialization sequence according to datasheet
				*/
				delay_ms(35);
				/**
				*@ 8 bits data length, two lines mode , 5*8 mode
				*/
				LCD_enuWriteCommand(FUNCTION_SET);
				delay_ms(1);
				LCD_enuWriteCommand(DISPLAY_ON_OFF_COTROL);
				delay_ms(1);
				LCD_enuWriteCommand(DISPLAY_CLEAR);
				delay_ms(2);
				LCD_enuWriteCommand(ENTRY_MODE_SET);
				
				
	
	
	return LCD_RETURN_ERRORSTATUS;
}/*LCD_init function*/


/**
*@ function that take character from user and display it on LCD
*/
LCD_enuErrorStatus_t LCD_enuWriteCharacter(u8 Copy_u8Data)
{
	
	/**
	*@ Error status return variable
	*/
	LCD_enuErrorStatus_t LCD_RETURN_ERRORSTATUS = LCD_enuOK;

	LCD_voidWriteCharacter_CG_DDRAM(Copy_u8Data);
	
	return LCD_RETURN_ERRORSTATUS;	
	
	
	
}/*LCD_enuWriteData function*/

/**
*@ function that take integer number and display it on LCD
*/
LCD_enuErrorStatus_t LCD_enuWriteNumber(s32 Copy_u8Number)
{
	/**
	*@ Error status return variable
	*/
	LCD_enuErrorStatus_t LCD_RETURN_ERRORSTATUS = LCD_enuOK;
	
	/**
	*@ array used to save the parsed digits which be displayed individually on LCD
	*/
	u8 Local_u8ParsingArray[20];
	/**
	*@ variables used in the parsing operation
	*/
    s32 Local_s32Iterator , Local_s32Reverse_Iterator, Local_s32Iterator2 ; 
	/**
	*@ temporary variable used in swaping and signe variable used to store the number sign
	*/
	s32 Local_32Temporary, Local_32Sign;

    /**
	*@ save the sign of the number and convert it to positive if it negative
	*/
    if ((Local_32Sign = Copy_u8Number) < 0)
    	{
    	  Copy_u8Number = -1 * Copy_u8Number ;
    	}
    Local_s32Iterator = 0;
    do 
	{
		/**
		*@ parsing the input number from the most right side 
		*@ and saving it in the array from the left side to the right
		*@ adding '0' to convert it to the corresponding assci code
		*/
        Local_u8ParsingArray[Local_s32Iterator++] = Copy_u8Number % 10 + '0';
		
		Copy_u8Number /= 10 ;
		
    } while (Copy_u8Number > 0);
	
	/**
	*@ check the sign of input number if it negative to be dislayed on the LCD with the number
	*/
    if (Local_32Sign < 0) Local_u8ParsingArray[Local_s32Iterator++] = '-';
	
	/**
	*@ append null character to the array to be treated as string in ordre to using 
	*@ LCD_enuWriteString function to display the numbers on LCD
	*/
	Local_u8ParsingArray[Local_s32Iterator] = '\0';

    /*
	*@ the number digits saved in the array in reversed ordre
	*@ swapping it to be displayed in the right manner
	*/
	Local_s32Iterator2 = Local_s32Iterator -1 ;
	
    for (Local_s32Reverse_Iterator = 0 ; Local_s32Reverse_Iterator < Local_s32Iterator2 ; Local_s32Reverse_Iterator ++, Local_s32Iterator2--)
	{
        Local_32Temporary = Local_u8ParsingArray[Local_s32Reverse_Iterator];
        Local_u8ParsingArray[Local_s32Reverse_Iterator] = Local_u8ParsingArray[Local_s32Iterator2];
        Local_u8ParsingArray[Local_s32Iterator2] = Local_32Temporary;
    }
	/**
	*@ calling LCD_enuWriteString function to display the number as string
	*/
	LCD_enuWriteString(Local_u8ParsingArray);
	
	
	return LCD_RETURN_ERRORSTATUS;
}/*LCD_enuWriteNumber function*/


/**
*@ function that display array of characters on LCD
*/
LCD_enuErrorStatus_t LCD_enuWriteString(u8 * Copy_pchPattern)
{
	
	/**
	*@ Error status return variable
	*/
	LCD_enuErrorStatus_t LCD_RETURN_ERRORSTATUS = LCD_enuOK;
	/**
	*@ iterator used to parse the string to individual character to be displayed on the LCD
	*/
	u8 LOCAL_u8Iterator = 0;
		
		while(Copy_pchPattern[LOCAL_u8Iterator]!='\0')
			{
				LCD_enuWriteCharacter(Copy_pchPattern[LOCAL_u8Iterator]);
				LOCAL_u8Iterator++;
			}
	
	
	return LCD_RETURN_ERRORSTATUS;
}/* LCD_enuWriteString function */


/**
*@ function to adjust the cursor at specific position on the screen 
*@ specific row and specific column
*/
LCD_enuErrorStatus_t LCD_enuGotoDDRAM_XY(u8 Copy_u8X, u8 Copy_u8Y)
{
	/**
	*@ The Location variable to be set
	*/
	u8 Local_u8Location = 0 ;
	/**
	*@ Error status return variable
	*/
	LCD_enuErrorStatus_t LCD_RETURN_ERRORSTATUS = LCD_enuOK;
	/**
	*@ check the line number
	*/
	switch(Copy_u8X)
  {
	case FIRST_LINE :
				Local_u8Location = Copy_u8Y;
	break ;
	case SECOND_LINE :
				Local_u8Location = Copy_u8Y + 0x40;
	break ;
	
	default :
			{
				LCD_RETURN_ERRORSTATUS = LCD_enuNOK;
			}
	break;		
  }
	
	LCD_enuWriteCommand( Local_u8Location | 0x80);	
	
	return LCD_RETURN_ERRORSTATUS;
}/*LCD_enuGotoDDRAM_XY function */

/**
*@ function that take a pattern that did not exist int DDRAM 
*@ and save it in the CG RAM to be displayed in DDRAM
*/
LCD_enuErrorStatus_t LCD_enuDisplaySpecialPattern(u8* Copy_pu8Pattern, u8 Copy_u8CGRAMBlockNumber, u8 Copy_u8X, u8 Copy_u8Y)
{
	/**
	*@ Error status return variable
	*/
	LCD_enuErrorStatus_t LCD_RETURN_ERRORSTATUS = LCD_enuOK;
	
	/**
	*@ iterator used in for to save pattern in CGRAM 
	*/
	 u8 Local_u8Iterator;
		
			
	      if(Copy_u8CGRAMBlockNumber<8)
	      {
			  /**
			  *@ command to write in the CGRAM
			  */
	    	  LCD_enuWriteCommand(0x40+(Copy_u8CGRAMBlockNumber*8));
			  
			  LCD_enuGotoDDRAM_XY( Copy_u8X , Copy_u8Y );
			  
	          for(Local_u8Iterator = 0; Local_u8Iterator < 8;Local_u8Iterator++)
				
	        	{  LCD_enuWriteCharacter(Copy_pu8Pattern[ Local_u8Iterator ]); }
	      }
	
	return LCD_RETURN_ERRORSTATUS;
	
}/*LCD_enuDisplaySpecialPattern function*/