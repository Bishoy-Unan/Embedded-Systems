/*######################################################################################################################*/
/* Author:	Bishoy Unan	 	   															   								*/
/* Date:	2/12/2023						            									       						*/
/* Version:	v2.0.0									 						 			     							*/
/* description: ATMwga32 DIO Driver with pre and post build configration defined by user			   					*/
/* Specs: 									      										   								*/
/* 01: DIO_enumError_t DIO_enumInit(void);																				*/
/* 02: DIO_enumError_t DIO_enumGetPin(DIO_enumPorts_t Copy_enumPortNum, DIO_enumPins_t Copy_enumPintNum , u8 * Pu8PinVal);*/
/* 03: DIO_enumError_t DIO_enumSetPortVal( DIO_enumPorts_t Copy_enumPortName , DIO_enumLogicState_t Copy_eumStatus);	  */
/*#######################################################################################################################*/


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_Private.h"
#include "DIO.h"
#include "DIO_CFG.h"
#include "Port.h"
#include "PortCFG.h"




#define CONCAT(p7,p6,p5,p4,p3,p2,p1,p0) CONCAT_HELPER(p7,p6,p5,p4,p3,p2,p1,p0) 
#define CONCAT_HELPER(p7,p6,p5,p4,p3,p2,p1,p0) 0b##p7##p6##p5##p4##p3##p2##p1##p0




/**
*@ In case Prebuild Configration
*/


