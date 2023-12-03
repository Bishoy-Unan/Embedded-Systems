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




#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_Private.h"
#include "DIO.h"
#include "DIO_CFG.h"
#include "Port.h"
#include "PortCFG.h"


/**
*@ in case user choose postbuild configration
*/






/**
*@ enum of pins configration options in case of postbuild mode
*/


/**
*@ array of 32 pin intial configration which may be change later in run time its DIO_enumINP_PU by default
*/
 DIO_enumPinOptions_t DIO_PinCFG[NUM_OF_PINS]={DIO_enumOUT_HIGH,DIO_enumINP_PU,DIO_enumINP_PU,DIO_enumINP_PU,DIO_enumINP_PU,
													DIO_enumINP_PU,DIO_enumINP_PU,DIO_enumINP_PU,DIO_enumINP_PU,DIO_enumINP_PU,
													DIO_enumINP_PU,DIO_enumINP_PU,DIO_enumINP_PU,DIO_enumINP_PU,DIO_enumINP_PU,
													DIO_enumINP_PU,DIO_enumINP_PU,DIO_enumINP_PU,DIO_enumINP_PU,DIO_enumINP_PU,
													DIO_enumINP_PU,DIO_enumINP_PU,DIO_enumINP_PU,DIO_enumINP_PU,DIO_enumINP_PU,
													DIO_enumINP_PU,DIO_enumINP_PU,DIO_enumINP_PU,DIO_enumINP_PU,DIO_enumINP_PU,
													DIO_enumINP_PU,DIO_enumINP_PU};
