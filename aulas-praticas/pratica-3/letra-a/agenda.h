/*****************************************************************************/
/******************************* Arquivo agenda.h ****************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Agenda {
    public:
        Agenda (int = 3);

        void insereNome (string);
        void mostraNomes ();

        private:
            vector <string> v;
            int maxNomes;

            string verificaNome (string);
};