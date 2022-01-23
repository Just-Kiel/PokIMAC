//
// Created by Aurore on 23/01/2022.
//
#include "type_definition.h"

#ifndef PROJET_SAVE_H
#define PROJET_SAVE_H
void save(const Joueur* player);
void writeJoueur(const Joueur * player, fstream & myFile);
void writeObjet(const Objet * objet, fstream & myFile);
void writePokimac(const Pokimac * pokimac, fstream & myFile);
#endif //PROJET_SAVE_H
