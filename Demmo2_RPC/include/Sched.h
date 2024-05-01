/*
 * Sched.h
 *
 *  Created on: Mar 24, 2024
 *      Author: Lenovo
 */

#ifndef SCHED_H_
#define SCHED_H_


typedef void (*runnableCb_t) (void);

// for any configurations configurable by the use
typedef struct
{
	u8 *name;
	u32 delayMS; // time until the task is first executed
	u32 periodicityMs;
	u32 priority;
	runnableCb_t cb;

}runnable_t;


void sched_register_runnable(runnable_t *runnable);

// To enable timers
void sched_init(void);


// all tasks must be created between the init and the start
// Although our implementation will allow tasks to be run after starting sched
void sched_start(void);


#endif /* SCHED_H_ */
