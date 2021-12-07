/* 
 Created by: 
 Estefanía Pérez Yeo A01639270
 Alan Paul García Rosales A01639631

 Compilacion para debug:  
  g++ -std=c++17 -g -o main *.cpp 

 Ejecucion con valgrind:
  valgrind --leak-check=full ./main 

 Compilacion para ejecucion:  
  g++ -std=c++17 -O3 -o main *.cpp 

 Ejecucion:
  ./main
*/

#include <iostream>
#include "Graph.h"
int main(){
  Graph graphBinnacle("bitacoraGrafos.txt");
}