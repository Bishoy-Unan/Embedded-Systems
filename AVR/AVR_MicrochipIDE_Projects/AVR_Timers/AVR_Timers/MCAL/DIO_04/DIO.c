/*###############################################################################################################################################*/
/* Author:	Bishoy Unan	 	   															   */
/* Date:	9/12/2023						            									       */
/* Version:	v1.0.4									 						 			     */
/* description: ATMwga32 DIO Driver							    					   				   */
/* Specs: 									      										   */
/* 01: DIO_enumError_t DIO_enumError_t DIO_enumSetCFG( PPRT_strCFG_t * ADD_strPORT_CFG )		*/
/* 02: DIO_enumError_t DIO_enumSetPortConfig(DIO_enumPorts_t Copy_enumPortNum , DIO_enumConfig_t Copy_enumConfig)					   */
/* 03: DIO_enumError_t DIO_enumSetPin(DIO_enumPorts_t Copy_enumPortNum , DIO_enumPins_t Copy_enumPintNum , DIO_enumLogicState_t Copy_enumLogicState) */
/* 04: DIO_enumError_t DIO_enumGetPin(DIO_enumPorts_t Copy_enumPortNum, DIO_enumPins_t Copy_enumPintNum , u8 * Pu8PinVal);				*/
/* 05: DIO_enumError_t DIO_enumSetPortVal( DIO_enumPorts_t Copy_enumPortName , DIO_enumLogicState_t Copy_eumStatus);		 						*/
/*###############################################################################################################################################*/



#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "DIO_Private.h"
#include "DIO.h"





/**
 *@brief  : Function to Configure the  LEDS Pins to be active high or active low ..
 *@param  : Address to struct in which i configure port num and pin num and pin configration.
 *@return : Error State                                               
 */	
