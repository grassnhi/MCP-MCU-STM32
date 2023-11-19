#ifndef SCHEDULER_H_
#define SCHEDULER_H_

#include <stdint.h>
#include "uart.h"

#define SCH_MAX_TASKS 10

extern int TIME_CYCLE ;

typedef struct {
    void (*pTask)(void);
    uint32_t Delay;
    uint32_t Period;
    uint8_t RunMe;
    uint32_t TaskID;
} sTasks;

typedef struct Node {
    sTasks task;
    struct Node* nextNode;
} node;

typedef struct {
    node* head;
    node* tail;
    uint32_t size;
} sTaskList;

void SCH_Init(void);
unsigned char SCH_Add_Task(void (*pFunction)(), uint32_t DELAY, uint32_t PERIOD);
void SCH_Update(void);
void SCH_Dispatch_Tasks(void);
unsigned char SCH_Delete_Task(uint32_t taskID);

#endif /* SCHEDULER_H_ */
