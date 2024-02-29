#ifndef VUELO_H_INCLUDED
#define VUELO_H_INCLUDED

#include <string>

using namespace std;

class Vuelo {
private:
    string codigoIATA;
    string nombreAeropuerto;
    string ciudad;
    string pais;
public:
    //post: Crea vuelo, dandole toda la informacion
    Vuelo(string codigoIATA, string nombreAeropuerto, string ciudad, string pais);

    //post: devuelve el codigo IATA
    string obtenerCodigoIATA();

    //post: devuelve el nombre del aeropuerto
    string obtenerNombreAeropuerto();

    //post: devuelve la ciudad
    string obtenerCiudad();

    //post: devuelve el pais
    string obtenerPais();

    //post: libera la memoria
    ~Vuelo();
};

#endif // VUELO_H_INCLUDED
