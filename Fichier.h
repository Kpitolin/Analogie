
//---------- Interface de la classe <Fichier> (fichier Fichier.h) ------
#if ! defined ( FICHIER_H_ )
#define FICHIER_H_

using namespace std;
//--------------------------------------------------- Interfaces utilis?es

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <map>
#include "Document.h"
//------------------------------------------------------------- Constantes

const int POSITION_DATE = 3;
const int POSITION_URLDOC = 6;
const int POSITION_CODERETOUR = 8;
const int POSITION_URLREFERER = 10;
const int POSITION_SYSTEME = 12;
const int POSITION_NAVIGATEUR = 18;




const string CODEOK = "200";

//on crée une liste d'extensions inutiles
const vector<string> listExtensionsInutiles=
{"bmp","css","tif","js","gif","jpg","jpeg","ico","png"} ;

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// R?le de la classe <Fichier>
//
//
//------------------------------------------------------------------------ 

class Fichier
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- M?thodes publiques
    vector <string> decoupeLigne (string ligne);
    // Mode d'emploi : decoupe la ligne selon les espaces et place chaque
    // sous chaine dans une case du vector
    // Contrat : on considere que la syntaxe d'une ligne est toujours celle
    // de l'exemple donnee dans le sujet
    
    void analyseLigne(string ligne,long nbHitsAnalyse,int heureAnalyse,string nomFichierDot);
    // Mode d'emploi : analyse la ligne en prenant en compte les options en
    // ligne de commande et le code de retour du document
    
    void analyseFichier(long nbHitsAnalyse = 0,int heureAnalyse = 0, string nomFichierDot = "");
    // Mode d'emploi : analyse toutes les lignes du fichier
    
    void genererFichierDot (string nomDot);
    // Mode d'emploi : cree un fichier dot quand l'option -g est presente
    
    void afficheDocConsult ();
    // Mode d'emploi : affiche les dix documents les plus consultes par
    // ordre decroissant
    
    bool inutiliteFichier(string nomFichier);
    // Mode d'emploi : verifie que le fichier ne fait pas partie
    // des types de fichiers ignorés

    int extraitDate (string date);
//------------------------------------------------- Surcharge d'op?rateurs
  


//-------------------------------------------- Constructeurs - destructeur
    Fichier ( const Fichier & unFichier );
    // constructeur de copie

    Fichier ( string cheminAccesFichier ,vector<bool> options);
    // Mode d'emploi : cree la classe Fichier

    virtual ~Fichier ( );
    // Mode d'emploi : detruit la classe Fichier


//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- M?thodes prot?g?es

//----------------------------------------------------- Attributs prot?g?s
    string cheminAcces;
    vector <bool> optionsActives;
    map <Document*,long > documents;
//---------------------------------------------------------- Classes amies
    friend class CreateurFichier;
    //permet a CreateurFichier d'utiliser les methodes de Fichier

};

//--------------------------- Autres d?finitions d?pendantes de <Fichier>

#endif // FICHIER_H_

