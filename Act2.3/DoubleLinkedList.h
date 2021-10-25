#ifndef _DOUBLELINKEDLIST_H_
#define _DOUBLELINKEDLIST_H_

#include <ctime>
#include <climits>
#include "Node.h"
//#include "Queue.h"
#include "linea.h"
#include "Stack.h"

template <class T>
class DoubleLinkedList{
    private:
      Node<T>* head;
      Node<T>* tail;
      int numElements;

    public:
      DoubleLinkedList();
      ~DoubleLinkedList();
      void clear();
      int getNumElements();
      void printList();
      void addFirst(T value);
      void addLast(T value);
      bool deleteData(T value);
      bool deleteAt(int position);
      T getData(int position);
      T operator[](const int position);
      void swap (T * a, T * b );
      Node<T>* partition(Node<T> *l, Node<T> *h);
      void _quickSort(Node<T>* l, Node<T> *h);
      Node<T>* lastNode(Node<T> *root);
      void quickSort();
};



//Constructor
template<class T>
DoubleLinkedList<T>::DoubleLinkedList() {
  std::cout << "--->Creando una lista vacia " << this << std::endl;
  head = NULL;
  tail = NULL;
  numElements = 0;
}

//Desconstructor
template<class T>
DoubleLinkedList<T>::~DoubleLinkedList() {
  std::cout << "--->Liberando memoria de la lista " << this << std::endl;
  Node<T> *p, *q;
  p = head;
  while (p != NULL) {
    q = p->next;
    delete p;
    p = q;
  }
  head = NULL;
  tail = NULL;
  numElements = 0;
}

//Conocer el tamaño de la lista
template<class T>
int DoubleLinkedList<T>::getNumElements() {
  return numElements;
}

//imprime la data de cada Nodo
template<class T>
void DoubleLinkedList<T>::printList() {
  Node<T> *ptr = head;
  while (ptr != NULL) {
    std::cout << ptr->data << " ";
    ptr = ptr->next;
  }
  std::cout << std::endl;
}

//Agrega al inicio un nuevo nodo
template<class T>
void DoubleLinkedList<T>::addFirst(T value) {
  Node<T> *newNode = new Node<T>(value);
  // Si la lista esta vacia 
  if (head == NULL) {
    head = newNode;
    tail = newNode;
  }
  else {
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
  }
  numElements++;
}

//Agrega al final un nuevo Nodo
template<class T>
void DoubleLinkedList<T>::addLast(T value) {
  // La lista esta vacia
  if (head == NULL) {
    addFirst(value);
  }
  else {
    Node<T> *newNode = new Node<T>(value);
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
    numElements++;
  }    
}

//Elimina Nodo en la lista a partir de un valor ingresado como parametro
template<class T>
bool DoubleLinkedList<T>::deleteData(T value) {
  Node<T> *p, *q;
  p = head;
  q = NULL;
  // Si la lista esta vacia 
  if (p == NULL) {
    return false;
  }
  else {
    // buscar value en la lista
    while (p != NULL && p->data != value) {
      q = p;
      p = p->next;
    }
    // Si no existe value en la lista
    if (p == NULL)
      return false;
    // Si debe borrarse el primer elemento
    if (p->prev == NULL) {
      head = p->next;
      if (head != NULL)
        head->prev = NULL;
    }
    else if (p->next == NULL) { 
      // Si debe borrarse el último elemento
      q->next = NULL;
      tail = q;
    }
    else {
      // Cualquier otro elemento entre la lista 
      q->next = p->next;
      p->next->prev = q;
    }
    delete p;
    numElements--;
    return true;
  }
}

//Elimina un nodo en la Lista a partir de la posicion como parametro
template<class T>
bool DoubleLinkedList<T>::deleteAt(int position) {
  if (position < 0 || position >= numElements) {
    std::cout << "Indice fuera de rango" << std::endl;
    return false;
  }
  else if (position == 0) { // Si debe borrarse el primer elemento
    Node<T> *p = head;
    // Si la lista contiene solo un nodo
    if (head != NULL && head->next == NULL) {
      head = NULL;
      tail = NULL;  
    }
    else {
      head = p->next;
      head->prev = NULL;
    }
    delete p;
    numElements--;
    return true; 
  }
  else { 
    Node<T> *p = head, *q = NULL;
    int index = 0;
    while (index != position) {
      q = p;
      p = p->next;
      index++;
    }
    // Si debe borrarse el último elemento
    if (p->next == NULL) {
      q->next = NULL;
      tail = q;
    }
    else { // Cualquier otro elemento entre la lista 
      q->next = p->next;
      p->next->prev = q;
    }
    delete p;
    numElements--;
    return true;
  }
}

//regresa la data del Nodo a partrir de la posicion como parametro
template<class T>
T DoubleLinkedList<T>::getData(int position) {
  if (position < 0 || position >= numElements) {
    std::cout << "Indice fuera de rango" << std::endl;
    return -1;
  }
  else {
    if (position == 0)
      return head->data;
    Node<T> *p = head;
    int index = 0;
    while (p != NULL) {
      if (index == position)
        return p->data;
      index++;
      p = p->next;
    }
    return -1;
  }
}

//Complejidad O(n)
template <class T>
T DoubleLinkedList<T>::operator[](const int position){
  
  T valor;
  try{
    if(position < 0 || position >= numElements){
      throw std::out_of_range("Elemento fuera de rango");
    }
    if (position == 0){
      return head->data;}
    Node<T> *p = head;
    int index = 0;
    while (p != NULL) {
      if (index == position)
        return p->data;
      index++;
      p = p->next;
    }
    return valor;
  }catch(const std::out_of_range &oor){
      std::cerr << "Error: " << oor.what() << std::endl;
      return valor;
  }
}
//-------------------------------
//Ordenamiento

//Complejidad O(1)
template <class T>
void DoubleLinkedList<T>::swap (T * a, T * b ){ 
  T t = *a; *a = *b; *b = t; 
}

//Complejidad O(n)
template <class T>
Node<T>* DoubleLinkedList<T>::partition(Node<T> *l, Node<T> *h){
    // set pivot as h element
    time_t x = h->data.getFechaHora().getDate();
 
    // similar to i = l-1 for array implementation
    Node<T> *i = l->prev;
 
    // Similar to "for (int j = l; j <= h- 1; j++)"
    for (Node<T> *j = l; j != h; j = j->next)
    {
        if (j->data.getFechaHora().getDate() <= x)
        {
            // Similar to i++ for array
            i = (i == NULL)? l : i->next;
 
            swap(&(i->data), &(j->data));
        }
    }
    i = (i == NULL)? l : i->next; // Similar to i++
    swap(&(i->data), &(h->data));
    return i;
}
 
// A recursive implementation
//of quicksort for linked list
//complejidad O(1)
template <class T>
void DoubleLinkedList<T>::_quickSort(Node<T>* l, Node<T> *h){
    if (h != NULL && l != h && l != h->next)
    {
        Node<T> *p = partition(l, h);
        _quickSort(l, p->prev);
        _quickSort(p->next, h);
    }
}

//complejidad O(n)
template <class T>
Node<T> * DoubleLinkedList<T>::lastNode(Node<T> *root){
    while (root && root->next)
        root = root->next;
    return root;
}
// The main function to sort a linked list.
// It mainly calls _quickSort()
//complejidad O(1)
template <class T>
void DoubleLinkedList<T>::quickSort(){
    Node<T> *p = head;
    // Find last node
    Node<T> *t = tail;
    // Call the recursive QuickSort
    _quickSort(p, t);
}



#endif // _DOUBLELINKEDLIST_H_
