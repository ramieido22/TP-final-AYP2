#include "Vuelo.h"

Vuelo::Vuelo(string codigo_iata, string nombre_aeropuerto, string ciudad, string pais) {
    this->codigo_iata = codigo_iata;
    this->nombre_aeropuerto = nombre_aeropuerto;
    this->ciudad = ciudad;
    this->pais = pais;
}

string Vuelo::obtenerCodigoIATA() {
    return this->codigo_iata;
}

string Vuelo::obtenerNombreAeropuerto() {
    return this->nombre_aeropuerto;
}

string Vuelo::obtenerCiudad() {
    return this->ciudad;
}

string Vuelo::obtenerPais() {
    return this->pais;
}

Vuelo::~Vuelo() {}
