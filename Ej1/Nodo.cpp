
#include "Nodo.h"

/////// CONSTRUCTORES ////////

Nodo::Nodo(string IATA,Nodo *padre){
    this->clave = IATA;
    this->hijo_derecho = nullptr;
    this->hijo_izquierdo = nullptr;
    this->data = nullptr;
    this->padre = padre;
}

Nodo::Nodo(string IATA,Nodo* padre,Nodo *pn_izq,Nodo *pn_der){
    this->clave = IATA;
    this->hijo_derecho = pn_der;
    this->hijo_izquierdo = pn_izq;
    this->padre = padre;
    this->data = nullptr;
}

Nodo::Nodo(const Nodo* pn){
    this->clave = pn->clave;
    this->hijo_derecho = pn->hijo_derecho;
    this->hijo_izquierdo = pn->hijo_izquierdo;
    this->padre = pn->padre;
    this->data = pn->data;
}

/////// CONSULTADORES (GETTERS) ////////

Nodo* Nodo::obtenerHijoIzquierdo(void){
    return this->hijo_izquierdo;
}

Nodo* Nodo::obtenerHijoDerecho(void){
    return this->hijo_derecho;
}

Nodo* Nodo::obtenerPadre(void){
    return this->padre;
}

string Nodo::obtenerClave(void){
    return this->clave;
}

Aeropuerto* Nodo::obtenerDatos(void){
    return this->data;
}

/////// MODIFICADORES (SETTERS) ////////

void Nodo::cambiarClave(string IATA){
    this->clave = IATA;
}

void Nodo::cambiarHijoDerecho(Nodo* pn){
    this->hijo_derecho = pn;
}

void Nodo::cambiarHijoIzquierdo(Nodo* pn){
    this->hijo_izquierdo = pn;
}

void Nodo::cambiarPadre(Nodo *pn){
    this->padre = pn;
}

void Nodo::cambiarDato(Aeropuerto* pn){
    this->data = pn;
}

void Nodo::desasignarHijo(Nodo *pn){
    if ( this->hijo_derecho == pn ){
        this->hijo_derecho = nullptr;
    } else {
        this->hijo_izquierdo = nullptr;
    }
}

/////// DESTRUCTOR ////////

Nodo::~Nodo(){
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