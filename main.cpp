#include "headers.h"

using namespace std;

int main()
{
    /*** Variables ***/
    string nom_sauvegarde;
    int choix=0;
    /*****************/

    srand(time(NULL));

    Deroulement PARTIE;


    PARTIE.initilisationAllegro();

    PARTIE.choix();
    /****** MENU *****/
    do
    {
        choix=PARTIE.new_menu();
        if(choix==1)   ///Nouvelle partie
        {
            Partie jeu;
            PARTIE.deroule(jeu);

        }
        else if(choix==2)  ///Partie chargée
        {
            textprintf_ex(screen,font,SCREEN_W/2,SCREEN_H/2,makecol(255,255,255),-1,"Saisir dans la console...");
            cout<<" Nom de la partie a charger : ";
            cin>>nom_sauvegarde;

            Partie sauvegarder(nom_sauvegarde);
            PARTIE.deroule(sauvegarder);

        }
        else if(choix==3)
        {
            PARTIE.aide();
            PARTIE.echap();
        }

        rest(2000);
    }
    while(choix!=4);
    /***********************/



    return 0;
}
END_OF_MAIN();
