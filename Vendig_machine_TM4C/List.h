#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED
#include "Node.cpp"

template <typename T>
class List {

  Node<T>* head;
  int Size=0;

public:
  List();
  ~List();
  void insertAfterLast(int dat, T *mensagem);
  int readFirst();
  int removeFirst();
  int removeNode(int dat);
  int getSize(void);
  T * readFirstMensagem();
};
#endif		// LIST
