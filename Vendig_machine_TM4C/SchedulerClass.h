#ifndef SHEDULERCLASS_H_INCLUDED
#define SHEDULERCLASS_H_INCLUDED
#include "TaskClass.cpp"
#include "drivers.h"
#include <stdint.h>
#include "timer.h"
#ifndef _MAX_N_TASKS
#define _MAX_N_TASKS 16 // Maximum number of tasks
#endif



 class SchedulerClass
 {
 public:
  SchedulerClass();

 // ponteiro para uma lista de objetos tipo TaskClass
 TaskClass *ptrTaskList[_MAX_N_TASKS];

 // numero de Tarefas existentes
 unsigned char nTasks;

 // informa o numero de tarefas maximo
 unsigned char getMaxNTasks(void);

 // insere tarefa na lista
 int InsertTask (TaskClass *ptrTask);

 // Start data and timing. Need to be called right before loop execution.
 void Start (void);

 // store previous time value
 unsigned long time_prev;

 // sort Task list in descending priority order (highest priorityto lowest priority)
 void Sort (void);
 // verify if period is over. If yes, set as ready.
 bool Run(void);

 // get task with higher priority amoung ready tasks
 TaskClass* GetReadyTask(void);

 private:

 };




#endif // SHEDULERCLASS_H_INCLUDED
