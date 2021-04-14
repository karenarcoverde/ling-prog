/*****************************************************************************/
/******************************* Arquivo agenda.h ****************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Agenda {
    public:

        void insereNome (string);
        void mostraNomes ();

        static int numeroNomes;

        private:
            const static int maxNomes = 3;
            string nomes [maxNomes];

            string verificaNome (string);
};