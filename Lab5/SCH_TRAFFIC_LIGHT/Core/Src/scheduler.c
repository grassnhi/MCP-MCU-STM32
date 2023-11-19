#include "scheduler.h"

sTask SCH_tasks_G[SCH_MAX_TASKS];
uint32_t size = 0;

void SCH_Init(void) {
	for(uint32_t index = 0; index < SCH_MAX_TASKS; index++) {
		SCH_tasks_G[index].pTask = 0x0000;
		SCH_tasks_G[index].Delay = 0;
		SCH_tasks_G[index].Period = 0;
		SCH_tasks_G[index].RunMe = 0;
	}
}

uint32_t SCH_Add_Task(void (* pFunction)(void), uint32_t DELAY, uint32_t PERIOD) {
	if(size == SCH_MAX_TASKS - 1) return SCH_MAX_TASKS;

	uint8_t flag = 0;
	uint32_t index = 0;
	if(TIMER_CYCLE > 0) {
		DELAY /= TIMER_CYCLE;
	}

	for(index = 0; index < size && flag == 0; index++) {
		if(DELAY > SCH_tasks_G[index].Delay) {
			DELAY -= SCH_tasks_G[index].Delay;
		}
		else {
			flag = 1;
			SCH_tasks_G[index].Delay -= DELAY;
			if(SCH_tasks_G[index].Delay == 0) {
				SCH_tasks_G[index].RunMe = 1;
			}
		}
	}

	if(flag == 1) {
		index -= 1;
		for(uint32_t temp = size; temp > index; temp--) {
			SCH_tasks_G[temp] = SCH_tasks_G[temp - 1];
			SCH_tasks_G[temp].TaskID += 1;
		}
	}
	SCH_tasks_G[index].pTask = pFunction;
	SCH_tasks_G[index].Delay = DELAY;
	SCH_tasks_G[index].Period = PERIOD;
	SCH_tasks_G[index].RunMe = (DELAY == 0) ? 1 : 0;
	SCH_tasks_G[index].TaskID = index;

	size += 1;

	return index;
}

void SCH_Delete_Task(uint32_t taskID) {
	if(SCH_tasks_G[taskID].pTask == 0) return;

	SCH_tasks_G[taskID + 1].Delay += SCH_tasks_G[taskID].Delay;

	for(uint32_t temp = taskID; temp < size - 1; temp++) {
		SCH_tasks_G[temp] = SCH_tasks_G[temp + 1];
		SCH_tasks_G[temp].TaskID -= 1;
	}

	size -= 1;
}

void SCH_Dispatch_Tasks(void) {
	if(SCH_tasks_G[0].RunMe == 1) {
		(*SCH_tasks_G[0].pTask)();

		sTask temp = SCH_tasks_G[0];

		SCH_Delete_Task(0);

		if(temp.Period > 0) {
			SCH_Add_Task(temp.pTask, temp.Period, temp.Period);
		}
	}
}

void SCH_Update(void) {
	if(SCH_tasks_G[0].Delay > 0) SCH_tasks_G[0].Delay--;

	if(SCH_tasks_G[0].Delay == 0) {
		SCH_tasks_G[0].RunMe = 1;
	}
}
