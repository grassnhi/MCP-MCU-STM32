#include "scheduler.h"

#define	HEAD	0

sTask SCH_tasks_G[SCH_MAX_TASKS];
uint32_t Size = 0;

void SCH_Init(void) {
	for(uint32_t Index = 0; Index < SCH_MAX_TASKS; Index++) {
		SCH_tasks_G[Index].pTask = 0x0000;
		SCH_tasks_G[Index].Delay = 0;
		SCH_tasks_G[Index].Period = 0;
		SCH_tasks_G[Index].RunMe = 0;
	}
}

uint32_t SCH_Add_Task(void (* pFunction)(void), uint32_t DELAY, uint32_t PERIOD) {
	if(Size == SCH_MAX_TASKS - 1) return SCH_MAX_TASKS;

	uint8_t flag = 0;
	uint32_t Index = 0;
	if(TIMER_CYCLE > 0) {
		DELAY /= TIMER_CYCLE;
	}

	for(; Index < Size && flag == 0; Index++) {
		if(DELAY > SCH_tasks_G[Index].Delay) {
			DELAY -= SCH_tasks_G[Index].Delay;
		}
		else {
			flag = 1;
			SCH_tasks_G[Index].Delay -= DELAY;
			if(SCH_tasks_G[Index].Delay == 0) {
				SCH_tasks_G[Index].RunMe = 1;
			}
		}
	}

	if(flag == 1) {
		Index -= 1;
		for(uint32_t Temp = Size; Temp > Index; Temp--) {
			SCH_tasks_G[Temp] = SCH_tasks_G[Temp - 1];
			SCH_tasks_G[Temp].TaskID += 1;
		}
	}
	SCH_tasks_G[Index].pTask = pFunction;
	SCH_tasks_G[Index].Delay = DELAY;
	SCH_tasks_G[Index].Period = PERIOD;
	SCH_tasks_G[Index].RunMe = (DELAY == 0) ? 1 : 0;
	SCH_tasks_G[Index].TaskID = Index;

	Size += 1;

	return Index;
}

void SCH_Delete_Task(uint32_t TASK_INDEX) {
	if(SCH_tasks_G[TASK_INDEX].pTask == 0) return;

	SCH_tasks_G[TASK_INDEX + 1].Delay += SCH_tasks_G[TASK_INDEX].Delay;

	for(uint32_t Temp = TASK_INDEX; Temp < Size - 1; Temp++) {
		SCH_tasks_G[Temp] = SCH_tasks_G[Temp + 1];
		SCH_tasks_G[Temp].TaskID -= 1;
	}

	Size -= 1;
}

void SCH_Dispatch_Tasks(void) {
	if(SCH_tasks_G[HEAD].RunMe == 1) {
		(*SCH_tasks_G[HEAD].pTask)();

		sTask temp = SCH_tasks_G[HEAD];

		SCH_Delete_Task(HEAD);

		if(temp.Period > 0) {
			SCH_Add_Task(temp.pTask, temp.Period, temp.Period);
		}
	}
}

void SCH_Update(void) {
	if(SCH_tasks_G[HEAD].Delay > 0) SCH_tasks_G[HEAD].Delay--;

	if(SCH_tasks_G[HEAD].Delay == 0) {
		SCH_tasks_G[HEAD].RunMe = 1;
	}
}