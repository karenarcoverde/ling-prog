#include <iostream>
#include <string>

#include "Nacional.h"
#include "Estadual.h"

/* Programa de Analise de casos Covid: 
   Uma Analise...
   Autora: Karen dos Anjos Arcoverde*/

using namespace std;

int main(){
   Estadual estado;
   string siglaEstado;
   Nacional Brasil;
   const int qtdDias = 10;

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

}


