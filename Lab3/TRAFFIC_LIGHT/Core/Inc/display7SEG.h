/*
 * display7SEG.h
 *
 *  Created on: Oct 22, 2023
 *      Author: PC
 */

#ifndef INC_DISPLAY7SEG_H_
#define INC_DISPLAY7SEG_H_

#include "main.h"
#include "global.h"

extern int index_led;
extern int counter1, counter2;

void display7SEG1(int num);
void display7SEG2(int num);
void update7SEG(int index);

void updateBufferMode1();
void updateBufferMode2();
void updateBufferMode3();
void updateBufferMode4();

#endif /* INC_DISPLAY7SEG_H_ */
