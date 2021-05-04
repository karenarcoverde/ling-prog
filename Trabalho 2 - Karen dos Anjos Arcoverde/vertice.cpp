/*****************************************************************************/
/***************************** Arquivo vertice.cpp **************************/
#include <iostream>
#include <vector>

#include "vertice.h"

void Vertice::setPalavra (string palavra_vertice){
    palavra = palavra_vertice;
}

string Vertice::getPalavra (){
    return palavra;
}

void Vertice::setPesoPalavra(){
    peso++;
}

int Vertice::getPesoPalavra (){
    return peso;
}
