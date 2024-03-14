/*****************************************************************
 * Author:	Bishoy Unan	 	   											  
 * Date:	15/1/2024						            							      
 * Version:	v1.0.0										 			    
 * description:  ATMwga32 Timers							    						
 * Specs:     
 *      01- Timers_ErrorSTATUS_t Timer0_enumSetTimer_OV(u32 Copy_u32Interval );
 *      02- Timers_ErrorSTATUS_t Timer0_enumSetTimer_CTC(u32 Copy_u32Interval ); 
 *      03- Timers_ErrorSTATUS_t Timer0_enumSetTimer_PWM_F(u8 Copy_u32DutyCycle ); 
 *      04- Timers_ErrorSTATUS_t Timer0_enumSetTimer_PWM_PC(u8 Copy_u32DutyCycle ); 
 *      05- Timers_ErrorSTATUS_t Timer1_enumSetTimer_OV(u32 Copy_u32Interval );
 *      06- Timers_ErrorSTATUS_t Timer1_enumSetTimer__CTC_CHA(u32 Copy_u32Interval );
 *		07- Timers_ErrorSTATUS_t Timer1_enumSetTimer__CTC_CHB(u32 Copy_u32Interval );
 *		08- Timers_ErrorSTATUS_t Timer1_enumSetTimer_PWM_F(u8 Copy_u32DutyCycle );
 *		09- Timers_ErrorSTATUS_t Timer1_enumSetTimer_PWM_PC(u8 Copy_u32DutyCycle );
 *		10- Timers_ErrorSTATUS_t Timer1_enumSetTimer_IC(u8 Copy_u32DutyCycle );
 *      11- Timers_ErrorSTATUS_t Timer2_enumSetTimer_OV(u32 Copy_u32Interval );
 *      12- Timers_ErrorSTATUS_t Timer2_enumSetTimer_CTC(u32 Copy_u32Interval ); 
 *      13- Timers_ErrorSTATUS_t Timer2_enumSetTimer_PWM_F(u8 Copy_u32DutyCycle );
 *      14- Timers_ErrorSTATUS_t Timer2_enumSetTimer_PWM_PC(u8 Copy_u32DutyCycle );  
 *      15- Timers_ErrorSTATUS_t TIMER0_enuSetOVFINT(void(*ptr)(void)); 
 *      16- Timers_ErrorSTATUS_t TIMER0_enuSetCTCINT(void(*ptr)(void)); 
 *      17- Timers_ErrorSTATUS_t TIMER1_enuSetOVFINT(void(*ptr)(void)); 
 *      18- Timers_ErrorSTATUS_t TIMER1_enuSetCTC_CHA_INT(void(*ptr)(void)); 
 *      19- Timers_ErrorSTATUS_t TIMER1_enuSetCTC_CHB_INT(void(*ptr)(void)); 
 *      20- Timers_ErrorSTATUS_t TIMER1_enuSetINP_CAP_INT(void(*ptr)(void)); 
 *      21- Timers_ErrorSTATUS_t TIMER2_enuSetOVFINT(void(*ptr)(void));
 *      22- Timers_ErrorSTATUS_t TIMER2_enuSetCTCINT(void(*ptr)(void));
 ****************************************************************/


#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "Timers_Private.h"
#include "Timers.h"
#include "Timers_CONFIG.h"
#include "../DIO_04/DIO_Private.h"



/**
*@  pointers to function used in ISR 
*@ this variables is been set by call back functions for Timer0 , Timer1 , Timer2 Interrupts
*@ this  functions take function name as input in application layer
*/
/**
*@ pointers to function for Timer0 
*@ OVER FLOW AND CTC INTERRUPTS
*/
 void (*Timer0_AddOVF_CallBack)(void) = NULL;
 void (*Timer0_AddCTC_CallBack)(void) = NULL;
