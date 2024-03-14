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





#ifndef SYSTICK_INERFACE_H
#define SYSTICK_INTERFACE_H_


/**
 *@ new data type ,pointer to function 
 */
typedef void (*SysTick_CallBack_Ptr_t) (void);

typedef enum
{
	SYSTICK_enuOK    ,
	SYSTICK_enuNOK 

}SYSTICK_enuErrStatus_t;



/**
 *@description: function to select clock source and interrupt mode 
 *@param: void
 *@return: Error status
*/
SYSTICK_enuErrStatus_t SYSTICK_enuInit();
/**
 *@description: function to enable (start) systick timer 
 *@param: void
 *@return: Error status
*/
SYSTICK_enuErrStatus_t SYSTICK_enuStart();
/**
 *@description: function to set time in milliseconds 
 *@param: the time in milliseconds
 *@return: Error status
*/
SYSTICK_enuErrStatus_t SYSTICK_enuSetTime_mS(u32 Copy_u16Time_MS);
/**
 *@description: function to set call back pointer to function 
 *@param: pointer to function
 *@return: Error status
*/
SYSTICK_enuErrStatus_t SYSTICK_enuSetCallback(SysTick_CallBack_Ptr_t Addr_Fptr);
/**
 * @ SysTick Interrupt Handler
*/
void SYSTICK_Handler (void);








#endif