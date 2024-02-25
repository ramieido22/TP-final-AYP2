#ifndef HASH_H
#define HASH_H

#include <iostream>
#include <cmath>
#include "lista.h"

using namespace std;


const float factor_carga = 0.8;

//Utilizacion del Hash base para poder elegir en el main que tipo de hash se quiere utilizar.
template<typename K, class V>
class Hash {
public:
    virtual ~Hash() {}

    virtual int ver_cantidad()=0;

    virtual bool esta_vacio()=0;

    virtual void agregar(K clave, V* valor)=0;

    //pre:
    //post:
    virtual V* buscar(K clave)=0;

    //pre:
    //post:
    virtual void eliminar(K clave)=0;

    //pre:
    //post:
    virtual bool pertenece(K clave)=0;

protected:
    int cantidad;

    int transformar_IATA_en_INT(K clave);
    
    int funcion_hash(K clave);
};

template<typename K, class V>
int  Hash<K,V>::transformar_IATA_en_INT(K clave){
        const int base = 128;
        int valor = 0;
        for (int i = 0; i <3; i++){
            valor += clave[i] * pow(base,i); //llevo a base de 128
        }
    return valor;
    };

template<typename K, class V>
int  Hash<K,V>::funcion_hash(K clave){
        return transformar_IATA_en_INT(clave) % this->tamanio;
    };

//====================================================================
//========================== HASH CERRADO ============================
//====================================================================

template<typename K, class V>
class Hash_cerrado : public Hash<K, V> {
private:
    //Atributos
    static const int tamanio = 67; //Como maximo voy a tener 50 aeropuertos, divido por el 0.8 y busco el primer numero primo. 67 en este caso.
    Nodo<V>* tabla[tamanio];

    //Metodos
    //pre:
    //post:
    Nodo<V>* buscar_nodo(K clave);

    int cantidad;

    int transformar_IATA_en_INT(K clave);
    
    int funcion_hash(K clave);


public:
    //Constructor
    Hash_cerrado();

    //Metodos
    //pre:
    //post:
    void agregar(K clave, V* valor) override;

    //pre:
    //post:
    V* buscar(K clave) override;

    //pre:
    //post:
    void eliminar(K clave) override;

    //pre:
    //post:
    bool pertenece(K clave) override;

    //pre:
    //post:
    int ver_cantidad() override;

    //pre:
    //post:
    bool esta_vacio() override;
    
    //Destructor
    virtual ~Hash_cerrado();
};

// Constructor
template<typename K, class V>
Hash_cerrado<K,V>::Hash_cerrado() {
    for (int i = 0; i < tamanio; i++) {
        tabla[i] = nullptr;
    }
    this->cantidad = 0;
}

// Métodos

template<typename K, class V>
int  Hash_cerrado<K,V>::transformar_IATA_en_INT(K clave){
        const int base = 128;
        int valor = 0;
        for (int i = 0; i <3; i++){
            valor += clave[i] * pow(base,i); //llevo a base de 128
        }
    return valor;
    };

template<typename K, class V>
int  Hash_cerrado<K,V>::funcion_hash(K clave){
        return transformar_IATA_en_INT(clave) % this->tamanio;
    };


template<typename K, class V>
Nodo<V>* Hash_cerrado<K,V>::buscar_nodo(K clave) {
    int pos = funcion_hash(clave);
    int pos_inicial = pos;
    while (tabla[pos] != nullptr && tabla[pos]->obtener_clave() != clave) {
        pos = (pos + 1);
        if (pos == tamanio){
            pos= pos%tamanio;
        }
        if (pos == pos_inicial) {
            return nullptr;
        }
    }
    return tabla[pos];
}

template<typename K, class V>
void Hash_cerrado<K,V>::agregar(K clave, V* valor) {
    int pos = funcion_hash(clave);
    int pos_inicial = pos;
    while (tabla[pos] != nullptr && tabla[pos]->obtener_estado() != VACIO) {
        pos = (pos + 1);
        if (pos == tamanio){
            pos= pos%tamanio;
        }
        if (pos == pos_inicial) {
            cout << "Tabla llena" << endl;
            return;
        }
    }
    tabla[pos] = new Nodo<V>(clave, valor, OCUPADO);
    this->cantidad ++;
}

template<typename K, class V>
V* Hash_cerrado<K,V>::buscar(K clave) {
    Nodo<V>* nodo = buscar_nodo(clave);
    if (nodo == nullptr) {
        cout << "NO SE ENCONTRO EL AEROPUERTO DE: "<< clave << endl;
        return nullptr;
    }
    cout << "SE ENCONTRO EL AEROPUERTO DE: "<< clave << endl;
    return nodo->obtener_valor();
}

template<typename K, class V>
void Hash_cerrado<K,V>::eliminar(K clave) {
    Nodo<V>* nodo = buscar_nodo(clave);
    if (nodo == nullptr) {
        cout << "NO SE ENCONTRO EL AEROPUERTO DE: "<< clave << endl;
        return;
    }
    else {
        nodo->borrar_datos_nodos();
        cout << "SE BORRARON LOS DATOS DEL AEROPUERTO DE: "<< clave << endl;
        this->cantidad --;
    }
}

template<typename K, class V>
bool  Hash_cerrado<K,V>::pertenece(K clave) {
    Nodo<V>* nodo = buscar_nodo(clave) ;
    if (nodo == nullptr) {
        cout << "NO PERTENECE EL AEROPUERTO DE: "<< clave << " A LA TABLA" << endl;
        return false;
    }
    cout << "PERTENECE EL AEROPUERTO DE: "<< clave << " A LA TABLA" << endl;
    return true;
}

