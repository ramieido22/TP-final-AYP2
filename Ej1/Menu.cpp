
#include <iostream>
#include "Menu.h"



void Menu::pregunarOpcionUsuario(){
    std::cout << "Menu para administrar los aeropuertos \n";
    std::cout << "---------------------------\n";
    std::cout << "Marque el numero de la operacion: \n";
    //
    std::cout << "1. Mostrar los datos de todos los aeropuertos: \n";
    std::cout << "2. Consultar los datos de un aeropuerto especifico: \n";
    std::cout << "3. Dar de alta un aeropuerto \n";
    std::cout << "4. Dar de baja un aeropuerto \n";
    std::cout << "5. Salida \n";
    //
    std::cout << "Marque: ";
    std::cin >> this->opcion;
}

OPCION_MENU Menu::obtenerOpcionUsuario(){
    return static_cast<OPCION_MENU>(this->opcion);
}