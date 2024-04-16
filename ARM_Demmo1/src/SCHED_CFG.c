
#include "SCHED_CFG.h"
#include "SCHED_Interface.h"
#include "app.h"
#include "SWITCH.h"
#include "LCD.h"


 const Runnable_t RunnableList[SCHED_RUNNABLE_NUM] = {
														[0] = {
																.RunnableCallBack = SWITCH_vidDebounceTask  ,
																.Sched_enuPeriodicTimeMs = 5	,
																.Sched_u32Firstdelay = 0
															  }	   , 
														[1] = {
				                                                .RunnableCallBack = LCD_vidRunnable ,
				                                                .Sched_enuPeriodicTimeMs = 2	,
																.Sched_u32Firstdelay = 0
		                                                      }		  ,	  
														[2] = {
																.RunnableCallBack = Watch_Runnable  ,
																.Sched_enuPeriodicTimeMs = 50	,
																.Sched_u32Firstdelay = 0
															  }	   ,	  
		                                                [3] = {
				                                                .RunnableCallBack = DisplayWatch_Runnable ,
				                                                .Sched_enuPeriodicTimeMs = 20	,
																.Sched_u32Firstdelay = 0
		                                                      }		,
														[4] = {
				                                                .RunnableCallBack = UART_vidRunnable ,
				                                                .Sched_enuPeriodicTimeMs = 200	,
																.Sched_u32Firstdelay = 0
		                                                      }	 	,
														[5] = {
				                                                .RunnableCallBack = DisplayDate_Runnable ,
				                                                .Sched_enuPeriodicTimeMs = 40	,
																.Sched_u32Firstdelay = 20
		                                                      }	  	,
														[6] = {
				                                                .RunnableCallBack = SelectMode_Runnable ,
				                                                .Sched_enuPeriodicTimeMs = 50	,
																.Sched_u32Firstdelay = 20
		                                                      } 	,
														[7] = {
				                                                .RunnableCallBack = EditTime_Runnable ,
				                                                .Sched_enuPeriodicTimeMs = 60	,
																.Sched_u32Firstdelay = 20
		                                                      } 	,
														[8] = {
				                                                .RunnableCallBack = StopWatch_Runnable ,
				                                                .Sched_enuPeriodicTimeMs = 100	,
																.Sched_u32Firstdelay = 00
		                                                      } 	 ,   	  	
														[9] = {
				                                                .RunnableCallBack = EditDate_Runnable ,
				                                                .Sched_enuPeriodicTimeMs = 80	,
																.Sched_u32Firstdelay = 50
		                                                      } 	  	 ,  	
														[10] = {
				                                                .RunnableCallBack = SwitchsState_Runnable ,
				                                                .Sched_enuPeriodicTimeMs = 80	,
																.Sched_u32Firstdelay = 50
		                                                      } 
                                                    };