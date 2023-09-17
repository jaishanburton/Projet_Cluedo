#ifndef PLATEAU_H_INCLUDED
#define PLATEAU_H_INCLUDED
#include "headers.h"
#include "pion.h"
//#include "des.h"

class Plateau
{
private:

    /*** Attribut ***/
    Pion m_jeton;

public:
    /*** Consctructeur & Destucteur***/
    Plateau();
    ~Plateau();
    /*******************************/

    /** Méthodes**/
    int affichage_plateau(Partie &jeu,int numero);
    int menu_pause(Partie jeu);

};


#endif // PLATEAU_H_INCLUDED
