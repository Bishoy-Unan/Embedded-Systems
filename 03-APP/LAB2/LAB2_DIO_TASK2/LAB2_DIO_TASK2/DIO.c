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







