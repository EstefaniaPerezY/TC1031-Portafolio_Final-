#ifndef _REGISTRO_H
#define _REGISTRO_H

//#include <vector>
#include "DoubleLinkedList.h"
#include "dateTime.h"
#include "linea.h"
#include <fstream>

class registro {
  private:
    DoubleLinkedList<linea> myList;
    int searchf1;
    int searchf2;

  public:
    registro();
    // leer datos
    void leerDatos();
    //dar tamaño de vector
    int getListSize();
    // crea txt de ordenamiento
    void crearFileO();
    // crea txt de busqueda
    void crearFileB();
    // metodo de busqueda
    int busquedaBinaria(dateTime k);
    //imprimir rango de búsqueda
    void imprimirIdx(int indexf1, int indexf2);
    //llamada de metodo de ordenamiento
    void sort();
    //setter's utilizados en busqueda
    void setSearchF1(int i);
    void setSearchF2(int i);
    //getter's utilizados en busqueda
    int getSearchF1();
    int getSearchF2();

};

//constructor
registro::registro() {
  //myList.clear();
  myList.~DoubleLinkedList();
}

void registro::leerDatos() {
  std::string mes, dia, hora, minuto, segundo, ip, razon;
  //open file
  std::ifstream in("bitacora.txt");
  while(std::getline(in, mes, ' ')){
    std::getline(in, dia, ' ');
    std::getline(in,hora,':');
    std::getline(in,minuto,':');
    std::getline(in,segundo,' ');
    std::getline(in,ip,' ');
    std::getline(in,razon);
    // crea objeto dateTime
    dateTime tmpDT (mes, stoi(dia), stoi(hora), stoi(minuto), stoi(segundo));
    // crea objeto linea
    linea tmpLine (mes, dia, hora, minuto, segundo, ip, razon, tmpDT);
    // Agrega un objeto line al vector
    myList.addLast(tmpLine);
  }
  in.close();
}

//crea nueva archivo txt con la bitacora ordenada
void registro::crearFileO() {
  std::ofstream f("bitacora_ordenada.txt");
  for (int i=0; i < myList.getNumElements(); i++) {
    f << myList[i].getAll() << "\n";
  }
}

//crea nueva archivo txt con el resultado de búsqueda binaria
void registro::crearFileB() {
  std::ofstream f("resultado_busqueda.txt");
  for (int i=this->getSearchF1(); i <= this->getSearchF2(); i++) {
    f << myList[i].getAll() << "\n";
  }
}

//regresa el tamaño del vector con los datos de la bitacora
int registro::getListSize(){
  return this->myList.getNumElements();
}

void registro::sort(){
  //myList.iterativeQuickSort();
  myList.quickSort();
} 

//algoritmo de busqueda
//Complejidad O(log n)
int registro::busquedaBinaria(dateTime k){
  int low = 0;
  int high = myList.getNumElements() - 1;
  while (low <= high) {
    int m = low + (high - low) / 2;
    if (k.getDate() == myList[m].getFechaHora().getDate()) return m;
    else if (k.getDate() < myList[m].getFechaHora().getDate())
      high = m - 1;
    else
      low = m + 1;
  }
  return -1;
}

//muestra en pantalla el rango de busqueda
void registro::imprimirIdx(int indexf1, int indexf2){
  for(int i = indexf1; i <= indexf2; i++){
    std::cout << myList[i].getMonth() << " " << myList[i].getDay() << " " << myList[i].getHour() << ":" << myList[i].getMin() << ":" << myList[i].getSeg() << " " << myList[i].getIP() << " " << myList[i].getRazon() << std::endl;
  }
} 

//ingresa valor a searchf1
void registro::setSearchF1(int i){
  this->searchf1 = i;
}

//ingresa valor a searchf2
void registro::setSearchF2(int i){
  this->searchf2 = i;
}

//devuelve valor de searchf1
int registro::getSearchF1(){
  return this->searchf1;
}

//devuelve valor de searchf2
int registro::getSearchF2(){
  return this->searchf2;
}

#endif // _REGISTRO_H
