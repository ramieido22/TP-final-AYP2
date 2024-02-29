#ifndef GRAFOS_GRAFO_H
#define GRAFOS_GRAFO_H
#include <string>
#include <fstream>
#include <sstream>
#include "Lista.h"
#include "Vuelo.h"
#include "Floyd.h"

using namespace std;

const string TEXTO = "vuelos.txt";

class Grafo {
/*ATRIBUTOS*/
private:
    int ** matrizDeAdyacencia;
    Lista<Vuelo> * vuelos;
    CaminoMinimo * algoritmoCaminoMinimo;

/*MÉTODOS*/

    //pre: tienen que existir tanto el origen como el destino. Ademas se deben haber calculado las matrices de Floyd
    //post: muestra el camino minimo entre el origen y el destino
    void caminoMinimo(int origen, int destino);

    //post: agranda dinamicamente la matriz de adyacencia
    void agrandarMatrizDeAdyacencia();

    //pre: la matriz que se le envie ya debe tener memoria reservada
    //post: copia la matriz de adyacencia en la nueva matriz
    void copiarMatrizAdyacente(int** nuevaAdyacente);

    //post inicializa un nuevo vertice en la matriz de adyacencia con un valor de infinito
    void inicializarNuevoVertice(int** nuevaAdyacente);

    //post libera la memoria de la matriz de adyacencia
    void liberarMatrizAdyacencia();

    //post: imprime por pantalla los vertices del grafo
    void mostrarVertices();

    //post: imprime por pantalla la matriz de adyacencia
    void mostrarMatrizAdyacencia();
public:

    Grafo();
    //pre: No hay vertices repetidos en nombre
    //post: agrega un nuevo vertice al grafo
    void agregarVertice(string codigoIATA, string nombreAeropuerto, string ciudad, string pais);

    //pre: el texto tiene que tener escrita 7 palabras por linea, la ultima siendo un numero
    //post: llena la matriz con los datos encontrados en el texto
    void llenarVuelos();

    //post: le pide al usuario que ingrese un codigo IATA para eligir una estacion de partida, si la estacion es incorrecta pide un reingreso
    string pedirCodigoIATApartida();

    //post: le pide al usuario que ingrese un codigo IATA para eligir una estacion de destino, si la estacion es incorrecta pide un reingreso
    string pedirCodigoIATAdestino();

    //pre: se debe tener un algortimo para calcular el camino mínimo previamente elegido
    //post: muestra por terminal el camino mínimo desde un origen a un destino
    void caminoMinimo(string origen, string destino);

    //pre: el peso es un valor positivo
    //post: Ajusta la matriz de adyacencia con el peso ingresado
    void agregarCamino(string origen, string destino, int peso);

    //post: imprime por pantalla el grafo
    void mostrarGrafo();

    //post: selecciona el algortimo de Floyd para calcular el camino mínimo
    void usarFloyd();

    //post: selecciona el algortimo de Dijkstra para calcular el camino mínimo
    void usarDijkstra();

    ~Grafo();
};


#endif //GRAFOS_GRAFO_H
