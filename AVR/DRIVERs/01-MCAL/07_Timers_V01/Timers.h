
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



#ifndef		TIMERS_H
#define		TIMERS_H

#include "../../LIB/STD_TYPES.h"

typedef enum
{
	Timers_enuOK ,
	Timers_enuNOK 
}Timers_ErrorSTATUS_t;



/**
*@bief : Timer0_enumInit function to set configration of timer0(prebuild configration)
*@inp: NOTHIGN
*@ret: ERROR STATUS
*/
//Timers_ErrorSTATUS_t Timer0_enumInit(void);
/**
*@bief : Timer1_enumInit function to set configration of timer0(prebuild configration)
*@inp: NOTHIGN
*@ret: ERROR STATUS
*/
//Timers_ErrorSTATUS_t Timer1_enumInit(void);
/**
*@bief : Timer2_enumInit function to set configration of timer0(prebuild configration)
*@inp: NOTHIGN
*@ret: ERROR STATUS
*/
//Timers_ErrorSTATUS_t Timer2_enumInit(void);

/**
*@ breif : function to set the interval in timer0 over flow mode
*@ param : the interval value it must be in micro seconds 
*@ return: error status
*@ this function to work the mode in configration file must be normal mode
*@ THE MAXIMUM INPUT THE FUNCTION CAN TAKE IS u32
*/
Timers_ErrorSTATUS_t Timer0_enumSetTimer_OV(u32 Copy_u32Interval );

/**
*@ breif : function to set the interval in timer0 compare match mode
*@ param : the interval value it must be in micro seconds 
*@ return: error status
*@ this function to work the mode in configration file must be CTC mode
*@ you can configure the prescaler according the value you want in the configration file
*/
Timers_ErrorSTATUS_t Timer0_enumSetTimer_CTC(u8 Copy_u32Interval );

/**
*@ breif : function to set the interval in timer0 FAST PWM mode
*@ param : The duty cyle in percentage value 
*@ return: error status
*@ this function to work the mode in configration file must be FAST PWM mode
*@ this function works with prescaler equal 8 only and TIMER0_OC0_PWM_F_NON_INVERTING_MODE
*/
Timers_ErrorSTATUS_t Timer0_enumSetTimer_PWM_F(u8 Copy_u32DutyCycle );

/**
*@ breif : function to set the interval in timer0 PHASE CORRECT PWM mode
*@ param : The duty cyle in percentage value 
*@ return: error status
*@ this function to work the mode in configration file must be PHASE CORRECT PWM mode
*@ this function works with prescaler equal 8 only and TIMER0_OC0_PWM_PC_NON_INVERTING_MODE
*/
Timers_ErrorSTATUS_t Timer0_enumSetTimer_PWM_PC(u8 Copy_u32DutyCycle );
/**
*@ breif : function to set the interval in timer1 over flow mode
*@ param : the interval value it must be in micro seconds 
*@ return: error status
*@ this function to work the mode in configration file must be normal mode to gurantee HW behavior
*@ THE MAXIMUM INPUT THE FUNCTION CAN TAKE IS u32
*/
Timers_ErrorSTATUS_t Timer1_enumSetTimer_OV(u32 Copy_u32Interval );
/**
*@ breif : function to set the interval in timer1 CTC mode
*@ param : the interval value it must be in micro seconds 
*@ return: error status
*@ this function to work the mode in configration file must be normal mode to gurantee HW behavior
*@ THE MAXIMUM INPUT THE FUNCTION CAN TAKE IS u32
*/
Timers_ErrorSTATUS_t Timer1_enumSetTimer__CTC_CHA(u16 Copy_u32Interval );

/**
*@ breif : function to set the interval in timer1 CTC mode
*@ param : the interval value it must be in micro seconds 
*@ return: error status
*@ this function to work the mode in configration file must be normal mode to gurantee HW behavior
*@ THE MAXIMUM INPUT THE FUNCTION CAN TAKE IS u32
*/
Timers_ErrorSTATUS_t Timer1_enumSetTimer__CTC_CHB(u16 Copy_u32Interval );

