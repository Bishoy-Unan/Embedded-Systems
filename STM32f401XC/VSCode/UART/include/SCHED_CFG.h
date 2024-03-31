/*=============================================================================     
 * Author            : Bishoy Unan                                                   
 * Version           : V0.0.0                                                      
 * Data              :  11  Mar 2024                                                
 * Description       :                          
 * Module  Features  : SCHED_CFG_H
 *                     1- SYSTICK_enuInit();                                       
 *                     2- SYSTICK_enuSetTime_MS(u32 Copy_u16Time_MS);              
 *                     3- SYSTICK_enuStart();                                       
 *                     4- SYSTICK_enuSetCallback(SysTick_CallBack_Ptr_t Addr_Fptr);
 *===========================================================================*/



#ifndef SCHED_CFG_H
#define SCHED_CFG_H

/**
 *@ the scheduler tick time in milliseconds 
*/
#define SCHED_TICK_TIME_MS  1
/**
 *@ Number of tasks runs by the scheduler 
*/
#define SCHED_RUNNABLE_NUM  7


#endif