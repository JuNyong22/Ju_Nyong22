#include <avr/io.h>
#include <util/delay.h>

int main()
{
	DDRA = 0xFF;
	DDRC = 0xF0;
	unsigned char SW = 0, LED_ON1 = 0xFF, LED_ON2_1 = 0x01, LED_ON2_2 = 0x80, LED_ON3_1 = 0x00, LED_ON3_2 = 0x00;
	int i, CNT = 0;
	PORTA = LED_ON1;
	while(1)
	{
		if(~PINC & 0x01) SW = 1;
		if(~PINC & 0x02) SW = 2;
		if(~PINC & 0x04) SW = 3;
		if(~PINC & 0x08) SW = 4;

		if(SW == 1)
		{
			PORTA = LED_ON1;
			_delay_ms(500);
			PORTA = ~LED_ON1;
			_delay_ms(500);
			if(~PINC & 0x02)
			{
				SW = 2;
				break;
			}
		}

		if(SW == 2)
		{
			for(i = 0; i < 7; i++)
			{
				PORTA = ~(LED_ON2_1<<i);
				_delay_ms(500);
			}
			for(i = 0; i < 7; i++)
			{
				PORTA = ~(LED_ON2_2>>i);
				_delay_ms(500);
			}
		}

		if(SW == 3)
		{
			for(i=0; i<4; i++)
					{
						LED_ON3_1 = (LED_ON3_1>>1);
						LED_ON3_2 = (LED_ON3_2<<1);
						PORTC = ~(LED_ON3_1 | LED_ON3_2);
						_delay_ms(500);
					}

					for(i=0; i<4; i++)
					{
						LED_ON3_1 = (LED_ON3_1<<1);
						LED_ON3_2 = (LED_ON3_2>>1);
						PORTC = ~(LED_ON3_1 | LED_ON3_2);
						_delay_ms(500);
					}
		}
	}
}
