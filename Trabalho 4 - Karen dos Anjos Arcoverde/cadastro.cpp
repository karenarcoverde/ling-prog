/***************************************************************************/
/*************************** cadastro.cpp  **********************************/

#include <exception>
#include "cadastro.h"

ostream &operator<<(ostream & saida, Cadastro & cadastro){
    saida << cadastro.Arvore_Pacientes;

    return saida;
}

Paciente &Cadastro::ExibePaciente(string nome_paciente){
    Paciente *paciente_arvore = Arvore_Pacientes(nome_paciente);

    if (paciente_arvore == NULL)
        throw PacienteNaoEncontrado();

    return *paciente_arvore;
}

void Cadastro::InserePaciente(Paciente paciente){
    if ((Arvore_Pacientes += paciente)==NULL)
        throw PacienteJaInserido();
}