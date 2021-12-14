/*
 * TODO Caractères à définir :
 *      - Joueur
 *      - Pokemons
 *      - Sol
 */

#include <iostream>
#include "carte.h"
using namespace std;

void changementTab(char tab[], int taille){
    char caractere, new_caractere;
    cout<<"Quel caractère souhaitez vous modifier ?"<<endl;
    cin>>caractere;
    cout<<"Par quel caractère voulez vous remplacer ?"<<endl;
    cin>>new_caractere;
    for(int i=0; i<taille;i++) {
        if (tab[i] == caractere) {
            tab[i] = new_caractere;
        }
    }
}

void affichageTab(char tab[], int taille){
    //Affichage du tableau
    cout<<"Te voici dans le bourg Coper, tu peux te deplacer avec zqsd."<<endl;
    for(int i=0; i<taille*taille; i++){
        if(i%taille==0 && i!=0){
            cout<<endl;
        }
        cout<<tab[i]<<"  ";
    }
    cout<<endl;
}

void remplissageTab(char tab[], int taille){
    //Remplissage du tableau
    for(int i=0; i<(taille*taille); i++){
        tab[i]=char(97);
    }
}
//
// Created by Aurore on 07/12/2021.
//