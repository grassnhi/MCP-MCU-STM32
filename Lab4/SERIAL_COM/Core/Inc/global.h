/*
 * global.h
 *
 *  Created on: Nov 2, 2023
 *      Author: PC
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include <stdint.h>
#include "string.h"
#include "stdio.h"
#include "stdlib.h"
#include "math.h"

#define INIT 	0
#define END		1

#define RST 	10
#define ADC		11
#define OK 	    12

#define MAX_BUFFER_SIZE 30

extern int parser_status;
extern int uart_status;

extern uint8_t temp;
extern uint8_t buffer[MAX_BUFFER_SIZE];
extern uint8_t index_buffer;
extern uint8_t buffer_flag;

extern uint8_t command_flag;
extern uint8_t command[MAX_BUFFER_SIZE];
extern uint8_t command_index;

extern char str[50];

extern uint32_t ADC_value;


#endif /* INC_GLOBAL_H_ */
