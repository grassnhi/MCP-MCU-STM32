/*
 * blinky_led.c2
 *
 *  Created on: Sep 28, 2023
 *      Author: KAI
 */

#include "blinky_led.h"
#include "software_timer.h"

void blinky_led_run(){
	switch(led_status){
		case INIT:
			led_status = LED_ON;
			setTimer(200);
			break;
		case LED_ON:
			led_on();
			if(timer_flag == 1){
				led_status = LED_OFF;
				setTimer(300);
			}
			break;
		case LED_OFF:
			led_off();
			if(timer_flag == 1){
				led_status = LED_ON;
				setTimer(200);
			}
			break;
		default:
			break;
	}
}
