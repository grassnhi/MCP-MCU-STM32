/*
 * software_timer.h
 *
 *  Created on: Sep 23, 2023
 *      Author: PC
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

extern int timer_flag[4];

void setTimer0(int duration);
void setTimer1(int duration);
void setTimer2(int duration);
void setTimer3(int duration);

void timer_run();

#endif /* INC_SOFTWARE_TIMER_H_ */