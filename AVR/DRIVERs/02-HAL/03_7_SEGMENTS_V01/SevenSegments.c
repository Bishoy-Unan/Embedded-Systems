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


extern SevenSegments_strCFG_t SevenSegments[NumOf_SevenSegments];

/**
 *@brief  : Function to Configure the  SevenSgments port and Pins and connection .
 *@param  : Address to struct in which i configure port and Pins and connection.
 *@return : Error State                                               
 */
SevenSegments_enumErrorState_t SevenSegments_enumInit(void)
{
	SevenSegments_enumErrorState_t LOCAL_enumReturnStatus = SevenSegments_enumOK ;
	
	u8 LOCAL_u8SegmentIterator1 = 0 ;
	
	u8 LOCAL_u8LedIterator2 = 0 ;
	
	PPRT_strCFG_t LOCAL_strCurrentSevenSegments[NumOf_SevenSegments];
	
	/**
	*@ for looping in each elemnt of array
	*/
	for( LOCAL_u8SegmentIterator1 = 0 ; LOCAL_u8SegmentIterator1 < NumOf_SevenSegments ; LOCAL_u8SegmentIterator1++)
	{
	
		
		//LOCAL_strCurrentSevenSegments[LOCAL_u8SegmentIterator1].PORT_strPIN  =  SevenSegments[LOCAL_u8SegmentIterator1].SevenSegments_strLED.SevenSegments_strLED_A ;
		
		/**
		*@ for looping in each led configration of the seven segment
		*/
		for( LOCAL_u8LedIterator2 = 0 ; LOCAL_u8LedIterator2 < SevenSegments_Leds_num ; LOCAL_u8LedIterator2++ ){
			
			
			LOCAL_strCurrentSevenSegments[LOCAL_u8SegmentIterator1].PORT_strPORT = SevenSegments[LOCAL_u8SegmentIterator1].SevenSegments_strLED[LOCAL_u8LedIterator2].SevenSegments_strPORT ;
			
			LOCAL_strCurrentSevenSegments[LOCAL_u8SegmentIterator1].PORT_strPIN  =  SevenSegments[LOCAL_u8SegmentIterator1].SevenSegments_strLED[LOCAL_u8LedIterator2].SevenSegments_strPIN ;
			
			switch (SevenSegments[LOCAL_u8SegmentIterator1].SevenSegments_strSTATE){
				
						case SevenSegments_enumCommonAnode :
								LOCAL_strCurrentSevenSegments[LOCAL_u8SegmentIterator1].PORT_strCFGType =  DIO_enumOUTPUTLOW ;
						break;
						case SevenSegments_enumCommonCathod:
								LOCAL_strCurrentSevenSegments[LOCAL_u8SegmentIterator1].PORT_strCFGType =  DIO_enumOUTPUTHIGH ;
						break;
						default:
						break;
				
			}/*switch1*/
			
			
			
			/**
			*@ call DIO_enumSetCFG function to set configration of each led of seven segment in DIO Driver
			*@ and check return of DIO_enumSetCFG function ok or not ok
			*/		
			DIO_enumSetCFG( & LOCAL_strCurrentSevenSegments [LOCAL_u8SegmentIterator1] );
				
			if( ! (DIO_enumSetCFG( & LOCAL_strCurrentSevenSegments [LOCAL_u8SegmentIterator1] ))){
				LOCAL_enumReturnStatus = SevenSegments_enumOK ;
			}/*if*/
			else {
				LOCAL_enumReturnStatus = SevenSegments_enumNOK ;
			}/*else*/
			
			
			
			
		}/*for2*/
		
	
			
	}/*for1*/
	

return LOCAL_enumReturnStatus ;
	
	
}/*led init function */



/**
 *@brief  : Function in which i select which seven segment i want to set and the value to be set .
 *@param  : Number of seven segment and the value.
 *@return : Error State                                               
 */
