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
    
   vector <filme> filmesEscolhidos;
   string produtoraEscolhida;
   filme filmeEscolhido;
   double NotaEscolhida;
   string nomeFilmeEscolhido;
   filme *ponteiroParaFilme;
   int qtdFilmes = 0;
   int escolher_novo_filme = 1;
   int edicao_filme = 0;

   while (opcao_menu != 7)
   {
      cout << "----------------- MENU -----------------" << endl;
      cout << "1. Insere filme " << endl;
      cout << "2. Remove filme " << endl;
      cout << "3. Busca e exibe filme " << endl;
      cout << "4. Editar filme " << endl;
      cout << "5. Exibir Catalogo " << endl;
      cout << "6. Exibir filme mais bem avaliado " << endl;
      cout << "7. Sair " << endl;

      cin >> opcao_menu;
      switch (opcao_menu)
      {

      case 1:
        while (escolher_novo_filme == 1){
          cin.ignore();
          cout << "Digite filme, produtora e nota que deseja inserir: " << endl;
          cin >> filmeEscolhido;
          filmesEscolhidos.push_back(filmeEscolhido);
          qtdFilmes++;

          cout << "Caso queira adicionar outro filme, digite 1." << endl;
          cout << "Caso queira voltar para o menu, digite 0. " << endl;
          cin >> escolher_novo_filme;
        }

        if (qtdFilmes == 1){
            catalogo += filmeEscolhido;
          }
        else{
            catalogo += filmesEscolhidos;
        }
        break;

      case 2:
        cout << "Digite o nome do filme que deseja remover:  " << endl;
        cin.ignore();
        getline (cin, nomeFilmeEscolhido);

        ponteiroParaFilme = catalogo(nomeFilmeEscolhido);
        catalogo -= *ponteiroParaFilme;
        break;
        

      case 3:
        cout << "Digite o nome do filme que deseja buscar: " << endl;
        cin.ignore();
        getline(cin, nomeFilmeEscolhido);

        ponteiroParaFilme = catalogo(nomeFilmeEscolhido);

        if (ponteiroParaFilme != NULL) 
          cout << *ponteiroParaFilme;
        else 
          cout << "Filme nao esta no catalogo. " << endl;
        break;

      case 4:
        cout << "Digite o nome do filme: ";
          cin.ignore();
          getline(cin, nomeFilmeEscolhido);

          if (!catalogo(nomeFilmeEscolhido)) {
              cout << "Filme nao esta no catalogo. " << endl;
              break;
          }


          while (edicao_filme != 3){
            cout << "O que voce deseja editar? " << endl;
            cout << "1. Produtora " << endl;
            cout << "2. Nota " << endl;
            cout << "3. Voltar ao menu " << endl;
            cin >> edicao_filme;
          
            if (edicao_filme == 1) {
                cout << "Digite a nova produtora: ";
                cin.ignore();
                getline(cin, produtoraEscolhida);
                catalogo(nomeFilmeEscolhido,produtoraEscolhida);
            }

            if (edicao_filme == 2) {
                cout << "Digite a nova nota: ";
                cin >> NotaEscolhida;
                catalogo(nomeFilmeEscolhido, NotaEscolhida);
            }
          }
          break;

      case 5:
        cout << catalogo;
        break;

      case 6:
        catalogo.ExibeFilmeBemAvaliado();
        break;

      case 7: 
        break;

      default:
        cout << "Operacao invalida, escolha uma operacao existente" << endl;
      }  
   }  

    catalogo.RenovarCatalogo();
    return 0;
}