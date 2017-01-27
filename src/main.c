/*
 * main.c
 *
 *  Created on: 28 lip 2014
 *  Fuses: H:D9, L:A4
 *  Internal 8 MHz RC oscillator, brown-out detector at 2.7V enabled
 */

#include <avr/io.h>
#include <util/delay.h>

#include <stdlib.h>

#include "led12.h"
#include "twimaster.h"
#include "rtc.h"
#include "btn.h"

uint8_t hour = 0, minute = 0;

void showTime(uint8_t hour, uint8_t minute);
void displayAnimation(uint8_t num);

int main()
{
	uint8_t steps = 0;
	uint8_t prevhour;

	i2c_init();
	led12Init();
	btnInit();

	rtcGetTime(&hour,&minute);
	srand(hour*60+minute);
	prevhour = hour;

	while(1)
	{
		led12Display();
		if(btnIsButtonPressed())
		{
			if(btnIsJumperOn())
			{
				++hour;
				if(hour == 0)
					hour = 12;
				if(hour > 12)
					hour = 1;
				prevhour = hour;
			}
			else
			{
				++minute;
				if(minute > 59)
					minute = 0;
			}
			rtcSetTime(hour,minute);
			showTime(hour,minute);
			_delay_ms(100);
		}
		if(steps == 0)
		{
			prevhour = hour;
			rtcGetTime(&hour,&minute);
			if(prevhour != hour)
				displayAnimation(rand() % 5);
			showTime(hour,minute);
		}
		++steps;
	}
	return 0;
}

void showTime(uint8_t hour, uint8_t minute)
{
	uint8_t i;

	for(i = 0; i < 12; ++i)
		led12Set(i,5,0);

	minute /= 5;
	led12Set(minute,50,1);

	if(hour == 12)
		hour = 0;
	led12Set(hour,200,0);
}

int8_t pos12(int8_t pos)
{
	return pos >= 0 ? pos % 12 : (pos+12)%12;
}

void displayAnimation(uint8_t num)
{
	uint8_t steps = 0, cycles = 0, i;
	int8_t pos = 0, pos2 = 0;

	for(i = 0; i < 12; ++i)
		led12Set(i,0,0);

	switch(num)
	{
	case 0:
		while(cycles < 12)
		{
			led12Display();
			++steps;
			if((steps % 3) == 0)
			{
				if(steps == 3*12)
				{
					++cycles;
					steps = 0;
				}
				led12Set(pos12(pos-2),0,0);
				++pos;
				pos %= 12;
				led12Set(pos,200,0);
				led12Set(pos12(pos-1),50,0);
				led12Set(pos12(pos-2),10,0);
			}
		} break;
	case 1:
		while(cycles < 12)
		{
			led12Display();
			++steps;
			if((steps % 3) == 0)
			{
				if(steps == 3*12)
				{
					++cycles;
					steps = 0;
				}
				led12Set(pos12(pos+2),0,0);
				pos += 11;
				pos %= 12;
				led12Set(pos,200,0);
				led12Set(pos12(pos+1),50,0);
				led12Set(pos12(pos+2),10,0);
			}
		} break;
	case 2:
		while(cycles < 12)
		{
			led12Display();
			++steps;
			if((steps % 3) == 0)
			{
				if(steps == 6*12)
				{
					++cycles;
					steps = 0;
				}
				pos += 11;
				pos %= 12;
				if((steps % 6) == 0)
				{
					++pos2;
					pos2 %= 12;
				}
				for(i = 0; i < 12; ++i)
				{
					uint8_t br = 0;
					if((i == (pos+2)) || (i == (pos2-2)))
						br = 10;
					if((i == (pos+1)) || (i == (pos2-1)))
						br = 50;
					if((i == pos) || (i == pos2))
						br = 200;
					led12Set(i,br,0);
				}
			}
		} break;
	case 3:
		while(cycles < 24)
		{
			led12Display();
			++steps;
			if(steps == 36)
			{
				++cycles;
				steps = 0;
			}
			for(i = 0; i < 12; i+=2)
				led12Set(i,10*cycles,1);
			for(i = 1; i < 12; i+=2)
				led12Set(i,10*cycles,2);
		} break;
	case 4:
		cycles = 0;
		while(cycles < 5)
		{
			++cycles;
			led12Set(0,200,0);
			led12Set(1,200,0);
			led12Set(2,200,0);
			pos = 2;
			steps = 0;
			while(steps < 5*11)
			{
				led12Display();
				++steps;
				if((steps % 5) == 0)
				{
					if(pos > 2)
						led12Set(pos-1,0,0);
					++pos;
					if(pos > 2)
						led12Set(pos-1,20,0);
					led12Set(pos,200,0);
				}
			}
			pos = 1;
			steps = 0;
			while(steps < 5*12)
			{
				led12Display();
				++steps;
				if((steps % 5) == 0)
				{
					led12Set(pos,0,0);
					if(pos > 1)
						led12Set(pos-1,0,0);
					++pos;
					if(pos > 1)
						led12Set(pos-1,20,0);
					led12Set(pos,200,0);
				}
			}
			pos = 0;
			steps = 0;
			while(steps < 5*13)
			{
				led12Display();
				++steps;
				if((steps % 5) == 0)
				{
					led12Set(pos,0,0);
					if(pos > 0)
						led12Set(pos-1,0,0);
					++pos;
					if(pos > 0)
						led12Set(pos-1,20,0);
					led12Set(pos,200,0);
				}
			}
		}
		break;
	}
}
