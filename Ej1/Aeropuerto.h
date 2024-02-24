

#ifndef AEROPUERTO_H_INCLUDED
#define AEROPUERTO_H_INCLUDED

#include <iostream>

using std::string;

class Aeropuerto {
    private:
        string IATA;
        string nombre;
        string ciudad;
        string pais;
        double area;
        int entero1;
        int entero2;
        int entero3;

    public:

        /**
         * Constructor
         * Genera una instancia de la
         * clase Aeropuerto
        */
        Aeropuerto(string IATA,string nombre,string ciudad,string pais,double area,int entero1,int entero2,int entero3);



};

#endif // AEROPUERTO_H_INCLUDED