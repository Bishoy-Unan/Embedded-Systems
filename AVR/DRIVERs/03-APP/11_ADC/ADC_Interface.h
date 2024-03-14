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



#ifndef	ADC_INTERFACE_H
#define ADC_INTERFACE_H

#include "../../LIB/STD_TYPES.h"



/**
*@ ADC Error Status
*/
typedef enum
{
	ADC_enuOK ,
	ADC_enuNOK
	
}ADC_enuErrorStatus_t;
/**
*@ new variable to be used in Asynchronous Mode
*/
typedef struct
{
	/**
	*@ number of channels
	*/
	u8 ADC_u8Length ;
	/**
	*@ array to select which channel
	*/
	u8 * ADC_AddChannels ;
	/**
	*@ array to get conversion result for each channel
	*/
	u8 * ADC_AddResult ;
	/**
	*@ end of job function (Asynchronous Function)
	*/
	void (*EndOfJob)(void);
	
}ADC_strChannelChain_t;

/***********************************************************************************************************
 *                                      01- ADC_enuInit                    		                           *
 *---------------------------------------------------------------------------------------------------------*
 * @description -> Cntrol ADC periphral according to configration in ADC_CFG.h file                        *
 * @param       -> void 										                                           *
 * @return      -> Error Status                                                                            *
 ***********************************************************************************************************/
ADC_enuErrorStatus_t ADC_enuInit(void);

/***********************************************************************************************************
 *                                      02- ADC_enuStartConversionSynch                                    *
 *---------------------------------------------------------------------------------------------------------*
 * @description -> Synchronouse Function to start conversion at only one channel at atime                  *
 * @param       -> channel number(it must be in range 0:7),pointer in which return the result of conversion*
 * @return      -> Error Status                                                                            *
 ***********************************************************************************************************/
ADC_enuErrorStatus_t ADC_enuStartConversionSynch(u8 Copy_u16ChaNum, u16 * Add_u16Result);

/***********************************************************************************************************
 *                                      03- ADC_enuStartConversionSynch                                    *
 *---------------------------------------------------------------------------------------------------------*
 * @description -> ASynchronouse Function to start conversion at only one channel at atime                 *
 * @param       -> pointer to struct in which configure the number of channels and array of channels to be *
 *					selected and empty arrat in which return the result of conversion for each channel     *
 *					and pointer to function (End Of Job function), to indicate							   *
 * @return      -> Error Status                                                                            *
 ***********************************************************************************************************/
ADC_enuErrorStatus_t ADC_enuStartConversionAsynch(ADC_strChannelChain_t  * Add_strChain);




#endif