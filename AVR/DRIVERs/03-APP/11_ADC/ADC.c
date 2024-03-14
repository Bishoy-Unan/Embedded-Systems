/**********************************************************************************************************************
* Author        : Bishoy Unan                                          
* Version       : V0.0.0                                               
* Date          : 11 Feb 2024                                           
* Description   :  ATMega32 ADC Driver          
* Module Features  :                                                   
*                 01- ADC_enuInit(void);
*                 02- ADC_enuStartConversionSynch(u8 Copy_u16ChaNum, u16 * Add_u16Result);            					    
*                 03- ADC_enuStartConversionAsynch(ADC_strChannelChain_t Add_strChain);    
************************************************************************************************************************/




#include "../../LIB/STD_TYPES.h"
#include "ADC_Interface.h"
#include "ADC_CFG.h"
#include "ADC_Private.h"


typedef enum
{
	BUZY,
	IDLE
}ADC_enuStateFlow_t;

static ADC_strChannelChain_t ADC_strGlobalChain;

static ADC_enuStateFlow_t ADC_u8BusyState = IDLE;

static u8 Adc_u8IndexConversion = 0;


ADC_enuErrorStatus_t ADC_enuInit(void)
{
	/**
	*@
	*/
	ADC_enuErrorStatus_t Ret_enuErrorStatus = ADC_enuOK  ;
	
	u8 Local_u8TempReg ;
	
	
	/**
	*@ set voltage reference 
	*/	
	Local_u8TempReg = ADMUX ;
	Local_u8TempReg &= REFERENCE_MASK ;
	#if 	(ADC_REFERENCE_VOLTAGE == ADC_EXTERNAL_VOLTAGE_REFERENCE)
						Local_u8TempReg |= ADC_EXTERNAL_VOLTAGE_REFERENCE ;
	#elif	(ADC_REFERENCE_VOLTAGE == ADC_AVCC_VOLTAGE_REFERENCE)
						Local_u8TempReg |= ADC_AVCC_VOLTAGE_REFERENCE ;
	#elif	(ADC_REFERENCE_VOLTAGE == ADC_INTERNAL_VOLTAGE_REFERENCE)
						Local_u8TempReg |= ADC_INTERNAL_VOLTAGE_REFERENCE ;
	#else	
		Ret_enuErrorStatus = ADC_enuNOK  ;
	#endif	
	ADMUX = Local_u8TempReg  ;
	
	
	/**
	*@ configure adjacement mode
	*/
	#if  (ADC_ADLAR == ADC_RIGHT_SHIFT)
				ADMUX &= ~(1 << ADLAR);
	#elif  (ADC_ADLAR == ADC_LEFT_SHIFT)
				ADMUX |=  (1 << ADLAR);
	#else
		Ret_enuErrorStatus = ADC_enuNOK ;
	#endif
	
	
	/**
	*@ configure Triggring  mode
	*/
	#if  (TRIGGRING_MODE == ONE_TIME_CONVERSION)
				ADCSRA &= ~(1 << ADATE);
	#elif  (TRIGGRING_MODE == AUTO_TRIGRRING)
				ADCSRA |=  (1 << ADATE);
	#else
		Ret_enuErrorStatus = ADC_enuNOK ;
	#endif
	
	/**
	*@ configure the trigrring source if the trigrring mode is auto
	*/	
	#if (TRIGGRING_MODE == AUTO_TRIGRRING)
			
			Local_u8TempReg = SFIOR ;
			Local_u8TempReg &= TRIGRRING_SOURCE_MASK ;
			#if 	(AUTO_TRIGRRING_SOURCE == FREE_RUNNING_MODE)
								Local_u8TempReg |= FREE_RUNNING_MODE ;
			#elif	(AUTO_TRIGRRING_SOURCE == ANALOGE_COMPARATOR)
								Local_u8TempReg |= ANALOGE_COMPARATOR ;
			#elif	(AUTO_TRIGRRING_SOURCE == EXTERNAL_INTERRUPT0)
								Local_u8TempReg |= EXTERNAL_INTERRUPT0 ;
			#elif	(AUTO_TRIGRRING_SOURCE == TIMER0_CTC)
								Local_u8TempReg |= TIMER0_CTC ;
			#elif	(AUTO_TRIGRRING_SOURCE == TIMER0_OVF)
								Local_u8TempReg |= TIMER0_OVF ;	
			#elif	(AUTO_TRIGRRING_SOURCE == TIMER0_CHB_CTC)
								Local_u8TempReg |= TIMER0_CHB_CTC ;
			#elif	(AUTO_TRIGRRING_SOURCE == TIMER1_OVF)
								Local_u8TempReg |= TIMER1_OVF ;	
			#elif	(AUTO_TRIGRRING_SOURCE == TIMER1_CAPTURE_EVENT)
								Local_u8TempReg |= TIMER1_CAPTURE_EVENT ;						
			#else	
				Ret_enuErrorStatus = ADC_enuNOK  ;
			#endif	
			SFIOR = Local_u8TempReg  ;
	#endif
	
	/**
	*@ configure ADC interrupt Enabling  mode
	*/
	#if  (INTERRUPT_ENABLE == ENABLE)
				ADCSRA |= (1 << ADIE) ;
	#elif  (INTERRUPT_ENABLE == DISABLE)
				ADCSRA &= ~(1 << ADIE);
	#else
		Ret_enuErrorStatus = ADC_enuNOK  ;
	#endif
	/**
	*@ enable global interrupt
	*/
	SREG |= (1<<7);
	
	
	/**
	*@ Configure ADC Prescaler 
	*/	
	Local_u8TempReg = ADCSRA ;
	Local_u8TempReg &= ADC_PRESCALER_MASK ;
	#if 	(ADC_PRESCALER == ADC_PRESCALER_2)
						Local_u8TempReg |= ADC_PRESCALER_2 ;
	#elif	(ADC_PRESCALER == ADC_PRESCALER_4)
						Local_u8TempReg |= ADC_PRESCALER_4 ;
	#elif	(ADC_PRESCALER == ADC_PRESCALER_8)
						Local_u8TempReg |= ADC_PRESCALER_8 ;
	#elif	(ADC_PRESCALER == ADC_PRESCALER_16)
						Local_u8TempReg |= ADC_PRESCALER_16 ;
	#elif	(ADC_PRESCALER == ADC_PRESCALER_32)
						Local_u8TempReg |= ADC_PRESCALER_32 ;	
	#elif	(ADC_PRESCALER == ADC_PRESCALER_64)
						Local_u8TempReg |= ADC_PRESCALER_64 ;
	#elif	(ADC_PRESCALER == ADC_PRESCALER_128)
						Local_u8TempReg |= ADC_PRESCALER_128 ;				
	#else	
		Ret_enuErrorStatus = ADC_enuNOK  ;
	#endif	
	ADCSRA = Local_u8TempReg  ;
	
	/**
	*@ configure ADC state  mode
	*/
	#if  (ADC_STATUS == ADC_ON)
				ADCSRA |= (1 << ADEN) ;
	#elif  (ADC_STATUS == ADC_OFF)
				ADCSRA &= ~(1 << ADEN);
	#else
		Ret_enuErrorStatus = ADC_enuNOK  ;
	#endif
	
	
return 	Ret_enuErrorStatus ;
}/*ADC_enuInit*/



