#include "Grafo.h"
#include "Dijkstra.h"
#include <iostream>

Grafo::Grafo() {
    matrizDeAdyacencia = nullptr;
    vuelos = new Lista<Vuelo>();
    algoritmoCaminoMinimo = nullptr;
}

void Grafo::agregarVertice(string codigo_iata, string nombre_aeropuerto, string ciudad, string pais) {
    agrandarMatrizDeAdyacencia();
    vuelos -> agregar(codigo_iata, nombre_aeropuerto, ciudad, pais);
}

void Grafo::mostrarGrafo() {
    mostrarVertices();
    mostrarMatrizAdyacencia();
}

void Grafo::agregarCamino(string origen, string destino, int peso) {
    int posicionOrigen = vuelos ->obtenerPosicion(origen);
    int posicionDestino = vuelos ->obtenerPosicion(destino);

    if(posicionOrigen == POSICION_NO_ENCONTRADA){
        cout << "El vertice " << origen << " no existe en el grafo" << endl;
    }
    if(posicionDestino == POSICION_NO_ENCONTRADA){
        cout << "El vertice " << destino << " no existe en el grafo" << endl;
    }

    if(!(posicionDestino == POSICION_NO_ENCONTRADA || posicionOrigen == POSICION_NO_ENCONTRADA)) {
        matrizDeAdyacencia[posicionOrigen][posicionDestino] = peso;
    }
}

void Grafo::llenarVuelos() {
    ifstream archivo;
    archivo.open("vuelos.txt");
    string palabra;
    int costo_vuelo;

    while(archivo >> palabra) {
        string codigo_iata_partida = palabra;
        if(vuelos ->obtenerPosicion(codigo_iata_partida) == POSICION_NO_ENCONTRADA) {
            archivo >> palabra;
            string nombre_aeropuerto_partida = palabra;
            archivo >> palabra;
            string ciudad_partida = palabra;
            archivo >> palabra;
            string pais_partida = palabra;
            archivo >> palabra;

            agregarVertice(codigo_iata_partida, nombre_aeropuerto_partida, ciudad_partida, pais_partida);
        }
        else {
            for(int i = 1; i <= 4; i++) {
                archivo >> palabra;
            }
        }

        string codigo_iata_destino = palabra;
        if(vuelos ->obtenerPosicion(codigo_iata_destino) == POSICION_NO_ENCONTRADA) {
            archivo >> palabra;
            string nombre_aeropuerto_destino = palabra;
            archivo >> palabra;
            string ciudad_destino = palabra;
            archivo >> palabra;
            string pais_destino = palabra;
            archivo >> palabra;

            agregarVertice(codigo_iata_destino, nombre_aeropuerto_destino, ciudad_destino, pais_destino);
        }
        else {
            for(int i = 1; i <= 4; i++) {
                archivo >> palabra;
            }
        }

        stringstream palabra_convertida;
        palabra_convertida << palabra;
        palabra_convertida >> costo_vuelo;

        agregarCamino(codigo_iata_partida, codigo_iata_destino, costo_vuelo);
    }
}

string Grafo::pedirCodigoIATAPartida() {
    cout << "Ingrese el codigo IATA de partida:" << endl;
    string codigo_IATA_partida;
    int vueloPartida;
    do {
        if (vueloPartida == POSICION_NO_ENCONTRADA) {
            cout << "El codigo IATA de partida no fue encontrado, ingrese otro codigo IATA de partida:" << endl;
        }
        cin >> codigo_IATA_partida;
        vueloPartida = vuelos ->obtenerPosicion(codigo_IATA_partida);
    } while (vueloPartida == POSICION_NO_ENCONTRADA);
    return codigo_IATA_partida;
}

string Grafo::pedirCodigoIATADestino() {
    cout << "Ingrese el codigo IATA de destino:" << endl;
    string codigo_IATA_destino;
    int vueloDestino;
    do {
        if (vueloDestino == POSICION_NO_ENCONTRADA) {
            cout << "El codigo IATA de destino no fue encontrado, ingrese otro codigo IATA de destino:" << endl;
        }
        cin >> codigo_IATA_destino;
        vueloDestino = vuelos ->obtenerPosicion(codigo_IATA_destino);
    } while (vueloDestino == POSICION_NO_ENCONTRADA);
    return codigo_IATA_destino;
}

