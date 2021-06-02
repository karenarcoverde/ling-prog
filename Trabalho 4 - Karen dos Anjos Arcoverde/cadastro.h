/***************************************************************************/
/*************************** cadastro.h  **********************************/


#include <string>
#include <iostream>
#include <stdexcept>

#include "arvore.h"
#include "paciente.h"


using namespace std;


class Cadastro{
    friend ostream &operator<<(ostream &, Cadastro &);

    public:
        void InserePaciente(Paciente);

        Paciente &ExibePaciente(string);

    private:
        Arvore <Paciente> Arvore_Pacientes;
};

// quando o paciente ja estiver na arvore
class PacienteInseridoException : public exception {
	public:
		virtual const char * what () const throw (); 
};

// quando o paciente nao estiver na arvore para buscar
class PacienteNaoEncontradoException : public exception {
	public:
		virtual const char * what () const throw (); 
};

