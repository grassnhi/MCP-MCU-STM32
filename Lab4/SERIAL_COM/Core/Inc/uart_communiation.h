/*
 * uart_communiation.h
 *
 *  Created on: Nov 2, 2023
 *      Author: PC
 */

#ifndef INC_UART_COMMUNIATION_H_
#define INC_UART_COMMUNIATION_H_

#include "main.h"
#include "software_timer.h"
#include "global.h"
#include "command_parser.h"

void uart_communiation_fsm(ADC_HandleTypeDef hadc1, UART_HandleTypeDef huart2);

#endif /* INC_UART_COMMUNIATION_H_ */
