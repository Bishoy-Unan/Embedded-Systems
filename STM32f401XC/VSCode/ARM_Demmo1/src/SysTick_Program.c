/*=============================================================================     
 * Author            : Bishoy Unan                                                   
 * Version           : V0.0.0                                                      
 * Data              :  9  Mar 2024                                                
 * Description       : MMSTK_Program.c --> implementations                         
 * Module  Features  : 
 *                     1- SYSTICK_enuInit();                                       
 *                     2- SYSTICK_enuSetTime_MS(u32 Copy_u16Time_MS);              
 *                     3- SYSTICK_enuStart();                                       
 *                     4- SYSTICK_enuSetCallback(SysTick_CallBack_Ptr_t Addr_Fptr);
 *===========================================================================*/


#include "STD_TYPES.h"
#include "SysTick_Private.h"
#include "SysTick_Interface.h"
#include "SysTick_CFG.h"

/**
 * @ global static call back pointer to be used in systick handler function
*/
static SysTick_CallBack_Ptr_t APPCallBackFunction ;



/**
 *@description: function to select clock source and interrupt mode 
 *@param: void
 *@return: Error status
*/
SYSTICK_enuErrStatus_t SYSTICK_enuInit()
{
    SYSTICK_enuErrStatus_t Return_enuErrorStatus = SYSTICK_enuOK;
    /**
     *@ configue systick clock source 
     */
    #if((SYSTICK_CLK_SRC != STK_SRC_AHB)  && (SYSTICK_CLK_SRC != STK_SRC_AHB) )
    {
        Return_enuErrorStatus = SYSTICK_enuNOK;
    }
    #else
    {
        SysTick->CTRL |= SYSTICK_CLK_SRC ;
    }
    #endif
    /**
     *@ configure exception mode
    */
    #if((SYSTICK_INT_MODE != SYSTICK_INT_ON)  && (SYSTICK_INT_MODE != SYSTICK_INT_OFF) )
    {
        Return_enuErrorStatus = SYSTICK_enuNOK;
    }
    #else
    {
        SysTick->CTRL |= SYSTICK_INT_MODE ;
    }
    #endif

    return Return_enuErrorStatus ;

} /*SYSTICK_enuInit function*/

/**
 *@description: function to enable (start) systick timer 
 *@param: void
 *@return: Error status
*/
SYSTICK_enuErrStatus_t SYSTICK_enuStart()
{
    SYSTICK_enuErrStatus_t Return_enuErrorStatus = SYSTICK_enuOK;

    /* CLEAR VAL REGISTER */
	SysTick->VAL = 0 ;

	/* ENABLE SYSTICK */
	SysTick->CTRL |= START;

    return Return_enuErrorStatus ;
}/*SYSTICK_enuStart function*/

/**
 *@description: function to set time in milliseconds 
 *@param: the time in milliseconds
 *@return: Error status
*/
SYSTICK_enuErrStatus_t SYSTICK_enuSetTime_mS(u32 Copy_u16Time_MS)
{
     SYSTICK_enuErrStatus_t Return_enuErrorStatus = SYSTICK_enuOK;

     u32 Loc_u32LoadValue = 0;

    #if(SYSTICK_CLK_SRC == STK_SRC_AHB  )
    {
       Loc_u32LoadValue = (u32)(((((u64)Copy_u16Time_MS) * (u64)CLOCK_FREQUENCY)/(u64)1000));
    }
    #elif( SYSTICK_CLK_SRC == STK_SRC_AHB_PLL8)
    {
        Loc_u32LoadValue = (((u64)Copy_u16Time_MS * (u64)CLOCK_FREQUENCY)/(u64) 8000);
    }
    #endif

     /* SET THE VALUE ON THE REGISTER */
	SysTick->LOAD = Loc_u32LoadValue;


      return Return_enuErrorStatus ;

}/*SYSTICK_enuSetTime_MS function*/

/**
 *@description: function to set call back pointer to function 
 *@param: pointer to function
 *@return: Error status
*/
SYSTICK_enuErrStatus_t SYSTICK_enuSetCallback(SysTick_CallBack_Ptr_t Addr_Fptr)
{
    SYSTICK_enuErrStatus_t Return_enuErrorStatus = SYSTICK_enuOK;


    /* ASSIGN THE FUNCTION TO THE POINTER */
	if(Addr_Fptr)
    {
		APPCallBackFunction = Addr_Fptr;
	}
	else
    {
		Return_enuErrorStatus = SYSTICK_enuNOK;
	}


    return Return_enuErrorStatus ;
}

/**
*@description: SysTick Interrupt Handler
*@param: void
 *@return: void
*/
void SysTick_Handler(void)
{
    /* 
    *@ ckecking that the aplication function not equal to null 
    */
	if(APPCallBackFunction)
    {
		/*
         *@ call the function 
         */
		APPCallBackFunction();
	}
}

