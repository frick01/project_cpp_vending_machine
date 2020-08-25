
#include <iostream>

using namespace std;

template <typename T>
class Node {

    int val, i;
    T *msg;
    T mensagem[20];
    Node* next;

  public:

    Node(int dat, Node* nxt, T *msg);
    int getVal();
    Node* getNext();
    void setVal(int dat);
    void setNext(Node* nxt);
    void setMensagem(T *msagem);
    T * getMensagem();
};
