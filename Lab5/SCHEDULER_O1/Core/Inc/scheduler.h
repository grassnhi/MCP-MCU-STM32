/*
 * scheduler.h
 *
 *  Created on: Nov 2, 2023
 *      Author: PC
 */

#ifndef INC_SCHEDULER_H_
#define INC_SCHEDULER_H_

#include "linkedList.h"
#include <stdint.h>

extern int TIME_CYCLE;

typedef struct {
    // Pointer to the task (must be a 'void (void)' function)
	void ( * pTask)(void);
	// Delay (ticks) until the function will (next) be run
	uint32_t Delay;
	// Interval (ticks) between subsequent runs.
	uint32_t Period;
	// Incremented (by scheduler) when task is due to execute
	uint8_t RunMe;
	//This is a hint to solve the question below.
	uint32_t TaskID;
} sTask;

// MUST BE ADJUSTED FOR EACH NEW PROJECT
#define SCH_MAX_TASKS 										40
#define	NO_TASK_ID											0

sTask SCH_tasks_G[SCH_MAX_TASKS];

#define ERROR_SCH_TOO_MANY_TASK								1
#define ERROR_SCH_WAITING_FOR_SLAVE_TO_ACK					2
#define ERROR_SCH_WAITING_FOR_START_COMMAND_FROM_MASTER		3
#define ERROR_SCH_ONE_OR_MORE_SLAVES_DID_NOT_START			4
#define ERROR_SCH_LOST_SLAVE								5
#define ERROR_SCH_CAN_BUS_ERROR								6
#define ERROR_I2C_WRITE_BYTE_AT24C64						7
#define ERROR_SCH_TOO_MANY_TASKS							8
#define RETURN_ERROR										(unsigned)"ERROR"
#define RETURN_NORMAL										(unsigned)"NORMAL"
#define ERROR_SCH_CANNOT_DELETE_TASK						(unsigned)"CANNOT DELETE TASK"

void SCH_Init(void);

unsigned char SCH_Add_Task( void (*pFunction)() , uint32_t DELAY, uint32_t PERIOD);

void SCH_Update(void);

void SCH_Dispatch_Tasks(void);

unsigned char SCH_Delete_Task(uint32_t taskID);

void SCH_Report_Status();

void SCH_Go_To_Sleep();

void Timer_init();

#endif /* INC_SCHEDULER_H_ */
