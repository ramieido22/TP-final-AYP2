#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <iostream>
#include "hash.h"
#include <fstream>
#include "tabla_iata.h"
#include "interfaces.h"
using namespace std;

bool cargar_hash(Hash<string,Aeropuerto>* hash_aeropuertos, Tabla_iata* tabla);

void eleccion_de_datos_aeropuertos_resultado(int eleccion,Aeropuerto* aeropuerto);

Aeropuerto* crear_nuevo_aeropuerto();
void resolucion_opciones_aeropuerto(int eleccion,Aeropuerto* aeropuerto,Hash<string,Aeropuerto>* hash_aeropuertos,Tabla_iata* tabla);
#endif //FUNCIONES_H
