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
    ConsoleUtils::setColor(ConsoleUtils::Color::LIGHTBLUE);
     cout << "      ,gW,    ,g&,    ,g&,              \n"
             "    ,@$$||l,,$llll$,,@$$l$$,            \n"
             "     \"B$||l$$$lll$\"  \"&$ll$$$g          \n"
             "       `g$$$$$$$\"      '&$$$$$$g        \n"
             "      g$$$$$$@\"           %$$&lllg      \n"
             "   ,g$$$$$$F*ggggggw        *@@@@@@@,   \n"
             " ,$lllM$$F    \"$$F-  |        \"$$Mlll@, \n"
             "\"&@@@@@Mw      ,&&&&&&&\"       ,&@@@@@@\"\n"
             "  `%$$lll$g  g@$$$@l@\"       g$$$$$$@\"  \n"
             "     1$$$$@$$%$$$$@\"       g$$$$$$&`    \n"
             "       *&llllll%F       ,g$$$$$$F       \n"
             "      ,$$@lllll$$y    ,$|j$$$$F         \n"
             "    ,$$$$$$$&$$$$$$w,$llll|$\"           \n"
             "     `%$$@\"  `%$$@\"  `&ll@\"             \n"
             "        `       `       `               \n"
             "" << endl;

    ConsoleUtils::resetColors();
    
    detectSpace();

    ConsoleUtils::setColor(ConsoleUtils::Color::BLUE);
    ConsoleUtils::setBackgroundColor(ConsoleUtils::BackgroundColor::BG_YELLOW);
    cout << "Bienvenue sur" <<endl;
    ConsoleUtils::resetColors();
    
    ConsoleUtils::setColor(ConsoleUtils::Color::LIGHTBLUE);
    cout<<"\n"
          "  _____      _    _____ __  __          _____ \n"
          " |  __ \\    | |  |_   _|  \\/  |   /\\   / ____|\n"
          " | |__) |__ | | __ | | | \\  / |  /  \\ | |     \n"
          " |  ___/ _ \\| |/ / | | | |\\/| | / /\\ \\| |     \n"
          " | |  | (_) |   < _| |_| |  | |/ ____ \\ |____ \n"
          " |_|   \\___/|_|\\_\\_____|_|  |_/_/    \\_\\_____|\n"
          "                                              \n"
          "                                              " << endl;
    ConsoleUtils::resetColors();

    ConsoleUtils::setColor(ConsoleUtils::Color::BLUE);
    ConsoleUtils::setBackgroundColor(ConsoleUtils::BackgroundColor::BG_YELLOW);
    cout << "by The Cassoulettes !";
    ConsoleUtils::resetColors(); std::cout << std::endl<<endl;
    
    ConsoleUtils::setColor(ConsoleUtils::Color::BLUE);
    cout << "Dans ce jeu,tu incarnes un jeune DressESIPE de PokIMAC a qui l'on offre un PokIMAC de depart, et tu pars pour une aventure semee d'embuches."<<endl<<"Tu parcours une region peuplee de PokIMACs sauvages que tu peux capturer et faire combattre."<<endl<<endl;
    ConsoleUtils::setColor(ConsoleUtils::Color::LIGHTYELLOW);
    cout<<"Tout ceci dans le but de te mesurer a l'elite des dresseurs du Champs et enfin devenir le Maitre du Bourg Coper avec le PokESIPE le plus rempli ! "<<endl
        <<endl
        <<"C'EST PARTI ? " <<endl;
    ConsoleUtils::resetColors();
    
    detectSpace();
}
