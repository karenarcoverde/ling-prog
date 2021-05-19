/***************************************************************************/
/*************************** Programa Principal ****************************/

#include <iostream>
#include <fstream>
#include <string>
#include "catalogo.h"

using namespace std;

/* Programa do Trabalho 3: 
   Programa de um catalogo de filmes
   Autora: Karen dos Anjos Arcoverde */

int main(){

   int opcao_menu;
   Catalogo catalogo;
    
   cout << "----------------- MENU -----------------" << endl;
   cout << "1. Insere filme " << endl;
   cout << "2. Remove filme " << endl;
   cout << "3. Busca e exibe filme " << endl;
   cout << "4. Editar filme " << endl;
   cout << "5. Exibir Catalogo " << endl;
   cout << "6. Renovar Catalogo " << endl;
   cout << "7. Exibir filme mais bem avaliado " << endl;
   cout << "8. Sair " << endl;


   while (opcao_menu != 8)
   {

      cin >> opcao_menu;
      switch (opcao_menu)
      {
      
      case 1:
        break;

      case 2:
        break;

      case 3:
        break;

      case 4:
        break;

      case 5:
        cout << catalogo;
        break;

      case 6:
        catalogo.RenovarCatalogo();
        break;

      case 7:
        catalogo.ExibeFilmeBemAvaliado();
        break;

      default:
        cout << "Operacao invalida, escolha uma operacao existente" << endl;
      }
   }  
    return 0;
}