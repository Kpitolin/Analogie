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
bool inf (const Document * a ,const Document * b){
    return *a<*b;
}



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
        
        if (optionsActives[TYPE_FICHIER_INUTILE] && optionsActives [VERIF_HORAIRE]){
            
            if( !inutiliteFichier( tableauInfos [POSITION_URLDOC]) && extraitDate( tableauInfos [POSITION_DATE]) == heureAnalyse  ){
                
                addDocument(tableauInfos);
                
            }
        }else if (optionsActives[TYPE_FICHIER_INUTILE]){
            if( !inutiliteFichier( tableauInfos [POSITION_URLDOC]) ){
                addDocument(tableauInfos);
                
            }
            
        }else if (optionsActives[VERIF_HORAIRE]){
            if( extraitDate( tableauInfos [POSITION_DATE]) == heureAnalyse  ){
                addDocument(tableauInfos);
                
                
            }
            
            
        }else {
            // ici on a pas d'option
            
            addDocument(tableauInfos);

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
        afficheDocConsult();
        if (nomFichierDot!=""){
            genererFichierDot(nomFichierDot);
        }
    }
    
    
} //----- Fin de M?thode

void Fichier::genererFichierDot (string nomDot)
{
    
    ofstream fluxFichier(nomDot, ios::out);
    ostringstream fluxFichierTemp;
    int iDoc = 0;
    int jRef = 0;
    int debutBoucle = 0;
    

    if(fluxFichier && fluxFichierTemp){
        fluxFichier<<"digraph {"<<endl;
      
        for(map<string,Document*>::iterator iter=documents.begin();  iter!= documents.end(); ++iter){
            fluxFichier<<"node"<< iDoc <<" [label=\""<<iter->first<<"\"];"<<endl;
            
            
            for(map<string,int>::iterator iter2 =iter->second->referers.begin(); iter2 != iter->second->referers.end(); ++iter2){
                
                
                if(debutBoucle==0 ){
                    jRef=iDoc+1;
                }
                
                    fluxFichier<<"node"<< jRef <<" [label=\""<<iter2->first<<"\"];"<<endl;
                    
                    fluxFichierTemp<<"node"<<iDoc<<
                    " -> "<<"node"<<jRef <<" [label=\""<<iter2->second<<"\"];"<<endl;
                
                jRef++;
                debutBoucle++;
                
            }
            
            iDoc=jRef+1;
            debutBoucle = 0;
            
            
                    }
        fluxFichier << fluxFichierTemp.str();
        fluxFichier<<"}";
        
        fluxFichier.close();
        
        cout<<"Le fichier "<<nomDot<<" a bien ete genere"<<endl;
        
    } else {
        cout<<"Impossible d'ecrire sur le fichier"<<nomDot<<endl;
    }
    
 
    
} //----- Fin de M?thode



void Fichier::afficheDocConsult (int nbDocsPlusConsultes)
{
    
    listDocs.sort(inf);
    listDocs.reverse();
    list<Document*>::iterator iter = listDocs.begin();
    cout <<"Liste des "<< nbDocsPlusConsultes<<" les plus consultes" <<endl;
    for(int i = 0; i< nbDocsPlusConsultes; i++){
        if (iter!= listDocs.end()) {
            
        cout << i+1<< " : " << (*iter)->toString()<< " :: " <<(*iter)->calculerNbHits() <<endl  ;
       if (i !=nbDocsPlusConsultes) ++iter;
    }
    
    }
    
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




void Fichier::addDocument (vector <string> tableauInfos){
    if (documents.find(tableauInfos [POSITION_URLDOC])!= documents.end()){
        map<string,Document*>::iterator iter =documents.find(tableauInfos [POSITION_URLDOC]);
        iter->second->addReferer(tableauInfos [POSITION_URLREFERER]);
    }else{
        Document *doc = new Document(tableauInfos [POSITION_URLDOC]);
        doc->addReferer(tableauInfos [POSITION_URLREFERER]);
        documents[tableauInfos [POSITION_URLDOC]]=doc;
        listDocs.push_back(doc);

    }
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
    
        for (map<string,Document*>::iterator iter = documents.begin(); iter!=documents.end();++iter ) {
            delete (iter->second);
        }

    
    
    
    
} //----- Fin de ~Fichier



// ...


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- M?thodes prot?g?es

//------------------------------------------------------- M?thodes priv?es
