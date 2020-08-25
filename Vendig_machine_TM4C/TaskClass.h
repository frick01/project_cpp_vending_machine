#ifndef TASKCLASS_H_INCLUDED
#define TASKCLASS_H_INCLUDED



 //typedef std::function<void(void)> timer_callback;
 typedef void(*ptr_task_function)(void);

 class TaskClass
 {
 public:

 // Constructor
 TaskClass(ptr_task_function f, unsigned long p);

 // indica se a tarefa est� pronta para execu��o
 bool ready;

 // Per�odo da tarefa. Se 0 indica uma tarefa aperi�dica.
 unsigned long period;

 // Unidade de tempo decorrido desde a �ltima execu��o
 unsigned long elapsed_time;

 // Tarefa a ser executada em cada per�odo ou uma vez.
 ptr_task_function task_function;

 private:

 };

#endif // TASKCLASS_H_INCLUDED
