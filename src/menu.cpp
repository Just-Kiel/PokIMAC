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


        cout << "Votre choix : ";
        cin >> user_choice;

        while(user_choice<1 || user_choice>3){
            cout<<"Ce choix n'est pas valide ! Tu dois choisir entre 1 et 3."<<endl;
            cout << "Votre choix : ";
            cin >> user_choice;
        }

        ConsoleUtils::clear();

        if (user_choice == 1) {
            //Facultatif TODO Afficher carte du jeu ou début
            int size = sizeMap();

            char * map=(char *) malloc(size*size*sizeof(char));

            //Personnalisation du dresseur
            //TODO à décommenter
            //initPlayer(joueur);

            //Début du déplacement sur la carte
            remplissageTab(map, size);
            deplacementTab(map, size, joueur);

        } else if (user_choice == 2) {
            //Facultatif TODO Amener vers fonction affichage des regles
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
    cout<<"Quel nom voulez-vous donner a votre dresseur PokIMAC ?"<<endl;
    cin>>player->nom;
    cout<<"C'est bien "<<player->nom<<" votre nom ? (o/n)"<<endl;
    cin>>validation;

    while(validation=='n' || validation!='o'){
        cout<<"Quel nom voulez-vous donner a votre dresseur PokIMAC ?"<<endl;
        cin>>player->nom;
        cout<<"C'est bien "<<player->nom<<" votre nom ? (o/n)"<<endl;
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

    cout<<"Votre choix : ";
    cin>>user_pokIMAC;

    while(user_pokIMAC<1 || user_pokIMAC>3){
        cout<<"Ce choix n'est pas valide ! Tu dois choisir entre 1 et 3."<<endl;
        cout << "Votre choix : ";
        cin >> user_pokIMAC;
    }

    player->equipe[0]=allPokimac[user_pokIMAC-1];
    cout<<player->nom<<", c'est parti pour l'aventure avec "<<allPokimac[user_pokIMAC-1].nom<<" !"<<endl;
    detectSpace();
}

int sizeMap(){
    //Facultatif TODO detecter si c'est un nb ou pas pour faire boucler (j'ai essayé un truc qui ne fonctionne pas)
    //char largeur[1];
    int largeur;
    cout<<"Combien de largeur veux-tu que la grille fasse ?"<<endl;
    cin>>largeur;

    /*while(largeur[0]<'1'||largeur[0]>'9'){
        cout<<"Ce choix n'est pas valide ! Tu dois choisir un nombre entier."<<endl;
        cout<<"Combien de largeur veux-tu que la grille fasse ?"<<endl;
        cin>>largeur;
    }*/

    ConsoleUtils::clear();
    //return atoi(largeur);
    return largeur;
}

void detectSpace(){
    cout<<endl<<"Appuie sur ESPACE pour passer a l'ecran suivant."<<endl;
    char input = ConsoleUtils::getChar();
    while(input == ' '){
        ConsoleUtils::clear();
        break;
    }
}
//
// Created by Aurore on 07/12/2021.
//