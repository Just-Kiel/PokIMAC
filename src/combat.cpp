//
// Created by Aurore on 20/12/2021.
//
#include <iostream>
#include <stdlib.h>
#include <iomanip>

#include "combat.h"

#include "consoleUtils.hpp"
#include "variables.h"
#include "menu.h"
#include "objet.h"
#include "equipe.h"
using namespace std;

void affichageDebutCombat(Joueur * player, Pokimac pokimac, char tab[], int taille){
    
    ConsoleUtils::setColor(ConsoleUtils::Color::BLUE);
    ConsoleUtils::setBackgroundColor(ConsoleUtils::BackgroundColor::BG_YELLOW);
    cout<<"Oh non te voici face a "<<pokimac.nom<<endl;
    ConsoleUtils::resetColors(); std::cout << std::endl<<endl;

    int nbChoixPokIMAC= choixPokIMAC(player);
    int statusFight=0;
    while(pokimac.pv>0 && player->equipe[nbChoixPokIMAC].pv>0 && statusFight!=2) {
        
        ConsoleUtils::setColor(ConsoleUtils::Color::LIGHTWHITE);
        ConsoleUtils::setBackgroundColor(ConsoleUtils::BackgroundColor::BG_MAGENTA);
        cout << left << setw(20) << player->equipe[nbChoixPokIMAC].nom ;
        ConsoleUtils::resetColors();

        ConsoleUtils::setColor(ConsoleUtils::Color::LIGHTWHITE);
        ConsoleUtils::setBackgroundColor(ConsoleUtils::BackgroundColor::BG_CYAN);
        cout<< pokimac.nom << endl;
        ConsoleUtils::resetColors(); std::cout << std::endl;
        
        ConsoleUtils::setColor(ConsoleUtils::Color::MAGENTA);
        cout << "Type : " << left << setw(13) << player->equipe[nbChoixPokIMAC].espece ;
        ConsoleUtils::resetColors();
        ConsoleUtils::setColor(ConsoleUtils::Color::CYAN);
        cout << " Type : " << pokimac.espece << endl;
        ConsoleUtils::resetColors();
        ConsoleUtils::setColor(ConsoleUtils::Color::MAGENTA);
        cout << "PV : " << left << setw(15) << player->equipe[nbChoixPokIMAC].pv ;
        ConsoleUtils::resetColors();
        ConsoleUtils::setColor(ConsoleUtils::Color::CYAN);
        cout << "   PV : " << pokimac.pv << endl;
        ConsoleUtils::resetColors(); std::cout << std::endl<<endl;

        statusFight = choixCombat(player, &pokimac, &nbChoixPokIMAC);
    }
    if(pokimac.pv<=0){
        
        ConsoleUtils::setColor(ConsoleUtils::Color::BLUE);
        ConsoleUtils::setBackgroundColor(ConsoleUtils::BackgroundColor::BG_YELLOW);
        cout<<pokimac.nom<<" est mort, tu as gagne !"<<endl;
        ConsoleUtils::resetColors(); std::cout << std::endl;

        detectSpace();
    } else if(player->equipe[nbChoixPokIMAC].pv<=0){
        for(int i = 0; i < sizeEquipe; i++){
            if(player->equipe[i].nom != videPokimac.nom && player->equipe[i].pv>0){
                ConsoleUtils::setColor(ConsoleUtils::Color::BLUE);
                ConsoleUtils::setBackgroundColor(ConsoleUtils::BackgroundColor::BG_YELLOW);
                cout << "Ton PokIMAC est blesse mais tu peux en envoyer un autre au combat !" << endl;
                ConsoleUtils::resetColors(); std::cout << std::endl;

                detectSpace();
                choixPokIMAC(player);
            } else {
                ConsoleUtils::setColor(ConsoleUtils::Color::WHITE);
                ConsoleUtils::setBackgroundColor(ConsoleUtils::BackgroundColor::BG_RED);
                cout << "Tu ne peux plus combattre ! Rends toi vite au PokIMAC Center le plus proche !" <<endl;
                ConsoleUtils::resetColors(); std::cout << std::endl;

                detectSpace();
                for(int i=0; i<(taille*taille); i++){
                    if(tab[i]==pokimac_center){
                        player->position_y = i/taille;
                        player->position_x = i%taille;
                        soinPokimacCenter(player);
                        break;
                    }
                }
            }
        }
    }
}