/**
* @ implementation of pretbuild Configration mode depend on user choice
*/
#if  CONFIGRATION_MODE == PREBUILD_MODE


	DIO_enumError_t DIO_enumInit(void)
		{
			DIO_enumError_t DIO_enumReturnErrorStatus = DIO_enumOK ;
			
			
			#if (NUM_OF_PORTS > 4 || NUM_OF_PORTS < 2)
				DIO_enumReturnErrorStatus = DIO_enumOUT_OF_RANGE;
			#endif
			
			
			#if (NUM_OF_PORTS == 4 || NUM_OF_PORTS == 3 || NUM_OF_PORTS ==2)
				/**
				*@ PIN0 PORT A configration implementation 
				*/
				#if   DIO_PORTA_PIN0 == INP_PU
						#define PIN0_DDR  LOW
						#define PIN0_PORT HIGH
				#elif DIO_PORTA_PIN0 == INP_HIm
						#define PIN0_DDR  LOW
						#define PIN0_PORT LOW
				#elif DIO_PORTA_PIN0 == OUT_HIGH
						#define PIN0_DDR  HIGH
						#define PIN0_PORT HIGH
				#elif DIO_PORTA_PIN0 == OUT_lOW
						#define PIN0_DDR  HIGH
						#define PIN0_PORT LOW
				#else 
						#warning " invalid configration "
				#endif	
				
				
				/**
				*@ PIN1 PORT A configration implementation 
				*/
				#if   DIO_PORTA_PIN1 == INP_PU
						#define PIN1_DDR  LOW
						#define PIN1_PORT HIGH
				#elif DIO_PORTA_PIN1 == INP_HIm
						#define PIN1_DDR  LOW
						#define PIN1_PORT LOW
				#elif DIO_PORTA_PIN1 == OUT_HIGH
						#define PIN1_DDR  HIGH
						#define PIN1_PORT HIGH
				#elif DIO_PORTA_PIN1 == OUT_lOW
						#define PIN1_DDR  HIGH
						#define PIN1_PORT LOW
				#else 
						#warning " invalid configration "
				#endif	
				
				/**
				*@ PIN2 PORT A configration implementation 
				*/
				#if   DIO_PORTA_PIN2 == INP_PU
						#define PIN2_DDR  LOW
						#define PIN2_PORT HIGH
				#elif DIO_PORTA_PIN2 == INP_HIm
						#define PIN2_DDR  LOW
						#define PIN2_PORT LOW
				#elif DIO_PORTA_PIN2 == OUT_HIGH
						#define PIN2_DDR  HIGH
						#define PIN2_PORT HIGH
				#elif DIO_PORTA_PIN2 == OUT_lOW
						#define PIN2_DDR  HIGH
						#define PIN2_PORT LOW
				#else 
						#warning " invalid configration "
				#endif
				
				
				/**
				*@ PIN3 PORT A configration implementation 
				*/
				#if   DIO_PORTA_PIN3 == INP_PU
						#define PIN3_DDR  LOW
						#define PIN3_PORT HIGH
				#elif DIO_PORTA_PIN3 == INP_HIm
						#define PIN3_DDR  LOW
						#define PIN3_PORT LOW
				#elif DIO_PORTA_PIN3 == OUT_HIGH
						#define PIN3_DDR  HIGH
						#define PIN3_PORT HIGH
				#elif DIO_PORTA_PIN3 == OUT_lOW
						#define PIN3_DDR  HIGH
						#define PIN3_PORT LOW
				#else 
						#warning " invalid configration "
				#endif
				
				
				/**
				*@ PIN4 PORT A configration implementation 
				*/
				#if   DIO_PORTA_PIN4 == INP_PU
						#define PIN4_DDR  LOW
						#define PIN4_PORT HIGH
				#elif DIO_PORTA_PIN4 == INP_HIm
						#define PIN4_DDR  LOW
						#define PIN4_PORT LOW
				#elif DIO_PORTA_PIN4 == OUT_HIGH
						#define PIN4_DDR  HIGH
						#define PIN4_PORT HIGH
				#elif DIO_PORTA_PIN4 == OUT_lOW
						#define PIN4_DDR  HIGH
						#define PIN4_PORT LOW
				#else 
						#warning " invalid configration "
				#endif
				
				
				/**
				*@ PIN5 PORT A configration implementation 
				*/
				#if   DIO_PORTA_PIN5 == INP_PU
						#define PIN5_DDR  LOW
						#define PIN5_PORT HIGH
				#elif DIO_PORTA_PIN5 == INP_HIm
						#define PIN5_DDR  LOW
						#define PIN5_PORT LOW
				#elif DIO_PORTA_PIN5 == OUT_HIGH
						#define PIN5_DDR  HIGH
						#define PIN5_PORT HIGH
				#elif DIO_PORTA_PIN5 == OUT_lOW
						#define PIN5_DDR  HIGH
						#define PIN5_PORT LOW
				#else 
						#warning " invalid configration "
				#endif
				
				
				/**
				*@ PIN6 PORT A configration implementation 
				*/
				#if   DIO_PORTA_PIN6 == INP_PU
						#define PIN6_DDR  LOW
						#define PIN6_PORT HIGH
				#elif DIO_PORTA_PIN6 == INP_HIm
						#define PIN6_DDR  LOW
						#define PIN6_PORT LOW
				#elif DIO_PORTA_PIN6 == OUT_HIGH
						#define PIN6_DDR  HIGH
						#define PIN6_PORT HIGH
				#elif DIO_PORTA_PIN6 == OUT_lOW
						#define PIN6_DDR  HIGH
						#define PIN6_PORT LOW
				#else 
						#warning " invalid configration "
				#endif
				
				
				
				/**
				*@ PIN7 PORT A configration implementation 
				*/
				#if   DIO_PORTA_PIN7 == INP_PU
						#define PIN7_DDR  LOW
						#define PIN7_PORT HIGH
				#elif DIO_PORTA_PIN7 == INP_HIm
						#define PIN7_DDR  LOW
						#define PIN7_PORT LOW
				#elif DIO_PORTA_PIN7 == OUT_HIGH
						#define PIN7_DDR  HIGH
						#define PIN7_PORT HIGH
				#elif DIO_PORTA_PIN7 == OUT_lOW
						#define PIN7_DDR  HIGH
						#define PIN7_PORT LOW
				#else 
						#warning " invalid configration "
				#endif
			/**
			*@ assign pins configration in Data Direction Register and PORT register
			*/	
			DDRA  = CONCAT(PIN7_DDR,PIN6_DDR,PIN5_DDR,PIN4_DDR,PIN3_DDR,PIN2_DDR,PIN1_DDR,PIN0_DDR);
			PORTA = CONCAT(PIN7_PORT,PIN6_PORT,PIN5_PORT,PIN4_PORT,PIN3_PORT,PIN2_PORT,PIN1_PORT,PIN0_PORT);	
			
 
 
				
				/**
				*@ PIN0 PORT B configration implementation 
				*/
				#if   DIO_PORTB_PIN0 == INP_PU
						#define PIN0_DDR  LOW
						#define PIN0_PORT HIGH
				#elif DIO_PORTB_PIN0 == INP_HIm
						#define PIN0_DDR  LOW
						#define PIN0_PORT LOW
				#elif DIO_PORTB_PIN0 == OUT_HIGH
						#define PIN0_DDR  HIGH
						#define PIN0_PORT HIGH
				#elif DIO_PORTB_PIN0 == OUT_lOW
						#define PIN0_DDR  HIGH
						#define PIN0_PORT LOW
				#else 
						#warning " invalid configration "
				#endif	
				
				
				/**
				*@ PIN1 PORT B configration implementation 
				*/
				#if   DIO_PORTB_PIN1 == INP_PU
						#define PIN1_DDR  LOW
						#define PIN1_PORT HIGH
				#elif DIO_PORTB_PIN1 == INP_HIm
						#define PIN1_DDR  LOW
						#define PIN1_PORT LOW
				#elif DIO_PORTB_PIN1 == OUT_HIGH
						#define PIN1_DDR  HIGH
						#define PIN1_PORT HIGH
				#elif DIO_PORTB_PIN1 == OUT_lOW
						#define PIN1_DDR  HIGH
						#define PIN1_PORT LOW
				#else 
						#warning " invalid configration "
				#endif	
				
				/**
				*@ PIN2 PORT B configration implementation 
				*/
				#if   DIO_PORTB_PIN2 == INP_PU
						#define PIN2_DDR  LOW
						#define PIN2_PORT HIGH
				#elif DIO_PORTB_PIN2 == INP_HIm
						#define PIN2_DDR  LOW
						#define PIN2_PORT LOW
				#elif DIO_PORTB_PIN2 == OUT_HIGH
						#define PIN2_DDR  HIGH
						#define PIN2_PORT HIGH
				#elif DIO_PORTB_PIN2 == OUT_lOW
						#define PIN2_DDR  HIGH
						#define PIN2_PORT LOW
				#else 
						#warning " invalid configration "
				#endif
				
				
				/**
				*@ PIN3 PORT B configration implementation 
				*/
				#if   DIO_PORTB_PIN3 == INP_PU
						#define PIN3_DDR  LOW
						#define PIN3_PORT HIGH
				#elif DIO_PORTB_PIN3 == INP_HIm
						#define PIN3_DDR  LOW
						#define PIN3_PORT LOW
				#elif DIO_PORTB_PIN3 == OUT_HIGH
						#define PIN3_DDR  HIGH
						#define PIN3_PORT HIGH
				#elif DIO_PORTB_PIN3 == OUT_lOW
						#define PIN3_DDR  HIGH
						#define PIN3_PORT LOW
				#else 
						#warning " invalid configration "
				#endif
				
				
				/**
				*@ PIN4 PORT B configration implementation 
				*/
				#if   DIO_PORTB_PIN4 == INP_PU
						#define PIN4_DDR  LOW
						#define PIN4_PORT HIGH
				#elif DIO_PORTB_PIN4 == INP_HIm
						#define PIN4_DDR  LOW
						#define PIN4_PORT LOW
				#elif DIO_PORTB_PIN4 == OUT_HIGH
						#define PIN4_DDR  HIGH
						#define PIN4_PORT HIGH
				#elif DIO_PORTB_PIN4 == OUT_lOW
						#define PIN4_DDR  HIGH
						#define PIN4_PORT LOW
				#else 
						#warning " invalid configration "
				#endif
				
				
				/**
				*@ PIN5 PORT B configration implementation 
				*/
				#if   DIO_PORTB_PIN5 == INP_PU
						#define PIN5_DDR  LOW
						#define PIN5_PORT HIGH
				#elif DIO_PORTB_PIN5 == INP_HIm
						#define PIN5_DDR  LOW
						#define PIN5_PORT LOW
				#elif DIO_PORTB_PIN5 == OUT_HIGH
						#define PIN5_DDR  HIGH
						#define PIN5_PORT HIGH
				#elif DIO_PORTB_PIN5 == OUT_lOW
						#define PIN5_DDR  HIGH
						#define PIN5_PORT LOW
				#else 
						#warning " invalid configration "
				#endif
				
				
				/**
				*@ PIN6 PORT C configration implementation 
				*/
				#if   DIO_PORTB_PIN6 == INP_PU
						#define PIN6_DDR  LOW
						#define PIN6_PORT HIGH
				#elif DIO_PORTB_PIN6 == INP_HIm
						#define PIN6_DDR  LOW
						#define PIN6_PORT LOW
				#elif DIO_PORTB_PIN6 == OUT_HIGH
						#define PIN6_DDR  HIGH
						#define PIN6_PORT HIGH
				#elif DIO_PORTB_PIN6 == OUT_lOW
						#define PIN6_DDR  HIGH
						#define PIN6_PORT LOW
				#else 
						#warning " invalid configration "
				#endif
				
				
				
				/**
				*@ PIN7 PORT B configration implementation 
				*/
				#if   DIO_PORTB_PIN7 == INP_PU
						#define PIN7_DDR  LOW
						#define PIN7_PORT HIGH
				#elif DIO_PORTB_PIN7 == INP_HIm
						#define PIN7_DDR  LOW
						#define PIN7_PORT LOW
				#elif DIO_PORTB_PIN7 == OUT_HIGH
						#define PIN7_DDR  HIGH
						#define PIN7_PORT HIGH
				#elif DIO_PORTB_PIN7 == OUT_lOW
						#define PIN7_DDR  HIGH
						#define PIN7_PORT LOW
				#else 
						#warning " invalid configration "
				#endif
			/**
			*@ assign pins configration in Data Direction Register and PORT register
			*/	
			DDRB  = CONCAT(PIN7_DDR,PIN6_DDR,PIN5_DDR,PIN4_DDR,PIN3_DDR,PIN2_DDR,PIN1_DDR,PIN0_DDR);
			PORTB = CONCAT(PIN7_PORT,PIN6_PORT,PIN5_PORT,PIN4_PORT,PIN3_PORT,PIN2_PORT,PIN1_PORT,PIN0_PORT);	

			
			
			
		#endif	
		
		
		#if(NUM_OF_PORTS == 4 || NUM_OF_PORTS == 3)
			
			
				/**
				*@ PIN0 PORT C configration implementation 
				*/
				#if   DIO_PORTC_PIN0 == INP_PU
						#define PIN0_DDR  LOW
						#define PIN0_PORT HIGH
				#elif DIO_PORTC_PIN0 == INP_HIm
						#define PIN0_DDR  LOW
						#define PIN0_PORT LOW
				#elif DIO_PORTC_PIN0 == OUT_HIGH
						#define PIN0_DDR  HIGH
						#define PIN0_PORT HIGH
				#elif DIO_PORTC_PIN0 == OUT_lOW
						#define PIN0_DDR  HIGH
						#define PIN0_PORT LOW
				#else 
						#warning " invalid configration "
				#endif	
				
				
				/**
				*@ PIN1 PORT C configration implementation 
				*/
				#if   DIO_PORTC_PIN1 == INP_PU
						#define PIN1_DDR  LOW
						#define PIN1_PORT HIGH
				#elif DIO_PORTC_PIN1 == INP_HIm
						#define PIN1_DDR  LOW
						#define PIN1_PORT LOW
				#elif DIO_PORTC_PIN1 == OUT_HIGH
						#define PIN1_DDR  HIGH
						#define PIN1_PORT HIGH
				#elif DIO_PORTC_PIN1 == OUT_lOW
						#define PIN1_DDR  HIGH
						#define PIN1_PORT LOW
				#else 
						#warning " invalid configration "
				#endif	
				
				/**
				*@ PIN2 PORT C configration implementation 
				*/
				#if   DIO_PORTC_PIN2 == INP_PU
						#define PIN2_DDR  LOW
						#define PIN2_PORT HIGH
				#elif DIO_PORTC_PIN2 == INP_HIm
						#define PIN2_DDR  LOW
						#define PIN2_PORT LOW
				#elif DIO_PORTC_PIN2 == OUT_HIGH
						#define PIN2_DDR  HIGH
						#define PIN2_PORT HIGH
				#elif DIO_PORTC_PIN2 == OUT_lOW
						#define PIN2_DDR  HIGH
						#define PIN2_PORT LOW
				#else 
						#warning " invalid configration "
				#endif
				
				
				/**
				*@ PIN3 PORT C configration implementation 
				*/
				#if   DIO_PORTC_PIN3 == INP_PU
						#define PIN3_DDR  LOW
						#define PIN3_PORT HIGH
				#elif DIO_PORTC_PIN3 == INP_HIm
						#define PIN3_DDR  LOW
						#define PIN3_PORT LOW
				#elif DIO_PORTC_PIN3 == OUT_HIGH
						#define PIN3_DDR  HIGH
						#define PIN3_PORT HIGH
				#elif DIO_PORTC_PIN3 == OUT_lOW
						#define PIN3_DDR  HIGH
						#define PIN3_PORT LOW
				#else 
						#warning " invalid configration "
				#endif
				
				
				/**
				*@ PIN4 PORT C configration implementation 
				*/
				#if   DIO_PORTC_PIN4 == INP_PU
						#define PIN4_DDR  LOW
						#define PIN4_PORT HIGH
				#elif DIO_PORTC_PIN4 == INP_HIm
						#define PIN4_DDR  LOW
						#define PIN4_PORT LOW
				#elif DIO_PORTC_PIN4 == OUT_HIGH
						#define PIN4_DDR  HIGH
						#define PIN4_PORT HIGH
				#elif DIO_PORTC_PIN4 == OUT_lOW
						#define PIN4_DDR  HIGH
						#define PIN4_PORT LOW
				#else 
						#warning " invalid configration "
				#endif
				
				
				/**
				*@ PIN5 PORT C configration implementation 
				*/
				#if   DIO_PORTC_PIN5 == INP_PU
						#define PIN5_DDR  LOW
						#define PIN5_PORT HIGH
				#elif DIO_PORTC_PIN5 == INP_HIm
						#define PIN5_DDR  LOW
						#define PIN5_PORT LOW
				#elif DIO_PORTC_PIN5 == OUT_HIGH
						#define PIN5_DDR  HIGH
						#define PIN5_PORT HIGH
				#elif DIO_PORTC_PIN5 == OUT_lOW
						#define PIN5_DDR  HIGH
						#define PIN5_PORT LOW
				#else 
						#warning " invalid configration "
				#endif
				
				
				/**
				*@ PIN6 PORT C configration implementation 
				*/
				#if   DIO_PORTC_PIN6 == INP_PU
						#define PIN6_DDR  LOW
						#define PIN6_PORT HIGH
				#elif DIO_PORTC_PIN6 == INP_HIm
						#define PIN6_DDR  LOW
						#define PIN6_PORT LOW
				#elif DIO_PORTC_PIN6 == OUT_HIGH
						#define PIN6_DDR  HIGH
						#define PIN6_PORT HIGH
				#elif DIO_PORTC_PIN6 == OUT_lOW
						#define PIN6_DDR  HIGH
						#define PIN6_PORT LOW
				#else 
						#warning " invalid configration "
				#endif
				
				
				
				/**
				*@ PIN7 PORT C configration implementation 
				*/
				#if   DIO_PORTC_PIN7 == INP_PU
						#define PIN7_DDR  LOW
						#define PIN7_PORT HIGH
				#elif DIO_PORTC_PIN7 == INP_HIm
						#define PIN7_DDR  LOW
						#define PIN7_PORT LOW
				#elif DIO_PORTC_PIN7 == OUT_HIGH
						#define PIN7_DDR  HIGH
						#define PIN7_PORT HIGH
				#elif DIO_PORTC_PIN7 == OUT_lOW
						#define PIN7_DDR  HIGH
						#define PIN7_PORT LOW
				#else 
						#warning " invalid configration "
				#endif
			/**
			*@ assign pins configration in Data Direction Register and PORT register
			*/	
			DDRC  = CONCAT(PIN7_DDR,PIN6_DDR,PIN5_DDR,PIN4_DDR,PIN3_DDR,PIN2_DDR,PIN1_DDR,PIN0_DDR);
			PORTC = CONCAT(PIN7_PORT,PIN6_PORT,PIN5_PORT,PIN4_PORT,PIN3_PORT,PIN2_PORT,PIN1_PORT,PIN0_PORT);	

			
		#endif

		


		#if(NUM_OF_PORTS == 4 )

				/**
				*@ PIN0 PORT D configration implementation 
				*/
				#if   DIO_PORTD_PIN0 == INP_PU
						#define PIN0_DDR  LOW
						#define PIN0_PORT HIGH
				#elif DIO_PORTD_PIN0 == INP_HIm
						#define PIN0_DDR  LOW
						#define PIN0_PORT LOW
				#elif DIO_PORTD_PIN0 == OUT_HIGH
						#define PIN0_DDR  HIGH
						#define PIN0_PORT HIGH
				#elif DIO_PORTD_PIN0 == OUT_lOW
						#define PIN0_DDR  HIGH
						#define PIN0_PORT LOW
				#else 
						#warning " invalid configration "
				#endif	
				
				
				/**
				*@ PIN1 PORT D configration implementation 
				*/
				#if   DIO_PORTD_PIN1 == INP_PU
						#define PIN1_DDR  LOW
						#define PIN1_PORT HIGH
				#elif DIO_PORTD_PIN1 == INP_HIm
						#define PIN1_DDR  LOW
						#define PIN1_PORT LOW
				#elif DIO_PORTD_PIN1 == OUT_HIGH
						#define PIN1_DDR  HIGH
						#define PIN1_PORT HIGH
				#elif DIO_PORTD_PIN1 == OUT_lOW
						#define PIN1_DDR  HIGH
						#define PIN1_PORT LOW
				#else 
						#warning " invalid configration "
				#endif	
				
				/**
				*@ PIN2 PORT D configration implementation 
				*/
				#if   DIO_PORTD_PIN2 == INP_PU
						#define PIN2_DDR  LOW
						#define PIN2_PORT HIGH
				#elif DIO_PORTD_PIN2 == INP_HIm
						#define PIN2_DDR  LOW
						#define PIN2_PORT LOW
				#elif DIO_PORTD_PIN2 == OUT_HIGH
						#define PIN2_DDR  HIGH
						#define PIN2_PORT HIGH
				#elif DIO_PORTD_PIN2 == OUT_lOW
						#define PIN2_DDR  HIGH
						#define PIN2_PORT LOW
				#else 
						#warning " invalid configration "
				#endif
				
				
				/**
				*@ PIN3 PORT D configration implementation 
				*/
				#if   DIO_PORTD_PIN3 == INP_PU
						#define PIN3_DDR  LOW
						#define PIN3_PORT HIGH
				#elif DIO_PORTD_PIN3 == INP_HIm
						#define PIN3_DDR  LOW
						#define PIN3_PORT LOW
				#elif DIO_PORTD_PIN3 == OUT_HIGH
						#define PIN3_DDR  HIGH
						#define PIN3_PORT HIGH
				#elif DIO_PORTD_PIN3 == OUT_lOW
						#define PIN3_DDR  HIGH
						#define PIN3_PORT LOW
				#else 
						#warning " invalid configration "
				#endif
				
				
				/**
				*@ PIN4 PORT D configration implementation 
				*/
				#if   DIO_PORTD_PIN4 == INP_PU
						#define PIN4_DDR  LOW
						#define PIN4_PORT HIGH
				#elif DIO_PORTD_PIN4 == INP_HIm
						#define PIN4_DDR  LOW
						#define PIN4_PORT LOW
				#elif DIO_PORTD_PIN4 == OUT_HIGH
						#define PIN4_DDR  HIGH
						#define PIN4_PORT HIGH
				#elif DIO_PORTD_PIN4 == OUT_lOW
						#define PIN4_DDR  HIGH
						#define PIN4_PORT LOW
				#else 
						#warning " invalid configration "
				#endif
				
				
				/**
				*@ PIN5 PORT  configration implementation 
				*/
				#if   DIO_PORTD_PIN5 == INP_PU
						#define PIN5_DDR  LOW
						#define PIN5_PORT HIGH
				#elif DIO_PORTD_PIN5 == INP_HIm
						#define PIN5_DDR  LOW
						#define PIN5_PORT LOW
				#elif DIO_PORTD_PIN5 == OUT_HIGH
						#define PIN5_DDR  HIGH
						#define PIN5_PORT HIGH
				#elif DIO_PORTD_PIN5 == OUT_lOW
						#define PIN5_DDR  HIGH
						#define PIN5_PORT LOW
				#else 
						#warning " invalid configration "
				#endif
				
				
				/**
				*@ PIN6 PORT D configration implementation 
				*/
				#if   DIO_PORTD_PIN6 == INP_PU
						#define PIN6_DDR  LOW
						#define PIN6_PORT HIGH
				#elif DIO_PORTD_PIN6 == INP_HIm
						#define PIN6_DDR  LOW
						#define PIN6_PORT LOW
				#elif DIO_PORTD_PIN6 == OUT_HIGH
						#define PIN6_DDR  HIGH
						#define PIN6_PORT HIGH
				#elif DIO_PORTD_PIN6 == OUT_lOW
						#define PIN6_DDR  HIGH
						#define PIN6_PORT LOW
				#else 
						#warning " invalid configration "
				#endif
				
				
				
				/**
				*@ PIN7 PORT D configration implementation 
				*/
				#if   DIO_PORTD_PIN7 == INP_PU
						#define PIN7_DDR  LOW
						#define PIN7_PORT HIGH
				#elif DIO_PORTD_PIN7 == INP_HIm
						#define PIN7_DDR  LOW
						#define PIN7_PORT LOW
				#elif DIO_PORTD_PIN7 == OUT_HIGH
						#define PIN7_DDR  HIGH
						#define PIN7_PORT HIGH
				#elif DIO_PORTD_PIN7 == OUT_lOW
						#define PIN7_DDR  HIGH
						#define PIN7_PORT LOW
				#else 
						#warning " invalid configration "
				#endif
			/**
			*@ assign pins configration in Data Direction Register and PORT register
			*/	
			DDRD  = CONCAT(PIN7_DDR,PIN6_DDR,PIN5_DDR,PIN4_DDR,PIN3_DDR,PIN2_DDR,PIN1_DDR,PIN0_DDR);
			PORTD = CONCAT(PIN7_PORT,PIN6_PORT,PIN5_PORT,PIN4_PORT,PIN3_PORT,PIN2_PORT,PIN1_PORT,PIN0_PORT);	


		#endif				


		return DIO_enumReturnErrorStatus;
	}/**dio inite pretbuild configration mode**/		

	DIO_enumError_t  DIO_voidGetPinVal(u8 Copy_u8PortNum, u8 Copy_u8PinNum , u8 * Pu8PinVal) 
		{
			DIO_enumError_t DIO_enumReturnErrorStatus = DIO_enumOK ;
			
				#if Copy_u8PortNum == DIO_PORTA 
					*Pu8PinVal = GET_BIT(PINA,Copy_u8PinNum);	
				#elif Copy_u8PortNum == DIO_PORTB 
					*Pu8PinVal = GET_BIT(PINB,Copy_u8PinNum);
				#elif Copy_u8PortNum == DIO_PORTC 
					*Pu8PinVal = GET_BIT(PINC,Copy_u8PinNum);
				#else
					*Pu8PinVal = GET_BIT(PIND,Copy_u8PinNum);
				#endif	
		
			return DIO_enumReturnErrorStatus;
		}/*DIO_voidGetPinVal*/
	
