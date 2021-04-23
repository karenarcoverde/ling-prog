/*****************************************************************************/
/*************************** Arquivo Nacional.cpp ****************************/



#include "Nacional.h"

#define limiar_alta 1.15
#define limiar_baixa 0.85


void Nacional::insereEstado (Estadual &e){
    estados.push_back (e);
}

void Nacional::mostraNumeroDeObitosBrasil (){
    int soma_mortes_brasil = 0;

    for (unsigned int indice_o_nacional = 0; indice_o_nacional < estados.size(); indice_o_nacional++)
        soma_mortes_brasil += estados[indice_o_nacional].getNumeroDeObitos();

    cout << "Numero de obitos no Brasil: " << soma_mortes_brasil << endl;
}

void Nacional::mostraNumeroDeObitosEstados (){

    for (unsigned int indice_o_estado = 0; indice_o_estado < estados.size(); indice_o_estado++)
        cout << "O numero de obitos no " << estados[indice_o_estado].getNomeEstado() << " eh: " << estados[indice_o_estado].getNumeroDeObitos() << endl;

}

void Nacional::mostraMediaMovelEstados (int qtdDias){

    for (unsigned int indice_o_estado = 0; indice_o_estado < estados.size(); indice_o_estado++)
        cout << "A media movel nos ultimos " << qtdDias << " dias no " << estados[indice_o_estado].getNomeEstado() << " eh: " << estados[indice_o_estado].getMediaMovel(qtdDias) << endl;
}

void Nacional::mostraMediaMovelBrasil (int qtdDias){
    int soma_mortes = 0;
    float media_movel_Brasil = 0;

    for (unsigned int indice_estados = 0; indice_estados < estados.size();indice_estados++)
        soma_mortes += estados[indice_estados].getNumeroDeObitosqtdDias(qtdDias);

    media_movel_Brasil = (soma_mortes/qtdDias);

    cout << "A media movel dos ultimos " << qtdDias << " dias no Brasil eh: " << media_movel_Brasil << endl;

}

void Nacional::mostraEstabilidadeEstados(int qtdDias){
    vector <string> alta, baixa, estabilidade;
    float porcentagem = 0;


    for (unsigned int indice_e = 0; indice_e < estados.size(); indice_e++)
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
    for (unsigned int indice_alta = 0; indice_alta < alta.size(); indice_alta++)
        cout << alta[indice_alta] << "\n" << endl;

    cout << "------------ Estados em baixa: ------------" << endl;
    for (unsigned int indice_baixa = 0; indice_baixa < baixa.size(); indice_baixa++)
        cout << baixa[indice_baixa] << "\n" << endl;
    
    cout << "------------ Estados em estabilidade: ------------" << endl;
    for (unsigned int indice_estabilidade = 0; indice_estabilidade < estabilidade.size(); indice_estabilidade++)
        cout << estabilidade[indice_estabilidade] << "\n" << endl;

}

void Nacional::mostraEstabilidadeBrasil(int qtdDias){

    float porcentagem_risco_Brasil = 0;
    int soma_mortes_atual = 0;
    int soma_mortes_anterior = 0;

    for (unsigned int indice_estados = 0; indice_estados < estados.size(); indice_estados++)
        soma_mortes_anterior += estados[indice_estados].getNumeroDeObitosDiasEspecificoAnterior(qtdDias);

    for (unsigned int indice_estados = 0; indice_estados < estados.size(); indice_estados++)
        soma_mortes_atual += estados[indice_estados].getNumeroDeObitosDiasEspecificoAtual(qtdDias);
    

    porcentagem_risco_Brasil = soma_mortes_atual/soma_mortes_anterior;
   

     if (porcentagem_risco_Brasil > limiar_alta)
        cout << "Brasil tem risco Alto!" << endl;
            

    else if (porcentagem_risco_Brasil < limiar_baixa)
        cout << "Brasil tem risco Baixo!" << endl;

    else
        cout << "Brasil tem risco Estavel!" << endl;

}


void Nacional::mostraMaiorPorcentagemRisco (int qtdDias){
    float parametro_maior = 0;


    for (unsigned int indice_p = 0; indice_p < estados.size(); indice_p++)
    {
        if (estados[indice_p].getPorcentagemRisco (qtdDias) > parametro_maior)
            parametro_maior = estados[indice_p].getPorcentagemRisco (qtdDias); 
    }

    cout  << "------- Estados com maior alta: --------" << endl;
    for (unsigned int indice_p = 0; indice_p < estados.size(); indice_p++)
    {
         if (estados[indice_p].getPorcentagemRisco (qtdDias) == parametro_maior)
             cout << estados[indice_p].getNomeEstado() << endl;
    }
}



void Nacional::mostraMenorPorcentagemRisco (int qtdDias){
    float parametro_menor;

    parametro_menor = estados[0].getPorcentagemRisco (qtdDias);
    for (unsigned int indice_p = 0; indice_p < estados.size(); indice_p++)
    {
        if (estados[indice_p].getPorcentagemRisco (qtdDias) < parametro_menor)
            parametro_menor = estados[indice_p].getPorcentagemRisco (qtdDias); 
    }


    cout  << "------- Estados com maior baixa: --------" << endl;
    for (unsigned int indice_p = 0; indice_p < estados.size(); indice_p++)
    {
         if (estados[indice_p].getPorcentagemRisco (qtdDias) == parametro_menor)
             cout << estados[indice_p].getNomeEstado() << endl;
    }
}

