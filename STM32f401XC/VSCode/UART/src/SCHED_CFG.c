
#include "SCHED_CFG.h"
#include "SCHED_Interface.h"
#include "app.h"



 const Runnable_t RunnableList[SCHED_RUNNABLE_NUM] = {
		                                                [0] = {
				                                                .RunnableCallBack = app ,
				                                                .Sched_enuPeriodicTimeMs = 1000
		                                                      }		,
														[1] = {
				                                                .RunnableCallBack = app1 ,
				                                                .Sched_enuPeriodicTimeMs = 2000
		                                                      }	 	,
														[2] = {
				                                                .RunnableCallBack = app2 ,
				                                                .Sched_enuPeriodicTimeMs = 3000
		                                                      }	  ,
														[3] = {
				                                                .RunnableCallBack = app3 ,
				                                                .Sched_enuPeriodicTimeMs = 4000
		                                                      }	  	  	   
                                                    };