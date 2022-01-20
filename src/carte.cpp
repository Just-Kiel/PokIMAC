#include <iostream>
#include <stdlib.h>

#include "carte.h"

#include "variables.h"
#include "consoleUtils.hpp"
#include "objet.h"
#include "combat.h"
#include "menu.h"
#include "equipe.h"

using namespace std;

char perso = 'J';
char sol = '~';
char herbes = '#';
char objet = '@';
char pokimac_center = '&';
bool recupDone=false;

void affichageTab(char tab[], int taille){
    //Affichage du tableau
    for(int i=0; i<taille*taille; i++){
        if(i%taille==0 && i!=0){
            cout<<endl;
        }
        cout<<tab[i]<<"  ";
    }
    cout<<endl<<endl;
    
    ConsoleUtils::setColor(ConsoleUtils::Color::BLUE);
    std::cout<<"Te voici dans le bourg Coper, tu peux te deplacer avec ";
    ConsoleUtils::resetColors();

    ConsoleUtils::setColor(ConsoleUtils::Color::LIGHTBLUE);
    std::cout<<"zqsd";
    ConsoleUtils::resetColors();
    
    ConsoleUtils::setColor(ConsoleUtils::Color::BLUE);
    cout<<" ou les ";
    ConsoleUtils::resetColors();
    
    ConsoleUtils::setColor(ConsoleUtils::Color::LIGHTBLUE);
    std::cout<<"fleches directionnelles";
    ConsoleUtils::resetColors();
    
    ConsoleUtils::setColor(ConsoleUtils::Color::BLUE);
    cout<<", ouvrir l'inventaire avec ";
    ConsoleUtils::resetColors();
    
    ConsoleUtils::setColor(ConsoleUtils::Color::LIGHTBLUE);
    std::cout<<"i";
    ConsoleUtils::resetColors();

    ConsoleUtils::setColor(ConsoleUtils::Color::BLUE);
    cout<<", voir ton equipe avec ";
    ConsoleUtils::resetColors();

    ConsoleUtils::setColor(ConsoleUtils::Color::LIGHTBLUE);
    std::cout<<"e";
    ConsoleUtils::resetColors();
    
    ConsoleUtils::setColor(ConsoleUtils::Color::BLUE);
    cout<<" et revenir au menu avec la touche ";
    ConsoleUtils::resetColors();
    
    ConsoleUtils::setColor(ConsoleUtils::Color::LIGHTBLUE);
    std::cout<<"ESPACE";
    ConsoleUtils::resetColors(); std::cout << std::endl<<endl;
    
    ConsoleUtils::setColor(ConsoleUtils::Color::BLUE);
    ConsoleUtils::setBackgroundColor(ConsoleUtils::BackgroundColor::BG_YELLOW);
    std::cout <<"Comprendre la map : ";
    ConsoleUtils::resetColors(); std::cout << std::endl<<endl;
    
    ConsoleUtils::setColor(ConsoleUtils::Color::LIGHTYELLOW);
    cout<<perso;
    ConsoleUtils::setColor(ConsoleUtils::Color::BLUE);
    cout<<" : ca, c'est toi !"<<endl;
    ConsoleUtils::resetColors();
    
    ConsoleUtils::setColor(ConsoleUtils::Color::LIGHTYELLOW);
    cout<<herbes;
    ConsoleUtils::setColor(ConsoleUtils::Color::BLUE);
    cout<<" : les hautes herbes ou se cachent les PokIMACS"<<endl;
    ConsoleUtils::resetColors();
    
    ConsoleUtils::setColor(ConsoleUtils::Color::LIGHTYELLOW);
    cout<<sol;
    ConsoleUtils::setColor(ConsoleUtils::Color::BLUE);
    cout<<" : le chemin classique"<<endl;
    ConsoleUtils::resetColors();
    
    ConsoleUtils::setColor(ConsoleUtils::Color::LIGHTYELLOW);
    cout<<objet;
    ConsoleUtils::setColor(ConsoleUtils::Color::BLUE);
    cout<<" : de type 0, 1 ou 2, ils te permettront d'aider tes PokIMACS"<<endl;
    ConsoleUtils::resetColors();
    
    ConsoleUtils::setColor(ConsoleUtils::Color::LIGHTYELLOW);
    cout<<pokimac_center;
    ConsoleUtils::setColor(ConsoleUtils::Color::BLUE);
    cout<<" : c'est l'endroit ou tu peux faire soigner tes PokIMACS"<<endl;
    ConsoleUtils::resetColors();

}

