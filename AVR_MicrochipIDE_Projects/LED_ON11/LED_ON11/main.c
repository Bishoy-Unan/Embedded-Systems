
#include<util/delay.h>
//#include <xc.h>



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

#define SFIO		*((volatile u8 *)0x50)





u8 Button=0;
int main(void)
{
	/*p0&p1&p2&p3 for led and p4 for switich*/
	/*configure p0,p1,p2,p3 as out and p4 as input*/
	DDRA = 0b00001111;
	/*enable pull up resistor at pin 4 port A*/
	PORTA = 0b00010000;
	while(1)
	{
		/*because of avr by default is pull up resistor so when the switch pressed we read zero on p4*/
		Button=(1&(PINA>>4));
		if(Button==0)
		{
			PORTA +=1;
			_delay_ms(1000);
		}
		
	
	}
}