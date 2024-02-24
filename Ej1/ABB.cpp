
#include "ABB.h"

ABB::ABB(){
    this->raiz = nullptr;
    this->cantidad_elementos = 0;
}

//////////////////////////////
//// FUNCIONES PRIVADAS //////
//////////////////////////////

Nodo* ABB::buscar(Nodo* nodo,string dato){
    if ( nodo != nullptr ){
        std::cout << nodo->obtenerClave() << std::endl;
        string clave_padre = nodo->obtenerClave();
        //
        if ( clave_padre < dato ){
            Nodo* derecho = nodo->obtenerHijoDerecho();
            if ( derecho != nullptr ){
                return this->buscar(derecho,dato);
            }
            // es mayor que el nodo padre
        } else if ( clave_padre > dato ){
            // es menor que el nodo padre
            Nodo* izquierdo = nodo->obtenerHijoIzquierdo();
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

void ABB::insertar(Nodo *nodo,string dato){
    string clave_padre = nodo->obtenerClave();
    //
    if ( clave_padre < dato ){
        // es mayor que el nodo padre
        Nodo* derecho = nodo->obtenerHijoDerecho();
        if ( derecho != nullptr ){
            this->insertar(derecho,dato);
        } else {
            Nodo* nuevo = new Nodo(dato,nodo);
            nodo->cambiarHijoDerecho(nuevo);
            this->cantidad_elementos++;
        }
    } else if ( clave_padre > dato ){
        // es menor que el nodo padre
        Nodo* izquierdo = nodo->obtenerHijoIzquierdo();
        if ( izquierdo != nullptr ){
            this->insertar(izquierdo,dato);
        } else {
            Nodo* nuevo = new Nodo(dato,nodo);
            nodo->cambiarHijoIzquierdo(nuevo);
            this->cantidad_elementos++;
        }
    }
}

void ABB::eliminarHoja(Nodo *nodo){
    Nodo* derecho = nodo->obtenerHijoDerecho();
    Nodo* izquierdo = nodo->obtenerHijoIzquierdo();
    //
    if ( derecho != nullptr && izquierdo != nullptr ){
        Nodo* predecesor = this->obtenerInmediatoPredecesor(nodo);
        nodo->cambiarClave(predecesor->obtenerClave());
        this->eliminarHoja(predecesor);
    } else if ( izquierdo != nullptr ){
        Nodo* predecesor = this->obtenerInmediatoPredecesor(nodo);
        nodo->cambiarClave(predecesor->obtenerClave());
        this->eliminarHoja(predecesor);
    } else if ( derecho != nullptr ){
        Nodo* sucesor = this->obtenerInmediatoSucesor(nodo);
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

Nodo* ABB::obtenerInmediatoPredecesor(Nodo* nodo){
    Nodo* predecesor = nodo->obtenerHijoIzquierdo();
    while( predecesor->obtenerHijoIzquierdo() != nullptr ){
        predecesor = predecesor->obtenerHijoIzquierdo();
    }
    //
    return predecesor;
}

Nodo* ABB::obtenerInmediatoSucesor(Nodo* nodo){
    Nodo* sucesor = nodo->obtenerHijoDerecho();
    while( sucesor->obtenerHijoDerecho() != nullptr ){
        sucesor = sucesor->obtenerHijoDerecho();
    }
    //
    return sucesor;
}

int ABB::calcularAltura(Nodo *nodo,int altura){
    Nodo* derecho = nodo->obtenerHijoDerecho();
    Nodo* izquierdo = nodo->obtenerHijoIzquierdo();
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

bool ABB::buscar(string dato){
    return ( this->buscar(this->raiz,dato) != nullptr);
}

bool ABB::insertar(string dato){
    int cant_anterior = this->cantidad_elementos;
    //
    if ( this->raiz == nullptr ){
        this->raiz = new Nodo(dato,nullptr);
        this->cantidad_elementos++;
        return true;    
    }
    //
    this->insertar(this->raiz,dato);
    //
    return ( (this->cantidad_elementos-cant_anterior) == 1 );
}

bool ABB::eliminar(string dato){
    int cantidad_anterior = this->cantidad_elementos;
    Nodo* buscado = this->buscar(this->raiz,dato);
    if ( buscado == nullptr ){
        return false;
    }
    //
    this->eliminarHoja(buscado);
    return ( cantidad_anterior-this->cantidad_elementos == 1 );
}

int ABB::altura(string dato){
    //
    int altura = 0;
    //
    Nodo* buscado = this->buscar(this->raiz,dato);
    if ( buscado != nullptr ){
        altura = this->calcularAltura(buscado,altura);    
    } else {
        return -1;
    }
    //
    return altura;
}

ABB::~ABB(){
    delete this->raiz;
}