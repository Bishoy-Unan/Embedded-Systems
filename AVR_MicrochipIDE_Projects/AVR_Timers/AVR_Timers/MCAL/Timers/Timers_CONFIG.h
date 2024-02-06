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


#ifndef		TIMERS_CONFIGURATION_H
#define		TIMERS_CONFIGURATION_H


/**
*@ the building mode
*@ options : 
*@         1- PREBUILD_MODE
*@         2- POSTBUILD_MODE
*@
*@ NOTE : IF YOU CHOOSE PREBUILD_MODE YOU NEED CONFIGURE THE WHOLE CONFIGRATIO IN THIS FILE
*@ 		   AND USE ONLY THE INIT FUNCTIONS
*@		  IF POSTBUILD_MODE YOU DONT USE THE INIT FUNCTIONS ONLY THE OTHER FUNCTIONS
*/
#define BUILDING_MODE		POSTBUILD_MODE



/*============================= Timer0 =========================================*/

/********************************************
 *		Timer 0  Configurations       		*
 ********************************************/

/**
 *@ Timer0 Waveform Generation Mode
 *@
 *@ Options:
 *@ 	 1-  TIMER0_MODE_NORMAL
 *@ 	 2-  TIMER0_MODE_PWM_PC
 *@ 	 3-  TIMER0_MODE_CTC
 *@ 	 4-  TIMER0_MODE_PWM_F
 *@
 */
#define	TIMER0_OPERATION_MODE  TIMER0_MODE_NORMAL



/**
 *@ Hardware behavior OC0 pin
 *@ Compare Output Mode non-PWM Mode,Fast PWM Mode , Phase Correct PWM Mode
 *@
 *@ Options:
 *@   in case of normal mode
 *@		    1- TIMER0_OC0_DISCONNECTED
 *@
 *@   in case of Compare Output Mode, non-PWM
 *@    		
 *@			2.1-  TIMER0_OC0_TOGGLE
 *@    		2.2-  TIMER0_OC0_CLEAR
 *@         2.3-  TIMER0_OC0_SET
 *@
 *@
 *@  in case of Compare Output Mode, Fast PWM
 *@
 *@        3.1-  TIMER0_OC0_PWM_F_NON_INVERTING_MODE
 *@        3.2-  TIMER0_OC0_PWM_F_INVERTING_MODE
 *@
 *@
 *@  in case of Compare Output Mode, Phase Correct and Phase and Frequency Correct PWM
 *@
 *@
 *@        4.1-  TIMER0_OC0_PWM_PC_NON_INVERTING
 *@        4.2-  TIMER0_OC0_PWM_PC_INVERTING
 */


#define TIMER0_OUTPUT_MODE     TIMER0_OC0_DISCONNECTED


/**
 *@	Clock Selection (prescaler)      		
 *@ Options:
 *@   1-   TIMER0_NO_CLK
 *@   2-   TIMER0_PRESCALER_DIV_1
 *@   3-   TIMER0_PRESCALER_DIV_8
 *@   4-   TIMER0_PRESCALER_DIV_64
 *@   5-   TIMER0_PRESCALER_DIV_256
 *@   6-  TIMER0_PRESCALER_DIV_1024
 *@   7-   TIMER0_EXT_CLK_FALLING_EDGE
 *@   8-  TIMER0_EXT_CLK_FALLING_RISING
 */

#define TIMER0_CLK_SEL  TIMER0_PRESCALER_DIV_8



/**
 *@ TIMER0_OVF_INT and TIMER0_CTC_INT enable or disable modes
 *@ Options:
 * 		1-	ENABLE
 * 		2-  DISABLE
 */
#define TIMER0_OVF_INT              ENABLE
#define TIMER0_CTC_INT		        DISABLE


/*============================= End_Timer0 =========================================*/


/*============================= Timer 1 ============================================*/

/********************************************
 *		Timer 1  Configurations       		*
 ********************************************/


