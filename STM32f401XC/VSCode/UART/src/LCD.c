/****************************************************************************
 * Author:	Bishoy Unan		
 * Date:	22/3/2024		
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
#include "BIT_MATH.h"
#include "LCD_Private.h"
#include "LCD.h"
#include "LCD_Config.h"
#include "GPIO_Interface.h"

/*==================================================================================================================*/
/*instructions from data sheet for  LCD initialization   */
#define	FUNCTION_SET	        0x38		//(0b00100000|(DISPLAY_FONT_TYPE<<2)|(DISPLAY_LINES_NUM<<3)| (DATA_LENGTH<<4))
#define DISPLAY_ON_OFF_COTROL   (0b00001000|(ENTIRE_DISPLAY_MODE<<2)|(CURSOR_MODE<<1)|(CURSOR_BLNKING_MODE<<0))
#define DISPLAY_CLEAR 			0x01
#define ENTRY_MODE_SET          (0b00000100|(INCREMENT_DECREMENT_MODE<<1))
#define DISPLAY_SHIFT_LEFT      0x18
#define DISPLAY_SHIFT_RIGHT     0x1c
#define CURSOR_SHIFT_LEFT       0x10
#define CURSOR_SHIFT_RIGHT      0x14
#define SET_CGRAMADRESS			0x48
#define DDRAM_ADDRESS			0b10000000
#define DISPLAY_CLOSED			0b00001000
#define DISPLAY_OPENED			0b00001100
/*==================================================================================================================*/
/**
*@ Array of LCD pins which declared in LCD_Config.c
*/
extern  GPIO_strPinConfg_t LCDPINS[LCD_PINS_NUM] ;
/*==================================================================================================================*/

/*==================================================================================================================*/
/**
 *@  new data type that define the sequence of init state which used in LCD task
*/
typedef enum
{
	LCD_enuPowerOn = 0		,
	LCD_enuFunctionSet		,
	LCD_enuDisplayOnOff		,
	LCD_enuDisplayClear		,
	LCD_enuEntryMode		,
	LCD_enuDone

}LCD_enuInitStateMachine_t;
/**
 *@ new data type that define the sequence of User Request which used in LCD task
*/
typedef enum
{
	LCD_enuNoRequest = 0			,
	LCD_enuWriteNum					,
	LCD_enuWriteStr					,
	LCD_enuGoto_XY					,
	LCD_enuClearScreen				,
	LCD_enuDisplay_ON				,
	LCD_enuDisplay_OFF				,	
	LCD_enuShiftLeft				,
	LCD_enuShiftRight				,
	LCD_enuDisplaySpecialPatt 	    
}LCD_enuUserRequestType_t;
/**
 *@ data type that configure the user request state 
*/
typedef enum 
{
	LCD_enuRequestState_Ready		,
	LCD_enuRequestState_Buzzy
}LCD_enuRequestState_t ;

/**
 *@ state machine for write process  
*/
typedef enum
{
    LCD_WriteStart,
    LCD_WriteCharacter,
} LCD_WriteState_t;
typedef struct
{
    u8 CurLinePostion;
    u8 CurColPostion;

} LCD_Write_t;

typedef enum
{
    LCD_WriteNumberStart,
    LCD_WriteNumber,
} LCD_WriteNumberState_t;
/**
 *@ state machine for set position process  
*/
typedef enum
{
    LCD_SetPosStart,
    LCD_SetPos,
    LCD_SetPosEnd
} LCD_SetPosState_t;
/**
 *@ state machine to handle enable bit delay 
*/
typedef enum
{
	LCD_enuEnableReady			,
	LCD_enuEnableBuzzy			,
	LCD_enuEnableDone			,
	LCD_enuEnableReady_2stage	,
	LCD_enuEnableBuzzy_2stage	,
	LCD_enuEnableDone_2stage	
}LCD_enuEnableSignalSM_t ;
/**
 *@ new data type that configure the user requst state which would be used in the LCD task threads 
 *@ this variable would be updaded by the LCD APIs and then used in the task
 *@ this variabl is shared between tasks
*/
typedef struct 
{
     const	  u8 * LCD_addString ;
	volatile  u8   LCD_u8String_Length ;
	volatile  u8	  LCD_u8ShiftLeft;
	volatile  u8	  LCD_u8ShiftRight;
	volatile  u8   LCD_u8Position_X;
	volatile  u8   LCD_u8Position_Y;
	volatile  u8   LCD_u8Number;
	volatile  u8   LCD_u8CGRAMBlockNumber ;
	volatile  LCD_enuRequestState_t LCD_enuRequestState ;
	volatile  LCD_enuUserRequestType_t  LCD_enuRequestType  ;

}LCD_strUserRequestCFG_t ;
/**
 *@ new data type that configure the LCD Current State 
*/
typedef enum 
{
	LCD_enuInitMode	 		,
	LCD_enuOperationMode    
}LCD_enuCurrentMode_t ;

/*==================================================================================================================*/

/*==================================================================================================================*/
/**
 *@ new data type that configure the LCD Current State 
*/
static LCD_enuCurrentMode_t 		LCD_enuCurrentMode    =  LCD_enuInitMode  ;
/**
 *@ new static variable that wold be used in LCD task that configure the current init state
*/
static LCD_enuInitStateMachine_t 	LCD_enuInitState	  = LCD_enuPowerOn ;
/**
 *@ new static variable that wold be used in LCD tasks that configure the current init state
*/
static LCD_strUserRequestCFG_t  	LCD_enuUserRequestCFG;// = {NULL,0,0,0,0,0,0,0,LCD_enuRequestState_Ready,LCD_enuNoRequest};
    
