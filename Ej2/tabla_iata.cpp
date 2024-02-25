#include "tabla_iata.h"

Tabla_iata::Tabla_iata() {
    this->capacidad = 10; 
    this->tamanio = 0; 
    this->tabla = new Ciudad_iata[capacidad]; 
}

void Tabla_iata::redimensionar(){
     int nueva_capacidad = capacidad * 2; 
    Ciudad_iata* nueva_tabla = new Ciudad_iata[nueva_capacidad]; 
    for (int i = 0; i < this->tamanio; ++i) {
        nueva_tabla[i] = tabla[i]; 
    }
    delete[] tabla; 
    this->tabla = nueva_tabla; 
    this->capacidad = nueva_capacidad; 
}

void Tabla_iata::agregar_ciudad_iata(string ciudad, string codigo_iata){
    if (this->tamanio == this->capacidad) {
        redimensionar(); }
    tabla[tamanio].ciudad = ciudad; 
    tabla[tamanio].codigo_iata = codigo_iata; 
    tamanio++;
}
bool Tabla_iata::pertenece(string ciudad) {
    for (int i = 0; i < this->tamanio; i++) {
        if (tabla[i].ciudad == ciudad) {
            return true; 
        }
    }
    return false; 
}



void Tabla_iata::eliminiar(string ciudad){
    if (pertenece(ciudad)){
        for (int i = 0; i <this->tamanio; ++i) {
            if (this->tabla[i].ciudad == ciudad) {
                for (int j = i; j < tamanio - 1; ++j) {
                    this->tabla[j] = tabla[j + 1];
                }
                tamanio--;
                return;
            }
        }
    }
}
    
string Tabla_iata::buscar_iata (string ciudad){
    for (int i = 0; i < this->tamanio; ++i) {
            if (this->tabla[i].ciudad == ciudad) {
                return this->tabla[i].codigo_iata;
            }
        }
    return "";
}

//Destructor
Tabla_iata::~Tabla_iata(){
    delete[] this->tabla;
}