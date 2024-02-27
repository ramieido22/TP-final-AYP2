
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

    /**
     * Constructor que crea una
     * instancia de la vinculación
     * ciudad y codigo IATA
    */
    Code_Aeropuerto() = default;

    /**
     * Constructor que tiene grabado
     * la vinculación del codigo IATA
     * con el nombre de la ciudad
    */
    Code_Aeropuerto(string codigo,string nombre_ciudad);

    /**
     * POST: Devuelve el codigo IATA
     * de la vinculación
    */
    string obtenerIATA(void);

    /**
     * POST: Devuelve el nombre de
     * la ciudad de la vinculación
    */
    string obtenerCiudad(void);

    /**
     * PRE: pasar el nuevo codigo IATA
     * POST: se cambia el codigo IATA al pasado
    */
    void cambiarIATA(string codigo);

    /**
     * PRE: pasar el nuevo nombre de la ciudad
     * POST: se cambia el nombre de la ciudad al pasado
    */
    void cambiarCiudad(string nombre_ciudad);

    /**
     * Sobrecarga del operador de igualdad
     * que compara dos objetos y indica que
     * son iguales si el nombre de la ciudad
     * es igual
    */
    bool operator==(Code_Aeropuerto otro_objeto);
    
};


#endif // CODE_H_INCLUDED