
//
// Created by Sarah on 07/12/2021.
//

using namespace std;
#include <iostream>
#include <cstring>


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
