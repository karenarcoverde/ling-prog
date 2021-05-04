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
   int qtdVertices = 0;
   int primeira_palavra = 1;
   int segunda_palavra = 2;

   int opcao_menu;

   fstream file;
   string nomeArquivo;

   //Lê o arquivo e guarda cada palavra lida em um vetor de strings

   nomeArquivo = "texto.txt";

   file.open (nomeArquivo, fstream::in);

   if (!file.is_open()){
      cout << "Arquivo nao existe." << endl;
      return; 
   }

   while (file.good()){
      string linha;

      getline (file, linha, ' ');
      if ((linha[linha.length()-1] == '.') || (linha[linha.length()-1] == ',')){
         linha = linha.substr(0,linha.length()-1);
         segunda_palavra = 3;
      }
      if (primeira_palavra == 1)  { 
         vertice.setPalavra (linha);
         grafo.insereVertice (vertice);
         qtdVertices ++;
         primeira_palavra = 0;
      }

      else if (segunda_palavra == 2){
         vertice.setPalavra (linha);
         grafo.insereVertice (vertice);
         qtdVertices ++;
         Aresta aresta (grafo.getVerticeEspecifico (qtdVertices - 1), grafo.getVerticeEspecifico (qtdVertices));
         grafo.insereAresta (aresta);
         primeira_palavra = 0;
      }

      else if (segunda_palavra == 3){
         vertice.setPalavra (linha);
         grafo.insereVertice (vertice);
         qtdVertices ++;
         Aresta aresta (grafo.getVerticeEspecifico (qtdVertices - 1), grafo.getVerticeEspecifico (qtdVertices));
         grafo.insereAresta (aresta);
         primeira_palavra = 1;
      }
   }

   file.close();

   cout << "----------------- MENU -----------------" << endl;
   cout << "1. Mostrar a(s) palavra(s) mais utilizada(s) no texto " << endl;
   cout << "2. Mostrar a(s) sequencia(s) de palavras de comprimento 2 mais utilizada(s) no texto " << endl;
   cout << "3. Mostrar a(s) sequencia(s) de palavras de comprimento N mais utilizada(s) no texto " << endl;
   cout << "4. Sair " << endl;


   while (opcao_menu != 4)
   {

      cin >> opcao_menu;

      switch (opcao_menu)
      {
      
      case 1:
         grafo.mostraMaiorPesoPalavra ();
         break;

      case 2:
         grafo.mostraMaiorPesoPalavraDupla ();
         break;

      case 3:
      
         break;

      case 4:
         break;

      default:
         cout << "Operacao invalida, escolha uma operacao existente" << endl;
      }
   }  

   return 0;
}