//
// Created by Aurore on 19/12/2021.
//
#include "objet.h"

#include "menu.h"
using namespace std;

void ajoutObjetAInventaire(Joueur * player, Objet object){
    bool recup = false;
    int size_inventaire = sizeof (player->inventaire)/sizeof(player->inventaire[0]);
    for(int i=0; i<size_inventaire; i++){
        //Si la place de l'inventaire est vide l'objet est récupéré
        if(player->inventaire[i].nom == ""){
            player->inventaire[i]=object;
            recup = true;
        }
    }

    if(!recup){
        cout<<"Malheureusement plus de place dans ton inventaire ! Utilise des objets avant !"<<endl;
    } else {
        cout << object.visuel << endl;
        cout << "L'objet " << object.nom << " vient d'etre ajoute a ton inventaire !" << endl;
        cout << "Voici son utilite :" << endl;
        cout << object.definition << endl;
    }
    detectSpace();
}