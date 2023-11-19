/*
 * linkedList.h
 *
 *  Created on: Nov 18, 2023
 *      Author: PC
 */

#ifndef INC_LINKEDLIST_H_
#define INC_LINKEDLIST_H_

#include <stdint.h>
#include <stdlib.h>

typedef struct{
	void (*pTask)(void);
	uint32_t 	Delay;
	uint32_t 	Period;
	uint8_t 	RunMe;

	uint32_t 	TaskID;
}sTasks;


typedef struct
{
    sTasks task;
    struct node* next;
} node;

typedef struct
{
	node* head;
	node* tail;
    uint32_t size;
} sTaskList;

int TIME_CYCLE = 10;

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
		task->next = (struct node *)taskList->head;
		taskList->head = task;
		taskList->size++;
	}else if (cur == NULL){ // add tail
		taskList->tail->next = (struct node *)task;
		taskList->tail = task;
		taskList->size++;
		return TaskID;
	}else{ // add mid
		prev->next = (struct node *)task;
		task->next = (struct node*)cur;
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
    	tmp = (node *)tmp->next;
    }

	if (tmp == NULL) {
    	return -1;
    }else if(prev == NULL){
    	taskList->head = (node *)(taskList->head->next);
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

uint32_t LIST_Delete_Head_Task(sTaskList* taskList) {
    if (taskList->size <= 0) {
        return -1;
    } else if (taskList->size == 1) {
    	node* tmp = taskList->head;
    	uint32_t TaskID = tmp->task.TaskID;
        taskList->head = NULL;
        taskList->tail = NULL;
        taskList->size--;
        free(tmp);
        return TaskID;
    } else {
    	node* tmp = taskList->head;
    	uint32_t TaskID = tmp->task.TaskID;
    	taskList->head = (node *)(taskList->head->next);
    	taskList->size--;
    	free(tmp);
    	return TaskID;
    }
}


#endif /* INC_LINKEDLIST_H_ */
