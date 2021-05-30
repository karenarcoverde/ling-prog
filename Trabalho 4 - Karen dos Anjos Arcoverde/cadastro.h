/***************************************************************************/
/*************************** cadastro.h  **********************************/


#include <string>

#include "arvore.h"
#include "paciente.h"

using namespace std;

// quando o paciente ja estiver na arvore
class PacienteJaInserido: public exception{
    public:
    const char *what() const throw()
    {
        return "Paciente ja consta no cadastro";
    }
};

// quando o paciente nao estiver na arvore
class PacienteNaoEncontrado: public exception{
    public:
    const char *what() const throw()
    {
        return "Paciente nao encontrado";
    }
};

class Cadastro{
    friend ostream &operator<<(ostream &, Cadastro &);

    public:
        void InserePaciente(Paciente);

        Paciente &ExibePaciente(string);

    private:
        Arvore <Paciente> Arvore_Pacientes;
};