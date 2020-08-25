#include <iostream>
using namespace std;


//include "Tasks.h"
#include "vendingMachine.h"
#define FSM vendingMachine
#include <stdlib.h>
FSM  Object;
SchedulerClass Scheduler;
DispatcherClass Dispatcher;

void Task_1_code (void);
void Task_2_code (void);
void Task_3_code (void);


TaskClass Task1(Task_1_code, 20);
TaskClass Task2(Task_2_code, 10);
TaskClass Task3(Task_3_code, 60);




int main()
{


//Scheduler.InsertTask(&Task1);
Scheduler.InsertTask(&Task2);
//Scheduler.InsertTask(&Task3);

Scheduler.Sort();

Scheduler.Start();

while(1){

    TaskClass* f;
    Scheduler.Run();
    f = Scheduler.GetReadyTask();
    if (f != NULL)
{
 // Exist a task to run
 Dispatcher.RunTask(f);
 }

}

}


void Task_1_code(void)
 {

    Object.menu();


 }

 void Task_2_code (void)
 {
cout<<"Tarefa2"<<endl;
    Object.detector_moeda();

 }

 void Task_3_code (void)
 {
cout<<"Tarefa3"<<endl;
   Object.showlogs();

 }

/*
int main()
{

Object.menu();

}*/




void timeUpdate(void){

   Object.update();

}




