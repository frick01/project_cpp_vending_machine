 /* Interface.h
 *
 *  Created on: 17 de out de 2019
 *      Author: Frick
 */
#ifndef INTERFACE_H_INCLUDED
#define INTERFACE_H_INCLUDED
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

class Interface{    /*Classe abstrata*/

public:
    virtual void print(char*, int) = 0;

    virtual char * input(void) = 0;
  
    //virtual void run(void) = 0;
   // virtual void menu(void)=0;
     //virtual void entradas(void)=0;
      //virtual void detector_moeda(void)=0;
};



#endif // INTERFACE_H_INCLUDED
