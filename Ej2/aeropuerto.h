#ifndef AEROPUERTO_H      
#define AEROPUERTO_H

#include <iostream>

using namespace std;

class Aeropuerto {
private:
    //Atributos
    string codigo_IATA;
    string nombre;
    string ciudad;
    string pais;
    float superficie;
    int cantidad_terminales;
    int destinos_nacionales;
    int destinos_internacionales;

public:
    //Metodos

    //Constructor
    Aeropuerto(string codigo_IATA, string nombre, string ciudad, string pais, float superficie, int cantidad_terminales, int destinos_nacionales, int destinos_internacionales);

    //pre:
    //post:
    string ver_codigo_IATA();

    //pre:
    //post:
    string ver_nombre();
    
    //pre:
    //post:
    string ver_ciudad();
    
    //pre:
    //post:
    string ver_pais();
    
    //pre:
    //post:
    float ver_superficie();
    
    //pre:
    //post:
    int ver_cantidad_terminales();
    
    //pre:
    //post:
    int ver_destinos_nacionales();
    
    //pre:
    //post:
    int ver_destinos_internacionales();
    
    //pre:
    //post:
    void imprimir();
};

#endif // AEROPUERTO_H