/**
 *@ state machine to handle character write process 
*/
static LCD_WriteState_t 			LCD_WriteState = LCD_WriteStart ;
static LCD_WriteNumberState_t 		WriteNumState = LCD_WriteNumberStart ;
static LCD_Write_t 					CurrentWritePostion;

static u32 							LCD_EnablePinState = LCD_ENABLE_OFF;
/*===================================================================================================================*/

/*===================================================================================================================*/
/**
*@ private functions prototype
*/
static LCD_enuErrorStatus_t LCD_voidWriteCharacter_CG_DDRAM(u8 Copy_u8Data);
static LCD_enuErrorStatus_t LCD_enuWriteCommand(u8 Copy_u8Command);
static LCD_enuErrorStatus_t LCD_enuInit(void);
static LCD_enuErrorStatus_t LCD_enuWriteCharacter(u8 Copy_u8Data);
static void LCD_ShiftLeft(void);
static void LCD_RightShift(void);
static void LCD_GotoDDRAM_XYPosition(void);
static void LCD_WriteNumb(void);
static void LCD_DisplaySpecialPattern(void);
static void LCD_WriteString(void);
static void LCD_PowerOn(void);
static void LCD_Helper_SetPosition(u8 *PTR_PostionDDRAM);
/*===================================================================================================================*/

/**
*@ turn the cursor and the display mode off
*/
LCD_enuErrorStatus_t LCD_VidDisplay_OFF(void)
{
	/**
		*@ Error status return variable
		*/
		LCD_enuErrorStatus_t LCD_RETURN_ERRORSTATUS = LCD_enuOK;
		/**
		 *@ set request type variable to display off state 
		*/
		LCD_enuUserRequestCFG.LCD_enuRequestType = LCD_enuDisplay_OFF ;
		/**
		 *@ set request state variable to display off state 
		*/
		LCD_enuUserRequestCFG.LCD_enuRequestState = LCD_enuRequestState_Buzzy;
		
	/**
	*@ cursor off , screen display off ,Blink off 
	*/
		//LCD_RETURN_ERRORSTATUS = LCD_enuWriteCommand(DISPLAY_CLOSED);
		

	return LCD_RETURN_ERRORSTATUS;		
}/* LCD_VidDisplay_OFF function*/

/**
*@ turn the cursor and the display mode on
*/
LCD_enuErrorStatus_t LCD_VidDisplay_ON(void)
{
	
	
	/**
		*@ Error status return variable
		*/
		LCD_enuErrorStatus_t LCD_RETURN_ERRORSTATUS = LCD_enuOK;
		/**
		 *@ set request state variable to display on state 
		*/
		LCD_enuUserRequestCFG.LCD_enuRequestType = LCD_enuDisplay_ON ;
		/**
		 *@ set request state variable to display off state 
		*/
		LCD_enuUserRequestCFG.LCD_enuRequestState = LCD_enuRequestState_Buzzy;
	
	/*
	*@ cursor off , screen display on ,Blink off 
	*/
		//LCD_RETURN_ERRORSTATUS = LCD_enuWriteCommand(DISPLAY_OPENED);

	return LCD_RETURN_ERRORSTATUS;		
}/* LCD_VidDisplay_ON function*/

/**
*@ CLEAR THE DISPLAY
*/
LCD_enuErrorStatus_t LCD_VidClearScreen(void)
{
		/**
		*@ Error status return variable
		*/
		LCD_enuErrorStatus_t LCD_RETURN_ERRORSTATUS = LCD_enuOK;
		/**
		 *@ set request state variable to display off state 
		*/
		LCD_enuUserRequestCFG.LCD_enuRequestType = LCD_enuClearScreen ;
		/**
		 *@ set request state variable to display off state 
		*/
		LCD_enuUserRequestCFG.LCD_enuRequestState = LCD_enuRequestState_Buzzy;
		
		//LCD_RETURN_ERRORSTATUS = LCD_enuWriteCommand(DISPLAY_CLEAR);
		
	
	
	return LCD_RETURN_ERRORSTATUS;	
}/*LCD_VidClearScreen function*/

/**
*@ shift the whole display to left
*/
LCD_enuErrorStatus_t LCD_VidShiftLeft(u8 Copy_u8ShiftNum)
{
	/**
		*@ Error status return variable
		*/
		LCD_enuErrorStatus_t LCD_RETURN_ERRORSTATUS = LCD_enuOK;
		/**
		 *@ set request state variable to display off state 
		*/
		LCD_enuUserRequestCFG.LCD_enuRequestType = LCD_enuShiftLeft ;
		/**
		 *@ set request state variable to display off state 
		*/
		LCD_enuUserRequestCFG.LCD_enuRequestState = LCD_enuRequestState_Buzzy;
		/**
		 *@ set the global variable that used by the thread in the lcd task 
		*/
		LCD_enuUserRequestCFG.LCD_u8ShiftLeft = Copy_u8ShiftNum ;
		
	
	
	return LCD_RETURN_ERRORSTATUS;
}/* LCD_VidShiftLeft function */

