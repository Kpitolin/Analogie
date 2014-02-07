/*************************************************************************
                           CreateurFichier  -  description
                             -------------------
    d?but                : 6 f?vr. 2014
    copyright            : (C) 2014 par KEV
*************************************************************************/

//---------- R?alisation de la classe <CreateurFichier> (fichier CreateurFichier.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst?me


//------------------------------------------------------ Include personnel
#include "CreateurFichier.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types priv?s


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- M?thodes publiques

bool CreateurFichier::verifExtension (string extension, string nomFichier){
    bool MethodeBienExecutee = false;
    long indexPoint;
    indexPoint =nomFichier.find_last_of('.');
    
    
    string extensionReelle = nomFichier.substr(indexPoint+1,string::npos);
    
    if (extensionReelle == extension ){
        MethodeBienExecutee = true;
    }
    
    return MethodeBienExecutee;
}


bool CreateurFichier::verifFichier (string extension, string nomFichier){
    // Algorithme :
    bool methodeBienExecutee = false;
    
    
    if (!verifExtension(extension, nomFichier) ){
        
        cout<< "le type de fichier est invalide. Insérez un fichier de type "<< extension <<endl;
    }else {
        //verification conformité du fichier (existe à ce chemin et peut etre ouvert)
        ifstream verifOuverture(nomFichier.c_str());
        if(verifOuverture.fail()){
            cout<<"Impossible de trouver le fichier "<<nomFichier<< ". Vérifiez le chemin d'accès."<<endl;
        }else {
            methodeBienExecutee=true;
        }
        
    }
    
    return methodeBienExecutee;
}


bool CreateurFichier::analyseArgument ()
// Algorithme :
//
{
    bool methodeBienExecutee = false;
    
    int nbArgsValide=0;
    
    int nbMinArgs = 1;
    string chaine =  listeArguments[nbArgs-1]; // on récupère le nom du fichier log

    
    if (nbArgs < nbMinArgs){
        cout<<ERR <<endl;
        
    }else{
        
        
        
        // on vérifie si on a bien un fichier log (existant) comme dernier argument
        if( verifFichier(EXTLOG, chaine)){
            
            nbArgsValide++;
        }else{
            cout<< "Insérez un nom de fichier LOG valide"<<endl;
            return methodeBienExecutee;
        }
        
        
        if(nbArgs>nbMinArgs){
            
            for(int i=0; i<nbArgs-1; i++){
                const string chaine2 =  listeArguments[i+1];
                
                istringstream iss (chaine2);
                
                if(listeArguments[i]==OPTIONS[GENERATION_DOT]){
                    if(verifExtension (EXTDOT, listeArguments[i+1])){ ;
                        nomFichierDot =listeArguments[i+1];
                        nbArgsValide+=2;
                        i++;
                    }
                    
                    
                }else if(listeArguments[i]==OPTIONS[VERIF_NB_HITS]){
                    
                    iss>>nbhits ;
                    if(verifType(chaine2,nbhits) && nbhits>=0){
                        nbArgsValide+=2;
                        i++;
                    }
                    
                }else if(listeArguments[i]==OPTIONS[VERIF_HORAIRE]){
                    iss>>heure;
                    if(verifType(chaine2,heure) && heure>=0 && heure<HEUREMAX){
                        nbArgsValide+=2;
                        i++;
                    }
                    
                }else if(listeArguments[i]==OPTIONS[TYPE_FICHIER_INUTILE]){
                    nbArgsValide++;
                    
                }
            }
        }
        
    }
    
    if(nbArgs==nbArgsValide && nbArgs!=0){
        methodeBienExecutee=true;
    }else{
        cout<<ERR<<endl ;
    }
    
    
    return methodeBienExecutee;
} //----- Fin de M?thode




bool CreateurFichier::creeFichier()
{
    if(analyseArgument())
    {
        Fichier fichier1 (listeArguments[nbArgs-1],traiteOptions());
       
        fichier1.analyseFichier(nbhits,heure,nomFichierDot);
        return true;
    }
    return false;
} //----- Fin de M?thode





vector<bool> CreateurFichier::traiteOptions (){
    vector <bool> options(OPTIONS.size());
    for (int i=0; i< listeArguments.size(); i++)
    {
        for (int j=0; j< OPTIONS.size(); j++){
            
            if (listeArguments[i].find(TIRET)!= -1 && listeArguments[i]==OPTIONS[j]){
                options[j]=true;
                break;
            }else if (listeArguments[i].find(TIRET)!= -1){
                options[j]=false;

            }

        }

    }
    

    return options;
}//----- Fin de M?thode




//------------------------------------------------- Surcharge d'op?rateurs



//-------------------------------------------- Constructeurs - destructeur
CreateurFichier::CreateurFichier ( const CreateurFichier & unCreateurFichier )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <CreateurFichier>" << endl;
#endif
} //----- Fin de CreateurFichier (constructeur de copie)


CreateurFichier::CreateurFichier (int argc, char * lstarg[])
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <CreateurFichier>" << endl;
#endif
    nbArgs = argc-1;
    listeArguments = vector <string> (lstarg+1,lstarg+argc);
    heure = 0;
    nbhits = 0;
   

} //----- Fin de CreateurFichier


CreateurFichier::~CreateurFichier ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <CreateurFichier>" << endl;
#endif
} //----- Fin de ~CreateurFichier


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- M?thodes prot?g?es

//------------------------------------------------------- M?thodes priv?es
