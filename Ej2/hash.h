#ifndef HASH_H
#define HASH_H
#include <iostream>
#include <cmath>
#include "lista.h"

using namespace std;

const double factor_carga = 0.8;

enum Funcionalidad{
    SIN_FUNC = 0,
    ABIERTO = 1,
    CERRADO = 2,
};

//Utilizacion del Hash base para poder elegir en el main que tipo de hash se quiere utilizar.

template<typename K, class V>
class Hash {
private:
    //Atributos
    static const int tamanio = 67; //Como maximo voy a tener 50 aeropuertos, divido por el 0.8 y busco el primer numero primo. 67 en este caso.
    int cantidad;
    Nodo<V>* tabla_cerrada[tamanio];
    Lista<V>* tabla_abierta[tamanio];
    Funcionalidad funcionalidad;

    //Metodos
    
    //pre: --
    //post: Transforma el texto IATA en un numero de base 128 % tamanio
    int transformar_IATA_en_INT(K clave);
    
    //pre:
    //post: Devuelve el valor de la funcion hash de la clave
    int funcion_hash(K clave);

    //pre: --
    //post: Busca un nodo en la tabla del hash
    Nodo<V>* buscar_nodo(K clave);

    //pre:--
    //post: Asocia un valor con una clave en el hash cerrado.
    void agregar_cerrado(K clave, V* valor);

    //pre:--
    //post: Asocia un valor con una clave en el hash abierto.
    void agregar_abierto(K clave, V* valor);

    //pre:  Debe pertenecer la clave
    //post: Devuelve el valor asociado a la clave
    V* buscar_cerrado(K clave);

    //pre:  Debe pertenecer la clave
    //post: Devuelve el valor asociado a la clave
    V* buscar_abierto(K clave);

    //pre: Debe pertenecer la clave
    //post: Elimina el valor asociado a la clave
    void eliminar_cerrado(K clave);

    //pre: Debe pertenecer la clave
    //post: Elimina el valor asociado a la clave
    void eliminar_abierto(K clave);

    //pre: -- 
    //post: Devuelve true si la clave esta en el hash, de lo contrario devuelve false
    bool pertenece_cerrado(K clave);

    //pre: --
    //post: Devuelve true si la clave esta en el hash, de lo contrario devuelve false
    bool pertenece_abierto(K clave);

    //pre: --
    //post: Destruye el hash cerrado
    void destruir_hash_cerrado();

    //pre: --
    //post: Destruye el hash abierto
    void destruir_hash_abierto();
public:
    //Constructor
    Hash(); 

    //Metodos

    //pre: --
    //post: Da funcionalidad al hash
    void dar_funcionalidad(Funcionalidad funcion);

    //pre: --
    //post: Crea un hash abierto o cerrado segun la funcionalidad

    void crear_hash_abierto_o_cerrado();

    //pre: --
    //post: Devuelve la cantidad de elementos
    int ver_cantidad();

    //pre: -- 
    //post: Devuelve true si el hash esta vacio, de lo contrario devuelve false
    bool esta_vacio();

    //pre:--
    //post: Asocia un valor con una clave en el hash.
    void agregar(K clave, V* valor);

    //pre:  Debe pertenecer la clave
    //post: Devuelve el valor asociado a la clave
    V* buscar(K clave);

    //pre: Debe pertenecer la clave
    //post: Elimina el valor asociado a la clave
    void eliminar(K clave);

    //pre: -- 
    //post: Devuelve true si la clave esta en el hash, de lo contrario devuelve false
    bool pertenece(K clave);

    //Destructor
    ~Hash();
};

//Constructor
template<typename K, class V>
Hash<K,V>::Hash() {
    this->funcionalidad = SIN_FUNC;
    this->cantidad = 0;
    crear_hash_abierto_o_cerrado();
}

template<typename K, class V>
int  Hash<K,V>::transformar_IATA_en_INT(K clave){
        const int base = 128;
        int valor = 0;
        for (int i = 0; i <3; i++){
            valor += static_cast<int>(clave[i] * pow(base,i)); //llevo a base de 128
        }
    return valor;
    };

template<typename K, class V>
int  Hash<K,V>::funcion_hash(K clave){
        return transformar_IATA_en_INT(clave) % this->tamanio;
    };

template<typename K, class V>
Nodo<V>* Hash<K,V>::buscar_nodo(K clave) {
    int pos = funcion_hash(clave);
    int pos_inicial = pos;
    while (tabla_cerrada[pos] != nullptr && tabla_cerrada[pos]->obtener_clave() != clave) {
        pos = (pos + 1);
        if (pos == tamanio){
            pos= pos%tamanio;
        }
        if (pos == pos_inicial) {
            return nullptr;
        }
    }
    return tabla_cerrada[pos];
}

