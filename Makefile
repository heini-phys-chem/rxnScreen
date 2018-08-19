XX = g++

OBDIR = /home/stefan/openbabel

INCLUDE = -I$(OBDIR)/include/openbabel-2.0/
LIBS = -L$(OBDIR)/lib
CXX_FLAGS = -std=c++11 -O3 -march=native -Wall
LINKER_FLAGS = -lopenbabel

all: main

main: src/rxnScreen.cpp 
	$(CXX) $(INCLUDE) $(LIBS) $(CXX_FLAGS) src/rxnScreen.cpp -o main $(LINKER_FLAGS)

main.o: main.o src/func.hpp src/utils.hpp
	$(CXX) $(INCLUDE) $(LIBS) $(CXX_FLAGS) -c src/rxnScreen.cpp $(LINKER_FLAGS)

clean:
	rm -rf main
	rm -rf *.o *.gch
	rm -rf test.xyz

clean_xyz:
	rm -rf test_*
