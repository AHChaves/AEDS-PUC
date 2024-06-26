all: main.o preferencias.o prefNumerical.o matrix.o
	g++ main.o preferencias.o matrix.o prefNumerical.o -o main
	rm -rf *.o
	clear
	.\main.exe

matrix.o: matrix.cpp
	g++ -c matrix.cpp

main.o: main.cpp
	g++ -c main.cpp 

preferencias.o: preferencias.cpp 
	g++ -c preferencias.cpp 

prefNumerical.o: prefNumerical.cpp
	g++ -c prefNumerical.cpp

clean: 
	rm -rf *.o