/**
*@ shift the whole screen to right
*/
LCD_enuErrorStatus_t LCD_VidShiftRight(u8 Copy_u8ShiftNum)
{
	/**
		*@ Error status return variable
		*/
		LCD_enuErrorStatus_t LCD_RETURN_ERRORSTATUS = LCD_enuOK;
	
	if ((LCD_enuCurrentMode == LCD_enuOperationMode) && (LCD_enuUserRequestCFG.LCD_enuRequestState == LCD_enuRequestState_Ready))
	{	
		
		/**
		 *@ set request state variable to display off state 
		*/
		LCD_enuUserRequestCFG.LCD_enuRequestType = LCD_enuShiftRight ;
		/**
		 *@ set request state variable to display off state 
		*/
		LCD_enuUserRequestCFG.LCD_enuRequestState = LCD_enuRequestState_Buzzy;
		/**
		 *@ set the global variable that used by the thread in the lcd task 
		*/
		LCD_enuUserRequestCFG.LCD_u8ShiftRight = Copy_u8ShiftNum ;
	}	
	
		return LCD_RETURN_ERRORSTATUS;
}/* LCD_VidShiftRight function*/

/**
*@  Write Data to CG or DD RAM
*/
LCD_enuErrorStatus_t LCD_voidWriteCharacter_CG_DDRAM(u8 Copy_u8Data)
{
		/**
		*@ Error status return variable
		*/
		LCD_enuErrorStatus_t LCD_RETURN_ERRORSTATUS = LCD_enuOK;	
		/**
		*@ iterator used in for loop to configure every single pin using DIO driver
		*/
		u8 LOCAL_u8Iterator = 0 ;
		u32 Loc_u32PinState;
		/**
		*@ check the operational mode 4 pins or 8 pins
		*/
		#if	(DATA_LENGTH == EIGHT_BITS_MODE)
			if (LCD_EnablePinState == LCD_ENABLE_OFF)
			{
				/*send the value*/
				GPIO_enuSetPinValue(LCDPINS[REG_SEL].GPIOPort,(u8)LCDPINS[REG_SEL].GPIOPin,GPIO_HIGH);
				/*send the value*/
				GPIO_enuSetPinValue(LCDPINS[READ_WRITE].GPIOPort,LCDPINS[READ_WRITE].GPIOPin,GPIO_LOW);
				/**
				*@ sending the lcd  configration
				*/
				for( LOCAL_u8Iterator = 0 ; LOCAL_u8Iterator < (LCD_PINS_NUM - 3) ; LOCAL_u8Iterator++)
				{
						/**
						*@ call DIO_enumSetCFG function to set configration in DIO Driver
						*@ and check return of DIO_enumSetCFG function ok or not ok
						*/		
					Loc_u32PinState = (Copy_u8Data & (1 << LOCAL_u8Iterator)) ? one : zero ;	
					GPIO_enuSetPinValue(LCDPINS[LOCAL_u8Iterator].GPIOPort , (LCDPINS[LOCAL_u8Iterator].GPIOPin),Loc_u32PinState);

				}/*for loop*/	
				/*set rising edge signal*/
				 LCD_EnablePinState = LCD_ENABLE_ON;
        		 GPIO_enuSetPinValue(LCDPINS[ENABLE].GPIOPort , (LCDPINS[ENABLE].GPIOPin),GPIO_HIGH);
			}	
			else
			{
				LCD_EnablePinState = LCD_ENABLE_OFF;
        		GPIO_enuSetPinValue(LCDPINS[ENABLE].GPIOPort , (LCDPINS[ENABLE].GPIOPin),GPIO_LOW);
			}
			
		
		#elif (DATA_LENGTH == FOUR_BITS_MODE)
			
			
			/**
			*@ sending the high nibble configration
			*/			
			for( LOCAL_u8Iterator = DATA_BIT4 ; LOCAL_u8Iterator <= DATA_BIT7 ; LOCAL_u8Iterator++)
			{
					/**
					*@ call DIO_enumSetCFG function to set configration in DIO Driver
					*@ and check return of DIO_enumSetCFG function ok or not ok
					*/		
				GPIO_enuSetPinValue(LCDPINS[LOCAL_u8Iterator].GPIOPort,LCDPINS[LOCAL_u8Iterator].GPIOPin,(GET_BIT(Copy_u8Data,LOCAL_u8Iterator)));
			
			}/*for loop*/		
		/*LCD check state every two milliseconds*/
			/*set enable signal*/
					/*LCD check state every two milliseconds*/
					switch(LCD_enuEnableSignalSM )
					{
					case LCD_enuEnableReady:
											LCD_enuEnableSignalSM = LCD_enuEnableBuzzy ;
											/**
											*@ Enable Rising edge
											*/
											GPIO_enuSetPinValue(LCDPINS[ENABLE].GPIOPort,LCDPINS[ENABLE].GPIOPin,GPIO_HIGH);
					break ;						
					case LCD_enuEnableBuzzy :
											LCD_enuEnableSignalSM = LCD_enuEnableReady_2stage ;
											/**
											*@ Enable falling edge
											*/
											GPIO_enuSetPinValue(LCDPINS[ENABLE].GPIOPort,LCDPINS[ENABLE].GPIOPin,GPIO_LOW);
					break;
					default:
					break;
					}/*switch*/
			/**
			*@ sending the low nibble
			*/			
			for( LOCAL_u8Iterator = DATA_BIT4 ; LOCAL_u8Iterator <= DATA_BIT7 ; LOCAL_u8Iterator++)
			{
					/**
					*@ call DIO_enumSetCFG function to set configration in DIO Driver
					*@ and check return of DIO_enumSetCFG function ok or not ok
					*/		
					GPIO_enuSetPinValue(LCDPINS[LOCAL_u8Iterator].GPIOPort,LCDPINS[LOCAL_u8Iterator].GPIOPin,(GET_BIT(Copy_u8Data,LOCAL_u8Iterator)));
			
			}/*for loop*/		
			/*LCD check state every two milliseconds*/
			/*set enable signal*/
	
				/*LCD check state every two milliseconds*/
				switch(LCD_enuEnableSignalSM )
				{
				case LCD_enuEnableReady_2stage:
										LCD_enuEnableSignalSM = LCD_enuEnableBuzzy_2stage ;
										/**
										*@ Enable Rising edge
										*/
										GPIO_enuSetPinValue(LCDPINS[ENABLE].GPIOPort,LCDPINS[ENABLE].GPIOPin,GPIO_HIGH);
				break ;						
				case LCD_enuEnableBuzzy_2stage :
										LCD_enuEnableSignalSM = LCD_enuEnableReady ;
										/**
										*@ Enable falling edge
										*/
										GPIO_enuSetPinValue(LCDPINS[ENABLE].GPIOPort,LCDPINS[ENABLE].GPIOPin,GPIO_LOW);
				break;
				default:
				break;
				}/*switch*/
			
		#else
			
		#endif			   			
			 

	return LCD_RETURN_ERRORSTATUS;		
}/*LCD_voidSetCGRAMAddress function*/