ADC_enuErrorStatus_t ADC_enuStartConversionSynch(u8 Copy_u16ChaNum, u16 * Add_u16Result)
{
	u8 Loc_u8TempReg = 0;
	u16 Loc_u16TimeOut = 0; 
	
	ADC_enuErrorStatus_t Ret_enuErrorStatus = ADC_enuOK;
	/**
	*@ check single ended channel or not within the range
	*/
	if (Copy_u16ChaNum < 0 || Copy_u16ChaNum > 7)
	{
		Ret_enuErrorStatus = ADC_enuNOK;
	}
	else if(Add_u16Result == NULL)
	{
			Ret_enuErrorStatus = ADC_enuNOK;
	}
	else
	{
		Loc_u8TempReg = ADMUX;	
		Loc_u8TempReg &= SINGLE_ENDED_CHANNELS_MAK;		
		Loc_u8TempReg |= Copy_u16ChaNum;
		ADMUX = Loc_u8TempReg;

		
		#if  (TRIGGRING_MODE == ONE_TIME_CONVERSION) 
		/**
		*@ Start Conversion
		*/
		ADCSRA |= (1<<6) ; 
		#endif
		
		/**
		*@ polling End conversion Interrupt Flag
		*/
		while(((ADCSRA & (1<<4))==0)  &&  Loc_u16TimeOut < 10000)
		{
			Loc_u16TimeOut ++ ;
		}			
		if(Loc_u16TimeOut == 10000)
		{
			Ret_enuErrorStatus = ADC_enuNOK;
		}
		
		
		
		
		#if ADC_u8ADLAR == ADC_RIGHT_SHIFT
		
				*Add_u16Result = (ADCL) | (ADCH << 8);
		
		#elif ADC_ADLAR == ADC_LEFT_SHIFT
		
				*Add_u16Result = (ADCL >> 8) | (ADCH << 2);
		
		#endif
		/**
		*@ clear End conversion Interrupt Flag
		*/
		ADCSRA |= (1<<4);
	

	}

return Ret_enuErrorStatus;
}




