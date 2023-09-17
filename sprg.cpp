#include "headers.h"

using namespace std;

Deroulement::Deroulement()
{

}

Deroulement::~Deroulement()
{

}

void Deroulement::initilisationAllegro()
{
    allegro_init();
    install_mouse();
    install_keyboard();
    set_uformat(U_ASCII);

    set_color_depth(desktop_color_depth());
    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED,1200,650,0,0)!=0)
    {
        allegro_message("prb gfx mode");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    show_mouse(screen);
    install_sound(DIGI_AUTODETECT,MIDI_AUTODETECT,NULL);
}


void Deroulement::choix()
{
    BITMAP *image2;


    SAMPLE *son=load_sample("ciao.wav");


    play_sample(son,255,1,1000,1);

    image2=load_bitmap("images/image1.bmp",NULL);    ///image de chargement du jeu

    if (!image2)
    {
        allegro_message("pas pu trouver/charger image1.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    blit(image2,screen,0,0,(SCREEN_W-image2->w)/2, (SCREEN_H-image2->h)/2, image2->w, image2->h);
    rest(5000); /// chargement 5 secondes
    destroy_bitmap(image2);
    rectfill(screen,0,0,1200,650,makecol(0,0,0));
    textprintf_ex(screen,font,900,600,makecol(255,255,255),-1,"Chargement du jeu. ");
    rest(1000);
    textprintf_ex(screen,font,900,600,makecol(255,255,255),-1,"Chargement du jeu.. ");
    rest(1000);
    textprintf_ex(screen,font,900,600,makecol(255,255,255),-1,"Chargement du jeu... ");
    rest(1000);
    textprintf_ex(screen,font,900,600,makecol(255,255,255),-1,"Chargement du jeu.... ");
    rest(1000);
    textprintf_ex(screen,font,900,600,makecol(255,255,255),-1,"Chargement du jeu..... ");
    rest(1000);
    rest(5000);
    destroy_sample(son);



}

int Deroulement::new_menu()
{
    Plateau plateaux;
    BITMAP *image;
    BITMAP *doubleBuffer;
    int white_color;
    int free=0;

    int variable=0;

    std::string nom_sauvegarde;


    //creation du double buffer
    doubleBuffer=create_bitmap(SCREEN_W,SCREEN_H);

    image=load_bitmap("images/image2.bmp",NULL);

    while(free==0)
    {
        clear_bitmap(doubleBuffer);
        if (!image)
        {
            allegro_message("pas pu trouver/charger image2.bmp");
            allegro_exit();
            exit(EXIT_FAILURE);
        }

        white_color=makecol(255,255,255);

        blit(image,doubleBuffer,0,0, (SCREEN_W-image->w)/2, (SCREEN_H-image->h)/2, image->w, image->h);
        if((mouse_x>800)&&(mouse_x<950)&&(mouse_y>230)&&(mouse_y<270))
        {
            rectfill(doubleBuffer,795,230,950,270,makecol(255,0,0));
            rectfill(doubleBuffer,795,280,950,320,makecol(0,0,0));
            rectfill(doubleBuffer,795,330,950,375,makecol(0,0,0));
            rectfill(doubleBuffer,795,430,950,470,makecol(0,0,0));
        }
        else if((mouse_x>795)&&(mouse_x<950)&&(mouse_y>280)&&(mouse_y<320))
        {
            rectfill(doubleBuffer,795,230,950,270,makecol(0,0,0));
            rectfill(doubleBuffer,795,280,950,320,makecol(255,0,0));
            rectfill(doubleBuffer,795,330,950,375,makecol(0,0,0));
            rectfill(doubleBuffer,795,430,950,470,makecol(0,0,0));
        }
        else if((mouse_x>795)&&(mouse_x<950)&&(mouse_y>330)&&(mouse_y<375))
        {
            rectfill(doubleBuffer,795,230,950,270,makecol(0,0,0));
            rectfill(doubleBuffer,795,280,950,320,makecol(0,0,0));
            rectfill(doubleBuffer,795,330,950,375,makecol(255,0,0));
            rectfill(doubleBuffer,795,430,950,470,makecol(0,0,0));
        }
        else if((mouse_x>795)&&(mouse_x<950)&&(mouse_y>430)&&(mouse_y<470))
        {
            rectfill(doubleBuffer,795,230,950,270,makecol(0,0,0));
            rectfill(doubleBuffer,795,280,950,320,makecol(0,0,0));
            rectfill(doubleBuffer,795,330,950,375,makecol(0,0,0));
            rectfill(doubleBuffer,795,430,950,470,makecol(255,0,0));
        }
        else
        {
            rectfill(doubleBuffer,795,230,950,270,makecol(0,0,0));
            rectfill(doubleBuffer,795,280,950,320,makecol(0,0,0));
            rectfill(doubleBuffer,795,330,950,375,makecol(0,0,0));
            rectfill(doubleBuffer,795,430,950,470,makecol(0,0,0));
        }

        textprintf_ex(doubleBuffer,font,670,250,white_color,-1,"                  NOUVELLE PARTIE ");
        textprintf_ex(doubleBuffer,font,670,300,white_color,-1,"                 PARTIE PRECEDENTE ");
        textprintf_ex(doubleBuffer,font,665,350,white_color,-1,"                        AIDE ");
        textprintf_ex(doubleBuffer,font,670,450,white_color,-1,"                      QUITTER ");

        blit(doubleBuffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);///affichage du double Buffer

        if(mouse_b&1)
        {
            if((mouse_x>800)&&(mouse_x<950)&&(mouse_y>230)&&(mouse_y<270))     /// commencer une nouvelle partie
            {
                destroy_bitmap(image);
                rectfill(screen,0,0,1200,650,makecol(0,0,0));   /// effacement de tout ce qu'il y avait precedemment à l'écran
                textprintf_ex(screen,font,900,600,makecol(255,255,255),-1,"Chargement du jeu. ");
                rest(1000);
                textprintf_ex(screen,font,900,600,makecol(255,255,255),-1,"Chargement du jeu.. ");
                rest(1000);
                textprintf_ex(screen,font,900,600,makecol(255,255,255),-1,"Chargement du jeu... ");
                rest(1000);
                textprintf_ex(screen,font,900,600,makecol(255,255,255),-1,"Chargement du jeu.... ");
                rest(1000);
                textprintf_ex(screen,font,900,600,makecol(255,255,255),-1,"Chargement du jeu..... ");
                rest(1000);
                textprintf_ex(screen,font,200,200,white_color,-1,"Vous avez choisi de lancer une nouvelle partie, amusez-vous bien !!! ");
                rest(5000);
                textprintf_ex(screen,font,200,200,makecol(0,0,0),-1,"Vous avez choisi de lancer une nouvelle partie, amusez-vous bien !!! ");
                textprintf_ex(screen,font,900,600,makecol(0,0,0),-1,"Chargement du jeu..... ");   ///effacer le texte de l'écran avec de la couleur noir

                variable=1;
                free=1;
                /// Hypothèse

            }
            else if((mouse_x>795)&&(mouse_x<950)&&(mouse_y>280)&&(mouse_y<320))      ///  revenir aux parties précédentes
            {
                destroy_bitmap(image);

                rectfill(screen,0,0,1200,650,makecol(0,0,0));   /// effacement de tout ce qu'il y avait precedemment à l'écran
                textprintf_ex(screen,font,900,600,makecol(255,255,255),-1,"Chargement du jeu. ");
                rest(1000);
                textprintf_ex(screen,font,900,600,makecol(255,255,255),-1,"Chargement du jeu.. ");
                rest(1000);
                textprintf_ex(screen,font,900,600,makecol(255,255,255),-1,"Chargement du jeu... ");
                rest(1000);
                textprintf_ex(screen,font,900,600,makecol(255,255,255),-1,"Chargement du jeu.... ");
                rest(1000);
                textprintf_ex(screen,font,900,600,makecol(255,255,255),-1,"Chargement du jeu..... ");
                rest(1000);
                textprintf_ex(screen,font,200,200,white_color,-1,"Vous avez choisi de revenir aux parties précédentes!!! ");
                rest(5000);
                textprintf_ex(screen,font,200,200,makecol(0,0,0),-1,"Vous avez choisi de revenir aux parties précédentes!!! ");
                textprintf_ex(screen,font,900,600,makecol(0,0,0),-1,"Chargement du jeu..... ");   ///effacer le texte de l'écran avec de la couleur noir

                variable=2;
                free=1;
            }

            else if((mouse_x>795)&&(mouse_x<950)&&(mouse_y>330)&&(mouse_y<375))
            {
                destroy_bitmap(image);
                rectfill(screen,0,0,1200,650,makecol(0,0,0));   /// effacement de tout ce qu'il y avait precedemment à l'écran
                textprintf_ex(screen,font,900,600,makecol(255,255,255),-1,"Chargement du jeu. ");
                rest(1000);
                textprintf_ex(screen,font,900,600,makecol(255,255,255),-1,"Chargement du jeu.. ");
                rest(1000);
                textprintf_ex(screen,font,900,600,makecol(255,255,255),-1,"Chargement du jeu... ");
                rest(1000);
                textprintf_ex(screen,font,900,600,makecol(255,255,255),-1,"Chargement du jeu.... ");
                rest(1000);
                textprintf_ex(screen,font,900,600,makecol(255,255,255),-1,"Chargement du jeu..... ");
                rest(1000);
                textprintf_ex(screen,font,200,200,white_color,-1,"Vous avez choisi de demander de l'aide, don't worry nous vous prenons en main !!! ");
                rest(5000);

                variable=3;
                free=1;
            }
            else if((mouse_x>795)&&(mouse_x<950)&&(mouse_y>430)&&(mouse_y<470))
            {
                variable=4;
                free=1;
            }
        }
    }

    destroy_bitmap(doubleBuffer);
    clear_bitmap(screen);
    return variable;
}

void Deroulement::aide() //mise en place du sous programme aide
{
    // Déclaration des différents pointeurs afin de recevoir des images
    BITMAP *maison;
    BITMAP *commencerpartie;
    BITMAP *deroulement;
    BITMAP *fin;
    //Déclaration du pointeur doubleBuffer
    BITMAP *doubleBuffer;

    int noir;
//Chargement des images "commencerpartie","deroulement" et "fin"
    maison=load_bitmap("images/maison1.bmp",NULL);
    commencerpartie=load_bitmap("images/commencerpartie.bmp",NULL);
    deroulement=load_bitmap("images/deroulement.bmp",NULL);
    fin=load_bitmap("images/fin1.bmp",NULL);

    //Creation du double buffer
    doubleBuffer=create_bitmap(SCREEN_W,SCREEN_H);
    //affectation de la couleur noire à la variable noir pour faciliter le code
    noir=makecol(0,0,0);

    while(!key[KEY_SPACE])
    {

        blit(maison,doubleBuffer,0,0,(SCREEN_W-maison->w)/2, (SCREEN_H-maison->h)/2, maison->w, maison->h);
        // mise en place de plusieurs rectangles jaunes constituant le menu d'aide
        rectfill(doubleBuffer,400,190,790,225,makecol(255,255,100));
        rectfill(doubleBuffer,400,265,790,305,makecol(255,255,100));
        rectfill(doubleBuffer,400,340,790,375,makecol(255,255,100));
        //textes contenus dans les rectangles pleins crees precedemment
        textprintf_ex(doubleBuffer,font,528,205,makecol(200,0,0),-1,"Commencer une partie");
        textprintf_ex(doubleBuffer,font,528,285,makecol(200,0,0),-1,"Déroulement du jeu");
        textprintf_ex(doubleBuffer,font,558,355,makecol(200,0,0),-1,"Fin du jeu");

        //condition permettant de selectionner l'option "idee de jeu"
        if (mouse_b&1 && ((mouse_x>400)&&(mouse_x<790)) && ((mouse_y>190)&&(mouse_y<217)))
        {
            //mise en plage de plusieurs rectangles pleins noirs pour "effacer" l'écran précédent
            rectfill(screen,400,190,790,225,noir);
            rectfill(screen,400,265,790,305,noir);
            rectfill(screen,400,340,790,375,noir);


            while(!key[KEY_ESC])
            {
                //effacage du bitmat
                clear_bitmap(doubleBuffer);
                //ajout de textes pour guider l'utilisateur
                textprintf_ex(screen,font,368,50,makecol(200,0,0),-1,"Voici les indications pour bien commencer le jeu");
                textprintf_ex(screen,font,30,625,makecol(255,128,0),-1,"Appuyez ECHAP pour quitter puis ESPACE pour aller au menu");
                //affichage de l'image commencerpartie
                blit(commencerpartie,screen,0,0,(SCREEN_W-commencerpartie->w)/2, (SCREEN_H-commencerpartie->h)/2, commencerpartie->w, commencerpartie->h);
            }
        }
        else

            //condition permettant de selectionner l'option "deroulement du jeu"
            if (mouse_b&1 && ((mouse_x>400)&&(mouse_x<790)) && ((mouse_y>240)&&(mouse_y<317)))
            {
                //mise en plage de plusieurs rectangles pleins noirs pour "effacer" l'écran précédent
                rectfill(screen,400,190,790,225,noir);
                rectfill(screen,400,265,790,305,noir);
                rectfill(screen,400,340,790,375,noir);
                while(!key[KEY_ESC])
                {
                    //ajout de textes pour guider l'utilisateur
                    textprintf_ex(screen,font,500,50,makecol(200,0,0),-1,"Voici le déroulement du jeu");
                    textprintf_ex(screen,font,30,625,makecol(255,128,0),-1,"Appuyez ECHAP pour quitter puis ESPACE pour aller au menu");
                    //affichage de l'image deroulement
                    blit(deroulement,screen,0,0,(SCREEN_W-deroulement->w)/2, (SCREEN_H-deroulement->h)/2, deroulement->w, deroulement->h);
                }
            }
            else

                //condition permettant de selectionner l'option "fin du jeu"
                if (mouse_b&1 && ((mouse_x>400)&&(mouse_x<790)) && ((mouse_y>340)&&(mouse_y<367)))
                {
                    //mise en plage de plusieurs rectangles pleins noirs pour "effacer" l'écran précédent
                    rectfill(screen,400,190,790,225,noir);
                    rectfill(screen,400,265,790,305,noir);
                    rectfill(screen,400,340,790,375,noir);
                    while(!key[KEY_ESC])
                    {
                        //texte pour guider l'utilisateur
                        textprintf_ex(screen,font,510,50,makecol(200,0,0),-1,"Voici la fin du jeu");
                        textprintf_ex(screen,font,30,625,makecol(255,128,0),-1,"Appuyez ECHAP pour quitter puis ESPACE pour aller au menu");
                        //affichage de l'image fin
                        blit(fin,screen,0,0, (SCREEN_W-fin->w)/2, (SCREEN_H-fin->h)/2, fin->w, fin->h);
                    }
                }
                else

                    blit(doubleBuffer,screen,0,0,0,0,SCREEN_W, SCREEN_H); //affichage du double Buffer
    }

    if(key[KEY_SPACE])
    {
        Deroulement::new_menu();
    }
    //destruction de chaque image
    destroy_bitmap(maison);
    destroy_bitmap(commencerpartie);
    destroy_bitmap(deroulement);
    destroy_bitmap(fin);
    destroy_bitmap(doubleBuffer);
}

void Deroulement::echap() //mise en place du sous programme echap
{
    if (key[KEY_ESC])   /// quitter le jeu avec la touche echap
    {
        rectfill(screen,0,0,1200,600,makecol(0,0,0));//mise en plage d'un rectangle plein noir pour "effacer" l'écran
        textprintf_ex(screen,font,1000,550,makecol(255,255,255),-1,"Chargement du jeu. ");//ecran de chargement
        rest(1000);//delai d'1 seconde
        textprintf_ex(screen,font,1000,550,makecol(255,255,255),-1,"Chargement du jeu.. ");//ecran de chargement
        rest(1000);//delai d'1 seconde
        aide(); //appel du sous programme aide à la fin de la fonction echap
    }
}




void Deroulement::deroule(Partie jeu)
{
    int milieu=0;
    int victoire=0;
    int quitter=0;
    int i=0;  /// Tour de jeu
    char *nom=new char[0];

    Plateau plateaux;
    Hypothese hypo;


    while((quitter!=2)&&(victoire==0))
    {
        nom=new char [jeu.getListeJoueur()[i].getNom().size()+1];
        strncpy(nom,jeu.getListeJoueur()[i].getNom().c_str(),jeu.getListeJoueur()[i].getNom().size()+1);
        allegro_message("A %s de jouer",nom);

        quitter=plateaux.affichage_plateau(jeu,i);

        if(quitter!=2)
        {
            milieu=hypo.verifPiece(jeu.getListeJoueur()[i].getPionX(),jeu.getListeJoueur()[i].getPionY());
            if(milieu==1)
                victoire=hypo.hypotheseMenu(jeu,i);
            if(victoire==1)
            {
                clear_bitmap(screen);
                textprintf_ex(screen,font,SCREEN_W/2,SCREEN_H/2,makecol(255,255,255),-1,"%s a gagné la partie",nom);
                rest(2000);
                clear_bitmap(screen);
            }
            else if(victoire==2)
            {
                clear_bitmap(screen);
                textprintf_ex(screen,font,SCREEN_W/2,SCREEN_H/2,makecol(255,255,255),-1,"%s a perdu la partie",nom);
                rest(2000);
                clear_bitmap(screen);
            }

            i++;

            if(i==jeu.getNombreJoueur())
            {
                i=0;
            }
        }

    }
}