/**
*@ pointers to function for TIMER1
*@ OVER FLOW AND CTC CHANNEL A & B AND INPUT CAPTURE INTERRUPTS
*/
void (*Timer1_AddOVF_CallBack)(void) = NULL;
void (*Timer1_AddCTC_CHA_CallBack)(void) = NULL;
void (*Timer1_AddCTC_CHB_CallBack)(void) = NULL;
void (*Timer1_Add_INP_CAP_CallBack)(void) = NULL;
/**
*@ pointers to function for Timer2 
*@ OVER FLOW AND CTC INTERRUPTS
*/
 void (*Timer2_AddOVF_CallBack)(void) = NULL;
 void (*Timer2_AddCTC_CallBack)(void) = NULL;

 /**
 *@ variables used in calculations
 */
 u8 Timer0_u8OVCounter  = 0;
 u8 Timer0_u8Counter = 0;
 u8 Timer0_u8LoadVal = 0;
 
 u8 Timer1_u8OVCounter  = 0;
 u8 Timer1_u8Counter = 0;
 u8 Timer1_u8LoadVal = 0;
 
 u8 Timer2_u8OVCounter  = 0;
 u8 Timer2_u8Counter = 0;
 u8 Timer2_u8LoadVal = 0;
 

	/**
	*@ breif : function to set the interval in timer0 over flow mode
	*@ param : the interval value it must be in micro seconds 
	*@ return: error status
	*@ this function to work the mode in configration file must be normal mode to gurantee HW behavior
	*@ THE MAXIMUM INPUT THE FUNCTION CAN TAKE IS u32
	*/
	Timers_ErrorSTATUS_t Timer0_enumSetTimer_OV(u32 Copy_u32Interval )
	{
			Timers_ErrorSTATUS_t Local_enuReturnStatus = Timers_enuOK ;
			
				/**
				*@ bit 7
				*@ NON PWM Mode
				*@ 0 --> PWM MODE
				*@ 1 --> NON PWM MODE
				*/
				SET_BIT(TCCR0,BIT_7);
				/**
				*@ NORMAL MODE
				*@ b3,b6
				*@  0 0 --> NORMAL MODE
				*@  0 1 --> PWM PHASE CORRECT MODE
				*@  1 0 --> CTC MODE
				*@  1 1 --> FAST PWM MODE
				*/
				TCCR0 &= TIMER0_OPERATION_MODE_MASK ;
				TCCR0 |= TIMER0_MODE_NORMAL ;
				
					/**
					*@ prescaler selecting
					*/
					TCCR0 &= TIMER0_CLK_SELCT_MASK ;
					
					if (Copy_u32Interval > 0 && Copy_u32Interval < 32)
					{
						/**
						*@ 0 0 1 --> clkI/O/(No prescaling)
						*@ tick time equal .125 micro second
						*@ OVER flow time equal 32 micro second
						*/						
						TCCR0 |= TIMER0_PRESCALER_DIV_1 ;
						
						
						/**
						*@ calculations
						*/
						Timer0_u8OVCounter  = 0;
						Timer0_u8Counter = 0;
						
						f32 Local_f32TickTime = .125 ;
						
						Timer0_u8LoadVal = (( 32 - Copy_u32Interval)/ Local_f32TickTime );
						
						TCNT0 = Timer0_u8LoadVal ;
					}	
					else if ( Copy_u32Interval < 256 && Copy_u32Interval >= 32)
					{
						/**
						*@ 0 1 0 --> clkI/O/8 (From prescaler)
						*@ tick time equal 1 micro second
						*@ OVER flow time equal 256 micro second
						*/
						TCCR0 |= TIMER0_PRESCALER_DIV_8 ;
						
						
						/**
						*@ calculations
						*/
						Timer0_u8OVCounter  = 0;
						Timer0_u8Counter = 0;
						
						u8 Local_u8TickTime = 1 ;
						
					    Timer0_u8LoadVal = ((256 - Copy_u32Interval)/ Local_u8TickTime );
						
						TCNT0 = Timer0_u8LoadVal ;
					}
					else if ( Copy_u32Interval < 2048 && Copy_u32Interval >= 256)	
					{
						/**
						*@ 0 1 1 --> clkI/O/64 (From prescaler)
						*@ tick time equal 8 micro second
						*@ OVER flow time equal 2048 micro second
						*/
						TCCR0 |= TIMER0_PRESCALER_DIV_64 ;
						
						/**
						*@ calculations
						*/
						Timer0_u8OVCounter  = 0;
						Timer0_u8Counter = 0;
						
						u8 Local_u8TickTime = 8 ;
						
					    Timer0_u8LoadVal = ((2048 - Copy_u32Interval)/ Local_u8TickTime );
						
						TCNT0 = Timer0_u8LoadVal ;
					}
					else if ( Copy_u32Interval < 8192 && Copy_u32Interval >= 2048)
					{
						/**
						*@ 1 0 0 --> clkI/O/256 (From prescaler)
						*@ tick time equal 32 micro
						*@ OVER flow time equal 8192 micro second
						*/
						TCCR0 |= TIMER0_PRESCALER_DIV_256 ;
						/**
						*@ calculations
						*/
						Timer0_u8OVCounter  = 0;
						Timer0_u8Counter = 0;
						
						u8 Local_u8TickTime = 32 ;
						
						Timer0_u8LoadVal = ((8192 - Copy_u32Interval)/ Local_u8TickTime );
						
						TCNT0 = Timer0_u8LoadVal ;
					}	
					else if ( Copy_u32Interval < 32768 && Copy_u32Interval >= 8192)
					{
						/**
						*@ 1 0 1 --> clkI/O/1024 (From prescaler)
						*@ tick time equal 128 micro second
						*@ OVER flow time equal 32768 micro second
						*/
						TCCR0 |= TIMER0_PRESCALER_DIV_1024 ;
						
						/**
						*@ calculations
						*/
						Timer0_u8OVCounter  = 0;
						Timer0_u8Counter = 0;
						
						u8 Local_u8TickTime = 128 ;
					   
    				    Timer0_u8LoadVal = ((32768 - Copy_u32Interval)/ Local_u8TickTime );
					
      					TCNT0 = Timer0_u8LoadVal ;
						  
					}	
					else if ( Copy_u32Interval >= 32768 && Copy_u32Interval < 4294967296)/*2^32*/	
					{
						/**
						*@ 1 0 1 --> clkI/O/1024 (From prescaler)
						*@ tick time equal 32768
						*/
						TCCR0 |= TIMER0_PRESCALER_DIV_1024 ;
						/**
						*@ calculations
						*/
						f32 Local_f32FloatCounter ;
						f32 Local_f32FractionVal ;
						
						
						Local_f32FloatCounter = ((f32)Copy_u32Interval / 32768);
						
						Timer0_u8OVCounter = (u32)Local_f32FloatCounter;
						
						Local_f32FractionVal = Local_f32FloatCounter - ((f32)Timer0_u8OVCounter);
						
						Timer0_u8LoadVal = (1-Local_f32FractionVal)*256 ;
						
						//Timer0_u8OVCounter += 1;
						
						TCNT0 = Timer0_u8LoadVal ;
					}	
					else
					
						Local_enuReturnStatus = Timers_enuNOK ;
							
								
			
			
			/**
			*@ enable over flow interrupt
			*/
				SET_BIT(TIMSK,BIT_0);
			/**
			*@ ENABLE GLOBAL INTERRUPT
			*/
			SET_BIT(SREG,BIT_7);
		
				
	return Local_enuReturnStatus ;	
	}/* Timer0_enumSetTimer function */
	
	
	
	/**
	*@ breif : function to set the interval in timer0 compare match mode
	*@ param : the interval value it must be in micro seconds 
	*@ return: error status
	*@ this function to work the mode in configration file must be CTC mode to gurantee HW behavior
	*@ you can configure the prescaler according the value you want in the configration file
	*/
	Timers_ErrorSTATUS_t Timer0_enumSetTimer_CTC(u8 Copy_u32Interval )
	{
			Timers_ErrorSTATUS_t Local_enuReturnStatus = Timers_enuOK ;
			
				/**
				*@ NON PWM Mode
				*@ 0 --> PWM MODE
				*@ 1 --> NON PWM MODE			
				*/
				SET_BIT(TCCR0,BIT_7);
				/**
				*@ TIMER0_MODE_CTC
				*@
				*@ P3,P6			
				*@ 0 0 --> NORMAL MODE
				*@ 0 1 --> PWM PHASE CORRECT MODE
				*@ 1 0 --> CTC MODE
				*@ 1 1 --> FAST PWM MODE
				*/
				TCCR0 &= TIMER0_OPERATION_MODE_MASK ;
				TCCR0 |= TIMER0_MODE_CTC ;
				
					/**
					*@ prescaler selecting
					*/
					TCCR0 &= TIMER0_CLK_SELCT_MASK ;
					
					if (Copy_u32Interval > 0 && Copy_u32Interval < 32)
					{
						/**
						*@ 0 0 1 --> clkI/O/(No prescaling)
						*@ tick time equal .125 micro second
						*@ OVER flow time equal 32 micro second
						*/						
						TCCR0 |= TIMER0_PRESCALER_DIV_1 ;
						
						
						/**
						*@ calculations
						*/
						
						
						f32 Local_f32TickTime = .125 ;
						
						u8 Local_u8LoadVal = (( 32 - Copy_u32Interval)/ Local_f32TickTime );
						
						OCR0 = Local_u8LoadVal ;
					}	
					else if ( Copy_u32Interval < 256 && Copy_u32Interval >= 32)
					{
						/**
						*@ 0 1 0 --> clkI/O/8 (From prescaler)
						*@ tick time equal 1 micro second
						*@ OVER flow time equal 256 micro second
						*/
						TCCR0 |= TIMER0_PRESCALER_DIV_8 ;
						
						
						/**
						*@ calculations
						*/
						
						
						u8 Local_u8TickTime = 1 ;
						
					    u8 Local_u8LoadVal = ((256 - Copy_u32Interval)/ Local_u8TickTime );
						
						OCR0 = Local_u8LoadVal ;
					}
					else if ( Copy_u32Interval < 2048 && Copy_u32Interval >= 256)	
					{
						/**
						*@ 0 1 1 --> clkI/O/64 (From prescaler)
						*@ tick time equal 8 micro second
						*@ OVER flow time equal 2048 micro second
						*/
						TCCR0 |= TIMER0_PRESCALER_DIV_64 ;
						
						/**
						*@ calculations
						*/
						
						
						u8 Local_u8TickTime = 8 ;
						
					    u8 Local_u8LoadVal = ((2048 - Copy_u32Interval)/ Local_u8TickTime );
						
						OCR0 = Local_u8LoadVal ;
					}
					else if ( Copy_u32Interval < 8192 && Copy_u32Interval >= 2048)
					{
						/**
						*@ 1 0 0 --> clkI/O/256 (From prescaler)
						*@ tick time equal 32 micro
						*@ OVER flow time equal 8192 micro second
						*/
						TCCR0 |= TIMER0_PRESCALER_DIV_256 ;
						/**
						*@ calculations
						*/
						
						
						u8 Local_u8TickTime = 32 ;
						
						u8 Local_u8LoadVal = ((8192 - Copy_u32Interval)/ Local_u8TickTime );
						
						OCR0 = Local_u8LoadVal ;
					}	
					else if ( Copy_u32Interval < 32768 && Copy_u32Interval >= 8192)
					{
						/**
						*@ 1 0 1 --> clkI/O/1024 (From prescaler)
						*@ tick time equal 128 micro second
						*@ OVER flow time equal 32768 micro second
						*/
						TCCR0 |= TIMER0_PRESCALER_DIV_1024 ;
						
						/**
						*@ calculations
						*/
						
						
						u8 Local_u8TickTime = 128 ;
					   
    				    u8 Local_u8LoadVal = ((32768 - Copy_u32Interval)/ Local_u8TickTime );
					
      					OCR0 = Local_u8LoadVal ;
						
					}
					else
						Local_enuReturnStatus = Timers_enuNOK ;
							
									
				
	
			
			/**
			*@ enable ctc interrupt
			*/		
				SET_BIT(TIMSK,BIT_1);
			/**
			*@ ENABLE GLOBAL INTERRUPT
			*/
			SET_BIT(SREG,BIT_7);
		
				
				
	return Local_enuReturnStatus ;	
	}/* Timer0_enumSetTimer function */
	
	
	
	/**
	*@ breif : function to set the interval in timer0 FAST PWM mode
	*@ param : The duty cyle in percentage value 
	*@ return: error status
	*@ this function to work the mode in configration file must be FAST PWM mode To gurantee HW behavior
	*@ this function works with prescaler equal 8 only and TIMER0_OC0_PWM_F_NON_INVERTING_MODE
	*/
	Timers_ErrorSTATUS_t Timer0_enumSetTimer_PWM_F(u8 Copy_u32DutyCycle )
	{
			Timers_ErrorSTATUS_t Local_enuReturnStatus = Timers_enuOK ;
			
			
						
						/**
						*@  PWM Mode
						*@ 0 --> PWM MODE
						*@ 1 --> NON PWM MODE			
						*/
						CLR_BIT(TCCR0,BIT_7);
						/**
						*@ TIMER0_MODE_CTC
						*@
						*@ P3,P6			
						*@ 0 0 --> NORMAL MODE
						*@ 0 1 --> PWM PHASE CORRECT MODE
						*@ 1 0 --> CTC MODE
						*@ 1 1 --> FAST PWM MODE
						*/
						TCCR0 &= TIMER0_OPERATION_MODE_MASK ;
						TCCR0 |= TIMER0_MODE_PWM_F ;
						/**
						*@ SET PIN3 AT PORTB (OC0) AS OUTPUT
						*/
						SET_BIT(DDRB,BIT_3);
						/**
						*@ TIMER0_OC0_PWM_F_NON_INVERTING
						*/
						TCCR0 &= TIMER0_OC0_OUTPUT_MODES_MASK ;
						TCCR0 |= TIMER0_OC0_PWM_F_NON_INVERTING ;
						
						/**
						*@ 0 1 0 --> clkI/O/8 (From prescaler)
						*/
						TCCR0 &= TIMER0_CLK_SELCT_MASK ;
						TCCR0 |= TIMER0_PRESCALER_DIV_8 ;
						
						/**
						*@ calculations
						*/
						u8 Local_u8LoadVal = (Copy_u32DutyCycle * 256 )/ 100 ;	
						
						OCR0 = Local_u8LoadVal ;
						
			/**
			*@ enable ctc interrupt
			*/
			SET_BIT(TIMSK,BIT_1);
			/**
			*@ ENABLE GLOBAL INTERRUPT
			*/
			SET_BIT(SREG,BIT_7);
				
				
				
	return Local_enuReturnStatus ;	
	}/* Timer0_enumSetTimer function */
	
	
	
	
	/**
	*@ breif : function to set the interval in timer0 PHASE CORRECT PWM mode
	*@ param : The duty cyle in percentage value 
	*@ return: error status
	*@ this function to work the mode in configration file must be PHASE CORRECT PWM mode
	*@ this function works with prescaler equal 8 only and TIMER0_OC0_PWM_PC_NON_INVERTING_MODE
	*/
	Timers_ErrorSTATUS_t Timer0_enumSetTimer_PWM_PC(u8 Copy_u32DutyCycle )
	
	{
		Timers_ErrorSTATUS_t Local_enuReturnStatus = Timers_enuOK ;
		
			/**
			*@  PWM Mode
			*@ 0 --> PWM MODE
			*@ 1 --> NON PWM MODE			
			*/
			CLR_BIT(TCCR0,BIT_7);
			/**
			*@ TIMER0_MODE_PWM_PC
			*@
			*@ P3,P6			
			*@ 0 0 --> NORMAL MODE
			*@ 0 1 --> PWM PHASE CORRECT MODE
			*@ 1 0 --> CTC MODE
			*@ 1 1 --> FAST PWM MODE
			*/
			TCCR0 &= TIMER0_OPERATION_MODE_MASK ;
			TCCR0 |= TIMER0_MODE_PWM_PC ;
			/**
			*@ SET PIN3 AT PORTB (OC0) AS OUTPUT
			*/
			SET_BIT(DDRB,BIT_3);
			/**
			*@ TIMER0_OC2_PWM_F_NON_INVERTING
			*/
			TCCR0 &= TIMER0_OC0_OUTPUT_MODES_MASK ;
			TCCR0 |= TIMER0_OC0_PWM_PC_NON_INVERTING ;
			
			/**
			*@ 0 1 0 --> clkI/O/8 (From prescaler)
			*/
			TCCR0 &= TIMER0_CLK_SELCT_MASK ;
			TCCR0 |= TIMER0_PRESCALER_DIV_8 ;
			
			/**
			*@ calculations
			*/
			u8 Local_u8LoadVal = (Copy_u32DutyCycle * 256 )/ 100 ;	
			
			OCR0 = Local_u8LoadVal ;
					
		/**
		*@ enable ctc interrupt
		*/	
			SET_BIT(TIMSK,BIT_1);
		/**
		 *@ ENABLE GLOBAL INTERRUPT
		 */
		 SET_BIT(SREG,BIT_7);
			
			
			
 return Local_enuReturnStatus ;	
}/* Timer0_enumSetTimer function */




	/**
	*@ breif : function to set the interval in timer1 over flow mode
	*@ param : the interval value it must be in micro seconds 
	*@ return: error status
	*@ this function to work the mode in configration file must be normal mode to gurantee HW behavior
	*@ THE MAXIMUM INPUT THE FUNCTION CAN TAKE IS u32
	*/
	Timers_ErrorSTATUS_t Timer1_enumSetTimer_OV(u32 Copy_u32Interval )
	{
			Timers_ErrorSTATUS_t Local_enuReturnStatus = Timers_enuOK ;
			
				/**
				 *@ NON PWM Mode
				 *@
				 *@ TCCR1B	TCCR1A	
				 *@ P4  P3  P1  P0
				 *@ 0   0   0    0  	TIMER1_MODE_NORMAL
				 *@ 		   P3  P2
				 *@			1  1	NORMAL MODE
				 */
				 SET_BIT(TCCR1A,BIT_3);
				 SET_BIT(TCCR1A,BIT_2);
				 
				 TCCR1A &= TIMER1_OPERATION_MODE_MASK_A_REG ;
				 TCCR1A |= TIMER1_MODE_NORMAL_AR ;
				 TCCR1B &= TIMER1_OPERATION_MODE_MASK_B_REG ;
				 TCCR1B |= TIMER1_MODE_NORMAL_BR ;
				 
				 
				 
				 
				 
					/**
					*@ prescaler selecting
					*/
					TCCR1B &= TIMER1_CLK_SELCT_MASK ;
					
					if (Copy_u32Interval > 0 && Copy_u32Interval < 4442)
					{
						/**
						*@ 0 0 1 --> clkI/O/(No prescaling)
						*@ tick time equal 125 nano second
						*@ OVER flow time equal 4442 micro second
						*/
						TCCR1B |= TIMER1_PRESCALER_DIV_1 ;
						
						/**
						*@ calculations
						*/
						Timer1_u8OVCounter  = 0;
						Timer1_u8Counter = 0;
						
						f32 Local_f32TickTime = .125 ;
						
						Timer1_u8LoadVal = (( 4442 - Copy_u32Interval)/ Local_f32TickTime );
						
						TCNT1L = Timer1_u8LoadVal ;
					}	
					else if ( Copy_u32Interval < 35536 && Copy_u32Interval >= 4442)
					{
						/**
						*@ 0 1 0 --> clkI/O/8 (From prescaler)
						*@ tick time equal 1 micro second
						*@ OVER flow time equal 35536 micro second
						*/
						TCCR1B |= TIMER1_PRESCALER_DIV_8 ;
						
						/**
						*@ calculations
						*/
						Timer1_u8OVCounter  = 0;
						Timer1_u8Counter = 0;
						
						u8 Local_u8TickTime = 1 ;
						
						Timer1_u8LoadVal = (( 35536 - Copy_u32Interval)/ Local_u8TickTime );
						
						TCNT1L = Timer1_u8LoadVal ;
					}
					else if ( Copy_u32Interval < 284288 && Copy_u32Interval >= 35536)	
					{
						/**
						*@ 0 1 1 --> clkI/O/64 (From prescaler)
						*@ tick time equal 8 micro second
						*@ OVER flow time equal 284288 micro second
						*/
						TCCR1B |= TIMER1_PRESCALER_DIV_64 ;
						
						/**
						*@ calculations
						*/
						Timer1_u8OVCounter  = 0;
						Timer1_u8Counter = 0;
						
						u8 Local_u8TickTime = 8 ;
						
						Timer1_u8LoadVal = (( 284288 - Copy_u32Interval)/ Local_u8TickTime );
						
						TCNT1L = Timer1_u8LoadVal ;
					}
					else if ( Copy_u32Interval < 1137152 && Copy_u32Interval >= 284288)
					{
						/**
						*@ 1 0 0 --> clkI/O/256 (From prescaler)
						*@ tick time equal 32 micro
						*@ OVER flow time equal 1137152 micro second
						*/
						TCCR1B |= TIMER1_PRESCALER_DIV_256 ;
						
						/**
						*@ calculations
						*/
						Timer1_u8OVCounter  = 0;
						Timer1_u8Counter = 0;
						
						u8 Local_u8TickTime = 32 ;
						
						Timer1_u8LoadVal = (( 1137152 - Copy_u32Interval)/ Local_u8TickTime );
						
						TCNT1L = Timer1_u8LoadVal ;
					}	
					else if ( Copy_u32Interval < 4548608 && Copy_u32Interval >= 1137152)
					{
						/**
						*@ 1 0 1 --> clkI/O/1024 (From prescaler)
						*@ tick time equal 128 micro second
						*@ OVER flow time equal 4548608 micro second
						*/
						TCCR1B |= TIMER1_PRESCALER_DIV_1024 ;
						
						/**
						*@ calculations
						*/
						Timer1_u8OVCounter  = 0;
						Timer1_u8Counter = 0;
						
						u8 Local_u8TickTime = 128 ;
						
						Timer1_u8LoadVal = (( 4548608 - Copy_u32Interval)/ Local_u8TickTime );
						
						TCNT1L = Timer1_u8LoadVal ;
					}	
					else if ( Copy_u32Interval >= 4548608 && Copy_u32Interval < 4294967296)/*2^32*/	
					{
						/**
						*@ 1 0 1 --> clkI/O/1024 (From prescaler)
						*@ tick time equal 32768
						*@ OVER flow time equal 4548608 micro second
						*/
						TCCR1B |= TIMER1_PRESCALER_DIV_1024 ;
						/**
						*@ calculations
						*/
						/**
						*@ calculations
						*/
						f32 Local_f32FloatCounter ;
						f32 Local_f32FractionVal ;
						
						
						Local_f32FloatCounter = (Copy_u32Interval / 4548608);
						
						Timer1_u8OVCounter = (u32)Local_f32FloatCounter;
						
						Local_f32FractionVal = Local_f32FloatCounter - ((f32)Timer1_u8OVCounter);
						
						Timer1_u8LoadVal = (1-Local_f32FractionVal)*35536 ;
						
						Timer1_u8OVCounter += 1;
						TCNT1L = Timer0_u8LoadVal ;
						
					}	
						
					else
						Local_enuReturnStatus = Timers_enuNOK ;
						
								
			
			
			/**
			*@ enable over flow interrupt
			*/
				SET_BIT(TIMSK,BIT_0);
			/**
			*@ ENABLE GLOBAL INTERRUPT
			*/
			SET_BIT(SREG,BIT_7);
		
				
	return Local_enuReturnStatus ;	
	}/* Timer1_enumSetTimer function */
	


	/**
	*@ breif : function to set the interval in timer1 CTC mode
	*@ param : the interval value it must be in micro seconds 
	*@ return: error status
	*@ this function to work the mode in configration file must be normal mode to gurantee HW behavior
	*@ THE MAXIMUM INPUT THE FUNCTION CAN TAKE IS u32
	*/
	Timers_ErrorSTATUS_t Timer1_enumSetTimer__CTC_CHA(u16 Copy_u32Interval )
	{
			Timers_ErrorSTATUS_t Local_enuReturnStatus = Timers_enuOK ;
			
				/**
				 *@ NON PWM Mode
				 *@
				 *@ TCCR1B	TCCR1A	
				 *@ P4  P3  P1  P0
				 *@ 0   1   0    0  	TIMER1_MODE_NORMAL
				 *@ 		   P3  P2
				 *@			1  1	NORMAL MODE
				 */
				 SET_BIT(TCCR1A,BIT_3);
				 SET_BIT(TCCR1A,BIT_2);
				 
				 TCCR1A &= TIMER1_OPERATION_MODE_MASK_A_REG ;
				 TCCR1A |= TIMER1_MODE_CTC_OCR1A_AR ;
				 TCCR1B &= TIMER1_OPERATION_MODE_MASK_B_REG ;
				 TCCR1B |= TIMER1_MODE_CTC_OCR1A_BR ;
				 
				 
				 
				 
				 
					/**
					*@ prescaler selecting
					*/
					TCCR1B &= TIMER1_CLK_SELCT_MASK ;
					
					if (Copy_u32Interval > 0 && Copy_u32Interval < 4442)
					{
						/**
						*@ 0 0 1 --> clkI/O/(No prescaling)
						*@ tick time equal 125 nano second
						*@ OVER flow time equal 4442 micro second
						*/
						TCCR1B |= TIMER1_PRESCALER_DIV_1 ;
						
						/**
						*@ calculations
						*/
						
						
						f32 Local_f32TickTime = .125 ;
						
						u8 Local_u8LoadVal = (( 4442 - Copy_u32Interval)/ Local_f32TickTime );
						
						OCR1AL = Local_u8LoadVal ;
					}	
					else if ( Copy_u32Interval < 35536 && Copy_u32Interval >= 4442)
					{
						/**
						*@ 0 1 0 --> clkI/O/8 (From prescaler)
						*@ tick time equal 1 micro second
						*@ OVER flow time equal 35536 micro second
						*/
						TCCR1B |= TIMER1_PRESCALER_DIV_8 ;
						
						/**
						*@ calculations
						*/
						
						
						u8 Local_u8TickTime = 1 ;
						
						u8 Local_u8LoadVal = (( 35536 - Copy_u32Interval)/ Local_u8TickTime );
						
						OCR1AL = Local_u8LoadVal ;
					}
					else if ( Copy_u32Interval < 284288 && Copy_u32Interval >= 35536)	
					{
						/**
						*@ 0 1 1 --> clkI/O/64 (From prescaler)
						*@ tick time equal 8 micro second
						*@ OVER flow time equal 284288 micro second
						*/
						TCCR1B |= TIMER1_PRESCALER_DIV_64 ;
						
						/**
						*@ calculations
						*/
						
						
						u8 Local_u8TickTime = 8 ;
						
						u8 Local_u8LoadVal = (( 284288 - Copy_u32Interval)/ Local_u8TickTime );
						
						OCR1AL = Local_u8LoadVal ;
					}
					else if ( Copy_u32Interval < 1137152 && Copy_u32Interval >= 284288)
					{
						/**
						*@ 1 0 0 --> clkI/O/256 (From prescaler)
						*@ tick time equal 32 micro
						*@ OVER flow time equal 1137152 micro second
						*/
						TCCR1B |= TIMER1_PRESCALER_DIV_256 ;
						
						/**
						*@ calculations
						*/
						
						
						u8 Local_u8TickTime = 32 ;
						
						u8 Local_u8LoadVal = (( 1137152 - Copy_u32Interval)/ Local_u8TickTime );
						
						OCR1AL = Local_u8LoadVal ;
					}	
					else if ( Copy_u32Interval < 4548608 && Copy_u32Interval >= 1137152)
					{
						/**
						*@ 1 0 1 --> clkI/O/1024 (From prescaler)
						*@ tick time equal 128 micro second
						*@ OVER flow time equal 4548608 micro second
						*/
						TCCR1B |= TIMER1_PRESCALER_DIV_1024 ;
						
						/**
						*@ calculations
						*/
						
						
						u8 Local_u8TickTime = 128 ;
						
						u8 Local_u8LoadVal = (( 4548608 - Copy_u32Interval)/ Local_u8TickTime );
						
						OCR1AL = Local_u8LoadVal ;
						
					}
						
						
						
					else
						Local_enuReturnStatus = Timers_enuNOK ;
						
								
			
			
			/**
			*@ enable CTC CHANNEL A interrupt
			*/
				SET_BIT(TIMSK,BIT_4);
			/**
			*@ ENABLE GLOBAL INTERRUPT
			*/
			SET_BIT(SREG,BIT_7);
		
				
	return Local_enuReturnStatus ;	
	}/* Timer1_enumSetTimer function */
	

	/**
	*@ breif : function to set the interval in timer1 CTC mode
	*@ param : the interval value it must be in micro seconds 
	*@ return: error status
	*@ this function to work the mode in configration file must be normal mode to gurantee HW behavior
	*@ THE MAXIMUM INPUT THE FUNCTION CAN TAKE IS u32
	*/
	Timers_ErrorSTATUS_t Timer1_enumSetTimer__CTC_CHB(u16 Copy_u32Interval )
	{
			Timers_ErrorSTATUS_t Local_enuReturnStatus = Timers_enuOK ;
			
				/**
				 *@ NON PWM Mode
				 *@
				 *@ TCCR1B	TCCR1A	
				 *@ P4  P3  P1  P0
				 *@ 0   1   0    0  	TIMER1_MODE_NORMAL
				 *@ 		   P3  P2
				 *@			1  1	NORMAL MODE
				 */
				 SET_BIT(TCCR1A,BIT_3);
				 SET_BIT(TCCR1A,BIT_2);
				 
				 TCCR1A &= TIMER1_OPERATION_MODE_MASK_A_REG ;
				 TCCR1A |= TIMER1_MODE_CTC_OCR1A_BR ;
				 TCCR1B &= TIMER1_OPERATION_MODE_MASK_B_REG ;
				 TCCR1B |= TIMER1_MODE_CTC_OCR1A_BR ;
				 
				 
				 
				 
				 
					/**
					*@ prescaler selecting
					*/
					TCCR1B &= TIMER1_CLK_SELCT_MASK ;
					
					if (Copy_u32Interval > 0 && Copy_u32Interval < 4442)
					{
						/**
						*@ 0 0 1 --> clkI/O/(No prescaling)
						*@ tick time equal 125 nano second
						*@ OVER flow time equal 4442 micro second
						*/
						TCCR1B |= TIMER1_PRESCALER_DIV_1 ;
						
						/**
						*@ calculations
						*/
						
						
						f32 Local_f32TickTime = .125 ;
						
						u8 Local_u8LoadVal = (( 4442 - Copy_u32Interval)/ Local_f32TickTime );
						
						OCR1BL = Local_u8LoadVal ;
					}	
					else if ( Copy_u32Interval < 35536 && Copy_u32Interval >= 4442)
					{
						/**
						*@ 0 1 0 --> clkI/O/8 (From prescaler)
						*@ tick time equal 1 micro second
						*@ OVER flow time equal 35536 micro second
						*/
						TCCR1B |= TIMER1_PRESCALER_DIV_8 ;
						
						/**
						*@ calculations
						*/
						
						
						u8 Local_u8TickTime = 1 ;
						
						u8 Local_u8LoadVal = (( 35536 - Copy_u32Interval)/ Local_u8TickTime );
						
						OCR1BL = Local_u8LoadVal ;
					}
					else if ( Copy_u32Interval < 284288 && Copy_u32Interval >= 35536)	
					{
						/**
						*@ 0 1 1 --> clkI/O/64 (From prescaler)
						*@ tick time equal 8 micro second
						*@ OVER flow time equal 284288 micro second
						*/
						TCCR1B |= TIMER1_PRESCALER_DIV_64 ;
						
						/**
						*@ calculations
						*/
						
						
						u8 Local_u8TickTime = 8 ;
						
						u8 Local_u8LoadVal = (( 284288 - Copy_u32Interval)/ Local_u8TickTime );
						
						OCR1BL = Local_u8LoadVal ;
					}
					else if ( Copy_u32Interval < 1137152 && Copy_u32Interval >= 284288)
					{
						/**
						*@ 1 0 0 --> clkI/O/256 (From prescaler)
						*@ tick time equal 32 micro
						*@ OVER flow time equal 1137152 micro second
						*/
						TCCR1B |= TIMER1_PRESCALER_DIV_256 ;
						
						/**
						*@ calculations
						*/
						
						
						u8 Local_u8TickTime = 32 ;
						
						u8 Local_u8LoadVal = (( 1137152 - Copy_u32Interval)/ Local_u8TickTime );
						
						OCR1BL = Local_u8LoadVal ;
					}	
					else if ( Copy_u32Interval < 4548608 && Copy_u32Interval >= 1137152)
					{
						/**
						*@ 1 0 1 --> clkI/O/1024 (From prescaler)
						*@ tick time equal 128 micro second
						*@ OVER flow time equal 4548608 micro second
						*/
						TCCR1B |= TIMER1_PRESCALER_DIV_1024 ;
						
						/**
						*@ calculations
						*/
						
						
						u8 Local_u8TickTime = 128 ;
						
						u8 Local_u8LoadVal = (( 4548608 - Copy_u32Interval)/ Local_u8TickTime );
						
						OCR1BL = Local_u8LoadVal ;
						
					}
						
						
						
					else
						Local_enuReturnStatus = Timers_enuNOK ;
						
								
			
			
			/**
			*@ enable CTC CHANNEL B interrupt
			*/
				SET_BIT(TIMSK,BIT_3);
			/**
			*@ ENABLE GLOBAL INTERRUPT
			*/
			SET_BIT(SREG,BIT_7);
		
				
	return Local_enuReturnStatus ;	
	}/* Timer1_enumSetTimer function */

	/**
	*@ breif : function to set the interval in timer1 FAST PWM mode
	*@ param : The duty cyle in percentage value 
	*@ return: error status
	*@ this function to work the mode in configration file must be FAST PWM mode To gurantee HW behavior
	*@ this function works with prescaler equal 8 only and TIMER1_OC1_PWM_F_NON_INVERTING_MODE
	*/
	Timers_ErrorSTATUS_t Timer1_enumSetTimer_PWM_F(u16 Copy_u32DutyCycle )
	{
		Timers_ErrorSTATUS_t Local_enuReturnStatus = Timers_enuOK ;
		
				 /**
				 *@  PWM Mode
				 *@
				 *@ TCCR1B	TCCR1A	
				 *@ P4  P3  P1  P0
				 *@ 0   1   0    0  	TIMER1_MODE_F
				 *@ 		   P3  P2
				 *@			0  0	NORMAL MODE
				 */
				 CLR_BIT(TCCR1A,BIT_3);
				 CLR_BIT(TCCR1A,BIT_2);
				 
				 TCCR1A &= TIMER1_OPERATION_MODE_MASK_A_REG ;
				 TCCR1A |= TIMER1_MODE_PWM_F_ICR1_AR ;
				 TCCR1B &= TIMER1_OPERATION_MODE_MASK_B_REG ;
				 TCCR1B |= TIMER1_MODE_PWM_F_ICR1_BR ;
				 
						/**
						*@ SET PIN5 AT PORTD (OC1A) AS OUTPUT
						*@ SET PIN4 AT PORTD (OC1B) AS OUTPUT
						*/
						SET_BIT(DDRD,BIT_5);
						SET_BIT(DDRD,BIT_4);
						/**
						*@ TIMER0_OC0_PWM_F_NON_INVERTING
						*/
						TCCR1A &= TIMER1_CHANNELA_OC1A_OUTPUT_MODES_MASK ;
						TCCR1A &= TIMER1_CHANNELB_OC1B_OUTPUT_MODES_MASK ;
						TCCR1A |= TIMER1_PWM_F_OC1A_NONE_INVERTING ;
						TCCR1A |= TIMER1_PWM_F_OC1B_NONE_INVERTING ;
						
						/**
						*@ 0 1 0 --> clkI/O/8 (From prescaler)
						*/
						TCCR1B &= TIMER0_CLK_SELCT_MASK ;
						TCCR1B |= TIMER0_PRESCALER_DIV_8 ;
						/**
						*@ usr ICR1 register as top value to be 20000
						*/
						ICR1L = 20000 ;
						/**
						*@ calculations
						*/
						u8 Local_u8LoadVal = (Copy_u32DutyCycle * 20000 )/ 100 ;	
						/**
						*@ FOR BOTH CHANNELS A & B
						*/
						OCR1AL = Local_u8LoadVal ;
						OCR1BL = Local_u8LoadVal ;
						
			
				
		
	return Local_enuReturnStatus ;
	}
	
		
	/**
	*@ breif : function to set the interval in timer1 PHASE CORRECT PWM mode
	*@ param : The duty cyle in percentage value 
	*@ return: error status
	*@ this function to work the mode in configration file must be PHASE CORRECT PWM mode
	*@ this function works with prescaler equal 8 only and TIMER1_OC1_PWM_PC_NON_INVERTING_MODE
	*/
	Timers_ErrorSTATUS_t Timer1_enumSetTimer_PWM_PC(u16 Copy_u32DutyCycle )
	{
		Timers_ErrorSTATUS_t Local_enuReturnStatus = Timers_enuOK ;
		
						 /**
				 *@  PWM Mode
				 *@
				 *@ TCCR1B	TCCR1A	
				 *@ P4  P3  P1  P0
				 *@ 0   1   0    0  	TIMER1_MODE_F
				 *@ 		   P3  P2
				 *@			0  0	NORMAL MODE
				 */
				 CLR_BIT(TCCR1A,BIT_3);
				 CLR_BIT(TCCR1A,BIT_2);
				 
				 TCCR1A &= TIMER1_OPERATION_MODE_MASK_A_REG ;
				 TCCR1A |= TIMER1_MODE_PWM_PC_ICR1_AR ;
				 TCCR1B &= TIMER1_OPERATION_MODE_MASK_B_REG ;
				 TCCR1B |= TIMER1_MODE_PWM_PC_ICR1_BR ;
				 
						/**
						*@ SET PIN5 AT PORTD (OC1A) AS OUTPUT
						*@ SET PIN4 AT PORTD (OC1B) AS OUTPUT
						*/
						SET_BIT(DDRD,BIT_5);
						SET_BIT(DDRD,BIT_4);
						/**
						*@ TIMER0_OC0_PWM_F_NON_INVERTING
						*/
						TCCR1A &= TIMER1_CHANNELA_OC1A_OUTPUT_MODES_MASK ;
						TCCR1A &= TIMER1_CHANNELB_OC1B_OUTPUT_MODES_MASK ;
						TCCR1A |= TIMER1_PWM_PC_OC1A_NONE_INVERTING ;
						TCCR1A |= TIMER1_PWM_PC_OC1A_NONE_INVERTING ;
						
						/**
						*@ 0 1 0 --> clkI/O/8 (From prescaler)
						*/
						TCCR1B &= TIMER0_CLK_SELCT_MASK ;
						TCCR1B |= TIMER0_PRESCALER_DIV_8 ;
						/**
						*@ usr ICR1 register as top value to be 20000
						*/
						ICR1L = 20000 ;
						/**
						*@ calculations
						*/
						u8 Local_u8LoadVal = (Copy_u32DutyCycle * 20000 )/ 100 ;	
						/**
						*@ FOR BOTH CHANNELS A & B
						*/
						OCR1AL = Local_u8LoadVal ;
						OCR1BL = Local_u8LoadVal ;
						

		
	return Local_enuReturnStatus ;	
	}
	
	/**
	*@ breif : function to set the interval in timer1 INPUT CAPTURE mode
	*@ param : The duty cyle in percentage value 
	*@ return: error status
	*@ this function to work the mode in configration file must be PHASE CORRECT PWM mode
	*@ this function works with prescaler equal 8 only and TIMER1_OC1_PWM_PC_NON_INVERTING_MODE
	*/
	Timers_ErrorSTATUS_t Timer1_enumSetTimer_IC(u16 Copy_u32DutyCycle )
	{
		Timers_ErrorSTATUS_t Local_enuReturnStatus = Timers_enuOK ;

		
	return Local_enuReturnStatus ;	
	}
	
	/**
	*@ breif : function to set the interval in timer2 over flow mode
	*@ param : the interval value it must be in micro seconds 
	*@ return: error status
	*@ this function to work the mode in configration file must be normal mode to gurantee HW behavior
	*@ THE MAXIMUM INPUT THE FUNCTION CAN TAKE IS u32
	*/
	Timers_ErrorSTATUS_t Timer2_enumSetTimer_OV(u32 Copy_u32Interval )
	{
			Timers_ErrorSTATUS_t Local_enuReturnStatus = Timers_enuOK ;
			/**
			*@ TIMER Mode not counter Mode
			*/
			//SET_BIT(ASSR,BIT_3);
				/**
					*@ NON PWM Mode
					*@ 0 --> PWM MODE
					*@ 1 --> NON PWM MODE
					*/
					SET_BIT(TCCR2,BIT_7);
					/**
					*@ NORMAL MODE
					*@ P3,P6
					*@  0 0 --> NORMAL MODE
					*@  0 1 --> PWM PHASE CORRECT MODE
					*@  1 0 --> CTC MODE
					*@  1 1 --> FAST PWM MODE
					*/
					TCCR2 &= TIMER2_OPERATION_MODE_MASK ;
					TCCR2 |= TIMER2_MODE_NORMAL ;
					
					/**
					*@ prescaler selecting
					*/
					TCCR2 &= TIMER2_CLK_SELCT_MASK ;
			
					if (Copy_u32Interval > 0 && Copy_u32Interval < 32)
					{
						/**
						*@ 0 0 1 --> clkI/O/(No prescaling)
						*@ tick time equal 125 nano second
						*@ OVER flow time equal 32 micro second
						*/
						TCCR2 |= TIMER2_PRESCALER_DIV_1 ;
						/**
						*@ calculations
						*/
						Timer2_u8OVCounter  = 0;
						Timer2_u8Counter = 0;
						
						f32 Local_f32TickTime = .125 ;
						
					    Timer2_u8LoadVal = (( 32 - Copy_u32Interval)/ Local_f32TickTime );
						
						TCNT2 = Timer2_u8LoadVal ;
					}	
					else if ( Copy_u32Interval < 256 && Copy_u32Interval > 32)
					{
						/**
						*@ 0 1 0 --> clkI/O/8 (From prescaler)
						*@ tick time equal 1 micro second
						*/
						TCCR2 |= TIMER2_PRESCALER_DIV_8 ;
						
						
						/**
						*@ calculations
						*/
						Timer2_u8OVCounter  = 0;
						Timer2_u8Counter = 0;
						
						u8 Local_u8TickTime = 1 ;
						
					    Timer2_u8LoadVal = ((256 - Copy_u32Interval)/ Local_u8TickTime );
						
						TCNT2 = Timer2_u8LoadVal ;
					}
					else if ( Copy_u32Interval < 2048 && Copy_u32Interval > 256)	
					{
						/**
						*@ 0 1 1 --> clkI/O/64 (From prescaler)
						*@ tick time equal 8 micro second
						*@ OVER flow time equal 256 micro second
						*/
						TCCR2 |= TIMER2_PRESCALER_DIV_64 ;
						
						
						/**
						*@ calculations
						*/
						Timer2_u8OVCounter  = 0;
						Timer2_u8Counter = 0;
						
						u8 Local_u8TickTime = 8 ;
						
					    Timer0_u8LoadVal = ((2048 - Copy_u32Interval)/ Local_u8TickTime );
						
						TCNT2 = Timer2_u8LoadVal ;
					}
					else if ( Copy_u32Interval < 8192 && Copy_u32Interval > 2048)
					{
						/**
						*@ 1 0 0 --> clkI/O/256 (From prescaler)
						*@ tick time equal 32 micro
						*@ OVER flow time equal 8192 micro second
						*/
						TCCR2 |= TIMER2_PRESCALER_DIV_256 ;
						
						
						/**
						*@ calculations
						*/
						Timer2_u8OVCounter  = 0;
						Timer2_u8Counter = 0;
						
						u8 Local_u8TickTime = 32 ;
						
					    Timer2_u8LoadVal = ((8192 - Copy_u32Interval)/ Local_u8TickTime );
						
						TCNT2 = Timer2_u8LoadVal ;
					}	
					else if ( Copy_u32Interval < 32768 && Copy_u32Interval > 8192)
					{
						/**
						*@ 1 0 1 --> clkI/O/1024 (From prescaler)
						*@ tick time equal 128 micro second
						*@ OVER flow time equal 32768 micro second
						*/
						TCCR2 |= TIMER2_PRESCALER_DIV_1024 ;
						
						
						/**
						*@ calculations
						*/
						Timer2_u8OVCounter  = 0;
						Timer2_u8Counter = 0;
						
						u8 Local_u8TickTime = 128 ;
						
					    Timer2_u8LoadVal = ((32768 - Copy_u32Interval)/ Local_u8TickTime );
						
						TCNT2 = Timer2_u8LoadVal ;
					}	
					else if ( Copy_u32Interval > 32768 && Copy_u32Interval < 4294967296)/*2^32*/	
					{
						/**
						*@ 1 0 1 --> clkI/O/1024 (From prescaler)
						*@ tick time equal 32768
						*@ OVER flow time equal 32768 micro second
						*/
						TCCR2 |= TIMER2_PRESCALER_DIV_1024 ;
						/**
						*@ calculations
						*/
						f32 Local_f32FloatCounter ;
						f32 Local_f32FractionVal ;
						
						
						Local_f32FloatCounter = ((f32)Copy_u32Interval / 32768);
						
						Timer2_u8OVCounter = (u32)Local_f32FloatCounter;
						
						Local_f32FractionVal = Local_f32FloatCounter - ((f32)Timer2_u8OVCounter);
						
						Timer2_u8LoadVal = (1-Local_f32FractionVal)*256 ;
						
						//Timer2_u8OVCounter += 1;
						TCNT2 = Timer2_u8LoadVal ;
						
						
					}	
					else
						Local_enuReturnStatus = Timers_enuNOK ;
							
								
			
			
			/**
			*@ enable over flow interrupt
			*/
				SET_BIT(TIMSK,BIT_6);
			/**
			*@ ENABLE GLOBAL INTERRUPT
			*/
			SET_BIT(SREG,BIT_7);
		
				
	return Local_enuReturnStatus ;	
	}/* Timer2_enumSetTimer function */
	
	
	
	/**
	*@ breif : function to set the interval in timer2 compare match mode
	*@ param : the interval value it must be in micro seconds 
	*@ return: error status
	*@ this function to work the mode in configration file must be CTC mode to gurantee HW behavior
	*@ you can configure the prescaler according the value you want in the configration file
	*/
	Timers_ErrorSTATUS_t Timer2_enumSetTimer_CTC(u8 Copy_u32Interval )
	{
			Timers_ErrorSTATUS_t Local_enuReturnStatus = Timers_enuOK ;
			
					/**
					*@ NON PWM Mode
					*@ 0 --> PWM MODE
					*@ 1 --> NON PWM MODE			
					*/
					SET_BIT(TCCR2,BIT_7);
					/**
					*@ TIMER0_MODE_CTC
					*@
					*@ P3,P6			
					*@ 0 0 --> NORMAL MODE
					*@ 0 1 --> PWM PHASE CORRECT MODE
					*@ 1 0 --> CTC MODE
					*@ 1 1 --> FAST PWM MODE
					*/
					TCCR2 &= TIMER2_OPERATION_MODE_MASK ;
				    TCCR2 |= TIMER2_MODE_NORMAL ;
				
					/**
					*@ prescaler selecting
					*/
					TCCR2 &= TIMER2_CLK_SELCT_MASK ;
					
					if (Copy_u32Interval > 0 && Copy_u32Interval < 32)
					{
						/**
						*@ 0 0 1 --> clkI/O/(No prescaling)
						*@ tick time equal .125 micro second
						*@ OVER flow time equal 32 micro second
						*/						
						TCCR2 |= TIMER2_PRESCALER_DIV_1 ;
						
						
						/**
						*@ calculations
						*/
						
						
						f32 Local_f32TickTime = .125 ;
						
						u8 Local_u8LoadVal = (( 32 - Copy_u32Interval)/ Local_f32TickTime );
						
						OCR2 = Local_u8LoadVal ;
					}	
					else if ( Copy_u32Interval < 256 && Copy_u32Interval >= 32)
					{
						/**
						*@ 0 1 0 --> clkI/O/8 (From prescaler)
						*@ tick time equal 1 micro second
						*@ OVER flow time equal 256 micro second
						*/
						TCCR2 |= TIMER2_PRESCALER_DIV_8 ;
						
						
						/**
						*@ calculations
						*/
						
						
						u8 Local_u8TickTime = 1 ;
						
					    u8 Local_u8LoadVal = ((256 - Copy_u32Interval)/ Local_u8TickTime );
						
						OCR2 = Local_u8LoadVal ;
					}
					else if ( Copy_u32Interval < 2048 && Copy_u32Interval >= 256)	
					{
						/**
						*@ 0 1 1 --> clkI/O/64 (From prescaler)
						*@ tick time equal 8 micro second
						*@ OVER flow time equal 2048 micro second
						*/
						TCCR2 |= TIMER2_PRESCALER_DIV_64 ;
						
						/**
						*@ calculations
						*/
						
						
						u8 Local_u8TickTime = 8 ;
						
					    u8 Local_u8LoadVal = ((2048 - Copy_u32Interval)/ Local_u8TickTime );
						
						OCR2 = Local_u8LoadVal ;
					}
					else if ( Copy_u32Interval < 8192 && Copy_u32Interval >= 2048)
					{
						/**
						*@ 1 0 0 --> clkI/O/256 (From prescaler)
						*@ tick time equal 32 micro
						*@ OVER flow time equal 8192 micro second
						*/
						TCCR2 |= TIMER2_PRESCALER_DIV_256 ;
						/**
						*@ calculations
						*/
						
						
						u8 Local_u8TickTime = 32 ;
						
						u8 Local_u8LoadVal = ((8192 - Copy_u32Interval)/ Local_u8TickTime );
						
						OCR2 = Local_u8LoadVal ;
					}	
					else if ( Copy_u32Interval < 32768 && Copy_u32Interval >= 8192)
					{
						/**
						*@ 1 0 1 --> clkI/O/1024 (From prescaler)
						*@ tick time equal 128 micro second
						*@ OVER flow time equal 32768 micro second
						*/
						TCCR2 |= TIMER2_PRESCALER_DIV_1024 ;
						
						/**
						*@ calculations
						*/
						
						
						u8 Local_u8TickTime = 128 ;
					   
    				    u8 Local_u8LoadVal = ((32768 - Copy_u32Interval)/ Local_u8TickTime );
					
      					OCR2 = Local_u8LoadVal ;
						
					}
					else
						Local_enuReturnStatus = Timers_enuNOK ;
							
								
				
	
			
			/**
			*@ enable ctc interrupt
			*/		
				SET_BIT(TIMSK,BIT_7);
			/**
			*@ ENABLE GLOBAL INTERRUPT
			*/
			SET_BIT(SREG,BIT_7);
		
				
				
	return Local_enuReturnStatus ;	
	}/* Timer2_enumSetTimer function */
	
	
	
	/**
	*@ breif : function to set the interval in timer2 FAST PWM mode
	*@ param : The duty cyle in percentage value 
	*@ return: error status
	*@ this function to work the mode in configration file must be FAST PWM mode To gurantee HW behavior
	*@ this function works with prescaler equal 8 only and TIMER0_OC0_PWM_F_NON_INVERTING_MODE
	*/
	Timers_ErrorSTATUS_t Timer2_enumSetTimer_PWM_F(u8 Copy_u32DutyCycle )
	{
			Timers_ErrorSTATUS_t Local_enuReturnStatus = Timers_enuOK ;
			
			
						
						/**
						*@  PWM Mode
						*@ 0 --> PWM MODE
						*@ 1 --> NON PWM MODE			
						*/
						CLR_BIT(TCCR2,BIT_7);
						/**
						*@ TIMER0_MODE_CTC
						*@
						*@ P3,P6			
						*@ 0 0 --> NORMAL MODE
						*@ 0 1 --> PWM PHASE CORRECT MODE
						*@ 1 0 --> CTC MODE
						*@ 1 1 --> FAST PWM MODE
						*/
						TCCR2 &= TIMER2_OPERATION_MODE_MASK ;
						TCCR2 |= TIMER2_MODE_PWM_F ;
						/**
						*@ SET PIN7 AT PORTD (OC2) AS OUTPUT
						*/
						SET_BIT(DDRB,BIT_7);
						/**
						*@ TIMER0_OC2_PWM_F_NON_INVERTING
						*/
						TCCR2 &= TIMER2_OC2_OUTPUT_MODES_MASK ;
						TCCR2 |= TIMER2_OC2_PWM_F_NON_INVERTING_MODE ;
						
						/**
						*@ 0 1 0 --> clkI/O/8 (From prescaler)
						*/
						TCCR2 &= TIMER2_CLK_SELCT_MASK ;
						TCCR2 |= TIMER2_PRESCALER_DIV_8 ;
						
						/**
						*@ calculations
						*/
						u8 Local_u8LoadVal = (Copy_u32DutyCycle * 256 )/ 100 ;	
						
						OCR2 = Local_u8LoadVal ;
						
			/**
			*@ enable ctc interrupt
			*/
			SET_BIT(TIMSK,BIT_7);
			/**
			*@ ENABLE GLOBAL INTERRUPT
			*/
			SET_BIT(SREG,BIT_7);
				
				
				
	return Local_enuReturnStatus ;	
	}/* Timer2_enumSetTimer function */
	
	
	
	
	/**
	*@ breif : function to set the interval in timer2 PHASE CORRECT PWM mode
	*@ param : The duty cyle in percentage value 
	*@ return: error status
	*@ this function to work the mode in configration file must be PHASE CORRECT PWM mode
	*@ this function works with prescaler equal 8 only and TIMER0_OC0_PWM_PC_NON_INVERTING_MODE
	*/
	Timers_ErrorSTATUS_t Timer2_enumSetTimer_PWM_PC(u8 Copy_u32DutyCycle )
	
	{
		Timers_ErrorSTATUS_t Local_enuReturnStatus = Timers_enuOK ;
		
			/**
			*@  PWM Mode
			*@ 0 --> PWM MODE
			*@ 1 --> NON PWM MODE			
			*/
			CLR_BIT(TCCR2,BIT_7);
			/**
			*@ TIMER0_MODE_PWM_PC
			*@
			*@ P3,P6			
			*@ 0 0 --> NORMAL MODE
			*@ 0 1 --> PWM PHASE CORRECT MODE
			*@ 1 0 --> CTC MODE
			*@ 1 1 --> FAST PWM MODE
			*/
			TCCR2 &= TIMER2_OPERATION_MODE_MASK ;
			TCCR2 |= TIMER2_MODE_PWM_PC ;
			/**
			*@ SET PIN7 AT PORTD (OC2) AS OUTPUT
			*/
			SET_BIT(DDRB,BIT_7);
			/**
			*@ TIMER0_OC2_PWM_F_NON_INVERTING
			*/
			TCCR2 &= TIMER2_OC2_OUTPUT_MODES_MASK ;
			TCCR2 |= TIMER2_OC2_PWM_PC_NON_INVERTING_MODE ;
			
			/**
			*@ 0 1 0 --> clkI/O/8 (From prescaler)
			*/
			TCCR2 &= TIMER2_CLK_SELCT_MASK ;
			TCCR2 |= TIMER2_PRESCALER_DIV_8 ;		
			/**
			*@ calculations
			*/
			u8 Local_u8LoadVal = (Copy_u32DutyCycle * 256 )/ 100 ;	
			
			OCR2 = Local_u8LoadVal ;
					
		/**
		*@ enable ctc interrupt
		*/	
			SET_BIT(TIMSK,BIT_7);
		/**
		 *@ ENABLE GLOBAL INTERRUPT
		 */
		 SET_BIT(SREG,BIT_7);
			
			
			
 return Local_enuReturnStatus ;	
}/* Timer2_enumSetTimer function */









