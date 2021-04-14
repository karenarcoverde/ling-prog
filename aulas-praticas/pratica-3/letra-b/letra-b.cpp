#include <iostream>
#include <string>

#include "agenda.h"

/* Programa do Laboratório 3: 
   Uma agenda...
   Autora: Karen dos Anjos Arcoverde*/
   
   
using namespace std;

int main(){
    Agenda agenda;
    string nome;


    cout << "Entre com tres nomes: "  << endl;
    cout << endl;

    for (int i = 0; i < 3; i++){
        cout << "Nome [" << i << "]: ";
        getline (cin, nome);
        agenda.insereNome (nome);
    }

    //Mostrar os nomes 
    cout << "\nA agenda possui "
         << Agenda::numeroNomes // chamada sem objeto 
         << "nomes... \nOs nomes da agenda sao: "
         << endl;
    agenda.mostraNomes ();
    
    return 0;
}