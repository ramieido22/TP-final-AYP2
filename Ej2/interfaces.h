#ifndef INTERFACES_H
#define INTERFACES_H
#include <iostream>
#include "aeropuerto.h"
#include "tabla_iata.h"
#include "hash.h"
#include "funciones.h"

using namespace std;

int eleccion_del_hash();

int menu_aeropuerto();

int eleccion_agregar_o_seleccionar();

Aeropuerto* seleccionar_ciudad(Hash<string,Aeropuerto>* hash_aeropuertos,Tabla_iata* tabla);

int menu_aeropuerto_datos();

void bucle_buscador(Hash<string,Aeropuerto>* hash_aeropuertos,Tabla_iata* tabla);



#endif //INTERFACES_H
