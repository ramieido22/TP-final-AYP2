#include "Grafo.h"

int main() {

    Grafo grafo;

    grafo.llenarVuelos();
    string codigoIATApartida = grafo.pedirCodigoIATApartida();
    string codigoIATAdestino = grafo.pedirCodigoIATAdestino();

    grafo.usarFloyd();
    grafo.caminoMinimo(codigoIATApartida, codigoIATAdestino);

    return 0;
}