/**
*@ function take pointer to function as input from application 
*@ and assign this variable Timer0_AddOVF_CallBack which used in OVER FLOW ISR 
*/
Timers_ErrorSTATUS_t TIMER0_enuSetOVFINT(void(*ptr)(void))
{
		/**
		*@ return variable to check the behavior of the function
		*/
		Timers_ErrorSTATUS_t Local_enuReturnStatus = Timers_enuOK ;
	
		/**
		*@ check if the user pass correct function or not
		*/
		if( ptr == NULL )
		{
			Local_enuReturnStatus = Timers_enuNOK ;
		}
		else
		{
			Timer0_AddOVF_CallBack = ptr ;
		}
	



return Local_enuReturnStatus ;		
}/*TIMER0_enuSetOVFINT*/



/**
*@ function take pointer to function as input from application 
*@ and assign this variable Timer0_AddCTC_CallBack which used in CTC ISR 
*/
Timers_ErrorSTATUS_t TIMER0_enuSetCTCINT(void(*ptr)(void))
{
		/**
		*@ return variable to check the behavior of the function
		*/
		Timers_ErrorSTATUS_t Local_enuReturnStatus = Timers_enuOK ;
	
		/**
		*@ check if the user pass correct function or not
		*/
		if( ptr == NULL )
		{
			Local_enuReturnStatus = Timers_enuNOK ;
		}
		else
		{
			Timer0_AddCTC_CallBack = ptr ;
		}
	



return Local_enuReturnStatus ;		
}/*TIMER0_enuSetCTCINT*/



