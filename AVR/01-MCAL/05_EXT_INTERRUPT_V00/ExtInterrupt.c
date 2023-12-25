/*############################################################################*/
/* Author:	Bishoy Unan	 	   							*/
/* Date:	24/12/2023						       						*/
/* Version:	v0.0.0									 					*/
/* description: ATMwga32 External Interrupt Driver for Int0 and Int1 and Int2 */
/* Specs: 									      							*/
/* 01: void ExtInterrupt_voidInit(void);	*/
/* 02: void ExtINT_voidSetExtINT0(void(*ptr)(void));*/
/* 03: void ExtINT_voidSetExtINT1(void(*ptr)(void));  */
/* 04: void ExtINT_voidSetExtINT2(void(*ptr)(void)); */
/*########################################################*/


#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "ExtInterrupt_Private.h"
#include "ExtInterrupt.h"
#include "ExtInterrupt_CFG.h"


/**
*@ three variables pointer to function used in ISR 
*@ this variables is been set by call back functions for ExtInt0 , ExtInt1 , ExtInt2
*@ this three functions take function name as input in application layer
*/
/**
*@ pointer to function for External Interrupt0
*/
 void (*ExtInt0_AddCallBack)(void);
/**
*@ pointer to function for External Interrupt1
*/
void (*ExtInt1_AddCallBack)(void);
/**
*@ pointer to function for External Interrupt2
*/
void (*ExtInt2_AddCallBack)(void);


/**
*@ function take pointer to function as input from application 
*@ and assign this variable ExtInt0_AddCallBack which used in ExtInt0 ISR 
*/
void ExtINT_voidSetExtINT0(void(*ptr)(void))
{
	ExtInt0_AddCallBack = ptr ;
	
}/*ExtINT_voidSetExtINT0*/


/**
*@ function take pointer to function as input from application 
*@ and assign this variable ExtInt0_AddCallBack which used in ExtInt1 ISR 
*/
void ExtINT_voidSetExtINT1(void(*ptr)(void))
{
	ExtInt1_AddCallBack = ptr ;
	
}/*ExtINT_voidSetExtINT1*/



/**
*@ function take pointer to function as input from application 
*@ and assign this variable ExtInt0_AddCallBack which used in ExtInt2 ISR 
*/
void ExtINT_voidSetExtINT2(void(*ptr)(void))
{
	ExtInt2_AddCallBack = ptr ;
	
}/*ExtINT_voidSetExtINT2*/