void Grafo::caminoMinimo(string origen, string destino) {
    int posicionOrigen = vuelos ->obtenerPosicion(origen);
    int posicionDestino = vuelos ->obtenerPosicion(destino);

    if(posicionOrigen == POSICION_NO_ENCONTRADA){
        cout << "El vertice " << origen << " no existe en el grafo" << endl;
    }
    if(posicionDestino == POSICION_NO_ENCONTRADA){
        cout << "El vertice " << destino << " no existe en el grafo" << endl;
    }

    caminoMinimo(posicionOrigen, posicionDestino);
}

void Grafo::agrandarMatrizDeAdyacencia() {
    int** matrizAuxiliar;
    int nuevaCantidadDeVertices = vuelos->obtenerCantidadDeElementos() + 1;

    matrizAuxiliar = new int*[nuevaCantidadDeVertices];
    for(int i = 0; i < nuevaCantidadDeVertices; i++){
        matrizAuxiliar[i] = new int[nuevaCantidadDeVertices];
    }

    copiarMatrizAdyacente(matrizAuxiliar);
    inicializarNuevoVertice(matrizAuxiliar);
    liberarMatrizAdyacencia();
    matrizDeAdyacencia = matrizAuxiliar;
}

void Grafo::copiarMatrizAdyacente(int** nuevaAdyacente) {
    for(int i = 0; i < vuelos -> obtenerCantidadDeElementos(); i++){
        for(int j = 0; j < vuelos -> obtenerCantidadDeElementos(); j++){
            nuevaAdyacente[i][j] = matrizDeAdyacencia[i][j];
        }
    }
}

void Grafo::inicializarNuevoVertice(int** nuevaAdyacente) {
    for(int i = 0; i < vuelos -> obtenerCantidadDeElementos(); i++){
        nuevaAdyacente[vuelos -> obtenerCantidadDeElementos()][i] = INFINITO;
        nuevaAdyacente[i][vuelos -> obtenerCantidadDeElementos()] = INFINITO;
    }
    nuevaAdyacente[vuelos -> obtenerCantidadDeElementos()][vuelos -> obtenerCantidadDeElementos()] = 0;
}

void Grafo::liberarMatrizAdyacencia() {
    for(int i = 0; i < vuelos -> obtenerCantidadDeElementos(); i++){
        delete[] matrizDeAdyacencia[i];
    }
    delete[] matrizDeAdyacencia;
}

Grafo::~Grafo() {
    liberarMatrizAdyacencia();
    matrizDeAdyacencia = nullptr;
    delete vuelos;
    delete algoritmoCaminoMinimo;
}

void Grafo::mostrarVertices() {
    cout << "Lista de vértices: [";
    for(int i = 0; i < vuelos -> obtenerCantidadDeElementos(); i++){
        cout << vuelos -> obtenerCodigoIATA(i + 1);
        if(i + 1 != vuelos -> obtenerCantidadDeElementos()){
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

void Grafo::mostrarMatrizAdyacencia() {
    cout << "Matriz de adyacencia:" << endl;
    for(int i = 0; i < vuelos -> obtenerCantidadDeElementos(); i++){
        for(int j = 0; j < vuelos -> obtenerCantidadDeElementos() * 2; j++) {
            if(j == vuelos -> obtenerCantidadDeElementos() * 2 - 1){
                cout << endl;
            } else if(j % 2 == 0){
                if(matrizDeAdyacencia[i][j/2] == INFINITO){
                    cout << "∞";
                } else {
                    cout << matrizDeAdyacencia[i][j/2];
                }
            } else{
                cout << "|";
            }
        }
    }
    cout << endl;
}

void Grafo::caminoMinimo(int origen, int destino) {
    algoritmoCaminoMinimo -> caminoMinimo(origen, destino);
}

void Grafo::usarFloyd() {
    delete algoritmoCaminoMinimo;
    algoritmoCaminoMinimo = new Floyd(vuelos, matrizDeAdyacencia);
}

void Grafo::usarDijkstra() {
    delete algoritmoCaminoMinimo;
    algoritmoCaminoMinimo = new Dijkstra(vuelos, matrizDeAdyacencia);
}
