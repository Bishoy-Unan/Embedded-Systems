/*########################################################*/
/* Author:	Bishoy Unan		*/
/* Date:	16/12/2023		*/
/* Version:	v1.0.0		*/
/* description: SevenSegments Driver Using DIO V04*/
/* Specs:		*/
/* 01: SevenSegments_enumErrorState_t SevenSegments_enumdInit(void)	*/
/* 02: SevenSegments_enumErrorState_t SevenSegments_enumSetVal(u8 SevenSegment_Num , SevenSegments_enumVal_t SevenSegments_enumNum );*/
/* 03: SevenSegments_enumErrorState_t SevenSegments_enumVal(u8 u8Value);*/
/*####################################################*/



#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "SevenSegments.h"
#include "SevenSegments_Config.h"
#include "../../MCAL/DIO_04/DIO.h"



/**
*@ araay of SevenSegments_strCFG_t data type in which we configure ports and pins for each led of SevenSegments and connection mode of it
*@and configure pins of SevenSegments and SevenSegments status
*/
SevenSegments_strCFG_t SevenSegments[NumOf_SevenSegments] =  { 
																[SevenSegments_1] = {.SevenSegments_strLED[SevenSegments_LEDA].SevenSegments_strPORT = DIO_enumPORTA , 
																					 .SevenSegments_strLED[SevenSegments_LEDA].SevenSegments_strPIN = DIO_enumPIN0 , 
																					 .SevenSegments_strLED[SevenSegments_LEDB].SevenSegments_strPORT = DIO_enumPORTA , 
																					 .SevenSegments_strLED[SevenSegments_LEDB].SevenSegments_strPIN = DIO_enumPIN1 ,
																					 .SevenSegments_strLED[SevenSegments_LEDC].SevenSegments_strPORT = DIO_enumPORTA , 
																					 .SevenSegments_strLED[SevenSegments_LEDC].SevenSegments_strPIN = DIO_enumPIN2 ,
																					 .SevenSegments_strLED[SevenSegments_LEDD].SevenSegments_strPORT = DIO_enumPORTA , 
																					 .SevenSegments_strLED[SevenSegments_LEDD].SevenSegments_strPIN = DIO_enumPIN3 ,
																					 .SevenSegments_strLED[SevenSegments_LEDE].SevenSegments_strPORT = DIO_enumPORTA , 
																					 .SevenSegments_strLED[SevenSegments_LEDE].SevenSegments_strPIN = DIO_enumPIN4 ,
																					 .SevenSegments_strLED[SevenSegments_LEDF].SevenSegments_strPORT = DIO_enumPORTA , 
																					 .SevenSegments_strLED[SevenSegments_LEDF].SevenSegments_strPIN = DIO_enumPIN5 ,
																					 .SevenSegments_strLED[SevenSegments_LEDG].SevenSegments_strPORT = DIO_enumPORTA , 
																					 .SevenSegments_strLED[SevenSegments_LEDG].SevenSegments_strPIN = DIO_enumPIN6 ,
																					 .SevenSegments_strLED[SevenSegments_DOT].SevenSegments_strPORT = DIO_enumPORTA , 
																					 .SevenSegments_strLED[SevenSegments_DOT].SevenSegments_strPIN = DIO_enumPIN7 ,
																					 .SevenSegments_strSTATE = SevenSegments_enumCommonCathod }  ,
																[SevenSegments_2] = {.SevenSegments_strLED[SevenSegments_LEDA].SevenSegments_strPORT = DIO_enumPORTB , 
																					 .SevenSegments_strLED[SevenSegments_LEDA].SevenSegments_strPIN = DIO_enumPIN0 , 
																					 .SevenSegments_strLED[SevenSegments_LEDB].SevenSegments_strPORT = DIO_enumPORTB , 
																					 .SevenSegments_strLED[SevenSegments_LEDB].SevenSegments_strPIN = DIO_enumPIN1 ,
																					 .SevenSegments_strLED[SevenSegments_LEDC].SevenSegments_strPORT = DIO_enumPORTB , 
																					 .SevenSegments_strLED[SevenSegments_LEDC].SevenSegments_strPIN = DIO_enumPIN2 ,
																					 .SevenSegments_strLED[SevenSegments_LEDD].SevenSegments_strPORT = DIO_enumPORTB , 
																					 .SevenSegments_strLED[SevenSegments_LEDD].SevenSegments_strPIN = DIO_enumPIN3 ,
																					 .SevenSegments_strLED[SevenSegments_LEDE].SevenSegments_strPORT = DIO_enumPORTB , 
																					 .SevenSegments_strLED[SevenSegments_LEDE].SevenSegments_strPIN = DIO_enumPIN4 ,
																					 .SevenSegments_strLED[SevenSegments_LEDF].SevenSegments_strPORT = DIO_enumPORTB , 
																					 .SevenSegments_strLED[SevenSegments_LEDF].SevenSegments_strPIN = DIO_enumPIN5 ,
																					 .SevenSegments_strLED[SevenSegments_LEDG].SevenSegments_strPORT = DIO_enumPORTB , 
																					 .SevenSegments_strLED[SevenSegments_LEDG].SevenSegments_strPIN = DIO_enumPIN6 ,
																					 .SevenSegments_strLED[SevenSegments_DOT].SevenSegments_strPORT = DIO_enumPORTB , 
																					 .SevenSegments_strLED[SevenSegments_DOT].SevenSegments_strPIN = DIO_enumPIN7 ,
																					 .SevenSegments_strSTATE = SevenSegments_enumCommonCathod  }			
															}; /* SevenSegments ARRAY*/