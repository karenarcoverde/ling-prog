/***************************************************************************/
/*************************** Programa Principal ****************************/

#include <iostream>
#include <fstream>
#include <string>
#include "grafo.h"

using namespace std;

/* Programa do Trabalho 2: 
   Programa da construção de um grafo
   Autora: Karen dos Anjos Arcoverde */

int main(){

   Grafo grafo;
   Vertice vertice;

   //Lê o arquivo e guarda cada palavra lida em um vetor de strings
   fstream file;
   string nomeArquivo;

   nomeArquivo = "texto.txt";
   vector <string> conjuntoDePalavras;

   file.open (nomeArquivo, fstream::in);

   if (!file.is_open()){
      cout << "Arquivo nao existe." << endl;
      return; 
   }

   while (file.good()){
      string linha;

      getline (file, linha, ' ');
      if ((linha[linha.length()-1] == '.') || (linha[linha.length()-1] == ','))
		linha = linha.substr(0,linha.length()-1);

      vertice.setPalavra (linha);
      grafo.insereVertice (vertice);
	}
   file.close();





   return 0;
}