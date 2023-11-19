/*
 * scheduler.c
 *
 *  Created on: Nov 2, 2023
 *      Author: PC
 */
#include <stdio.h>

#include "scheduler.h"

sTaskList taskList;
int32_t TaskID_arr[SCH_MAX_TASKS];
uint32_t curID = 0;
uint8_t dispatch = 0;

void SCH_Init(void) {
	sTasks* tmp = (sTasks*)taskList.head;
    while (tmp != NULL)
    {
        SCH_Delete_Task(tmp->TaskID);
    }
    for (int32_t i=0; i<SCH_MAX_TASKS; i++) {
        TaskID_arr[i] = -1;
    }
    LIST_Init(&taskList);
}

unsigned char SCH_Add_Task( void (*pFunction)(),
					uint32_t DELAY,
					uint32_t PERIOD) {

	uint32_t id = 0;

	node *cur = taskList.head;
	node *prev = NULL;

	while (TaskID_arr[curID] != -1 && id < SCH_MAX_TASKS)
    {
        curID = (curID+1)%SCH_MAX_TASKS;
        id++;
    }

	if(id == SCH_MAX_TASKS){
		return -1;
	}

	if (taskList.size == 0) {
    	LIST_Add_Task(&taskList, pFunction, DELAY, PERIOD, curID, prev, cur);
    } else {
    	uint32_t sumDelay = 0;
		uint32_t newDelay = 0;

    	while (DELAY >= sumDelay + cur->task.Delay && cur != NULL) {
    		sumDelay += cur->task.Delay;
    		prev = cur;
    		cur = (node *)cur->next;
    	}
    	newDelay = DELAY - sumDelay;
    	if (cur != NULL) {
    		cur->task.Delay -= newDelay;
    	}
    	LIST_Add_Task(&taskList, pFunction, newDelay, PERIOD, curID, prev, cur);
    }
	TaskID_arr[curID] = curID;
    return curID;
}

void SCH_Update() {
	node* tmp = taskList.head;
    if(tmp != NULL && dispatch == 0) {
        if(tmp->task.Delay != 0){
            tmp->task.Delay--;
        }else{
        	//dispatch = 1;
        }
    }
}

void SCH_Dispatch_Tasks(void) {
	node* tmp = taskList.head;
    if (tmp->task.Delay == 0 && tmp != NULL) {
        (*tmp->task.pTask)();
        if (tmp->task.Period == 0) {
            SCH_Delete_Task(tmp->task.TaskID);
            return;
        } else {
            void (*pTask) (void) = tmp->task.pTask;
//            uint32_t DELAY = tmp->task.Delay;
            uint32_t PERIOD = tmp->task.Period;
//            uint32_t TaskID = tmp->task.TaskID;
//            uint8_t RunMe = tmp->task.RunMe;
            SCH_Delete_Task(tmp->task.TaskID);
            SCH_Add_Task(pTask, PERIOD, PERIOD);
        }
        //dispatch = 0;
    }
}

unsigned char SCH_Delete_Task(uint32_t taskID) {
	if (TaskID_arr[taskID] == -1) {
        return -1;
    }
    LIST_Delete_Task(&taskList, taskID);
    TaskID_arr[taskID] = -1;
    return taskID;
}

// Example tasks
void task1() {
    printf("Task 1 executed.\n");
}

void task2() {
    printf("Task 2 executed.\n");
}

void task3() {
    printf("Task 3 executed.\n");
}

int main() {
    SCH_Init();

    // Adding tasks with different delays
    SCH_Add_Task(&task1, 3, 0);
    SCH_Add_Task(&task2, 1, 0);
    SCH_Add_Task(&task3, 2, 0);

    // Simulating scheduler update and dispatch
    for (int i = 0; i < 5; ++i) {
        printf("Scheduler tick %d\n", i);
        SCH_Update();
        SCH_Dispatch_Tasks();
    }

    return 0;
}