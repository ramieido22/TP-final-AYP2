
#ifndef ABB_H_INCLUDED
#define ABB_H_INCLUDED

#include "Nodo.h"
#include "Aeropuerto.h"

class ABB {
    private:
        Nodo* raiz;
        int cantidad_elementos;

        /**
         * PRE: pasar el nodo a traves del cual se 
         * va a comenzar la busqueda y el dato a buscar
         * POST: devuelve el nodo si el dato existe y NULL si no
        */
        Nodo* buscar(Nodo* nodo,string dato);

        /**
         * PRE: pasar el nodo a traves del cual se 
         * va a comenzar la insercion y el dato a insertar
         * POST: el dato sera insertado si ya no esta presente en el arbol
        */
        Nodo* insertar(Nodo* nodo,string dato);

        /**
         * PRE: pasar el nodo lo cual se quiere eliminar
         * POST: el nodo sera eliminado si se encuentra
        */
        void eliminarHoja(Nodo* nodo);

        /**
         * POST: devuelve el nodo con el dato mas grande
         * comparado con el dato del nodo pasado como parametro
        */
        Nodo* obtenerInmediatoPredecesor(Nodo *nodo);

        /**
         * POST: devuelve el nodo con el dato mas chico
         * comparado con el dato del nodo pasado como parametro
        */
        Nodo* obtenerInmediatoSucesor(Nodo *nodo);

        /**
         * PRE: El nodo dado no debe ser null
         * POST: devuelve la altura del nodo en el arbol
        */
        int calcularAltura(Nodo *nodo,int altura);
    public:

        /**
         * Constructor de la clase
        */
        ABB();

        /**
         *  PRE: el dato aeropuerto debe
         * estar cargado en el arbol
         * POST: la altura del nodo 
         * cargado
        */
        int altura(string dato);

        /**
         * POST: devuelve true si el dato
         * se encuentra en el arbol y false si no
        */
        bool estaEnArbol(string dato);

        /**
         * PRE: pasa la clave del nodo como
         * parametro
         * POST: obtener el dato grabado en
         * el nodo
        */
        Aeropuerto* obtenerDato(string dato);

        /**
         * PRE: debe ser un dato que
         * no existe en el arbol binario
         * POST: devuelve true si el nodo se inserta con exito y false si no
        */
        bool insertar(string clave,Aeropuerto* datos);

        /**
         * PRE: el elemento dado debe estar en el arbol
         * POST: devuelve true si el nodo se elimina con exito y false si no
        */
        bool eliminar(string dato);

        /**
         * POST: devuelve la cantidad
         * de nodos que tiene el ABB
        */
        int cantidad();

        /**
         * Destructor de la clase
        */
        ~ABB();
};


#endif // ABB_H_INCLUDED