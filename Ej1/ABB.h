
#ifndef ABB_H_INCLUDED
#define ABB_H_INCLUDED

#include "Nodo.h"

/**
 * Para usar la clave, el parametero
 * de template Dato se maneja siempre
 * con referencia
*/
template <typename Clave,class Dato>
class ABB {
    private:
        Nodo<Clave,Dato>* raiz;
        int cantidad_elementos;

        /**
         * PRE: pasar el nodo a traves del cual se 
         * va a comenzar la busqueda y el dato a buscar
         * POST: devuelve el nodo si el dato existe y NULL si no
        */
        Nodo<Clave,Dato>* buscar(Nodo<Clave,Dato>* nodo,Clave dato);

        /**
         * PRE: pasar el nodo a traves del cual se 
         * va a comenzar la insercion y el dato a insertar
         * POST: el dato sera insertado si ya no esta presente en el arbol
        */
        Nodo<Clave,Dato>* insertar(Nodo<Clave,Dato>* nodo,Clave dato);

        /**
         * PRE: pasar el nodo lo cual se quiere eliminar
         * POST: el nodo sera eliminado si se encuentra
        */
        void eliminarHoja(Nodo<Clave,Dato>* nodo);

        /**
         * POST: devuelve el nodo con el dato mas grande
         * comparado con el dato del nodo pasado como parametro
        */
        Nodo<Clave,Dato>* obtenerInmediatoPredecesor(Nodo<Clave,Dato>* nodo);

        /**
         * POST: devuelve el nodo con el dato mas chico
         * comparado con el dato del nodo pasado como parametro
        */
        Nodo<Clave,Dato>* obtenerInmediatoSucesor(Nodo<Clave,Dato>* nodo);

        /**
         * PRE: El nodo dado no debe ser null
         * POST: devuelve la altura del nodo en el arbol
        */
        int calcularAltura(Nodo<Clave,Dato>* nodo,int altura);
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
        int altura(Clave dato);

        /**
         * POST: devuelve true si el dato
         * se encuentra en el arbol y false si no
        */
        bool estaEnArbol(Clave dato);

        /**
         * PRE: pasa la clave del nodo como
         * parametro
         * POST: obtener el dato grabado en
         * el nodo
        */
        Dato* obtenerDato(Clave dato);

        /**
         * PRE: debe ser un dato que
         * no existe en el arbol binario
         * POST: devuelve true si el nodo se inserta con exito y false si no
        */
        bool insertar(Clave clave,Dato* datos);

