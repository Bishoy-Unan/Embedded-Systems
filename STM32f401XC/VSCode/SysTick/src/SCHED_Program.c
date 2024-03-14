
#include "SCHED_Interface.h"
#include "SCHED_CFG.h"
#include "SysTick_Interface.h"


extern const Runnable_t RunnableList[SCHED_RUNNABLE_NUM] ;

static volatile u32 PendingTicks = 0 ;


void SCHED_vidInit()
{

	/* INITALIZE SYSTICK TIMER */
	SYSTICK_enuInit();

    /* CONFIGURE TICK TIME */
	SYSTICK_enuSetTime_MS( SCHED_TICK_TIME_MS);

	/* SET CALLBACK FUNCTION */
	SYSTICK_enuSetCallback(SCHED_TickCallBack);
}

void SCHED_TickCallBack(void)
{
    PendingTicks++;
}


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
          Scheduler();      
        }

    }
}


void Scheduler(void)
{
    /**
     *@  STATIC VARIABLE : TO INCREAMENT SCHEDULER TIME 
     */
	static u32 Loc_u32TimeMs = 0;

	/**
     *@  LOCAL VARIABLE : TO ITERATE THROUGH THE LIST OF THE RUNNABLE 
     */
	u8 Loc_u8RunnableIndex = 0;

	/* INTERATE THROUGHT ALL THE RUNNABLE, BY PRIORITY */
	for(Loc_u8RunnableIndex=0;Loc_u8RunnableIndex<SCHED_RUNNABLE_NUM;Loc_u8RunnableIndex++)
    {

		/* CHECKING IF TASK WOULD RUN */
		if((Loc_u32TimeMs % RunnableList[Loc_u8RunnableIndex].Sched_enuPeriodicTimeMs) == 0){
			/* CALL THE FUNCTION OF THE TASK */
			(RunnableList[Loc_u8RunnableIndex].RunnableCallBack)();
		}
	}

    /* INCREAMENT BY THE SCHEDULER TICK TIME */
	Loc_u32TimeMs += SCHED_TICK_TIME_MS;
}