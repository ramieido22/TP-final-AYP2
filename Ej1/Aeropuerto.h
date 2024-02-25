

#ifndef AEROPUERTO_H_INCLUDED
#define AEROPUERTO_H_INCLUDED

#include <iostream>
#include <fstream>

using std::string;

class Aeropuerto {
    private:
        string IATA;
        string nombre;
        string ciudad;
        string pais;
        double area;
        int cantidad_terminales;
        int destinos_nacionales;
        int destinos_internacionales;

    public:

        Aeropuerto() = default;

        /**
         * Constructor
         * Genera una instancia de la
         * clase Aeropuerto
        */
        Aeropuerto(string IATA,string nombre,string ciudad,string pais,double area,int cantidad_terminales,int destinos_nacionales,int destinos_internacionales);

        /**
         * POST: imprime los datos del
         * aeropuerto por pantalla
        */
        void mostrarDatos();

        string obtenerIATA();

        string obtenerNombre();
        
        string obtenerCiudad();

        string obtenerPais();

        double obtenerArea();

        int obtenerCantidadTerminales();

        int obtenerDestinosNacionales();

        int obtenerDestinosInternacionales();
};

#endif // AEROPUERTO_H_INCLUDED