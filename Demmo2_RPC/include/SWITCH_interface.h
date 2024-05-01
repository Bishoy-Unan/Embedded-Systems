/*
 * SWITCH_interface.h
 *
 *  Created on: Feb 19, 2024
 *      Author: Aml Ashraf
 */

#ifndef SWITCH_INTERFACE_H_
#define SWITCH_INTERFACE_H_

#include "SWITCH_config.h"
#include "GPIO_interface.h"

#define  START_SWITCH			0
#define  STOP_SWITCH			1

#define SWITCH_PULLUP_PRESSED 		0
#define SWITCH_PULLDOWN_PRESSED 	1

void SWITCH_init(void);

u8 SWITCH_getState(u8 SWITCH_u8SwitchNum);

//void SWITCH_IsPressed(u8 SWITCH_u8SwitchNum,u8 *ptr_u8switchPressed);

#endif /* SWITCH_INTERFACE_H_ */
