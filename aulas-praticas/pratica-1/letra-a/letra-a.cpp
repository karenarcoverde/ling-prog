#include <iostream>
#include "fibonacci.h"

/* Primeiro programa do Laboratório 1: 
   Fibonacci sem classes.
   Autora: Karen dos Anjos Arcoverde*/

using namespace std;

int main () {
	int indice;
	
	cout << "Entre com o indice da serie de Fibonacci: ";
	cin >> indice;

	cout << "\n\nO numero eh: " << resultadoFibonacci (indice) << endl;
	
	return 0;
}    
