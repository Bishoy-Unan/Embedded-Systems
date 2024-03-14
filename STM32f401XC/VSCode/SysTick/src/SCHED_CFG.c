
#include "SCHED_CFG.h"
#include "SCHED_Interface.h"
#include "app.h"



 const Runnable_t RunnableList[SCHED_RUNNABLE_NUM] = {
		                                                [0] = {
				                                                .RunnableCallBack = app ,
				                                                .Sched_enuPeriodicTimeMs = 1000
		                                                      }
                                                    };