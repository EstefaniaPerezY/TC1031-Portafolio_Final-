#ifndef _SUMMARY_H_
#define _SUMMARY_H_
#include <string>
using namespace std;

class Summary{
  public:
    Summary(); //Complejidad O(1)
    Summary(string ip); //Complejidad O(1)
    string getIP(); //Complejidad O(1)
    int getEntrances(); //Complejidad O(1)
    int getDepartures(); //Complejidad O(1)
    void printSummary(); //Complejidad O(1)
    void updateEntrances(); //Complejidad O(1)
    void updateDepartures(); //Complejidad O(1)
    
  private:
    string ip;
    int departures, entrances;
};


Summary::Summary(){
  this->ip = "unknown";
  this->departures = 0;
  this->entrances = 0;
}

Summary::Summary(string _ip){
  this->ip = _ip;
  this->departures = 0;
  this->entrances = 0;
}

string Summary::getIP(){
  return this->ip;
}

int Summary::getDepartures(){
  return this->departures;
}

int Summary::getEntrances(){
  return this->entrances;
}

void Summary::updateDepartures(){
  this->departures++;
}

void Summary::updateEntrances(){
  this->entrances++;
}

void Summary::printSummary(){
  std::cout << "IP: " << this-> ip << std::endl;
  std::cout << "Departures from IP: " << this-> departures << std::endl;
  std::cout << "Entrances to the IP: " << this-> entrances << std::endl;
}

#endif //_SUMMARY_H_