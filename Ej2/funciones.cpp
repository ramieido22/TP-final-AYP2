#include "funciones.h"

bool cargar_hash(Hash<string,Aeropuerto>* hash_aeropuertos, Tabla_iata* tabla){
    string codigo, nombre, ciudad, pais;
    ifstream archivo_de_aeropuertos;
    float superficie;
    int cantidad_terminales, destinos_nacionales, destinos_internacionales;
    
    archivo_de_aeropuertos.open("aeropuertos.txt");
    if(!archivo_de_aeropuertos.is_open()) {  //
        cout << "No se pudo abrir el archivo" << endl;
        return false;
    }
    while (archivo_de_aeropuertos >> codigo >> nombre >> ciudad >> pais >> superficie >> cantidad_terminales >> destinos_nacionales >> destinos_internacionales ){
        Aeropuerto*  aeropuerto = new Aeropuerto(codigo,nombre,ciudad,pais,superficie,cantidad_terminales,destinos_nacionales ,destinos_internacionales);
        tabla->agregar_ciudad_iata(ciudad,codigo);
        hash_aeropuertos->agregar(codigo,aeropuerto);
    }
    archivo_de_aeropuertos.close();
    return true;
}

void eleccion_de_datos_aeropuertos_resultado(int eleccion,Aeropuerto* aeropuerto){
    switch (eleccion) {
    {
    case 1:
        cout << "El codigo IATA del aeropuerto es: " << aeropuerto->ver_codigo_IATA() << endl;
        break;
    case 2:
        cout << "El nombre del aeropuerto es: " << aeropuerto->ver_nombre() << endl;
        break;
    case 3:
        cout << "La ciudad del aeropuerto es: " << aeropuerto->ver_ciudad() << endl;
        break;
    case 4:
        cout << "El pais del aeropuerto es: " << aeropuerto->ver_pais() << endl;
        break;
    case 5:
        cout << "La superficie del aeropuerto es: " << aeropuerto->ver_superficie() << endl;
        break;
    case 6:
        cout << "La cantidad de terminales del aeropuerto es: " << aeropuerto->ver_cantidad_terminales() << endl;
        break;
    case 7:
        cout << "Los destinos nacionales del aeropuerto son: " << endl;
        aeropuerto->ver_destinos_nacionales();
        break;
    case 8:
        cout << "Los destinos internacionales del aeropuerto son: " << endl;
        aeropuerto->ver_destinos_internacionales();
        break;
    default:
        break;
    }
}
}


Aeropuerto* crear_nuevo_aeropuerto(){
    string codigo, nombre, ciudad, pais;
    float superficie;
    int cantidad_terminales, destinos_nacionales, destinos_internacionales;
    cout << "Ingrese el codigo IATA del aeropuerto: ";
    cin >> codigo;
    cout << "Ingrese el nombre del aeropuerto: ";
    cin >> nombre;
    cout << "Ingrese la ciudad del aeropuerto: ";
    cin >> ciudad;
    cout << "Ingrese el pais del aeropuerto: ";
    cin >> pais;
    cout << "Ingrese la superficie del aeropuerto: ";
    cin >> superficie;
    cout << "Ingrese la cantidad de terminales del aeropuerto: ";
    cin >> cantidad_terminales;
    cout << "Ingrese la cantidad de destinos nacionales del aeropuerto: ";
    cin >> destinos_nacionales;
    cout << "Ingrese la cantidad de destinos internacionales del aeropuerto: ";
    cin >> destinos_internacionales;
    Aeropuerto*  aeropuerto = new Aeropuerto(codigo,nombre,ciudad,pais,superficie,cantidad_terminales,destinos_nacionales ,destinos_internacionales);
    return aeropuerto;
}


void resolucion_opciones_aeropuerto(int eleccion,Aeropuerto* aeropuerto,Hash<string,Aeropuerto>* hash_aeropuertos,Tabla_iata* tabla){
    string ciudad;
    int eleccion_de_datos_aeropuerto;
    switch (eleccion) {
            {
            case 1:
                cout << " "<< endl; 
                aeropuerto->imprimir();
                cout << " "<< endl; 
                break;
            case 2:
                cout << " "<< endl; 
                eleccion_de_datos_aeropuerto = menu_aeropuerto_datos();
                cout << " "<< endl; 
                eleccion_de_datos_aeropuertos_resultado(eleccion_de_datos_aeropuerto,aeropuerto);
                cout << " "<< endl; 
                break;
            case 3: 
                ciudad = aeropuerto->ver_ciudad();
                hash_aeropuertos->eliminar(aeropuerto->ver_codigo_IATA());
                tabla->eliminiar(ciudad);
                break;
            default:
                break;
            }
    }
}