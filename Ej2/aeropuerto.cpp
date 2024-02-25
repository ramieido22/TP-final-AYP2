#include "aeropuerto.h"

Aeropuerto::Aeropuerto(string codigo_IATA, string nombre, string ciudad, string pais, float superficie, int cantidad_terminales, int destinos_nacionales, int destinos_internacionales){
    this->codigo_IATA = codigo_IATA;
    this->nombre = nombre;
    this->ciudad = ciudad;
    this->pais = pais;
    this->superficie = superficie;
    this->cantidad_terminales = cantidad_terminales;
    this->destinos_nacionales = destinos_nacionales;
    this->destinos_internacionales = destinos_internacionales;
}

string Aeropuerto::ver_codigo_IATA(){
    return this->codigo_IATA;
}

string Aeropuerto::ver_nombre(){
    return this->nombre;
}

string Aeropuerto::ver_ciudad(){
    return this->ciudad;
}

string Aeropuerto::ver_pais(){
    return this->pais;
}

float Aeropuerto::ver_superficie(){
    return this->superficie;
}

int Aeropuerto::ver_cantidad_terminales(){
    return this->cantidad_terminales;
}

int Aeropuerto::ver_destinos_nacionales(){
    return this->destinos_nacionales;
}

int Aeropuerto::ver_destinos_internacionales(){
    return this->destinos_internacionales;
}

void Aeropuerto::imprimir(){
    cout << "Codigo IATA: " << this->codigo_IATA << endl;
    cout << "Nombre: " << this->nombre << endl;
    cout << "Ciudad: " << this->ciudad << endl;
    cout << "Pais: " << this->pais << endl;
    cout << "Superficie: " << this->superficie << endl;
    cout << "Cantidad de terminales: " << this->cantidad_terminales << endl;
    cout << "Destinos nacionales: " << this->destinos_nacionales << endl;
    cout << "Destinos internacionales: " << this->destinos_internacionales << endl;
}