CC = g++
OFLAGS = -c -Wall -ansi -pedantic -Werror -std=c++0x -lboost_unit_test_framework
CFLAGS = -Wall -ansi -pedantic -Werror -std=c++0x -lboost_unit_test_framework
LFLAGS = -lsfml-window -lsfml-graphics -lsfml-audio -lsfml-system

all:NBody

NBody: nbody.o main.o
	$(CC) nbody.o main.o $(CFLAGS) $(LFLAGS)  -o NBody

main.o: main.cpp
	$(CC) $(OFLAGS) $(LFLAGS) main.cpp

nbody.o: nbody.cpp nbody.hpp
	$(CC) $(OFLAGS) nbody.cpp

clean:
	rm *.o  *~ NBody 
