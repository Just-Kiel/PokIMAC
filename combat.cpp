//
// Created by Aurore on 20/12/2021.
//
#include <iostream>
#include <stdlib.h>
#include <iomanip>

#include "combat.h"
#include "consoleUtils.hpp"
using namespace std;

void affichageDebutCombat(Joueur * player, Pokimac pokimac){
    cout<<"Oh non te voici face a "<<pokimac.nom<<endl;
    while(pokimac.pv>0) {
        cout << left << setw(20) << player->equipe[0].nom << pokimac.nom << endl;

        cout << "PV : " << left << setw(15) << player->equipe[0].pv << "PV : " << pokimac.pv << endl;

        choixCombat(player, &pokimac);
    }
    cout<<"PTDR il est mort"<<endl;
};

void choixCombat(Joueur * player, Pokimac * pokimac){
    int user_fight;

    cout<<"Que souhaites tu faire ?"<<endl;
    cout<<"1. Attaquer"<<endl;
    cout<<"2. Capturer"<<endl;
    cout<<"3. Inventaire"<<endl;
    cout<<"4. Fuir"<<endl;

    cout<<"Votre choix :";
    cin>> user_fight;

    while(user_fight<1 || user_fight>4){
        cout<<"Ce choix n'est pas valide ! Tu dois choisir entre 1 et 4."<<endl;
        cout << "Votre choix : ";
        cin >> user_fight;
    }

    if(user_fight == 1){
        //TODO attaque

        cout<<"Tu attaques avec "<<player->equipe[0].nom<<endl;
        pokimac->pv-=player->equipe[0].attaque;
        ConsoleUtils::clear();
    } else if(user_fight==2) {
        //TODO Lancer Pokeball
    } else if(user_fight == 3){
        //TODO ouvrir inventaire
    } else {
        //TODO fuite du combat
    }
}