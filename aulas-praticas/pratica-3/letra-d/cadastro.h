/*****************************************************************************/
/**************************** Arquivo cadastro.h *****************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Cadastro {
    public:
        void setNome (string);
        string getNome ();


        void setProfissao (string);
        string getProfissao ();

        void setIdade (int);
        int getIdade ();

    private:
        string nome, profissao;
        int idade;

        string verificaNome (string);
};