#include "headers.h"
using namespace std;

Effectif::Effectif(int positionY,int texteY,int nombre)
{
    m_positionX=795;
    m_positionY=positionY;
    m_tailleX=155;
    m_tailleY=40;
    m_couleur=makecol(255,255,255);
    m_texteX=840;
    m_texteY=texteY;
    m_nombre=nombre;
}
Effectif::~Effectif()
{

}
int Effectif::getPositionX()
{
    return m_positionX;
}
int Effectif::getPositionY()
{
    return m_positionY;
}
int Effectif::getTailleX()
{
    return m_tailleX;
}
int Effectif::getTailleY()
{
    return m_tailleY;
}
int Effectif::getCouleur()
{
    return m_couleur;
}
int Effectif::getTexteX()
{
    return m_texteX;
}
int Effectif::getTexteY()
{
    return m_texteY;
}
int Effectif::getNombre()
{
    return m_nombre;
}
void Effectif::setCouleur(int couleur)
{
    m_couleur=couleur;
}
void Effectif::afficher(BITMAP * doubleBuffer)
{
    if((mouse_x>m_positionX)&&(mouse_x<(m_positionX+m_tailleX))&&(mouse_y>m_positionY)&&(mouse_y<(m_positionY+m_tailleY)))
        setCouleur(makecol(255,0,0));
    else
        setCouleur(makecol(255,255,255));
    rectfill(doubleBuffer,m_positionX,m_positionY,m_positionX+m_tailleX,m_positionY+m_tailleY,m_couleur);
}
