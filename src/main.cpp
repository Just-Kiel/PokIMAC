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

// Facultatif TODO rendre le tout esthétique (des couleurs)
// TODO faire les variables (objets, attaques, representations des pokimacs)

int main(){
    //graine de l'aléatoire avec temps de l'ordi
    srand(time(0));

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

    //Lancement du programme
    printMenu(&joueur);
    return 0;
}