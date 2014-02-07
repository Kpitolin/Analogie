/*************************************************************************
                           Fichier  -  description
                             -------------------
    d?but                : 6 f?vr. 2014
    copyright            : (C) 2014 par KEV
*************************************************************************/

//---------- R?alisation de la classe <Fichier> (fichier Fichier.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst?me


//------------------------------------------------------ Include personnel
#include "Fichier.h"

//------------------------------------------------------------- Constantes
const int TYPE_FICHIER_INUTILE = 0;
const int GENERATION_DOT = 1;
const int VERIF_HORAIRE = 2;
const int VERIF_NB_HITS = 3;
//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types priv?s


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- M?thodes publiques
vector <string> Fichier::decoupeLigne (string ligne)
// Algorithme :
//
{
    istringstream iss (ligne);
    vector<string> stockage;
    while (getline(iss,ligne,' ')){
        stockage.push_back(ligne);

    }

    return stockage;
} //----- Fin de M?thode

void Fichier::analyseLigne(string ligne,long nbHitsAnalyse,int heureAnalyse,string nomFichierDot)
{
    vector <string> tableauInfos = decoupeLigne(ligne);
    if (tableauInfos [POSITION_CODERETOUR] == CODEOK){
        
    
    if (optionsActives[TYPE_FICHIER_INUTILE]){

        if( !inutiliteFichier( tableauInfos [POSITION_URLDOC]) ){

            

            if( extraitDate( tableauInfos [POSITION_DATE]) == heureAnalyse  ){
                // dans ce cas on crée un doc
                cout << "cool"<<endl;
                
                //if(documents.find(tableauInfos [POSITION_URLDOC]) != documents.end()){
                   // map<Document,long>::iterator iter =documents.find(tableauInfos [POSITION_URLDOC]);
                    //documents[iter->first]++;
                  //  tableauInfos [POSITION_URLREFERER];
            

                }else {
                  //  Document *doc = new Document(tableauInfos [POSITION_URLDOC]);
                    //documents[doc]=1;

                }
                

            }
            
            
        }

    }
    
    
        

    
    
    


    
    
    
} //----- Fin de M?thode


void Fichier::analyseFichier(long nbHitsAnalyse,int heureAnalyse, string nomFichierDot)
{
    ifstream fichier(cheminAcces,ios::in);  // on ouvre en lecture
    string ligne;
    if(fichier){
       
        while(getline(fichier, ligne)){
            analyseLigne(ligne,nbHitsAnalyse, heureAnalyse, nomFichierDot);
        }
    }
    
    
} //----- Fin de M?thode

void Fichier::genererFichierDot (string nomDot)
{
} //----- Fin de M?thode


void Fichier::afficheDocConsult ()
{
    //for (vector<string>::iterator iter = tableauInfos.begin(); iter!=tableauInfos.end();++iter){

} //----- Fin de M?thode

bool verifExtension (string extension, string nomFichier){
    bool MethodeBienExecutee = false;
    long indexPoint;
    indexPoint =nomFichier.find_last_of('.');
    
    
    string extensionReelle = nomFichier.substr(indexPoint+1,string::npos);
    
    if (extensionReelle == extension ){
        MethodeBienExecutee = true;
    }
    
    return MethodeBienExecutee;
}


bool Fichier::inutiliteFichier(string nomFichier){
    bool ficInutile = false;
    for (int i =0; i<listExtensionsInutiles.size() ; i++) {
        if(verifExtension(listExtensionsInutiles[i], nomFichier)){
            ficInutile = true;
            break;
        }
        
    }
    return ficInutile;
}

int Fichier::extraitDate (string date){
    
    long debutDate = date.find(':') +1;
    long finDate = date.find(':',debutDate)-1;
    date = date.substr(debutDate,finDate);
    istringstream iss (date);
    int entier;
    iss >> entier;
    return entier;
}
//------------------------------------------------- Surcharge d'op?rateurs


//-------------------------------------------- Constructeurs - destructeur
Fichier::Fichier ( const Fichier & unFichier )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Fichier>" << endl;
#endif
} //----- Fin de Fichier (constructeur de copie)


Fichier::Fichier (string cheminAccesFichier , vector<bool> options)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Fichier>" << endl;
#endif
    
    cheminAcces = cheminAccesFichier ;
    optionsActives = options;
    
    
} //----- Fin de Fichier


Fichier::~Fichier ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Fichier>" << endl;
#endif
} //----- Fin de ~Fichier


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- M?thodes prot?g?es

//------------------------------------------------------- M?thodes priv?es
