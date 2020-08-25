#ifndef TASKCLASS_H_INCLUDED
#define TASKCLASS_H_INCLUDED



 //typedef std::function<void(void)> timer_callback;
 typedef void(*ptr_task_function)(void);

 class TaskClass
 {
 public:

 // Constructor
 TaskClass(ptr_task_function f, unsigned long p);

 // indicates if task is ready to run
 bool ready;

 // Task period. If 0 indicates an aperiodic task.
 unsigned long period;

 // Elapsed time unit since last execution.
 unsigned long elapsed_time;

 // Task to be executed in each period ou once.
 ptr_task_function task_function;

 private:

 };

#endif // TASKCLASS_H_INCLUDED
