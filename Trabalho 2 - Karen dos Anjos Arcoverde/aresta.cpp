/*****************************************************************************/
/***************************** Arquivo aresta.cpp *****************************/


#include "aresta.h"


Aresta::Aresta (Vertice *prim, Vertice *seg){
    primeiroVertice = prim;
    segundoVertice = seg;
}

Vertice *Aresta::getPrimeiroVertice (){
    return primeiroVertice;
}

Vertice *Aresta::getSegundoVertice (){
    return segundoVertice;
}

void Aresta::setPesoAresta (){
    peso++;
}

int Aresta::getPesoAresta (){
    return peso;
}