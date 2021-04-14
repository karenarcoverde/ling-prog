/*****************************************************************************/
/***************************** Arquivo agenda.cpp ****************************/

#include "agenda.h"

int Agenda::numeroNomes = 0;

void Agenda::insereCadastro (Cadastro &c){
    if (numeroNomes >= maxNomes)
        cout << "Agenda cheia!" << endl;
    
    else
        nomes [numeroNomes++] = c;
}

void Agenda::mostraCadastros (){
    for (int i = 0; i < numeroNomes; i++){
        cout << "Nome [" << i << "] " << nomes[i].getNome () << endl
            << "Prof [" << i << "] " << nomes[i].getProfissao () << endl
            << "Idade [" << i << "] " << nomes[i].getIdade () << endl;
    }


}