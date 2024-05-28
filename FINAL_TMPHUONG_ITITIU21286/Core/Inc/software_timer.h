/*
 * software_timer.h
 *
 *  Created on: May 27, 2024
 *      Author: MSI
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

extern int timer0_flag;

void setTimer0(int duration);

void timerRun();

#endif /* INC_SOFTWARE_TIMER_H_ */
