
#include "SCHED_Interface.h"
#include "SCHED_CFG.h"
#include "SysTick_Interface.h"

/**
 *@ the runnable list that configured by user in SCHED_CFG.c file 
*/
extern const Runnable_t RunnableList[SCHED_RUNNABLE_NUM] ;
/**
 *@ Any info or new feature developer needs to add to the task during the run time should be configured here
 */
typedef struct
{
    const Runnable_t *Runnable;
    /**
	 *@ This indicate the remaining time to execute the the current task it should update automatically
     *@ When the value of it reaches 0 this mean that this the time to execute the task
     *@ After that ou should reset it by PeriodicityMs value
	 */
    u32 RemainingTimeMs;

} RunnableInfo_t;
/*variable to be used in callback function to guarantee that it's execution time would be constant time*/
static volatile u32 PendingTicks = 0 ;
/*variable to be used in init function*/
RunnableInfo_t Runinfo[SCHED_RUNNABLE_NUM];


/*
 * @brief    : Initializes the scheduler.
 * @param    : None.
 * @return   : Error status .
 * @descrip  : Initializes the scheduler by configuring the sys tick timer and setting the tick time.
 */
void SCHED_vidInit()
{
	  u8 Loc_idx ;

	/* INITALIZE SYSTICK TIMER */
	SYSTICK_enuInit();

    /* CONFIGURE TICK TIME */
	SYSTICK_enuSetTime_mS( SCHED_TICK_TIME_MS);

	/* SET CALLBACK FUNCTION */
	SYSTICK_enuSetCallback(SCHED_TickCallBack);

	for (Loc_idx =0 ; Loc_idx < SCHED_RUNNABLE_NUM; Loc_idx++)
    {
        if (Runinfo[Loc_idx].Runnable == NULL)
        {
            /*Pass pointer which user pass to me in the current struct of RunnableInfo_t */
            Runinfo[Loc_idx].Runnable = &RunnableList[Loc_idx];
            /*Initiate the remaining time with delayms */
            Runinfo[Loc_idx].RemainingTimeMs = Runinfo[Loc_idx].Runnable->Sched_u32Firstdelay;
        }
        else
        {
            //do Nothong
        }
    }
}
/*
 * @brief        : Callback function for system timer interrupts.
 * @param[in]    : None.
 * @return       : None.
 * @description  : Increments the pending ticks counter upon system timer interrupt.
 */
void SCHED_TickCallBack(void)
{
    PendingTicks++;
}
/*
 * @brief        : Starts the scheduler.
 * @param[in]    : None.
 * @return       : Error_enumStatus_t.
 * @description  : Starts the scheduler by enabling the system timer interrupts and entering an infinite loop
 *                 where it checks for pending ticks and executes the scheduler function accordingly
 *                 Task should be created between Init and start.
 */
void SCHED_vidStart()
{

	/* START SYSTICK TIMER */
	SYSTICK_enuStart();

	/* POLLING TILL NEW TICK */
	while(1)
    {
        if(PendingTicks)
        {
          PendingTicks--;  
		  /**
		   *@  Execute the scheduler function 
		  */ 
          Scheduler();      
        }

    }
}
/*
 * @brief        : Executes the scheduler.
 * @param[in]    : None.
 * @return       : None.
 * @description  : Executes the scheduler by iterating through the list of runnables and calling their
 *                 respective callback functions if the time condition is met.
 */
void Scheduler(void)
{
	/**
     *@  LOCAL VARIABLE : TO ITERATE THROUGH THE LIST OF THE RUNNABLE 
     */
	u8 Loc_u8RunnableIndex = 0;

	/* INTERATE THROUGHT ALL THE RUNNABLE, BY PRIORITY */
	for(Loc_u8RunnableIndex = 0 ; Loc_u8RunnableIndex < SCHED_RUNNABLE_NUM ; Loc_u8RunnableIndex++)
    {
		 /* Check if the callback function is not NULL and if the time condition is met */
        if ((Runinfo[Loc_u8RunnableIndex].Runnable->RunnableCallBack) && (Runinfo[Loc_u8RunnableIndex].RemainingTimeMs== 0))
        {
            /* Call the callback function */
            RunnableList[Loc_u8RunnableIndex].RunnableCallBack();
            Runinfo[Loc_u8RunnableIndex].RemainingTimeMs = Runinfo[Loc_u8RunnableIndex].Runnable->Sched_enuPeriodicTimeMs ;
        }
        Runinfo[Loc_u8RunnableIndex].RemainingTimeMs -= SCHED_TICK_TIME_MS ;

		
	}

   
}