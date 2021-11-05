#include <cmath>
#include <string>
#include "internetP.h"

internetP::internetP(){
  
}


void internetP::setDecimalEntero(){
  uint tres = std::pow(256,3);
  uint dos = std::pow(256,2);
  uint uno = std::pow(256,1);
  uint cero = std::pow(256,0);

  uint res1 = this->octA * tres;
  uint res2 = this->octB * dos;
  uint res3 = this->octC * uno;
  uint res4 = this->octD * cero;

  uint res = res1 +res2 + res3 + res4;

  this->decimalEntero = res;
}

internetP::internetP(int octA, int octB, int octC, int octD, int puerto){
  this->octA = octA;
  this->octB = octB;
  this->octC = octC;
  this->octD = octD;
  this->puerto = puerto;
  this->setDecimalEntero();
}

uint internetP::getDecimalEntero(){
  return this->decimalEntero;
}

std::string internetP::imprimir(){
  std::string tmp =  std::to_string(this->octA) + "." + std::to_string(this->octB) + "." + std::to_string(this->octC) + "." + std::to_string(this->octD);

  return tmp;
}

