//
// Created by Aurore on 07/12/2021.
//

#include <iostream>
using namespace std;
#include "menu.h"
#include "main.h"


int main(){
    Joueur joueur;
    joueur.position_x = 1;
    joueur.position_y = 2;
    printMenu(&joueur);
    return 0;
}