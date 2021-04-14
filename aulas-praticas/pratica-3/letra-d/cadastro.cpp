/*****************************************************************************/
/*************************** Arquivo cadastro.cpp ****************************/

#include "cadastro.h"

void Cadastro::setNome (string n){
    nome = verificaNome (n);
}

string Cadastro::getNome (){
    return nome;
}

void Cadastro::setProfissao (string p){
    profissao = p;
}

string Cadastro::getProfissao (){
    return profissao;
}

void Cadastro::setIdade (int a){
    idade = a;
}

int Cadastro::getIdade (){
    return idade;
}

string Cadastro::verificaNome (string str){
    if (str.length () > 10){
        cout << "Nome com mais de 10 caracteres, reduzindo para 10...";
        cout << endl;

        str = str.substr (0,10);
    }

    return str;
}