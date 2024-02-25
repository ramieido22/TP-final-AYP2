#ifndef TABLA_IATA_H
#define TABLA_IATA_H

#include <iostream>
using namespace std;

class Tabla_iata
{
private:

    //Atributos
    struct Ciudad_iata{ //Utilizo un par (ciudad, codigo_iata) para poder vincularlo despues en el programa.
        string ciudad;
        string codigo_iata;
    };
    Ciudad_iata*  tabla;
    int tamanio;
    int capacidad;
    
    //Metodos
    //pre: -
    //post: resimensiona la tabla al doble de su capacidad
    void redimensionar();

public:
    //Constructor
    Tabla_iata();

    //Metodos

    //pre: -
    //post: agrega una ciudad con su respectivo codigo iata
    void agregar_ciudad_iata(string ciudad, string codigo_iata);

    //pre: -
    //post: devuelve true si la ciudad esta en la tabla, false en caso contrario
    bool pertenece(string ciudad);

    //pre: -
    //post: elimina la ciudad de la tabla
    void eliminiar(string ciudad);

    //pre: -
    //post: devuelve el codigo iata de la ciudad
    string buscar_iata (string ciudad);

    //Destructor
    ~Tabla_iata();
};
#endif // TABLA_IATA_H