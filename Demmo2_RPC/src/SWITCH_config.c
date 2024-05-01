/*
 * SWITCH_config.c
 *
 *  Created on: Feb 19, 2024
 *      Author: Aml Ashraf
 */


#include "GPIO_interface.h"
#include "Switch_interface.h"

SWITCH_strCfg SWITCHS[NUM_OF_SWITCHS] =
				{
					[SWITCH_1] =
								{.Switch_struct_Port_Number = GPIOB,
								 .Switch_struct_Pin_Number= GPIO_PIN0,
								 .Switch_struct_SwitchState= PULL_UP,
								 },
					[SWITCH_2]  =
								{.Switch_struct_Port_Number = GPIOB,
								 .Switch_struct_Pin_Number= GPIO_PIN3,
								 .Switch_struct_SwitchState= PULL_UP,
								 },

				};

