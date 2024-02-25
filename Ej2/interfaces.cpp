#include "interfaces.h"


int eleccion_del_hash(){
    int eleccion;
    cout << "Bienvenido al programa" << endl;
    cout << "Elija el tipo de hash que desea utilizar: " << endl;
    cout << "1. Hash cerrado" << endl;
    cout << "2. Hash abierto" << endl;
    cin >> eleccion;
    while (eleccion < 1 || eleccion > 2) {
        cout << "Eleccion invalida, por favor elija 1 o 2" << endl;
        cin >> eleccion;
    }
    if (eleccion == 1){
        cout << "Ha elegido hash cerrado" << endl;
    } else {
        cout << "Ha elegido hash abierto" << endl;
    }
    return eleccion;
}

int menu_aeropuerto(){
    int eleccion;
    cout << "Menu principal:" << endl;
    cout << "1) Ver todos los datos relacionados al aeropuerto" <<  endl;
    cout << "2) Ver algun dato en especifico relacionado al aeropuerto"<< endl;
    cout << "3) Eliminar aeropuerto"<< endl;
    cout << "Ingrese su opccion: ";
    cin>>eleccion;

    while (eleccion<1 || eleccion >3 ){
        cout << "Opcion no valida,ingrese nuevamente: " << endl;
        cin>>eleccion;
    }
    return eleccion;
}

int menu_aeropuerto_datos(){
    int eleccion;
    cout << "1) Ver codigo IATA del aeropuerto" <<  endl;
    cout << "2) Ver nombre del aeropuerto"<< endl;
    cout << "3) Ver ciudad del aeropuerto"<< endl;
    cout << "4) Ver pais del aeropuerto" <<  endl;
    cout << "5) Ver superficie del aeropuerto"<< endl;
    cout << "6) Ver cantidad de terminales del aeropuerto"<< endl;
    cout << "7) Ver destinos nacionales del aeropuerto" <<  endl;
    cout << "8) Ver destinos internacionales del aerpuerto"<< endl;
    cout << "9) Volver al menu principal"<< endl;
    cout << "Ingrese su opcion: ";
    cin>>eleccion;
    while (eleccion<1 || eleccion >9 ){
        cout << "Opcion no valida,ingrese nuevamente: " << endl;
        cin>>eleccion;
    }
    return eleccion;
}

int eleccion_agregar_o_seleccionar(){
    int eleccion;
    cout << " " << endl;
    cout << "1)Agregar un nuevo aeropuerto"<< endl;
    cout << "2)Seleccionar un aeropuerto" <<endl;
    cout << "3)Salir del programa" << endl;
    cout << "Ingrese la opcion: "<< endl;
    cin>>eleccion;
        while (eleccion<1 || eleccion >3 ){
            cout << "Opcion no valida,ingrese nuevamente: " << endl;
            cin>>eleccion;
        }
    return eleccion;
}

Aeropuerto* seleccionar_ciudad(Hash<string,Aeropuerto>* hash_aeropuertos,Tabla_iata* tabla){
    string ciudad;
    cout << "Ingrese el nombre de la ciudad que sea ver el aeropuerto respetando las mayusculas, sin tildes y con con guion medio en vez del espacio (ej: Buenos-Aires): "<< endl; 
    cin >> ciudad;
    while (!tabla->pertenece(ciudad)){
        cout << "Ciudad incorrecta o no pertenece. Vuelva a ingresar: "<<  endl;
        cin >> ciudad;
    }  
    string codigo= tabla->buscar_iata(ciudad);
    return hash_aeropuertos ->buscar(codigo);
}

void bucle_buscador(Hash<string,Aeropuerto>* hash_aeropuertos,Tabla_iata* tabla){
    int eleccion_de_datos_aeropuerto;
    int eleccion_de_menu_general = eleccion_agregar_o_seleccionar();
    Aeropuerto* nuevo_aeropuerto;
    cout << " "<< endl; 
    while (eleccion_de_menu_general != 3){
        if (eleccion_de_menu_general==1){
            nuevo_aeropuerto = crear_nuevo_aeropuerto();
            hash_aeropuertos->agregar(nuevo_aeropuerto->ver_codigo_IATA(),nuevo_aeropuerto);
            tabla->agregar_ciudad_iata(nuevo_aeropuerto->ver_ciudad(),nuevo_aeropuerto->ver_codigo_IATA());
        }else{
            Aeropuerto* aeropuerto = seleccionar_ciudad(hash_aeropuertos,tabla);
            cout << " "<< endl; 
            int eleccion_de_seleccionar_aeropuerto = menu_aeropuerto();
            resolucion_opciones_aeropuerto(eleccion_de_seleccionar_aeropuerto,aeropuerto,hash_aeropuertos,tabla);
        }
        eleccion_de_menu_general = eleccion_agregar_o_seleccionar();
    }
    cout << "Gracias por usar el programa" << endl;
}

