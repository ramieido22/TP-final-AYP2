#include "interfaces.h"

using namespace std;

int main(){

    Hash<string, Aeropuerto>* hash_aeropuertos = new Hash<string, Aeropuerto>();
    Tabla_iata* tabla_ciu_iata = new  Tabla_iata();

    int eleccion = eleccion_del_hash();
    
    if (eleccion == 1){
        hash_aeropuertos->dar_funcionalidad(CERRADO);
    } else{
        hash_aeropuertos->dar_funcionalidad(ABIERTO);
    }
    hash_aeropuertos->crear_hash_abierto_o_cerrado();

    if (!cargar_hash(hash_aeropuertos,tabla_ciu_iata)){
        cout << "No se pudo cargar el hash" << endl;
        return 1;
    }
    
    bucle_buscador(hash_aeropuertos,tabla_ciu_iata);
    
    delete hash_aeropuertos;
    delete tabla_ciu_iata;
    return 0;
}