#ifndef PION_H_INCLUDED
#define PION_H_INCLUDED
#include "plateau.h"
#include "headers.h"
#include "des.h"

class Pion
{
private:
    /*** Attributs ***/
    int m_posLigne;
    int m_posColonne;
    int m_depLigne;
    int m_depColonne;

    De m_De2;
    De m_De1;
    /******************/

public:
    /*** Constructeur & Destructeur***/
    Pion();
    ~Pion();
    /******************/

    /*** Accesseurs ***/
    int get_POSITIONx()const;
    int get_POSITIONy()const;
    int get_DEPLACEMENTx()const;
    int get_DEPLACEMENTy()const;
    /**********************/

    /*** Méthodes ***/
    int deplacement(Partie &jeu,int numero);
    int passage_secret();



};


#endif // PION_H_INCLUDED
