/*######################################################################################################################*/
/* Author:	Bishoy Unan	 	   					   					*/
/* Date:	2/12/2023									       			*/
/* Version:	v2.0.0				 			     					         */
/* description: ATMwga32 DIO Driver with pre and post build configration defined by user			          */
/* Specs: 								     						*/
/* 01: DIO_enumError_t DIO_enumInit(void);		      								  */
/* 02: DIO_enumError_t DIO_enumGetPin(DIO_enumPorts_t Copy_enumPortNum, DIO_enumPins_t Copy_enumPintNum , u8 * Pu8PinVal);*/
/* 03: DIO_enumError_t DIO_enumSetPortVal( DIO_enumPorts_t Copy_enumPortName , DIO_enumLogicState_t Copy_eumStatus);	  */
/*#######################################################################################################################*/



/**
*@ header guard to prevend recursive inclusion
*/
#ifndef MDIO_PortCFG_H
#define MDIO_PortCFG_H





#define NUM_OF_PORTS	4
#define NUM_OF_PINS	   32
#define PINS_PER_PORT	8






/**
*@ Here you can choose Configration Mode 
*@ 1- Prebuild_Mode 
*@ 2- Postbuild_Mode
*@ note the default Configration mode is Prebuild Configration Mode
**/

#define CONFIGRATION_MODE	POSTBUILD_MODE



/**
*@ user should define number of ports of he target and number of pins per port 
*/

#define NUM_OF_PORTS	4
#define NUM_OF_PINS	   32
#define PINS_PER_PORT	8




/**
*@ in case of prebuild configration user should configre each pin according to his desire
*@ available options in next comment
*/

/**
*@ Here you can choose Pins Configrations 
*@ Input pullup or input high impedance "floating pin" or output high or output low
*@ choose :
*@ 1- INP_PU 
*@ 2- INP_HIm
*@ 3- OUT_HIGH
*@ 4- OUT_lOW
*@ note the default Pins Configration Mode is input pull up
**/

#if (NUM_OF_PORTS == 4 || NUM_OF_PORTS == 3 || NUM_OF_PORTS ==2)
	/**
	*@ PORT A
	*/
	#define DIO_PORTA_PIN0		OUT_HIGH
	#define DIO_PORTA_PIN1		OUT_lOW
	#define DIO_PORTA_PIN2		INP_PU
	#define DIO_PORTA_PIN3		INP_PU
	#define DIO_PORTA_PIN4		INP_PU
	#define DIO_PORTA_PIN5		INP_PU
	#define DIO_PORTA_PIN6 		INP_PU
	#define DIO_PORTA_PIN7 		INP_PU
	
	/**
	*@ PORT B 
	**/
	
	#define DIO_PORTB_PIN0		INP_PU
	#define DIO_PORTB_PIN1		INP_PU
	#define DIO_PORTB_PIN2		INP_PU
	#define DIO_PORTB_PIN3		INP_PU
	#define DIO_PORTB_PIN4		INP_PU
	#define DIO_PORTB_PIN5		INP_PU
	#define DIO_PORTB_PIN6 		INP_PU
	#define DIO_PORTB_PIN7 		INP_PU
	
#endif	

#if (NUM_OF_PORTS == 4 || NUM_OF_PORTS == 3)
	/**
	*@ PORT C
	*/
	#define DIO_PORTC_PIN0		INP_PU
	#define DIO_PORTC_PIN1		INP_PU
	#define DIO_PORTC_PIN2		INP_PU
	#define DIO_PORTC_PIN3		INP_PU
	#define DIO_PORTC_PIN4		INP_PU
	#define DIO_PORTC_PIN5		INP_PU
	#define DIO_PORTC_PIN6 		INP_PU
	#define DIO_PORTC_PIN7 		INP_PU
	
	
#endif	

#if(NUM_OF_PORTS == 4 )
	/**
	*@ PORT D
	*/
	
	#define DIO_PORTD_PIN0		INP_PU
	#define DIO_PORTD_PIN1		INP_PU
	#define DIO_PORTD_PIN2		INP_PU
	#define DIO_PORTD_PIN3		INP_PU
	#define DIO_PORTD_PIN4		INP_PU
	#define DIO_PORTD_PIN5		INP_PU
	#define DIO_PORTD_PIN6 		INP_PU
	#define DIO_PORTD_PIN7 		INP_PU
	
#endif



typedef enum{
		
		DIO_enumINP_PU	  ,
		DIO_enumINP_HIm   ,
		DIO_enumOUT_HIGH  ,
		DIO_enumOUT_lOW	  
	
}DIO_enumPinOptions_t;



#endif /*header guard*/ 