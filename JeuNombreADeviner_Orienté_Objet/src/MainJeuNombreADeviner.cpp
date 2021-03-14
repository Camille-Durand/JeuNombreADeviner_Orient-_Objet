/*************************************************/
// Nom du projet: Jeu du nombre � deviner
// Nom du fichier: MainJeuNombreAdeviner.cpp
// Version : 1.0
// Nom du programmeur: MP Pinaud
// Date de cr�ation : 05/02/2021
// R�le du fichier: Contient le code jeu
// Nom des composants utilises: CPartie
//                              CJoueur
//                              iostream
// Historique du fichier:
/*************************************************/
#include <iostream>
using namespace std;

#include "../include/Partie.h"

int main()
{

    //Cr�ation d'un joueur
    cout << "Vous allez jouer pour deviner un nombre secret" << endl;
    cout << "----------------------------------------------"<< endl;
    cout << "Veuillez entrer le nom du Joueur1" << endl;
    string un_nom;
    cin >> un_nom;
    CJoueur joueur (un_nom);

    // Cr�ation d'un 2�me joueur
    cout << "----------------------------------------------"<< endl;
    cout << "Veuillez entrer le nom du Joueur2" << endl;
    string un_nom2;
    cin >> un_nom2;
    CJoueur joueur2 (un_nom2);


    cout << "----------------------------------------------"<< endl;
    cout << "Combien de parties voulez-vous jouer ?" << endl;
    int nbParties;
    cin >> nbParties;



    for (int i = 0; i <nbParties; i++)
    {
        cout << "----------------------------------------------"<< endl;
        cout <<"Partie Numero : " << i+1 << endl;
        cout << "----------------------------------------------"<< endl;

        CPartie partie (0,10,4); // nombre � deviner entre 0 et 10, nombre de tentatives maximum 4

        partie.Jouer(joueur); // ex�cution d'une partie pour le joueur1
        partie.Jouer(joueur2); // ex�cution d'une partie pour le joueur2
    }


    cout << "----------------------------------------------"<< endl;
    cout << "Affichage des resultats du joueur "<< joueur.Nom() << endl;
    cout << "----------------------------------------------"<< endl;
    // R�cup�ration des r�sultats du joueur1
    int nbsucces, nbechecs, nbessais;
    joueur.Resultats(nbsucces, nbechecs, nbessais);  // les param�tres sont pass�s par r�f�rence
    // Affichage des r�sultats
    cout << "Nombre de parties gagnees : " << nbsucces << endl;
    cout << "Nombre de parties perdues : " << nbechecs << endl;
    cout << "Nombre de tentatives totales : " << nbessais << endl;
    cout << "----------------------------------------------"<< endl;

    cout << "----------------------------------------------"<< endl;
    cout << "Affichage des resultats du joueur "<< joueur2.Nom() << endl;
    cout << "----------------------------------------------"<< endl;


    int nbsucces2, nbechecs2, nbessais2; // R�cup�ration des r�sultats du joueur2
    joueur2.Resultats(nbsucces2, nbechecs2, nbessais2);  // les param�tres sont pass�s par r�f�rence
    // Affichage des r�sultats
    cout << "Nombre de parties gagnees : " << nbsucces2 << endl;
    cout << "Nombre de parties perdues : " << nbechecs2 << endl;
    cout << "Nombre de tentatives totales : " << nbessais2 << endl;
    cout << "----------------------------------------------"<< endl;

    // Indiquer quel joueur a gagn�
    if (nbsucces2>nbsucces)
        cout << joueur2.Nom() << "a gagn�!" << endl;
    else if (nbsucces2<nbsucces)
        cout << joueur.Nom() << "a gagn�!" << endl;
    else
        cout << joueur.Nom() << " et " << joueur2.Nom() << "sont ex-aequo!" << endl;

    cout << "----------------------------------------------"<< endl;

    return 0;
}


