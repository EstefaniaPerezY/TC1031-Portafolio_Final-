#ifndef __GRAPH_H_
#define __GRAPH_H_
#include <vector>
#include <fstream>
#include <utility> 
#include <exception>
#include "IP.h"
#include "HashTable.h"

class Graph {
  private:
    int numNodes;
    int numEdges;
    void heapSort(); //Complejidad O(nlogn)
    void heapify(int n, int i); //Complejidad O(n)
    int binarySearch(IP search); //Complejidad O(n)
    void loadGraphList(string file); //Complejidad O(n)
    vector<pair<IP,vector<IP>>> adjList; 
  public:
    Graph(string file); //Complejidad O(n)
    ~Graph(); //Complejidad O(n)
    vector<pair<IP,vector<IP>>> getAdjList(); //Complejidad O(1)
};
Graph::Graph(string file) {
    loadGraphList(file);
}

Graph::~Graph() {
  adjList.clear();
}

void Graph::loadGraphList(string file) {
  std::ifstream infile;
  std::string stringNumEdges;
  std::string stringNumNodes;
  std::vector<IP> adjacencyIPVect;
  int ip1, ip2, ip3, ip4;
  int ipFate1, ipFate2, ipFate3, ipFate4;
  std::string mes, dia, hora, min, seg;
  std::string ip1String, ip2String, ip3String, ip4String, ipFate1String, ipFate2String, ipFate3String, ipFate4String, port, port2, failure;
  int i = 0;
  
  std::cout << "--->Opening file" << std::endl;  
  infile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
  try {infile.open(file);
  }catch(std::ifstream::failure e){
  std::cout << "--->WARNING the file hasn´t been opened correctly"<< std::endl;
  }
  std::cout << "--->File opened successfully" << std::endl;
  while (!infile.eof()){
    if(i == 0){
      getline(infile, stringNumNodes, ' ');
      getline(infile, stringNumEdges, '\n');
      this->numNodes = stoi(stringNumNodes);
      this->numEdges = stoi(stringNumEdges);
      i++;
      continue;
    }else if(i>0 && i<=numNodes){
      getline(infile, ip1String, '.');
      getline(infile, ip2String, '.');
      getline(infile, ip3String, '.');
      getline(infile, ip4String, '\n');
      ip1 = stoi(ip1String);
      ip2 = stoi(ip2String);
      ip3 = stoi(ip3String);
      ip4 = stoi(ip4String);
      IP ip(ip1,ip2,ip3,ip4,"0");
      adjList.push_back(make_pair(ip,adjacencyIPVect));
      i++;
      continue; 
    }
    if(i == numNodes+1){
      heapSort();
    }
    getline(infile, mes, ' ');
    getline(infile, dia, ' ');
    getline(infile, hora, ':');
    getline(infile, min, ':');
    getline(infile, seg, ' ');
    getline(infile, ip1String, '.');
    getline(infile, ip2String, '.');
    getline(infile, ip3String, '.');
    getline(infile, ip4String, ':');
    getline(infile, port, ' ');
    getline(infile, ipFate1String, '.');
    getline(infile, ipFate2String, '.');
    getline(infile, ipFate3String, '.');
    getline(infile, ipFate4String, ':');
    getline(infile, port2, ' ');
    getline(infile, failure);

    ip1 = stoi(ip1String);
    ip2 = stoi(ip2String);
    ip3 = stoi(ip3String);
    ip4 = stoi(ip4String);
    ipFate1 = stoi(ipFate1String);
    ipFate2 = stoi(ipFate2String);
    ipFate3 = stoi(ipFate3String);
    ipFate4 = stoi(ipFate4String);

    IP ipSouce(ip1, ip2, ip3, ip4, port);
    IP ipFate(ipFate1, ipFate2, ipFate3, ipFate4, port2);

    int pos = binarySearch(ipSouce);
    int pos2 = binarySearch(ipFate);
    adjList[pos].second.push_back(ipFate);
    adjList[pos].first.updateSummaryDepartures();
    adjList[pos2].first.updateSummaryEntrances();
    
    i++;
  }
  infile.close();

  if(!infile.is_open()){
  std::cout << "--->The file has been closed correctly" << std::endl;
  }if(infile.is_open()){
  std::cout << "--->WARNING the file hasn't been closed correctly" << std::endl;
  }

}

vector<pair<IP,vector<IP>>> Graph::getAdjList(){
  return this->adjList;
}

void Graph::heapify(int size, int i){
  int largest = i;
  int l = 2*i+1;
  int r = 2*i+2;
  if (l < size && adjList[l].first > adjList[largest].first)
    largest = l;
  if (r < size && adjList[r].first > adjList[largest].first)
    largest = r;
  if (largest != i){
    swap(adjList[i], adjList[largest]);
    heapify(size, largest);
  }
}

void Graph::heapSort(){
  int size = numNodes;
  for (int i = size/2-1; i >= 0; i--)
    heapify(size, i);
    
  for (int i = size-1; i >= 0; i--){
    swap(adjList[0], adjList[i]);
    heapify(i, 0);
  }
}

int Graph::binarySearch(IP search){
  int low = 0, high = numNodes - 1;
  while (low <= high){
    int m = low + (high - low) / 2;
    if (search == adjList[m].first){
      return m;
    }else if (search < adjList[m].first){
      high = m - 1;
    }else {
      low = m + 1;
    }
  }
  return -1;
}

#endif // __GRAPH_H_