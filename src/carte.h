//
// Created by Aurore on 07/12/2021.
//
#include "type_definition.h"
#ifndef PROJET_CARTE_H
#define PROJET_CARTE_H
extern char pokimac_center;
void affichageTab(char tab[], int taille);
void remplissageTab(char tab[], int taille);
void deplacementTab(char tab[], int taille, Joueur * player);
bool detection(char tab[], int taille, Joueur * player);
void affichageApresDeplacementCell(Joueur * player, char *tab, int taille);
#endif //PROJET_CARTE_H