/**
*@ function to send commands to LCD controller
*/
LCD_enuErrorStatus_t LCD_enuWriteCommand(u8 Copy_u8Command)
{
	    LCD_enuErrorStatus_t LCD_RETURN_ERRORSTATUS = LCD_enuOK ;
		/**
		*@ iterator used in for loop to configure every single pin using DIO driver
		*/
		u8 LOCAL_u8Iterator = 0 ;
		/**
		*@ intialization sequence according to datasheet
		*@ set RW=0  & Set RS=0 & Activate Enable Bit
		*/
	
		u32 Loc_u32PinState;
		/**
		*@ check the operational mode 4 pins or 8 pins
		*/
		#if	(DATA_LENGTH == EIGHT_BITS_MODE)
			if (LCD_EnablePinState == LCD_ENABLE_OFF)
			{
				/*send the value*/
				GPIO_enuSetPinValue(LCDPINS[READ_WRITE].GPIOPort,LCDPINS[READ_WRITE].GPIOPin,GPIO_LOW);
				/*send the value*/
				GPIO_enuSetPinValue(LCDPINS[REG_SEL].GPIOPort,LCDPINS[REG_SEL].GPIOPin,GPIO_LOW);
				for( LOCAL_u8Iterator = 0 ; LOCAL_u8Iterator < (LCD_PINS_NUM - 3) ; LOCAL_u8Iterator++)
				{
						/**
						*@ call GPIO_enuSetPinValue function to set configration in DIO Driver
						*@ and check return of DIO_enumSetCFG function ok or not ok
						*/		
						 /*send the value*/
					Loc_u32PinState = (Copy_u8Command & (1 << LOCAL_u8Iterator)) ? one : zero ;	 
					GPIO_enuSetPinValue(LCDPINS[LOCAL_u8Iterator].GPIOPort,LCDPINS[LOCAL_u8Iterator].GPIOPin,Loc_u32PinState);
				}/*for loop*/		
				/**
				*@ Enable Rising edge
				*/
				GPIO_enuSetPinValue(LCDPINS[ENABLE].GPIOPort,LCDPINS[ENABLE].GPIOPin,GPIO_HIGH);
				LCD_EnablePinState = LCD_ENABLE_ON;
			}
			else
			{
				 LCD_EnablePinState = LCD_ENABLE_OFF;
				 /*enable falling edge*/
        		 GPIO_enuSetPinValue(LCDPINS[ENABLE].GPIOPort,LCDPINS[ENABLE].GPIOPin,GPIO_LOW);
			}			
		#elif (DATA_LENGTH == FOUR_BITS_MODE)
			
			for( LOCAL_u8Iterator = DATA_BIT4 ; LOCAL_u8Iterator <= DATA_BIT7 ; LOCAL_u8Iterator++)
			{
					/**
					*@ call DIO_enumSetCFG function to set configration in DIO Driver
					*@ and check return of DIO_enumSetCFG function ok or not ok
					*/		
				
					 /*send the value*/
				GPIO_enuSetPinValue(LCDPINS[LOCAL_u8Iterator].GPIOPort,LCDPINS[LOCAL_u8Iterator].GPIOPin,(GET_BIT(Copy_u8Command,LOCAL_u8Iterator)));
			
			}/*for loop*/	
				/*LCD check state every two milliseconds*/
			/*set enable signal*/
					/*LCD check state every two milliseconds*/
					switch(LCD_enuEnableSignalSM )
					{
					case LCD_enuEnableReady:
											LCD_enuEnableSignalSM = LCD_enuEnableBuzzy ;
											/**
											*@ Enable Rising edge
											*/
											GPIO_enuSetPinValue(LCDPINS[ENABLE].GPIOPort,LCDPINS[ENABLE].GPIOPin,GPIO_HIGH);
					break ;						
					case LCD_enuEnableBuzzy :
											LCD_enuEnableSignalSM = LCD_enuEnableReady_2stage ;
											/**
											*@ Enable falling edge
											*/
											GPIO_enuSetPinValue(LCDPINS[ENABLE].GPIOPort,LCDPINS[ENABLE].GPIOPin,GPIO_LOW);
					break;
					default:
					break;
					}/*switch*/
					
			/**
			*@ sending the low nibble
			*/			
			for( LOCAL_u8Iterator = DATA_BIT4 ; LOCAL_u8Iterator <= DATA_BIT7 ; LOCAL_u8Iterator++)
			{
					/**
					*@ call DIO_enumSetCFG function to set configration in DIO Driver
					*@ and check return of DIO_enumSetCFG function ok or not ok
					*/		
					GPIO_enuSetPinValue(LCDPINS[LOCAL_u8Iterator].GPIOPort,LCDPINS[LOCAL_u8Iterator].GPIOPin,(GET_BIT(Copy_u8Data,LOCAL_u8Iterator)));
			
			}/*for loop*/		
			/*LCD check state every two milliseconds*/
			/*set enable signal*/
			
				/*LCD check state every two milliseconds*/
				switch(LCD_enuEnableSignalSM )
				{
				case LCD_enuEnableReady_2stage:
										LCD_enuEnableSignalSM = LCD_enuEnableBuzzy_2stage ;
										/**
										*@ Enable Rising edge
										*/
										GPIO_enuSetPinValue(LCDPINS[ENABLE].GPIOPort,LCDPINS[ENABLE].GPIOPin,GPIO_HIGH);
				break ;						
				case LCD_enuEnableBuzzy_2stage :
										LCD_enuEnableSignalSM = LCD_enuEnableReady ;
										/**
										*@ Enable falling edge
										*/
										GPIO_enuSetPinValue(LCDPINS[ENABLE].GPIOPort,LCDPINS[ENABLE].GPIOPin,GPIO_LOW);
				break;
				default:
				break;
				}/*switch*/
				
		#else
				 LCD_RETURN_ERRORSTATUS = LCD_enuNOK;
		#endif			   			
		


	return LCD_RETURN_ERRORSTATUS;		
}/*LCD_enuWriteCommand function*/

