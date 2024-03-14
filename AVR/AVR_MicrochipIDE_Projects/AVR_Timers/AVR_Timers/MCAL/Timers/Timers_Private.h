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









#ifndef		TIMERS_PRIVATE_H
#define		TIMERS_PRIVATE_H

#include "../../LIB/STD_TYPES.h"


/******************************************************
 * 		Registers Adrresses		      *
 ******************************************************/

#define WDT_REFRESH()	asm("WDR")

#define TCCR0	*((volatile u8*)0x53)
#define TCNT0	*((volatile u8*)0x52)
#define OCR0	*((volatile u8*)0x5C)
#define TIMSK	*((volatile u8*)0x59)
#define TIFR	*((volatile u8*)0x58)
#define TCCR1A	*((volatile u8*)0x4F)
#define TCCR1B	*((volatile u8*)0x4E)
#define TCNT1H	*((volatile u8*)0x4D)
#define TCNT1L	*((volatile u16*)0x4C)
#define OCR1AH	*((volatile u8*)0x4B)
#define OCR1AL	*((volatile u16*)0x4A)
#define OCR1BH	*((volatile u8*)0x49)
#define OCR1BL	*((volatile u16*)0x48)
#define ICR1H	*((volatile u8*)0x47)
#define ICR1L	*((volatile u16*)0x46)
#define TCCR2	*((volatile u8*)0x45)
#define TCNT2	*((volatile u8*)0x44)
#define OCR2	*((volatile u8*)0x43)
#define ASSR	*((volatile u8*)0x42)
#define WDTCR	*((volatile u8*)0x41)
#define SFIOR	*((volatile u8*)0x50)
#define SREG 	*((volatile u8*)0x5F)
#define OCR	*((volatile u16*)0x4A)



/******************************************************
 * 		Timers ISR Defination		      *
 ******************************************************/

#define ISR(vect_no) void vect(vect_no)(void) __attribute__((signal));\
						void vect(vect_no) (void)
#define vect(x) __vector_##x


/******************************************************
 * 		Timers Macros		   	      *
 ******************************************************/

#define ENABLE   1
#define DISABLE  0


/*================================================ timer 0 =================================================*/

/***************************************************************
 *		TCCR0_REG timer/Counter Control Register       *
 ***************************************************************/

/**
 *@ Waveform Generation Mode (pin 6 & pin 3)
 */

#define TIMER0_OPERATION_MODE_MASK      0b10110111

#define TIMER0_MODE_NORMAL           	(u8)0x00
#define TIMER0_MODE_PWM_PC         	    (u8)0x40
#define TIMER0_MODE_CTC                 (u8)0x08
#define TIMER0_MODE_PWM_F               (u8)0x48

/**
 *@ (pin 5 & pin 4)
 *@ hardware behavior in diffrent modes (OC0)
 *@ non-PWM Mode : Compare Output Mode
 *@ PWM Mode: Fast PWM Mode , Phase Correct PWM Mode
 */


/**
 *@ non-PWM Compare Output Mode 
 */


#define TIMER0_OC0_OUTPUT_MODES_MASK      			0b11001111

#define TIMER0_OC0_DISCONNECTED            			    (u8)0x00

#define TIMER0_OC0_TOGGLE                 			    (u8)0x10
#define TIMER0_OC0_CLEAR                  				(u8)0x20
#define TIMER0_OC0_SET                    				(u8)0x30

/**
 *@ Compare Output Mode, Fast PWM
 */

#define TIMER0_OC0_PWM_F_NON_INVERTING            			(u8)0x20
#define TIMER0_OC0_PWM_F_INVERTING	                  		(u8)0x30

/**
 *@ Compare Output Mode, Phase Correct and Phase and Frequency Correct PWM
 */

#define TIMER0_OC0_PWM_PC_NON_INVERTING     			(u8)0x20
#define TIMER0_OC0_PWM_PC_INVERTING    	    			(u8)0x30

/**
 *@  Clock Select (Prescaler select)
 */

#define TIMER0_CLK_SELCT_MASK                			0b11111000

#define TIMER0_NO_CLK                        			(u8)0x00
#define TIMER0_PRESCALER_DIV_1               			(u8)0x01
#define TIMER0_PRESCALER_DIV_8               			(u8)0x02
#define TIMER0_PRESCALER_DIV_64              			(u8)0x03
#define TIMER0_PRESCALER_DIV_256             			(u8)0x04
#define TIMER0_PRESCALER_DIV_1024            			(u8)0x05
#define TIMER0_EXT_CLK_FALLING_EDGE          			(u8)0x06
#define TIMER0_EXT_CLK_FALLING_RISING        			(u8)0x07


/*================================================ End timer 0 =====================================================*/


/*================================================ timer 1 =========================================================*/

/***************************************************************
 *		TCCR1A Timer/Counter1 Control Register A       *
 ***************************************************************/

