//
// Created by Aurore on 07/12/2021.
//
#include "type_definition.h"
#include "carte.h"
#ifndef PROJET_MENU_H
#define PROJET_MENU_H
extern char * map;
int sizeMap();
void printMenu();
void initPlayer(Joueur *player);
void detectSpace();
void confirmChoice(Joueur * player, int taille, char tab[]);
#endif //PROJET_MENU_H
