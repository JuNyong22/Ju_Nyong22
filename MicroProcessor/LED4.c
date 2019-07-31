#include <avr/io.h>
#include <util/delay.h>
int main()

{
	DDRA = 0b00110101;
	int i;

	while(1)
	{
		for (i = 0; i < 4; i++)
		{
			PORTA = ~((0b00000001) << i);
			_delay_ms(100);
		}
		
		for (i = 0; i < 3; i++)
		{
			PORTA = ~((0b00001000) >> i);
			_delay_ms(100);
		}
	}
}
