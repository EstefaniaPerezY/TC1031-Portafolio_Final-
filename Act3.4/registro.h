#ifndef _REGISTRO_H_
#define _REGISTRO_H_

#include "internetP.h"
#include "linea.h"
#include <string>
#include <vector>
#include "Tmp.h"
#include <iostream>


class registro{

  private:
    //usado en heapsort
    linea arre[16807];
    //usado en findcounts
    std::vector<internetP> vectIP;
    //usado en heaptify_down
    std::vector<int> vectMaxHeap;
    //usado en set
    std::vector<Tmp> temporal;

  public:
    registro();
    void leerDatos();
    void heapify(linea arr[], int n, int i);
    void heapSort(linea arr[], int n);
    int getArrSize();
    void ordenar();
    void crearFileO();
    void findCounts();
    void heapify_down(int i);
    void heapify_up(int i);
    void push(int key);
    void pop();
    int top();
    void countFreq();
    std::string printFive();
    void mostrar();
    
};



#endif // _REGISTRO_H_
