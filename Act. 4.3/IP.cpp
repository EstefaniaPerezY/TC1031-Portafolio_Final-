#include<cmath> 
#include "IP.h"

//Complejidad O(1)
IP::IP() {
    ip = "unknown";
    ipSimple = "unknown";
    degree = 0;
}

//Complejidad O(1)
IP::IP(std::string _ip) {
  ip = _ip;
  int first = ip.find(":");
  ipSimple = ip.substr(0, first);
  std::string temporal = ipSimple;
  degree = 0;
  //Complejidad O(1)
  for(int i = 0; i < 4; i++){
    int separador = ipSimple.find(".");
    std::string temp = ipSimple.substr(0, separador);
    oct[i] = std::stoi(temp);
    temp = ipSimple.substr(0, separador + 1);
    ipSimple = ipSimple.substr(temp.length(), ipSimple.length());
  }
  ipSimple = temporal;
  decimal = oct[0]*std::pow(256,3) + oct[1]*std::pow(256,2) + oct[2]*std::pow(256,1) + oct[3]*std::pow(256,0);
    
}

//Complejidad O(1)
string IP::getIp() {
  return ip;
}

//Complejidad O(1)
void IP::setDegree(int g){
  degree = g;
}

//Complejidad O(1)
void IP::addToDegree(){
  degree++;
}

//Complejidad O(1)
int IP::getDegree(){
  return degree;
}

//Complejidad O(1)
std::string IP::getSimpleIP() {
    return ipSimple;
}

//Complejidad O(1)
long int IP::getIpInt(){
  return decimal;
}

//Complejidad O(1)
bool IP::operator==(IP &other) {
  return decimal == other.getIpInt();
}

//Complejidad O(1)
bool IP::operator!=(IP &other) {
  return decimal != other.getIpInt();
}

//Complejidad O(1)
bool IP::operator>(IP &other) {
  return decimal > other.getIpInt();
}

//Complejidad O(1)
bool IP::operator<( IP &other) {
  return decimal < other.getIpInt();
}

//Complejidad O(1)
bool IP::operator>=( IP &other) {
  return decimal >= other.getIpInt();
}

//Complejidad O(1)
bool IP::operator<=( IP &other) {
  return decimal <= other.getIpInt();
}