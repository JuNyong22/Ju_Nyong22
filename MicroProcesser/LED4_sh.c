#include <avr/io.h>
#include <util/delay.h>
int main()
{
	unsigned char LED_ON = 0x01;
	int i;
	DDRA = 0xFF;

	while(1)
	{
		for(i=0; i<7; i++)
		{
			PORTA = LED_ON;
			LED_ON = (LED_ON<<i^0xFF);
		}
	}
	/*while(1)
	{
		PORTB = LED_ON;
		LED_ON = LED_ON^0xFF;
		_delay_ms(300);

	}*/
/*	while(1)
	{

		for(i=0; i<4; i++)
		{
			PORTB = ~((LED_FORWARD)<<i);
			_delay_ms(500);
		}

		for(i=0; i<2; i++)
		{
			PORTB = ~((LED_BACK)>>i);
			_delay_ms(500);
		}
	}*/
	/*while(1)
	{
		for(i=0;i<7;i++)
		{
			PORTB = LED_ON;
			LED_ON = LED_ON<<1|0x01;
			_delay_ms(300);
		}
		for(i=0;i<7;i++)
		{
			PORTB = LED_ON;
			LED_ON = LED_ON>>1|0x80;
			_delay_ms(300);
		}
	}*/
}
