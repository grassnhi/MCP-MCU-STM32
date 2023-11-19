#ifndef INC_SCHED_H_
#define INC_SCHED_H_

#include <stdint.h>
#include <stdlib.h>

#define TIMER_CYCLE 	10
#define SCH_MAX_TASKS	40

typedef struct {
	void (* pTask)(void);

	// Delay (ticks) until the function will (next) be run
	uint32_t Delay;

	// Interval (ticks) between subsequent runs
	uint32_t Period;

	// Incremented (by scheduler) when task i s due to execute
	uint8_t RunMe;

	uint32_t TaskID;
} sTask;

void SCH_Init(void);
uint32_t SCH_Add_Task(void (* pFunction)(void), uint32_t DELAY, uint32_t PERIOD);
void SCH_Delete_Task(uint32_t taskID);
void SCH_Dispatch_Tasks(void);
void SCH_Update(void);


#endif /* INC_SCHED_H_ */
