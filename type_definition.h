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
    
}Attaque;

typedef struct {
    
    string objet;
    string pokiballs;
    string rares;
    string cpcs;
    
} Inventaire;


typedef struct {
    
    string nom;
    string espece;
    string representation;
    int pv;
    int force;
    int defense;
    
} Pokimac;


typedef struct{
    
    string nom;
    Pokimac equipe[] ;
    Inventaire equipement;
    
    
<<<<<<< Updated upstream:type_definition.h
} joueur;

#endif /* type_definition_h */
=======
} Joueur;
>>>>>>> Stashed changes:type_definition.cpp
