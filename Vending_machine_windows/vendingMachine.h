#ifndef VENDINGMACHINE_H_INCLUDED
#define VENDINGMACHINE_H_INCLUDED


/*
 * vendingMachine.h
 *
 *  Created on: 17 de out de 2019
 *      Author: Frick
 */

#include "Interface.h"
#include "List.cpp"
#include "ClockCalendar.h"
#include "SchedulerClass.h"
#include "DispatcherClass.h"

class vendingMachine  :public Interface{
    ClockCalendar t;
    List<char> lista1, lista2;
    List<int> logs;
    int totalValue, state,sales,hsales;
    int *getDH;
    int *valor;

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
    void showlogs(void);
    void update(void);
    void run(void);
    string toString();
    /**/
    void menu(void);
    void entradas(void);
    void relogio_system(void);
    void detector_moeda(void);

//    void UserClockCalendar(void);

};




#endif // VENDINGMACHINE_H_INCLUDED
