#ifndef __HASH_TABLE_H_
#define __HASH_TABLE_H_

#include <vector>
#include <stdexcept>
#include "HashNode.h"
#include "IP.h"

template<class K, class T>
class HashTable {
  private:
    std::vector<HashNode<K,T>> table;
    int size, collisions;
    int maxSize;

  public:
    HashTable(int selectedMaxSize);//Complejidad O(1)
    void fill(std::vector<pair<IP,std::vector<IP>>>& list); //Complejidad O(n)
    void getIPSummary(IP ip);//Complejidad O(n)
    IP getInput(); //Complejidad O(n)
    std::vector<HashNode<K,T>> getTable(); //Complejidad O(1)
    int getHashIndex(K keyVal); //Complejidad O(1)
    int getSize(); //Complejidad O(1)
    int getCol();//Complejidad O(1)
    void print(); //Complejidad O(n)
    void add(K keyVal, T value); //Complejidad O(n)
    int find(K keyVal); //Complejidad O(n)
    T getDataAt(int index); //Complejidad O(n)
    void remove(K keyVal); //Complejidad O(n)
    void quickSort(std::vector<IP> arr, int low, int high); //Complejidad O(nlogn)
    int partition(std::vector<IP> &arr, int low, int high); //Complejidad O(n)
    void swap(IP* a, IP* b); //Complejidad O(1)
};


template<class K, class T>
HashTable<K, T>::HashTable(int selectedMaxSize) {
  maxSize = selectedMaxSize;
  size = 0;
  table = std::vector<HashNode<K,T>>(maxSize);
}

template<class K, class T>
void HashTable<K, T>::fill(std::vector<pair<IP,std::vector<IP>>>& list) {
  for(int i = 0; i < list.size(); i++){
    list[i].first.setAdjIP(list[i].second);
    add(list[i].first.getDecimal(), list[i].first);
  }
}

template<class K, class T>
void HashTable<K,T>::getIPSummary(IP ipKey){
  int index = find(ipKey.getDecimal());
  if(index == -1){
    std::cout << "The entered IP does not exist"<<std::endl;
    return;
  }
  IP ip = getDataAt(index);
  quickSort(ip.getIPvect(),0, ip.getIPvect().size()-1);
  ip.getSummary().printSummary();
  std::cout << "-----------------------" << std::endl;
  std::cout << "Ip's accessed:" << std::endl;
  for(int i = 0; i < ip.getIPvect().size(); i++){
    std::cout << ip.getIPvect()[i] << std::endl;
  }
}

template<class K, class T>
IP HashTable<K,T>::getInput(){
  std:: cout << "-----------------------" << std::endl;
  int oct1, oct2, oct3, oct4;
  std::cout << "Enter the first octate: ";
  cin >> oct1;
  while(oct1 < 0 || oct1 > 255){
    std::cout << "Digit invalid (valid range: 0-255)"<<std::endl;
    std::cout << "Enter again";
    cin >> oct1;
  }
  std::cout << "Enter the second octate: ";
  cin >> oct2;
  while(oct2 < 0 || oct2 > 255){
    std::cout << "Digit invalid (valid range: 0-255)"<<std::endl;
    std::cout << "Enter again";
    cin >> oct2;
  }
  std::cout << "Enter the third octate: ";
  cin >> oct3;
  while(oct3 < 0 || oct3 > 255){
    std::cout << "Digit invalid (valid range: 0-255)"<<std::endl;
    std::cout << "Enter again";
    cin >> oct3;
  }
  std::cout << "Enter the fourth octate: ";
  cin >> oct4;
  while(oct4 < 0 || oct4 > 255){
    std::cout << "Digit invalid (valid range: 0-255)"<<std::endl;
    std::cout << "Enter again";
    cin >> oct4;
  }
  IP ip(oct1, oct2, oct3, oct4, "0");

  return ip;
}

template<class K, class T>
std::vector<HashNode<K,T>> HashTable<K, T>::getTable() {
  return table;
}

template<class K, class T>
int HashTable<K,T>::getHashIndex(K keyVal) {
  return keyVal % maxSize;
}

