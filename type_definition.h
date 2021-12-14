//
//  type_definition.h
//  
//
//  Created by Sarah N'GOTTA on 10/12/2021.
//

#ifndef type_definition_h
#define type_definition_h

#include <iostream>
#include <cstring>
using namespace std;

// structure attaque qui définie les atatques des pokimacs

typedef struct{
    
    string nom_attaque; //nom de l'attaque
    int puissance; // puissance de l'attaque
    
}Attaque;

// structure Objet qui définie les objets présent dans l'inventaire (sac a dos) du joueur

typedef struct {
    
    string nom; //nom de l'objet
    string definition; // a quoi il sert
    int id_type; //quel est son type : pokiball, rare, obj du quotidien...
    string visuel; // visuel de l'objet
    float apparition; //combien de fois il va apparaitre dans le jeu, sa rareté
    
    
} Objet;

// structure Pokimac qui définie les Pokimacs


typedef struct {
    
    string nom; //nom du pokimac
    string espece; // son espece : 3D, graphisme, communication, dev, inté, audiovisuelle...
   // int representation; // visuel du pokimac
    int pv; // nombre de pv du pokimac
   // int resistance; //
  //  int defense; // quantité de pv qu'un pokimac peut encaisser sans perdre de vie lorsqu'il subit lors d'une attanque par un adversaire
    Attaque pouvoir[2] ; //attaque propre au pokimac defini par le type attaque
    
} Pokimac;

// structure Joueur qui définie le joueur

typedef struct{
    
    string nom; //nom du joueur
    Pokimac equipe[6] ; //composition de son équipe de pokemon, via la struct pokimac
    Objet inventaire[2] ; // composition de son sac a dos, via la struct objet
    int position_x;
    int position_y;
    
}Joueur;

#endif /* type_definition_h */