/**
 *@ Timer1 Waveform Generation Mode
 *@
 *@ Options:
 *@
 *@ 	1-    TIMER1_MODE_NORMAL
 *@ 	2-    TIMER1_MODE_PWM_PC_8BIT
 *@ 	3-    TIMER1_MODE_PWM_PC_9BIT
 *@ 	4-    TIMER1_MODE_PWM_PC_10BIT
 *@    	5-	  TIMER1_MODE_CTC_OCR1A
 *@    	6-	  TIMER1_MODE_PWM_F_8BIT
 *@    	7-	  TIMER1_MODE_PWM_F_9BIT
 *@    	8-	  TIMER1_MODE_PWM_F_10BIT
 *@    	9-	  TIMER1_MODE_PWM_PC__FC_ICR1
 *@    	10-	  TIMER1_MODE_PWM_PC__FC_OCR1A
 *@    	11-	  TIMER1_MODE_PWM_PC_ICR1
 *@    	12-	  TIMER1_MODE_PWM_PC_OCR1A
 *@    	13-	  TIMER1_MODE_CTC_ICR1
 *@    	14-	  TIMER1_MODE_PWM_F_ICR1
 *@    	15	  TIMER1_MODE_PWM_F_OCR1A
 *@
 */
#define	TIMER1_OPERATION_MODE  TIMER1_MODE_NORMAL

/**
 *@ Input Capture Edge Select
 *@
 *@ Options:
 *@ 	1-	CAPTURE_EDGE_DETECTION_FALLING
 *@ 	2-	CAPTURE_EDGE_DETECTION_RISING
 */

#define INPUT_CAPTURE_EDGE   CAPTURE_EDGE_DETECTION_RISING

/**
 *@  Hardware behavior OC1 pin
 *@ Compare Output Mode, non-PWM Mode,Fast PWM Mode , Phase Correct PWM Mode
 *@
 *@ Options:
 *@
 *@     1.1-     TIMER1_OC1A_DISCONNECTED  
 *@     1.2-     TIMER1_OC1B_DISCONNECTED  
 *@
 *@ in case of Compare Output Mode, non-PWM
 *@      
 *@    CHANNEL A:  
 *@	   2.1   TIMER1_OC1A_DISCONNECTED
 *@    2.2    TOGGLE_OC1A_ON_COMPARE_MATCH
 *@    2.3    CLEAR_OC1A_ON_COMPARE_MATCH
 *@    2.4    SET_OC1A_ON_COMPARE_MATCH
 *@
 *@		HANNEL B:
 *@	   2.1   TIMER1_OC1B_DISCONNECTED
 *@    2.2    TOGGLE_OC1B_ON_COMPARE_MATCH
 *@    2.3    CLEAR_OC1B_ON_COMPARE_MATCH
 *@    2.4    SET_OC1B_ON_COMPARE_MATCH
 *@
 *@ Compare Output Mode, Fast PWM
 *@ 
 *@ 
 *@		CHANNEL A:
 *@	   3.1   TIMER1_OC1A_DISCONNECTED
 *@    3.2   TIMER1_PWM_PC_TOGGLE_OC1A_ON_COM_MATCH 
 *@    3.3   TIMER1_PWM_F_OC1A_NON_INVERTING
 *@    3.4   TIMER1_PWM_F_OC1A_INVERTING
 *@
 *@		CHANNEL B:
 *@	   3.1   TIMER1_OC1B_DISCONNECTED
 *@    3.2   TIMER1_PWM_PC_OC1B_DISCONNECTED 
 *@    3.3   TIMER1_PWM_F_OC1B_NON_INVERTING
 *@    3.4   TIMER1_PWM_F_OC1B_INVERTING
 *@
 *@
 *@ in case of Compare Output Mode, Phase Correct and Phase and Frequency Correct PWM
 *@ 
 *@   	 CHANNEL A:
 *@		 4.1   TIMER1_OC1A_DISCONNECTED
 *@      4.2   TIMER1_PWM_PC_TOGGLE_OC1A_ON_COM_MATCH 
 *@      4.3   TIMER1_PWM_PC_OC1A_NON_INVERTING
 *@      4.4   TIMER1_PWM_PC_OC1A_INVERTING
 *@
 *@		  CHANNEL B:
 *@		 4.1   TIMER1_OC1B_DISCONNECTED
 *@      4.2   TIMER1_PWM_PC_OC1B_DISCONNECTED 
 *@      4.3   TIMER1_PWM_PC_OC1B_NON_INVERTING
 *@      4.4   TIMER1_PWM_PC_OC1B_INVERTING
 */
 
 
#define TIMER1_OUTPUT_CHANNELA_HW_MODE     TIMER1_OC1A_DISCONNECTED

#define TIMER1_OUTPUT_CHANNELB_HW_MODE     TIMER1_OC1B_DISCONNECTED