#elif CONFIGRATION_MODE == POSTBUILD_MODE

extern DIO_enumPinOptions_t DIO_PinCFG[NUM_OF_PINS];

/**
* @ implementation of postbuild Configration mode depend on user choice
*/
DIO_enumError_t DIO_enumInit(void)
		{
			u8 iterator=0;
			/*return value of the function */
			DIO_enumError_t DIO_enumReturnErrorStatus = DIO_enumOK ;
			/*DIO_enumPort_t variable used to check which port used*/
			DIO_enumPorts_t LOC_enumPortNum = DIO_enumPORTA ;
			/*DIO_enumPinOptions_t variable used to configre pin mode*/
			DIO_enumPinOptions_t LOC_enumPinNum = DIO_enumINP_PU;
			
			
			for(iterator=0; iterator < NUM_OF_PINS ;iterator++){
				/*determine the pin choosed from 32 pins exist in which port*/
				LOC_enumPortNum = iterator / PINS_PER_PORT;
				/*specify the bit number it will be from 0 to 7 */
				LOC_enumPinNum  = iterator % PINS_PER_PORT;
				
				switch(LOC_enumPortNum)
				{
					case DIO_enumPORTA:
							switch(DIO_PinCFG[iterator])
							{
									case DIO_enumINP_PU:
											CLR_BIT(DDRA,LOC_enumPinNum);
											SET_BIT(PORTA,LOC_enumPinNum);
									break;
									case DIO_enumINP_HIm:
											CLR_BIT(DDRA,LOC_enumPinNum);
											CLR_BIT(PORTA,LOC_enumPinNum);
									break;
									case DIO_enumOUT_HIGH:
											SET_BIT(DDRA,LOC_enumPinNum);
											SET_BIT(PORTA,LOC_enumPinNum);
									break;
									case DIO_enumOUT_lOW:
											SET_BIT(DDRA,LOC_enumPinNum);
											CLR_BIT(PORTA,LOC_enumPinNum);
									break;
									default:
									break;
							}/*switch 2*/
					break;
					case DIO_enumPORTB:
							switch(DIO_PinCFG[iterator])
									{
											case DIO_enumINP_PU:
													CLR_BIT(DDRB,LOC_enumPinNum);
													SET_BIT(PORTB,LOC_enumPinNum);
											break;
											case DIO_enumINP_HIm:
													CLR_BIT(DDRB,LOC_enumPinNum);
													CLR_BIT(PORTB,LOC_enumPinNum);
											break;
											case DIO_enumOUT_HIGH:
													SET_BIT(DDRB,LOC_enumPinNum);
													SET_BIT(PORTB,LOC_enumPinNum);
											break;
											case DIO_enumOUT_lOW:
													SET_BIT(DDRB,LOC_enumPinNum);
													CLR_BIT(PORTB,LOC_enumPinNum);
											break;
											default:
											break;
									}/*switch 2*/
					break;
					case DIO_enumPORTC:
								switch(DIO_PinCFG[iterator])
									{
											case DIO_enumINP_PU:
													CLR_BIT(DDRC,LOC_enumPinNum);
													SET_BIT(PORTC,LOC_enumPinNum);
											break;
											case DIO_enumINP_HIm:
													CLR_BIT(DDRC,LOC_enumPinNum);
													CLR_BIT(PORTC,LOC_enumPinNum);
											break;
											case DIO_enumOUT_HIGH:
													SET_BIT(DDRC,LOC_enumPinNum);
													SET_BIT(PORTC,LOC_enumPinNum);
											break;
											case DIO_enumOUT_lOW:
													SET_BIT(DDRC,LOC_enumPinNum);
													CLR_BIT(PORTC,LOC_enumPinNum);
											break;
											default:
											break;
									}/*switch 2*/
					break;
					case DIO_enumPORTD:
								switch(DIO_PinCFG[iterator])
									{
											case DIO_enumINP_PU:
													CLR_BIT(DDRD,LOC_enumPinNum);
													SET_BIT(PORTD,LOC_enumPinNum);
											break;
											case DIO_enumINP_HIm:
													CLR_BIT(DDRD,LOC_enumPinNum);
													CLR_BIT(PORTD,LOC_enumPinNum);
											break;
											case DIO_enumOUT_HIGH:
													SET_BIT(DDRD,LOC_enumPinNum);
													SET_BIT(PORTD,LOC_enumPinNum);
											break;
											case DIO_enumOUT_lOW:
													SET_BIT(DDRD,LOC_enumPinNum);
													CLR_BIT(PORTD,LOC_enumPinNum);
											break;
											default:
											break;
									}/*switch 2*/
					break;
					default:
					break;
				}/*switch 1*/
				
				
			}/*for*/
			
			
			
			
			
			
			return DIO_enumReturnErrorStatus;
			
		}/*dio inite postbuild configration mode*/

#else
		#warning "invalid choice"
#endif	

