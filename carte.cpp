#include <iostream>
#include <stdlib.h>
#include "carte.h"
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
int nbObjet = 3;

void changementTab(char tab[], int taille){
    char caractere, new_caractere;
    cout<<"Quel caractère souhaitez vous modifier ?"<<endl;
    cin>>caractere;
    cout<<"Par quel caractère voulez vous remplacer ?"<<endl;
    cin>>new_caractere;
    for(int i=0; i<taille;i++) {
        if (tab[i] == caractere) {
            tab[i] = new_caractere;
        }
    }
}

void affichageTab(char tab[], int taille){
    //Affichage du tableau
    cout<<"Te voici dans le bourg Coper, tu peux te deplacer avec zqsd ou les fleches directionnelles."<<endl;
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
    int randomObject;
    for(int i=0; i<(taille*taille); i++){
        tab[i]=sol;
    }

    //Positionnement random des objets
    for(int j=0; j<nbObjet; j++){
        randomObject = rand()%(taille*taille);
        tab[randomObject]=objet;
    }

    affichageTab(tab, taille);
}

void deplacementTab(char tab[], int taille, Joueur* player){
    //Deplacement sur le tableau
    bool move = true;
    while(move) {
        consoleUtils::setCursorPos(player->position_x, player->position_y);
        cout << perso;
        char input = consoleUtils::getChar();
        switch (input) {
            case 'H':
            case 'A': //Check if A sur Mac up ?
            case 'z':
                if(player->position_y-1>=2){
                    consoleUtils::setCursorPos(player->position_x, player->position_y);
                    cout<<tab[(taille*(player->position_y-2)+(player->position_x)/3)];
                    player->position_y--;
                }
                break;
            case 'P':
            case 'B': //Check if B sur Mac down ?
            case 's':
                if(player->position_y-1<taille) {
                    consoleUtils::setCursorPos(player->position_x, player->position_y);
                    cout<<tab[(taille*(player->position_y-2)+(player->position_x)/3)];
                    player->position_y++;
                }break;
            case 'M':
            case 'C': //Check if C sur Mac right ?
            case 'd':
                if((player->position_x)/3+1<taille) {
                    consoleUtils::setCursorPos(player->position_x, player->position_y);
                    cout<<tab[(taille*(player->position_y-2)+(player->position_x)/3)];
                    player->position_x += 3;
                }
                break;
            case 'K':
            case 'D': //Check if D sur Mac left ?
            case 'q':
                if((player->position_x)>1) {
                    consoleUtils::setCursorPos(player->position_x, player->position_y);
                    cout<<tab[(taille*(player->position_y-2)+(player->position_x)/3)];
                    player->position_x -= 3;
                }
                break;
            case 'o':
                move=false;
                consoleUtils::clear();break;
        }
        move = detection(tab, taille, player);
    }

}
//TODO detecter objet et passer un écran pour signaler l'objet dans l'inventaire
bool detection(char tab[], int taille, Joueur * player){
    if(tab[(taille*(player->position_y-2)+(player->position_x)/3)]=='o'){
        consoleUtils::clear();
        return false;
    }
    return true;
}
//
// Created by Aurore on 07/12/2021.
//