programa: main.o Grafo.o Lista.h Nodo.h Vuelo.o Dijkstra.o Floyd.o CaminoMinimo.o
	g++ main.o Grafo.o Lista.h Nodo.h Vuelo.o Dijkstra.o Floyd.o CaminoMinimo.o -o programa

main.o: main.cpp
	g++ -c main.cpp

Grafo.o: Grafo.cpp Grafo.h
	g++ -c Grafo.cpp
	
Vuelo.o: Vuelo.cpp Vuelo.h
	g++ -c Vuelo.cpp

Dijkstra.o: Dijkstra.cpp Dijkstra.h
	g++ -c Dijkstra.cpp

Floyd.o: Floyd.cpp Floyd.h
	g++ -c Floyd.cpp

CaminoMinimo.o: CaminoMinimo.cpp CaminoMinimo.h
	g++ -c CaminoMinimo.cpp

clean:
	rm *.o programa