/**
 *@ Waveform Generation Mode (Register TCCR1A pin0 , pin1 )
 */

#define TIMER1_OPERATION_MODE_MASK_A_REG          			0b11111100

#define TIMER1_MODE_NORMAL_AR            	  				0x00
#define TIMER1_MODE_PWM_PC_8BIT_AR            				0x01
#define TIMER1_MODE_PWM_PC_9BIT_AR            				0x02
#define TIMER1_MODE_PWM_PC_10BIT_AR           				0x03
#define TIMER1_MODE_CTC_OCR1A_AR              				0x00
#define TIMER1_MODE_PWM_F_8BIT_AR             				0x01
#define TIMER1_MODE_PWM_F_9BIT_AR             				0x02
#define TIMER1_MODE_PWM_F_10BIT_AR            				0x03
#define TIMER1_MODE_PWM_PC__FC_ICR1_AR        				0x00
#define TIMER1_MODE_PWM_PC__FC_OCR1A_AR       				0x01
#define TIMER1_MODE_PWM_PC_ICR1_AR            				0x02
#define TIMER1_MODE_PWM_PC_OCR1A_AR           				0x03
#define TIMER1_MODE_CTC_ICR1_AR               				0x00
#define TIMER1_MODE_PWM_F_ICR1_AR             				0x02
#define TIMER1_MODE_PWM_F_OCR1A_AR            				0x03





/**
 *@ to select the edge that Capture mode detect (Register TCCR1B pin6)
 */
#define CAPTURE_EDGE_DETECTION_FALLING 		 0
#define CAPTURE_EDGE_DETECTION_RISING  		 1




/**
 *@ Compare Output Mode, non-PWM Mode,Fast PWM Mode,Phase Correct PWM Mode 
 *@ (Register A : pin7,pin6 for channel A (OC1A))
 *@ (Register A : pin5,pin4 for channel B(OC1B))
 */

#define TIMER1_CHANNELA_OC1A_OUTPUT_MODES_MASK        	 0b00111111  
#define TIMER1_CHANNELB_OC1B_OUTPUT_MODES_MASK        	 0b11001111  
#define TIMER1_OC1_DISCONNECTED                      	 (u8)0x00    


/**
 *@ Compare Output Mode, non-PWM
 */
#define TIMER1_CTC_OC1A_TOGGLE                        	 (u8)0x40
#define TIMER1_CTC_OC1B_TOGGLE                        	 (u8)0x10
#define TIMER1_CTC_OC1A_CLEAR                         	 (u8)0x80
#define TIMER1_CTC_OC1B_CLEAR                         	 (u8)0x20
#define TIMER1_CTC_OC1A_SET                           	 (u8)0xC0
#define TIMER1_CTC_OC1B_SET                           	 (u8)0x30

/**
 *@ Compare Output Mode, Fast PWM
 */  
#define TIMER1_PWM_F__SPICHAL_TOGGLE                         (u8)0x01
#define TIMER1_PWM_F_OC1A_NONE_INVERTING                     (u8)0x80
#define TIMER1_PWM_F_OC1B_NONE_INVERTING                     (u8)0x20
#define TIMER1_PWM_F_OC1A_INVERTING                	         (u8)0xC0
#define TIMER1_PWM_F_OC1B_INVERTING                	         (u8)0x30
                                                        
/**
 *@ Compare Output Mode, Phase Correct and Phase and Frequency Correct PWM
 */
#define TIMER1_PWM_PC_SPICHAL_TOGGLE                 	  			(u8)0x01
#define TIMER1_PWM_PC_OC1A_NONE_INVERTING     						(u8)0x80
#define TIMER1_PWM_PC_OC1B_NONE_INVERTING     					    (u8)0x20
#define TIMER1_PWM_PC_OC1A_INVERTING    							(u8)0xC0
#define TIMER1_PWM_PC_OC1B_INVERTING    							(u8)0x30


/***************************************************************
 *	      TCCR1B Timer/Counter1 Control Register B         *
 ***************************************************************/



/**
 *@ Rest of bits to select Waveform Generation Mode (Register TCCR1B : pin3,pin4)
 */

#define TIMER1_OPERATION_MODE_MASK_B_REG         0b11100111
#define TIMER1_MODE_NORMAL_BR                	0x00      
#define TIMER1_MODE_PWM_PC_8BIT_BR           	0x00      
#define TIMER1_MODE_PWM_PC_9BIT_BR           	0x00      
#define TIMER1_MODE_PWM_PC_10BIT_BR          	0x00      
#define TIMER1_MODE_CTC_OCR1A_BR             	0x08      
#define TIMER1_MODE_PWM_F_8BIT_BR            	0x08      
#define TIMER1_MODE_PWM_F_9BIT_BR            	0x08      
#define TIMER1_MODE_PWM_F_10BIT_BR           	0x08      
#define TIMER1_MODE_PWM_PC__FC_ICR1_BR       	0x10      
#define TIMER1_MODE_PWM_PC__FC_OCR1A_BR      	0x10      
#define TIMER1_MODE_PWM_PC_ICR1_BR           	0x10      
#define TIMER1_MODE_PWM_PC_OCR1A_BR          	0x10      
#define TIMER1_MODE_CTC_ICR1_BR              	0x18      
#define TIMER1_MODE_PWM_F_ICR1_BR            	0x18      
#define TIMER1_MODE_PWM_F_OCR1A_BR           	0x18      