SevenSegments_enumErrorState_t SevenSegments_enumSetVal(u8 SevenSegment_Num , SevenSegments_enumVal_t SevenSegments_enumNum )
{
	/**
	*@ LOCAL_enumReturnStatus The function return value
	*/
	SevenSegments_enumErrorState_t LOCAL_enumReturnStatus = SevenSegments_enumOK ;
	/**
	*@ iterator used in for loop
	*/
	//u8 LOCAL_u8LedIterator = 0 ;
	
	if (  (SevenSegment_Num > NumOf_SevenSegments) || (SevenSegment_Num < 1 ) )
		{ 
			 LOCAL_enumReturnStatus = SevenSegments_enumNOK ;
		}
	else if ( (SevenSegments_enumNum > nine) || (SevenSegments_enumNum < zero) )
		{
			LOCAL_enumReturnStatus = SevenSegments_enumNOK ;
		}
	/**
	*@ check the connection mode if it common ande or common cathod
	*@ subtract 1 from input value to be right index in the array of seven segments
	*/
	u8 LOCAL_u8SevSegArrayIndex = SevenSegment_Num  ;
	
	switch(SevenSegments[(LOCAL_u8SevSegArrayIndex)].SevenSegments_strSTATE){
		
		case SevenSegments_enumCommonCathod:
						switch (SevenSegments_enumNum){
								
								case zero:
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDA].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDA].SevenSegments_strPIN , DIO_enumHIGH );
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDB].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDB].SevenSegments_strPIN , DIO_enumHIGH );
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDC].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDC].SevenSegments_strPIN , DIO_enumHIGH );
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDD].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDD].SevenSegments_strPIN , DIO_enumHIGH );
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDE].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDE].SevenSegments_strPIN , DIO_enumHIGH );
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDF].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDF].SevenSegments_strPIN , DIO_enumHIGH );
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDG].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDG].SevenSegments_strPIN , DIO_eumLOW );
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_DOT].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_DOT].SevenSegments_strPIN , DIO_enumHIGH );
								break;
								case one:
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDA].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDA].SevenSegments_strPIN , DIO_eumLOW );
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDB].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDB].SevenSegments_strPIN , DIO_enumHIGH );
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDC].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDC].SevenSegments_strPIN , DIO_enumHIGH );
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDD].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDD].SevenSegments_strPIN , DIO_eumLOW );
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDE].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDE].SevenSegments_strPIN , DIO_eumLOW );
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDF].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDF].SevenSegments_strPIN , DIO_eumLOW );
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDG].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDG].SevenSegments_strPIN , DIO_eumLOW );
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_DOT].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_DOT].SevenSegments_strPIN , DIO_enumHIGH );
								break;
								case two:
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDA].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDA].SevenSegments_strPIN , DIO_enumHIGH );
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDB].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDB].SevenSegments_strPIN , DIO_enumHIGH );
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDC].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDC].SevenSegments_strPIN , DIO_eumLOW );
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDD].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDD].SevenSegments_strPIN , DIO_enumHIGH );
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDE].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDE].SevenSegments_strPIN , DIO_enumHIGH );
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDF].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDF].SevenSegments_strPIN , DIO_eumLOW );
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDG].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDG].SevenSegments_strPIN , DIO_enumHIGH );
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_DOT].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_DOT].SevenSegments_strPIN , DIO_enumHIGH );
								break;
								case three:
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDA].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDA].SevenSegments_strPIN , DIO_enumHIGH );
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDB].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDB].SevenSegments_strPIN , DIO_enumHIGH );
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDC].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDC].SevenSegments_strPIN , DIO_enumHIGH );
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDD].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDD].SevenSegments_strPIN , DIO_enumHIGH );
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDE].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDE].SevenSegments_strPIN , DIO_eumLOW );
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDF].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDF].SevenSegments_strPIN , DIO_eumLOW );
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDG].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDG].SevenSegments_strPIN , DIO_enumHIGH );
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_DOT].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_DOT].SevenSegments_strPIN , DIO_enumHIGH );
								break;
								case four:
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDA].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDA].SevenSegments_strPIN , DIO_eumLOW );
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDB].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDB].SevenSegments_strPIN , DIO_enumHIGH );
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDC].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDC].SevenSegments_strPIN , DIO_enumHIGH );
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDD].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDD].SevenSegments_strPIN , DIO_eumLOW );
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDE].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDE].SevenSegments_strPIN , DIO_eumLOW );
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDF].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDF].SevenSegments_strPIN , DIO_enumHIGH );
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDG].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDG].SevenSegments_strPIN , DIO_enumHIGH );
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_DOT].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_DOT].SevenSegments_strPIN , DIO_enumHIGH );
								break;
								case five:
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDA].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDA].SevenSegments_strPIN , DIO_enumHIGH );
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDB].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDB].SevenSegments_strPIN , DIO_eumLOW );
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDC].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDC].SevenSegments_strPIN , DIO_enumHIGH );
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDD].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDD].SevenSegments_strPIN , DIO_enumHIGH );
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDE].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDE].SevenSegments_strPIN , DIO_eumLOW );
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDF].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDF].SevenSegments_strPIN , DIO_enumHIGH );
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDG].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDG].SevenSegments_strPIN , DIO_enumHIGH );
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_DOT].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_DOT].SevenSegments_strPIN , DIO_enumHIGH );
								break;
								case six:
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDA].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDA].SevenSegments_strPIN , DIO_enumHIGH );
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDB].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDB].SevenSegments_strPIN , DIO_eumLOW );
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDC].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDC].SevenSegments_strPIN , DIO_enumHIGH );
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDD].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDD].SevenSegments_strPIN , DIO_enumHIGH );
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDE].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDE].SevenSegments_strPIN , DIO_enumHIGH );
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDF].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDF].SevenSegments_strPIN , DIO_enumHIGH );
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDG].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDG].SevenSegments_strPIN , DIO_enumHIGH );
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_DOT].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_DOT].SevenSegments_strPIN , DIO_enumHIGH );
								break;
								case seven:
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDA].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDA].SevenSegments_strPIN , DIO_enumHIGH );
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDB].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDB].SevenSegments_strPIN , DIO_enumHIGH );
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDC].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDC].SevenSegments_strPIN , DIO_enumHIGH );
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDD].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDD].SevenSegments_strPIN , DIO_eumLOW );
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDE].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDE].SevenSegments_strPIN , DIO_eumLOW );
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDF].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDF].SevenSegments_strPIN , DIO_eumLOW );
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDG].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDG].SevenSegments_strPIN , DIO_eumLOW );
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_DOT].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_DOT].SevenSegments_strPIN , DIO_enumHIGH );
								break;
								case eight:
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDA].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDA].SevenSegments_strPIN , DIO_enumHIGH );
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDB].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDB].SevenSegments_strPIN , DIO_enumHIGH );
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDC].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDC].SevenSegments_strPIN , DIO_enumHIGH );
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDD].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDD].SevenSegments_strPIN , DIO_enumHIGH );
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDE].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDE].SevenSegments_strPIN , DIO_enumHIGH );
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDF].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDF].SevenSegments_strPIN , DIO_enumHIGH );
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDG].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDG].SevenSegments_strPIN , DIO_enumHIGH );
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_DOT].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_DOT].SevenSegments_strPIN , DIO_enumHIGH );
								break;
								case nine :
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDA].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDA].SevenSegments_strPIN , DIO_enumHIGH );
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDB].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDB].SevenSegments_strPIN , DIO_enumHIGH );
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDC].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDC].SevenSegments_strPIN , DIO_enumHIGH );
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDD].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDD].SevenSegments_strPIN , DIO_enumHIGH );
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDE].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDE].SevenSegments_strPIN , DIO_eumLOW );
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDF].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDF].SevenSegments_strPIN , DIO_enumHIGH );
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDG].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDG].SevenSegments_strPIN , DIO_enumHIGH );
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_DOT].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_DOT].SevenSegments_strPIN , DIO_enumHIGH );
								break;
								default:
								break;
						}/*switch two*/
		break;
		case SevenSegments_enumCommonAnode :
						switch (SevenSegments_enumNum){
								
								case zero:
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDA].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDA].SevenSegments_strPIN , DIO_eumLOW );
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDB].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDB].SevenSegments_strPIN , DIO_eumLOW );
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDC].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDC].SevenSegments_strPIN , DIO_eumLOW );
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDD].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDD].SevenSegments_strPIN , DIO_eumLOW );
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDE].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDE].SevenSegments_strPIN , DIO_eumLOW );
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDF].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDF].SevenSegments_strPIN , DIO_eumLOW );
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDG].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDG].SevenSegments_strPIN , DIO_enumHIGH );
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_DOT].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_DOT].SevenSegments_strPIN , DIO_eumLOW );
								break;
								case one:
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDA].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDA].SevenSegments_strPIN , DIO_enumHIGH );
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDB].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDB].SevenSegments_strPIN , DIO_eumLOW );
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDC].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDC].SevenSegments_strPIN , DIO_eumLOW );
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDD].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDD].SevenSegments_strPIN , DIO_enumHIGH );
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDE].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDE].SevenSegments_strPIN , DIO_enumHIGH );
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDF].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDF].SevenSegments_strPIN , DIO_enumHIGH );
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDG].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDG].SevenSegments_strPIN , DIO_enumHIGH );
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_DOT].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_DOT].SevenSegments_strPIN , DIO_eumLOW );
								break;
								case two:
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDA].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDA].SevenSegments_strPIN , DIO_eumLOW );
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDB].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDB].SevenSegments_strPIN , DIO_eumLOW );
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDC].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDC].SevenSegments_strPIN , DIO_enumHIGH );
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDD].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDD].SevenSegments_strPIN , DIO_eumLOW );
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDE].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDE].SevenSegments_strPIN , DIO_eumLOW );
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDF].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDF].SevenSegments_strPIN , DIO_enumHIGH );
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDG].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDG].SevenSegments_strPIN , DIO_eumLOW );
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_DOT].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_DOT].SevenSegments_strPIN , DIO_eumLOW );
								break;
								case three:
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDA].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDA].SevenSegments_strPIN , DIO_eumLOW );
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDB].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDB].SevenSegments_strPIN , DIO_eumLOW );
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDC].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDC].SevenSegments_strPIN , DIO_eumLOW );
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDD].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDD].SevenSegments_strPIN , DIO_eumLOW );
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDE].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDE].SevenSegments_strPIN , DIO_enumHIGH );
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDF].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDF].SevenSegments_strPIN , DIO_enumHIGH );
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDG].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDG].SevenSegments_strPIN , DIO_eumLOW );
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_DOT].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_DOT].SevenSegments_strPIN , DIO_eumLOW );
								break;
								case four:
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDA].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDA].SevenSegments_strPIN , DIO_enumHIGH );
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDB].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDB].SevenSegments_strPIN , DIO_eumLOW );
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDC].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDC].SevenSegments_strPIN , DIO_eumLOW );
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDD].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDD].SevenSegments_strPIN , DIO_enumHIGH );
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDE].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDE].SevenSegments_strPIN , DIO_enumHIGH );
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDF].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDF].SevenSegments_strPIN , DIO_eumLOW );
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDG].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDG].SevenSegments_strPIN , DIO_eumLOW );
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_DOT].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_DOT].SevenSegments_strPIN , DIO_eumLOW );
								break;
								case five:
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDA].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDA].SevenSegments_strPIN , DIO_eumLOW );
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDB].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDB].SevenSegments_strPIN , DIO_enumHIGH );
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDC].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDC].SevenSegments_strPIN , DIO_eumLOW );
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDD].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDD].SevenSegments_strPIN , DIO_eumLOW );
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDE].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDE].SevenSegments_strPIN , DIO_enumHIGH );
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDF].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDF].SevenSegments_strPIN , DIO_eumLOW );
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDG].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDG].SevenSegments_strPIN , DIO_eumLOW );
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_DOT].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_DOT].SevenSegments_strPIN , DIO_eumLOW );
								break;
								case six:
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDA].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDA].SevenSegments_strPIN , DIO_eumLOW );
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDB].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDB].SevenSegments_strPIN , DIO_enumHIGH );
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDC].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDC].SevenSegments_strPIN , DIO_eumLOW );
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDD].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDD].SevenSegments_strPIN , DIO_eumLOW );
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDE].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDE].SevenSegments_strPIN , DIO_eumLOW );
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDF].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDF].SevenSegments_strPIN , DIO_eumLOW );
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDG].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDG].SevenSegments_strPIN , DIO_eumLOW );
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_DOT].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_DOT].SevenSegments_strPIN , DIO_eumLOW );
								break;
								case seven:
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDA].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDA].SevenSegments_strPIN , DIO_eumLOW );
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDB].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDB].SevenSegments_strPIN , DIO_eumLOW );
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDC].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDC].SevenSegments_strPIN , DIO_eumLOW );
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDD].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDD].SevenSegments_strPIN , DIO_enumHIGH );
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDE].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDE].SevenSegments_strPIN , DIO_enumHIGH );
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDF].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDF].SevenSegments_strPIN , DIO_enumHIGH );
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDG].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDG].SevenSegments_strPIN , DIO_enumHIGH );
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_DOT].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_DOT].SevenSegments_strPIN , DIO_eumLOW );
								break;
								case eight:
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDA].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDA].SevenSegments_strPIN , DIO_eumLOW );
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDB].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDB].SevenSegments_strPIN , DIO_eumLOW );
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDC].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDC].SevenSegments_strPIN , DIO_eumLOW );
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDD].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDD].SevenSegments_strPIN , DIO_eumLOW );
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDE].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDE].SevenSegments_strPIN , DIO_eumLOW );
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDF].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDF].SevenSegments_strPIN , DIO_eumLOW );
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDG].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDG].SevenSegments_strPIN , DIO_eumLOW );
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_DOT].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_DOT].SevenSegments_strPIN , DIO_eumLOW );
								break;
								case nine :
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDA].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDA].SevenSegments_strPIN , DIO_eumLOW );
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDB].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDB].SevenSegments_strPIN , DIO_eumLOW );
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDC].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDC].SevenSegments_strPIN , DIO_eumLOW );
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDD].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDD].SevenSegments_strPIN , DIO_eumLOW );
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDE].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDE].SevenSegments_strPIN , DIO_enumHIGH );
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDF].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDF].SevenSegments_strPIN , DIO_eumLOW );
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDG].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_LEDG].SevenSegments_strPIN , DIO_eumLOW );
										DIO_enumSetPinVal(SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_DOT].SevenSegments_strPORT , SevenSegments[LOCAL_u8SevSegArrayIndex].SevenSegments_strLED[SevenSegments_DOT].SevenSegments_strPIN , DIO_eumLOW );
								break;
								default:
								break;
						}/*switch two*/
		break;
		default:
		break;
		
	}/*switch 1*/
	
