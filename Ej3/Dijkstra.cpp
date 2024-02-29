#include "Dijkstra.h"

Dijkstra::Dijkstra(Lista<Vuelo> *vuelos, int **matrizAdyacencia) : CaminoMinimo(vuelos, matrizAdyacencia) {
    verticesVisitados = new bool[cantidadVertices];
    distancia = new int[cantidadVertices];
    recorrido = new int[cantidadVertices];
}

void Dijkstra::caminoMinimo(int origen, int destino) {
    inicializarVisitados(origen);
    inicializarDistancia(matrizAdyacencia[origen]);
    inicializarRecorrido(origen);

    while(!seVisitaronTodosLosVertives()) {
    	int vertice = verticeMinimaDistancia();
    	actualizarDistancia(vertice);
        verticesVisitados[vertice] = true;
    }

    mostrarRecorrido(origen, destino);
}

bool Dijkstra::seVisitaronTodosLosVertives() {
	int i = 0;
	bool respuesta = false;
	while((i < cantidadVertices) && (verticesVisitados[i] == true)) {
		i++;
	}
	if (i == cantidadVertices) {
		respuesta = true;
	}
	return respuesta;
}

int Dijkstra::verticeMinimaDistancia() {
    int minimaDistancia = INFINITO;
    int minimoVertice;

    for(int i = 0; i < cantidadVertices; i++){
        if(!verticesVisitados[i] && distancia[i] <= minimaDistancia){
            minimaDistancia = distancia[i];
            minimoVertice = i;
        }
    }

    return minimoVertice;
}

void Dijkstra::inicializarVisitados(int origen) {
    for(int i = 0; i < cantidadVertices; i++)
        verticesVisitados[i] = false;
    verticesVisitados[origen] = true;
}

void Dijkstra::inicializarRecorrido(int origen) {
    for(int i = 0; i < cantidadVertices; i++)
        recorrido[i] = origen;
}

Dijkstra::~Dijkstra() {
    delete[] verticesVisitados;
    delete[] distancia;
    delete[] recorrido;
}

void Dijkstra::inicializarDistancia(const int * distanciaOrigen) {
    for(int i = 0; i < cantidadVertices; i++)
        distancia[i] = distanciaOrigen[i];
}

void Dijkstra::actualizarDistancia(int vertice) {
    for(int i = 0; i < cantidadVertices; i++){
        if(!verticesVisitados[i] && distancia[vertice] != INFINITO && distancia[i] > matrizAdyacencia[vertice][i] + distancia[vertice]){
            distancia[i] = matrizAdyacencia[vertice][i] + distancia[vertice];
            recorrido[i] = vertice;
        }
    }
}

void Dijkstra::mostrarRecorrido(int origen, int destino) {
    if(distancia[destino] == INFINITO){
        cout << "No hay un camino que conecte " <<  vuelos->obtenerCodigoIATA(origen + 1) << " con " << vuelos->obtenerCodigoIATA(destino + 1);
    }else{
        cout << "El camino minimo que une " <<  vuelos->obtenerCodigoIATA(origen + 1) << " con " << vuelos->obtenerCodigoIATA(destino + 1) << " es el siguiente: " << endl;
        cout << "      Codigo IATA - Aeropuerto - Ciudad - Pais - Precio" << endl;
        cout << "De    " << vuelos->obtenerCodigoIATA(destino + 1) << " " << vuelos->obtenerNombreAeropuerto(destino + 1) << " " << vuelos->obtenerCiudad(destino + 1) << " " << vuelos->obtenerPais(destino + 1) << endl;
        int i = 1;
        int destinoAux = destino;
        do{
            destino = recorrido[destino];
            cout << "hasta " << vuelos->obtenerCodigoIATA(destino + 1) << " " << vuelos->obtenerNombreAeropuerto(destino + 1) << " " << vuelos->obtenerCiudad(destino + 1) << " " << vuelos->obtenerPais(destino + 1) << " " << calcularPrecio(i) << endl;
            i++;
        }while(origen != destino);
        cout << "Costo Total:" << distancia[destinoAux] << endl;
    }
}

int Dijkstra::calcularPrecio(int posicion) {
    int precio = distancia[posicion];
    int ultimoPrecio = precio;
    for (int i = posicion - 1; 0 < i; i--) {
        if ((distancia[i] != INFINITO) && (distancia[i] != ultimoPrecio)) {
            cout << distancia[i] << endl;
            precio -= distancia[i];
            ultimoPrecio = distancia[i];
        }
    }
    return precio;
}

void Dijkstra::mostrarIteracion(int iteracion) {
    cout << endl << "Iteración " << iteracion << endl;

    cout << "Visitados: [";
    for(int i = 0; i < cantidadVertices; i++){
        cout << verticesVisitados[i];
        if(i + 1 != cantidadVertices){
            cout << ", ";
        }
    }
    cout << "]" << endl;

    cout << "Distancia: [";
    for(int i = 0; i < cantidadVertices; i++){
        if(distancia[i] != INFINITO) {
            cout << distancia[i];
        } else {
            cout << "∞";
        }
        if(i + 1 != cantidadVertices){
            cout << ", ";
        }
    }
    cout << "]" << endl;

    cout << "Recorrido: [";
    for(int i = 0; i < cantidadVertices; i++){
        cout << vuelos -> obtenerCodigoIATA(recorrido[i] + 1);
        if(i + 1 != cantidadVertices){
            cout << ", ";
        }
    }
    cout << "]" << endl << endl;
}



