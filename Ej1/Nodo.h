
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
         * Constructor de copia
        */
        Nodo(const Nodo* pn);

        /**
         * POST: devuelve el nodo padre
         * del nodo dado
        */
        Nodo* obtenerPadre(void);

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

        /**
         * PRE: pasar el nuevo codigo IATA
         * POST: cambiar la clave por 
         * el codigo pasado
        */
        void cambiarClave(string IATA);

        /**
         * PRE: pasar el nuevo hijo derecho
         * POST: se establece el nodo parametro
         * pasado como hijo derecho del nodo
        */
        void cambiarHijoDerecho(Nodo *pn);

        /**
         * PRE: pasar el nuevo hijo izquierdo
         * POST: se establece el nodo parametro
         * pasado como hijo izquierdo del nodo
        */
        void cambiarHijoIzquierdo(Nodo *pn);

        /**
         * PRE: pasar el nuevo padre
         * POST: se establece el nodo parametro
         * pasado como padre del nodo
        */
        void cambiarPadre(Nodo *pn);

        /**
         * PRE: pasar como parametro 
         * la nueva referencia de datos
         * POST: se establece la referencia
         * como referencia a los datos del puntero
        */
        void cambiarDato(Aeropuerto* pn);

        /**
         * POST: si el nodo de parametro 
         * es uno de los hijos del nodo ,
         * entonces se desasigna de su
         * posicion como hijo, si no 
         * no se cambia nada en el nodo
        */
        void desasignarHijo(Nodo *pn);

        /**
         * Destructor
         * POST: elimina los
         * nodos vinculados al nodo
        */
        ~Nodo();
};

#endif // NODO_H_INCLUDED