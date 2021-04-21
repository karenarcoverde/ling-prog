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
   unsigned int qtdDias = 7;
   int opcao_menu;

   vector <int> RJ = {30, 40, 35, 38, 39, 25, 31, 24, 29, 36, 36, 35, 29, 21};

    estado.setMortesDiarias (RJ);
    estado.setNomeEstado ("Rio de Janeiro");

    Brasil.insereEstado (estado);

    //Sao Paulo

    vector <int> SP = {60, 50, 55, 49, 59, 57, 45, 47, 48, 54, 53, 55, 42, 53};

    estado.setMortesDiarias (SP);
    estado.setNomeEstado ("Sao Paulo");

    Brasil.insereEstado (estado);

    //Espirito Santo

    vector <int> ES = {20, 17, 19, 25, 23, 24, 15, 19, 18, 21, 31, 27, 17, 30};

    estado.setMortesDiarias (ES);
    estado.setNomeEstado ("Espirito Santo");

    Brasil.insereEstado (estado);

    //Minas Gerais

    vector <int> MG = {59, 57, 49, 46, 55, 60, 50, 45, 58, 56, 43, 42, 52, 62};

    estado.setMortesDiarias (MG);
    estado.setNomeEstado ("Minas Gerais");

    Brasil.insereEstado (estado);

    //Santa Catarina

    vector <int> SC = {20, 15, 13, 12, 25, 17, 19, 21, 9, 8, 16, 14, 24, 11};

    estado.setMortesDiarias (SC);
    estado.setNomeEstado ("Santa Catarina");

    Brasil.insereEstado (estado);

    //Alagoas

    vector <int> AL = {1, 2, 3, 4, 5, 6, 7, 300, 400, 500, 600, 700, 800, 900};

    estado.setMortesDiarias (AL);
    estado.setNomeEstado ("Alagoas");

    Brasil.insereEstado (estado);

    vector <int> SE = {200, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 200, 200, 200};

    estado.setMortesDiarias (SE);
    estado.setNomeEstado ("Sergipe");

    Brasil.insereEstado (estado);

    //Bahia

    vector <int> BA = {1, 2, 3, 4, 5, 6, 7, 300, 400, 9, 10, 11, 12, 500};

    estado.setMortesDiarias (BA);
    estado.setNomeEstado ("Bahia");

    Brasil.insereEstado (estado);



   /*
   // RIO DE JANEIRO
   vector <int> RJ = {20, 10, 50, 60, 80, 70, 90, 35, 40, 77};
  

   estado.setNomeEstado ("Rio de Janeiro");
   estado.setMortesDiarias (RJ);

   Brasil.insereEstado(estado);

   // SAO PAULO
   vector <int> SP = {15, 25, 45, 65, 72, 90, 86, 27, 21, 31};

   estado.setNomeEstado ("Sao Paulo");
   estado.setMortesDiarias (SP);
   
   Brasil.insereEstado(estado);

   // MINAS GERAIS
   vector <int> MG = {20, 10, 50, 60, 80, 70, 90, 35, 40, 77};


   estado.setNomeEstado ("Minas Gerais");
   estado.setMortesDiarias (MG);

   Brasil.insereEstado(estado);

   // ESPIRITO SANTO
  vector <int> ES = {20, 10, 50, 60, 80, 70, 90, 35, 40, 77};


   estado.setNomeEstado ("Espirito Santo");
   estado.setMortesDiarias (ES);

   Brasil.insereEstado(estado);

   // RIO GRANDE DO SUL
   vector <int> RS = {20, 10, 50, 60, 80, 70, 90, 35, 40, 77};


   estado.setNomeEstado ("Rio Grande do Sul");
   estado.setMortesDiarias (RS);

   Brasil.insereEstado(estado);


   // BAHIA
   vector <int> BA = {20, 10, 50, 60, 80, 70, 90, 35, 40, 77};


   estado.setNomeEstado ("Bahia");
   estado.setMortesDiarias (BA);

   Brasil.insereEstado(estado);

   // DISTRITO FEDERAL
   vector <int> DF = {20, 10, 50, 60, 80, 70, 90, 35, 40, 77};


   estado.setNomeEstado ("Distrito Federal");
   estado.setMortesDiarias (DF);

   Brasil.insereEstado(estado);

   // RIO GRANDE DO NORTE
   vector <int> RN = {20, 10, 50, 60, 80, 70, 90, 35, 40, 77};


   estado.setNomeEstado ("Rio Grande do Norte");
   estado.setMortesDiarias (RN);

   Brasil.insereEstado(estado);
   */
   

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


