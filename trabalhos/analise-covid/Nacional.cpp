/*****************************************************************************/
/*************************** Arquivo Nacional.cpp ****************************/

#include "Estadual.h"


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




