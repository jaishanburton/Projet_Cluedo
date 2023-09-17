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
    /*** M�thodes **/
    int verifierH(int pionX,int pionY);     /// Valider de l'hypoyth�se
    std::string selectionner(std::vector<Carte>liste);  /// S�lectionner les cartes
    int action();   /// action � faire (Accuser ou soup�onner)
    int hypotheseMenu(Partie &partie,int joueur);   /// Formuler l'hypoth�se
    void ecranDeVictoire(std::vector<Carte>card);
    int verifPiece(int pieceX,int pieceY);  /// Valider l'action
    /**********************************/
};
#endif // HYPOTHESE_H_INCLUDED
