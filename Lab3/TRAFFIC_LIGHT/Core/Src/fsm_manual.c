/*
 * fsm_manual.c
 *
 *  Created on: Oct 23, 2023
 *      Author: PC
 */

#include "fsm_manual.h"

void fsm_manual_run(){
	switch(status){
	case MODE2:
			set_blinky(INIT);

			index_led = 0;
			updateBufferMode2();
			update7SEG(index_led);

			setTimer(2, 500);
			setTimer(3, 500);
			clearTimer(0);
			clearTimer(1);

			status = AUTO_RED;

			break;

		case AUTO_RED:
			if (timer_flag[3] == 1) {
				setTimer(3, 500);
				set_blinky(AUTO_RED);
			}
			if (timer_flag[2] == 1) {
				setTimer(2, 500);
				updateBufferMode2();
				update7SEG(index_led);
			}
			if (check_button_pressed(0) == 1) {
				status = MODE3;
			}
			if (check_button_pressed(1) == 1) {
				status = ADJ_RED;
				if (RED >= 99) RED = AMBER + 1;
				else RED++;
			}
			break;

		case ADJ_RED:
			if (timer_flag[3] == 1) {
				setTimer(3, 500);
				set_blinky(AUTO_RED);
			}
			if (timer_flag[2] == 1) {
				setTimer(2, 500);
				updateBufferMode2();
				update7SEG(index_led);
			}
			if (check_button_pressed(1) == 1) {
				if (RED >= 99) RED = AMBER + 1;
				else RED++;
			}
			if (check_button_pressed(2) == 1) {
				status = AUTO_RED;
				GREEN = RED - AMBER;
			}
			break;

		case MODE3:
			set_blinky(AUTO_AMBER);

			index_led = 0;
			updateBufferMode2();
			update7SEG(index_led);

			setTimer(2, 500);
			setTimer(3, 500);
			clearTimer(0);
			clearTimer(1);

			status = AUTO_AMBER;
			break;

		case AUTO_AMBER:
			if (timer_flag[3] == 1) {
				setTimer(3, 500);
				set_blinky(AUTO_AMBER);
			}
			if (timer_flag[2] == 1) {
				setTimer(2, 500);
				updateBufferMode3();
				update7SEG(index_led);
			}
			if (check_button_pressed(0) == 1) {
				status = MODE4;
			}
			if (check_button_pressed(1) == 1) {
				status = ADJ_AMBER;
				if (AMBER >= 5) AMBER = 1;
				else AMBER++;
			}
			break;

		case ADJ_AMBER:
			if (timer_flag[3] == 1) {
				setTimer(3, 500);
				set_blinky(AUTO_AMBER);
			}
			if (timer_flag[2] == 1) {
				setTimer(2, 500);
				updateBufferMode3();
				update7SEG(index_led);
			}
			if (check_button_pressed(1) == 1) {
				if (AMBER >= 5) AMBER = 1;
				else AMBER++;
			}
			if (check_button_pressed(2) == 1) {
				status = AUTO_AMBER;
				if (RED <= AMBER) RED = AMBER + 1;
				GREEN = RED - AMBER;
			}
			break;

		case MODE4:
			set_blinky(AUTO_GREEN);

			index_led = 0;
			updateBufferMode2();
			update7SEG(index_led);

			setTimer(2, 500);
			setTimer(3, 500);
			clearTimer(0);
			clearTimer(1);

			status = AUTO_GREEN;

			break;

		case AUTO_GREEN:
			if (timer_flag[3] == 1) {
				setTimer(3, 500);
				set_blinky(AUTO_GREEN);
			}
			if (timer_flag[2] == 1) {
				setTimer(2, 500);
				updateBufferMode4();
				update7SEG(index_led);
			}
			if (check_button_pressed(0) == 1) {
				status = MODE1;
			}
			if (check_button_pressed(1) == 1) {
				status = ADJ_GREEN;
				if (GREEN >= RED - AMBER) GREEN = 1;
				else GREEN++;
			}
			break;

		case ADJ_GREEN:
			if (timer_flag[3] == 1) {
				setTimer(3, 500);
				set_blinky(AUTO_GREEN);
			}
			if (timer_flag[2] == 1) {
				setTimer(2, 500);
				updateBufferMode4();
				update7SEG(index_led);
			}
			if (check_button_pressed(1) == 1) {
				if (GREEN >= RED - AMBER) GREEN = 1;
				else GREEN++;
			}
			if (check_button_pressed(2) == 1) {
				status = AUTO_GREEN;
				RED = GREEN + AMBER;
			}
			break;

		default:
			break;
	}
}
