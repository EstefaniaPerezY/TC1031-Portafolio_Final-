#include <iostream>
#include "registro.h"

int main() {
  std::cout << "test" << std::endl;
  registro myReg;
  myReg.leerDatos();
  myReg.ordenar();
  myReg.crearFileO();
  myReg.countFreq();
  myReg.mostrar();
}
