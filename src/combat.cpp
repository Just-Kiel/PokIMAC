//
// Created by Aurore on 20/12/2021.
//
#include <iostream>
#include <stdlib.h>
#include <iomanip>

#include "combat.h"
#include "consoleUtils.hpp"
#include "variables.h"
#include "menu.h"
using namespace std;

void affichageDebutCombat(Joueur * player, Pokimac pokimac){
    //Facultatif TODO choisir quel PokIMAC envoyé
    cout<<"Oh non te voici face a "<<pokimac.nom<<endl;
    int statusFight=0;
    while(pokimac.pv>0 && player->equipe[0].pv>0 && statusFight!=2) {
        cout << left << setw(20) << player->equipe[0].nom << pokimac.nom << endl;

        cout << "PV : " << left << setw(15) << player->equipe[0].pv << "PV : " << pokimac.pv << endl;

        statusFight=choixCombat(player, &pokimac);
    }
    if(pokimac.pv<=0){
        cout<<pokimac.nom<<" est mort, tu as gagne !"<<endl;
    } else if(player->equipe[0].pv<=0){
        cout<<"Oh non ton pokIMAC doit vite etre soigne !"<<endl;
    }
};

int choixCombat(Joueur * player, Pokimac * pokimac){
    int user_fight;

    cout<<"Que souhaites tu faire ?"<<endl;
    cout<<"1. Attaquer"<<endl;
    cout<<"2. Capturer"<<endl;
    cout<<"3. Inventaire (not implemented yet)"<<endl;
    cout<<"4. Fuir (not implemented yet)"<<endl;

    cout<<"Votre choix :";
    cin>> user_fight;

    while(user_fight<1 || user_fight>4){
        cout<<"Ce choix n'est pas valide ! Tu dois choisir entre 1 et 4."<<endl;
        cout << "Votre choix : ";
        cin >> user_fight;
    }

    ConsoleUtils::clear();

    if(user_fight == 1){
        //TODO attaque par attaques différentes + types de chaque pokimac

        cout<<"Tu attaques avec "<<player->equipe[0].nom<<endl;
        pokimac->pv-=player->equipe[0].attaque;
        cout<<pokimac->nom<<" contr-attaque !"<<endl;
        player->equipe[0].pv-=pokimac->attaque;
        detectSpace();
        return 1;
    } else if(user_fight==2) {
        //TODO Lancer Pokeball + systeme de capture par force ou rareté
        for(int i=0; i<3; i++){
            if(player->inventaire[i].nom=="PokIBALL"){
                for(int j=0; j<7; j++){
                    if(player->equipe[j].nom == ""){
                        player->equipe[j]=*pokimac;
                        cout<<"Tu as capture "<<pokimac->nom<<endl;
                        return 2;
                        break;
                    }
                }
                player->inventaire[i]=vide;
                break;
            }
        }


    } else if(user_fight == 3){
        //Facultatif TODO ouvrir inventaire
        return 0;

    } else {
        //Facultatif TODO fuite du combat
        return 0;
    }
    return 0;
}