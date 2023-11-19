/*
 * scheduler.c
 *
 *  Created on: Nov 2, 2023
 *      Author: PC
 */

#ifndef SRC_SCHEDULER_C_
#define SRC_SCHEDULER_C_

#include "scheduler.h"

int TIME_CYCLE = 10;

sTasks SCH_tasks_G[SCH_MAX_TASKS];
uint8_t current_index_task = 0;

sTaskList taskList;
int32_t TaskID_arr[SCH_MAX_TASKS];
uint32_t curID = 0;
uint8_t dispatch = 0;

void SCH_Init(void) {
	sTasks* tmp = taskList.head;
    while (tmp != NULL)
    {
        SCH_Delete_Task(tmp->TaskID);
    }
    for (int32_t i=0; i<SCH_MAX_TASKS; i++) {
        TaskID_arr[i] = -1;
    }
    LIST_Init(&taskList);
}

void SCH_Add_Task ( void (*pFunction)() ,
					uint32_t DELAY,
					uint32_t PERIOD) {

	uint32_t id = 0;

	node *cur = taskList.head;
	node *prev = NULL;
	node *last = NULL;

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
    		cur = cur->next;
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

void SCH_Update_Task() {
	node* tmp = taskList.head;
    if(tmp != NULL && dispatch == 0) {
        if(tmp->task.Delay != 0){
            tmp->task.Delay--;
        }else{
        	dispatch = 1;
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
            uint32_t DELAY = tmp->task.Delay;
            uint32_t PERIOD = tmp->task.Period;
            uint32_t TaskID = tmp->task.TaskID;
            uint8_t RunMe = tmp->task.RunMe;
            SCH_Delete_Task(tmp->task.TaskID);
            SCH_Add_Task(pTask, PERIOD, PERIOD);
        }
        dispatch = 0;
    }
}

uint32_t SCH_Delete_Task(uint32_t taskID) {
	if (TaskID_arr[taskID] == -1) {
        return -1;
    }
    LIST_Delete_Task(&taskList, taskID);
    TaskID_arr[taskID] = -1;
    return taskID;
}

void LIST_Init(sTaskList* taskList) {
    taskList->head = NULL;
    taskList->tail = NULL;
    taskList->size = 0;
}

uint32_t LIST_Add_Task(sTaskList* taskList, void (*pFunction)(), uint32_t DELAY, uint32_t PERIOD, uint32_t TaskID, node* prev, node* cur){
	node* task = (node*)malloc(sizeof(node));
	if (task == NULL) {
		return -1; // Check if memory allocation fails
	}
	task->task.pTask = pFunction;
	task->task.Delay = DELAY/TIME_CYCLE;
	task->task.Period = PERIOD/TIME_CYCLE;
	task->task.TaskID = TaskID;
	task->task.RunMe = 0;
	task->next = NULL;
	if(taskList->size == 0){
		taskList->head = task;
		taskList->tail = task;
		taskList->size = 1;
	}else if(prev == NULL){ // add head
		task->next = taskList->head;
		taskList->head = task;
		taskList->size++;
	}else if (cur == NULL){ // add tail
		taskList->tail->next = task;
		taskList->tail = task;
		taskList->size++;
		return TaskID;
	}else{ // add mid
		prev->next = task;
		task->next = cur;
		taskList->size++;
	}
	return TaskID;
}

uint32_t LIST_Delete_Task(sTaskList* taskList, uint32_t TaskID){
	if (taskList->size <= 0) {
        return -1;
    }
	
	node* tmp = taskList->head;
    node* prev = NULL;
    
    if (taskList->size == 1) {
        taskList->head = NULL;
        taskList->tail = NULL;
        taskList->size--;
        free(tmp);
        return TaskID;
    }

	while (tmp->task.TaskID != TaskID || tmp != NULL) {
    	prev = tmp;
    	tmp = tmp->next;
    }

	if (tmp == NULL) {
    	return -1;
    }else if(prev == NULL){
    	taskList->head = taskList->head->next;
    	taskList->size--;
    	free(tmp);
    }else if(tmp->next == NULL){
    	prev->next = NULL;
    	taskList->tail = prev;
    	taskList->size--;
    	free(tmp);
    }else{
    	prev->next = tmp->next;
    	tmp->next = NULL;
    	free(tmp);
    	taskList->size--;
    }
    return TaskID;
}

#endif /* SRC_SCHEDULER_C_ */
