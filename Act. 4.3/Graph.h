#ifndef __GRAPH_H_
#define __GRAPH_H_
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <exception>
#include "IP.h"
#include "MaxHeap.h"

class Graph {
  private:
    int numNodes;
    int numEdges;

    std::vector<IP> ips;
    std::vector<std::vector<int>> adjList;
    
    int loadGraphList(std::string file); //Complejidad O(n^2)
    void split(std::string line, std::vector<int> &out); //Complejidad O(n)
    void splitString(std::string line, std::vector<std::string>  &out); //Complejidad O(n)
    void quickSort(std::vector<IP> &arr, int low, int high);//Complejidad O(nlogn)
    void swap(IP* a, IP* b); //Complejidad O(1)
    int binarySearch(std::vector<IP> reg, int n, IP tmp); //Complejidad O(n)
    int partition(std::vector<IP> &arr, int low, int high);//Complejidad O(n)
  public:
    Graph(std::string file);//Complejidad O(1)
    ~Graph();//Complejidad O(1)
    void printGraph();//Complejidad O(n^2)
};

#endif