#include "headers.h"

using namespace std;

Plateau::Plateau()///:m_jeton.m_posLigne(375),m_jeton.m_posColonne(475),m_jeton.m_depLigne(25),m_jeton.m_depColonne(25)
{

}

Plateau::~Plateau()
{

}

int Plateau::affichage_plateau(Partie &jeu,int numero)
{

    int couleur;
    int couleur_red;
    int free=0;
    BITMAP *Image3,*doubleBuffer,*Image4,*manger,*salon,*cuisine,*billard,*bureau,*biblio,*veranda,*hall,*ball;
    BITMAP *fleche_HAUT,*fleche_BAS,*fleche_DROIT,*fleche_GAUCHE;
    int couleur_des,couleur_jeu,couleur_donnees,couleur_pause;
    couleur_des=couleur_jeu=couleur_donnees=couleur_pause=makecol(255,255,255);


    // Pion PIONNIER(375,475,25,25);
    ///---------------------------------------------------COORDONNEES DE LA SOURIS----------------------------------------------
    int x, y;
    //creation du double buffer
    doubleBuffer=create_bitmap(SCREEN_W,SCREEN_H);

    Image3=load_bitmap("images/image3.bmp",NULL);
    Image4=load_bitmap("images/image4.bmp",NULL);
    manger=load_bitmap("images/salleManger.bmp",NULL);
    cuisine=load_bitmap("images/cuisine.bmp",NULL);
    salon=load_bitmap("images/salon.bmp",NULL);
    bureau=load_bitmap("images/bureau.bmp",NULL);
    billard=load_bitmap("images/billard.bmp",NULL);
    veranda=load_bitmap("images/veranda.bmp",NULL);
    hall=load_bitmap("images/hall.bmp",NULL);
    biblio=load_bitmap("images/library.bmp",NULL);
    ball=load_bitmap("images/ball.bmp",NULL);

    fleche_BAS=load_bitmap("images/fleche_bas.bmp",NULL);
    fleche_HAUT=load_bitmap("images/fleche_haut.bmp",NULL);
    fleche_DROIT=load_bitmap("images/fleche_droit.bmp",NULL);
    fleche_GAUCHE=load_bitmap("images/fleche_gauche.bmp",NULL);


    while(free==0)
    {
        clear_bitmap(doubleBuffer);


        /// Avoir une couleur (ici du blanc)
        couleur=makecol(255,255,255);
        couleur_red=makecol(255,0,0);

        blit(Image3,doubleBuffer,0,0, (SCREEN_W-Image3->w)/2, (SCREEN_H-Image3->h)/2, Image3->w, Image3->h);   ///fond arrière
        blit(Image4,doubleBuffer,0,0, 50, 50, 650, 700);   ///fond arrière du plateau


        textprintf_ex(doubleBuffer,font, 850, 20,couleur_red,-1," Coordonnées de la souris:");
        textprintf_ex(doubleBuffer,font,55,20,couleur,-1,"Le CLUEDO: Plateau de jeu !!!");


        x=mouse_x;
        y=mouse_y;
        textprintf_ex(doubleBuffer,font, 1060, 20,couleur_red,-1, "  x: %d  y: %d", x,y);


        if((mouse_x>900)&&(mouse_x<1100)&&(mouse_y>50)&&(mouse_y<90))   /// qd on est sur lancer les dés=> contour rouge
        {
            couleur_des=couleur_red;
            couleur_jeu=couleur_donnees=couleur_pause=makecol(255,255,255);

        }

        else if((mouse_x>900)&&(mouse_x<1100)&&(mouse_y>220)&&(mouse_y<260))   /// qd on est sur lancer les dés=> contour rouge
        {
            couleur_jeu=couleur_red;
            couleur_des=couleur_donnees=couleur_pause=makecol(255,255,255);

        }

        else if((mouse_x>900)&&(mouse_x<1100)&&(mouse_y>320)&&(mouse_y<360))   /// qd on est sur lancer les dés=> contour rouge
        {
            couleur_donnees=couleur_red;
            couleur_jeu=couleur_des=couleur_pause=makecol(255,255,255);

        }

        else if((mouse_x>900)&&(mouse_x<1100)&&(mouse_y>420)&&(mouse_y<460))   /// qd on est sur lancer les dés=> contour rouge
        {
            couleur_pause=couleur_red;
            couleur_jeu=couleur_donnees=couleur_des=makecol(255,255,255);

        }
        else
        {
            couleur_pause=couleur_jeu=couleur_donnees=couleur_des=makecol(255,255,255);
        }

        ///le bleu de l'ECE (Pour appuyer la touche pour le lancement des dés)
        rectfill(doubleBuffer,900,50,1100,90,couleur_des);
        textprintf_ex(doubleBuffer,font,910,70,makecol(0,0,0),-1,"     Lancer les dés ");

        rectfill(doubleBuffer,900,220,1100,260,couleur_jeu);
        textprintf_ex(doubleBuffer,font,910,240,makecol(0,0,0),-1,"     Afficher jeu ");

        rectfill(doubleBuffer,900,320,1100,360,couleur_donnees);
        textprintf_ex(doubleBuffer,font,910,340,makecol(0,0,0),-1,"     Afficher données ");

        rectfill(doubleBuffer,900,420,1100,460,couleur_pause);
        textprintf_ex(doubleBuffer,font,910,440,makecol(0,0,0),-1,"     Menu pause ");








///Le (main) quadrillage
        hline(doubleBuffer,100,100,700,couleur_red);
        hline(doubleBuffer,100,150,700,couleur_red);
        hline(doubleBuffer,100,200,700,couleur_red);
        hline(doubleBuffer,100,250,700,couleur_red);
        hline(doubleBuffer,100,300,700,couleur_red);
        hline(doubleBuffer,100,350,700,couleur_red);


        hline(doubleBuffer,100,400,700,couleur_red);
        hline(doubleBuffer,100,450,700,couleur_red);

        hline(doubleBuffer,100,500,700,couleur_red);
        hline(doubleBuffer,100,550,700,couleur_red);

        hline(doubleBuffer,100,600,700,couleur_red);
        hline(doubleBuffer,100,650,700,couleur_red);
        hline(doubleBuffer,100,700,700,couleur_red);



        vline(doubleBuffer,100,100,600,couleur_red);
        vline(doubleBuffer,150,100,600,couleur_red);
        vline(doubleBuffer,200,100,600,couleur_red);
        vline(doubleBuffer,250,100,600,couleur_red);
        vline(doubleBuffer,300,100,600,couleur_red);
        vline(doubleBuffer,350,100,600,couleur_red);

        vline(doubleBuffer,400,100,600,couleur_red);
        vline(doubleBuffer,450,100,600,couleur_red);

        vline(doubleBuffer,500,100,600,couleur_red);
        vline(doubleBuffer,550,100,600,couleur_red);
        vline(doubleBuffer,600,100,600,couleur_red);

        vline(doubleBuffer,650,100,600,couleur_red);
        vline(doubleBuffer,700,100,600,couleur_red);

///Affichage des salles sur le plateau de jeu

        blit(manger,doubleBuffer,0,0, 50, 80, 200, 230);   //LA SALLE A MANGER
        blit(cuisine,doubleBuffer,0,0, 100, 300, 200, 400);   //La cuinine
        blit(salon,doubleBuffer,0,0, 50, 500, 200, 600);   //La salon
        blit(bureau,doubleBuffer,0,0,550,50,650,100);  //le bureau
        blit(billard,doubleBuffer,0,-30,550,200,650,300); //le billard
        blit(veranda,doubleBuffer,0,0,552,500,700,600); //le veranda
        blit(hall,doubleBuffer,0,0,302,500,450,600); // le hall
        blit(biblio,doubleBuffer,0,0,300,50,450,150); //la bibliothèque
        blit(ball,doubleBuffer,0,0,320,250,450,300); // la salle de bal

        blit(fleche_HAUT,doubleBuffer,0,0,100,250,150,300);
        blit(fleche_HAUT,doubleBuffer,0,0,150,400,200,450);
        blit(fleche_GAUCHE,doubleBuffer,0,0,200,550,250,600);
        blit(fleche_BAS,doubleBuffer,0,0,350,450,400,500);
        blit(fleche_HAUT,doubleBuffer,0,0,350,200,400,250);
        blit(fleche_HAUT,doubleBuffer,0,0,550,150,600,200);
        blit(fleche_DROIT,doubleBuffer,0,0,500,300,550,350);
        blit(fleche_BAS,doubleBuffer,0,0,600,450,650,500);




        rectfill(doubleBuffer,300,300,450,350,makecol(0,0,0));
        textprintf_ex(doubleBuffer,font,365,325,couleur,-1,"???");
        rectfill(doubleBuffer,300,350,450,400,makecol(200,122,64)); // du marron
        textprintf_ex(doubleBuffer,font,320,375,couleur,-1,"ENTREE DU JEU");
        rectfill(doubleBuffer,350,400,400,450,makecol(200,122,64)); // du marron



        hline(doubleBuffer,350,400,400,makecol(0,0,0));
        hline(doubleBuffer,350,410,400,makecol(0,0,0));
        hline(doubleBuffer,350,420,400,makecol(0,0,0));
        hline(doubleBuffer,350,430,400,makecol(0,0,0));
        hline(doubleBuffer,350,440,400,makecol(0,0,0));
        hline(doubleBuffer,350,450,400,makecol(0,0,0));


        if((mouse_b&1)&&(couleur_des==couleur_red))
        {
            free=m_jeton.deplacement(jeu,numero);
        }

        else if((mouse_b&1)&&(couleur_jeu==couleur_red))
        {
            jeu.afficherCarte(jeu.getListeJoueur()[numero].getJeu());

        }

        else if((mouse_b&1)&&(couleur_donnees==couleur_red))
        {
            jeu.afficherCarte(jeu.getListeJoueur()[numero].getDonnee());
        }

        else if((mouse_b&1)&&(couleur_pause==couleur_red))
        {
            free=menu_pause(jeu);
        }



        blit(doubleBuffer,screen,0,0,0,0,SCREEN_W, SCREEN_H); ///affichage du double Buffe
    }

    destroy_bitmap(doubleBuffer);
    destroy_bitmap(Image3);
    destroy_bitmap(manger);
    destroy_bitmap(salon);
    destroy_bitmap(cuisine);
    destroy_bitmap(bureau);
    destroy_bitmap(billard);
    destroy_bitmap(veranda);
    destroy_bitmap(hall);
    destroy_bitmap(biblio);
    destroy_bitmap(ball);

    return free;

}




