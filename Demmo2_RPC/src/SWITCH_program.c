/*
 * SWITCH_program.c
 *
 *  Created on: Feb 19, 2024
 *      Author: Aml Ashraf
 */

#include "STD_TYPES.h"
#include "Switch_interface.h"
#include "GPIO_interface.h"

extern SWITCH_strCfg SWITCHS[NUM_OF_SWITCHS];
static u8 state[NUM_OF_SWITCHS]= {0};

void SWITCH_init(void)
{
	u8 i;

	for(i=0;i<NUM_OF_SWITCHS;i++)
	{
			if(SWITCHS[i].Switch_struct_SwitchState == PULL_UP)
			{
				GPIO_voidSetPinMode(SWITCHS[i].Switch_struct_Port_Number,SWITCHS[i].Switch_struct_Pin_Number,GPIO_PIN_INPUT);
				GPIO_voidSetPinPullValue(SWITCHS[i].Switch_struct_Port_Number,SWITCHS[i].Switch_struct_Pin_Number,GPIO_PIN_PULL_UP);
			}
			else if(SWITCHS[i].Switch_struct_SwitchState == PULL_DOWN)
			{
				GPIO_voidSetPinMode(SWITCHS[i].Switch_struct_Port_Number,SWITCHS[i].Switch_struct_Pin_Number,GPIO_PIN_INPUT);
				GPIO_voidSetPinPullValue(SWITCHS[i].Switch_struct_Port_Number,SWITCHS[i].Switch_struct_Pin_Number,GPIO_PIN__PULL_DOWN);
			}


	}

}
/*

void SWITCH_IsPressed(u8 SWITCH_u8SwitchNum,u8 *ptr_u8switchPressed)
{
	u8 u8_switchStatus;

		GPIO_voidSetGetPinValue(SWITCHS[SWITCH_u8SwitchNum].Switch_struct_Port_Number,SWITCHS[SWITCH_u8SwitchNum].Switch_struct_Pin_Number,&u8_switchStatus);
		if((u8_switchStatus == 0 && SWITCHS[SWITCH_u8SwitchNum].Switch_struct_SwitchState == PULL_UP) || (u8_switchStatus == 1 && SWITCHS[SWITCH_u8SwitchNum].Switch_struct_SwitchState == PULL_DOWN))
		{

			*ptr_u8switchPressed = 1;
		}
		else if((u8_switchStatus == 1 && SWITCHS[SWITCH_u8SwitchNum].Switch_struct_SwitchState == PULL_UP) || (u8_switchStatus == 0 && SWITCHS[SWITCH_u8SwitchNum].Switch_struct_SwitchState == PULL_DOWN))
		{
			*ptr_u8switchPressed = 0;
		}



}
*/

void SWITCH_Runnuble(void)
{
	u8 i;
	u8 cur_state;
	static u8 previos_state[NUM_OF_SWITCHS]={0};
	static u8 counts[NUM_OF_SWITCHS]={0};

	for(i=0;i<NUM_OF_SWITCHS;i++)
	{

		GPIO_voidSetGetPinValue(SWITCHS[i].Switch_struct_Port_Number,SWITCHS[i].Switch_struct_Pin_Number,&cur_state);

		if(previos_state[i]== cur_state)
		{
			counts[i]++;

		}
		else
		{
			counts[i] = 0;

		}

		if(counts[i] == 4)
		{
			state[i]= cur_state;
			counts[i] = 0;

		}
		previos_state[i]= cur_state;

	}

}

u8 SWITCH_getState(u8 SWITCH_u8SwitchNum)
{
	return state[SWITCH_u8SwitchNum];
}
