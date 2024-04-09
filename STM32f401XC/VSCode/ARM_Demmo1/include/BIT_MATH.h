/*###########################################################################*/
/*Author	: Bishoy Unan						     */
/*Version	: v0.0.0						     */
/*Date		: 							     */
/*Description	: BitMath file 					             */
/*###########################################################################*/



#ifndef BIT_MATH_H
#define BIT_MATH_H

#define 	SET_BIT(REG,BITNO)			(REG|=(1<<BITNO))
#define 	CLR_BIT(REG,BITNO)			(REG&=~(1<<BITNO))
#define 	TOG_BIT(REG,BITNO)			(REG^=(1<<BITNO))
#define 	GET_BIT(REG,BITNO)			(1&(REG>>BITNO))

#define 	SET_LOW_NIBBL(REG)			(REG=0x0F)
#define 	CLR_LOW_NIBBL(REG)			(REG=0xF0)
#define 	TOG_LOW_NIBBL(REG)			(REG^=0x0F)
#define 	GET_LOW_NIBBL(REG)			(REG&0x0F)
#define 	ASS_LOW_NIBBLE(REG,VAL) 		(REG=(REG&0xF0)|(VAL&0x0F))

#define 	SET_HIGH_NIBBL(REG)			(REG=0xF0)
#define 	CLR_HIGH_NIBBL(REG)			(REG=0x0F)
#define 	TOG_HIGH_NIBBL(REG)			(REG^=0xF0)
#define 	GET_HIGH_NIBBL(REG)			(REG&0xF0)
#define 	ASS_HIGH_NIBBLE(REG,VAL) 		(REG=(REG&0x0F)|(VAL&0xF0))

#define		RIGHT_SHIFT(REG,NO)			(REG>>NO)
#define		LEFT_SHIFT(REG,NO)			(REG<<NO)
#define		CIRCULAR_LSHIFT(REG,NO)			(((REG)<<(NO)|((REG)>>(8*sizeof(REG)-(NO))))
#define		CIRCULAR_RSHIFT(REG,NO)			(((REG)>>(NO)|((REG)<<(8*sizeof(REG)-(NO))))


//#define		NULL	((void*)0)
					
#endif