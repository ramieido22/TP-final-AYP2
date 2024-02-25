

#ifndef NODO_LISTA_H_INCLUDED
#define NODO_LISTA_H_INCLUDED

template <typename Dato>
class Nodo_L {
    private:
        Dato data;
        Nodo_L* siguiente;
    
    public:

        /**
         * Constructor 
         * PRE: recibe el dato a grabar en el
         * nodo
        */
        Nodo_L(Dato d);

        /**
         * Constructor 
         * PRE: recibe el dato a grabar en el
         * nodo y el nodo que le sigue
        */
        Nodo_L(Dato d,Nodo_L* pn);

        /**
         * POST: devuelve el nodo siguiente
         * al nodo actual
        */
        Nodo_L* obtenerSiguiente();

        /**
         * POST: devuelve el dato que
         * esta grabado en el nodo
        */
        Dato obtenerDato();

        /**
         * PRE: debe pasar como parametro el nodo
         * que le sigue
         * POST: se setea el nodo dado como
         * el nodo que le sigue
        */
        void cambiarSiguiente(Nodo_L* pn);

        /**
         * PRE: el nuevo dato a grabar en el nodo
         * POST: cambia el dato del nodo
        */
        void cambiarDato(Dato d);
};

template <typename Dato>
Nodo_L<Dato>::Nodo_L(Dato d,Nodo_L* pn){
    this->data = d;
    this->siguiente = pn;
}

template <typename Dato>
Nodo_L<Dato>::Nodo_L(Dato d){
    this->data = d;
    this->siguiente = nullptr;
}


template <typename Dato>
Nodo_L<Dato>* Nodo_L<Dato>::obtenerSiguiente(){
    return this->siguiente;
}

template <typename Dato>
Dato Nodo_L<Dato>::obtenerDato(){
    return this->data;
}

template <typename Dato>
void Nodo_L<Dato>::cambiarDato(Dato d){
    this->data = d;
}

template <typename Dato>
void Nodo_L<Dato>::cambiarSiguiente(Nodo_L* pn){
    this->siguiente = pn;
}

#endif // NODO_LISTA_H_INCLUDED