/**
*@ function take pointer to function as input from application 
*@ and assign this variable Timer1_AddOVF_CallBack which used in OVER FLOW ISR 
*/
Timers_ErrorSTATUS_t TIMER1_enuSetOVFINT(void(*ptr)(void))
{
		/**
		*@ return variable to check the behavior of the function
		*/
		Timers_ErrorSTATUS_t Local_enuReturnStatus = Timers_enuOK ;
	
		/**
		*@ check if the user pass correct function or not
		*/
		if( ptr == NULL )
		{
			Local_enuReturnStatus = Timers_enuNOK ;
		}
		else
		{
			Timer1_AddOVF_CallBack = ptr ;
		}
	



return Local_enuReturnStatus ;		
}/*TIMER1_enuSetOVFINT*/




/**
*@ function take pointer to function as input from application 
*@ and assign this variable Timer1_AddCTC_CHA_CallBack which used in CTC CHANNEL A ISR 
*/
Timers_ErrorSTATUS_t TIMER1_enuSetCTC_CHA_INT(void(*ptr)(void))
{
		/**
		*@ return variable to check the behavior of the function
		*/
		Timers_ErrorSTATUS_t Local_enuReturnStatus = Timers_enuOK ;
	
		/**
		*@ check if the user pass correct function or not
		*/
		if( ptr == NULL )
		{
			Local_enuReturnStatus = Timers_enuNOK ;
		}
		else
		{
			Timer1_AddCTC_CHA_CallBack = ptr ;
		}
	



return Local_enuReturnStatus ;		
}/*TIMER1_enuSetCTC_CHA_INT*/

