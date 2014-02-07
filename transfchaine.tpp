#include <sstream>
#include <string>

template <class T>

 bool  transfChaine (const string chaine, T &tmp){
    bool res = false;
    istringstream iss(chaine);
    if(iss>>tmp){
        res = true;
    }
    return res ;
    
}


template <class T>

bool verifType (const string chaine, T tmp){
    // créer un flux à partir de la chaîne donnée
    istringstream iss( chaine );
    // tenter la conversion et
    // vérifier qu'il ne reste plus rien dans la chaîne
    return ( iss >> tmp ) && ( iss.eof() );
    
}

