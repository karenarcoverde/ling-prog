/*****************************************************************************/
/***************************** Arquivo filme.cpp *****************************/


#include "filme.h"

istream &operator>>(istream &entrada, filme &item_filme){

    getline(entrada, item_filme.nomeDoFilme);
    getline(entrada, item_filme.nomeDaProdutora);


    entrada >> item_filme.notaDoFilme;

    return entrada;
}

ostream &operator<<(ostream &saida, const filme &item_filme){
    saida << "\tFilme: " << item_filme.nomeDoFilme << endl;
    saida << "\tProdutora: " << item_filme.nomeDaProdutora << endl;
    saida << "\tNota: " << item_filme.notaDoFilme << endl;
    saida << endl;

    return saida;
}