/**
*@ function take pointer to function as input from application 
*@ and assign this variable Timer1_AddCTC_CHB_CallBack which used in CTC CHANNEL B ISR 
*/
Timers_ErrorSTATUS_t TIMER1_enuSetCTC_CHB_INT(void(*ptr)(void))
{
		/**
		*@ return variable to check the behavior of the function
		*/
		Timers_ErrorSTATUS_t Local_enuReturnStatus = Timers_enuOK ;
	
		/**
		*@ check if the user pass correct function or not
		*/
		if( ptr == NULL )
		{
			Local_enuReturnStatus = Timers_enuNOK ;
		}
		else
		{
			Timer1_AddCTC_CHB_CallBack = ptr ;
		}
	



return Local_enuReturnStatus ;		
}/*TIMER1_enuSetCTC_CHB_INT*/



/**
*@ function take pointer to function as input from application 
*@ and assign this variable Timer1_Add_INP_CAP_CallBack which used in INPUT CAPTURE ISR 
*/
Timers_ErrorSTATUS_t TIMER1_enuSetINP_CAP_INT(void(*ptr)(void))
{
		/**
		*@ return variable to check the behavior of the function
		*/
		Timers_ErrorSTATUS_t Local_enuReturnStatus = Timers_enuOK ;
	
		/**
		*@ check if the user pass correct function or not
		*/
		if( ptr == NULL )
		{
			Local_enuReturnStatus = Timers_enuNOK ;
		}
		else
		{
			Timer1_Add_INP_CAP_CallBack = ptr ;
		}
	



return Local_enuReturnStatus ;		
}/*TIMER1_enuSetINP_CAP_INT*/



