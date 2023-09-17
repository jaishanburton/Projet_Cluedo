#ifndef PARTIE_H_INCLUDED
#define PARTIE_H_INCLUDED
#include "headers.h"

class Partie
{
    private:
        /********** Attributs ************/
        int m_nombre;
        std::string m_nomPartie;
        std::string m_sauvegarde;
        int m_tourDeJeu;
        std::vector<Joueur> m_listeJoueur;
    std::vector<Carte> m_pioche;
        std::vector <Carte> m_listeCarte;
        std::vector<Carte> m_enveloppe;
        std::vector<Carte> m_mystere;
    public:
        /********* Consctructeur ***********/
        Partie();
        Partie(std::string nomSauvegarde);
        ~Partie();
        /********* Accesseur ***************/
        int getNombreJoueur()const;
        int getTour()const;
        std::string getNomPartie()const;
        std::string getSauvegarde()const;
        std::vector<Joueur>& getListeJoueur();
        std::vector<Carte> getpioche()const;
        std::vector<Carte> getEnveloppe()const;
        std::vector<Carte> getMystere()const;
        std::vector<Carte>getListeCarte()const;
        void setSauvegarde(std::string nom);
        void setTour();
        /***************************************/

        /************ Methodes ************/
        std::vector<Effectif> CreationForme();
        int nombreJoueurs();
        void afficherJoueur();
        std::vector<Carte>initiliseCarte();
        void afficherCarte(std::vector<Carte>donnee);
                ///Sauvegarde///
        void sauvegarder();
        void sauvegarderCarte(std::string element,std::vector <Carte> liste);
        void sauvegarderJoueur(std::string numero,Joueur j);
                ///Chargement///
        std::vector<Carte> chargerCarte(std::string element);
};

#endif // PARTIE_H_INCLUDED
