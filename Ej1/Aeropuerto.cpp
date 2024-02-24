
#include "Aeropuerto.h"

Aeropuerto::Aeropuerto(string IATA,string nombre,string ciudad,string pais,double area,int entero1,int entero2,int entero3){
    this->IATA = IATA;    
    this->nombre = nombre;
    this->ciudad = ciudad;
    this->pais = pais;
    this->area = area;
    this->entero1 = entero1;
    this->entero2 = entero2;
    this->entero3 = entero3;
}

/* Aeropuerto::Aeropuerto(const Aeropuerto* pn){
    this->IATA = pn->IATA;    
    this->nombre = pn->nombre;
    this->ciudad = pn->ciudad;
    this->pais = pn->pais;
    this->area = pn->area;
    this->entero1 = pn->entero1;
    this->entero2 = pn->entero2;
    this->entero3 = pn->entero3;
} */