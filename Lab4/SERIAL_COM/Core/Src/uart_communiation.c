/*
 * uart_communiation.c
 *
 *  Created on: Nov 2, 2023
 *      Author: PC
 */

#include "uart_communiation.h"

void uart_communiation_fsm(ADC_HandleTypeDef hadc1, UART_HandleTypeDef huart2) {
	switch(uart_status) {

	case RST:
		if (command_flag == 1) {
			command_flag = 0;
			if (command[0] == 'R' && command[1] == 'S' && command[2] == 'T') {
				// Get ADC value
				HAL_ADC_Start(&hadc1);
				ADC_value = HAL_ADC_GetValue(&hadc1);
				HAL_ADC_Stop(&hadc1);
				HAL_UART_Transmit(&huart2, (void*)str, sprintf(str, "\r\n"), 1000);
				uart_status = ADC;
				setTimer(1, 3000);
			}
		}
		break;

	case ADC:
		HAL_UART_Transmit(&huart2, (void*)str, sprintf(str, "!ADC=%lu#\r\n", ADC_value), 1000);
		uart_status = OK;
		break;

	case OK:
		if (command_flag == 1) {
			command_flag = 0;
			if (command[0] == 'O' && command[1] == 'K') {
				HAL_UART_Transmit(&huart2, (void*)str, sprintf(str, "\r\n"), 1000);
				uart_status = RST;
				clearTimer(1);
			}
		}
		if(timer_flag[1] == 1) {
			uart_status = ADC;
			setTimer(1, 3000);
		}
		break;
	default:
		break;
	}
}
