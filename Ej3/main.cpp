#include "Grafo.h"

int main() {

    Grafo grafo;

    grafo.llenarVuelos();
    string codigo_IATA_partida = grafo.pedirCodigoIATAPartida();
    string codigo_IATA_destino = grafo.pedirCodigoIATADestino();

    grafo.usarFloyd();
    grafo.caminoMinimo(codigo_IATA_partida, codigo_IATA_destino);

    return 0;
}