DIO_enumError_t DIO_enumSetCFG( PPRT_strCFG_t * ADD_strPORT_CFG )
{
	DIO_enumError_t Ret_enumERRORStatus = DIO_enumOK  ; 
	
	if( ((ADD_strPORT_CFG -> PORT_strPORT) > DIO_enumPORTD) || ((ADD_strPORT_CFG -> PORT_strPORT) < DIO_enumPORTA) )
		{ 
			Ret_enumERRORStatus = DIO_enumINVALID_PORT ;
		}
	else if( ((ADD_strPORT_CFG -> PORT_strPIN) > DIO_enumPIN7) || ((ADD_strPORT_CFG -> PORT_strPIN) < DIO_enumPIN0) )
		{
			Ret_enumERRORStatus = DIO_enumINVALID_PIN ;
		}	
	else if( ((ADD_strPORT_CFG -> PORT_strCFGType) > DIO_enumInputExternalPullDown) || ((ADD_strPORT_CFG -> PORT_strCFGType) < DIO_enumOUTPUTHIGH) )
		{
			Ret_enumERRORStatus = DIO_enumINVALID_MODE ;
		}
	else
		{
			switch(ADD_strPORT_CFG -> PORT_strPORT)
			{
				case DIO_enumPORTA:
									switch(ADD_strPORT_CFG -> PORT_strCFGType){
										case DIO_enumOUTPUTHIGH:
												/*set port A(0:7) as ouput mode*/
												SET_BIT(DDRA,ADD_strPORT_CFG -> PORT_strPIN) ;		
												SET_BIT(PORTA,ADD_strPORT_CFG -> PORT_strPIN) ;		
										break;
										case DIO_enumOUTPUTLOW:
												/*set port A(0:7) as ouput mode*/
												SET_BIT(DDRA,ADD_strPORT_CFG -> PORT_strPIN) ;		
												CLR_BIT(PORTA,ADD_strPORT_CFG -> PORT_strPIN) ;		
										break;
										case DIO_enumInputPullUp:
												/*set this bit as input */
												CLR_BIT(DDRA,ADD_strPORT_CFG -> PORT_strPIN) ;
												/*Enable pull up resistor for this pin*/
												SET_BIT(PORTA,ADD_strPORT_CFG -> PORT_strPIN) ;			
										break;
										case DIO_enumInputExternalPullDown:
												/*set this bit as input*/
												CLR_BIT(DDRA,ADD_strPORT_CFG -> PORT_strPIN) ;
												/*diable pull up resistors*/
												CLR_BIT(PORTA,ADD_strPORT_CFG -> PORT_strPIN); 
										break;
										
										default:
										break;
									}//switch2
				break;
				case DIO_enumPORTB:
									switch(ADD_strPORT_CFG -> PORT_strCFGType){
										case DIO_enumOUTPUTHIGH:
												/*set port A(0:7) as ouput mode*/
												SET_BIT(DDRB,ADD_strPORT_CFG -> PORT_strPIN) ;		
												SET_BIT(PORTB,ADD_strPORT_CFG -> PORT_strPIN) ;		
										break;
										case DIO_enumOUTPUTLOW:
												/*set port A(0:7) as ouput mode*/
												SET_BIT(DDRB,ADD_strPORT_CFG -> PORT_strPIN) ;		
												CLR_BIT(PORTB,ADD_strPORT_CFG -> PORT_strPIN) ;		
										break;
										case DIO_enumInputPullUp:
												/*set this bit as input */
												CLR_BIT(DDRB,ADD_strPORT_CFG -> PORT_strPIN) ;
												/*Enable pull up resistor for this pin*/
												SET_BIT(PORTB,ADD_strPORT_CFG -> PORT_strPIN) ;			
										break;
										case DIO_enumInputExternalPullDown:
												/*set this bit as input*/
												CLR_BIT(DDRB,ADD_strPORT_CFG -> PORT_strPIN) ;
												/*diable pull up resistors*/
												CLR_BIT(PORTB,ADD_strPORT_CFG -> PORT_strPIN); 
										break;
										
										default:
										break;
									}//switch2
										
				break ;
				case DIO_enumPORTC:
									switch(ADD_strPORT_CFG -> PORT_strCFGType){
										case DIO_enumOUTPUTHIGH:
												/*set port A(0:7) as ouput mode*/
												SET_BIT(DDRC,ADD_strPORT_CFG -> PORT_strPIN) ;		
												SET_BIT(PORTC,ADD_strPORT_CFG -> PORT_strPIN) ;		
										break;
										case DIO_enumOUTPUTLOW:
												/*set port A(0:7) as ouput mode*/
												SET_BIT(DDRC,ADD_strPORT_CFG -> PORT_strPIN) ;		
												CLR_BIT(PORTC,ADD_strPORT_CFG -> PORT_strPIN) ;		
										break;
										case DIO_enumInputPullUp:
												/*set this bit as input */
												CLR_BIT(DDRC,ADD_strPORT_CFG -> PORT_strPIN) ;
												/*Enable pull up resistor for this pin*/
												SET_BIT(PORTC,ADD_strPORT_CFG -> PORT_strPIN) ;			
										break;
										case DIO_enumInputExternalPullDown:
												/*set this bit as input*/
												CLR_BIT(DDRC,ADD_strPORT_CFG -> PORT_strPIN) ;
												/*diable pull up resistors*/
												CLR_BIT(PORTC,ADD_strPORT_CFG -> PORT_strPIN); 
										break;
										
										default:
										break;
									}//switch2
				break;
				case DIO_enumPORTD:
									switch(ADD_strPORT_CFG -> PORT_strCFGType){
										case DIO_enumOUTPUTHIGH:
												/*set port A(0:7) as ouput mode*/
												SET_BIT(DDRD,ADD_strPORT_CFG -> PORT_strPIN) ;		
												SET_BIT(PORTD,ADD_strPORT_CFG -> PORT_strPIN) ;		
										break;
										case DIO_enumOUTPUTLOW:
												/*set port A(0:7) as ouput mode*/
												SET_BIT(DDRD,ADD_strPORT_CFG -> PORT_strPIN) ;		
												CLR_BIT(PORTD,ADD_strPORT_CFG -> PORT_strPIN) ;		
										break;
										case DIO_enumInputPullUp:
												/*set this bit as input */
												CLR_BIT(DDRD,ADD_strPORT_CFG -> PORT_strPIN) ;
												/*Enable pull up resistor for this pin*/
												SET_BIT(PORTD,ADD_strPORT_CFG -> PORT_strPIN) ;			
										break;
										case DIO_enumInputExternalPullDown:
												/*set this bit as input*/
												CLR_BIT(DDRD,ADD_strPORT_CFG -> PORT_strPIN) ;
												/*diable pull up resistors*/
												CLR_BIT(PORTD,ADD_strPORT_CFG -> PORT_strPIN); 
										break;
										
										default:
										break;
									}//switch2
				break;
				default :
				break;
			}//switch1
			
			
			
			
			
			
			
			Ret_enumERRORStatus = DIO_enumOK ;
		}//els
	return Ret_enumERRORStatus ;
	
	
	
	
	
}/*set pin configration function*/
/**************************************************************************************/
/**
 *@brief  : Function to Configure the whole Port(8 pins) at one time to be INPUT or OUTPUT port.
 *@param  : Port Number,Configuration type(Input/Output).
 *@return : Error State                                                                      
 */