        /**
         * PRE: el elemento dado debe estar en el arbol
         * POST: devuelve true si el nodo se elimina con exito y false si no
        */
        bool eliminar(Clave dato);

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

template <typename Clave,class Dato>
ABB<Clave,Dato>::ABB(){
    this->raiz = nullptr;
    this->cantidad_elementos = 0;
}

//////////////////////////////
//// FUNCIONES PRIVADAS //////
//////////////////////////////

template <typename Clave,class Dato>
Nodo<Clave,Dato>* ABB<Clave,Dato>::buscar(Nodo<Clave,Dato>* nodo,Clave dato){
    if ( nodo != nullptr ){
        Clave clave_padre = nodo->obtenerClave();
        //
        if ( clave_padre < dato ){
            Nodo<Clave,Dato>* derecho = nodo->obtenerHijoDerecho();
            if ( derecho != nullptr ){
                return this->buscar(derecho,dato);
            }
            // es mayor que el nodo padre
        } else if ( clave_padre > dato ){
            // es menor que el nodo padre
            Nodo<Clave,Dato>* izquierdo = nodo->obtenerHijoIzquierdo();
            if ( izquierdo != nullptr ){
                return this->buscar(izquierdo,dato);
            }
        } else {
            return nodo;
        }
    }
    //
    return nullptr;
}

template <typename Clave,class Dato>
Nodo<Clave,Dato>* ABB<Clave,Dato>::insertar(Nodo<Clave,Dato>* nodo,Clave dato){
    Clave clave_padre = nodo->obtenerClave();
    //
    if ( clave_padre < dato ){
        // es mayor que el nodo padre
        Nodo<Clave,Dato>* derecho = nodo->obtenerHijoDerecho();
        if ( derecho != nullptr ){
            return this->insertar(derecho,dato);
        } else {
            Nodo<Clave,Dato>* nuevo = new Nodo<Clave,Dato>(dato,nodo);
            nodo->cambiarHijoDerecho(nuevo);
            this->cantidad_elementos++;
            return nuevo;
        }
    } else if ( clave_padre > dato ){
        // es menor que el nodo padre
        Nodo<Clave,Dato>* izquierdo = nodo->obtenerHijoIzquierdo();
        if ( izquierdo != nullptr ){
            return this->insertar(izquierdo,dato);
        } else {
            Nodo<Clave,Dato>* nuevo = new Nodo<Clave,Dato>(dato,nodo);
            nodo->cambiarHijoIzquierdo(nuevo);
            this->cantidad_elementos++;
            return nuevo;
        }
    }
    //
    return nullptr;
}

template <typename Clave,class Dato>
void ABB<Clave,Dato>::eliminarHoja(Nodo<Clave,Dato>* nodo){
    Nodo<Clave,Dato>* derecho = nodo->obtenerHijoDerecho();
    Nodo<Clave,Dato>* izquierdo = nodo->obtenerHijoIzquierdo();
    //
    if ( derecho != nullptr && izquierdo != nullptr ){
        Nodo<Clave,Dato>* predecesor = this->obtenerInmediatoPredecesor(nodo);
        nodo->cambiarClave(predecesor->obtenerClave());
        this->eliminarHoja(predecesor);
    } else if ( izquierdo != nullptr ){
        Nodo<Clave,Dato>* predecesor = this->obtenerInmediatoPredecesor(nodo);
        nodo->cambiarClave(predecesor->obtenerClave());
        this->eliminarHoja(predecesor);
    } else if ( derecho != nullptr ){
        Nodo<Clave,Dato>* sucesor = this->obtenerInmediatoSucesor(nodo);
        nodo->cambiarClave(sucesor->obtenerClave());
        this->eliminarHoja(sucesor);
    } else {
        //
        if ( nodo == raiz ){
            delete this->raiz;
            this->raiz = nullptr;
            this->cantidad_elementos--;
        } else {
            nodo->obtenerPadre()->desasignarHijo(nodo);
            delete nodo;
            this->cantidad_elementos--;
        }
    }
}

template <typename Clave,class Dato>
Nodo<Clave,Dato>* ABB<Clave,Dato>::obtenerInmediatoPredecesor(Nodo<Clave,Dato>* nodo){
    Nodo<Clave,Dato>* predecesor = nodo->obtenerHijoIzquierdo();
    while( predecesor->obtenerHijoIzquierdo() != nullptr ){
        predecesor = predecesor->obtenerHijoIzquierdo();
    }
    //
    return predecesor;
}

template <typename Clave,class Dato>
Nodo<Clave,Dato>* ABB<Clave,Dato>::obtenerInmediatoSucesor(Nodo<Clave,Dato>* nodo){
    Nodo<Clave,Dato>* sucesor = nodo->obtenerHijoDerecho();
    while( sucesor->obtenerHijoDerecho() != nullptr ){
        sucesor = sucesor->obtenerHijoDerecho();
    }
    //
    return sucesor;
}

template <typename Clave,class Dato>
int ABB<Clave,Dato>::calcularAltura(Nodo<Clave,Dato>* nodo,int altura){
    Nodo<Clave,Dato>* derecho = nodo->obtenerHijoDerecho();
    Nodo<Clave,Dato>* izquierdo = nodo->obtenerHijoIzquierdo();
    int altura_derecho = 0;
    int altura_izquierda = 0;
    //
    bool no_existe_derecho = (derecho == nullptr);
    bool no_existe_izquierdo = (izquierdo == nullptr);
    //
    if ( no_existe_derecho && no_existe_izquierdo ){
        return altura;
    } else {
        if ( !no_existe_derecho ){
            altura_derecho = this->calcularAltura(derecho,altura); 
        }
        //
        if ( !no_existe_izquierdo ){
            altura_izquierda = this->calcularAltura(izquierdo,altura);
        }
        //
        altura++;
        //
        if ( altura_derecho > altura_izquierda ){
            altura += altura_derecho;
        } else {
            altura += altura_izquierda;
        }    
    }
    //
    return altura;
}

//////////////////////////////
//// FUNCIONES PUBLICAS //////
//////////////////////////////

template <typename Clave,class Dato>
bool ABB<Clave,Dato>::estaEnArbol(Clave dato){
    return ( this->buscar(this->raiz,dato) != nullptr);
}

template <typename Clave,class Dato>
Dato* ABB<Clave,Dato>::obtenerDato(Clave dato){
    Nodo<Clave,Dato>* buscado = this->buscar(this->raiz,dato);
    if ( buscado != nullptr ){
        return buscado->obtenerDatos();
    }
    //
    return nullptr;
}

template <typename Clave,class Dato>
bool ABB<Clave,Dato>::insertar(Clave clave,Dato* datos){
    int cant_anterior = this->cantidad_elementos;
    //
    if ( this->raiz == nullptr ){
        this->raiz = new Nodo<Clave,Dato>(clave,nullptr);
        this->raiz->cambiarDato(datos);
        this->cantidad_elementos++;
        return true;
    }
    //
    Nodo<Clave,Dato>* nuevo = this->insertar(this->raiz,clave);
    nuevo->cambiarDato(datos);
    //
    return ( (this->cantidad_elementos-cant_anterior) == 1 );
}

template <typename Clave,class Dato>
bool ABB<Clave,Dato>::eliminar(Clave dato){
    int cantidad_anterior = this->cantidad_elementos;
    Nodo<Clave,Dato>* buscado = this->buscar(this->raiz,dato);
    if ( buscado == nullptr ){
        return false;
    }
    //
    this->eliminarHoja(buscado);
    return ( cantidad_anterior-this->cantidad_elementos == 1 );
}

template <typename Clave,class Dato>
int ABB<Clave,Dato>::altura(Clave dato){
    //
    int altura = 0;
    //
    Nodo<Clave,Dato>* buscado = this->buscar(this->raiz,dato);
    if ( buscado != nullptr ){
        altura = this->calcularAltura(buscado,altura);    
    } else {
        return -1;
    }
    //
    return altura;
}

template <typename Clave,class Dato>
int ABB<Clave,Dato>::cantidad(){
    return this->cantidad_elementos;
}

template <typename Clave,class Dato>
ABB<Clave,Dato>::~ABB(){
    delete this->raiz;
}


#endif // ABB_H_INCLUDED