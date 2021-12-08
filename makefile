pokIMAC : main.o carte.o menu.o
	g++ main.o carte.o menu.o -o pokIMAC -Wall

main.o : main.cpp menu.h
	g++ -c -Wall main.cpp

carte.o : carte.cpp
	g++ -c -Wall carte.cpp

menu.o : menu.cpp menu.h
	g++ -c -Wall menu.cpp