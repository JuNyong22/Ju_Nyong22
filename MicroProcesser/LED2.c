#include <avr/io.h>
#include <util/delay.h>
int main()

{
	DDRA = 0b00000101;
	

	while(1)
	{
		PORTA = 0b00000001;
		_delay_ms(100);
		PORTA = 0b00000100;
		_delay_ms(100);
	}
}
