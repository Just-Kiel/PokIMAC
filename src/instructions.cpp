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
#include "variables.h"

using namespace std;

void printRegles();

void printSelection( ){
    cout<<"  _____           _                   _   _                 \n"
          " |_   _|         | |                 | | (_)                \n"
          "   | |  _ __  ___| |_ _ __ _   _  ___| |_ _  ___  _ __  ___ \n"
          "   | | | '_ \\/ __| __| '__| | | |/ __| __| |/ _ \\| '_ \\/ __|\n"
          "  _| |_| | | \\__ \\ |_| |  | |_| | (__| |_| | (_) | | | \\__ \\\n"
          " |_____|_| |_|___/\\__|_|   \\__,_|\\___|\\__|_|\\___/|_| |_|___/\n"
          "                                                            "<<endl;

    ConsoleUtils::setColor(ConsoleUtils::Color::BLUE);
    ConsoleUtils::setBackgroundColor(ConsoleUtils::BackgroundColor::BG_YELLOW);
    cout << "Choisis dans le menu (1, 2 ou 3) :";
    ConsoleUtils::resetColors(); std::cout << std::endl<<endl;
        
    cout << "1. Commandes" << endl;
    cout << "2. Regles du jeu" << endl;
    cout << "3. Retour" << endl;

    char user_choice;
    cout << "Ton choix : ";
    
    ConsoleUtils::setColor(ConsoleUtils::Color::LIGHTMAGENTA);
    cin >> user_choice;
    ConsoleUtils::resetColors();
    
    while(user_choice<'1' || user_choice>'3'){
        ConsoleUtils::setColor(ConsoleUtils::Color::LIGHTRED);
        cout<<"Ce choix n'est pas valide ! Tu dois choisir entre 1 et 3."<<endl
            <<endl;
        ConsoleUtils::resetColors();

        cout << "Ton choix : ";
        ConsoleUtils::setColor(ConsoleUtils::Color::LIGHTMAGENTA);
        cin >> user_choice;
        ConsoleUtils::resetColors();

    }
    cin.ignore(numeric_limits<streamsize>::max(),'\n');

    ConsoleUtils::clear();

    if (user_choice == '1') {
        // Présentation des commandes + possibilité de faire retour
        cout<<"   _____                                          _           \n"
              "  / ____|                                        | |          \n"
              " | |     ___  _ __ ___  _ __ ___   __ _ _ __   __| | ___  ___ \n"
              " | |    / _ \\| '_ ` _ \\| '_ ` _ \\ / _` | '_ \\ / _` |/ _ \\/ __|\n"
              " | |___| (_) | | | | | | | | | | | (_| | | | | (_| |  __/\\__ \\\n"
              "  \\_____\\___/|_| |_| |_|_| |_| |_|\\__,_|_| |_|\\__,_|\\___||___/\n"
              "                                                              "<<endl << endl;

        ConsoleUtils::setColor(ConsoleUtils::Color::BLUE);
        ConsoleUtils::setBackgroundColor(ConsoleUtils::BackgroundColor::BG_YELLOW);
        cout << "Pour se diriger dans le jeu : ";
        ConsoleUtils::resetColors(); std::cout <<std::endl<<endl<<endl;
        
        ConsoleUtils::setColor(ConsoleUtils::Color::BLACK);
        ConsoleUtils::setBackgroundColor(ConsoleUtils::BackgroundColor::BG_CYAN);
        cout << "> 'Fleche du haut' ou Z : ";
        ConsoleUtils::resetColors(); std::cout << "  pour aller vers le haut"<<std::endl<<endl;

        ConsoleUtils::setColor(ConsoleUtils::Color::BLACK);
        ConsoleUtils::setBackgroundColor(ConsoleUtils::BackgroundColor::BG_CYAN);
        cout << "> 'Fleche de droite' ou D : ";
        ConsoleUtils::resetColors(); std::cout << "  pour aller vers la droite"<<std::endl<<endl;

        ConsoleUtils::setColor(ConsoleUtils::Color::BLACK);
        ConsoleUtils::setBackgroundColor(ConsoleUtils::BackgroundColor::BG_CYAN);
        cout << "> 'Fleche du bas' ou S : ";
        ConsoleUtils::resetColors(); std::cout << "  pour aller vers le bas"<<std::endl<<endl;

        ConsoleUtils::setColor(ConsoleUtils::Color::BLACK);
        ConsoleUtils::setBackgroundColor(ConsoleUtils::BackgroundColor::BG_CYAN);
        cout << "> 'Fleche de gauche' ou Q : ";
        ConsoleUtils::resetColors(); std::cout << "  pour aller vers la gauche "<<std::endl<<endl<<endl;
        
        detectSpace();

        ConsoleUtils::setColor(ConsoleUtils::Color::BLUE);
        ConsoleUtils::setBackgroundColor(ConsoleUtils::BackgroundColor::BG_YELLOW);
        cout << "Pour selectionner une option : ";
        ConsoleUtils::resetColors(); std::cout <<std::endl<<endl;
        
        ConsoleUtils::setColor(ConsoleUtils::Color::CYAN);
        cout << "> ";
        ConsoleUtils::resetColors(); std::cout<<"Saisir ton choix ou ce qui t'est demande a l'aide du clavier. Si tu dois valider ton choix, appuie sur la touche 'o'" <<std::endl<<endl;

        ConsoleUtils::setColor(ConsoleUtils::Color::CYAN);
        cout << "> ";
        ConsoleUtils::resetColors(); std::cout<<"Appuie sur la touche 'espace' pour revenir au menu principal. Attention, realise en cours de partie, cette action quittera la partie de façon definitive." <<std::endl<<endl;
        

        ConsoleUtils::setColor(ConsoleUtils::Color::BLACK);
        ConsoleUtils::setBackgroundColor(ConsoleUtils::BackgroundColor::BG_CYAN);
        cout << "> Si tu ne comprends pas les commandes, adresse toi a Aurore Lafaurie (@_just_kiel_ sur instagram), elle saura te guider ! ";
        ConsoleUtils::resetColors(); std::cout <<std::endl<<endl;

        detectSpace();
        printSelection();
        
    } else if (user_choice == '2') {
        
       //Fonction printRegle qui affiche le menu des règles du jeu
        
        printRegles();
        
        
    } else {
        
        //Fin du programme > retour au menu principal
        return;
        
    }
}


