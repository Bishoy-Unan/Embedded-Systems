/*==================================================
 * Author:	Bishoy Unan		
 * Date:	17/2/2024		
 * Version:	v1.0.0		
 * description: STM32F401CC SWITCH Driver Using 
 * Specs:		
 * 01: SWITCH_enumErrorState SWITCH_enumdInit(void);
 * SWITCH_enumErrorState SWITCH_enuGetSwitchState(u8 Copy_strSwitchPort , u8 * Add_u8State) 
 *=======================================================*/


#ifndef SWITCH_CFG_H
#define SWITCH_CFG_H








typedef enum 
{
	SWITCH1	,
	SWITCH2 ,
	SWITCH3 ,
	SWITCH4 ,
	SWITCH5 ,
	SWITCH6 ,
	SWITCH7 ,
	SWITCH8 ,
	SWITCH9 ,
	SWITCH10 ,
	
	
	_NUM_OF_SWITHs
	
}SWITCHs_t;






#endif