/**
 *@ Clock Selection (prescaler)
 *@ Options:
 *@
 *@    1-  TIMER1_NO_CLK
 *@    2-  TIMER1_PRESCALER_DIV_1
 *@    3-  TIMER1_PRESCALER_DIV_8
 *@    4-  TIMER1_PRESCALER_DIV_64
 *@    5-  TIMER1_PRESCALER_DIV_256
 *@    6-  TIMER1_PRESCALER_DIV_1024
 *@    7-  TIMER1_EXT_CLK_FALLING_EDGE
 *@    8-  TIMER1_EXT_CLK_FALLING_RISING
 */

#define TIMER1_CLK_SEL  TIMER1_PRESCALER_DIV_8




/**
 *@ Timer1 Interrups Enable and Disable
 *@
 *@ Options:
 *@ 		 1-   ENABLE
 *@ 		 2-   DISABLE
 */


#define TIMER1_OVF_INT                  ENABLE
#define TIMER1_CTC_CHANNELA_INT		    DISABLE
#define TIMER1_CTC_CHANNELB_INT		    DISABLE
#define TIMER1_CAPTURE_INT		        DISABLE



/*=================================== End_Timer1 ==========================================*/


/*==================================== Timer 2 ============================================*/

/********************************************
 *		Timer 2  Configurations       		*
 ********************************************/


/**
 *@ Timer/COUNTER OPERATION MODE
 *@ it may operate as timer(synchronus) or as counter (asynchronus)
 *@
 *@ Options:
 *@
 *@ 	1-   SYNCHRONUS
 *@ 	2-   ASYNCHRONUS
 *@
 */
#define	TIMER_COUNTER_2_OPERATION_MODE  SYNCHRONUS

/**
 *@ Timer2 Waveform Generation Mode
 *@
 *@ Options:
 *@
 *@ 	1-   TIMER2_MODE_NORMAL
 *@ 	2-   TIMER2_MODE_PWM_PC
 *@ 	3-   TIMER2_MODE_CTC
 *@ 	4-   TIMER2_MODE_PWM_F
 *@
 */
#define	TIMER2_OPERATION_MODE  TIMER2_MODE_NORMAL



/**
 *@  Hardware behavior OC2 pin
 *@ Compare Output Mode, non-PWM Mode,Fast PWM Mode , Phase Correct PWM Mode
 *@
 *@ Options:
 *@    		1- TIMER2_OC2_DISCONNECTED
 *@
 *@
 *@  in case of Compare Output Mode, non-PWM
 *@
 *@         2.1- TIMER2_OC2_TOGGLE
 *@     	2.2- TIMER2_OC2_CLEAR
 *@     	2.3- TIMER2_OC2_SET
 *@
 *@
 *@  in case of Compare Output Mode, Fast PWM
 *@
 *@
 *@        3.1-  TIMER0_OC2_PWM_F_NON_INVERTING
 *@        3.2-  TIMER0_OC2_PWM_F_INVERTING
 *@
 *@
 *@  in case of Compare Output Mode, Phase Correct and Phase and Frequency Correct PWM
 *@
 *@
 *@     	4.1- TIMER0_OC2_PWM_PC_NON_INVERTING
 *@     	4.2- TIMER0_OC2_PWM_PC_INVERTING
 */


#define TIMER2_OUTPUT_MODE     TIMER2_OC2_DISCONNECTED

/**
 *@  Clock Selection(prescaler)
 *@
 *@ Options:
 *@    	  1- 	 TIMER2_NO_CLK
 *@    	  2- 	 TIMER2_PRESCALER_DIV_1
 *@    	  3- 	 TIMER2_PRESCALER_DIV_8
 *@		  4- 	 TIMER2_PRESCALER_DIV_32	
 *@    	  5-	 TIMER2_PRESCALER_DIV_64
 *@    	  6-	 TIMER2_PRESCALER_DIV_128
 *@    	  7-	 TIMER2_PRESCALER_DIV_256
 *@    	  8-	 TIMER2_PRESCALER_DIV_1024
 *@    	  
 *@    	  
 */

#define TIMER2_CLK_SEL  TIMER2_PRESCALER_DIV_8




/**
 *@ Timer2 Interrupts Enable and Disable
 *@ 
 *@ Options:
 * 		1-   ENABLE
 * 		2-   DISABLE
 */
#define TIMER2_OVF_INT          DISABLE
#define TIMER2_CTC_INT		    DISABLE


/*================================End_Timer 2=================================*/


#endif
