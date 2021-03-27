/*****************************************************************************/
/************************** Arquivo fibonacci.cpp ****************************/

#include "fibonacci.h"

void Fibonacci::setFibonacci (int indice){
    resultado = calculoFibonacci (indice);
}

int Fibonacci::getFibonacci (){
    return resultado;
}

int Fibonacci::calculoFibonacci (int indice){
    // Índice não positivos devem ser tratados na função principal

    if (indice == 0)
        return 0;
    else if (indice == 1)
        return 1;
    else
        return calculoFibonacci (indice -1) + calculoFibonacci (indice -2);
}