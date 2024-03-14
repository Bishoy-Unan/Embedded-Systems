
#include<util/delay.h>
#include <xc.h>



typedef unsigned char u8 ;
typedef unsigned short int u16 ;
typedef unsigned int u32 ;
typedef unsigned long long int u64 ;

typedef signed char s8 ;
typedef signed short int s16 ;
typedef signed  int s32 ;
typedef signed long long int s64 ;

typedef float  f32 ;

typedef double f64  ;

typedef long double f96  ;


//PORT A
#define DDRA		*((volatile u8 *)0x3A)
#define PORTA		*((volatile u8 *)0x3B)
#define PINA		*((volatile u8 *)0x39)
//PORT B
#define DDRB		*((volatile u8 *)0x37)
#define PORTB		*((volatile u8 *)0x38)
#define PINB		*((volatile u8 *)0x36)
//PORT C
#define DDRC		*((volatile u8 *)0x34)
#define PORTC		*((volatile u8 *)0x35)
#define PINC		*((volatile u8 *)0x33)
//PORT D
#define DDRD		*((volatile u8 *)0x31)
#define PORTD		*((volatile u8 *)0x32)
#define PIND		*((volatile u8 *)0x30)






int main(void)
{
	/*cnfigure pin0 and pin1 at port A as output */
	DDRA = 0b00000011;
	while(1)
	{
		/*LED ON1 FOR ONE SECOND AND LED TWO OFF FOR ONE SECOND*/
		PORTA = 0b00000001;
		_delay_ms(1000);
		/*LED ON1 FOR ONE SECOND AND LED TWO OFF FOR ONE SECOND*/
		PORTA = 0b00000010;
		_delay_ms(1000);
	}
}