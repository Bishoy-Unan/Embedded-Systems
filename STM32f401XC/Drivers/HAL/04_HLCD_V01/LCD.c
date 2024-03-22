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
#include"BIT_MATH.h"
#include "LCD_Private.h"
#include "LCD.h"
#include "LCD_Config.h"
#include "GPIO_Interface.h"





/*==================================================================================================================*/
/*instructions from data sheet for  LCD initialization   */
#define	FUNCTION_SET	        (0b00100000|(DISPLAY_FONT_TYPE<<2)|(DISPLAY_LINES_NUM<<3)| (DATA_LENGTH<<4))
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
	LCD_enuDisplay_ON				,
	LCD_enuDisplay_OFF				,
	LCD_enuClearScreen				,	
	LCD_enuShiftLeft				,
	LCD_enuShiftRight				,
	LCD_enuWriteNum					,
	LCD_enuWriteStr					,
	LCD_enuGoto_XY					,
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
 *@ new data type that configure the user requst state which would be used in the LCD task threads 
 *@ this variable would be updaded by the LCD APIs and then used in the task
 *@ this variabl is shared between tasks
*/
typedef struct 
{
	 u8 * LCD_addString ;
	 u8   LCD_u8String_Length ;
	 u8	  LCD_u8ShiftLeft;
	 u8	  LCD_u8ShiftRight;
	 u8   LCD_u8Position_X;
	 u8   LCD_u8Position_Y;
	 u8   LCD_u8Number;
	 u8   LCD_u8CGRAMBlockNumber ;
	 LCD_enuRequestState_t LCD_enuRequestState ;
	 LCD_enuUserRequestType_t  LCD_enuRequestType  ;

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
static LCD_enuCurrentMode_t LCD_enuCurrentMode =  LCD_enuInitMode  ;
/**
 *@ new static variable that wold be used in LCD task that configure the current init state
*/
static LCD_enuInitStateMachine_t LCD_enuInitState	= LCD_enuPowerOn ;
/**
 *@ new static variable that wold be used in LCD tasks that configure the current init state
*/
static LCD_strUserRequestCFG_t  LCD_enuUserRequestCFG ={NULL,0,0,0,LCD_enuRequestState_Ready,LCD_enuNoRequest};
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
		LCD_enuUserRequestCFG.LCD_enuRequestState = LCD_enuDisplay_ON ;
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
		LCD_enuUserRequestCFG.LCD_enuRequestState = LCD_enuClearScreen ;
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
		LCD_enuUserRequestCFG.LCD_enuRequestState = LCD_enuShiftLeft ;
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
		/**
		 *@ set request state variable to display off state 
		*/
		LCD_enuUserRequestCFG.LCD_enuRequestState = LCD_enuShiftRight ;
		/**
		 *@ set request state variable to display off state 
		*/
		LCD_enuUserRequestCFG.LCD_enuRequestState = LCD_enuRequestState_Buzzy;
		/**
		 *@ set the global variable that used by the thread in the lcd task 
		*/
		LCD_enuUserRequestCFG.LCD_u8ShiftRight = Copy_u8ShiftNum ;
		
	
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
		
		/**
		*@ select ir register and write command
		*/
		LCDPINS[REG_SEL].GPIOMode =  GPIO_MODE_OUTPUT_PP 	     ;
		/*configure enable pin speed*/
		LCDPINS[REG_SEL].GPIOSpeed = GPIO_OUTPUT_SPEED_LOW;
		GPIO_enuInit( & LCDPINS [REG_SEL] );
		/*send the value*/
		GPIO_enuSetPinValue(LCDPINS[REG_SEL].GPIOPort,(u8)LCDPINS[REG_SEL].GPIOPin,GPIO_HIGH);
		LCDPINS[READ_WRITE].GPIOMode =  GPIO_MODE_OUTPUT_PP 	     ;
		/*configure enable pin speed*/
		LCDPINS[READ_WRITE].GPIOSpeed = GPIO_OUTPUT_SPEED_LOW;
		GPIO_enuInit( & LCDPINS [REG_SEL] );
		/*send the value*/
		GPIO_enuSetPinValue(LCDPINS[READ_WRITE].GPIOPort,LCDPINS[READ_WRITE].GPIOPin,GPIO_LOW);
		
		/**
		*@ check the operational mode 4 pins or 8 pins
		*/
		#if	(DATA_LENGTH == EIGHT_BITS_MODE)
			
				
			/**
			*@ sending the lcd  configration
			*/
			for( LOCAL_u8Iterator = 0 ; LOCAL_u8Iterator < LCD_PINS_NUM ; LOCAL_u8Iterator++)
			{
					/**
					*@ call DIO_enumSetCFG function to set configration in DIO Driver
					*@ and check return of DIO_enumSetCFG function ok or not ok
					*/		
				GPIO_enuSetPinValue(LCDPINS[LOCAL_u8Iterator].GPIOPort,LCDPINS[LOCAL_u8Iterator].GPIOPin,(GET_BIT(Copy_u8Data,LOCAL_u8Iterator)));
			
			}/*for loop*/	
		
			/**
			*@ Enable Rising edge
			*/
			GPIO_enuSetPinValue(LCDPINS[ENABLE].GPIOPort,LCDPINS[ENABLE].GPIOPin,GPIO_HIGH);
			/**
			*@ send enable signal to LCD
			*/
			
			
			/**
			*@ Enable falling edge
			*/
			
			/**
			*@ send enable signal to LCD
			*/
			GPIO_enuSetPinValue(LCDPINS[ENABLE].GPIOPort,LCDPINS[ENABLE].GPIOPin,GPIO_LOW);
			
	
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
		
			/**
			*@ Enable Rising edge
			*/
			GPIO_enuSetPinValue(LCDPINS[ENABLE].GPIOPort,LCDPINS[ENABLE].GPIOPin,GPIO_HIGH);
			/**
			*@ send enable signal to LCD
			*/
			
			
			/**
			*@ Enable falling edge
			*/
			
			/**
			*@ send enable signal to LCD
			*/
			GPIO_enuSetPinValue(LCDPINS[ENABLE].GPIOPort,LCDPINS[ENABLE].GPIOPin,GPIO_LOW);
							
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
			/**
			*@ Enable Rising edge
			*/
			GPIO_enuSetPinValue(LCDPINS[ENABLE].GPIOPort,LCDPINS[ENABLE].GPIOPin,GPIO_HIGH);
			/**
			*@ send enable signal to LCD
			*/
			
			
			/**
			*@ Enable falling edge
			*/
			
			/**
			*@ send enable signal to LCD
			*/
			GPIO_enuSetPinValue(LCDPINS[ENABLE].GPIOPort,LCDPINS[ENABLE].GPIOPin,GPIO_LOW);
			
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
		LCDPINS[READ_WRITE].GPIOMode =  GPIO_MODE_OUTPUT_PP   ;
		LCDPINS[READ_WRITE].GPIOSpeed =  GPIO_OUTPUT_SPEED_LOW   ;
		/*send the value*/
		GPIO_enuSetPinValue(LCDPINS[READ_WRITE].GPIOPort,LCDPINS[READ_WRITE].GPIOPin,GPIO_LOW);
		LCDPINS[REG_SEL].GPIOMode =  GPIO_MODE_OUTPUT_PP   ;
		LCDPINS[REG_SEL].GPIOSpeed =  GPIO_OUTPUT_SPEED_LOW   ;
		/*send the value*/
		GPIO_enuSetPinValue(LCDPINS[REG_SEL].GPIOPort,LCDPINS[REG_SEL].GPIOPin,GPIO_LOW);
		 		
	
		/**
		*@ check the operational mode 4 pins or 8 pins
		*/
		#if	(DATA_LENGTH == EIGHT_BITS_MODE)

		
			for( LOCAL_u8Iterator = 0 ; LOCAL_u8Iterator < (LCD_PINS_NUM - 3) ; LOCAL_u8Iterator++)
			{
					/**
					*@ call GPIO_enuSetPinValue function to set configration in DIO Driver
					*@ and check return of DIO_enumSetCFG function ok or not ok
					*/		
					 /*send the value*/
				GPIO_enuSetPinValue(LCDPINS[LOCAL_u8Iterator].GPIOPort,LCDPINS[LOCAL_u8Iterator].GPIOPin,(GET_BIT(Copy_u8Command,LOCAL_u8Iterator)));
			
			}/*for loop*/		
				
			/**
			*@ Enable Rising edge
			*/
			/*send the value*/
			GPIO_enuSetPinValue(LCDPINS[ENABLE].GPIOPort , LCDPINS[ENABLE].GPIOPin , GPIO_HIGH);
			
			/**
			*@ Enable falling edge
			*/
			/*send the value*/
			GPIO_enuSetPinValue(LCDPINS[ENABLE].GPIOPort,LCDPINS[ENABLE].GPIOPin,GPIO_LOW);
			
			
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
			
			/**
			*@ Enable Rising edge
			*/
			/*send the value*/
			GPIO_enuSetPinValue(LCDPINS[ENABLE].GPIOPort,LCDPINS[ENABLE].GPIOPin,GPIO_HIGH);
			
			/**
			*@ Enable falling edge
			*/
			/*send the value*/
			GPIO_enuSetPinValue(LCDPINS[ENABLE].GPIOPort,LCDPINS[ENABLE].GPIOPin,GPIO_LOW);

			/**
			*@ sending the low nibble
			*/			
			for( LOCAL_u8Iterator = DATA_BIT4 ; LOCAL_u8Iterator <= DATA_BIT7 ; LOCAL_u8Iterator++)
			{
					/**
					*@ call DIO_enumSetCFG function to set configration in DIO Driver
					*@ and check return of DIO_enumSetCFG function ok or not ok
					*/		
				
					 /*send the value*/
				GPIO_enuSetPinValue(LCDPINS[LOCAL_u8Iterator].GPIOPort,LCDPINS[LOCAL_u8Iterator].GPIOPin,(GET_BIT(Copy_u8Command,LOCAL_u8Iterator)));
			
			}/*for loop*/

			/**
			*@ Enable Rising edge
			*/
			/*send the value*/
			GPIO_enuSetPinValue(LCDPINS[ENABLE].GPIOPort,LCDPINS[ENABLE].GPIOPin,GPIO_HIGH);
			
			/**
			*@ Enable falling edge
			*/
			/*send the value*/
			GPIO_enuSetPinValue(LCDPINS[ENABLE].GPIOPort,LCDPINS[ENABLE].GPIOPin,GPIO_LOW);	
			
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
	/**
	 *@ static Local counter used to switch between states 
	*/
	static u8 Loc_u8Counter = 0;
	/**
	 *@ iterator used in for loop 
	*/
	u8 LOCAL_u8Iterator;
	
			/**
			*@ Enable falling edge
			*/
			LCDPINS[ENABLE].GPIOMode =  GPIO_MODE_OUTPUT_PP  ;
			/*configure enable pin speed*/
			LCDPINS[ENABLE].GPIOSpeed = GPIO_OUTPUT_SPEED_LOW;
			LCD_RETURN_ERRORSTATUS = GPIO_enuInit( & LCDPINS [ENABLE] );
			/*send the value*/
			GPIO_enuSetPinValue(LCDPINS[ENABLE].GPIOPort,LCDPINS[ENABLE].GPIOPin,GPIO_LOW);
			/**
			*@ send the pins which configred in LCD_Config.c to LCD
			*/
			for( LOCAL_u8Iterator = 0 ; LOCAL_u8Iterator < LCD_PINS_NUM ; LOCAL_u8Iterator++)
			{
					/**
					*@ Enable falling edge
					*/
					LCDPINS[LOCAL_u8Iterator].GPIOMode =  GPIO_MODE_OUTPUT_PP  ;
					/*configure enable pin speed*/
					LCDPINS[LOCAL_u8Iterator].GPIOSpeed = GPIO_OUTPUT_SPEED_LOW;
					/**
					*@ call DIO_enumSetCFG function to set configration in DIO Driver
					*@ and check return of DIO_enumSetCFG function ok or not ok
					*/		
						LCD_RETURN_ERRORSTATUS = GPIO_enuInit( & LCDPINS [LOCAL_u8Iterator] );
						/*send the value*/
						GPIO_enuSetPinValue(LCDPINS[LOCAL_u8Iterator].GPIOPort,LCDPINS[LOCAL_u8Iterator].GPIOPin,GPIO_LOW);
			
			}/*for loop*/
			
			
#if	(DATA_LENGTH == EIGHT_BITS_MODE)			
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
										 *@ 8 bits data length, two lines mode , 5*8 mode
										 */
										LCD_enuWriteCommand(FUNCTION_SET);
				break;
				case LCD_enuDisplayOnOff:
										/**
										 *@ switch to next state 
										*/
										LCD_enuInitState = LCD_enuDisplayClear;
										LCD_enuWriteCommand(DISPLAY_ON_OFF_COTROL);
				break;
				case LCD_enuDisplayClear:
											/**
											 *@ switch to next state 
											*/
											LCD_enuInitState = LCD_enuDisplayClear;
											LCD_enuWriteCommand(DISPLAY_CLEAR);
				break;
				case LCD_enuEntryMode:
										 /**
										 *@ switch to next state 
										 */
										 LCD_enuInitState = LCD_enuDone;
										 /* switch to operation mode on LCD_Task*/
										 LCD_enuCurrentMode = LCD_enuOperationMode;
										 LCD_enuWriteCommand(ENTRY_MODE_SET);
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
	/**
		 *@ set request state variable to display off state 
		*/
		LCD_enuUserRequestCFG.LCD_enuRequestState = LCD_enuWriteNum ;
		/**
		 *@ set request state variable to display off state 
		*/
		LCD_enuUserRequestCFG.LCD_enuRequestState = LCD_enuRequestState_Buzzy;
		/**
		 *@ set the global variable that used by the thread in the lcd task 
		*/
		LCD_enuUserRequestCFG.LCD_u8Number = Copy_u8Number ;

	
	
	
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
		 *@ set request state variable to display off state 
		*/
		LCD_enuUserRequestCFG.LCD_enuRequestState = LCD_enuWriteStr ;
		/**
		 *@ set request state variable to display off state 
		*/
		LCD_enuUserRequestCFG.LCD_enuRequestState = LCD_enuRequestState_Buzzy;
		/**
		 *@ set the global variable that used by the thread in the lcd task 
		*/
		LCD_enuUserRequestCFG.LCD_addString = Copy_pchPattern ;
	
	
	
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
		/**
		 *@ set request state variable to display off state 
		*/
		LCD_enuUserRequestCFG.LCD_enuRequestState = LCD_enuGoto_XY ;
		/**
		 *@ set request state variable to display off state 
		*/
		LCD_enuUserRequestCFG.LCD_enuRequestState = LCD_enuRequestState_Buzzy;
		/**
		 *@ set the X and Y positions in global variable that used by the thread in the lcd task 
		*/
		LCD_enuUserRequestCFG.LCD_u8Position_X =  Copy_u8X ;
		LCD_enuUserRequestCFG.LCD_u8Position_Y =  Copy_u8Y ;
	
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
void LCD_vidTask(void)
{
	if(LCD_enuCurrentMode == LCD_enuInitMode)
	{
			if (LCD_enuInitState != LCD_enuDone)
			{
				LCD_enuInit();
			}
	}
	else if(LCD_enuCurrentMode == LCD_enuOperationMode)		
	{		
		if(LCD_enuUserRequestCFG.LCD_enuRequestState == LCD_enuRequestState_Buzzy )
		{
			switch(LCD_enuUserRequestCFG.LCD_enuRequestType)
			{
				case LCD_enuDisplay_ON:
										/* reset request state to ready for next request*/
										LCD_enuUserRequestCFG.LCD_enuRequestState = LCD_enuRequestState_Ready ;
										/* call LCD_VidDisplay_ON thread*/
										LCD_enuWriteCommand(DISPLAY_OPENED);
				break;
				case LCD_enuDisplay_OFF:
										/* reset request state to ready for next request*/
										LCD_enuUserRequestCFG.LCD_enuRequestState = LCD_enuRequestState_Ready ;
										/* call LCD_VidDisplay_OFF thread*/
										LCD_enuWriteCommand(DISPLAY_CLOSED);
										
				break;
				case LCD_enuClearScreen:
										/* reset request state to ready for next request*/
										LCD_enuUserRequestCFG.LCD_enuRequestState = LCD_enuRequestState_Ready ;
										/* call LCD_VidDisplay_OFF thread*/
										LCD_enuWriteCommand(DISPLAY_CLEAR);
				break;
				case LCD_enuShiftLeft:
										/* reset request state to ready for next request*/
										LCD_enuUserRequestCFG.LCD_enuRequestState = LCD_enuRequestState_Ready ;
										/* call LCD_ShiftLeft thread*/
										LCD_ShiftLeft();
				break;
				case LCD_enuShiftRight:
										/* reset request state to ready for next request*/
										LCD_enuUserRequestCFG.LCD_enuRequestState = LCD_enuRequestState_Ready ;
										/* call LCD_ShiftLeft thread*/
										LCD_RightShift();
				break;
				case LCD_enuWriteNum:
										/* reset request state to ready for next request*/
										LCD_enuUserRequestCFG.LCD_enuRequestState = LCD_enuRequestState_Ready ;
										 LCD_WriteNumb();
				break;
				case LCD_enuWriteStr:
									/* reset request state to ready for next request*/
									 LCD_enuUserRequestCFG.LCD_enuRequestState = LCD_enuRequestState_Ready ;
									 /* call LCD_WriteString thread*/
									 LCD_WriteString();
				break;
				case LCD_enuGoto_XY:
									 /* reset request state to ready for next request*/
									 LCD_enuUserRequestCFG.LCD_enuRequestState = LCD_enuRequestState_Ready ;
									 /* call LCD_ShiftLeft thread*/
									 LCD_GotoDDRAM_XYPosition();
				break;
				case LCD_enuDisplaySpecialPatt:
									/* reset request state to ready for next request*/
									 LCD_enuUserRequestCFG.LCD_enuRequestState = LCD_enuRequestState_Ready ;
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
	u8 Local_u8Location = 0 ;
	/**
	*@ check the line number
	*/
	switch(LCD_enuUserRequestCFG.LCD_u8Position_X)
  {
	case FIRST_LINE :
				Local_u8Location = LCD_enuUserRequestCFG.LCD_u8Position_Y;
	break ;
	case SECOND_LINE :
				Local_u8Location = LCD_enuUserRequestCFG.LCD_u8Position_Y + 0x40;
	break ;
	
	default :
			
	break;		
  }
	
	 LCD_enuWriteCommand( Local_u8Location | 0x80);	

}

void LCD_WriteNumb(void)
{
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
    if ((Local_32Sign = (LCD_enuUserRequestCFG.LCD_u8Number)) < 0)
    	{
    	  LCD_enuUserRequestCFG.LCD_u8Number = -1 * LCD_enuUserRequestCFG.LCD_u8Number ;
    	}
    Local_s32Iterator = 0;
    do 
	{
		/**
		*@ parsing the input number from the most right side 
		*@ and saving it in the array from the left side to the right
		*@ adding '0' to convert it to the corresponding assci code
		*/
        Local_u8ParsingArray[Local_s32Iterator++] = (LCD_enuUserRequestCFG.LCD_u8Number) % 10 + '0';
		
		LCD_enuUserRequestCFG.LCD_u8Number /= 10 ;
		
    } while (LCD_enuUserRequestCFG.LCD_u8Number > 0);
	
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
	u8 LOCAL_u8Iterator = 0;
		
		while(LCD_enuUserRequestCFG.LCD_addString[LOCAL_u8Iterator]!='\0')
			{
				LCD_enuWriteCharacter(LCD_enuUserRequestCFG.LCD_addString[LOCAL_u8Iterator]);
				LOCAL_u8Iterator++;
			}

}


/*======================================================================================================*/







