/*
 * fsm_mode.c
 *
 *  Created on: Oct 22, 2023
 *      Author: PC
 */

#include "fsm_automatic.h"

void fsm_automatic_run() {
	switch(status){

	case INIT:
		status = MODE1;
		break;

	case MODE1:
		status = AUTO_RED1_GREEN2;

		traffic_light(INIT);

		counter1 = 1;
		counter2 = 1;
		index_led = 0;

		updateBufferMode1();
		update7SEG(index_led);

		setTimer(0, GREEN * 1000);	// Timer AUTO_RED1_GREEN2
		setTimer(1, 1000);			// Timer updateBufferMode1
		setTimer(2, 500);			// Timer LED 7-SEG
		clearTimer(3);				// Timer blinking LED

		break;

	case AUTO_RED1_GREEN2:
		traffic_light(AUTO_RED1_GREEN2);

		if (timer_flag[0] == 1) {
			status = AUTO_RED1_AMBER2;
			setTimer(0, AMBER * 1000);
		}
		if (timer_flag[1] == 1) {
			updateBufferMode1();
			setTimer(1, 1000);
		}
		if (timer_flag[2] == 1) {
			update7SEG(index_led);
			setTimer(2, 500);
		}
		if (check_button_pressed(0) == 1) {
			status = MODE2;
		}
		break;

	case AUTO_RED1_AMBER2:
		traffic_light(AUTO_RED1_AMBER2);

		if (timer_flag[0] == 1) {
			status = AUTO_GREEN1_RED2;
			setTimer(0, GREEN * 1000);
		}
		if (timer_flag[1] == 1) {
			updateBufferMode1();
			setTimer(1, 1000);
		}
		if (timer_flag[2] == 1) {
			update7SEG(index_led);
			setTimer(2, 500);
		}
		if (check_button_pressed(0) == 1) {
			status = MODE2;
		}
		break;

	case AUTO_GREEN1_RED2:
		traffic_light(AUTO_GREEN1_RED2);

		if (timer_flag[0] == 1) {
			status = AUTO_AMBER1_RED2;
			setTimer(0, AMBER * 1000);
		}
		if (timer_flag[1] == 1) {
			updateBufferMode1();
			setTimer(1, 1000);
		}
		if (timer_flag[2] == 1) {
			update7SEG(index_led);
			setTimer(2, 500);
		}
		if (check_button_pressed(0) == 1) {
			status = MODE2;
		}
		break;

	case AUTO_AMBER1_RED2:
		traffic_light(AUTO_AMBER1_RED2);

		if (timer_flag[0] == 1) {
			status = AUTO_RED1_GREEN2;
			setTimer(0, GREEN * 1000);
		}
		if (timer_flag[1] == 1) {
			updateBufferMode1();
			setTimer(1, 1000);
		}
		if (timer_flag[2] == 1) {
			update7SEG(index_led);
			setTimer(2, 500);
		}
		if (check_button_pressed(0) == 1) {
			status = MODE2;
		}
		break;

	default:
		break;
	}
}

