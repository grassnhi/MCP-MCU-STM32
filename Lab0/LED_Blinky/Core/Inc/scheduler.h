/*
 * scheduler.h
 *
 *  Created on: Nov 1, 2023
 *      Author: PC
 */

#ifndef INC_SCHEDULER_H_
#define INC_SCHEDULER_H_

#include <stdint.h>

typedef struct{
	void (*pTask)(void);
	uint32_t 	Delay; //counter
	uint32_t 	Period; // counter
	uint8_t 	RunMe; // timer flag

	uint32_t	TaskID;
}sTasks;

#define SCH_MAX_TASKS	40

void SCH_Init(void);

void SCH_Add_Task(	void (*pFunction)(),
					uint32_t DELAY,
					uint32_t PERIOD		); // setTimer

void SCH_Update(void); // timerRun

void SCH_Dispatch_Tasks(void); // check flag

void SCH_Delete(uint32_t ID);

#endif /* INC_SCHEDULER_H_ */
