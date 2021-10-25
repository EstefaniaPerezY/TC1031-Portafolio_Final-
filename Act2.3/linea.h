#ifndef _LINEA_H
#define _LINEA_H
#include <iostream>
#include "dateTime.h"

class linea{
  
  private:
    std::string day, seg, min, hour;
    std::string month, ip, razon;
    dateTime fechaHora;
  
  public:

    //constructores
    linea();
    linea(std::string me, std::string di, std::string ho, std::string mi, std::string se, std::string ip, std::string razon, dateTime dt);
    
    // metodos de set
    void setMonth(std::string month);
    void setDay(std::string day);
    void setHour(std::string hour);
    void setMin(std::string min);
    void setSeg(std::string seg);
    void setIP(std::string ip);
    void setRazon(std::string razon);
    void setFechaHora(dateTime dt);

    //metodos get
    std::string getMonth();
    std::string getIP();
    std::string getRazon();
    std::string getDay();
    std::string getHour();
    std::string getMin();
    std::string getSeg();
    dateTime getFechaHora();
    std::string getAll();
};



#endif // _LINEA_H
