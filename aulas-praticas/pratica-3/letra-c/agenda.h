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

        static int numeroNomes;

        private:
            const static int maxNomes = 3;

            Cadastro nomes [maxNomes];
};