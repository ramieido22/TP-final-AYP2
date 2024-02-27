
EXE=./ej1.exe # nombre del ejecutable
OBJS= $(patsubst %.cpp,obj/%.o,$(wildcard *.cpp)) # los archivos binarios
GCC=g++ # Compilador
GCCFLAGS=-Wall -Werror -Wconversion # Opciones del compilador
TESTER=valgrind # herramienta de testing
TESTEROPTIONS=--tool=memcheck # Opciones de la herramienta de testing


all: $(OBJS) $(EXE)

$(EXE): $(OBJS)
	mkdir -p obj
	$(GCC) $(GCCFLAGS) -o $(EXE) $(OBJS)

obj/main.o: main.cpp ABM.h
	$(GCC) $(GCCFLAGS) -c main.cpp -o $@
obj/ABM.o: ABM.cpp ABM.h ABB.hpp Lista.h Menu.h Aeropuerto.h Nodo_L.h Nodo.hpp
	$(GCC) $(GCCFLAGS) -c ABM.cpp -o $@
obj/Aeropuerto.o: Aeropuerto.cpp Aeropuerto.h
	$(GCC) $(GCCFLAGS) -c Aeropuerto.cpp -o $@
obj/Menu.o: Menu.cpp Menu.h
	$(GCC) $(GCCFLAGS) -c Menu.cpp -o $@
obj/Code_Aeropuerto.o: Code_Aeropuerto.h Code_Aeropuerto.cpp
	$(GCC) $(GCCFLAGS) -c Code_Aeropuerto.cpp -o $@

.PHONY: full_clean clean test

test:
	$(TESTER) $(TESTEROPTIONS) $(EXE)

clean:
	rm $(EXE)

full_clean:
	rm $(EXE)
	rm $(OBJS)
