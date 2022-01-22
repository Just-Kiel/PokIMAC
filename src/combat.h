//
// Created by Aurore on 20/12/2021.
//
#include "type_definition.h"
#ifndef PROJET_COMBAT_H
#define PROJET_COMBAT_H
void affichageDebutCombat(Joueur * player, Pokimac pokimac, char tab[], int taille);
int choixCombat(Joueur * player, Pokimac * pokimac, int * pokimacUser);
int choixPokIMAC(Joueur * player);
void attaqueCombat(Pokimac * player_pokimac, Pokimac * enemy_pokimac);
int multiplicateurType(Pokimac attaque, Pokimac defense);
#endif //PROJET_COMBAT_H
