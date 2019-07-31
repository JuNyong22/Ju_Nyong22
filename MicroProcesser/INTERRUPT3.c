#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

volatile unsigned int sw1 = 0, sw2 = 0, i, a = 0xFF, b = 0xFF;

ISR(INT0_vect)
{
	for(i = 0; i < 3; i++)
	{
		PORTA = ~0xFF;
		PORTC = ~0xFF;
		_delay_ms(300);
		PORTA = 0xFF;
		PORTC = 0xFF;
		_delay_ms(300);
	}
	PORTA = 0x00;
	PORTC = 0x00;
	sw1 = 0;
	sw2 = 0;
	EIMSK = 0x07;
	a = 0xFF;
	b = 0xFF;
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
	DDRA = 0x1F;
	DDRC = 0x1F;
	DDRD = 0x00;

	EICRA = 0x2A;
	EIMSK = 0x07;
	SREG |= 0x80;

	PORTA = 0x00;
	PORTC = 0x00;

	a = 0xFF;
	b = 0xFF;
	while(1)
	{

		if(a != 0x1F)
		{
			if(sw1 == 5)
			{
				PORTA = ~a << 1 | 0x01;
				sw1 = 0;
				a = ~PORTA;
			}

			if (a == ~(0x1F))
			{
				for(i = 0; i < 3; i++)
				{
					PORTA = ~0xFF;
					_delay_ms(300);
					PORTA = 0xFF;
					_delay_ms(300);
				}
				a = 0xFF;
				PORTA = 0x00;
				EIMSK = 0x01;
			}
			
		}

		if(b != 0x1F)
		{
			if(sw2 == 5)
			{
				PORTC = ~b << 1 | 0x01;
				sw2 = 0;
				b = ~PORTC;
			}

			if (b == ~(0x1F))
			{
				for(i = 0; i < 3; i++)
				{
					PORTC = ~0xFF;
					_delay_ms(300);
					PORTC = 0xFF;
					_delay_ms(300);
				}
				b = 0xFF;
				PORTC = 0x00;
				EIMSK = 0x01;
			}
		}
	}
}
