#ifndef _NODO_H_
#define _NODO_H_
#include "aeropuerto.h"

enum ESTADO {
    VACIO,
    OCUPADO,
    BORRADO,
    NONE //estado sin valor
};

template<typename T>
class Nodo {
private:
    // ATRIBUTOS
    string  clave;
    T* valor;
    ESTADO estado;
    Nodo<T>* siguiente;

public:
    
    // CONSTRUCTORES

    // pos: construye un Nodo 
    Nodo();

    Nodo(string d, T* v); //(Hash Abierto)
    
    // pos: construye un Nodo con un dato d, un puntero v y un estado (VACIO, OCUPADO, BORRADO) Hash Cerrado.
    Nodo(string d, T* v, ESTADO estado);

    // METODOS
    string obtener_clave();

    T* obtener_valor();

    Nodo<T>* obtener_siguiente();

    ESTADO obtener_estado();

    void borrar_datos_nodos();

    void cambiar_siguiente(Nodo<T>* pn);
    // DESTRUCTOR
    ~Nodo();

};

// DECLARACIONES DE LOS METODOS DE LA CLASE NODO:

template<typename T>
Nodo<T>::Nodo() {
    clave = "";
    valor = nullptr;
    estado = VACIO;
    siguiente = nullptr;
}

template<typename T>
Nodo<T>::Nodo(string d, T* v) {
    clave = d;
    valor = v;
    this->estado = NONE;
    siguiente = nullptr;
}

template<typename T>
Nodo<T>::Nodo(string d, T* v, ESTADO estado) {
    clave = d;
    valor = v;
    this->estado = estado;
    siguiente = nullptr;
}

template<typename T>
string Nodo<T>::obtener_clave() {
    return this->clave;
}

template<typename T>
T* Nodo<T>::obtener_valor() {
    return this->valor;
}

template<typename T>
Nodo<T>* Nodo<T>::obtener_siguiente() {
    return this->siguiente;
}

template<typename T>
ESTADO Nodo<T>::obtener_estado() {
    return this->estado;
}

template<typename T>
void  Nodo<T>::borrar_datos_nodos(){
    delete this->valor;
    this->valor=nullptr;
    this->clave = "";
    this->estado = BORRADO;
}

template<typename T>
void Nodo<T>::cambiar_siguiente(Nodo<T>* pn) {
    siguiente = pn;
}


template<typename T>
Nodo<T>::~Nodo() {
    delete valor;
}

#endif // _NODO_H_
