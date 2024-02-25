#ifndef _LISTA_H_
#define _LISTA_H_

#include "nodo.h"
#include <iostream>
using namespace std;

template<typename T>


class Lista {
private:
    Nodo<T>* primero;
    Nodo<T>* cursor;
    int cantidad;
    // pre: 0 < pos <= cantidad
    // pos: devuelve un puntero al nodo en la posicion pos
    Nodo<T>* obtener_nodo(int pos);
public:
    // CONSTRUCTOR
    // pre: -
    // pos: construye una Lista
    Lista();

    // METODOS PUBLICOS
    
    // pre: 0 < pos <= obtener_cantidad() + 1
    // pos: agrega d a la Lista en la posicion pos
    void alta(string clave,T* d, int pos);

    // pre: 0 < pos <= obtener_cantidad()
    // pos: elimina de la Lista el elemento en la posicion pos 
    void baja(int pos);

    // pre: -
    // pos: devuelve true si la Lista esta vacia
    // devuelve false en caso contrario
    bool esta_vacia();

    // pre: 0 < pos <= obtener_cantidad()
    // pos: devuelve el elemento de la posicion pos 
    T consulta(int pos);

    // pre: -
    // pos: devuelve la cantidad de elementos en la lista
    int obtener_cantidad();

    // pre: -
    // pos: devuelve true si hay siguiente, false si no
    bool hay_siguiente();

    // pre: hay_siguiente() == true
    // pos: devuelve el siguiente dato y actualiza el cursor
    T* siguiente();

    // pre: -
    // pos: vuelve el cursor al inicio
    void reiniciar_cursor();

    // pre: Se necesita el elemento que se desea buscar
    // pos: devuelve true si el elemento pertenece a la lista, false si no.
    bool pertenece_elemento(T elemento);

    // pre: -
    // pos: muestra todos los elementos de la lista
    void mostrar_todos_elementos();


    // DESTRUCTOR
    // pre: -
    // pos: destruye la Lista y libera toda la memoria utilizada.
    ~Lista();
};

//DECLARACIONES DE LOS METODOS DE LA CLASE LISTA:
template<typename T>
Lista<T>::Lista() {
    primero = nullptr;
    cursor = primero;
    cantidad = 0;
}

template<typename T>
Nodo<T>* Lista<T>::obtener_nodo(int pos) {
    Nodo<T>* pn = primero;
    for (int i = 1; i < pos; i++)
        pn = pn->obtener_siguiente();
    return pn;
}

template<typename T>
void Lista<T>::alta(string clave,T* d, int pos) {
    Nodo<T>* nuevo = new Nodo<T>(clave,d);
    if (esta_vacia())
        cursor = nuevo;
    if (pos == 1){
        nuevo->cambiar_siguiente(primero);
        primero = nuevo;
    } else {
        Nodo<T>* anterior = obtener_nodo(pos-1);
        Nodo<T>* siguiente = anterior->obtener_siguiente();
        nuevo->cambiar_siguiente(siguiente);
        anterior->cambiar_siguiente(nuevo);
    }
    cantidad++;
}


template<typename T>
void Lista<T>::baja(int pos) {
    Nodo<T>* borrar = primero;
    if (pos == 1) {
        primero = borrar->obtener_siguiente();
        reiniciar_cursor();
    } else {
        Nodo<T>* anterior = obtener_nodo(pos-1);
        borrar = anterior->obtener_siguiente();
        Nodo<T>* siguiente = borrar->obtener_siguiente();
        anterior->cambiar_siguiente(siguiente);
    }
    if (cursor == borrar){
        siguiente();
    }
    delete borrar;
    cantidad--;
}

template<typename T>
T Lista<T>::consulta(int pos) {
    Nodo<T>* pn = obtener_nodo(pos);
    return pn->obtener_dato();
}

template<typename T>
bool Lista<T>::esta_vacia() {
    return (cantidad == 0);
}

template<typename T>
int Lista<T>::obtener_cantidad() {
    return cantidad;
}
template<typename T>
bool Lista<T>::hay_siguiente() {
    return (cursor != nullptr);
}

template<typename T>
T* Lista<T>::siguiente() {
    T* dato = cursor->obtener_valor();
    cursor = cursor->obtener_siguiente();
    return dato;
}

template<typename T>
void Lista<T>::reiniciar_cursor() {
    cursor = primero;
}

template<typename T>
bool Lista<T>::pertenece_elemento(T elemento) {
    reiniciar_cursor();
    while (hay_siguiente()) {
        if (siguiente() == elemento)
            return true;
    }
    return false;
}

template<typename T>
void Lista<T>::mostrar_todos_elementos() {
    for (int i = 1; i <= obtener_cantidad(); i++)
        cout << "Elemento " << i << ": " << consulta(i)->obtener_nombre() << endl;
}

template<typename T>
Lista<T>::~Lista() {
    while (!esta_vacia())
        baja(1);
}

#endif // _LISTA_H_