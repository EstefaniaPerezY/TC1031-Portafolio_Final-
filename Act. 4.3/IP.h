#ifndef _IP_H_
#define _IP_H_

#include <iostream>
#include <string>
using namespace std;

class IP {
    public:
        IP(); //Complejidad O(1)
        IP(string);//Complejidad O(1)
        string getIp();//Complejidad O(1)
        string getSimpleIP();//Complejidad O(1)
        long int getIpInt();//Complejidad O(1)
        int getDegree();//Complejidad O(1)
        void setDegree(int);//Complejidad O(1)
        void addToDegree();//Complejidad O(1)
        bool operator ==(IP&);//Complejidad O(1)
        bool operator !=(IP&);//Complejidad O(1)
        bool operator >(IP&);//Complejidad O(1)
        bool operator <(IP&);//Complejidad O(1)
        bool operator >=(IP&);//Complejidad O(1)
        bool operator <=(IP&);//Complejidad O(1)
    private:
        string ip;
        string ipSimple;
        int oct[4];
        long int decimal;
        int degree;
};




#endif // _IP_H_