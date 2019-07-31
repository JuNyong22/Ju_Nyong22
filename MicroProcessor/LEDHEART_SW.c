#include <avr/io.h>
#include <util/delay.h>
int main()
{
	int i;
	unsigned char LED_ON1 = 0xFF, LED_ON2 = 0xFF, SW;
	DDRA = 0xFF;
	DDRB = 0xF7;
	DDRC = 0xFF;

	while(1)
	{
		SW = 0x00;
		if(~PINB & 0x10)
		{
			SW = SW ^ 10;
			_delay_ms(200);
		}
		if(SW == 0x10)
		{
			PORTA = 0xFF;
			PORTC = 0xFF;
			for(i=0; i<=7; i++)
			{
				LED_ON1 = (LED_ON1<<1);
				PORTA = LED_ON1;
				_delay_ms(200);
			}
			for(i=0; i<=7; i++)
			{
				LED_ON2 = (LED_ON2<<1);
				PORTC = LED_ON2;
				_delay_ms(200);
			}
			LED_ON1 = 0xFF;
			LED_ON2 = 0xFF;
		}
		if(SW |= 0x10)
		{
			LED_ON1 = 0xFF;
			LED_ON2 = 0xFF;
		}
	}
}
