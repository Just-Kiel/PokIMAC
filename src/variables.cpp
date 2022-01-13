//
//  variables.cpp
//  
//
//  Created by Sarah N'GOTTA on 07/12/2021.
//
#include "variables.h"

// Tableau qui rassemble tous les pokimacs

const Objet allObject[nbObjet]={
        {"PokIBALL", "permet de capturer des pokIMACs", 0, "P", 0.9}
};

// Tableau vide qui va se remplir avec les objets au fur et a mesure du jeu

const Objet vide={"", "",0,"",0};


// Tableau qui rassemble tous les pokimacs

const Pokimac allPokimac[12]= {
        {"Robbizarre", "culture","R" , 80, {{"Perspective", 10}, {"Exposition", 5}}},
        {"Nosteevrapti", "programmation","N" , 50, {{"TP", 8}, {"C++", 12}}},
        {"Ozlameche", "culture", "O", 70, {{"Expose", 20}, {"In english please", 6}}},
        {"Soniafee", "aide", "S", 100, {{"Emploi du temps", 4}, {"Cle", 8}}},
        {"Laporteille", "programmation", "L", 80, {{"Video", 8}, {"Pointeur", 12}}},
        {"Nocvelli", "mathematiques", "N", 120, {{"Integration", 25}, {"Contre-intuition", 20}}},
        {"Rieulu", "mathematiques", "R", 140, {{"TD", 10}, {"Explications", 8}}},
        {"Gairrarlande", "culture", "G", 70, {{"Culture", 15}, {"Controles", 17}}},
        {"Charpenti", "programmation", "C", 80, {{"CSS", 9}, {"Twitter", 5}}},
        {"Enguerratueur", "aide", "E", 100, {{"Photo", 5}, {"Diplome", 8}}},
        {"Gautiplouf", "design", "G", 50, {{"Pixel Art", 12}, {"JeudIMAC", 14}}},
        {"Chataiglam", "design", "C", 90, {{"Repertoire", 9}, {"Croquis", 16}}}
};

const Pokimac videPokimac={"", "", "", 0, {{"", 0}, {"", 0}}};
