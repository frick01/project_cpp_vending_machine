
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
#include <stdio.h>

#include <stdlib.h>
#include "vendingMachine.h"
//#include "ClockCalendar.h"
#include <time.h>
#include <iomanip>
#define NULL 0
#include "timer.h"
#include "SchedulerClass.h"
#include "DispatcherClass.h"
void timeUpdate(void);



/******************************************************************************************************
 *                                         CONSTRUTORES E DESTRUTORES                                 *
 *                                                                                                    *
 * variavel totalValue detém o valor montante                                                         *
 *                                                                                                    *
 * ***************************************************************************************************/

vendingMachine::vendingMachine() {


    totalValue=0;
    state=0;
    sales=0;
    hsales=0;

    start_timer(1000, &timeUpdate);
   // kernelStatus_t kernel_task_waiting;

}


vendingMachine::~vendingMachine() {
stop_timer();
}


void vendingMachine::sumnewValue(int newValue){
    totalValue = totalValue + newValue;

};

/****************************************************************************************************
                                MÉTODO PARA A DEVOCAO DE DINHEIRO                                   *
*****************************************************************************************************/

void vendingMachine::dev(void){

    print("Devolvendo:R$ ", (totalValue/100));//Reais
    print(",", (totalValue%100)); //Centavos
    print("NULL", NULL);
    totalValue = 0; state = 0;

};

/****************************************************************************************************
*                                  MÉTODO DE CONTROLE DA FSM                                        *
****************************************************************************************************/
void vendingMachine::advanceState(char coins){
    switch (coins){
    case '1':                                           // estado 1 montate = 25 centavos
        state++; sumnewValue(25);                       // avanca estado 2
        verify();
        break;
    case '2':                                            // estado 2 montante = 50 centavos
        for(int i=0;i<=1;i++){state++; sumnewValue(25);} // avança estado 3
        verify();
        break;
    case '3':                                            // estado 3 montante  = 75 centavos
        for(int i=0;i<=3;i++){state++; sumnewValue(25);} // avança estado 4 -> 100 centavos
        verify();
        break;
    case '6':
        dev();
   case '7':
        showlogs();
          print("MOSTRADO LOGS", NULL);
          break;                        // devolve
    default:
        print("Valor incorreto! Insira o total de  R$ 1,50...", NULL);
        print("NULL", NULL);
        break;
    }
};

/*****************************************************************************************************
*                                  MÉTODO DE VERIFICAÇAO DO VALOR PAGO                               *
* Funcionalidade: Faz a verificacao se o valor colocado na maquina é correspondente                  *
*ao preço da bebida.Quando o valor ultrapassa R1,50, é subtraído do montante                         *                            *
/****************************************************************************************************/
void vendingMachine::verify(void){
    int i;
       cout<<"task verify"<<endl;
    if(state > 6){                 // Gera troco
        i = (state-6)*25;
        print("Inserido R$ ", (i/100));
        print(",", (i%100));
        print("Voce inseriu a mais que o suficiente! O valor está sendo devolvido", NULL);
        print("NULL", NULL);
        sumnewValue(-i); state = 6; // Subtrai o troco do montante
        }

    if(state < 6){
        print("Insira  R$ 1,50...", NULL);
        print("NULL", NULL);
        }

    else {
        print("OK! Pode escolher seu refri", NULL);
        print("NULL", NULL);
        choise();
        }
};

/****************************************************************************************************
*                          METODO PARA ESCOLHER O REFRIGERANTE                                      *
*Funcionalidade: Escolhe uma das opçoes, e faz o desconto do pagamento no montante inserido para    *
retornar ao estado 0                                                                                *
*****************************************************************************************************/
void vendingMachine::choise(void){
    char coins, *ent;
    ent =input();
    coins = ent[0];
    switch (coins){
    case '4':                                             //  Refrigerante Meet
        print("Voce escolheu MEET!", NULL);
        print("NULL", NULL);
        for(int i=0;i<=5;i++)
        {state--; sumnewValue(-25);}          // Subtrai 1,50 e retorna ao estado 0
        sales++;
        logs.insertAfterLast(sales,t.getClockCalendar());
        verify();
        break;
    case '5':                                          //  Refrigerante Etirps
        print("Voce escolheu ETIRPS!", NULL);
        print("NULL", NULL);
        for(int i=0;i<=5;i++)
        {state--; sumnewValue(-25);}          // Subtrai 1,50 e retorna ao estado 0
        sales++;
        logs.insertAfterLast(sales, t.getClockCalendar());
        verify();
        break;

    default:
        advanceState(coins);
        break;
    }
};

/**************************************************************************************************
*                                    MÉTODO PARA FAZER A INTERFACE DAS MENSAGENS                  *
* Funcionalidade: Funçao virtual que faz a interface das mensagens printadas na                   *
 classe  vendingMachine                                                                           *
**************************************************************************************************/