/**
*@ LCD_enuErrorStatus_t LCD_init(void);
*/
LCD_enuErrorStatus_t LCD_enuInit(void)
{
	
	/**
	*@ Error status return variable
	*/
	LCD_enuErrorStatus_t LCD_RETURN_ERRORSTATUS = LCD_enuOK;
	
#if	(DATA_LENGTH == EIGHT_BITS_MODE)			
			/**
			*@ intialization sequence according to datasheet
			*@ switch between init states
			*/
			switch(LCD_enuInitState)
			{
				case LCD_enuPowerOn:
									LCD_PowerOn();
									LCD_enuInitState = LCD_enuFunctionSet;
				break;
				case LCD_enuFunctionSet:
										/**
										 *@ 8 bits data length, two lines mode , 5*8 mode
										 */
										LCD_enuWriteCommand(FUNCTION_SET);
										/**
										 *@ switch to next state 
										*/
										if (LCD_EnablePinState == LCD_ENABLE_OFF)
        								{
											LCD_enuInitState = LCD_enuDisplayOnOff;
										}	
				break;						
				case LCD_enuDisplayOnOff:
										/**
										 *@ switch to next state 
										*/
										LCD_enuWriteCommand(LCD_CURSOR_ON);
										if (LCD_EnablePinState == LCD_ENABLE_OFF)
        								{
											LCD_enuInitState = LCD_enuDisplayClear;
										}
				break;
				case LCD_enuDisplayClear:
											/**
											 *@ switch to next state 
											*/
											LCD_enuWriteCommand(LCD_CLEAR_COMMAND);
											if (LCD_EnablePinState == LCD_ENABLE_OFF)
        									{
													LCD_enuInitState = LCD_enuEntryMode;
											}
				break;
				case LCD_enuEntryMode:
										LCD_enuWriteCommand(LCD_INCREMENT_CRUSOR_SHIFT_RIGHT_MODE);
										 /**
										 *@ switch to next state 
										 */
										if (LCD_EnablePinState == LCD_ENABLE_OFF)
        								{
											LCD_enuInitState = LCD_enuDone;
										}
										 
										 
				break;
				case LCD_enuDone:
								LCD_enuUserRequestCFG.LCD_enuRequestState = LCD_enuRequestState_Ready;
								/* switch to operation mode on LCD_Task*/
								 LCD_enuCurrentMode = LCD_enuOperationMode;
								 LCD_enuUserRequestCFG.LCD_enuRequestType = LCD_enuNoRequest ;
								 /*only for testing the driver*/
								
								//  LCD_enuUserRequestCFG.LCD_addString = "Bishoy" ;
								//  LCD_enuUserRequestCFG.LCD_u8String_Length = 6 ;
								//  LCD_enuUserRequestCFG.LCD_enuRequestState = LCD_enuRequestState_Buzzy;
								//  LCD_enuUserRequestCFG.LCD_enuRequestType = LCD_enuWriteStr ;


								
				break;
				default:
				break;
			}/*switch case*/	
				
#elif (DATA_LENGTH == FOUR_BITS_MODE)			
				/**
			*@ intialization sequence according to datasheet
			*@ switch between init states
			*/
			switch(LCD_enuInitState)
			{
				case LCD_enuPowerOn:
									Loc_u8Counter += LCD_TASK_PERIODICITY ;
									/*wait 30 ms according to data sheet sequence and switch the state*/
									if(Loc_u8Counter >30)
									{
										/*reset the counter*/
										Loc_u8Counter = 0;	
										/*switch the init state*/
										LCD_enuInitState = LCD_enuFunctionSet;
									}
				break;
				case LCD_enuFunctionSet:
										/**
										 *@ switch to next state 
										*/
										LCD_enuInitState = LCD_enuDisplayOnOff;
										/**
										 *@ function set command
										 *@ 4 bits data length, two lines mode , 5*8 mode
										 */
										 LCD_RETURN_ERRORSTATUS = LCD_enuWriteCommand(0X02);
										 LCD_RETURN_ERRORSTATUS = LCD_enuWriteCommand(0X02);
										 LCD_RETURN_ERRORSTATUS = LCD_enuWriteCommand(0x28);
				break;
				case LCD_enuDisplayOnOff:
										/**
										 *@ switch to next state 
										*/
										LCD_enuInitState = LCD_enuDisplayClear;
										/**
										 *@ Display ON/OFF control command.
										 *@ Display ON cursor off blink off
										 */
										 LCD_RETURN_ERRORSTATUS = LCD_enuWriteCommand(0x00);
										 LCD_RETURN_ERRORSTATUS = LCD_enuWriteCommand(0x0C);
				break;
				case LCD_enuDisplayClear:
											/**
											 *@ switch to next state 
											*/
											LCD_enuInitState = LCD_enuDisplayClear;
											/**
											 *@ Display clear command.
											 */
											 LCD_RETURN_ERRORSTATUS = LCD_enuWriteCommand(0x00);
											 LCD_RETURN_ERRORSTATUS = LCD_enuWriteCommand(0x01);
				break;
				case LCD_enuEntryMode:
										 /**
										 *@ switch to next state 
										 */
										 LCD_enuInitState = LCD_enuDone;
										 /* switch to operation mode on LCD_Task*/
										 LCD_enuCurrentMode = LCD_enuOperationMode;
										 /**
										*@ Entry mode set command.
										*/
										LCD_RETURN_ERRORSTATUS = LCD_enuWriteCommand(0x00);
										LCD_RETURN_ERRORSTATUS = LCD_enuWriteCommand(0x06);
										break;
				default:
				break;
			
			}/*switch case*/
					
 #else	
		LCD_RETURN_ERRORSTATUS = LCD_enuNOK;
 #endif	
				
	
	
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

	LCD_RETURN_ERRORSTATUS = LCD_voidWriteCharacter_CG_DDRAM(Copy_u8Data);
	
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
	
    
    static u8 NumberBuffer[16];
    u8 counter = 0;
    u8 Loc_idx = 0 ;
    u32 Loc_TempNum = Copy_u8Number;
    if ((LCD_enuCurrentMode == LCD_enuOperationMode) && (LCD_enuUserRequestCFG.LCD_enuRequestState == LCD_enuRequestState_Ready))
    {
        /**
		 *@ set request state variable to display off state 
		*/
		LCD_enuUserRequestCFG.LCD_enuRequestType = LCD_enuWriteNum ;
		/**
		 *@ set request state variable to display off state 
		*/
		LCD_enuUserRequestCFG.LCD_enuRequestState = LCD_enuRequestState_Buzzy;
        if (Copy_u8Number == 0)
        {
            counter ++;
        }
        else
        {
            while (Loc_TempNum != 0)
            {
                Loc_TempNum = Loc_TempNum / 10;
                counter++;
            }
        }
        Loc_idx = counter-1 ;
        while (Loc_idx != INTEGER_OVER_FLOW)
        {
            NumberBuffer[Loc_idx] = (Copy_u8Number % 10) + '0';
            Copy_u8Number = Copy_u8Number / 10;
            Loc_idx -- ;
        }
        LCD_enuUserRequestCFG.LCD_u8String_Length = counter;
        LCD_enuUserRequestCFG.LCD_addString = NumberBuffer;
    }
    else
    {
        LCD_RETURN_ERRORSTATUS = LCD_enuNOK;
    }
     
	return LCD_RETURN_ERRORSTATUS;
}/*LCD_enuWriteNumber function*/

