/*
 * rtc.c
 *
 *  Created on: 29 lip 2014
 *
 */

#include "rtc.h"

void rtcGetTime(uint8_t* hour, uint8_t* minute)
{
	i2c_start_wait(0xD0);
	i2c_write(0x01); // 0x01 minutes, 0x02 hours
	i2c_rep_start(0xD1);
	*minute = i2c_read(1);
	*hour = i2c_read(0);
	i2c_stop();

	// bcd2bin conversion
	*minute = ((*minute & 0xF0) >> 4)*10 + (*minute & 0x0F);
	*hour = ((*hour & 0x10) >> 4)*10 + (*hour & 0x0F);
}

void rtcSetTime(uint8_t hour, uint8_t minute)
{
	// bin2bcd conversion
	hour = ((hour / 10) << 4) | (hour % 10);
	minute = ((minute / 10) << 4) | (minute % 10);
	hour |= 0x40; // 12-hour mode

	i2c_start_wait(0xD0);
	i2c_write(0x00);
	i2c_write(0x80); // halt
	i2c_stop();

	i2c_start_wait(0xD0);
	i2c_write(0x01);
	i2c_write(minute);
	i2c_write(hour);
	i2c_stop();

	i2c_start_wait(0xD0);
	i2c_write(0x00);
	i2c_write(0x00); // resume and reset seconds
	i2c_stop();
}
