//
// Created by Aurore on 07/12/2021.
//

#include <iostream>
using namespace std;
#include "menu.h"
#include "main.h"
#include "hello.hpp"
#include "variables.h"
#include <stdlib.h>
#include <time.h>

int main(){
    //graine de l'aléatoire avec temps de l'ordi
    srand(time(0));

    //Lancement du programme
    printHello();
    printMenu();
    free(map);
    return 0;
}
