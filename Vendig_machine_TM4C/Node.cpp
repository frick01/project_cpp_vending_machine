
#include "Node.h"

// Constructor - initializes the node
//
template <typename T>
Node<T>::Node(int dat, Node* nxt, T *msg){
       val = dat;
       next = nxt;
       setMensagem(msg);
}

// getVal returns the integer value stored in the node
//
template <typename T>
int Node<T>::getVal(){
     return val;
}

// getNext returns a pointer for the next node in the linked list
//
template <typename T>
Node<T>* Node<T>::getNext(){
     return next;
}

// setVal stores the integer value in the node
//
template <typename T>
void Node<T>::setVal(int dat){
     val = dat;
}

// setNext stores the pointer to the next node in the list in the "next" field
//
template <typename T>
void Node<T>::setNext(Node* nxt){
       next = nxt;
}

template <typename T>
void Node<T>::setMensagem(T *msagem){
    msg = msagem;
    for(int i=0; i<20; i++){
    mensagem[i] = msg[i];}
}

template <typename T>
T * Node<T>::getMensagem(){
    return mensagem;
}
