pokIMAC : main.o carte.o menu.o
	g++ main.o carte.o menu.o -o pokIMAC -Wall

main.o : main.cpp main.h
	g++ -c -Wall main.cpp

carte.o : carte.cpp carte.h
	g++ -c -Wall carte.cpp

menu.o : menu.cpp menu.h
	g++ -c -Wall menu.cpp