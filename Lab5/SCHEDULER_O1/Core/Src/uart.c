/*
 * uart.c
 *
 *  Created on: Nov 19, 2023
 *      Author: PC
 */


#include "uart.h"
#include "stdio.h"

char str[50];
uint8_t temp = 0;

void displayUART(uint32_t ID, uint32_t DELAY, UART_HandleTypeDef huart2) {
	HAL_UART_Transmit(&huart2, (void*)str, sprintf(str, "!%lu=%lu#\r\n", ID, DELAY), 1000);
}
