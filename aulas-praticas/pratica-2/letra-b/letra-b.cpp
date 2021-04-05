#include <iostream>

// include ponto.h já foi realizado em linha.h
//#include "ponto.h"
#include "linha.h"


/* Programa do Laboratório 2: 
   Cálculo do comprimento de linhas usando composição entre classes.
   Autora: Karen dos Anjos Arcoverde */

using namespace std;

void printCoordenadas (Ponto p){
    // Variável local estática conta o número de vezes que a função foi chamada
	static int count = 1;

    cout << "[Impressao no. " << count
         << "] : Coordenadas de p (" << p.getCoordX ()
         << ", " << p.getCoordY ()
         << ", " << p.getCoordZ ()
         << ")" << endl;
    
    count++;
}

int main (){
    Ponto p1 (2,2,1);
    Ponto p2; // Construtor da classe Ponto com argumentos padrão (1.0, 1.0, 1.0) 
    Linha linha (p1, p2);

    printCoordenadas (p1);
    printCoordenadas (p2);

    cout << "== O comprimento da linha eh: " << linha.getComprimento () << endl;

    cout << "\nNovas coordenadas para p2. . . \n" << endl;
    p2.setCoordX (2); // Método setCoordX atualiza a coordenada X do ponto p2
    printCoordenadas(p2);

    linha.setP2 (p2); // Método setP2 atualiza o ponto p2 da linha

    cout << "== O NOVO comprimento da linha eh: " << linha.getComprimento () << endl;

    return 0;
}