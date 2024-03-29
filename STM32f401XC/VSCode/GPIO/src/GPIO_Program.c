
#include"../include/STD_TYPES.h"
#include"../include/GPIO_Interface.h"

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
GPIO_enuErrorStatus_t GPIO_enuInit(GPIO_strPinConfg_t * Add_strPintConfg)
{
	
	GPIO_enuErrorStatus_t  Loc_enuRetError = GPIO_enuOK ;
	/* casting port variable to GPIOx_t data type*/
	//Add_strPintConfg -> GPIOPort = (GPIOx_t)(Add_strPintConfg -> GPIOPort);
	
	/**
	*@ VALIDATE input parameters
	*/
	if(Add_strPintConfg == NULL)
	{
		Loc_enuRetError = GPIO_enuNOK ;
	}
	else if((Add_strPintConfg->GPIOPort!=GPIOA)&&(Add_strPintConfg->GPIOPort!=GPIOB)&&(Add_strPintConfg->GPIOPort!=GPIOC)&&(Add_strPintConfg->GPIOPort!=GPIOD)&&(Add_strPintConfg->GPIOPort!=GPIOE)&&(Add_strPintConfg->GPIOPort!=GPIOH))
	{
		Loc_enuRetError = GPIO_enuNOK ;
	}
	else if((Add_strPintConfg -> GPIOPin > GPIO_PIN15))
	{
		Loc_enuRetError = GPIO_enuNOK ;
	}
	else if(((Add_strPintConfg -> GPIOSpeed) > GPIO_OUTPUT_SPEED_VERYHIGH))
	{
		Loc_enuRetError = GPIO_enuNOK ;
	}
	else{
			u32 Loc_u32TempReg = 0;
			
			
			
			
			/* get the dirction mode  */
			Loc_u32TempReg = ((Add_strPintConfg->GPIOMode & GET_MODE_MASK)>>3);
			/* set mode register */
			Add_strPintConfg -> GPIOPort->MODEREG |= (Loc_u32TempReg<<((Add_strPintConfg->GPIOPin)*2));
			
			/*set out mode in case of OUTPUT_MODE or AF_MODE*/
			if((Loc_u32TempReg == OUTPUT_MODE)||(Loc_u32TempReg == AF_MODE))
			{
				/* get the output type mode  */
				Loc_u32TempReg = ((Add_strPintConfg->GPIOMode & GET_TYPE_MASK)>>2);
				/* set the output type register  */
				Add_strPintConfg -> GPIOPort->OTYPER |= (Loc_u32TempReg<<((Add_strPintConfg->GPIOPin)));
			}/*if*/
			
			/* get the pull up/pull down mode  */
			Loc_u32TempReg = ((Add_strPintConfg->GPIOMode & GET_PUPDR_MASK));
			/* SET PUP/PD Rgister  */
			Add_strPintConfg -> GPIOPort->PUPDR |= (Loc_u32TempReg<<((Add_strPintConfg->GPIOPin)*2));
			
			/*set output speed  in case of OUTPUT_MODE or AF_MODE*/
			if((Loc_u32TempReg == OUTPUT_MODE)||(Loc_u32TempReg == AF_MODE))
			{
				/* SET Speed Register  */
				Add_strPintConfg -> GPIOPort->OSPEEDR = ((Add_strPintConfg->GPIOSpeed)<<((Add_strPintConfg->GPIOPin)*2));
			}/*if*/
		
	}/*else*/
	
	return Loc_enuRetError ;
}/*GPIO_enuInit*/



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
GPIO_enuErrorStatus_t GPIO_enuSetPinValue(GPIOx_t * Add_u8PORT , u8 Copy_u8PIN , u8 Copy_u8Val )
{
	GPIO_enuErrorStatus_t  Loc_enuRetError = GPIO_enuOK ;
	/* casting port variable to GPIOx_t data type*/
	//Add_u8PORT = (GPIOx_t)(Add_u8PORT)
	
	/**
	*@ VALIDATE input parameters
	*/
	if((Add_u8PORT!=GPIOA)&&(Add_u8PORT!=GPIOB)&&(Add_u8PORT!=GPIOC)&&(Add_u8PORT!=GPIOD)&&(Add_u8PORT!=GPIOE)&&(Add_u8PORT!=GPIOH))
	{
		Loc_enuRetError = GPIO_enuNOK ;
	}
	else if((Copy_u8PIN > GPIO_PIN15))
	{
		Loc_enuRetError = GPIO_enuNOK ;
	}
	else if((Copy_u8Val > GPIO_HIGH))
	{
		Loc_enuRetError = GPIO_enuNOK ;
	}
	else{
			if(Copy_u8Val == GPIO_HIGH)
			{
				/* set pin as high*/
				Add_u8PORT->BSRR |= (1<<Copy_u8PIN);
			}
			else if(Copy_u8Val == GPIO_LOW)
			{
				/*set pin as Low*/
				Add_u8PORT->BSRR |= (1<<(Copy_u8PIN + 16));
			}
			else
			{
				Loc_enuRetError = GPIO_enuNOK ;
			}
			
	    }/*else*/
	
	return Loc_enuRetError ;
}/*GPIO_enuSetPinVal*/



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
GPIO_enuErrorStatus_t GPIO_enuGetPinValue(GPIOx_t  * Add_u8PORT , u8 Copy_u8PIN , u8 * Add_u8Val )
{
	GPIO_enuErrorStatus_t  Loc_enuRetError = GPIO_enuOK ;
	/* casting port variable to GPIOx_t data type*/
	//Add_u8PORT = (GPIOx_t)(Add_u8PORT)
	
	/**
	*@ VALIDATE input parameters
	*/
	if((Add_u8PORT!=GPIOA)||(Add_u8PORT!=GPIOB)||(Add_u8PORT!=GPIOC)||(Add_u8PORT!=GPIOD)||(Add_u8PORT!=GPIOE)||(Add_u8PORT!=GPIOH))
	{
		Loc_enuRetError = GPIO_enuNOK ;
	}
	else if((Copy_u8PIN > GPIO_PIN15))
	{
		Loc_enuRetError = GPIO_enuNOK ;
	}
	else if(Add_u8Val == NULL)
	{
		Loc_enuRetError = GPIO_enuNOK ;
	}
	else{
			*Add_u8Val = ((Add_u8PORT->IDR>>Copy_u8PIN) & GET_FIRST_BIT);
			
	    }/*else*/
	
	return Loc_enuRetError ;
}/*GPIO_enuGetPinVal*/