/**
*@ External Interrupt Init function in which we enable and disable ExtInt0 , ExtInt1, ExtInt2
*@ and configure the trigring type
*/
void ExtInterrupt_voidInit(void)
{
		/**
		*@ temporary variable used to set registers
		*/	
			u8 Local_u8TempRegVal;
			
			
		/*
		*@ enable or disable and choose triggring mode external interrupt0
		*/	
		#if   (EXT_INT0_ENABLING == ENABLE )
				/**
				*@ enable external interrupt0 by setting PIE bit in GICR Register
				*@ assign GICR register value to temp variable to set the whole register at one time
				*/
		
				Local_u8TempRegVal = GICR ;
				/**
				*@ masking the variable to affect only the desired bits
				*/
				Local_u8TempRegVal &= GICR_INT0_MASK ;
				/**
				*@ assign the desigred value only in the specific bits
				*/
				Local_u8TempRegVal |= GICR_INT0_ENABLE ;
				/**
				*@ assign the variable back to the register with the desigred value 
				*/
				GICR = Local_u8TempRegVal ;
			
		
		
		
		
				/**
				*@ MCUCR register used to set trigring mode
				*@ assign MCUCR register value to temp variable to set the whole register at one time
				*/
		
				Local_u8TempRegVal = MCUCR ;
				/**
				*@ masking the variable to affect only the desired bits
				*/
				Local_u8TempRegVal &= MCUCR_INT0_MASK ;
		
				/**
				*@ choose trigring mode of external interrupt0 
				*/		
				#if    ( EXT_INT0_Triggring_Type == The_low_level)
		
						/**
						*@ assign the desigred value only in the specific bits
						*/
						Local_u8TempRegVal |= MCUCR_INT0_LL ;
		
				
				#elif  ( EXT_INT0_Triggring_Type == Any_logical_change)
						/**
						*@ assign the desigred value only in the specific bits
						*/
						Local_u8TempRegVal |= MCUCR_INT0_ALC ;
		
				#elif  ( EXT_INT0_Triggring_Type == The_falling_edge)
						/**
						*@ assign the desigred value only in the specific bits
						*/
						Local_u8TempRegVal |= MCUCR_INT0_FE ;
			
				#elif  ( EXT_INT0_Triggring_Type == The_rising_edge)
						/**
						*@ assign the desigred value only in the specific bits
						*/
						Local_u8TempRegVal |= MCUCR_INT0_RE ;
		
				#else
						#error " invalid triggring mode "
				#endif
				/**
				*@ assign the variable back to the register with the desigred value 
				*/
				MCUCR = Local_u8TempRegVal ;
		
		#elif (EXT_INT0_ENABLING == DISABLE )
						/**
				*@ disable external interrupt0 by clear PIE bit in GICR Register
				*@ assign GICR register value to temp variable to set the whole register at one time
				*/
		
				Local_u8TempRegVal = GICR ;
				/**
				*@ masking the variable to affect only the desired bits
				*/
				Local_u8TempRegVal &= GICR_INT0_MASK ;
				/**
				*@ assign the desigred value only in the specific bits
				*/
				Local_u8TempRegVal |= GICR_INT0_DISABLE ;
				/**
				*@ assign the variable back to the register with the desigred value 
				*/
				GICR = Local_u8TempRegVal ;
		#else 
			#error " invalid choice "
		#endif	
			
					
		/*
		*@ enable or disable and choose triggring mode external interrupt1
		*/	
		#if   (EXT_INT1_ENABLING == ENABLE )
				/**
				*@ enable external interrupt1 by setting PIE bit in GICR Register
				*@ assign GICR register value to temp variable to set the whole register at one time
				*/
		
				Local_u8TempRegVal = GICR ;
				/**
				*@ masking the variable to affect only the desired bits
				*/
				Local_u8TempRegVal &= GICR_INT1_MASK ;
				/**
				*@ assign the desigred value only in the specific bits
				*/
				Local_u8TempRegVal |= GICR_INT1_ENABLE ;
				/**
				*@ assign the variable back to the register with the desigred value 
				*/
				GICR = Local_u8TempRegVal ;
			
		
		
		
		
				/**
				*@ MCUCR register used to set trigring mode
				*@ assign MCUCR register value to temp variable to set the whole register at one time
				*/
		
				Local_u8TempRegVal = MCUCR ;
				/**
				*@ masking the variable to affect only the desired bits
				*/
				Local_u8TempRegVal &= MCUCR_INT1_MASK ;
		
				/**
				*@ choose trigring mode of external interrupt0 
				*/		
				#if    ( EXT_INT1_Triggring_Type == The_low_level)
		
						/**
						*@ assign the desigred value only in the specific bits
						*/
						Local_u8TempRegVal |= MCUCR_INT1_LL ;
		
				
				#elif  ( EXT_INT1_Triggring_Type == Any_logical_change)
						/**
						*@ assign the desigred value only in the specific bits
						*/
						Local_u8TempRegVal |= MCUCR_INT1_ALC ;
		
				#elif  ( EXT_INT1_Triggring_Type == The_falling_edge)
						/**
						*@ assign the desigred value only in the specific bits
						*/
						Local_u8TempRegVal |= MCUCR_INT1_FE ;
			
				#elif  ( EXT_INT1_Triggring_Type == The_rising_edge)
						/**
						*@ assign the desigred value only in the specific bits
						*/
						Local_u8TempRegVal |= MCUCR_INT1_RE ;
		
				#else
						#error " invalid triggring mode "
				#endif
				/**
				*@ assign the variable back to the register with the desigred value 
				*/
				MCUCR = Local_u8TempRegVal ;
		
		#elif (EXT_INT1_ENABLING == DISABLE )
				/**
				*@ disable external interrupt1 by clear PIE bit in GICR Register
				*@ assign GICR register value to temp variable to set the whole register at one time
				*/
		
				Local_u8TempRegVal = GICR ;
				/**
				*@ masking the variable to affect only the desired bits
				*/
				Local_u8TempRegVal &= GICR_INT1_MASK ;
				/**
				*@ assign the desigred value only in the specific bits
				*/
				Local_u8TempRegVal |= GICR_INT1_DISABLE ;
				/**
				*@ assign the variable back to the register with the desigred value 
				*/
				GICR = Local_u8TempRegVal ;
		#else 
			#error " invalid choice "
		#endif	
				
				
		/*
		*@ enable or disable and choose triggring mode external interrupt2
		*/	
		#if   (EXT_INT2_ENABLING == ENABLE )
				/**
				*@ enable external interrupt2 by setting PIE bit in GICR Register
				*@ assign GICR register value to temp variable to set the whole register at one time
				*/
		
				Local_u8TempRegVal = GICR ;
				/**
				*@ masking the variable to affect only the desired bits
				*/
				Local_u8TempRegVal &= GICR_INT2_MASK ;
				/**
				*@ assign the desigred value only in the specific bits
				*/
				Local_u8TempRegVal |= GICR_INT2_ENABLE ;
				/**
				*@ assign the variable back to the register with the desigred value 
				*/
				GICR = Local_u8TempRegVal ;
			
		
		
		
		
				/**
				*@ MCUCR register used to set trigring mode
				*@ assign MCUCR register value to temp variable to set the whole register at one time
				*/
		
				Local_u8TempRegVal = MCUCSR ;
				/**
				*@ masking the variable to affect only the desired bits
				*/
				Local_u8TempRegVal &= MCUCSR_INT2_MASK ;
		
				/**
				*@ choose trigring mode of external interrupt0 
				*/		
				
				#if  ( EXT_INT0_Triggring_Type == The_falling_edge)
						/**
						*@ assign the desigred value only in the specific bits
						*/
						Local_u8TempRegVal |= MCUCSR_INT2_FE ;
			
				#elif  ( EXT_INT0_Triggring_Type == The_rising_edge)
						/**
						*@ assign the desigred value only in the specific bits
						*/
						Local_u8TempRegVal |= MCUCSR_INT2_RE ;
		
				#else
						#error " invalid triggring mode "
				#endif
				/**
				*@ assign the variable back to the register with the desigred value 
				*/
				MCUCSR = Local_u8TempRegVal ;
		
		#elif (EXT_INT0_ENABLING == DISABLE )
						/**
				*@ disable external interrupt0 by clear PIE bit in GICR Register
				*@ assign GICR register value to temp variable to set the whole register at one time
				*/
		
				Local_u8TempRegVal = GICR ;
				/**
				*@ masking the variable to affect only the desired bits
				*/
				Local_u8TempRegVal &= GICR_INT2_MASK ;
				/**
				*@ assign the desigred value only in the specific bits
				*/
				Local_u8TempRegVal |= GICR_INT2_DISABLE ;
				/**
				*@ assign the variable back to the register with the desigred value 
				*/
				GICR = Local_u8TempRegVal ;
		#else 
			//#warning "invalid choice"
		#endif	
		/**
		*@ Set GIE global Interrupt enable  
		*/		
		Local_u8TempRegVal = SREG ;
		/**
		*@ masking the variable to affect only the desired bits
		*/
		Local_u8TempRegVal &= SREG_MASK ;
		/**
		*@ assign the desigred value only in the specific bits
		*/
		Local_u8TempRegVal |= SREG_ENABLE_MASK ;
		/**
		*@ assign the variable back to the register with the desigred value 
		*/
		SREG = Local_u8TempRegVal ;
}/* ExtInterrupt_voidInit function */




/**
* ISR of External Interrupt0
*/

ISR(EXT_INT0)
{
/**
*@ pointer to function which is set in set call back function 
*/	
	ExtInt0_AddCallBack();
	/**
	*@ clear interrupt flag
	*/
	SET_BIT(GIFR,6);
	
}/*EXT_INT0 ISR*/


/**
* ISR of External Interrupt1
*/
ISR(EXT_INT1)
{
/**
*@ pointer to function which is set in set call back function 
*/	
	ExtInt1_AddCallBack();
	/**
	*@ clear interrupt flag
	*/
	SET_BIT(GIFR,7);

}/* EXT_INT1 ISR*/


/**
* ISR of External Interrupt2
*/
ISR(EXT_INT2)
{
/**
*@ pointer to function which is set in set call back function 
*/	
	ExtInt2_AddCallBack();
	
	/**
	*@ clear interrupt flag
	*/
	SET_BIT(GIFR,5);

}/* EXT_INT2 ISR */

