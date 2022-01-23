//
// Created by Aurore on 23/01/2022.
//
#include <iostream>
#include <fstream>

#include <limits>

#include "save.h"

#include "variables.h"

using namespace std;

void save(const Joueur* player) {
    fstream saveFile("save.txt",ios::out|ios::trunc);
    writeJoueur(player, saveFile);
    saveFile.close();
}

void writeJoueur(const Joueur * player, fstream & myFile){
    myFile << player->nom << "," << player->position_x << "," << player->position_y << "," << endl;
    for (int i = 0; i < sizeInventaire; i++) {
        writeObjet(&(player->inventaire[i]), myFile);
    }
    myFile << endl;
    for(int i = 0; i < sizeEquipe; i++) {
        writePokimac(&(player->equipe[i]), myFile);
    }
}

void writeObjet(const Objet * objet, fstream & myFile){
    myFile << objet->nom << ",";
}

void writePokimac(const Pokimac * pokimac, fstream & myFile){
    myFile << pokimac->nom << "," << pokimac->pv << "," << endl;
}

void load(Joueur * player){
    ifstream readFile("save.txt", ios::in);
    readJoueur(player, readFile);
    readFile.close();
}

void readJoueur(Joueur * player, ifstream & myFile){
    // Extrait ce qui est avant la premiere , pour remplir la variable
    getline(myFile, player->nom, ',');
    myFile >> player->position_x;
    myFile.ignore(1);
    myFile >> player->position_y;

    myFile.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int i = 0; i < sizeInventaire; i++) {
        readObjet(&(player->inventaire[i]), myFile);
    }

    myFile.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int i = 0; i < sizeEquipe ; i++) {
        readPokimac(&(player->equipe[i]), myFile);
        myFile.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

void readObjet(Objet * objet, ifstream & myFile){
    getline(myFile, objet->nom, ',');
    Objet ref;
    if(objet->nom == vide.nom){
        ref = vide;
        objet = &ref;
    } else {
        for (int i = 0; i < nbObjet; i++) {
            if (objet->nom == allObject[i].nom) {
                ref = allObject[i];
                objet->puissance = ref.puissance;
                objet->apparition = ref.apparition;
                objet->visuel = ref.visuel;
                objet->id_type = ref.id_type;
                objet->definition = ref.definition;
                break;
            }
        }
    }
}

void readPokimac(Pokimac * pokimac, ifstream & myFile){
    getline(myFile, pokimac->nom, ',');
    myFile >> pokimac->pv;
    Pokimac ref;
    if(pokimac->nom == videPokimac.nom){
        ref = videPokimac;
        pokimac = &ref;
    } else {
        for (int i = 0; i < nbPokIMAC; i++) {
            if(pokimac->nom == allPokimac[i].nom){
                pokimac->espece = allPokimac[i].espece;
                pokimac->representation = allPokimac[i].representation;
                for(int j = 0; j < nbAttaque; j++){
                    pokimac->pouvoir[j] = allPokimac[i].pouvoir[j];
                }
                break;
            }
        }
    }
}

//typedef struct Objet{
//
//    string nom; //nom de l'objet
//    string definition; // a quoi il sert
//    int id_type; //quel est son type : 0, 1, 2...
//    string visuel; // visuel de l'objet
//    float apparition; //combien de fois il va apparaitre dans le jeu, sa rareté
//    int puissance; //force de l'action
//
//    friend std::ostream& operator<<(std::ostream& os, const struct Objet& o)
//    {
//        return os << o.nom << ',';
//    }
//
//    friend std::istream& operator>>(std::istream& is, struct Objet& o)
//    {
//        getline(is, o.nom, ',');
//        return is;
//    }
//
//} Objet;
//
//// structure Pokimac qui définie les Pokimacs
//
//constexpr int nbAttaque = 2;
//
//typedef struct {
//
//    string nom; //nom du pokimac
//    string espece; // son espece : 3D, graphisme, communication, dev, inté, audiovisuelle...
//    string representation; // visuel du pokimac
//    int pv; // nombre de pv du pokimac
//    Attaque pouvoir[nbAttaque] ; //attaque propre au pokimac defini par le type attaque
//
//} Pokimac;
//
//// structure Joueur qui définit le joueur
//constexpr int sizeInventaire = 2;
//constexpr int sizeEquipe = 6;
//typedef struct Joueur {
//
//    string nom; //nom du joueur
//    Pokimac equipe[sizeEquipe] ; //composition de son équipe de pokemon, via la struct pokimac
//    Objet inventaire[sizeInventaire] ; // composition de son sac a dos, via la struct objet
//    int position_x;
//    int position_y;
//
//    friend std::ostream& operator<<(std::ostream& os, const struct Joueur& j)
//    {
//
//        os << j.nom << "," << j.position_x << "," << j.position_y << "," << endl;
//        for (int i = 0; i < sizeInventaire; i++) {
//            os << j.inventaire[i];
//        }
//
//        return os;
//    }
//
//    friend std::istream& operator>>(std::istream& is, struct Joueur& j)
//    {
//        getline(is, j.nom, ',');
//        is >> j.position_x;
//        is.ignore(1);
//        is >> j.position_y;
//        is.ignore(numeric_limits<streamsize>::max(), '\n');
//
//        for (int i = 0; i < sizeInventaire; i++) {
//            is >> j.inventaire[i];
//        }
//
//        return is;
//    }
//
//}Joueur;