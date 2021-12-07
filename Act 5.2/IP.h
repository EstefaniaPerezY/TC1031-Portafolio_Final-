#ifndef _IP_H_
#define _IP_H_
#include <iostream>
#include <string>
#include <math.h>
#include "Summary.h"
using namespace std;

class IP{
  public:
    IP();
    IP(int oct1, int oct2, int oct3, int oct4, string puerto); //Complejidad O(1)
    Summary getSummary(); //Complejidad O(1)
    long getDecimal();//Complejidad O(1)
    void updateSummaryDepartures(); //Complejidad O(1)
    void updateSummaryEntrances(); //Complejidad O(1)
    void setAdjIP(std::vector<IP> adj); //Complejidad O(1)
    std::vector<IP> getIPvect(); //Complejidad O(1)
    bool operator ==(IP&); //Complejidad O(1)
    bool operator >(IP&); //Complejidad O(1)
    bool operator <(IP&); //Complejidad O(1)
    bool operator <=(IP&); //Complejidad O(1)
    friend ostream& operator<<(ostream& os, const IP& ip); //Complejidad O(1)
  private:
    int oct1, oct2, oct3, oct4;
    long decimal;
    std::vector<IP> adjIP;
    string puerto;
    Summary res;
};

IP::IP(){
  IP(0, 0, 0, 0, "unknown");
}

IP::IP(int oct1, int oct2, int oct3, int oct4, string puerto){
  this->oct1 = oct1;
  this->oct2 = oct2;
  this->oct3 = oct3;
  this->oct4 = oct4;
  this->puerto = puerto;
  string ip = to_string(oct1) + "." + to_string(oct2) + "." + to_string(oct3) + "." + to_string(oct4);
  this->res = Summary(ip);
  this->decimal = (oct1*pow(256,3)) + 
                  (oct2*pow(256,2)) + 
                  (oct3*pow(256,1)) + 
                  (oct4*pow(256,0));
}

Summary IP::getSummary(){
  return this->res;
}

long IP::getDecimal(){
  return this->decimal;
}

void IP::updateSummaryDepartures(){
  this->res.updateDepartures();
}

void IP::updateSummaryEntrances(){
  this->res.updateEntrances();
}

void IP::setAdjIP(std::vector<IP> adj){
  this->adjIP = adj;
}

std::vector<IP> IP::getIPvect(){
  return this->adjIP;
}

bool IP::operator==(IP& other){
  return this-> getDecimal() == other.getDecimal();
}

bool IP::operator>(IP& other){
  return this-> getDecimal() > other.getDecimal();
}

bool IP::operator<(IP& other){
  return this-> getDecimal() < other.getDecimal();
}

bool IP::operator<=(IP& other){
  return this -> getDecimal() <= other.getDecimal();
}

ostream& operator<<(ostream& os, const IP& ip){
  os << to_string(ip.oct1) + "." + to_string(ip.oct2) + "." + to_string(ip.oct3) + "." + to_string(ip.oct4);
  return os;
}

#endif //_IP_H_