//
//  variables.cpp
//  
//
//  Created by Sarah N'GOTTA on 07/12/2021.
//
#include "variables.h"

// Tableau qui rassemble tous les objets

const Objet allObject[nbObjet]={
        {"PokIBALL", "permet de capturer des pokIMACS", 0, "                               ,gg@@@@@@@@@@@@gg,                               \n"
                                                           "                           ,g@@@@NM*\"'`   '\"\"*%%@@@g,                           \n"
                                                           "                         g@@@M|`||'              \"M@@@g                         \n"
                                                           "                       g@@@|||||                    \"%@@b                       \n"
                                                           "                     ,@@@|||||                        '%@@g                     \n"
                                                           "                    g@@M|||||                           j@@N                    \n"
                                                           "                   ]@@M|||||      ,g@@@@@@@@g,           \"@@K                   \n"
                                                           "                   @@@|||||     ,@@@N\"`   \"%$@@,          ]@@C                  \n"
                                                           "                  ]@@L|||||    ;@@@          %@@L         '$@@                  \n"
                                                           "                  $@@@@@@@@@@@@@@@            $@@@@@@@@@@@@@@@                  \n"
                                                           "                  ]@@**********]@@            @@P**********$@@                  \n"
                                                           "                  ]@@           %@@,        ,@@@           @@@                  \n"
                                                           "                   $@@           \"B@@mg,,gg@@@P           ]@@                   \n"
                                                           "                   '@@g             \"MNNNNM\"`            /@@F                   \n"
                                                           "                    '@@@                                g@@C                    \n"
                                                           "                      %@@g                            ,@@@`                     \n"
                                                           "                       \"%@@g                        g@@@\"                       \n"
                                                           "                         '%@@@g,                ,g@@@N`                         \n"
                                                           "                            '*%@@@@mggg,,,ggm@@@@@P`                            \n"
                                                           "                                 \"**NNNNNNNNM*\"                                 \n"
                                                           "", 0.9, 0},
        {"Biere", "permet de regenerer 5 PV au PokIMAC de ton choix", 1, "B", 0.9, 5},
        {"Mojito", "permet de regenerer 10 PV au PokIMAC de ton choix", 1, "M", 0.9, 10},
        {"Chocolat Chaud", "permet de regenerer 15 PV au PokIMAC de ton choix", 1, "CC", 0.9, 15},
        {"Repas Crous", "permet de regenerer 20 PV au PokIMAC de ton choix", 1, "RC", 0.9, 20},
        {"Cassoulet", "permet de regenerer 25 PV au PokIMAC de ton choix", 1, "C", 0.9, 25},
        {"Sel", "augmente x2.0 la puissance de toutes tes attaques - valable 1 fois / combat", 2, "S", 0.9, 2},
        {"Weekend", "augmente x3 la puissance de toutes tes attaques - valable 1 fois / combat", 2, "WK", 0.9, 3},
        {"Presentiel", "augmente x4 la puissance de toutes tes attaques - valable 1 fois / combat", 2, "PR", 0.9, 4},
        {"Billet de Train", "augmente x5 la puissance de toutes tes attaques - valable 1 fois / combat", 2, "BT", 0.9, 5},
        {"Sommeil Reparateur", "augmente x10 la puissance de toutes tes attaques - valable 1 fois / combat", 2, "SR", 0.9, 10}
};

// Tableau vide qui va se remplir avec les objets au fur et a mesure du jeu

Objet vide={"", "",0,"",0, 0};


// Tableau qui rassemble tous les pokimacs

