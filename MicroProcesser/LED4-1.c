#include <avr/io.h>
#include <util/delay.h>
int main()
{
	DDRB = 0x3C;

	while(1)
	{
	PORTB = ~(0x0C);
	_delay_ms(500);
	PORTB = ~(0X30);
	_delay_ms(500);
	}
}
