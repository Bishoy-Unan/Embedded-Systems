/***************************************************************
 * Author            : Bishoy Unan                              
 * Version           : V0.0.0                                   
 * Data              : 5 Mar 2024                              
 * Description       : MSTK_Privite.h --> implementations       
 * Features          : Register Definitions                     
 ***************************************************************/



/*******************************************************************************************************
 *                                   guard of file will call on time in .c                             *
 *******************************************************************************************************/


#ifndef NVIC_PRIVATE_H
#define NVIC_PRIVATE_H


/*******************************************************************************************************
 *                                    Macros Base Address Of NVIC Registers                            *
 *******************************************************************************************************/


#define NVIC_BASE_ADDRESS    0xE000E100

/********************************************************************************************************
  *                                       Register Definitions                                          *
  *-----------------------------------------------------------------------------------------------------*
  *     - Developer can't Edit in it                                                                    *
  *     - Register _ Defination		                                                                    *
  *     - Design :                                                                                      *
  *    				- #define	:	NO                                                                  *
  *    				- Union		:	NO                                                                  *
  *    				- Struct	:	YES                                                                 *
  *                                                                                                     *
  *******************************************************************************************************/




/* NVIC register map type. */
typedef struct
{
	u32 ISER[8];              /**< Interrupt Set Enable Registers */
	u32 RESERVED0[24];        /**< Reserved */
	u32 ICER[8];              /**< Interrupt Clear Enable Registers */
	u32 RSERVED1[24];         /**< Reserved */
	u32 ISPR[8];              /**< Interrupt Set Pending Registers */
	u32 RESERVED2[24];        /**< Reserved */
	u32 ICPR[8];              /**< Interrupt Clear Pending Registers */
	u32 RESERVED3[24];        /**< Reserved */
	u32 IABR[8];              /**< Interrupt Active bit Registers */
	u32 RESERVED4[56];        /**< Reserved */
	u8  IPR[58];             /**< Interrupt Priority Registers */
	u32 RESERVED5[580];       /**< Reserved */
	u32 STIR;                 /**< Software Trigger Interrupt Registers */
} NVIC_REG_t;


/*******************************************************************************************************/
/*                                   Struct Macros Base Address Of NVIC                                */
/*******************************************************************************************************/

#define     NVIC_REG    ((volatile NVIC_REG_t*)(NVIC_BASE_ADDRESS))

#define     SCB_AIRCR   (*(volatile u32*) 0xE000ED0C)   //Regiter Definaition

#define     NVIC_VECTKEY     0x05FA0000

#define     MAX_NUM_OF_INT			240


/*5FA IS REGISTER KEY*/
#define     NVIC_GROUPMODE_G16S0 		0x05FA0300	//(4 BITS FOR GROUP 0 BITS FOR SUBGROUP - IPR REGISTER)
#define     NVIC_GROUPMODE_G8S2  		0x05FA0400	//(3 BITS FOR GROUP 1 BITS FOR SUBGROUP - IPR REGISTER)
#define     NVIC_GROUPMODE_G4S4  		0x05FA0500	//(2 BITS FOR GROUP 2 BITS FOR SUBGROUP - IPR REGISTER)
#define     NVIC_GROUPMODE_G2S8  		0x05FA0600	//(1 BITS FOR GROUP 3 BITS FOR SUBGROUP - IPR REGISTER)
#define     NVIC_GROUPMODE_G0S16		0x05FA0700	//(0 BITS FOR GROUP 4 BITS FOR SUBGROUP - IPR REGISTER)




#endif // GPIO_PRIVATE_H
