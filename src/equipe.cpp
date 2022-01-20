//
// Created by Aurore on 17/01/2022.
//

#include "equipe.h"

#include "type_definition.h"
#include "variables.h"
#include "menu.h"
#include "consoleUtils.hpp"

using namespace std;

void ouvertureEquipe(Joueur * player){
    int nbPokimacMax = 0;
    cout << "Dans ton equipe il y a :" << endl;
    for(int i = 0; i<sizeEquipe; i++){
        if(player->equipe[i].nom != videPokimac.nom){
            cout << i+1 << ". " << player->equipe[i].nom<<endl;
            nbPokimacMax++;
        }
    }

    cout<<sizeEquipe+1<<". Retour"<<endl;

    int user_choice;
    cout << "Ton choix : ";
    cin >> user_choice;

    while(user_choice!=sizeEquipe+1 && (user_choice<1 || user_choice>nbPokimacMax)){
        cout<<"Ce choix n'est pas valide ! Tu dois choisir entre 1 et "<<nbPokimacMax<<" ou "<<sizeEquipe+1<<"."<<endl;
        cout << "Ton choix : ";
        cin >> user_choice;
    }

    if(user_choice == sizeEquipe+1){
        ConsoleUtils::clear();
    } else {
        ConsoleUtils::clear();
        cout << player->equipe[user_choice-1].representation << endl;
        cout << player->equipe[user_choice-1].nom << endl;
        cout << "Type : " << player->equipe[user_choice-1].espece << endl;
        cout << "PV : " << player->equipe[user_choice-1].pv << endl;
        detectSpace();

        ouvertureEquipe(player);
    }
}

void soinPokimacCenter(Joueur * player){
    cout << "Tes PokIMACs sont soignes !"<< endl;
    for(int all = 0; all<nbPokIMAC; all++) {
        for (int i = 0; i < sizeEquipe; i++) {
            if (player->equipe[i].nom == allPokimac[all].nom) {
                player->equipe[i].pv = allPokimac[all].pv;
            }
        }
    }
}