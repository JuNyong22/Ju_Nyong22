#include <avr/io.h>
#include <util/delay.h>

int main()
{
	DDRA = 0x7F;
	DDRB = 0xF8;
	unsigned char LED_ON = 0x08, SW1 = 0, SW2 = 0, SW3 = 0, CNT1 = 0, CNT2 = 0, FLAG1 = 0, FLAG2 = 0;
	PORTA = 0xF7;
	while(1)
	{
		SW1 = ~PINB & 0x01;
		SW2 = ~PINB & 0x02;
		SW3 = ~PINB & 0x04;

		if(SW1 == 0x01)
		{
		PORTA = 0xF7;
		CNT1 = 0;
		CNT2 = 0;
		SW1 = 0;
		SW2 = 0;
		SW3 = 0;
		FLAG1 = 0;
		FLAG2 = 0;
		LED_ON = 0x08;
		}

		if(SW3 == 0x04)
		{
			if(FLAG1 == 0)
			{
				if(LED_ON == 0x40 || LED_ON == 0x01)
				{
					continue;
				} //LED 마지막 부분 끝
				else
				{
					FLAG1 = 1;
					CNT2 = 0;
					CNT1++;
					if(CNT1 == 2)
					{
						CNT1 =0;
						LED_ON = LED_ON<<1;
						_delay_ms(100);
					}
				}
			}
		}
		else FLAG1 = 0;


		if(SW2 == 0x02)
		{
			if(FLAG2 == 0)
			{
				if(LED_ON == 0x40 || LED_ON == 0x01)
				{
					continue;
				} //LED 마지막 부분 끝
				else
				{
					FLAG2 = 1;
					CNT1 = 0;
					CNT2++;
					if(CNT2 == 2)
					{
						CNT2 = 0;
						LED_ON = LED_ON>>1;
						_delay_ms(100);
					}
				}
			}
		}
		else FLAG2 = 0;

		PORTA = ~LED_ON;
	}
	return 0;
}
