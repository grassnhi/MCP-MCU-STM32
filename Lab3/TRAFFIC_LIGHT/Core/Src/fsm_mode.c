/*
 * fsm_mode.c
 *
 *  Created on: Oct 22, 2023
 *      Author: PC
 */

#include "fsm_mode.h"
#include "input_reading.h"

void fsm_mode() {
	switch(status){

//----------------------------------------------------------------------------------------------
// MODE INIT
	case INIT:
		status = MODE1;
		break;
//----------------------------------------------------------------------------------------------



//----------------------------------------------------------------------------------------------
// MODE 1
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
//----------------------------------------------------------------------------------------------



//----------------------------------------------------------------------------------------------
// MODE 2
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
//----------------------------------------------------------------------------------------------



//----------------------------------------------------------------------------------------------
// MODE 3
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
//----------------------------------------------------------------------------------------------



//----------------------------------------------------------------------------------------------
// MODE 4
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
//--------------------------------------------------------------------------------------



//--------------------------------------------------------------------------------------
// DEFAULT
	default:
		break;
	}
}

