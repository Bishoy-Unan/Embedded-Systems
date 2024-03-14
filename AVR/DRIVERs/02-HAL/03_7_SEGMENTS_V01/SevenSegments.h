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


#ifndef SevenSegments_H
#define SevenSegments_H


#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#define ZERO
#define ONE

#define SevenSegments_LEDA	0
#define SevenSegments_LEDB	1
#define SevenSegments_LEDC	2
#define SevenSegments_LEDD	3
#define SevenSegments_LEDE	4
#define SevenSegments_LEDF	5
#define SevenSegments_LEDG	6
#define SevenSegments_DOT	7

#define TEN 10


/**
*@ enum of error status in Seven segment Driver
*/
typedef enum
{
  SevenSegments_enumOK ,
  
  SevenSegments_enumNOK	

  }SevenSegments_enumErrorState_t ;


/**
*@ enum of available valid patterns to show in seven segments (numbers 0:9 )
*/  
typedef enum{
			
			zero	,
			one		,
			two		,
			three	,
			four	,
			five	,
			six		,
			seven	,
			eight	,
			nine	
			
}SevenSegments_enumVal_t ;
  
  
  
  
/**
 *@brief  : Function to Configure the  SevenSgments port and Pins and connection .
 *@param  : Nothing.
 *@return : Error State                                               
 */
SevenSegments_enumErrorState_t SevenSegments_enumInit(void);

/**
 *@brief  : Function in which i select which seven segment i want to set and the value to be set .
 *@ the value to be set must be elemnt of SevenSegments_enumVal_t data type
 *@param  : Number of seven segment and the value.
 *@return : Error State                                               
 */
SevenSegments_enumErrorState_t SevenSegments_enumSetVal(u8 SevenSegment_Num , SevenSegments_enumVal_t SevenSegments_enumNum );

/**
 *@brief  : Function take vlue and show it in available seven segments .
 *@param  : u8Value : the value i want to show.
 *@return : Error State                                               
 */
SevenSegments_enumErrorState_t SevenSegments_enumVal(u8 u8Value);






#endif