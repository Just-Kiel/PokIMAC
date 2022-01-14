#include <iostream>

#include "menu.h"

#include "consoleUtils.hpp"
#include "variables.h"
#include "instructions.h"
using namespace std;

void printMenu(Joueur* joueur){
    int user_choice=0;

    //Menu
    cout<<"\n"
          "  _____      _    _____ __  __          _____ \n"
          " |  __ \\    | |  |_   _|  \\/  |   /\\   / ____|\n"
          " | |__) |__ | | __ | | | \\  / |  /  \\ | |     \n"
          " |  ___/ _ \\| |/ / | | | |\\/| | / /\\ \\| |     \n"
          " | |  | (_) |   < _| |_| |  | |/ ____ \\ |____ \n"
          " |_|   \\___/|_|\\_\\_____|_|  |_/_/    \\_\\_____|\n"
          "                                              \n"
          "                                              "<<endl;

        cout << "Choisis dans le menu (1, 2 ou 3) :" << endl;
        cout << "1. Jouer" << endl;
        cout << "2. Instructions" << endl;
        cout << "3. Quitter" << endl;


        cout << "Ton choix : ";
        cin >> user_choice;

        while(user_choice<1 || user_choice>3){
            cout<<"Ce choix n'est pas valide ! Tu dois choisir entre 1 et 3."<<endl;
            cout << "Ton choix : ";
            cin >> user_choice;
        }

        ConsoleUtils::clear();

        if (user_choice == 1) {
            //Facultatif++ TODO Afficher carte du jeu ou début
            int size = sizeMap();
            char * map=(char *) malloc(size*size*sizeof(char));

            //Personnalisation du dresseur
            //TODO à décommenter
            initPlayer(joueur);

            //Début du déplacement sur la carte
            remplissageTab(map, size);
            deplacementTab(map, size, joueur);

        } else if (user_choice == 2) {
            //Sarah / Facultatif TODO Amener vers fonction affichage des regles
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
    cout<<"Quel nom veux-tu donner a ton dresseur PokIMAC ?"<<endl;
    cin>>player->nom;
    cout<<"C'est bien "<<player->nom<<" ton nom ? (o/n)"<<endl;
    cin>>validation;

    while(validation=='n' || validation!='o'){
        cout<<"Quel nom veux-tu donner a ton dresseur PokIMAC ?"<<endl;
        cin>>player->nom;
        cout<<"C'est bien "<<player->nom<<" ton nom ? (o/n)"<<endl;
        cin>>validation;
    }
    cout<<"Bienvenue "<<player->nom<<" !"<<endl;

    detectSpace();

    //Choix du premier PokIMAC
    int user_pokIMAC=0;
    cout<<"Avec quel PokIMAC veux-tu partir a l'aventure ?"<<endl;
    int randomPokIMAC1 = rand()%nbPokIMAC;

    int randomPokIMAC2 = rand()%nbPokIMAC;
    while (randomPokIMAC2==randomPokIMAC1){
        randomPokIMAC2 = rand()%nbPokIMAC;
    }

    int randomPokIMAC3 = rand()%nbPokIMAC;
    while (randomPokIMAC3 == randomPokIMAC2 || randomPokIMAC3 == randomPokIMAC1){
        randomPokIMAC3 = rand()%nbPokIMAC;
    }
    cout << "1. " <<allPokimac[randomPokIMAC1].nom<< endl;
    cout << "2. " << allPokimac[randomPokIMAC2].nom << endl;
    cout << "3. " << allPokimac[randomPokIMAC3].nom << endl;

    cout<<"Ton choix : ";
    cin>>user_pokIMAC;

    while(user_pokIMAC<1 || user_pokIMAC>3){
        cout<<"Ce choix n'est pas valide ! Tu dois choisir entre 1 et 3."<<endl;
        cout << "Ton choix : ";
        cin >> user_pokIMAC;
    }

    player->equipe[0]=allPokimac[user_pokIMAC-1];
    cout<<player->nom<<", c'est parti pour l'aventure avec "<<allPokimac[user_pokIMAC-1].nom<<" !"<<endl;
    detectSpace();
}

int sizeMap(){
    char largeur[2];
    cout<<"Combien de largeur veux-tu que la grille fasse ?"<<endl;
    cin>>largeur;

    int largeurInt = atoi(largeur);
    while(largeurInt<1||largeurInt>9){
        cout<<"Ce choix n'est pas valide ! Tu dois choisir un nombre entier."<<endl;
        cout<<"Combien de largeur veux-tu que la grille fasse ?"<<endl;
        cin>>largeur;
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
        cout<<"Veux-tu vraiment retourner au menu principal ? (o/n)"<<endl;
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
                cout<<"Tu ne peux repondre que par o ou n !"<<endl;
                break;
        }

    }
}
//
// Created by Aurore on 07/12/2021.
//