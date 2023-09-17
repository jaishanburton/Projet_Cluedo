#ifndef EFFECTIF_H_INCLUDED
#define EFFECTIF_H_INCLUDED

#include "headers.h"

class Effectif
{
private :
    /*** Attributs ***/
    int m_positionX;
    int m_positionY;
    int m_tailleX;
    int m_tailleY;
    int m_couleur;
    int m_texteX;
    int m_texteY;
    int m_nombre;
    /*****************/
public :
    /*** Constructeur & destructeur ***/
    Effectif(int positionY,int texteY,int nombre);
    ~Effectif();
    /***********************************/

    /*** Accesseur ***/
    int getPositionX();
    int getPositionY();
    int getTailleX();
    int getTailleY();
    int getCouleur();
    int getTexteX();
    int getTexteY();
    int getNombre();
    /***********************************/

    /*** Méthodes ***/
    void afficher(BITMAP * doubleBuffer);
    void setCouleur(int couleur);
};

#endif // EFFECTIF_H_INCLUDED
