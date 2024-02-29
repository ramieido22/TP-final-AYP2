#include "Vuelo.h"

Vuelo::Vuelo(string codigoIATA, string nombreAeropuerto, string ciudad, string pais) {
    this->codigoIATA = codigoIATA;
    this->nombreAeropuerto = nombreAeropuerto;
    this->ciudad = ciudad;
    this->pais = pais;
}

string Vuelo::obtenerCodigoIATA() {
    return this->codigoIATA;
}

string Vuelo::obtenerNombreAeropuerto() {
    return this->nombreAeropuerto;
}

string Vuelo::obtenerCiudad() {
    return this->ciudad;
}

string Vuelo::obtenerPais() {
    return this->pais;
}

Vuelo::~Vuelo() {}
