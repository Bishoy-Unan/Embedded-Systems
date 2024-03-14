/*########################################################*/
/* Author:	Bishoy Unan		*/
/* Date:	9/12/2023		*/
/* Version:	v1.0.0		*/
/* description: switch Driver Using DIO V04*/
/* Specs:		*/
/* 01: SWITCH_enumErrorState SWITCH_enumdInit(void)						*/
/* SWITCH_enumErrorState SWITCH_enuGetSwitchState(u8 Copy_strSwitchPort , u8 * Add_u8State) */
/*####################################################*/

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "SWITCH.h"
#include "SWITCH_Config.h"
#include "../../MCAL/DIO_04/DIO.h"




	/**
	*@ araay of LED_strCFG_t data type in which we configure ports of leds and configure pins of leds and leds status
	*/
SWITCH_strCFG_t SWITCHS[NumOfLSWITCHES] =  { [SWITCH1] = {.SWITCH_strPORT = DIO_enumPORTD ,
														  .SWITCH_strPIN = DIO_enumPIN0 ,
											              .SWITCH_strSTATE = SWITCH_enumINPUT_PULLUP }  ,
								             [SWITCH2] = {.SWITCH_strPORT = DIO_enumPORTD ,
											              .SWITCH_strPIN = DIO_enumPIN1 ,
											              .SWITCH_strSTATE = SWITCH_enumINPUT_PULLUP }  ,
								             [SWITCH3] = {.SWITCH_strPORT = DIO_enumPORTD ,
									                      .SWITCH_strPIN = DIO_enumPIN2,
								                          .SWITCH_strSTATE = SWITCH_enumINPUT_PULLUP }						
							               }; /* LEDS ARRAY*/