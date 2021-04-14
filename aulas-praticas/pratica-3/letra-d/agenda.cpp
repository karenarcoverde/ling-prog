/*****************************************************************************/
/***************************** Arquivo agenda.cpp ****************************/

#include "agenda.h"


void Agenda::insereCadastro (Cadastro &c){
    if (v.size() >= maxNomes)
        cout << "Agenda cheia!" << endl;
    
    else
        v.push_back (c);
}

void Agenda::mostraCadastros (){
    for (unsigned int i = 0; i < v.size (); i++){
        cout << "Nome [" << i << "] " << v[i].getNome () << endl
            << "Prof [" << i << "] " << v[i].getProfissao () << endl
            << "Idade [" << i << "] " << v[i].getIdade () << endl;
    }

}