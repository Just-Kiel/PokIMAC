#include <iostream>

#include "menu.h"

#include "consoleUtils.hpp"
#include "variables.h"
#include "instructions.h"
using namespace std;

void printMenu(Joueur* joueur){
    int user_choice=0;

    //Menu
    ConsoleUtils::setColor(ConsoleUtils::Color::LIGHTBLUE);
    cout<<"\n"
          "  _____      _    _____ __  __          _____ \n"
          " |  __ \\    | |  |_   _|  \\/  |   /\\   / ____|\n"
          " | |__) |__ | | __ | | | \\  / |  /  \\ | |     \n"
          " |  ___/ _ \\| |/ / | | | |\\/| | / /\\ \\| |     \n"
          " | |  | (_) |   < _| |_| |  | |/ ____ \\ |____ \n"
          " |_|   \\___/|_|\\_\\_____|_|  |_/_/    \\_\\_____|\n"
          "                                              \n"
          "                                              "<<endl;

    ConsoleUtils::setColor(ConsoleUtils::Color::BLUE);
    ConsoleUtils::setBackgroundColor(ConsoleUtils::BackgroundColor::BG_YELLOW);
    std::cout << "Choisis dans le menu (1, 2 ou 3) :";
    ConsoleUtils::resetColors(); std::cout << std::endl<<endl;
    
        cout << "1. Jouer" << endl;
        cout << "2. Instructions" << endl;
        cout << "3. Quitter" << endl;


        cout << "Ton choix : ";
        cin >> user_choice;

        while(user_choice<1 || user_choice>3){
            
            ConsoleUtils::setColor(ConsoleUtils::Color::LIGHTRED);
            std::cout<<"Ce choix n'est pas valide ! Tu dois choisir entre 1 et 3."<<endl;
            ConsoleUtils::resetColors(); std::cout << std::endl<<endl;

            cout << "Ton choix : ";
            cin >> user_choice;
        }

        ConsoleUtils::clear();

        if (user_choice == 1) {
            //Facultatif++ TODO Afficher carte du jeu ou début
            int size = sizeMap();
            char * map=(char *) malloc(size*size*sizeof(char));

            //Personnalisation du dresseur
            initPlayer(joueur);

            //Début du déplacement sur la carte
            remplissageTab(map, size);
            deplacementTab(map, size, joueur);

        } else if (user_choice == 2) {
            //Sarah fonction affichage des regles
            printSelection();
            printMenu(joueur);
        } else {
            //Fin du programme
            cout<<"Merci d'avoir joue a PokIMAC !"<<endl;
            detectSpace();
            //Facultatif++ TODO Fin de jeu
        }
}

void initPlayer(Joueur *player){
    //Nom du dresseur PokIMAC

    char validation='o';
    
    ConsoleUtils::setColor(ConsoleUtils::Color::BLUE);
    ConsoleUtils::setBackgroundColor(ConsoleUtils::BackgroundColor::BG_YELLOW);
    std::cout << "Quel nom veux-tu donner a ton dresseur PokIMAC ?";
    ConsoleUtils::resetColors(); std::cout << std::endl<<endl;
    
    ConsoleUtils::setColor(ConsoleUtils::Color::LIGHTMAGENTA);
        cin>>player->nom;
    ConsoleUtils::resetColors(); std::cout << std::endl;

    ConsoleUtils::setColor(ConsoleUtils::Color::BLUE);
    ConsoleUtils::setBackgroundColor(ConsoleUtils::BackgroundColor::BG_YELLOW);
    std::cout <<"C'est bien "<<player->nom<<" ton nom ? (o/n)";
    ConsoleUtils::resetColors(); std::cout << std::endl<<endl;
    cin>>validation;

    while(validation=='n' || validation!='o'){
        ConsoleUtils::setColor(ConsoleUtils::Color::BLUE);
        ConsoleUtils::setBackgroundColor(ConsoleUtils::BackgroundColor::BG_YELLOW);
        std::cout << "Quel nom veux-tu donner a ton dresseur PokIMAC ?";
        ConsoleUtils::resetColors(); std::cout << std::endl<<endl;
        
        ConsoleUtils::setColor(ConsoleUtils::Color::LIGHTMAGENTA);
            cin>>player->nom;
        ConsoleUtils::resetColors(); std::cout << std::endl;
        
        ConsoleUtils::setColor(ConsoleUtils::Color::BLUE);
        ConsoleUtils::setBackgroundColor(ConsoleUtils::BackgroundColor::BG_YELLOW);
        std::cout <<"C'est bien "<<player->nom<<" ton nom ? (o/n)";
        ConsoleUtils::resetColors(); std::cout << std::endl<<endl;
        
        cin>>validation;
    }
    cout<<"Bienvenue "<<player->nom<<" !"<<endl;

    detectSpace();

    //Choix du premier PokIMAC
    int user_pokIMAC=0;
    
    ConsoleUtils::setColor(ConsoleUtils::Color::BLUE);
    ConsoleUtils::setBackgroundColor(ConsoleUtils::BackgroundColor::BG_YELLOW);
    std::cout <<"Avec quel PokIMAC veux-tu partir a l'aventure ?";
    ConsoleUtils::resetColors(); std::cout << std::endl<<endl;
    
    int randomPokIMAC1 = rand()%nbPokIMAC;

    int randomPokIMAC2 = rand()%nbPokIMAC;
    while (randomPokIMAC2==randomPokIMAC1){
        randomPokIMAC2 = rand()%nbPokIMAC;
    }

    int randomPokIMAC3 = rand()%nbPokIMAC;
    while (randomPokIMAC3 == randomPokIMAC2 || randomPokIMAC3 == randomPokIMAC1){
        randomPokIMAC3 = rand()%nbPokIMAC;
    }
    
    ConsoleUtils::setColor(ConsoleUtils::Color::BLUE);
    std::cout << "1."<<allPokimac[randomPokIMAC1].nom<< endl;
    ConsoleUtils::resetColors(); std::cout << std::endl<<endl;
    
    ConsoleUtils::setColor(ConsoleUtils::Color::MAGENTA);
    std::cout << "2."<<allPokimac[randomPokIMAC2].nom << endl;
    ConsoleUtils::resetColors(); std::cout << std::endl<<endl;
    
    ConsoleUtils::setColor(ConsoleUtils::Color::CYAN);
    std::cout << "3."<<allPokimac[randomPokIMAC3].nom << endl;
    ConsoleUtils::resetColors(); std::cout << std::endl<<endl;
    
    /*cout << "1. " <<allPokimac[randomPokIMAC1].nom<< endl;
    cout << "2. " << allPokimac[randomPokIMAC2].nom << endl;
    cout << "3. " << allPokimac[randomPokIMAC3].nom << endl;*/
    
    cout<<"Ton choix : ";
    cin>>user_pokIMAC;

    while(user_pokIMAC<1 || user_pokIMAC>3){
        ConsoleUtils::setColor(ConsoleUtils::Color::LIGHTRED);
        std::cout<<"Ce choix n'est pas valide ! Tu dois choisir entre 1 et 3."<<endl;
        ConsoleUtils::resetColors(); std::cout << std::endl<<endl;
        cout << "Ton choix : ";
        cin >> user_pokIMAC;
    }

    if(user_pokIMAC == 1){
        player->equipe[0]=allPokimac[randomPokIMAC1];
    } else if(user_pokIMAC == 2){
        player->equipe[0]=allPokimac[randomPokIMAC2];
    } else {
        player->equipe[0]=allPokimac[randomPokIMAC3];
    }

    cout<<player->nom<<", c'est parti pour l'aventure avec "<<player->equipe[0].nom<<" !"<<endl;
    detectSpace();
}

