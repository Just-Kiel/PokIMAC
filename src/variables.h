#include "type_definition.h"
#ifndef PROJET_VARIABLES_H
#define PROJET_VARIABLES_H
//
//  variables.cpp
//
//
//  Created by Sarah N'GOTTA on 07/12/2021.
//

constexpr int nbObjet = 1;
extern const Objet allObject[nbObjet];
extern const Objet vide;

constexpr int nbPokIMAC = 12;
extern const Pokimac allPokimac[nbPokIMAC];
extern const Pokimac videPokimac;
/*
Pokimac Robbizarre = {.nom="Robbizarre",
                     .espece="culture",
                     .representation="Robibi",
                     .pv=80,
                     //.pouvoir={perspective, exposition}
                     };
*/
/*Nosteevrapti={"Nosteevrapti", "programmation", 50, pouvoir[tp,c++ ]};

Ozlameche={"Ozlameche", "culture", 70, pouvoir[expose, inenglishplease] };

Soniafee={"Soniafee", "aide", 100, pouvoir[edt,cle]};

Laporteille={"Laporteille", "programmation", 80, pouvoir[video, pointeur]};

Nocvelli={ "Nocvelli", "mathematiques", 120, pouvoir[integration,contreintuition]};

Rieulu={"Rieulu", "mathematiques", 140, pouvoir[td, explications]};

Guerrarlande={ "Guerrarlande", "culture", 70, pouvoir[culture, controles]};

Charpenti={ "Charpenti", "programmation", 80, pouvoir[css, twitter]};

Enguerratueur={ "Enguerratueur", "aide", 100, pouvoir[photo, diplome]};

Gautiplouf={ "Gautiplouf", "design", 50, pouvoir[pixelart, jeudimac] };

Chataiglam={ "Chataiglam", "design", 90, pouvoir[repertoire, croquis]};

Attaque perspective, exposition, tp, c++ , expose, inenglishplease, edt, cle, video, pointeur, integration, contreintuition, td, explications, culture, controles, css, twitter, photo, diplome;

*/
#endif //PROJET_VARIABLES_H