template<typename K, class V>
int Hash_cerrado<K,V>::ver_cantidad() {
    return this->cantidad;
}

template<typename K, class V>
bool Hash_cerrado<K,V>::esta_vacio(){
    return (this->cantidad == 0);
}

// Destructor
template<typename K, class V>
Hash_cerrado<K,V>::~Hash_cerrado() {
    for (int i = 0; i < tamanio; i++) {
        delete tabla[i];
    }
}

//====================================================================
//========================== HASH ABIERTO ============================
//====================================================================

template<typename K, class V>
class Hash_abierto : public Hash<K, V> {
private:
    //Atributos
    static const int tamanio = 67; //Como maximo voy a tener 50 aeropuertos, divido por el 0.8 y busco el primer numero primo. 67 en este caso.
    Lista<V>* tabla[tamanio];

    int cantidad;

    int transformar_IATA_en_INT(K clave);
    
    int funcion_hash(K clave);

public:
    //Constructor
    Hash_abierto();

    //Metodos
    //pre:
    //post:
    void agregar(K clave, V* valor) override;

    //pre:
    //post:
    V* buscar(K clave) override;

    //pre:
    //post:
    void eliminar(K clave) override;

    //pre:
    //post:
    bool pertenece(K clave) override;

    //pre:
    //post:
    int ver_cantidad() override;

    //pre:
    //post:
    bool esta_vacio() override;
    
    //Destructor
    virtual ~Hash_abierto();
};

// Constructor
template<typename K, class V>
Hash_abierto<K,V>::Hash_abierto() {
    for (int i = 0; i < tamanio; i++) {
        tabla[i] = new Lista<V>();
    }
    this->cantidad = 0;
}

// Métodos
template<typename K, class V>
int  Hash_abierto<K,V>::transformar_IATA_en_INT(K clave){
        const int base = 128;
        int valor = 0;
        for (int i = 0; i <3; i++){
            valor += clave[i] * pow(base,i); //llevo a base de 128
        }
    return valor;
    };

template<typename K, class V>
int  Hash_abierto<K,V>::funcion_hash(K clave){
        return transformar_IATA_en_INT(clave) % this->tamanio;
    };

template<typename K, class V>
void Hash_abierto<K,V>::agregar(K clave, V* valor) {
    int pos = funcion_hash(clave);
    Lista<V>* lista = tabla[pos];
    int largo = lista->obtener_cantidad();
    lista->alta(clave,valor, largo+1);
    this->cantidad ++;
}
template<typename K, class V>
V* Hash_abierto<K,V>::buscar(K clave) {
    int pos = funcion_hash(clave);
    Lista<V>* lista = tabla[pos];
    lista->reiniciar_cursor();
    V* aeropuertoEncontrado = nullptr;
    while (lista->hay_siguiente() && aeropuertoEncontrado == nullptr){
        V* aeropuerto = lista->siguiente();
        if (aeropuerto->ver_codigo_IATA() == clave){
            aeropuertoEncontrado = aeropuerto;
            cout << "SE ENCONTRO EL AEROPUERTO DE: "<< clave << endl;
        }
    }
    if (aeropuertoEncontrado == nullptr){
        cout << "NO SE ENCONTRO EL AEROPUERTO DE: "<< clave << endl;
    }
    return aeropuertoEncontrado;
}
template<typename K, class V>
void Hash_abierto<K,V>::eliminar(K clave) {
    int pos = funcion_hash(clave);
    Lista<V>* lista = tabla[pos];
    lista->reiniciar_cursor();
    int contador = 1;
    bool encontrado = false;
    while (lista->hay_siguiente() && !encontrado){
        V* aeropuerto = lista->siguiente();
        if (aeropuerto->ver_codigo_IATA() == clave){
            cout << "SE BORRARON LOS DATOS DEL AEROPUERTO DE: "<< clave << endl;
            lista->baja(contador);
            this->cantidad--;
            encontrado = true;
        }
        contador++;
    }
    if (!encontrado) {
        cout << "NO SE ENCONTRO EL AEROPUERTO DE: "<< clave << endl;;
    }
}
template<typename K, class V>
bool Hash_abierto<K,V>::pertenece(K clave) {
    int pos = funcion_hash(clave);
    Lista<V>* lista = tabla[pos];
    lista->reiniciar_cursor();
    bool encontrado = false;
    while (!encontrado && lista->hay_siguiente()) {
        V* aeropuerto = lista->siguiente();
        if (aeropuerto->ver_codigo_IATA() == clave) {
            encontrado = true;
            cout << "PERTENECE EL AEROPUERTO DE: "<< clave << " A LA TABLA" << endl;
        }
    }
    if(!encontrado){
        cout << "NO PERTENECE EL AEROPUERTO DE: "<< clave << " A LA TABLA" << endl;
    }
    return encontrado;
}

template<typename K, class V>
int Hash_abierto<K,V>::ver_cantidad() {
    return this->cantidad;
}

template<typename K, class V>
bool Hash_abierto<K,V>::esta_vacio(){
    return (this->cantidad == 0);
}


// Destructor
template<typename K, class V>
Hash_abierto<K,V>::~Hash_abierto() {
    for (int i = 0; i < tamanio; i++) {
        delete tabla[i];
    }
}

#endif // HASH_H
