/*****************************************************************************/
/***************************** Arquivo catalogo.cpp **************************/

#include "catalogo.h"

ostream &operator<<(ostream &saida, const Catalogo &catalogo){
    for (int indice_filmes = 0; indice_filmes < catalogo.conjuntoDeFilmes.size(); indice_filmes++)
        saida << catalogo.conjuntoDeFilmes.at(indice_filmes);
    
    return saida;
}

bool operator>(const filme &primfilme, const filme &segfilme){
    if (primfilme.nomeDoFilme > segfilme.nomeDoFilme) 
        return true;

    return false;
}

bool operator==(const filme &primfilme, const filme &segfilme){
    if (primfilme.nomeDoFilme == segfilme.nomeDoFilme) 
        return true;

    return false;
}

bool operator>(const filme &item_filme, const double &notaDoFilme){
    if (item_filme.notaDoFilme > notaDoFilme) 
        return true;

    return false;
}

void Catalogo::ExibeFilmeBemAvaliado(){
    filme filmeBemAvaliado;
    filmeBemAvaliado.notaDoFilme = 0;

    for (int indice_conjunto_filmes = 0; indice_conjunto_filmes < conjuntoDeFilmes.size(); indice_conjunto_filmes++){
        if (conjuntoDeFilmes.at(indice_conjunto_filmes) > filmeBemAvaliado.notaDoFilme) 
            filmeBemAvaliado = conjuntoDeFilmes.at(indice_conjunto_filmes);
    }
    cout << "O filme mais bem avaliado eh:" << filmeBemAvaliado << endl;
}

void Catalogo::RenovarCatalogo(){
    fstream file;
    file.open(nomeArquivo, fstream::out);

    if (!file.is_open()){
        cout << "Arquivo nao existe." << endl;
        exit (0);
    }

    //reescreve com as novas alteracoes 
    for (int indice_conjunto_filmes = 0; indice_conjunto_filmes < conjuntoDeFilmes.size(); indice_conjunto_filmes++){
        file << conjuntoDeFilmes.at(indice_conjunto_filmes).nomeDoFilme << ',';
        file << conjuntoDeFilmes.at(indice_conjunto_filmes).nomeDaProdutora << ',';
        file  << conjuntoDeFilmes.at(indice_conjunto_filmes).notaDoFilme<< endl;
    }

    file.close();
}
