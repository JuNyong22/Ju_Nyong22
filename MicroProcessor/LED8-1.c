#include <avr/io.h>
#include <util/delay.h>
int main()
{
	DDRC = 0xF7;
	/*int i;
	unsigned char LED1 = 0x00, LED2 = 0x00;
	unsigned char LED_ON[4] = {0x81, 0xC3, 0xE7, 0xFF};
	while(1)
	{
		for(i =0; i<=3; i++)
		{
			PORTC = ~LED_ON[i];
			_delay_ms(500);
		}

		for(i=2; i>=0; i--)
		{
			PORTC = ~LED_ON[i];
			_delay_ms(500);
		}
		PORTC = 0xFF;
		_delay_ms(500);
	}
	while(1)
	{
		for(i=0; i<4; i++)
		{
			LED1 = (LED1>>1) | 0x80;
			LED2 = (LED2<<1) | 0x01;
			PORTC = ~(LED1 | LED2);
			_delay_ms(500);
		}

		for(i=0; i<4; i++)
		{
			LED1 = (LED1<<1);
			LED2 = (LED2>>1);
			PORTC = ~(LED1 | LED2);
			_delay_ms(500);
		}
	}*/
	}
