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
#include "objet.h"
using namespace std;

void affichageDebutCombat(Joueur * player, Pokimac pokimac){
    cout<<"Oh non te voici face a "<<pokimac.nom<<endl;

    int nbChoixPokIMAC= choixPokIMAC(player);
    int statusFight=0;
    while(pokimac.pv>0 && player->equipe[nbChoixPokIMAC].pv>0 && statusFight!=2) {
        cout << left << setw(20) << player->equipe[nbChoixPokIMAC].representation << pokimac.representation <<endl;
        cout << left << setw(20) << player->equipe[nbChoixPokIMAC].nom << pokimac.nom << endl;

        cout << "PV : " << left << setw(15) << player->equipe[nbChoixPokIMAC].pv << "PV : " << pokimac.pv << endl;

        statusFight = choixCombat(player, &pokimac, nbChoixPokIMAC);
    }
    if(pokimac.pv<=0){
        cout<<pokimac.nom<<" est mort, tu as gagne !"<<endl;
    } else if(player->equipe[nbChoixPokIMAC].pv<=0){
        cout<<"Oh non ton pokIMAC doit vite etre soigne !"<<endl;
    }
}

int choixCombat(Joueur * player, Pokimac * pokimac, int pokimacUser){
    int user_fight;

    cout<<"Que souhaites tu faire ?"<<endl;
    cout<<"1. Attaquer"<<endl;
    cout<<"2. Capturer"<<endl;
    cout<<"3. Inventaire (not implemented yet)"<<endl;
    cout<<"4. Fuir"<<endl;
    cout<<"5. Changer de PokIMAC"<<endl;

    cout<<"Ton choix :";
    cin>> user_fight;

    while(user_fight<1 || user_fight>5){
        cout<<"Ce choix n'est pas valide ! Tu dois choisir entre 1 et 4."<<endl;
        cout << "Ton choix : ";
        cin >> user_fight;
    }

    ConsoleUtils::clear();

    if(user_fight == 1){
        attaqueCombat(&player->equipe[pokimacUser], pokimac);

        return 1;
    } else if(user_fight==2) {
        // Tentative de capture avec lancement de PokIBALL
        int captureStatus=capturePokIBALL(player, pokimac);
        return captureStatus;

    } else if(user_fight == 3){
        // Ouvre l'inventaire et permet le retour (pas encore possible d'agir vu que 0 objet possible)
        ouvertureInventaire(player, true, pokimacUser);
        return 0;

    } else if(user_fight == 4){
        // Fuite du combat
        cout<<"Tu choisis de fuir le combat !"<<endl;
        detectSpace();

        return 2;
    }else{
        // Changement de PokIMAC en combat
        pokimacUser = choixPokIMAC(player);
        return 1;
    }
    return 0;
}

int choixPokIMAC(Joueur * player){
    cout<<"Quel PokIMAC veux-tu envoyer ?"<<endl;

    //Taille équipe PokIMAC du dresseur
    int nbTeamPokIMAC = sizeof(player->equipe)/sizeof (player->equipe[0]);
    int nbPokIMACMax=0;
    for(int i=0; i<nbTeamPokIMAC; i++){
        if(player->equipe[i].nom != videPokimac.nom){
            cout<<i+1<<". "<<player->equipe[i].nom<<endl;
            nbPokIMACMax++;
        }
    }

    int user_pokIMAC;

    cout<<"Ton choix : ";
    cin>>user_pokIMAC;

    while((user_pokIMAC<1 || user_pokIMAC>nbPokIMACMax)||player->equipe[user_pokIMAC-1].pv <= 0){
        if(user_pokIMAC<1 || user_pokIMAC>nbPokIMACMax){
            cout << "Ce choix n'est pas valide ! Tu dois choisir entre 1 et " << nbPokIMACMax << "." << endl;
        } else {
            cout<<"Ton PokIMAC n'est pas en etat de se battre ! Envoie en un autre !"<<endl;
        }
        cout << "Ton choix : ";
        cin >> user_pokIMAC;
    }

    ConsoleUtils::clear();
    return user_pokIMAC-1;
}

void attaqueCombat(Pokimac * player_pokimac, Pokimac * enemy_pokimac){

    cout<<player_pokimac->nom<<" peut attaquer avec :"<<endl;

    for(int a=0; a<nbAttaque; a++){
        cout<<a+1<<". "<<player_pokimac->pouvoir[a].nom_attaque<<endl;
    }

    int user_choice;
    cout << "Ton choix : ";
    cin >> user_choice;

    while(user_choice<1 || user_choice>nbAttaque+1){
        cout<<"Ce choix n'est pas valide ! Tu dois choisir entre 1 et "<<nbAttaque+1<<"."<<endl;
        cout << "Ton choix : ";
        cin >> user_choice;
    }

    ConsoleUtils::clear();

    cout<<"Tu attaques avec "<<player_pokimac->pouvoir[user_choice-1].nom_attaque<<endl;

    int efficiency = multiplicateurType(*player_pokimac, *enemy_pokimac);

    if(efficiency == 1){
        enemy_pokimac->pv-=(player_pokimac->pouvoir[user_choice-1].puissance)*multiplicateurObjet;
    } else if(efficiency == 0){
        cout<<"C'est tres peu efficace !"<<endl<<endl;
        enemy_pokimac->pv-=((player_pokimac->pouvoir[user_choice-1].puissance)*multiplicateurObjet)/2;
    } else if(efficiency == 2){
        cout<<"C'est tres efficace !"<<endl<<endl;
        enemy_pokimac->pv-=((player_pokimac->pouvoir[user_choice-1].puissance)*multiplicateurObjet)*2;
    }

    cout<<enemy_pokimac->nom<<" contre-attaque !"<<endl;

    int randAttaque = rand()%nbAttaque;

    efficiency = multiplicateurType(*enemy_pokimac, *player_pokimac);

    if(efficiency == 1) {
        player_pokimac->pv -= enemy_pokimac->pouvoir[randAttaque].puissance;
    } else if(efficiency == 0){
        player_pokimac->pv -= (enemy_pokimac->pouvoir[randAttaque].puissance)/2;
    } else if(efficiency == 2){
        player_pokimac->pv -= (enemy_pokimac->pouvoir[randAttaque].puissance)*2;
    }

    multiplicateurObjet = 1;
    detectSpace();
}

int multiplicateurType(Pokimac attaque, Pokimac defense){
    int multiply = 1;
    if(attaque.espece == "Culture"){
        if(defense.espece=="Mathematiques"){
            multiply=0;
        } else if(defense.espece == "Design") {
            multiply = 2;
        }
    } else if(attaque.espece == "Programmation"){
        if(defense.espece == "Aide"){
            multiply = 2;
        } else if(defense.espece == "Design"){
            multiply = 0;
        }
    } else if(attaque.espece == "Aide"){
        if(defense.espece == "Mathematiques"){
            multiply = 2;
        } else if(defense.espece == "Programmation"){
            multiply = 0;
        }
    } else if(attaque.espece == "Design"){
        if(defense.espece == "Programmation"){
            multiply = 2;
        } else if(defense.espece == "Culture"){
            multiply = 0;
        }
    } else if(attaque.espece == "Mathematiques"){
        if(defense.espece == "Culture"){
            multiply = 2;
        } else if(defense.espece == "Aide"){
            multiply = 0;
        }
    }

    return multiply;
}