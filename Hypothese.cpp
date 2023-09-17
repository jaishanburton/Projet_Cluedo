#include "headers.h"

using namespace std;

Hypothese::Hypothese()
{
}
Hypothese::~Hypothese()
{

}
int Hypothese::getX()
{
    return m_pieceX;
}
void Hypothese::setX(string lieu)
{
    if(lieu=="salon")
    {
        m_pieceX=175;
    }
    else if(lieu=="cuisine")
    {
        m_pieceX=185;
    }
    else if(lieu=="salleManger")
    {
        m_pieceX=135;
    }
    else if(lieu=="hall")
    {
        m_pieceX=385;
    }
    else if(lieu=="library")
    {
        m_pieceX=385;
    }
    else if(lieu=="bureau")
    {
        m_pieceX=585;
    }
    else if(lieu=="billard")
    {
        m_pieceX=585;
    }
    else if(lieu=="veranda")
    {
        m_pieceX=635;
    }
    else
    {
        m_pieceX=385;
    }
}
int Hypothese::getY()
{
    return m_pieceY;
}
void Hypothese::setY(string lieu)
{
    if(lieu=="salon")
    {
        m_pieceY=575;
    }
    else if(lieu=="cuisine")
    {
        m_pieceY=375;
    }
    else if(lieu=="salleManger")
    {
        m_pieceY=225;
    }
    else if(lieu=="hall")
    {
        m_pieceY=525;
    }
    else if(lieu=="library")
    {
        m_pieceY=175;
    }
    else if(lieu=="bureau")
    {
        m_pieceY=125;
    }
    else if(lieu=="billard")
    {
        m_pieceY=325;
    }
    else if(lieu=="veranda")
    {
        m_pieceY=525;
    }
    else
    {
        m_pieceY=275;
    }
}
string Hypothese::getArme()
{
    return m_arme;
}
string Hypothese::getLieu()
{
    return m_lieu;
}
string Hypothese::getPersonnage()
{
    return m_personnage;
}
int Hypothese::verifierH(int pionX,int pionY)
{
    if(getX()==pionX&&getY()==pionY)
        return 1;
    else
        return 0;
}
string Hypothese::selectionner(vector<Carte>liste)
{
    ///Variables
    int i=0,free=0;
    string nom;

    /*** Bitmaps ***/
    BITMAP * imageChargee;
    BITMAP * doubleBuffer;
    /*********************/

    /****************** chargement des images ****************/
    imageChargee =load_bitmap("images/maison1.bmp",NULL);
    doubleBuffer=create_bitmap(SCREEN_W,SCREEN_H);
    /*********************************************************/
    rest(1000);

    /************************** Sélection de l'image *************************************/
    while(!mouse_b&1||free==0)
    {
        clear_bitmap(doubleBuffer);
        blit(imageChargee, doubleBuffer, 0, 0, 0, 0, imageChargee->w, imageChargee->h);

        i=0;
        for(auto elem:liste)
        {
            i++;
            elem.setX(120*i-10);
            elem.setY(SCREEN_H/2);
            elem.afficher(doubleBuffer);
            if((mouse_x>elem.getX())&&(mouse_x<(elem.getX()+elem.getImage()->w))&&(mouse_y>elem.getY())&&(mouse_y<elem.getY()+elem.getImage()->h))
            {
                nom=elem.getNom();
                free=1;
            }
        }
        blit(doubleBuffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);
    }
    /****************************************************************************************/

    /*** Destruction des bitmaps***/
    destroy_bitmap(imageChargee);
    destroy_bitmap(doubleBuffer);
    clear_bitmap(screen);
    /*******************************/
    return nom;
}
int Hypothese::action()
{
    ///Variables
    int choix=0;

    /** Bitmaps **/
    BITMAP * imageChargee;
    BITMAP * doubleBuffer;
    BITMAP * accuser;
    BITMAP * soupconner;
    BITMAP * accuser_1;
    BITMAP * soupconner_1;
    /*******************/

    /*********chargement des images *********************/
    imageChargee =load_bitmap("images/maison1.bmp",NULL);
    accuser=load_bitmap("images/accuser_noir.bmp",NULL);
    soupconner=load_bitmap("images/soupconner_noir.bmp",NULL);
    accuser_1=load_bitmap("images/accuser_rouge.bmp",NULL);
    soupconner_1=load_bitmap("images/soupconner_rouge.bmp",NULL);
    /******************************************************/

    /// Creation double buffer
    doubleBuffer=create_bitmap(SCREEN_W,SCREEN_H);

    rest(1000);

    /************************** Choix de l'action ***********************************************/
    while((!mouse_b&1)||(choix==0))
    {
        clear_bitmap(doubleBuffer); /// Affiche double buffer

        blit(imageChargee, doubleBuffer, 0, 0, 0, 0, imageChargee->w, imageChargee->h);

        if((mouse_y>SCREEN_H/2)&&(mouse_y<SCREEN_H/2+accuser->h))
        {
            if((mouse_x>SCREEN_W/4)&&(mouse_x<SCREEN_W/4+accuser->w))
            {
                blit(accuser_1, doubleBuffer, 0, 0,SCREEN_W/4, SCREEN_H/2, accuser->w, accuser->h);
                blit(soupconner, doubleBuffer, 0, 0,3*SCREEN_W/4-soupconner->w, SCREEN_H/2, soupconner->w, soupconner->h);
                choix=1;
            }
            else if((mouse_x>3*SCREEN_W/4-soupconner->w)&&(mouse_x<3*SCREEN_W/4))
            {
                blit(accuser, doubleBuffer, 0, 0,SCREEN_W/4, SCREEN_H/2, accuser->w, accuser->h);
                blit(soupconner_1, doubleBuffer, 0, 0,3*SCREEN_W/4-soupconner->w, SCREEN_H/2, soupconner->w, soupconner->h);
                choix=2;
            }
            else
            {
                blit(accuser, doubleBuffer, 0, 0,SCREEN_W/4, SCREEN_H/2, accuser->w, accuser->h);
                blit(soupconner, doubleBuffer, 0, 0,3*SCREEN_W/4-soupconner->w, SCREEN_H/2, soupconner->w, soupconner->h);
                choix=0;
            }

        }
        else
        {
            blit(accuser, doubleBuffer, 0, 0,SCREEN_W/4, SCREEN_H/2, accuser->w, accuser->h);
            blit(soupconner, doubleBuffer, 0, 0,3*SCREEN_W/4-soupconner->w, SCREEN_H/2, soupconner->w, soupconner->h);
            choix=0;
        }
        /// affichage du double buffer
        blit(doubleBuffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);
    }
    /**************************************************************************************************************/

    /*** Destruction des bitmaps ***/
    destroy_bitmap(imageChargee);
    destroy_bitmap(doubleBuffer);
    destroy_bitmap(accuser);
    destroy_bitmap(soupconner);
    destroy_bitmap(soupconner_1);
    destroy_bitmap(accuser_1);
    clear_bitmap(screen);
    /*******************************/
    return choix;
}
int Hypothese::hypotheseMenu(Partie &partie,int joueur)
{
    /******** Variables ***********/
    vector<Carte>listePersonnage;
    vector<Carte>listeArme;
    vector<Carte>listeLieu;
    vector<Carte>suspect;
    string personnage,arme,lieu,carteDevoiler;

    int choix,victoire=0,carteMontrer=0;
    char*nom=new char[0];
    /******************************/

    /************* Choix de l'action (accuser ou soupçonner) **********/
    do
    {
        textprintf_ex(screen,font,SCREEN_W/2,SCREEN_H/2,makecol(255,255,255),-1,"Pour accuser vous devez être sur la case CLUEDO!!!");
        choix=action();
    }
    while(choix==1&&(partie.getListeJoueur()[joueur].getPionX()!=385||partie.getListeJoueur()[joueur].getPionY()!=475));
    /***********************************************************/

    /************* Choix du des cartes **********/
    for(auto elem:partie.getListeCarte())
    {
        if(elem.getIdentifiant()<20)
        {
            listePersonnage.push_back(elem);
        }
        else if(elem.getIdentifiant()<30)
        {
            listeArme.push_back(elem);
        }
        else listeLieu.push_back(elem);
    }
    do
    {
        textprintf_ex(screen,font,SCREEN_W/2,SCREEN_H/2,makecol(255,255,255),-1,"Pour soupçonner vous devez être dans le lieu que vous suspecter!!!");
        personnage=selectionner(listePersonnage);
        arme=selectionner(listeArme);
        lieu=selectionner(listeLieu);
        setX(lieu);
        setY(lieu);
    }
    while(choix==2&&verifierH(partie.getListeJoueur()[joueur].getPionX(),partie.getListeJoueur()[joueur].getPionY())==0);
    clear_bitmap(screen);

    for(auto elem:partie.getListeCarte())
    {
        if(elem.getNom()==personnage)
            suspect.push_back(elem);
        else if (elem.getNom()==arme)
            suspect.push_back(elem);
        else if (elem.getNom()==lieu)
            suspect.push_back(elem);
    }
    /**********************************************/

    /************** Hypothese *********************/
    if(choix==2)/// Le joueur soupçonne
    {
        partie.afficherCarte(suspect);
        /*** On demande dans l'ordre***/
        for(int i=joueur+1; i<partie.getNombreJoueur(); i++) /// Joueurs après
        {
            if(carteMontrer==0)
            {
                nom=new char [partie.getListeJoueur()[i].getNom().size()+1];
                strncpy(nom,partie.getListeJoueur()[i].getNom().c_str(),partie.getListeJoueur()[i].getNom().size()+1);
                allegro_message("%s doit montrer une carte",nom);

                for(auto elem:partie.getListeJoueur()[i].getJeu())
                {
                    if(carteMontrer==0&&(elem.getNom()==personnage||elem.getNom()==lieu||elem.getNom()==arme))
                    {
                        carteMontrer=1;
                        carteDevoiler=selectionner(partie.getListeJoueur()[i].getJeu());
                        while(carteDevoiler!=personnage&&carteDevoiler!=arme&&carteDevoiler!=lieu)
                        {
                            textprintf_ex(screen,font,SCREEN_W/2,SCREEN_H/2,makecol(255,255,255),-1,"Carte non demandée!!!");
                            rest(1000);
                            carteDevoiler=selectionner(partie.getListeJoueur()[i].getJeu());
                        }
                    }
                }
            }
            if(carteMontrer==0)
            {
                clear_bitmap(screen);
                rest(1000);
                while(!mouse_b&1)
                {
                    textprintf_ex(screen,font,SCREEN_W/2,SCREEN_H/2,makecol(255,255,255),-1,"Vous n'avez aucune carte à montrer!!!");
                }
            }

        }
        for(int i=0; i<joueur; i++) /// Joueurs avant
        {
            if(carteMontrer==0)
            {
                nom=new char [partie.getListeJoueur()[i].getNom().size()+1];
                strncpy(nom,partie.getListeJoueur()[i].getNom().c_str(),partie.getListeJoueur()[i].getNom().size()+1);
                allegro_message("%s doit montrer une carte",nom);

                for(auto elem:partie.getListeJoueur()[i].getJeu())
                {
                    if(carteMontrer==0&&(elem.getNom()==personnage||elem.getNom()==lieu||elem.getNom()==arme))
                    {
                        carteMontrer=1;
                        carteDevoiler=selectionner(partie.getListeJoueur()[i].getJeu());
                        while(carteDevoiler!=personnage&&carteDevoiler!=arme&&carteDevoiler!=lieu)
                        {
                            textprintf_ex(screen,font,SCREEN_W/2,SCREEN_H/2,makecol(255,255,255),-1,"Carte non demandée!!!");
                            rest(1000);
                            carteDevoiler=selectionner(partie.getListeJoueur()[i].getJeu());
                        }
                    }
                }
            }
            if(carteMontrer==0)
            {
                clear_bitmap(screen);
                rest(1000);
                while(!mouse_b&1)
                {
                    textprintf_ex(screen,font,SCREEN_W/2,SCREEN_H/2,makecol(255,255,255),-1,"Vous n'avez aucune carte à montrer!!!");
                }
            }
        }
        /******************************/

        /*** On montre la carte au joueur***/
        nom=new char [partie.getListeJoueur()[joueur].getNom().size()+1];
        strncpy(nom,partie.getListeJoueur()[joueur].getNom().c_str(),partie.getListeJoueur()[joueur].getNom().size()+1);
        allegro_message("%s doit voir la carte",nom);
        if(carteMontrer==1)
        {
            for(auto elem:partie.getListeCarte())
            {
                if(elem.getNom()==carteDevoiler)
                {
                    partie.getListeJoueur()[joueur].setDonnee(elem);
                    partie.afficherCarte(partie.getListeJoueur()[joueur].getDonnee());
                }
            }
        }
        else
        {
            rest(1000);
            clear_bitmap(screen);
            while(!mouse_b&1)
            {
                textprintf_ex(screen,font,SCREEN_W/2,SCREEN_H/2,makecol(255,255,255),-1,"Personne n'a pu vous montrer une carte!!!");
            }
        }
        /***********************************/
    }
    else if(choix) /// Le joueur accuse
    {
        partie.afficherCarte(suspect);
        for(auto elem:partie.getEnveloppe())
        {
            if(elem.getNom()==personnage||elem.getNom()==lieu||elem.getNom()==arme)
                victoire++;
            else victoire=0;
        }
        if(victoire==3)
        {
            victoire=1;
            ecranDeVictoire(partie.getEnveloppe());
        }
        else
            victoire=2;
    }
    delete[]nom;
    return victoire;
}
int Hypothese::verifPiece(int pieceX,int pieceY)
{
    int valide=0;
    if(pieceX==175&&pieceY==575)///Salon
        valide=1;
    else if(pieceX==185&&pieceY==375)///Cuisine
        valide=1;
    else if(pieceX==135&&pieceY==225)/// Salle à Manger
        valide=1;
     else if(pieceX==385&&pieceY==525)/// Hall
        valide=1;
    else if(pieceX==385&&pieceY==175)/// Library
        valide=1;
    else if(pieceX==585&&pieceY==125)/// Bureau
        valide=1;
    else if(pieceX==585&&pieceY==325)/// Salle de billard
        valide=1;
    else if(pieceX==635&&pieceY==525)/// Véranda
        valide=1;
    else if(pieceX==385&&pieceY==275)/// Ball
        valide=1;
    else if(pieceX==385&&pieceY==475)/// Accuser
        valide=1;
    else valide=0; /// sur une case quelconque

    return valide;
}