int choixCombat(Joueur * player, Pokimac * pokimac, int * pokimacUser){
    char user_fight;
   
    ConsoleUtils::setColor(ConsoleUtils::Color::BLUE);
    ConsoleUtils::setBackgroundColor(ConsoleUtils::BackgroundColor::BG_YELLOW);
    cout<<"Que souhaites tu faire ?";
    ConsoleUtils::resetColors(); std::cout << std::endl<<endl;

    cout<<"1. Attaquer"<<endl;
    cout<<"2. Capturer"<<endl;
    cout<<"3. Inventaire"<<endl;
    cout<<"4. Fuir"<<endl;
    cout<<"5. Changer de PokIMAC"<<endl<<endl;

    ConsoleUtils::setColor(ConsoleUtils::Color::BLUE);
    ConsoleUtils::setBackgroundColor(ConsoleUtils::BackgroundColor::BG_YELLOW);
    cout<<"Ton choix :";
    ConsoleUtils::resetColors(); std::cout << std::endl;

    ConsoleUtils::setColor(ConsoleUtils::Color::LIGHTMAGENTA);
    cin>> user_fight;
    ConsoleUtils::resetColors(); std::cout << std::endl;


    while(user_fight<'1' || user_fight>'5'){
        ConsoleUtils::setColor(ConsoleUtils::Color::LIGHTRED);
        cout<<"Ce choix n'est pas valide ! Tu dois choisir entre 1 et 5."<<endl;
        ConsoleUtils::resetColors(); std::cout << std::endl;

        ConsoleUtils::setColor(ConsoleUtils::Color::BLUE);
        ConsoleUtils::setBackgroundColor(ConsoleUtils::BackgroundColor::BG_YELLOW);
        cout<<"Ton choix :";
        ConsoleUtils::resetColors(); std::cout << std::endl;
        
        ConsoleUtils::setColor(ConsoleUtils::Color::LIGHTMAGENTA);
        cin>> user_fight;
        ConsoleUtils::resetColors(); std::cout << std::endl;
    }

    cin.ignore(numeric_limits<streamsize>::max(),'\n');

    ConsoleUtils::clear();

    if(user_fight == '1'){
        attaqueCombat(&player->equipe[*pokimacUser], pokimac);

        return 0;
    } else if(user_fight=='2') {
        // Tentative de capture avec lancement de PokIBALL
        int captureStatus=capturePokIBALL(player, pokimac);
        return captureStatus;

    } else if(user_fight == '3'){
        // Ouvre l'inventaire et permet le retour (pas encore possible d'agir vu que 0 objet possible)
        ouvertureInventaire(player, true, *pokimacUser);
        return 0;

    } else if(user_fight == '4'){
        // Fuite du combat
        
        ConsoleUtils::setColor(ConsoleUtils::Color::LIGHTGREEN);
        cout<<"Tu choisis de fuir le combat !"<<endl;
        ConsoleUtils::resetColors(); std::cout << std::endl;

        detectSpace();

        return 2;
    }else if(user_fight == '5'){
        // Changement de PokIMAC en combat
        *pokimacUser = choixPokIMAC(player);
        return 0;
    } else {
        return 0;
    }
}

