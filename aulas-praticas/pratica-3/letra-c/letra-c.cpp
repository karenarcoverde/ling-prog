#include <iostream>
#include <string>

#include "agenda.h"

/* Programa do Laboratório 3: 
   Uma agenda...
   Autora: Karen dos Anjos Arcoverde*/
   
   
using namespace std;

int main(){
    Agenda agenda;
    string nome, profissao;
    int idade;


    cout << "Entre com tres cadastros: "  << endl;
    cout << endl;

    for (int i = 0; i < 3; i++){
        Cadastro cadastro;

        cout << "Nome [" << i << "]: ";
        getline (cin, nome);
        cadastro.setNome (nome);

        cout << "Profissao [" << i << "]: ";
        getline (cin, profissao);
        cadastro.setProfissao (profissao);

        cout << "Idade [" << i << "]: ";
        cin >> idade;
        cin.ignore ();
        cadastro.setIdade (idade);

        agenda.insereCadastro (cadastro);

        if (i < 2)
            cout << "--- proximo ---" << endl;
    }

    //Mostrar os atributos dos cadastros
    cout << "\nOs cadastros da agenda sao: " << endl;
    agenda.mostraCadastros ();
    
    return 0;
}