#include <avr/io.h>
#include <util/delay.h>
void main()
{
	DDRA = 0b00000001;

	while(1)
	{
		PORTA = 0b00000000;
		_delay_ms(100);
		PORTA = 0b00000001;
		_delay_ms(100);
	}
}
