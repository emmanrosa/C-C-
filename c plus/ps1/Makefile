CC = g++
CFLAGS = -Wall -ansi -pedantic -Werror -std=c++0x -lboost_unit_test_framework
LFLAGS = -lsfml-window -lsfml-graphics -lsfml-audio -lsfml-system

all:  sierpinski original

sierpinski: main.o sierpinski.o
	$(CC) main.o sierpinski.o $(CFLAGS) $(LFLAGS) -o sierpinski

original: maino.o original.o
	$(CC) maino.o original.o $(CFLAGS) $(LFLAGS) -o original

main.o: main.cpp sierpinski.hpp
	$(CC) -c $(CFLAGS) $(LFLAGS) main.cpp

sierpinski.o: sierpinski.cpp sierpinski.hpp
	$(CC) -c $(CFLAGS) $(LFLAGS) sierpinski.cpp

maino.o: maino.cpp original.hpp
	$(CC) -c $(CFLAGS) $(LFLAGS) maino.cpp 

original.o: original.cpp original.hpp
	$(CC) -c $(CFLAGS) $(LFLAGS) original.cpp 

clean:
	rm *.o sierpinski original
