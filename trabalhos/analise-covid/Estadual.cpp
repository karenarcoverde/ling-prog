/*****************************************************************************/
/******************************* Arquivo Estadual.cpp ************************/

#include <iostream>
#include <string>

#include "Nacional.h"

using namespace std;

void Estadual::setNomeEstado (string siglaEstado_escolhido){
    siglaEstado = siglaEstado_escolhido;
}

string Estadual::getNomeEstado (){
    return siglaEstado;
}

void Estadual::setMortesDiarias (vector int mortesEstado){
    mortesEstado_dias = mortesEstado;
}

vector <int> Estadual::getMortesDiarias (){
    return mortesEstado_dias;
}


float Estadual::getMediaMovel (int qtdDias){
    int soma_mortes = 0;

    for (int indice = 0; indice < qtdDias; indice++)
        soma_mortes += mortesEstado_dias[indice];

    media_movel_dias = (soma_mortes/qtdDias);

    return media_movel_dias;

}

float Estadual::getPorcentagemRisco (int qtdDias){
    float porcentagem_risco_estado = 0;
    int soma_mortes_atual = 0;

    for (int indice_dias = 1; indice_dias < qtdDias +1; indice_dias++)
        soma_mortes_atual += mortesEstado_dias[indice_dias];
    
    media_movel_mortes_atual = (soma_mortes_atual/qtdDias);

    porcentagem_risco_estado = (getMediaMovel (qtdDias)/media_movel_mortes_atual);
   
    return porcentagem_risco_estado;
}


int Estadual::getNumeroDeObitos (){
    int soma_mortes_total = 0;

    for (int indice_obitos = 0; indice_obitos < mortesEstado_dias.size(); indice_obitos++)
        soma_mortes_total += mortesEstado_dias[indice_obitos]

    return soma_mortes_total;
}

int Estadual::getNumeroDeObitosDiasEspecificoAnterior (int qtdDias){
    int soma_mortes_total_anterior = 0;

    for (int indice_obitos = 1; indice_obitos < qtdDias+1; indice_obitos++)
        soma_mortes_total_anterior += mortesEstado_dias[indice_obitos]

    return soma_mortes_total_anterior;
}

int Estadual::getNumeroDeObitosDiasEspecificoAtual (int qtdDias){
    int soma_mortes_total_atual = 0;

    for (int indice_obitos = 0; indice_obitos < qtdDias; indice_obitos++)
        soma_mortes_total_atual += mortesEstado_dias[indice_obitos]

    return soma_mortes_total_atual;
}
