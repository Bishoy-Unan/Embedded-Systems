/*############################################################################*/
/* Author:	Bishoy Unan	 	   							*/
/* Date:	24/12/2023						       						*/
/* Version:	v0.0.0									 						 			     							*/
/* description: ATMwga32 External Interrupt Driver for Int0 and Int1 and Int2 */
/* Specs: 									      										   								*/
/* 01: void ExtInterrupt_voidInit(void);	*/
/* 02: void ExtINT_voidSetExtINT0(void(*ptr)(void));*/
/* 03: void ExtINT_voidSetExtINT1(void(*ptr)(void));  */
/* 04: void ExtINT_voidSetExtINT2(void(*ptr)(void)); */
/*########################################################*/




#ifndef	ExtInterrupt_Private_H
#define	ExtInterrupt_Private_H


#define MCUCR 	*((volatile u8*)0x55)
#define MCUCSR 	*((volatile u8*)0x54)
#define GICR	*((volatile u8*)0x5B)
#define GIFR	*((volatile u8*)0x5A)
#define SREG	*((volatile u8*)0x5F)

#define ENABLE   1
#define DISABLE  0

#define	The_low_level		0
#define	Any_logical_change	1
#define	The_falling_edge	2
#define	The_rising_edge		3


/**
*@ numbers of external int0 and int1 and int2 in Reset and Interrupt Vectors (data sheet)
*/
#define EXT_INT0	1
#define EXT_INT1	2
#define EXT_INT2	3


/********************************************************************/
/**
*@ Masking values used to set register GICR ExtInterrupt0
*/
#define GICR_INT0_MASK		0XBF
/**
*@ Enable mask used to enable register GICR ExtInterrupt0
*/
#define GICR_INT0_ENABLE		0X40
/**
*@ Enable mask used to enable register GICR ExtInterrupt0
*/
#define GICR_INT0_DISABLE		0X00
/**
*@ Masking values used to set register MCUCR ExtInterrupt0
*/
#define MCUCR_INT0_MASK		0XFC
/**
*@ Masking value of The_low_level ExtInterrupt0
*/
#define MCUCR_INT0_LL		0X00
/**
*@ Masking value of Any_logical_change ExtInterrupt0
*/
#define MCUCR_INT0_ALC		0X01
/**
*@ Masking value of The_falling_edge ExtInterrupt0
*/
#define MCUCR_INT0_FE		0X02
/**
*@ Masking value of The_rising_edge ExtInterrupt0
*/
#define MCUCR_INT0_RE		0X03

/********************************************************************/
/**
*@ Masking values used to set register GICR ExtInterrupt0
*/
#define GICR_INT1_MASK		0X7F
/**
*@ Enable mask used to enable register GICR ExtInterrupt0
*/
#define GICR_INT1_ENABLE		0XE0
/**
*@ Enable mask used to enable register GICR ExtInterrupt0
*/
#define GICR_INT1_DISABLE		0X0C
/**
*@ Masking values used to set register MCUCR ExtInterrupt0
*/
#define MCUCR_INT1_MASK		0XF3
/**
*@ Masking value of The_low_level ExtInterrupt0
*/
#define MCUCR_INT1_LL		0X00
/**
*@ Masking value of Any_logical_change ExtInterrupt0
*/
#define MCUCR_INT1_ALC		0X01
/**
*@ Masking value of The_falling_edge ExtInterrupt0
*/
#define MCUCR_INT1_FE		0X02
/**
*@ Masking value of The_rising_edge ExtInterrupt0
*/
#define MCUCR_INT1_RE		0X03

/********************************************************************/
/**
*@ Masking values used to set register GICR ExtInterrupt0
*/
#define GICR_INT2_MASK		0XDF
/**
*@ Enable mask used to enable register GICR ExtInterrupt0
*/
#define GICR_INT2_ENABLE		0X20
/**
*@ Enable mask used to enable register GICR ExtInterrupt0
*/
#define GICR_INT2_DISABLE		0X00
/**
*@ Masking values used to set register MCUCR ExtInterrupt0
*/
#define MCUCSR_INT2_MASK		0XBF

/**
*@ Masking value of The_falling_edge ExtInterrupt0
*/
#define MCUCSR_INT2_FE		0X00
/**
*@ Masking value of The_rising_edge ExtInterrupt0
*/
#define MCUCSR_INT2_RE		0X40

/**
*@ masking value of SREG register
*/
#define SREG_MASK	0x7F
/**
*@ masking value of SREG register to enable GIE
*/
#define SREG_ENABLE_MASK	0x80








/**
*@ this two lines to write isr like ISR(vect_no)
*/
#define ISR(vect_no) void vect(vect_no)(void) __attribute__((signal));\
						void vect(vect_no) (void)
#define vect(x) __vector_##x











#endif