

#ifndef  	GPIO_PRIVATE_H
#define		GPIO_PRIVATE_H



/**
*@ Macros Base Address Of GPI0x Registers                           
*/
#define  GPIOA_BASE_ADDRESS         0x40020000
#define  GPIOB_BASE_ADDRESS         0x40020400
#define  GPIOC_BASE_ADDRESS         0x40020800 
#define  GPIOD_BASE_ADDRESS 	    0x40020C00
#define  GPIOE_BASE_ADDRESS 	    0x40021000
#define  GPIOH_BASE_ADDRESS 	    0x40021C00


/**
*@ defination of registers addresses using struct method
*/
;
typedef struct{
	 volatile u32 MODEREG  ;  /*!< GPIO port mode register,               Address offset: 0x00      */
	 volatile u32 OTYPER ;  /*!< GPIO port output type register,        Address offset: 0x04      */
	 volatile u32 OSPEEDR;  /*!< GPIO port output speed register,       Address offset: 0x08      */
	 volatile u32 PUPDR  ;  /*!< GPIO port pull-up/pull-down register,  Address offset: 0x0C      */
	 volatile u32 IDR    ;  /*!< GPIO port input data register,         Address offset: 0x10      */
	 volatile u32 ODR    ;  /*!< GPIO port output data register,        Address offset: 0x14      */
	 volatile u32 BSRR   ;  /*!< GPIO port bit set/reset register,      Address offset: 0x18      */
	 volatile u32 LCKR   ;  /*!< GPIO port configuration lock register, Address offset: 0x1C      */
	 volatile u32 AFRL   ;  /*!< GPIO alternate function registers,     Address offset: 0x20-0x24 */
	 volatile u32 AFRH   ;
}GPIOx_t;

/**
*@ craete pointers for each insatance(PORT) of GPIO periphral
*/
#define GPIOA        ((GPIOx_t * ) GPIOA_BASE_ADDRESS )
#define GPIOB        ((GPIOx_t * ) GPIOB_BASE_ADDRESS )
#define GPIOC        ((GPIOx_t * ) GPIOC_BASE_ADDRESS )
#define GPIOD        ((GPIOx_t * ) GPIOD_BASE_ADDRESS )
#define GPIOE        ((GPIOx_t * ) GPIOE_BASE_ADDRESS )
#define GPIOH        ((GPIOx_t * ) GPIOH_BASE_ADDRESS )



#define GPIO_PIN0			0			
#define GPIO_PIN1			1
#define GPIO_PIN2			2
#define GPIO_PIN3			3
#define GPIO_PIN4			4
#define GPIO_PIN5			5
#define GPIO_PIN6			6
#define GPIO_PIN7			7
#define GPIO_PIN8			8
#define GPIO_PIN9			9
#define GPIO_PIN10			10
#define GPIO_PIN11			11
#define GPIO_PIN12			12
#define GPIO_PIN13			13
#define GPIO_PIN14			14
#define GPIO_PIN15			15


/* MODE CONFIGURATION */

#define GPIO_MODE_INPUT_FLOATING 			0b00000	
#define GPIO_MODE_INPUT_PU					0b00001
#define GPIO_MODE_INPUT_PD                	0b00010

#define GPIO_MODE_OUTPUT_PP					0b01000
#define GPIO_MODE_OUTPUT_PP_PU        		0b01001
#define GPIO_MODE_OUTPUT_PP_PD      		0b01010

#define GPIO_MODE_OUTPUT_OPENDRAIN			0b01100
#define GPIO_MODE_OUTPUT_OPENDRAIN_PU       0b01101
#define GPIO_MODE_OUTPUT_OPENDRAIN_PD     	0b01110

#define GPIO_MODE_AF_PP						0b10000
#define GPIO_MODE_AF_PP_PU            		0b10001
#define GPIO_MODE_AF_PP_PD          		0b10010
#define GPIO_MODE_AF_OPENDRAIN				0b10100
#define GPIO_MODE_AF_OPENDRAIN_PU           0b10101
#define GPIO_MODE_AF_OPENDRAIN_PD         	0b10110

#define GPIO_MODE_ANALOG					0b11000
/* masks to parse the configrations*/
#define GET_MODE_MASK		0b11000
#define GET_TYPE_MASK 		0b00100
#define GET_PUPDR_MASK 		0b00011


/* SPEED CONFIGURATION */
#define GPIO_OUTPUT_SPEED_LOW			    0b00
#define GPIO_OUTPUT_SPEED_MEDIUM		    0b01
#define GPIO_OUTPUT_SPEED_HIGH			    0b10
#define GPIO_OUTPUT_SPEED_VERYHIGH          0b11

/* directions mode masks*/
#define INPUT_MODE			0X00
#define OUTPUT_MODE			0X01
#define AF_MODE				0X02
#define ANALOG_MODE			0X03

#define GPIO_HIGH			1
#define GPIO_LOW			0


#define GET_FIRST_BIT 		1






#endif
