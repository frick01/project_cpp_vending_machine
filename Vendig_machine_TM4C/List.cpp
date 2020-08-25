
#include "List.h"


template <typename T>
List<T>::List() {
   head = 0;
}

template <typename T>
List<T>::~List() {
  Node<T>* cursor = head;
  while(head) {
    cursor = cursor->getNext();
    delete head;
    head = cursor;
  }
  head = 0; // Officially empty
}

template <typename T>
void List<T>::insertAfterLast(int dat, T *mensagem) {
  Node<T>* p = head;
  Node<T>* q = head;

  if (head == 0)
     head = new Node<T>(dat, head, mensagem);
  else {
     while (q != 0) {
        p = q;
        q = p->getNext();
     }
     p->setNext(new Node<T>(dat, 0, mensagem));
   }
   Size++;                  // Acrescenta o tamanho da fila
}

template <typename T>
int List<T>::readFirst() {
   if(head == 0){return 0;}     // caso a Fila esteja vazia, a função requisita leitura, dessa forma não há bloqueio
   else {return head->getVal();}
}

template <typename T>
int List<T>::removeFirst() {
  int retval = 0;
  Size--;                 // Decrescenta o tamanho da fila
  if (head != 0){
     retval = head->getVal();
     Node<T>* oldHead = head;
     head = head->getNext();
     delete oldHead;
  }
  return retval;
}

template <typename T>
int List<T>::removeNode(int dat) {
  Node<T>* p = head;
  Node<T>* q = head;
  int result;

  if (head == 0)
     result = 0;
  else {
	  while ((q != 0) && (q->getVal() != dat)){  // Error!! the addresses will always be different!
		  p = q;
		  q = p->getNext();
	  }
	  if (q != 0) {

		  if (q == head){	// it is the first node
			  result = q->getVal();
			  head = q->getNext();
			  delete q;
		  }
		  else{				// the node is in the middle
			  result = q->getVal();
			  p->setNext(q->getNext());
			  delete q;
		  }
	  }
	  else
		  result = 0;		// node not found!
  }

  return result;
}

template <typename T>
int List<T>::getSize(void) {    // Captura o tamanho
  return Size;
}

template <typename T>
T * List<T>::readFirstMensagem() {   // Retorna a mensagem gravada anteriormente no node

    Node<T>* m = head;
    T *mensagem;
    mensagem = m->getMensagem();
    if(head == 0){return 0;}
    else {return mensagem;}
}