return LOCAL_enumReturnStatus ;
	
}/* SevenSegments_enumSetVal function*/





/**
 *@brief  : Function take vlue and show it in available seven segments .
 *@param  : u8Value : the value i want to show.
 *@return : Error State                                               
 */
SevenSegments_enumErrorState_t SevenSegments_enumVal(u8 u8Value)
{
	/**
	*@ LOCAL_enumReturnStatus The function return value
	*/
	SevenSegments_enumErrorState_t LOCAL_enumReturnStatus = SevenSegments_enumOK ;
	/**
	*@ variable to select which 7 segment will be set
	*/
	u8 LOCAL_u8SevenSegmentNum = 1 ;
	/**
	*@ variable hold the most right digit of input number to be set
	*/
	u8 LOCAL_u8Remainder = 0  ;
	
	while(u8Value != 0 ){
		
		LOCAL_u8Remainder = ( u8Value % TEN ) ;
		
		u8Value = ( u8Value  / 10 );
		
		//LOCAL_u8SevenSegmentNum = 1 ;
		
		 LOCAL_enumReturnStatus = SevenSegments_enumSetVal( LOCAL_u8SevenSegmentNum++ , LOCAL_u8Remainder );
		
		
		
	}/*while 1*/
	
	
	
return 	LOCAL_enumReturnStatus ;
	
}/*SevenSegments_enumVal function*/



