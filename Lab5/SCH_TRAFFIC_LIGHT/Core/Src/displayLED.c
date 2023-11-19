/*
 * displayLED.c
 *
 *  Created on: Oct 22, 2023
 *      Author: PC
 */

#include "displayLED.h"

void traffic_light(int color) {
	switch (color) {
		case INIT:
			HAL_GPIO_WritePin(GPIOA, R1_Pin | G1_Pin | A1_Pin | R2_Pin | G2_Pin | A2_Pin, GPIO_PIN_SET);
			break;
		case AUTO_RED1_GREEN2:
			HAL_GPIO_WritePin(GPIOA, R1_Pin | G2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, G1_Pin | A1_Pin | R2_Pin | A2_Pin, GPIO_PIN_SET);
			break;
		case AUTO_RED1_AMBER2:
			HAL_GPIO_WritePin(GPIOA, R1_Pin | A2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, G1_Pin | A1_Pin | G2_Pin | R2_Pin, GPIO_PIN_SET);
			break;
		case AUTO_GREEN1_RED2:
			HAL_GPIO_WritePin(GPIOA, G1_Pin | R2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, R1_Pin | A1_Pin | G2_Pin | A2_Pin, GPIO_PIN_SET);
			break;
        case AUTO_AMBER1_RED2:
			HAL_GPIO_WritePin(GPIOA, A1_Pin | R2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, G1_Pin | R1_Pin |  G2_Pin | A2_Pin, GPIO_PIN_SET);
			break;
		default:
			break;
	}
}

void set_blinky(int color) {
	switch (color) {
        case INIT:
			// HAL_GPIO_WritePin(R1_GPIO_Port, R1_Pin, GPIO_PIN_RESET);
			// HAL_GPIO_WritePin(R2_GPIO_Port, R2_Pin, GPIO_PIN_RESET);
            // HAL_GPIO_WritePin(GPIOA, R1_Pin | G1_Pin | A1_Pin | R2_Pin | G2_Pin | A2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(R1_GPIO_Port, R1_Pin, RESET);
			HAL_GPIO_WritePin(R2_GPIO_Port, R2_Pin, RESET);
			HAL_GPIO_WritePin(A1_GPIO_Port, A1_Pin, SET);
			HAL_GPIO_WritePin(A2_GPIO_Port, A2_Pin, SET);
			HAL_GPIO_WritePin(G1_GPIO_Port, G1_Pin, SET);
			HAL_GPIO_WritePin(G2_GPIO_Port, G2_Pin, SET);
            break;
		case AUTO_RED:
			HAL_GPIO_WritePin(GPIOA, G1_Pin | A1_Pin | G2_Pin | A2_Pin, GPIO_PIN_SET);
			HAL_GPIO_TogglePin(R1_GPIO_Port, R1_Pin);
			HAL_GPIO_TogglePin(R2_GPIO_Port, R2_Pin);
			break;
		case AUTO_AMBER:
			HAL_GPIO_WritePin(GPIOA, R1_Pin | G1_Pin | R2_Pin | G2_Pin , GPIO_PIN_SET);
			HAL_GPIO_TogglePin(A1_GPIO_Port, A1_Pin);
			HAL_GPIO_TogglePin(A2_GPIO_Port, A2_Pin);
			break;
		case AUTO_GREEN:
			HAL_GPIO_WritePin(GPIOA, R1_Pin | A1_Pin | R2_Pin | A2_Pin, GPIO_PIN_SET);
			HAL_GPIO_TogglePin(GPIOA, G1_Pin | G2_Pin);
			break;
		default:
			break;
	}
}