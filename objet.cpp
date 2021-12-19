//
// Created by Aurore on 19/12/2021.
//

#include "objet.h"
using namespace std;

void ajoutObjetAInventaire(Joueur * player, Objet * object, int nbObjects){
    for(int i=0; i<nbObjects; i++){
        if(player->inventaire[i].nom == ""){
            player->inventaire[i]=*object;
        }
    }
    cout<<object->visuel<<endl;
    cout<<"L'objet "<<object->nom<<" vient d'etre ajoute a ton inventaire !"<<endl;
    cout<<"Voici son utilite :"<<endl;
    cout<<object->definition<<endl;
}