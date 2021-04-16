/*****************************************************************************/
/******************************* Arquivo Estadual.cpp ************************/

#include <iostream>
#include <string>

#include "nacional.h"

using namespace std;


void Estadual::setSiglaEstado (string siglaEstado){
    siglaEstado = SiglaEstado;
}

string Estadual::getSiglaEstado (){
    return siglaEstado;
}