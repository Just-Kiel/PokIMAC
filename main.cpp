//
// Created by Aurore on 07/12/2021.
//

#include <iostream>
using namespace std;
#include "menu.h"
#include "main.h"
#include "variables.h"
#include <stdlib.h>
#include <time.h>


int main(){
    //graine de l'aléatoire avec temps de l'ordi
    srand(time(0));
    Joueur joueur;
    joueur.position_x = 0;
    joueur.position_y = 0;
    joueur.equipe[0]=allPokimac[0];
    for(int i=1; i<6; i++){
        joueur.equipe[i]=videPokimac;
    }
    joueur.inventaire[0]=pokIBALL;
    printMenu(&joueur);
    return 0;
}