/**
*@ function that display array of characters on LCD
*/
LCD_enuErrorStatus_t LCD_enuWriteString(const u8 * Copy_pchPattern , u8 Copy_u8Length)
{
	
	/**
	*@ Error status return variable
	*/
	LCD_enuErrorStatus_t LCD_RETURN_ERRORSTATUS = LCD_enuOK;
	if(Copy_pchPattern == NULL)
	{
		LCD_RETURN_ERRORSTATUS = LCD_enuNOK;
	}
	else
	{
		if ((LCD_enuCurrentMode == LCD_enuOperationMode) && (LCD_enuUserRequestCFG.LCD_enuRequestState == LCD_enuRequestState_Ready))
		{
				/**
				 *@ set request state variable to display off state 
				*/
				LCD_enuUserRequestCFG.LCD_enuRequestType = LCD_enuWriteStr ;
				/**
				 *@ set request state variable to display off state 
				*/
				LCD_enuUserRequestCFG.LCD_enuRequestState = LCD_enuRequestState_Buzzy;
				/**
				 *@ set the global variable that used by the thread in the lcd task 
				*/
				LCD_enuUserRequestCFG.LCD_addString = Copy_pchPattern ;
				/**
				 *@ set string size 
				*/
				LCD_enuUserRequestCFG.LCD_u8String_Length = Copy_u8Length ;
		}
		else
		{
				LCD_RETURN_ERRORSTATUS = LCD_enuNOK;
		}
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
	*@ Error status return variable
	*/
	LCD_enuErrorStatus_t LCD_RETURN_ERRORSTATUS = LCD_enuOK;
	if ((LCD_enuCurrentMode == LCD_enuOperationMode) && (LCD_enuUserRequestCFG.LCD_enuRequestState == LCD_enuRequestState_Ready))
	{
		
		/**
		 *@ set request state variable to display off state 
		*/
		LCD_enuUserRequestCFG.LCD_enuRequestState = LCD_enuRequestState_Buzzy;
		/**
		 *@ set request state variable to display off state 
		*/
	    /*LCD_enuGoto_XY*/
		LCD_enuUserRequestCFG.LCD_enuRequestType = LCD_enuGoto_XY ;
		/**
		 *@ set the X and Y positions in global variable that used by the thread in the lcd task 
		*/
		LCD_enuUserRequestCFG.LCD_u8Position_X =  Copy_u8X ;
		LCD_enuUserRequestCFG.LCD_u8Position_Y =  Copy_u8Y ;
	}
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
		 *@ set request state variable to display off state 
		*/
		LCD_enuUserRequestCFG.LCD_enuRequestState = LCD_enuDisplaySpecialPatt ;
		/**
		 *@ set request state variable to display off state 
		*/
		LCD_enuUserRequestCFG.LCD_enuRequestState = LCD_enuRequestState_Buzzy;
		/**
		 *@ set the global variable that used by the thread in the lcd task 
		*/
		LCD_enuUserRequestCFG.LCD_addString = Copy_pu8Pattern ;
		LCD_enuUserRequestCFG.LCD_u8CGRAMBlockNumber = Copy_u8CGRAMBlockNumber ;
		LCD_enuUserRequestCFG.LCD_u8Position_X = Copy_u8X ;
		LCD_enuUserRequestCFG.LCD_u8Position_Y = Copy_u8Y ;
	
	
	return LCD_RETURN_ERRORSTATUS;
	
}/*LCD_enuDisplaySpecialPattern function*/

/**
 *@ LCD Task that would be invoked in the scheduler 
*/
void LCD_vidRunnable(void)
{
	switch(LCD_enuCurrentMode) 
	{
		case LCD_enuInitMode:
							LCD_enuInit();
		break ;
		case LCD_enuOperationMode :		
							if(LCD_enuUserRequestCFG.LCD_enuRequestState == LCD_enuRequestState_Buzzy )
							{
								switch(LCD_enuUserRequestCFG.LCD_enuRequestType)
								{
									case LCD_enuDisplay_ON:
															/* call LCD_VidDisplay_ON thread*/
															LCD_enuWriteCommand(DISPLAY_OPENED);
									break;
									case LCD_enuDisplay_OFF:
															/* call LCD_VidDisplay_OFF thread*/
															LCD_enuWriteCommand(DISPLAY_CLOSED);

									break;
									case LCD_enuClearScreen:
															/* call LCD_VidDisplay_OFF thread*/
															LCD_enuWriteCommand(DISPLAY_CLEAR);
									break;
									case LCD_enuShiftLeft:
															/* call LCD_ShiftLeft thread*/
															LCD_ShiftLeft();
									break;
									case LCD_enuShiftRight:
															/* call LCD_ShiftLeft thread*/
															LCD_RightShift();
									break;
									case LCD_enuWriteNum:
															 LCD_WriteNumb();
									break;
									case LCD_enuWriteStr:
														 /* call LCD_WriteString thread*/
														 LCD_WriteString();
									break;
									case LCD_enuGoto_XY:
														 /* call LCD_ShiftLeft thread*/
														 LCD_GotoDDRAM_XYPosition();
									break;
									case LCD_enuDisplaySpecialPatt:
														 /* call LCD_DisplaySpecialPattern thread*/
														 LCD_DisplaySpecialPattern();
									break;
									case LCD_enuNoRequest:
										// Do Nothing
									break;
									default:
									break;
								}
							}
		break ;
		default :
		break;			
	}
}


/*====================================private function that used by the scheduler only==================*/
void LCD_ShiftLeft(void)
{
	u8 Local_u8Iterator = 0 ;
	static u8 Loc_u8ShiftLeftCounter = 0 ;
	
	for(Local_u8Iterator =0 ; Local_u8Iterator < (LCD_enuUserRequestCFG.LCD_u8ShiftLeft) ;Local_u8Iterator++)
		{
			Loc_u8ShiftLeftCounter += LCD_TASK_PERIODICITY;
			if(Loc_u8ShiftLeftCounter == 500 )
			{
				LCD_enuWriteCommand(DISPLAY_SHIFT_LEFT);
			}	
			
		}


}

void LCD_RightShift(void)
{
	u8 Local_u8Iterator = 0 ;
	static u8 Loc_u8ShiftRightCounter = 0 ;
	
	for(Local_u8Iterator =0 ; Local_u8Iterator < (LCD_enuUserRequestCFG.LCD_u8ShiftRight) ;Local_u8Iterator++)
		{
			Loc_u8ShiftRightCounter += LCD_TASK_PERIODICITY;
			if(Loc_u8ShiftRightCounter == 500 )
			{
				LCD_enuWriteCommand(DISPLAY_SHIFT_RIGHT);
			}	
			
		}


}

void LCD_GotoDDRAM_XYPosition(void)
{
	/**
	*@ The Location variable to be set
	*/
	static LCD_SetPosState_t Loc_u8PostionState = LCD_SetPosStart;
    static u8 Loc_Location = 0;
	switch(Loc_u8PostionState)
	{
		case LCD_SetPosStart:
        				LCD_Helper_SetPosition(&Loc_Location);
        				Loc_u8PostionState = LCD_SetPos;
        break;
    	case LCD_SetPos:
       					 LCD_enuWriteCommand((0X80 + Loc_Location));
       					 if (LCD_EnablePinState == LCD_ENABLE_OFF)
       					  {
       					 		 LCD_enuUserRequestCFG.LCD_enuRequestType = LCD_enuNoRequest ;
								 /**
								  *@ set request state variable to display off state 
								 */
								 LCD_enuUserRequestCFG.LCD_enuRequestState = LCD_enuRequestState_Ready;
       					 		 Loc_u8PostionState = LCD_SetPosStart;
       					  }
        break;
        default:
        break;
	}

}

void LCD_WriteNumb(void)
{
	switch (WriteNumState)
    {
    case LCD_WriteNumberStart:
        WriteNumState = LCD_WriteNumber;
        CurrentWritePostion.CurColPostion = 0;
        break;
    case LCD_WriteNumber:
        if (CurrentWritePostion.CurColPostion != LCD_enuUserRequestCFG.LCD_u8String_Length)
        {
            LCD_voidWriteCharacter_CG_DDRAM(LCD_enuUserRequestCFG.LCD_addString[CurrentWritePostion.CurColPostion]);
            if (LCD_EnablePinState == LCD_ENABLE_OFF)
            {
                CurrentWritePostion.CurColPostion++;
            }
        }
        else
        {
			 LCD_enuUserRequestCFG.LCD_enuRequestType = LCD_enuNoRequest ;
		     LCD_enuUserRequestCFG.LCD_enuRequestState = LCD_enuRequestState_Ready;
            WriteNumState = LCD_WriteNumberStart;
        }
        break;
    default:
        break;
    }
	

}

void LCD_DisplaySpecialPattern(void)
{
	/**
	*@ iterator used in for to save pattern in CGRAM 
	*/
	 u8 Local_u8Iterator;
		
			
	      if(LCD_enuUserRequestCFG.LCD_u8CGRAMBlockNumber<8)
	      {
			  /**
			  *@ command to write in the CGRAM
			  */
	    	 LCD_enuWriteCommand(0x40+(LCD_enuUserRequestCFG.LCD_u8CGRAMBlockNumber  *8));
			  
			 LCD_enuGotoDDRAM_XY( LCD_enuUserRequestCFG.LCD_u8Position_X , LCD_enuUserRequestCFG.LCD_u8Position_Y );
			  
	          for(Local_u8Iterator = 0; Local_u8Iterator < 8;Local_u8Iterator++)
				
	        	{  LCD_enuWriteCharacter(LCD_enuUserRequestCFG.LCD_addString[ Local_u8Iterator ]); }
	      }

}

void LCD_WriteString(void)
{
	/**
	*@ iterator used to parse the string to individual character to be displayed on the LCD
	*/
	
	static u8 Local_u8WritePosition = 0 ;
	switch (LCD_WriteState)
    {
   			case LCD_WriteStart:
   			    				LCD_WriteState = LCD_WriteCharacter;
   			    				Local_u8WritePosition = 0;
   			break;
   			case LCD_WriteCharacter:
   								if (Local_u8WritePosition != LCD_enuUserRequestCFG.LCD_u8String_Length)
   								{
   								    LCD_voidWriteCharacter_CG_DDRAM(LCD_enuUserRequestCFG.LCD_addString[Local_u8WritePosition]);
   								    if (LCD_EnablePinState == LCD_ENABLE_OFF)
									{ 
										Local_u8WritePosition ++ ;
									}
   								}
   								else
   								{
   								     LCD_enuUserRequestCFG.LCD_enuRequestState = LCD_enuRequestState_Ready;
   								    LCD_enuUserRequestCFG.LCD_enuRequestType = LCD_enuNoRequest;
   								    LCD_WriteState = LCD_WriteStart;
   								}
   			break;
   			default:
   			break;
    }

}

void LCD_PowerOn(void)
{
	/**
	*@ Error status return variable
	*/
	LCD_enuErrorStatus_t LCD_RETURN_ERRORSTATUS = LCD_enuOK;

	
	/**
	 *@ iterator used in for loop 
	*/
	u8 LOCAL_u8Iterator;
	
			for( LOCAL_u8Iterator = 0 ; LOCAL_u8Iterator < LCD_PINS_NUM ; LOCAL_u8Iterator++)
			{
					/**
					*@ Enable falling edge
					*/
					LCDPINS[LOCAL_u8Iterator].GPIOMode =  GPIO_MODE_OUTPUT_PP  ;
					/*configure enable pin speed*/
					LCDPINS[LOCAL_u8Iterator].GPIOSpeed = GPIO_OUTPUT_SPEED_HIGH;
					/**
					*@ call DIO_enumSetCFG function to set configration in DIO Driver
					*@ and check return of DIO_enumSetCFG function ok or not ok
					*/		
						LCD_RETURN_ERRORSTATUS = GPIO_enuInit( & LCDPINS [LOCAL_u8Iterator] );
						
			}/*for loop*/

}

static void LCD_Helper_SetPosition(u8 *PTR_PostionDDRAM)
{
    
    u8 Loc_u8LCDLoctaionOnDDRAM = 0;
    switch (LCD_enuUserRequestCFG.LCD_u8Position_X)
    {
  		case 1:
  		    Loc_u8LCDLoctaionOnDDRAM = LCD_enuUserRequestCFG.LCD_u8Position_Y + 0X0;
  		break;
  		case 2:
  		    Loc_u8LCDLoctaionOnDDRAM = LCD_enuUserRequestCFG.LCD_u8Position_Y + 0X40;
  		break;
  		default:
  	    break;
    }
    *PTR_PostionDDRAM = Loc_u8LCDLoctaionOnDDRAM;

    
}

/*======================================================================================================*/







