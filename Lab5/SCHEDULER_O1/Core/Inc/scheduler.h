/*
 * scheduler.h
 *
 *  Created on: Nov 2, 2023
 *      Author: PC
 */

#ifndef INC_SCHEDULER_H_
#define INC_SCHEDULER_H_

#include "linkedList.h"

extern int TIME_CYCLE;

#define SCH_MAX_TASKS	40

void SCH_Init(void);

uint32_t SCH_Add_Task ( void (*pFunction)() ,
					uint32_t DELAY,
					uint32_t PERIOD);

void SCH_Update_Task(void);

void SCH_Dispatch_Tasks(void);

uint32_t SCH_Delete_Task(uint32_t taskID);


#endif /* INC_SCHEDULER_H_ */
