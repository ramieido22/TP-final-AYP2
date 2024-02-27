
#include "ABM.h"
#include <fstream>

using std::cout;
using std::cin;
using std::endl;

ABM::ABM(){
    std::ifstream file;
    file.open("aeropuertos.txt",std::ios::in);
    //
    string IATA, nombre, ciudad, pais;
    double area;
    int cantidad_terminales,destinos_nacionales,destinos_internacionales;
    Aeropuerto* aux;
    //
    int i=1;
    while ( file >> IATA && file >> nombre && file >> ciudad && file >> pais && file >> area && file >> cantidad_terminales && file >> destinos_nacionales && file >> destinos_internacionales ){
        aux = new Aeropuerto(IATA,nombre,ciudad,pais,area,cantidad_terminales,destinos_nacionales,destinos_internacionales);
        this->datos_aeropuertos.alta(aux,i);
        this->aeropuertos.insertar(IATA,aux);
        this->ciudad_IATA.alta(Code_Aeropuerto(IATA,ciudad),1);
        i++;
    }
    //
    file.close();
}

//////////// METODOS INTERNOS /////////////////////

int ABM::cantidad(){
    return this->aeropuertos.cantidad();
}

bool ABM::cancelarOperacion(){
    int operacion;
    //
    cout << "Si desea cancelar la operación marque 1: " ;
    cin >> operacion;
    //
    return ( operacion == 1 );
}

void ABM::preguntarCiudad(string &ciudad){
    cout << "Introduza el nombre de la ciudad que desea consultar su aeropuerto \n";
    cout << "Atención: si el nombre contiene espacios hay que reemplazarlos por '-'  \n";
    cout << "Ciudad: ";
    cin >> ciudad;
}

/////////// METODOS PUBLICOS ////////////////////

void ABM::administrar(){
    cout << "Arrancando el administrador de aeropuertos" << endl;
    //
    OPCION_MENU opcion;
    do {
        this->menu_usuario.pregunarOpcionUsuario();
        //
        opcion = this->menu_usuario.obtenerOpcionUsuario();
        switch (opcion){
            case ALTA:
                this->alta();
                break;
            case CONSULTA:
                this->consulta();
                break;
            case CONSULTA_GENERAL:
                this->consultaGeneral();
                break;
            case BAJA:
                this->baja();
                break;
            case SALIDA:
                cout << "Cerrando el programa, Gracias por usarlo!" << endl;
                break;
            default:
                cout << "La opcíon elegida es invalida." << endl;
                break;
        }
    } while ( opcion != SALIDA );
}

void ABM::alta(){
    cout << "Cargue los datos del nuevo aeropuerto: \n";
    cout << "NOTA: los espacios deben ser reemplazados por '-' \n";
    //
    string IATA, nombre, ciudad, pais;
    double area;
    int cantidad_terminales, destinos_nacionales, destinos_internacionales;
    Aeropuerto* aux;
    //
    bool valido = false;
    bool cancela = false;
    //
    while ( !valido && !cancela ){
        cout << "Nombre del Aeropuerto: ";
        cin >> nombre;
        //
        cout << "Codigo del Aeropuerto IATA: ";
        cin >> IATA;
        //
        if ( !this->aeropuertos.estaEnArbol(IATA) ){
            valido = true;
        } else {
            cout << "El aeropuerto ya fue cargado anteriormente." << std::endl;
            cancela = this->cancelarOperacion();
        }
    }
    //
    if ( cancela ){
        return;
    }
    //
    cout << "Ciudad del Aeropuerto: ";
    cin >> ciudad;
    //
    cout << "Pais del Aeropuerto: ";
    cin >> pais;
    //
    cout << "Area del Aeropuerto: ";
    cin >> area;
    //
    cout << "Cantidad de Terminales del Aeropuerto: ";
    cin >> cantidad_terminales;
    //
    cout << "Destinos Nacionales del Aeropuerto: ";
    cin >> destinos_nacionales;
    //
    cout << "Destinos Internacionales del Aeropuerto: ";
    cin >> destinos_internacionales;
    //
    aux = new Aeropuerto(IATA,nombre,ciudad,pais,area,cantidad_terminales,destinos_nacionales,destinos_internacionales);
    this->datos_aeropuertos.alta(aux,1);
    this->aeropuertos.insertar(IATA,aux);
    this->ciudad_IATA.alta(Code_Aeropuerto(IATA,ciudad),1);
    cout << "Los datos fueron cargados con exito." << std::endl;
}

