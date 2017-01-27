/*
 * btn.c
 *
 *  Created on: 29 lip 2014
 *
 */

#include "btn.h"

void btnInit(void)
{
	BTN_BUTTON_PORT |= 1 << BTN_BUTTON_NUM;
	BTN_JUMPER_PORT |= 1 << BTN_JUMPER_NUM;
	// button and jumper ddrs are 0 by default
}

uint8_t btnIsJumperOn(void)
{
	return !(BTN_JUMPER_PIN & (1 << BTN_JUMPER_NUM));
}

uint8_t btnIsButtonPressed(void)
{
	return !(BTN_BUTTON_PIN & (1 << BTN_BUTTON_NUM));
}
