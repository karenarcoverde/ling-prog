/***************************************************************************/
/*************************** Programa Principal ****************************/



#include "cadastro.h"
#include "paciente.h"


using namespace std;


/* Programa do Trabalho 4: 
   Programa de cadastro de pacientes de um hospital
   Autora: Karen dos Anjos Arcoverde */

int main(){

   int opcao_menu;
   Cadastro cadastro;
   string nome_paciente_novo;

   while (opcao_menu != 4)
   {
      cout << "----------------- MENU -----------------" << endl;
      cout << "1. Insere paciente " << endl;
      cout << "2. Busca paciente " << endl;
      cout << "3. Exibe pacientes " << endl;
      cout << "4. Sair " << endl;
     

      cin >> opcao_menu;
      switch (opcao_menu)
      {

      case 1:
         int opcao_paciente;
         Paciente *paciente;

         cout << "Tipo de paciente: " << endl;
         cout << "1. Paciente " << endl;
         cout << "2. Paciente Consultas " << endl;
         cout << "3. Paciente Risco " << endl;
      
         cin >> opcao_paciente;

         cout << "Nome do paciente: " ;


         switch (opcao_paciente)
         {
         case 1:
            paciente = new Paciente;
            break;
         case 2:
            paciente = new Paciente_Numero_Consultas;
            break;
         case 3:
            paciente = new Paciente_Risco;
            break;  

         default:
            cout << "Operacao invalida. Escolha uma das tres opcoes." << endl;
            return 2;
            break;
         }

         cin >> *paciente;

         try{
            cadastro.InserePaciente(*paciente);
         }
         catch(const PacienteJaInserido & erro){
            cout << "Paciente ja inserido. "<< endl;
            cerr << erro.what();
         }

         delete paciente;
         break;

      case 2:
         cout << "Nome do paciente: ";
         cin >> nome_paciente_novo; 
         cout << "Exibindo detalhes do paciente:"<< endl;

         try{
            cout << cadastro.ExibePaciente(nome_paciente_novo);
         }
         catch(const PacienteNaoEncontrado &erro){
            cout << "Erro ao exibir paciente. "<< endl;
            cerr << erro.what();
         }
         break;

      case 3:
        cout << cadastro;
        break;

      case 4:
        break;

      default:
        cout << "Operacao invalida, escolha uma operacao existente" << endl;
      }  
   }  

    return 0;
}


