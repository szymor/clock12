/*
 * btn.h
 *
 *  Created on: 29 lip 2014
 *
 */

#ifndef BTN_H_
#define BTN_H_

#include <avr/io.h>

#define BTN_BUTTON_PORT	PORTC
#define BTN_BUTTON_DDR	DDRC
#define BTN_BUTTON_PIN	PINC
#define BTN_BUTTON_NUM	2
#define BTN_JUMPER_PORT	PORTC
#define BTN_JUMPER_DDR	DDRC
#define BTN_JUMPER_PIN	PINC
#define BTN_JUMPER_NUM	3

void btnInit(void);
uint8_t btnIsJumperOn(void);
uint8_t btnIsButtonPressed(void);

#endif /* BTN_H_ */
