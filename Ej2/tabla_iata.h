#ifndef TABLA_IATA_H
#define TABLA_IATA_H

#include <iostream>
using namespace std;

class Tabla_iata
{
private:
    //Atributos
    struct Ciudad_iata{
        string ciudad;
        string codigo_iata;
    };
    Ciudad_iata*  tabla;
    int tamanio;
    int capacidad;
    
    //Metodos
    void redimensionar();

public:
    Tabla_iata();

    void agregar_ciudad_iata(string ciudad, string codigo_iata);

    bool pertenece(string ciudad);

    void eliminiar(string ciudad);

    string buscar_iata (string ciudad);

    ~Tabla_iata();
};
#endif // TABLA_IATA_H