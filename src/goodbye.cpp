//
//  goodbye.cpp
//  
//
//  Created by Sarah N'GOTTA on 19/01/2022.
//

#include "goodbye.hpp"
#include "variables.h"
#include "menu.h"
#include "main.h"
#include <stdio.h>
#include <cstring>
#include <iostream>
#include "consoleUtils.hpp"
#include "menu.h"

using namespace std;

void printGoodbye(){
    
    ConsoleUtils::setColor(ConsoleUtils::Color::BLUE);
    ConsoleUtils::setBackgroundColor(ConsoleUtils::BackgroundColor::BG_YELLOW);
    std::cout << "Les Cassoulettes vous remercient d'avoir jouer au";
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
    std::cout << "A bientot !";
    ConsoleUtils::resetColors(); std::cout << std::endl<<endl;
    
    detectSpace();
    
}
