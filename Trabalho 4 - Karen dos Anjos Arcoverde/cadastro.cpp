/***************************************************************************/
/*************************** cadastro.cpp  **********************************/

#include <exception>
#include "cadastro.h"


const char * PacienteNaoEncontradoException::what () const throw () {
	return "Paciente nao encontrado";
} 

const char * PacienteInseridoException::what () const throw () {
	return "Paciente ja consta no cadastro";
} 

// retorna todos os pacientes e suas informacoes
ostream &operator<<(ostream & saida, Cadastro & cadastro){
    saida << cadastro.Arvore_Pacientes;

    return saida;
}

//exibe paciente escolhido pelo usuario
Paciente &Cadastro::ExibePaciente(string nome_paciente){
    Paciente *paciente_arvore = Arvore_Pacientes(nome_paciente);

    if (paciente_arvore == NULL)
        throw PacienteNaoEncontradoException(); //caso o paciente escolhido na busca nao esteja na arvore

    return *paciente_arvore;
}

//insere o paciente na arvore
void Cadastro::InserePaciente(Paciente paciente){
    if ((Arvore_Pacientes += paciente)==NULL)
        throw PacienteInseridoException(); //caso o paciente escolhido para inserir retorne NULL
}