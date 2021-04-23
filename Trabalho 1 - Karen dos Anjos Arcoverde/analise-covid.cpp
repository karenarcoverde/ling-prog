#include <iostream>
#include <string>

#include "Nacional.h"

/* Programa de Analise de casos Covid: 
   Autora: Karen dos Anjos Arcoverde*/

using namespace std;

int main(){
   Estadual estado;
   string siglaEstado;
   Nacional Brasil;
   unsigned int qtdDias = 9;
   int opcao_menu;

   
   // RIO DE JANEIRO
   vector <int> RJ = {20, 10, 50, 60, 80, 170, 90, 35, 340, 77};
  

   estado.setNomeEstado ("Rio de Janeiro");
   estado.setMortesDiarias (RJ);

   Brasil.insereEstado(estado);

   // SAO PAULO
   vector <int> SP = {15, 25, 45, 65, 72, 90, 286, 27, 21, 31};

   estado.setNomeEstado ("Sao Paulo");
   estado.setMortesDiarias (SP);
   
   Brasil.insereEstado(estado);

   // MINAS GERAIS
   vector <int> MG = {900, 20, 550, 9, 98, 15, 80, 335, 80, 55};


   estado.setNomeEstado ("Minas Gerais");
   estado.setMortesDiarias (MG);

   Brasil.insereEstado(estado);

   // ESPIRITO SANTO
  vector <int> ES = {40, 70, 60, 80, 222, 341, 90, 450, 40, 77};


   estado.setNomeEstado ("Espirito Santo");
   estado.setMortesDiarias (ES);

   Brasil.insereEstado(estado);

   // RIO GRANDE DO SUL
   vector <int> RS = {12, 13, 50, 40, 804, 70, 24, 7, 90, 770};


   estado.setNomeEstado ("Rio Grande do Sul");
   estado.setMortesDiarias (RS);

   Brasil.insereEstado(estado);


   // BAHIA
   vector <int> BA = {51, 11, 500, 608, 807, 1, 3, 73, 78, 77};


   estado.setNomeEstado ("Bahia");
   estado.setMortesDiarias (BA);

   Brasil.insereEstado(estado);

   // DISTRITO FEDERAL
   vector <int> DF = {2, 650, 430, 60, 79, 13, 91, 61, 12, 80};


   estado.setNomeEstado ("Distrito Federal");
   estado.setMortesDiarias (DF);

   Brasil.insereEstado(estado);

   // RIO GRANDE DO NORTE
   vector <int> RN = {11, 10, 50, 60, 20, 70, 90, 35, 40, 12};


   estado.setNomeEstado ("Rio Grande do Norte");
   estado.setMortesDiarias (RN);

   Brasil.insereEstado(estado);
   
   

   cout << "----------------- MENU -----------------" << endl;
   cout << "1. Mostrar media movel dos estados " << endl;
   cout << "2. Mostrar media movel no Brasil " << endl;
   cout << "3. Mostrar numero de obitos em cada estado " << endl;
   cout << "4. Mostrar numero de obitos no Brasil" << endl;
   cout << "5. Mostrar a estabilidade dos estados" << endl;
   cout << "6. Mostrar a estabilidade do Brasil " << endl;
   cout << "7. Mostrar estados com maior alta e maior baixa " << endl;
   cout << "8. Sair " << endl;

   

   while (opcao_menu != 8)
   {

      cin >> opcao_menu;

      switch (opcao_menu)
      {
      
      case 1:
         Brasil.mostraMediaMovelEstados(qtdDias); 
         break;

      case 2:
         Brasil.mostraMediaMovelBrasil (qtdDias);
         break;

      case 3:
         Brasil.mostraNumeroDeObitosEstados();
         break;

      case 4:
         Brasil.mostraNumeroDeObitosBrasil ();
         break;

      case 5:
         Brasil.mostraEstabilidadeEstados(qtdDias);
         break;

      case 6:
         Brasil.mostraEstabilidadeBrasil(qtdDias);
         break;

      case 7:
         Brasil.mostraMaiorPorcentagemRisco (qtdDias);
         Brasil.mostraMenorPorcentagemRisco (qtdDias);
         break;

      case 8:
         break;

      default:
         cout << "Operacao invalida, escolha uma operacao existente" << endl;
      }
   }  
}


