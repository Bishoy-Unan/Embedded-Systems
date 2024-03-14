/**********************************************************************************************************************
 * Author        : Bishoy Unan                                          
 * Version       : V0.0.0                                               
 * Date          : 11 Feb 2024                                           
 * Description   :  ATMega32 ADC Driver          
 * Module Features  :                                                   
 *                 01- ADC_enuInit(void);
 *                 02- ADC_enuStartConversionSynch(u8 Copy_u16ChaNum, u16 * Add_u16Result);            					    
 *                 03- ADC_enuStartConversionAsynch(ADC_strChannelChain_t * Add_strChain);    
 ************************************************************************************************************************/



#ifndef	ADC_PRIVATE_H
#define ADC_PRIVATE_H


#include "../../LIB/STD_TYPES.h"

/**
*@ Registers addresses
*/
#define ADMUX     *((volatile u8*)0x27)
#define ADCSRA    *((volatile u8*)0x26)
#define ADCH      *((volatile u8*)0x25)
#define ADCL      *((volatile u8*)0x24)
#define SFIOR     *((volatile u8*)0x50)
#define SREG	  *((volatile u8*)0x5F)

/**
*@ maskes
*/
#define 	REFERENCE_MASK						0b00111111
#define 	ADC_EXTERNAL_VOLTAGE_REFERENCE		0x00
#define 	ADC_AVCC_VOLTAGE_REFERENCE			0x40
#define		ADC_INTERNAL_VOLTAGE_REFERENCE		0xC0

#define     SINGLE_ENDED_CHANNELS_MAK			0b11100000
#define		ADC_CHANNEL0						0x00
#define		ADC_CHANNEL1						0x01
#define		ADC_CHANNEL2						0x02
#define		ADC_CHANNEL3						0x03
#define		ADC_CHANNEL4						0x04
#define		ADC_CHANNEL5						0x05
#define		ADC_CHANNEL6						0x06
#define		ADC_CHANNEL7						0x07

#define    ADC_PRESCALER_MASK					0b11111000
#define    ADC_PRESCALER_2						0x01
#define    ADC_PRESCALER_4						0x02
#define    ADC_PRESCALER_8						0x03
#define    ADC_PRESCALER_16						0x04
#define    ADC_PRESCALER_32						0x05
#define    ADC_PRESCALER_64						0x06
#define    ADC_PRESCALER_128					0x07

#define TRIGRRING_SOURCE_MASK					0b00011111
#define FREE_RUNNING_MODE						0x00
#define ANALOGE_COMPARATOR						0x20
#define EXTERNAL_INTERRUPT0						0x40
#define TIMER0_CTC								0x60
#define TIMER0_OVF								0x80
#define TIMER0_CHB_CTC							0xA0
#define TIMER1_OVF								0xC0
#define TIMER1_CAPTURE_EVENT					0xE0


#define ADLAR					5
#define ADATE					5

#define ADC_RIGHT_SHIFT			0
#define ADC_LEFT_SHIFT			1

#define ONE_TIME_CONVERSION 	0
#define AUTO_TRIGRRING	 		1

#define ADC_ON					0
#define ADC_OFF					1

#define ENABLE					0
#define DISABLE					1

#define ADEN					7
#define ADIE					3



/**        
*@ ADC interrupt number in vector table
*/
#define ADC_INT_NO		16
/*
*@ ADC ISR
*/
#define ISR(vect_no) void vect(vect_no)(void) __attribute__((signal));\
						void vect(vect_no) (void)
#define vect(x) __vector_##x



#endif