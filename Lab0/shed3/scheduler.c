#include "scheduler.h"
#include <stdlib.h>
#include <stdio.h>

int TIME_CYCLE = 10;

sTaskList taskList;
int32_t TaskID_arr[SCH_MAX_TASKS];
uint32_t curID = 0;
uint8_t dispatch = 0;

UART_HandleTypeDef huart2;

void SCH_Init(void) {
    for (int32_t i = 0; i < SCH_MAX_TASKS; i++) {
        TaskID_arr[i] = -1;
    }
    taskList.head = NULL;
    taskList.tail = NULL;
    taskList.size = 0;
}

unsigned char SCH_Add_Task(void (*pFunction)(), uint32_t DELAY, uint32_t PERIOD) {
    if (taskList.size >= SCH_MAX_TASKS) {
        return 0; // Scheduler full
    }

    sTasks newTask;
    newTask.pTask = pFunction;
    newTask.Delay = DELAY;
    newTask.Period = PERIOD;
    newTask.RunMe = 0;
    newTask.TaskID = curID;

    TaskID_arr[curID] = 1; // Mark task ID as used
    curID++;

    node* newNode = (node*)malloc(sizeof(node));
    if (newNode == NULL) {
        return 0; // Memory allocation failed
    }

    newNode->task = newTask;
    newNode->nextNode = NULL;

    // If the list is empty or the new task has smaller delay than the head task
    if (taskList.head == NULL || DELAY < taskList.head->task.Delay) {
        newNode->nextNode = taskList.head;
        taskList.head = newNode;
    } else {
        node* current = taskList.head;

        while (current->nextNode != NULL && current->nextNode->task.Delay <= DELAY) {
            current = current->nextNode;
        }

        newNode->nextNode = current->nextNode;
        current->nextNode = newNode;
    }

    taskList.size++;
    displayUART(newTask.TaskID, DELAY, huart2);
    return 1; // Task added successfully
}


void SCH_Update(void) {
    node* tmp = taskList.head;
    while (tmp != NULL) {
        if (tmp->task.Delay >= 0) {
            tmp->task.Delay--;
        } else {
            tmp->task.RunMe = 1;
        }
        tmp = tmp->nextNode;
    }
//    node* tmp = taskList.head;
//	if(tmp != NULL && dispatch == 0) {
//		if(tmp->task.Delay != 0){
//			tmp->task.Delay--;
//		}else{
//			tmp->task.RunMe = 1;
//		}
//	}
//	displayUART(tmp->task.TaskID, tmp->task.Delay, huart2);
}

void SCH_Dispatch_Tasks(void) {
//    node* tmp = taskList.head;
//    while (tmp != NULL) {
//        if (tmp->task.RunMe == 1) {
//            tmp->task.RunMe = 0;
//            (*(tmp->task.pTask))();
//            SCH_Add_Task(tmp->task.pTask, tmp->task.Period, tmp->task.Period);
//            SCH_Delete_Task(tmp->task.TaskID);
//        }
//        tmp = tmp->nextNode;
//    }
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
		tmp->task.RunMe = 0;
	}
}


unsigned char SCH_Delete_Task(uint32_t taskID) {
    if (taskList.size == 0) {
        return 0; // No tasks in the scheduler
    }

    if (taskList.size <= 0) {
            return -1;
        } else if (taskList.size == 1) {
        	node* tmp = taskList.head;
        	uint32_t TaskID = tmp->task.TaskID;
            taskList.head = NULL;
            taskList.tail = NULL;
            taskList.size--;
            free(tmp);
            return TaskID;
        } else {
        	node* tmp = taskList.head;
        	uint32_t TaskID = tmp->task.TaskID;
        	taskList.head = (taskList.head->nextNode);
        	taskList.size--;
        	free(tmp);
        	return TaskID;
        }
    TaskID_arr[taskID] = -1;
        return taskID;
}
