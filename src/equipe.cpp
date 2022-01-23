//
// Created by Aurore on 17/01/2022.
//

#include "equipe.h"

#include "type_definition.h"
#include "variables.h"
#include "menu.h"
#include "consoleUtils.hpp"

using namespace std;

void ouvertureEquipe(Joueur * player){
    int nbPokimacMax = 0;
    
    ConsoleUtils::setColor(ConsoleUtils::Color::BLUE);
    ConsoleUtils::setBackgroundColor(ConsoleUtils::BackgroundColor::BG_YELLOW);
    cout << "Dans ton equipe il y a :" << endl;
    ConsoleUtils::resetColors(); std::cout << std::endl<<endl;

    for(int i = 0; i<sizeEquipe; i++){
        if(player->equipe[i].nom != videPokimac.nom){
            ConsoleUtils::setColor(ConsoleUtils::Color::BLUE);
            cout << i+1 << ". " << player->equipe[i].nom<<endl<<endl;
            ConsoleUtils::resetColors(); std::cout << std::endl;
            nbPokimacMax++;
        }
    }

    cout<<sizeEquipe+1<<". Retour"<<endl;

    char user_choice;
    cout << "Ton choix : ";
    
    ConsoleUtils::setColor(ConsoleUtils::Color::LIGHTMAGENTA);
    cin >> user_choice;
    ConsoleUtils::resetColors(); std::cout << std::endl<<endl;

    while(user_choice!=(char)(sizeEquipe+1+48) && (user_choice<'1' || user_choice>(char)(48+nbPokimacMax))){
        ConsoleUtils::setColor(ConsoleUtils::Color::LIGHTRED);
        cout<<"Ce choix n'est pas valide ! Tu dois choisir entre 1 et "<<nbPokimacMax<<" ou "<<sizeEquipe+1<<"."<<endl;
        ConsoleUtils::resetColors(); std::cout << std::endl<<endl;

        cout << "Ton choix : ";
        
        ConsoleUtils::setColor(ConsoleUtils::Color::LIGHTMAGENTA);
        cin >> user_choice;
        ConsoleUtils::resetColors(); std::cout << std::endl<<endl;

    }

    cin.ignore(numeric_limits<streamsize>::max(),'\n');

    if(user_choice == (char)(48+sizeEquipe+1)){
        ConsoleUtils::clear();
    } else {
        ConsoleUtils::clear();
        cout << player->equipe[user_choice-1-48].representation << endl<<endl;
        ConsoleUtils::setColor(ConsoleUtils::Color::LIGHTBLUE);
        cout << player->equipe[user_choice-1-48].nom << endl;
        ConsoleUtils::resetColors(); std::cout << std::endl<<endl;
        ConsoleUtils::setColor(ConsoleUtils::Color::LIGHTYELLOW);
        cout << "Type : " << player->equipe[user_choice-1-48].espece << endl;
        cout << "PV : " << player->equipe[user_choice-1-48].pv << endl;
        ConsoleUtils::resetColors(); std::cout << std::endl<<endl;

        detectSpace();

        ouvertureEquipe(player);
    }
}

void soinPokimacCenter(Joueur * player){
    
    ConsoleUtils::setColor(ConsoleUtils::Color::LIGHTGREEN);
    cout << "Tes PokIMACs sont soignes !"<< endl;
    ConsoleUtils::resetColors(); std::cout << std::endl<<endl;

    for(int all = 0; all<nbPokIMAC; all++) {
        for (int i = 0; i < sizeEquipe; i++) {
            if (player->equipe[i].nom == allPokimac[all].nom) {
                player->equipe[i].pv = allPokimac[all].pv;
            }
        }
    }
}
