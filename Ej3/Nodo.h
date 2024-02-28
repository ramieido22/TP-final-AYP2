#ifndef GRAFOS_NODO_H
#define GRAFOS_NODO_H
#include <string>

using namespace std;

template < typename Tipo >
class Nodo {
/*ATRIBUTOS*/
private:
    Tipo* elemento;
    Nodo<Tipo>* siguiente;

/*MÉTODOS*/
public:
    Nodo(string codigo_iata, string nombre_aeropuerto, string ciudad, string pais);

    //post: devuelve el nodo siguiente.
    Nodo<Tipo>* obtenerSiguiente();

    //post: devuelve el codigo IATA del nodo
    string obtenerCodigoIATA();

    //post: devuelve el nombre del aeropuerto del nodo
    string obtenerNombreAeropuerto();

    //post: devuelve la ciudad del nodo
    string obtenerCiudad();

    //post: devuelve el pais del nodo
    string obtenerPais();

    //post: le asigna como siguiente el nodo recibido
    void asignarSiguiente(Nodo<Tipo>* siguiente);

    ~Nodo();
};

template<typename Tipo>
Nodo<Tipo>::Nodo(string codigo_iata, string nombre_aeropuerto, string ciudad, string pais) {
    elemento = new Tipo(codigo_iata, nombre_aeropuerto, ciudad, pais);
    siguiente = nullptr;
}

template<typename Tipo>
Nodo<Tipo> *Nodo<Tipo>::obtenerSiguiente() {
    return siguiente;
}

template<typename Tipo>
string Nodo<Tipo>::obtenerCodigoIATA() {
    return elemento -> obtenerCodigoIATA();
}

template<typename Tipo>
string Nodo<Tipo>::obtenerNombreAeropuerto() {
    return elemento -> obtenerNombreAeropuerto();
}

template<typename Tipo>
string Nodo<Tipo>::obtenerCiudad() {
    return elemento -> obtenerCiudad();
}

template<typename Tipo>
string Nodo<Tipo>::obtenerPais() {
    return elemento -> obtenerPais();
}

template<typename Tipo>
void Nodo<Tipo>::asignarSiguiente(Nodo<Tipo> *siguiente) {
    this -> siguiente = siguiente;
}

template<typename Tipo>
Nodo<Tipo>::~Nodo() {
    delete elemento;
}


#endif //GRAFOS_NODO_H
