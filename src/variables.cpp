//
//  variables.cpp
//  
//
//  Created by Sarah N'GOTTA on 07/12/2021.
//
#include "variables.h"

// Tableau qui rassemble tous les objets

const Objet allObject[nbObjet]={
        {"PokIBALL", "permet de capturer des pokIMACS", 0, "P", 0.9},
        {"Biere", "permet de regenerer 5 PV au PokIMAC de ton choix", 1, "B", 0.9},
        {"Mojito", " permet de regenerer 10 PV au PokIMAC de ton choix", 1, "M", 0.9},
        {"Chocolat Chaud", " permet de regenerer 15 PV au PokIMAC de ton choix", 1, "CC", 0.9},
        {"Repas Crous", " permet de regenerer 20 PV au PokIMAC de ton choix", 1, "RC", 0.9},
        {"Cassoulet", " permet de regenerer 25 PV au PokIMAC de ton choix", 1, "C", 0.9},
        {"Sel", " augmente x2.0 la puissance de toutes tes attaques - valable 1 fois / combat", 2, "S", 0.9},
        {"Weekend", " augmente x3 la puissance de toutes tes attaques - valable 1 fois / combat", 2, "WK", 0.9},
        {"Presentiel", " augmente x4 la puissance de toutes tes attaques - valable 1 fois / combat", 2, "PR", 0.9},
        {"Billet de Train", " augmente x5 la puissance de toutes tes attaques - valable 1 fois / combat", 2, "BT", 0.9},
        {"Sommeil Reparateur", " augmente x10 la puissance de toutes tes attaques - valable 1 fois / combat", 2, "SR", 0.9}
};

// Tableau vide qui va se remplir avec les objets au fur et a mesure du jeu

const Objet vide={"", "",0,"",0};


// Tableau qui rassemble tous les pokimacs

const Pokimac allPokimac[12]= {
        {"Robbizarre", "Culture","R" , 80, {{"Perspective", 10}, {"Exposition", 5}}},
        {"Nosteevrapti", "Programmation","N" , 50, {{"TP", 8}, {"C++", 12}}},
        {"Ozlameche", "Culture", "O", 70, {{"Expose", 20}, {"In english please", 6}}},
        {"Soniafee", "Aide", "S", 100, {{"Emploi du temps", 4}, {"Cle", 8}}},
        {"Laporteille", "Programmation", "L", 80, {{"Video", 8}, {"Pointeur", 12}}},
        {"Nocvelli", "Mathematiques", "N", 120, {{"Integration", 25}, {"Contre-intuition", 20}}},
        {"Rieulu", "Mathematiques", "R", 140, {{"TD", 10}, {"Explications", 8}}},
        {"Gairrarlande", "Culture", "G", 70, {{"Culture", 15}, {"Controles", 17}}},
        {"Charpenti", "Programmation", "C", 80, {{"CSS", 9}, {"Twitter", 5}}},
        {"Enguerratueur", "Aide", "E", 100, {{"Photo", 5}, {"Diplome", 8}}},
        {"Gautiplouf", "Design", "G", 50, {{"Pixel Art", 12}, {"JeudIMAC", 14}}},
        {"Chataiglam", "Design", "C", 90, {{"Repertoire", 9}, {"Croquis", 16}}}
};

// Tableau vide qui va se remplir avec les PokIMACS au fur et a mesure du jeu

const Pokimac videPokimac={"", "", "", 0, {{"", 0}, {"", 0}}};