void remplissageTab(char tab[], int taille){
    //Remplissage du tableau
    for(int i=0; i<(taille*taille); i++){
        tab[i]=sol;
    }

    int randomObject;

    //Positionnement random des objets
    for(int j=0; j<(taille*taille/5); j++){
        randomObject = rand()%((taille*taille)-1);
        tab[randomObject+1]=objet;
    }

    //Positionnement des mauvaises herbes
    for(int k=1; k<(taille*taille/3); k++){
        randomObject = rand()%(taille*taille) +1;
        if(tab[randomObject]!=objet){
            tab[randomObject]=herbes;
        }
    }

    //Positionnement du PokIMAC Center
    int center = taille/2;
    tab[center] = pokimac_center;

    affichageTab(tab, taille);
}

void affichageApresDeplacementCell(Joueur * player, char *tab, int taille){
    ConsoleUtils::setCursorPos(player->position_x*3, player->position_y);
    //Si le dresseur vient de récupérer un objet (et qu'il avait la place dans son inventaire), il n'est plus affiché sur la carte
    if(tab[(taille*(player->position_y)+(player->position_x))] == objet && recupDone){
        tab[(taille*(player->position_y)+(player->position_x))]=sol;
    }

    cout<<tab[(taille*(player->position_y)+(player->position_x))];
}

void deplacementTab(char tab[], int taille, Joueur* player){
    int min_hauteur_map = 0;

    //Deplacement sur le tableau
    bool move = true;
    bool detect = false;
    bool arrow = false;
    //Detection et déplacement en fonction des fleches et de ZQSD
    while(move && !detect) {
        ConsoleUtils::setCursorPos(player->position_x*3, player->position_y);
        cout << perso;
        char input = ConsoleUtils::getChar(&arrow);
        if(arrow){
            switch (input) {
                case ConsoleUtils::KEY_UP:
                    if (player->position_y >= min_hauteur_map) {
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
                case 'e':
                case 'E':
                    ConsoleUtils::clear();
                    ouvertureEquipe(player);
                    affichageTab(tab, taille);
                    break;
                case 'I':
                case 'i':
                    ConsoleUtils::clear();
                    ouvertureInventaire(player);
                    affichageTab(tab, taille);
                    break;
                case 'z':
                case 'Z':
                    if (player->position_y >= min_hauteur_map) {
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
                    confirmChoice(player, taille, tab);
                    break;
            }
        }
        if(input!= ' ') {
            detect = detection(tab, taille, player);
        }
    }

}

bool detection(char tab[], int taille, Joueur * player){
    if(tab[(taille*(player->position_y)+(player->position_x))]==objet){
        ConsoleUtils::clear();

        //Facultatif TODO random en fonction de la rareté d'apparition

        int random=rand()%nbObjet;

        //Fonction ajout Objet à inventaire
        recupDone=ajoutObjetAInventaire(player, allObject[random]);
        affichageTab(tab, taille);

    } else if(tab[(taille*(player->position_y)+(player->position_x))]==herbes){
        ConsoleUtils::clear();
        //Random vérifiant si un PokIMAC est dans la mauvaise herbe (permet de simuler le déplacement des pokIMACs)
        bool randomBoolPokIMAC =rand()%2;
        if(randomBoolPokIMAC){
            int randomPokIMAC=rand()%nbPokIMAC;
            affichageDebutCombat(player, allPokimac[randomPokIMAC], tab, taille);
            ConsoleUtils::clear();
        }

        affichageTab(tab, taille);
    } else if(tab[(taille*(player->position_y)+(player->position_x))]==pokimac_center){
        ConsoleUtils::clear();
        soinPokimacCenter(player);

        detectSpace();

        affichageTab(tab, taille);
    }
    return false;
}
//
// Created by Aurore on 07/12/2021.
//
