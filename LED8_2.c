#include <avr/io.h>
#include <util/delay.h>
int main()
{
	unsigned char SW, LED_ON=0xF7;
	DDRB = 0xF7;
	while(1)
	{
		SW = ~PINB & 0x08;
		if( SW == 0x08)
		{
			LED_ON = ~LED_ON;
			_delay_ms(30);
		}
		PORTC = LED_ON;

	}
}
