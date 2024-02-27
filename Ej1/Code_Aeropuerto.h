
#ifndef CODE_H_INCLUDED
#define CODE_H_INCLUDED

#include <iostream>

using std::string;

/**
 * Item que contiene
 * al codigo IATA y el
 * nombre de la ciudad
*/
class Code_Aeropuerto
{
private:
    
    string IATA;
    string ciudad;
public:

    Code_Aeropuerto() = default;

    /**
     * Constructor que tiene grabado
     * la vinculación del codigo IATA
     * con el nombre de la ciudad
    */
    Code_Aeropuerto(string codigo,string nombre_ciudad);

    string obtenerIATA(void);

    string obtenerCiudad(void);

    void cambiarIATA(string codigo);

    void cambiarCiudad(string nombre_ciudad);

    bool operator==(Code_Aeropuerto otro_objeto);
    
};


#endif // CODE_H_INCLUDED