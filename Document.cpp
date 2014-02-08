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
string Document::toString ()
// Algorithme :
//
{
    return url;
} //----- Fin de M?thode

long Document::calculerNbHits ()
{
    
     //nbHits ++;
    nbHits = 0;
    for ( map <string, int>::iterator iter = referers.begin(); iter!=referers.end();++iter){
       nbHits+= iter->second ;
    }
    return nbHits;
} //----- Fin de M?thode

void Document::addReferer (string urlReferer){
    if (referers.find(urlReferer)!= referers.end()){
        referers[urlReferer]++;
    }else{
        referers[urlReferer]=1;
    }
    calculerNbHits();
}

//------------------------------------------------- Surcharge d'op?rateurs
//bool operator==(const Document & a, const Document & b)
//// Algorithme :
////
//{
//	bool res;
//	a.url == b.url ? res = true : res = false;
//	return res;
//}

bool operator<(const Document & a ,const Document & b)
// Algorithme :
//
{
	bool res;
	a.nbHits < b.nbHits ? res = true : res = false;
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
    nbHits = 0;
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
