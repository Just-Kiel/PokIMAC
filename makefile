pokIMAC : main.o carte.o menu.o objet.o variables.o combat.o
	g++ main.o carte.o menu.o objet.o variables.o combat.o -o pokIMAC -Wall

main.o : main.cpp main.h variables.cpp
	g++ -c -Wall main.cpp

carte.o : carte.cpp carte.h objet.h combat.cpp
	g++ -c -Wall carte.cpp

menu.o : menu.cpp menu.h
	g++ -c -Wall menu.cpp

objet.o : objet.cpp objet.h
	g++ -c -Wall objet.cpp

variables.o : variables.cpp variables.h
	g++ -c -Wall variables.cpp

combat.o : combat.cpp combat.h
	g++ -c -Wall combat.cpp

clean :
	$(RM) -f *.o *.exe