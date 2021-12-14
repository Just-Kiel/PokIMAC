pokIMAC : main.o carte.o menu.o
	g++ main.o carte.o menu.o -o pokIMAC -Wall

main.o : main.cpp menu.h main.h type_definition.h
	g++ -c -Wall main.cpp

carte.o : carte.cpp carte.h
	g++ -c -Wall carte.cpp

menu.o : menu.cpp menu.h main.h carte.h
	g++ -c -Wall menu.cpp