
#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include "Nodo_L.h"

template <typename Dato>
class Pila {

    /**
     * Referencia al nodo que se encuentra
     * al principio de la pila
    */
    Nodo_L<Dato>* tope;

    /**
     * La cantidad de nodos grabados
     * en la pila
    */
    int cant_elem;

    public:
        
        /**
         * Crea una instancia de una
         * Pila dinamica
        */
        Pila();

        /**
         * POST: da de alta un nuevo elemento en
         * la pila 
         * (ATENCION:Lo da de alta al principio debido a las reglas
         * de esa estructura)
        */
        void alta(Dato d);

        /**
         * POST: da de baja un nuevo elemento en
         * la pila , si la pila esta vacia no hace nada
         * pero no se recomienda ejecutar antes de saber si
         * la pila es vacia o no
         * (ATENCION:Lo da de baja al principio debido a las reglas
         * de esa estructura)
        */
        void baja();

        /**
         * PRE: la pila no debe estar vacia
         * POST: devuelve el dato del nodo que esta
         * al prinicipio de la pila
        */
        Dato consulta();

        /**
         * POST: devuelve la cantidad de nodos
         * o elementos que tiene la pila
        */
        bool es_vacia();

        /**
         * Destructor
         * Libera toda la memoria reservada
         * para los nodos de la pila
        */
        ~Pila();
};

template <typename Dato>
Pila<Dato>::Pila(){
    this->tope = nullptr;
    this->cant_elem = 0;
}

template <typename Dato>
void Pila<Dato>::alta(Dato d){
    Nodo_L<Dato>* nuevo = new Nodo_L<Dato>(d);
    if ( this->tope == nullptr ){
        this->tope = nuevo;
    } else {
        nuevo->cambiarSiguiente(this->tope);
        this->tope = nuevo;
    }
    //
    this->cant_elem++;
}

template <typename Dato>
void Pila<Dato>::baja(){
    if ( this->tope != nullptr ){
        Nodo_L<Dato>* borrar = this->tope;
        //
        this->tope = this->tope->obtenerSiguiente();
        delete borrar;
        this->cant_elem--;
    }
}

template <typename Dato>
Dato Pila<Dato>::consulta(){
    return (this->tope->obtenerDato());
}

template <typename Dato>
bool Pila<Dato>::es_vacia(){
    return (this->cant_elem == 0);
}

template <typename Dato>
Pila<Dato>::~Pila(){
    while ( !this->es_vacia() ){
        this->baja();
    }
}

#endif // LISTA_H_INCLUDED