/*****************************************************************************/
/**************************** Arquivo ponto.cpp ******************************/

#include "ponto.h"

Ponto::Ponto (double x, double y, double z){
    coordX = x;
    coordY = y;
    coordZ = z;
}

double Ponto::getCoordX (){
    return coordX;
}

double Ponto::getCoordY (){
    return coordY;
}

double Ponto::getCoordZ (){
    return coordZ;
}

void Ponto::setCoordX (double x){
    coordX = x;
}

void Ponto::setCoordY (double y){
    coordY = y;
}

void Ponto::setCoordZ (double z){
    coordZ = z;
}
