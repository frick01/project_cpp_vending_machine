#ifndef VENDINGMACHINE_H_INCLUDED
#define VENDINGMACHINE_H_INCLUDED
/*
 * vendingMachine.h
 *
 *  Created on: 17 de out de 2019
 *      @Author: Frick
 *      @version 1.0
 * Este software está implementado os métodos responsáveis pelo controle FSM
 * e as funcionalidade básica da Máquina de venda de bebidas. A classe vendindMachine
 * está hierarquicamente ligada á classe interface.
 *
 *
 */


#include "drivers.h"
#include "Interface.h"
#include "List.cpp"
#include "ClockCalendar.cpp"
#include "SchedulerClass.cpp"
#include "DispatcherClass.cpp"
#include <string>
#include <time.h>
#include <iomanip>
#define NULL 0


class vendingMachine  :public Interface{
    ClockCalendar t, b;
    
    List<char> lista1, lista2;
    List<int> logs;
    int totalValue, state,sales,hsales,task;
    int etirps,meet;
    


public:
    vendingMachine(void);
    ~vendingMachine();
    void sumnewValue(int newValue);
    void dev(void);
    void advanceState(char enter);
    void verify(void);
    void choise(void);
    void print(char *menssagem, int newValue);
    char * input(void);
    char dayPeriod(void);
    void update(void);
    void showlogs(void);
    void run(void);
      void menu(void);
    void entradas(void);
    void relogio_system(void);
    void detector_moeda(void);
   
    

};


#endif // VENDINGMACHINE_H_INCLUDED
