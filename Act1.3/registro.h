#ifndef _REGISTRO_H
#define _REGISTRO_H

#include <vector>
#include "linea.h"
#include "dateTime.h"

class registro {
  private:
    std::vector<linea> myVect;

  public:
    registro();
    // leer datos
    void leerDatos();
    //dar tamaño de vector
    int getVectSize();
    // imprime registro
    void crearFile();
    // metodo de ordenamiento
    void ordenaMerge(int low, int high);
    void merge(int low, int m, int high);
    // metodo de busqueda
    int busquedaBinaria(dateTime k);
    //imprimir rango de búsqueda
    void imprimirIdx(int indexf1, int indexf2);

};

#endif // _REGISTRO_H