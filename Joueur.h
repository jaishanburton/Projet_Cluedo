#ifndef JOUEUR_H_INCLUDED
#define JOUEUR_H_INCLUDED

#include "headers.h"

class Joueur
{
private :
    /*** Attributs ***/
    std::string m_pseudo;
    std::string m_nom;
    std::vector<Carte>m_donnee;
    std::vector<Carte>m_jeu;
    int m_pionX;
    int m_pionY;
    BITMAP *m_pion;
    /*********************/

public :
    /*** Constructeur & Destructeur ***/
    Joueur(std::vector<Carte>liste,int num_j);
    Joueur(std::string nom,std::vector<Carte>jeu,std::vector<Carte>donnee,int num_j);
    ~Joueur();
    /**********************************/

    /*** Accesseurs ***/
    std::string getPseudo()const;
    std::string getNom()const;
    std::vector<Carte> getDonnee()const;
    std::vector<Carte> getJeu()const;
    int getPionX()const;
    int getPionY()const;
    BITMAP* getPion()const;
    //-----------------------------//
    void setDonnee(Carte ajouter);
    void setJeu(Carte ajouter);
    void setPionX(int x);
    void setPionY(int y);
    /*****************************/

    /*** Méthodes ***/
    void afficherName();
};

#endif // JOUEUR_H_INCLUDED
