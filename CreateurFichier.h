
//---------- Interface de la classe <CreateurFichier> (fichier CreateurFichier.h) ------
#if ! defined ( CREATEURFICHIER_H_ )
#define CREATEURFICHIER_H
using namespace std;

//--------------------------------------------------- Interfaces utilis?es
#include "Fichier.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>

//------------------------------------------------------------- Constantes


const char TIRET ='-';
const string ERR = "Erreur de syntaxe : commande invalide";
const int HEUREMAX = 24;
const string EXTLOG = "log";
const string EXTDOT = "dot";
const int TYPE_FICHIER_INUTILE = 0;
const int GENERATION_DOT = 1;
const int VERIF_HORAIRE = 2;
const int VERIF_NB_HITS = 3;
const vector<string> OPTIONS
// liste les differentes options et permet plus facilement d'en rajouter
// reutilisabilite !
{
    "-x",
    "-g",
    "-t",
    "-l"
};



//------------------------------------------------------------------ Types

//------------------------------------------------------------------------ 
// R?le de la classe <CreateurFichier>
//
//
//------------------------------------------------------------------------ 

class CreateurFichier
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- M?thodes publiques
    bool analyseArgument ();
    // Mode d'emploi : verifie la conformite de la syntaxe de la commande
    // Contrat : on considere que le fichier log est toujours a la fin

    bool creeFichier();
    // Mode d'emploi: on cree une instance de Fichier avec pour chemin
    // d'acces celui precise dans la commande.
    //Si le fichier n'exite pas ou que le chemin d'acces est incorrecte
    // cette methode renvoie faux.

    bool verifExtension (string extension, string nomFichier);
    //  Mode d'emploi: Verifie que l'extension du fichier traite est conforme
    // a celle prise en parametre
    bool verifFichier (string extension, string nomFichier);
    //  Mode d'emploi: verifie la conformite du fichier
    // (bonne extension + existence)
    
    vector<bool> traiteOptions ();
    //  Mode d'emploi: Renvoie un tableau de booléens permettant d'identifier
    //  les options actives (dans l'ordre précisé par l'enum Options)

//------------------------------------------------- Surcharge d'op?rateurs


//-------------------------------------------- Constructeurs - destructeur
    CreateurFichier ( const CreateurFichier & unCreateurFichier );
    // constructeur de copie

    CreateurFichier (int argc, char * lstarg[]);
    // Mode d'emploi : cree la classe CreateurFichier

    virtual ~CreateurFichier ( );
    // Mode d'emploi : detruit la classe CreateurFichier


//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- M?thodes prot?g?es

//----------------------------------------------------- Attributs prot?g?s
    vector <string> listeArguments;
    int nbArgs;
    int nbhits;
    int heure;
    string nomFichierDot;

};

//--------------------------- Autres d?finitions d?pendantes de <CreateurFichier>
#include "transfchaine.tpp"

#endif // CREATEURFICHIER_H_

