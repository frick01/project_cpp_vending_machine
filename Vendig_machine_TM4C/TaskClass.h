#ifndef TASKCLASS_H_INCLUDED
#define TASKCLASS_H_INCLUDED



 //typedef std::function<void(void)> timer_callback;
 typedef void(*ptr_task_function)(void);

 class TaskClass
 {
 public:

 // Constructor
 TaskClass(ptr_task_function f, unsigned long p);

 // indica se a tarefa está pronta para execução
 bool ready;

 // Período da tarefa. Se 0 indica uma tarefa aperiódica.
 unsigned long period;

 // Unidade de tempo decorrido desde a última execução
 unsigned long elapsed_time;

 // Tarefa a ser executada em cada período ou uma vez.
 ptr_task_function task_function;

 private:

 };

#endif // TASKCLASS_H_INCLUDED
