/*
 * global.c
 *
 *  Created on: Nov 2, 2023
 *      Author: PC
 */

#include "global.h"

int parser_status = INIT;
int uart_status = RST;

uint8_t temp = 0;
uint8_t buffer[MAX_BUFFER_SIZE];
uint8_t index_buffer = 0;
uint8_t buffer_flag = 0;

uint8_t command[MAX_BUFFER_SIZE];
uint8_t command_index = 0;
uint8_t command_flag = 0;

char str[50];

uint32_t ADC_value = 0;
