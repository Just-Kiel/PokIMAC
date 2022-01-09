#include <iostream>

#include "menu.h"

#include "consoleUtils.hpp"
#include "variables.h"
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
            //Facultatif TODO Afficher carte du jeu ou début
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
            printMenu(joueur);
        } else {
            //Fin du programme
            cout<<"Merci d'avoir joue a PokIMAC !"<<endl;
            detectSpace();
            //Facultatif TODO Fin de jeu
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
    cout << "1. " <<allPokimac[0].nom<< endl;
    cout << "2. " << allPokimac[1].nom << endl;
    cout << "3. " << allPokimac[2].nom << endl;

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
//
// Created by Aurore on 07/12/2021.
//