


#ifndef SCHED_INTERFACE_H
#define SCHED_INTERFACE_H


#include "STD_TYPES.h"

/**
 *@ New pointer to function type for set the runnable or call by it 
 */
typedef void (*Runnablecb_t)(void);

/**
 *@ Return Error Status types
*/
typedef enum {
  SCHED_enuOK,
  SCHED_enuNOK
}SCHED_enuErrStatus_t;
/**
 *@ Struct ofRunnable data to be used in the scheduler 
*/
typedef struct {
  /*the applicaton which be excuted*/
	Runnablecb_t RunnableCallBack ;
  /*the periodic time in which this application would be executed*/
	u32 Sched_enuPeriodicTimeMs;
  /*the first time this application would be executed*/
  u32 Sched_u32Firstdelay;

}Runnable_t;



/*
 * @brief    : Initializes the scheduler.
 * @param    : None.
 * @return   : Error status .
 * @descrip  : Initializes the scheduler by configuring the sys tick timer and setting the tick time.
 */
void SCHED_vidInit();
/*
 * @brief        : Starts the scheduler.
 * @param[in]    : None.
 * @return       : Error_enumStatus_t.
 * @description  : Starts the scheduler by enabling the system timer interrupts and entering an infinite loop
 *                 where it checks for pending ticks and executes the scheduler function accordingly
 *                 Task should be created between Init and start.
 */
void SCHED_vidStart();
/*
 * @brief        : Callback function for system timer interrupts.
 * @param[in]    : None.
 * @return       : None.
 * @description  : Increments the pending ticks counter upon system timer interrupt.
 */
void SCHED_TickCallBack(void);
/*
 * @brief        : Executes the scheduler.
 * @param[in]    : None.
 * @return       : None.
 * @description  : Executes the scheduler by iterating through the list of runnables and calling their
 *                 respective callback functions if the time condition is met.
 */
void Scheduler(void);

#endif