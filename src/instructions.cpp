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
 
    
    //cout << "Choisis dans le menu (1, 2 ou 3) :" << endl<<endl;
    
    ConsoleUtils::setColor(ConsoleUtils::Color::BLUE);
    ConsoleUtils::setBackgroundColor(ConsoleUtils::BackgroundColor::BG_YELLOW);
    std::cout << "Choisis dans le menu (1, 2 ou 3) :";
    ConsoleUtils::resetColors(); std::cout << std::endl<<endl;
        
    cout << "1. Commandes" << endl;
    cout << "2. Regles du jeu" << endl;
    cout << "3. Retour" << endl;

    int user_choice;
    cout << "Ton choix : ";
    cin >> user_choice;

    while(user_choice<1 || user_choice>3){
        cout<<"Ce choix n'est pas valide ! Tu dois choisir entre 1 et 3."<<endl
            <<endl;
        cout << "Ton choix : ";
        cin >> user_choice;
    }
    
    ConsoleUtils::clear();

    if (user_choice == 1) {
        
       // int choix=0;
        
        // Présentation des commandes + possibilité de faire retour
        // TODO Récupérer ASCII ART "COMMANDES"
        
        detectSpace();
        
        cout<<""<<endl;
        
       // cout<<"Pour se diriger dans le jeu : "<<endl<<endl;
        
        ConsoleUtils::setColor(ConsoleUtils::Color::BLUE);
        ConsoleUtils::setBackgroundColor(ConsoleUtils::BackgroundColor::BG_YELLOW);
        std::cout << "Pour se diriger dans le jeu : ";
        ConsoleUtils::resetColors(); std::cout <<std::endl<<endl<<endl;
        
        ConsoleUtils::setColor(ConsoleUtils::Color::BLACK);
        ConsoleUtils::setBackgroundColor(ConsoleUtils::BackgroundColor::BG_CYAN);
        std::cout << "> 'Fleche du haut' ou Z : ";
        ConsoleUtils::resetColors(); std::cout << "  pour aller vers le haut"<<std::endl<<endl;
        
       // cout<<"> 'Fleche du haut' ou Z : pour aller vers le haut"<<endl;
        
        ConsoleUtils::setColor(ConsoleUtils::Color::BLACK);
        ConsoleUtils::setBackgroundColor(ConsoleUtils::BackgroundColor::BG_CYAN);
        std::cout << "> 'Fleche de droite' ou D : ";
        ConsoleUtils::resetColors(); std::cout << "  pour aller vers la droite"<<std::endl<<endl;
        
       // cout<<"> 'Fleche de droite' ou D : pour aller vers la droite"<<endl;
        
        ConsoleUtils::setColor(ConsoleUtils::Color::BLACK);
        ConsoleUtils::setBackgroundColor(ConsoleUtils::BackgroundColor::BG_CYAN);
        std::cout << "> 'Fleche du bas' ou S : ";
        ConsoleUtils::resetColors(); std::cout << "  pour aller vers le bas"<<std::endl<<endl;
        
      //  cout<<"> 'Fleche du bas' ou S : pour aller vers le bas"<<endl;
        
        ConsoleUtils::setColor(ConsoleUtils::Color::BLACK);
        ConsoleUtils::setBackgroundColor(ConsoleUtils::BackgroundColor::BG_CYAN);
        std::cout << "> 'Fleche de gauche' ou Q : ";
        ConsoleUtils::resetColors(); std::cout << "  pour aller vers la gauche "<<std::endl<<endl<<endl;
        
     //   cout<<"> 'Fleche de gauche' ou Q : pour aller vers la gauche"<<endl<<endl;

       //cout<<"Pour selectionner une option : "<<endl<<endl;
        
        ConsoleUtils::setColor(ConsoleUtils::Color::BLUE);
        ConsoleUtils::setBackgroundColor(ConsoleUtils::BackgroundColor::BG_YELLOW);
        std::cout << "Pour selectionner une option : ";
        ConsoleUtils::resetColors(); std::cout <<std::endl<<endl;
        
        ConsoleUtils::setColor(ConsoleUtils::Color::CYAN);
        std::cout << "> ";
        ConsoleUtils::resetColors(); std::cout<<"Saisir ton choix ou ce qui t'est demande a l'aide du clavier. Si tu dois valider ton choix, appuie sur la touche 'o'" <<std::endl<<endl;
        
     //   cout<<"> Saisir ton choix ou ce qui t'est demande a l'aide du clavier. Si tu dois valider ton choix, appuie sur la touche 'o'"<<endl;
        
        ConsoleUtils::setColor(ConsoleUtils::Color::CYAN);
        std::cout << "> ";
        ConsoleUtils::resetColors(); std::cout<<"Appuie sur la touche 'espace' pour revenir au menu principal. Attention, realise en cours de partie, cette action quittera la partie de façon definitive." <<std::endl<<endl;
        
        
       // cout<<"> Appuie sur la touche 'espace' pour revenir au menu principal. Attention, realise en cours de partie, cette action quittera la partie de façon definitive."<<endl<<endl;
        
        ConsoleUtils::setColor(ConsoleUtils::Color::BLACK);
        ConsoleUtils::setBackgroundColor(ConsoleUtils::BackgroundColor::BG_CYAN);
        std::cout << "> Si tu ne comprends pas les commandes, adresse toi a Aurore Lafaurie (@_just_kiel_ sur instagram), elle saura te guider ! ";
        ConsoleUtils::resetColors(); std::cout <<std::endl<<endl;
        
      //  cout<<"> Si tu ne comprends pas les commandes, adresse toi a Aurore Lafaurie (@_just_kiel_ sur instagram), elle saura te guider ! "<<endl<<endl;
        
        detectSpace();
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
        
    ConsoleUtils::setColor(ConsoleUtils::Color::BLUE);
    ConsoleUtils::setBackgroundColor(ConsoleUtils::BackgroundColor::BG_YELLOW);
    std::cout << "Choisis dans le menu (1, 2 ou 3) :";
    ConsoleUtils::resetColors(); std::cout << std::endl<<endl;
    
    // cout << "1. Histoire et Enjeux" << endl;

    ConsoleUtils::setColor(ConsoleUtils::Color::BLUE);
    ConsoleUtils::setBackgroundColor(ConsoleUtils::BackgroundColor::BG_YELLOW);
    std::cout << "1.";
    ConsoleUtils::resetColors(); std::cout << " Histoire et Enjeux" <<std::endl<<endl;
    
      //  cout << "2. Les PokImacs" << endl;
    
    ConsoleUtils::setColor(ConsoleUtils::Color::BLUE);
    ConsoleUtils::setBackgroundColor(ConsoleUtils::BackgroundColor::BG_YELLOW);
    std::cout << "2.";
    ConsoleUtils::resetColors(); std::cout << " Les PokImacs" <<std::endl<<endl;
    
     // cout << "3. Les Objets" << endl;
    
    ConsoleUtils::setColor(ConsoleUtils::Color::BLUE);
    ConsoleUtils::setBackgroundColor(ConsoleUtils::BackgroundColor::BG_YELLOW);
    std::cout << "3.";
    ConsoleUtils::resetColors(); std::cout << " Les Objets" <<std::endl<<endl;
    
    //cout << "4. Combat, capture et fuite" << endl;
    
    ConsoleUtils::setColor(ConsoleUtils::Color::BLUE);
    ConsoleUtils::setBackgroundColor(ConsoleUtils::BackgroundColor::BG_YELLOW);
    std::cout << "4.";
    ConsoleUtils::resetColors(); std::cout << " Combat, capture et fuite" <<std::endl<<endl;
    
    //cout << "5. Retour" << endl;
    
    ConsoleUtils::setColor(ConsoleUtils::Color::BLUE);
    ConsoleUtils::setBackgroundColor(ConsoleUtils::BackgroundColor::BG_YELLOW);
    std::cout << "5.";
    ConsoleUtils::resetColors(); std::cout << " Retour" <<std::endl<<endl;
    
    
        
        cout << "Ton choix : ";
        cin >> choix_utilisateur;

        while(choix_utilisateur<1 || choix_utilisateur>5){
            cout<<"Ce choix n'est pas valide ! Tu dois choisir entre 1 et 5."<<endl;
            cout << "Ton choix : ";
            cin >> choix_utilisateur;
        }
        
        detectSpace();

        if (choix_utilisateur == 1) {
            
           // cout<<"HISTOIRE ET ENJEUX"<<endl<<endl;
           // detectSpace();
            
            ConsoleUtils::setColor(ConsoleUtils::Color::BLUE);
            ConsoleUtils::setBackgroundColor(ConsoleUtils::BackgroundColor::BG_YELLOW);
            std::cout << "HISTOIRE ET ENJEUX";
            ConsoleUtils::resetColors(); std::cout<<std::endl<<endl;
            

            
            cout<<"Tu incarnes un jeune DressESIPE de PokIMAC a qui l'on offre un PokIMAC de depart, et tu pars pour une aventure semee d'embuches."<<endl
            <<"Tu parcours une region peuplee de PokIMAC sauvages que tu peux capturer et faire combattre."<<endl
            <<endl
            <<"Tout ceci dans le but de te mesurer a l'elite des dresseurs du Champs et enfin devenir le Maitre du Bourg Coper avec le PokESIPE le plus rempli !"<<endl;
            
            detectSpace();
            printRegles();
            
        } else if (choix_utilisateur == 2) {
            
            // Les PokIMAC :
            
          //  cout<<"LES POKIMACS"<<endl;
            
            ConsoleUtils::setColor(ConsoleUtils::Color::BLUE);
            ConsoleUtils::setBackgroundColor(ConsoleUtils::BackgroundColor::BG_YELLOW);
            std::cout << "LES POKIMACS";
            ConsoleUtils::resetColors(); std::cout<<std::endl<<endl<<endl;
            
            
            cout<<"Les PokIMACS sont des creatures dotees de pouvoirs extraordinaires, comme la capacite de vous faire parler anglais ou de t'aider a obtenir ton diplome."<<endl
            <<"Ils peuvent se faire capturer par les DressESIPE dans des Pokiballs, des boules creuses rouges, oranges, bleues et vertes qui semblent aspirer la creature :on peut donc transporter ces poKIMACS dans des Pokiballs de la taille d'une pomme. On recense actuellement 5 especes de PokIMAC."<<endl<<endl;
            
            // <<"Consultez le PokESIPE pour acceder a la liste de tous les PokIMACS existants !"<<endl;
            ConsoleUtils::setColor(ConsoleUtils::Color::BLACK);
            ConsoleUtils::setBackgroundColor(ConsoleUtils::BackgroundColor::BG_MAGENTA);
            std::cout << "Consultez le PokESIPE pour acceder a la liste de tous les PokIMACS existants";
            ConsoleUtils::resetColors(); std::cout<<std::endl<<endl<<endl;
            
            detectSpace();
            
            // Liste des PokIMAC
            
          //  cout<<" ###!!! DISCLAIMER !!!### "<<endl
            
            ConsoleUtils::setColor(ConsoleUtils::Color::WHITE);
            ConsoleUtils::setBackgroundColor(ConsoleUtils::BackgroundColor::BG_RED);
            std::cout << " ###!!! DISCLAIMER !!!### ";
            ConsoleUtils::resetColors(); std::cout<<std::endl<<endl<<endl;
            
            
            cout<<"Toute ressemblance de PokIMAC avec des professeurs de l'ESIPE - IMAC est parfaitement fortuite."<<endl
                <<"Ce jeu a été code dans l'innocence, la stress et la prise de tête. Il n'a aucunement pour but de denigrer l'integrite de qui que ce soit. Il se veut fun et bienveillant ! "<<endl<<endl;

            detectSpace();
            
           //cout<<"PokESIPE : "<<endl<<endl;
            
            ConsoleUtils::setColor(ConsoleUtils::Color::BLUE);
            ConsoleUtils::setBackgroundColor(ConsoleUtils::BackgroundColor::BG_YELLOW);
            std::cout << " PokESIPE ";
            ConsoleUtils::resetColors(); std::cout<<std::endl<<endl<<endl;
            
            
            //cout<<"Type Culture : "<<endl
            
            ConsoleUtils::setColor(ConsoleUtils::Color::BLACK);
            ConsoleUtils::setBackgroundColor(ConsoleUtils::BackgroundColor::BG_CYAN);
            std::cout << " Type Culture ";
            ConsoleUtils::resetColors(); std::cout<<std::endl<<endl<<endl;
            
            ConsoleUtils::setColor(ConsoleUtils::Color::CYAN);
            std::cout << " Cible :";
            ConsoleUtils::resetColors(); std::cout<<" Design"<<std::endl<<endl;
            
            cout<<" - Robbizarre" << endl
                <<" - Ozlameche "<< endl
                <<" - Gairrarlande"<<endl<<endl;
            
           // cout<<"Type Programmation : "<<endl
            
            ConsoleUtils::setColor(ConsoleUtils::Color::BLACK);
            ConsoleUtils::setBackgroundColor(ConsoleUtils::BackgroundColor::BG_CYAN);
            std::cout << " Type Programmation ";
            ConsoleUtils::resetColors(); std::cout<<std::endl<<endl<<endl;
            
            ConsoleUtils::setColor(ConsoleUtils::Color::CYAN);
            std::cout << " Cible :";
            ConsoleUtils::resetColors(); std::cout<<" Mathematiques"<<std::endl<<endl;
            
            cout<<" - Nosteevrapti" <<endl
                <<" - Laporteille" <<endl
                <<" - Charpenti" <<endl<<endl;
            
            //cout<<"Type Mathematiques : "<<endl
            
            ConsoleUtils::setColor(ConsoleUtils::Color::BLACK);
            ConsoleUtils::setBackgroundColor(ConsoleUtils::BackgroundColor::BG_CYAN);
            std::cout << " Type Mathematiques ";
            ConsoleUtils::resetColors(); std::cout<<std::endl<<endl<<endl;
            
            ConsoleUtils::setColor(ConsoleUtils::Color::CYAN);
            std::cout << " Cible :";
            ConsoleUtils::resetColors(); std::cout<<" Culture"<<std::endl<<endl;
            
            cout<<" - Nocvelli"<<endl
                <<" - Rieulu"<<endl<<endl;
            
          //  cout<<"Type Aide : "<<endl
            
            ConsoleUtils::setColor(ConsoleUtils::Color::BLACK);
            ConsoleUtils::setBackgroundColor(ConsoleUtils::BackgroundColor::BG_CYAN);
            std::cout << " Type Aide ";
            ConsoleUtils::resetColors(); std::cout<<std::endl<<endl<<endl;
            
            ConsoleUtils::setColor(ConsoleUtils::Color::CYAN);
            std::cout << " Cible :";
            ConsoleUtils::resetColors(); std::cout<<" Mathematiques"<<std::endl<<endl;
            
            
            cout<<" - Soniafee"<<endl
                <<" - Enguerratueur"<<endl
                <<" - Cherripant"<<endl<<endl;
            
            
           // cout<<"Type Design : "<<endl
            
            ConsoleUtils::setColor(ConsoleUtils::Color::BLACK);
            ConsoleUtils::setBackgroundColor(ConsoleUtils::BackgroundColor::BG_CYAN);
            std::cout << " Type Design ";
            ConsoleUtils::resetColors(); std::cout<<std::endl<<endl<<endl;
            
            ConsoleUtils::setColor(ConsoleUtils::Color::CYAN);
            std::cout << " Cible :";
            ConsoleUtils::resetColors(); std::cout<<" Programmation"<<std::endl<<endl;
            
            cout<<" - Gautiplouf"<<endl
                <<" - Chataiglam"<<endl<<endl;
            
            detectSpace();
            
            // Les poKIMAC Starter :
            
            ConsoleUtils::setColor(ConsoleUtils::Color::BLUE);
            ConsoleUtils::setBackgroundColor(ConsoleUtils::BackgroundColor::BG_YELLOW);
            std::cout << "Les PokIMACS de départ";
            ConsoleUtils::resetColors(); std::cout<<" tres souvent appeles par le terme anglais 'starters', sont les premiers PokIMACS a rejoindre ton equipe."<<std::endl<<endl;
            
            
            cout<<"Dans la plupart des cas, tu as le choix entre trois PokIMACS ayant l'un de ces types : Culture, Programmation, Mathematiques, Design et Aide."<<endl
                <<"Ce trio permet d'introduire rapidement au joueur la notion de sensibilite des types avec des concepts familiers : la Culture bat le Design et la Culture craint les Mathématiques par exemple."<<endl;
           

            detectSpace();
            printRegles();

        } else if (choix_utilisateur == 3) {
            
            //objets
            
           // cout<<"LES OBJETS"<<endl;
            
            ConsoleUtils::setColor(ConsoleUtils::Color::BLUE);
            ConsoleUtils::setBackgroundColor(ConsoleUtils::BackgroundColor::BG_YELLOW);
            std::cout << "LES OBJETS";
            ConsoleUtils::resetColors(); std::cout<<std::endl<<endl;
            
            cout<<" Les objets font partie de ton inventaire, ton sac a dos d'aventurier ! "<<endl<<"Ils te permettent d'ameliorer ta chasse aux PokIMAC. Lorsque tu utilises un objet, celui-ci disparait apres utilisation"<<endl;
            
            // visuel de Pokiball
            
            cout<<""<<endl;
            
            ConsoleUtils::setColor(ConsoleUtils::Color::WHITE);
            ConsoleUtils::setBackgroundColor(ConsoleUtils::BackgroundColor::BG_MAGENTA);
            std::cout << "Les Pokiball ";
            ConsoleUtils::resetColors(); std::cout<<" sont des objets de type 0, elles te permettent de capturer des PokIMACS sauvages."<<std::endl<<endl;
            
            ConsoleUtils::setColor(ConsoleUtils::Color::MAGENTA);
            std::cout << "Attention, 1 pokiball ne peut contenir qu'un seul PokIMAC !";
            ConsoleUtils::resetColors(); std::cout<<" Tu commences la partie avec une Pokiball, a toi d'en gagner d'autres en te baladant dans le Bourg Coper."<<std::endl<<endl;
            
            detectSpace();
            
            ConsoleUtils::setColor(ConsoleUtils::Color::MAGENTA);
            std::cout << "Les objets de type 1 te permettent de regenerer les PV de tes PokIMACS si ces derniers sont blesses. Tu peux regenerer tes PV autant de fois que tu as d'objets !";
            ConsoleUtils::resetColors(); std::cout<<std::endl<<endl;
            
            cout <<"Voici les differents objets de type 1 : "<<endl;
            
            cout<<""<<endl; // TODO visuel biere
            
              // cout <<"> La Biere te permet de regenerer 5 PV au PokIMAC de ton choix. "<<endl;
            
            ConsoleUtils::setColor(ConsoleUtils::Color::BLACK);
            ConsoleUtils::setBackgroundColor(ConsoleUtils::BackgroundColor::BG_YELLOW);
            std::cout << "> La Biere";
            ConsoleUtils::resetColors(); std::cout<<" te permet de regenerer ";
            ConsoleUtils::setColor(ConsoleUtils::Color::LIGHTYELLOW);
            std::cout << "5 PV";
            ConsoleUtils::resetColors(); std::cout<<" au PokIMAC de ton choix."<<std::endl<<endl;

            
            cout<<""<<endl; // TODO  visuel Mojito
            
              //  <<"> Le Mojito te permet de regenerer 10 PV au PokIMAC de ton choix. "<<endl;
            
            ConsoleUtils::setColor(ConsoleUtils::Color::BLACK);
            ConsoleUtils::setBackgroundColor(ConsoleUtils::BackgroundColor::BG_GREEN);
            std::cout << "> Le Mojito";
            ConsoleUtils::resetColors(); std::cout<<" te permet de regenerer ";
            ConsoleUtils::setColor(ConsoleUtils::Color::LIGHTGREEN);
            std::cout << "10 PV";
            ConsoleUtils::resetColors(); std::cout<<" au PokIMAC de ton choix."<<std::endl<<endl;
            
            cout<<""<<endl; // TODO visuel Chocolat Chaud
                
            //<<"> Le Chocolat Chaud te permet de regenerer 15 PV au PokIMAC de ton choix. "<<endl;
            
            ConsoleUtils::setColor(ConsoleUtils::Color::WHITE);
            ConsoleUtils::setBackgroundColor(ConsoleUtils::BackgroundColor::BG_BLUE);
            std::cout << "> Le Chocolat Chaud";
            ConsoleUtils::resetColors(); std::cout<<" te permet de regenerer ";
            ConsoleUtils::setColor(ConsoleUtils::Color::LIGHTBLUE);
            std::cout << "15 PV";
            ConsoleUtils::resetColors(); std::cout<<" au PokIMAC de ton choix."<<std::endl<<endl;
            
            
            cout<<""<<endl; // TODO visuel Repas CROUS
               
            //<<"> Le Repas CROUS te permet de regenerer 20 PV au PokIMAC de ton choix. "<<endl;
            
            ConsoleUtils::setColor(ConsoleUtils::Color::WHITE);
            ConsoleUtils::setBackgroundColor(ConsoleUtils::BackgroundColor::BG_RED);
            std::cout << "> Le Repas Crous";
            ConsoleUtils::resetColors(); std::cout<<" te permet de regenerer ";
            ConsoleUtils::setColor(ConsoleUtils::Color::LIGHTRED);
            std::cout << "20 PV";
            ConsoleUtils::resetColors(); std::cout<<" au PokIMAC de ton choix."<<std::endl<<endl;
            
            cout<<""<<endl; // TODO visuel Cassoulet
            
               // <<"> Le Cassoulet te permet de regenerer 25 PV au PokIMAC de ton choix. "<<endl;
            
            ConsoleUtils::setColor(ConsoleUtils::Color::BLACK);
            ConsoleUtils::setBackgroundColor(ConsoleUtils::BackgroundColor::BG_CYAN);
            std::cout << "> Le Cassoulet";
            ConsoleUtils::resetColors(); std::cout<<" te permet de regenerer ";
            ConsoleUtils::setColor(ConsoleUtils::Color::LIGHTCYAN);
            std::cout << "25 PV";
            ConsoleUtils::resetColors(); std::cout<<" au PokIMAC de ton choix."<<std::endl<<endl;
            
            detectSpace();
            
           // cout<<"Les objets de type 2 te permettent de multiplier la puissance de tes attaques. Attention, tu ne peux multiplier tes attaques qu'une seule fois dans par combat ! "<<endl
            
            ConsoleUtils::setColor(ConsoleUtils::Color::MAGENTA);
            std::cout << "Les objets de type 2 te permettent de multiplier la puissance de tes attaques."<<endl<<"Attention, tu ne peux multiplier tes attaques qu'une seule fois dans par combat !";
            ConsoleUtils::resetColors(); std::cout<<std::endl<<endl;

            cout<< "Voici les differents objets de type 2 : "<<endl;
            
            cout<<""<<endl; // TODO visuel sel
               
           // <<"Le Sel augmente x2 la puissance de toutes tes attaques."<<endl;
            
            ConsoleUtils::setColor(ConsoleUtils::Color::BLACK);
            ConsoleUtils::setBackgroundColor(ConsoleUtils::BackgroundColor::BG_CYAN);
            std::cout << "> Le Sel";
            ConsoleUtils::resetColors(); std::cout<<" augmente ";
            ConsoleUtils::setColor(ConsoleUtils::Color::LIGHTCYAN);
            std::cout << "X2";
            ConsoleUtils::resetColors(); std::cout<<" la puissance de toutes tes attaques."<<std::endl<<endl;
            
            
            cout<<""<<endl;  // TODO visuel Weekend
            
            
              //  <<"Le Weekend augmente x3 la puissance de toutes tes attaques."<<endl;
            
            ConsoleUtils::setColor(ConsoleUtils::Color::BLACK);
            ConsoleUtils::setBackgroundColor(ConsoleUtils::BackgroundColor::BG_YELLOW);
            std::cout << "> Le Weekend";
            ConsoleUtils::resetColors(); std::cout<<" augmente ";
            ConsoleUtils::setColor(ConsoleUtils::Color::LIGHTYELLOW);
            std::cout << "X3";
            ConsoleUtils::resetColors(); std::cout<<" la puissance de toutes tes attaques."<<std::endl<<endl;
            
            
            cout<<""<<endl ;// TODO visuel Presentiel
               
            //<<"Le Presentiel augmente x4 la puissance de toutes tes attaques."<<endl;
            
            ConsoleUtils::setColor(ConsoleUtils::Color::BLACK);
            ConsoleUtils::setBackgroundColor(ConsoleUtils::BackgroundColor::BG_GREEN);
            std::cout << "> Le Presentiel";
            ConsoleUtils::resetColors(); std::cout<<" augmente ";
            ConsoleUtils::setColor(ConsoleUtils::Color::LIGHTGREEN);
            std::cout << "X4";
            ConsoleUtils::resetColors(); std::cout<<" la puissance de toutes tes attaques."<<std::endl<<endl;
            
            
            cout<<""<<endl; // TODO visuel billet train
            
            //<<"Le Billet de Train augmente x5 la puissance de toutes tes attaques. "<<endl;
            
            ConsoleUtils::setColor(ConsoleUtils::Color::WHITE);
            ConsoleUtils::setBackgroundColor(ConsoleUtils::BackgroundColor::BG_RED);
            std::cout << "> Le Billet de Train";
            ConsoleUtils::resetColors(); std::cout<<" augmente ";
            ConsoleUtils::setColor(ConsoleUtils::Color::LIGHTRED);
            std::cout << "X5";
            ConsoleUtils::resetColors(); std::cout<<" la puissance de toutes tes attaques."<<std::endl<<endl;
            
            cout<<""<<endl; // TODO visuel sommeil
            
            // <<"Le Sommeil Reparateur augmente x10 la puissance de toutes tes attaques."<<endl;
            
            ConsoleUtils::setColor(ConsoleUtils::Color::WHITE);
            ConsoleUtils::setBackgroundColor(ConsoleUtils::BackgroundColor::BG_BLUE);
            std::cout << "> Le Sommeil Reparateur";
            ConsoleUtils::resetColors(); std::cout<<" augmente ";
            ConsoleUtils::setColor(ConsoleUtils::Color::LIGHTBLUE);
            std::cout << "X10";
            ConsoleUtils::resetColors(); std::cout<<" la puissance de toutes tes attaques."<<std::endl<<endl;
            
            detectSpace();
            printRegles();
            
        } else if (choix_utilisateur == 4) {

            //combat, capture, fuite
            
            ConsoleUtils::setColor(ConsoleUtils::Color::BLUE);
            ConsoleUtils::setBackgroundColor(ConsoleUtils::BackgroundColor::BG_YELLOW);
            std::cout << "COMBAT, CAPTURE ET FUITE";
            ConsoleUtils::resetColors(); std::cout<<std::endl<<endl;
            
            ConsoleUtils::setColor(ConsoleUtils::Color::YELLOW);
            std::cout << "Pour capturer ou combattre des PokIMACS, rend toi dans les hautes herbes ! (#)";
            ConsoleUtils::resetColors(); std::cout<<std::endl<<endl;

            
            ConsoleUtils::setColor(ConsoleUtils::Color::LIGHTBLUE);
            std::cout << "> Combat";
            ConsoleUtils::resetColors(); std::cout<<std::endl<<endl;
            
            cout<<"Selectionne ton attaque et tente de blesser le PokIMAC adverse ! Attention, ce dernier va repliquer ! "<<endl
                <<"Le combat se deroule jusqu'a ce que tu viennes a bout de ton adversaire ou que tu decides de fuire ou de capturer ton ennemi. "<<endl
                <<endl
                <<"Ces combats permettent d'entrainer tes PokIMAC pour les rendre plus forts !"<<endl
            <<endl;
            
            ConsoleUtils::setColor(ConsoleUtils::Color::BLACK);
            ConsoleUtils::setBackgroundColor(ConsoleUtils::BackgroundColor::BG_GREEN);
            std::cout << "QUE LE MEILLEUR GAGNE !";
            ConsoleUtils::resetColors(); std::cout<<std::endl<<endl;
            
            detectSpace();
            
            ConsoleUtils::setColor(ConsoleUtils::Color::LIGHTCYAN);
            std::cout << "> Capture";
            ConsoleUtils::resetColors(); std::cout<<std::endl<<endl;
            
            cout<<"Lorsque tu rencontres un PokIMAC, si ce dernier possede moins de PV que ton PokIMAC, tu peux le capturer sans avoir a mener combat sanguinaire !"<<endl
            <<"Si le PokIMAC rencontre est plus fort que toi, tu peux decider de le combattre pour l'affaiblir et ainsi pouvoir le capturer ! "<<endl;
               
            ConsoleUtils::setColor(ConsoleUtils::Color::LIGHTRED);
            std::cout << "Attention ! Pour pouvoir capturer un PokIMAC, tu dois posseder des Pokiball !";
            ConsoleUtils::resetColors(); std::cout<<std::endl<<endl;
            ConsoleUtils::setColor(ConsoleUtils::Color::WHITE);
            ConsoleUtils::setBackgroundColor(ConsoleUtils::BackgroundColor::BG_RED);
            std::cout << "POUR RAPPEL : 1 POKIBALL = 1 POKIMAC !";
            ConsoleUtils::resetColors(); std::cout<<std::endl<<endl;

            detectSpace();
            
            ConsoleUtils::setColor(ConsoleUtils::Color::LIGHTMAGENTA);
            std::cout << "> Fuite";
            ConsoleUtils::resetColors(); std::cout<<std::endl<<endl;
            
            cout<<"Si tu ne veux ni combattre ni capturer de PokIMAC, tu peux decider de fuire pour continuer ta promenade."<<endl
            <<"Tu peux egalement fuire lors d'un combat si ce dernier s'annonce laborieux ou que tu es trop affaiblit pour continuer."<<endl;
            
            ConsoleUtils::setColor(ConsoleUtils::Color::LIGHTMAGENTA);
            std::cout << "Malheureusement, a ce rythme la, tu ne risque pas de devenir le plus grand dresseur du Champs...";
            ConsoleUtils::resetColors(); std::cout<<std::endl;
        
            detectSpace();
            printRegles();

        }else{
            
            //Fin du programme > retour au menu instruction

            printSelection();
            
        }
    
}
