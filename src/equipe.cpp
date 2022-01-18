//
// Created by Aurore on 17/01/2022.
//

#include "equipe.h"

#include "type_definition.h"
#include "variables.h"
#include "menu.h"

using namespace std;

//TODO affichage equipe
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
        cout<<"Ce choix n'est pas valide ! Tu dois choisir entre 1 et "<<nbPokimacMax<<" ou "<<sizeInventaire+1<<"."<<endl;
        cout << "Ton choix : ";
        cin >> user_choice;
    }
    detectSpace();
}
