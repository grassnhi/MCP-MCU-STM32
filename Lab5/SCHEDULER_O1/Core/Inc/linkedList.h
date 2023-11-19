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

void LIST_Init(sTaskList* taskList);

uint32_t LIST_Add_Task(sTaskList* taskList, void (*pFunction)(), uint32_t DELAY, uint32_t PERIOD, uint32_t TaskID, node* prev, node* cur);

uint32_t LIST_Delete_Task(sTaskList* taskList, uint32_t TaskID);

uint32_t LIST_Delete_Head_Task(sTaskList* taskList);

#endif /* INC_LINKEDLIST_H_ */
