/*
 * led12.h
 *
 *  Created on: 28 lip 2014
 *
 */

#ifndef LED12_H_
#define LED12_H_

#include <avr/io.h>
#include <util/delay.h>

#define LED12_D1_PORT	PORTD
#define LED12_D1_DDR	DDRD
#define LED12_D1_PIN	1
#define LED12_D2_PORT	PORTD
#define LED12_D2_DDR	DDRD
#define LED12_D2_PIN	2
#define LED12_D3_PORT	PORTD
#define LED12_D3_DDR	DDRD
#define LED12_D3_PIN	3
#define LED12_D4_PORT	PORTD
#define LED12_D4_DDR	DDRD
#define LED12_D4_PIN	4
#define LED12_D5_PORT	PORTB
#define LED12_D5_DDR	DDRB
#define LED12_D5_PIN	6
#define LED12_D6_PORT	PORTB
#define LED12_D6_DDR	DDRB
#define LED12_D6_PIN	7
#define LED12_D7_PORT	PORTD
#define LED12_D7_DDR	DDRD
#define LED12_D7_PIN	5
#define LED12_D8_PORT	PORTD
#define LED12_D8_DDR	DDRD
#define LED12_D8_PIN	6
#define LED12_D9_PORT	PORTD
#define LED12_D9_DDR	DDRD
#define LED12_D9_PIN	7
#define LED12_D10_PORT	PORTB
#define LED12_D10_DDR	DDRB
#define LED12_D10_PIN	0
#define LED12_D11_PORT	PORTB
#define LED12_D11_DDR	DDRB
#define LED12_D11_PIN	1
#define LED12_D12_PORT	PORTD
#define LED12_D12_DDR	DDRD
#define LED12_D12_PIN	0

void led12Init(void);
void led12Set(uint8_t led, uint8_t brightness, uint8_t blink_bool);
void led12Display(void);

#endif /* LED12_H_ */