/**
*@ function take pointer to function as input from application 
*@ and assign this variable Timer2_AddOVF_CallBack which used in OVER FLOW ISR 
*/
Timers_ErrorSTATUS_t TIMER2_enuSetOVFINT(void(*ptr)(void))
{
		/**
		*@ return variable to check the behavior of the function
		*/
		Timers_ErrorSTATUS_t Local_enuReturnStatus = Timers_enuOK ;
	
		/**
		*@ check if the user pass correct function or not
		*/
		if( ptr == NULL )
		{
			Local_enuReturnStatus = Timers_enuNOK ;
		}
		else
		{
			Timer2_AddOVF_CallBack = ptr ;
		}
	



return Local_enuReturnStatus ;		
}/*TIMER2_enuSetOVFINT*/



/**
*@ function take pointer to function as input from application 
*@ and assign this variable Timer2_AddCTC_CallBack which used in CTC ISR 
*/
Timers_ErrorSTATUS_t TIMER2_enuSetCTCINT(void(*ptr)(void))
{
		/**
		*@ return variable to check the behavior of the function
		*/
		Timers_ErrorSTATUS_t Local_enuReturnStatus = Timers_enuOK ;
	
		/**
		*@ check if the user pass correct function or not
		*/
		if( ptr == NULL )
		{
			Local_enuReturnStatus = Timers_enuNOK ;
		}
		else
		{
			Timer2_AddCTC_CallBack = ptr ;
		}
	



return Local_enuReturnStatus ;		
}/*TIMER2_enuSetCTCINT*/

