all: main.o preference.o numerical.o
	g++ main.o preference.o numerical.o -o main

main.o: main.cpp
	g++ -c main.cpp

preference.o: preferencias.cpp ./headers/prefNumerical.h
	g++ -c preferencias.cpp

numerical.o: prefNumerical.cpp ./headers/prefNumerical.h
	g++ -c prefNumerical.cpp

clean: 
	rm -rf *.o