void Hypothese::ecranDeVictoire(std::vector<Carte>card) /// sous programme ecran de victoire pour chaque personnage
{
    /*** Bitmap ***/
    BITMAP *fond;
    BITMAP *personnage;
    /****************/

    string nom;
    char *image_charger=new char[0];
    BITMAP *doubleBuffer;  // double buffer

    /************ Musique **************/
    SAMPLE*son=load_sample("bleach.wav");
    play_sample(son,255,1,1000,1);
    /***********************************/

    for(auto elem: card)
    {
        if(elem.getIdentifiant()<20)
        {
            nom=elem.getNom();
        }
    }

    /******** Convertion string en char ***********/
    nom="images/"+nom+"1.bmp";
    image_charger=new char[nom.size()+1];
    strncpy(image_charger,nom.c_str(),nom.size()+1);
    personnage=load_bitmap(image_charger,NULL);
    /***********************************************/


    fond=load_bitmap("images/maison1.bmp",NULL);
    doubleBuffer=create_bitmap(SCREEN_W,SCREEN_H);

    while(!key[KEY_ESC])
    {

        clear_bitmap(doubleBuffer);
        blit(fond,doubleBuffer,0,0,(SCREEN_W-fond->w)/2, (SCREEN_H-fond->h)/2, fond->w, fond->h);
        blit(personnage,doubleBuffer,0,0,(SCREEN_W-personnage->w)/2, (SCREEN_H)/2,personnage->w,personnage->h);
        textprintf_ex(doubleBuffer,font,500,300,makecol(200,0,0),-1,"L'ASSASSIN EST : ");

        blit(doubleBuffer,screen,0,0,0,0,SCREEN_W, SCREEN_H); //affichage du double Buffer
    }

    /*** Destruction des Bitmaps***/
    destroy_sample(son);
    destroy_bitmap(fond);
    destroy_bitmap(personnage);
    destroy_bitmap(doubleBuffer);
}

