#include "plateau.h"
#include "headers.h"
#include "pion.h"

using namespace std;

De::De():m_numero(1)
{

}

De::~De()
{

}

int De::affichaged()
{


    BITMAP *m_FACE1;
    BITMAP *m_FACE2;
    BITMAP *m_FACE3;
    BITMAP *m_FACE4;
    BITMAP *m_FACE5;
    BITMAP *m_FACE6;


    m_FACE1=load_bitmap("images/face1.bmp",NULL);
    m_FACE2=load_bitmap("images/face2.bmp",NULL);
    m_FACE3=load_bitmap("images/face3.bmp",NULL);
    m_FACE4=load_bitmap("images/face4.bmp",NULL);
    m_FACE5=load_bitmap("images/face5.bmp",NULL);
    m_FACE6=load_bitmap("images/face6.bmp",NULL);



    if (!m_FACE1)
    {
        allegro_message("pas pu trouver/charger images/face1.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    if (!m_FACE2)
    {
        allegro_message("pas pu trouver/charger images/face2.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    if (!m_FACE3)
    {
        allegro_message("pas pu trouver/charger images/face3.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    if (!m_FACE4)
    {
        allegro_message("pas pu trouver/charger images/face4.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    if (!m_FACE5)
    {
        allegro_message("pas pu trouver/charger images/face5.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    if (!m_FACE6)
    {
        allegro_message("pas pu trouver/charger images/face6.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }





    m_numero=rand()%(6-1+1)+1;
    cout<<"Numero du 1er de: "<<m_numero<<endl;

    if(m_numero==1)
    {

        blit(m_FACE1,screen,0,0, 900, 100, 1150, 400);   //affichage de la face 1 du dé

    }
    else if(m_numero==2)
    {

        blit(m_FACE2,screen,0,0, 900, 100, 1150, 400);
    }
    else if(m_numero==3)
    {

        blit(m_FACE3,screen,0,0, 900, 100, 1150, 400);
    }
    else if(m_numero==4)
    {

        blit(m_FACE4,screen,0,0, 900, 100, 1150, 400);
    }
    else if(m_numero==5)
    {

        blit(m_FACE5,screen,0,0, 900, 100, 1150, 400);
    }
    else if(m_numero==6)
    {

        blit(m_FACE6,screen,0,0, 900, 100, 1150, 400);
    }
    else
    {
        cout<<"erreur de des"<<endl;
    }

    return m_numero;
}





int De::affichaged2()
{


    BITMAP *m_FACE1;
    BITMAP *m_FACE2;
    BITMAP *m_FACE3;
    BITMAP *m_FACE4;
    BITMAP *m_FACE5;
    BITMAP *m_FACE6;


    m_FACE1=load_bitmap("images/face1.bmp",NULL);
    m_FACE2=load_bitmap("images/face2.bmp",NULL);
    m_FACE3=load_bitmap("images/face3.bmp",NULL);
    m_FACE4=load_bitmap("images/face4.bmp",NULL);
    m_FACE5=load_bitmap("images/face5.bmp",NULL);
    m_FACE6=load_bitmap("images/face6.bmp",NULL);



    if (!m_FACE1)
    {
        allegro_message("pas pu trouver/charger images/face1.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    if (!m_FACE2)
    {
        allegro_message("pas pu trouver/charger images/face2.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    if (!m_FACE3)
    {
        allegro_message("pas pu trouver/charger images/face3.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    if (!m_FACE4)
    {
        allegro_message("pas pu trouver/charger images/face4.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    if (!m_FACE5)
    {
        allegro_message("pas pu trouver/charger images/face5.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    if (!m_FACE6)
    {
        allegro_message("pas pu trouver/charger images/face6.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }





    m_numero=rand()%(6-1+1)+1;
    cout<<"Numero du 2eme de: "<<m_numero<<endl;

    if(m_numero==1)
    {

        blit(m_FACE1,screen,0,0, 1000, 100, 1150, 400);   //affichage de la face 1 du dé

    }
    else if(m_numero==2)
    {

        blit(m_FACE2,screen,0,0, 1000, 100, 1150, 400);
    }
    else if(m_numero==3)
    {

        blit(m_FACE3,screen,0,0, 1000, 100, 1150, 400);
    }
    else if(m_numero==4)
    {

        blit(m_FACE4,screen,0,0, 1000, 100, 1150, 400);
    }
    else if(m_numero==5)
    {

        blit(m_FACE5,screen,0,0, 1000, 100, 1150, 400);
    }
    else if(m_numero==6)
    {

        blit(m_FACE6,screen,0,0, 1000, 100, 1150, 400);
    }
    else
    {
        cout<<"erreur de des"<<endl;
    }

    return m_numero;
}


