
#include "SCHED_CFG.h"
#include "SCHED_Interface.h"
#include "app.h"
#include "SWITCH.h"
#include "LCD.h"


 const Runnable_t RunnableList[SCHED_RUNNABLE_NUM] = {
														/*[0] = {
																.RunnableCallBack = SWITCH_vidDebounceTask  ,
																.Sched_enuPeriodicTimeMs = 5	,
																.Sched_u32Firstdelay = 0
															  }	   ,*/ 
														[0] = {
				                                                .RunnableCallBack = LCD_vidRunnable ,
				                                                .Sched_enuPeriodicTimeMs = 2	,
																.Sched_u32Firstdelay = 0
		                                                      }		  ,	  
														[1] = {
																.RunnableCallBack = app  ,
																.Sched_enuPeriodicTimeMs = 1000	,
																.Sched_u32Firstdelay = 40
															  }	  /* ,	  
		                                                [3] = {
				                                                .RunnableCallBack = app4 ,
				                                                .Sched_enuPeriodicTimeMs = 50	,
																.Sched_u32Firstdelay = 50
		                                                      }		,
														[4] = {
				                                                .RunnableCallBack = app1 ,
				                                                .Sched_enuPeriodicTimeMs = 2000	,
																.Sched_u32Firstdelay = 40
		                                                      }	 	,
														[5] = {
				                                                .RunnableCallBack = app2 ,
				                                                .Sched_enuPeriodicTimeMs = 3000	,
																.Sched_u32Firstdelay = 30
		                                                      }	  ,
														[6] = {
				                                                .RunnableCallBack = app3 ,
				                                                .Sched_enuPeriodicTimeMs = 4000	,
																.Sched_u32Firstdelay = 20
		                                                      }	*/  	
														
                                                    };