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
   Paciente *paciente;
   int opcao_paciente;
   string nome_paciente;
   string nome_doenca;
   int qtdConsultas;


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
         cout << "Tipo de paciente: " << endl;
         cout << "1. Paciente " << endl;
         cout << "2. Paciente Consultas " << endl;
         cout << "3. Paciente Doenca " << endl;
         cout << "4. Sair " << endl;
         
         cin >> opcao_paciente;
        
         switch (opcao_paciente)
         {
         case 1:
            paciente = new Paciente;
            break;
         case 2:
            paciente = new Paciente_Numero_Consultas;
            break;
         case 3:
            paciente = new Paciente_Doenca;
            break;
         
         case 4:
            break;

         default:
            cout << "Operacao invalida. Escolha uma das tres opcoes." << endl;
            cin.ignore();
         }

         cout << "Nome do paciente: " << endl;
         cin >> *paciente;

        if (opcao_paciente == 3){
            cout << "Digite nome da doenca: " << endl;
            getline(cin,nome_doenca);
            static_cast<Paciente_Doenca *>(paciente)->setTipo_Doenca (nome_doenca);
        }

        if (opcao_paciente == 2){
            cout << "Digite o numero de consultas: " << endl;
            cin >> qtdConsultas;
            static_cast<Paciente_Numero_Consultas *>(paciente)->setNumero_Consultas (qtdConsultas);
        }

         try{
            cadastro.InserePaciente(*paciente);
         }
         catch(PacienteInseridoException & except){
            cout << except.what() << endl;
         }

         break;
         
      case 2:
         cout << "Nome do paciente: ";
         cin.ignore();
         getline(cin, nome_paciente_novo);
         

         try{
            cout << cadastro.ExibePaciente(nome_paciente_novo) << endl;
         }
         catch(PacienteNaoEncontradoException &except){
            cout << except.what() << endl;
         }
         break;

      case 3:
        cout << cadastro;
        break;

      case 4:
        break;

      default:
        cout << "Operacao invalida, escolha uma operacao existente" << endl;
        cin.ignore();
      }  
   }  

    return 0;
}


