
#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED

template <typename Clave,class Dato>
class Nodo {
    private:
        Nodo* hijo_izquierdo;
        Nodo* hijo_derecho;
        Nodo* padre;
        Clave clave;
        Dato* data;
    
    public:

        /**
         * Constructor
         * PRE: pasa el codigo IATA
        */
        Nodo(Clave IATA,Nodo* padre);

        /**
         * Constructor
         * PRE: pasa el codigo IATA, y los punteros
         * a los hijos derecho y izquierdo
        */
        Nodo(Clave IATA,Nodo* padre,Nodo* pn_izq,Nodo* pn_der);

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
        Clave obtenerClave(void);

        /**
         * POST: devuelve los datos
         * del aeropuerto vinculado 
         * con el nodo
        */
        Dato* obtenerDatos(void);

        /**
         * PRE: pasar el nuevo codigo IATA
         * POST: cambiar la clave por 
         * el codigo pasado
        */
        void cambiarClave(Clave IATA);

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
        void cambiarDato(Dato* pn);

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

/////// CONSTRUCTORES ////////

template <typename Clave,class Dato>
Nodo<Clave,Dato>::Nodo(Clave IATA,Nodo *padre){
    this->clave = IATA;
    this->hijo_derecho = nullptr;
    this->hijo_izquierdo = nullptr;
    this->data = nullptr;
    this->padre = padre;
}

template <typename Clave,class Dato>
Nodo<Clave,Dato>::Nodo(Clave IATA,Nodo* padre,Nodo *pn_izq,Nodo *pn_der){
    this->clave = IATA;
    this->hijo_derecho = pn_der;
    this->hijo_izquierdo = pn_izq;
    this->padre = padre;
    this->data = nullptr;
}

template <typename Clave,class Dato>
Nodo<Clave,Dato>::Nodo(const Nodo* pn){
    this->clave = pn->clave;
    this->hijo_derecho = pn->hijo_derecho;
    this->hijo_izquierdo = pn->hijo_izquierdo;
    this->padre = pn->padre;
    this->data = pn->data;
}

/////// CONSULTADORES (GETTERS) ////////

template <typename Clave,class Dato>
Nodo<Clave,Dato>* Nodo<Clave,Dato>::obtenerHijoIzquierdo(void){
    return this->hijo_izquierdo;
}

template <typename Clave,class Dato>
Nodo<Clave,Dato>* Nodo<Clave,Dato>::obtenerHijoDerecho(void){
    return this->hijo_derecho;
}

template <typename Clave,class Dato>
Nodo<Clave,Dato>* Nodo<Clave,Dato>::obtenerPadre(void){
    return this->padre;
}

template <typename Clave,class Dato>
Clave Nodo<Clave,Dato>::obtenerClave(void){
    return this->clave;
}

template <typename Clave,class Dato>
Dato* Nodo<Clave,Dato>::obtenerDatos(void){
    return this->data;
}

/////// MODIFICADORES (SETTERS) ////////

template <typename Clave,class Dato>
void Nodo<Clave,Dato>::cambiarClave(Clave IATA){
    this->clave = IATA;
}

template <typename Clave,class Dato>
void Nodo<Clave,Dato>::cambiarHijoDerecho(Nodo* pn){
    this->hijo_derecho = pn;
}

template <typename Clave,class Dato>
void Nodo<Clave,Dato>::cambiarHijoIzquierdo(Nodo* pn){
    this->hijo_izquierdo = pn;
}

template <typename Clave,class Dato>
void Nodo<Clave,Dato>::cambiarPadre(Nodo *pn){
    this->padre = pn;
}

template <typename Clave,class Dato>
void Nodo<Clave,Dato>::cambiarDato(Dato* pn){
    this->data = pn;
}

template <typename Clave,class Dato>
void Nodo<Clave,Dato>::desasignarHijo(Nodo *pn){
    if ( this->hijo_derecho == pn ){
        this->hijo_derecho = nullptr;
    } else {
        this->hijo_izquierdo = nullptr;
    }
}

/////// DESTRUCTOR ////////

template <typename Clave,class Dato>
Nodo<Clave,Dato>::~Nodo(){
    if ( this->hijo_izquierdo != nullptr ){
        delete this->hijo_izquierdo;
        this->hijo_izquierdo = nullptr;
    }
    //
    if ( this->hijo_derecho != nullptr ){
        delete this->hijo_derecho;
        this->hijo_derecho = nullptr;
    }
    //
    this->data = nullptr;
    this->padre = nullptr;
}

#endif // NODO_H_INCLUDED