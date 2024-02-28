#include "CaminoMinimo.h"

CaminoMinimo::CaminoMinimo(Lista<Vuelo> *vuelos, int **matrizAdyacencia) {
    this -> vuelos = vuelos;
    this -> matrizAdyacencia = matrizAdyacencia;
    cantidadVertices = vuelos -> obtenerCantidadDeElementos();
}
