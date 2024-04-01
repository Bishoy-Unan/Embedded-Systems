
#include "SCHED_CFG.h"
#include "SCHED_Interface.h"
#include "app.h"
#include "SWITCH.h"
#include "LCD.h"


 const Runnable_t RunnableList[SCHED_RUNNABLE_NUM] = {
														[0] = {
																.RunnableCallBack = SWITCH_vidDebounceTask  ,
																.Sched_enuPeriodicTimeMs = 5
															  }	   , 
														[1] = {
																.RunnableCallBack = app4  ,
																.Sched_enuPeriodicTimeMs = 50
															  }	   ,	  
		                                                [2] = {
				                                                .RunnableCallBack = app ,
				                                                .Sched_enuPeriodicTimeMs = 1000
		                                                      }		,
														[3] = {
				                                                .RunnableCallBack = app1 ,
				                                                .Sched_enuPeriodicTimeMs = 2000
		                                                      }	 	,
														[4] = {
				                                                .RunnableCallBack = app2 ,
				                                                .Sched_enuPeriodicTimeMs = 3000
		                                                      }	  ,
														[5] = {
				                                                .RunnableCallBack = app3 ,
				                                                .Sched_enuPeriodicTimeMs = 4000
		                                                      }	  	,
														[6] = {
				                                                .RunnableCallBack = LCD_vidTask ,
				                                                .Sched_enuPeriodicTimeMs = 2
		                                                      }		  
                                                    };