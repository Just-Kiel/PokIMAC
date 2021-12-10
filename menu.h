//
// Created by Aurore on 07/12/2021.
//

#ifndef PROJET_MENU_H
#define PROJET_MENU_H

int sizeMap();
void printMenu();

typedef struct {

    std::string objet;
    std::string pokiballs;
    std::string rares;
    std::string cpcs;

} Inventaire;


typedef struct {

    std::string nom;
    std::string espece;
    std::string representation;
    int pv;
    int force;
    int defense;

} Pokimac;
typedef struct{
    std::string nom;
    Pokimac equipe[6] ;
    Inventaire equipement;
} Joueur;

void initPlayer(Joueur *player);

#endif //PROJET_MENU_H
