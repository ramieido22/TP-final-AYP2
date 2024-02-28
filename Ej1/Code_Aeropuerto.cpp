
#include "Code_Aeropuerto.h"

Code_Aeropuerto::Code_Aeropuerto(string codigo,string nombre_ciudad){
    this->ciudad = nombre_ciudad;
    this->IATA = codigo;
}

string Code_Aeropuerto::obtenerIATA(){
    return this->IATA;
}

string Code_Aeropuerto::obtenerCiudad(){
    return this->ciudad;
}

void Code_Aeropuerto::cambiarIATA(string codigo){
    this->IATA = codigo;
}

void Code_Aeropuerto::cambiarCiudad(string nombre_ciudad){
    this->ciudad = nombre_ciudad;
}

bool Code_Aeropuerto::operator==(Code_Aeropuerto otro_objeto){
    return (this->ciudad == otro_objeto.ciudad);
}