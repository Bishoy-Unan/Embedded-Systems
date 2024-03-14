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



#ifndef SevenSegments_CFG_H
#define SevenSegments_CFG_H

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO_04/DIO.h"


#define NumOf_SevenSegments 	2

#define SevenSegments_1		0
#define SevenSegments_2 	1

#define SevenSegments_Leds_num	8



/**
*@ enum by which we configure Seven Segments connection if it common anode or common cathod
*@ you have to choose one state and configre it in the array in SevenSegments_Config.c
*/

typedef enum
{
	SevenSegments_enumCommonAnode	,

	SevenSegments_enumCommonCathod	

}SevenSegments_enumSTATE_t;




/**
*@ struct for each led in seven segments in which i configre which port and which pin 
*/
typedef struct{
	
			/**
			*@	DIO_enumPorts_t data type created in DIO.h to configure the port number
			*/
			DIO_enumPorts_t SevenSegments_strPORT ;
			
			DIO_enumPins_t SevenSegments_strPIN ;
	
}SevenSegments_strLED_CFG_t;


/**
*@ struct by which we configure ports and pins numbers and pins configrations
*/

typedef struct{

	
	/**
	*@ struct by which we configure ports and pins numbers and pins configrations
	*/
	SevenSegments_strLED_CFG_t	SevenSegments_strLED[SevenSegments_Leds_num] ; 
	/**
	*@ SevenSegments_enumSTATE_t data type created in SevenSegments_Config.h to configure the SevenSegment state
	*/
	SevenSegments_enumSTATE_t SevenSegments_strSTATE ;
	
}SevenSegments_strCFG_t;









#endif