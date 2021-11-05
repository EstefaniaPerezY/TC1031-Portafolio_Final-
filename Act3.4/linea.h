#ifndef _LINEA_H_
#define _LINEA_H_

#include <string>
#include "internetP.h"

class linea{

  private:
    std::string mes; 
    std::string dia; 
    std::string hora;
    std::string min; 
    std::string seg; 
    std::string octA;
    std::string octB; 
    std::string octC; 
    std::string octD; 
    std::string puerto;
    std::string razon;
    internetP direccion;

  public:
    linea();
    linea(std::string mes, std::string dia, std::string hora, std::string min, std::string seg, std::string octA, std::string octB, std::string octC, std::string octD, std::string puerto, std::string razon, internetP direccion);
    internetP getDireccion();
    std::string print();
 
};


#endif //_LINEA_H_
