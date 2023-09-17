#include "headers.h"
using namespace std;
Partie::Partie()
{
    int carte,arme,personnage,lieu,ajout,it=0;
    vector<Carte>listePersonnage;

    textprintf_ex(screen,font,SCREEN_W/2,SCREEN_H/2,makecol(255,255,255),-1,"Saisir dans la console...");
    cout<<"Nom de la partie : ";
    cin>>m_nomPartie;

    m_nombre=nombreJoueurs();
    m_tourDeJeu=0;

    rest(1000);

    cout<<"Nombre de joueur : "<<m_nombre<<endl;

    /*** Initilisation des cartes ***/
    m_pioche=initiliseCarte();
    m_listeCarte=m_pioche;
    /********************************/

    for(auto elem:m_listeCarte)
    {
        if(elem.getIdentifiant()<20)
        {
            listePersonnage.push_back(elem);
        }
    }

    /*** Carte de l'envelope (crime) ***/
    arme=rand()%(6);
    personnage=rand()%(11-6+1)+6;
    lieu=rand()%(20-12+1)+12;

    m_enveloppe.push_back(m_pioche[personnage]);
    m_enveloppe.push_back(m_pioche[arme]);
    m_enveloppe.push_back(m_pioche[lieu]);
    /*******************************/

    /*** Pioche (carte restante)****/
    m_pioche.erase(m_pioche.begin()+arme);
    m_pioche.erase(m_pioche.begin()+personnage-1);
    m_pioche.erase(m_pioche.begin()+lieu-2);
    /********************************/

    carte=m_pioche.size()/m_nombre;

    /************** Creation des joueurs ***********************/
    for(int i=0; i<m_nombre; i++)
    {
        cout<<"**** Joueur "<<i+1<<" ****"<<endl;
        Joueur ji(listePersonnage,i);
        it=0;

        for(auto elem:listePersonnage)
        {
            if(ji.getPseudo()==elem.getNom())
                listePersonnage.erase(listePersonnage.begin()+it);
            it++;
        }
        m_listeJoueur.push_back(ji);
        /***** Remplissage jeu du joueurs ****/
        for(int j=0; j<carte; j++)
        {
            ajout=rand()%(m_pioche.size());
            m_listeJoueur[i].setJeu(m_pioche[ajout]);
            m_pioche.erase(m_pioche.begin()+ajout);
        }
        /*************************************/
    }
    /***********************************************************************/
}
Partie::Partie(std::string nomSauvegarde)
{
    string nomfichier,convertion;
    vector<Carte>jeu,donnee;

    nomfichier="Sauvegardes/"+nomSauvegarde+".txt";
    m_sauvegarde=nomSauvegarde;

    ifstream Flux(nomfichier);

    if(Flux)
    {
        Flux>>m_nombre;
        Flux>>m_nomPartie;
        Flux>>m_tourDeJeu;
    }
    else
    {
        cout << "ERREUR: Impossible d'ouvrir le fichier : "<<nomfichier<< endl;
    }
    for(int i=0; i<getNombreJoueur(); i++)
    {
        convertion=to_string(i);
        jeu=chargerCarte("Joueur_"+convertion+"_jeu");
        donnee=chargerCarte("Joueur_"+convertion+"_donnee");
        Joueur ji(nomSauvegarde+"_Joueur_"+convertion,jeu,donnee,i);
        m_listeJoueur.push_back(ji);
    }
    m_pioche=chargerCarte("pioche");
    m_listeCarte=chargerCarte("listeCarte");
    m_enveloppe=chargerCarte("enveloppe");
}
Partie::~Partie()
{

}
int Partie::getNombreJoueur()const
{
    return m_nombre;
}
string Partie::getNomPartie()const
{
    return m_nomPartie;
}
vector <Joueur>&Partie::getListeJoueur()
{
    return m_listeJoueur;
}
vector<Carte> Partie::getpioche()const
{
    return m_pioche;
}
vector<Carte> Partie::getEnveloppe()const
{
    return m_enveloppe;
}
vector <Carte>Partie::getMystere()const
{
    return m_mystere;
}
std::vector<Carte>Partie::getListeCarte()const
{
    return m_listeCarte;
}
void Partie::afficherJoueur()
{

}
vector<Effectif>Partie::CreationForme()
{
    vector<Effectif>affichage;

    /// Creation des objets
    Effectif f1(230,250,2);
    Effectif f2(280,300,3);
    Effectif f3(330,350,4);
    Effectif f4(380,400,5);
    Effectif f5(430,450,6);

    /// Ajouts au vecteur
    affichage.push_back(f1);
    affichage.push_back(f2);
    affichage.push_back(f3);
    affichage.push_back(f4);
    affichage.push_back(f5);

    /// Retourne le vecteur
    return affichage;
}
int Partie::nombreJoueurs()
{
    ///Bitmaps
    BITMAP * imageChargee;
    BITMAP * doubleBuffer;
    BITMAP * image;
    ///declaration de variables
    vector <Effectif>effectif;
    int joueurs=0;

    ///chargement des images
    imageChargee =load_bitmap("images/maison1.bmp",NULL);
    image=load_bitmap("images/nombreJoueurs1.bmp",NULL);
    doubleBuffer=create_bitmap(SCREEN_W,SCREEN_H);

    effectif=CreationForme();

    /// boucle événements
    while (!mouse_b&1||(mouse_x<effectif[0].getPositionX())||(mouse_x>(effectif[0].getPositionX()+effectif[0].getTailleX()))||mouse_y<effectif[0].getPositionY()||mouse_y>effectif[4].getPositionY()+effectif[4].getTailleY())
    {
        clear_bitmap(doubleBuffer);
        ///affichage des images chargées
        blit(imageChargee, doubleBuffer, 0, 0, 0, 0, imageChargee->w, imageChargee->h);
        blit(image, doubleBuffer, 0, 0,200, 230, image->w, image->h);
        /// affichage des formes
        for(auto elem:effectif)
        {
            elem.afficher(doubleBuffer);
            if(elem.getCouleur()==makecol(255,0,0))
                joueurs=elem.getNombre();
            textprintf_ex(doubleBuffer,font,elem.getTexteX(),elem.getTexteY(),makecol(0,0,0),-1,"%d Joueurs ",elem.getNombre());
        }
        /// affichage du double buffer
        blit(doubleBuffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);
    }
    /// Destruction des bitmaps
    destroy_bitmap(imageChargee);
    destroy_bitmap(doubleBuffer);
    destroy_bitmap(image);
    clear_bitmap(screen);

    return joueurs;
}
vector<Carte> Partie::initiliseCarte()
{
    vector<Carte>pioche;
    /// Initilisation des cartes

    /// Armes
    Carte A1(20,"chandelier");
    pioche.push_back(A1);
    A1.~Carte();

    Carte A2(21,"revolver");
    pioche.push_back(A2);
    A2.~Carte();

    Carte A3(22,"barredefer");
    pioche.push_back(A3);
    A3.~Carte();

    Carte A4(23,"corde");
    pioche.push_back(A4);
    A4.~Carte();

    Carte A5(24,"poignard");
    pioche.push_back(A5);
    A5.~Carte();

    Carte A6(25,"clefanglaise");
    pioche.push_back(A6);
    A6.~Carte();

    /// Personnage
    Carte P1(10,"professeur");
    pioche.push_back(P1);

    Carte P2(11,"tokyo");
    pioche.push_back(P2);

    Carte P3(12,"berlin");
    pioche.push_back(P3);

    Carte P4(14,"denver");
    pioche.push_back(P4);

    Carte P5(15,"rio");
    pioche.push_back(P5);

    Carte P6(13,"nairobi");
    pioche.push_back(P6);

    /// Lieu
    Carte L1(30,"billard");
    pioche.push_back(L1);

    Carte L2(31,"bureau");
    pioche.push_back(L2);

    Carte L3(32,"bal");
    pioche.push_back(L3);

    Carte L4(33,"cuisine");
    pioche.push_back(L4);

    Carte L5(34,"library");
    pioche.push_back(L5);

    Carte L6(35,"veranda");
    pioche.push_back(L6);

    Carte L7(36,"salleManger");
    pioche.push_back(L7);

    Carte L8(37,"hall");
    pioche.push_back(L8);

    Carte L9(38,"salon");
    pioche.push_back(L9);
    return pioche;
}
void Partie::afficherCarte(vector<Carte> donnee)
{
    int i=0;
    ///Bitmaps
    BITMAP * imageChargee;
    BITMAP * doubleBuffer;
    ///chargement des images
    imageChargee =load_bitmap("images/maison1.bmp",NULL);
    doubleBuffer=create_bitmap(SCREEN_W,SCREEN_H);
    rest(1000);
    while(!mouse_b&1)
    {
        clear_bitmap(doubleBuffer);
        blit(imageChargee, doubleBuffer, 0, 0, 0, 0, imageChargee->w, imageChargee->h);
        i=0;
        for(auto elem:donnee)
        {
            if(elem.getIdentifiant()<20)
            {
                i++;
                elem.setX(i*180-100);
                elem.setY(180);
                elem.afficher(doubleBuffer);
            }
        }
        i=0;
        for(auto elem:donnee)
        {
            if(elem.getIdentifiant()>19&&elem.getIdentifiant()<30)
            {
                i++;
                elem.setX(i*180-100);
                elem.setY(320);
                elem.afficher(doubleBuffer);
            }
        }
        i=0;
        for(auto elem:donnee)
        {
            if(elem.getIdentifiant()>29)
            {
                elem.setX(i*150+10);
                elem.setY(450);
                elem.afficher(doubleBuffer);
                i++;
            }
        }
        blit(doubleBuffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);
    }
    clear_bitmap(screen);
    destroy_bitmap(imageChargee);
    destroy_bitmap(doubleBuffer);
}
int Partie::getTour()const
{
    return m_tourDeJeu;
}
void Partie::setTour()
{
    m_tourDeJeu++;
    if(m_tourDeJeu>=getNombreJoueur())
        m_tourDeJeu=0;
}
string Partie::getSauvegarde()const
{
    return m_sauvegarde;
}
void Partie::setSauvegarde(string nom)
{
    m_sauvegarde=nom;
}
void Partie::sauvegarder()
{
    string nomfichier,nom,convertion;

    cout<<"Nom de la sauvegarde : ";
    cin>>nom;
    setSauvegarde(nom);
    nomfichier="Sauvegardes/"+getSauvegarde()+".txt";

    string const nomFichier(nomfichier);
    ofstream Flux(nomFichier.c_str());

    if(Flux)
    {
        Flux <<getNombreJoueur()<< endl;
        Flux <<getNomPartie()<< endl;
        Flux <<getTour()<<endl;
    }
    else
    {
        cout << "ERREUR: Impossible d'ouvrir le fichier : "<<nomfichier<< endl;
    }
    sauvegarderCarte("listeCarte",getListeCarte());
    sauvegarderCarte("enveloppe",getEnveloppe());
    sauvegarderCarte("pioche",getpioche());
    /***********************************/
    for(int i=0; i<getNombreJoueur(); i++)
    {
        convertion=to_string(i);
        sauvegarderJoueur(convertion,getListeJoueur()[i]);
    }
    /***********************************/
    cout<<"La partie a ete sauvegarde : "<<endl;;
}
void Partie::sauvegarderCarte(string element,vector <Carte> liste)
{
    string nomfichier;
    nomfichier="Sauvegardes/"+getSauvegarde()+"_"+element+".txt";

    string const nomFichier(nomfichier);
    ofstream Flux(nomFichier.c_str());
    for(auto elem:liste)
    {
        if(Flux)
        {
            Flux <<elem.getNom()<< endl;
            Flux <<elem.getIdentifiant()<< endl;
        }
        else
        {
            cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;
        }

    }

}
void Partie::sauvegarderJoueur(string numero,Joueur j)
{
    string nomfichier;
    nomfichier="Sauvegardes/"+getSauvegarde()+"_Joueur_"+numero+".txt";

    string const nomFichier(nomfichier);
    ofstream Flux(nomFichier.c_str());
    if(Flux)
    {
        Flux <<j.getNom()<< endl;
        Flux <<j.getPseudo()<< endl;
        Flux <<j.getPionX()<< endl;
        Flux <<j.getPionY()<< endl;
    }
    else
    {
        cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;
    }
    sauvegarderCarte("Joueur_"+numero+"_jeu",j.getJeu());
    sauvegarderCarte("Joueur_"+numero+"_donnee",j.getDonnee());
}
std::vector<Carte>Partie::chargerCarte(string element)
{
    vector<Carte>liste;
    string nomfichier,nom,ligne;
    int identifiant;
    nomfichier="Sauvegardes/"+getSauvegarde()+"_"+element+".txt";

    ifstream Flux(nomfichier);
    if(Flux)
    {
        while(Flux)
        {
            Flux>>nom;
            Flux>>identifiant;
            Carte c1(identifiant,nom);
            liste.push_back(c1);
        }
        liste.pop_back();
    }
    else
    {
        cout << "ERREUR: Impossible d'ouvrir le fichier : "<<nomfichier<< endl;
    }
    return liste;
}
