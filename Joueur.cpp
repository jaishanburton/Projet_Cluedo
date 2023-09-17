#include "headers.h"
using namespace std;

Joueur::Joueur(vector<Carte>liste,int num_j)
{
    int i=0,free=0;

    /**** Convertion string en char ****/
    string Name=to_string(num_j);
    Name="images/pion"+Name+".bmp";
    char *image_pion= new char [Name.size()+1];
    strncpy(image_pion,Name.c_str(),Name.size()+1);
    /************************************/

    textprintf_ex(screen,font,SCREEN_W/2,SCREEN_H/2,makecol(255,255,255),-1,"Saisir dans la console...");

    cout<<"Nom :";
    cin>>m_nom;

    m_pion=load_bitmap(image_pion,NULL);
    m_pionX=385;
    m_pionY=475;

    /*** Bitmaps ***/
    BITMAP * imageChargee;
    BITMAP * doubleBuffer;
    /********************/

    imageChargee =load_bitmap("images/maison1.bmp",NULL);
    doubleBuffer=create_bitmap(SCREEN_W,SCREEN_H);

    /*************** Choix du pseudo ****************************/
    while(!mouse_b&1||free==0)
    {
        clear_bitmap(doubleBuffer);
        blit(imageChargee, doubleBuffer, 0, 0, 0, 0, imageChargee->w, imageChargee->h);

        i=0;
        for(auto elem:liste)
        {
            i++;
            elem.setX(180*i-100);
            elem.setY(230);
            elem.afficher(doubleBuffer);
            if((mouse_x>elem.getX())&&(mouse_x<(elem.getX()+elem.getImage()->w))&&(mouse_y>elem.getY())&&(mouse_y<elem.getY()+elem.getImage()->h))
            {
                m_pseudo=elem.getNom();
                free=1;
            }
        }
        blit(doubleBuffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);
    }
    /*********************************************************/
    /**** Destuction des Bitmpas *****/
    destroy_bitmap(imageChargee);
    destroy_bitmap(doubleBuffer);
    clear_bitmap(screen);
    /*********************************/

    cout<<"Pseudo : "<<m_pseudo<<endl;
}
Joueur::Joueur(string nom,vector<Carte>jeu,vector<Carte>donnee,int num_j)
{
    string nomfichier;
    m_donnee=donnee;
    m_jeu=jeu;

    nomfichier="Sauvegardes/"+nom+".txt"; /// Chargement du fichier

    /******** Convertion string en char ********************/
    string Name=to_string(num_j);
    Name="images/pion"+Name+".bmp";
    char *image_pion= new char [Name.size()+1];
    strncpy(image_pion,Name.c_str(),Name.size()+1);
    /********************************************************/

    m_pion=load_bitmap(image_pion,NULL);

    ifstream Flux(nomfichier);
    cout<<nomfichier<<endl;

    if(Flux)
    {
        Flux>>m_nom;
        Flux>>m_pseudo;
        Flux>>m_pionX;
        Flux>>m_pionY;
        cout<<m_nom<<endl;
    }
    else
    {
        cout << "ERREUR: Impossible d'ouvrir le fichier en lecture : "<<nomfichier<< endl;
    }
}
Joueur::~Joueur()
{

}
string Joueur::getPseudo() const /// Retourne le pseudo du joueur
{
    return m_pseudo;
}
string Joueur::getNom()const /// Retourne le nom du joueur
{
    return m_nom;
}
vector<Carte> Joueur::getDonnee()const /// Retourne les informations du joueur
{

    return m_donnee;
}
vector <Carte> Joueur::getJeu()const /// Retourne le jeu du joueur
{
    return m_jeu;
}
void Joueur::setDonnee(Carte ajouter) /// Ajoute une carte dans les infos
{
    m_donnee.push_back(ajouter);

}
void Joueur::setJeu(Carte ajouter) /// Ajoute une carte dans les infos
{
    m_jeu.push_back(ajouter);
}
int Joueur::getPionX()const
{
    return m_pionX;
}
int Joueur::getPionY()const
{
    return m_pionY;
}
void Joueur::setPionX(int x)
{
    m_pionX=x;
}
void Joueur::setPionY(int y)
{
    m_pionY=y;
}
void Joueur::afficherName()
{
    cout<<"Nom : "<<getNom()<<endl;
    cout<<"Pseudo : "<<getPseudo()<<endl;
}

BITMAP* Joueur::getPion()const
{
    return m_pion;
}
