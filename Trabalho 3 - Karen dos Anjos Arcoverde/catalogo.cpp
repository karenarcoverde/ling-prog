/*****************************************************************************/
/***************************** Arquivo catalogo.cpp **************************/

#include "catalogo.h"

ostream &operator<<(ostream &saida, const Catalogo &catalogo){
    for (int indice_filmes = 0; indice_filmes < catalogo.conjuntoDeFilmes.size(); indice_filmes++)
        saida << catalogo.conjuntoDeFilmes.at(indice_filmes);
    
    return saida;
};

bool operator>(const filme &primfilme, const filme &segfilme){
    if (primfilme.nomeDoFilme > segfilme.nomeDoFilme) 
        return true;

    return false;
};

bool operator==(const filme &primfilme, const filme &segfilme){
    if (primfilme.nomeDoFilme == segfilme.nomeDoFilme) 
        return true;

    return false;
};

bool operator>(const filme &item_filme, const double &notaDoFilme){
    if (item_filme.notaDoFilme > notaDoFilme) 
        return true;

    return false;
}
