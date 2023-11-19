/*
 * display7SEG.c
 *
 *  Created on: Oct 22, 2023
 *      Author: PC
 */

#include "display7SEG.h"

void display7SEG1(int num) {
	const uint8_t sevenSegment[10] = {	0b00111111, // 0
											0b00000110, // 1
											0b01011011, // 2
											0b01001111, // 3
											0b01100110, // 4
											0b01101101, // 5
											0b01111101, // 6
											0b00000111, // 7
											0b01111111, // 8
											0b01101111  // 9
		};
		HAL_GPIO_WritePin(SEG1a_GPIO_Port, SEG1a_Pin, (sevenSegment[num] & 0x01) ? RESET : SET);
		HAL_GPIO_WritePin(SEG1b_GPIO_Port, SEG1b_Pin, (sevenSegment[num] & 0x02) ? RESET : SET);
		HAL_GPIO_WritePin(SEG1c_GPIO_Port, SEG1c_Pin, (sevenSegment[num] & 0x04) ? RESET : SET);
		HAL_GPIO_WritePin(SEG1d_GPIO_Port, SEG1d_Pin, (sevenSegment[num] & 0x08) ? RESET : SET);
		HAL_GPIO_WritePin(SEG1e_GPIO_Port, SEG1e_Pin, (sevenSegment[num] & 0x10) ? RESET : SET);
		HAL_GPIO_WritePin(SEG1f_GPIO_Port, SEG1f_Pin, (sevenSegment[num] & 0x20) ? RESET : SET);
		HAL_GPIO_WritePin(SEG1g_GPIO_Port, SEG1g_Pin, (sevenSegment[num] & 0x40) ? RESET : SET);
}

void display7SEG2(int num){
	const uint8_t sevenSegment[10] = {	0b00111111, // 0
										0b00000110, // 1
										0b01011011, // 2
										0b01001111, // 3
										0b01100110, // 4
										0b01101101, // 5
										0b01111101, // 6
										0b00000111, // 7
										0b01111111, // 8
										0b01101111  // 9
	};
	HAL_GPIO_WritePin(SEG2a_GPIO_Port, SEG2a_Pin, (sevenSegment[num] & 0x01) ? RESET : SET);
	HAL_GPIO_WritePin(SEG2b_GPIO_Port, SEG2b_Pin, (sevenSegment[num] & 0x02) ? RESET : SET);
	HAL_GPIO_WritePin(SEG2c_GPIO_Port, SEG2c_Pin, (sevenSegment[num] & 0x04) ? RESET : SET);
	HAL_GPIO_WritePin(SEG2d_GPIO_Port, SEG2d_Pin, (sevenSegment[num] & 0x08) ? RESET : SET);
	HAL_GPIO_WritePin(SEG2e_GPIO_Port, SEG2e_Pin, (sevenSegment[num] & 0x10) ? RESET : SET);
	HAL_GPIO_WritePin(SEG2f_GPIO_Port, SEG2f_Pin, (sevenSegment[num] & 0x20) ? RESET : SET);
	HAL_GPIO_WritePin(SEG2g_GPIO_Port, SEG2g_Pin, (sevenSegment[num] & 0x40) ? RESET : SET);
}

int index_led = 0;
int led_buffer[4] = {1,2,3,4};
void update7SEG(int index){
	switch(index){
	case 0:
		index_led = 1;

		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, RESET);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, RESET);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);

		display7SEG1(led_buffer[0]);
		display7SEG2(led_buffer[1]);
		break;
	case 1:
		index_led = 0;

		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, RESET);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, RESET);

		display7SEG1(led_buffer[2]);
		display7SEG2(led_buffer[3]);
		break;
	default:
		break;
	}
}

int counter1 = 1, counter2 = 1;
void updateBufferMode1() {
	if (counter1 <= RED) {
		led_buffer[0] = (RED - counter1) / 10;
		led_buffer[1] = (RED - counter1) % 10;
	}
	else if (counter1 <= (RED + GREEN)) {
		led_buffer[0] = (RED + GREEN - counter1) / 10;
		led_buffer[1] = (RED + GREEN - counter1) % 10;
	}
	else{
		led_buffer[0] = (RED + GREEN + AMBER - counter1) / 10;
		led_buffer[1] = (RED + GREEN + AMBER - counter1) % 10;
	}

	counter1++;
	if (counter1 > RED + AMBER + GREEN) counter1 = 1;

	/* --- */

	if (counter2 <= GREEN) {
		led_buffer[2] = (GREEN - counter2) / 10;
		led_buffer[3] = (GREEN - counter2) % 10;
	}
	else if (counter2 <= (AMBER + GREEN)) {
		led_buffer[2] = (AMBER + GREEN - counter2) / 10;
		led_buffer[3] = (AMBER + GREEN - counter2) % 10;
	}
	else {
		led_buffer[2] = (RED + GREEN + AMBER - counter2) / 10;
		led_buffer[3] = (RED + GREEN + AMBER - counter2) % 10;
	}

	counter2++;
	if (counter2 > RED + AMBER + GREEN) counter2 = 1;
}

void updateBufferMode2() {
	led_buffer[0] = 0;
	led_buffer[1] = 2;

	led_buffer[2] = RED / 10;
	led_buffer[3] = RED % 10;
}

void updateBufferMode3() {
	led_buffer[0] = 0;
	led_buffer[1] = 3;

	led_buffer[2] = AMBER / 10;
	led_buffer[3] = AMBER % 10;
}

void updateBufferMode4() {
	led_buffer[0] = 0;
	led_buffer[1] = 4;

	led_buffer[2] = GREEN / 10;
	led_buffer[3] = GREEN % 10;
}
