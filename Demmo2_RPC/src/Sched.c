/*
 * Sched.c
 *
 *  Created on: Mar 24, 2024
 *      Author: Lenovo
 */

#include "STD_types.h"
#include "SYSTick_interface.h"
#include "Sched.h"

#define MAX_SUPPORTED_TASKS 3

static u32 PendingTicks;
typedef struct
{
	runnable_t *runnable;
	u32 remainTimeMs;

}runnableInfo_t;

static runnableInfo_t rInfo[MAX_SUPPORTED_TASKS];
u8 tickMs = 1;

void tickcb()
{
	PendingTicks++;

}

void sched_register_runnable(runnable_t *r)
{
	if(r && (rInfo[r->priority].runnable == NULL))
	{
		rInfo[r->priority].runnable = r;
		rInfo[r->priority].remainTimeMs = r->delayMS;

	}

}

// To enable timers
void sched_init(void)
{
	SYSTick_voidInit();
	SYSTick_voidSetCallBack(tickcb);

}

static void sched()
{
	u32 index;
	for(index = 0; index <MAX_SUPPORTED_TASKS; index++)
	{
		if(rInfo[index].remainTimeMs == 0)
		{
			rInfo[index].runnable->cb();
			rInfo[index].remainTimeMs= rInfo[index].runnable->periodicityMs;

		}
		rInfo[index].remainTimeMs -= tickMs;
	}

}

// all tasks must be created between the init and the start
// Although our implementation will allow tasks to be run after starting sched
void sched_start(void)
{
	SYSTick_voidStart((1*1000));

	while(1)
	{
		if(PendingTicks)
		{
			PendingTicks--;
			sched();
		}
	}

}