DIO_enumError_t DIO_enumSetPortConfig(DIO_enumPorts_t Copy_enumPortNum , DIO_enumConfig_t Copy_enumConfig)
{
	DIO_enumError_t Ret_enumERRORStatus = DIO_enumOK  ; 
	
	if( (Copy_enumPortNum > DIO_enumPORTD) || (Copy_enumPortNum < DIO_enumPORTA))
		{ 
			Ret_enumERRORStatus = DIO_enumINVALID_PORT ;
		}
	else if( (Copy_enumConfig > DIO_enumInputExternalPullDown) || (Copy_enumConfig < DIO_enumOUTPUTHIGH))
		{
			Ret_enumERRORStatus = DIO_enumINVALID_MODE ;
		}
	else
		{
			switch(Copy_enumPortNum)
			{
				case DIO_enumPORTA:
									switch(Copy_enumConfig){
										case DIO_enumOUTPUTHIGH:
												/*set port A(0:7) as ouput moe*/
												DDRA = 0xFF;	
												PORTA = 0xFF;	
										break;
										case DIO_enumOUTPUTLOW:
										/*set port A(0:7) as ouput moe*/
										DDRA = 0xFF;
										PORTA = 0x00;
										break;
										case DIO_enumInputPullUp:
												DDRA = 0x00 ;
												PORTA = 0xFF ;		
										break;
										case DIO_enumInputExternalPullDown:
												DDRA = 0x00 ;
												/*diable pull up resistors*/
												PORTA = 0x00; 
										break;
										default:
										break;
									}//switch2
				break;
				case DIO_enumPORTB:
									switch(Copy_enumConfig){
										case DIO_enumOUTPUTHIGH:
										/*set port A(0:7) as ouput moe*/
										DDRB = 0xFF;
										PORTB = 0xFF;
										break;
										case DIO_enumOUTPUTLOW:
										/*set port A(0:7) as ouput moe*/
										DDRB = 0xFF;
										PORTB = 0x00;
										break;
										case DIO_enumInputPullUp:
												DDRB = 0x00 ;
												PORTB = 0xFF ;		
										break;
										case DIO_enumInputExternalPullDown:
												DDRB = 0x00 ;
												/*diable pull up resistors*/
												PORTB = 0x00; 
										break;
										default:
										break;
									}//switch2
				break ;
				case DIO_enumPORTC:
									switch(Copy_enumConfig){
										case DIO_enumOUTPUTHIGH:
										/*set port A(0:7) as ouput moe*/
										DDRC = 0xFF;
										PORTC = 0xFF;
										break;
										case DIO_enumOUTPUTLOW:
										/*set port A(0:7) as ouput moe*/
										DDRC = 0xFF;
										PORTC = 0x00;
										break;
										case DIO_enumInputPullUp:
												DDRC = 0x00 ;
												PORTC = 0xFF ;		
										break;
										case DIO_enumInputExternalPullDown:
												DDRC = 0x00 ;
												/*diable pull up resistors*/
												PORTC = 0x00; 
										break;
										default:
										break;
									}//switch2
				break;
				case DIO_enumPORTD:
									switch(Copy_enumConfig){
										case DIO_enumOUTPUTHIGH:
										/*set port A(0:7) as ouput moe*/
										DDRD = 0xFF;
										PORTD = 0xFF;
										break;
										case DIO_enumOUTPUTLOW:
										/*set port A(0:7) as ouput moe*/
										DDRD = 0xFF;
										PORTD = 0x00;
										break;
										case DIO_enumInputPullUp:
												DDRD = 0x00 ;
												PORTD = 0xFF ;		
										break;
										case DIO_enumInputExternalPullDown:
												DDRD = 0x00 ;
												/*diable pull up resistors*/
												PORTD = 0x00; 
										break;
										default:
										break;
									}//switch2
				break;
				default :
				break;
			}//switch1
			
			
			
			
			
			
			
			Ret_enumERRORStatus = DIO_enumOK ;
		}//els
	return Ret_enumERRORStatus ;
}/*set port configration function*/
/**************************************************************************************/
/**
 *@brief  : Function to Set the Pins to be Logic HIGH  or Logic LOW.
 *@param  : Port Number,Pin Number,Logic State(HIGH/LOW).
 *@return : Error State                                                                      
 */
