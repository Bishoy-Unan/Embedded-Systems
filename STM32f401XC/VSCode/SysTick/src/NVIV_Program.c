/***************************************************************
 * Author            : Bishoy Unan                              
 * Version           : V0.0.0                                   
 * Data              : 5 Mar 2024                              
 * Description       : NVIC_Program.c --> implementations                                            
 * Module  Features  :                                                                                 
 *      01- NVIC_enuEnableInterrupt(u8 Copy_u8InterruptID);                                                                                  
 *      02- NVIC_enuDisableInterrupt(u8 Copy_u8InterruptID);                                                                                    
 *      03- NVIC_enuSetPending(u8 Copy_u8InterruptID);                                                                                          
 *      04- NVIC_enuClearPending(u8 Copy_u8InterruptID);                                                                                           
 *      05- NVIC_enuGetActiveStatus(u8 Copy_u8InterruptID);                                                                                   
 *      06- NVIC_enuSetPriority(u8 Copy_u8InterruptID,u32 Copy_u32GroupingMode,u8 Copy_u8GroupPriority, u8 Copy_u8SubGroupPriority);                                                                                                                                                
 **************************************************************/

#include"STD_TYPES.h"
#include"NVIC_Interface.h"
#include"NVIC_Private.h"


/******************** NVIC_enuEnableInterrupt ***************************
 * @brief: This function Enable an interrupt. 
 * @param :  Copy_u8InterruptID (u8)  : 0 -> 239 
 * @return: NVIC_enuErrorStatus
 ************************************************************************/
NVIC_enuErrorStatus_t NVIC_enuEnableInterrupt(u8 Copy_u8InterruptID)
{

	NVIC_enuErrorStatus_t Ret_enuErrorStatus = NVIC_enuOK;

	

    /* VALIDATION : CHECH INTERRUPT NUMBER */
	if(Copy_u8InterruptID > MAX_NUM_OF_INT)
    {
		Ret_enuErrorStatus = NVIC_enuNOK;
	}

	else
    {
        /*(divid on 32 to get register number in the registers array)*/
        /*(modules 32 to get the interrupt position in the register)*/
		 NVIC_REG->ISER[Copy_u8InterruptID/32] = (1U << (Copy_u8InterruptID % 32 )) ;
	}



	return Ret_enuErrorStatus;
}
/*=================================================================================================================================*/
/******************** NVIC_enuDisableInterrupt **************************
 * @brief: This function Enable an interrupt. 
 * @param :  Copy_u8InterruptID (u8)  : 0 -> 239 
 * @return: NVIC_enuErrorStatus
 ************************************************************************/
NVIC_enuErrorStatus_t NVIC_enuDisableInterrupt(u8 Copy_u8InterruptID)
{

	NVIC_enuErrorStatus_t Ret_enuErrorStatus = NVIC_enuOK;

	

    /* VALIDATION : CHECH INTERRUPT NUMBER */
	if(Copy_u8InterruptID > MAX_NUM_OF_INT)
    {
		Ret_enuErrorStatus = NVIC_enuNOK;
	}

	else
    {
        /*(divid on 32 to get register number in the registers array)*/
        /*(modules 32 to get the interrupt position in the register)*/
		 NVIC_REG->ICER[Copy_u8InterruptID/32] = (1U << (Copy_u8InterruptID % 32 )) ;
	}



	return Ret_enuErrorStatus;
}
/*=================================================================================================================================*/


/*********************** NVIC_enuSetPending *****************************
 * @brief: This function set pending flag. 
 * @param :  Copy_u8InterruptID (u8)  : 0 -> 239 
 * @return: NVIC_enuErrorStatus
 ************************************************************************/
NVIC_enuErrorStatus_t NVIC_enuSetPending(u8 Copy_u8InterruptID)
{

	NVIC_enuErrorStatus_t Ret_enuErrorStatus = NVIC_enuOK;

	

    /* VALIDATION : CHECH INTERRUPT NUMBER */
	if(Copy_u8InterruptID > MAX_NUM_OF_INT)
    {
		Ret_enuErrorStatus = NVIC_enuNOK;
	}

	else
    {
        /*(divid on 32 to get register number in the registers array)*/
        /*(modules 32 to get the interrupt position in the register)*/
		 NVIC_REG->ISPR[Copy_u8InterruptID/32] = (1U << (Copy_u8InterruptID % 32 )) ;
	}



	return Ret_enuErrorStatus;
}


/*=================================================================================================================================*/

/*********************** NVIC_enuClearPending ***************************
 * @brief: This function clear pending flag. 
 * @param :  Copy_u8InterruptID (u8)  : 0 -> 239 
 * @return: NVIC_enuErrorStatus
 ************************************************************************/
NVIC_enuErrorStatus_t NVIC_enuClearPending(u8 Copy_u8InterruptID)
{

	NVIC_enuErrorStatus_t Ret_enuErrorStatus = NVIC_enuOK;

	

    /* VALIDATION : CHECH INTERRUPT NUMBER */
	if(Copy_u8InterruptID > MAX_NUM_OF_INT)
    {
		Ret_enuErrorStatus = NVIC_enuNOK;
	}

	else
    {
        /*(divid on 32 to get register number in the registers array)*/
        /*(modules 32 to get the interrupt position in the register)*/
		 NVIC_REG->ICPR[Copy_u8InterruptID/32] = (1U << (Copy_u8InterruptID % 32 )) ;
	}



	return Ret_enuErrorStatus;

}
/*=================================================================================================================================*/

