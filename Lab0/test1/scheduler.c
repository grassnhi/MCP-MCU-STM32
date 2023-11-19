#include "scheduler.h"
#include <stdlib.h>
#include <stdio.h>

sTaskList taskList;
int32_t TaskID_arr[SCH_MAX_TASKS];
uint32_t curID = 0;
uint8_t dispatch = 0;

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
    return 1; // Task added successfully
}


void SCH_Update(void) {
    node* tmp = taskList.head;
    while (tmp != NULL) {
        if (tmp->task.Delay > 0) {
            tmp->task.Delay--;
        } else {
            tmp->task.RunMe = 1;
        }
        tmp = tmp->nextNode;
    }
}

void SCH_Dispatch_Tasks(void) {
    node* tmp = taskList.head;
    while (tmp != NULL) {
        if (tmp->task.RunMe == 1) {
            tmp->task.RunMe = 0;
            (*(tmp->task.pTask))();
            SCH_Add_Task(tmp->task.pTask, tmp->task.Period, tmp->task.Period);
            SCH_Delete_Task(tmp->task.TaskID);
        }
        tmp = tmp->nextNode;
    }
}


unsigned char SCH_Delete_Task(uint32_t taskID) {
    if (taskList.size == 0) {
        return 0; // No tasks in the scheduler
    }

    node* current = taskList.head;
    node* prev = NULL;

    while (current != NULL) {
        if (current->task.TaskID == taskID) {
            if (prev == NULL) {
                taskList.head = current->nextNode;
            } else {
                prev->nextNode = current->nextNode;
            }

            if (current->nextNode == NULL) {
                taskList.tail = prev;
            }

            TaskID_arr[taskID] = -1; // Mark TaskID as available
            free(current);
            taskList.size--;
            return 1; // Task deleted successfully
        }
        prev = current;
        current = current->nextNode;
    }
    return 0; // Task not found
}

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
    SCH_Add_Task(&task1, 3, 1);
    SCH_Add_Task(&task2, 1, 3);
    SCH_Add_Task(&task3, 2, 2);

    // Simulating scheduler update and dispatch
    for (int i = 0; i < 10; ++i) {
        printf("Scheduler tick %d\n", i);
        SCH_Update();
        SCH_Dispatch_Tasks();
    }

    return 0;
}