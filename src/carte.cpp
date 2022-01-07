#include <iostream>
#include <stdlib.h>

#include "carte.h"

#include "variables.h"
#include "consoleUtils.hpp"
#include "objet.h"
#include "combat.h"
#include "menu.h"

using namespace std;

/*
 * TODO Caractères à définir :
 *      - Joueur
 *      - Pokemons
 *      - Objet
 *      - Sol
 */
char perso = 'i';
char sol = 'a';
char herbes = 'X';
char objet = 'o';
int nbObjet = sizeof(allObject)/sizeof(allObject[0]);

void affichageTab(char tab[], int taille){
    //Affichage du tableau
    cout<<"Te voici dans le bourg Coper, tu peux te deplacer avec zqsd ou les fleches directionnelles et revenir au menu avec la touche ESPACE."<<endl;
    for(int i=0; i<taille*taille; i++){
        if(i%taille==0 && i!=0){
            cout<<endl;
        }
        cout<<tab[i]<<"  ";
    }
    cout<<endl;
}

void remplissageTab(char tab[], int taille){
    //Remplissage du tableau
    for(int i=0; i<(taille*taille); i++){
        tab[i]=sol;
    }

    int randomObject;

    //Positionnement random des objets
    for(int j=0; j<(taille*taille/5); j++){
        randomObject = rand()%(taille*taille);
        tab[randomObject]=objet;
    }

    //Positionnement des mauvaises herbes
    for(int k=1; k<(taille*taille/3); k++){
        randomObject = rand()%(taille*taille) +1;
        if(tab[randomObject]!=objet){
            tab[randomObject]=herbes;
        }
    }

    affichageTab(tab, taille);
}

void affichageApresDeplacementCell(Joueur * player, char *tab, int taille){
    ConsoleUtils::setCursorPos(player->position_x*3, player->position_y+1);
    //Si le dresseur vient de récupérer un objet, il n'est plus affiché sur la carte
    if(tab[(taille*(player->position_y)+(player->position_x))] == objet){
        tab[(taille*(player->position_y)+(player->position_x))]=sol;
    }
    cout<<tab[(taille*(player->position_y)+(player->position_x))];
}

void deplacementTab(char tab[], int taille, Joueur* player){
    //Deplacement sur le tableau
    bool move = true;
    bool detect = false;
    bool arrow = false;
    //Detection et déplacement en fonction des fleches et de ZQSD
    while(move && !detect) {
        ConsoleUtils::setCursorPos(player->position_x*3, player->position_y+1);
        cout << perso;
        char input = ConsoleUtils::getChar(&arrow);
        if(arrow){
            switch (input) {
                case ConsoleUtils::KEY_UP:
                    if (player->position_y > 0) {
                        affichageApresDeplacementCell(player, tab, taille);
                        player->position_y--;
                    }
                    break;
                case ConsoleUtils::KEY_DOWN:
                    if (player->position_y < taille - 1) {
                        affichageApresDeplacementCell(player, tab, taille);
                        player->position_y++;
                    }
                    break;
                case ConsoleUtils::KEY_RIGHT:
                    if (player->position_x < taille - 1) {
                        affichageApresDeplacementCell(player, tab, taille);
                        player->position_x++;
                    }
                    break;
                case ConsoleUtils::KEY_LEFT:
                    if ((player->position_x) > 0) {
                        affichageApresDeplacementCell(player, tab, taille);
                        player->position_x--;
                    }
                    break;
            }
        } else {
            switch (input) {
                case 'z':
                case 'Z':
                    if (player->position_y > 0) {
                        affichageApresDeplacementCell(player, tab, taille);
                        player->position_y--;
                    }
                    break;
                case 's':
                case 'S':
                    if (player->position_y < taille - 1) {
                        affichageApresDeplacementCell(player, tab, taille);
                        player->position_y++;
                    }
                    break;
                case 'd':
                case 'D':
                    if (player->position_x < taille - 1) {
                        affichageApresDeplacementCell(player, tab, taille);
                        player->position_x++;
                    }
                    break;
                case 'q':
                case 'Q':
                    if ((player->position_x) > 0) {
                        affichageApresDeplacementCell(player, tab, taille);
                        player->position_x--;
                    }
                    break;

                    //Revenir au menu principal
                case ' ':
                    move = false;
                    detect=false;
                    ConsoleUtils::clear();
                    printMenu(player);
                    break;
            }
        }
        if(input!= ' ') {
            detect = detection(tab, taille, player);
        }
    }

}
//je crois c'est bon TODO detecter objet et passer un écran pour signaler l'objet dans l'inventaire
bool detection(char tab[], int taille, Joueur * player){
    if(tab[(taille*(player->position_y)+(player->position_x))]==objet){
        ConsoleUtils::clear();

        //Facultatif TODO random en fonction de la rareté d'apparition

        //Objet possibleObjects[]={test1, test2, test3};
        int random=rand()%nbObjet;

        //Fonction ajout Objet à inventaire
        ajoutObjetAInventaire(player, allObject[random]);
        affichageTab(tab, taille);
        return false;
    } else if(tab[(taille*(player->position_y)+(player->position_x))]==herbes){
        ConsoleUtils::clear();
        //TODO is there pokimac in that herb ?

        affichageDebutCombat(player, allPokimac[1]);
        ConsoleUtils::clear();
        affichageTab(tab, taille);
        return false;
    }
    return false;
}
//
// Created by Aurore on 07/12/2021.
//