#ifndef DISPATCHERCLASS_H_INCLUDED
#define DISPATCHERCLASS_H_INCLUDED


#define NULL 0

 #include "TaskClass.h"

 class DispatcherClass
 {
 public:
 // constructor
 DispatcherClass();

 // execute task:
 void RunTask(TaskClass* f);

 private:

 };


#endif // DISPATCHERCLASS_H_INCLUDED
