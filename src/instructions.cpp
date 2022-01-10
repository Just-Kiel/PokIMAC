//
//  instructions.cpp
//  
//
//  Created by Sarah N'GOTTA on 07/01/2022.
//

#include <stdio.h>
#include <cstring>
#include <iostream>
#include "consoleUtils.hpp"
#include "menu.h"

using namespace std;

//TODO ajouter detectSpace pour aérer texte
//TODO enlever accents et caractères spéciaux (casse)

void printRegles();

void printSelection( ){
    
    // TODO Récupérer ASCII ART "INSTRUCTIONS"
    cout<<""<<endl;
    
    cout << "Choisis dans le menu (1, 2 ou 3) :" << endl;
    cout << "1. Commandes" << endl;
    cout << "2. Regles du jeu" << endl;
    cout << "3. Retour" << endl;

    int user_choice;
    cout << "Ton choix : ";
    cin >> user_choice;

    while(user_choice<1 || user_choice>3){
        cout<<"Ce choix n'est pas valide ! Tu dois choisir entre 1 et 3."<<endl;
        cout << "Ton choix : ";
        cin >> user_choice;
    }
    
    ConsoleUtils::clear();

    if (user_choice == 1) {
        
        int choix=0;
        
        // Présentation des commandes + possibilité de faire retour
        // TODO Récupérer ASCII ART "COMMANDES"
        
        cout<<""<<endl;
        
        cout<<"Pour se diriger dans le jeu : "<<endl;
        cout<<"↑ ou Z : pour aller vers le haut"<<endl;
        cout<<"→ ou D : pour aller vers la droite"<<endl;
        cout<<"↓ ou S : pour aller vers le bas"<<endl;
        cout<<"← ou Q : pour aller vers la gauche"<<endl;

        cout<<"Pour selectionner une option : "<<endl;
        cout<<"Saisir ton choix ou ce qui t'est demande a l'aide du clavier. Si tu dois valider ton choix, appuis sur la touche 'o'"<<endl;
        
        cout<<"Appuie sur la touche 'espace' pour revenir au menu principal. Attention, réalise en cours de partie, cette action quittera la partie de façon définitive."<<endl;
        
        cout<<"Si tu ne comprends pas les commandes, adresse toi a Aurore Lafaurie (@just_kiel sur instagram), elle saura te guider ! "<<endl;

        cout<<"Tu as fini de consulter les commandes ? "<<endl;
        cout << "1. OUI" << endl;
        cout << "2. NON" << endl;
        
        cout << "Ton choix : ";
        cin >> choix;

        while(choix<1 || choix>2){
            cout<<"Ce choix n'est pas valide ! Tu dois choisir entre 1 et 2."<<endl;
            cout << "Ton choix : ";
            cin >> user_choice;
        }
        
        printSelection();

    } else if (user_choice == 2) {
        
       //Fonction printRegle qui affiche le menu des règles du jeu
        
        printRegles();
        
        
    } else {
        
        //Fin du programme > retour au menu principal
        return;
        
    }
}


void printRegles(){
        
        // Explications des règles du jeu + possibilité de faire retour
        // TODO Récupérer ASCII ART "RÈGLES DU JEU "
        
        int choix_utilisateur=0;
        
        cout << "Choisis dans le menu (1, 2, 3, 4 ou 5) :" << endl;
        cout << "1. Histoire et Enjeux" << endl;
        cout << "2. Les PokImacs" << endl;
        cout << "3. Les Objets" << endl;
        cout << "4. Combat, capture et fuite" << endl;
        cout << "5. Retour" << endl;
        
        cout << "Ton choix : ";
        cin >> choix_utilisateur;

        while(choix_utilisateur<1 || choix_utilisateur>5){
            cout<<"Ce choix n'est pas valide ! Tu dois choisir entre 1 et 5."<<endl;
            cout << "Ton choix : ";
            cin >> choix_utilisateur;
        }
        
        ConsoleUtils::clear();
        
        if (choix_utilisateur == 1) {
            
            cout<<"HISTOIRE ET ENJEUX"<<endl;
            
            cout<<"Tu incarnes un jeune DressESIPE de PokIMAC a qui l'on offre un PokIMAC de depart, \n et tu pars pour une aventure semee d'embuches. \n Tu parcours une région peuplee de PokIMAC sauvages que tu peux capturer et faire combattre. /n Tout ceci dans le but de te mesurer a l'élite des dresseurs du Champs et enfin devenir le Maitre du Bourg Coper avec le PokESIPE le plus rempli !"<<endl;
            detectSpace();
            
            printRegles();
        } else if (choix_utilisateur == 2) {
            
            // Les PokIMAC :
            
            cout<<"Les PokIMAC sont des créatures dotées de pouvoirs extraordinaires, comme la capacité de vous faire parler anglais ou de t'aider à obtenir ton diplome. \n Ils peuvent se faire capturer par les DressESIPE dans des PokIballs, des boules creuses rouges, oranges, bleues et vertes qui semblent aspirer la créature : \n on peut donc transporter ces poKIMACS dans des PokIballs de la taille d'une pomme. \n On recense actuellement 5 espèces de PokIMAC. Consultez le PokESIPE pour accéder à la liste de tous les PokIMACS existants !"<<endl;
            
            // Les poKIMAC Starter :
            
            cout<<"Les PokIMAC de départ, très souvent appelés par le terme anglais 'starters', sont les premiers Pokémon à rejoindre ton équipe."<<endl
                <<"Dans la plupart des cas, tu as le choix entre trois PokIMAC ayant l'un de ces types : Culture, Programmation, Mathématiques, Design et Aide."<<endl
                <<"Ce trio permet d'introduire rapidement au joueur à la notion de sensibilité des types avec des concepts familiers : le Design s'inspire de la Culture mais craint la programmation, qui est lui même battu par les Mathématiques. "<<endl;
            
            // Liste des PokIMAC
            
            cout<<" ###!!! DISCLAIMER !!!### "<<endl
                <<"Toute ressemblance de PokIMAC avec des professeurs de l'ESIPE - IMAC est parfaitement fortuite."<<endl
                <<"Ce jeu a été codé dans l'innoncence, la stress et la prise de tête. Il n'a aucunement pour but de dénigrer l'integrite de qui que ce soit. Il se veut fun et bienveillant ! "<<endl;

            
            cout<<"PokESIPE : "<<endl;
            
            cout<<"Type Culture : "<<endl
                <<" - Robbizarre" << endl
                <<" - Ozlameche "<< endl
                <<" - Guerrarlande"<<endl;
            
            cout<<"Type Programmation : "<<endl
                <<" - Nosteevrapti" <<endl
                <<" - Laporteille" <<endl
                <<" - Charpenti" <<endl;
            
            cout<<"Type Mathematiques : "<<endl
                <<" - Nocvelli"<<endl
                <<" - Rieulu"<<endl;
            
            cout<<"Type Aide : "<<endl
                <<"Soniafee"<<endl
                <<"Enguerratueur"<<endl;
            
            cout<<"Type Design : "<<endl
                <<"Gautiplouf"<<endl
                <<"Chataiglam"<<endl;

            printRegles();
            
        } else if (choix_utilisateur == 3) {
            
            //objets
            
            printRegles();
            
        } else if (choix_utilisateur == 4) {

            //combat, capture, fuite
        
        
            printRegles();
            
        }else{
            
            //Fin du programme > retour au menu instruction
            printSelection();
//            return;
            
        }
    
}
