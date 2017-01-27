/*
 * rtc.h
 *
 *  Created on: 29 lip 2014
 *  DS1307 RTC module used here
 */

#ifndef RTC_H_
#define RTC_H_

#include "twimaster.h"

void rtcGetTime(uint8_t* hour, uint8_t* minute);
void rtcSetTime(uint8_t hour, uint8_t minute);

#endif /* RTC_H_ */
