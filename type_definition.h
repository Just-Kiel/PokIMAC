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

typedef struct{
    
    string nom_attaque;
    int pouvoir;
    
}attaque;

typedef struct {
    
    string objet;
    string pokiballs;
    string rares;
    string cpcs;
    
} inventaire;


typedef struct {
    
    string nom;
    string espece;
    string representation;
    int pv;
    int force;
    int defense;
    
} pokimac;


typedef struct{
    
    string nom;
    pokimac equipe[] ;
    inventaire equipement;
    
    
} joueur;

#endif /* type_definition_h */