ADC_enuErrorStatus_t ADC_enuStartConversionAsynch(ADC_strChannelChain_t * Add_strChain)
{
	ADC_enuErrorStatus_t Ret_enuErrorStatus = ADC_enuOK;
	
	u8 Loc_u8TempReg;

	/*check pointer to null*/
	if(Add_strChain == NULL)
	{
		Ret_enuErrorStatus = ADC_enuNOK;
	}
	else
	{
		/**
		*@ state flow to avoid sending more than one chain at a time
		*/
		if(ADC_u8BusyState == IDLE)
		{
			ADC_u8BusyState = BUZY;

			

			Adc_u8IndexConversion = 0;
			
			
			ADC_strGlobalChain.ADC_u8Length    = Add_strChain->ADC_u8Length;
			ADC_strGlobalChain.ADC_AddChannels = Add_strChain->ADC_AddChannels;
			ADC_strGlobalChain.ADC_AddResult   = Add_strChain->ADC_AddResult;
			ADC_strGlobalChain.EndOfJob        = Add_strChain->EndOfJob;

			
			/**
			*@ select which channel to start from the 8 single ended channels according to ADC_strChannelChain_t \
			*@ configration in main function
			*/
			Loc_u8TempReg = ADMUX;
			Loc_u8TempReg &= SINGLE_ENDED_CHANNELS_MAK;
			Loc_u8TempReg |= ADC_strGlobalChain.ADC_AddChannels[0];
			ADMUX = Loc_u8TempReg;

			/**
			*@ Start Conversion
			*/
			ADCSRA |= (1<<6) ; 

		}

		else
		{
			ADC_u8BusyState = BUZY;
		}
	}

	
return Ret_enuErrorStatus;	
}/*ADC_enuStartConversion*/



ISR(ADC_INT_NO)
{
	
	u8 Loc_u8TempReg = 0;
	/**
	*@ Reade the result of conversion
	*/
	#if ADC_u8ADLAR == ADC_RIGHT_SHIFT
				ADC_strGlobalChain.ADC_AddResult[Adc_u8IndexConversion] = (ADCL) | (ADCH << 8);
	#elif ADC_ADLAR == ADC_LEFT_SHIFT	
				ADC_strGlobalChain.ADC_AddResult[Adc_u8IndexConversion] = (ADCL >> 8) | (ADCH << 2);
	#endif
	/**
	*@ configure next channel
	*/
	if(Adc_u8IndexConversion < ADC_strGlobalChain.ADC_u8Length)
	{
		Adc_u8IndexConversion ++ ;
		/**
		*@ select next channel
		*/
		Loc_u8TempReg = ADMUX;
		Loc_u8TempReg &= SINGLE_ENDED_CHANNELS_MAK;
		Loc_u8TempReg |= ADC_strGlobalChain.ADC_AddChannels[Adc_u8IndexConversion];
		ADMUX = Loc_u8TempReg;
		
		/**
		*@ Start Conversion
		*/
		ADCSRA |= (1<<6) ;
		
		
	}
	else
	{
		Adc_u8IndexConversion = 0 ;
		
		ADC_strGlobalChain.EndOfJob();
		
		ADC_u8BusyState = IDLE ;
		
	}
}