/*****************************************************************************/
/*************************** Arquivo Nacional.cpp ****************************/

#include "Estadual.h"

#define limiar_alta 1.15
#define limiar_baixa 0.85


void Nacional::insereEstado (Estadual &e){
    estados.push_back (e);
}

void Nacional::mostraNumeroDeObitosBrasil (){
    int soma_mortes_brasil = 0;

    for (int indice_o_nacional = 0; indice_o_nacional < e.size(); indice_o_nacional++)
        soma_mortes_brasil += e[indice_o_nacional].getNumeroDeObitos();

    cout << "Numero de obitos no Brasil: " << soma_mortes_brasil << endl;
}

void Nacional::mostraNumeroDeObitosEstados (){

    for (int indice_o_estado = 0; indice_o_estado < e.size(); indice_o_estado++)
        cout << "O numero de obitos no " << e[indice_o_estado].getNomeEstado() << "eh: " << e[indice_o_estado].getNumeroDeObitos() << endl;

}

void Nacional::mostraMediaMovelEstados (int qtdDias){

    for (int indice_o_estado = 0; indice_o_estado < e.size(); indice_o_estado++)
        cout << "A media movel nos ultimos " << qtdDias << "dias no: " << e[indice_o_estado].getNomeEstado() << "eh: " << e[indice_o_estado].getMediaMovel(qtdDias) << endl;
}

void Nacional::mostraMediaMovelBrasil (int qtdDias){
    int soma_mortes = 0;
    media_movel_Brasil = 0;

    for (int indice_estados = 0; indice_estados < e.size();indice_estados++)
        soma_mortes += e[indice_estados].getNumeroDeObitos();

    media_movel_Brasil = (soma_mortes/qtdDias);

    cout << "A media movel dos ultimos " << qtdDias << "dias no Brasil eh: " << media_movel_Brasil << endl;

}

void mostraEstabilidadeEstados(int qtdDias){
    vector <string> alta, baixa, estabilidade;


    for (int indice_e = 0; indice_e < estados.size(); indice_e++)
    {

        porcentagem = estados[indice_e].getPorcentagemRisco(qtdDias);

        if (porcentagem > limiar_alta)
            alta.push_back (estados[indice_e].getNomeEstado());

        else if (porcentagem < limiar_baixa)
            baixa.push_back (estados[indice_e].getNomeEstado());

        else
            estabilidade.push_back (estados[indice_e].getNomeEstado());

    }

    cout << "------------Estados em alta: ------------" << endl;
    for (int indice_alta = 0; int < alta.size(); indice_alta++)
        cout << alta[indice_alta] << "\n" << endl;

    cout << "------------ Estados em baixa: ------------" << endl;
    for (int indice_baixa = 0; int < baixa.size(); indice_baixa++)
        cout << baixa[indice_baixa] << "\n" << endl;
    
    cout << "------------ Estados em estabilidade: ------------" << endl;
    for (int indice_estabilidade = 0; int < estabilidade.size(); indice_estabilidade++)
        cout << baixa[indice_estabilidade] << "\n" << endl;

}

void Nacional::mostraEstabilidadeBrasil(int qtdDias){

    float porcentagem_risco_estado = 0;
    int soma_mortes_atual = 0;

    for (int indice_estados = 0; indice_estados < qtdDias; indice_estados++)
        soma_mortes_atual += estados[indice_estados].getNumeroDeObitosDiasEspecifico();
    
    media_movel_mortes_atual = (soma_mortes_atual/qtdDias);

    porcentagem_risco_Brasil = (getMediaMovel (qtdDias)/media_movel_mortes_atual);
   
    return porcentagem_risco_Brasil;

}

