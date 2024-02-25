

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

        /**
         * POST: devuelve el codigo de IATA
        */
        string obtenerIATA();

        /**
         * POST: devuelve el nombre del
         * Aeropuerto
        */
        string obtenerNombre();
        
        /**
         * POST: devuelve el nombre de
         * la ciudad del aeropuerto
        */
        string obtenerCiudad();

        /**
         * POST: devuelve el nombre de
         * del pais donde esta ubicado el
         * aeropuerto
        */
        string obtenerPais();

        /**
         * POST: devuelve la area del
         * aeropuerto
        */
        double obtenerArea();

        /**
         * POST: devuelve la cantidad
         * de terminales del aeropuerto
        */
        int obtenerCantidadTerminales();

        /**
         * POST: devuelve la cantidad
         * de destinos nacionales
        */
        int obtenerDestinosNacionales();

        /**
         * POST: devuelve la cantidad
         * de destinos internacionales
        */
        int obtenerDestinosInternacionales();

        bool operator==(const Aeropuerto &d);
};

#endif // AEROPUERTO_H_INCLUDED