/********************** NVIC_enuGetActiveStatus *************************
 * @bief: This function get active status  
 * @param:  Copy_u8InterruptID (u8) : 0 -> 239 
 *           Add_pu8ActiveValue(pu8) : to return the value 
 * @return: NVIC_enuErrorStatus 
 ************************************************************************/
NVIC_enuErrorStatus_t NVIC_enuGetActiveStatus(u8 Copy_u8InterruptID, u8* Add_pu8ActiveValue)
{

	NVIC_enuErrorStatus_t Ret_enuErrorStatus = NVIC_enuOK;

	

    /* VALIDATION : CHECH INTERRUPT NUMBER */
	if(Copy_u8InterruptID > MAX_NUM_OF_INT)
    {
		Ret_enuErrorStatus = NVIC_enuNOK;
	}
    else if(Add_pu8ActiveValue == NULL)
    {
        Ret_enuErrorStatus = NVIC_enuNOK;
    } 
	else
    {
        /*(divid on 32 to get register number in the registers array)*/
        /*(modules 32 to get the interrupt position in the register)*/
		*Add_pu8ActiveValue = (((NVIC_REG->IABR[Copy_u8InterruptID/32]) >> (Copy_u8InterruptID % 32 )) & 1) ;
	}



	return Ret_enuErrorStatus;		
}

/*=================================================================================================================================*/

/*
	REMINDER: 1- Case1: you have 0 group priorities and 16 sub-priorities so it sets sub-priority to priority value directly
			  2- Case2:	you have 16 group priorities and 0 sub-priorities so it sets group priority to priority value directly
			  3- Case3:	you have 4 group priorities and 4 sub-priorities which means values from 0~3 only for each,
					also the shifting number is 2 because the 4 bits of priority are divided into 2 group and 2 subs
			  4- Case4:	you have 2 group priorities and 8 sub-priorities which means group values 0~1 only and 
			  sub values 0~7, also the shifting number is 3 because the 4 bits of priority are divided into 
			  1 group and 3 subs.
			  5- Case5: same concept as first
*/

/********************** NVIC_enuSetPriority *****************************************************
 * @bief: This function set grouping mode and group priority and sub group priority ( only for external interrupt --240 int--)  
 * @param:  Copy_u8InterruptID (u8) : 0 -> 239 
 *          Copy_u32GroupingMode : 
 *                                   1- NVIC_GROUPMODE_G16S0
 *                                   2- NVIC_GROUPMODE_G8S2 
 *                                   3- NVIC_GROUPMODE_G4S4 
 *                                   4- NVIC_GROUPMODE_G2S8 
 *                                   5- NVIC_GROUPMODE_G0S16
 *         Copy_u8GroupPriority:
 *         Copy_u8SubGroupPriority: any number based on grouping mode
 * @return: NVIC_enuErrorStatus 
 ****************************************************************************************************/

NVIC_enuErrorStatus_t NVIC_enuSetPriority(u8 Copy_u8InterruptID,u32 Copy_u32GroupingMode,u8 Copy_u8GroupPriority, u8 Copy_u8SubGroupPriority)
{

	NVIC_enuErrorStatus_t Ret_enuErrorStatus = NVIC_enuOK;


    /* VALIDATION : CHECH INTERRUPT NUMBER */
    if(Copy_u8InterruptID > MAX_NUM_OF_INT)
    {
        Ret_enuErrorStatus = NVIC_enuNOK;
    }
    else if((Copy_u8SubGroupPriority != NVIC_GROUPMODE_G16S0) && (Copy_u8SubGroupPriority != NVIC_GROUPMODE_G16S0) && (Copy_u8SubGroupPriority != NVIC_GROUPMODE_G8S2) && (Copy_u8SubGroupPriority != NVIC_GROUPMODE_G4S4) && (Copy_u8SubGroupPriority != NVIC_GROUPMODE_G2S8) && (Copy_u8SubGroupPriority != NVIC_GROUPMODE_G0S16))
    {
        Ret_enuErrorStatus = NVIC_enuNOK;
    }
    else
    {
        /*EQUATION TO SET GROUP AND SUBGROUP PRIORITIES IN IPR REGISTER*/
        u8 Local_u8Priority = (Copy_u8SubGroupPriority | (Copy_u8GroupPriority << ((Copy_u32GroupingMode - 0x05FA0300)/0x100)));
    
        /*SET GROUPING MODE IN SYSTEM CONTROL BLOCK PERIPHRAL*/
        SCB_AIRCR = Copy_u32GroupingMode ;

        /*IPR REGISTER IS BYTE ACCESSABLE*/
        NVIC_REG->IPR[Copy_u8InterruptID] = (Local_u8Priority << 4 ) ;
    }  
    

	return Ret_enuErrorStatus;
}