DIO_enumError_t DIO_enumSetPinVal(DIO_enumPorts_t Copy_enumPortNum , DIO_enumPins_t Copy_enumPinNum , DIO_enumLogicState_t Copy_enumLogicState)
{
	
	DIO_enumError_t Ret_enumERRORStatus = DIO_enumOK  ; 
	
	if( (Copy_enumPortNum > DIO_enumPORTD) || (Copy_enumPortNum < DIO_enumPORTA))
		{ 
			Ret_enumERRORStatus = DIO_enumINVALID_PORT ;
		}
	else if( (Copy_enumPinNum > DIO_enumPIN7) || (Copy_enumPinNum < DIO_enumPIN0))
		{
			Ret_enumERRORStatus = DIO_enumINVALID_PIN ;
		}	
	else if( (Copy_enumLogicState > DIO_enumHIGH) || (Copy_enumLogicState < DIO_eumLOW))
		{
			Ret_enumERRORStatus = DIO_enumINVALID_VALUE ;
		}
	else
		{
			switch(Copy_enumPortNum)
			{
				case DIO_enumPORTA:
									
									switch(Copy_enumLogicState)
									{
										case DIO_eumLOW:
														/*clear bin in port A as ouput mode*/
														CLR_BIT(PORTA,Copy_enumPinNum) ;	
										break;
										case DIO_enumHIGH:
														/*set bin in port A as ouput mode*/
														SET_BIT(PORTA,Copy_enumPinNum) ;	
										break;
										default:
										break;
										
									}/*switch 2 */
										
									
				break;
				case DIO_enumPORTB:
									
									
									switch(Copy_enumLogicState)
									{
										case DIO_eumLOW:
														/*clear bin in port A as ouput mode*/
														CLR_BIT(PORTB,Copy_enumPinNum) ;	
										break;
										case DIO_enumHIGH:
														/*set bin in port A as ouput mode*/
														SET_BIT(PORTB,Copy_enumPinNum) ;	
										break;
										default:
										break;
										
									}/*switch 2 */
									
										
				break ;
				case DIO_enumPORTC:
									
									switch(Copy_enumLogicState)
									{
										case DIO_eumLOW:
														/*clear bin in port A as ouput mode*/
														CLR_BIT(PORTC,Copy_enumPinNum) ;	
										break;
										case DIO_enumHIGH:
														/*set bin in port A as ouput mode*/
														SET_BIT(PORTC,Copy_enumPinNum) ;	
										break;
										default:
										break;
										
									}/*switch 2 */
									
										
				break;
				case DIO_enumPORTD:
									
									switch(Copy_enumLogicState)
									{
										case DIO_eumLOW:
														/*clear bin in port A as ouput mode*/
														CLR_BIT(PORTD,Copy_enumPinNum) ;	
										break;
										case DIO_enumHIGH:
														/*set bin in port A as ouput mode*/
														SET_BIT(PORTD,Copy_enumPinNum) ;	
										break;
										default:
										break;
										
									}/*switch 2 */
										
				break;
				default :
				break;
			}//switch1
			
			
			
			
			
			
			
			Ret_enumERRORStatus = DIO_enumOK ;
		}//els
	return Ret_enumERRORStatus ;
	
	
	
	
	
	
}/*set bin value function*/
/**************************************************************************************/
/**
 *@brief  : Function to Read the Logic State of the Pin (Is it HIGH or LOW).
 *@param  : Port Number,Pin Number, Pointer points to unsigned char passed by address (to return the value of pin state).
 *@return : Error State                                                                     
 */
