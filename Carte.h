#ifndef CARTE_H_INCLUDED
#define CARTE_H_INCLUDED

#include "headers.h"

class Carte
{
private :
    /*** Attributs ***/
    int m_identifiant;
    std::string m_nom;
    BITMAP* m_image;
    int m_positionX;
    int m_positionY;
    /*****************/
public :
    /*** Constructeur & destructeur ***/
    Carte(int identifiant,std::string nom);
    ~Carte();

    /*** Accesseur ***/
    int getX();
    int getY();
    int getIdentifiant();
    std::string getNom();
    BITMAP* getImage();
    void setX(int positionX);
    void setY(int positionY);
    /*********************/

    /*** Méthodes ***/
    void afficher(BITMAP*doubleBuffer); /// Afficher les cartes
};

#endif // CARTE_H_INCLUDED

