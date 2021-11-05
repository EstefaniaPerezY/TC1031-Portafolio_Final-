#ifndef _TMP_H_
#define _TMP_H_

#include "internetP.h"

class Tmp{
  private:
    internetP direccion;
    int key;
  public:
    Tmp(){};
    Tmp(internetP direccion, int key){this->direccion = direccion; this->key = key;};
    int getKey(){return this->key;}; 
    internetP getDireccion(){return this->direccion;};
};



#endif //_TMP_H_
