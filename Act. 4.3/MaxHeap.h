#ifndef __MAXHEAP_H_
#define __MAXHEAP_H_

#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include "IP.h"

template<class T>
class MaxHeap {
  private:
    std::vector<T> data; 
    int maxSize;
    int size;   
    int parent(int i);
    int left(int i);
    int right(int i);

  public:
    MaxHeap(int capacity);
    ~MaxHeap();
    bool isEmpty();
    int getSize();
    int getCapacity();
    void printMaxHeap();
    void push(T key);
    void createDegreesBinnacle(std::string file, int start, int end);
    void connections(std::string file);
    void heapify(int n, int i);
    void heapSort();
    void moveDown(int i);
    void pop();
    T top();
};

//Complejidad O(n)
template <class T> 
MaxHeap<T>::MaxHeap(int capacity){
  size = 0;
  maxSize = capacity;
  //Complejidad O(n)
  data.resize(maxSize);
}

//Complejidad O(1)
template <class T> 
MaxHeap<T>::~MaxHeap() {
  data.clear();
}

 //Complejidad O(1) 
template <class T> 
bool MaxHeap<T>::isEmpty(){
  return (size <= 0);
}

//Complejidad O(1)
template <class T> 
int MaxHeap<T>::getSize() {
  return size;
}

//Complejidad O(1)
template <class T> 
int MaxHeap<T>::getCapacity() {
  return maxSize;
}

//Complejidad O(1)
template <class T> 
void MaxHeap<T>::printMaxHeap() {
  for (int i=0; i < size; i++)
    std::cout << data[i].getAll() << std::endl;
}

//Complejidad O(1)
template <class T> 
int MaxHeap<T>::parent(int i) {
  return (i-1)/2; 
}

//Complejidad O(1)
template <class T> 
int MaxHeap<T>::left(int i) {
  return (2*i + 1); 
}

//Complejidad O(1)
template <class T> 
int MaxHeap<T>::right(int i) {
  return (2*i + 2);
}

//Complejidad O(n)
template <class T> 
void MaxHeap<T>::push(T key) {
  if (size == maxSize) {
    std::cout << "Overflow: no se puede insertar la llave: " << std::endl;
    return;
  }

  int i = size;
  data[i] = key;
  size++;

  while (i != 0 && data[parent(i)].getIp() < data[i].getIp()) {
      std::swap(data[i], data[parent(i)]);
      i = parent(i);
  }
}

//Complejidad O(logn)
template <class T> 
T MaxHeap<T>::top(){
  T result;
  if (isEmpty()){
    std::cout << "Empty MaxHeap" << std::endl;
    return result;
  }else{  
    return data[0];
  }
}

//Complejidad O(n)
template<class T>
void MaxHeap<T>::createDegreesBinnacle(std::string file, int start, int end){
  std::ofstream degBinnacle(file);
  //Complejidad O(1)
  if(degBinnacle.is_open()){
    std::cout << "\nEl archivo 'grados_ip.txt' se ha creado correctamente. \n" << std::endl;
  }else{
    std::cout << "\nWARN: El archivo 'grados_ip.txt' no se ha creado correctamente. \n" << std::endl;
  }
  //Complejidad O(n)
  for (int i = start; i <= end; i++){
    std::string line;
    //Complejidad O(1)
    if (i == data.size() - 1){
      line = data[i].getSimpleIP() + "  " + std::to_string(data[i].getDegree());
      degBinnacle << line;
    }else{
      line = data[i].getSimpleIP() + "  " + std::to_string(data[i].getDegree()) + "\n";
      degBinnacle << line;
    }
  }

  //Complejidad O(1)
  degBinnacle.close();
  if(!degBinnacle.is_open()){
    std::cout << "\nEl archivo 'grados_ip.txt' ha cerrado correctamente. \n" << std::endl;
  }else{
    std::cout << "\n WARN: El archivo 'grados_ip.txt' no ha cerrado correctamente. \n" << std::endl;
  }
}

//Complejidad O(logn)
template<class T>
void MaxHeap<T>::connections(std::string file){
  std::ofstream out(file);
  //Complejidad O(1)
  if(out.is_open()){
    std::cout << "El archivo 'mayores_grados_ips.txt' se ha creado correctamente. \n" << std::endl;
  }else{
    std::cout << "WARN: El archivo 'mayores_grados_ips.txt' no se ha creado correctamente. \n" << std::endl;
  }
  //Complejidad O(1)
  for (int i = 0; i < 6; i++){
    pop();
    //Complejidad O(logn)
    if (i > 0){
      if(i==1){
        std::cout << "Allegedly Boot Master IP: " << top().getSimpleIP() << " Connections: " << std::to_string(top().getDegree()) << std::endl;
        std::cout << "\n";
        std::cout << "Top 5 IPs with more connections: \n";
      }
      out << "IP: "<<top().getSimpleIP() + " Connections: " + std::to_string(top().getDegree()) + "\n";
      std::cout << "IP: "<<top().getSimpleIP() + " Connections: " + std::to_string(top().getDegree()) << std::endl;
      
    } 
  }
  std::cout << "\n";
  out.close();
  //Complejidad O(1)
  if(!out.is_open()){
    std::cout << "El archivo 'mayores_grados_ips.txt' se ha cerrado correctamente. \n" << std::endl;
  }else{
    std::cout << "WARN: El archivo 'mayores_grados_ips.txt' no se ha cerrado correctamente. \n" << std::endl;
  }
}

//Complejidad O(logn)
template <class T>
void MaxHeap<T>::heapify(int n, int i){
  int m = i;
  int l = 2 * i + 1;
  int r = 2 * i + 2;

  if(l < n && data[l].getDegree() > data[m].getDegree()){
    m = l;
  }if(r < n && data[r].getDegree() > data[m].getDegree()){
    m = r;
  }if (m != i){
    std::swap(data[i], data[m]);
    heapify(n, m);
  }
}

//Complejidad O(nlogn)
template <class T>
void MaxHeap<T>::heapSort(){
  int n = size;
  for (int i = (n / 2) - 1; i >= 0; i--){
    heapify(n, i);
  }
  for (int i = n - 1; i > 0; i--){
    std::swap(data[0], data[i]);
    heapify(i, 0);
  }
}

//Complejidad O(logn)
template <class T>
void MaxHeap<T>::moveDown(int i) {

  int maxIndex = i;

  if (left(i) <= size && data[left(i)].getIp() > data[maxIndex].getIp()) {
    maxIndex = left(i);
  }if (right(i) <= size && data[right(i)].getIp() > data[maxIndex].getIp()) {
    maxIndex = right(i);
  }if (i != maxIndex) {
    std::swap(data[i], data[maxIndex]);
    moveDown(maxIndex);
  }
}

//Complejidad O(logn)
template <class T>
void MaxHeap<T>::pop(){
  if (size < 1) {
    std::cout << "WARN: Empty MaxHeap. \n" << std::endl;
    return;
  }
  data[0] = data.back();
  data.pop_back();
  heapify(size, 0);
  size--;
  return;
}

#endif // __MAXHEAP_H_