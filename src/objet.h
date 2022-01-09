//
// Created by Aurore on 19/12/2021.
//
#include "type_definition.h"
#ifndef PROJET_OBJET_H
#define PROJET_OBJET_H
bool ajoutObjetAInventaire(Joueur * player, Objet object);
int capturePokIBALL(Joueur * player, Pokimac * pokimac);
void ouvertureInventaire(Joueur * player, bool inCombat=false);
#endif //PROJET_OBJET_H
