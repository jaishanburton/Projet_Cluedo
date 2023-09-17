#include "headers.h"

using namespace std;

Carte::Carte(int identifiant,string nom):
    m_identifiant(identifiant),m_nom(nom)
{
    m_positionX=100;
    m_positionY=100;
    if(getNom()=="professeur")
        m_image=load_bitmap("images/professeur.bmp",NULL);
    else if(getNom()=="rio")
        m_image=load_bitmap("images/rio.bmp",NULL);
    else if(getNom()=="tokyo")
        m_image=load_bitmap("images/tokyo.bmp",NULL);
    else if(getNom()=="denver")
        m_image=load_bitmap("images/denver.bmp",NULL);
    else if(getNom()=="berlin")
        m_image=load_bitmap("images/berlin.bmp",NULL);
    else if(getNom()=="nairobi")
        m_image=load_bitmap("images/nairobi.bmp",NULL);
    else if(getNom()=="revolver")
        m_image=load_bitmap("images/revolver.bmp",NULL);
    else if(getNom()=="barredefer")
        m_image=load_bitmap("images/barredefer.bmp",NULL);
    else if(getNom()=="poignard")
        m_image=load_bitmap("images/poignard.bmp",NULL);
    else if(getNom()=="corde")
        m_image=load_bitmap("images/corde.bmp",NULL);
    else if(getNom()=="chandelier")
        m_image=load_bitmap("images/chandelier.bmp",NULL);
    else if(getNom()=="clefanglaise")
        m_image=load_bitmap("images/clefanglaise.bmp",NULL);
    else if(getNom()=="billard")
        m_image=load_bitmap("images/billard1.bmp",NULL);
    else if(getNom()=="bal")
        m_image=load_bitmap("images/bal1.bmp",NULL);
    else if(getNom()=="bureau")
        m_image=load_bitmap("images/bureau1.bmp",NULL);
    else if(getNom()=="library")
        m_image=load_bitmap("images/library1.bmp",NULL);
    else if(getNom()=="cuisine")
        m_image=load_bitmap("images/cuisine1.bmp",NULL);
    else if(getNom()=="salon")
        m_image=load_bitmap("images/salon1.bmp",NULL);
    else if(getNom()=="salleManger")
        m_image=load_bitmap("images/salleManger1.bmp",NULL);
    else if(getNom()=="veranda")
        m_image=load_bitmap("images/veranda1.bmp",NULL);
    else if(getNom()=="hall")
        m_image=load_bitmap("images/hall1.bmp",NULL);
}
Carte::~Carte()
{

}
int Carte::getIdentifiant()
{
    return m_identifiant;
}
string Carte::getNom()
{
    return m_nom;
}
BITMAP*Carte::getImage()
{
    return m_image;
}
int Carte::getX()
{
    return m_positionX;
}
int Carte::getY()
{
    return m_positionY;
}
void Carte::setX(int positionX)
{
    m_positionX=positionX;
}
void Carte::setY(int positionY)
{
    m_positionY=positionY;
}
void Carte::afficher(BITMAP*doubleBuffer)
{
    blit(getImage(), doubleBuffer, 0, 0,getX(), getY(), getImage()->w, getImage()->h);
}
