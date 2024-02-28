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
    //post: Devuelve el codigo IATA del aeropuerto
    string ver_codigo_IATA();

    //pre:
    //post: Devuelve el nombre del aeropuerto
    string ver_nombre();
    
    //pre:
    //post: Devuelve la ciudad del aeropuerto
    string ver_ciudad();
    
    //pre:
    //post: Devuelve el pais del aeropuerto
    string ver_pais();
    
    //pre:
    //post: Devuelve la superficie del aeropuerto
    float ver_superficie();
    
    //pre:
    //post: Devuelve la cantidad de terminales del aeropuerto
    int ver_cantidad_terminales();
    
    //pre:
    //post: Devuelve la cantidad de destinos nacionales del aeropuerto
    int ver_destinos_nacionales();
    
    //pre:
    //post: Devuelve la cantidad de destinos internacionales del aeropuerto
    int ver_destinos_internacionales();
    
    //pre:
    //post: Imprime por pantalla los datos del aeropuerto
    void imprimir();
};

#endif // AEROPUERTO_H