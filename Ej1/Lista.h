
#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include "Nodo_L.h"

template <typename Dato>
class Lista {

    /**
     * Referencia al nodo primer nodo
     * de la lista
    */
    Nodo_L<Dato>* primero;

    /**
     * Referencia al nodo primer nodo
     * de la lista
    */
    Nodo_L<Dato>* cursor;

    /**
     * La cantidad de nodos grabados
     * en la lista
    */
    int cant_elem;

    /**
     * PRE: pasar la posición del nodo a buscar (0 < posicion <= cant_elem)
     * POST: devuelve el nodo buscado
    */
    Nodo_L<Dato>* obtenerNodo(int posicion);

    public:
        
        /**
         * Crea una instancia de una
         * Lista simplemente enlazada dinamica
        */
        Lista();

        /**
         * PRE: La posicion debe estar entre (0 < posicion <= cant_elem)
         * POST: se da de alta el nodo de esa posicion de la lista
        */
        void alta(Dato d,int posicion);

        /**
         * PRE: La posicion debe estar entre (0 < posicion <= cant_elem)
         * POST: se da de baja el nodo de esa posicion de la lista
        */
        void baja(int posicion);

        /**
         * PRE: la pila no debe estar vacia (0 < posicion <= cant_elem)
         * POST: devuelve el dato del nodo que esta
         * al prinicipio de la lista
        */
        Dato buscarDato(int posicion);

        /**
         * PRE: enviar el dato a buscar
         * POST: devuelve la posicion del nodo
         * que almacena el dato en la lista si
         * no devuelve 0
        */
        int buscarPosicion(Dato d);

        /**
         * POST: devuelve la cantidad de nodos
         * o elementos que tiene la lista
        */
        bool esVacia();
        
        /**
         * POST: reinicia el cursor apuntandolo
         * al primer nodo de la lista
        */
        void reiniciarCursor();

        /**
         * PRE: el cursor tiene no tiene que estar
         * en la ultima posición
         * POST: devuelve el dato del nodo donde
         * apunta el cursor
        */
        Dato moverCursor();

        /**
         * POST: devuele true si el cursor
         * llego al final de la lista , de
         * lo contrario devuelve false
        */
        bool finalCursor();

        /**
         * Destructor
         * Libera toda la memoria reservada
         * para los nodos de la lista
        */
        ~Lista();
};

////////// CONSTRUCTOR //////////

template <typename Dato>
Lista<Dato>::Lista(){
    this->primero = nullptr;
    this->cursor = nullptr;
    this->cant_elem = 0;
}

////////// FUNCIONES PRIVADAS //////////

template <typename Dato>
Nodo_L<Dato>* Lista<Dato>::obtenerNodo(int posicion){
    Nodo_L<Dato>* buscado = this->primero;
    for(int i=1;i < posicion;i++){
        buscado = buscado->obtenerSiguiente();
    }
    //
    return buscado;
}

/////////// FUNCIONES PUBLICAS ////////////

template <typename Dato>
void Lista<Dato>::alta(Dato d,int posicion){
    Nodo_L<Dato>* nuevo = new Nodo_L<Dato>(d);
    if ( posicion == 1 ){
        nuevo->cambiarSiguiente(this->primero);
        this->primero = nuevo;
    } else {
        Nodo_L<Dato>* actual = this->obtenerNodo(posicion-1);
        Nodo_L<Dato>* sigue = actual->obtenerSiguiente();
        //
        actual->cambiarSiguiente(nuevo);
        nuevo->cambiarSiguiente(sigue);
    }
    //
    this->cant_elem++;
}

template <typename Dato>
void Lista<Dato>::baja(int posicion){
    Nodo_L<Dato>* borrar = this->primero;
    //
    if ( posicion == 1 ){
        this->primero = this->primero->obtenerSiguiente();
    } else {
        Nodo_L<Dato>* anterior = this->obtenerNodo(posicion-1);
        borrar = anterior->obtenerSiguiente();
        //
        anterior->cambiarSiguiente(borrar->obtenerSiguiente());
    }
    //
    delete borrar;
    borrar = nullptr;
    this->cant_elem--;
}

template <typename Dato>
Dato Lista<Dato>::buscarDato(int posicion){
    return (this->obtenerNodo(posicion)->obtenerDato());
}

template <typename Dato>
int Lista<Dato>::buscarPosicion(Dato d){
    if ( this->primero == nullptr ){
        return 0;
    }
    //    
    Nodo_L<Dato>* aux = this->primero;
    Dato dato_lista = aux->obtenerDato();
    bool encontrado = ( d == dato_lista );
    int i = 1;
    //
    while ( !encontrado && aux->obtenerSiguiente() != nullptr ){
        aux = aux->obtenerSiguiente();
        dato_lista = aux->obtenerDato();
        if ( d == dato_lista ){
            encontrado = true;
        }
        //
        i++;
    }
    //
    if ( !encontrado ){
        return 0;
    }
    //
    return i;
}

template <typename Dato>
bool Lista<Dato>::esVacia(){
    return (this->cant_elem == 0);
}

////////// FUNCIONES DEL CURSOR /////////////

template <typename Dato>
void Lista<Dato>::reiniciarCursor(){
    this->cursor = this->primero;
}

template <typename Dato>
Dato Lista<Dato>::moverCursor(){
    Dato dato = this->cursor->obtenerDato();
    this->cursor = this->cursor->obtenerSiguiente();
    //
    return dato;
}

template <typename Dato>
bool Lista<Dato>::finalCursor(){
    return ( this->cursor == nullptr );
}

////////// DESTRUCTOR ///////////////

template <typename Dato>
Lista<Dato>::~Lista(){
    while ( !this->esVacia() ){
        this->baja(1);
    }
}

#endif // LISTA_H_INCLUDED