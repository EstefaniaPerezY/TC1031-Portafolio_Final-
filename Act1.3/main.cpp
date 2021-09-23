//solo dar clic en Run
//created by: Estefanía Pérez Yeo - A01639270

#include <iostream>
#include "registro.h"
#include <fstream>

int main() {
  std::cout << "test" << std::endl;
  registro myReg;
  myReg.leerDatos();
  
  //uso de argoritmo de ordenamiento merge
  myReg.ordenaMerge(0, myReg.getVectSize() - 1);

  std::cout << "---------------" << std::endl;
  std::cout << "bitacora ordenada" << std::endl;
  std::cout << "---------------" << std::endl;
  
  //crea archivo llamado "bitacora_ordenada" 
  myReg.crearFile();

  std::string mes1, dia1, hora1, min1, seg1;

  //datos de usuario
  //fecha 1 
  std::cout << "**Registro de primera fecha" << std::endl;
  std::cout << "Ingresa el mes, solo las primeras tres letras y en inglés  (Ej. Aug)" << std::endl;
  std::cin >> mes1;
  std::cout << "Ingresa el día, solo dos dígitos (Ej. 09)" << std:: endl;
  std::cin >> dia1;
  std::cout << "Ingresa la hora como horario de 24 hrs, solo dos dígitos (Ej. 24)" << std:: endl;
  std::cin >> hora1;
  std::cout << "Ingresa el minuto, solo dos dígitos (Ej. 10)" << std:: endl;
  std::cin >> min1;
  std::cout << "Ingresa el segundo, solo dos dígitos (Ej. 00)" << std:: endl;
  std::cin >> seg1;

  dateTime f1(mes1, stoi(dia1), stoi(hora1), stoi(min1), stoi(seg1));

  //uso de algoritmo de búsqueda
  int indexf1 = myReg.busquedaBinaria(f1);

  std::string mes2, dia2, hora2, min2, seg2;

  //fecha 2
  std::cout << "**Registro de primera fecha" << std::endl;
  std::cout << "Ingresa el mes, solo las primeras tres letras y en inglés  (Ej. Aug)" << std::endl;
  std::cin >> mes2;
  std::cout << "Ingresa el día, solo dos dígitos (Ej. 09)" << std:: endl;
  std::cin >> dia2;
  std::cout << "Ingresa la hora como horario de 24 hrs, solo dos dígitos (Ej. 24)" << std:: endl;
  std::cin >> hora2;
  std::cout << "Ingresa el minuto, solo dos dígitos (Ej. 10)" << std:: endl;
  std::cin >> min2;
  std::cout << "Ingresa el segundo, solo dos dígitos (Ej. 00)" << std:: endl;
  std::cin >> seg2;

  dateTime f2(mes2, stoi(dia2), stoi(hora2), stoi(min2), stoi(seg2));

  //uso de algoritmo de búsqueda
  int indexf2 = myReg.busquedaBinaria(f2);
  
  //muestra el rango de lineas establecidas por el algoritmo de busqueda
  myReg.imprimirIdx(indexf1, indexf2);
  
  return 0;
}