int Plateau::menu_pause(Partie jeu)
{
    BITMAP *doubleBuffer;
    int couleur_sauvegarde=makecol(255,255,255);
    int couleur_quitter=makecol(255,255,255);
    int couleur_reprendre=makecol(255,255,255);
    int couleur_red=makecol(255,0,0);
    int choix=3;

    doubleBuffer=create_bitmap(300,200);

    do
    {

        clear_bitmap(doubleBuffer);

        rectfill(doubleBuffer,SCREEN_W/2-100,SCREEN_H/2-100,SCREEN_W/2+100,SCREEN_H/2+100,makecol(0,0,0));
        textprintf_ex(doubleBuffer,font,50,10,makecol(255,255,255),-1,"      *****MENU*****");

        textprintf_ex(doubleBuffer,font,50,80,couleur_reprendre,-1,"  -Reprendre la partie-");


        textprintf_ex(doubleBuffer,font,50,120,couleur_sauvegarde,-1,"  -Sauvegarder la partie-");

        textprintf_ex(doubleBuffer,font,50,160,couleur_quitter,-1,"        -Quitter-");

        if((mouse_x>573&&mouse_x<724)&&(mouse_y>305&&mouse_y<312))
        {
            couleur_reprendre=couleur_red;
            couleur_quitter=couleur_sauvegarde=makecol(255,255,255);
        }

        if((mouse_x>573&&mouse_x<740)&&(mouse_y>344&&mouse_y<353))
        {
            couleur_sauvegarde=couleur_red;
            couleur_quitter=couleur_reprendre=makecol(255,255,255);
        }

        if((mouse_x>623&&mouse_x<677)&&(mouse_y>384&&mouse_y<394))
        {
            couleur_quitter=couleur_red;
            couleur_sauvegarde=couleur_reprendre=makecol(255,255,255);
        }

        if((mouse_b&1)&&(couleur_reprendre==couleur_red))
        {
            choix=0;
        }

        else if((mouse_b&1)&&(couleur_sauvegarde==couleur_red))
        {
            jeu.sauvegarder();
            choix=0;
        }

        else if((mouse_b&1)&&(couleur_quitter==couleur_red))
        {
            choix=2;
        }



        blit(doubleBuffer,screen,0,0,SCREEN_W/2-100,SCREEN_H/2-100,300,200);
    }
    while(choix!=2&&choix!=0);


    destroy_bitmap(doubleBuffer);

    return choix;


}


