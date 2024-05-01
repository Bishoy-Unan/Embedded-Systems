/*
 * SWITCH_config.h
 *
 *  Created on: Feb 19, 2024
 *      Author: Aml Ashraf
 */

#ifndef SWITCH_CONFIG_H_
#define SWITCH_CONFIG_H_



#include "STD_TYPES.h"


#define  NUM_OF_SWITCHS		2

#define  SWITCH_1		0
#define  SWITCH_2		1

#define  PULL_UP			1
#define  PULL_DOWN			2

typedef struct
{
	void* Switch_struct_Port_Number;
	u8 Switch_struct_Pin_Number;
	u8 Switch_struct_SwitchState;

}SWITCH_strCfg;


#endif /* SWITCH_CONFIG_H_ */