int choixPokIMAC(Joueur * player){
    
    ConsoleUtils::setColor(ConsoleUtils::Color::BLUE);
    ConsoleUtils::setBackgroundColor(ConsoleUtils::BackgroundColor::BG_YELLOW);
    cout<<"Quel PokIMAC veux-tu envoyer ?"<<endl;
    ConsoleUtils::resetColors(); std::cout << std::endl;


    //Taille équipe PokIMAC du dresseur
    int nbTeamPokIMAC = sizeof(player->equipe)/sizeof (player->equipe[0]);
    int nbPokIMACMax=0;
    for(int i=0; i<nbTeamPokIMAC; i++){
        if(player->equipe[i].nom != videPokimac.nom){
            cout<<i+1<<". "<<player->equipe[i].nom<<endl<<endl;
            nbPokIMACMax++;
        }
    }

    char user_pokIMAC;

    ConsoleUtils::setColor(ConsoleUtils::Color::BLUE);
    ConsoleUtils::setBackgroundColor(ConsoleUtils::BackgroundColor::BG_YELLOW);
    cout<<"Ton choix : ";
    ConsoleUtils::resetColors(); std::cout << std::endl;
    
    ConsoleUtils::setColor(ConsoleUtils::Color::LIGHTMAGENTA);
    cin>>user_pokIMAC;
    ConsoleUtils::resetColors(); std::cout << std::endl;


    while((user_pokIMAC<'1' || user_pokIMAC>(char)(48+nbPokIMACMax))||player->equipe[user_pokIMAC-1-48].pv <= 0){
        if(user_pokIMAC<'1' || user_pokIMAC>(char)(48+nbPokIMACMax)){
            
            ConsoleUtils::setColor(ConsoleUtils::Color::LIGHTRED);
            cout << "Ce choix n'est pas valide ! Tu dois choisir entre 1 et " << nbPokIMACMax << "." << endl;
            ConsoleUtils::resetColors(); std::cout << std::endl;


        } else {
            ConsoleUtils::setColor(ConsoleUtils::Color::LIGHTRED);
            cout<<"Ton PokIMAC n'est pas en etat de se battre ! Envoie en un autre !"<<endl;
            ConsoleUtils::resetColors(); std::cout << std::endl;

        }
        
        ConsoleUtils::setColor(ConsoleUtils::Color::BLUE);
        ConsoleUtils::setBackgroundColor(ConsoleUtils::BackgroundColor::BG_YELLOW);
        cout<<"Ton choix : ";
        ConsoleUtils::resetColors(); std::cout << std::endl;
        
        ConsoleUtils::setColor(ConsoleUtils::Color::LIGHTMAGENTA);
        cin>>user_pokIMAC;
        ConsoleUtils::resetColors(); std::cout << std::endl;    }

    cin.ignore(numeric_limits<streamsize>::max(),'\n');

    ConsoleUtils::clear();
    return user_pokIMAC-1-48;
}

