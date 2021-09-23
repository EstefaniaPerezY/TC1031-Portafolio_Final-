#include "linea.h"
#include  <string>

using namespace std;

//constructor vacio
linea::linea(){
  
}
//constructor con parámetros
linea::linea(string me, string di, string ho, string mi, string se, string ip, string razon, dateTime dt) {
  this->month = me;
  this->day = di;
  this->hour = ho;
  this->min = mi;
  this->seg = se;
  this->ip = ip;
  this->razon = razon;
  this->fechaHora = dt;  
}

//Setters
void linea::setMonth(string month){
  this->month = month;
}

void linea::setIP(string ip){
  this->ip = ip;
}

void linea::setRazon(string razon){
  this->razon = razon;
}

void linea::setDay(string day){
  this->day = day;
}

void linea::setHour(string hour){
  this->hour = hour;
}

void linea::setSeg(string seg){
  this->seg = seg;
}

void linea::setMin(string min){
  this->min = min;
}

void linea::setFechaHora(dateTime dt) {
  this->fechaHora = dt;
}


//Getters
std::string linea::getMonth(){
  return this->month;
}

std::string linea::getIP(){
  return this->ip;
}

std::string linea::getRazon(){
  return this->razon;
}

string linea::getDay(){
  return this->day;
}

string linea::getHour(){
  return this->hour;
}

string linea::getMin(){
  return this->min;
}

string linea::getSeg(){
  return this->seg;
}

dateTime linea::getFechaHora() {
  return this->fechaHora;
}


//concatena con formato los atributos de linea
string linea::getAll() {
  string tmpR = this->month + " " + this->day + " " +
  this->hour + ":" + this->min + ":" + this->seg + " " + this->ip + " " + this->razon; // + " " + to_string(this->fechaHora);  
  return tmpR;
}
