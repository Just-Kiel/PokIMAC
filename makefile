pokIMAC : main.o carte.o menu.o objet.o
	g++ main.o carte.o menu.o objet.o -o pokIMAC -Wall

main.o : main.cpp main.h
	g++ -c -Wall main.cpp

carte.o : carte.cpp carte.h
	g++ -c -Wall carte.cpp

menu.o : menu.cpp menu.h
	g++ -c -Wall menu.cpp

objet.o : objet.cpp objet.h
	g++ -c -Wall objet.cpp