/**
*@ breif : function to set the interval in timer1 FAST PWM mode
*@ param : The duty cyle in percentage value 
*@ return: error status
*@ this function to work the mode in configration file must be FAST PWM mode To gurantee HW behavior
*@ this function works with prescaler equal 8 only and TIMER1_OC1_PWM_F_NON_INVERTING_MODE
*/
Timers_ErrorSTATUS_t Timer1_enumSetTimer_PWM_F(u16 Copy_u32DutyCycle );	
/**
*@ breif : function to set the interval in timer1 PHASE CORRECT PWM mode
*@ param : The duty cyle in percentage value 
*@ return: error status
*@ this function to work the mode in configration file must be PHASE CORRECT PWM mode
*@ this function works with prescaler equal 8 only and TIMER1_OC1_PWM_PC_NON_INVERTING_MODE
*/
Timers_ErrorSTATUS_t Timer1_enumSetTimer_PWM_PC(u16 Copy_u32DutyCycle );
/**
*@ breif : function to set the interval in timer1 INPUT CAPTURE mode
*@ param : The duty cyle in percentage value 
*@ return: error status
*@ this function to work the mode in configration file must be PHASE CORRECT PWM mode
*@ this function works with prescaler equal 8 only and TIMER1_OC1_PWM_PC_NON_INVERTING_MODE
*/
Timers_ErrorSTATUS_t Timer1_enumSetTimer_IC(u16 Copy_u32DutyCycle );


/**
*@ breif : function to set the interval in timer2 over flow mode
*@ param : the interval value it must be in micro seconds 
*@ return: error status
*@ this function to work the mode in configration file must be normal mode to gurantee HW behavior
*@ THE MAXIMUM INPUT THE FUNCTION CAN TAKE IS u32
*/
Timers_ErrorSTATUS_t Timer2_enumSetTimer_OV(u32 Copy_u32Interval );
	
/**
*@ breif : function to set the interval in timer2 compare match mode
*@ param : the interval value it must be in micro seconds 
*@ return: error status
*@ this function to work the mode in configration file must be CTC mode to gurantee HW behavior
*@ you can configure the prescaler according the value you want in the configration file
*/
Timers_ErrorSTATUS_t Timer2_enumSetTimer_CTC(u8 Copy_u32Interval );

/**
*@ breif : function to set the interval in timer2 FAST PWM mode
*@ param : The duty cyle in percentage value 
*@ return: error status
*@ this function to work the mode in configration file must be FAST PWM mode To gurantee HW behavior
*@ this function works with prescaler equal 8 only and TIMER0_OC0_PWM_F_NON_INVERTING_MODE
*/
Timers_ErrorSTATUS_t Timer2_enumSetTimer_PWM_F(u8 Copy_u32DutyCycle );	

/**
*@ breif : function to set the interval in timer2 PHASE CORRECT PWM mode
*@ param : The duty cyle in percentage value 
*@ return: error status
*@ this function to work the mode in configration file must be PHASE CORRECT PWM mode
*@ this function works with prescaler equal 8 only and TIMER0_OC0_PWM_PC_NON_INVERTING_MODE
*/
Timers_ErrorSTATUS_t Timer2_enumSetTimer_PWM_PC(u8 Copy_u32DutyCycle );

/**
*@ function take pointer to function as input from application 
*@ and assign this variable Timer0_AddOVF_CallBack which used in OVER FLOW ISR 
*/
Timers_ErrorSTATUS_t TIMER0_enuSetOVFINT(void(*ptr)(void));
/**
*@ function take pointer to function as input from application 
*@ and assign this variable Timer0_AddCTC_CallBack which used in CTC ISR 
*/
Timers_ErrorSTATUS_t TIMER0_enuSetCTCINT(void(*ptr)(void));
/**
*@ function take pointer to function as input from application 
*@ and assign this variable Timer1_AddOVF_CallBack which used in OVER FLOW ISR 
*/
Timers_ErrorSTATUS_t TIMER1_enuSetOVFINT(void(*ptr)(void));
/**
*@ function take pointer to function as input from application 
*@ and assign this variable Timer1_AddCTC_CHA_CallBack which used in CTC CHANNEL A ISR 
*/
Timers_ErrorSTATUS_t TIMER1_enuSetCTC_CHA_INT(void(*ptr)(void));
/**
*@ function take pointer to function as input from application 
*@ and assign this variable Timer1_AddCTC_CHB_CallBack which used in CTC CHANNEL B ISR 
*/
Timers_ErrorSTATUS_t TIMER1_enuSetCTC_CHB_INT(void(*ptr)(void));
/**
*@ function take pointer to function as input from application 
*@ and assign this variable Timer1_Add_INP_CAP_CallBack which used in INPUT CAPTURE ISR 
*/
Timers_ErrorSTATUS_t TIMER1_enuSetINP_CAP_INT(void(*ptr)(void));
/**
*@ function take pointer to function as input from application 
*@ and assign this variable Timer2_AddOVF_CallBack which used in OVER FLOW ISR 
*/
Timers_ErrorSTATUS_t TIMER2_enuSetOVFINT(void(*ptr)(void));
/**
*@ function take pointer to function as input from application 
*@ and assign this variable Timer2_AddCTC_CallBack which used in CTC ISR 
*/
Timers_ErrorSTATUS_t TIMER2_enuSetCTCINT(void(*ptr)(void));


#endif