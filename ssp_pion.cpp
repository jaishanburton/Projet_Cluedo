#include "plateau.h"
#include "headers.h"

using namespace std;


Pion::Pion():m_posLigne(385),m_posColonne(475),m_depLigne(50),m_depColonne(50)
{

}

Pion::~Pion()
{

}

int Pion::get_POSITIONx()const
{
    return m_posLigne;
}

int Pion::get_POSITIONy()const
{
    return m_posColonne;
}

int Pion::get_DEPLACEMENTx()const
{
    return m_depLigne;
}

int Pion::get_DEPLACEMENTy()const
{
    return m_depColonne;
}

int Pion::deplacement(Partie &jeu,int numero)
{


    int LIGNE=650;
    int COLONNE=750;

    //BITMAP *doubleBuffer;
    int lancer_des=0;
    int lancer_des2=0;
    int lancer_final=0;
    int cpt=0;
    int choix_pas=0;

    int quitter=0;

    m_posColonne=jeu.getListeJoueur()[numero].getPionY();
    m_posLigne=jeu.getListeJoueur()[numero].getPionX();



    jeu.getListeJoueur()[numero].setPionX(m_posLigne);
    jeu.getListeJoueur()[numero].setPionY(m_posColonne);

    for(int i=0; i<jeu.getNombreJoueur(); i++)
    {
        blit(jeu.getListeJoueur()[i].getPion(),screen,0,0,jeu.getListeJoueur()[i].getPionX()-25,jeu.getListeJoueur()[i].getPionY()-25,jeu.getListeJoueur()[i].getPion()->w,jeu.getListeJoueur()[i].getPion()->h);

    }

    cout<<" Baptiste et Saru sont chauds, Jaishan maybe"<<endl;
    rest(250);


    lancer_des=m_De1.affichaged();
    lancer_des2=m_De2.affichaged2();
    lancer_final=lancer_des+lancer_des2;
    do
    {

//clear_bitmap(doubleBuffer);

        //Blindage du pion sur le plateau de jeu
        if(key[KEY_RIGHT])  // à droite
        {

            if(m_posLigne>= LIGNE)
            {
                m_posLigne=675;
            }
            else if(((m_posLigne>=250)&&(m_posLigne<=400))&&((m_posColonne>=50)&&(m_posColonne<=200)))  //blibliothèque coté gauche
            {
                m_posLigne=275;
            }
            else if(((m_posLigne>=250)&&(m_posLigne<=400))&&((m_posColonne>=250)&&(m_posColonne<=400)))  //salle de ball/ Entrée de jeu/ coté gauche
            {
                m_posLigne=275;
            }
            else if(((m_posLigne>=250)&&(m_posLigne<=350))&&((m_posColonne>=400)&&(m_posColonne<=450)))  //Escalier coté gauche
            {
                m_posLigne=325;
            }
            else if(((m_posLigne>=250)&&(m_posLigne<=400))&&((m_posColonne>=500)&&(m_posColonne<=650)))  //le hall coté gauche
            {
                m_posLigne=275;
            }
            else if((m_posLigne>=500)&&((m_posColonne>=50)&&(m_posColonne<=150)))  //LE BUREAU coté gauche
            {
                m_posLigne=525;
            }
            else if((m_posLigne>=500)&&(((m_posColonne>=250)&&(m_posColonne<=300))||((m_posColonne>=350)&&(m_posColonne<=400))))  //La salle de billard coté gauche
            {
                m_posLigne=525;
            }
            else if((m_posLigne>=550)&&((m_posColonne>=250)&&(m_posColonne<=400)))  //La salle de billard coté gauche
            {
                m_posLigne=575;
            }
            else if((m_posLigne>=500)&&((m_posColonne>=500)&&(m_posColonne<=600)))  //Le veranda coté gauche
            {
                m_posLigne=525;
            }
            else if(((m_posLigne>=50)&&(m_posLigne<=200))&&((m_posColonne>=100)&&(m_posColonne<=250)))  //La salle à manger normalement pas besoin de blindage pour le coté gauche
            {
                m_posLigne=75;
            }
            else if(((m_posLigne>=100)&&(m_posLigne<=200))&&((m_posColonne>=300)&&(m_posColonne<=400)))  //La CUISINE normalement pas besoin de blindage pour le coté gauche
            {
                m_posLigne=125;
            }
            else if(((m_posLigne>=50)&&(m_posLigne<=150))&&((m_posColonne>=500)&&(m_posColonne<=650)))  //Le salon normalement pas besoin de blindage pour le coté gauche
            {
                m_posLigne=75;
            }
            else
            {
                m_posLigne=m_posLigne+m_depLigne;
            }
            rest(250);
            cpt++;
        }
        else

            if(key[KEY_LEFT])   //à gauche
            {

                if(m_posLigne<150)//100
                {
                    m_posLigne=125;
                }
                else if((m_posLigne<=300)&&((m_posColonne>=100)&&(m_posColonne<=250)))  //La salle à manger pour le coté droit
                {
                    m_posLigne=225;
                }
                else if((m_posLigne<=300)&&((m_posColonne>=300)&&(m_posColonne<=400)))  //La CUISINE  pour le coté droit
                {
                    m_posLigne=225;
                }
                else if((m_posLigne<=300)&&(((m_posColonne>=500)&&(m_posColonne<=550))||((m_posColonne>=600)&&(m_posColonne<=650))))  //Le salon pour le coté droit
                {
                    m_posLigne=225;
                }
///------------------------------------------------------------------------------------------------------------------------------------------
                else if(((m_posLigne>=50)&&(m_posLigne<=250))&&((m_posColonne>=500)&&(m_posColonne<=650)))  //Pour limiter le salon côté droit
                {
                    m_posLigne=175;

                    choix_pas=passage_secret();
                    if(choix_pas==1)
                    {

                        m_posLigne=575;
                        m_posColonne=125;
                        // blit(PIONNE,screen,0,0,m_posLigne-25,m_posColonne-25,m_posLigne+25,m_posColonne+25);
                        cpt++;
                        ///coordonnées du pion dans la salle à manger
                    }
                    else if(choix_pas==0)
                    {
                        m_posLigne=175;
                    }
                    else
                    {
                        m_posLigne=175;
                    }

                }
///-------------------------------------------------------------------------------------------------------------------------------------------


                else if(((m_posLigne>=250)&&(m_posLigne<=550))&&((m_posColonne>=50)&&(m_posColonne<=200)))  //bibliothèque coté droit
                {
                    m_posLigne=475;

                }
                else if(((m_posLigne>=300)&&(m_posLigne<=550))&&((m_posColonne>=250)&&(m_posColonne<=400)))  //salle de ball/ Entrée de jeu/ coté droit
                {

                    m_posLigne=475;;

                }
                else if(((m_posLigne>=350)&&(m_posLigne<=500))&&((m_posColonne>=400)&&(m_posColonne<=450)))  //Escalier coté droit
                {
                    m_posLigne=425;

                }
                else if(((m_posLigne>=300)&&(m_posLigne<=550))&&((m_posColonne>=500)&&(m_posColonne<=650)))  //le hall coté droit
                {
                    m_posLigne=475;
                }
                else if(((m_posLigne>=500)&&(m_posLigne<=750))&&((m_posColonne>=50)&&(m_posColonne<=150)))  //LE BUREAU coté droit (blindage négligeable)
                {
                    m_posLigne=775;
                }
                else if(((m_posLigne>=600)&&(m_posLigne<=750))&&((m_posColonne>=250)&&(m_posColonne<=400)))  //La salle de billard coté droit (négligeable)
                {
                    m_posLigne=775;
                }
                else if(((m_posLigne>=500)&&(m_posLigne<=750))&&((m_posColonne>=500)&&(m_posColonne<=600)))  //Le veranda coté droit (négligeable)
                {
                    m_posLigne=775;
                }
                else

                {
                    m_posLigne=m_posLigne-m_depLigne;
                }
                rest(250);
                cpt++;
            }
            else if(key[KEY_DOWN])   //en bas
            {
                if(m_posColonne>= COLONNE)
                {
                    m_posColonne=625;
                }
                else if(((m_posLigne>=550)&&(m_posLigne<=750))&&((m_posColonne>=200)&&(m_posColonne<=400)))  //La salle de billard coté haut
                {
                    m_posColonne=225;

                }
                else if(((m_posLigne>=550)&&(m_posLigne<=750))&&((m_posColonne>=0)&&(m_posColonne<=100)))  //Le bureau coté haut (négligeable)
                {
                    m_posColonne=25;

                }
                else if(((((m_posLigne>=550)&&(m_posLigne<=600))||((m_posLigne>=650)&&(m_posLigne<=750)))&&((m_posColonne>=450)&&(m_posColonne<=600)))) //Le veranda coté haut=> entrée possible par haut milieu
                {
                    m_posColonne=475;
                }
                else
///________________________________________________________________________________________________________________________________________
                    if(((m_posLigne>=550)&&(m_posLigne<=750))&&(m_posColonne>=500))    // pour limiter le bas du veranda
                    {
                        m_posColonne=525;

                        choix_pas=passage_secret();
                        if(choix_pas==1)
                        {
                            m_posLigne=135;
                            m_posColonne=225;
                            cpt++;
                            ///coordonnées du pion dans la salle à manger
                        }
                        else if(choix_pas==0)
                        {
                            m_posColonne=525;
                        }
                        else
                        {
                            m_posColonne=525;
                        }

                    }
                    else

///________________________________________________________________________________________________________________________________________


                        if((((m_posLigne>=300)&&(m_posLigne<=350))||((m_posLigne>=400)&&(m_posLigne<=450)))&&((m_posColonne>=450)&&(m_posColonne<=600)))  //le hall haut
                        {
                            m_posColonne=475;

                        }
                        else if(((m_posLigne>=300)&&(m_posLigne<=450))&&(m_posColonne>=500))    // pour limiter le bas du hall
                        {
                            m_posColonne=525;

                        }
                        else


                            if((((m_posLigne>=300)&&(m_posLigne<=350))||((m_posLigne>=400)&&(m_posLigne<=450)))&&((m_posColonne>=200)&&(m_posColonne<=400)))  //salle de ball/ Entrée de jeu/ coté haut
                            {
                                m_posColonne=225;

                            }
                            else if(((m_posLigne>=300)&&(m_posLigne<=450))&&((m_posColonne>=250)&&(m_posColonne<=400)))   // pour limiter le bas de la salle de ball
                            {
                                m_posColonne=275;

                            }
                            else


                                if(((m_posLigne>=300)&&(m_posLigne<=450))&&((m_posColonne>=50)&&(m_posColonne<=150)))  //La biblio coté haut (négligeable)
                                {
                                    m_posColonne=25;

                                }
                                else

                                    if(((m_posLigne>=50)&&(m_posLigne<=200))&&((m_posColonne>=100)&&(m_posColonne<=200)))  //La salle à manger coté haut (négligeable)
                                    {
                                        m_posColonne=125;
                                    }
                                    else

                                        if(((m_posLigne>=100)&&(m_posLigne<=200))&&((m_posColonne>=250)&&(m_posColonne<=350)))  //La cuisine coté haut
                                        {
                                            m_posColonne=275;

                                        }
                                        else if(((m_posLigne>=50)&&(m_posLigne<=200))&&((m_posColonne>=450)&&(m_posColonne<=650)))  //Le salon coté haut (négligeable)
                                        {
                                            m_posColonne=475;
                                        }
                                        else

                                            if((m_posColonne>=550))    //limiter le bas du plateau
                                            {
                                                m_posColonne=575;

                                            }
                                            else
                                            {
                                                m_posColonne=m_posColonne+m_depColonne;
                                            }
                rest(250);
                cpt++;
            }
            else if(key[KEY_UP]) //en haut
            {
                if(m_posColonne<100)
                {
                    m_posColonne=80;
                }
                else

                    if((((m_posLigne>=300)&&(m_posLigne<=350))||(((m_posLigne>=400)&&(m_posLigne<=450))))&&((m_posColonne>=50)&&(m_posColonne<=250)))  //La biblio coté bas
                    {
                        m_posColonne=225;

                    }
                    else
///-----------------------------------------------------------------------------------------------------------------------------
                        if(((m_posLigne>=300)&&(m_posLigne<=450))&&(m_posColonne<=200))    // pour limiter le bas de la biblio
                        {
                            m_posColonne=175;

                        }
                        else
///-----------------------------------------------------------------------------------------------------------------------------
                            if((((m_posLigne>=50)&&(m_posLigne<=100))||((m_posLigne>=150)&&(m_posLigne<=200)))&&((m_posColonne>=100)&&(m_posColonne<=300)))  //La salle à manger coté bas
                            {
                                m_posColonne=275;

                            }
                            else

                                if(((m_posLigne>=50)&&(m_posLigne<=200))&&(m_posColonne<=250))    // pour limiter le bas de la salle à manger
                                {
                                    m_posColonne=225;

                                    choix_pas=passage_secret();
                                    if(choix_pas==1)
                                    {
                                        m_posLigne=625;
                                        m_posColonne=525;
                                        cpt++;
                                        ///coordonnées du pion dans la salle à manger
                                    }
                                    else if(choix_pas==0)
                                    {
                                        m_posColonne=225;
                                    }
                                    else
                                    {
                                        m_posColonne=225;
                                    }

                                }
                                else

                                    if(((m_posLigne>=100)&&(m_posLigne<=150))&&((m_posColonne>=300)&&(m_posColonne<=450)))  //La cuisine coté bas
                                    {
                                        m_posColonne=425;

                                    }
                                    else if(((m_posLigne>=100)&&(m_posLigne<=200))&&((m_posColonne>=300)&&(m_posColonne<=450)))  //pour limiter le bas de La cuisine
                                    {
                                        m_posColonne=375;

                                    }
                                    else

                                        if(((m_posLigne>=600)&&(m_posLigne<=750))&&((m_posColonne>=0)&&(m_posColonne<=200)))  //Le bureau coté bas
                                        {
                                            m_posColonne=175;

                                        }
                                        else if(((m_posLigne>=550)&&(m_posLigne<=750))&&(m_posColonne<=150))  //Pour limiter le bureau coté bas
                                        {
                                            m_posColonne=125;

                                            choix_pas=passage_secret();
                                            if(choix_pas==1)
                                            {
                                                m_posLigne=175;
                                                m_posColonne=575;
                                                cpt++;
                                                ///coordonnées du pion dans la salle à manger
                                            }
                                            else if(choix_pas==0)
                                            {
                                                m_posColonne=125;
                                            }
                                            else
                                            {
                                                m_posColonne=125;
                                            }

                                        }
                                        else

                                            if(((m_posLigne>=550)&&(m_posLigne<=750))&&((m_posColonne>=250)&&(m_posColonne<=450)))  //La salle de billard coté bas
                                            {
                                                m_posColonne=425;

                                            }
                                            else


                                                if((m_posColonne<=150))  // limiter le haut du plateau
                                                {
                                                    m_posColonne=125;

                                                }
                                                else

                                                {
                                                    m_posColonne=m_posColonne-m_depColonne;

                                                }
                cpt++;
                rest(250);
            }
        jeu.getListeJoueur()[numero].setPionX(m_posLigne);
        jeu.getListeJoueur()[numero].setPionY(m_posColonne);

        for(int i=0; i<jeu.getNombreJoueur(); i++)
        {
            blit(jeu.getListeJoueur()[i].getPion(),screen,0,0,jeu.getListeJoueur()[i].getPionX()-25,jeu.getListeJoueur()[i].getPionY()-25,jeu.getListeJoueur()[i].getPion()->w,jeu.getListeJoueur()[i].getPion()->h);

        }


        rest(250);
        cout<<" Position du pion : "<<endl<<"x: "<<m_posLigne<<endl<<"y: "<<m_posColonne<<endl;
        cout<<endl;


        if(key[KEY_ESC]||(cpt==lancer_final))
        {
            quitter=1;
        }


    }
    while(!key[KEY_ESC]&&(cpt<lancer_final));


    return quitter;

}

int Pion::passage_secret()
{

    int number_choice;


    do
    {
        cout<<" Voulez-vous utiliser le passage secret pour aller dans la salle qui se trouve a la diagonale? "<<endl;
        cin>>number_choice;
    }
    while((number_choice<0)||(number_choice>1));



    return number_choice;

}

