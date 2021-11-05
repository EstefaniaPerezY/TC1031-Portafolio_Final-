#include "linea.h"
linea::linea(){

}
linea::linea(std::string mes, std::string dia, std::string hora, std::string min, std::string seg, std::string octA, std::string octB, std::string octC, std::string octD, std::string puerto, std::string razon, internetP direccion){
  this->mes = mes;
  this->dia = dia;
  this->hora = hora;
  this->min = min;
  this->seg = seg;
  this->octA = octA;
  this->octB = octB;
  this->octC = octC;
  this->octD = octD;
  this->puerto = puerto;
  this->razon = razon;
  this->direccion = direccion;
}

internetP linea::getDireccion(){return this->direccion;}

std::string linea::print(){
  std::string tmpLine = this->mes + " " + this->dia + " " + this->hora + ":" + this->min + ":" + this->seg + " " + this->octA + "." + this->octB + "." + this->octC + "." + this->octD + ":" + this->puerto + " " + this->razon;
  return tmpLine;
}
