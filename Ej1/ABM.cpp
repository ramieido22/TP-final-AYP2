
#include "ABM.h"
#include <fstream>

ABM::ABM(){
    std::ifstream file;
    file.open("aeropuertos.txt",std::ios::in);
    //
    string IATA;
    string nombre;
    string ciudad;
    string pais;
    double area;
    int entero1;
    int entero2;
    int entero3;
    //
    this->datos_aeropuertos = new Aeropuerto[5];
    int i=0;
    while ( file >> IATA && file >> nombre && file >> ciudad && file >> pais && file >> area && file >> entero1 && file >> entero2 && file >> entero3 ){
        this->datos_aeropuertos[i] = Aeropuerto(IATA,nombre,ciudad,pais,area,entero1,entero2,entero3);
        this->aeropuertos.insertar(IATA,&(this->datos_aeropuertos[i]));
        i++;
    }
    //
    file.close();
}

//////////// METODOS INTERNOS /////////////////////

int ABM::cantidad(){
    return this->aeropuertos.cantidad();
}

/////////// METODOS PUBLICOS ////////////////////



//////////// DESTRUCTOR /////////////////////

ABM::~ABM(){
    delete [] this->datos_aeropuertos;
}