
//---------- Interface de la classe <Document> (fichier Document.h) ------
#if ! defined ( DOCUMENT_H_ )
#define DOCUMENT_H_
using namespace std;
//--------------------------------------------------- Interfaces utilis?es
#include <string>
#include <map>
#include <iostream>
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// R?le de la classe <Document>
//
//
//------------------------------------------------------------------------ 

class Document
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- M?thodes publiques
    string toString ();
    // Mode d'emploi : met a jour, a chaque ligne, l'url du document si
    // celle-ci existe deja dans la map
    // Contrat : on considere que l'URL est conforme a l'exemple donne
    // sur le sujet
    
    long calculerNbHits ();
    // Mode d'emploi : parcours la map de referer afin de compter le nombre
    // total de hits associes aux documents

    void addReferer (string urlReferer);
    // Mode d'emploi : sert à ajouter un url referer associe au document
    // ou à incrementer le nb de hits pour un referer existant
//------------------------------------------------- Surcharge d'op?rateurs
    //friend bool operator == ( const Document & a ,const Document & b );
	// Mode d'emploi :
	// Redéfinition de l'opérateur ==.
	//
	// Contrat :
	//

    friend bool operator< (const Document &a, const Document &b);
	// Mode d'emploi :


//-------------------------------------------- Constructeurs - destructeur
    Document ( const Document & unDocument );
    // constructeur de copie

    Document (string urlParam);
    // Mode d'emploi : cree la classe Document

    virtual ~Document ( );
    // Mode d'emploi : detruit la classe Document
   

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- M?thodes prot?g?es

//----------------------------------------------------- Attributs prot?g?s
    string url;
    long taille;
    string date;
    map <string, int> referers;
    long nbHits;
    //---------------------------------------------------------- Classes amies
    friend class Fichier;
    //permet a Fichier d'utiliser les methodes de Document


};

//--------------------------- Autres d?finitions d?pendantes de <Document>

#endif // DOCUMENT_H_

