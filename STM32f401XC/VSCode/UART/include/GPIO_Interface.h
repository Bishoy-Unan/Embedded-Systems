

#ifndef  	GPIO_INTERFACE_H
#define		GPIO_INTERFACE_H

#include "STD_TYPES.h"
#include "GPIO_Private.h"

typedef enum
{
	GPIO_enuOK,
	GPIO_enuNOK
	
}GPIO_enuErrorStatus_t;




typedef struct{
	
	GPIOx_t * GPIOPort ;
	u16 GPIOPin;
	u8 GPIOMode;
	u8 GPIOSpeed;
	u8 AF_Num;
	
}GPIO_strPinConfg_t;




/**
 *@ Gpio_enuInit
 *@ breif  :  Initialize the pins of the GPIO peripheral 
 *@ param  :   Add_strPintConfg (GPIO_strPinConfg_t) : struct
 *@
 *@	       Add_strPintConfg -> GPIOMode : GPIO_MODE_INPUT_FLOATING 		           	   
 *@                                       GPIO_MODE_INPUT_PU				              
 *@                                       GPIO_MODE_INPUT_PD                                     
 *@                                       GPIO_MODE_OUTPUT_PP				            
 *@                                       GPIO_MODE_OUTPUT_PP_PU        	            
 *@                                       GPIO_MODE_OUTPUT_PP_PD      	                                        
 *@                                       GPIO_MODE_OUTPUT_OPENDRAIN		            
 *@                                       GPIO_MODE_OUTPUT_OPENDRAIN_PU               
 *@                                       GPIO_MODE_OUTPUT_OPENDRAIN_PD                                                             
 *@                                       GPIO_MODE_AF_PP					            
 *@                                       GPIO_MODE_AF_PP_PU            	            
 *@                                       GPIO_MODE_AF_PP_PD          	            
 *@                                       GPIO_MODE_AF_OPENDRAIN			  
 *@                                       GPIO_MODE_AF_OPENDRAIN_PU       
 *@                                       GPIO_MODE_AF_OPENDRAIN_PD       
 *@                                       GPIO_MODE_ANALOG	
 *@ 
 *@       Add_strPintConfg -> GPIOPort:   GPIOA  
 *@										  GPIOB
 *@										  GPIOC
 *@										  GPIOD
 *@										  GPIOE
 *@										  GPIOH
 *@
 *@      Add_strPintConfg -> GPIOSpeed :  GPIO_OUTPUT_SPEED_LOW                      
 *@                                      GPIO_OUTPUT_SPEED_MEDIUM                      
 *@                                      GPIO_OUTPUT_SPEED_HIGH                        
 *@                                      GPIO_OUTPUT_SPEED_VERYHIGH                    
 *@                                                                                    
 *@     Add_strPintConfg -> GPIOPin   :   GPIO_PIN0 : GPIO_PIN15                               
 *@                                                                                             
 *@ return  :  error status  
 */
GPIO_enuErrorStatus_t GPIO_enuInit(GPIO_strPinConfg_t * Add_strPintConfg);

/**
 *@ GPIO_enuSetPinVal
 *@ breif  :  Set Pin to HIGH or to LOW 
 *@ param  :   
 *@
 *@       Add_u8PORT : GPIOA  
 *@					   GPIOB
 *@					   GPIOC
 *@					   GPIOD
 *@					   GPIOE
 *@					   GPIOH
 *@
 *@                                                                                    
 *@      Copy_u8PIN   :   GPIO_PIN0 : GPIO_PIN15 
 *@ 
 *@		 Copy_u8Val	  :  GPIO_HIGH
 *@						 GPIO_LOW
 *@                                                                                             
 *@ return  :  error status  
 */
GPIO_enuErrorStatus_t GPIO_enuSetPinValue(GPIOx_t * Add_u8PORT , u8 Copy_u8PIN , u8 Copy_u8Val );

/**
 *@ GPIO_enuGetetPinVal
 *@ breif  :  Get the value of the passed pin 
 *@ param  :   
 *@
 *@       Add_u8PORT : GPIOA  
 *@					   GPIOB
 *@					   GPIOC
 *@					   GPIOD
 *@					   GPIOE
 *@					   GPIOH
 *@
 *@                                                                                    
 *@      Copy_u8PIN   :   GPIO_PIN0 : GPIO_PIN15 
 *@ 
 *@                                                                                             
 *@ return  :  error status  
 */
GPIO_enuErrorStatus_t GPIO_enuGetPinValue(GPIOx_t * Add_u8PORT , u8 Copy_u8PIN , u8 * Add_u8Val );






#endif
