#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
volatile unsigned int sw1 = 0, sw2 = 0, i, tmp = 0, start = 0;

ISR(INTO_vect)
{
	EIMSK = 0x07;
	for(i = 0; i <  3; i++)
	{
		PORTC = 0x00;
		_delay_ms(300);
		PORTC = 0xFF;
		_delay_ms(300);
	}

	sw1 = 0;
	sw2 = 0;
	tmp = 0;
	start = 1;
}

ISR(INT1_vect)
{
	if(start == 1)
		sw1++;
}

ISR(INT2_vect)
{
	if(start == 1)
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
			while(tmp < 3)
			{
				PORTC = 0x01;
				_delay_ms(300);
				PORTC = 0x00;
				_delay_ms(300);
				tmp++;
			}
			PORTC = 0x00;
			EIMSK = 0x01;

		}

		if(sw2 >= 5)
		{
			while(tmp <3)
			{
				PORTC = 0x02;
				_delay_ms(300);
				PORTC = 0x00;
				_delay_ms(300);
				tmp++;
			}
			PORTC = 0x00;
			EIMSK = 0x01;

		}
	}
}
