
#ifndef ABMAEROPUERTOS_H_INCLUDED
#define ABMAEROPUERTOS_H_INCLUDED

#include "ABB.h"
#include "Menu.h"
#include "Aeropuerto.h"
#include "Lista.h"
#include "Code_Aeropuerto.h"


class ABM {
    private:

        /**
         * Arbol donde se graban los
         * codigos IATA y una referencia
         * a los datos
        */
        ABB<string,Aeropuerto> aeropuertos;

        /**
         * Tabla de ciudad y codigo IATA,
         * donde se realiza la busqueda para
         * obtener el codigo IATA a traves de la
         * ciudad
        */
       Lista<Code_Aeropuerto> ciudad_IATA;
        
        /**
         * Pila en donde se graban los datos que
         * se levantaron de la base de datos
        */
        Lista<Aeropuerto*> datos_aeropuertos;

        /**
         * El menu del ABM que se
         * muestra al usuario para que
         * interactue con los datos
        */
        Menu menu_usuario;

        /**
         * POST: devuelve la cantidad de datos de
         * aeropuertos que tiene el ABM
        */
        int cantidad();

        /**
         * Pregunta al usuario si desea cancelar
         * alguna de las operaciones que esta haciendo
         * POST: devuelve true si el usuario desea cancelar
         * y false si el usuario no desea cancelar
        */
        bool cancelarOperacion();

        /**
         * PRE: hay que pasar como parametro una referencia 
         * a una cadena
         * POST: se almacena en la cadena pasado como parametro
         * la ciudad cargada por el usuario
        */
        void preguntarCiudad(string &ciudad);
        
    public:

        /**
         * Constructor del ABM
         * lee los datos de la base de datos
         * (el archivo) para iniciar el 
         * ABM
        */
        ABM();

        /**
         * Metodo que incia el menu de administración
         * para que el usuario pueda interactuar con
         * los datos
        */
        void administrar();

        /**
         * Metodo que da de alta un
         * nuevo aeropuerto (los datos)
         * los carga el usuario
         * POST: se da de alta un nuevoaeropuerto
        */
        void alta();

        /**
         * Metodo que consulta los
         * datos de un aeropuerto especifico
         * (la busqueda es por nombre de ciudad)
         * POST: se muestran los datos del aeropuerto,
         * en caso de no encontrarlo permite cancelar la busqueda
        */
        void consulta();

        void consultaGeneral();

        /**
         * Metodo que da de baja un
         * aeropuerto , el aeropuerto
         * es elegido por el usuario
         * POST: se da de baja el aeropuerto solicitado
         * por el usuario
        */
        void baja();

        /**
         * Destructor
         * Sobreescribe los datos de
         * la base de datos con los datos
         * de la ABM
        */
        ~ABM();
};

#endif // ABMAEROPUERTOS_H_INCLUDED