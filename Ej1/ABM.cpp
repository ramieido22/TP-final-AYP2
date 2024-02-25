
#include "ABM.h"
#include <fstream>

using std::cout;
using std::cin;

ABM::ABM(){
    std::ifstream file;
    file.open("aeropuertos.txt",std::ios::in);
    //
    string IATA;
    string nombre;
    string ciudad;
    string pais;
    double area;
    int cantidad_terminales;
    int destinos_nacionales;
    int destinos_internacionales;
    //
    while ( file >> IATA && file >> nombre && file >> ciudad && file >> pais && file >> area && file >> cantidad_terminales && file >> destinos_nacionales && file >> destinos_internacionales ){
        this->datos_aeropuertos.alta(new Aeropuerto(IATA,nombre,ciudad,pais,area,cantidad_terminales,destinos_nacionales,destinos_internacionales));
        this->datos_aeropuertos.consulta()->mostrarDatos();
        this->aeropuertos.insertar(IATA,this->datos_aeropuertos.consulta());
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

/////////// METODOS PUBLICOS ////////////////////

void ABM::administrar(){
    OPCION_MENU opcion;
    do {
        this->menu_usuario.pregunarOpcionUsuario();
        //
        opcion = this->menu_usuario.obtenerOpcionUsuario();
        if ( opcion == ALTA ){
            this->alta();
        } else if ( opcion == CONSULTA ){
            cout << "Consulta un aeropuerto" << std::endl;
        } else if ( opcion == BAJA ){
            cout << "Da de baja un aeropuerto" << std::endl;
        }
    } while ( opcion != SALIDA );
}

void ABM::alta(){
    cout << "Cargue los datos del nuevo aeropuerto: \n";
    //
    string IATA;
    string nombre;
    string ciudad;
    string pais;
    double area;
    int cantidad_terminales;
    int destinos_nacionales;
    int destinos_internacionales;
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
        if ( !this->aeropuertos.buscar(IATA) ){
            valido = true;
            cancela = true;
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
    this->datos_aeropuertos.alta(new Aeropuerto(IATA,nombre,ciudad,pais,area,cantidad_terminales,destinos_nacionales,destinos_internacionales));
    this->aeropuertos.insertar(IATA,this->datos_aeropuertos.consulta());
    cout << "Los datos fueron cargados con exito." << std::endl;
}

/* void ABM::baja(){
    string IATA;
    //
    cout << "Introduza el codigo IATA del aeropuerto que desea eliminar \n";
    cin >> IATA;
    //
} */

//////////// DESTRUCTOR /////////////////////

ABM::~ABM(){
    //
    std::ofstream file;
    file.open("aeropuertos.txt",std::ios::out);
    //
    Aeropuerto *aux;
    while ( !this->datos_aeropuertos.es_vacia() ){
        aux = this->datos_aeropuertos.consulta();
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
        this->datos_aeropuertos.baja();
        delete aux;
        aux = nullptr;
    }
    //
    file.close();
}