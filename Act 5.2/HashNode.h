#ifndef __HASH_NODE_H_
#define __HASH_NODE_H_

#include <vector>
#include <algorithm>
#include <iterator>

template<class K, class T>
class HashNode {

  private:
    K key;
    T data;
    int status;  // 0 vacio, 1 datos, 2 borrado
    std::vector<int> overflow; // used to easily find collision elements  

  public:
    HashNode(); //Complejidad O(1)
    K getKey(); //Complejidad O(1)
    T getData(); //Complejidad O(1)
    int getStatus(); //Complejidad O(1)
    void setKey(K keyVal); //Complejidad O(1)
    void setData(T dataVal); //Complejidad O(1)
    void clearData(); //Complejidad O(1)
    void addToOverflow(int hashIndex); //Complejidad O(1)
    int getOverflowSize(); //Complejidad O(1)
    int getOverflowAt(int index); //Complejidad O(1)
    void removeFromOverflow(int value); //Complejidad O(1)
    
};

template<class K, class T>
HashNode<K,T>::HashNode() {
  key = 0;
  status = 0;
}

template<class K, class T>
K HashNode<K,T>::getKey() {
  if (status != 1) throw "Invalid operation: Empty node";
  return key;
}

template<class K, class T>
T HashNode<K,T>::getData() {
  return data;
}

template<class K, class T>
int HashNode<K,T>::getStatus() {
  return status;
}

template<class K, class T>
void HashNode<K,T>::setKey(K keyVal) {
  key = keyVal;
}

template<class K, class T>
void HashNode<K,T>::setData(T dataVal) {
  if (status == 1) throw "Node has been taken";
  data = dataVal;
  status = 1;
}

template<class K, class T>
void HashNode<K,T>::clearData() {
    status = 0;
}

template<class K, class T>
void HashNode<K,T>::addToOverflow(int hashIndex) {
  overflow.push_back(hashIndex);
}

template<class K, class T>
int HashNode<K,T>::getOverflowSize() {
  return overflow.size();
}

template<class K, class T>
int HashNode<K,T>::getOverflowAt(int index) {
  return overflow[index];
}

template<class K, class T>
void HashNode<K,T>::removeFromOverflow(int value) {
  std::vector<int>::iterator it = std::find(overflow.begin(), overflow.end(), value);
  // If element was found remove it
  if (it != overflow.end()) {
    // remove element from overflow vector 
    overflow.erase(overflow.begin()+(it - overflow.begin()));
  }
}



#endif // __HASH_NODE_H_