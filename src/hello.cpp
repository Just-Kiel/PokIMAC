//
//  hello.cpp
//  
//
//  Created by Sarah N'GOTTA on 18/01/2022.
//

#include "hello.hpp"
#include "variables.h"
#include "menu.h"
#include "main.h"
#include <stdio.h>
#include <cstring>
#include <iostream>
#include "consoleUtils.hpp"
#include "menu.h"

using namespace std;

void printHello(){
    
    //Initialisation du Joueur
     Joueur joueur;
     joueur.position_x = 0;
     joueur.position_y = 0;
     joueur.equipe[0]=allPokimac[0];
     for(int i=1; i<6; i++){
         joueur.equipe[i]=videPokimac;
     }

     int size_inventaire = sizeof (joueur.inventaire)/sizeof(joueur.inventaire[0]);
     joueur.inventaire[0]=allObject[0];
     for(int i=1; i<size_inventaire; i++){
         joueur.inventaire[i]=vide;
     }
    
    ConsoleUtils::setColor(ConsoleUtils::Color::LIGHTBLUE);
    cout<<endl<<
    "         ++:               +#:                +-."<<endl<<
    "      .+@@##+:           +%%%%*:           .+@@==-."<<endl<<
    "      .+@@@@####*:      .+%%%%%%%%#-      .+@@@@====-."<<endl<<
    "     +@@@@@@######+:   +%%%%%%%%%%%%#:   +@@@@@@======-."<<endl<<
    "   :@@@@@@@@########++%%%%%%%%%%%%%%%%*:@@@@@@@@========-."<<endl<<
    "    .*@@@@@@#######%%%%%%%%%%%%%%%%%#-   .*@@@@@@==========-."<<endl<<
    "      .*@@@@#####%%%%%%%%%%%%%%%%%%-       .*@@@@============-."<<endl<<
    "       :#@@###%%%%%%%%%%%%%%%%%#-            :#@@==============-."<<endl<<
    "         .*#%%%%%%%%%%%%%%%%%#-                 .*================-."<<endl<<
    "          +%%%%%%%%%%%%%%%%%=                      :================-."<<endl<<
    "        +%%%%%%%%%%%%%%%%%=....                       :================-."<<endl<<
    "     .+%%%%%%%%%%%%%%%%#=........                       :================-."<<endl<<
    "    +%%%%%%%%%%%%%%%%%=............                        :================-."<<endl<<
    "   %%%%%%%%%%%%%%%%#==---------------:                       -****************=."<<endl<<
    ".+%%%%%%%%%%%%%%%%#- .=############*-..                         .*@@@@@@@@@@@@%+==-."<<endl<<
   "+%%%%%%%%%%%%%%%%%-        .=########*-......                       .*@@@@@@@@%+======-."<<endl<<
  "+%%%%%%%%%%%%%%%%#-           .+####*-..........                        :*@ @@@%+==========-."<<endl<<
".+%%%%%%%%%%%%%%%%#-              .=*-..............                       .*%+==============-."<<endl<<
".+%%%%%%%%%%%%%%%%#:             =%###############+.                       *@@@@@@@@@@@@@@@@%:"<<endl<<
  ".*%%%%%%%%%%%%%%%%*:         =#%%%############+:                      .+@@@@@@@@@@@@@@@@#:"<<endl<<
    ".+%%%%%%%%%%%%%%%%#-   .=%%%%%%%%%#######+:                       .+@@@@@@@@@@@@@@@@#:"<<endl<<
    " .+%%%%%%%%%%%%%%%%#:=%%%%%%%%%%%%%###*.                        *@@@@@@@@@@@@@@@@%:"<<endl<<
    "  .*%%%%%%%%%%%%%%%%*=%%%%%%%%%%%%%%%%*:                      =%@@@@@@@@@@@@@@@#-"<<endl<<
    "   .+%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*-                      .:===#@@@@@@@@@@@@*:"<<endl<<
    "     .+%%%%%%%%%%%%%%%%%%%%%%%%%%#-                      -=======#@@@@@@@@#:"<<endl<<
    "       .*%%%%%%%%%%%%%%%%%%%%%%#-                     :==========+#@@@@#:"<<endl<<
    "        .+%%%%%%%%%%%%%%%%%%*-                      .:===============#*:"<<endl<<
    "         =#%%%%%%%%%%%%%%%%%#:                   :================-."<<endl<<
    "         =*####%%%%%%%%%%%%%%%%%*:             :-===============-."<<endl<<
    "     .=*########%%%%%%%%%%%%%%%%%#-         :-===============-."<<endl<<
    "    =#############%%%%%%%%%%%%%%%%%#:    :================-."<<endl<<
    "  :*###############**%%%%%%%%%%%%%%%%*.-===============-."<<endl<<
    "   .=############*-  .+%%%%%%%%%%%%#-   :============:."<<endl<<
    "    .=########*:      .+%%%%%%%%%-       :========-."<<endl<<
    "      .+####*-          .*%%%%#-           :====-."<<endl<<
    "        .=*-              .+#-               ::."<<endl;
    

    ConsoleUtils::resetColors(); std::cout << std::endl<<endl;
    
    detectSpace();
    
    ConsoleUtils::setColor(ConsoleUtils::Color::BLUE);
    ConsoleUtils::setBackgroundColor(ConsoleUtils::BackgroundColor::BG_YELLOW);
    std::cout << "Bienvenue sur";
    ConsoleUtils::resetColors(); std::cout << std::endl<<endl;
    
    ConsoleUtils::setColor(ConsoleUtils::Color::LIGHTBLUE);
    cout<<"\n"
          "  _____      _    _____ __  __          _____ \n"
          " |  __ \\    | |  |_   _|  \\/  |   /\\   / ____|\n"
          " | |__) |__ | | __ | | | \\  / |  /  \\ | |     \n"
          " |  ___/ _ \\| |/ / | | | |\\/| | / /\\ \\| |     \n"
          " | |  | (_) |   < _| |_| |  | |/ ____ \\ |____ \n"
          " |_|   \\___/|_|\\_\\_____|_|  |_/_/    \\_\\_____|\n"
          "                                              \n"
          "                                              ";
    ConsoleUtils::resetColors(); std::cout << std::endl<<endl;


    ConsoleUtils::setColor(ConsoleUtils::Color::BLUE);
    ConsoleUtils::setBackgroundColor(ConsoleUtils::BackgroundColor::BG_YELLOW);
    std::cout << "by The Cassoulettes !";
    ConsoleUtils::resetColors(); std::cout << std::endl<<endl;
    
    ConsoleUtils::setColor(ConsoleUtils::Color::BLUE);
    std::cout << "Dans ce jeu,tu incarnes un jeune DressESIPE de PokIMAC a qui l'on offre un PokIMAC de depart, et tu pars pour une aventure semee d’embuches."<<endl<<"Tu parcours une region peuplee de PokIMAC sauvages que tu peux capturer et faire combattre."<<endl<<endl;
    ConsoleUtils::setColor(ConsoleUtils::Color::LIGHTYELLOW);
    cout<<"Tout ceci dans le but de te mesurer à l'élite des dresseurs du Champs et enfin devenir le Maitre du Bourg Coper avec le PokESIPE le plus rempli ! "<<endl
        <<endl
        <<"C'EST PARTI ? ";
    ConsoleUtils::resetColors(); std::cout << std::endl<<endl;
    
    detectSpace();
    printMenu(&joueur);
    
}
