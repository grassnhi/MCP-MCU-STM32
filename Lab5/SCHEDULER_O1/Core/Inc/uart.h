/*
 * uart.c
 *
 *  Created on: Nov 19, 2023
 *      Author: PC
 */

#ifndef INC_UART_C_
#define INC_UART_C_

#include "main.h"

extern char str[50];
extern uint8_t temp;

//UART_HandleTypeDef huart2;

void displayUART(uint32_t ID, uint32_t DELAY, UART_HandleTypeDef huart2);

#endif /* INC_UART_C_ */
