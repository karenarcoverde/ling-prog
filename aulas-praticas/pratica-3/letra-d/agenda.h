/*****************************************************************************/
/******************************* Arquivo agenda.h ****************************/

#include <iostream>
#include <string>

#include "cadastro.h"

using namespace std;

class Agenda {
    public:

        void insereCadastro (Cadastro &);
        void mostraCadastros ();

        private:
            const static int maxNomes = 3;
            // Vector para armazenamento de cadastros
            vector <Cadastro> v;
            
};