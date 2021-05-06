/*****************************************************************************/
/***************************** Arquivo aresta.cpp *****************************/


#include "aresta.h"


Aresta::Aresta (Vertice prim, Vertice seg){
    primeiroVertice = prim;
    segundoVertice = seg;
}

Vertice Aresta::getPrimeiroVertice (){
    return primeiroVertice;
}

Vertice Aresta::getSegundoVertice (){
    return segundoVertice;
}

string Aresta::getNomePrimeiroVertice (){
    return primeiroVertice.getPalavra();
}

string Aresta::getNomeSegundoVertice (){
    return segundoVertice.getPalavra();
}

void Aresta::setPesoAresta (){
    peso++; //soma 1 sempre que receber um vertice
}

int Aresta::getPesoAresta (){
    return peso;
}