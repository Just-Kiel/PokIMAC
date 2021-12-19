//
// Created by Aurore on 07/12/2021.
//
#include "type_definition.h"
#include "consoleUtils.hpp"
#include "variables.h"
#include "objet.h"
#ifndef PROJET_CARTE_H
#define PROJET_CARTE_H
void changementTab(char tab[], int taille);
void affichageTab(char tab[], int taille);
void remplissageTab(char tab[], int taille);
void deplacementTab(char tab[], int taille, Joueur * player);
bool detection(char tab[], int taille, Joueur * player);
void affichageApresDeplacementCell(Joueur * player, char *tab, int taille);
#endif //PROJET_CARTE_H
