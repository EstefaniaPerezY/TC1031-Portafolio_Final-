#include "registro.h"

#include <fstream>
//constructor
registro::registro() {
  //myList.clear();
  //myBST.~BinarySearchTree();
}

void registro::leerDatos() {
  int i = 0;
  std::string mes, dia, hora, minuto, segundo, octA, octB, octC, octD, puerto, razon;
  //open file
  std::ifstream in("bitacoraHeap.txt");
  while(std::getline(in, mes, ' ')){
    std::getline(in, dia, ' ');
    std::getline(in,hora,':');
    std::getline(in,minuto,':');
    std::getline(in,segundo,' ');
    std::getline(in,octA,'.');
    std::getline(in,octB,'.');
    std::getline(in,octC,'.');
    std::getline(in,octD,':');
    std::getline(in,puerto,' ');
    std::getline(in,razon);
    // crea objeto internetP
    internetP tmpIP (stoi(octA), stoi(octB), stoi(octC), stoi(octD), stoi(puerto));
    // crea objeto linea
    linea tmpLine (mes, dia, hora, minuto, segundo, octA, octB, octC, octD, puerto, razon, tmpIP);
    // Agrega un objeto  array
    arre[i] = tmpLine;
    // Agrega a un objeto array solo con IP entero
    //arIP[i] = tmpIP.getDecimalEntero();
    i++;
    
  }
  std::cout << "-------end of myReg.leerDatos()" << std::endl;
  in.close();
}

void registro::heapify(linea arr[], int n, int i)
{
    int largest = i; // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2
 
    // If left child is larger than root
    if (l < n && arr[l].getDireccion().getDecimalEntero() > arr[largest].getDireccion().getDecimalEntero())
        largest = l;
 
    // If right child is larger than largest so far
    if (r < n && arr[r].getDireccion().getDecimalEntero() > arr[largest].getDireccion().getDecimalEntero())
        largest = r;
 
    // If largest is not root
    if (largest != i) {
        std::swap(arr[i], arr[largest]);
 
        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}
 
// main function to do heap sort
void registro::heapSort(linea arr[], int n)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
 
    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        std::swap(arr[0], arr[i]);
 
        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

int registro::getArrSize(){
  int size  = sizeof(arre) / sizeof(arre[0]);
  return size;
}


void registro::ordenar(){
  this->heapSort(arre,getArrSize());
  std::cout << "-------end of myReg.ordenar()" << std::endl;
}

//crea nueva archivo txt con la bitacora ordenada
void registro::crearFileO() {
  std::ofstream f("bitacora_ordenada.txt");
  for (int i=0; i < getArrSize(); i++) {
    f << arre[i].print() << "\n";
  }
  std::cout << "-------new file created" << std::endl;
}

// ocuntFreq retrieved from: https://www.geeksforgeeks.org/counting-frequencies-of-array-elements/
//and adapted to the proyect
void registro::countFreq()
{ 
  int n = getArrSize();
  // Mark all array elements as not visited
  std::vector<bool> visited(n, false);

  // Traverse through array elements and
  // count frequencies
  for (int i = 0; i < n; i++) {

    // Skip this element if already processed
    if (visited[i] == true)
      continue;

    // Count frequency
    int count = 1;
    for (int j = i + 1; j < n; j++) {
      if (arre[i].getDireccion().getDecimalEntero() == arre[j].getDireccion().getDecimalEntero()) {
        visited[j] = true;
        count++;
      }
    }
    Tmp caso (arre[i].getDireccion(), count);
    temporal.push_back(caso);
    vectIP.push_back(arre[i].getDireccion());
    this->push(count);
  }
  std::cout << "-------end of myReg.countFreq()" << std::endl;
}

//heapify_down, heapify_up, push, pop, top
//retrieved from: https://www.techiedelight.com/min-heap-max-heap-implementation-c/software
//and adapted to the proyect

// Recursive heapify-down algorithm.
// The node at index `i` and its two direct children
// violates the heap property
void registro::heapify_down(int i)
{
  // get left and right child of node at index `i`
  int left = 2 * i + 1;
  int right = 2 * i + 2;
  int largest = i;

  // compare `A[i]` with its left and right child
  // and find the largest value
  if (left < vectMaxHeap.size() && vectMaxHeap[left] > vectMaxHeap[i]) {
      largest = left;
  }

  if (right < vectMaxHeap.size() && vectMaxHeap[right] > vectMaxHeap[largest]) {
      largest = right;
  }

  // swap with a child having greater value and
  // call heapify-down on the child
  if (largest != i)
  {
      std::swap(vectMaxHeap[i], vectMaxHeap[largest]);
      heapify_down(largest);
  }
}

// Recursive heapify-up algorithm
void registro::heapify_up(int i)
{
  int parent = (i - 1) / 2;
  // check if the node at index `i` and its parent violate the heap property
  if (i && vectMaxHeap[parent] < vectMaxHeap[i])
  {
    // swap the two if heap property is violated
    std::swap(vectMaxHeap[i], vectMaxHeap[parent]);

    // call heapify-up on the parent
    heapify_up(parent);
  }
}

// insert key into the heap
void registro::push(int key)
{ 
  
  // insert a new element at the end of the vector
  //this->set(key,direccion,i);
  
  vectMaxHeap.push_back(key);

  // get element index and call heapify-up procedure
  int index = vectMaxHeap.size() - 1;
  heapify_up(index);
}

// Function to remove an element with the highest priority (present at the root)
void registro::pop()
{
  try {
    // if the heap has no elements, throw an exception
    if (vectMaxHeap.size() == 0)
    {
      throw std::out_of_range("Vector<X>::at() : "
              "index is out of range(Heap underflow)");
    }

    // replace the root of the heap with the last element
    // of the vector
    vectMaxHeap[0] = vectMaxHeap.back();
    vectMaxHeap.pop_back();

    // call heapify-down on the root node
    heapify_down(0);
  }
  // catch and print the exception
  catch (const std::out_of_range &oor) {
      std::cout << std::endl << oor.what();
  }
  //std::cout << "-------end of myReg.pop()" << std::endl;
}

// Function to return an element with the highest priority (present at the root)
int registro::top()
{
  try {
    // if the heap has no elements, throw an exception
    if (vectMaxHeap.size() == 0)
    {
      throw std::out_of_range("Vector<X>::at() : "
              "index is out of range(Heap underflow)");
    }

    // otherwise, return the top (first) element
    //std::cout << "-------end of myReg.top()" << std::endl;
    return vectMaxHeap[0];
  }
  // catch and print the exception
  catch (const std::out_of_range &oor) {
    std::cout << std::endl << oor.what();
  }

  
}

void registro::mostrar(){
  std::string tmp;
  std:: cout << "\n******* 5 direcciones con más accesos\n";
  std::cout << "Direccion IP | No. de acceso" << std::endl;
  for(int j = 0; j < 5; j++){
    for(int i = 0; i < vectIP.size(); i++){
      if(temporal[i].getKey() == top()){
        tmp = tmp + temporal[i].getDireccion().imprimir() + "   " + std::to_string(top()) + "\n";
        pop();
        auto it = temporal.begin() + i;
        temporal.erase(it);
        break;
      }
    }
  }
  std::cout << tmp << std::endl;
  std::cout << "\n-------new file created" << std::endl;
  std::ofstream f("ips_con_mayor_acceso.txt");
  f << tmp;

  std::cout << "-------end of myReg.mostrar()" << std::endl;
}

