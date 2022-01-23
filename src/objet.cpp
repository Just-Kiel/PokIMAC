//
// Created by Aurore on 19/12/2021.
//
#include "objet.h"

#include "menu.h"
#include "variables.h"
#include "consoleUtils.hpp"
using namespace std;

bool ajoutObjetAInventaire(Joueur * player, Objet object){
    bool recup = false;
    int size_inventaire = sizeof (player->inventaire)/sizeof(player->inventaire[0]);
    for(int i=0; i<size_inventaire; i++){
        //Si la place de l'inventaire est vide l'objet est récupéré
        if(player->inventaire[i].nom == ""){
            player->inventaire[i]=object;
            recup = true;
        }
    }

    if(!recup){
        ConsoleUtils::setColor(ConsoleUtils::Color::LIGHTRED);
        cout<<"Malheureusement plus de place dans ton inventaire ! Utilise des objets avant !"<<endl;
        ConsoleUtils::resetColors(); std::cout << std::endl<<endl;
    } else {
        cout << object.visuel << endl;
        ConsoleUtils::setColor(ConsoleUtils::Color::LIGHTCYAN);
        cout << "L'objet " << object.nom << " vient d'etre ajoute a ton inventaire !" << endl;
        ConsoleUtils::resetColors(); std::cout << std::endl<<endl;
        ConsoleUtils::setColor(ConsoleUtils::Color::BLUE);
        ConsoleUtils::setBackgroundColor(ConsoleUtils::BackgroundColor::BG_YELLOW);
        cout << "Voici son utilite : ";
        ConsoleUtils::resetColors();
        ConsoleUtils::setColor(ConsoleUtils::Color::BLUE);
        cout << object.definition << endl;
        ConsoleUtils::resetColors(); std::cout << std::endl<<endl;

    }
    detectSpace();
    return recup;
}

int capturePokIBALL(Joueur * player, Pokimac * pokimac){
    Objet pokiball=allObject[0];
    bool recup = false;
    if(pokimac->pv<=10) {
        for (int i = 0; i < sizeInventaire; i++) {
            if (player->inventaire[i].nom == pokiball.nom) {
                for (int j = 0; j < 7; j++) {
                    if (player->equipe[j].nom == videPokimac.nom) {
                        player->equipe[j] = *pokimac;
                        recup = true;
                        ConsoleUtils::setColor(ConsoleUtils::Color::LIGHTCYAN);
                        cout << "Tu as capture " << pokimac->nom << endl;
                        ConsoleUtils::resetColors();
                        detectSpace();
                        break;
                    }
                }
                player->inventaire[i] = vide;
                break;
            }
        }
    }
    if(pokimac->pv>10){
        ConsoleUtils::setColor(ConsoleUtils::Color::LIGHTGREEN);
        cout<<"Tu n'as pas pu capture le PokIMAC, desole !"<<endl;
        ConsoleUtils::resetColors();

        detectSpace();
        return 0;
    }else if(!recup){
        ConsoleUtils::setColor(ConsoleUtils::Color::LIGHTRED);
        cout<<"Tu n'as plus de PokIBALL !"<<endl;
        ConsoleUtils::resetColors();

        detectSpace();
        return 0;
    }else{
        return 2;
    }
}

void ouvertureInventaire(Joueur * player, bool inCombat, int pokimacUser){
    int nbObjetMax=0;
    
    ConsoleUtils::setColor(ConsoleUtils::Color::BLUE);
    ConsoleUtils::setBackgroundColor(ConsoleUtils::BackgroundColor::BG_YELLOW);
    cout<<"Dans ton inventaire il y a :"<<endl<<endl;
    ConsoleUtils::resetColors();


    for(int i=0; i<sizeInventaire; i++){
        if(player->inventaire[i].nom != vide.nom && (!inCombat || player->inventaire[i].nom != allObject[0].nom)){
            
            ConsoleUtils::setColor(ConsoleUtils::Color::BLUE);
            cout<< i+1 <<". "<<player->inventaire[i].nom<<endl;
            ConsoleUtils::resetColors();

            nbObjetMax=i+1;
        }
    }
    cout<<sizeInventaire+1<<". Retour"<<endl;

    char user_choice;
    cout << "Ton choix : ";
    ConsoleUtils::setColor(ConsoleUtils::Color::LIGHTMAGENTA);
    cin >> user_choice;
    ConsoleUtils::resetColors();


    while(user_choice!=(char)(sizeInventaire+1+48) && (user_choice<'1' || user_choice>(char)(nbObjetMax+48))){
        ConsoleUtils::setColor(ConsoleUtils::Color::LIGHTRED);
        cout<<"Ce choix n'est pas valide ! Tu dois choisir entre 1 et "<<(char)(nbObjetMax+48)<<" ou "<<(char)(48+sizeInventaire+1)<<"."<<endl<<endl;
        ConsoleUtils::resetColors();

        cout << "Ton choix : ";
        ConsoleUtils::setColor(ConsoleUtils::Color::LIGHTMAGENTA);
        cin >> user_choice;
        ConsoleUtils::resetColors();

    }

    cin.ignore(numeric_limits<streamsize>::max(),'\n');

    if(user_choice == (char)(sizeInventaire+1+48)){
        ConsoleUtils::clear();
    } else {
        Objet * current_objet = &(player->inventaire[(user_choice-1-48)]);
        howToUse(*current_objet);

        if(inCombat){
            useInCombat(current_objet, &player->equipe[pokimacUser]);
        } else {
            ouvertureInventaire(player, inCombat);
        }
    }
}

void howToUse(Objet objet){
    ConsoleUtils::clear();
    cout << objet.visuel << endl;
    ConsoleUtils::setColor(ConsoleUtils::Color::LIGHTBLUE);
    cout << objet.nom << endl;
    ConsoleUtils::resetColors();
    ConsoleUtils::setColor(ConsoleUtils::Color::BLUE);
    ConsoleUtils::setBackgroundColor(ConsoleUtils::BackgroundColor::BG_YELLOW);
    cout << "Son utilite : ";
    ConsoleUtils::resetColors();
    ConsoleUtils::setColor(ConsoleUtils::Color::BLUE);
    cout << objet.definition << endl;
    ConsoleUtils::resetColors();


    detectSpace();
}

int multiplicateurObjet = 1;

void useInCombat(Objet * useObject, Pokimac * player_pokimac){
    Pokimac refPokIMAC;
    for(int i = 0; i<nbPokIMAC; i++){
        if(allPokimac[i].nom == player_pokimac->nom){
            refPokIMAC = allPokimac[i];
        }
    }
    if(useObject->id_type == 1){
        if (player_pokimac->pv<refPokIMAC.pv){
            ConsoleUtils::setColor(ConsoleUtils::Color::LIGHTGREEN);
            cout << "Ton pokIMAC voit ses PV se regenerer !"<<endl;
            ConsoleUtils::resetColors();

            int pvMissing = refPokIMAC.pv - player_pokimac->pv;
            if(pvMissing<useObject->puissance){
                player_pokimac->pv += pvMissing;
            } else {
                player_pokimac->pv+=useObject->puissance;
            }
            *useObject = vide;
        } else {
            ConsoleUtils::setColor(ConsoleUtils::Color::LIGHTRED);
            cout << "Tu as deja trop de PV, pas besoin d'utiliser ce style d'objet !"<<endl;
            ConsoleUtils::resetColors();

        }
    } else if(useObject->id_type == 2){
        multiplicateurObjet = useObject->puissance;

        *useObject = vide;
    }
}
