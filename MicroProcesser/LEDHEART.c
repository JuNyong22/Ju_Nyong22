#include <avr/io.h>
#include <util/delay.h>
int main()
{
	int i;
	unsigned char LED_ON1 = 0xFF, LED_ON2 = 0xFF;
	DDRA = 0xFF;
	DDRC = 0xFF;

	while(1)
	{
		PORTA = 0xFF;
		PORTC = 0xFF;
		for(i=0; i<=7; i++)
		{
			LED_ON1 = (LED_ON1<<1);
			PORTA = LED_ON1;
			_delay_ms(300);
		}
		for(i=0; i<=7; i++)
		{
			LED_ON2 = (LED_ON2<<1);
			PORTC = LED_ON2;
			_delay_ms(300);
		}
		LED_ON1 = 0xFF;
		LED_ON2 = 0xFF;
	}
}