const Pokimac allPokimac[nbPokIMAC]= {
        {"Robbizarre", "Culture","                                       ,.~~.,                                   \n"
                                 "                                  ,,g@g@@@@gggg,                                \n"
                                 "                              ,,ggg@$@@@@@$$@@@@@g,                             \n"
                                 "                           ,g@@@@@@@@@@@@@@@@@@@@@@@m,                          \n"
                                 "                        +'g@@@@NMMM%@@@@@@@@@@@@@@@@@@@,                        \n"
                                 "                      ,g@@@@@'     'j%%%%@@@@@@@@@@@@@@@g                       \n"
                                 "                     ,@@$@@`          ''*M%%@@@@@@@@@@@@@@                      \n"
                                 "                    .@$@@@                 ''**M%@@@@@@@@@@w                    \n"
                                 "                    @@@@$L                      ''*%%@@@@@@@                    \n"
                                 "                    ]%%$@                ,,,,,,    ||%@@@@@@                    \n"
                                 "                     M#@L  ,wg@@gL    ;$@@MMMM$MM,  |j@@@@@@w                   \n"
                                 "                     ]#@  |\"ll**$@L   j%$$N@@@g@L|   |$@@@@@C                   \n"
                                 "                      %@   $m*@@FL'   'L'.,|||!'*'   |%@@@@$[                   \n"
                                 "                       %     |;WL        ''`         j$@@%@l|                   \n"
                                 "                       ]L     '                      |%@@@|'F                   \n"
                                 "                       ]@                L,           '%|LL.                    \n"
                                 "                        \"       l%wg@g%MM               ` '                     \n"
                                 "                                  \"''''                 ygL                     \n"
                                 "                          |           ,,,,,,w           @@                      \n"
                                 "                               '\"*\"\"\"\"\"' `     ,|    ||j@                       \n"
                                 "                           '        ,,,,          ||;lLj@%                      \n"
                                 "                            '|       '`         |y$$MTL \"L                      \n"
                                 "                              \"             ,;yy@@$T|'  @@w                     \n"
                                 "                                 ,,,,,,,,ygg@@@@@M'     ]@@@@,                  \n"
                                 "                             g@@L|j%@@@@@@@@%MMT'      |j@@@@@@                 \n"
                                 "",
                                 80, {{"Perspective", 10}, {"Exposition", 5}}},
        //TODO Visuel Vincent Steeve
        {"Nosteevrapti", "Programmation","N" , 50, {{"TP", 8}, {"C++", 12}}},

        {"Ozlameche", "Culture", "                                         ,,,,,,                                 \n"
                                 "                               ,,,gggg@@@$@@@@@@@@g,                            \n"
                                 "                           ,@@$@@@@@@@@@@@@@@@@@@$%@@g,                         \n"
                                 "                         g@@@@@@@@@@@@@@@@@@@@@@@@@@$@$@,                       \n"
                                 "                       ,@$@@@@@@@@@@@@@@@@@@@@@@@@@@@@@$$b                      \n"
                                 "                      /@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@$@L                    \n"
                                 "                     ]$@@@@@MMMMMM%@@@@@@@@@@@@@@@@@@@@@@@$@g                   \n"
                                 "                    ,$@@@@ML`    '''\"%@@@@@$@$%@@@@@@@@@@@@@@m                  \n"
                                 "                    $@@@@F           '\"%@@@@@$g%$@@@@@@@@@@@@@L                 \n"
                                 "                   $$@@@$L              '*%@@@@@@$@@@@@@@@@@@@@                 \n"
                                 "                  .$$@@@L                  \"%@`\"MT|%@@@@@@@@@@@@                \n"
                                 "                  ]#@$@@T                     \"%,  ']@@@@@@@@@@@K               \n"
                                 "                  $$@@@@L ,aM*Mmg,           ,gm*MM*w]@@@@@@@@@@@               \n"
                                 "                  $$@@@T||   ,,ggw,'+        |ggg, x '%@@@@@@@@@@               \n"
                                 "                  %@@@@L   |#F\"kmF''        % ]@@\"%g' j$@@@@@@@@@               \n"
                                 "                  ]@@@@L   ''*L\"'            '<  *''  '$@@@@@@@@@               \n"
                                 "                   '%@%L                               j@@@@@@@@F               \n"
                                 "                     M$T                               j%@@@@@F                 \n"
                                 "                      ]@           ,                   j%@@@@                   \n"
                                 "                     \"M$l          ',,,,,,,,           j$@@*                    \n"
                                 "                         |           `'\"'`            |                         \n"
                                 "                         Y|      ,,,,,, ,,,,,,        `                         \n"
                                 "                          %|      '*|'\"\"\"'''                                    \n"
                                 "                           l  L     `''''                                       \n"
                                 "                            ', ,               ,    L                           \n"
                                 "                           |  '|iL,,        ,| '                                \n"
                                 "                                ''lllWyWL||'''                                  \n"
                                 "                          ]     '    `''`                                       \n"
                                 "                       ,,y                          g,                          \n"
                                 "", 70, {{"Expose", 20}, {"In english please", 6}}},
        // TODO Visuel Sonia Mendes
        {"Soniafee", "Aide", "S", 100, {{"Emploi du temps", 4}, {"Cle", 8}}},
        // TODO Visuel Eric Laporte
        {"Laporteille", "Programmation", "L", 80, {{"Video", 8}, {"Pointeur", 12}}},
        // TODO Visuel Jean-Christophe Novelli
        {"Nocvelli", "Mathematiques", "N", 120, {{"Integration", 25}, {"Contre-intuition", 20}}},
        // TODO Visuel Alexandre Rieu
        {"Rieulu", "Mathematiques", "R", 140, {{"TD", 10}, {"Explications", 8}}},
        // TODO Visuel Alice Bernard Gairard
        {"Gairrarlande", "Culture", "G", 70, {{"Culture", 15}, {"Controles", 17}}},
        // TODO Visuel Gaelle Charpentier
        {"Charpenti", "Programmation", "C", 80, {{"CSS", 9}, {"Twitter", 5}}},
        // TODO Visuel Enguerrand De Smet
        {"Enguerratueur", "Aide", "E", 100, {{"Photo", 5}, {"Diplome", 8}}},
        // TODO Visuel Théo Gautier
        {"Gautiplouf", "Design", "G", 50, {{"Pixel Art", 12}, {"JeudIMAC", 14}}},

        {"Cherripant", "Aide", "                     g$@$@@$$$m&&@@$@@$@$%@$@@@$$@@$$@$@$@                      \n"
                               "                   g$@$$@$@@@@@@@@@@@@@@@$$$$@@$@@@@g@%@$jI,                    \n"
                               "                  @$@$@@@@@@$@@@@@@%@MMMM$$$%@$%@@$@@@$@$@'L                    \n"
                               "                ,@@$$@@@$@@@@@MM**\"''   '''*T%M%@$%@@@@@@lMk                    \n"
                               "                @@M@@@@@@@@@M||              ''||lM%@@$$l%g\"}w                  \n"
                               "               ]$@@@@@@@@MTL' `                 '|lljlM&@\"L&  `                 \n"
                               "               $@@@@@@@MT' `                        |lllL\"M,mg,,'               \n"
                               "              #@@@@@@@$L'                            ||ll,   `$\"\\               \n"
                               "             ]@@@@@@@$@L                              ''lM   ]gU'               \n"
                               "             @@@@@@@@@@L                                'L   ]F}                \n"
                               "            @@$@@@@@@@@L    ,                    ,,y,,gy ' ] #C,                \n"
                               "           ]%%$@@@@@@@T||,;g@@@@@gggyg,,     ;y@@@@@@@&$L,  FM $@               \n"
                               "           []@@@@@@@$@L ||lM$$M@RNM%&%@L    l@MM\"%ggL|%@L{  M{ ]$F              \n"
                               "             #@@@@@@@$|  '~jM\"|'** jW|lL    |$!||'''' , ''  |   j$              \n"
                               "             @R@@@@@@@L  \"''      |||''      ji'!''|  '      y,  ]|             \n"
                               "            ]@%@@@@@%$L       ''  '           |lL            @QL  u             \n"
                               "            ]@@@@L'} '|                       'lw,          ]|lOgg              \n"
                               "            ]$@@@   ` ||           ,|L       ,  \"jL,        !',,%F'             \n"
                               "            ]Q@$%@    |`          ;'|L, ,,   ,L,,lLML,||    % '*'               \n"
                               "             ` \"%*%@gg@|       ;g||' |'|||@WWg@M$iMlLj||                        \n"
                               "                 ` '%MNrL| |  jlw|| ~' '''\"'' ',||l$&ML|`                       \n"
                               "                     \",$ ||'|' l|'\"*M%*F****\"\"']{MM{||||                        \n"
                               "                     ,j@ L|L|| '|    '  `'''\"||L 'l|lLy' ,-                     \n"
                               "                    /]@@L}L|L|lL    |+,;~;=w|;;Li !||l`r,%@wg,,~                \n"
                               "                  ~^jMM%F ||||Ll||'  ||l|||'|lll$W;|F {,l, \"**=                 \n"
                               "                 ,-`  `,   |'lL||lL||'''   '''|L 'W`   \"\"~                      \n"
                               "                       |    '|lll|ll,||| :|lL||L i`                             \n"
                               "                      |       'llli$@g||il$$lllg$, `                            \n"
                               "                   ,w'         ||||lj$$$$%%M%&$M$                               \n"
                               "                 g@`            '''!||lT|||||llLL   ]Wl$@@gg,,,                 \n"
                               "", 150, {{"Mooh la vache", 12}, {"24/24 7/7", 25}}},
        // TODO Visuel Noémie Chataigner
        {"Chataiglam", "Design", "C", 90, {{"Repertoire", 9}, {"Croquis", 16}}}
};

// Tableau vide qui va se remplir avec les PokIMACS au fur et a mesure du jeu

const Pokimac videPokimac={"", "", "", 0, {{"", 0}, {"", 0}}};