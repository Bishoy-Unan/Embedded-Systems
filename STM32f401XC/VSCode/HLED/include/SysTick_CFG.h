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



#ifndef SYSTICK_CFG_H
#define SYSTICK_CFG_H




#define CLOCK_FREQUENCY		25000000

/**
 *@ define the clock source to the systick timer 
 *@  Options:
 *@      	 1-  STK_SRC_AHB 
 *@			 2-  STK_SRC_AHB_PLL8 
 */
#define SYSTICK_CLK_SRC     STK_SRC_AHB
/**
 *@ enable or disable exception for systick timer
 *@ OPTIONS :
 *@           SYSTICK_INT_OFF
 *@           SYSTICK_INT_ON
 */
#define SYSTICK_INT_MODE  SYSTICK_INT_ON




#endif