void vendingMachine::print(char *msg, int newValue){

  if((msg == "NULL") && (newValue == NULL)) {cout << endl;} // Pula uma linha

    else{

             if(msg != "NULL"){cout<<msg;}
            if(newValue >= 0){cout<<newValue;}

        }
};




/****************************************************************************************************
*                                   MÉTODO PARA FAZET A INTERFACE DOS DADOS DE ENTRADA              *
* Funcionalidade: Função vitual que faz a interface dos dados de entrada na classe vendingMachine   *
****************************************************************************************************/
char * vendingMachine::input(void){
    char rDeiveData[20], *rD;
    cin >> rDeiveData;
    rD = rDeiveData;
    return rD;
};

/******************************************************************************************************
                             logs
******************************************************************************************************/



// **************************************************************************************************
//                      Função para exibição dos logs
// **************************************************************************************************
void vendingMachine::showlogs(void){
    int total;
    int *msgm;
    if (sales == 0)print("Nenguma venda ainda",NULL);
    else{
    total = 150 * sales;                // Realisa a contagem do dinheiro arrecadado
    print("Cash: R$ ", (total/100)); // Imprime o dinheiro arrecadado
    print(",", (total%100));          // Imprime os centavos
    print("NULL", NULL);

    for(int i=0; i<logs.getSize(); i++){  // imprime todos o Nodes da lista "Documentação"
        print("Hora de venda: ", NULL);
        msgm = logs.readFirstMensagem();

        print(" ",msgm[0]);print("/",msgm[1]);print("/",msgm[2]);
        print(" - ",msgm[3]);print(":",msgm[4]);print(":",msgm[5]);

        print("NULL", NULL);print("NULL", NULL);
        logs.insertAfterLast(logs.removeFirst(), logs.readFirstMensagem());

    }
}
}






/*****************************************************************************************************
*                                       METODO EXECUTAR O FLUXO                                      *
*  ***************************************************************************************************/

void vendingMachine::run(void){
    char getInput, *getI;
    int x, *getDH;


while(true){
      //  cout<<valor<<endl;

    getDH = t.getClockCalendar();

    cout<<"VALOR: "<<&valor[3]<<endl;

print("\n*******VENDING MACHINE TEST!********\n",NULL);
        print("[1] - 25c \n", NULL);
        print("[2] - 50c \n", NULL);
        print("[3] - 1R$ \n", NULL);
        print("[4] - MEET \n", NULL);
        print("[5] - ETIRPS\n", NULL);
        print("[6] - DEV \n", NULL);
        print("[7] - SHOW LOGS\n",NULL);
        print("********* DATA E HORA***************\n",NULL);
        print(" ",getDH[0]);print("/",getDH[1]);print("/",getDH[2]);
        print(" - ",getDH[3]);print(":",getDH[4]);print(":",getDH[5]);
        print("\n*******DINHIRO INSERIDO***********\n\n",NULL);
        print("R$", (totalValue/100)); //Montante
        print(",", (totalValue%100));
        getI =input();
        getInput = getI[0];
        advanceState(getInput);   // flow FSM*/


        };


    };

/**********************************************************************************************/

void vendingMachine::menu(){
   // char getInput, *getI;
        print("\n*******VENDING MACHINE TEST!********\n",NULL);
        print("[1] - 25c \n", NULL);
        print("[2] - 50c \n", NULL);
        print("[3] - 1R$ \n", NULL);
        print("[4] - MEET \n", NULL);
        print("[5] - ETIRPS\n", NULL);
        print("[6] - DEV \n", NULL);
        print("[7] - SHOW LOGS\n",NULL);
        print("********* DATA E HORA***************\n",NULL);
        print("********* DATA E HORA***************\n",NULL);
        print(" ",getDH[0]);print("/",getDH[1]);print("/",getDH[2]);
        print(" - ",getDH[3]);print(":",getDH[4]);print(":",getDH[5]);
     //   getI =input();
      //  getInput = getI[0];
      //  advanceState(getInput);
      //  update();
       system("cls");
       }



void vendingMachine::relogio_system(void){
    int*getDH;
    getDH = t.getClockCalendar();

}

void vendingMachine::entradas(){
    char getInput, *getI;
 while (1){
        getDH = t.getClockCalendar();
        getI =input();
        getInput = getI[0];

 }
}


void vendingMachine::update(void){

  ++t;
  /* getDH = t.getClockCalendar();
        print(" ",getDH[0]);print("/",getDH[1]);print("/",getDH[2]);
        print(" - ",getDH[3]);print(":",getDH[4]);print(":",getDH[5]);*/
}

void vendingMachine::detector_moeda()//simula o detector de moeda
{
   char getInput, *getI;
   getI =input();
   getInput = getI[0];



   switch (getInput){

       case '1' :{print("MOEDA 25c",NULL);sleep(1);advanceState(getInput);}break;
       case '2' :{print("MOEDA 50c",NULL);sleep(1);advanceState(getInput);}break;
       case '3' :{print("MOEDA 1R$",NULL);sleep(1);advanceState(getInput);}break;

   }



};