template<class K, class T>
int HashTable<K,T>::getSize() {
  return size;
}

template<class K, class T>
int HashTable<K,T>::getCol() {
  return collisions;
}

template<class K, class T>
void HashTable<K,T>::print() {
  std::cout << "Content of the hash table: " << std::endl;
  for (int i = 0; i < maxSize; i++) {
    if (table.at(i).getStatus()==1) // Cell is used
      std::cout << "Cell: " << i << " Key: " << table.at(i).getKey() << ", Value: " << table.at(i).getData() << ", Overflow.size: " << table.at(i).getOverflowSize() << std::endl;
  }
}

template<class K, class T>
void HashTable<K,T>::add(K keyVal, T value) {
  if (size == maxSize) {
    throw std::out_of_range("Hash Table is full");
  }
  // Compute the index of the table using a key and a hash function
  int hashVal = getHashIndex(keyVal);
  HashNode<K, T> node = table.at(hashVal);
  // The cell in the table is not taken
  if (node.getStatus() != 1) {
    node.setKey(keyVal);
    node.setData(value);
    table.at(hashVal) = node;
  }
  else { // The cell in the table is already taken
    // Find next free space using quadratic probing
    int i = 1;
    int currentHashVal = getHashIndex(hashVal + i * i);
    HashNode<K, T> currentNode = table.at(currentHashVal);
    while (currentNode.getStatus() == 1) {
      i++;
      currentHashVal = getHashIndex(hashVal + i * i);
      currentNode = table.at(currentHashVal);
      collisions++;
    }
    currentNode.setKey(keyVal);
    currentNode.setData(value);
    node.addToOverflow(currentHashVal);
    table.at(currentHashVal) = currentNode;
    table.at(hashVal) = node;
    collisions++;
  }
  size++;
}  

template<class K, class T>
int HashTable<K,T>::find(K keyVal) {
  int hashVal = getHashIndex(keyVal); 
  HashNode<K, T> node = table.at(hashVal);
  // Cell in the table is taken
  if (node.getStatus() == 1) {
    if (node.getKey() == keyVal) {
      return hashVal;
    }
    for (int i = 0; i < node.getOverflowSize(); i++) {
      int overflowIndex = node.getOverflowAt(i);
      if (table.at(overflowIndex).getKey() == keyVal) {
        return overflowIndex;
      }
    }
    return -1;
  }
  return -1;
}

// Compleidad: O(1)
template<class K, class T>
T HashTable<K,T>::getDataAt(int index) {
  return table.at(index).getData();
}

template<class K, class T>
void HashTable<K,T>::remove(K keyVal) {
  int pos, hashVal;
  pos = find(keyVal);
  if (pos == -1) {
    throw std::invalid_argument("Element does not exist in hash table");
  }
  hashVal = getHashIndex(keyVal);
  if (pos != hashVal) {
    HashNode<K, T> node = table.at(hashVal);
    node.removeFromOverflow(pos);
    table.at(hashVal) = node;
  }
  table.at(pos).clearData(); 
}

template<class K, class T>
void HashTable<K,T>::quickSort(std::vector<IP> arr, int low, int high){
  if (low < high){
    int pi = partition(arr, low, high);
    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
  }
}

//Complejidad O(n)
template<class K, class T>
int HashTable<K,T>::partition(std::vector<IP> &arr, int low, int high){
  IP pivot = arr[high];
  int i = (low - 1);  

  //Complejidad O(n)
  for (int j = low; j <= high- 1; j++){
    IP ipIndx = arr[j];
    //Complejidad O(1)
    if (ipIndx <= pivot){
      i++;  
      //Complejidad O(1)  
      swap(&arr[i], &arr[j]);
    }
  }
  //Complejidad O(1)
  swap(&arr[i + 1], &arr[high]);
  return (i + 1);
}

//Complejidad O(1)
template<class K, class T>
void HashTable<K,T>::swap(IP* a, IP* b){
  IP t = *a;
  *a = *b;
  *b = t;
}


#endif // __HASH_TABLE_H_

