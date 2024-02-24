

GCC=g++
GCCFLAGS=-Wall -Werror -Wconversion
TESTER=valgrind
TESTEROPTIONS=--tool=memcheck
EXE=./ej1.exe

all:
	$(GCC) $(GCCFLAGS) -o $(EXE) *.cpp

.PHONY: clean test

test:
	$(TESTER) $(TESTEROPTIONS) $(EXE)

clean:
	rm $(EXE)
