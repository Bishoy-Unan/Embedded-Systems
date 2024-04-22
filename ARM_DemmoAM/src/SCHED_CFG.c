
#include "SCHED_CFG.h"
#include "SCHED_Interface.h"
#include "app.h"
#include "SWITCH.h"
#include "LCD.h"


 const Runnable_t RunnableList[SCHED_RUNNABLE_NUM] = {
														[0] = {
																.RunnableCallBack = SWITCH_vidDebounceTask  ,
																.Sched_enuPeriodicTimeMs = 10	,
																.Sched_u32Firstdelay = 0
															  }	   ,
														[1] = {
				                                                .RunnableCallBack = LCD_vidRunnable ,
				                                                .Sched_enuPeriodicTimeMs = 2	,
																.Sched_u32Firstdelay = 0
		                                                      }		  ,	  
														[2] = {
																.RunnableCallBack = Watch_Runnable  ,
																.Sched_enuPeriodicTimeMs = 700	,
																.Sched_u32Firstdelay = 0
															  }	   ,	  
														[3] = {
				                                                .RunnableCallBack = UART_vidRunnable ,
				                                                .Sched_enuPeriodicTimeMs = 300	,
																.Sched_u32Firstdelay = 0
		                                                      }	 	,
														[4] = {
				                                                .RunnableCallBack = Modes_Runnable ,
				                                                .Sched_enuPeriodicTimeMs = 30	,
																.Sched_u32Firstdelay = 20
		                                                      } 	,  	
														[5] = {
				                                                .RunnableCallBack = SwitchsState_Runnable ,
				                                                .Sched_enuPeriodicTimeMs = 200	,
																.Sched_u32Firstdelay = 0
		                                                      } /*,
														[6] = {
				                                                .RunnableCallBack = TestUART ,
				                                                .Sched_enuPeriodicTimeMs = 50	,
																.Sched_u32Firstdelay = 0
		                                                      }   */
                                                    };
