/*************************************************************************
                           Document  -  description
                             -------------------
    d?but                : 6 f?vr. 2014
    copyright            : (C) 2014 par KEV
*************************************************************************/

//---------- R?alisation de la classe <Document> (fichier Document.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst?me
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Document.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types priv?s


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- M?thodes publiques
void Document::setURL ()
// Algorithme :
//
{
} //----- Fin de M?thode

long Document::calculerNbHits ()
{
    return 0;
} //----- Fin de M?thode


//------------------------------------------------- Surcharge d'op?rateurs
bool operator==(const Document & a, const Document & b)
// Algorithme :
//
{
	bool res;
	a.url == b.url ? res = true : res = false;
	return res;
}


//-------------------------------------------- Constructeurs - destructeur
Document::Document ( const Document & unDocument )
// Algorithme :
//
{
    
#ifdef MAP
    cout << "Appel au constructeur de copie de <Document>" << endl;
#endif
} //----- Fin de Document (constructeur de copie)


Document::Document (string urlParam)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Document>" << endl;
#endif
    
    
    url = urlParam;
} //----- Fin de Document


Document::~Document ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Document>" << endl;
#endif
} //----- Fin de ~Document


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- M?thodes prot?g?es

//------------------------------------------------------- M?thodes priv?es