/**
*@ INTERRUPT HANDLER OF TIMER0 OVER FLOW MODE
*/
ISR(TIMER0_OV_ISR)
{
	if(Timer0_u8Counter == Timer0_u8OVCounter)
	{
		Timer0_AddOVF_CallBack();
	
		TCNT0 = Timer0_u8LoadVal ;
		
		Timer0_u8Counter = 0;
	}
	else
	{
		Timer0_u8Counter ++;
	}
}/*TIMER0_OV_ISR*/


/**
*@ INTERRUPT HANDLER OF TIMER0 CTC MODE
*/
ISR(TIMER0_CTC_ISR)
{
	Timer0_AddCTC_CallBack();
	
}/*TIMER0_CTC_ISR*/


/**
*@ INTERRUPT HANDLER OF TIMER1 OVER FLOW MODE
*/
ISR(TIMER1_OV_ISR)
{
	if(Timer1_u8Counter == Timer1_u8OVCounter)
	{
		Timer1_AddOVF_CallBack();
	
		TCNT1L = Timer1_u8LoadVal ;
		
		Timer1_u8Counter = 0;
	}
	else
	{
		Timer1_u8Counter ++;
	}
	
	
}/*TIMER1_OV_ISR*/


/**
*@ INTERRUPT HANDLER OF TIMER1 CTC MODE MODE CHANNEL A
*/
ISR(TIMER1_CTC_CHA_ISR)
{
	Timer1_AddCTC_CHA_CallBack();
	
}/*TIMER_CTC_CHA_ISR*/


