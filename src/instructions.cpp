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
    std::cout << "Choisis dans le menu (1, 2 ou 3) :";
    ConsoleUtils::resetColors(); std::cout << std::endl<<endl;
        
    cout << "1. Commandes" << endl;
    cout << "2. Regles du jeu" << endl;
    cout << "3. Retour" << endl;

    char user_choice;
    cout << "Ton choix : ";
    cin >> user_choice;

    while(user_choice<'1' || user_choice>'3'){
        cout<<"Ce choix n'est pas valide ! Tu dois choisir entre 1 et 3."<<endl
            <<endl;
        cout << "Ton choix : ";
        cin >> user_choice;
    }
    
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
        std::cout << "Pour se diriger dans le jeu : ";
        ConsoleUtils::resetColors(); std::cout <<std::endl<<endl<<endl;
        
        ConsoleUtils::setColor(ConsoleUtils::Color::BLACK);
        ConsoleUtils::setBackgroundColor(ConsoleUtils::BackgroundColor::BG_CYAN);
        std::cout << "> 'Fleche du haut' ou Z : ";
        ConsoleUtils::resetColors(); std::cout << "  pour aller vers le haut"<<std::endl<<endl;

        ConsoleUtils::setColor(ConsoleUtils::Color::BLACK);
        ConsoleUtils::setBackgroundColor(ConsoleUtils::BackgroundColor::BG_CYAN);
        std::cout << "> 'Fleche de droite' ou D : ";
        ConsoleUtils::resetColors(); std::cout << "  pour aller vers la droite"<<std::endl<<endl;

        ConsoleUtils::setColor(ConsoleUtils::Color::BLACK);
        ConsoleUtils::setBackgroundColor(ConsoleUtils::BackgroundColor::BG_CYAN);
        std::cout << "> 'Fleche du bas' ou S : ";
        ConsoleUtils::resetColors(); std::cout << "  pour aller vers le bas"<<std::endl<<endl;

        ConsoleUtils::setColor(ConsoleUtils::Color::BLACK);
        ConsoleUtils::setBackgroundColor(ConsoleUtils::BackgroundColor::BG_CYAN);
        std::cout << "> 'Fleche de gauche' ou Q : ";
        ConsoleUtils::resetColors(); std::cout << "  pour aller vers la gauche "<<std::endl<<endl<<endl;
        
        detectSpace();

        ConsoleUtils::setColor(ConsoleUtils::Color::BLUE);
        ConsoleUtils::setBackgroundColor(ConsoleUtils::BackgroundColor::BG_YELLOW);
        std::cout << "Pour selectionner une option : ";
        ConsoleUtils::resetColors(); std::cout <<std::endl<<endl;
        
        ConsoleUtils::setColor(ConsoleUtils::Color::CYAN);
        std::cout << "> ";
        ConsoleUtils::resetColors(); std::cout<<"Saisir ton choix ou ce qui t'est demande a l'aide du clavier. Si tu dois valider ton choix, appuie sur la touche 'o'" <<std::endl<<endl;

        ConsoleUtils::setColor(ConsoleUtils::Color::CYAN);
        std::cout << "> ";
        ConsoleUtils::resetColors(); std::cout<<"Appuie sur la touche 'espace' pour revenir au menu principal. Attention, realise en cours de partie, cette action quittera la partie de façon definitive." <<std::endl<<endl;
        

        ConsoleUtils::setColor(ConsoleUtils::Color::BLACK);
        ConsoleUtils::setBackgroundColor(ConsoleUtils::BackgroundColor::BG_CYAN);
        std::cout << "> Si tu ne comprends pas les commandes, adresse toi a Aurore Lafaurie (@_just_kiel_ sur instagram), elle saura te guider ! ";
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
    //TODO detect if darwin (linux + mac) ou windows

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
    std::cout << "Choisis dans le menu :";
    ConsoleUtils::resetColors(); std::cout << std::endl<<endl;

    ConsoleUtils::setColor(ConsoleUtils::Color::BLUE);
    ConsoleUtils::setBackgroundColor(ConsoleUtils::BackgroundColor::BG_YELLOW);
    std::cout << "1.";
    ConsoleUtils::resetColors(); std::cout << " Histoire et Enjeux" <<std::endl<<endl;

    ConsoleUtils::setColor(ConsoleUtils::Color::BLUE);
    ConsoleUtils::setBackgroundColor(ConsoleUtils::BackgroundColor::BG_YELLOW);
    std::cout << "2.";
    ConsoleUtils::resetColors(); std::cout << " Les PokImacs" <<std::endl<<endl;

    ConsoleUtils::setColor(ConsoleUtils::Color::BLUE);
    ConsoleUtils::setBackgroundColor(ConsoleUtils::BackgroundColor::BG_YELLOW);
    std::cout << "3.";
    ConsoleUtils::resetColors(); std::cout << " Les Objets" <<std::endl<<endl;

    ConsoleUtils::setColor(ConsoleUtils::Color::BLUE);
    ConsoleUtils::setBackgroundColor(ConsoleUtils::BackgroundColor::BG_YELLOW);
    std::cout << "4.";
    ConsoleUtils::resetColors(); std::cout << " Combat, capture et fuite" <<std::endl<<endl;

    ConsoleUtils::setColor(ConsoleUtils::Color::BLUE);
    ConsoleUtils::setBackgroundColor(ConsoleUtils::BackgroundColor::BG_YELLOW);
    std::cout << "5.";
    ConsoleUtils::resetColors(); std::cout << " Retour" <<std::endl<<endl;

    cout << "Ton choix : ";
    cin >> choix_utilisateur;

    while(choix_utilisateur<'1' || choix_utilisateur>'5'){
        cout<<"Ce choix n'est pas valide ! Tu dois choisir entre 1 et 5."<<endl;
        cout << "Ton choix : ";
        cin >> choix_utilisateur;
    }

        ConsoleUtils::clear();

        if (choix_utilisateur == '1') {

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
            
        } else if (choix_utilisateur == '2') {
            
            // Les PokIMAC :
            ConsoleUtils::setColor(ConsoleUtils::Color::BLUE);
            ConsoleUtils::setBackgroundColor(ConsoleUtils::BackgroundColor::BG_YELLOW);
            std::cout << "LES POKIMACS";
            ConsoleUtils::resetColors(); std::cout<<std::endl<<endl<<endl;
            
            
            cout<<"Les PokIMACS sont des creatures dotees de pouvoirs extraordinaires, comme la capacite de vous faire parler anglais ou de t'aider a obtenir ton diplome."<<endl
            <<"Ils peuvent se faire capturer par les DressESIPE dans des Pokiballs, des boules creuses rouges, oranges, bleues et vertes qui semblent aspirer la creature :on peut donc transporter ces poKIMACS dans des Pokiballs de la taille d'une pomme. On recense actuellement 5 especes de PokIMAC."<<endl<<endl;
            
            ConsoleUtils::setColor(ConsoleUtils::Color::BLACK);
            ConsoleUtils::setBackgroundColor(ConsoleUtils::BackgroundColor::BG_MAGENTA);
            std::cout << "Consultez le PokESIPE pour acceder a la liste de tous les PokIMACS existants";
            ConsoleUtils::resetColors(); std::cout<<std::endl<<endl<<endl;
            
            detectSpace();
            
            // Liste des PokIMAC:
            ConsoleUtils::setColor(ConsoleUtils::Color::WHITE);
            ConsoleUtils::setBackgroundColor(ConsoleUtils::BackgroundColor::BG_RED);
            std::cout << " ###!!! DISCLAIMER !!!### ";
            ConsoleUtils::resetColors(); std::cout<<std::endl<<endl<<endl;
            
            
            cout<<"Toute ressemblance de PokIMAC avec des professeurs de l'ESIPE - IMAC est parfaitement fortuite."<<endl
                <<"Ce jeu a ete code dans l'innocence et le stress. Il n'a aucunement pour but de denigrer l'integrite de qui que ce soit. Il se veut fun et bienveillant ! "<<endl<<endl;

            detectSpace();

            ConsoleUtils::setColor(ConsoleUtils::Color::BLUE);
            ConsoleUtils::setBackgroundColor(ConsoleUtils::BackgroundColor::BG_YELLOW);
            std::cout << " PokESIPE ";
            ConsoleUtils::resetColors(); std::cout<<std::endl<<endl<<endl;
            

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

            detectSpace();

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

            detectSpace();

            ConsoleUtils::setColor(ConsoleUtils::Color::BLACK);
            ConsoleUtils::setBackgroundColor(ConsoleUtils::BackgroundColor::BG_CYAN);
            std::cout << " Type Mathematiques ";
            ConsoleUtils::resetColors(); std::cout<<std::endl<<endl<<endl;
            
            ConsoleUtils::setColor(ConsoleUtils::Color::CYAN);
            std::cout << " Cible :";
            ConsoleUtils::resetColors(); std::cout<<" Culture"<<std::endl<<endl;
            
            cout<<" - Nocvelli"<<endl
                <<" - Rieulu"<<endl<<endl;

            detectSpace();

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

            detectSpace();

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
            std::cout << "Les PokIMACS de depart";
            ConsoleUtils::resetColors(); std::cout<<" tres souvent appeles par le terme anglais 'starters', sont les premiers PokIMACS a rejoindre ton equipe."<<std::endl<<endl;
            
            
            cout<<"Dans la plupart des cas, tu as le choix entre trois PokIMACS ayant l'un de ces types : Culture, Programmation, Mathematiques, Design et Aide."<<endl
                <<"Ce trio permet d'introduire rapidement au joueur la notion de sensibilite des types avec des concepts familiers : la Culture bat le Design et la Culture craint les Mathematiques par exemple."<<endl;
           

            detectSpace();
            printRegles();

        } else if (choix_utilisateur == '3') {
            
            //objets
            ConsoleUtils::setColor(ConsoleUtils::Color::BLUE);
            ConsoleUtils::setBackgroundColor(ConsoleUtils::BackgroundColor::BG_YELLOW);
            std::cout << "LES OBJETS";
            ConsoleUtils::resetColors(); std::cout<<std::endl<<endl;
            
            cout<<"Les objets font partie de ton inventaire, ton sac a dos d'aventurier ! "<<endl<<"Ils te permettent d'ameliorer ta chasse aux PokIMACs. Lorsque tu utilises un objet, celui-ci disparait apres utilisation."<<endl << endl;

            detectSpace();

            cout<<"            ,gg@@@@@@@@@@Nw,            \n"
                  "        ,g@@@@@RP**\"\"*\"*RB@@@@N,        \n"
                  "      g@@@N\"-               \"N@@@N      \n"
                  "    g@@@P                      \"B@@@    \n"
                  "  ,@@@P                          \"@@@w  \n"
                  " ,@@@            ,,ggg,            $@@g \n"
                  " @@@`         ,@@@@@@@@@@g          $@@ \n"
                  "]@@P         @@@P^     %@@@         ]@@@\n"
                  "@@@ggggggggg@@@P   gg   ]@@@ggggggggg@@@\n"
                  "$@@@BBBBBBBBB@@L  'NN`  ]@@@BBBBBBBBB@@@\n"
                  "]@@P         B@@g      g@@@`        ]@@@\n"
                  " @@@          *@@@@@@@@@@P          @@@P\n"
                  " ]@@@           '\"*PP*\"`           @@@P \n"
                  "  ]@@@p                          ,@@@P  \n"
                  "   '%@@@,                      ,@@@@'   \n"
                  "     \"%@@@g,                ,g@@@@\"     \n"
                  "        \"B@@@@Nwg,,,,,,,gg@@@@@*`       \n"
                  "           \"\"RB@@@@@@@@@@@R*`           \n"
                  "                   --                   \n"
                  ""<<endl;
            
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
            
            cout <<"Voici les differents objets de type 1 : "<<endl <<endl;
            
            cout<<"         ,@@NN@N  ,,                    \n"
                  "      ,,$@-    ]@P*PN@gggg,             \n"
                  "   g@P**B@            T\" '%@            \n"
                  "  ]@P                     ,@P           \n"
                  "  ]@P              ]@@NNNN$@            \n"
                  "  ]@P  gg,,g@@     ]@`    ]@            \n"
                  "  ]@P  @K***-*B@N@@P-     ]@NNNNNB@g    \n"
                  "  '@g ,@P                 ]@       $@   \n"
                  "    P$@` ]@P  @P  @P  @P  ]@@@@N,   @L  \n"
                  "     $@  ]@P  @P  @P  @P  ]@   ]@   @P  \n"
                  "     $@  ]@P  @P  @P  @P  ]@   ]@   @P  \n"
                  "     $@  ]@P  @P  @P  @P  ]@   ]@   @P  \n"
                  "     $@  ]@P  @P  @P  @P  ]@   ]@   @P  \n"
                  "     $@  ]@P  @P  @P  @P  ]@@@@@\"   @P  \n"
                  "     $@   @P  @P  @P  @P  ]@       $@`  \n"
                  "     $@                   ]@ggggg@@P'   \n"
                  "     $@                   $@            \n"
                  "      %@gpppppppppppppppp@@\"            \n"
                  ""<<endl;

            ConsoleUtils::setColor(ConsoleUtils::Color::BLACK);
            ConsoleUtils::setBackgroundColor(ConsoleUtils::BackgroundColor::BG_YELLOW);
            std::cout << "> La Biere";
            ConsoleUtils::resetColors(); std::cout<<" te permet de regenerer ";
            ConsoleUtils::setColor(ConsoleUtils::Color::LIGHTYELLOW);
            std::cout << "5 PV";
            ConsoleUtils::resetColors(); std::cout<<" au PokIMAC de ton choix."<<std::endl<<endl;

            detectSpace();

            cout<<"           ,@@@          @@@@@@@@@P     \n"
                  "     ,@@  /@@@@@p       ]@@             \n"
                  "     ]@P  @@@@@@@       $@@             \n"
                  "                        @@              \n"
                  "    )@BBBBBBBBBBBBBBBBBP``BBBBBBBBBw    \n"
                  "    ]@@@@@@@@@@@@@@@@@@  ]@@@@@@@@@P    \n"
                  "     @@@@@@@@@@@@@@@@@@  @@@@@@@@@@     \n"
                  "     ]@@@@@*\"\"\"\"\"\"\"\"\"\"-  \"\"\"\"%@@@@@     \n"
                  "      @@@@@  gggg      -ggg  ]@@@@P     \n"
                  "      $@@@@  ]@@   &@@   @@  @@@@@      \n"
                  "      ]@@@@P -@@@g     g@@P  @@@@@      \n"
                  "       @@@@@  $@@@@Ngg@@@@  ]@@@@       \n"
                  "       ]@@@@  ]@@@@@@@@@@[  @@@@@       \n"
                  "       ]@@@@P  @@@@@@@@@@P ]@@@@P       \n"
                  "        $@@@@  $@@@@@@@@@  ]@@@@        \n"
                  "        ]@@@@-             @@@@@        \n"
                  "         @@@@@@@@@@@@@@@@@@@@@@P        \n"
                  "         $@@@@@@@@@@@@@@@@@@@@@         \n"
                  ""<<endl;

            ConsoleUtils::setColor(ConsoleUtils::Color::BLACK);
            ConsoleUtils::setBackgroundColor(ConsoleUtils::BackgroundColor::BG_GREEN);
            std::cout << "> Le Mojito";
            ConsoleUtils::resetColors(); std::cout<<" te permet de regenerer ";
            ConsoleUtils::setColor(ConsoleUtils::Color::LIGHTGREEN);
            std::cout << "10 PV";
            ConsoleUtils::resetColors(); std::cout<<" au PokIMAC de ton choix."<<std::endl<<endl;

            detectSpace();

            cout<<"                            @@          \n"
                  "                           g@@   @@     \n"
                  "                     ,gg@@N*\"  ,@@C     \n"
                  "                  g@@*\"-,g@@@NR**       \n"
                  "                 ]@C   @@\"              \n"
                  "                 '    '*                \n"
                  "                                        \n"
                  " @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@        \n"
                  " @@@P    @@@@@@@@@@@@@@@@@@@@@@@gg,     \n"
                  " @@@L    @@@@@@@@@@@@@@@@@@@@@@@B@@@@g  \n"
                  " $@@@    @@@@@@@@@@@@@@@@@@@@@@@  \"@@@@ \n"
                  " ]@@@    @@@@@@@@@@@@@@@@@@@@@@@   ]@@@P\n"
                  " -@@@@   ]@@@@@@@@@@@@@@@@@@@@@   g@@@@ \n"
                  "  ]@@@@  '@@@@@@@@@@@@@@@@@@@@@@@@@@@\"  \n"
                  "   %@@@@g ]@@@@@@@@@@@@@@@@@@@*P\"\"`     \n"
                  "    ]@@@@@N@@@@@@@@@@@@@@@@@P           \n"
                  "     '%@@@@@@@@@@@@@@@@@@@P             \n"
                  " RNB@@@@@@@@@@@@@@@@@@@@@@@@@@NP        \n"
                  ""<<endl;

            ConsoleUtils::setColor(ConsoleUtils::Color::WHITE);
            ConsoleUtils::setBackgroundColor(ConsoleUtils::BackgroundColor::BG_BLUE);
            std::cout << "> Le Chocolat Chaud";
            ConsoleUtils::resetColors(); std::cout<<" te permet de regenerer ";
            ConsoleUtils::setColor(ConsoleUtils::Color::LIGHTBLUE);
            std::cout << "15 PV";
            ConsoleUtils::resetColors(); std::cout<<" au PokIMAC de ton choix."<<std::endl<<endl;
            
            detectSpace();

            cout<<"                  ]@@K                  \n"
                  "               ,gg@@@@gg,               \n"
                  "           g@@@@@@@@@@@@@@@Bg           \n"
                  "        ,@@@@@@@@@@@@@@@@@@@@@@,        \n"
                  "       g@@@@@@@@@@@@@@@@@@@@@@@@@       \n"
                  "      @@@@@@@@@@@@@@@@@@@@@@@@@@@@      \n"
                  "     @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@     \n"
                  "   @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@w  \n"
                  "   ********\"@$*********$@@$@@\"******\"   \n"
                  "           ]@@@      ,@@@@@@P           \n"
                  "           ]@@@     g@@@@@@P            \n"
                  "           @@@@K  g@@@@@@@`             \n"
                  "          @@@@@@@@@@@@@@\"               \n"
                  "         @@@@@@@@@@@@@P                 \n"
                  "      ,g@@@@@@@@@@@@\"                   \n"
                  "     'B@@@@@@@@@@\"                      \n"
                  "       \"B@@@@@\"                         \n"
                  "          %@@P                          \n"
                  ""<<endl;

            ConsoleUtils::setColor(ConsoleUtils::Color::WHITE);
            ConsoleUtils::setBackgroundColor(ConsoleUtils::BackgroundColor::BG_RED);
            std::cout << "> Le Repas Crous";
            ConsoleUtils::resetColors(); std::cout<<" te permet de regenerer ";
            ConsoleUtils::setColor(ConsoleUtils::Color::LIGHTRED);
            std::cout << "20 PV";
            ConsoleUtils::resetColors(); std::cout<<" au PokIMAC de ton choix."<<std::endl<<endl;

            detectSpace();

            cout<<"                                    /@N,\n"
                  "  g@@g                            g@*`\"`\n"
                  " ]NMPMBg,                  ,gg@@@@      \n"
                  "        \"%@@@@Ngggg, |  |y@@@@@@@@,     \n"
                  "       :||@@@@@@@@@@@@@@M**M$@@@@@@@@g  \n"
                  "     !|,,g@@@@@@@@@@@@$` |  `'T\"%@NNB@  \n"
                  "   ||,@@@@@@@@@@@\"\"\"*M@ | ||||'|||||  | \n"
                  " @ ||]@@@@MMM'  | ' | - || ||  ||,gggg@W\n"
                  "]@K||`*B@'  |'`| ||||  ||  ||||,@$$$$@@@\n"
                  "@@@g||   || |||||  -'''|||| |`g@$$$@@@@@\n"
                  "$@@@@,   |||||||'||||||||||,g@$$$@@@@@@@\n"
                  "]@@@@@@@,  |||||||||||||`g@@$$@@@@@@@@@@\n"
                  " $@@@@@@@@@@gggggggggg@$$@@@@@@@@@@@@@@ \n"
                  "  %@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@` \n"
                  "   \"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@P   \n"
                  "     \"B@@@@@@@@@@@@@@@@@@@@@@@@@@@P`    \n"
                  "       `*B@@@@@@@@@@@@@@@@@@@@@P\"       \n"
                  "           \"\"MN@@@@@@@@@@@N*\"           \n"
                  "                   ---                  \n"
                  ""<<endl;

            ConsoleUtils::setColor(ConsoleUtils::Color::BLACK);
            ConsoleUtils::setBackgroundColor(ConsoleUtils::BackgroundColor::BG_CYAN);
            std::cout << "> Le Cassoulet";
            ConsoleUtils::resetColors(); std::cout<<" te permet de regenerer ";
            ConsoleUtils::setColor(ConsoleUtils::Color::LIGHTCYAN);
            std::cout << "25 PV";
            ConsoleUtils::resetColors(); std::cout<<" au PokIMAC de ton choix."<<std::endl<<endl;
            
            detectSpace();

            ConsoleUtils::setColor(ConsoleUtils::Color::MAGENTA);
            std::cout << "Les objets de type 2 te permettent de multiplier la puissance de tes attaques."<<endl<<"Attention, l'objet n'est valable que pour une attaque !";
            ConsoleUtils::resetColors(); std::cout<<std::endl<<endl;

            cout<< "Voici les differents objets de type 2 : "<<endl <<endl;
            
            cout<<"              ,gg@@@@@@gg,              \n"
                  "            g@@@@@@\"\"$@@@@@g            \n"
                  "          g@@@@P\"$@Ng@@\"*@@@@g          \n"
                  "         ]@@@@@Ng@@@@@@gg@@@@@K         \n"
                  "         RRRRRRRRRRRRRRRRRRRRRR         \n"
                  "                                        \n"
                  "         @@@@@@@@@@@@@@@@@@@@@@P        \n"
                  "         @@@@@@@@@@@@@@@@@@@@@@P        \n"
                  "         @@@@@@@@@@@@@@@@@@@@@@P        \n"
                  "         @@@@@@@@@@@@@@@@@@@@@@P        \n"
                  "         @@@@@@@@@@@@@@@@@@@@@@P        \n"
                  "         @@@@@@@@@@@@@@@@@@@@@@P        \n"
                  "         @@@@@@@@@@@@@@@@@@@@@@P        \n"
                  "         @@@@@@@@@@@@@@@@@@@@@@P        \n"
                  "         @@@@@@@@@@@@@@@@@@@@@@P        \n"
                  "         @@@@@@@@@@@@@@@@@@@@@@         \n"
                  ""<<endl;

            ConsoleUtils::setColor(ConsoleUtils::Color::BLACK);
            ConsoleUtils::setBackgroundColor(ConsoleUtils::BackgroundColor::BG_CYAN);
            std::cout << "> Le Sel";
            ConsoleUtils::resetColors(); std::cout<<" augmente ";
            ConsoleUtils::setColor(ConsoleUtils::Color::LIGHTCYAN);
            std::cout << "X2";
            ConsoleUtils::resetColors(); std::cout<<" la puissance de toutes tes attaques."<<std::endl<<endl;
            
            detectSpace();

            cout<<"                   gN                   \n"
                  "                  g@@@                  \n"
                  "      ,            ``            ,      \n"
                  "      ]@@@P   ,,ggB@@BNgg,   9@@@K      \n"
                  "       $P  ,g@@@@@@@@@@@@@@N,  *@       \n"
                  "         ,@@@@@@@@@@@@@@@@@@@@g         \n"
                  "        /@@@@@@@@@@@@@@@@@@@@@@N        \n"
                  "       ]@@@@@@@@@@@@@@@@@@@@@@@@b       \n"
                  " ,g@@  $@@@@@@@@@@@@@@@@@@@@@@@@@  $@g, \n"
                  "`*N@@  $@@@@@@@@@@@@@@@@@@@@@@@@@  ]@N^-\n"
                  "       ]@@@@@@@@@@@@@@@@@@@@@@@@P  -    \n"
                  "        ]@@@@@@@@@@@@@@@@@@@@@@@        \n"
                  "         \"@@@@@@@@@@@@@@@@@@@@P         \n"
                  "       @g  *B@@@@@@@@@@@@@@@P  ,@       \n"
                  "      ]@@@w   \"*NB@@@@@NP\"-  g@@@K      \n"
                  "      *\"                       -`\"      \n"
                  "                  %@@@                  \n"
                  "                   %@                   \n"
                  ""<<endl;

            ConsoleUtils::setColor(ConsoleUtils::Color::BLACK);
            ConsoleUtils::setBackgroundColor(ConsoleUtils::BackgroundColor::BG_YELLOW);
            std::cout << "> Le Weekend";
            ConsoleUtils::resetColors(); std::cout<<" augmente ";
            ConsoleUtils::setColor(ConsoleUtils::Color::LIGHTYELLOW);
            std::cout << "X3";
            ConsoleUtils::resetColors(); std::cout<<" la puissance de toutes tes attaques."<<std::endl<<endl;

            detectSpace();
            
            cout<<"              ,,gg@@@@gg,,              \n"
                  "       ,gg@@@@@@@@@@@@@@@@@@@Npg,       \n"
                  " gg@@@@@@@@@@@@@@@P**PN@@@@@@@@@@@@@Bgg,\n"
                  "$@@@@@@@@@@@@@@@@ *NNP $@@@@@@@@@@@@@@@@\n"
                  " '\"*NB@@@@@@@@NP\"-,gg@@@@@@@@@@@@@@NP\"\" \n"
                  "     gg,`]@` ,g@@@@@@@@@@@@BR**`,,g     \n"
                  "     @@@@@@ ,g, `\"PMMP\"\" ,gg@@@@@@@     \n"
                  "     @@@@@@ ]@@@@@@@@@@@@@@@@@@@@@@     \n"
                  "     @@@@@@ ]@@@@@@@@@@@@@@@@@@@@@@     \n"
                  "     B@@@@@ ]@@@@@@@@@@@@@@@@@@@@@@     \n"
                  "      *B@@@ ]@@@@@@@@@@@@@@@@@@@@P`     \n"
                  "         ]@ 'TPPPRNNNNRPP*\"\"'           \n"
                  "         g@,                            \n"
                  "       j@@@@@                           \n"
                  "       ]@@@@@                           \n"
                  "        B@@@@                           \n"
                  ""<<endl ;

            ConsoleUtils::setColor(ConsoleUtils::Color::BLACK);
            ConsoleUtils::setBackgroundColor(ConsoleUtils::BackgroundColor::BG_GREEN);
            std::cout << "> Le Presentiel";
            ConsoleUtils::resetColors(); std::cout<<" augmente ";
            ConsoleUtils::setColor(ConsoleUtils::Color::LIGHTGREEN);
            std::cout << "X4";
            ConsoleUtils::resetColors(); std::cout<<" la puissance de toutes tes attaques."<<std::endl<<endl;

            detectSpace();
            
            cout<<"                       g@@@,            \n"
                  "                     g@@@@@@@g          \n"
                  "                  ,@@@@P- ]@@@P         \n"
                  "                ,@@@@P    @@@`          \n"
                  "              g@@@@C      $@@@,  ,gg    \n"
                  "            g@@@@\"         *@@@@@@@@@@, \n"
                  "          g@@@P    ,@@@r     `\"\"\"\" \"@@@@\n"
                  "       ,@@@@P-   ,@@@@P           g@@@N\"\n"
                  "     ,@@@@P    g@@@@C          ,g@@@P'  \n"
                  "   g@@@@*     ]@@@\"  ,gg     ,@@@@P     \n"
                  " g@@@@\"         -  g@@@@   ,@@@@*       \n"
                  "$@@@g  ,,,        ]@@@`  g@@@@\"         \n"
                  " *B@@@@@@@@@w          g@@@@`           \n"
                  "   \"NBP\" \"%@@@      ,g@@@P-             \n"
                  "           @@@    ,@@@@P                \n"
                  "          @@@$  ,@@@@*                  \n"
                  "          \"B@@@@@@@\"                    \n"
                  "            *B@@N`                      \n"
                  ""<<endl;

            ConsoleUtils::setColor(ConsoleUtils::Color::WHITE);
            ConsoleUtils::setBackgroundColor(ConsoleUtils::BackgroundColor::BG_RED);
            std::cout << "> Le Billet de Train";
            ConsoleUtils::resetColors(); std::cout<<" augmente ";
            ConsoleUtils::setColor(ConsoleUtils::Color::LIGHTRED);
            std::cout << "X5";
            ConsoleUtils::resetColors(); std::cout<<" la puissance de toutes tes attaques."<<std::endl<<endl;

            detectSpace();

            cout<<"                               @@@@@@@' \n"
                  "                                  @@P   \n"
                  "           ,g@@@@@P`            ,@@C    \n"
                  "       ,g@@@@@@@P              g@@Ngggg \n"
                  "     ,@@@@@@@@@`    ]@@@@@@   '\"\"\"\"\"\"\"\" \n"
                  "   ,@@@@@@@@@@P       .@@P              \n"
                  "  ,@@@@@@@@@@@       ,@@@,,,            \n"
                  "  @@@@@@@@@@@@      7RRRRRRK            \n"
                  " @@@@@@@@@@@@@              gggggw      \n"
                  " @@@@@@@@@@@@@@             **@@@       \n"
                  " @@@@@@@@@@@@@@@            ,@@@@@      \n"
                  " $@@@@@@@@@@@@@@@g          ------      \n"
                  "  @@@@@@@@@@@@@@@@@g,              .    \n"
                  "  ]@@@@@@@@@@@@@@@@@@@@Nwg,,,,gg@@@     \n"
                  "   \"B@@@@@@@@@@@@@@@@@@@@@@@@@@@@P      \n"
                  "     *@@@@@@@@@@@@@@@@@@@@@@@@@P`       \n"
                  "       \"N@@@@@@@@@@@@@@@@@@@@P`         \n"
                  "           \"RB@@@@@@@@@@N*\"             \n"
                  "                  --                    \n"
                  ""<<endl;

            ConsoleUtils::setColor(ConsoleUtils::Color::WHITE);
            ConsoleUtils::setBackgroundColor(ConsoleUtils::BackgroundColor::BG_BLUE);
            std::cout << "> Le Sommeil Reparateur";
            ConsoleUtils::resetColors(); std::cout<<" augmente ";
            ConsoleUtils::setColor(ConsoleUtils::Color::LIGHTBLUE);
            std::cout << "X10";
            ConsoleUtils::resetColors(); std::cout<<" la puissance de toutes tes attaques."<<std::endl<<endl;
            
            detectSpace();
            printRegles();
            
        } else if (choix_utilisateur == '4') {

            //combat, capture, fuite
            ConsoleUtils::setColor(ConsoleUtils::Color::BLUE);
            ConsoleUtils::setBackgroundColor(ConsoleUtils::BackgroundColor::BG_YELLOW);
            std::cout << "COMBAT, CAPTURE ET FUITE";
            ConsoleUtils::resetColors(); std::cout<<std::endl<<endl;
            
            ConsoleUtils::setColor(ConsoleUtils::Color::YELLOW);
            std::cout << "Pour capturer ou combattre des PokIMACS, rends toi dans les hautes herbes ! (#)";
            ConsoleUtils::resetColors(); std::cout<<std::endl<<endl;

            
            ConsoleUtils::setColor(ConsoleUtils::Color::LIGHTBLUE);
            std::cout << "> Combat";
            ConsoleUtils::resetColors(); std::cout<<std::endl<<endl;
            
            cout<<"Selectionne ton attaque et tente de blesser le PokIMAC adverse ! Attention, ce dernier va repliquer ! "<<endl
                <<"Le combat se deroule jusqu'a ce que tu viennes a bout de ton adversaire ou que tu decides de fuir ou de capturer ton ennemi. "<<endl
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
            <<"Tu peux egalement fuire lors d'un combat si ce dernier s'annonce laborieux ou que tu es trop affaibli pour continuer."<<endl;
            
            ConsoleUtils::setColor(ConsoleUtils::Color::LIGHTMAGENTA);
            std::cout << "Malheureusement, a ce rythme la, tu ne risques pas de devenir le plus grand dresseur du Champs...";
            ConsoleUtils::resetColors(); std::cout<<std::endl;
        
            detectSpace();
            printRegles();

        }else{
            
            //Fin du programme > retour au menu instruction

            printSelection();
            
        }
    
}
