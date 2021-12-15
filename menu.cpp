#include <iostream>
#include "menu.h"
#include "carte.h"

using namespace std;

void printMenu(Joueur* joueur){
    int user_choice=0;
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

        consoleUtils::clear();
        if (user_choice == 1) {
            //TODO Afficher carte du jeu ou début
            int size = sizeMap();

            char * map=(char *) malloc(size*size*sizeof(char));

            initPlayer(joueur);
            remplissageTab(map, size);
            deplacementTab(map, size, joueur);
        } else if (user_choice == 2) {
            //TODO Amener vers fonction affichage des regles
        } else {
            //Fin du programme
        }
}

void initPlayer(Joueur *player){
    //TODO est ce qu'on lui fait choisir un pokimac starter ou pas ?
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
    consoleUtils::clear();
}

int sizeMap(){
    int largeur;
    cout<<"Combien de largeur veux-tu que la grille fasse ?"<<endl;
    cin>>largeur;
    return largeur;
}
//
// Created by Aurore on 07/12/2021.
//