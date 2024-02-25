#ifndef INTERFACES_H
#define INTERFACES_H
#include <iostream>
#include "aeropuerto.h"
#include "tabla_iata.h"
#include "hash.h"
#include "funciones.h"

using namespace std;

//pre: -- 
//post: Muestra el menu de eleccion de hash
int eleccion_del_hash();

//pre: --
//post: Muestra el menu de eleccion de que realizar con el Aeropuerto
int menu_aeropuerto();

//pre: -- 
//post: Muestra el menu de eleccion para agregar o seleccionar un Aeropuerto
int eleccion_agregar_o_seleccionar();

//pre: -- 
//post: Interfaz para introducir el nombre de la ciudad y devuelve el objeto aeropuerto asociado en el Hash
Aeropuerto* seleccionar_ciudad(Hash<string,Aeropuerto>* hash_aeropuertos,Tabla_iata* tabla);

//pre: --
//post: Muestra el menu para elegir un dato en particular del Aeropuerto
int menu_aeropuerto_datos();

//pre: Haber inicializado el hash y la tabla
//post: Realiza el bucle de selecciones de usuario
void bucle_buscador(Hash<string,Aeropuerto>* hash_aeropuertos,Tabla_iata* tabla);



#endif //INTERFACES_H
