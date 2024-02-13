/*########################################################*/
/* Author:	Bishoy Unan		*/
/* Date:	9/12/2023		*/
/* Version:	v1.0.0		*/
/* description: SWITCH Driver Using DIO V04*/
/* Specs:		*/
/* 01: SWITCH_enumErrorState LED_enumdInit(void);		*/
/* SWITCH_enumErrorState SWITCH_enuGetSwitchState(u8 Copy_strSwitchPort , u8 * Add_u8State) */
/*####################################################*/



#ifndef SWITCH_H
#define SWITCH_H



typedef enum
{
  SWITCH_enumOK ,
  SWITCH_enumNOK	
}SWITCH_enumErrorState;

/**
 *@brief  : Function to Configure the  SWITCHS Pins to be INPUT Pull up or input external pull down resistor .
 *@param  : Address to struct in which i configure port num and pin num and pin configration.
 *@return : Error State                                               
 */	
SWITCH_enumErrorState SWITCH_enumdInit(void);


/**
 *@brief  : Function to get switch state .
 *@param  : switch number and variable in which return switch state.
 *@return : Error State                                               
 */	
SWITCH_enumErrorState SWITCH_enuGetSwitchState(u8 Copy_strSwitchPort , u8 * Add_u8State);






#endif