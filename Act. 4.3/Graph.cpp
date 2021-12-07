#include "Graph.h"

//Complejidad O(1)
Graph::Graph(std::string file) {  
  loadGraphList(file);      
}

//Complejidad O(1)
Graph::~Graph() {
  adjList.clear();
  ips.clear();
}

//Complejidad O(n^2)
int Graph::loadGraphList(std::string file) {
  std::ifstream infile;
  std::string line;
  std::pair<IP, IP> tmpPair;
  std::vector<std::pair<IP, IP>> lineas;
  std::string ipSource, ipFate;
  int i = 0;
  std::cout << "Abriendo el archivo '" << file << "'"<< std::endl;

  infile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
  try {infile.open(file);
  }catch(std::ifstream::failure e){
  std::cout << "WARN: El archivo '" << file << "' no ha abierto correctamente."<< std::endl;
  return 0;
  }
  //Complejidad O(n^2)
  while (!infile.eof()){
    getline(infile, line);
    //Complejidad O(n)
    if (i == 0){
      std::vector<int> out;
      //Complejidad O(n)
      split(line, out);
      numNodes = out[0];
      numEdges = out[1];
      //Complejidad O(n)
      adjList.resize(numNodes+1);
      
    }else if(i>0 && i<=numNodes){ //O(1)
      IP ipTemporal(line + ":0000");
      ips.push_back(ipTemporal);
      
    }else{  //O(n)
      std::vector<std::string> out;
      //Complejidad O(n)
      splitString(line, out);

      ipSource = out[3] + ":0000";
      ipFate = out[4] + ":0000";

      IP ipSrc(ipSource);
      IP ipFte(ipFate);

      tmpPair.first = ipSrc;
      tmpPair.second = ipFte;

      lineas.push_back(tmpPair);
    }i++;
  }
  infile.close(); 
  //Complejidad O(1)
  if(infile.is_open()){
    std::cout << "WARN: El archivo '" << file << "' no ha cerrado correctamente." << std::endl;
  }

  //Complejidad O(nlogn)
  quickSort(ips, 0, ips.size()-1);
  
  int origen, destino;
  
  //Complejidad O(nlogn)
  for(int i = 0; i < lineas.size(); i++){
    //Complejidad O(logn)
    origen = binarySearch(ips, ips.size(), lineas[i].first);
    //Complejidad O(logn)
    destino = binarySearch(ips, ips.size(), lineas[i].second);
    adjList[origen].push_back(destino);
    ips[origen].addToDegree(); 
  }

  MaxHeap<IP> maxDegrees(13371);

  //Complejidad O(n)
  for (int i = 0; i < ips.size(); i++){
    maxDegrees.push(ips[i]);
  }

  //Complejidad O(nlogn)
  maxDegrees.heapSort();
  //Complejidad O(n)
  maxDegrees.createDegreesBinnacle("grados_ips.txt", 0, 
  maxDegrees.getSize() - 1);
  //Complejidad O(logn)
  maxDegrees.connections("mayores_grados_ips.txt");
  return 1;
}

//Complejidad O(1)
void Graph::swap(IP* a, IP* b){
  IP t = *a;
  *a = *b;
  *b = t;
}

//Complejidad O(n)
int Graph::partition(std::vector<IP> &arr, int low, int high){
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

//Complejidad O(n)
//split vector tipo int
void Graph::split(std::string line, std::vector<int> &out){
  size_t first = line.find(" ");
  size_t last = 0;
  //Complejidad O(n)
  while (first != std::string::npos){
    out.push_back(stoi(line.substr(last, first - last)));
    last = first + 1;
    first = line.find(" ", last);
  }
  out.push_back(stoi(line.substr(last, line.size() - last)));
}

//Complejidad O(n)
//split vector tipo string
void Graph::splitString(std::string line, std::vector<std::string> &out) {
  size_t first = line.find(" ");
  size_t last = 0;
  while (first != std::string::npos) {
    out.push_back(line.substr(last, first - last));
    last = first + 1;
    first = line.find(" ", last);
  }
  out.push_back(line.substr(last, line.size() - last));
}

//Complejidad O(n^2)
void Graph::printGraph(){
	  std::cout << "-----Adjacency List-----" << std::endl;
    //Complejidad O(n^2)
		for (int i = 0; i < numNodes; i++){
      std::cout << "Vertex " << i << ": ";
      for (int j = 0; j < (int)adjList[i].size(); j ++){
        std::cout << " " << adjList[i][j];
      }
      std::cout << std::endl;
    }
}

//Complejidad O(n)
int Graph::binarySearch(std::vector<IP> reg, int n, IP tmp) {
  int low = 0;
  int high = n - 1;
  //Complejidad O(n)
  while (low <= high) {
    int i = low + (high - low) / 2;
    if (tmp.getIpInt() == reg[i].getIpInt()){
      return i;
    }else if (tmp.getIpInt() < reg[i].getIpInt()) {
      high = i - 1;
    }else{
      low = i + 1;
    }
  }
  return -1;
}

//Complejidad O(nlogn)
void Graph::quickSort(std::vector<IP> &arr, int low, int high){
  if (low < high){
    int pi = partition(arr, low, high);
    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
  }
}