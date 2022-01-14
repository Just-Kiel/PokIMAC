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
        
        cout<<"Pour se diriger dans le jeu : "<<endl<<endl;
        cout<<" 'Fleche du haut' ou Z : pour aller vers le haut"<<endl;
        cout<<"'Fleche de droite' ou D : pour aller vers la droite"<<endl;
        cout<<"'Fleche du bas' ou S : pour aller vers le bas"<<endl;
        cout<<"'Fleche de gauche' ou Q : pour aller vers la gauche"<<endl<<endl;

        cout<<"Pour selectionner une option : "<<endl<<endl;
        cout<<"Saisir ton choix ou ce qui t'est demande a l'aide du clavier. Si tu dois valider ton choix, appuie sur la touche 'o'"<<endl;
        
        cout<<"Appuie sur la touche 'espace' pour revenir au menu principal. Attention, realise en cours de partie, cette action quittera la partie de façon definitive."<<endl;
        
        cout<<"Si tu ne comprends pas les commandes, adresse toi a Aurore Lafaurie (@_just_kiel_ sur instagram), elle saura te guider ! "<<endl<<endl;

        cout<<"Tu as fini de consulter les commandes ? "<<endl<<endl;
        cout << "1. OUI" << endl;
        cout << "2. NON" << endl<<endl;
        
        cout << "Ton choix : ";
        cin >> choix;

        while(choix<1 || choix>2){
            cout<<"Ce choix n'est pas valide ! Tu dois choisir entre 1 et 2."<<endl;
            cout << "Ton choix : ";
            cin >> user_choice;
        }
        
        detectSpace();
        
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
        
        detectSpace();

        if (choix_utilisateur == 1) {
            
            cout<<"HISTOIRE ET ENJEUX"<<endl<<endl;
           // detectSpace();

            
            cout<<"Tu incarnes un jeune DressESIPE de PokIMAC a qui l'on offre un PokIMAC de depart, \n et tu pars pour une aventure semee d'embuches. \n Tu parcours une region peuplee de PokIMAC sauvages que tu peux capturer et faire combattre. /n Tout ceci dans le but de te mesurer a l'elite des dresseurs du Champs et enfin devenir le Maitre du Bourg Coper avec le PokESIPE le plus rempli !"<<endl;
            
            detectSpace();
            
        } else if (choix_utilisateur == 2) {
            
            // Les PokIMAC :
            
            cout<<"LES POKIMACS"<<endl;
            
            cout<<"Les PokIMAC sont des creatures dotees de pouvoirs extraordinaires, comme la capacite de vous faire parler anglais ou de t'aider a obtenir ton diplome. \n Ils peuvent se faire capturer par les DressESIPE dans des PokIballs, des boules creuses rouges, oranges, bleues et vertes qui semblent aspirer la creature : \n on peut donc transporter ces poKIMACS dans des PokIballs de la taille d'une pomme. \n On recense actuellement 5 especes de PokIMAC. Consultez le PokESIPE pour acceder a la liste de tous les PokIMACS existants !"<<endl;
            
            detectSpace();

            
            // Les poKIMAC Starter :
            
            cout<<"Les PokIMAC de départ, tres souvent appeles par le terme anglais 'starters', sont les premiers Pokémon a rejoindre ton equipe."<<endl
                <<"Dans la plupart des cas, tu as le choix entre trois PokIMAC ayant l'un de ces types : Culture, Programmation, Mathematiques, Design et Aide."<<endl
                <<"Ce trio permet d'introduire rapidement au joueur la notion de sensibilite des types avec des concepts familiers : le Design s'inspire de la Culture mais craint la programmation, qui est lui meme battu par les Mathematiques. "<<endl;
            
            detectSpace();

            
            // Liste des PokIMAC
            
            cout<<" ###!!! DISCLAIMER !!!### "<<endl
                <<"Toute ressemblance de PokIMAC avec des professeurs de l'ESIPE - IMAC est parfaitement fortuite."<<endl
                <<"Ce jeu a été code dans l'innoncence, la stress et la prise de tête. Il n'a aucunement pour but de denigrer l'integrite de qui que ce soit. Il se veut fun et bienveillant ! "<<endl;

            
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

            detectSpace();

        } else if (choix_utilisateur == 3) {
            
            //objets
            
            cout<<"LES OBJETS"<<endl;
            
            cout<<" Les objets font partie de ton inventaire, ton sac a dos d'aventurier ! "<<endl<<"Ils te permettent d'ameliorer ta chasse aux PokIMAC. Lorsque tu utilises un objet, celui-ci disparait apres utilisation"<<endl;
            
            // visuel de Pokiball
            
            cout<<""<<endl;
            
            cout<<"Les Pokiball sont des objets de type 0, elles te permettent de capturer des PokIMACS sauvages. Attention, 1 pokiball ne peut contenir qu'un seul PokIMAC ! Tu commences la partie avec une Pokiball, a toi d'en gagner d'autres en te baladant dans le Bourg Coper."<<endl;
            
            cout<<"Les objets de type 1 te permettent de regenerer les PV de tes PokIMACS si ces derniers sont blesses. Attention, tu ne peux régénérer les PV de ton PokIMAC qu'une seule fois dans le combat ! "<<endl<< "Voici les differents objets de type 1: "<<endl;
            
            cout<<""<<endl // visuel biere
                <<"La Biere te permet de regenerer 5 PV au PokIMAC de ton choix. "<<endl;
            
            cout<<""<<endl // visuel Mojito
                <<"Le Mojito te permet de regenerer 10 PV au PokIMAC de ton choix. "<<endl;
            
            cout<<""<<endl // visuel Chocolat Chaud
                <<"Le Chocolat Chaud te permet de regenerer 15 PV au PokIMAC de ton choix. "<<endl;
            
            cout<<""<<endl // visuel Repas CROUS
                <<"Le Repas CROUS te permet de regenerer 20 PV au PokIMAC de ton choix. "<<endl;
            
            cout<<""<<endl // visuel Cassoulet
                <<"Le Cassoulet te permet de regenerer 25 PV au PokIMAC de ton choix. "<<endl;
            
            detectSpace();

        } else if (choix_utilisateur == 4) {

            //combat, capture, fuite
            
            cout<<"Pour capturer ou combattre des PokIMACS, rend toi dans les hautes herbes ! (#) "<<endl<<endl;

            
            cout<<"> Combat :"<<endl
                <<"Selectionne ton attaque et tente de blesser le PokIMAC adverse ! Attention, ce dernier va repliquer ! "<<endl
                <<"Le combat se deroule jusqu'a ce que tu viennes a bout de ton adversaire ou que tu decides de fuire ou de capturer ton ennemi. "<<endl
                <<endl
                <<"Ces combats permettent d'entrainer tes PokIMAC pour les rendre plus forts !"<<endl
                <<endl
                <<"QUE LE MEILLEUR GAGNE ! "<<endl<<endl<<endl;
            
            detectSpace();
            
            cout<<"> Capture :"<<endl
                <<"Lorsque tu rencontres un PokIMAC, si ce dernier possede moins de PV que ton PokIMAC, tu peux le capturer sans avoir a mener combat sanguinaire !"<<endl
                <<"Si le PokIMAC rencontre est plus fort que toi, tu peux decider de le combattre pour l'affaiblir et ainsi pouvoir le capturer ! "<<endl
                <<"Attention ! Pour pouvoir capturer un PokIMAC, tu dois posseder des Pokiball !"<<endl<<endl
                <<"POUR RAPPEL : 1 POKIBALL = 1 POKIMAC !"<<endl;
            
            detectSpace();
            
            cout<<"> Fuite :"<<endl<<endl
                <<"Si tu ne veux ni combattre ni capturer de PokIMAC, tu peux decider de fuire pour continuer ta promenade."<<endl
                <<"Tu peux egalement fuire lors d'un combat si ce dernier s'annonce laborieux ou que tu es trop affaiblit pour continuer."<<endl
                << "Malheureusement, a ce rythme la, tu ne risque pas de devenir le plus grand dresseur du Champs..."<<endl;
        
            detectSpace();

        }else{
            
            //Fin du programme > retour au menu instruction

            return;
            
        }
    
}
