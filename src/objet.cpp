//
// Created by Aurore on 19/12/2021.
//
#include "objet.h"

#include "menu.h"
#include "variables.h"
#include "consoleUtils.hpp"
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
        cout << "Voici son utilite :";
        cout << object.definition << endl;
    }
    detectSpace();
    return recup;
}

int capturePokIBALL(Joueur * player, Pokimac * pokimac){
    Objet pokiball=allObject[0];
    bool recup = false;
    if(pokimac->pv<=10) {
        for (int i = 0; i < sizeInventaire; i++) {
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

void ouvertureInventaire(Joueur * player, bool inCombat, int pokimacUser){
    int nbObjetMax=0;
    cout<<"Dans ton inventaire il y a :"<<endl;

    for(int i=0; i<sizeInventaire; i++){
        if(player->inventaire[i].nom != vide.nom && (!inCombat || player->inventaire[i].nom != allObject[0].nom)){
            cout<< i+1 <<". "<<player->inventaire[i].nom<<endl;
            nbObjetMax=i+1;
        }
    }
    cout<<sizeInventaire+1<<". Retour"<<endl;

    int user_choice;
    cout << "Ton choix : ";
    cin >> user_choice;

    while(user_choice!=sizeInventaire+1 && (user_choice<1 || user_choice>nbObjetMax)){
        cout<<"Ce choix n'est pas valide ! Tu dois choisir entre 1 et "<<nbObjetMax<<" ou "<<sizeInventaire+1<<"."<<endl;
        cout << "Ton choix : ";
        cin >> user_choice;
    }

    if(user_choice == sizeInventaire+1){
        ConsoleUtils::clear();
    } else {
        Objet * current_objet = &(player->inventaire[user_choice-1]);
        howToUse(*current_objet);

        if(inCombat){
            useInCombat(current_objet, &player->equipe[pokimacUser]);
        } else {
            ouvertureInventaire(player, inCombat);
        }
    }
}

void howToUse(Objet objet){
    ConsoleUtils::clear();
    cout << objet.visuel << endl;
    cout << objet.nom << endl;
    cout << "Son utilite : " << objet.definition << endl;

    detectSpace();
}

int multiplicateurObjet = 1;

void useInCombat(Objet * useObject, Pokimac * player_pokimac){
    Pokimac refPokIMAC;
    for(int i = 0; i<nbPokIMAC; i++){
        if(allPokimac[i].nom == player_pokimac->nom){
            refPokIMAC = allPokimac[i];
        }
    }
    if(useObject->id_type == 1){
        if (player_pokimac->pv<refPokIMAC.pv){
            cout << "Ton pokIMAC voit ses PV se regenerer !"<<endl;
            int pvMissing = refPokIMAC.pv - player_pokimac->pv;
            if(pvMissing<useObject->puissance){
                player_pokimac->pv += pvMissing;
            } else {
                player_pokimac->pv+=useObject->puissance;
            }
            *useObject = vide;
        } else {
            cout << "Tu as deja trop de PV, pas besoin d'utiliser ce style d'objet !"<<endl;
        }
    } else if(useObject->id_type == 2){
        multiplicateurObjet = useObject->puissance;

        *useObject = vide;
    }
    detectSpace();
}