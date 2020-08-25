#ifndef TASKS_H_INCLUDED
#define TASKS_H_INCLUDED

#include "vendingMachine.h"
#define FSM_vendingMachine vendingMachine


FSM_vendingMachine Object;




void Task_1_code (void);
void Task_2_code (void);
void Task_3_code (void);


void Task_1_code(void)
 {  cout<<"Tarefa1"<<endl;

    Object.run();
 }

 void Task_2_code (void)
 {
cout<<"Tarefa2"<<endl;
    Object.relogio_system();
 }

 void Task_3_code (void)
 {
cout<<"Tarefa3"<<endl;
   Object.update();

 }

void timeUpdate(void){

   Object.update();
}
#endif // TASKS_H_INCLUDED

