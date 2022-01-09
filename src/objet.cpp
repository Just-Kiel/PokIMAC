//
// Created by Aurore on 19/12/2021.
//
#include "objet.h"

#include "menu.h"
#include "variables.h"
using namespace std;

bool ajoutObjetAInventaire(Joueur * player, Objet object){
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
    return recup;
}

int capturePokIBALL(Joueur * player, Pokimac * pokimac){
    Objet pokiball=allObject[0];
    bool recup = false;
    if(pokimac->pv<=10) {
        for (int i = 0; i < 3; i++) {
            if (player->inventaire[i].nom == pokiball.nom) {
                for (int j = 0; j < 7; j++) {
                    if (player->equipe[j].nom == videPokimac.nom) {
                        player->equipe[j] = *pokimac;
                        recup = true;
                        cout << "Tu as capture " << pokimac->nom << endl;
                        detectSpace();
                        break;
                    }
                }
                player->inventaire[i] = vide;
                break;
            }
        }
    }
    if(pokimac->pv<=10){
        cout<<"Tu n'as pas pu capture le PokIMAC, desole !"<<endl;
        detectSpace();
        return 0;
    }else if(!recup){
        cout<<"Tu n'as plus de PokIBALL !"<<endl;
        detectSpace();
        return 0;
    }else{
        return 2;
    }
}