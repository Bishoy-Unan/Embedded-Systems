/*
 * GPIO_private.h
 *
 *  Created on: Feb 17, 2024
 *      Author: Aml Ashraf
 */

#ifndef GPIO_PRIVATE_H_
#define GPIO_PRIVATE_H_

typedef struct
{
	 u32 volatile 	 MODE    ;
	 u32 volatile 	 OTYPER  ;
	 u32 volatile 	 OSPEEDR ;
	 u32 volatile 	 PUPDR   ;
	 u32 volatile 	 IDR     ;
	 u32 volatile 	 ODR     ;
	 u32 volatile 	 BSRR    ;
	 u32 volatile 	 LCKR    ;
	 u32 volatile 	 AFRL    ;
	 u32 volatile 	 AFRH    ;
}GPIO_t ;


#endif /* GPIO_PRIVATE_H_ */
