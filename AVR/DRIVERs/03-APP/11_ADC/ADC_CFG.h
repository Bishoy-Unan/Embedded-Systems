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


#ifndef ADC_CFG_H
#define ADC_CFG_H



/**
 *@ Rference voltage used in ADC
 *@ options :
 *@ 		1-	ADC_EXTERNAL_VOLTAGE_REFERENCE
 *@ 		2-	ADC_AVCC_VOLTAGE_REFERENCE
 *@ 		3-	ADC_INTERNAL_VOLTAGE_REFERENCE
 */
 
#define ADC_REFERENCE_VOLTAGE		ADC_AVCC_VOLTAGE_REFERENCE


/**
 *@ ADC Adjacement mode
 *@ Options :
 *@ 	  1-	ADC_RIGHT_SHIFT
 *@ 	  2-	ADC_LEFT_SHIFT
 */
#define ADC_ADLAR					ADC_RIGHT_SHIFT



/**
 *@ ADC Prescaler
 *@ options :
 *@ 		1-	ADC_PRESCALER_2
 *@ 		2-	ADC_PRESCALER_4
 *@ 		3-	ADC_PRESCALER_8
 *@ 		4-	ADC_PRESCALER_16
 *@ 		5-	ADC_PRESCALER_32
 *@ 		6-	ADC_PRESCALER_64
 *@ 		7-	ADC_PRESCALER_128
 */
#define ADC_PRESCALER				ADC_PRESCALER_2

/**
*@ Trigring times mode
*@ Options:
*@ 			1- ONE_TIME_CONVERSION 	 
*@ 			2- AUTO_TRIGRRING	 
*/
#define TRIGGRING_MODE		ONE_TIME_CONVERSION
/**
*@ configure the trigrring source if the trigrring mode is auto
*@ OPTIONS :
*@			1-  FREE_RUNNING_MODE	
*@			2-  ANALOGE_COMPARATOR	
*@			3-  EXTERNAL_INTERRUPT0	
*@			4-  TIMER0_CTC			
*@			5-  TIMER0_OVF			
*@			6-  TIMER0_CHB_CTC		
*@			7-  TIMER1_OVF			
*@			8-  TIMER1_CAPTURE_EVENT
*/
#define AUTO_TRIGRRING_SOURCE	EXTERNAL_INTERRUPT0
/**
*@ ADC Interrupt Enable
*@  Options :
*@			1- ENABLE
*@			2- DISABLE
*/
#define INTERRUPT_ENABLE		ENABLE
/**
*@ configure ADC Prescaler
*@	Options :
*@			1-  ADC_PRESCALER_2	
*@			2-  ADC_PRESCALER_4	
*@			3-  ADC_PRESCALER_8	
*@			4-  ADC_PRESCALER_16	
*@			5-  ADC_PRESCALER_32	
*@			6-  ADC_PRESCALER_64	
*@          7-  ADC_PRESCALER_128
*/
#define ADC_PRESCALER	ADC_PRESCALER_2



/**
 *@ 1-	ADC_ON
 *@ 2-	ADC_OFF
 */
#define ADC_STATUS					ADC_ON


#endif 

/* ADC_CFG_H_ */