int sizeMap(){
    char largeur[2];
    
    ConsoleUtils::setColor(ConsoleUtils::Color::BLUE);
    ConsoleUtils::setBackgroundColor(ConsoleUtils::BackgroundColor::BG_YELLOW);
    std::cout<<"Combien de largeur veux-tu que la grille fasse ?"<<endl;
    ConsoleUtils::resetColors(); std::cout << std::endl;
   
    ConsoleUtils::setColor(ConsoleUtils::Color::LIGHTMAGENTA);
    cin>>largeur;
    ConsoleUtils::resetColors(); std::cout << std::endl;

    int largeurInt = atoi(largeur);
    while(largeurInt<1||largeurInt>9){
        
        ConsoleUtils::setColor(ConsoleUtils::Color::LIGHTRED);
        std::cout<<"Ce choix n'est pas valide ! Tu dois choisir un nombre entier."<<endl;
        ConsoleUtils::resetColors(); std::cout << std::endl<<endl;
        
        ConsoleUtils::setColor(ConsoleUtils::Color::BLUE);
        ConsoleUtils::setBackgroundColor(ConsoleUtils::BackgroundColor::BG_YELLOW);
        std::cout<<"Combien de largeur veux-tu que la grille fasse ?"<<endl;
        ConsoleUtils::resetColors(); std::cout << std::endl;
        
        ConsoleUtils::setColor(ConsoleUtils::Color::LIGHTMAGENTA);
        cin>>largeur;
        ConsoleUtils::resetColors(); std::cout << std::endl;
        
        largeurInt = atoi(largeur);
    }

    ConsoleUtils::clear();
    return largeurInt;
}

void detectSpace(){
    cout<<endl<<"Appuie sur une touche pour passer a l'ecran suivant."<<endl;
    ConsoleUtils::getChar();
    ConsoleUtils::clear();
}

void confirmChoice(Joueur * player, int taille, char tab[]){
    bool answer = false;

    while (!answer){
        
        ConsoleUtils::setColor(ConsoleUtils::Color::LIGHTYELLOW);
        std::cout<<"Veux-tu vraiment retourner au menu principal ? (o/n)"<<endl;
        ConsoleUtils::resetColors(); std::cout << std::endl<<endl;
        
        cout<<"Ton choix :";
        char input = ConsoleUtils::getChar();
        switch (input) {
            case 'o':
            case 'O':
                answer=true;
                printMenu(player);
                break;
            case 'n':
            case 'N':
                answer= true;
                ConsoleUtils::clear();
                affichageTab(tab, taille);
                deplacementTab(tab, taille, player);
                break;
            default:
                ConsoleUtils::clear();
                ConsoleUtils::setColor(ConsoleUtils::Color::LIGHTRED);
                std::cout<<"Tu ne peux repondre que par o ou n !"<<endl;
                ConsoleUtils::resetColors(); std::cout << std::endl<<endl;
                
                break;
        }

    }
}
//
// Created by Aurore on 07/12/2021.
//
