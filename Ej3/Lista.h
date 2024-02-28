#ifndef GRAFOS_LISTA_H
#define GRAFOS_LISTA_H
#include <string>
#include "Nodo.h"

using namespace std;

const int POSICION_NO_ENCONTRADA = -1;
const string NOMBRE_NO_ENCONTRADO = "";

template < typename Tipo >
class Lista{
/*ATRIBUTOS*/
private:
    int cantidadDeElementos;
    Nodo<Tipo>* primero;
    Nodo<Tipo>* ultimo;

/*MÉTODOS*/
public:
    Lista();

    //post: devuelve la cantidad de elementos que tiene la lista
    int obtenerCantidadDeElementos();

    //post: devuelve la posicion en la que se encuentra el nombre que recibe o -1 si no lo encuentra
    int obtenerPosicion(string nombre);

    //post: devuelve el codigo IATA que se encuentra en la posicion recibida
    string obtenerCodigoIATA(int posicion);

	//post: devuelve el aeropuerto que se encuentra en la posicion recibida
    string obtenerNombreAeropuerto(int posicion);

	//post: devuelve la ciudad que se encuentra en la posicion recibida
    string obtenerCiudad(int posicion);

    //post: devuelve el pais que se encuentra en la posicion recibida
    string obtenerPais(int posicion);

    //post: agrega un nuevo elemento a la lista
    void agregar(string codigo_iata, string nombre_aeropuerto, string ciudad, string pais);

    ~Lista();
private:
    //post: devuelve el nodo que se encuentra en la posicion recibida o nullptr si no lo encuentra
	Nodo<Tipo>* obtenerNodo(int posicion);

};

template < typename Tipo >
Lista<Tipo>::Lista(){
    cantidadDeElementos = 0;
    ultimo = nullptr;
    primero =  nullptr;
}

template < typename Tipo >
int Lista<Tipo>::obtenerCantidadDeElementos(){
    return cantidadDeElementos;
}

template < typename Tipo >
int Lista<Tipo>::obtenerPosicion(string nombre) {
    bool elementoEncontrado = false;
    int i = 0;
    Nodo<Tipo>* auxiliar = primero;

    while(!elementoEncontrado && i < cantidadDeElementos){
        if(auxiliar -> obtenerCodigoIATA() == nombre){
            elementoEncontrado = true;
        }
        i++;
        auxiliar = auxiliar -> obtenerSiguiente();
    }

    if(!elementoEncontrado){
        return POSICION_NO_ENCONTRADA;
    }
    return i - 1;
}

template < typename Tipo >
void Lista<Tipo>::agregar(string codigo_iata, string nombre_aeropuerto, string ciudad, string pais) {
    Nodo<Tipo>* nuevoNodo = new Nodo<Tipo>(codigo_iata, nombre_aeropuerto, ciudad, pais);
    if(primero == nullptr){
        primero = nuevoNodo;
        ultimo = primero;
    } else {
        ultimo -> asignarSiguiente(nuevoNodo);
        ultimo = nuevoNodo;
    }
    cantidadDeElementos++;
}

template<typename Tipo>
Lista<Tipo>::~Lista() {
    Nodo<Tipo>* siguiente;
    while(primero != nullptr){
        siguiente = primero -> obtenerSiguiente();
        delete primero;
        primero = siguiente;
    }
}

template<typename Tipo>
string Lista<Tipo>::obtenerCodigoIATA(int posicion) {
    return obtenerNodo(posicion) -> obtenerCodigoIATA();
}

template<typename Tipo>
string Lista<Tipo>::obtenerNombreAeropuerto(int posicion) {
    return obtenerNodo(posicion) -> obtenerNombreAeropuerto();
}

template<typename Tipo>
string Lista<Tipo>::obtenerCiudad(int posicion) {
    return obtenerNodo(posicion) -> obtenerCiudad();
}

template<typename Tipo>
string Lista<Tipo>::obtenerPais(int posicion) {
    return obtenerNodo(posicion) -> obtenerPais();
}

template<typename Tipo>
Nodo<Tipo>* Lista<Tipo>::obtenerNodo(int posicion) {
    int i = 0;
    Nodo<Tipo>* auxiliar = primero;

    if(posicion > cantidadDeElementos){
        return nullptr;
    }

    while(i != posicion - 1){
        auxiliar = auxiliar -> obtenerSiguiente();
        i++;
    }
    return auxiliar;
}
#endif //GRAFOS_LISTA_H
