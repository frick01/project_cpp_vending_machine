
//#define TM4C
//#define WIN
//#ifdef WIN

/*#include <windows.h>
//#include "vendingMachinePC.cpp"
//#define FSM_vendingMachine vendingMachinePC
#endif //WIN

#ifdef TM4C
#include "vendingMachineCPP.cpp"
#define FSM_vendindMachine vendingMachine
#endif // TM4C
*/

#include <iostream>
#include <stdint.h>
#include <stdbool.h>
#include "drivers.h"

#include "vendingMachine.cpp"
#define FSM_vendingMachine vendingMachine
SchedulerClass Scheduler;
DispatcherClass Dispatcher;

void Task_1_code (void);
void Task_2_code (void);
void Task_3_code (void);


TaskClass Task1(Task_1_code, 20);
TaskClass Task2(Task_2_code, 40);
TaskClass Task3(Task_3_code, 60);


 FSM_vendingMachine Object;
int main()
{
   
SysCtlClockSet(SYSCTL_SYSDIV_16 | SYSCTL_USE_PLL| SYSCTL_OSC_MAIN | SYSCTL_XTAL_16MHZ);
Scheduler.InsertTask(&Task1);
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

void timeUpdate(void){ 
   
   Object.update();
   TimerIntClear(WTIMER2_BASE, TIMER_TIMB_TIMEOUT);
}
/*
void int_Handler(void){
   
   Scheduler.Timer_scheduler();
    TimerIntClear(WTIMER3_BASE, TIMER_TIMB_TIMEOUT);
}

*/

void Task_1_code(void)
 {
 Object.run();
   
 }

void Task_2_code (void)
 {
   
    Object.detector_moeda();
 }
 void Task_3_code (void)
 {

  Object.showlogs();
 }