/**
 *@  Clock Select  (Register TCCR1B : pin2,pin1,pin0)
 */

#define TIMER1_CLK_SELCT_MASK                0b11111000
					                         
#define TIMER1_NO_CLK                        (u8)0x00 
#define TIMER1_PRESCALER_DIV_1               (u8)0x01 
#define TIMER1_PRESCALER_DIV_8               (u8)0x02 
#define TIMER1_PRESCALER_DIV_64              (u8)0x03 
#define TIMER1_PRESCALER_DIV_256             (u8)0x04 
#define TIMER1_PRESCALER_DIV_1024            (u8)0x05 
#define TIMER1_EXT_CLK_FALLING_EDGE          (u8)0x06 
#define TIMER1_EXT_CLK_FALLING_RISING        (u8)0x07 



/*================================================ End timer 1 ===========================================================*/


/*================================================ timer 2 =========================================================*/

/***************************************************************
 *		TCCR2_REG timer/Counter Control Register       *
 ***************************************************************/
/**
 *@ Waveform Generation Mode (Register TCCR2 pin6,pin3)
 */

#define TIMER2_OPERATION_MODE_MASK      						0b10110111
#define TIMER2_MODE_NORMAL             							0x00      
#define TIMER2_MODE_PWM_PC             							0x40      
#define TIMER2_MODE_CTC                							0x08      
#define TIMER2_MODE_PWM_F              							0x48      

/**
 *@ (Register TCCR2 pin5,pin4)
 *@ Compare Output Mode, non-PWM Mode,Fast PWM Mode , Phase Correct PWM Mode
 */

#define TIMER2_OC2_OUTPUT_MODES_MASK      						0b11001111
#define TIMER2_OC2_DISCONNECTED           						(u8)0x00
						
/**
 *@  Compare Output Mode, non-PWM
 */
#define TIMER2_OC2_TOGGLE_RES             						(u8)0x10
#define TIMER2_OC2_CLEAR                  						(u8)0x20	
#define TIMER2_OC2_SET                    						(u8)0x30

/**
 *@ Compare Output Mode, Fast PWM
 */

#define TIMER2_OC2_PWM_F_NON_INVERTING_MODE                     		(u8)0x20
#define TIMER2_OC2_PWM_F_INVERTING_MODE                         		(u8)0x30

/**
 *@ Compare Output Mode, Phase Correct and Phase and Frequency Correct PWM
 */

#define TIMER2_OC2_PWM_PC_NON_INVERTING_MODE   			 (u8)0x20
#define TIMER2_OC2_PWM_PC_INVERTING_MODE        			 (u8)0x30

/**
 *@  Clock Select ( Register TCCR2 pin2,pin1,PIN0)
 */

#define TIMER2_CLK_SELCT_MASK               		 0b11111000
     
#define TIMER2_NO_CLK                       		 (u8)0x00  
#define TIMER2_PRESCALER_DIV_1              		 (u8)0x01  
#define TIMER2_PRESCALER_DIV_8              		 (u8)0x02  
#define TIMER2_PRESCALER_DIV_32             		 (u8)0x03  
#define TIMER2_PRESCALER_DIV_64             		 (u8)0x04  
#define TIMER2_PRESCALER_DIV_128            		 (u8)0x05  
#define TIMER2_PRESCALER_DIV_256            		 (u8)0x06  
#define TIMER2_PRESCALER_DIV_1024           		 (u8)0x07  

/**
*@ ASYNCHRONUS ( COUNTER ) MODE
*/
#define SYNCHRONUS		0
#define ASYNCHRONUS		1



/*================================================ End timer 2 ===========================================================*/

#define BIT_0	0
#define BIT_1	1
#define BIT_2	2
#define BIT_3	3
#define BIT_4	4
#define BIT_5	5
#define BIT_6	6
#define BIT_7	7

/**
*@ TIMERS INTERUUPT HANDLER INDECIES IN VECTOR TABLE
*/
#define		TIMER0_OV_ISR			11
#define		TIMER0_CTC_ISR			10
#define		TIMER1_OV_ISR			9
#define		TIMER1_CTC_CHA_ISR		7
#define		TIMER1_CTC_CHB_ISR		8
#define		TIMER1_INP_CAP_ISR		6
#define		TIMER2_OV_ISR			5
#define		TIMER2_CTC_ISR			4
                                     
#endif