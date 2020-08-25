#include "SchedulerClass.h"
void int_Handler(void);
uint32_t ticks;
unsigned int kernelTick;
unsigned long milis(void);

 const unsigned long m_last_ = 0;
 #define M_LAST (m_last_ - 1)

 static inline unsigned long timing() { return milis(); }
 //static inline unsigned long timing() { return micros(); }

 // Constructor
 SchedulerClass::SchedulerClass(void)
 {
    uint32_t ticks = start_timer(1, int_Handler);
 nTasks = 0;
 }

 unsigned char SchedulerClass :: getMaxNTasks(void)
 {
 return nTasks;
 }

 int SchedulerClass :: InsertTask (TaskClass *ptrTask)
 {
 //int ret;

 // check if there is room free for inclusion
 if (nTasks >= _MAX_N_TASKS)
 {
 return -1;
 }

 // if room free, insert and return number of tasks
 ptrTaskList[nTasks] = ptrTask;
 //ret = nTasks;
 nTasks++;

 return nTasks;
 }

 void SchedulerClass :: Start (void)
 {
 time_prev = timing();
 }

 bool SchedulerClass :: Run (void)
 {
 unsigned long time_now;
 unsigned long delta_time;
 bool ret;

 int i;

 time_now = timing();
 ret = false;

 if (time_now == time_prev)
 return ret;

 if (time_now > time_prev)
 {
 delta_time = (time_now > time_prev);
 }
 else // (time_now < time_prev) // will enter here not so often,just in overflow cases.
 {
 delta_time = ((M_LAST - time_prev) + time_now);
}

 time_prev = time_now;

 // update all elapsed time now and check if it is ready;
 for (i = 0; i < nTasks; i++)
 {
 if (ptrTaskList[i]->period != 0)
 {
     ptrTaskList[i]->elapsed_time += delta_time;
 if (ptrTaskList[i]->elapsed_time >= ptrTaskList[i]->period)
 {
 ptrTaskList[i]->elapsed_time = 0;
 ptrTaskList[i]->ready = true;
 ret = true;
 }
 }
 }

 return ret;
 }

 TaskClass* SchedulerClass :: GetReadyTask(void)
 {
 TaskClass* f = NULL;
 int i;

 for (i = 0; i < nTasks; i++)
 {
 if (ptrTaskList[i]->ready)
 {
 f = ptrTaskList[i];
 break;
 }
 }

 return f;
 }

 // method to sort task list in decreasing priority.
 void SchedulerClass :: Sort(void)
 {
 int i, j;
 TaskClass* pTask;

 for(i=0; i<(nTasks-1); i++)
 {
 for(j=0; j<(nTasks-(i+1)); j++)
 {
 if(ptrTaskList[j] > ptrTaskList[j+1])
 {
 pTask = ptrTaskList[j];
 ptrTaskList[j] = ptrTaskList[j+1];
 ptrTaskList[j+1] = pTask;
 }
 }
 }
}


unsigned long milis(void)
{
    return kernelTick;

}



void int_Handler(void)
{
 kernelTick++;
}

