#include <iostream>
#include "fibonacci.h"

/* Programa do Laboratório 1: 
   Fibonacci com classes.
   Autora: Karen dos Anjos Arcoverde */

using namespace std;

int main (){
    // Objeto da classe Fibonacci
    Fibonacci fibonacci;
    int indice;

    cout << "Entre com o indice da serie de Fibonacci: ";
    cin >> indice;

    fibonacci.setFibonacci(indice);

    cout <<  "\n\nO numero eh: " <<  fibonacci.getFibonacci () << endl;

    return 0;
}