void ABM::baja(){
    string ciudad;
    bool cancela = false;
    bool valido = false;
    Code_Aeropuerto codigo;
    int indice_tabla;
    //
    while ( !valido && !cancela ){
        this->preguntarCiudad(ciudad);
        codigo.cambiarCiudad(ciudad);
        indice_tabla = this->ciudad_IATA.buscarPosicion(codigo);
        //
        if ( indice_tabla > 0 ){
            valido = true;
        } else {
            cout << "El aeropuerto no se encuentra en los datos del sistema" << endl;
            cancela = this->cancelarOperacion();
        }
    }
    //
    if ( !cancela ){
        string codigo_IATA = this->ciudad_IATA.buscarDato(indice_tabla).obtenerIATA();
        Aeropuerto* buscado = this->aeropuertos.obtenerDato(codigo_IATA);
        int posicion_en_lista = this->datos_aeropuertos.buscarPosicion(buscado);
        //
        this->ciudad_IATA.baja(indice_tabla);
        this->aeropuertos.eliminar(buscado->obtenerIATA());
        this->datos_aeropuertos.baja(posicion_en_lista);
        cout << "El aeropuerto: " << buscado->obtenerNombre() << " fue eliminado con exito!" << endl;
        delete buscado;
    }
}

void ABM::consulta(){
    string ciudad;
    bool valido = false;
    bool cancela = false;
    Code_Aeropuerto codigo;
    int indice_tabla;
    //
    while ( !valido && !cancela ){
        this->preguntarCiudad(ciudad);
        codigo.cambiarCiudad(ciudad);
        indice_tabla = this->ciudad_IATA.buscarPosicion(codigo);
        //
        if ( indice_tabla > 0 ){
            valido = true;
        } else {
            cout << "La ciudad introducida no tiene un aeropuerto asociado en los datos." << endl;
            cancela = this->cancelarOperacion();   
        }
    }
    //
    if ( cancela ){
        return;
    } else {
        string codigo_IATA = this->ciudad_IATA.buscarDato(indice_tabla).obtenerIATA();
        Aeropuerto* buscado = this->aeropuertos.obtenerDato(codigo_IATA);
        buscado->mostrarDatos();
    }
}

void ABM::consultaGeneral(){
    if ( this->datos_aeropuertos.esVacia() ){
        cout << "No se encuentran datos de ningun aeropuerto " << endl;
    } else {
        this->datos_aeropuertos.reiniciarCursor();
        while ( !this->datos_aeropuertos.finalCursor() ){
            this->datos_aeropuertos.moverCursor()->mostrarDatos();
        }
    }
}

//////////// DESTRUCTOR /////////////////////

ABM::~ABM(){
    //
    std::ofstream file;
    file.open("aeropuertos.txt",std::ios::out);
    //
    Aeropuerto* aux;
    while ( !this->datos_aeropuertos.esVacia() ){
        aux = this->datos_aeropuertos.buscarDato(1);
        //
        file << aux->obtenerIATA() << " ";
        file << aux->obtenerNombre() << " ";
        file << aux->obtenerCiudad() << " ";
        file << aux->obtenerPais() << " ";
        file << aux->obtenerArea() << " ";
        file << aux->obtenerCantidadTerminales() << " ";
        file << aux->obtenerDestinosNacionales() << " ";
        file << aux->obtenerDestinosInternacionales() << "\n";
        //
        this->datos_aeropuertos.baja(1);
        delete aux;
        aux = nullptr;
    }
    //
    file.close();
}