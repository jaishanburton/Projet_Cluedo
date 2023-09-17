#ifndef HYPOTHESE_H_INCLUDED
#define HYPOTHESE_H_INCLUDED

#include "headers.h"

class Hypothese
{
private:
    /*** Attributs ***/
    int m_pieceX;
    int m_pieceY;
    std::string m_personnage;
    std::string m_lieu;
    std::string m_arme;
    /******************/
public:
    /*** Constructeur & Destructeur ***/
    Hypothese();
    ~Hypothese();
    /**********************************/
    /*** Accesseur ***/
    int getX();
    int getY();
    std::string getPersonnage();
    std::string getLieu();
    std::string getArme();
    void setX(std::string lieu);
    void setY(std::string lieu);
    void setPersonnage(int personnage);
    void setLieu(int lieu);
    void setArme(int arme);
    /**********************************/
    /*** Méthodes **/
    int verifierH(int pionX,int pionY);     /// Valider de l'hypoythèse
    std::string selectionner(std::vector<Carte>liste);  /// Sélectionner les cartes
    int action();   /// action à faire (Accuser ou soupçonner)
    int hypotheseMenu(Partie &partie,int joueur);   /// Formuler l'hypothèse
    void ecranDeVictoire(std::vector<Carte>card);
    int verifPiece(int pieceX,int pieceY);  /// Valider l'action
    /**********************************/
};
#endif // HYPOTHESE_H_INCLUDED
