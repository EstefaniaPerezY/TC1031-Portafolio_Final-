#ifndef _INTERNETP_H_
#define _INTERNETP_H_

#include <string>

class internetP{
  private:
    uint octA;
    uint octB;
    uint octC;
    uint octD;
    uint puerto;
    uint decimalEntero;
  public:
    internetP();
    internetP(int octA, int octB, int octC, int octD, int puerto);
    uint getDecimalEntero();
    void setDecimalEntero(); 
    std::string imprimir();
};

#endif //_INTERNETP_H_
