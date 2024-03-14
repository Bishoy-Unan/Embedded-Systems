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




#ifndef SYSTICK_PRIVATE_H
#define SYSTICK_PRIVATE_H

typedef struct
{
	volatile u32 CTRL  ;
	volatile u32 LOAD  ;
	volatile u32 VAL   ;
    volatile u32 CAL   ;
}STK_Type_t;

#define     SysTick    ((STK_Type_t*)0xE000E010)


#define     STK_SRC_AHB              0x00000004
#define     STK_SRC_AHB_PLL8         0x00000000

#define     SYSTICK_INT_OFF          0x00000000
#define     SYSTICK_INT_ON           0x00000002



#define     START                    0x00000001


#endif