DIO_enumError_t DIO_enumGetPinVal(DIO_enumPorts_t Copy_enumPortNum, DIO_enumPins_t Copy_enumPinNum , u8 * Pu8PinVal)
{
	
	DIO_enumError_t Ret_enumERRORStatus = DIO_enumOK  ; 
	
	if( (Copy_enumPortNum > DIO_enumPORTD) || (Copy_enumPortNum < DIO_enumPORTA))
		{ 
			Ret_enumERRORStatus = DIO_enumINVALID_PORT ;
		}
	else if( (Copy_enumPinNum > DIO_enumPIN7) || (Copy_enumPinNum < DIO_enumPIN0))
		{
			Ret_enumERRORStatus = DIO_enumINVALID_PIN ;
		}	
	
	else
		{
			switch(Copy_enumPortNum)
			{
				case DIO_enumPORTA:
									*Pu8PinVal = GET_BIT(PINA,Copy_enumPinNum);
					
				break;
				case DIO_enumPORTB:
									*Pu8PinVal = GET_BIT(PINB,Copy_enumPinNum);
										
				break ;
				case DIO_enumPORTC:
									*Pu8PinVal = GET_BIT(PINC,Copy_enumPinNum);
										
				break;
				case DIO_enumPORTD:
									*Pu8PinVal = GET_BIT(PIND,Copy_enumPinNum);
										
				break;
				default :
				break;
			}//switch1
			
			
			
			
			
			
			
			Ret_enumERRORStatus = DIO_enumOK ;
		}//els
	return Ret_enumERRORStatus ;
	
	
}/*get bin value function*/
/**************************************************************************************/
/**
 *@brief : Function to Set the whole Port(8 pins) at one time to be Logic HIGH  or Logic LOW.
 *@param : Port Number,Logic State(HIGH/LOW).
 *@return: Error State.                                                                      
 */
DIO_enumError_t DIO_enumSetPortVal( DIO_enumPorts_t Copy_enumPortNum , DIO_enumLogicState_t Copy_eumStatus)
{
	DIO_enumError_t Ret_enumERRORStatus = DIO_enumOK  ; 
	
	if( (Copy_enumPortNum > DIO_enumPORTD) || (Copy_enumPortNum < DIO_enumPORTA))
		{ 
			Ret_enumERRORStatus = DIO_enumINVALID_PORT ;
		}
	
	else if( (Copy_eumStatus > DIO_enumHIGH) || (Copy_eumStatus < DIO_eumLOW))
		{
			Ret_enumERRORStatus = DIO_enumINVALID_VALUE ;
		}
	else
		{
			switch(Copy_enumPortNum)
			{
				case DIO_enumPORTA:
									switch(Copy_eumStatus)
									{
										case DIO_eumLOW:
													PORTA = 0x00;	
													
										break;
										case DIO_enumHIGH:
													PORTA = 0xFF;	
														
													
										break;
										default:
										break;
									}//SWITCH2	
				break;
				case DIO_enumPORTB:
									switch(Copy_eumStatus)
									{
										case DIO_eumLOW:
													PORTB = 0x00;	
													
										break;
										case DIO_enumHIGH:
													PORTB = 0xFF;	
														
													
										break;
										default:
										break;
									}//SWITCH2	
				break ;
				case DIO_enumPORTC:
									switch(Copy_eumStatus)
									{
										case DIO_eumLOW:
													PORTC = 0x00;	
													
										break;
										case DIO_enumHIGH:
													PORTC = 0xFF;	
														
													
										break;
										default:
										break;
									}//SWITCH2	
				break;
				case DIO_enumPORTD:
									switch(Copy_eumStatus)
									{
										case DIO_eumLOW:
													PORTD = 0x00;	
													
										break;
										case DIO_enumHIGH:
													PORTD = 0xFF;	
														
													
										break;
										default:
										break;
									}//SWITCH2	
				break;
				default :
				break;
			}//switch1
			
			
			
			
			
			
			
			Ret_enumERRORStatus = DIO_enumOK ;
		}//els
	return Ret_enumERRORStatus ;
	
	
	
	
}/*set port value function*/
/**************************************************************************************/






