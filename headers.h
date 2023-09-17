#ifndef HEADERS_H_INCLUDED
#define HEADERS_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include<allegro.h>
#include <fstream>
#include <cstring>

#include "Carte.h"
#include "Joueur.h"
#include "Effectif.h"
#include "Partie.h"
#include "Hypothese.h"

#include "plateau.h"
#include "time.h"
#include "pion.h"

class Deroulement
{

public:

    /** Constructeur **/
    Deroulement();
    ~Deroulement();
    /******************/

    /*** Méthodes ***/
    void initilisationAllegro();
    void choix();
    int new_menu();
    void aide();
    void echap();
    void deroule(Partie jeu); /// Tour de jeu
    /******************/
};


#endif // HEADERS_H_INCLUDED
