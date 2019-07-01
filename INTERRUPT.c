#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
volatile unsigned int sw1 = 0, sw2 = 0;

ISR(INT0_vect)
{
	PORTC = 0x00;
	sw1 = 0;
	sw2 = 0;
}

ISR(INT1_vect)
{
	sw1++;
}

ISR(INT2_vect)
{
	sw2++;
}

int main(void)
{
	DDRC = 0x03;
	DDRD = 0x00;

	EICRA = 0x2A;
	EIMSK = 0x07;
	SREG |= 0x80;

	PORTC = 0x00;

	while(1)
	{
		if(sw1 >= 5)
		{
			PORTC = 0x01;
			sw2 = 0;
		}

		if(sw2 >= 5)
		{
			PORTC = 0x02;
			sw1 = 0;
		}
	}
}