template<typename K, class V>
void Hash<K,V>::dar_funcionalidad(Funcionalidad funcion){
    if (funcion == ABIERTO){
        this->funcionalidad = ABIERTO;
    }
    else if (funcion == CERRADO){
        this->funcionalidad = CERRADO;
    }
}

template<typename K, class V>
void Hash<K,V>::crear_hash_abierto_o_cerrado(){
    for (int i = 0; i < tamanio; i++) {
        if (this->funcionalidad == ABIERTO){
            this->tabla_abierta[i] = new Lista<V>();
        }else{
            this->tabla_cerrada[i] = nullptr;
            }
        }
    this->cantidad = 0;
}

template<typename K, class V>
int Hash<K,V>::ver_cantidad() {
    return this->cantidad;
}

template<typename K, class V>
bool Hash<K,V>::esta_vacio(){
    return (this->cantidad == 0);
}

template<typename K, class V>
void Hash<K,V>::agregar_cerrado(K clave, V* valor) {
    int pos = funcion_hash(clave);
    int pos_inicial = pos;
    while (tabla_cerrada[pos] != nullptr && tabla_cerrada[pos]->obtener_estado() != VACIO) {
        pos = (pos + 1);
        if (pos == tamanio){
            pos= pos%tamanio;
        }
        if (pos == pos_inicial) {
            cout << "Tabla llena" << endl;
            return;
        }
    }
    tabla_cerrada[pos] = new Nodo<V>(clave, valor, OCUPADO);
    this->cantidad ++;
}

template<typename K, class V>
void Hash<K,V>::agregar_abierto(K clave, V* valor) {
    int pos = funcion_hash(clave);
    Lista<V>* lista = tabla_abierta[pos];
    int largo = lista->obtener_cantidad();
    lista->alta(clave,valor, largo+1);
    this->cantidad ++;
}

template<typename K, class V>
void Hash<K,V>::agregar(K clave, V* valor) {
    if (this->funcionalidad == ABIERTO){
        agregar_abierto(clave,valor);
    }else{
        agregar_cerrado(clave, valor);
    }
}

template<typename K, class V>
V* Hash<K,V>::buscar_cerrado(K clave) {
    Nodo<V>* nodo = buscar_nodo(clave);
    if (nodo == nullptr) {
        cout << "NO SE ENCONTRO EL AEROPUERTO DE: "<< clave << endl;
        return nullptr;
    }
    cout << "SE ENCONTRO EL AEROPUERTO DE: "<< clave << endl;
    return nodo->obtener_valor();
}

template<typename K, typename V>
V* Hash<K,V>::buscar_abierto(K clave) {
    int pos = funcion_hash(clave);
    Lista<V>* lista = tabla_abierta[pos];
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
V* Hash<K,V>::buscar(K clave) {
    if (this->funcionalidad == ABIERTO){
        return buscar_abierto(clave);
    }else{
        return buscar_cerrado(clave);
    }
}

template<typename K, class V>
void Hash<K,V>::eliminar_cerrado(K clave) {
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
void Hash<K,V>::eliminar_abierto(K clave) {
    int pos = funcion_hash(clave);
    Lista<V>* lista = tabla_abierta[pos];
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
void Hash<K,V>::eliminar(K clave) {
    if (this->funcionalidad == ABIERTO){
        eliminar_abierto(clave);
    }else{
        eliminar_cerrado(clave);
    }
}

template<typename K, class V>
bool Hash<K,V>::pertenece_cerrado(K clave) {
    Nodo<V>* nodo = buscar_nodo(clave) ;
    if (nodo == nullptr) {
        cout << "NO PERTENECE EL AEROPUERTO DE: "<< clave << " A LA TABLA" << endl;
        return false;
    }
    cout << "PERTENECE EL AEROPUERTO DE: "<< clave << " A LA TABLA" << endl;
    return true;
}

template<typename K, class V>
bool Hash<K,V>::pertenece_abierto(K clave) {
    int pos = funcion_hash(clave);
    Lista<V>* lista = tabla_abierta[pos];
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
bool Hash<K,V>::pertenece(K clave) {
    if (this->funcionalidad == ABIERTO){
        return pertenece_abierto(clave);
    }else{
        return pertenece_cerrado(clave);
    }
}

template<typename K, class V>
void Hash<K,V>::destruir_hash_cerrado() {
    for (int i = 0; i < tamanio; i++) {
        delete tabla_cerrada[i];
    }
}

template<typename K, class V>
void Hash<K,V>::destruir_hash_abierto() {
    for (int i = 0; i < tamanio; i++) {
        delete tabla_abierta[i];
    }
}


//Destructor
template<typename K, class V>
Hash<K,V>::~Hash() {
    if (this->funcionalidad == ABIERTO){
        destruir_hash_abierto();
    }else{
        destruir_hash_cerrado();
    }
}

#endif // HASH_H