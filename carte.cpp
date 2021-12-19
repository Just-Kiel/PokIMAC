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

void affichageApresDeplacementCell(Joueur * player, char *tab, int taille){
    ConsoleUtils::setCursorPos(player->position_x*3, player->position_y+1);
    cout<<tab[(taille*(player->position_y)+(player->position_x))];
}

void deplacementTab(char tab[], int taille, Joueur* player){
    //Deplacement sur le tableau
    bool move = true;
    bool detect = false;
    bool arrow = false;
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
                //case 'H':
                //case 'A': //Check if A sur Mac up ?
                case 'z':
                    if (player->position_y > 0) {
                        affichageApresDeplacementCell(player, tab, taille);
                        player->position_y--;
                    }
                    break;
                //case 'P':
                //case 'B': //Check if B sur Mac down ?
                case 's':
                    if (player->position_y < taille - 1) {
                        affichageApresDeplacementCell(player, tab, taille);
                        player->position_y++;
                    }
                    break;
                //case 'M':
                //case 'C': //Check if C sur Mac right ?
                case 'd':
                    if (player->position_x < taille - 1) {
                        affichageApresDeplacementCell(player, tab, taille);
                        player->position_x++;
                    }
                    break;
                //case 'K':
                //case 'D': //Check if D sur Mac left ?
                case 'q':
                    if ((player->position_x) > 0) {
                        affichageApresDeplacementCell(player, tab, taille);
                        player->position_x--;
                    }
                    break;
                case ' ':
                    move = false;
                    ConsoleUtils::clear();
                    break;
            }
        }

        detect = detection(tab, taille, player);
    }

}
//TODO detecter objet et passer un écran pour signaler l'objet dans l'inventaire
bool detection(char tab[], int taille, Joueur * player){
    if(tab[(taille*(player->position_y)+(player->position_x))]=='o'){
        ConsoleUtils::clear();

        //TODO random en fonction de la rareté d'apparition
        Objet possibleObjects[]={test1, test2, test3};
        int random=rand()%nbObjet;

        //Fonction ajout Objet à inventaire
        ajoutObjetAInventaire(player, &possibleObjects[random], nbObjet);

        return true;
    }
    return false;
}
//
// Created by Aurore on 07/12/2021.
//