void printRegles(){
        
    // Explications des règles du jeu + possibilité de faire retour

    cout << "  _____            _                 _           _            \n"
            " |  __ \\          | |               | |         (_)           \n"
            " | |__) |___  __ _| | ___  ___    __| |_   _     _  ___ _   _ \n"
            " |  _  // _ \\/ _` | |/ _ \\/ __|  / _` | | | |   | |/ _ \\ | | |\n"
            " | | \\ \\  __/ (_| | |  __/\\__ \\ | (_| | |_| |   | |  __/ |_| |\n"
            " |_|  \\_\\___|\\__, |_|\\___||___/  \\__,_|\\__,_|   | |\\___|\\__,_|\n"
            "              __/ |                            _/ |           \n"
            "             |___/                            |__/"<<endl << endl;

    char choix_utilisateur;
        
    ConsoleUtils::setColor(ConsoleUtils::Color::BLUE);
    ConsoleUtils::setBackgroundColor(ConsoleUtils::BackgroundColor::BG_YELLOW);
    cout << "Choisis dans le menu :";
    ConsoleUtils::resetColors(); std::cout << std::endl<<endl;

    ConsoleUtils::setColor(ConsoleUtils::Color::BLUE);
    ConsoleUtils::setBackgroundColor(ConsoleUtils::BackgroundColor::BG_YELLOW);
    cout << "1.";
    ConsoleUtils::resetColors(); std::cout << " Histoire et Enjeux" <<std::endl<<endl;

    ConsoleUtils::setColor(ConsoleUtils::Color::BLUE);
    ConsoleUtils::setBackgroundColor(ConsoleUtils::BackgroundColor::BG_YELLOW);
    cout << "2.";
    ConsoleUtils::resetColors(); std::cout << " Les PokImacs" <<std::endl<<endl;

    ConsoleUtils::setColor(ConsoleUtils::Color::BLUE);
    ConsoleUtils::setBackgroundColor(ConsoleUtils::BackgroundColor::BG_YELLOW);
    cout << "3.";
    ConsoleUtils::resetColors(); std::cout << " Les Objets" <<std::endl<<endl;

    ConsoleUtils::setColor(ConsoleUtils::Color::BLUE);
    ConsoleUtils::setBackgroundColor(ConsoleUtils::BackgroundColor::BG_YELLOW);
    cout << "4.";
    ConsoleUtils::resetColors(); std::cout << " Combat, capture et fuite" <<std::endl<<endl;

    ConsoleUtils::setColor(ConsoleUtils::Color::BLUE);
    ConsoleUtils::setBackgroundColor(ConsoleUtils::BackgroundColor::BG_YELLOW);
    cout << "5.";
    ConsoleUtils::resetColors(); std::cout << " Retour" <<std::endl<<endl;

    cout << "Ton choix : ";
    ConsoleUtils::setColor(ConsoleUtils::Color::LIGHTMAGENTA);
    cin >> choix_utilisateur;
    ConsoleUtils::resetColors();

    while(choix_utilisateur<'1' || choix_utilisateur>'5'){
        ConsoleUtils::setColor(ConsoleUtils::Color::LIGHTRED);
        cout<<"Ce choix n'est pas valide ! Tu dois choisir entre 1 et 5."<<endl;
        ConsoleUtils::resetColors();
        cout << "Ton choix : ";
        ConsoleUtils::setColor(ConsoleUtils::Color::LIGHTMAGENTA);
        cin >> choix_utilisateur;
        ConsoleUtils::resetColors();

    }

    cin.ignore(numeric_limits<streamsize>::max(),'\n');

        ConsoleUtils::clear();

        if (choix_utilisateur == '1') {

            ConsoleUtils::setColor(ConsoleUtils::Color::BLUE);
            ConsoleUtils::setBackgroundColor(ConsoleUtils::BackgroundColor::BG_YELLOW);
            cout << "HISTOIRE ET ENJEUX";
            ConsoleUtils::resetColors(); std::cout<<std::endl<<endl;


            cout<<"Tu incarnes un jeune DressESIPE de PokIMAC a qui l'on offre un PokIMAC de depart, et tu pars pour une aventure semee d'embuches."<<endl
            <<"Tu parcours une region peuplee de PokIMAC sauvages que tu peux capturer et faire combattre."<<endl
            <<endl
            <<"Tout ceci dans le but de te mesurer a l'elite des dresseurs du Champs et enfin devenir le Maitre du Bourg Coper avec le PokESIPE le plus rempli !"<<endl;
            
            detectSpace();
            printRegles();
            
        } else if (choix_utilisateur == '2') {
            
            // Les PokIMAC :
            ConsoleUtils::setColor(ConsoleUtils::Color::BLUE);
            ConsoleUtils::setBackgroundColor(ConsoleUtils::BackgroundColor::BG_YELLOW);
            cout << "LES POKIMACS";
            ConsoleUtils::resetColors(); std::cout<<std::endl<<endl<<endl;
            
            
            cout<<"Les PokIMACS sont des creatures dotees de pouvoirs extraordinaires, comme la capacite de vous faire parler anglais ou de t'aider a obtenir ton diplome."<<endl
            <<"Ils peuvent se faire capturer par les DressESIPE dans des Pokiballs, des boules creuses rouges, oranges, bleues et vertes qui semblent aspirer la creature :on peut donc transporter ces poKIMACS dans des Pokiballs de la taille d'une pomme. On recense actuellement 5 especes de PokIMAC."<<endl<<endl;
            
            ConsoleUtils::setColor(ConsoleUtils::Color::LIGHTWHITE);
            ConsoleUtils::setBackgroundColor(ConsoleUtils::BackgroundColor::BG_MAGENTA);
            cout << "Consultez le PokESIPE pour acceder a la liste de tous les PokIMACS existants";
            ConsoleUtils::resetColors(); std::cout<<std::endl<<endl<<endl;
            
            detectSpace();
            
            // Liste des PokIMAC:
            ConsoleUtils::setColor(ConsoleUtils::Color::WHITE);
            ConsoleUtils::setBackgroundColor(ConsoleUtils::BackgroundColor::BG_RED);
            cout << " ###!!! DISCLAIMER !!!### ";
            ConsoleUtils::resetColors(); std::cout<<std::endl<<endl<<endl;
            
            
            cout<<"Toute ressemblance de PokIMAC avec des professeurs de l'ESIPE - IMAC est parfaitement fortuite."<<endl
                <<"Ce jeu a ete code dans l'innocence et le stress. Il n'a aucunement pour but de denigrer l'integrite de qui que ce soit. Il se veut fun et bienveillant ! "<<endl<<endl;

            detectSpace();

            ConsoleUtils::setColor(ConsoleUtils::Color::BLUE);
            ConsoleUtils::setBackgroundColor(ConsoleUtils::BackgroundColor::BG_YELLOW);
            cout << " PokESIPE "<<endl<<endl<<"Découvre l'ensemble des PokIMACS disponible !";
            ConsoleUtils::resetColors(); std::cout<<std::endl<<endl<<endl;
            
            detectSpace();
            
            for (int i=0; i<nbPokIMAC; i++){
                
                if(allPokimac[i].espece=="Culture"){
                    ConsoleUtils::setColor(ConsoleUtils::Color::BLACK);
                    ConsoleUtils::setBackgroundColor(ConsoleUtils::BackgroundColor::BG_CYAN);
                    cout <<"Type "<<allPokimac[i].espece ;
                    ConsoleUtils::resetColors(); std::cout<<std::endl<<endl;
                    
                    ConsoleUtils::setColor(ConsoleUtils::Color::LIGHTCYAN);
                    cout << " Cible :";
                    ConsoleUtils::resetColors(); std::cout<<" Design"<<std::endl<<endl;
                    
                    cout<<allPokimac[i].representation<<endl;
                    ConsoleUtils::setColor(ConsoleUtils::Color::LIGHTCYAN);
                    cout<<allPokimac[i].nom<<endl;
                    ConsoleUtils::resetColors();
                    ConsoleUtils::setColor(ConsoleUtils::Color::LIGHTYELLOW);
                    cout<<allPokimac[i].pv<<" PV"<<endl<<endl;
                    ConsoleUtils::resetColors();
                    ConsoleUtils::setColor(ConsoleUtils::Color::BLACK);
                    ConsoleUtils::setBackgroundColor(ConsoleUtils::BackgroundColor::BG_CYAN);
                    cout<<"Ses attaques : "<<endl<<endl;
                    ConsoleUtils::resetColors();
                    for (int n=0; n<2; n++){
                    ConsoleUtils::setColor(ConsoleUtils::Color::LIGHTYELLOW);
                    cout<<allPokimac[i].pouvoir[n].nom_attaque<<" :";
                    ConsoleUtils::resetColors();
                    cout<<" fait perdre "<<allPokimac[i].pouvoir[n].puissance<<" PV a ton adversaire."<<endl<<endl;
                    }
                    detectSpace();
                }
                
                if(allPokimac[i].espece=="Programmation"){
                    ConsoleUtils::setColor(ConsoleUtils::Color::WHITE);
                    ConsoleUtils::setBackgroundColor(ConsoleUtils::BackgroundColor::BG_BLUE);
                    cout <<"Type "<<allPokimac[i].espece ;
                    ConsoleUtils::resetColors(); std::cout<<std::endl<<endl;
                    
                    ConsoleUtils::setColor(ConsoleUtils::Color::LIGHTBLUE);
                    cout << " Cible :";
                    ConsoleUtils::resetColors(); std::cout<<" Aide"<<std::endl<<endl;
                    
                    cout<<allPokimac[i].representation<<endl;
                    ConsoleUtils::setColor(ConsoleUtils::Color::LIGHTBLUE);
                    cout<<allPokimac[i].nom<<endl;
                    ConsoleUtils::resetColors();
                    ConsoleUtils::setColor(ConsoleUtils::Color::LIGHTYELLOW);
                    cout<<allPokimac[i].pv<<" PV"<<endl<<endl;
                    ConsoleUtils::resetColors();
                    ConsoleUtils::setColor(ConsoleUtils::Color::WHITE);
                    ConsoleUtils::setBackgroundColor(ConsoleUtils::BackgroundColor::BG_BLUE);
                    cout<<"Ses attaques : "<<endl<<endl;
                    ConsoleUtils::resetColors();
                    for (int n=0; n<2; n++){
                    ConsoleUtils::setColor(ConsoleUtils::Color::LIGHTYELLOW);
                    cout<<allPokimac[i].pouvoir[n].nom_attaque<<" :";
                    ConsoleUtils::resetColors();
                    cout<<" fait perdre "<<allPokimac[i].pouvoir[n].puissance<<" PV a ton adversaire."<<endl<<endl;
                    }
                    detectSpace();
                }
                
                if(allPokimac[i].espece=="Aide"){
                    ConsoleUtils::setColor(ConsoleUtils::Color::WHITE);
                    ConsoleUtils::setBackgroundColor(ConsoleUtils::BackgroundColor::BG_GREEN);
                    cout <<"Type "<<allPokimac[i].espece ;
                    ConsoleUtils::resetColors(); std::cout<<std::endl<<endl;
                    
                    ConsoleUtils::setColor(ConsoleUtils::Color::LIGHTGREEN);
                    cout << " Cible :";
                    ConsoleUtils::resetColors(); std::cout<<" Mathematiques"<<std::endl<<endl;
                    
                    cout<<allPokimac[i].representation<<endl;
                    ConsoleUtils::setColor(ConsoleUtils::Color::LIGHTGREEN);
                    cout<<allPokimac[i].nom<<endl;
                    ConsoleUtils::resetColors();
                    ConsoleUtils::setColor(ConsoleUtils::Color::LIGHTYELLOW);
                    cout<<allPokimac[i].pv<<" PV"<<endl<<endl;
                    ConsoleUtils::resetColors();
                    ConsoleUtils::setColor(ConsoleUtils::Color::WHITE);
                    ConsoleUtils::setBackgroundColor(ConsoleUtils::BackgroundColor::BG_GREEN);
                    cout<<"Ses attaques : "<<endl<<endl;
                    ConsoleUtils::resetColors();
                    for (int n=0; n<2; n++){
                    ConsoleUtils::setColor(ConsoleUtils::Color::LIGHTYELLOW);
                    cout<<allPokimac[i].pouvoir[n].nom_attaque<<" :";
                    ConsoleUtils::resetColors();
                    cout<<" fait perdre "<<allPokimac[i].pouvoir[n].puissance<<" PV a ton adversaire."<<endl<<endl;
                    }
                    detectSpace();
                }
                
                if(allPokimac[i].espece=="Mathematiques"){
                    ConsoleUtils::setColor(ConsoleUtils::Color::WHITE);
                    ConsoleUtils::setBackgroundColor(ConsoleUtils::BackgroundColor::BG_RED);
                    cout <<"Type "<<allPokimac[i].espece ;
                    ConsoleUtils::resetColors(); std::cout<<std::endl<<endl;
                    
                    ConsoleUtils::setColor(ConsoleUtils::Color::LIGHTRED);
                    cout << " Cible :";
                    ConsoleUtils::resetColors(); std::cout<<" Culture"<<std::endl<<endl;
                    
                    cout<<allPokimac[i].representation<<endl;
                    ConsoleUtils::setColor(ConsoleUtils::Color::LIGHTRED);
                    cout<<allPokimac[i].nom<<endl;
                    ConsoleUtils::resetColors();
                    ConsoleUtils::setColor(ConsoleUtils::Color::LIGHTYELLOW);
                    cout<<allPokimac[i].pv<<" PV"<<endl<<endl;
                    ConsoleUtils::resetColors();
                    ConsoleUtils::setColor(ConsoleUtils::Color::WHITE);
                    ConsoleUtils::setBackgroundColor(ConsoleUtils::BackgroundColor::BG_RED);
                    cout<<"Ses attaques : "<<endl<<endl;
                    ConsoleUtils::resetColors();
                    for (int n=0; n<2; n++){
                    ConsoleUtils::setColor(ConsoleUtils::Color::LIGHTYELLOW);
                    cout<<allPokimac[i].pouvoir[n].nom_attaque<<" :";
                    ConsoleUtils::resetColors();
                    cout<<" fait perdre "<<allPokimac[i].pouvoir[n].puissance<<" PV a ton adversaire."<<endl<<endl;
                    }
                    detectSpace();
                }
                
                if(allPokimac[i].espece=="Design"){
                    ConsoleUtils::setColor(ConsoleUtils::Color::WHITE);
                    ConsoleUtils::setBackgroundColor(ConsoleUtils::BackgroundColor::BG_MAGENTA);
                    cout <<"Type "<<allPokimac[i].espece ;
                    ConsoleUtils::resetColors(); std::cout<<std::endl<<endl;
                    
                    ConsoleUtils::setColor(ConsoleUtils::Color::LIGHTMAGENTA);
                    cout << " Cible :";
                    ConsoleUtils::resetColors(); std::cout<<" Programmation"<<std::endl<<endl;
                    
                    cout<<allPokimac[i].representation<<endl;
                    ConsoleUtils::setColor(ConsoleUtils::Color::LIGHTMAGENTA);
                    cout<<allPokimac[i].nom<<endl;
                    ConsoleUtils::resetColors();
                    ConsoleUtils::setColor(ConsoleUtils::Color::LIGHTYELLOW);
                    cout<<allPokimac[i].pv<<" PV"<<endl<<endl;
                    ConsoleUtils::resetColors();
                    ConsoleUtils::setColor(ConsoleUtils::Color::WHITE);
                    ConsoleUtils::setBackgroundColor(ConsoleUtils::BackgroundColor::BG_MAGENTA);
                    cout<<"Ses attaques : "<<endl<<endl;
                    ConsoleUtils::resetColors();
                    for (int n=0; n<2; n++){
                    ConsoleUtils::setColor(ConsoleUtils::Color::LIGHTYELLOW);
                    cout<<allPokimac[i].pouvoir[n].nom_attaque<<" :";
                    ConsoleUtils::resetColors();
                    cout<<" fait perdre "<<allPokimac[i].pouvoir[n].puissance<<" PV a ton adversaire."<<endl<<endl;
                    }
                    detectSpace();
                }
                
            }
            

            
            // Les poKIMAC Starter :
            ConsoleUtils::setColor(ConsoleUtils::Color::BLUE);
            ConsoleUtils::setBackgroundColor(ConsoleUtils::BackgroundColor::BG_YELLOW);
            cout << "Les PokIMACS de depart";
            ConsoleUtils::resetColors(); std::cout<<" tres souvent appeles par le terme anglais 'starters', sont les premiers PokIMACS a rejoindre ton equipe."<<std::endl<<endl;
            
            
            cout<<"Dans la plupart des cas, tu as le choix entre trois PokIMACS ayant l'un de ces types : Culture, Programmation, Mathematiques, Design et Aide."<<endl
                <<"Ce trio permet d'introduire rapidement au joueur la notion de sensibilite des types avec des concepts familiers : la Culture bat le Design et la Culture craint les Mathematiques par exemple."<<endl;
           

            detectSpace();
            printRegles();

        } else if (choix_utilisateur == '3') {
            
            ConsoleUtils::setColor(ConsoleUtils::Color::BLUE);
            ConsoleUtils::setBackgroundColor(ConsoleUtils::BackgroundColor::BG_YELLOW);
            cout << "LES OBJETS";
            ConsoleUtils::resetColors(); std::cout<<std::endl<<endl;
            
            cout<<"Les objets font partie de ton inventaire, ton sac a dos d'aventurier ! "<<endl<<"Ils te permettent d'ameliorer ta chasse aux PokIMACs. Lorsque tu utilises un objet, celui-ci disparait apres utilisation."<<endl << endl;
            
            detectSpace();
            
            for (int i=0; i<nbObjet; i++){
                
                cout<<allObject[i].visuel<<endl;
                
                ConsoleUtils::setColor(ConsoleUtils::Color::LIGHTBLUE);
                cout<<allObject[i].nom<<endl<<endl;
                ConsoleUtils::resetColors();
                ConsoleUtils::setColor(ConsoleUtils::Color::LIGHTCYAN);
                cout<<"Objet de type "<<allObject[i].id_type<<endl<<endl;
                ConsoleUtils::resetColors();
                ConsoleUtils::setColor(ConsoleUtils::Color::LIGHTYELLOW);
                cout<<"Utilité :";
                ConsoleUtils::resetColors();
                ConsoleUtils::setColor(ConsoleUtils::Color::BLUE);
                cout<<" "<<allObject[i].definition<<endl;
                ConsoleUtils::resetColors();
                detectSpace();

            }
            
            printRegles();
            
        } else if (choix_utilisateur == '4') {

            //combat, capture, fuite
            ConsoleUtils::setColor(ConsoleUtils::Color::BLUE);
            ConsoleUtils::setBackgroundColor(ConsoleUtils::BackgroundColor::BG_YELLOW);
            cout << "COMBAT, CAPTURE ET FUITE";
            ConsoleUtils::resetColors(); std::cout<<std::endl<<endl;
            
            ConsoleUtils::setColor(ConsoleUtils::Color::YELLOW);
            cout << "Pour capturer ou combattre des PokIMACS, rends toi dans les hautes herbes ! (#)";
            ConsoleUtils::resetColors(); std::cout<<std::endl<<endl;

            
            ConsoleUtils::setColor(ConsoleUtils::Color::LIGHTBLUE);
            cout << "> Combat";
            ConsoleUtils::resetColors(); std::cout<<std::endl<<endl;
            
            cout<<"Selectionne ton attaque et tente de blesser le PokIMAC adverse ! Attention, ce dernier va repliquer ! "<<endl
                <<"Le combat se deroule jusqu'a ce que tu viennes a bout de ton adversaire ou que tu decides de fuir ou de capturer ton ennemi. "<<endl
                <<endl
                <<"Ces combats permettent d'entrainer tes PokIMAC pour les rendre plus forts !"<<endl
            <<endl;
            
            ConsoleUtils::setColor(ConsoleUtils::Color::BLACK);
            ConsoleUtils::setBackgroundColor(ConsoleUtils::BackgroundColor::BG_GREEN);
            cout << "QUE LE MEILLEUR GAGNE !";
            ConsoleUtils::resetColors(); std::cout<<std::endl<<endl;
            
            detectSpace();
            
            ConsoleUtils::setColor(ConsoleUtils::Color::LIGHTCYAN);
            cout << "> Capture";
            ConsoleUtils::resetColors(); std::cout<<std::endl<<endl;
            
            cout<<"Lorsque tu rencontres un PokIMAC, si ce dernier possede moins de PV que ton PokIMAC, tu peux le capturer sans avoir a mener combat sanguinaire !"<<endl
            <<"Si le PokIMAC rencontre est plus fort que toi, tu peux decider de le combattre pour l'affaiblir et ainsi pouvoir le capturer ! "<<endl;
               
            ConsoleUtils::setColor(ConsoleUtils::Color::LIGHTRED);
            cout << "Attention ! Pour pouvoir capturer un PokIMAC, tu dois posseder des Pokiball !";
            ConsoleUtils::resetColors(); std::cout<<std::endl<<endl;
            ConsoleUtils::setColor(ConsoleUtils::Color::WHITE);
            ConsoleUtils::setBackgroundColor(ConsoleUtils::BackgroundColor::BG_RED);
            cout << "POUR RAPPEL : 1 POKIBALL = 1 POKIMAC !";
            ConsoleUtils::resetColors(); std::cout<<std::endl<<endl;

            detectSpace();
            
            ConsoleUtils::setColor(ConsoleUtils::Color::LIGHTMAGENTA);
            cout << "> Fuite";
            ConsoleUtils::resetColors(); std::cout<<std::endl<<endl;
            
            cout<<"Si tu ne veux ni combattre ni capturer de PokIMAC, tu peux decider de fuire pour continuer ta promenade."<<endl
            <<"Tu peux egalement fuire lors d'un combat si ce dernier s'annonce laborieux ou que tu es trop affaibli pour continuer."<<endl;
            
            ConsoleUtils::setColor(ConsoleUtils::Color::LIGHTMAGENTA);
            cout << "Malheureusement, a ce rythme la, tu ne risques pas de devenir le plus grand dresseur du Champs...";
            ConsoleUtils::resetColors(); std::cout<<std::endl;
        
            detectSpace();
            printRegles();

        }else{
            
            //Fin du programme > retour au menu instruction

            printSelection();
            
        }
    
}
