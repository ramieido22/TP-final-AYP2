
#include "Aeropuerto.h"

using std::cout;
using std::endl;

///////////// CONSTRUCTOR //////////////////

Aeropuerto::Aeropuerto(string IATA,string nombre,string ciudad,string pais,double area,int cantidad_terminales,int destinos_nacionales,int destinos_internacionales){
    this->IATA = IATA;    
    this->nombre = nombre;
    this->ciudad = ciudad;
    this->pais = pais;
    this->area = area;
    this->cantidad_terminales = cantidad_terminales;
    this->destinos_nacionales = destinos_nacionales;
    this->destinos_internacionales = destinos_internacionales;
}


void Aeropuerto::mostrarDatos(){
    cout << "///////////////////////////// \n";
    // cout << "/////////// Aeropuerto: " << this->nombre << " ////////////////// \n";
    cout << "Aeropuerto: " << this->nombre << "\n";
    cout << "Codigo IATA: " << this->IATA << "\n";
    cout << "Ciudad (donde esta ubicado): " << this->ciudad << "\n";
    cout << "País: " << this->pais << "\n";
    cout << "Area: " << this->area << "\n";
    cout << "Cantidad de Terminales: " << this->cantidad_terminales << "\n";
    cout << "Destinos Nacionales: " << this->destinos_nacionales << "\n";
    cout << "Destinos Internacionales: " << this->destinos_internacionales << "\n";
    cout << "///////////////////////////// " << endl;
}

///////// GETTERS /////////

string Aeropuerto::obtenerIATA(){
    return this->IATA;
}

string Aeropuerto::obtenerNombre(){
    return this->nombre;
}

string Aeropuerto::obtenerCiudad(){
    return this->ciudad;
}

string Aeropuerto::obtenerPais(){
    return this->pais;
}

double Aeropuerto::obtenerArea(){
    return this->area;
}

int Aeropuerto::obtenerCantidadTerminales(){
    return this->cantidad_terminales;
}

int Aeropuerto::obtenerDestinosNacionales(){
    return this->destinos_nacionales;
}

int Aeropuerto::obtenerDestinosInternacionales(){
    return this->destinos_internacionales;
}

bool Aeropuerto::operator==(const Aeropuerto &d){
    return ( this->IATA == d.IATA );
}