/**
*@ INTERRUPT HANDLER OF TIMER1 CTC MODE CHANNEL B 
*/
ISR(TIMER1_CTC_CHB_ISR)
{
	Timer1_AddCTC_CHB_CallBack();
	
}/*TIMER_CTC_CHB_ISR*/


/**
*@ INTERRUPT HANDLER OF TIMER1 INPUT CAPTURE MODE
*/
ISR(TIMER1_INP_CAP_ISR)
{
	Timer1_Add_INP_CAP_CallBack();
	
}/*TIMER_INP_CAP_ISR*/



/**
*@ INTERRUPT HANDLER OF TIMER2 OVER FLOW MODE
*/
ISR(TIMER2_OV_ISR)
{
	if(Timer2_u8Counter == Timer2_u8OVCounter)
	{
		Timer2_AddOVF_CallBack();
	
		TCNT2 = Timer2_u8LoadVal ;
		
		Timer2_u8Counter = 0;
	}
	else
	{
		Timer2_u8Counter ++;
	}
	
	
}/*TIMER2_OV_ISR*/


/**
*@ INTERRUPT HANDLER OF TIMER2 CTC MODE
*/
ISR(TIMER2_CTC_ISR)
{
	Timer2_AddCTC_CallBack();
	
}/*TIMER2_CTC_ISR*/

