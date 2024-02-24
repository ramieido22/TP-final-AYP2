
#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED

#include "Aeropuerto.h"

class Nodo {
    private:
        Nodo* hijo_izquierdo;
        Nodo* hijo_derecho;
        Nodo* padre;
        string clave;
        Aeropuerto* data;
    
    public:

        /**
         * Constructor
         * PRE: pasa el codigo IATA
        */
        Nodo(string IATA,Nodo* padre);

        /**
         * Constructor
         * PRE: pasa el codigo IATA, y los punteros
         * a los hijos derecho y izquierdo
        */
        Nodo(string IATA,Nodo* padre,Nodo* pn_izq,Nodo* pn_der);

        /**
         * POST: devuelve el nodo del 
         * hijo izquierdo
        */
        Nodo* obtenerHijoIzquierdo(void);

        /**
         * POST: devuelve el nodo del
         * hijo derecho
        */
        Nodo* obtenerHijoDerecho(void);

        /**
         * POST: devuelve el codigo del 
         * aeropuerto grabado en el nodo
        */
        string obtenerClave(void);

        /**
         * POST: devuelve los datos
         * del aeropuerto vinculado 
         * con el nodo
        */
        Aeropuerto* obtenerDatos(void);

        Nodo* obtenerPadre(void);

        /**
         * 
        */
        void cambiarClave(string IATA);

        void cambiarHijoDerecho(Nodo *pn);

        void cambiarHijoIzquierdo(Nodo *pn);

        void cambiarPadre(Nodo *pn);

        void desasignarHijo(Nodo *pn);

        /**
         * POST: elimina los
         * nodos vinculados al nodo
        */
        ~Nodo();
};

#endif // NODO_H_INCLUDED