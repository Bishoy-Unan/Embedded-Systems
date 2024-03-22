


#ifndef SCHED_INTERFACE_H
#define SCHED_INTERFACE_H


#include "STD_TYPES.h"



typedef enum {
  SCHED_enuOK,
  SCHED_enuNOK
}SCHED_enuErrStatus_t;

typedef struct {

	void ( * RunnableCallBack )(void);
	u32 Sched_enuPeriodicTimeMs;

}Runnable_t;




void SCHED_vidInit();
void SCHED_vidStart();

void SCHED_TickCallBack(void);

void Scheduler(void);

#endif