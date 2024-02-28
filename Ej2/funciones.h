#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <fstream>
#include "interfaces.h"

using namespace std;

//pre: --
//post: Carga el hash y la tabla a partir de los archivos
bool cargar_hash(Hash<string,Aeropuerto>* hash_aeropuertos, Tabla_iata* tabla);

//pre: --
//post: Realiza la logica de la eleccion de usuario en los datos del Aeropuerto
void eleccion_de_datos_aeropuertos_resultado(int eleccion,Aeropuerto* aeropuerto);

//pre: --
//post: Crea un nuevo aeropuerto a partir de los datos ingresados por el usuario
Aeropuerto* crear_nuevo_aeropuerto();

//pre: --
//post: Realiza la logica de la eleccion de usuario en las opciones del Aeropuerto
void resolucion_opciones_aeropuerto(int eleccion,Aeropuerto* aeropuerto,Hash<string,Aeropuerto>* hash_aeropuertos,Tabla_iata* tabla);

//pre: --
//post: Realiza la logica de la eleccion de usuario en el hash
void definir_estado_hash(int eleccion, Hash<string, Aeropuerto>* hash_aeropuertos);

#endif //FUNCIONES_H
