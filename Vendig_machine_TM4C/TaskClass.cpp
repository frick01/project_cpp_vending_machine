#include "TaskClass.h"

 // Task Constructor
TaskClass :: TaskClass(ptr_task_function f, unsigned long p)
 {
 ready = false;

 task_function = f;

 elapsed_time = 0;

 period = p;
 }
