#include "Floyd.h"

int ** Floyd::crearMatrizCaminos(){

    int ** caminos = new int*[cantidadVertices];
    for(int i = 0; i < cantidadVertices; i++){
        caminos[i] = new int[cantidadVertices];
    }

    for(int i = 0; i < cantidadVertices; i++){
        for(int j = 0; j < cantidadVertices; j++) {
            caminos[i][j] = j;
        }
    }

    return caminos;
}

int ** Floyd::crearMatrizCostos(int ** matrizAdyacencia){

    int ** costos = new int*[cantidadVertices];
    for(int i = 0; i < cantidadVertices; i++){
        costos[i] = new int[cantidadVertices];
    }

    for(int i = 0; i < cantidadVertices; i++){
        for(int j = 0; j < cantidadVertices; j++){
            costos[i][j] = matrizAdyacencia[i][j];
        }
    }
    return costos;
}

void Floyd::mostrarMatrices(){
    cout << "Matriz de costos:      ||           Matriz de caminos:" << endl;
    string filaCostos;
    string filaCaminos;
    for(int i = 0; i < cantidadVertices; i++){
        for(int j = 0; j < cantidadVertices * 2; j++) {
            if(j == cantidadVertices * 2 - 1){
                filaCostos += "            ||           ";
                filaCaminos += "\n";
            } else if(j % 2 == 0){
                if(matrizCostos[i][j/2] == INFINITO){
                    filaCostos += "∞";
                } else {
                    filaCostos += to_string(matrizCostos[i][j/2]);
                }

                if(matrizCaminos[i][j/2] == POSICION_NO_ENCONTRADA){
                    filaCaminos += "-";
                } else {
                    filaCaminos += to_string(matrizCaminos[i][j/2]);
                }
            } else{
                filaCaminos += "|";
                filaCostos += "|";
            }
        }
        cout << filaCostos << filaCaminos;
        filaCostos = "";
        filaCaminos = "";
    }
    cout << endl;
}

void Floyd::calcularMatrices() {

    cantidadVertices = vuelos -> obtenerCantidadDeElementos();
    matrizCostos = crearMatrizCostos(matrizAdyacencia);
    matrizCaminos = crearMatrizCaminos();

    for(int i = 0; i < cantidadVertices; i++) {
        for(int posicion_origen = 0; posicion_origen < cantidadVertices; posicion_origen++) {
            for(int posicion_destino = 0; posicion_destino < cantidadVertices; posicion_destino++) {
                if ((posicion_origen != i) && (posicion_destino != i) && (matrizCostos[i][posicion_destino] + matrizCostos[posicion_origen][i] < matrizCostos[posicion_origen][posicion_destino])) {
                    matrizCostos[posicion_origen][posicion_destino] = matrizCostos[i][posicion_destino] + matrizCostos[posicion_origen][i];
                    matrizCaminos[posicion_origen][posicion_destino] = matrizCaminos[posicion_origen][i];
                }
            }
        }
    }
}

void Floyd::caminoMinimo(int origen, int destino) {

    if(matrizCaminos[origen][destino] == POSICION_NO_ENCONTRADA){
        cout << "No hay un camino que conecte " <<  vuelos->obtenerCodigoIATA(origen + 1) << " con " << vuelos->obtenerCodigoIATA(destino + 1);
    } else {
        int origen_aux = origen;
        cout << "El camino minimo que une " <<  vuelos->obtenerCodigoIATA(origen + 1) << " con " << vuelos->obtenerCodigoIATA(destino + 1) << " es el siguiente: " << endl;
        cout << "\n" << "      Codigo IATA - Aeropuerto - Ciudad - Pais - Precio" << endl;
        cout << "De    " << vuelos->obtenerCodigoIATA(origen + 1) << " " << vuelos->obtenerNombreAeropuerto(origen + 1) << " " << vuelos->obtenerCiudad(origen + 1) << " " << vuelos->obtenerPais(origen + 1) << endl;
        do {
            int origen_costo = origen;
            origen = matrizCaminos[origen][destino];
            cout << "Hasta " << vuelos->obtenerCodigoIATA(origen + 1) << " " << vuelos->obtenerNombreAeropuerto(origen + 1) << " " << vuelos->obtenerCiudad(origen + 1) << " " << vuelos->obtenerPais(origen + 1) << " " << matrizCostos[origen_costo][origen] << endl;
        } while(origen != destino);
        cout << "\n" << "Costo total: " << matrizCostos[origen_aux][destino] << endl;
    }
    cout << endl;

}

void Floyd::liberarMatrices() {
    if(matrizCostos != nullptr && matrizCaminos != nullptr){
        for(int i = 0; i < cantidadVertices; i++){
            delete[] matrizCostos[i];
            delete[] matrizCaminos[i];
        }
        delete[] matrizCostos;
        delete[] matrizCaminos;

        matrizCostos = nullptr;
        matrizCaminos = nullptr;
    }
}

Floyd::~Floyd(){
    liberarMatrices();
}

Floyd::Floyd(Lista<Vuelo> *vuelos, int ** matrizAdyacencia) : CaminoMinimo(vuelos, matrizAdyacencia){
    calcularMatrices();
}




