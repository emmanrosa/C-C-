
CC = g++

CFLAGS = -Wall -ansi -pedantic -Werror -std=c++0x -lboost_unit_test_framework

OFLAGS =  -c -Wall -ansi -pedantic -Werror -std=c++0x -lboost_unit_test_framework

LFLAGS = -lsfml-window -lsfml-graphics -lsfml-system


all: ps2b

ps2b: PhotoMagic.o LFSR.o
	$(CC) PhotoMagic.o LFSR.o -o PhotoMagic  $(CFLAGS) $(LFLAGS) 

PhotoMagic.o: PhotoMagic.cpp 
	$(CC)  $(OFLAGS)  $(LFLAGS) PhotoMagic.cpp

LFSR.o: LFSR.cpp LFSR.hpp
	$(CC)  $(OFLAGS) LFSR.cpp

clean:
	rm *.o PhotoMagic encrypted-cat.bmp *.cpp~ *~

