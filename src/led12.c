/*
 * led12.c
 *
 *  Created on: 28 lip 2014
 *
 */

#include "led12.h"

volatile uint8_t * const ports[12] = {
		&LED12_D12_PORT,
		&LED12_D1_PORT,
		&LED12_D2_PORT,
		&LED12_D3_PORT,
		&LED12_D4_PORT,
		&LED12_D5_PORT,
		&LED12_D6_PORT,
		&LED12_D7_PORT,
		&LED12_D8_PORT,
		&LED12_D9_PORT,
		&LED12_D10_PORT,
		&LED12_D11_PORT,
};
volatile uint8_t * const ddrs[12] = {
		&LED12_D12_DDR,
		&LED12_D1_DDR,
		&LED12_D2_DDR,
		&LED12_D3_DDR,
		&LED12_D4_DDR,
		&LED12_D5_DDR,
		&LED12_D6_DDR,
		&LED12_D7_DDR,
		&LED12_D8_DDR,
		&LED12_D9_DDR,
		&LED12_D10_DDR,
		&LED12_D11_DDR,
};
uint8_t const pins[12] = {
		LED12_D12_PIN,
		LED12_D1_PIN,
		LED12_D2_PIN,
		LED12_D3_PIN,
		LED12_D4_PIN,
		LED12_D5_PIN,
		LED12_D6_PIN,
		LED12_D7_PIN,
		LED12_D8_PIN,
		LED12_D9_PIN,
		LED12_D10_PIN,
		LED12_D11_PIN,
};
uint8_t bright[12];
uint8_t blink[12];
uint8_t blinkState = 0;

void led12Init(void)
{
	uint8_t i;

	for(i = 0; i < 12; ++i)
	{
		*ports[i] |= 1 << pins[i];
		*ddrs[i] |= 1 << pins[i];
		bright[i] = 0;
		blink[i] = 0;
	}
}

void led12Set(uint8_t led, uint8_t brightness, uint8_t blink_bool)
{
	if(led > 11)
		return;
	bright[led] = brightness;
	blink[led] = blink_bool;
}

void led12Display(void)
{
	uint8_t i = 0;
	uint8_t j;
	do {
		for(j = 0; j < 12; ++j)
		{
			if(!blink[j] || ((blink[j] == 1) && (blinkState < 40)) || ((blink[j] == 2) && (blinkState > 40)))
			{
				if(i < bright[j])
					*ports[j] &= ~(1<<pins[j]);
				else
					*ports[j] |= 1<<pins[j];
			}
		}
		//_delay_us(20);
		++i;
	} while(i);
	++blinkState;
	blinkState %= 80;
}
