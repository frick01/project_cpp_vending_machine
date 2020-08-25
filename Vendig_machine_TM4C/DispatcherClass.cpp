#include "DispatcherClass.h"
 // Constructor
 DispatcherClass :: DispatcherClass()
 {

 }

 void DispatcherClass :: RunTask (TaskClass* f)
 {
 if (f == NULL)
 return;

 f->task_function();
 f->ready = false;
 }
