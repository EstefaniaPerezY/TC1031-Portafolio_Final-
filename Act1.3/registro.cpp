#include <fstream>
#include "registro.h"


//constructor
registro::registro() {
  myVect.clear();
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
    myVect.push_back(tmpLine);
  }
  in.close();
}

//crea nueva archivo txt con la bitacora ordenada
void registro::crearFile() {
  std::ofstream f("bitacora_ordenada.txt");
  for (int i=0; i < myVect.size(); i++) {
    f << myVect[i].getAll() << "\n";
  }
}

//regresa el tamaño del vector con los datos de la bitacora
int registro::getVectSize(){
  return this->myVect.size();
}

//Algoritmo de ordenamiento
// Complejidad O(n log n)
void registro::merge(int low, int m, int high) {
  int i, j, k;
  int n1 = m - low + 1;
  int n2 = high - m;
  // crear arreglos L y R
  std::vector<linea> L(n1), R(n2);
  // Copiar datos a L y R
  for (i = 0; i < n1; i++)
    L[i] = myVect[low + i];
  for (j = 0; j < n2; j++)
    R[j] = myVect[m + 1 + j];
  // Fusionar L y R
  i = j = 0; k = low;
  while (i < n1 && j < n2) {
    if (L[i].getFechaHora() <= R[j].getFechaHora()) {
      myVect[k]= L[i];
      i++;
    }
    else {
      myVect[k] = R[j];
      j++;
    }
    k++;
  }
  // Copiar los elementos restantes de L
  while (i < n1) {
    myVect[k] = L[i];
    i++;
    k++;
  }
  // Copiar los elementos restantes de R
  while (j < n2) {
    myVect[k] = R[j];
    j++;
    k++;
  }
}

//Complejidad O(n^((log_2)(2)))
//Debido a que el logaritmo base 2 de 2, resulta uno, se convierte 
//en O(n^1)
//lo que resulta en O(n)

//Complejidad O(n)

void registro::ordenaMerge(int low, int high) { 
  
  if (low >= high) {
    return;
  }
  int m = low + (high - low)/2;
  ordenaMerge(low, m);    // mitad izquierda
  ordenaMerge(m+1, high); // mitad derecha
  merge(low, m, high);  // fusion de mitades
}

//algoritmo de busqueda
//Complejidad O(log n)
int registro::busquedaBinaria(dateTime k){
  int low = 0;
  int high = myVect.size() - 1;
  while (low <= high) {
    int m = low + (high - low) / 2;
    if (k.getDate() == myVect[m].getFechaHora().getDate()) return m;
    else if (k.getDate() < myVect[m].getFechaHora().getDate())
      high = m - 1;
    else
      low = m + 1;
  }
  return -1;
}

//muestra en pantalla el rango de busqueda
void registro::imprimirIdx(int indexf1, int indexf2){
  for(int i = indexf1; i <= indexf2; i++){
    std::cout << myVect[i].getMonth() << " " << myVect[i].getDay() << " " << myVect[i].getHour() << ":" << myVect[i].getMin() << ":" << myVect[i].getSeg() << " " << myVect[i].getIP() << " " << myVect[i].getRazon() << std::endl;
  }
} 