void attaqueCombat(Pokimac * player_pokimac, Pokimac * enemy_pokimac){

    ConsoleUtils::setColor(ConsoleUtils::Color::BLUE);
    ConsoleUtils::setBackgroundColor(ConsoleUtils::BackgroundColor::BG_YELLOW);
    cout<<player_pokimac->nom<<" peut attaquer avec :"<<endl;
    ConsoleUtils::resetColors(); std::cout << std::endl;

    for(int a=0; a<nbAttaque; a++){
        ConsoleUtils::setColor(ConsoleUtils::Color::BLUE);
        cout<<a+1<<". "<<player_pokimac->pouvoir[a].nom_attaque<<endl<<endl;
        ConsoleUtils::resetColors();
    }

    char user_choice;
    ConsoleUtils::setColor(ConsoleUtils::Color::BLUE);
    ConsoleUtils::setBackgroundColor(ConsoleUtils::BackgroundColor::BG_YELLOW);
    cout << "Ton choix : ";
    ConsoleUtils::resetColors(); std::cout << std::endl;

    ConsoleUtils::setColor(ConsoleUtils::Color::LIGHTMAGENTA);
    cin >> user_choice;
    ConsoleUtils::resetColors(); std::cout << std::endl;

    while(user_choice<'1' || user_choice>(char)(nbAttaque+1+48)){
        
        ConsoleUtils::setColor(ConsoleUtils::Color::LIGHTRED);
        cout<<"Ce choix n'est pas valide ! Tu dois choisir entre 1 et "<<nbAttaque<<"."<<endl;
        ConsoleUtils::resetColors(); std::cout << std::endl;
        
        ConsoleUtils::setColor(ConsoleUtils::Color::BLUE);
        ConsoleUtils::setBackgroundColor(ConsoleUtils::BackgroundColor::BG_YELLOW);
        cout << "Ton choix : ";
        ConsoleUtils::resetColors(); std::cout << std::endl;

        ConsoleUtils::setColor(ConsoleUtils::Color::LIGHTMAGENTA);
        cin >> user_choice;
        ConsoleUtils::resetColors(); std::cout << std::endl;
    }

    cin.ignore(numeric_limits<streamsize>::max(),'\n');

    ConsoleUtils::clear();

    ConsoleUtils::setColor(ConsoleUtils::Color::BLUE);
    ConsoleUtils::setBackgroundColor(ConsoleUtils::BackgroundColor::BG_YELLOW);
    cout<<"Tu attaques avec "<<player_pokimac->pouvoir[user_choice-1-48].nom_attaque<<endl;
    if(multiplicateurObjet!=1){
        for(int i=0; i<nbObjet; i++){
            if(allObject[i].puissance == multiplicateurObjet){
                cout<< allObject[i].nom << " est actif !" <<endl;
                break;
            }
        }
    }
    ConsoleUtils::resetColors(); std::cout << std::endl;

    int efficiency = multiplicateurType(*player_pokimac, *enemy_pokimac);

    if(efficiency == 1){
        enemy_pokimac->pv-=(player_pokimac->pouvoir[user_choice-1-48].puissance)*multiplicateurObjet;
    } else if(efficiency == 0){
        ConsoleUtils::setColor(ConsoleUtils::Color::LIGHTYELLOW);
        cout<<"C'est tres peu efficace !"<<endl<<endl;
        ConsoleUtils::resetColors(); std::cout << std::endl;

        enemy_pokimac->pv-=((player_pokimac->pouvoir[user_choice-1-48].puissance)*multiplicateurObjet)/2;
    } else if(efficiency == 2){
        ConsoleUtils::setColor(ConsoleUtils::Color::LIGHTGREEN);
        cout<<"C'est tres efficace !"<<endl<<endl;
        ConsoleUtils::resetColors(); std::cout << std::endl;

        enemy_pokimac->pv-=((player_pokimac->pouvoir[user_choice-1-48].puissance)*multiplicateurObjet)*2;
    }
    
    ConsoleUtils::setColor(ConsoleUtils::Color::LIGHTCYAN);
    cout<<enemy_pokimac->nom<<" contre-attaque !"<<endl;
    ConsoleUtils::resetColors(); std::cout << std::endl;


    int randAttaque = rand()%nbAttaque;

    efficiency = multiplicateurType(*enemy_pokimac, *player_pokimac);

    if(efficiency == 1) {
        player_pokimac->pv -= enemy_pokimac->pouvoir[randAttaque].puissance;
    } else if(efficiency == 0){
        player_pokimac->pv -= (enemy_pokimac->pouvoir[randAttaque].puissance)/2;
    } else if(efficiency == 2){
        player_pokimac->pv -= (enemy_pokimac->pouvoir[randAttaque].puissance)*2;
    }

    multiplicateurObjet = 1;
    detectSpace();
}

int multiplicateurType(Pokimac attaque, Pokimac defense){
    int multiply = 1;
    if(attaque.espece == "Culture"){
        if(defense.espece=="Mathematiques"){
            multiply=0;
        } else if(defense.espece == "Design") {
            multiply = 2;
        }
    } else if(attaque.espece == "Programmation"){
        if(defense.espece == "Aide"){
            multiply = 2;
        } else if(defense.espece == "Design"){
            multiply = 0;
        }
    } else if(attaque.espece == "Aide"){
        if(defense.espece == "Mathematiques"){
            multiply = 2;
        } else if(defense.espece == "Programmation"){
            multiply = 0;
        }
    } else if(attaque.espece == "Design"){
        if(defense.espece == "Programmation"){
            multiply = 2;
        } else if(defense.espece == "Culture"){
            multiply = 0;
        }
    } else if(attaque.espece == "Mathematiques"){
        if(defense.espece == "Culture"){
            multiply = 2;
        } else if(defense.espece == "Aide"){
            multiply = 0;
        }
    }

    return multiply;
}
